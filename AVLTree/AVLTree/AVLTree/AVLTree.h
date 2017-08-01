#include <iostream>


class AVLTree
{
public:
	AVLTree();
	void insert(int new_element);
	void remove(int del_element);
    void print_tree();
	int get_height(){return height;};
private:
	struct BinaryNode
	{
		int element;
		int height;
		int depth;
		BinaryNode* left;
		BinaryNode* right;
		BinaryNode(int element_value, int height_value, BinaryNode* left_p, BinaryNode* right_p):
		    element(element_value), left(left_p), right(right_p), height(height_value){depth = 0;}
	};
	BinaryNode *root;
	int height;
	int height_track;
	void insert(int new_element, BinaryNode*& t);
	void remove(int del_element, BinaryNode*& t);
	void update_depth(BinaryNode* t);
	void balance(BinaryNode*& t);
	void rotate_left(BinaryNode*& t);
	void rotate_right(BinaryNode*& t);
	int get_depth(BinaryNode* t);
	void double_rotate_left(BinaryNode*& t);
	void double_rotate_right(BinaryNode*& t);
	BinaryNode* findmin(BinaryNode* t);
	BinaryNode* findmax(BinaryNode* t);
}
;