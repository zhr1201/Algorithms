#include "HuffmanTree.h"


HuffmanTree::HuffmanTree(int N_init)
{
	N_elements = N_init;
	root = nullptr;
	vector<Node*> Node_list_tmp(N_init);
	Node_list = Node_list_tmp;
	for(int i = 0; i < N_elements; i++)
	{
		Node_list[i] = new Node(i);

	}
}

HuffmanTree::~HuffmanTree()
{
	for(int i = 0; i < N_elements; i++)
	{
		delete Node_list[i];
	}
}

void HuffmanTree::merge_new(int id1, int id2)
{
	Node* new_root = new Node(-1);
	new_root->left = Node_list[id1];
	new_root->right = Node_list[id2];
	Node_list[id1] = new_root;
	Node_list[id2] = new_root;
	root = new_root;
}

void HuffmanTree::preorder_travesal()
{
	max_depth = 0;
	min_depth = INT_MAX;
	preorder_travesal_loop(root);
	cout << endl;
	cout << "max depth: " << max_depth << endl;
	cout << "min_depth: " << min_depth << endl;
	return;
}

void HuffmanTree::preorder_travesal_loop(Node* start_node)
{
	if(start_node->left != nullptr)
	{
		start_node->left->depth = start_node->depth + 1;
		preorder_travesal_loop(start_node->left);
	}
	if(start_node->right != nullptr)
	{
		start_node->right->depth = start_node->depth + 1;
		preorder_travesal_loop(start_node->right);
	}
	cout << start_node->id << "  " ;
	if(max_depth < start_node->depth)
		max_depth = start_node->depth;
	if((min_depth > start_node->depth) & (start_node->id != -1))
		min_depth = start_node->depth;
	return;
}