//Question : https://www.geeksforgeeks.org/topological-sorting/
#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;

void DFS(int n, vector<vector<int>> &graph,
 vector<bool> &vis, vector<int> &s){
	vis[n] = 1;
	for(auto nbr : graph[n]){
		if(!vis[nbr])
			DFS(nbr, graph, vis, s);
	}
	s.push_back(n);
	
}


vector<int> topologicalSort(vector<vector<int>> &graph){
	vector<bool> vis(graph.size(), 0);
	vector<int> s;
	for(int i=0;i<graph.size();i++){
		if(!vis[i])
			DFS(i, graph, vis, s);
	}
	//or use stack
	reverse(s.begin(), s.end());
	return s;
}

int main(){
	vector<vector<int>> graph = {
		{},{},{3},{1},{0,1},{0,2}
	};
	vector<int> v = topologicalSort(graph);
	for(auto e : v)cout<<e<<" ";
}