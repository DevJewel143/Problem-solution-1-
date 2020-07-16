#include<bits/stdc++.h>
using namespace std;
#define Om ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
string disk[10];
int parity, diskset, d, s, b;
bool valid()
{
    for(int i=0; i<s*b; i++)
    {
        int x=0, idx=0;
        bool Xor = 0;
        for(int j=0; j<d; j++)
        {
            if(disk[j][i] == '1')
                Xor ^= 1;
            else if(disk[j][i] == 'x')
            {
                if(x)
                    return false;
                x++;
                idx = j;
            }
        }
        if(!x && (parity^Xor))
            return false;
        if(x)
            disk[idx][i] = (Xor^parity) + '0';
    }
    return true;
}
void DataPrint()
{
    int Xor=0, cnt=0;
    for(int i=0; i<b; i++)
    {
        for(int j=0; j<d; j++)
        {
            if(j == i%d)
                continue;
            for(int k=0; k<s; k++)
            {
                if( disk[j][s*i+k] == '1')
                    Xor += 1;
                if( ++cnt == 4)
                {
                    if(Xor>9)
                        cout<<(char)((Xor-9)+'A'-1);
                    else
                        cout<<Xor;
                    Xor = 0;
                    cnt =0;
                }
                else
                    Xor <<= 1;
            }
        }
    }
    if(cnt)
    {
        Xor <<= (3-cnt);
        if(Xor > 9)
            cout<<(char)((Xor-9)+'A'-1);
        else
            cout<<Xor<<endl;
    }
    cout<<endl;
}
int main()
{
    Om;
    while(cin>>d && d)
    {
        string c;
        cin>>s>>b>>c;
        parity = (c[0] == 'O');
        for(int i=0; i<d; i++)
            cin>>disk[i];
        if(valid())
        {
            cout<<"Disk set "<<++diskset<<" is valid, contents are: ";
            DataPrint();
        }
        else
            cout<<"Disk set "<<++diskset<<" is invalid."<<endl;
    }
    return 0;
}


