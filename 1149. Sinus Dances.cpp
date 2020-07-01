#include<bits/stdc++.h>
using namespace std;
#define Om ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
void SinA(int n)
{
    for(int i=1; i<=n; i++)
    {
        cout<<"sin("<<i;
        if(i<n)
        {
            if(i&1)
                cout<<"-";
            else
                cout<<"+";
        }
        else
        {
            for(int j=0; j<n; j++)
                cout<<")";
        }
    }
}
int main()
{
    Om;
    int n;
    cin>>n;
    for(int i=1; i<n; i++)
    {
        cout<<"(";
    }
    for(int i=1; i<=n; i++)
    {
        SinA(i);
        if(i<n)
        {
            cout<<"+"<<n-i+1<<")";
        }
        else
            cout<<"+"<<1<<endl;
    }
    return 0;
}



