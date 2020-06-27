#include<bits/stdc++.h>
using namespace std;
#define Om ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int main()
{
    Om;
    int n, i, j, sum, ans;
    cin>>n;
    vector<int>v(n);
    for(i=0,sum=0; i<n; i++)
    {
        cin>>v[i];
        sum += v[i];
    }
    ans = sum;
    bool dp[sum+1];
    memset(dp, 0, sum);
    dp[0] = 1;
    /*cout<<"   ";
    for(j=sum; j>0; j--)
    {
        cout<<j<<" ";
    }
    cout<<endl;*/
    for(j=0; j<n; j++)
    {
        //cout<<v[j]<<" --->  ";
        for(i=sum; i>0; i--)
        {
            if(i>=v[j] && dp[i-v[j]]){
                //cout<<i<<"    ";
                dp[i] = 1;
                ans = min(ans, abs(sum-i*2));
            }
            //cout<<dp[i]<<" ";
        }
        //cout<<endl;
    }
    cout<<ans<<endl;
    return 0;
}


