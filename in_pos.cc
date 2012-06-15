#include<iostream>
using namespace std;

int index;
struct NODE
{
	int data;
	NODE* left;
	NODE* right;
};

int find_root( int root, int infix[], int st, int end)
{
	for(int i=st; i<=end; i++)
	{
		if(root == infix[i]) return i;
	}
	

}

NODE* create_tree(int infix[], int prefix[], int st, int end)
{

	cout<<"\nInside create\n";
	if( st > end)
	{
		return NULL;
	}

	NODE* node = new NODE;
	int root = prefix[index++];
	node->data = root;
	cout<<"\n Root= "<<node->data<<endl;

	node->left=NULL;
	node->right=NULL;
	if(st == end)
	{
		return node;
	}
	int i = find_root(root, infix, st, end);
	node->left = create_tree(infix, prefix, st, i-1); 
 	node->right = create_tree(infix, prefix, i+1, end);
	return node;

}

void print_tree( NODE* root)
{

	if( root==NULL) return;
	
	print_tree(root->left);
	print_tree(root->right);
	cout<<" "<<root->data;

}
int main(int argc, char* argv[])
{

	int n, in[10], pos[10];

	cout<<"\nInput the number of nodes\n";
	cin>>n;

	cout<<"\nInput the infix\n";
	for(int i=0;i<n;i++)
	{
		cin>>in[i];
	}
	cout<<"\nInput the prefix\n";
        for(int i=0;i<n;i++)
        {
                cin>>pos[i];
        }
	NODE* root = new NODE;
	root = create_tree(in, pos, 0, n-1);

	//cout<<"\nData at the root= "<<root->data;
	cout<<endl;
	print_tree(root);
	cout<<endl;
	return 0;

}





























































