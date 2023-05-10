//Question : https://practice.geeksforgeeks.org/problems/shortest-path-in-undirected-graph-having-unit-distance/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=shortest-path-in-undirected-graph-having-unit-distance
#include<iostream>
#include<vector>
#include<utility>
#include<climits>
#include<queue>
using namespace std;


void DFS(int i, vector<int> adj[], bool vis[], vector<int> &wts){
	vis[i] = 1;
	for(auto nbr : adj[i]){
		int wt = wts[i] + 1;
		if(wts[nbr] > wt){
			wts[nbr] = wt;
			DFS(nbr, adj, vis, wts);
		}
	}
}

vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
	vector<int> wts(N, INT_MAX);
	wts[src] = 0;

	vector<int> adj[N];
	for(auto e : edges){
		adj[e[0]].push_back(e[1]);
		adj[e[1]].push_back(e[0]);
	}

	bool vis[N] = {0};
	vis[src] = 1;

	//BFS
	// queue<int> q;
	// q.push(src);
	// while(!q.empty()){
	// 	int p = q.front();
	// 	q.pop();
	// 	for(auto nbr : adj[p]){
	// 		int wt = wts[p] + 1;
	// 		vis[nbr] = 1;
	// 		if(wts[nbr]> wt){
	// 			q.push(nbr);
	// 			wts[nbr] = wt;
	// 		}
	// 	} 
	// }
	
	//DFS
	DFS(src, adj, vis, wts);
	for(int i=0;i<N;i++){
		if(!vis[i])wts[i] =-1;
	}
	return wts;
}

int main(){
	vector<vector<int>> graph = {
		{0,1,2},{0,4,1},{4,5,4},{4,2,2},{1,2,3},{2,3,6},{5,3,1}
	};
	vector<int> ans = shortestPath(graph, 6, 7, 0);
	for(auto e : ans)cout<<e<<" ";
}