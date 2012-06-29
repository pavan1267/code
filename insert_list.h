#include<iostream>
using namespace std;

struct NODE
{
	int data;
	int flag;
	NODE *link;
};

NODE* insert_list(NODE *first, NODE *cur)
{
	if(first == NULL)
	{
		first = cur;
		return first;
	}
	cur->link = first;
	first = cur;
	return first;
}

NODE* find_node(NODE *first, int a)
{
	NODE *temp = first;
	while(temp->data != a)
	{
		temp = temp->link;
	}
	return temp;
}

NODE* find_last(NODE *first)
{
	NODE *temp = first;
	while(temp->link != NULL)
	{
		temp = temp->link;
	}
	return temp;
}


void print_list(NODE *first)
{
	NODE *temp = first;
	while(temp!=NULL)
	{
		cout<<" "<<temp->data;
		temp = temp->link;
	}
}

