/* Program: Implement menu driven program for insertion (at the beginning, at specified location, at the end) 
    & deletion (at the beginning, at specified location, at the end) on doubly Double Linked List and circular doubly Double Linked List.*/

#include<iostream>
#include<process.h>

using namespace std;

struct node
{
    int info;
    node *prev;
    node *next;
    node(int val)
    {
        info=val;
        prev=NULL;
        next=NULL;
    }
};

node * head=NULL;       // GLOBAL "head" pointer 
    void disp()
    {
        if (head==NULL)
        {
            cout<<"\n Sorry the Double Linked List is empty";
        }
        else
        {
            cout<<"\n The Double Linked List: ";
            cout<<"NULL<-";
            if(head->next==NULL)
            {
                cout<<head->info<<"->";
            }
            else
            {
                node *temp=head;
                while(temp!=NULL)
                {
                    cout<<temp->info<<"<->";
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
        head->prev=ptr;
        head=ptr;
    }

    void insertAtEnd(int val)
    {
        node *ptr=new node(val);
        if (head->next==NULL)
        {
            head->next=ptr;
            ptr->prev=head;
        }
        else
        {
            node *list=head;
            while(list->next!=NULL) { list=list->next; }
            list->next=ptr;
            ptr->prev=list;
        }
    }

    void insertAtPos(int val,int pos)
    {
        if(head==NULL){cout<<"\n Sorry Double Linked List is empty so can't insert";}
        else
        {
            node *ptr=new node(val);
            node *temp=head;      
            while(temp->info!=pos)
            {
                temp=temp->next;
                if(temp->next==NULL){cout<<"\n Sorry can't insert at position";exit(0);}  //(When insertion at end position) or (end of LL is reached and value still not found)
            }
            ptr->next=temp->next;   //make
            ptr->prev=temp;     //make
            temp->next=ptr;     //break
            temp->next->prev=ptr;       //break
        }
    }

    void deleteAtBeg()
    {
        node *temp=head;
        cout<<"\n The deleted value is: "<<temp->info;
        head=head->next;
        head->prev=NULL;
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
            temp->next->prev=list;
            cout<<temp->info;
            delete(temp);
        }
    }

    void Cdisp()
    {
        if (head==NULL)
        {
            cout<<"\n Sorry the Circular Double Linked List is empty";
        }
        else
        {
            cout<<"\n The Circular Double Linked List: ";
            if(head->next==head)
            {
                cout<<head->info<<"<->";
            }
            else
            {
                node *temp=head->next;
                cout<<head->info<<"<->";
                while(temp!=head)
                {
                    cout<<temp->info<<"<->";
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
            ptr->prev=head;
            head->prev=ptr;
            head->next=ptr;
            head=ptr;
        }
        else
        {
            ptr->next=head;
            ptr->prev=head->prev;
            head->prev->next=ptr;
            head->prev=ptr;
            head=ptr;
        }
    }

    void CinsertAtEnd(int val)
    {
        node *ptr=new node(val);
        if (head->next==head)
        {
            ptr->next=head;
            ptr->prev=head;
            head->prev=ptr;
            head->next=ptr;
        }
        else
        {
            ptr->next=head;
            ptr->prev=head->prev;
            head->prev->next=ptr;
            head->prev=ptr;
        }
    }

    void CinsertAtPos(int val,int pos)
    {
        if(head==NULL){cout<<"\n Sorry Double Linked List is empty so can't insert";}
        else
        {
            node *ptr=new node(val);
            node *temp=head;      
            while(temp->info!=pos)
            {
                temp=temp->next;
                if(temp->next==head){cout<<"\n Sorry can't insert at position";exit(0);}  //(When insertion at end position) or (end of LL is reached and value still not found)
            }
            ptr->next=temp->next;   //make
            ptr->prev=temp;     //make
            temp->next=ptr;     //break
            temp->next->prev=ptr;       //break
        }
    }

    void CdeleteAtBeg()
    {
        cout<<"\n The deleted value is: "<<head->info;
        head->prev->next=head->next;
        head->next->prev=head->prev;
        node* temp=head;
        head=head->next;
        delete(temp);
    }

    void CdeleteAtEnd()
    {
        node *temp=head->prev;
        head->prev->prev->next=head;
        head->prev=head->prev->prev;
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
            temp->next->prev=list;
            delete(temp);
        }
    }


int main()
{
	cout<<"******02216412819*******"<<endl;
	cout<<"*****Abhishek Jain*****"<<endl;
    int DSAchoice;
    cout<<"\n Menu ";
    cout<<"\n 1. Linear Double Linked List";
    cout<<"\n 2. Circular Double Linked List";
    cout<<"\n Enter the choice:";
    cin>>DSAchoice;
    if(DSAchoice==1) 
        {int ch, value;   
            do
            {
                cout<<"\n Double Linked List Menu ";
                cout<<"\n 1. Transverse/Print through Double Linked List";
                cout<<"\n 2. Insert into Double Linked List";
                cout<<"\n 3. Delete from Double Linked List";
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
                            cout<<"\n Can't delete, the Double Linked List is already empty";
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
                cout<<"\n Circular Double LL Menu:";
                cout<<"\n 1. Transverse/Print through Double Linked List";
                cout<<"\n 2. Insert into Circular Double Linked List";
                cout<<"\n 3. Delete from Circular Double Linked List";
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
                            head->next=head;
                            head->prev=head;
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
                            cout<<"\n Can't delete, the Double Linked List is already empty";
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
