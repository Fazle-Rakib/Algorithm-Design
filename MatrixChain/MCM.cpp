#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n = 5;
    int p[] = {5,4,6,2,7};
    int j,Min,q;
    int M[n][n],S[n][n];
    memset(M,0,sizeof(M));
    memset(S,0,sizeof(S));
    for(int d = 1;d < n-1;d++)
    {
        for(int i = 1; i < n-d;i++)
        {
            j = i+d;
            Min = 32767;
            for(int k = i;k <= j-1;k++)
            {
                q = M[i][k]+M[k+1][j]+(p[i-1]*p[k]*p[j]);
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
