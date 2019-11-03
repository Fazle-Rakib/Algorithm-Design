#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,x;
    cin >> x;
    n = x+1;
    int sz = 2*x;
    int dimension[sz];
    for(int i = 0; i < sz;i++)
    {
        cin >> dimension[i];
    }
    int dim[n];
    dim[0] = dimension[0];
    for(int i=1,j = 1; i < sz;i+=2,j++)
    {
        dim[j] = dimension[i];
    }
    int M[n][n],S[n][n],j,Min,q;
    memset(M,0,sizeof(M));
    memset(S,0,sizeof(S));
    for(int d = 1; d < n-1;d++)
    {
        for(int i = 1; i < n-d;i++)
        {
            j = i+d;
            Min = INT_MAX;
            for(int k = i;k <= j-1;k++)
            {
                q = M[i][k]+M[k+1][j]+(dim[i-1] * dim[k] * dim[j]);
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
