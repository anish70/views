#include <iostream>
#include <cstdlib>

using namespace std;

class Node {
	public:
		int data;
		Node *next;
};


// Operations on a stack are:
// 1. Constructor
// 2. Destructor
// 3. Enqueue
// 4. Dequeue
// 4. Print
class QueueL {
	public:
		QueueL(int depth) {
			head = NULL;
			maxSize = depth;
			count = 0;
		}

		~QueueL() {
			if (head != NULL) {
				--count;
				Node *t = head;
				head = t->next;
				delete t;
			}
		}

		bool QueueFull() {
			return (count == maxSize);
		}

		void enqueue(int data) {
			if (count == maxSize) {
				cout << "Queue FULL\n";
			} else {
				++count;
				Node *t = new Node;
				t->data = data;
				t->next = NULL;

				if (head == NULL) {
					head = t;
				} else {
					Node *p = head;
					while (p->next != NULL) p = p->next;
					p->next = t;
				}
			}
		}

		void dequeue() {
			if (head == NULL) {
				cout << "Queue Empty\n";
			} else {
				--count;
				Node *t = head;

				if (t->next == NULL) {
					head = NULL;
				} else {
					head  = t->next;
					t->next = NULL;
				}
				delete t;
			}
		}

		void print() {
			Node *t = head;

			while (t != NULL) {
				cout << " " << t->data;
				t = t->next;
			}
			cout << endl;
		}

	private:
		Node *head;
		int count;
		int maxSize;
};


class Hash {
	QueueL **array;
	int hashSize;
};

int main()
{
	Hash *hash_ = new Hash();
	hash_->hashSize = 20;
	hash_->array = new QueueL[20];

	QueueL 	*l = new QueueL(40);
	for (int i = 0; i < 20; i++) {
		l->enqueue(i);
	}

	l->print();

	for (int i = 0; i < 4; i++) {
		l->dequeue();
	}
	l->print();

	delete l;

	return 0;
}
