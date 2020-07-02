#include<bits/stdc++.h>
using namespace std;
#define Om ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int main()
{
    Om;
    string a, b;
    while(cin>>a>>b)
    {
        vector<int>aa(26), bb(26), t(26);
        for(int i=0; a[i]; i++)
        {
            aa[a[i]-'A']++;
            bb[b[i]-'A']++;
        }
        for(int i=0; i<26; i++)
        {
            t[aa[i]]++;
            t[bb[i]]--;
        }
        sort(t.begin(), t.end());
        if(t[0] || t[25])
            cout<<"NO"<<endl;
        else
            cout<<"YES"<<endl;
    }
    return 0;
}


