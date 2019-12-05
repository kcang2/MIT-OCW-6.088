#include <assert.h>
#include <stdio.h>
#include "bst.h"
#include <time.h>

int main() {
  clock_t start;
  clock_t end;
  double time_taken;
  start = clock();


  /* Insert 0. */
  node_t* cur = make_tree(1);
  print_bst(cur);
  printf("\n");
  assert(find_val(1, cur) == TRUE);

  /* Insert 1. */
  insert(0, cur);
  assert(find_val(0, cur) == TRUE);
  print_bst(cur);
  printf("\n");

  /* Insert 2. */
  insert(2, cur);
  assert(find_val(2, cur) == TRUE);

  /* Print the tree. */
  print_bst(cur);
  printf("\n");

  /* Insert 4. */
  insert(4, cur);
  assert(find_val(4, cur) == TRUE);
  print_bst(cur);
  printf("\n");

  /* Insert 3 */
  insert(3, cur);
  assert(find_val(3, cur) == TRUE);
  print_bst(cur);
  printf("\n");

  /* ADD YOUR TESTS HERE. */
  assert(find_val(33, cur) == FALSE);
  insert(4, cur);  // Duplicate
  insert(6, cur);
  insert(5, cur);
  insert(7, cur);
  print_bst(cur);
  printf("\n");

  /* Delete the list. */
  delete_bst(cur);

  end = clock();
  time_taken = ((double) (end-start)/CLOCKS_PER_SEC);
  printf("Time: %f seconds\n", time_taken);

  return 0;
}
