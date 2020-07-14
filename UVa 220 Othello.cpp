#include<bits/stdc++.h>
using namespace std;
#define Om ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
char board[10][10];
char CurrentPlayer;
int dx[] = { 1, 1, 0, -1, -1, -1,  0,  1};
int dy[] = { 0, 1, 1,  1,  0, -1, -1, -1};
bool Inside(int r, int c)
{
    return (r>0&&r<9 && c>0&&c<9);
}
void Change_CP()
{
    CurrentPlayer = (CurrentPlayer == 'W') ? 'B' : 'W';

}
bool CheckBracket(int r, int c, int dx, int dy)
{
    bool isFound = false;
    while(true)
    {
        r += dx;
        c += dy;
        char pos = board[r][c];
        if(!Inside(r,c) || pos == '-' || (!isFound && pos==CurrentPlayer))
            return 0;
        else if(pos != CurrentPlayer)
            isFound = true;
        else if(isFound && pos==CurrentPlayer)
            return 1;
    }
}
void EditBoard(int r, int c, int dx, int dy)
{
    while(true)
    {
        r += dx;
        c += dy;
        if(board[r][c] == CurrentPlayer)
            return;
        board[r][c] = CurrentPlayer;
    }
}
bool valid(int r, int c)
{
    if(board[r][c] == '-')
    {
        for(int i=0; i<8; i++)
        {
            if(CheckBracket(r, c, dx[i], dy[i]))
                return true;
        }
    }
    return false;
}
void ListallMoves()
{
    bool isFound = false;
    for(int i=1; i<=8; i++)
    {
        for(int j=1; j<=8; j++)
        {
            if(valid(i, j))
            {
                if(isFound)
                    cout<<" ";
                cout<<"("<<i<<","<<j<<")";
                isFound = true;
            }
        }
    }
    if(!isFound)
        cout<<"No legal move.";
    cout<<endl;
}
void MakeMoves()
{
    char x, y;
    cin>>x>>y;
    int r = x-'0', c = y-'0';
    if(!valid(r, c))
        Change_CP();
    board[r][c] = CurrentPlayer;
    for(int i=0; i<8; i++)
    {
        if(CheckBracket(r, c, dx[i], dy[i]))
        {
            EditBoard(r, c, dx[i], dy[i]);
        }
    }
    int w=0, b=0;
    for(int i=1; i<=8; i++)
    {
        for(int j=1; j<=8; j++)
        {
            if(board[i][j] == 'W')
                w++;
            else if(board[i][j] == 'B')
                b++;
        }
    }
    cout<<"Black - "<<setw(2)<<b<<" White - "<<setw(2)<<w<<endl;
    Change_CP();
}
void ShowBoard()
{
    for(int i=1; i<=8; i++)
    {
        for(int j=1; j<=8; j++)
            cout<<board[i][j];
        cout<<endl;
    }
}
int main()
{
    Om;
    int TestCase;
    cin>>TestCase;
    while(TestCase--)
    {
        for(int i=1; i<=8; i++)
            cin>>board[i]+1;
        cin>>CurrentPlayer;
        while(true)
        {
            char command;
            cin>>command;
            if(command == 'Q')
            {
                ShowBoard();
                break;
            }
            else if(command == 'L')
                ListallMoves();
            else
                MakeMoves();
        }
        if(TestCase)
            cout<<endl;
    }
    return 0;
}


