#include<iostream>
#include<stack>
#include "support.h"
using namespace std;
int maxht;
stack <int> right_nodes; 

void left(NODE *root)
{
	if( root == NULL)
		return;
	if( root->left != NULL)
	{
		cout<<" "<<root->left->data;
		root->left->visited = 1;
	}
	left(root->left);
	return;

}
void bottom(NODE *root, int ht)
{
	if(root == NULL)
		return;
	if((ht == maxht)&&(root->visited == 0))
	{
		root->visited = 1;
		cout<<" "<<root->data;
	}
	bottom(root->left, ht+1);
	bottom(root->right, ht+1);
	return;
}
void right(NODE * root)
{
	if(root == NULL)
		return;
	if( root->visited == 0)
	{
		root->visited = 1;
		right_nodes.push(root->data);
	}
	if(root->right == NULL)
		right(root->left);
	else
		right(root->right);
	return;
}
int main( int argc, char* argv[])
{
	int n;
	NODE *root = NULL;
	cout<<"\nInput the number of node";
	cin>>n;
	cout<<"\nInput the elements\n";
	for(int i=0;i<n;i++)
	{
		NODE *cur = new NODE;
		int ele;
		cin>>ele;
		cur->data = ele;
		cur->left = NULL;
		cur->right = NULL;
		cur->visited = 0;
		insert( &root, cur);
	}

	maxht = height(root);
	cout<<"\nHeight= "<<maxht<<endl;
	cout<<"print ";
	print(root);
	cout<<endl;
	left(root);
	bottom(root, 1);
	right(root);
	while(!right_nodes.empty())
	{
		cout<<" "<<right_nodes.top();
		right_nodes.pop();
	}
	cout<<endl;
	return 0;
}
