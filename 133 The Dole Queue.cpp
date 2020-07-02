#include<bits/stdc++.h>
using namespace std;
#define Om ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int main()
{
    Om;
    int n, k, m;
    while(cin>>n>>k>>m, n&&k&&m)
    {
        vector<int>mark(n);
        int ki=0, mi=n-1, cnt=n, cntk=0, cntm=0;
        while(cnt)
        {
            while(true)
            {
                if(mark[ki] != -1)
                    cntk++;
                if(cntk==k)
                    break;
                ki = (ki+1)%n;
            }
            while(true)
            {
                if(mark[mi] != -1)
                    cntm++;
                if(cntm==m)
                    break;
                mi = (mi-1+n)%n;
            }
            if(ki == mi)
            {
                cnt--;
                mark[ki] = -1;
                cout<<setw(3)<<ki+1;
                if(cnt>0)
                    cout<<",";
            }
            else
            {
                cnt -= 2;
                mark[ki]=mark[mi]=-1;
                cout<<setw(3)<<ki+1<<setw(3)<<mi+1;
                if(cnt>0)
                    cout<<",";
            }
            cntk=cntm=0;
        }
        cout<<endl;
    }
    return 0;
}


