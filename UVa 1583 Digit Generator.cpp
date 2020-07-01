#include<bits/stdc++.h>
using namespace std;
#define Om ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
vector<int>ans(100050, INT_MAX);
int sum(int n)
{
    int s=0;
    while(n)
    {
        s += (n%10);
        n /= 10;
    }
    return s;
}
void solve()
{
    for(int i=1; i<=100000; i++)
    {
        int k = i + sum(i);
        ans[k] = min(ans[k], i);
    }
}
int main()
{
    Om;
    solve();
    int t;
    cin>>t;
    while(t--)
    {
        int a;
        cin>>a;
        if(ans[a]==INT_MAX)
            ans[a] = 0;
        cout<<ans[a]<<endl;
    }
    return 0;
}


