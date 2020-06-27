#include<bits/stdc++.h>
using namespace std;
#define Om ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define pi acos(-1.0)
double distance(double x1, double y1, double x2, double y2)
{
    return sqrt( (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) );
}
int main()
{
    Om;
    int n, i;
    double ans, r;
    cin>>n>>r;
    double x[n],  y[n];
    for(i=0; i<n; i++)
    {
        cin>>x[i]>>y[i];
    }
    ans = distance(x[0],y[0], x[n-1],y[n-1]);
    for(i=0; i<n-1; i++)
    {
        ans += distance(x[i],y[i],  x[i+1],y[i+1]);
    }
    ans += 2*pi*r;
    cout<<setprecision(2)<<fixed<<ans<<endl;
    return 0;
}


