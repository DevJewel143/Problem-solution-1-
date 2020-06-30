#include<bits/stdc++.h>
using namespace std;
#define Om ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int main()
{
    Om;
    string s, a = "APOR", b = "BMS", C = "DGJKTW";
    map<char,int>mp;
    for(auto c : a)
        mp[c]=1;
    for(auto c : b)
        mp[c]=2;
    for(auto c : C)
        mp[c]=3;
    int n, i, pre=1, ans=0;
    cin>>n;
    while(n--)
    {
        cin>>s;
        ans += abs(pre - mp[s[0]]);
        pre = mp[s[0]];
    }
    cout<<ans<<endl;
    return 0;
}


