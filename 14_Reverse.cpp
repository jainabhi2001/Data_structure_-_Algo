// Program: Write a program to count the total number of nodes & reverse the singly linked list.

#include<iostream>
#include<process.h>

using namespace std;

struct node
{
    int info;
    node *next;
    node(int val)
    {
        info=val;
        next=NULL;
    }
};

node * head=NULL;       // GLOBAL "head" pointer 
    void disp()
    {
        if (head==NULL)
        {
            cout<<"\n Sorry the Linked list is empty";
        }
        else
        {
            cout<<"\n The Linked list: ";
            if(head->next==NULL)
            {
                cout<<head->info<<"->";
            }
            else
            {
                node *temp=head;
                while(temp!=NULL)
                {
                    cout<<temp->info<<"->";
                    temp=temp->next;
                }
            }
            cout<<"NULL"<<endl;
        }    
    }

    void insertAtBeg(int val)
    {
        node *ptr=new node(val);
        ptr->next=head;
        head=ptr;
    }

    void insertAtEnd(int val)
    {
        node *ptr=new node(val);
        if (head->next==NULL)
        {
            head->next=ptr;
        }
        else
        {
            node *list=head;
            while(list->next!=NULL) { list=list->next; }
            list->next=ptr;
        }
    }

    void insertAtPos(int val,int pos)
    {
        if(head==NULL){cout<<"\n Sorry Linked list is empty so can't insert";}
        else
        {
            node *ptr=new node(val);
            node *temp=head;      
            while(temp->info!=pos)
            {
                temp=temp->next;
                if(temp==NULL){cout<<"\n  Location not found in LL ";return;}  // end of LL is reached and value still not found
            }
            if(temp->next==NULL) // When insertion at end position 
            {
                cout<<"\n  Sorry can't insert at end using this function";return;
            }
            ptr->next=temp->next;
            temp->next=ptr;
        }
    }

    void deleteAtBeg()
    {
        node *temp=head;
        cout<<"\n The deleted value is: "<<temp->info;
        head=head->next;
        delete(temp);
    }

    void deleteAtEnd()
    {
        node *list=head;
        while(list->next->next!=NULL){list=list->next;}
        {
            node *temp=list->next;
            list->next=NULL;
            delete(temp);
        }        
    }

    void deleteAtPos(int pos)
    {
        node *temp_prev;
        if(head->info==pos)
        {
            cout<<"\n Sorry can't delete at this position";
        }
        else
        {
            node *temp=head;      
            while(temp->info!=pos)
            {
                temp_prev=temp;
                temp=temp->next;
                if(temp==NULL){cout<<"\n  Location not found in LL ";return;}  // end of LL is reached and value position still not found
            }
            if(temp->next==NULL) // When deletion at end position 
            {
                cout<<"\n  Sorry can't delete at end using this function";return;
            }
	        temp_prev->next=temp->next;
	        delete temp;
        }
    }

    void reverse()
    {
        if(head==NULL)
        {
            cout<<"\n Can't reverse as Linked list is empty";
        }
        else if(head->next==NULL)
        {
            cout<<"\n Linked list is already reversed";
        }
        else
        {
            node * prev,*current,*save;
            current=head;
            prev=NULL;
            while(current!=NULL)
            {
                save=current->next;
                current->next=prev;
                prev=current;
                current=save;
            }
            head=prev;
        }
    }

    void Count()
    {
        if (head==NULL)
        {
            cout<<"\n The Linked list is empty, therefore '0' elements";
        }
        else if (head->next==NULL)
        {
            cout<<"\n There are total '1' node in the linked list";
        }
        else
        {
            int count=0;      // For telling position 
            node *temp=head;
            while(temp!=NULL)
            {
                count+=1;
                temp=temp->next;
            }
            cout<<"\n There are total '"<<count<<"' nodes in the linked list";
        }
    }

int main()
{
    int ch,value;
	cout<<"******02216412819*******"<<endl;
	cout<<"*****Abhishek Jain*****"<<endl;
    do
    {
        cout<<"\n Linked List Menu ";
        cout<<"\n 1. Transverse/Print through Linked List";
        cout<<"\n 2. Insert into Linked List";
        cout<<"\n 3. Delete from Linked List";
        cout<<"\n 4. Reverse the Linked List";
        cout<<"\n 5. Count the number of nodes in the Linked List";
        cout<<"\n 6. Exit";
        cout<<"\n Enter the choice:";
        cin>>ch;
        switch(ch)
        {
            case 1:disp();break;
            case 2:
            {
                int inser,position=0;
                cout<<"\n Enter the value to be inserted: ";
                cin>>value;
                if(head==NULL)
                {
                    node *ptr=new node(value);
                    head=ptr;
                    ptr->next=NULL;
                }
                else
                {
                    cout<<"\n Enter whether you want to insert at (1) Beginning (2) End (3) At position: ";
                    cin>>inser;
                    switch(inser)
                    {
                        case 1:insertAtBeg(value);break;
                        case 2:insertAtEnd(value);break;
                        case 3:{
                            cout<<"\n Enter the value after which you want to insert the element:";
                            cin>>position;
                            insertAtPos(value,position);}break;
                        default: cout<<"\n Wrong choice";
                    }
                }
                disp();
            }break; 
            case 3:
            {
                int del,position=0;
                if(head==NULL)
                {
                    cout<<"\n Can't delete, the Linked list is already empty";
                }
                else if(head->next==NULL)
                {
                    node *temp=head;
                    cout<<"\n The deleted value is: "<<temp->info;
                    head=NULL;
                    delete(temp);
                }
                else
                {
                    cout<<"\n Enter whether you want to delete at (1) Beginning (2) End (3) At position: ";
                    cin>>del;
                    switch(del)
                    {
                        case 1:deleteAtBeg();break;
                        case 2:deleteAtEnd();break;
                        case 3:{
                            cout<<"\n Enter the value that you want to delete:";
                            cin>>position;
                            deleteAtPos(position);}break;
                        default: cout<<"\n Wrong choice";
                    }
                }
                disp();
            }break;
            case 4: reverse();disp();break;
            case 5: Count();break;
            case 6: exit(0);
        }
    } while (ch<=5);
    return 0;
}
