#include<iostream>
#include<vector>
using namespace std;

class DisjointSet{

public:
	vector<int> parent, rank, size;
	DisjointSet(int V){
		parent.resize(V+1);
		size.resize(V+1, 1);
		rank.resize(V+1, 0);
		for(int i=0;i<=V; i++){
			parent[i] = i;
		}
	}

	//O(4*alpha) ~ O(1) since alpha is very small
	//therefore efficient
	int findUltParent(int n){
		if(parent[n] == n)return n;
		return parent[n] = findUltParent(parent[n]);
	}

	void unionByRank(int u, int v){
		int up_u = findUltParent(u);
		int up_v = findUltParent(v);
		if(rank[up_v] > rank[up_u]){
			parent[up_u] = up_v;
		}
		else if (rank[up_v] < rank[up_u]){
			parent[up_v] = up_u;
		}
		else {
			rank[up_u]++;
			parent[up_v] = up_u;
		}
	}
	void unionBySize(int u, int v){
		int up_u = findUltParent(u);
		int up_v = findUltParent(v);

		if(up_u == up_v)return;
		if(size[up_u] < size[up_v]){
			size[up_v]+= size[up_u];
			parent[up_u] = up_v;
		}
		else {
			size[up_u]+= size[up_v];
			parent[up_v] = up_u;
		}
	}
};


int main(){
	DisjointSet ds(7);
	ds.unionBySize(1, 2);
	ds.unionBySize(2, 3);
	ds.unionBySize(4, 5);
	ds.unionBySize(6, 7);
	ds.unionBySize(5, 6);


	if(ds.findUltParent(3) == ds.findUltParent(7))cout<<"Yes";
	else cout<<"No";
	
	ds.unionBySize(3, 7);

	if(ds.findUltParent(3) == ds.findUltParent(7))cout<<"Yes";
	else cout<<"No";
	
	return 0;
}