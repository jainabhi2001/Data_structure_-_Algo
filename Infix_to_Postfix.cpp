// Program 4. Implement the conversion of infix notation to postfix notation using stacks
// A+(B+C)*D)
// A+(B*C-(D/E^F)*G)*H

#include<iostream>
#include<process.h>
#include<stack>             //Stack STL

using namespace std;


int prece(char c)           // To check precedence of operatorsS
{
    if(c=='^') { return 3;}
    else if((c=='*') || (c=='/')) 
    {
        return 2;
    }
    else if((c=='+') || (c=='-')) 
    {
        return 1;
    }
    else {return 0;}        // for paranthesis
}

string infixToPostfix(string I)
{
    stack <char> ST;
    string result;

    ST.push('(');
    I+=')';
    cout<<"\n Infix expression after paranthesis operation : "<<I<<endl;
    cout<<"\n Top element of stack \t Output"<<endl;
    
    for (int i=0;i<I.length();i++)
    {
        cout<<"\t"<<ST.top()<<" \t \t"<<result<<endl;
        if((I[i]>='a' && I[i]<='z') || (I[i]>='A' && I[i]<='Z'))       // 1. Operand
        {
            result+=I[i];
        }
        else if(I[i]=='(' )       // 2. Left paranthesis encountered
        {
            ST.push(I[i]);
        }
        else if(I[i]==')' )         // 3. Right paranthesis encountered
        {
            while (!ST.empty() && ST.top()!='(')
            {
                result+=ST.top();
                ST.pop();
            }
            if (!ST.empty())    // This is when ST.top()='(
            {
                ST.pop();       // To pop out the "Left paranthesis"
            }

        }
        else                     // 4. Operators
        {
            // It is the case of more precedence operator in Stack
            while(!ST.empty() && prece(ST.top())>prece(I[i]) )
            {
                result+=ST.top();
                ST.pop();
            }
            // Now the case is of less precendence or no operator in Stack
            ST.push(I[i]);
        }
    }
    return result;
}

int main()
{
    string Infix;
    string Postfix;
	cout<<"******02216412819*******"<<endl;
	cout<<"*****Abhishek Jain*****"<<endl;
    cout<<"\n Enter the Infix expression that is to be converted to Postfix : ";
    cin>>Infix;

    Postfix= infixToPostfix(Infix);
    cout<<"\n ----------------------------------------------------------------------";
    cout<<"\n The postfix Expression is : "<<Postfix;
    return 0;
}