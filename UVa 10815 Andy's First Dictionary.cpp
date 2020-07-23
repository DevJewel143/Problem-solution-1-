#include<bits/stdc++.h>
using namespace std;
#define Om ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
set< string >Set;
bool isCapital(char c)
{
    return c>='A'&&c<='Z';
}
bool isSmall(char c)
{
    return c>='a'&&c<='z';
}
int main()
{
    Om;
    string str;
    while(getline(cin, str) != EOF)
    {
        for(int i=0; i<str.size(); i++)
        {
            if(isCapital(str[i]))
                str[i] = str[i]-'A'+'a';
            else if(!isSmall(str[i]))
                str[i] = ' ';
        }
        istringstream ss(str);
        string s;
        while(ss >> s)
        {
            Set.insert(s);
        }
    }
    for(auto c : Set)
        cout<<c<<endl;
    return 0;
}



