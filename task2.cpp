#include<iostream>
using namespace std;

int calculate(int op1, int op2, char op)
{
    if(op == '+')
    {
        return op1 + op2;
    }
    else if(op == '-')
    {
        return op1 - op2;
    }
    else if(op == '*')
    {
        return op1 * op2;
    }
    else if(op == '/')
    {
        if(op2 != 0)
        {
            return op1 / op2;
        }
        else
        {
            cout << "Error! Division by zero is INFINITY." << endl;
            return -1;
        }
    }
    else
    {
        cout<<"Enter VALID operator."<<endl;
        return -1;
    }
}

int main()
{
    int n1,n2;
    char op;

    cout<<"Enter operand 1: ";
    cin>>n1;

    cout<<"Enter operand 2: ";
    cin>>n2;

    cout<<"Enter operator: ";
    cin>>op;

    double result = calculate(n1,n2,op);

    if(result != -1)
    {
        cout<<"\nResult = "<<result<<endl;
    }

    return 0;
}