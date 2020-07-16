#include<bits/stdc++.h>
using namespace std;
#define Om ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
int i, j, a[32], b[32];
void Binary(int n, int a[])
{
    int i=7;
    while(n)
    {
        a[i--] = n%2;
        n>>=1;
    }
    for( ; i>=0; i--)
        a[i]=0;
}
int Decimal(int a[])
{
    int b=1, n=0;
    for(int i=7; i>=0; i--)
    {
        if(a[i])
            n += b;
        b <<= 1;
    }
    return n;
}
int main()
{
    Om;
    int n;
    while(cin>>n)
    {
        int ip[4][n];
        char c;
        for(i=0; i<n; i++)
        {
            for(j=0; j<4; j++)
            {
                cin>>ip[j][i];
                if(j<3)
                    cin>>c;
            }
        }
        for(i=0; i<4; i++)
            sort(ip[i], ip[i]+n);

        for(i=0; i<4; i++)
        {
            Binary(ip[i][0], a+i*8);
            Binary(ip[i][n-1], b+i*8);
        }
        for(i=0; i<32; i++)
        {
            if(a[i] != b[i])
                break;
        }
        for(j=0; j<32; j++)
        {
            if(j<i)
                b[j]=1;
            else
                a[j]=b[j]=0;
        }
        for(i=0; i<4; i++)
        {
            cout<<Decimal(a+i*8);
            if(i<3)
                cout<<".";
            else
                cout<<endl;
        }
        for(i=0; i<4; i++)
        {
            cout<<Decimal(b+i*8);
            if(i<3)
                cout<<".";
            else
                cout<<endl;
        }
    }
    return 0;
}


