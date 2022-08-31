#include <iostream>
using namespace std;

class NODE
{
    public:
        int data;
        NODE *left, *right;
        NODE(int d)
        {
            data = d;
            left = NULL;
            right = NULL;
        }
};

class BST
{
    public:
        NODE *root, *nn, *ptr;
        BST()
        {
            root = NULL;
            ptr = root;
        }
        NODE* insert(NODE* root, int data)
        {
            if(root==NULL)
            {
                nn = new NODE(data);
                root = nn;
            }
            else
            {
                if(data<=root->data)
                    root->left = insert(root->left,data);
                else
                    root->right = insert(root->right,data);
            }
            return root;
        }
        void preorder(NODE* root)
        {
            if(root==NULL)
            {
                return;
            }
            else
            {
                cout<<root->data<<" ";
                preorder(root->left);
                preorder(root->right);
            }
        }
};

int main()
{
    BST T1;
    int arr[] = {6,3,5,7,8,4};
    for(int i=0;i<6;i++)
    {
        T1.root = T1.insert(T1.root,arr[i]);
    }
    cout<<"\nPreorder Traversal: \n";
    T1.preorder(T1.root);
}