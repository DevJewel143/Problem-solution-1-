#include<bits/stdc++.h>
using namespace std;
#define Om ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int main()
{
    Om;
    int q;
    cin>>q;
    while(q--)
    {
        int n, m, i, j, err=0;
        cin>>n>>m;
        string s[n], ans="";
        for(i=0; i<n; i++)
            cin>>s[i];
        for(j=0; j<m; j++)
        {
            char c;
            vector<int>mx(26, 0);
            int M=0;
            for(i=0; i<n; i++)
            {
                int h = s[i][j]-'A';
                mx[h]++;
                if( M == mx[h] )
                {
                    c = min(c, s[i][j]);
                }
                if( M < mx[h] )
                {
                    M = mx[h];
                    c = s[i][j];
                }
            }
            ans += c;
            err += (n-mx[c-'A']);
        }
        cout<<ans<<endl<<err<<endl;
    }
    return 0;
}


