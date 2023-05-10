#include<iostream>
#include<vector>
#include<unordered_map>
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

int removeStones(vector<vector<int>>& stones) {
	int n = stones.size();
	int maxR{0};
	int maxC{0};
	for(auto s : stones){
		maxR = max(maxR, s.at(0));
		maxC = max(maxC, s.at(1));
	}

	DisjointSet ds(maxR + maxC + 1);
	unordered_map<int, int> m;
	//to count which rows/columns contain stones, since there may be empty rows and columns

	for(auto s : stones){
		int r = s[0];
		int c = maxR + s[1] + 1;
		ds.unionBySize(r, c);
		m[r] = 1;
		m[c] = 1;
	}

	//to count number of components
	int cnt{0};
	for(auto p : m){
		if(ds.findUltParent(p.first) == p.first)
			cnt++;
	}
	//(total stones - no of components in disjoint set) gives the max stones that can be removed.
	return n - cnt;
}


int main(){
	vector<vector<int>> stones = {{0,0},{0,1},{1,0},{1,2},{2,1},{2,2}};
	cout<<removeStones(stones);
}