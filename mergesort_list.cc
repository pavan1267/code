#include<iostream>
#include "insert_list.h"



void split_list(NODE *first, NODE **a, NODE **b)
{
        NODE *slow, *fast;
        slow = first;
        fast = (first)->link;
        while((fast!=NULL)&&(fast->link != NULL))
        {
                slow = slow->link;
                fast = fast->link->link;
        }
        *a = first;
        *b = slow->link;
        slow->link= NULL;
}

NODE* merge_list(NODE *a, NODE *b)
{
	NODE *result = NULL;
	if(a == NULL)
	{
		return b;
	}
	else if(b == NULL)
	{
		return a;
	}
	else
	{
		if(a->data <= b->data)
		{
			result = a;
			result->link = merge_list(a->link, b);
		}
		else
		{
			result = b;
			result->link = merge_list(a, b->link);
		}
	}
	return result;
}


void merge_sort(NODE **first)
{
	NODE *a, *b;
	if((*first == NULL)||((*first)->link == NULL))
	{
		return;
	}
	split_list(*first, &a, &b);
	merge_sort(&a);
	merge_sort(&b);
	*first = merge_list(a, b);
	
}

int main(int argc, char *argv[])
{
        NODE *first = NULL;
        int n;
        cout<<"\nInput n\n";
        cin>>n;
        cout<<"\nInput the elements\n";
        for(int i=0; i<n; i++)
        {
                NODE *cur = new NODE;
                int ele;
                cin>>ele;
                cur->data = ele;
                cur->link = NULL;
                first = insert_list(first, cur);
        }
        cout<<endl;
        print_list(first);
        cout<<endl;
	cout<<"\nSorted list\n";
	merge_sort(&first);
	print_list(first);
	cout<<endl;
        return 0;
}




