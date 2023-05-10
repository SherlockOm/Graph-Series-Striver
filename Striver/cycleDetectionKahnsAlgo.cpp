//question : https://www.geeksforgeeks.org/detect-cycle-in-a-graph/
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

bool kahnsAlgoCyclic(vector<vector<int>> graph){
		int v = graph.size();
    	vector<int> inDeg (v, 0);
    	for(int i=0;i<v;i++){
    		for(auto nbr : graph[i])
    			inDeg[nbr] ++;
    	}
    
    	//modified BFS
    	int count{0};
    	queue<int> q;
    	for(int i=0;i<v;i++){
    		if(inDeg[i] == 0)
    			q.push(i);
    	}
    
    	while(!q.empty()){
    		int n= q.front();
    		q.pop();
    		count++;
    		for(auto nbr : graph[n]){
    			inDeg[nbr]--;
    			if(inDeg[nbr] == 0)q.push(nbr);
    		}
    	}
    	return count == v ?0:1;
    }

int main(){
	vector<vector<int>> graph = {
		// {1}, {0, 2, 4}, {1, 3}, {2, 4}, {1, 3}
		{1},{2},{3},{4,7},{5},{6},{},{5},{9},{10},{8}
	};
	cout<<kahnsAlgoCyclic(graph);

}