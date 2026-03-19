#include<bits/stdc++.h>
using namespace std;
vector<int>adj_list[1005];
bool visit[1005];
void bfs(int src)
{
    queue<int>q;
    q.push(src);
    visit[src] = true;
    while(!q.empty())
    {
        //queue theke ber kore ana
        int parnt = q.front();
        q.pop();
        //oi node ke niye kaj kora
        cout << parnt << " ";
        //childern gula push kora
        for(int child : adj_list[parnt])
        {
            if(!visit[child])
            {
            q.push(child);
            visit[child] = true;
            }

        }
    }
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
        adj_list[b].push_back(a);
    }
    memset(visit,false,sizeof(visit));
    bfs(0);
    return 0;
}
// 7 7
// 0 1
// 1 3
// 1 4
// 3 2
// 4 6
// 3 5
// 4 5 