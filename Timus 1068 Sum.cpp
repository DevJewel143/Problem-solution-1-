#include<bits/stdc++.h>
using namespace std;
#define Om ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int main()
{
    Om;
    int n, sum=0;
    cin>>n;
    if(n==0)
        cout<<1<<endl;
    else if(n>0)
        cout<< (n*(n+1))/2 <<endl;
    else
    {
        n *= (-1);
        cout << (-1)*(n*(n+1)/2)+1 <<endl;
    }
    return 0;
}



