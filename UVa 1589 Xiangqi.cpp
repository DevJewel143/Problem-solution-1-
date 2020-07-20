#include<bits/stdc++.h>
using namespace std;
#define Om ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define M 15
int change[4][2] = { {1,0}, {0,1}, {-1,0}, {0,-1} };
int horse[4][4] = { {1,1,1,-1}, {1,1,-1,1}, {-1,1,-1,-1}, {1,-1,-1,-1} };
char board[M][M];
bool visit[M][M];
char type[M];
int x, y, xx[M], yy[M];
bool Inside(int a, int b)
{
    return (a>=1&&a<=10&&b>=1&&b<10);
}
void General_Chariot(int a, int b)
{
    for(int i=0; i<4; i++)
    {
        x = a+change[i][0];
        y = b+change[i][1];
        while(Inside(x,y) && board[x][y]=='_')
        {
            visit[x][y] = false;
            x += change[i][0];
            y += change[i][1];
        }
        if(Inside(x,y))
            visit[x][y] = false;
    }
}
void Cannon(int a, int b)
{
    for(int i=0; i<4; i++)
    {
        x = a+change[i][0];
        y = b+change[i][1];
        while(Inside(x,y) && board[x][y]=='_')
        {
            x += change[i][0];
            y += change[i][1];
        }
        if(Inside(x,y))
        {
            x += change[i][0];
            y += change[i][1];
            while(Inside(x,y) && board[x][y]=='_')
            {
                visit[x][y] = false;
                x += change[i][0];
                y += change[i][1];
            }
            if(Inside(x,y))
                visit[x][y] = false;
        }
    }
}
void Horse(int a, int b)
{
    for(int i=0; i<4; i++)
    {
        x = a+change[i][0];
        y = b+change[i][1];
        if(Inside(x,y) && board[x][y]=='_')
        {
            int p = x+horse[i][0];
            int q = y+horse[i][1];
            visit[p][q] = false;
            p = x+horse[i][2];
            q = y+horse[i][3];
            visit[p][q] = false;
        }
    }
}
bool CheckMate(int a, int b)
{
    for(int i=0; i<4; i++)
    {
        x = a+change[i][0];
        y = b+change[i][1];
        if(x>=1&&x<=3 && y>=4&&y<=6 && visit[x][y])
            return false;
    }
    return true;
}
void Print()
{
    cout<<endl<<endl;
    for(int i=1; i<11; i++)
    {
        for(int j=1; j<10; j++)
        {
            cout<<board[i][j]<<"("<<visit[i][j]<<")"<<"      ";
        }
        cout<<endl;
    }
    cout<<endl<<endl;
}
int main()
{
    Om;
    int n, X, Y;
    while(cin>>n>>X>>Y, n&&X&&Y)
    {
        memset(visit, true, sizeof(visit));
        memset(board, '_', sizeof(board));
        for(int i=0; i<n; i++)
        {
            cin>>type[i]>>xx[i]>>yy[i];
            board[xx[i]][yy[i]] = '$$';
        }
        //Print();
        for(int i=0; i<n; i++)
        {
            char c  = type[i];
            if(c == 'G' || c  == 'R')
                General_Chariot(xx[i], yy[i]);
            else if(c == 'C')
                Cannon(xx[i], yy[i]);
            else if(c == 'H')
                Horse(xx[i], yy[i]);
        }
        //Print();
        if(CheckMate(X,Y))
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}




