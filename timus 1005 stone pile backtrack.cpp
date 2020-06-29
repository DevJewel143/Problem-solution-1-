#include<bits/stdc++.h>
using namespace std;
#define Om ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
int n, sum, ans;
vector<int>v;
void backtrack(int t, int s)
{
    if(t==n)
    {
        //cout<<s<<"   "<<sum-s<<endl;
        ans = min(ans, abs(sum-s*2));
        return;
    }
    backtrack(t+1, s);
    backtrack(t+1, s+v[t]);
}
int main()
{
    Om;
    cin>>n;
    v.resize(n);
    for(int i=0; i<n; i++)
    {
        cin>>v[i];
        sum += v[i];
    }
    ans = sum;
    backtrack(0,0);
    cout<<ans<<endl;
    return 0;
}


