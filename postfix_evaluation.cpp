#include <iostream>
#include<math.h>
#include<stack>
using namespace std;

int postfix_eval(string exp)
{
    stack<int> stak;

    for(int i =0;i<exp.length();i++)
    {
        if(exp[i]>='0' && exp[i]<='9')
        {
            stak.push(exp[i]-'0');
        }
        else
        {
            int op2 = stak.top();
            stak.pop();
            int op1 = stak.top();
            stak.pop();
            switch (exp[i])
            {
            case '+':
                stak.push(op1+op2);
                break;
            case '-':
                stak.push(op1-op2);
                break;
            case '*':
                stak.push(op1*op2);
                break;
            case '/':
                stak.push(op1/op2);
                break;
            case '^':
                stak.push(pow(op1,op2));
                break;        
            }
        }
    }
     return stak.top();
}

int main()
{
    string exp;
    cout << "Enter the postfix expression to evaluate : " << endl;
    cin >> exp;
    cout << postfix_eval(exp);

}