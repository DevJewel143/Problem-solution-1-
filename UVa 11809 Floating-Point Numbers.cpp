#include<bits/stdc++.h>
using namespace std;
#define Om ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define EPS 1e-6
long long E[11][31];
double M[11][31];
void fun()
{
    double mantisa, exp, num;
    for(int m=0; m<10; m++)
    {
        for(int e=1; e<31; e++)
        {
            mantisa = 1.0 - pow(2.0, -1-m);
            exp = pow(2.0, e)-1;
            num = log10(mantisa) + exp*log10(2);
            E[m][e] = num;
            M[m][e] = pow(10.0, num-E[m][e]);
            cout<<m<<" "<<e<<" "<<M[m][e]<<" "<<E[m][e]<<endl;
        }
    }
}
int main()
{
    Om;
    fun();
    string s;
    while(cin>>s && s!="0e0")
    {
        s[17]  = ' ';
        istringstream ss(s);
        long long exp;
        double mantisa;
        ss>>mantisa>>exp;
        for(int m=0; m<10; m++)
        {
            for(int e=1; e<31; e++)
            {
                if(exp==E[m][e] && fabs(mantisa-M[m][e])<EPS)
                {
                    cout<<m<<" "<<e<<endl;
                    break;
                }
            }
        }
    }

    return 0;
}
