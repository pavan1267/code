#include<iostream>
#include "support_tree_eval.h"


void print_level(NODE *root, int level, int dir)
{
	if(root == NULL)
		return;
	if(level == 1)
		cout<<" "<<root->data;
	if(dir == 0)
	{
		print_level(root->left, level-1, dir);
		print_level(root->right, level-1, dir);
	}
	else
	{
		print_level(root->right, level-1, dir);
                print_level(root->left, level-1, dir);
	}
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
                insert( &root, cur);
        }
	int ht = height(root);
	int dir = 0;
	for(int i=1; i<=ht; i++)
	{	
		print_level(root, i, dir);
		dir = !dir;
	}
	return 0;
}


