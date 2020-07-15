#include<bits/stdc++.h>
using namespace std;
#define Om ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
string Code[300];
char tmp[15];
int limit=0;
void dfs(int i, int n)
{
    if(i == n)
    {
        tmp[n] = '\0';
        Code[limit++] = tmp;
        return;
    }
    tmp[i] = '0';
    dfs(i+1, n);
    tmp[i] = '1';
    dfs(i+1, n);
}
void Build_Code()
{
    for(int i=1; i<8; i++, limit--)
        dfs(0, i);
}
int main()
{
    Om;
    Build_Code();
    string message;
    while(getline(cin, message))
    {
        char a, b, c;
        while(true)
        {
            while(cin>>a)
            {
                if(a=='1' || a=='0')
                    break;
            }
            while(cin>>b)
            {
                if(b=='1' || b=='0')
                    break;
            }
            while(cin>>c)
            {
                if(c=='1' || c=='0')
                    break;
            }
            int num = (int)(a-'0')<<2 | (int)(b-'0')<<1 | (int)(c-'0');
            if(!num)
                break;
            while(true)
            {
                int cnt = num, ind=0, i;
                while(cnt--)
                {
                    while(cin>>a)
                    {
                        if(a=='1' || a=='0')
                            break;
                    }
                    tmp[ind++] = a;
                }
                tmp[ind] = '\0';
                for(i=0; i<limit; i++)
                {
                    if(Code[i] == tmp)
                    {
                        cout<<message[i];
                        break;
                    }
                }
                if(i==limit)
                    break;
            }
        }
        cout<<endl;
        cin.ignore();
    }
    return 0;
}


