

/*!
 \brief Cell list
 */
struct Cell_t  {
    TYPE_TREE data = 0; ///<value element cell
    Cell_t* nextl;    ///<pointer on previous element cell, if his on that it is empty (left)
    Cell_t* nextr;    ///<pointer on previous element cell, if his on that it is empty (right)
    Cell_t* prev;    ///<pointer on next element cell, if his on that it is empty
    int number;         ///<cell number from the list
};


/*!
 \brief type list
 */
struct Tree_t {
    Cell_t* cell;                  ///<pointer on dynamic massif cells
    int size = 0;                  ///<size array cells
    Cell_t* position_cell;         ///<pointer to a list item
    Cell_t* position_first_cell;   ///<pointer to the first cell of the list
};


enum ERROR {
    ERROR_NEW_CELL = 1,
    ERROR_DUMP = 2
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
Cell_t* CellDelete(Cell_t* cell);


/*!
 \brief TreeConstruct sheet constructor type TYPE_Tree
 \param Tree pointer to TYPE type Tree
 \param cell a pointer to the cell of the array
 \param Cell_new_adress pointer to the selected branch
 \param element insertion element
 \return int
 */
int TreeAdd (Tree_t* Tree, Cell_t* cell, Cell_t* Cell_new_adress, TYPE_TREE element);


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


Cell_t* PositionCell (Tree_t* Tree, int cell_number);


int TreeComparison (const void* pcell1, const void* pcell2);


int error_prog (int number);


int TreeGoRound (Tree_t* Tree, Cell_t* (*function)(Cell_t*));


Cell_t* TreeRecurs (Cell_t* pos_cell, Cell_t* (*function)(Cell_t*));








/*
 |===================|
 |                   |
 |     function      |
 |                   |
 |===================|
*/



Tree_t*  ListConstruct (TYPE_TREE element)
{
    Tree_t* Tree = new Tree_t;
    
    Cell_t* cell = new Cell_t;
    cell->data = element;
    cell->number = 0;
    cell->prev = NULL;
    cell->nextl = NULL;
    cell->nextr = NULL;
    
    Tree->cell = cell;
    Tree->position_cell = NULL;
    Tree->position_first_cell = Tree->cell;
    Tree->size = 1;
    return Tree;
}



int TreeDestructor (Tree_t* Tree) {
    assert(Tree);
    TreeGoRound (Tree, CellDelete);
    delete Tree;
    return 0;
}



Cell_t* CellDelete(Cell_t* cell) {
    assert(cell);
    Cell_t* pos_cell_prev = cell->prev;
    
    delete cell;
    
    return pos_cell_prev;
}



//после
int TreeAdd(Tree_t* Tree, Cell_t* cell, Cell_t* Cell_new_adress, TYPE_TREE element) {
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
    
    Cell_new_adress = new_cell;
    
    ++Tree->size;
    return 0;
}

//удаление
int TreeDelete (Tree_t* Tree, Cell_t* cell) {
    assert(cell);
    assert(Tree);
    
    
    
    delete cell;
    --Tree->size;
    return 0;
}



/*
int TreeDump (Tree_t* Tree) {
    assert(Tree);
    
    FILE *file_dump = fopen("dump.gv","wt");
    if (file_dump == NULL)
        return ERROR_DUMP;
    
    fprintf(file_dump, "digraph list {\n\tnode [shape = record,height=.1];\n");
    
    Tree->cell = Tree->position_first_cell;
    
    for (long int i = 0; i < Tree->size; ++i) {
        fprintf(file_dump, "\t\"node%i\" [label = \"<f0>data = %s |<f1>next = %p |<f2>pos = %p |<f3>prev = %p\" ] ;\n", (Tree->cell)->number, (Tree->cell)->data, (Tree->cell)->next, Tree->cell, (Tree->cell)->prev);
        Tree->cell = (Tree->cell)->next;
        
    }
    
    Tree->cell = Tree->position_first_cell;
    
    for (long int i = 0; i < Tree->size; ++i) {
        if ((Tree->cell)->next != NULL)
            fprintf(file_dump, "\t\"node%i\":f1 -> \"node%i\":f2;\n", (Tree->cell)->number, ((Tree->cell)->next)->number);
        if ((Tree->cell)->prev != NULL)
            fprintf(file_dump, "\t\"node%i\":f3 -> \"node%i\":f2;\n", (Tree->cell)->number, ((Tree->cell)->prev)->number);
        
        Tree->cell = (Tree->cell)->next;
    }
    
    fprintf(file_dump, "}");
                       
    fclose(file_dump);
    system("open -a /Applications/Graphviz.app '/Users/macbook/Documents/GitHub/List/Lists/dump.gv'");
    
    return 0;
}
*/


Cell_t* PositionCell (Tree_t* Tree, int cell_number) {
    assert(Tree);
    Tree->cell = Tree->position_first_cell;
    
    for (int i = 0; i < Tree->size; ++i) {
        if ((Tree->cell)->number == cell_number) {
            return Tree->cell;
        }
        //Tree->cell = (Tree->cell)->next;
    }
    return NULL;
}



int TreeGoRound (Tree_t* Tree, Cell_t* (*function)(Cell_t*)) {
    assert(function);
    assert(Tree);
    
    Tree->cell = Tree->position_first_cell;
    Cell_t* pos_cell = Tree->cell;
    while (pos_cell->nextl != NULL) {
        pos_cell = pos_cell->nextl;
    }
    TreeRecurs (pos_cell, function);
    return 0;
}



Cell_t* TreeRecurs (Cell_t* pos_cell, Cell_t* (*function)(Cell_t*)) {
    assert(function);
    assert(pos_cell);
    
    if (pos_cell->nextl != NULL) {
        pos_cell = pos_cell->nextl;
        TreeRecurs(pos_cell, function);
    }
    if (pos_cell->nextr != NULL) {
        pos_cell = pos_cell->nextr;
        TreeRecurs(pos_cell, function);
    }
    // тут можно что-то юзать :)
    // крч используй функцию что бы юзать
    
    pos_cell = function (pos_cell); // функция обязательна должна возвращать pos_prev указатель на предыдующую ветку дерева!!!!!!!!
    assert(pos_cell);
    return pos_cell;
}



int error_prog (int number) {
    switch (number) {
        case ERROR_DUMP:
            printf("\ndump error in .dot\n");
            assert(0);
            break;
            
        case ERROR_NEW_CELL:
            printf("\nerror of writing a new cell to the list\n");
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


