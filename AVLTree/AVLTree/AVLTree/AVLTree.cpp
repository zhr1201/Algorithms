#include "AVLTree.h"
#include <list>
#include <cmath>


using namespace std;


AVLTree::AVLTree()
{
	root = nullptr;
	height = -1;
}

void AVLTree::update_depth(BinaryNode* t)
{
	if(t == nullptr)
		return;
	else if(t->left == nullptr & t->right == nullptr)
		t->depth = 0;
	else if(t->left == nullptr)
		t->depth = t->right->depth + 1;
	else if(t->right == nullptr)
		t->depth = t->left->depth + 1;
	else
		t->depth = max(t->left->depth, t->right->depth) + 1;
	return;
}

void AVLTree::insert(int new_element)
{
	height_track = -1;
	insert(new_element, root);
	return;
}

void AVLTree::remove(int del_element)
{
	remove(del_element, root);
	return;
}

void AVLTree::remove(int del_element, BinaryNode*& t)
{
	if(t == nullptr)
		return;
	else if(del_element < t->element)
	{
		remove(del_element, t->left);
		update_depth(t);
	}
	else if(del_element > t->element)
	{
		remove(del_element, t->right);
		update_depth(t);
	}
	else if(t->right != nullptr & t->left != nullptr)
	{
		t->element = findmin(t->right)->element;
		remove(t->element, t->right);
		update_depth(t);
	}
	else
	{
		BinaryNode *new_node = t;
		if(t->left == nullptr)
			t = t->right;
		else
			t = t->left;
		update_depth(t);
	}
	balance(t);
}

void AVLTree::insert(int new_element, BinaryNode*& t)
{
	height_track++;
	if(t == nullptr)
	{
		t = new BinaryNode(new_element, height_track, nullptr, nullptr);
		if(height_track > height)
			height = height_track;
		update_depth(t);
	}
	else if(t->element <= new_element)
	{
		insert(new_element, t->right);
		update_depth(t);
	}
	else
	{
		insert(new_element, t->left);
		update_depth(t);
	}
	balance(t);
	return;
}

AVLTree::BinaryNode* AVLTree::findmax(BinaryNode* t)
{
	if(t == nullptr)
		return nullptr;
	else if(t->right == nullptr)
		return t;
	else
		return findmax(t->right);
}

AVLTree::BinaryNode* AVLTree::findmin(BinaryNode* t)
{
	if(t == nullptr)
		return nullptr;
	else if(t->left == nullptr)
		return t;
	else
		return findmax(t->left);
}


void AVLTree::print_tree()
{
	int interval = 1;
	int previous_depth = -1;
	int current_depth = -1;
	list<BinaryNode*> print_queue;
	print_queue.push_back(root);
	int print_count = 0;
	while(!print_queue.empty())
	{
		BinaryNode* tmp = *print_queue.begin();
		print_queue.pop_front();
		print_count++;
		if(print_count == 1)
			current_depth = 0;
		else
			current_depth = log((double)print_count) / log(2.0);
		int inter1 = 0;
		int inter2 = 2;
		for(int count = 0; count < (height - current_depth); count++)
		{
			inter1 += inter2 / 2 + 1;
			inter2 = inter2 * 2 + 2;
		}
		if(current_depth != previous_depth)
		{
			if(current_depth > height)
				break;
			cout << endl;
			previous_depth = current_depth;
			for(int i = 0; i < inter1; i++)
				cout << " ";
			if(tmp != nullptr)
			{
				if(tmp->element < 10)
					cout << " ";
			    cout << tmp->element;
			}
			else
				cout << "  ";
		}
		else
		{
			for(int i = 0; i < inter2; i++)
				cout << ' ';
			if(tmp != nullptr)
			{
				if(tmp->element < 10)
					cout << " ";
				cout << tmp->element;
			}
			else
				cout << "  ";
		}
		if(tmp != nullptr)
		{
			if(tmp->left != nullptr)
				print_queue.push_back(tmp->left);
			else
				print_queue.push_back(nullptr);
			if(tmp->right != nullptr)
				print_queue.push_back(tmp->right);
			else
				print_queue.push_back(nullptr);
		}
		else
		{
			print_queue.push_back(nullptr);
			print_queue.push_back(nullptr);
		}
	}
	return;
}

int AVLTree::get_depth(BinaryNode* t)
{
	if(t == nullptr)
		return -1;
	else
		return t->depth;
}

void AVLTree::balance(BinaryNode*& t)
{
	if(t == nullptr)
		return;
	else if(get_depth(t->left) - get_depth(t->right) > 1)
	{
		if(get_depth(t->left->left) >= get_depth(t->left->right))
			rotate_left(t);
		else
			double_rotate_left(t);
	}
	else if(get_depth(t->right) - get_depth(t->left) > 1)
	{
		if(get_depth(t->right->right) >= get_depth(t->right->left))
			rotate_right(t);
		else
			double_rotate_right(t);
	}
	return;
}

void AVLTree::rotate_left(BinaryNode*& t)
{
	BinaryNode *k1 = t->left;
	t->left = k1->right;
	k1->right = t;
	update_depth(k1);
	update_depth(t);
	t = k1; 
}

void AVLTree::rotate_right(BinaryNode*& t)
{
	BinaryNode *k1 = t->right;
	t->right = k1->left;
	k1->left = t;
	update_depth(k1);
	update_depth(t);
	t = k1; 
}

void AVLTree::double_rotate_left(BinaryNode*& t)
{
	rotate_right(t->left);
	rotate_left(t);
}

void AVLTree::double_rotate_right(BinaryNode*& t)
{
	rotate_left(t->right);
	rotate_right(t);
}
