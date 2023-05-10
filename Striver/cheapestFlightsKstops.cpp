//Question : https://practice.geeksforgeeks.org/problems/cheapest-flights-within-k-stops/1
#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;


int findCheapestPrice(int N, vector<vector<int>>& flights,
int src, int dst, int k) {
	vector<vector<int>> adj[N];
	for(auto edge : flights){
	   adj[edge[0]].push_back({edge[1], edge[2]});
	}
	vector<int> dist(N, INT_MAX);
	dist[src] = 0;

	queue<vector<int>> q;
	q.push({0, src, 0});

	while(!q.empty()){
		auto v = q.front();
		int nStops = v[0];
		int node = v[1];
		int curDist = v[2];
		q.pop();

		if(nStops > k)continue;

		for(auto vNbr : adj[node]){
			int nbr = vNbr[0];
			int d = vNbr[1] ;

			if(dist[nbr] > d  + curDist){
				q.push({nStops + 1, nbr, d + curDist});
				dist[nbr]  = d + curDist;
			}
		}

	}
	for(auto e : dist)cout<<e<<" ";
	if(dist[dst] == INT_MAX)return -1;
	return dist[dst];

}


int main(){
	vector<vector<int>> flights = 
	{{0,1,100},{1,2,100},{2,0,100},{1,3,600},{2,3,200}};

	vector<vector<int>> flights2 = 
	{{0,1,100},{1,2,100},{0,2,500}};

	vector<vector<int>> flights3 = 
	{{0,1,100},{1,2,100},{0,2,500}};

	cout<<findCheapestPrice(3, flights3, 0, 2, 0);
}