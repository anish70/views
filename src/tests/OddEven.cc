#include <string>
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <list>

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

	void OddEven(){
		Node *n = this;
		Node *head = this;

		list<int>  myEvens;
		list <int> myOdds;
		list<int>::iterator it;

		while (n->next  != NULL) {
			if (n->data %2 == 0) {
				myEvens.push_back(n->data);
			} else {
				myOdds.push_back(n->data);
			}
			n = n->next;	
		}

		for (it = myOdds.end(); it != myOdds.begin(); it--) {
			cout << " " << (*it);
		}

		for (it = myEvens.begin(); it != myEvens.end(); it++) {
			cout << " " << (*it);
		}


	}

	void removeDups() {
		Node *n = this;
		Node *t;
		Node *d;

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

};


int
main(void)
{
	Node *n = new Node(0);
	for (int i = 1; i < 10; i++) {
		n->appendToTail(i);
	}

	cout << "Print List" << endl;
	n->printList();

	n->OddEven();

	return 0;
}
