#include <stdio.h>
#include <stdlib.h>

#define LEAF 0

struct node *parent( struct node*);
struct node *grandparent(struct node*);
struct node *sibling(struct node*);
struct node *uncle(struct node*);
void rotate_left(struct node*);
void rotate_right(struct node*);
struct node *insert(struct node*, struct node *);
void insert_recurse(struct node*, struct node*);
void insert_repair_tree(struct node *);

/*

Property 1 (every node is either red or black).
Property 2 (the root is black) is checked and corrected with case 1.
Property 3 (all leaves are black) always holds.
Property 4 (red nodes have only black children) is threatened only by adding a red node, repainting a node from black to red, or a rotation.
Property 5 (all paths from any given node to its leaves have the same number of black nodes) is threatened only by adding a black node, repainting a node, or a rotation.

*/
void insert_case1(struct node*);
void insert_case2(struct node*);
void insert_case3(struct node*);
void insert_case4(struct node*);
void insert_case4_step2(struct node*);

