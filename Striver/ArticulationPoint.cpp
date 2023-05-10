#include<iostream>
#include<vector>
#include<set>
using namespace std;

void DFS(int node, int parent, vector<bool> &vis, int timer, vector<int> &low, vector<int> &tin, vector<int> adj[], set<int> &s){
	vis[node] = 1;
	low[node] = tin[node] = timer;
	timer++;
	int nChild{0};
	for(auto nbr : adj[node]){
		if(nbr == parent)continue;
		if(!vis[nbr]){
			DFS(nbr, node, vis, timer, low, tin, adj, s);
			low[node] = min(low[node], low[nbr]);
			if(low[nbr] >= tin[node] and parent!=-1){
				s.insert(node);
			}
			//for 0 only
			//we have to count childs
			//note that we increase no of childs in not visited condition
			//which means, the neighbor can't be connected
			nChild++;
		}
		else {
			low[node] = min(low[node], tin[nbr]);
		}
	}
	if(nChild > 1 and parent == -1)s.insert(node);
}

vector<int> articulationPoints(int v, vector<int>adj[]) {
    vector<int> ans;
    vector<bool> vis(v,0);
    vector<int> low(v), tin(v);
    int timer= 1;
    set<int> s;
    DFS(0, -1, vis, timer, low, tin, adj, s);

    for(auto e : s)ans.push_back(e);
    return ans.size() ==0 ?{-1} : ans;
}


int main(){
	int v {5};
	vector<int> adj[v] = {
		{1},{0,4},{3,4},{2,4},{1,2,3}		
	};

	vector<int> ans = articulationPoints(v, adj);
	for(auto e : ans)cout<<e<<" ";
}