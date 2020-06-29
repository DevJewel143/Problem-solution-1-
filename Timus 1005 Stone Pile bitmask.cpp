#include<bits/stdc++.h>
using namespace std;
#define Om ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int main()
{
    Om;
    int n, i, k, s, ans, sum=0;
    cin>>n;
    vector<int>v(n);
    for(i=0;  i<n; i++)
    {
        cin>>v[i];
        sum += v[i];
    }
    ans = sum;
    for(k=0; k<(1<<n); k++)
    {
        s=0;
        for(i=0; i<n; i++)
        {
            if((1<<i)&k)
                s += v[i];
        }
        ans = min(ans, abs(sum-s*2));
    }
    cout<<ans<<endl;
    return 0;
}


