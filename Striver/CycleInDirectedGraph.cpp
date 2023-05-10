#include<iostream>
#include<vector>
using namespace std;

bool DFS(int n, vector<vector<int>> &graph, vector<int> &vis){
	vis[n] = 2;
	// pathVis[n] =1;
	for(auto nbr : graph[n]){
		if(!vis[nbr] ){
			if(DFS(nbr, graph, vis)){
				return 1;
			}
		}	
		else if(vis[nbr] == 2)
			return 1;
	}
	vis[n] = 1;
	// pathVis[n] =0;
	return 0;
}


bool isCyclic(vector<vector<int>> &graph){
	vector<int> vis(graph.size(), 0);
	// vector<bool> pathVis(graph.size(), 0);
	for(int i=0;i<graph.size();i++){
		if(!vis[i])
			if(DFS(i, graph, vis))return 1;
	}
	return 0;
}


int main(){
	vector<vector<int>> graph = {
		// {1}, {0, 2, 4}, {1, 3}, {2, 4}, {1, 3}
		{1},{2},{3},{4,7},{5},{6},{},{5},{9},{10},{8}
	};

	cout<<isCyclic(graph);
}