#include<iostream>
using namespace std;
int n;
struct NODE
{
	int data;
	NODE *left;
	NODE *right;
};

int find(int data, int inorder[])
{
	for(int i=0; i<n; i++)
	{
		if(data == inorder[i])	return i;
	}
}
	

NODE* build_tree(int inorder[], int preorder[], int in_start, int in_end, int pre_start, int pre_end)
{
	NODE *root;
	root = new NODE;
	root->data = preorder[pre_start];
	root->left = NULL;
	root->right = NULL;
	int index = find(root->data, inorder);
	int root_index = find(root->data, preorder);
	int node_left = index - in_start;
	int node_right = in_end - index;
	
	if((in_start == in_end)&&(pre_start == pre_end))
	{
		return root;
	}
	if(node_left>0)
	{
		root->left = build_tree(inorder, preorder, in_start, in_start+node_left-1, root_index+1, root_index+node_left);
	}
	if(node_right>0)
	{
		root->right = build_tree(inorder, preorder, index+1, in_end, pre_end-node_right+1, pre_end);
	}

}

void print(NODE *root)
{
	if(root == NULL)
		return;
	print(root->left);
	print(root->right);
	cout<<" "<<root->data;
}

int main(int argc, char*argv[])
{
	int inorder[20], preorder[20];
	cout<<"\nInput the number of nodes\n";
	cin>>n;
	cout<<"\nInput the inorder\n";
	for(int i=0; i<n; i++)
	{
		cin>>inorder[i];
	}
	cout<<"\nInput the preorder\n";
	for(int i=0; i<n; i++)
	{
		cin>>preorder[i];
	}
	NODE *root = build_tree(inorder, preorder, 0, n-1, 0, n-1);
	cout<<endl;
	print(root);
	cout<<endl;
	return 0;
}	

