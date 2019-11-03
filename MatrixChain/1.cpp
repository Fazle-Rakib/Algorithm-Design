#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    while(cin >> n)
    {
        int dime[n];
        for(int i = 0; i < n;i++)
        {
            cin >> dime[i];
        }
        int M[n][n],S[n][n],q,j,Min;
        memset(M,0,sizeof(M));
        memset(S,0,sizeof(S));
        for(int d = 1; d < n-1;d++)
        {
            for(int i = 1; i < n-d; i++)
            {
                j = i+d;
                Min = INT_MAX;
                for(int k = i; k <= j-1;k++)
                {
                    q = M[i][k]+M[k+1][j]+dime[i-1]*dime[k]*dime[j];
                    if(q < Min)
                    {
                        Min = q;
                        S[i][j] = k;
                    }
                }
                M[i][j] = Min;
            }
        }
        cout << M[1][n-1] << endl;
    }
}
