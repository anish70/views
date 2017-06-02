#include <string>
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

class Node {
	Node *next;
	int data;
	
	public:

	Node(int d) {
		data = d;
		next = NULL;
	}

	~Node() {
		next = NULL;
	}

	int getData() {
		return  (this->data);
	}

	void appendToTail(int d) {
		Node *last = new Node(d);
		Node *n = this;
		int i = 0;
		while (n->next != NULL) {
			n = n->next;
			++i;
		}
		n->next = last;	
		// cout << "\tNode[ " << i++ << "] = " << n->data << endl;
	}

	Node* MiddleNode() {
		Node *p1 = this;
		if (!p1) {
			return NULL;
		}

		Node *p2 = p1->next;

		while (p2 && p2->next) {
			p1 = p1->next;
			p2 = p2->next->next;
		}

		return p1;
	}

	void printList(){
		Node *n = this;
		int i = 0;
		while (n->next  != NULL) {
			cout << "\tNode[ " << i++ << "] = " << n->data << " Ptr = " << n << endl;
			n = n->next;
		}
	}

	void deleteList(){
		Node *n = this;
		Node *t;

		while (n->next  != NULL) {
			t = n;
			n = n->next;	
			cout << "\tDeleting Node: " << t << endl;
			t->next = NULL;
			delete t;
		}
	}

	void removeDups() {
		Node *n = this;
		Node *t;

		while (n->next != NULL) {
			t = n;
			n = n->next;
			if (t->data == n->data) {
				cout << "\tDeleting Dup Node: " << t << " Data: " << n->data << endl;
				t->next = NULL;
				delete t;
			}
		}
	}



	Node *swap_alternate_nodes(Node *head) {
		Node *alternate = NULL;
		Node *temp = NULL;

		if (head == NULL || head->next == NULL)
			return (head);

		alternate = head->next;
		temp = swap_alternate_nodes(head->next->next);

		/* Now swap */
		head->next = temp;
		alternate->next = head;

		return (alternate);
	}

	void swapPairs() {
		Node* cur, *prev, *next, *result;
  		cur = this;
		next = 0;
		prev = 0;
		result = 0;

		cout << __func__; 

		while (cur && cur->next) {
			next = cur->next->next;
			if (!result) result = cur->next;
			if (prev) prev->next = cur->next;
			cur->next->next = cur;
			cur->next = next;
			prev = cur;
			cur = next;
		}
		if (!result) result = this;
	}

	Node *nthToLast(Node *head, int k, int &i) {
		cout << "\t\tHead: " << head << " Data: " << head->data << endl;
		if (head == NULL) return NULL;
		Node *t = nthToLast(head->next, k, i);
		i = i+1;
		if (i == k)
			return head;

		return t;
	}

	Node *nthToLast(int k) {
		Node *n = this;
		cout << "\tHead: " << n << " Data: " << n->data << endl;
		int i = 0;
		return nthToLast(n, k, i);
	}

};


int
main(void)
{
	Node *n = new Node(0);
	for (int i = 1; i < 20; i+=2) {
		n->appendToTail(i);
	}

	cout << "Print List" << endl;
	n->printList();

	Node *m = n->MiddleNode();
	cout << "\tMiddle node: " << m << " Data: " << m->getData() << endl;

	Node *a = n->nthToLast(6);
	if (a) {
		cout << "\tData from 12th node: " << a;
		cout << " Data: " << a->getData() << endl;
	}

	n->swapPairs();

	n->printList();
#if 0
	cout << "Removing Dups" << endl;
	n->removeDups();

	cout << "Removing List" << endl;
	n->deleteList();

	n = new Node(0);
	for (int i = 1; i < 20; i+=2) {
		n->appendToTail(2*i);
	}

	cout << "Newer List" << endl;
	n->printList();

	cout << "Swap List" << endl;
	n->swapPairs();

	n->printList();
#endif
	n->deleteList();

	return 0;
}
