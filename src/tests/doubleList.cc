#include <string>
#include <fstream>
#include <iostream>
#include <stdio.h>

using namespace std;

class Node {
	Node *next;
	Node *prev;
	int data;
	
	public:

	Node *head;

	Node(int d) {
		data = d;
		next = NULL;
		prev = NULL;
	}

	~Node() {
		next = NULL;
		prev = NULL;
	}

	int getData() {
		return  (this->data);
	}

	void pushToList(int d) {
		Node *new_node = new Node(d);
		new_node->next = head;	
		if (head != NULL) {
			head->prev = new_node;
		}
		head = new_node;
	}

	void printList(){
		Node *n = head;
		int i = 0;
		while (n  != NULL) {
			cout << "\tNode[ " << i++ << "] = " << n->data << " Ptr = " << n << endl;
			n = n->next;
		}
	}

	void reverseList() {
		Node *temp = NULL;  
		Node *current = head;
      
		while (current !=  NULL) {
			temp = current->prev;
			current->prev = current->next;
			current->next = temp;              
			current = current->prev;
		}      
      
		if(temp != NULL )
			head = temp->prev;
	}

	void deleteList(){
		Node *n = head;
		Node *t;

		while (n->next  != NULL) {
			t = n;
			n = n->next;	
			cout << "\tDeleting Node: " << t << endl;
			t->next = NULL;
			delete t;
		}
		head = NULL;
	}
};


int
main(void)
{
	Node *n = new Node(0);
	n->head = n;
	for (int i = 1; i < 20; i+=2) {
		n->pushToList(i);
	}

	n->reverseList();

	cout << "Print List" << endl;
	n->printList();

	n->deleteList();
	cout << "Print List" << endl;
	n->printList();

	return 0;
}
