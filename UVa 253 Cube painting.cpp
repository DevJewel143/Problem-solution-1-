#include<bits/stdc++.h>
using namespace std;
#define Om ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int main()
{
    Om;
    string s;
    while(cin>>s)
    {
        bool ok = true;
        for(int i=0; i<3; i++)
        {
            int a=i, b=5-i;
            bool check = false;
            for(int j=6; j<9; j++)
            {
                int x=j, y=17-j;
                if( (s[a]==s[x] && s[b]==s[y]) || (s[a]==s[y] && s[b]==s[x]))
                {
                    check = true;
                    s[x]='$', s[y]='$';
                    break;
                }
            }
            if(!check)
            {
                ok = false;
                break;
            }
        }
        if(ok)
            cout<<"TRUE"<<endl;
        else
            cout<<"FALSE"<<endl;
    }
    return 0;
}


