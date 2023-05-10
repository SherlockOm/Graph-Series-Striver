//https://leetcode.com/problems/critical-connections-in-a-network/
#include<iostream>
#include<vector>
using namespace std;


void DFS(int node, int parent, int timer, vector<int> adj[], bool vis[], vector<int> &low, vector<int> &tin,
 vector<vector<int>> &bridges){
	vis[node] = 1;
	tin[node] = low[node] = timer;
	timer++;
	for(auto nbr : adj[node]){
		if(nbr == parent)continue;
		if(!vis[nbr]){
			DFS(nbr, node, timer, adj, vis,low, tin, bridges);
			low[node] = min(low[node], low[nbr]);
			//if nbr can't come before parent's insertion time (which can even be greater than lowest of parent)
			//no matter which path it chooses then the connection between them can be removed
			if(tin[node] < low[nbr])
				bridges.push_back({node, nbr});
		}
		else {
			low[node] = min(low[node], low[nbr]);
		}
	}

}

vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
	vector<int> adj[n];
	for(auto e : connections){
		adj[e[0]].push_back(e[1]);
		adj[e[1]].push_back(e[0]);
	}

	bool vis[n]= {0};
	int timer = 1;
	vector<int> tin(n), low(n);
	vector<vector<int>> bridges;
	DFS(0, -1, timer, adj, vis, low, tin, bridges);
	return bridges;
}


//space : O(V + 2E + 3N)
//time : O(V+E) of DFS
int main(){
	int n = 4;
    vector<vector<int>> connections = {
        {0, 1}, {1, 2},
        {2, 0}, {1, 3}
    };
    vector<vector<int>> bridges = criticalConnections(n, connections);
}