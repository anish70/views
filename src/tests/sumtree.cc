#include <iostream>
#include <string>
#include <assert.h>

using namespace std;

class Tree {
public:
	Tree *left;
	Tree *right;
	int data;
};

int sum (Tree *t) {
	if (t == NULL) return 0;
	return sum(t->left) + t->data + sum(t->right);
}


int toSumTree(Tree *node) {
	if (node == NULL) return 0;
	int old_val = node->data;

	node->data = toSumTree(node->left) + toSumTree(node->right);

	return node->data + old_val;
}

void printInorder(Tree *node) {
	if (node == NULL) return;
	
	printInorder(node->left);
	cout << " " << node->data;
	printInorder(node->right);

}

bool isSumTree(Tree *node) {
	int ls, rs;

	if (node == NULL || node->left == NULL || node->right == NULL) return true;
	ls = sum(node->left);
	rs = sum(node->right);

	if (node->data == (ls+rs) && isSumTree(node->left) && isSumTree(node->right))
		return true;

	return false;
}

Tree *addNode(int val) {
	Tree *t = new Tree();
	assert (t!=NULL);
	t->data = val;
	t->left = NULL;
	t->right = NULL;

	return t;
}


int main(int argc, char **argv)
{
	Tree *t = addNode(26);
	t->left = addNode(10);
	t->right = addNode(3);
	t->left->left = addNode(4);
	t->left->right = addNode(6);
	t->right->right = addNode(3);

	cout << "Given tree " << (isSumTree(t) == true ? " is " : " is not") << " Sumtree " << endl;

	Tree *m = addNode(10);
	m->left = addNode(-2);
	m->right = addNode(6);
	m->left->left = addNode(8);
	m->left->right = addNode(-4);
	m->right->left = addNode(7);
	m->right->right = addNode(5);

	printInorder(m); cout << endl;
	toSumTree(m);
	printInorder(m); cout << endl;
}
