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


    typedef char* TYPE_TREE;
    #include "../resources/tree.h"

const char* TREE_FILES = "../resources/save.txt";


int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    
    Tree_t* Tree = TreeConstruct("Hello");
    
    TreeReadFiles(TREE_FILES,Tree, Tree->cell, LEFT_cell);
    
    
    
    TreeDump(Tree);
    
    TreeDestructor(Tree);
    
    
    return 0;
}
