/* Program 16.	Implement Inorder,Preorder,Postorder traversals on Binary Search Tree (using STACKS) */

// Sample array: 64 1 18 34 5 6 78 49 32

#include<iostream>
#include<process.h>
#include<vector>    // For creating dynamic array
#include<stack>

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

stack <int> PREORDER_STACK;
stack <int> INORDER_STACK;
stack <int> POSTORDER_STACK;

node* insertBST(int val,node * root)
{
    if(root==NULL)              // Base case
    {
        node * ptr=new node(val);
        root=ptr;
        return root;
    }
    if(val < root->info)
    {
        root->left=insertBST(val,root->left);
    }
    else
    {
        root->right=insertBST(val,root->right);
    }
    return root;
}

node* deleteFromBST(int value,node * root)
{
    if(root==NULL)                                           // BASE CONDITION :: Value not found base condition
    {
        cout<<"\n Sorry the value is not present in BST, so can't delete";
        return root;
    }
    else if(root->left==NULL && root->right==NULL && root->info==value)          // CONDITION 1.1:: Leaf node  condition
    {
        int temp=root->info;
        root=NULL;
        cout<<"Hurray! Value found in BST and is successfully deleted";
        cout<<"\n Deleted value is: "<<temp;
        return root;
    }
    else if(root->left==NULL && root->info==value)         // CONDITION 1.2:: Non leaf node case 1: When node has only right subtree
    {
        // Here we need to take "smallest from right"

        cout<<"\n Deleted value is: "<<root->info;
        node *right=root->right;
        delete(root);
        cout<<"\n Value successfully deleted from BST";
        return right;
    }
    else if(root->right==NULL && root->info==value)         // CONDITION 1.2:: Non leaf node case 2: When node has only left subtree
    {
        // Here we need to take "largest from left"

        cout<<"\n Deleted value is: "<<root->info;
        node *left=root->left;
        delete(root);
        cout<<"\n Value successfully deleted from BST";
        return left;
    }
    else if(root->info==value)                         // CONDITION 1.2:: Non leaf node case 3: When node has both left and right subtree
    {
        // Here we can take either "largest from left" or "smallest from right" and replace it with current node
        // So we choose "smallest from right"

        node* min_from_right=root->right;       // Since we want smallest from right of node
        while(min_from_right->left!=NULL){              // Since smallest value is present on leftmost node
            min_from_right=min_from_right->left;
        }

        // SWAPPING the smallest value in right subtree of root node with the root node value
        int min_val=min_from_right->info;  //    Swapping line 1
        min_from_right->info=root->info;     //    Swapping line 2
        root->info=min_val;          //    Swapping line 3

        // Now again recursively callling "deleteFromBST(initial root node value which was to be deleted, right node of the root)"
        // and initializing it to right node of root
        root->right=deleteFromBST(min_from_right->info,root->right); //Here "min_from_right->info" now represent the actual value which we wanted to delete
        return root;

    }

    if(value < root->info)                                          
    {
        root->left = deleteFromBST(value,root->left);
    }
    else                                                           
    {
        root->right = deleteFromBST(value,root->right);
    }
    return root;
}

void smallSearch(node *root)
{
    if(root->left==NULL)
    {
        cout<<"\n The smallest value in BST is: "<<root->info;
        return;
    }
    smallSearch(root->left);
    return;
}

void largeSearch(node *root)
{
    if(root->right==NULL)
    {
        cout<<"\n The smallest value in BST is: "<<root->info;
        return;
    }
    largeSearch(root->right);
    return;
}

void valueSearch(int value,node *root)
{
    if(root==NULL)
    {
        cout<<"\n Sorry the value is not present in BST";
        return;
    }
    else if(root->info==value)
    {
        cout<<"\n "<<value<<" is present in BST";
        return;
    }

    if(value< root->info)
    {
        valueSearch(value,root->left);
    }
    else
    {
        valueSearch(value,root->right);
    }
    return;
}

/*
void preorder(node* root)
{
    string result;
    stack <node*> PREORDER_STACK;
    if(root->left==NULL && root->right==NULL)           // If tree has only root node
    {
        cout<<"\n \n PREORDER of BST: "<<root->info;
    }
    else
    {
        node * PTR;
        PTR=root;
        cout<<"\n PTR \t \t PRINT";
        step1:                                              //goto label 1
            while(PTR!=NULL)
            {
                result += to_string(PTR->info);
                result+=' ';
                cout<<"\n  "<<PTR->info<<"\t \t"<<result;
                if(PTR->right!=NULL)
                {    PREORDER_STACK.push(PTR->right);}
                PTR=PTR->left;
            }
        step2:                                           //goto label 1
            if(!PREORDER_STACK.empty())
            {
                PTR=PREORDER_STACK.top();
                PREORDER_STACK.pop();
                // Now we have PTR, therefore return to step 1
                goto step1;                                                //goto statement
            }
            cout<<"\n \n PREORDER of BST: "<<result;
    }
}
*/

void preorder(node* root)
{
    string result;
    stack <node*> PREORDER_STACK;
    if(root->left==NULL && root->right==NULL)          // If tree has only root node
    {
        cout<<"\n \n PREORDER of BST: "<<root->info;
    }
    else
    {
        node * PTR;
        PTR=root;
        cout<<"\n PTR \t \t PRINT [PREORDER]";

        while(PTR!=NULL)         // When the ptr is not null
        {
            while(PTR!=NULL)                // To go to leftmost element in BST
            {
                result += to_string(PTR->info);
                result+=' ';
                cout<<"\n  "<<PTR->info<<"\t \t  "<<result;
                if(PTR->right!=NULL)            //If node has a right child
                {    PREORDER_STACK.push(PTR->right);}
                PTR=PTR->left;
            }

            if(!PREORDER_STACK.empty())
            {
                PTR=PREORDER_STACK.top();
                PREORDER_STACK.pop();
                // Now we have PTR, therefore return to previous step 
            }
        }
        cout<<"\n \n PREORDER of BST: "<<result;
    }
}


void inorder(node* root)
{
    string result;
    stack <node*> INORDER_STACK;
    if(root->left==NULL && root->right==NULL)          // If tree has only root node
    {
        cout<<"\n \n INORDER of BST: "<<root->info;
    }
    else
    {
        node * PTR=root;
        cout<<"\n PTR \t \t PRINT [INORDER]";

        while(PTR!=NULL)         // When the ptr is not null
        {
            while(PTR!=NULL)                // To go to leftmost element in BST
            {
                INORDER_STACK.push(PTR);
                cout<<"\n  "<<PTR->info;
                PTR=PTR->left;
            }

            while(!INORDER_STACK.empty())
            {
                node * TEMP=INORDER_STACK.top();        // to store the popped node
                INORDER_STACK.pop();
                
                // Pop and process TEMP
                result += to_string(TEMP->info);
                result+=' ';
                cout<<"\n   "<<"\t \t  "<<result;

                if(TEMP->right!=NULL)            //If node has a right child
                {
                    PTR=TEMP->right; 
                    break;      // So that it can come out of this while loop and go to outer while loop i.e previous step
                }
            }
        }
        cout<<"\n \n INORDER of BST: "<<result;
    }
}

void postorder(node* root)
{
    string result;
    stack <node*> POSTORDER_STACK;
    if(root->left==NULL && root->right==NULL)          // If tree has only root node
    {
        cout<<"\n \n POSTORDER of BST: "<<root->info;
    }
    else
    {
        node * PTR=root;
        cout<<"\n PTR \t \t PRINT [POSTORDER]";

        while(PTR!=NULL)         // When the ptr is not null
        {
            while(PTR!=NULL)                // To go to leftmost element in BST
            {
                POSTORDER_STACK.push(PTR);
                if(PTR->right!=NULL)
                {
                    POSTORDER_STACK.push(PTR->right);
                    POSTORDER_STACK.push(NULL);       // Because we can't insert a sentinal here as stack is of nodes
                }
                cout<<"\n  "<<PTR->info;
                PTR=PTR->left;
            }

            while(!POSTORDER_STACK.empty())
            {
                if(POSTORDER_STACK.top()!=NULL)   // non sentinal node case
                {
                    node * TEMP=POSTORDER_STACK.top();        // to store the popped node
                    POSTORDER_STACK.pop();
                    result += to_string(TEMP->info);
                    result+=' ';
                    cout<<"\n   "<<"\t \t  "<<result;
                }
                else                            // Sentinal case
                {
                    POSTORDER_STACK.pop();             //pop NULL 
                    PTR=POSTORDER_STACK.top();        // to store the popped node
                    POSTORDER_STACK.pop();
                    break;
                }
            }
        }
        cout<<"\n \n POSTORDER of BST: "<<result;
    }
}


int main()
{
    int ch,value;
	cout<<"******02216412819*******"<<endl;
	cout<<"*****Abhishek Jain*****"<<endl;
    node * root=NULL;
    do
    {
        cout<<endl;
        cout<<"\n ***************************************";
        cout<<"\n Binary Search Tree Menu               *";
        cout<<"\n --------------------------------------*"; 
        cout<<"\n 1. Insert into BST                    *";
        cout<<"\n 2. Delete from BST                    *";
        cout<<"\n 3. Search a value in BST              *";
        cout<<"\n 4. Print Preorder of BST using Stack  *";
        cout<<"\n 5. Print Inorder of BST using Stack   *";
        cout<<"\n 6. Print Postorder of BST using Stack *";
        cout<<"\n 7. Exit                               *";
        cout<<"\n ***************************************";
        cout<<"\n Enter the choice:";
        cin>>ch;
        switch(ch)
        {
            case 1:
            {
                int value;
                cout<<"\n Enter the value to be inserted into BST:";
                cin>>value;
                root=insertBST(value,root);
                cout<<"\n Value inserted successfully";
            };break; 
            case 2:
            {
                if(root==NULL)
                {
                    cout<<"\n Sorry can't delete as initial BST not created";
                }
                else
                {
                    int value;
                    cout<<"\n Enter the value to be deleted from BST: ";
                    cin>>value;
                    root=deleteFromBST(value,root);
                } 
            }break;
            case 3:
            {
                if(root==NULL)
                {
                    cout<<"\n Can't search as BST is not created yet";
                }
                else
                {
                    int choice,value;
                    cout<<"\n Search Menu: ";
                    cout<<"\n 1. Search the smallest value";
                    cout<<"\n 2. Search the largest value";
                    cout<<"\n 3. Search a particular value";
                    cout<<"\n Enter the choice:";
                    cin>>choice;
                    switch(choice)
                    {
                        case 1: smallSearch(root);break;
                        case 2: largeSearch(root);break;
                        case 3: 
                        cout<<"\n Enter the value that is to be searched: ";
                        cin>>value;
                        valueSearch(value,root);break;
                        default: cout<<"\n Entered wrong choice ";

                    }
                }
                
            }break;
            case 4:
            {
                if(root==NULL)
                {
                    cout<<"\n Sorry! The BST is empty";
                }
                else
                {
                    preorder(root); 
                }
            }break; 
            case 5:
            {
                if(root==NULL)
                {
                    cout<<"\n Sorry! The BST is empty";
                }
                else
                {
                    inorder(root);
                }
            }break; 
            case 6:   
            {
                if(root==NULL)
                {
                    cout<<"\n Sorry! The BST is empty";
                }
                else
                {
                    postorder(root); 
                }
            }break; 
            case 7: exit(0);
        }
    } while (ch<=7);
    return 0;
}