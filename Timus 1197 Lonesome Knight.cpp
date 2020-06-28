#include<bits/stdc++.h>
using namespace std;
#define Om ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
//knight move
int dx[] = {2, 2, -2, -2, 1, 1, -1, -1};
int dy[] = {1, -1, 1, -1, 2, -2, 2, -2};
bool check(int x, int y)
{
    return (x>=1&&x<=8) && (y>=1&&y<=8);
}
void solve()
{
    string s;
    cin>>s;
    int x, y, i, moveCount=0;
    x = s[0]-'a'+1;
    y = s[1]-'1'+1;
    for(i=0; i<8; i++)
    {
        moveCount += check(x+dx[i], y+dy[i]);
    }
    cout<<moveCount<<endl;
}
int main()
{
    Om;
    int q;
    cin>>q;
    while(q--)
    {
        solve();
    }
    return 0;
}


