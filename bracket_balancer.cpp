#include<iostream>
#include<bits/stdc++.h>
#include<stack>
using namespace std;

bool Bracket_chq(string str){
  
    stack <char> stak;
    bool ans = true;

    for(int i =0;i<str.length();i++){
        if(str[i] == '{' or str[i] == '(' or str[i]=='['){
            stak.push(str[i]);
        }
        else if(str[i]==')'){
            if(!stak.empty() and stak.top() =='('){
                stak.pop();
            }
            else{
                ans = false;
                break;
            }           
        }
        else if(str[i]=='}'){
            if(!stak.empty() and stak.top() =='{'){
                stak.pop();
            }
            else{
                ans = false;
                break;
            }           
        }
        else if(str[i]==']'){
            if(!stak.empty() and stak.top() =='['){
                stak.pop();
            }
            else{
                ans = false;
                break;
            }           
        }
    }
    if(!stak.empty()){
        return false;
    }
    return ans;    
}

int main(){
    string str;
    cout << "Enter Brackets : " << endl;
    cin >> str;
    if(Bracket_chq(str)){
        cout<<"Brackets are Balanced"<<endl;
    }
    else{
        cout<<"Brackets are not Balanced"<<endl;
    }
    return 0;
}