//https://practice.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1
#include<iostream>
#include<vector>
#include<stack>
using namespace std;
	

void dfs(int n, bool vis[], vector<vector<int>> &adj, stack<int> &s){
	vis[n] = 1;
	for(auto nbr : adj[n]){
		if(!vis[nbr])
			dfs(nbr, vis, adj, s);
	}
	s.push(n);
}

void dfs2(int n, vector<int> adj[], bool vis[]){
	vis[n] = 1;
	for(auto nbr : adj[n]){
		if(!vis[nbr])
			dfs2(nbr, adj, vis);
	}
}

int kosaraju(int v, vector<vector<int>>& adj){
    stack<int> s;
    bool vis[v] = {0};

    for(int i=0;i<v;i++){
    	if(!vis[i])
    		dfs(i, vis, adj, s);
    }

    vector<int> adjT[v];
    for(int i=0;i<v;i++){
		vis[i] = 0;
    	for(auto nbr : adj[i]){
    		adjT[nbr].push_back(i);
    	}
    }

    int scc{0};
    while(!s.empty()){
    	int n= s.top();
    	s.pop();
    	if(!vis[n]){
    		scc++;
    		dfs2(n, adjT, vis);
    	}
    }
    return scc;
}
int main(){
	vector<vector<int>> adj = {
		{1, 0}, {0, 2},
        {2, 1}, {0, 3},
        {3, 4}
	};
	int v = 5;
	cout<<kosaraju(v, adj);
	cout<<"adfddff";
}