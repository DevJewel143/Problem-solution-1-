#include<bits/stdc++.h>
using namespace std;
#define Om ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
int game;
int main()
{
    Om;
    int n;
    while(cin>>n && n)
    {
        vector<int>s(n);
        for(auto &it : s)
            cin>>it;
        cout<<"Game "<<++game<<":"<<endl;
        while(true)
        {
            vector<int>g(n);
            for(auto &it : g)
                cin>>it;
            if(count(g.begin(), g.end(), 0) == n)
                break;
            int sm=0, wm=0;
            vector< bool >mark(n, true);
            for(int i=0; i<n; i++)
            {
                if(s[i] == g[i])
                {
                    sm++;
                    mark[i] = false;
                    g[i] = -1;
                }
            }
            for(int i=0; i<n; i++)
            {
                if(mark[i])
                {
                    for(int j=0; j<n; j++)
                    {
                        if(s[i] == g[j])
                        {
                            wm++;
                            mark[i] = false;
                            g[j] = -1;\
                            break;
                        }
                    }
                }
            }
            cout<<"    ("<<sm<<","<<wm<<")"<<endl;
        }
    }

    return 0;
}


