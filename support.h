using namespace std;
struct NODE
{
        int data;
	int visited;
        NODE* left;
        NODE* right;
};

void insert( NODE **root, NODE *cur)
{

        if( !(*root))
        {
                *root = cur;
                return;
        }
        if( cur->data < (*root)->data  )
                insert(&(*root)->left, cur);
        else
                insert(&(*root)->right, cur);


}

void print(NODE *root)
{
	if(root == NULL)
		return;
	print(root->left);
	cout<<" "<<root->data;
	print(root->right);
}

int height(NODE *root)
{

	if(root == NULL)	
		return 0;
	int lt = height(root->left) + 1;
	int rt = height(root->right) + 1;
	return max(lt, rt);
}


