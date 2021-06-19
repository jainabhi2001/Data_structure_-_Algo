/* Program 9 Implement menu driven program for insertion (at the beginning, at specified location, at the end) & deletion 
(at the beginning, at specified location, at the end) on singly linked list, circular single linked list.  */
// Insert at position according to "info" 
// First ask whether single LL or circular LL

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
                if(temp->next==NULL){cout<<"\n Sorry can't insert at position";exit(0);}  //(When insertion at end position) or (end of LL is reached and value still not found)
            }
            ptr->next=temp->next;
            temp->next=ptr;
        }
    }
// USE BELOW CODE FOR INSERTATPOSITION 
/*     
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
*/

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
        if(head->info==pos)
        {
            cout<<"\n Sorry can't delete at this position";
        }
        else
        {
            node *list=head;     
            while(list->next->info!=pos)
            {
                list=list->next;
                if(list->next->next==NULL){cout<<"\n Sorry can't delete at this position";exit(0);} 
            }
            node *temp=list->next;
            list->next=list->next->next;
            delete(temp);
        }
    }
// USE BELOW CODE FOR DELETEATPOSITION 
/*     
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
*/
    void Cdisp()
    {
        if (head==NULL)
        {
            cout<<"\n Sorry the Circular Linked List is empty";
        }
        else
        {
            cout<<"\n The Circular Linked List: ";
            if(head->next==head)
            {
                cout<<head->info<<"->";
            }
            else
            {
                node *temp=head->next;
                cout<<head->info<<"->";
                while(temp!=head)
                {
                    cout<<temp->info<<"->";
                    temp=temp->next;
                }
            }
        }    
    }

    void CinsertAtBeg(int val)
    {
        node *ptr=new node(val);
        if (head->next==head)
        {
            ptr->next=head;
            head->next=ptr;
        }
        else
        {
            node *list=head;
            while(list->next!=head){ list=list->next;}
            ptr->next=head;
            list->next=ptr;
            head=ptr;
        }
    }

    void CinsertAtEnd(int val)
    {
        node *ptr=new node(val);
        if (head->next==head)
        {
            ptr->next=head;
            head->next=ptr;
        }
        else
        {
            node *list=head;
            while(list->next!=head) { list=list->next; }
            ptr->next=head;
            list->next=ptr;
        }
    }

    void CinsertAtPos(int val,int pos)
    {
        if(head==NULL){cout<<"\n Sorry Linked list is empty so can't insert";}
        else
        {
            node *ptr=new node(val);
            node *temp=head;      
            while(temp->info!=pos)
            {
                temp=temp->next;
                if(temp->next==head){cout<<"\n Sorry can't insert at position";exit(0);}  //(When insertion at end position) or (end of LL is reached and value still not found)
            }
            ptr->next=temp->next;
            temp->next=ptr;
        }
    }

    void CdeleteAtBeg()
    {
        node* list=head;
        while(list->next!=head){list=list->next;}
        node *temp=head;
        cout<<"\n The deleted value is: "<<temp->info;
        list->next=head->next;
        delete(temp);
        head=list->next;
    }

    void CdeleteAtEnd()
    {
        node *list=head;
        while(list->next->next!=head){list=list->next;}
        node *temp=list->next;
        list->next=head;
        delete(temp);       
    }

    void CdeleteAtPos(int pos)
    {
        if(head->info==pos)
        {
            cout<<"\n Sorry can't delete at this position";
        }
        else
        {
            node *list=head;     
            while(list->next->info!=pos)
            {
                list=list->next;
                if(list->next->next==head){cout<<"\n Sorry can't delete at this position";exit(0);} 
            }
            node *temp=list->next;
            list->next=list->next->next;
            delete(temp);
        }
    }


int main()
{
	cout<<"******02216412819*******"<<endl;
	cout<<"*****Abhishek Jain*****"<<endl;
    int DSAchoice;
    cout<<"\n Menu ";
    cout<<"\n 1. Linear Linked List";
    cout<<"\n 2. Circular Linked List";
    cout<<"\n Enter the choice:";
    cin>>DSAchoice;
    if(DSAchoice==1) 
        {int ch, value;   
            do
            {
                cout<<"\n Linked List Menu ";
                cout<<"\n 1. Transverse/Print through Linked List";
                cout<<"\n 2. Insert into Linked List";
                cout<<"\n 3. Delete from Linked List";
                cout<<"\n 4. Exit";
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
                                default: cout<<"\n Wrong choice";exit(1);
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
                                default: cout<<"\n Wrong choice";exit(1);
                            }
                        }
                        disp();
                    }break;
                    case 4:exit(0);
                }
            } while (ch<=4);
        }
    else if(DSAchoice==2) 
        {int ch,value;   
            do
            {
                cout<<"\n Circular LL Menu:";
                cout<<"\n 1. Transverse/Print through Linked List";
                cout<<"\n 2. Insert into Circular Linked List";
                cout<<"\n 3. Delete from Circular Linked List";
                cout<<"\n 4. Exit";
                cout<<"\n Enter the choice:";
                cin>>ch;
                switch(ch)
                {
                    case 1:Cdisp();break;
                    case 2:
                    {
                        int inser,position=0;
                        cout<<"\n Enter the value to be inserted: ";
                        cin>>value;
                        if(head==NULL)
                        {
                            node *ptr=new node(value);
                            head=ptr;
                            ptr->next=head;
                        }
                        else
                        {
                            cout<<"\n Enter whether you want to insert at (1) Beginning (2) End (3) At position: ";
                            cin>>inser;
                            switch(inser)
                            {
                                case 1:CinsertAtBeg(value);break;
                                case 2:CinsertAtEnd(value);break;
                                case 3:{
                                    cout<<"\n Enter the value after which you want to insert the element:";
                                    cin>>position;
                                    CinsertAtPos(value,position);}break;
                                default: cout<<"\n Wrong choice";exit(1);
                            }
                        }
                        Cdisp();
                    }break; 
                    case 3:
                    {
                        int del,position=0;
                        if(head==NULL)
                        {
                            cout<<"\n Can't delete, the Linked list is already empty";
                        }
                        else if(head->next==head)
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
                                case 1:CdeleteAtBeg();break;
                                case 2:CdeleteAtEnd();break;
                                case 3:{
                                    cout<<"\n Enter the value that you want to delete:";
                                    cin>>position;
                                    CdeleteAtPos(position);}break;
                                default: cout<<"\n Wrong choice";exit(1);
                            }
                        }
                        Cdisp();
                    }break;
                    case 4:exit(0);
                }
            } while (ch<=4);
        }
    else
    {
        cout<<"\n Wrong choice";
    }
    return 0;
}