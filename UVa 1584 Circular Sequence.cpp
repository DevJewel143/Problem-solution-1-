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
        string s, ans;
        cin>>s;
        int n = s.size();
        ans = s;
        s += s;
        for(int i=0; i<n; i++)
        {
            ans = min(ans, s.substr(i, n));
        }
        cout<<ans<<endl;
    }
    return 0;
}
