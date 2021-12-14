/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <stack>
using namespace std;

string ONP(string w) {
    stack<char> stos;
    stos.push('#');
    string onp="";
    for(int i=0; i<w.size();i++) {
        //cout<<w[i]<<endl;
        switch(w[i]) {
            case '(': stos.push('('); break;
            case ')': while(stos.top()!='(') {
                            onp=onp+stos.top(); stos.pop();
                        }
                      stos.pop(); break;
            case '+': while(stos.top()!='#'&&stos.top()!='(') { 
                    onp=onp+stos.top(); stos.pop();
                        }
                        stos.push('+'); break;
            case '-': while(stos.top()!='#'&&stos.top()!='(') { 
                    onp=onp+stos.top(); stos.pop();
                        }
                        stos.push('-'); break;
            case '*': if(stos.top()=='*' || stos.top()=='/') {
                        onp=onp+stos.top(); stos.pop();
                        } stos.push('*'); break;
            case '/': if(stos.top()=='*' || stos.top()=='/') {
                        onp=onp+stos.top(); stos.pop();
                        } stos.push('/'); break;
            default: onp=onp+w[i];
        }
   // cout<<onp[i]<<endl;
    }
    while(stos.top()!='#') {
        onp = onp+stos.top(); stos.pop();
    }
    stos.pop();
    return onp;
}

int main() {
    string napis;
    cin>>napis;
    cout<<ONP(napis);
}
