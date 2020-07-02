#include<bits/stdc++.h>
using namespace std;
#define Om ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
bool match(int i, string a, string b)
{
    for(int j=0; i<a.size()&&j<b.size(); i++,j++)
    {
        if(a[i]=='2' && b[j]=='2')
            return false;
    }
    return true;
}
int main()
{
    Om;
    string master, driven;
    while(cin>>master>>driven)
    {
        int n = master.size(), m = driven.size();
        int i, j;
        for(i=0; i<n; i++)
        {
            if(match(i, master, driven))
                break;
        }
        for(j=0; j<m; j++)
        {
            if(match(j, driven, master))
                break;
        }
        cout<<min( max(n, m+i), max(m, n+j)) <<endl;
    }

    return 0;
}


