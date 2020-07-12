#include<bits/stdc++.h>
using namespace std;
#define Om ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int main()
{
    Om;
    int x, y;
    while(cin>>x>>y)
    {
        if(x>y)
            swap(x,y);
        vector< pair<int,int>  >v;
        v.push_back( make_pair(x,y));
        for(int i=1; i<6; i++)
        {
            cin>>x>>y;
            if(x>y)
                swap(x,y);
            v.push_back(make_pair(x,y));
        }
        sort(v.begin(), v.end());
        for(int i=0; i<6; i++)
        {
            cout<<v[i].first<<"  "<<v[i].second<<endl;
        }
        bool ok = true;
        if(v[0]!=v[1] || v[2]!=v[3] || v[4]!=v[5])
            ok = false;
        if(v[0].first!=v[2].first  || v[0].second!=v[4].first || v[2].second!=v[4].second)
            ok = false;
        if(ok)
            cout<<"POSSIBLE"<<endl;
        else
            cout<<"IMPOSSIBLE"<<endl;
    }

    return 0;
}


