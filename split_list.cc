#include<iostream>
#include "insert_list.h"

void split_list(NODE **first, NODE **a, NODE **b)
{
        NODE *slow, *fast;
        slow = *first;
	fast = (*first)->link;
        while((fast!=NULL)&&(fast->link != NULL))
        {
                slow = slow->link;
                fast = fast->link->link;
        }
        *a = *first;
	*b = slow->link;
	slow->link= NULL;
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
        NODE *a, *b;
	split_list(&first, &a, &b);
        cout<<endl;
	print_list(a);
	cout<<endl;
	print_list(b);
	cout<<endl;
        return 0;
}
