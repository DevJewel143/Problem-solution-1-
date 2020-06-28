#include<bits/stdc++.h>
using namespace std;
#define Om ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
int Sum(int x)
{
    if(x<10)
        return x;
    return Sum(x/10)+(x%10);
}
int power(int x, int n)
{
    int p = 1;
    while(n--)
        p *= x;
    return p;
}
int main()
{
    Om;
    int n, i, ans=0;
    cin>>n;
    n = power(10, n/2);
    //cout<<n<<endl;
    vector<int>sum(n+5);
    vector<int>k(40, 0);
    for(i=0; i<n; i++)
    {
        sum[i] = Sum(i);
        //cout<<i<<" --> "<<sum[i]<<endl;
        k[sum[i]]++;
    }
    for(i=0; i<n; i++)
    {
        //cout<<i<<" -> "<<sum[i]<<" -> "<<k[sum[i]]<<endl;
        ans += (k[sum[i]] * k[sum[i]]) ;
        k[sum[i]] = 0;
    }
    cout<<ans<<endl;
    return 0;
}


