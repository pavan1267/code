#include<iostream>
#include "support_tree_eval.h"


int tree_eval(NODE *root)
{
	if(root == NULL)
	{
		return 0;
	}
	int val = root->data;
	int sum = tree_eval(root->left) + tree_eval(root->right);
	root->data = sum;
	return sum+val;
}

int main(int argc, char *argv[])
{
	NODE *root = NULL;
	int n;
	cout<<"\nInput the number of nodes";
	cin>>n;
	for(int i=0; i<n; i++)
	{	
		int ele;
		cin>>ele;
		NODE *cur = new NODE;
		cur->data = ele;
		cur->left = cur->right = NULL;
		insert(&root, cur);
	}

	cout<<"\nThe value of the tree = "<<tree_eval(root);
	cout<<endl;
	print(root);
	return 0;
}
