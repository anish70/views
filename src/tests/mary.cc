#include <iostream>
#include <queue>
#include <iomanip>

using namespace std;

class MTree {
	private:
		struct node {
			node* parent;
			vector <node*> children;
			string data;
			int num;
			int level;
		};

		node* root;
	public:
		MTree() { root = NULL; }
		~MTree () { delete root; }

	bool isEmpty() const { return root == NULL; }
 
	//*******************************************************
	int compare (string on, string start) {
		int x, d = 0;

		for (x = 0; x < start.length(); x++)
			if (start[x] != on[x])
				d++;

		return d;
	}
 
	friend bool isInVec (vector <string> vec, string info) {
		vector<string>::iterator it;

		for (it = vec.begin(); it != vec.end(); it++) {
			if (info == *it) return true;
		}

		return false;
	}

	//******************************************************* 
	// builds the tree
	void buildTree (vector <string> vec, string one, string two)
	{
		insert(one);

		for(int x = 0; x < vec.size(); x++)
		   if (!(compare(vec[x], one) == 0 || compare(vec[x], two) == 0))
			insert(vec[x]);
		insert(two);
}
 
	//*******************************************************
	void insert(string d) { // adds the word to the tree if applicable
		node* t = new node;
		t->data = d;
		t->num = 0;
		t->level = 0;

		if(isEmpty())
			root = t;  // if new tree, make insert the root
		else {
			node* curr = root;
			curr = inHelp (curr, d);
			if (curr != NULL) {
				t->level = 1+curr->level;
				curr->children.push_back(t);
				curr->num++;
			} else
				delete t;
		}
	}
       
	//*******************************************************
	// Finds the right spot to add the new node to.
	node* inHelp (node* ptr, string on) {
		if (compare(ptr->data, on) == 1)
			return ptr;
		else {
			int x = 0;

			node* now = NULL;
			while (now == NULL && x < ptr->children.size()) {
				now = inHelp (ptr->children[x++], on);
			}

			return now;
		}
	}
 
	/*******************************************************
	 **********           REMOVED             **********
	 *******************************************************/
	void print() {
		pin(root);
		cout << "\n\n";
	}
	 
	//*******************************************************
	void pin(node* p) {
		if(p != NULL) {
			for (int y = 0; y < p->level; y++)
				cout << setw(p->data.length()+4) << " ";
			cout << p->data << " " << p->num << endl;
			int x = 0;
			while (x < p->num) {
				pin(p->children[x++]);
			}
		}
	}

};

int main()
{
	MTree *m = new MTree();
	string words[] = { "india", "america", "usa", "uk", "spain", "iran", "iraq", "korea", "japan" };
	vector<string> tree_words(words, words + sizeof(words) / sizeof(words[0]) );
	m->buildTree(tree_words, "india", "america");
}

