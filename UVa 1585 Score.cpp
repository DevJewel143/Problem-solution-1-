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
        string s;
        int ans=0, cnt=0, i;
        cin>>s;
        for(auto c : s)
        {
            if(c=='O')
                cnt++;
            else
                cnt=0;
            ans += cnt;
        }
        cout<<ans<<endl;
    }
    return 0;
}


