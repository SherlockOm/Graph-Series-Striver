//https://practice.geeksforgeeks.org/problems/number-of-islands/1
#include<iostream>
#include<vector>
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


vector<int> numOfIslands(int n, int m, vector<vector<int>> &queries) {
    vector<int> ans;
    int size = n*m;
    bool vis[size] = {0};
    DisjointSet ds(size);

    int ix[] = {0,0,1,-1};
    int iy[] = {1,-1,0,0};

    int nIslands{0};
    for(int i=0;i<queries.size();i++){
    	int r = queries[i].at(0);
    	int c = queries[i].at(1);

    	int node= r*m + c;
    	if(vis[node]){
    		ans.push_back(nIslands);
    		continue;
	    }
    	
		nIslands++;
		vis[node] = 1;
		for(int i=0;i<4;i++){
			int nr = r + ix[i];
			int nc = c + iy[i];
			if(nr>=0 and nc>=0 and nr<n and nc<m){
    			int nbr = nr*m + nc;
    			if(vis[nbr] and ds.findUltParent(node)!= ds.findUltParent(nbr)){
    				nIslands--;
    				ds.unionBySize(nbr, node);
				}
			}
		}
	
    	ans.push_back(nIslands);
    }
    return ans;
}


int main(){
	vector<vector<int>> queries = {{0,0},{1,1},{2,2},{3,3}};
	vector<vector<int>> q = {
		{1, 1},
		{0, 3},
		{2, 3},
		{2, 4},
		{2, 4},
		{2, 1},
		{1, 4},
		{0, 0},
		{1, 2},
		{2, 0}};
	int n=3, m=5;
	auto ans = numOfIslands(n, m, q);
	for(auto e : ans)cout<<e<<" ";
}