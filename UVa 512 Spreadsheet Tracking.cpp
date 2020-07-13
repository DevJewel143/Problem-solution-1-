#include<bits/stdc++.h>
using namespace std;
#define Om ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define cal 10000
#define size 101
int Case;
int row, column;
int sheet[size][size];
int copySheet[size][size];
int ans[size][size];
bool mark[size];
void SetFun()
{
    memset(sheet, 0, sizeof(sheet));
    memset(ans, 0, sizeof(sheet));
    for(int i=1; i<=row; i++)
    {
        for(int j=1; j<=column; j++)
        {
            sheet[i][j] = i*cal + j;
        }
    }
}
void Copy(char type, int to, int from)
{
    if(type == 'R')
    {
        for(int i=1; i<=column; i++)
        {
            sheet[to][i] = copySheet[from][i];
        }
    }
    else
    {
        for(int i=1; i<=row; i++)
        {
            sheet[i][to] = copySheet[i][from];
        }
    }
}
void Delete(char type)
{
    memcpy(copySheet, sheet, sizeof(sheet));
    int NewRorC=0;
    int maxRorC = (type == 'R') ? row : column;
    for(int i=1; i<=maxRorC; i++)
    {
        if(!mark[i])
            Copy(type, ++NewRorC, i);
    }
    if(type == 'R')
        row = NewRorC;
    else
        column = NewRorC;
}
void Insert(char type)
{
    memcpy(copySheet, sheet, sizeof(sheet));
    int NewRorC=0;
    int maxRorC = (type == 'R') ? row : column;
    for(int i=1; i<=maxRorC; i++)
    {
        if(mark[i])
            Copy(type, ++NewRorC, 0);
        Copy(type, ++NewRorC, i);
    }
    if(type == 'R')
        row = NewRorC;
    else
        column = NewRorC;
}
void Print()
{
    for(int i=1; i<=row; i++)
    {
        for(int j=1; j<=column; j++)
        {
            cout<<setw(6)<<sheet[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl<<endl;
}
void MakeAns()
{
    for(int i=1; i<=row; i++)
    {
        for(int j=1; j<=column; j++)
        {
            ans[ sheet[i][j]/cal ][ sheet[i][j]%cal] = i*cal + j;
        }
    }
    /*
    for(int i=1; i<=row; i++)
    {
        for(int j=1; j<=column; j++)
        {
            cout<<setw(6)<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl<<endl;
    */
}
int main()
{
    Om;
    while(cin>>row>>column, row&&column)
    {
        SetFun();
        //Print();
        int Operation;
        cin>>Operation;
        while(Operation--)
        {
            string command;
            cin>>command;
            if(command == "EX")
            {
                int x, y, a, b;
                cin>>x>>y>>a>>b;
                swap(sheet[x][y], sheet[a][b]);
            }
            else
            {
                memset(mark, false, sizeof(mark));
                int num;
                cin>>num;
                while(num--)
                {
                    int RorC;
                    cin>>RorC;
                    mark[RorC] = true;
                }
                if(command[0] == 'D')
                    Delete(command[1]);
                else
                    Insert(command[1]);
            }
            //Print();
        }
        MakeAns();
        if(Case)
            cout<<endl;
        cout<<"Spreadsheet #"<<++Case<<endl;
        int query;
        cin>>query;
        while(query--)
        {
            int x, y;
            cin>>x>>y;
            cout<<"Cell data in ("<<x<<","<<y<<") ";
            if(ans[x][y])
            {
                cout<<"moved to ("<<ans[x][y]/cal<<","<<ans[x][y]%cal<<")"<<endl;
            }
            else
                cout<<"GONE"<<endl;
        }
    }
    return 0;
}


