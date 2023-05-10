//https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class DisjointSet{
	vector<int> parent, size;
public: 
	DisjointSet(int V ){
		parent.resize(V+1);
		size.resize(V+1,1);
		for(int i=0;i<=V;i++)
			parent[i] = i;
	}
	int findUltParent(int n){
		if(n == parent[n])return n;
		return parent[n] = findUltParent(parent[n]);
	}

	void unionBySize(int u, int v){
		int ultU = findUltParent(u);
		int ultV = findUltParent(v);
		if(ultU == ultV )return;
		if(size[ultV] > size[ultU]){
			size[ultV]+= size[ultU];
			parent[ultU] = ultV;
		}
		else {
			size[ultU]+= size[ultV];
			parent[ultV] = ultU;
		}
	}
};


int spanningTree(int V, vector<vector<int>> adj[]){
    vector<vector<int>>edges ;
    for(int i=0;i<V;i++){
    	for(auto ve : adj[i]){
    		int wt = ve[1];
    		int u = ve[0];
    		
    		edges.push_back({wt, i, u});
    	}
    }

    sort(edges.begin(), edges.end());

    DisjointSet ds(V);
    int wtSum{0};
    for(auto e : edges){
    	int wt = e[0];
    	int u = e[1];
    	int v = e[2];
    	if(ds.findUltParent(u) != ds.findUltParent(v)){
    		wtSum += wt;
    		ds.unionBySize(u, v);
    	}
    }
    return wtSum;
}


int main(){
	vector<vector<int>> edges = {
		{0, 1, 5},
		{1, 2, 3},
		{0, 2, 1}
	};
    // vector<vector<int>> edges = {{0, 1, 2}, {0, 2, 1}, {1, 2, 1}, {2, 3, 2}, {3, 4, 1}, {4, 2, 2}};

	int V = 3;
	vector<vector<int>> adj[V];
	for(auto e : edges){
		adj[e[0]].push_back({e[1], e[2]});
		adj[e[1]].push_back({e[0], e[2]});
	}

	cout<<spanningTree(V, adj);
}