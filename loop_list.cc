#include<iostream>
using namespace std;


struct NODE
{
	int data;
	NODE *link;
};

NODE *first, *first_loop, *second_loop;
NODE* insert_list(NODE *cur, int ele)
{
	NODE *temp;
	temp = first;
	if(first == NULL)
	{
		first = cur;
		cout<<"\nIn insert  "<<first->data<<" "<<cur->data<<endl;
		return cur;
	}
	while(temp->link != NULL)
	{
		temp = temp->link;
	}
	temp->link = cur;
	return first;
}

void print_list(NODE *first)
{
	if(first == NULL)
	{
		cout<<"\nList is empty\n";
		return;
	}
	NODE *temp = first;
	while(temp!=NULL)
	{
		cout<<" "<<temp->data;
		temp = temp->link;
	}
	return;
}
void insert_loop(NODE *first, int a, int b)
{
	if(first == NULL)
	{
		cout<<"\nList is empty\n";
		return;
	}
	if( a==-1)
		return;
	NODE *temp = first;
	while(temp->data != a)
	{
		temp = temp->link;
	}
	first_loop = temp;
	temp = first;
	while(temp->data != b)
	{
		temp = temp->link;
	}
	second_loop = temp;
	second_loop->link = first_loop;

}
int find_loop(NODE *first)
{
	NODE *slow, *fast;
	slow = first;
	if((first==NULL)||(fast->link==NULL))	return 0;
	fast = first->link->link;
	cout<<"\nFast data\n";
	while( (fast!=NULL) && (slow!=fast))
	{
		slow = slow->link;
		if(fast->link == NULL)	return 0;
		fast = fast->link->link;
	}
	if(fast == NULL)
		return 0;
	return 1;
}

int main(int argc, char *argv[])
{
	first=NULL;
	int n;
	cout<<"\nInput the number of nodes\n";
	cin>>n;
	cout<<"\nInput the data\n";
	for(int i=0; i<n; i++)
	{
		int ele;
		cin>>ele;
		NODE *cur = new NODE;
		cur->data = ele;
		cur->link = NULL;
		first = insert_list(cur, ele);
	}
	cout<<endl;
	print_list(first);
	cout<<"\nInput the nodes for the loop\n";
	int a, b;
	cin>>a;
	cin>>b;
	insert_loop(first, a, b);
	int val = find_loop(first);
	if(val == 1)
		cout<<"\nList has a loop\n";
	else
		cout<<"\nList does not have a loop\n";

	return 0;
}

