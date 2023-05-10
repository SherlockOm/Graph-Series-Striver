//Question : https://www.geeksforgeeks.org/eventual-safe-states/

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

vector<int> safeNodes(vector<vector<int>> &graph){
	int v = graph.size();
	vector<int> nodes;
	int inDeg[v]={0};

	vector<int> revGraph[v];
	for(int i=0;i<v;i++){
		for(auto nbr : graph[i]){
			revGraph[nbr].push_back(i);
			inDeg[i]++;
		}
	}
	
	queue<int> q;
	for(int i=0;i<v;i++)if(inDeg[i]==0)q.push(i);

	while(!q.empty()){
		int n= q.front();
		q.pop();
		nodes.push_back(n);
		for(auto nbr : revGraph[n]){
			inDeg[nbr] -- ;
			if(inDeg[nbr] == 0)
				q.push(nbr);
		}
	}
	sort(nodes.begin(), nodes.end());
	return nodes;
}

int main(){
	vector<vector<int>> graph = {
		 {{1,2},{2,3},{5},{0},{5},{},{}}
	};
	vector<int> ans = safeNodes(graph);
	for(auto e : ans)cout<<e<<" ";
}