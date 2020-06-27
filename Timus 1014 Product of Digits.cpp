#include<bits/stdc++.h>
using namespace std;
#define Om ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int main()
{
    Om;
    int n, i;
    vector<int>v;
    cin>>n;
    if(n<=1)
        return cout<<n<<endl, 0;
    for(i=9; i>1 && n>1; i--)
    {
        while(!(n%i))
        {
            n /= i;
            v.push_back(i);
        }
    }
    if(n>1)
        cout<<-1<<endl;
    else
    {
        sort(v.begin(), v.end());
        for(auto it : v)
            cout<<it;
        cout<<endl;
    }
    return 0;
}


