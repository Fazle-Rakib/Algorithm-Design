#include<bits/stdc++.h>
using namespace std;
int *coins = NULL, *counts = NULL,n,val;
void printCoin(int stin, int total)
{
    if(stin >= n)
    {
        int i = 0;
        cout << val << " : ";
        for(int i = 0; i < n;i++)
        {
            if(i == n-1)
            {
                cout << counts[i] << "*" << coins[i] << endl;
            }
            else
            {
                cout << counts[i] << "*" << coins[i] << " + ";
            }
        }
        return;
    }
    if(stin == n-1)
    {
        if(total%coins[stin] == 0)
        {
            counts[stin] = total/coins[stin];
            printCoin(stin+1,0);
        }
    }
    else
    {
        for(int i =0; i <= total/coins[stin];i++)
        {
            counts[stin] = i;
            printCoin(stin+1,total-coins[stin]*i);
        }
    }
}

int main()
{
    cin >> n;
    coins = new int[n];
    counts = new int[n];
    for(int i = 0; i < n;i++)
    {
        cin >> coins[i];
    }
    cin >> val;
    printCoin(0,val);
}
