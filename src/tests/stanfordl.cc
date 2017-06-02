#include <iostream>
#include <stdio.h>

using namespace std;

class List {
	public:
		List *next;
		int data;

	List(int d) {
		next = NULL;
		data = d;
	}

	void addNode(int d) {
		List *t = this;
		while (t->next != NULL) {
			t = t->next;
		}
		List *p = new List(d);
		t->next = p;
	}

	void printList() {
		List *t = this;
		while (t != NULL) {
			cout << " " << t->data;
			t = t->next;
		}
		cout << endl;
	}

	int Count_Num(int num) {
		List *t = this;
		int count = 0;
		while (t != NULL) {
			if (num == t->data)
				count++;
			t = t->next;
		}

		return count;
	}

	void DeleteList() {
		List *n = this;
		List *t;

		while (n->next  != NULL) {
			t = n;
			n = n->next;	
			cout << "\tDeleting Node: " << t << endl;
			t->next = NULL;
			delete t;
		}
	}

	int Pop() {
		List *head = this;
		int data = 0;

		if (head == NULL)
			cout << "Nothing to pop\n";
		else {
			data = head->data;
			List *p = head->next;
			delete head;
		}
		return data;
	}

	int GetNth(int nth) {
		List *t = this;
		int count = 0;
		while (t != NULL) {
			if (count++ == nth)
				return t->data;
			t = t->next;
		}

		return -1;
	}


};

List *BuildOneTwoThree() {
	List *l = new List(1);
	l->addNode(2);
	l->addNode(2);
	l->addNode(2);
	l->addNode(2);
	l->addNode(2);
	l->addNode(3);

	return l;	
	
}

int
main(int argc, char **argv)
{
	List *l = BuildOneTwoThree();
	l->printList();
	cout << "Count of 2 is: " << l->Count_Num(2) << endl;
	cout << "Count of 5 is: " << l->Count_Num(5) << endl;
	cout << "GetNth of 6 is: " << l->GetNth(6) << endl;
	cout << "GetNth of 12 is: " << l->GetNth(12) << endl;
	// l->DeleteList();
	int a = l->Pop();
	a = l->Pop();
	l->printList();
	
}
		
