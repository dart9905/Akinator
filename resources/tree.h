
const char* DUMP_DOT_NAME_FILES = "dump_tree.gv";

/*!
 \brief Cell list
 */
struct Cell_t  {
    TYPE_TREE data = 0;            ///<value element cell
    Cell_t* nextl;                 ///<pointer on previous element cell, if his on that it is empty (left)
    Cell_t* nextr;                 ///<pointer on previous element cell, if his on that it is empty (right)
    Cell_t* prev;                  ///<pointer on next element cell, if his on that it is empty
    int number;                    ///<cell number from the list
};


/*!
 \brief type list
 */
struct Tree_t {
    Cell_t* cell;                  ///<pointer on dynamic massif cells
    int size = 0;                  ///<size array cells
    Cell_t* position_first_cell;   ///<pointer to the first cell of the tree
    
        int position_number;           ///<number to a tree item
        Cell_t* position_cell;         ///<pointer to a tree item
    
};


enum ERROR {
    ERROR_NEW_CELL = 1,            ///<error creating a new tree cell
    ERROR_DUMP = 2,                ///<dump error
    ERROR_DEL_CELL = 3             ///<error removing the cell tree
};


enum PLUS_CELL {
    LEFT_cell = 1,                 ///<left direction
    RIGHT_cell = 2                 ///<right direction
};


/*!
 \brief TreeConstruct sheet constructor type TYPE_Tree
 \param element the first default item in the Tree
 \return pointer to TYPE_Tree type list
 */
Tree_t* TreeConstruct (TYPE_TREE element);


/*!
 \brief TreeDestructor sheet constructor type TYPE_Tree
 \param Tree pointer to TYPE type Tree
 \return int
 */
int TreeDestructor (Tree_t* Tree);


/*!
 \brief CellDelete an auxiliary function for removing tree cells, this function is used only in the TreeGoRound and in the TreeRecurs
 \param Tree pointer to TYPE type Tree
 \param cell pointer to a cell to delete
 \return Cell_t pointer to the previous branch in the tree
 */
Cell_t* TreeCellDelete(Tree_t* Tree, Cell_t* cell);


/*!
 \brief TreeAdd adding a new item
 \param Tree pointer to TYPE type Tree
 \param cell a pointer to the cell of the array
 \param next branch: LEFT_cell or RIGHT_cell
 \param element insertion element
 \return int
 */
int TreeAdd (Tree_t* Tree, Cell_t* cell, const int next, TYPE_TREE element);


/*!
 \brief TreeAddLeft adding a new element on the left branch
 \param Tree pointer to TYPE type Tree
 \param cell a pointer to the cell of the array
 \param element insertion element
 \return int
 */
int TreeAddLeft(Tree_t* Tree, Cell_t* cell, TYPE_TREE element);


/*!
 \brief TreeAddRight adding a new element on the right branch
 \param Tree pointer to TYPE type Tree
 \param cell a pointer to the cell of the array
 \param element insertion element
 \return int
 */
int TreeAddRight(Tree_t* Tree, Cell_t* cell, TYPE_TREE element);


/*!
 \brief TreeConstruct sheet constructor type TYPE_TREE
 \param Tree pointer to TYPE type Tree
 \param cell a pointer to the cell of the array
 \return int
 */
int TreeDelete (Tree_t* Tree, Cell_t* cell);


/*!
 \brief TreeDump dump on a sheet
 \param Tree pointer to TYPE type Tree
 \return int
 */
int TreeDump (Tree_t* Tree);


/*!
 \brief TreePrintNode1 (full format) recursive printing of cells into a dump, this function is used only in the TreeGoRound and in the TreeRecurs
 \param Tree pointer to TYPE type Tree
 \param cell print pointer to a dump cell
 \return Cell_t pointer to the previous branch in the tree
 */
Cell_t* TreePrintNode1 (Tree_t* Tree, Cell_t* cell);


/*!
 \brief TreePrintNode2 (full format) recursive printing of cells into a dump, this function is used only in the TreeGoRound and in the TreeRecurs
 \param Tree pointer to TYPE type Tree
 \param cell print pointer to a dump cell
 \return Cell_t pointer to the previous branch in the tree
 */
Cell_t* TreePrintNode2 (Tree_t* Tree, Cell_t* cell);


/*!
 \brief TreePrintNodeUSE1 (compressed format) recursive printing of cells into a dump, this function is used only in the TreeGoRound and in the TreeRecurs
 \param Tree pointer to TYPE type Tree
 \param cell print pointer to a dump cell
 \return Cell_t pointer to the previous branch in the tree
 */
Cell_t* TreePrintNodeUSE1 (Tree_t* Tree, Cell_t* cell);


/*!
 \brief TreePrintNodeUSE2 (compressed format) recursive printing of cells into a dump, this function is used only in the TreeGoRound and in the TreeRecurs
 \param Tree pointer to TYPE type Tree
 \param cell print pointer to a dump cell
 \return Cell_t pointer to the previous branch in the tree
 */
Cell_t* TreePrintNodeUSE2 (Tree_t* Tree, Cell_t* cell);


/*!
 \brief PositionCell search for a branch with a number in cell_number in the Tree
 \param Tree pointer to TYPE type Tree
 \param cell_number number of the desired branch
 \return Cell_t* pointer to the branch
 */
Cell_t* TreePositionCell (Tree_t* Tree, int cell_number);


/*!
 \brief TreePosRecurs recursively searches for a cell with a number, this function is used only in the TreeGoRound and in the TreeRecurs
 \param Tree pointer to TYPE type Tree
 \param cell print pointer to a dump cell
 \return Cell_t pointer to the previous branch in the tree
 */
Cell_t* TreePosRecurs (Tree_t* Tree, Cell_t* cell);


/*
 \brief error_prog searching for errors in the use of a tree
 \param number error number
 \return int
*/
int TreeErrorProg (int number);


/*!
 \brief TreeGoRound function of wood crocheting and processing
 \param Tree pointer to TYPE type Tree
 \param function This is an auxiliary function that will handle the final element of the tree branch, be sure to watch the ad
 \return int
 */
int TreeGoRound (Tree_t* Tree, Cell_t* (*function)(Tree_t*, Cell_t*));


/*!
 \brief TreeRecurs recursively traverses the entire tree by stopping on each finite branch
 \param pos_cell a pointer to the cell of the array
 \param function This is an auxiliary function that will handle the final element of the tree branch, be sure to watch the ad
 \return int returns a pointer to the previous branch element for recursive traversal (WARNING)!!!
 */
Cell_t* TreeRecurs (Tree_t* Tree, Cell_t* pos_cell, Cell_t* (*function)(Tree_t*, Cell_t*));


/*!
 \brief TreeReadFiles function that creates a new tree to the branch, read from a file
 \param name_files name of the file to read
 \param Tree pointer to TYPE type Tree
 \param cell pointer to a tree branch
 \return int
 */
int TreeReadFiles (const char* name_files, Tree_t* Tree, Cell_t* cell);


/*!
 \brief TreeReadFilesRecurs function to recursively read a file from the buffer and create new branches
 \param my_buffer buffer with the contents of the file
 \param number_of_char buffer size in characters
 \param Tree pointer to TYPE type Tree
 \param cell pointer to a tree branch
 \param next branch: LEFT_cell or RIGHT_cell
 \return pointer to a new buffer
 */
char* TreeReadFilesRecurs (char* my_buffer, long int number_of_char, Tree_t* Tree, Cell_t* cell, int next);


/*!
 \brief ReadFiles file reading function
 \param name_files name of the file to read
 \param number_of_char buffer size in characters
 \return pointer to a new buffer
 */
char* ReadFiles (const char* name_files, long int *number_of_char);






/*
 |===================|
 |                   |
 |     function      |
 |                   |
 |===================|
*/



Tree_t*  TreeConstruct (TYPE_TREE element)
{
    Tree_t* Tree = new Tree_t;
    
    Cell_t* cell = new Cell_t;
    cell->data = element;
    cell->number = 0;
    cell->prev = NULL;
    cell->nextl = NULL;
    cell->nextr = NULL;
    
    Tree->cell = cell;
    
        Tree->position_number = 0;
        Tree->position_cell = NULL;
    
    Tree->position_first_cell = Tree->cell;
    Tree->size = 1;
    return Tree;
}



int TreeDestructor (Tree_t* Tree) {
    assert(Tree);
    TreeGoRound (Tree, TreeCellDelete);
    delete Tree;
    return 0;
}



Cell_t* TreeCellDelete(Tree_t* Tree, Cell_t* cell) {
    assert(cell);
    Cell_t* pos_cell_prev = cell->prev;
    
    delete cell;
    
    return pos_cell_prev;
}


//после
int TreeAdd(Tree_t* Tree, Cell_t* cell, int next, TYPE_TREE element) {
    assert(cell);
    assert(Tree);
    Cell_t* new_cell = new Cell_t;
    if (new_cell == NULL)
        return ERROR_NEW_CELL;
    new_cell->data = element;
    new_cell->number = Tree->size;
    new_cell->prev = cell;
    new_cell->nextl = NULL;
    new_cell->nextr = NULL;
    
    if (next == LEFT_cell)
        cell->nextl = new_cell;
    else
        if (next == RIGHT_cell)
            cell->nextr = new_cell;
    //вывод ошибки!!!!!!!!!!!!!!!!!!!!!!!!!!!
    
    ++Tree->size;
    return 0;
}



int TreeAddLeft(Tree_t* Tree, Cell_t* cell, TYPE_TREE element) {
    assert(cell);
    assert(Tree);
    TreeAdd(Tree, cell, LEFT_cell, element);
    return 0;
}



int TreeAddRight(Tree_t* Tree, Cell_t* cell, TYPE_TREE element) {
    assert(cell);
    assert(Tree);
    TreeAdd(Tree, cell, RIGHT_cell, element);
    return 0;
}



//удаление
int TreeDelete (Tree_t* Tree, Cell_t* cell) {
    assert(cell);
    assert(Tree);
    
    if ((cell->nextl == NULL) && (cell->nextr == NULL)) {
        delete cell;
        --Tree->size;
        return 0;
    }
    return ERROR_DEL_CELL;
}




int TreeDump (Tree_t* Tree) {
    assert(Tree);
    
    FILE *file_dump = fopen(DUMP_DOT_NAME_FILES,"wt");
    if (file_dump == NULL)
        return ERROR_DUMP;
    fprintf(file_dump, "digraph list {\n\tnode [shape = record,height=.1];\n");
    fclose(file_dump);
    
    TreeGoRound (Tree, TreePrintNodeUSE1);
    TreeGoRound (Tree, TreePrintNodeUSE2);
    
    file_dump = fopen(DUMP_DOT_NAME_FILES,"at");
    if (file_dump == NULL)
        return ERROR_DUMP;
    fprintf(file_dump, "}");
    fclose(file_dump);
    
    system("open -a /Applications/Graphviz.app '/Users/macbook/Documents/GitHub/Tree/Tree/dump_tree.gv'");
    
    return 0;
}

Cell_t* TreePrintNodeUSE1 (Tree_t* Tree, Cell_t* cell) {
    FILE *file_dump = fopen(DUMP_DOT_NAME_FILES,"at");
    
    fprintf(file_dump, "\t\"node%i\" [label = \"<f0>data = %s\" ] ;\n", cell->number, cell->data);
    
    fclose(file_dump);
    return cell->prev;
}



Cell_t* TreePrintNodeUSE2 (Tree_t* Tree, Cell_t* cell) {
    FILE *file_dump = fopen(DUMP_DOT_NAME_FILES,"at");
    
    if (cell->nextl != NULL)
        fprintf(file_dump, "\t\"node%i\":f0 -> \"node%i\":f0 [color=""red""];\n", cell->number, (cell->nextl)->number);
    if (cell->nextr != NULL)
        fprintf(file_dump, "\t\"node%i\":f0 -> \"node%i\":f0  [color=""green""];\n", cell->number, (cell->nextr)->number);
    
    fclose(file_dump);
    return cell->prev;
}

Cell_t* TreePrintNode1 (Tree_t* Tree, Cell_t* cell) {
    FILE *file_dump = fopen(DUMP_DOT_NAME_FILES,"at");
    
    fprintf(file_dump, "\t\"node%i\" [label = \"<f0>data = %s |<f1>nextl = %p |<f2>nextr = %p |<f3>pos = %p |<f4>prev = %p\" ] ;\n", cell->number, cell->data, cell->nextl, cell->nextr, cell, cell->prev);
    
    fclose(file_dump);
    return cell->prev;
}



Cell_t* TreePrintNode2 (Tree_t* Tree, Cell_t* cell) {
    FILE *file_dump = fopen(DUMP_DOT_NAME_FILES,"at");
    
    if (cell->nextl != NULL)
        fprintf(file_dump, "\t\"node%i\":f1 -> \"node%i\":f3;\n", cell->number, (cell->nextl)->number);
    if (cell->nextr != NULL)
        fprintf(file_dump, "\t\"node%i\":f2 -> \"node%i\":f3;\n", cell->number, (cell->nextr)->number);
    if (cell->prev != NULL)
        fprintf(file_dump, "\t\"node%i\":f4 -> \"node%i\":f3;\n", cell->number, (cell->prev)->number);
    
    fclose(file_dump);
    return cell->prev;
}



Cell_t* TreePositionCell (Tree_t* Tree, int cell_number) {
    assert(Tree);
    Tree->position_cell = NULL;
    Tree->cell = Tree->position_first_cell;
    Tree->position_number = cell_number;
    TreeGoRound(Tree, TreePosRecurs);
    
    return Tree->position_cell;
}



Cell_t* TreePosRecurs (Tree_t* Tree, Cell_t* cell) {
    if (Tree->position_number == cell->number) {
        Tree->position_cell = cell;
    }
    return cell->prev;
}



int TreeGoRound (Tree_t* Tree, Cell_t* (*function)(Tree_t*, Cell_t*)) {
    assert(function);
    assert(Tree);
    
    Tree->cell = Tree->position_first_cell;;
    TreeRecurs (Tree, Tree->cell, function);
    return 0;
}



Cell_t* TreeRecurs (Tree_t* Tree, Cell_t* pos_cell, Cell_t* (*function)(Tree_t*, Cell_t*)) {
    assert(function);
    assert(Tree);
    assert(pos_cell);
    
    if (pos_cell->nextl != NULL) {
        pos_cell = pos_cell->nextl;
        pos_cell = TreeRecurs(Tree, pos_cell, function);
    }
    if (pos_cell->nextr != NULL) {
        pos_cell = pos_cell->nextr;
        pos_cell = TreeRecurs(Tree, pos_cell, function);
    }
    // тут можно что-то юзать :)
    // крч используй функцию что бы юзать
    //printf( "\t\"node%i\" [label = \"<f0>data = %s |<f1>nextl = %p |<f2>nextr = %p |<f3>pos = %p |<f4>prev = %p\" ] ;\n", pos_cell->number, pos_cell->data, pos_cell->nextl, pos_cell->nextr, pos_cell, pos_cell->prev);
    pos_cell = function (Tree, pos_cell); // функция обязательна должна возвращать pos_prev указатель на предыдующую ветку дерева!!!!!!!!
    return pos_cell;
}



int TreeReadFiles (const char* name_files, Tree_t* Tree, Cell_t* cell, const int next) {
    
    long int number_of_char = 0;
    
    char* my_buffer = ReadFiles (name_files, &number_of_char);
    
    TreeReadFilesRecurs(my_buffer, number_of_char, Tree, cell, next);
    
    return 0;
}



char* TreeReadFilesRecurs (char* my_buffer, long int number_of_char, Tree_t* Tree, Cell_t* cell, int next) {
    
    //craft
    char* str = new char [20];
    
    for (int i = 0; ((i < number_of_char) && (my_buffer [0] != '\'')); ++i, ++my_buffer) {//printf("%c", my_buffer[0]);
    }
    ++my_buffer;
    for (int i = 0; my_buffer [i] != '\''; ++i) {
        str [i] = my_buffer [i];
        str [i+1] = '\0';
    }
    printf("%s\n",str);
    for (int i = 0; ((i < number_of_char) && (my_buffer [0] != '(') && (my_buffer [0] != ')')); ++i, ++my_buffer) {//printf("%c", my_buffer[0]);
    }
    Cell_t* cell_new = new Cell_t;
    cell_new->data = str;
    cell_new->number = Tree->size;
    cell_new->prev = cell;
    cell_new->nextl = NULL;
    cell_new->nextr = NULL;
    ++Tree->size;
    
    if (next == LEFT_cell)
        cell->nextl = cell_new;
    else
        if (next == RIGHT_cell)
            cell->nextr = cell_new;
    
    printf("%c\n", my_buffer [0]);
    
    if (my_buffer [0] == '(') {
        my_buffer = TreeReadFilesRecurs(my_buffer, number_of_char, Tree, cell_new, LEFT_cell);
        my_buffer = TreeReadFilesRecurs(my_buffer, number_of_char, Tree, cell_new, RIGHT_cell);
    }
        
    return my_buffer;
}



char* ReadFiles (const char* name_files, long int *number_of_char) {
    
    
    FILE *files = fopen (name_files, "rt");
    
    
    if (files == NULL)
    {
        assert(files != NULL);
    }
    
    fseek (files, 0, SEEK_END);
    *number_of_char = ftell(files);
    
    char* file_validation = new char [++*number_of_char];
    
    
    fseek (files, 0, SEEK_SET);
    fread (file_validation, sizeof (char), *number_of_char, files);
    fclose (files);
    file_validation [*number_of_char - 1] = '\0';
    return file_validation;
}



int TreeErrorProg (int number) {
    switch (number) {
        case ERROR_DUMP:
            printf("\ndump error in .dot\n");
            assert(0);
            break;
            
        case ERROR_NEW_CELL:
            printf("\nerror of writing a new cell to the list\n");
            assert(0);
            break;
            
        case ERROR_DEL_CELL:
            printf("\nerror on deleting the desired item\n");
            assert(0);
            break;
            
        case 0:
            return 0;
            break;
            
        default:
            printf("\nunknown error %i\n", number);
            assert(0);
            break;
    }
    return 0;
}


