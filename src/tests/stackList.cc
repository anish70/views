#include <iostream>
#include <cstdlib>

using namespace std;

class Node {
	public:
		int	data;
		Node	*next;
};

// Operations on a stack are: (LIFO)
// 1. Constructor
// 2. Destructor
// 3. Push
// 4. Pop
// 4. Count
class StackL {
	public:
		StackL(int depth) {
			top = NULL;
			maxDepth = depth;
			count = 0;
		}

		~StackL() {
			if (top != NULL) {
				--count;
				Node *t = top;
				top = t->next;
				delete t;
			}
			maxDepth = 0;
		}

		// Logic
		// 1. Walk the list and find all Even Nodes.
		// 2. Insert all Even nodes ot the end.
		// 3. 
		void segregateEvenOdd() {
			Node *end = top;
			Node *prev = NULL;
			Node *curr = top;
 
			/* Get pointer to the last node */
			while (end->next != NULL)
				end = end->next;
 
			Node *new_end = end; // last node
 
			// Consider all Even nodes before the first Odd node
			// and move them after end
			while (curr->data %2 == 0 && curr != end) {
				new_end->next = curr;
				curr = curr->next;
				new_end->next->next = NULL;
				new_end = new_end->next;
			}
 
			// Do following steps only if there is any Odd node
			if (curr->data%2 != 0) {
				top = curr; // points to first ODD node
 
				/* now current points to the first ODD node */
				while (curr != end) {
					if ( (curr->data)%2 != 0 ) {
						prev = curr;
						curr = curr->next;
					} else {
						prev->next = curr->next; // break the link between prev and current
						curr->next = NULL; /* Make next of curr as NULL  */
						new_end->next = curr; /* Move curr to end */
						new_end = curr; /* make curr as new end of list */
						curr = prev->next; /* Update current pointer to next of the moved node */
					}
				}
			} else {
				prev = curr;
			}
 
			// If there are more than 1 odd nodes and end of original list is
			// odd then move this node to end to maintain same order of odd
			// numbers in modified list
			if (new_end!=end && (end->data)%2 == 0) {
				prev->next = end->next;
				end->next = NULL;
				new_end->next = end;
			}
		}

		void push(int data) {
			if (count == maxDepth) {
				cout << "STACK FULL\n";
			} else {
				++count;
				Node *t = new Node;
				t->data = data;
				t->next = NULL;

				if (top != NULL) {
					t->next = top;
				}
				top = t;
			}
		}

		void evenOdd() {
			Node *curr = top;
			Node *prev = NULL;
			Node *temp;

			while (curr != NULL) {
				// cout << "Ptr:  " << curr << " Data: " << curr->data << endl;
				temp = curr->next;	
				if (curr->data %2 == 0) {
					if (curr == top) {
						curr = curr->next;
						continue;
					} else {
						curr->next = top;
						prev->next = temp;
						top = curr;
					}
				}
				prev = curr;
				curr = temp;
			}
		}

		void pop() {
			if (top == NULL) {
				cout << "STACK Empty\n";
			} else {
				--count;
				Node *t = top;
				top = t->next;
				delete t;
			}
		}

		void print() {
			Node *t = top;

			while (t != NULL) {
				cout << " " << t->data;
				t = t->next;
			}
			cout << endl;
		}

		int Count() {
			Node *t = top;
			int count = 0;	

			while (t != NULL) {
				t = t->next;
				++count;
			}
			return count;
		}

		int GetNth(int nth) {
			Node *t = top;
			int num = 0;

			while (t != NULL) {
				if (++num == nth)
					return t->data;
			
				t = t->next;
			}
			return -1;
		}

		void InsertNth(int nth) {
			Node *t = top;
			int num = 0;

			while (t != NULL) {
				if (++num == nth) {
					Node *p = t->next;
					Node *l = new Node;
					l->data = nth;
					t->next = l;
					l->next = p; 
					++count;
					return;
				}
			
				t = t->next;
			}
		}

		void SortedInsert(int value) {
			Node *t = top;

			while (t != NULL) {
				if (value > t->data ) 
					break;
				t = t->next;
			}

			cout << "t: " << t << endl;
			Node *l = new Node;
			l->next = NULL;
			l->data = value;
			++count;
			if (t != NULL) {
				Node *temp = t->next;
				t->next = l;
				l->next = temp;
			} else {
				if (top == NULL) top = l;
				else t = l;
			}
		}

		void Append(StackL *m) {
			Node *t = top;
			while (t->next != NULL) {
				t = t->next;
			}
			t->next = m->top;
			this->count += m->count;
		}


	private:
		Node *top;
		int count;
		int maxDepth;
};

int main()
{
	StackL 	*l = new StackL(20);
	cout << "Count:- " << l->Count() << endl;

	for (int i = 0; i < 20; i++) {
		l->push(i);
	}

	l->evenOdd();
	l->print();

	l->InsertNth(1);
	l->InsertNth(3);

	cout << "Count:- " << l->Count() << endl;
	cout << "GetNth(4):- " << l->GetNth(4) << endl;

	StackL 	*m = new StackL(4);
	for (int i = 30; i < 38; i+= 2) {
		m->push(i);
	}
	m->print();

	l->Append(m);

	l->print();

	for (int i = 0; i < 4; i++) {
		l->pop();
	}
	l->print();

	delete l;

	l = new StackL(6);
	l->SortedInsert(11);
	l->SortedInsert(17);
	l->SortedInsert(1);
	l->SortedInsert(2);
	l->print();

	return 0;
}
