struct node {
	int item;
	struct node *next;
};
typedef struct node node;

struct stack {
	node * top;
};
typedef struct stack stack;
