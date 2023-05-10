#include<iostream>
#include<vector>
using namespace std;

vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
	vector<int> dist(V, 1e8);
	dist[S] = 0;
	for(int i=0;i<V-1;i++){
		for(auto edge : edges){
			int u =edge[0];
			int v = edge[1];
			int d = edge[2];
			if(dist[u]!= 1e8 and dist[u] + d < dist[v])
				dist[v] = dist[u] + d;
		}
	}

	//to detect negetive cycle
	for(auto edge : edges){
		int u =edge[0];
			int v = edge[1];
			int d = edge[2];
			if(dist[u]!= 1e8 and dist[u] + d < dist[v])
				return {-1};
	}

	return dist;
}

int main(){
	vector<vector<int>> edges = {{0,1,5},{1,0,3},{1,2,-1},{2,0,1}};
	vector<int> ans = bellman_ford(3, edges, 2);
	for(auto e : ans)cout<<e<<" ";
}