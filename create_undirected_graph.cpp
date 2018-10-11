#include<bits/stdc++.h>
#define ve vector
#define pb push_back
using namespace std;

int ver, edg;
ve<ve<int> > adj;


int main()
{
	cin>>ver>>edg;
	adj.resize(ver);
	for(int i=0;i<edg;i++)
	{
		int u,v;
		cin>>u>>v;
		u--,v--;
		adj[u].pb(v);
		adj[v].pb(u);
	}

	cout<<"Graph has been created : <3"<<endl;

	return 0;
}
