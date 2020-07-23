#include<bits/stdc++.h>
using namespace std;
#define Om ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int main()
{
    Om;
    long long n, i, k, s=0;
    set<long long int>st;
    for(i=0; ;i++)
    {
        s = 1LL + (i*(i+1LL))/2LL;
        if(s>(1LL<<31LL))
            break;
        st.insert(s);
    }
    cin>>n;
    while(n--)
    {
        cin>>k;
        if(st.count(k))
            cout<<1<<endl;
        else
            cout<<0<<endl;
    }
    return 0;
}


