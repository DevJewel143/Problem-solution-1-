#include<bits/stdc++.h>
using namespace std;
#define Om ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
int a[100000];
void pre_calculate()
{
    a[1]=1;
    for(int i=2; i<100000; i++)
    {
        if(!(i&1))
            a[i] = a[i>>1];
        else
            a[i] = a[i>>1]+a[(i>>1)+1];
    }
}
int main()
{
    Om;
    pre_calculate();
    int n;
    while(cin>>n, n)
    {
        int i, ans=0;
        for(i=0; i<=n; i++)
            ans = max(ans, a[i]);
        cout<<ans<<endl;
    }
    return 0;
}


