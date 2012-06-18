#include<iostream>
using namespace std;
struct NODE
{
	int data;
	NODE *left;
	NODE *right;
};


void insert( NODE **root, NODE *cur)
{

	if( !(*root))
	{
		*root = cur;
		return;
	}
	if( (*root)->data < cur->data )
		insert(&(*root)->left, cur);
	else
		insert(&(*root)->right, cur);


}

int height(NODE *root)
{
	if(root == NULL)
		return 0;

	int left = height(root->left) + 1;;
	int right = height(root->right) + 1;

	if( left>right) return left;

	return right;
}
	


int find_diameter(NODE *root)
{
	int left_height = 0, right_height = 0;
	if(root == NULL)
	{
		return 0;
	}

	left_height =  height(root->left);
	right_height = height(root->right);
	int ld=0, rd=0;
	ld = find_diameter(root->left);
	rd = find_diameter(root->right);
	return ( max(left_height + right_height + 1, max(ld, rd)));

}



int main(int argc, char * argv[])
{

	NODE *root;
	root= NULL;
	int n;	
	cout<<"\nInput the number of nodes";
	cin>>n;
	cout<<"\nInput the elements\n";
	for( int i=0; i<n; i++)
	{
		int ele;
		cin>>ele;
		NODE *cur = new NODE;
		cur->data = ele;
		cur->left = cur->right = NULL;
		insert( &root, cur );
	}
	

	int diameter = find_diameter(root);

	cout<<"\nHeight= "<<diameter<<endl;

	return 0 ;
}

