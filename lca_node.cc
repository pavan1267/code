#include<iostream>
using namespace std;

struct NODE
{
	int data;
	NODE *left;
	NODE *right;
};

void insert(NODE **root, NODE *cur)
{
	if(!(*root))
	{
		*root = cur;
		return;
	}
	if((*root)->data < cur->data)
		insert(&((*root)->left), cur);
	else
		insert(&((*root)->right), cur);

}



int lca(NODE *root, int a, int b)
{


	if( root == NULL) return -1;

	if((root->data > a)&&(root->data < b)) 
		return root->data;

	if( (root->right!=NULL) && ( root->right->data == a || root->right->data == b))
		return root->data;
	if( (root->left != NULL) && ( root->left->data == a || root->left->data == b))
                return root->data;
	
	if( (root!=NULL) && ((root->data) < a) && (root->data < b))
		lca( root->left, a, b);
 	if( (root!=NULL) && ((root->data) > a) && (root->data > b))
                lca( root->right, a, b);

}
int main( int argc, char *argv[])
{

	int n;

	NODE *root;

	cout<<"\nInput the value of n\n";
	cin>>n;
	root = NULL;
	cout<<"\nInput the elements\n";
	for(int i=0; i<n;i++)
	{
		NODE *cur = new NODE;
		int ele;
		cin>>ele;
		cur->data = ele;
		cur->left = NULL;
		cur->right = NULL;
		insert(&root, cur);
	}
	cout<<"\n Input the two nodes\n";

	int a, b;
	cin>>a;
	cin>>b;
	int ansc = lca(root, a, b); 
	if(ansc == -1)
	{
		cout<<"\nThe nodes does not exit\n";
	}
	else
		cout<<"\nThe LCA of the two nodes = "<<ansc;

	cout<<endl;
	return 0;

}
