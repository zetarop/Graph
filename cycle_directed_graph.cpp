/*
  Given a directed graph.
  Check is there is cycle present of not.
  
 Note: we can not use dsu algorithm for dircted graph to detect cycle.
 Algo here is just a backtracking algo to detect cycle .
 For larger graph time will matter here.
*/

#include<bits/stdc++.h>
#define ve vector
#define pb push_back
using namespace std;


int n;
int m;
ve<ve<int> > adj;
ve<int> mark;
ve<int> visited;


bool dfs(int u)
{
	visited[u]=1;
	if(mark[u])
		return 1;
	mark[u]=1;
	for(auto a:adj[u])
		if(dfs(a))
			return 1;
	mark[u]=0;
	return 0;
}


int main()
{
	cin>>n>>m;
	adj.resize(n);
	mark.resize(n,0);
	visited.resize(n,0);
	for(int i=0;i<m;i++)
	{
		int u,v;
		cin>>u>>v;
		u--,v--;
		adj[u].pb(v);
	}
	for(int i=0;i<n;i++)
		if(!visited[i])
		{
			if(dfs(i))
			{
				cout<<"cycle found"<<endl;
				return 0;
			}
		}
	cout<<"no cycle found"<<endl;
	return 0;

}
