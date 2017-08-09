#include <iostream>
#include <vector>

using namespace std;


class HuffmanTree
{
public:
	HuffmanTree(int N_init);
	~HuffmanTree();
	void preorder_travesal();
    void merge_new(int id1, int id2);
private:
	struct Node
	{
		Node *left;
		Node *right;
		int id;
		int depth;
		Node(int init_id):id(init_id), left(nullptr), right(nullptr), depth(0){};
	};
	int max_depth;
	int min_depth;
	int N_elements;
	Node* root;
	void preorder_travesal_loop(Node* start_node);
	vector<Node*> Node_list;  //store root
};
