#include<bits/stdc++.h>
using namespace std;

bool isBalancedString(string str)
{
    stack<char>st;
    int stringLen=str.length();
    for(int i=0;i<stringLen;i++)
    {
        if(str[i]=='{'||str[i]=='['||str[i]=='(')
            st.push(str[i]);
        else if(str[i]=='}')
        {
            if(st.empty()||st.top()!='{')
                return false;
            st.pop();
        }
        else if(str[i]==')')
        {
            if(st.empty()||st.top()!='(')
                return false;
            st.pop();
        }
        else if(str[i]==']')
        {
            if(st.empty()||st.top()!='[')
                return false;
            st.pop();
        }
    }
    if(st.size()>0)
        return false;
    return true;
}

int main()
{
    int noOfStrings;
    cin>>noOfStrings;
    string str[noOfStrings];
    for(int i=0;i<noOfStrings;i++)
    {
        cin>>str[i];
    }
    bool currValid;
    for(int i=0;i<noOfStrings;i++)
    {
        currValid=isBalancedString(str[i]);
        if(currValid)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
