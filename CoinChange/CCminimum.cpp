#include<bits/stdc++.h>
using namespace std;
int minCoin(int ara[],int n,int val)
{
    int tb[n+1][val+1];
    for(int i = 0; i < n+1;i++)
    {
        tb[i][0] = 0;
        for(int j = 1; j < val+1;j++)
        {
            tb[i][j] = INT_MAX;
        }
    }
    for(int i = 1; i < n+1; i++)
    {
        for(int j = 1; j < val+1; j++)
        {
            if(j - ara[i-1] >= 0)
            {
                if(tb[i][j-ara[i-1]] != INT_MAX)
                {
                    tb[i][j] = min(tb[i][j-ara[i-1]]+1,tb[i-1][j]);
                }
                else
                {
                    tb[i][j] = tb[i-1][j];
                }
            }
            else
            {
                tb[i][j] = tb[i-1][j];
            }
        }
    }
    for(int i = 0; i < n+1;i++)
    {
        for(int j = 0; j < val+1;j++)
        {
            cout << tb[i][j] << " ";
        }
        cout << endl;
    }
    return tb[n][val];
}
int main()
{
    int n;
    cin >> n;
    int ara[n];
    for(int i = 0; i < n;i++)
    {
        cin >> ara[i];
    }
    int val;
    cin >> val;
    cout << "MInimum Coin requries : " << minCoin(ara,n,val) << endl;
}
