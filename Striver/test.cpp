#include<iostream>
#include<vector>
#include<list>
#include<queue>
using namespace std;

class Node{
public:
	int data;
	vector<int> nbrs;

	Node(int d):data{d}{}
};


class Graph{
public:
	int v;
	list<int> *l;
	list<pair<int, int>> *lw;

	Graph(int V){
		v = V;
		l = new list<int> [v];
	}

	void addEdge(int n1, int n2, bool undir=true, int w=0){
		if(undir){
			l[n1].push_back(n2);
			l[n2].push_back(n1);
		}
		else
			lw[n1].push_back({n2, w});
	}
	void printGraph(){
		for(int i=0;i<v;i++){
			cout<<i<<"-->";
			for(auto elem : l[i])
				cout<<elem<<",";
			cout<<endl;
		}
	}

	void BFS(int root){
		vector<bool> vis (v,0);
		queue<int> q;
		q.push(root);
		vis[root] = true;
		while(!q.empty()){
			int n = q.front();
			q.pop();
			cout<<n<<" ";
			
			for(auto nbr : l[n]){
				if(!vis[nbr]){
					q.push(nbr);
					vis[nbr] = true;
				}
			}
		}
	}
	
	void DFS(int root, vector<bool> &vis){
		if(vis[root])return ;
		// cout<<root<<" ";
		vis[root] = true;
		for(auto nbr : l[root]){
			DFS(nbr, vis);
		}
	}

	int NoOfProvinces(){
		int count{0};		
		vector<bool> vis(v, 0);
		for(int i=0;i<v;i++){
			if(!vis[i]){
				count++;
				DFS(i, vis);
			}
		}
		return count;
	}
};


int main(){
	//  Graph g(7);
	// g.addEdge(0,1);
	// g.addEdge(0,4);
	// g.addEdge(2,1);
	// g.addEdge(3,4);
	// g.addEdge(4,5);
	// g.addEdge(2,3);
	// g.addEdge(3,5);
	// g.addEdge(5,6);
	// g.printGraph();

	// g.BFS(0);

	// vector<bool> vis (g.v, false);
	// g.DFS(0, vis);



	Graph g(8);
	// g.addEdge(0,1);
	g.addEdge(1,2);
	g.addEdge(3,4);
	g.addEdge(4,5);
	g.addEdge(6,7);
	g.printGraph();
	cout<<g.NoOfProvinces();

	// Graph g(5);
	// g.addEdge(1,2,false,1);
	// g.addEdge(1,5,false,2);
	// g.addEdge(2,5,false,3);
	// g.addEdge(5,4,false,2);
	
}