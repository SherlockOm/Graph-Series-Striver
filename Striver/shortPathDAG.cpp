//Question : https://practice.geeksforgeeks.org/problems/shortest-path-in-undirected-graph/1
#include<iostream>
#include<vector>
#include<stack>
#include<climits>
using namespace std;

void topoSort(int i, vector<pair<int, int>> adj[], stack<int> &s, bool vis[]){
	vis[i] = 1;
	for(auto p : adj[i]){
		topoSort(p.first, adj, s, vis);
	}
	s.push(i);
}

vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
    vector<pair<int, int>>  adj[N];
    for(auto v : edges){
    		adj[v[0]].push_back({v[1], v[2]});
    }

    bool vis[N] = {0};

    stack<int> s;
    vector<int> wts(N, INT_MAX);
    
    topoSort(0, adj, s, vis);
    for(int i =0;i<N;i++){
        if(!vis[i])wts[i] = -1;
    }

    //we can choose any source to start with
    //when source = 0
    wts[0] = 0;
    while(!s.empty()){
    	int n= s.top();
    	s.pop();
    	for(auto p : adj[n]){
    		int nbr = p.first;
    		int wt = p.second + wts[n];

    		if(wts[nbr] > wt)
    			wts[nbr] = wt;
    	}
    }
    return wts;
}

int main(){
	vector<vector<int>> graph = {
		{0,1,2},{0,4,1},{4,5,4},{4,2,2},{1,2,3},{2,3,6},{5,3,1}
	};
	vector<int> ans = shortestPath(6, 7, graph);
	for(auto e : ans)cout<<e<< " ";
}