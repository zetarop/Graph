#include<bits/stdc++.h>
#define ve vector
#define pb push_back
#define inf 1000000007

int n;
int m;
ve<ve<int> > adj;
ve<int> mark;
stack<int> S;


void dfs(int u)
{
	mark[u]=1;
	for(auto a:adj[u])
		if(!mark[a])
			dfs(a);

	S.push(u);
}

void topological_sort()
{
	for(int i=0;i<n;i++)
		if(!mark[i])
			dfs(i);
	while(!S.empty())
	{
		int t=S.top();
		cout<<t<<" ";
		S.pop();
	}
}

int main()
{
	cin>>n>>m;
	adj.resize(n);
	mark.resize(n,0);
	for(int i=0;i<m;i++)
	{
		int u,v;
		cin>>u>>v;
		u--,v--;
		adj[u].pb(v);
	}
	topological_sort();
	return 0;
}