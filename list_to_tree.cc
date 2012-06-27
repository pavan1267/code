#include<iostream>
using namespace std;

struct NODE
{
	int data;
	NODE *left;
	NODE *right;
};

NODE* insert(NODE *first, NODE *cur)
{
	if(first == NULL)
	{
		first = cur;
		return first;
	}
	NODE *temp = first;
	while(temp->right != NULL)
	{
		temp = temp->right;
	}
	temp->right = cur;
	cur->left = temp;
	return first;
}
int count_list(NODE *first)
{
	if(first == NULL)	return 0;
	NODE *temp = first;
	int count = 0;
	while(temp != NULL)
	{
		count = count + 1;
		temp = temp->right;
	}
	return count;
}
void print_list(NODE *first)
{
	if(first == NULL)
	{
		cout<<"\nList is empty\n";
		return;
	}
	NODE *temp = first;
	while(temp != NULL)
	{
		cout<<" "<<temp->data;
		temp = temp->right;
	}
}

NODE* build_tree(NODE *first, int count)
{
	if(count == 0)
		return NULL;
	int mid = (count / 2) + 1;
	NODE *temp = first;
	int count_node = 1;
	while(count_node != mid)
	{
		count_node = count_node + 1;
		temp = temp->right;
	}
	int left = mid -1;
	int right = count - mid;
	temp->left = build_tree(first, left);
	temp->right = build_tree(temp->right, right);
	return temp;			

}
void print_tree(NODE *root)
{
	if(root == NULL)
		return;
	cout<<" "<<root->data;
	print_tree(root->left);
	print_tree(root->right);
}

int main(int argc, char *argv[])
{
	NODE *first = NULL;
	int n;
	cout<<"\nInput the number of nodes\n";
	cin>>n;
	cout<<"\nInput the elements\n";
	for(int i=0; i<n; i++)
	{
		int ele;
		cin>>ele;
		NODE *cur = new NODE;
		cur->data = ele;
		cur->left = cur->right = NULL;
		first = insert(first, cur);
	}
	cout<<"\nLinked List\n";
	print_list(first);
	cout<<endl;
	int count = count_list(first);
	NODE *root = build_tree(first, count); 
	cout<<"\nPreorder of the tree\n";
	print_tree(root);
	cout<<endl;
	return 0;	
}

