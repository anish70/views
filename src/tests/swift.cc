#include <iostream>
#include <stdio.h>
#include <assert.h>

using namespace std;

class List {
	public:
		List *head;
		int count;
		int data;
		List *next;

	List() {
		head = NULL;
		count = data = 0;
		next = NULL;
	}

	void addToList(int val) {
		List *t = new List;
		t->data = val;
		t->next = NULL;
		++count;


		if (head == NULL) {
			head = t;
		} else {
			t->next = head;
			head = t;
		}
	}

	int Pop() {
		// return count;
		List *curr = head;
		assert (curr != NULL);

		head = curr->next;
		int data = curr->data;
		delete curr;
		--count;
		return data;
	}

	void evenOdd() {
		List *curr = head;
		List *prev = NULL;
		List *temp;

		while (curr != NULL) {
			int val = curr->data;
			cout << "val:  " << val << "Curr: " << curr << endl;
			temp = curr->next;	
			if (val %2 != 0) {
				if (curr == head) {
					curr = curr->next;
					continue;
				} else {
					curr->next = head;
					prev->next = temp;
					head = curr;
				}
			}
			prev = curr;
			curr = temp;
		}
	}

	void GetNth(int nth) {
		List *p = head;
		int num = 0;

		while (p != NULL) {
			if (++num == nth) {
				cout << "nth: of " << nth << " " << p->data << endl;
				break;
			}
			p = p->next;
		}
	}

	void Delete() {
		List *curr = head;
		List *temp;

		while (curr != NULL) {
			temp = curr->next;	
			cout << "\tDeleting Node: " << curr;
			cout << " data: " << curr->data << endl;
			delete curr;
			curr = temp;
			--count;
		}
		head = NULL;
	}

	void Print() {
		List *p = head;

		cout << "List Contents: Head: " << p << endl;

		while (p != NULL) {
			cout << "\tPTR: " << p << " Data: " << p->data << endl;
			p = p->next;
		}
	}


	void Reverse() {
		List *curr = head;
		List *prev = NULL;
		List *next;

		while (curr != NULL) {
			next = curr->next;
			curr->next = prev;	
			prev = curr;
			curr = next;
		}

		head = prev;
	}

	void InsertNth(int nth, int val) {
		List *p = head;
		int num = 0;

		while (p != NULL) {
			if (++num == nth) {
				List *t = new List;
				t->data = val;
				t->next = NULL;
				++count;


				t->next = p->next;
				p->next = t;
				break;
			}
			p = p->next;
		}
	}

	void SortedInsert(int val) {
		List *t = new List;
		t->data = val;
		t->next = NULL;
		++count;

		if (head == NULL || head->data >= t->data) {
			t->next = head;
			head = t;
		} else {
			List *curr = head;

			while (curr->next != NULL && curr->next->data < t->data) {
				curr = curr->next;
			}
			t->next = curr->next;
			curr->next = t;
		}

	}

	int Count() {
		// return count;
		int tot = 0;
		List *p = head;
		while (p != NULL) {
			p = p->next;
			tot++;
		}
		return tot;
	}

};
	
void Split(List *source, List **a, List **b) {
	if (source->head == NULL || source->head->next == NULL) {
		*a = source->head;
		*b = NULL;
	} else {
		List *slow = source->head;
		List *fast = source->head->next;
		int num = 0;

		while (fast != NULL) {
			fast = fast->next;
			if (fast != NULL) {
				slow = slow->next;
				fast = fast->next;
			}
			++num;
		}

		*a = source;
		(*a)->head = source->head;
		(*a)->count = num;
		*b = slow->next;
		(*b)->head = slow->next;
		(*b)->count = source->count - num;
		slow->next = NULL;
	}
}

void MoveNode(List **dest, List **src)
{
	if ((*src)->head == NULL) return;
	if ((*src) == NULL) return;

	List *curr = (*src)->head;
	(*src)->head = curr->next;
	cout << " " << __LINE__ << "*src" << (*src)->head << endl;

	if ((*dest)->head == NULL) {
		(*dest)->head = curr;
		(*dest)->next = NULL;
		cout << " " << __LINE__ << "*dest" << *dest << endl;
	} else {
		cout << " " << __LINE__ << "*dest" << *dest << endl;
		List *p = (*dest)->head;
		(*dest)->head = curr;
		curr->next = p;
	}
}


void Split2(List *source, List **a, List **b) {
	if (source->head == NULL || source->head->next == NULL) {
		*a = source->head;
		*b = NULL;
	} else {
		int num = source->count;
		cout << " " << __LINE__ << "NUM: " << num << endl;

		// while (num > 0) {
			MoveNode(a, &source);
			(*a)->count++;
			MoveNode(b, &source);
			(*b)->count++;
			// num -= 2;
		// }
	}
}

void RemoveDups(List **src) {
	List *curr = (*src)->head;
	List *nextNext;

	while (curr->next != NULL) {
		if (curr->data == curr->next->data) {
			nextNext = curr->next->next;
			cout << "\tDeleting Dup Node: " << curr;
			cout << " Data: " << curr->data << endl;
			delete curr->next;
			curr->next = nextNext;
			--(*src)->count;
		} else {
			curr = curr->next;
		}
	}
}

void SortMe(List* head)
{
	List *curr = head;
	List *prev;

	for ( ; curr->next != NULL; curr = curr->next) {
		for (prev = curr->next; prev != NULL; prev = prev->next) {
			if (curr->data > prev->data) {
				int temp = curr->data;
				curr->data = prev->data;
				prev->data = temp;
			}
		}
	}
}


int main(int argc, char **argv) {
#if 0
	List *l = new List;
	for (int i = 0; i < 20; i+=2) {
		l->addToList(i);
	}
	l->Print();
	cout << "Count: " << l->Count() << endl;
	l->GetNth(2);
	l->GetNth(8);
	l->InsertNth(8,15);
	l->InsertNth(6,11);
	cout << "Popped " << l->Pop() << endl;
	cout << "Popped " << l->Pop() << endl;
	l->Print();
	l->Delete();
#endif

#if 0
	List *l = new List;
	l->SortedInsert(0);
	l->SortedInsert(7);
	l->SortedInsert(6);
	l->SortedInsert(9);
	l->SortedInsert(1);
	l->SortedInsert(2);
	l->SortedInsert(8);
	l->SortedInsert(18);
	l->Print();
	l->Delete();
#endif

	List *l = new List;
	for (int i = 10; i >= 0; i--) {
		l->addToList(i);
	}

	l->evenOdd();
	l->Print();

#if 0
	for (int i = 20; i > 10; i-=2) {
		l->addToList(i);
	}

	l->addToList(1);
	l->addToList(4);

	// cout << "Before:\n";
	// l->Print();

	cout << "Sorted:\n";
	SortMe(l->head);
	// cout << "After:\n";
	// l->Print();

	l->addToList(4);

	List *m = new List;
	for (int i = 0; i < 14; i++) {
		m->SortedInsert(l->Pop());
	}

	cout << "Reversed:\n";
	// m->Reverse();
	// m->Print();

	cout << "Removed Dups:\n";
	RemoveDups(&m);
	m->Print();

	List *a = new List;
	List *b = new List;

	cout << "Split :\n";
	Split(m, &a, &b);
	// cout << "List of a: " << a ; a->Print();
	// cout << "List of b: " << b ;  b->Print();
	cout << "Moved one node over :\n";
	MoveNode(&a, &b);
	cout << "List of a: " << a ; a->Print();
	cout << "List of b: " << b ;  b->Print();



	Split2(m, &a, &b);
	cout << "List of a: " << a ; a->Print();
	cout << "List of b: " << b ;  b->Print();
#endif
}	
