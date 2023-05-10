//https://practice.geeksforgeeks.org/problems/connecting-the-graph/1
#include<iostream>
#include<vector>
using namespace std;


class DisjointSet{
public: 
	vector<int> parent, size;
	int extraEdges{0};
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
		if(ultU == ultV ){
			extraEdges++;
			return;
		}
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

int Solve(int n, vector<vector<int>>& edge) {
    DisjointSet ds(n);
    for(auto e : edge){
    	ds.unionBySize(e[0], e[1]);
    }
    
    int numComp{0};
    for(int i=0;i<n;i++){
    	if(ds.parent[i] == i)numComp++;
    }

    if(ds.extraEdges >= numComp-1)return numComp-1;
    return -1;
}


int main(){
	vector<vector<int>> edge ={ {0,1} , {0,2} , {0,3} , {1,2} , {1,3} };
	cout<<Solve(6, edge);
}