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

int Dialog (char* str, Tree_t* Tree);



int AkinatorGo (Tree_t* Tree);



int AkinatorSay (Tree_t* Tree, char* str);



int AkinatorPlus (Tree_t* Tree);



Cell_t* AkinatorSayRecurs (Tree_t* Tree, Cell_t* cell);




int main(int argc, const char * argv[]) {
    // insert code here...
    char str [20];
    
    Tree_t* Tree = TreeConstruct("Hello");
    
    TreeReadFiles(TREE_FILES,Tree, Tree->cell, LEFT_cell);
    
    Dialog ("help", Tree);
    
    do {
        printf("-> ");
        scanf("%s",str);
        Dialog (str, Tree);
    } while (strcmp(str,"bye") != 0);
    
    Tree->cell = Tree->position_first_cell;
    
    TreePrintFile(Tree, Tree->cell->nextl);
    
    TreeDump(Tree, Tree->cell->nextl);
    
    TreeDestructor(Tree);
    
    
    return 0;
}



int Dialog (char* str, Tree_t* Tree) {
    assert(Tree);
    if (strcmp(str,"bye") == 0) {
        return 0;
    }
    if (strcmp(str,"say") == 0) {
        char str [CELL_SIZE_DATA];
        scanf("%s", str);
        AkinatorSay (Tree, str);
        return 0;
    }
    if (strcmp(str,"go") == 0) {
        Tree->cell = Tree->position_first_cell;
        AkinatorGo (Tree);
        return 0;
    }
    if (strcmp(str,"help") == 0) {
        printf("bye - complete the dialogue program\n");
        printf("say 'word' - say the definition of a word\n");
        printf("go - start a dialogue\n");
        printf("help - help on commands\n");
        return 0;
    }
    return 0;
}


int AkinatorGo (Tree_t* Tree) {
    assert(Tree);
    Tree->cell = Tree->position_first_cell;
    char str [20];
    do {
        if ((Tree->cell->nextl != NULL) && (Tree->cell->nextr != NULL)) {
            printf ("this is a %s?\n", Tree->cell->data);
            scanf("%s", str);
            if ((strcmp(str,"y") == 0) || (strcmp(str,"yes") == 0))
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
            printf ("this is a %s\n", Tree->cell->data);
            scanf("%s", str);
            if ((strcmp(str,"y") != 0) && (strcmp(str,"yes") != 0))
                AkinatorPlus (Tree);
            return 0;
        }
            
        
    } while (true);
    
    return 0;
}



int AkinatorPlus (Tree_t* Tree) {
    assert(Tree);
    char* str1 = new char [CELL_SIZE_DATA];
    char* str2 = new char [CELL_SIZE_DATA];
    
    printf("And what is this?\n");
    scanf("%s", str1);
    
    printf("but what is different from a %s?\n", Tree->cell->data);
    scanf("%s", str2);
    
    Cell_t* cell_new1 = CellNew(Tree);
    Cell_t* cell_new2 = CellNew(Tree);
    
    cell_new1->data = Tree->cell->data;
    cell_new2->data = str1;
    Tree->cell->data = str2;
    
    cell_new1->prev = Tree->cell;
    cell_new2->prev = Tree->cell;
    
    Tree->cell->nextl = cell_new1;
    Tree->cell->nextr = cell_new2;
    
    printf ("Thank you\n");
    
    return 0;
}



int AkinatorSay (Tree_t* Tree, char* str) {
    Tree->str_param = str;
    TreeGoRound(Tree, Tree->position_first_cell, AkinatorSayRecurs, FROM_BELOW);
    return 0;
}



Cell_t* AkinatorSayRecurs (Tree_t* Tree, Cell_t* cell) {
    if (strcmp(Tree->str_param,cell->data) == 0) {
        Tree->position_cell = cell;
        printf("%s -", Tree->position_cell->data);
        
        do {
            if (Tree->position_cell->prev->nextr != Tree->position_cell)
                printf(" ne");
            Tree->position_cell = Tree->position_cell->prev;
            printf(" %s", Tree->position_cell->data);
            
        } while (Tree->position_cell->prev != NULL);
        printf(".\n");
    }
    return cell->prev;
}
