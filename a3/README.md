To compile:
  gcc test_bst.c bst.c -o test_bst -g

To run:
  valgrind --leak-check=yes ./test_bst

Array form of BST is faster than node_t form.
0.000191 secs vs 0.000109 secs
