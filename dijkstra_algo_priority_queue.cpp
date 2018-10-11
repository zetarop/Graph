#include<bits/stdc++.h>
#define ve vector
#define pb push_back
#define N 1000000007

class solve
{
	int n;   //vertex count
	int m;	//edge count
	int srcVer;		//source vertex 
	ve<ve<pair<int,int> > > adj;
	ve<int> mark;
	ve<int> d;
public:
	solve()
	{
		cin>>n>>m;
		adj.resize(n);
		d.resize(n,N);
		mark.resize(n,0);
		for(int i=0;i<m;i++)
		{
			int u,v,w;
			cin>>u>>v>>w;
			u--,v--;
			adj[u].pb({v,w});
			adj[v].pb({u,w});
		}

		cin>>srcVer;
		srcVer--;

		dijkstra(srcVer);
	}

	void dijkstra(int u)
	{
		d[u]=0;
		priority_queue< pair<int,int>, ve<pair<int, int>>, greater<pair<int, int> > > pq;
		pq.push({d[u],u});

		while(!pq.empty())
		{
			int t=pq.top().second;
			pq.pop();

			if(!mark[t])
				mark[t]=1;
			else
				continue;
			for(auto a:adj[t])
			{
				if(d[a.first] > d[t] + a.second)
					d[a.first] = d[t] + a.second;
				pq.push({d[a.first], a.first});
			}
		}
		for(auto a:d)
			cout<<a<<" ";
	}
};

int main()
{
	solve s;
	return 0;
}
