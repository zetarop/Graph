/*
  This backtracking algo works for directed and undirected graph.
*/

#include<bits/stdc++.h>
#define ve vector
#define pb push_back
#define inf 1000000007

int n;
int m;
int ans=0;
ve<ve<pair<int,int> > > adj;
ve<int> mark;


void dfs(int u, int v, int sum)
{
	mark[u]=1;
	//cout<<u+1<<" "<<sum<<endl;
	for(auto a:adj[u])
	{
		if(a.first == v)
		{
			ans = max(ans, sum + a.second);
		}
		else if(!mark[a.first])
			dfs(a.first, v, sum+a.second);
	}
	mark[u]=0;
}


int main()
{
	cin>>n>>m;
	adj.resize(n);
	mark.resize(n,0);
	for(int i=0;i<m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		u--,v--;
		adj[u].pb({v,w});
		adj[v].pb({u,w});
	}

	int u,v;   // u:source vertex , v: destination vertex
	cin>>u>>v;
	u--,v--;
	dfs(u,v,0);
	cout<<ans<<endl;
	return 0;
}
