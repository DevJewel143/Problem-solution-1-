#include<bits/stdc++.h>
using namespace std;
#define Om ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
int Case;
int main()
{
    Om;
    int n;
    while(cin>>n)
    {
        int H[10][10]={}, V[10][10]={}, ans[10]={};
        int m;
        cin>>m;
        while(m--)
        {
            char c;
            int x, y;
            cin>>c>>x>>y;
            if(c == 'H')
                H[x][y] = 1;
            else
                V[y][x] = 1;
        }
        if(Case)
            cout<<endl<<"**********************************"<<endl<<endl;
        cout<<"Problem #"<<++Case<<endl<<endl;
        for(int i=n; i>0; i--)
        {
            for(int j=n; j>0; j--)
            {
                if(H[i][j])
                    H[i][j] = H[i][j+1]+1;
                if(V[i][j])
                    V[i][j] = V[i+1][j]+1;
            }
        }
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                for(int Size=min(H[i][j], V[i][j]);  Size; Size--)
                {
                    if(H[i+Size][j] >= Size  &&  V[i][j+Size] >= Size)
                        ans[Size]++;
                }
            }
        }
        bool ok = true;
        for(int i=1; i<=n; i++)
        {
            if(ans[i])
            {
                ok = false;
                cout<<ans[i]<<" square (s) of size "<<i<<endl;
            }
        }
        if(ok)
            cout<<"No completed squares can be found."<<endl;
    }
    return 0;
}


