// Program 12 Implement addition of two polynomial expressions using singly linked list.

// Note: We will deal with only 1 variable polynomial

#include<iostream>
#include<process.h>

using namespace std;

struct node
{
    int coeff;
    int pow;
    node *next;
    node(int coefficient,int power)
    {
        coeff=coefficient;
        pow=power;
        next=NULL;
    }
};

void dispPoly(node * head)
{
    node *temp=head;
    int power;// To check the last power is 0 then don't add extra 0
    while(temp!=NULL)
    {
        cout<<temp->coeff<<"x^"<<temp->pow<<"+";
        power=temp->pow;
        temp=temp->next;
    }
    cout<<"0";

}
/*
void checkOrder(node *head1, node *head2)
{
    node *temp1=head1;
    node *temp2=head2;
    while(temp1->next!=NULL)
    {
        if((temp1->pow)<(temp1->next->pow))
        {cout<<"\n Sorry the polynomial 1 powers were not in decreasing order";exit(0);}
        temp1=temp1->next;
    }
    while(temp2->next!=NULL)
    {
        if((temp2->pow)<(temp2->next->pow))
        {cout<<"\n Sorry the polynomial 2 powers were not in decreasing order";exit(0);}
        temp2=temp2->next;
    }
    cout<<"\n Both polynomial's power were in order, so can calculate SUM"<<endl;
}*/

void calcSum(node * headP,node * headQ,node * &headSUM)
{
    node *temp1=headP;
    node *temp2=headQ;
    node *temp3;
    while(temp1!=NULL || temp2!=NULL)
    {
        if(temp1==NULL && temp2!=NULL)
        {
            node *ptr=new node(temp2->coeff,temp2->pow);
            temp3->next=ptr;
            temp3=temp3->next;
            temp2=temp2->next;

        }
        else if(temp1!=NULL && temp2==NULL)
        {
            node *ptr=new node(temp1->coeff,temp1->pow);
            temp3->next=ptr;
            temp3=temp3->next;
            temp1=temp1->next;

        }
        else if((temp1->pow)>(temp2->pow))
        {
            node *ptr=new node(temp1->coeff,temp1->pow);
            if(headSUM==NULL)
            {
                headSUM=ptr;
                temp3=headSUM;
            }
            else 
            {
                temp3->next=ptr;
                temp3=temp3->next;
            }
            temp1=temp1->next;
        }
        else if((temp1->pow)<(temp2->pow))
        {
            node *ptr=new node(temp2->coeff,temp2->pow);
            if(headSUM==NULL)
            {
                headSUM=ptr;
                temp3=headSUM;
            }
            else 
            {
                temp3->next=ptr;
                temp3=temp3->next;
            }
            temp2=temp2->next;
        }
        else if((temp1->pow)==(temp2->pow))
        {
            int coeffSum=temp1->coeff + temp2->coeff;
            node *ptr=new node(coeffSum,temp1->pow);
            if(headSUM==NULL)
            {
                headSUM=ptr;
                temp3=headSUM;
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
    node *headP=NULL;
    node *headQ=NULL;
    node *headSUM=NULL;
    int coeff;int pow;
    // POLYNOMIAL P
    char moreP='Y';
    cout<<"\n Enter details in following manner for 1st polynomial (The exponent should be in decreasing order only) :";
    cout<<"\n Coefficient \t Power"<<endl;
    while((moreP=='Y') || (moreP=='y'))
    {
        cin>>coeff>>pow;
        node *ptr=new node(coeff,pow);
        if(headP==NULL){headP=ptr;}
        else
        {
            node *list1=headP;
            while(list1->next!=NULL){list1=list1->next;}
            list1->next=ptr;
            list1=ptr;
        }
        moreP='N';
        cout<<" Do you want to add more coefficient-exponent terms (Y/N) : ";
        cin>>moreP;
    }

        // POLYNOMIAL Q
    char moreQ='Y';
    cout<<"\n Enter details in following manner for 2nd polynomial (The exponent should be in decreasing order only) :";
    cout<<"\n Coefficient \t Power"<<endl;
    while((moreQ=='Y') || (moreQ=='y'))
    {
        cin>>coeff>>pow;
        node *ptr=new node(coeff,pow);
        if(headQ==NULL){headQ=ptr;}
        else
        {
            node *list1=headQ;
            while(list1->next!=NULL){list1=list1->next;}
            list1->next=ptr;
            list1=ptr;
        }
        moreQ='N';
        cout<<" Do you want to add more coefficient-exponent terms (Y/N) : ";
        cin>>moreQ;
    }
    // DISPLAY BOTH POLYNOMIALS
    cout<<"\n Polynomial 1 : ";
    dispPoly(headP);

    cout<<"\n Polynomial 2 : ";
    dispPoly(headQ);

    // checkOrder(headP,headQ);

    calcSum(headP,headQ,headSUM);
    cout<<"\n Sum result : ";
    dispPoly(headSUM);
    return 0;
}