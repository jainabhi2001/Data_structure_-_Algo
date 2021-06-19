// Program :Write a program to merge 2 sorted linked list and display the final sorted linked list.

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


    void disp(node * head)
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


    void insertAtEnd(node * &head,int val)
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

    bool checkSorted(node * head)
    {
        if(head->next==NULL)
        {
            return true;
        }
        else
        {
            node *list=head;
            while(list->next!=NULL)
            {
                if(list->info > list->next->info)
                    return false;
                list=list->next;
            }
            return true;
        }
    }

    void Merge(node * head1,node * head2,node * &headRes)
    {
        node *temp1=head1;
        node *temp2=head2;
        node *temp3;
        while(temp1!=NULL || temp2!=NULL)
        {
            if(temp1==NULL && temp2!=NULL)
            {
                node *ptr=new node(temp2->info);
                temp3->next=ptr;
                temp3=temp3->next;
                temp2=temp2->next;

            }
            else if(temp1!=NULL && temp2==NULL)
            {
                node *ptr=new node(temp1->info);
                temp3->next=ptr;
                temp3=temp3->next;
                temp1=temp1->next;

            }
            else if((temp1->info)>(temp2->info))
            {
                node *ptr=new node(temp2->info);
                if(headRes==NULL)
                {
                    headRes=ptr;
                    temp3=headRes;
                }
                else 
                {
                    temp3->next=ptr;
                    temp3=temp3->next;
                }
                temp2=temp2->next;
            }
            else if((temp1->info)<(temp2->info))
            {
                node *ptr=new node(temp1->info);
                if(headRes==NULL)
                {
                    headRes=ptr;
                    temp3=headRes;
                }
                else 
                {
                    temp3->next=ptr;
                    temp3=temp3->next;
                }
                temp1=temp1->next;
            }
            else if((temp1->info)==(temp2->info))
            {
                node *ptr=new node(temp1->info);
                if(headRes==NULL)
                {
                    headRes=ptr;
                    temp3=headRes;
                }
                else 
                {
                    temp3->next=ptr;
                    temp3=temp3->next;
                }
                temp1=temp1->next;
                temp2=temp2->next;
            }
        }
    }

int main()
{
    node * head1=NULL;
    node * head2=NULL;
    node * res_head=NULL;
	cout<<"******02216412819*******"<<endl;
	cout<<"*****Abhishek Jain*****"<<endl;

    int num,value;
    cout<<"\n Enter the number of values that are to be inserted into Linked list 1: ";
    cin>>num;
    cout<<"\n Enter the "<<num<<" values one by one to be inserted: \n";
    for(int i=0;i<num;i++)
    {
        cin>>value;
        if(head1==NULL)
        {
            node *ptr=new node(value);
            head1=ptr;
        }
        else
            insertAtEnd(head1,value);
    }

    cout<<"\n Enter the number of values that are to be inserted into Linked list 2: ";
    cin>>num;
    cout<<"\n Enter the "<<num<<" values one by one to be inserted: \n";
    for(int i=0;i<num;i++)
    {
        cin>>value;
        if(head2==NULL)
        {
            node *ptr=new node(value);
            head2=ptr;
        }
        else
            insertAtEnd(head2,value);
    }

    cout<<"\n Linked list 1: ";
    disp(head1);
    cout<<"\n Linked list 2: ";
    disp(head2);

    if(checkSorted(head1)==1 && checkSorted(head2)==1)
    {
        cout<<"\n Both Linked Lists are sorted therefore can merge them";
        Merge(head1,head2,res_head);
        cout<<"\n Result Linked list :";
        disp(res_head);
    }
    else
    {
        cout<<"\n Sorry Linked Lists are not sorted therefore can't merge them";
        exit(0);
    }
    return 0;
}
