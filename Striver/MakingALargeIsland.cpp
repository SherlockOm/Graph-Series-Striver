//https://leetcode.com/problems/making-a-large-island/
//https://practice.geeksforgeeks.org/problems/maximum-connected-group/1
#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

class DisjointSet{
public: 
	vector<int> parent, size;
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


int largestIsland(vector<vector<int>>& grid) {
	int n= grid.size();
	DisjointSet ds(n*n);

	int ix[] = {0,0,1,-1};
	int iy[] = {1,-1,0,0};

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			int node = i*n + j;
			if(grid[i][j] == 1){
				for(int k=0;k<4;k++){
					int nr = i + ix[k];
					int nc = j + iy[k];
					int newNode = nr*n + nc;
					if(nr>=0 and nc>=0 and nr<n and nc<n and grid[nr][nc]==1){
						ds.unionBySize(node, newNode);
					}

				}
			}
		}
	}

	int ans{0};

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(grid[i][j] == 1)continue;
			int temp{1};
			unordered_set<int> ults;
			for(int k=0;k<4;k++){
				int nr = i + ix[k];
				int nc = j + iy[k];
				
				if(nr>=0 and nc>=0 and nr<n and nc<n and grid[nr][nc] == 1 ){
					int ultP = ds.findUltParent(nr*n + nc);
					ults.insert(ultP);
				}
			}
			for(auto p : ults){
				temp+= ds.size[p];
			}
			ans = max(ans, temp);
		}
	}
	//in case all 1s
	for(int node =0 ;node<n*n;node++){
		ans = max(ds.size[node], ans);
	}
	return ans;
}

int main(){
	vector<vector<int>> grid = {
		{1, 0, 1},
		{1, 0, 1},
		{1, 0, 1}
	};
	cout<<largestIsland(grid);

}