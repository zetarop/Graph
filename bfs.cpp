#include<bits/stdc++.h>
#define ve vector
#define pb push_back
using namespace std;

int ver, edg;
ve<int> mark;
ve<ve<int> > adj;


void bfs(int u)
{
	queue<int> Q;
	Q.push(u);
	mark[u]=1;
	while(!Q.empty())
	{
		int t=Q.front();
		Q.pop();
		cout<<t+1<<" ";
		for(auto a:adj[t])
			if(!mark[a])
			{
				Q.push(a);
				mark[a]=1;
			}
	}
}


int main()
{
	cin>>ver>>edg;
	adj.resize(ver);
	mark.resize(ver,0);
	for(int i=0;i<edg;i++)
	{
		int u,v;
		cin>>u>>v;
		u--,v--;
		adj[u].pb(v);
		adj[v].pb(u);
	}

	bfs(0);

	return 0;
}
