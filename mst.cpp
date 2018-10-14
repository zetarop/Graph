#include<bits/stdc++.h>
#define ve vector
#define pb push_back
using namespace std;

ve<pair<int,pair<int, int> > > edges;
ve<int> parent;



int find(int a)
{
	return a==parent[a] ? a:parent[a]=find(parent[a]);
}

void join(int a, int b)
{
	parent[find(b)]=find(a);
}

int main()
{
	int n;
	int m;
	int weight_of_mst=0;
	cin>>n>>m;
	parent.resize(n);
	for(int i=0;i<n;i++)
		parent[i]=i;
	for(int i=0;i<m;i++)
	{
		int w,u,v;
		cin>>w>>u>>v;
		u--,v--;
		edges.pb({w,{u,v}});
	}
	sort(edges.begin(), edges.end());

	for(auto a:edges)
	{
		if(find(a.second.first) != find(a.second.second))
		{
			join(a.second.first, a.second.second);
			weight_of_mst += a.first;
		}
	}
	cout<<weight_of_mst<<endl;
	return 0;
}
