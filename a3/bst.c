#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

bst_t* make_tree(int size) {
    bst_t* bst = malloc(sizeof(bst_t));
    bst->vals = malloc(sizeof(int)*size);
    bst->size = size;
    return bst;
}


void init_tree(bst_t* bst) {
   for (int i=0; i < bst->size; ++i) {
   	bst->vals[i] = -1; // Init all to -1
   }
}

int recursive_index(int val, int i, bst_t* tree) {
   if (tree->vals[i] > val) {  // left
        if (2*i+1 < tree->size) {
	  if (tree->vals[2*i+1] < 0)  // new left
	    return 2*i+1;
	  else   // existing left
	    return recursive_index(val, 2*i+1, tree);
	}
        else
          return -1; // out-of-bounds
   }

   else if (tree->vals[i] < val) {  // right
        if (2*i+2 < tree->size) {
	  if (tree->vals[2*i+2] < 0)  // new right
	    return 2*i+2;
	  else   // existing right
	    return recursive_index(val, 2*i+2, tree);
	}
        else // out-of-bounds
          return -1;
   }

   else  // equal value
	return -1;
   
}

void insert(int val, bst_t* tree) {
   if (tree->vals[0] < 0) {  // 1st insertion
   	tree->vals[0] = val;
	return;
   }

   int i = recursive_index(val, 0, tree);
   if (i >= 0)
   	tree->vals[i] = val; 
}

bool find_val(int val, bst_t* tree) {
   int i = recursive_index(val, 0, tree);
   if (i < 0)
        return 1;
   else
	return 0;
}

void delete_bst(bst_t* tree) {
   free(tree->vals);
   free(tree);
}

void pre_order(int i, bst_t* tree) {
   if (tree->vals[i] >= 0) {
        printf("%d ", tree->vals[i]);
	if (2*i+1 >= tree->size)  // out-of-bounds
		return;
	pre_order(2*i+1, tree);
	pre_order(2*i+2, tree);
   }
}

void print_bst(bst_t* tree) {
   pre_order(0, tree);
}

