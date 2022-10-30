#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<stack>
#include<unordered_map>
using namespace std;

const int N=1e5+10;
stack<int> stkn;
stack<char> stkop;
unordered_map<char,int> priority{{'+',1},{'-',1},{'*',2},{'/',2}};
string s;
int res;//保存答案;
void eval()
{
    int x=0;
    int b=stkn.top();//第二个操作数
    stkn.pop();
    
    int a=stkn.top();//第一个操作数
    stkn.pop();
    
    char op=stkop.top();//运算符;
    stkop.pop();
    
    if(op=='+')  x=a+b;
    else if(op=='-') x=a-b;
    else if(op=='*') x=a*b;
    else x=a/b;
    stkn.push(x);//将计算的结果入栈;
}

int main()
{
    cin>>s;
    int n=s.size();
    for(int i=0;i<n;i++){
        auto c=s[i];
        if(isdigit(c))
        {
            int x=0,j=i;
            while(j<n&&isdigit(s[j]))
            {
                x=x*10+(s[j++]-'0');
            }
            i=j-1;
            stkn.push(x);
        }
        else if(c=='(') stkop.push(c);//左括号无优先级直接入栈； 
        else if(c==')') {
            while(stkop.top()!='(') eval();//如果遇到右括号，一直计算直到左括号；
            stkop.pop();
        }
        else{
            while(stkop.size()&&stkop.top()!='('&&priority[stkop.top()]>=priority[c]) eval();
            stkop.push(c);
        }
    }
    while(stkop.size()) eval();
    res=stkn.top();
    printf("%d\n",res);
    return 0;
}
    