#include<bits/stdc++.h>
using namespace std;
#define Om ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int main()
{
    Om;
    string s, t;
    while(cin>>s>>t)
    {
        int ls = s.size(), lt = t.size(), i, j;
        for(i=0,j=0; j<ls&&i<lt; i++)
        {
            if(s[j] == t[i])
                j++;
        }
        if(ls==j)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }

    return 0;
}


