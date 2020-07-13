#include<bits/stdc++.h>
using namespace std;
#define Om ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define EPS 1e-6
int rgn;
int main()
{
    Om;
    int n, m;
    while(cin>>n>>m, n&&m)
    {
        vector<int>v;
        int i, j, a;
        for(i=0; i<n; i++)
        {
            for(j=0; j<m; j++)
            {
                cin>>a;
                v.push_back(a);
            }
        }
        n *= m;
        double volume;
        cin>>volume;
        cout<<"Region "<<++rgn<<endl;
        sort(v.begin(), v.end());
        v.push_back(1e+10);
        double sum = 0, h = 0;
        for(i=0; i<n; i++)
        {
            sum += v[i];
            h = (volume+sum*100.0)/(i+1)/100.0;
            if(h < v[i+1]+EPS)
            {
                cout<<"Water level is "<<setprecision(2)<<fixed<<h<<" meters."<<endl;
                cout<<setprecision(2)<<fixed<<(i+1)*100.0/n<<" percent of the region is under water."<<endl<<endl;
                break;
            }

        }
    }

    return 0;
}


