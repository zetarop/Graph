#include<bits/stdc++.h>
#define ve vector
#define pb push_back
#define inf 1000000007

class solve
{
	int n;
	int m;
	int weight_of_mst;
	ve<pair<int, pair<int,int> > > edges;
	ve<int> parent;
public:
	solve()
	{
		cin>>n>>m;
		weight_of_mst=0;
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
				weight_of_mst += a.first;
				join(a.second.first, a.second.second);
			}
		}
		cout<<"weight of mst : "<<weight_of_mst<<endl;
	}

	int find(int a)
	{
		return a == parent[a] ? a : parent[a] = find(parent[a]);
	}
	void join(int a, int b)
	{
		parent[find(b)] = find(a);
	}

};

int main()
{
	solve s;
	return 0;
}
