#include<iostream>
using namespace std;
int n;

struct NODE
{
	NODE* left;
	NODE* right;
	int data;
};

int find_node(int val, int pre[])
{
	int i;
	for(i=0; i<n; i++)
	{
		if(pre[i] == val)	return i;
	}
	return 0;
}


NODE* inorder(int pre[], int pos[], int pre_start, int pre_end, int pos_start, int pos_end)
{
	NODE *cur = NULL;
	if((pre_start > pre_end) || (pos_start > pos_end))	return cur;
	if( (pre_start == pre_end) || (pos_start == pos_end) )
	{
		cur = new NODE;
		cur->data = pre[pre_start];
		cur->left = NULL;
		cur->right = NULL;
		cout<<"\nInside if    ";
		cout<<"\nData =  "<<cur->data<<"pre_start = "<<pre_start<<"  pre_end = "<<pre_end<<"  pos_start =  "<<pos_start<<"  pos_end  =  "<<pos_end;
		return cur;
	}
	int right_child = find_node(pos[pos_end - 1], pre);
	int num_rchild;


	num_rchild = pre_end - right_child + 1;
	cout<<"  Right_index =  "<<right_child<<"  Number_child =   "<<num_rchild;
	int item;
	cin >> item;
	cur = new NODE;
	cur->data = pre[pre_start];
	cur->left = cur->right = NULL;
	cout<<"\nData =  "<<cur->data<<"pre_start = "<<pre_start<<"  pre_end = "<<pre_end<<"  pos_start =  "<<pos_start<<"  pos_end  =  "<<pos_end;
	if((pre_start < pre_end) && (pos_start < pos_end))
	{
		cur->left = inorder( pre, pos, pre_start+1, right_child -1, pos_start, pos_end - num_rchild -1);	
	}
	if((pre_start < pre_end) && (pos_start < pos_end))	
	{
		cur->right = inorder(pre, pos, right_child, pre_end, pos_end - 1 - num_rchild + 1, pos_end - 1);
	}	
	return cur;

}
void print( NODE* root)
{
	if( root == NULL) 	return;
	cout<<" "<< root->data;
	print( root->left);
	print( root->right);

}
int main(int argc, char* argv[])
{
	int pre[10], pos[10];
	NODE* root = NULL;
	cout<<"\nInput n";
	cin >> n;
	for(int i=0; i<n; i++)
	{
		cin >> pre[i];
	}
	for(int i=0; i<n; i++)
	{
		cin >> pos[i];
	}
	root = inorder(pre, pos, 0, n-1, 0, n-1);
	cout<<endl;
	print(root);
	return 0;
}




