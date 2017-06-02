#include <iostream>

struct node { 
	int data;
	node *next;
};

node *
reverse(node *list)
{ 
	node *prev = NULL;
	node *next;

	while (list) {
		next = list->next;
		list->next = prev;
		prev = list;
		list = next;
	}

	return prev;
}


void
show_list(node *list)
{
	while (list != NULL) {
		std::cout << list->data << ", ";
		list = list->next;
	}
	std::cout << "\n";
}

int
main()
{
	node *list = NULL;

	for (int i=0; i<10; i++) {
		node *n = new node;
		n->next = list;
		n->data = 2*i;
		list = n;
	}

	std::cout << "As built: "; show_list(list);
	list = reverse(list);
	std::cout << "Reversed: "; show_list(list);
}
