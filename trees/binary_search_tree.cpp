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
        NODE *root, *nn;
        BST()
        {
            root = NULL;
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
                return;
            else
            {
                cout<<root->data<<" ";
                preorder(root->left);
                preorder(root->right);
            }
        }
        void inorder(NODE* root)
        {
            if(root==NULL)
                return;
            else
            {
                inorder(root->left);
                cout<<root->data<<" ";
                inorder(root->right);
            }
        }
        void postorder(NODE* root)
        {
            if(root==NULL)
                return;
            else
            {
                postorder(root->left);
                postorder(root->right);
                cout<<root->data<<" ";
            }
        }
        NODE* min_value_node(NODE* root)
        {
            NODE* curr = root;
            while(curr && curr->left!=NULL)
                curr=curr->left;
            return curr;
        }
        NODE* delete_node(NODE* root, int key)
        {
            if(root==NULL)
                return root;
            if(key<root->data)
                root->left=delete_node(root->left,key);
            else if(key>root->data)
                root->right=delete_node(root->right,key);
            else
            {
                if(root->left==NULL && root->right==NULL)      // no child
                    return NULL;
                else if(root->left==NULL)                      // only right child
                {
                    NODE* temp = root->right;
                    free(root);
                    return temp;
                }
                else if(root->right==NULL)                     // only left child
                {
                    NODE* temp = root->left;
                    free(root);
                    return temp;
                }

                /* Inorder successor (smallest node in right subtree)
                   is replaced by the root with 2 childs
                */
                NODE* min = min_value_node(root->right); 
                root->data=min->data;
                root->right = delete_node(root->right,min->data);
            }
            return root;
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
    cout<<"\nInorder Traversal: \n";
    T1.inorder(T1.root);
    cout<<"\nPostorder Traversal: \n";
    T1.postorder(T1.root);

    cout<<"\nMinimum value = "<<T1.min_value_node(T1.root)->data;
    T1.delete_node(T1.root,7);
    cout<<"\nInorder Traversal: \n";
    T1.inorder(T1.root);
}