#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

/*
 * Creates a new node from a given value, allocating heap memory for it.
 */
node_t* make_tree(int val) {
  node_t* new_tree = malloc(sizeof(node_t));
  new_tree->val = val;
  new_tree->left = NULL;
  new_tree->right = NULL;
  return new_tree;
}

/*
 * Inserts a new value into a given binary search tree, allocating heap memory
 * for it.
 */
void insert(int val, node_t* cur_root) {
  if (val < cur_root -> val) { // go left
	if (cur_root -> left == NULL) {  // new left
		node_t* temp = make_tree(val);
		cur_root -> left = temp;
		return;
	}
	else {  // existing left
		insert(val, cur_root -> left);
	}
  }

  else if (val > cur_root -> val) {  // go right
	if (cur_root -> right == NULL) {  // new right
		node_t* temp = make_tree(val);
		cur_root -> right = temp;
		return;
	}
	else {  // existing right
		insert(val, cur_root -> right);
	}
  }

  else {  // equal value
  	return;
  }

  return;
}

bool find_val(int val, node_t* root) {
  if (val < root->val) { // try left
	if (root->left != NULL)
		return find_val(val, root->left);
	else
		return 0;
  }

  else if (val > root->val) { // try right
	if (root->right != NULL)
		return find_val(val, root->right);
	else
		return 0;
  }

  else { // equal
	return 1;
  }

}

/*
 * Given a pointer to the root, frees the memory associated with an entire tree.
 */
void delete_bst(node_t* root) {
// Post-order traversal
  if (root->left != NULL)
  	delete_bst(root->left);
  
  if (root->right != NULL) 
	delete_bst(root->right);
 
  free(root);
}

/* Given a pointer to the root, prints all o fthe values in a tree. */
void print_bst(node_t* root) {
  if (root != NULL) {  // Pre-order traversal
    printf("%d ", root->val);
    print_bst(root->left);
    print_bst(root->right);
  }
  return;
}
