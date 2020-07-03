#include<bits/stdc++.h>
using namespace std;
#define Om ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int main()
{
    //Om;
    char ch;
    long int total=0;
    while(scanf("%c", &ch) == 1)
    {
        if(ch == '"')
        {
            total++;
            if(total % 2 == 1)
            {
                printf("``");
            }
            else if(total % 2 == 0)
            {
                printf("''");
            }
        }
        else
        {
            printf("%c", ch);
        }
    }
    return 0;
}


