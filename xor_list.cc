#include<iostream>
#include<stdlib.h>
using namespace std;


struct NODE
{
	int data;
	NODE *link;
};

NODE *head, *last;

void  insert(int ele)
{
	NODE *cur = new NODE;
	cur->data = ele;
	cur->link = NULL;
	if(head == NULL)
	{
		head = cur;
		last = cur;
		return;
	}
	head->link = (NODE*) ((unsigned int)head->link ^ (unsigned int)cur);
	cur->link = head;
	head = cur;
}

void delete_ele(int ele)
{
	NODE *prev, *cur;
	if(head == NULL)
	{
		cout<<"\nList is empty\n";
		return;
	}
	prev = NULL;
	cur = head;
	while(cur->data != ele)
	{
		NODE *temp = cur;
		cur = (NODE*)((unsigned int)cur->link ^ (unsigned int)prev);
		prev = temp;
	}
	NODE *next = (NODE*)((unsigned int)cur->link ^ (unsigned int)prev);
	if(head == last)
	{
		head = NULL;
		delete(cur);
		return;
	}
	if(cur == head)
	{
		head = next;
		next->link = (NODE*)((unsigned int)cur ^(unsigned int)next->link);
		delete(cur);
		return;
	}
	
	if(cur == last)
	{
		last = prev;
		prev->link = (NODE*)((unsigned int)prev->link ^ (unsigned int)cur);
		delete(cur);
		return;
	}
	prev->link = (NODE*)((unsigned int) prev->link ^ (unsigned int)cur ^(unsigned int) next);
	next->link = (NODE*)((unsigned int)next->link ^ (unsigned int)cur ^(unsigned int) prev);
	delete(cur);
}

void display()
{
	NODE *cur, *prev;
	cur = head;
	prev = NULL;
	if(head == NULL)
	{
		cout<<"\nList is empty\n";
		return;
	}
	while(cur != last)
	{
		cout<<" "<<cur->data;
		NODE *temp = cur;
		cur =(NODE*) ((unsigned int)cur->link ^ (unsigned int)prev);
		prev = temp;
	}	
	cout<<" "<<cur->data;
}


int main(int argc, char *argv[])
{
	int choice;
	
	for( ; ;)
	{
		cout<<"\n1. Insert  2. Delete  3. Display 4.Exit\n";
		cout<<"\nInput choice";
		cin>>choice;
		switch(choice)
		{
			case 1: int ele;
				cin>>ele;
				cout<<endl;
				insert(ele);
				break;
			case 2: cout<<"\nInput one of the elements in the list\n";
				cin>>ele;
				delete_ele(ele);
				break;
			case 3: display();
				cout<<endl;
				break;
			case 4: exit(0);
		}
	}

	return 0;

}

