/****************************************************
Can only print the tree in right format if the number
length is short and the tree depth is short
***************************************************/

#include "AVLTree.h"


using namespace std;


int main()
{
	AVLTree tree;
	tree.insert(0);
	tree.insert(1);
	tree.insert(2);
	tree.insert(3);
	tree.insert(4);
	tree.insert(5);
	tree.print_tree();
	cout << endl;
	tree.insert(8);
	tree.insert(2);
	tree.insert(4);
	tree.insert(5);
	tree.print_tree();
	cout << endl;
	tree.remove(2);
	tree.remove(8);
	tree.print_tree();

	return 0;
}
