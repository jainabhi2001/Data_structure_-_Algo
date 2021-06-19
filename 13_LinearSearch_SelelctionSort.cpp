// Program : Implement linear search and selection sort in a single linked list.
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

void traverse()
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

void LinearSearch()
    {
        if (head==NULL)
        {
            cout<<"\n Sorry the Linked list is empty, so you can't search";
        }
        else
        {
            int value;
            int count=0;      // For telling position 
            cout<<"\n Enter the value you want to search: ";
            cin>>value;
            node *temp=head;
            while(temp!=NULL)
            {
                count+=1;
                if((temp->info!=value) && (temp->next==NULL))
                {
                    cout<<"\n Sorry value not found";exit(0);
                }
                else if(temp->info==value)
                {
                    cout<<"\n"<<value<<" found in Linked list at '"<<count<<"' position";break;
                }
                temp=temp->next;
            }
        }
    }

void SelectionSort()
{
    if (head==NULL)
    {
        cout<<"\n Sorry the Linked list is empty, so can't sort";
    }
    else if(head->next==NULL)   {cout<<"\n Linked List is already sorted";}  // Nothing to do,as one element means already sorted
    else
    {
        node *list1=head;
        while(list1!=NULL)
        {
            node* small=list1;
            node *list2=list1->next;
            while(list2!=NULL)
            {
                if(small->info > list2->info)
                {  small=list2;  }
                list2=list2->next;
            }
            int temp=list1->info;
            list1->info=small->info;
            small->info=temp;
            list1=list1->next;
        }
        cout<<"\t After sorting: ";
    }
}

int main()
{
    int ch;
	cout<<"******02216412819*******"<<endl;
	cout<<"*****Abhishek Jain*****"<<endl;
    do
    {
        cout<<"\n Menu:";
        cout<<"\n 1. Transverse through Linked list";
        cout<<"\n 2. Insert into Linked List";
        cout<<"\n 3. Delete from Linked List";
        cout<<"\n 4. Linear search";
        cout<<"\n 5. Selection sort ";
        cout<<"\n 6. Exit";
        cout<<"\n Enter the choice:";
        cin>>ch;
        switch(ch)
        {
            case 1: traverse();break;
            case 2:
                    {
                        int inser,value,position=0;
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
                                default: cout<<"\n Wrong choice";exit(1);
                            }
                        }
                        traverse();
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
                                default: cout<<"\n Wrong choice";exit(1);
                            }
                        }
                        traverse();
                    }break; 
            case 4: LinearSearch();break;   
            case 5: SelectionSort();traverse();break;
            case 6: exit(0);
        }
    } while (ch<=6);
    return 0;
}
