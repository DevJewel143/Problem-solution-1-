#include<bits/stdc++.h>
using namespace std;
#define Om ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, 1, -1};
string change = "ABRL";
map<char, int>X, Y;
void Change()
{
    for(int i=0; i<4; i++)
    {
        X[change[i]] = dx[i];
        Y[change[i]] = dy[i];
        //cout<<change[i]<<" ... "<<dx[i]<<" "<<dy[i]<<endl;
    }
}
int main()
{
    Om;
    Change();
    vector<string>grid(5);
    string line = "";
    for(int test=1; ;test++)
    {
        int spaceX(-1), spaceY(-1);
        for(int i=0; i<5; i++)
        {
            getline(cin, grid[i]);
            if(grid[i] == "Z")
                return 0;
            for(int j=0; j<5; j++)
            {
                if(grid[i][j] == ' ' || grid[i][j] == '\n')
                {
                    spaceX = i;
                    spaceY = j;
                }
            }
        }
        //cout<<"Space -- " <<spaceX<<", "<<spaceY<<endl;
        cout<<line;
        line = '\n';

        bool valid(true);
        char move;
        cin>>move;
        while(move != '0')
        {
            int newX(spaceX+X[move]), newY(spaceY+Y[move]);
            if(newX<0 || newX>=5 || newY<0 || newY>=5)
            {
                valid = false;
                //cout<<"false --- "<<newX<<", "<<newY<<endl;
            }
            if(valid)
            {
                swap(grid[newX][newY], grid[spaceX][spaceY]);
                spaceX = newX;
                spaceY = newY;
            }
            cin>>move;
        }
        cout<< "Puzzle #" << test << ":\n";

        if(valid)
        {
            for(int i=0; i<5; i++)
            {
                string space = "";
                for(int j=0; j<5; j++)
                {
                    cout<<space<< grid[i][j];
                    space = " ";
                }
                cout<<endl;
            }
        }
        else
            cout<<"This puzzle has no final configuration."<<endl;
        cin.ignore();
    }

    return 0;
}


