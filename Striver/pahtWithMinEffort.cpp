//Question : https://practice.geeksforgeeks.org/problems/path-with-minimum-effort/1
#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;


int MinimumEffort(vector<vector<int>>& heights) {
	int ans{INT_MAX};

    int n = heights.size();
    int m = heights[0].size();
    vector<vector<int>> dist(n, vector<int> (m, INT_MAX));

   	dist[0][0] = 0;
   	priority_queue<vector<int>,
   				   vector<vector<int>>,
   				   greater<vector<int>> > q;
   	q.push({0, 0, 0});

   	int ix[] = {0,0,1,-1};
   	int iy[] = {1,-1,0,0};

   	while(!q.empty()){
   		auto v = q.top();
   		int curDiff = v[0];
   		int r = v[1];
   		int c = v[2];
   		q.pop();

   		if(r == n-1 and c==m-1)
   			return curDiff;

   		for(int i=0;i<4;i++){
   			int nr = r + ix[i];
   			int nc = c + iy[i];
   			if(nr>=0 and nc>=0 and nr<n and nc<m){ 
   				int diff = max(abs(heights[r][c] - heights[nr][nc]),curDiff);
   				if(dist[nr][nc] > diff){
   					dist[nr][nc] = diff;
   					q.push({diff, nr, nc});
   				}
   			}
   		}
   		
   	}
}

int main(){
	vector<vector<int>> heights = {{1,2,2},{3,8,2},{5,3,5}};
	vector<vector<int>> h2 = {{1,2,3},{3,8,4},{5,3,5}};
	vector<vector<int>> h3 = {{1,2,1,1,1},{1,2,1,2,1},{1,2,1,2,1},{1,2,1,2,1},{1,1,1,2,1}};

	cout<<MinimumEffort(h3);
	cout<<"as";
}