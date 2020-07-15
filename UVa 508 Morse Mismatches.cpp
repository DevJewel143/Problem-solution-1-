#include<bits/stdc++.h>
using namespace std;
#define Om ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
map<char, string>morse;
map<string, string>Map;
int Distance(string s1, string s2)
{
    if(s1 == s2)
        return 0;
    if(s1.size() > s2.size())
        swap(s1, s2);
    if( s1 == s2.substr(0, s1.size()))
        return (s2.size() - s1.size());
    return INT_MAX;
}
string encode(string s)
{
    string result = "";
    for(auto c : s)
        result += morse[c];
    return result;
}
string decode(string s)
{
    string result;
    int MinDistance = INT_MAX;
    for(auto it : Map)
    {
        int CurDistance = Distance(it.second, s);
        if(!MinDistance  && !CurDistance)
        {
            return (result+"!");
        }
        if(CurDistance <= MinDistance)
        {
            result = it.first;
            MinDistance = CurDistance;
        }
    }
    if(MinDistance)
        result += "?";
    return result;
}
int main()
{
    Om;
    string s1, s2;
    while(cin>>s1 && s1 != "*")
    {
        cin>>s2;
        morse[s1[0]] = s2;
    }
    while(cin>>s1 && s1 != "*")
    {
        Map[s1] = encode(s1);
    }
    while(cin>>s1 && s1 != "*")
    {
        cout<< decode(s1) <<endl;
    }
    return 0;
}


