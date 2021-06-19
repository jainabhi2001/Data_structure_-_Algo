// Program 7. Implement evaluation of postfix notation using stacks.
// ABC*D/+
// 5,6,2,+,*,12,4,/,-
// 5 6 2 + * 12 4 / -

#include <iostream>
#include <process.h>
#include <math.h>           // For math related functions
#include <ctype.h>           // For character related operations -isdigit
#include <stack>             //Stack STL

using namespace std;

int calc(int fir,int sec,char op)           // To check precedence of operators
{
    int res=0;
    switch(op)
    {
        case '^':{res=pow(fir,sec);break;} 
        case '*':{res=fir*sec;break; }
        case '/':{res=fir/sec;break;}
        case '+':{res=fir+sec;break;}
        case '-':{res=fir-sec;break;}
        default: cout<<"\n Invalid operator used in expression"; exit(1);
    }
    cout<<"   "<<fir<<" "<<op<<" "<<sec<<"     =    "<<res<<endl;
    return res;
}

int infixToPostfix(string P)
{
    stack <int> ST;
    P+=')';
    cout<<"\n Postfix expression after paranthesis operation : "<<P<<endl;
    cout<<"\n Operation \t Result"<<endl;
    
    for (int i=0;i<P.length();i++)
    {
        int operation;


        if(P[i]==',' || P[i]==' '){}        //Do nothing when comma comes
        else if(P[i]>='0' && P[i]<='9')       // 1. Operand
        {
            if (P[i+1]>='0' && P[i+1]<='9') 
            {
                int number = (P[i] - '0') * 10 + (P[i+1] - '0');        // For 2 digit number
                i=i+1;                                              // For leaving the 2nd digit number in next loop turn
                ST.push(number); 
            }
            else
                ST.push(P[i]-'0');     //Subtracting ascii value of 0 from that of character to get actual number
        }
        else if(P[i]==')' )       // 2. Right bracket is present at end of expression
        {
            return (ST.top());
        }
        else if(P[i]=='^'|| P[i]=='*'||P[i]=='/' || P[i]=='+'||P[i]=='-')                       // 3. Operator encountered
        {
            int sec_op=ST.top(); ST.pop();
            int fir_op=ST.top(); ST.pop();           
            operation= calc(fir_op,sec_op,P[i]);
            ST.push(operation);
        }
    }
    cout<<"\n Sorry evaluation failed";         // This will never happen
    return -1;
}

int main()
{
    char Postfix[50];
    int Evaluation;
	cout<<"******02216412819******"<<endl;
	cout<<"*****Abhishek Jain*****"<<endl;
    cout<<"\n Enter the Postfix expression that is to be evaluated: ";
    gets(Postfix);

    Evaluation= infixToPostfix(Postfix);
    cout<<"\n ----------------------------------------------------------------------";
    cout<<"\n The Evaluated Expression/Result is : "<<Evaluation;
    return 0;
}
