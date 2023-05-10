#include<iostream>
#include<vector>
#include<set>
#include<queue>
#include<climits>
using namespace std;

vector<int> dijkstra(int N, vector<vector<int>> graph[], int src){
	vector<int> dist(N, INT_MAX);
	dist[src] = 0;
	set<pair<int, int>> s;
	s.insert({0, src});
	while(!s.empty()){
		int node = s.begin()->second;
		int curCost = s.begin()->first;
		s.erase(s.begin());
		for(auto p : graph[node]){
			int nbr = p[0];
			int cost = curCost + p[1];
			if(cost < dist[nbr]){
				dist[nbr] = cost;
				s.insert({dist[nbr], nbr});
			}
			
		}
	}
	return dist;
}

vector<int> dijkstraPQ(int N, vector<vector<int>> graph[], int src){
	vector<int> dist(N, INT_MAX);
	dist[src] = 0;
	priority_queue<pair<int, int>,
				  vector<pair<int, int>>,
				  greater<pair<int, int>> >q;
	q.push({0, src});
	while(!q.empty()){
		int node = q.top().second;
		int curCost = q.top().first;
		q.pop();
		for(auto p : graph[node]){
			int nbr = p[0];
			int cost = curCost + p[1];
			if(cost < dist[nbr]){
				dist[nbr] = cost;
				q.push({dist[nbr], nbr});
			}
			
		}
	}
	return dist;
}

//https://practice.geeksforgeeks.org/problems/shortest-path-in-weighted-undirected-graph/1
//shortest path using dijkstra
vector<int> shortestPath(int N, int m, vector<vector<int>> &edges){
    int src = 1;
    
	vector<vector<int>> graph[N+1];
	for(auto v : edges){
	    graph[v[0]].push_back({v[1], v[2]});
	    graph[v[1]].push_back({v[0], v[2]});
	}
	
	vector<int> dist(N+1, INT_MAX);
	vector<int> parent(N+1, -1);
	parent[src] = src;
	
	dist[src] = 0;
	
	set<pair<int, int>> s;
	s.insert({0, src});
	
	while(!s.empty()){
		int node = s.begin()->second;
		int curCost = s.begin()->first;
		s.erase(s.begin());
		for(auto p : graph[node]){
			int nbr = p[0];
			int cost = curCost + p[1];
			if(cost < dist[nbr]){
			    parent[nbr] = node;
				dist[nbr] = cost;
				s.insert({dist[nbr], nbr});
			}
			
		}
	}
	if(dist[N] == INT_MAX)return {-1};
	vector<int> path;
	int node = N;
	while(parent[node]!=node){
	    path.push_back(node);
	    node = parent[node];
	}
	path.push_back(node);
	reverse(path.begin(), path.end());
	return path;
}


int main(){
	vector<vector<int>> graph[] = {
		{{1, 1}, {2, 6}}, 
		{{2, 3}, {0, 1}}, 
		{{1, 3}, {0, 6}}
	};
	int src = 2;
	vector<int> dist = dijkstraPQ(3, graph, src);
	for(auto e : dist)cout<<e<<" ";
}