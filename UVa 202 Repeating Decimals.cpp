#include<bits/stdc++.h>
using namespace std;
#define Om ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int main()
{
    Om;
    int a, b;
    while(cin>>a>>b)
    {
        vector<int>mark(b+5, -1);
        vector<char>s;
        int i, Start, End;
        cout<<a<<"/"<<b<<" = "<<a/b<<".";
        a %= b;
        mark[a] = 0;
        for(i=1; ;i++)
        {
            a *= 10;
            s.push_back(a/b + '0');
            a %= b;
            if(mark[a] != -1)
                break;
            mark[a] = i;
        }
        Start = mark[a];
        End = i;

        for(i=0; i<End&&i<51; i++)
        {
            if(i==Start)
                cout<<"(";
            cout<<s[i];
        }
        if(i<End)
            cout<<"...";
        cout<<")"<<endl;
        cout<<"   "<<End-Start<<" = number of digits in repeating cycle"<<endl<<endl;
    }
    return 0;
}


