#include<bits/stdc++.h>
using namespace std;
#define om ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
int sum[1<<20];
int main()
{
    om;
    int n, i, ans, s=0;
    cin>>n;
    vector<int>v(n);
    for(i=0; i<n; i++)
    {
        cin>>v[i];
        s += v[i];
    }
    ans = s;
    for(i=0; i<n; i++)
    {
        //cout<<i<<endl;
        for(int mask=(1<<i); mask<(1<<(i+1)); mask++)
        {
            //cout<<mask<<"  ->  "<< (mask^(1<<i)) <<endl;
            sum[mask] = sum[mask ^ (1<<i)] + v[i];
            ans = min(ans, abs(s-2*sum[mask]));
        }
        //cout<<endl;
    }
    cout<<ans<<endl;
    return 0;
}
