#include<bits/stdc++.h>
using namespace std;
#define Om ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
string str = "`1234567890-=QWERTYUIOP[]\ASDFGHJKL;'ZXCVBNM,./";
map<char, char>mp;
int main()
{
    Om;
    for(int i=1; str[i]; i++)
    {
        mp[str[i]] = str[i-1];
    }
    mp[' '] = ' ';
    mp['\n'] = '\n';
    char s;
    while( (s = getchar()) != EOF)
    {
        putchar(mp[s]);
    }
    return 0;
}


