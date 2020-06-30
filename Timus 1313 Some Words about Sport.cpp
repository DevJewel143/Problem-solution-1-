#include<bits/stdc++.h>
using namespace std;
#define Om ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int main()
{
    Om;
    int n, i, j, k;
    cin>>n;
    int a[n+1][n+1];
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
            cin>>a[i][j];
    }
    vector<int>v;
    for(i=0; i<2*n-1; i++)
    {
        for(j=min(i, n-1); j>=0; j--)
        {
            k = i-j;
            if(k>=0 && k<n)
                v.push_back(a[j][k]);
        }
    }
    for(auto it : v)
        cout<<it<<" ";
    cout<<endl;
    return 0;
}


