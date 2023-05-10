#include<iostream>
#include<vector>
using namespace std;

void dfs(int n, vector<int> adj[], bool vis[]){
	vis[n] =1;
	for(auto nbr : adj[n]){
		if(!vis[nbr])
			dfs(nbr, adj, vis);
	}
}

int findCircleNum(vector<vector<int>>& mat) {
	int v = mat.size();
	vector<int> adj[v];
	for(int i=0;i<v;i++){
		for(int j=0;j<v;j++){
			if(mat[i][j] == 1 and i!=j){
				adj[i].push_back(j);
				adj[j].push_back(i);
			}
		}
	}

	bool vis[v] = {0};
	int count{0};
	for(int i=0;i<v;i++){
		if(!vis[i]){
			count++;
			dfs(i , adj, vis);
		}
	}
	return count;
}

//can also be done using disjoint set data structure 
//we can count no of different ultimate parents
int main(){
	vector<vector<int>> graph = {
	 {1, 0, 1},
	 {0, 1, 0},
	 {1, 0, 1}};

	cout<<findCircleNum(graph);

}