//Question : https://www.geeksforgeeks.org/eventual-safe-states/
#include<iostream>
#include<vector>
using namespace std;

bool DFS(int n, vector<vector<int>> &graph, vector<bool> &check, vector<int> &vis){
    vis[n] = 2;
    for(auto nbr : graph[n]){
        if(!vis[nbr]){
            if(DFS(nbr, graph, check, vis)){
                return 1;
            }
        }
        else if (vis[nbr] == 2)
            return 1;
    }
    vis[n] = 1;
    check[n] = 1;
    return 0;	
}

vector<int> eventualSafeNodes(vector<vector<int>> graph){
    vector<int> safeNodes;
    int V = graph.size();
    vector<int> vis(V, 0);
    vector<bool> check(V, 0);
    for(int i=0;i<V;i++){
        if(!vis[i])
            DFS(i, graph, check, vis);
    }

    for(int i=0;i<V;i++)
        if(check[i])safeNodes.push_back(i);

    return safeNodes;
}

int main(){
	vector<vector<int>> graph = {
		 {{1,2},{2,3},{5},{0},{5},{},{}}
	};
	vector<int> ans = eventualSafeNodes(graph);
	for(auto e : ans)cout<<e<<" ";
}