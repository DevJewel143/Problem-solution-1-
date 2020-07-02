#include<bits/stdc++.h>
using namespace std;
#define Om ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int main()
{
    Om;
    map<char, double>Mol;
    Mol['C'] = 12.01;
    Mol['H'] = 1.008;
    Mol['O'] = 16.00;
    Mol['N'] = 14.01;
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        int i, num;
        double k, ans=0;
        cin>>s;
        for(i=0; s[i]; )
        {
            k = Mol[s[i]];
            i++, num=0;
            while(s[i] && s[i]>='0' && s[i]<='9')
            {
                num = num*10 + (s[i]-'0');
                i++;
            }
            if(num==0)
                num=1;
            ans += (k*num*1.0);
        }
        cout<<ans<<endl;
    }

    return 0;
}


