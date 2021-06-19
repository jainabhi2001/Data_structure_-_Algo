#include<iostream>
#include<process.h>

using namespace std;

struct node
{
    int info;
    node *left;
    node *right;
    node(int val)
    {
        info=val;
        left=NULL;
        right=NULL;
    }
};
/* 
// Function to insert nodes in level order
Node* insertLevelOrder(int arr[], Node* root,
                       int i, int n)
{
    // Base case for recursion
    if (i < n)
    {
        Node* temp = newNode(arr[i]);
        root = temp;
  
        // insert left child
        root->left = insertLevelOrder(arr,
                   root->left, 2 * i + 1, n);
  
        // insert right child
        root->right = insertLevelOrder(arr,
                  root->right, 2 * i + 2, n);
    }
    return root;
}
 */
void preorder(node* root)
{
    if(root=NULL)
    {
        return;
    }
    cout<<root->info<<" ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(node* root)
{
    if(root=NULL)
    {
        return;
    }
    inorder(root->left);
    cout<<root->info<<" ";
    inorder(root->right);
}

void preorder(node* root)
{
    if(root=NULL)
    {
        return;
    }
    preorder(root->left);
    preorder(root->right);
    cout<<root->info<<" ";
}

int main()
{
    int ch;
	cout<<"******02216412819*******"<<endl;
	cout<<"*****Abhishek Jain*****"<<endl;
/*     int arr[] = { 1, 2, 3, 4, 5, 6, 6, 6, 6 };
    int n = sizeof(arr)/sizeof(arr[0]);*/
    Node* root = insertLevelOrder(arr, root, 0, n); 

    do
    {
        cout<<"\n Menu:";
        cout<<"\n 1. Insert into Linked List";
        cout<<"\n 2. Print preorder traversal";
        cout<<"\n 3. Print inorder traversal";
        cout<<"\n 4. Print postorder traversal";
        cout<<"\n 5. Exit";
        cout<<"\n Enter the choice:";
        cin>>ch;
        switch(ch)
        {
            case 1: insertLevelOrder();break;
            case 2: preorder(root); break; 
            case 3: inorder(root);break;
            case 4: postorder(root);break;   
            case 5: exit(0);
        }
    } while (ch<=5);
    return 0;
}

