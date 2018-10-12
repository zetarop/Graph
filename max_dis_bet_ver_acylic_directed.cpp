/*
	When graph is directed acyclic
	Source and Destination vertex in input such there must exist a path from source vertex to destination vertex
*/
#include<bits/stdc++.h>
#define ve vector
#define pb push_back
#define min_inf -1000000007

int n;
int m;
int ans=0;

ve<ve<pair<int,int> > > adj;
ve<int> mark;
ve<int> d;

stack<int> S;

void dfs(int u)
{
	mark[u]=1;
	for(auto a:adj[u])
	{
		if(!mark[a.first])
			dfs(a.first);
	}
	S.push(u);
}

void update_distance()
{
	d[S.top()]=0;
	while(!S.empty())
	{
		int t=S.top();
		S.pop();
		for(auto a:adj[t])
			if(d[a.first] < d[t] + a.second)
				d[a.first] = d[t] + a.second;
	}
}

void topological_sort()
{
	for(int i=0;i<n;i++)
		if(!mark[i])
			dfs(i);
	update_distance();
}

int main()
{
	cin>>n>>m;
	adj.resize(n);
	mark.resize(n,0);
	d.resize(n,min_inf);
	for(int i=0;i<m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		u--,v--;
		adj[u].pb({v,w});
	}

	int u,v;
	cin>>u>>v;
	u--,v--;
	topological_sort();
	
	cout<<"Max_distance: "<<d[v]-d[u]<<endl;

	return 0;
}
