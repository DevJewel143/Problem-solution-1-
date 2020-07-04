#include<bits/stdc++.h>
using namespace std;
#define Om ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
string a = "AEHIJLMOSTUVWXYZ12358", b = "A3HILJMO2TUVWXY51SEZ8";
map<char, char>M;
bool isPalin(string s)
{
    int n = s.size(), i;
    for(i=0; i<n/2; i++)
    {
        if(s[i] != s[n-1-i])
            return false;
    }
    return true;
}
bool isMirror(string s)
{
    int n = s.size(), i;
    for(i=0; i<(n+1)/2; i++)
    {
        //cout<<s[i]<<" ... "<<M[s[i]]<<" ... "<<s[n-1-i]<<endl;
        if( M[s[i]] != s[n-1-i] )
            return false;
    }
    return true;
}
int main()
{
    Om;
    //cout<<a.size()<<"  "<<b.size()<<endl;
    for(int i=0; a[i]; i++)
    {
        M[a[i]] = b[i];
        //cout<<a[i]<<"  "<<b[i]<<endl;
    }
    string s;
    while(cin>>s)
    {
        bool palin = isPalin(s), mirror = isMirror(s);
        if(!palin && !mirror)
        {
            cout<<s<<" -- is not a palindrome."<<endl;
        }
        else if(!palin && mirror)
        {
            cout<<s<<" -- is a mirrored string."<<endl;
        }

        else if(palin && !mirror)
        {
            cout<<s<<" -- is a regular palindrome."<<endl;
        }
        else
        {
            cout<<s<<" -- is a mirrored palindrome."<<endl;
        }
        cout<<endl;
    }
    return 0;
}


