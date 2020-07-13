#include<bits/stdc++.h>
using namespace std;
#define Om ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
int pzl;
int main()
{
    Om;
    int r, c;
    while(cin>>r && r)
    {
        cin>>c;
        string s[r];
        for(int i=0; i<r; i++)
        {
            cin>>s[i];
        }
        if(pzl)
            cout<<endl;
        cout<<"puzzle #"<<++pzl<<":"<<endl;
        int cnt=0, pos[r][c]={};
        for(int i=0; i<r; i++)
        {
            for(int j=0; j<c; j++)
            {
                if(s[i][j]!='*' && (i==0||j==0||s[i-1][j]=='*'||s[i][j-1]=='*'))
                    pos[i][j] = ++cnt;
            }
        }
        cout<<"Across"<<endl;
        for(int i=0; i<r; i++)
        {
            for(int j=0; j<c; )
            {
                if(s[i][j] != '*')
                {
                    cout<<setw(3)<<pos[i][j]<<".";
                    while(j<c && s[i][j]!='*')
                        cout<<s[i][j++];
                    cout<<endl;
                }
                else
                    j++;
            }
        }
        cout<<"Down"<<endl;
        for(int i=0; i<r; i++)
        {
            for(int j=0; j<c; j++)
            {
                int k = i;
                if(s[i][j]!='*' && (i==0 || s[i-1][j]=='*'))
                {
                    cout<<setw(3)<<pos[i][j]<<".";
                    while(k<r && s[k][j]!='*')
                        cout<<s[k++][j];
                    cout<<endl;

                }
            }
        }
    }
    return 0;
}


