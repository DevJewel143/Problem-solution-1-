#include<bits/stdc++.h>
using namespace std;
#define Om ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
int Case;
int main()
{
    Om;
    int n, q;
    while(cin>>n>>q, n&&q)
    {
        int a[n+5];
        for(int i=1;  i<=n; i++)
            cin>>a[i];
        sort(a+1, a+n+1);
        cout<<"CASE# "<<++Case<<":"<<endl;
        while(q--)
        {
            int t, p;
            cin>>t;
            p = lower_bound(a+1, a+1+n, t) - a;
            if(t == a[p])
                cout<<t<<" found at "<<p<<endl;
            else
                cout<<t<<" not found"<<endl;
        }
    }
    return 0;
}



