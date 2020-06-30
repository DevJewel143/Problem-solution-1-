#include<bits/stdc++.h>
using namespace std;
#define Om ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int main()
{
    Om;
    int n, i, ans=0;
    cin>>n;
    vector<int>v(n);
    for(auto &c : v)
    {
        cin>>c;
    }
    sort(v.begin(), v.end());
    for(i=0; i<(n+1)/2; i++)
    {
        ans += (v[i]+1)/2;
    }
    cout<<ans<<endl;
    return 0;
}


