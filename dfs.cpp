// Dfs for a undirected connected graph

#include<bits/stdc++.h>
#define ve vector
#define pb push_back
using namespace std;

int ver, edg;
ve<int> mark;
ve<ve<int> > adj;


void dfs(int u)
{
	mark[u]=1;
	cout<<u+1<<" ";
	for(auto a:adj[u])
		if(!mark[a])
			dfs(a);
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
  
  // dfs with starting vertex 1
	dfs(0);

	return 0;
}
