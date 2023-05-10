//Question : https://www.geeksforgeeks.org/topological-sorting-indegree-based-solution/
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void kahnsAlgo(vector<vector<int>> &graph){
	int v = graph.size();
	vector<int> inDeg (v, 0);
	for(int i=0;i<v;i++){
		for(auto nbr : graph[i])
			inDeg[nbr] ++;
	}

	//modified BFS
	queue<int> q;
	for(int i=0;i<v;i++){
		if(inDeg[i] == 0)
			q.push(i);
	}

	while(!q.empty()){
		int n= q.front();
		q.pop();
		cout<<n<<" ";
		for(auto nbr : graph[n]){
			inDeg[nbr]--;
			if(inDeg[nbr] == 0)q.push(nbr);
		}
	}
}

int main(){
	vector<vector<int>> graph = {
		{},{},{3},{1},{0,1},{0,2}
	};
	kahnsAlgo(graph);
}
