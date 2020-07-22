#include<bits/stdc++.h>
using namespace std;
#define Om ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
vector< vector<int> >block;
void start(int n)
{
    for(int i=0; i<n; i++)
    {
        block[i].push_back(i);
    }
}
int Find(int val, int &pos)
{
    for(int i=0; i<block.size(); i++)
    {
        for(int j=0; j<block[i].size(); j++)
        {
            if(block[i][j] == val)
            {
                pos = j;
                return i;
            }
        }
    }
}
void Return_To_Initial(int blockNo, int pos)
{
    while(block[blockNo].size()>pos)
    {
        int val  = block[blockNo].back();
        block[val].push_back(val);
        block[blockNo].pop_back();
    }
}
void Print()
{
    for(int i=0; i<block.size(); i++)
    {
        cout<<i<<":";
        for(int j=0; j<block[i].size(); j++)
        {
            cout<<" "<<block[i][j];
        }
        cout<<endl;
    }
}
int main()
{
    Om;
    int n;
    cin>>n;
    block.resize(n);
    start(n);
    while(true)
    {
        string mainCommand, SecondCommand;
        int a, b, posA, posB, blockNoOfA, blockNoOfB;
        cin>>mainCommand;
        if(mainCommand == "quit")
            break;
        cin>>a>>SecondCommand>>b;

        blockNoOfA = Find(a, posA);
        blockNoOfB = Find(b, posB);

        if(blockNoOfA == blockNoOfB)
            continue;

        if(mainCommand == "move")
        {

            Return_To_Initial(blockNoOfA, posA+1);
            if(SecondCommand == "onto")
            {
                Return_To_Initial(blockNoOfB, posB+1);
            }
            block[blockNoOfB].push_back(a);
            block[blockNoOfA].pop_back();
        }
        else
        {
            if(SecondCommand == "onto")
            {
                Return_To_Initial(blockNoOfB, posB+1);
            }
            for(int i=posA; i<block[blockNoOfA].size(); i++)
            {
                block[blockNoOfB].push_back(block[blockNoOfA][i]);
            }
            while(block[blockNoOfA].size() > posA)
                block[blockNoOfA].pop_back();
        }
        //Print();
    }
    Print();
    return 0;
}
