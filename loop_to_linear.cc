#include<iostream>
using namespace std;

struct NODE
{
	int data;
	int marked;
	NODE *link;
};

int flag =1;
NODE *first, *first_loop, *second_loop;
NODE* insert_list(NODE *cur, int ele)
{
	NODE *temp;
	temp = first;
	if(first == NULL)
	{
		first = cur;
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
void find_loop(NODE *first)
{
	NODE *slow, *fast;
	slow = first;
	fast = NULL;
	if((first==NULL))	return ;
	while( slow!=fast)
	{
		if(flag)
		{
			flag = 0;
			fast = first;
		}
		slow = slow->link;
		fast = fast->link->link;
	}
	NODE *temp = slow;
	while(temp->link != fast)
	{
		temp->marked = 1;
		temp = temp->link;
	}
	temp->marked = 1;
	NODE *head = first;
	while(head->marked != 1)
	{
		head = head->link;
	}
	while(fast->link!=head)
	{
		fast = fast->link;
	}
	fast->link = NULL;
	return;	
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
		cur->marked = 0;
		first = insert_list(cur, ele);
	}
	cout<<endl<<"\nList is  ";
	print_list(first);
	cout<<"\nInput the end points of the loop";
	int a, b;
	cin>>a;
	cin>>b;
	insert_loop(first, a, b);
	find_loop(first);
	cout<<endl<<"\nLinear list is  ";
	print_list(first);
	cout<<endl;
	return 0;
}

