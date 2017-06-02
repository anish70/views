#include <stdio.h>
#include <iostream>

using namespace std;

struct tree_node
{
	tree_node *left;
	tree_node *right;
	int data;
} ;

class bst
{
	tree_node *root;
	public:
	bst() {
		root=NULL;
	}
	int isempty() {
		return(root==NULL);
	}
	void insert(int item);
	void inordertrav();
	void inorder(tree_node *);
	void postordertrav();
	void postorder(tree_node *);
	void preordertrav();
	void preorder(tree_node *);
};

void bst::insert(int item)
{
	tree_node *p=new tree_node;
	tree_node *parent;
	p->data=item;
	p->left=NULL;
	p->right=NULL;
	parent=NULL;
	if(isempty()) {
		root=p;
	} else {
		tree_node *ptr;
		ptr=root;
		while(ptr!=NULL) {
			parent=ptr;
			ptr = (item>ptr->data) ? ptr->right:ptr->left;
		}	
		if(item<parent->data)
			parent->left=p;
		else
			parent->right=p;
	}
}

void bst::inordertrav()
{
	inorder(root);
	cout << endl;
}
void bst::inorder(tree_node *ptr)
{
	if(ptr!=NULL) {
		inorder(ptr->left);
		cout<<"  "<<ptr->data<<"     ";
		inorder(ptr->right);
	}
}
void bst::postordertrav()
{
	postorder(root);
	cout << endl;
}

void bst::postorder(tree_node *ptr)
{
	if(ptr!=NULL) {
		postorder(ptr->left);
		postorder(ptr->right);
		cout<<"  "<<ptr->data<<"     ";
	}
}

void bst::preordertrav()
{
	preorder(root);
	cout << endl;
}

void bst::preorder(tree_node *ptr)
{
	if(ptr!=NULL) {
		cout<<"  "<<ptr->data<<"     ";
		preorder(ptr->left);
		preorder(ptr->right);
	}
}

int main()
{
	bst b;
	int a[7] = {52, 25, 50, 15, 40, 45, 20 };
	for (int i = 0; i < 7; i++)
		b.insert(a[i]);
	cout<<"inorder:\t"; b.inordertrav();
	cout<<"postorder:\t"; b.postordertrav();
	cout<<"preorder:\t"; b.preordertrav();
}
