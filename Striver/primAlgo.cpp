//https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

//with edges
vector<vector<int>> MinSpanningTree(int V, vector<vector<int>> adj[]){
    vector<vector<int>> mst;
    bool vis[V] = {0};
    // int sum{0};

    priority_queue<vector<int>, vector<vector<int>> , greater<vector<int>> > q;
    q.push({0, 0, -1});

    while(!q.empty()){
    	auto v = q.top();
    	q.pop();
    	int curD= v[0];
    	int node = v[1];
    	int parent = v[2];
    	if(vis[node])continue;
    	// sum += curD;

    	if(parent!=-1) mst.push_back({parent, node, curD});

    	vis[node] = 1;

    	for(auto nbrV : adj[node] ){
    		int nbr = nbrV[0];
    		int d = nbrV[1];
    		if(!vis[nbr])
	    		q.push({d, nbr, node});
    	}
    }
    
    return mst;
}

//sum only
int spanningTree(int V, vector<vector<int>> adj[]){
    bool vis[V] = {0};
    int sum{0};


    priority_queue<vector<int>, vector<vector<int>> , greater<vector<int>> > q;
    q.push({0, 0});

    while(!q.empty()){
    	auto v = q.top();
    	q.pop();
    	int curD= v[0];
    	int node = v[1];
    	if(vis[node])continue;
    	sum+= curD;
    	vis[node] = 1;

    	for(auto nbrV : adj[node] ){
    		int nbr = nbrV[0];
    		int d = nbrV[1];
    		if(!vis[nbr])
	    		q.push({d, nbr});
    	}
    }
    return sum;
}

int main(){
	int V = 3;
	vector<vector<int>> edges = {{0, 1, 5},
	{1, 2, 3},
	{0, 2, 1}};
	vector<vector<int>> adj[V];
	for(auto e : edges){
		adj[e[0]].push_back({e[1], e[2]});
		adj[e[1]].push_back({e[0], e[2]});
	}
	cout<<spanningTree(V, adj);

}