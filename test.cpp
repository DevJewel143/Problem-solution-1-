#include<bits/stdc++.h>
using namespace std;
#define Om ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int main()
{
    Om;
    int t;
    cin>>t;
    while(t--)
    {
        if(t)
            cout<<endl;
        string s;
        cin>>s;
        int k, i, j, m, n=s.size();
        bool ok;
        for(k=1; k<n; k++)
        {
            ok = true;
            if(n%k)
                ok = false;
            for(i=1, m=k; i<n/k && n%k==0; i++)
            {
                for(j=0; j<k; j++,m++)
                {
                    if(s[m] != s[j])
                    {
                        ok = false;
                            break;
                    }
                }
                if(!ok)
                    break;
            }
            if(ok)
                break;
        }
        cout<<k<<endl;
        if(t)
            cout<<endl;
    }

    return 0;
}


