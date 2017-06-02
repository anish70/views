// A O(n) solution to find LCA of two given values n1 and n2

/* Following is definition of LCA from Wikipedia:
 * Let T be a rooted tree. The lowest common ancestor between two nodes n1 and n2
 * is defined as the lowest node in T that has both n1 and n2 as descendants
 * (where we allow a node to be a descendant of itself).
 *
 * The LCA of n1 and n2 in T is the shared ancestor of n1 and n2 that is located
 * farthest from the root. Computation of lowest common ancestors may be useful,
 * for instance, as part of a procedure for determining the distance between pairs
 * of nodes in a tree: the distance from n1 to n2 can be computed as the distance
 * from the root to n1, plus the distance from the root to n2, minus twice the
 * distance from the root to their lowest common ancestor. 
 */

#include <iostream>
#include <vector>
using namespace std;
 
// A Bianry Tree node
struct Node {
	int key;
	Node *left;
	Node *right;
};
 
// Utility function creates a new binary tree node with given key
Node * newNode(int k) {
	Node *temp = new Node;
	if (temp) {
		temp->key = k;
		temp->left = NULL;
		temp->right = NULL;
	}

	return temp;
}
 
// Finds the path from root node to given root of the tree, Stores the
// path in a vector path[], returns true if path exists otherwise false
bool findPath(Node *root, vector<int> &path, int k)
{
	if (root == NULL) return false; // base case

	// Store this node in path vector. The node will be removed if not in path from root to k
	path.push_back(root->key);
 
	// See if the k is same as root's key
	if (root->key == k)
		return true;
 
	// Check if k is found in left or right sub-tree
	if ( (root->left && findPath(root->left, path, k)) ||
	     (root->right && findPath(root->right, path, k)) )
		return true;
 
	// If not present in subtree rooted with root, remove root from
	// path[] and return false
	path.pop_back();
	return false;
}
 
// Returns LCA if node n1, n2 are present in the given binary tree,
// otherwise return -1
int findLCA(Node *root, int n1, int n2)
{
	// to store paths to n1 and n2 from the root
	vector<int> path1, path2;
 
	// Find paths from root to n1 and root to n1. If either n1 or n2
	// is not present, return -1
	if (!findPath(root, path1, n1) || !findPath(root, path2, n2))
		return -1;
 
	// Compare the paths to get the first different value
	for (int i = 0; i < path1.size() && i < path2.size() ; i++)
		if (path1[i] != path2[i])
			break;

	return path1[i-1];
}
 
int main()
{
	// create the Binary Tree shown in above diagram.
	//			5
	//		2
	//			4
	//	1
	//			6
	//		3
	//			7
	Node * root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->right->left = newNode(6);
	root->right->right = newNode(7);
	cout << "LCA(4, 5) = " << findLCA(root, 4, 5);
	cout << "\nLCA(4, 6) = " << findLCA(root, 4, 6);
	cout << "\nLCA(3, 4) = " << findLCA(root, 3, 4);
	cout << "\nLCA(2, 4) = " << findLCA(root, 2, 4);
	cout << endl;
	return 0;
}
