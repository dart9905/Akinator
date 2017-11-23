//
//  main.cpp
//  Tree
//
//  Created by macbook on 15.11.2017.
//  Copyright © 2017 macbook. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <cassert>
#include <string.h>
#include <math.h>

const char* TREE_FILES = "../resources/save1.txt";
const char* TREE_FILES1 = "../resources/save1.txt";

    typedef char* TYPE_TREE;
    #include "../resources/tree.h"

    typedef char* TYPE_LIST;
    #include "../resources/List.h"


int Dialog (char* str, Tree_t* Tree);



int AkinatorGo (Tree_t* Tree);



int AkinatorSay (Tree_t* Tree, char* str);



int AkinatorPlus (Tree_t* Tree);



int AkinatorIf (Tree_t* Tree);



int AkinatorSayPrint (Tree_t* Tree, Cell_t* cell);



int AkinatorBool (Tree_t* Tree);



int List_Tree (Cell_t* cell, List_t* list);



char* No_Cell (char* str);



int _SAY_(const char* str1, const char* str2, const char* str3);



int main(int argc, const char * argv[]) {
    // insert code here...
    
    char str [20];
    
    Tree_t* Tree = TreeConstruct("Привет");
    
    TreeReadFiles(TREE_FILES,Tree, Tree->cell, LEFT_cell);
    
    do {
        printf("-> ");
        scanf("%s",str);
        Dialog (str, Tree);
    } while (strcmp(str,"пока") != 0);
    
    Tree->cell = Tree->position_first_cell;
    
    TreePrintFile(Tree, Tree->cell->nextl);
    
    TreeDump(Tree, Tree->cell->nextl);
    
    TreeDestructor(Tree);
    
    
    return 0;
}



int Dialog (char* str, Tree_t* Tree) {
    assert(Tree);
    if (strcmp(str,"пока") == 0) {
        return 0;
    }
    if (strcmp(str,"найди") == 0) {
        char str [CELL_SIZE_DATA];
        scanf("%s", str);
        AkinatorSay (Tree, str);
        return 0;
    }
    if (strcmp(str,"говори") == 0) {
        Tree->cell = Tree->position_first_cell;
        AkinatorGo (Tree);
        return 0;
    }
    if (strcmp(str,"разница") == 0) {
        Tree->cell = Tree->position_first_cell;
        AkinatorBool(Tree);
        return 0;
    }
    if (strcmp(str,"помощь") == 0) {
        printf("пока - завершение диалога\n");
        printf("найди 'слово' - находит и определяет слово\n");
        printf("говори - начинает диалог\n");
        printf("разница 'слово1' 'слово2'- показывает разницу между словами\n");
        printf("помощь - вызывает помощь\n");
        system("say ""пока - завершение диалога""");
        system("say ""найди 'слово' - находит и определяет слово""");
        system("say ""говори - начинает диалог""");
        system("say ""разница 'слово1' 'слово2'- показывает разницу между словами""");
        system("say ""помощь - вызывает помощь""");
        return 0;
    }
    return 0;
}


int AkinatorGo (Tree_t* Tree) {
    assert(Tree);
    Tree->cell = Tree->position_first_cell;
    char str [CELL_SIZE_DATA];
    char str_say [CELL_SIZE_DATA+CELL_SIZE_DATA];
    do {
        if ((Tree->cell->nextl != NULL) && (Tree->cell->nextr != NULL)) {
            printf ("Это %s?\n", Tree->cell->data);
            _SAY_("Это ", Tree->cell->data, "?");
            scanf("%s", str);
            if ((strcmp(str,"Угадала") == 0) || (strcmp(str,"Правильно") == 0)) {
                system("say ""Здорово!""");
                return 0;
            }
            
            if ((strcmp(str,"не") != 0) && (strcmp(str,"нет") != 0))
                Tree->cell = Tree->cell->nextr;
            else
                Tree->cell = Tree->cell->nextl;
        }
        
        if ((Tree->cell->nextl != NULL) && (Tree->cell->nextr == NULL)) {
            printf ("%s\n", Tree->cell->data);
            Tree->cell = Tree->cell->nextl;
        }
            
        if ((Tree->cell->nextl == NULL) && (Tree->cell->nextr != NULL)) {
            printf ("%s\n", Tree->cell->data);
            Tree->cell = Tree->cell->nextr;
        }
        
        if ((Tree->cell->nextl == NULL) && (Tree->cell->nextr == NULL)) {
            printf ("Это %s\n", Tree->cell->data);
            _SAY_("Это ", Tree->cell->data, ".");
            scanf("%s", str);
            if ((strcmp(str,"точнее") == 0) ) {
                AkinatorIf (Tree);
            }
            if ((strcmp(str,"не") == 0) || (strcmp(str,"нет") == 0))
                AkinatorPlus (Tree);
            
            system("say ""Здорово!""");
            return 0;
        }
            
        
    } while (true);
    
    return 0;
}



int AkinatorPlus (Tree_t* Tree) {
    assert(Tree);
    
    char* str1 = new char [CELL_SIZE_DATA];
    char* str2 = new char [CELL_SIZE_DATA];
    Cell_t* cell_new1 = CellNew (Tree);
    Cell_t* cell_new2 = CellNew (Tree);
    
    
    
    printf("Что это тогда?\n");
    system("say ""Что это тогда?""");
    scanf("%s", str1);
    printf("А чем отличается от %s?\n", Tree->cell->data);
    _SAY_("А чем отличается от ", Tree->cell->data, ".");
    scanf("%s", str2);
    
    cell_new1->data = Tree->cell->data;
    cell_new2->data = str1;
    Tree->cell->data = str2;
    
    
    cell_new1->prev = Tree->cell;
    cell_new2->prev = Tree->cell;
    
    Tree->cell->nextl = cell_new1;
    Tree->cell->nextr = cell_new2;
    
    
    return 0;
}


int AkinatorIf (Tree_t* Tree) {
    assert(Tree);
    
    char* str1 = new char [CELL_SIZE_DATA];
    char* str2 = new char [CELL_SIZE_DATA];
    Cell_t* cell_new1 = CellNew (Tree);
    Cell_t* cell_new2 = CellNew (Tree);
    
    
    
    printf("Что это тогда?\n");
    system("say ""Что это тогда?""");
    scanf("%s", str1);
    printf("А не %s?\n", Tree->cell->data);
    _SAY_("А не ", Tree->cell->data, "?");
    scanf("%s", str2);
    
    cell_new1->data = str1;
    cell_new2->data = str2;
    
    
    cell_new1->prev = Tree->cell;
    cell_new2->prev = Tree->cell;
    
    Tree->cell->nextl = cell_new2;
    Tree->cell->nextr = cell_new1;
    
    
    return 0;
}



int AkinatorSay (Tree_t* Tree, char* str) {
    
    Tree->str_param = str;
    Tree->position_cell = TreePositionCell_data(Tree, Tree->position_first_cell);
    
    if (Tree->position_cell != NULL)
        AkinatorSayPrint (Tree, Tree->position_cell);
    else {
        printf("Извините, я ничего не нашла(\n");
        system("say ""Извините, я ничего не нашла...""");
    }
    
    return 0;
}



int AkinatorSayPrint (Tree_t* Tree, Cell_t* cell) {
    
    printf("%s - ", cell->data);
    
    _SAY_("", cell->data, " - ");
    
    Cell_t* cell_copy;
    
        cell_copy = cell;
        cell = cell->prev;
        do {
            if (cell->prev != NULL)
                if (cell_copy->prev->nextl == cell_copy) {
                    printf("не ");
                    system("say ""не""");
                }
            printf("%s ", cell->data);
            
            _SAY_("", cell->data, "");
            
            cell_copy = cell;
            cell = cell->prev;
            
        } while (cell->prev != NULL);
        printf(".\n");
    return 0;
}



int AkinatorBool (Tree_t* Tree) {
    
    char str1 [CELL_SIZE_DATA];
    char str2 [CELL_SIZE_DATA];
    scanf("%s", str1);
    scanf("%s", str2);
    
    Tree->str_param = str1;
    Cell_t* cell1 = TreePositionCell_data(Tree, Tree->position_first_cell);
    
    Tree->str_param = str2;
    Cell_t* cell2 = TreePositionCell_data(Tree, Tree->position_first_cell);
    
    List_t* list1 = ListConstruct(cell1->data);
    List_t* list2 = ListConstruct(cell2->data);
    
    list1->position_cell = list1->position_first_cell;
    list2->position_cell = list2->position_first_cell;
    
    List_Tree(cell1, list1);
    List_Tree(cell2, list2);
    
    list1->position_cell = list1->position_cell->prev;
    list2->position_cell = list2->position_cell->prev;
    
    
    
    while ((list2->position_cell != NULL) && (list1->position_cell != NULL) &&
           (strcmp(list1->position_cell->data, list2->position_cell->data) == 0)) {
        printf("они оба %s\n", list1->position_cell->data);
        
        _SAY_("они оба ", list1->position_cell->data, ".");
        
        list1->position_cell = list1->position_cell->prev;
        list2->position_cell = list2->position_cell->prev;
        
        
    }
    
    
    while ((list1->position_cell != NULL) && (list1->position_cell->prev != NULL)) {
        printf("%s %s\n", str1, list1->position_cell->data);
        
        _SAY_(str1, list1->position_cell->data, ".");
        
        list1->position_cell = list1->position_cell->prev;
    }
    
    while ((list2->position_cell != NULL) && (list2->position_cell->prev != NULL)) {
        printf("%s %s\n", str2, list2->position_cell->data);
        
        _SAY_(str2, list2->position_cell->data, ".");
        
        list2->position_cell = list2->position_cell->prev;
    }
    
    delete list1;
    delete list2;
    
    
    return 0;
}



int List_Tree (Cell_t* cell, List_t* list) {
    
    Cell_t* cell_copy;
    
    while (cell->prev != NULL) {
        cell_copy = cell;
        cell = cell->prev;
        
        if ((cell_copy->prev != NULL) && (cell_copy == cell_copy->prev->nextl)) {
            ListAddBefore(list, list->position_cell, No_Cell (cell->data));
        
        } else
            ListAddBefore(list, list->position_cell, cell->data);
        
        list->position_cell = list->position_cell->next;
    }
    return 0;
}



char* No_Cell (char* str) {
    char* str_new = new char [CELL_SIZE_DATA * 2];
    str_new [0] = '\0';
    
    strcat(str_new, "не ");
    strcat(str_new, str);
    
    return str_new;
}



int _SAY_(const char* str1, const char* str2, const char* str3) {
    assert(str1);
    assert(str2);
    assert(str3);
    
    char str_say [CELL_SIZE_DATA * 5];
    str_say [0] = '\0';
    
    strcat(str_say, "say """);
    strcat(str_say, str1);
    strcat(str_say, str2);
    strcat(str_say, str3);
    strcat(str_say, """");
    system(str_say);
    
    return 0;
}
