#include <string>
#include <iostream>
#include <stdio.h>
#include <string.h>

using std::string;
using namespace std;

class Tree {
	class Node {
		public:
			string data;
		private:
			Node *right;
			Node *left;
			Node *next;

		friend class Tree;

		Node (const string word) {
			next = right = left = NULL;
			data = word;
		}
	};

	public:
		Node *root;
		Node *head;

	void tree () {root = NULL;};

	void appendToTail(string s) {
		Node *last = new Node(s);
		if (head == NULL) {
			head = last;
			head->next = NULL;
		} else {
			Node *n = head;
			while (n->next != NULL) {
				n = n->next;
			}
			n->next = last;	
		}		
	}

	void treeToList(Node *n) {
		if (n == NULL) return;

		treeToList(n->left);
		appendToTail(n->data);
		treeToList(n->right);
	}

	void printList(Node *n) {
		Node *temp = head;

		while (temp != NULL) {
			cout << " " << temp->data;
			temp = temp->next;
		}
		cout << endl;
	}

	void insert_one(Node * &tree_node, const string word) {
		if (tree_node == NULL) {
			tree_node = new Node(word);
		}	

		if (tree_node->data == word) return;
		if (tree_node->data < word) {
			insert_one(tree_node->right, word);
		} else {
			insert_one(tree_node->left, word);
		}
	}

	void
	add_node(const string word) {
		insert_one(root, word);
	}

	void
	visit(Node *n) {
		if (n == NULL) {
			cout << "Empty node" << endl;
		}

		cout << " " << n->data;
	}	

	void inOrderTraversal(Node *n) {
		if (n != NULL) {
			inOrderTraversal(n->left);
			visit(n);
			inOrderTraversal(n->right);
		}
	}

	void preOrderTraversal(Node *n) {
		if (n != NULL) {
			visit(n);
			preOrderTraversal(n->left);
			preOrderTraversal(n->right);
		}
	}

	void postOrderTraversal(Node *n) {
		if (n != NULL) {
			postOrderTraversal(n->left);
			postOrderTraversal(n->right);
			visit(n);
		}
	}

	int sizeTree(Node *n) {
		if (n == NULL) return 0;
		return (sizeTree(n->left) + 1 + sizeTree(n->right));
	}

	void mirrorTree(Node *n) {
		if (n == NULL) return;

		mirrorTree(n->left);
		mirrorTree(n->right);

		Node *temp = n->left;
		n->left = n->right;
		n->right = temp;
	}

	int maxDepth(Node *n) {
		if (n == NULL) return 0;
		int ldepth = maxDepth(n->left);
		int rdepth = maxDepth(n->right);
		return (ldepth > rdepth ? ldepth + 1 : rdepth + 1);
	}

	string &minValue(Node *n) {
		Node *curr = n;

		while (curr->left != NULL) curr = curr->left; 
		return curr->data;
	}

	void printMyPaths(string paths[],  int len) {
		for (int i = 0; i < len; i++)
			cout << " " << paths[i];
		cout << endl;
	}

	void printPathsRecur(Node *n, string paths[], int pathLen) {
		if (n == NULL) return;

		paths[pathLen++] = n->data;

		if (n->left == NULL && n->right == NULL) {
			printMyPaths(paths, pathLen);
		} else {
			printPathsRecur(n->left, paths, pathLen);
			printPathsRecur(n->right, paths, pathLen);
		}
	}

	void printPaths(Node *n) {
		string paths[100];
		printPathsRecur(n, paths, 0);
	}
};

int
main(void)
{
	Tree *t = new Tree();

	string fruits[] = { "mango", "guava", "banana", "pear", "grapes", "apple", "orange", "coconut", "peach", "cactus" };

	for(string &w: fruits) {
		t->add_node(w);
	}

	cout << "Inorder: ";
	t->inOrderTraversal(t->root);
	cout << endl;

	t->mirrorTree(t->root);
	t->mirrorTree(t->root);
	cout << "Inorder: Mirror Tree: ";
	t->inOrderTraversal(t->root);
	cout << endl;

	cout << "Pre-order: ";
	t->preOrderTraversal(t->root);
	cout << endl;
	cout << "Post-order: ";
	t->postOrderTraversal(t->root);
	cout << endl;

	cout << "Size of Tree: " << t->sizeTree(t->root) << endl;
	cout << "Max Depth of Tree: " << t->maxDepth(t->root) << endl;
	cout << "Min value of Tree: " << t->minValue(t->root) << endl;
	t->printPaths(t->root);

	t->treeToList(t->root);
	t->printList(t->head);

	return 0;
}
