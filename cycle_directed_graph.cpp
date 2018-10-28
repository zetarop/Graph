#include<bits/stdc++.h>
#define ve vector
#define pb push_back
#define ll long long
using namespace std;

int n;
int m;
ve<ve<int>> adj;
ve<int> mark;

bool dfs(int u)
{
	if(mark[u])
		return 1;
	mark[u]=1;

	for(auto a:adj[u])
	{
		if(dfs(a) == 1)
			return 1;
	}
	mark[u]=0;
	return 0;
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

	cout<<dfs(0)<<endl;


	return 0;
}
