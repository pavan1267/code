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

void mark_list(NODE *first)
{
	while(first != NULL)
	{
		first->flag = 1;
		first = first->link;
	}
}
NODE* find_inter(NODE* first)
{
	while((first->flag !=1)&&(first != NULL))
	{
		first = first->link;
	}
	return first;
}

int main(int argc, char* argv[])
{
	NODE *first1 = NULL, *first2 = NULL;
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
		cur->flag = 0;
		cur->link = NULL;
		first1 = insert_list(first1, cur);
	}
	cout<<"\nInput the intersection point\n";
	int ele;
	cin>>ele;
	NODE *temp = find_node(first1, ele);
	NODE *last1 = find_last(first1);
	cout<<"\nInsert the number of nodes on list2\n";
	cin>>n;
	for(int i=0; i<n; i++)
	{
		int ele;
		cin>>ele;
		NODE *cur = new NODE;
		cur->data = ele;
		cur->flag = 0;
		cur->link = NULL;
		first2 = insert_list(first2, cur);
	}
	NODE *last2 = find_last(first2);
	last2->link = temp;
	cout<<endl;
	print_list(first1);
	cout<<endl;
	print_list(first2);
	cout<<"\nAddr of intersection point= "<<temp<<endl;
	mark_list(first1);
	NODE *intr = find_inter(first2);
	cout<<"\nAddr of the point = "<<intr<<endl;
	return 0;

}
