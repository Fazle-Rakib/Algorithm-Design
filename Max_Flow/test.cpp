#include<bits/stdc++.h>
using namespace std;
#define V 6
bool bfs(int rgraph[V][V],int s, int t, int parent[])
{
    bool visited[V];
    memset(visited,0,sizeof(visited));
    queue<int>q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int v = 0;v < V;v++)
        {
            if(visited[v] == false && rgraph[u][v] > 0)
            {
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }

    }
    return(visited[t] == true);
}
int ford_Flukerson(int graph[V][V],int s,int t)
{
    int rgraph[V][V];
    for(int i  = 0; i < V;i++)
    {
        for(int j= 0; j < V;j++)
        {
            rgraph[i][j] = graph[i][j];
        }
    }
    int Max_Flow = 0;
    int parent[V];
    while(bfs(rgraph,s,t,parent))
    {
        int u = s;
        int path_flow = INT_MAX;
        for(int v = t; v != s; v = parent[v])
        {
            u = parent[v];
            path_flow = min(path_flow,rgraph[u][v]);
        }
        for(int v = t; v != s; v = parent[v])
        {
            u = parent[v];
            rgraph[u][v] -= path_flow;
            rgraph[v][u] += path_flow;
        }
        Max_Flow += path_flow;
    }
    return Max_Flow;
}
int main()
{
    int edges;
    cin >> edges;
    int graph[V][V];
    memset(graph,0,sizeof(graph));
    int a,b,w;
    while(edges--)
    {
        cout << edges << " : ";
        cin >> a >> b >> w;
        graph[a][b] = w;
    }
    cout << "The Max Flow is : " << ford_Flukerson(graph,0,V-1);
}
/*
9
0 1 10
0 2 10
1 2 10
1 3 10
1 4 10
2 4 10
4 3 10
3 5 10
4 5 10
*/
