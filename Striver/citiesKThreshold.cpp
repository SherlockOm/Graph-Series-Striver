//Question : https://practice.geeksforgeeks.org/problems/city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/0?category%5B%5D=Graph
//Question : https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/

#include<iostream>
#include<vector>
#include<climits>
using namespace std;


int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
	vector<vector<int>> adj(n, vector<int> (n, INT_MAX));
	for(auto edge : edges){
		adj[edge[0]][edge[1]] = edge[2];
		adj[edge[1]][edge[0]] = edge[2];
	}

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
			if(i==j)adj[i][j] = 0;
	}

	for(int via =0;via<n;via++){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(adj[i][via]!= INT_MAX and adj[via][j]!=INT_MAX){
					if(adj[i][j] ==INT_MAX or adj[i][j] > adj[i][via] + adj[via][j])
						adj[i][j] = adj[i][via] + adj[via][j];
				}
			}
		}
	}
	int nCities{n};
	int ans{-1};
	for(int i=0;i<n;i++){
		int cnt{0};
		for(int j=0;j<n;j++){
			if(adj[i][j] <= distanceThreshold)
				cnt++;
		}
		if(cnt <= nCities){
			ans = i;
			nCities = cnt;
		}
	}
	return ans;
}
	
int main(){
	vector<vector<int>> edges = {{0,1,3},{1,2,1},{1,3,4},{2,3,1}};
	int vertices = 4;
	int threshold = 4;
	cout<<findTheCity(vertices, edges, threshold);
}