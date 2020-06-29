#include<bits/stdc++.h>
using namespace std;
#define Om ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
void solve(int n)
{
    if(n==1)
        return;
    n--;
    solve(n);
    cout<<n<<" ";
}
int main()
{
    Om;
    int n;
    cin>>n;
    solve(n+1);
    cout<<endl;
    return 0;
}


