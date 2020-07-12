#include<bits/stdc++.h>
using namespace std;
#define Om ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int main()
{
    Om;
    int rnd;
    while(cin>>rnd && rnd!=-1)
    {
        string solution, guess;
        cin>>solution>>guess;
        int stroke=0;
        for(int i=0; guess[i] && stroke<7 && solution!=""; i++)
        {
            if(solution.find(guess[i]) != string::npos)
            {
                solution.erase( remove(solution.begin(),solution.end(),guess[i]), solution.end());
            }
            else
                stroke++;
        }
        cout<<"Round "<<rnd<<endl;
        if(stroke == 7)
            cout<<"You lose."<<endl;
        else if(solution == "")
            cout<<"You win."<<endl;
        else
            cout<<"You chickened out."<<endl;
    }

    return 0;
}


