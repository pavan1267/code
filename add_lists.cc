#include<iostream>
#include<stack>

using namespace std;
stack <int> s1, s2, s3;
struct NODE
{
	int data;
	NODE *link;
};

NODE *list1 =NULL, *list2 =NULL, *last1= NULL, *last2=NULL, *list3=NULL, *last3=NULL;
void form_stack(stack <int>*s, int n)
{
	while(n!=0)
	{
		int r = n % 10;
		s->push(r);
		n = n/10;
	}
}


NODE* list_form(stack <int> &s, NODE *list, NODE **last)
{
	NODE *prev, *tmp;
	while(!s.empty())
	{
		int ele = s.top();
		s.pop();
		NODE * cur = new NODE;
		cur->data = ele;
		cur->link = NULL;
		if(list == NULL)
		{
			list = cur;
			*last = list;
		}
		else
		{
			NODE *temp;
			temp = list;	
			prev = NULL;
			while(temp != *last)
			{
				tmp = temp;
				temp = (NODE*)((unsigned int)temp->link ^ (unsigned int)prev);
				prev = tmp;
			}
			temp->link = (NODE*)((unsigned int)cur ^ (unsigned int)temp->link);
			*last = cur;
			(*last)->link = temp;
		}
	}
	return list;
}
		
void print_list(NODE *list, NODE *last)
{
	NODE *cur = list, *prev = NULL, *temp;
	if(list == NULL)
	{
		cout<<"\nList is empty\n";
		return;
	}
	while(cur != last)
	{
		cout<<" "<<cur->data;
		temp = cur;
		cur = (NODE*)((unsigned int)cur->link ^ (unsigned int)prev);
		prev = temp;
	}
	cout<<" "<<cur->data;

}	
	
void sum_list(stack <int> *s3)
{
	NODE *temp1, *temp2, *prev1, *prev2, *tmp1, *tmp2;
	temp1 = last1;
	temp2 = last2;
	prev1 = prev2 = NULL;
	int carry = 0;
	while(temp1 != NULL && temp2 != NULL)
	{
		int a = temp1->data;
		int b = temp2->data;
		int sum = a+b+carry;
		if(sum > 10)
		{
		 	int r = sum % 10;
			s3->push(r);
			carry = sum / 10;
		}
		else
			s3->push(sum);
		tmp1 = temp1;
		tmp2 = temp2;
		temp1= (NODE*)((unsigned int)temp1->link ^ (unsigned int) prev1); 
		temp2= (NODE*)((unsigned int)temp2->link ^ (unsigned int) prev2);
		prev1 = tmp1;
		prev2 = tmp2;
	}
	while(temp1 != NULL)
	{
	
		int sum = temp1->data + carry;
		if(sum >10)
		{
			int r = sum % 10;
			s3->push(r);
			carry = sum / 10;
		}
		else
			s3->push(sum);
		tmp1 = temp1;
		temp1= (NODE*)((unsigned int)temp1->link ^ (unsigned int) prev1);
		prev1 = tmp1;
	}
	while(temp2 != NULL)
        {

                int sum = temp2->data + carry;
                if(sum >10)
                {
                        int r = sum % 10;
                        s3->push(r);
                        carry = sum / 10;
                }
                else
                        s3->push(sum);
                tmp2 = temp2;
                temp2= (NODE*)((unsigned int)temp2->link ^ (unsigned int) prev2);
                prev2 = tmp2;

        }
}
int main(int argc, char* argv[])
{
	int n1, n2;
	cout<<"\nInput n1";
	cin>>n1;
	cout<<"\nInput n2";
	cin>>n2;
	form_stack(&s1,n1);
	form_stack(&s2, n2);
	list1 = list2 = NULL;	
	list1 = list_form(s1, list1, &last1);
	list2 = list_form(s2, list2, &last2);
	cout<<"\nList1\n";
	print_list(list1, last1);
	cout<<"\nList2\n";
	print_list(list2, last2);
	sum_list(&s3);
	cout<<"\nSum of lists\n";
	list3 = list_form(s3, list3, &last3);
	print_list(list3, last3);
	cout<<endl;
	return 0;



}
