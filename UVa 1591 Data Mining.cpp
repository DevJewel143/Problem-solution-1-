#include<bits/stdc++.h>
using namespace std;
#define Om ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int main()
{
    Om;
    long long n, sp, sq;
    while(cin>>n>>sp>>sq)
    {
        long long i, j, A, B, pros = (n-1)*sp, mink=n*sq, k = (long long int)1<<62;
        for(i=0; i<32; i++)
        {
            for(j=0; j<32; j++)
            {
                long long t = ( (pros+ (pros<<i)) >> j) + sq;
                if( t < k  && t>= mink)
                {
                    k = t;
                    A = i;
                    B = j;
                }
            }
        }
        cout<<k<<" "<<A<<" "<<B<<endl;
    }

    return 0;
}


