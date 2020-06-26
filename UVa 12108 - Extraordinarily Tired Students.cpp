#include<bits/stdc++.h>
using namespace std;
#define Om ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
int Testcase, n, student[11][2], AwakeOrSleep[11];
int gcd(int a, int b){
    if(!(a%b))
        return b;
    return gcd(b, a%b);
}
int lcm(int a, int b){
    return a*b/gcd(a,b);
}
bool check()
{
    int i, awake=0;
    for(i=0; i<n; i++)
    {
        if(AwakeOrSleep[i] <= student[i][0])
            awake++;
    }
    if(awake == n)
        return true;
    for(i=0; i<n; i++)
    {
        if( (AwakeOrSleep[i]==student[i][0] && awake >= (n+1)/2 )  || (AwakeOrSleep[i] == student[i][0]+student[i][1]))
            AwakeOrSleep[i] = 1;
        else
            AwakeOrSleep[i]++;
    }
    return false;
}
int main()
{
    Om;
    while(cin>>n, n)
    {
        int i, l=1;
        for(i=0; i<n; i++)
        {
            cin>>student[i][0]>>student[i][1]>>AwakeOrSleep[i];
            l = lcm(l, student[i][0]+student[i][1]);
        }
        bool found;
        for(i=1; i<=l; i++)
        {
            found = check();
            if(found)
            {
                cout<<"Case "<<++Testcase<<": "<<i<<endl;
                break;
            }
        }
        if(!found)
        {
            cout<<"Case "<<++Testcase<<": -1"<<endl;
        }
    }

    return 0;
}

