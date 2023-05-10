//Question : https://leetcode.com/problems/is-graph-bipartite/
#include<iostream>
#include<vector>
#include<queue>
using namespace std;



bool BFScheck(int n, int color[], vector<vector<int>> &graph){
	queue<int> q;
	q.push(n);
	color[n] = 0;
	while(!q.empty()){
		int node= q.front();
		q.pop();
		for(auto nbr : graph[node]){
			if(color[nbr] == -1){
				color[nbr] = !color[node];
				q.push(nbr);
			}

			else if(color[nbr] == color[node])
				return 0;
		}
	}
	return 1;
}

bool DFScheck(int n, int c, int color[], vector<vector<int>> &graph){
	color[n] = c;
	for(auto nbr : graph[n]){
		if(color[nbr] == -1){
			if(!DFScheck(nbr, !c, color, graph))return 0;
		}
		else if(color[nbr] == c)
			return false;
	}
	return true;
}


bool isBipartite(vector<vector<int>>& graph) {
    int v = graph.size();
    vector<bool> vis(v, 0);
    int color[v] ;
    for(int i=0;i<v;i++)color[i] = -1;

    for(int i=0;i<v;i++){
        if(color[i]==-1){
			// if(!BFScheck(i, col, or, graph))
			// 	return 0;
			if(!DFScheck(i, 0, color, graph))
				return 0;
        }
    }
    return 1;
}


int main(){
	vector<vector<int>> v = {
		{1,2},{0,2},{0,1}
    };

    // [[2,3,5,6,7,8,9],[2,3,4,5,6,7,8,9],[0,1,3,4,5,6,7,8,9],[0,1,2,4,5,6,7,8,9],[1,2,3,6,9],[0,1,2,3,7,8,9],[0,1,2,3,4,7,8,9],[0,1,2,3,5,6,8,9],[0,1,2,3,5,6,7],[0,1,2,3,4,5,6,7]]
	cout<<isBipartite(v);
}