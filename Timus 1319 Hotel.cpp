#include<bits/stdc++.h>
using namespace std;
#define Om ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
int a[101][101];
int main()
{
    Om;
    int n, i, j, k, d=0;
    cin>>n;
    for(i=0; i<2*n-1; i++)
    {
        for(j=0; j<=i&&j<n; j++)
        {
            k = i-j;
            if(k>=0 && k<n)
                a[j][k] = ++d;
        }
    }
    for(i=0; i<n; i++)
    {
        for(j=n-1; j>=0; j--)
        {
             cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}


