#include<iostream>
#include "support.h"

NODE *prev = NULL;
void tree_list(NODE *root, NODE **head)
{
	if(root == NULL)
		return;
	tree_list(root->left, head);
	root->left = prev;
	if(prev != NULL)
	{
		prev->right = root;
	}
	else
	{
		*head = root;
	}
	(*head)->left = root;
	NODE *right = root->right;
	root->right = *head;
	prev = root;
	tree_list(right, head);
}

void print_list(NODE *head)
{
	if(head == NULL)
		return;
	NODE *cur = head;
	while(cur->right != head)
	{
		cout<<" "<<cur->data;
		cur=cur->right;
	}
	cout<<" "<<cur->data;
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
	NODE *head = NULL;	
	tree_list(root, &head);
	cout<<endl;
	print_list(head);
	cout<<endl;
	return 0;
}

