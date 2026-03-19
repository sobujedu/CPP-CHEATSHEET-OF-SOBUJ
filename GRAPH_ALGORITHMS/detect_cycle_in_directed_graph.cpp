#include<bits/stdc++.h>
using namespace std;
bool vis[105];
vector<int>adj_list[105];
bool path[105];
bool cycle;
void dfs(int src)
{
    vis[src] = true;
    path[src] = true;
    for(int child : adj_list[src])
    {
        if(vis[child] && path[child])
              cycle = true;
        if(!vis[child])
        {
            
            dfs(child);
        }
    }
    path[src] = false;
}
int main()
{
    int n,e;
    cin >> n >> e;
    while(e--)
    {
        int a,b;
        cin >> a >> b;
        adj_list[a].push_back(b);
    }
    memset(vis,false,sizeof(vis));
    memset(path,false,sizeof(path));
    cycle = false;
    for(int i=0;i<n;i++)
    {
        if(!vis[i])
          dfs(i);
    }
    (cycle) ? cout << "CYCLE ACHE" : cout << "CYCLE NAI";
    return 0;
}
// #include<bits/stdc++.h>
// using namespace std;
// char grid[105][105];
// bool vis[105][105];
// int n,m;
// vector<pair<int,int>>mov = {{-1,0},{1,0},{0,-1},{0,1}};
// bool valid(int i, int j)
// {
//     if(i<0 || i >=n || j<0 || j>=m)
//       return false;
//     return true;
   
// }
// void dfs(int si,int sj)
// {
   
//     cout << si << " " << sj << endl;
//     vis[si][sj] = true;
//     for(int i=0;i<4;i++)
//     {
//         int ci,cj;
//         ci = si + mov[i].first;
//         cj = sj + mov[i].second;
//         if(valid(ci,cj)==true && !vis[ci][cj])
//            dfs(ci,cj);
//     }
// }
// int main()
// {
//     cin >> n >> m;
//     for(int i=0;i<n;i++)
//     {
//        for(int j=0;j<m;j++)
//        {
//            cin >> grid[i][j];
//        }
//     }
//     memset(vis,false,sizeof(vis));
//     return 0;
// }