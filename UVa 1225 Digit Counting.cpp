#include<bits/stdc++.h>
using namespace std;
#define Om ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int main()
{
    Om;
    int q;
    cin>>q;
    while(q--)
    {
        int n;
        cin>>n;
        vector<int>ans(10, 0);
        for(int i=1; i<=n; i++)
        {
            int k = i;
            while(k)
            {
                ans[k%10]++;
                k /= 10;
            }
        }
        for(auto it : ans)
        {
            cout<<it<<" ";
        }
        cout<<endl;
    }

    return 0;
}


