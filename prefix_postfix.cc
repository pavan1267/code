#include<iostream>
using namespace std;

int n;
int ret[10];

struct NODE
{
	int data;
	NODE* left;
	NODE* right;
};

int find( int child, int prefix[])
{
	for(int i=0; i<n; i++)
	{
		if(prefix[i] == child) return i;
	}

}


NODE* build_tree(int prefix[], int postfix[], int pre_start, int pre_end, int pos_start, int pos_end)
{

	NODE* node = new NODE;

	int root = postfix[pos_end];
	node->data = root;
	node->left = NULL;
	node->right = NULL;
	if( ((pre_start == pre_end) && ( pos_start == pos_end)) || (pre_start > pre_end) || (pos_start > pos_end))
	{
		if( ret[node->data] == 0)
		{
			ret[node->data] = 1;
			return node;
		}
		return NULL; 
	}

	int right_child = postfix[pos_end -1];
	int index = find(right_child, prefix);
	int root_index = find( root, prefix);
	int node_left = index - root_index -1;
	int node_right = pre_end - index +1;
	if( node_left > 0)
	{
		node->left = build_tree( prefix, postfix, root_index +1, index-1, pos_start, pos_start + node_left-1);
	}

	if( node_right > 0)
	{
		node->right = build_tree( prefix, postfix, index, pre_end, pos_end - node_right, pos_end-1 );

	}


}

void print( NODE* root)
{
	if( root == NULL) 	return;
	print( root->left);
	cout<<" "<< root->data;
	print( root->right);

}

int main( int argc, char*argv[])
{

	int prefix[10], postfix[10];
	cout<<"\nInput the number of nodes\n";
	cin>>n;
	cout<<"\nInput the preorder\n";
	for(int i=0;i<n;i++)
	{
		cin>>prefix[i];
	}
	cout<<"\nInput the postorder\n";
	for(int i=0;i<n;i++)
	{
		cin>>postfix[i];
	}
	NODE* root = new NODE;
	root = build_tree(prefix, postfix, 0, n-1, 0, n-1);
	cout<<"\n Inorder\n";
	print(root);
	cout<<endl;
	return 0;

}






