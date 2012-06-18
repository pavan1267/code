#include<iostream>
using namespace std;

struct NODE
{
	int data;
	NODE* left;
	NODE* right;
};

int find_len( NODE* root)
{
	if( root == NULL) return 0;

	int left_tree = find_len( root->left) + 1;
	int right_tree = find_len( root->right) + 1;

	if( left_tree > right_tree) return left_tree;

	return right_tree;

}


void insert( NODE** root, NODE* cur)
{
	if( !(*root))
	{
		*root = cur;
		return;
		
	}

	if( cur->data < (*root)->data)
		insert( &((*root)->left), cur);

	else
		insert( &((*root)->right), cur);
}


void print_tree( NODE* root)
{
	if( root == NULL)
		return;

	print_tree( root->left);
	cout<<" "<<root->data;
	print_tree( root->right);

}


int main( int argc, char* argv[])
{
	int n;
	NODE* root, *cur;
	root = NULL;
	cout<<"\n Root= "<<(root)<<endl;
	cout<<"\nInput the number of nodes\n";
	cin>>n;
	cout<<"\nInput the elements\n";
	for(int i=0; i<n; i++)
	{
		cur = new NODE;
		int ele;
		cin >> ele;
		cur->data = ele;
		cur->left = NULL;
		cur->right = NULL;
	//	cin>>ele;
		insert( &root, cur);
	}  
	
	print_tree(root);

	int len = find_len( root);

	cout<<"\nNo of nodes in the longest path= "<<len<<endl;
	return 0;
}











