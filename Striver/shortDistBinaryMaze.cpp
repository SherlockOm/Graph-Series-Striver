//Question : https://www.geeksforgeeks.org/shortest-path-in-a-binary-maze/
#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;

int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                 pair<int, int> destination) {
	int sr = source.first, sc=source.second;
	int dr = destination.first, dc = destination.second;

	if(grid[sr][sc] == 0 or grid[dr][dc] == 0)return -1;

    vector<vector<int>> dist(grid.size(), vector<int> (grid[0].size(), INT_MAX));
    dist[sr][sc] = 0;
    int ix[] = {0,0,1,-1};
    int iy[] = {1,-1,0,0};

    queue<vector<int>> q;
    q.push({0, sr, sc});

    while(!q.empty()){
    	auto v = q.front();
    	int r = v.at(1);
    	int c = v.at(2);
    	int cost = v.at(0);
    	q.pop();
    	if(r == dr and c == dc)
    		return cost;
    	for(int i=0;i<4;i++){
    		int nr = ix[i] + r;
    		int nc = iy[i] + c;

    		if(nr>= 0 and nc>=0 and nr<grid.size() and nc<grid[0].size() 
    			and grid[nr][nc] == 1 and dist[nr][nc] > cost + 1){
    			q.push({cost + 1, nr, nc});
    			dist[nr][nc] = cost + 1;
    		}
    	}
    }
    return -1;
}


//leetcode: 8 directions
//https://leetcode.com/problems/shortest-path-in-binary-matrix/
bool check(int r, int c, int n,vector<vector<int>> &grid){
    if(r>=n or c>=n or r<0 or c<0 or grid[r][c] == 1)
        return 0;
    return 1;
}

int shortestPathBinaryMatrix(vector<vector<int>>& grid){
	//source : (0,0), destination : (n-1, n-1)
    int n = grid.size();
    if(grid[0][0]==1 or grid[n-1][n-1] == 1)
        return -1;

    vector<vector<int>> dist(n, vector<int> (n, INT_MAX));
    dist[0][0] = 1;
    int ix[] = {0,0,1,-1,-1,-1,1,1};
    int iy[] = {1,-1,0,0,1,-1,1,-1};

    queue<vector<int>> q;
    q.push({1, 0, 0});

    while(!q.empty()){
        auto v = q.front();
        int r = v.at(1);
        int c = v.at(2);
        int cost = v.at(0);
        q.pop();
        if(r == n-1 and c == n-1)
            return cost;
        for(int i=0;i<8;i++){
            int nr = ix[i] + r;
            int nc = iy[i] + c;

            if(check(nr, nc, n, grid) and dist[nr][nc] > cost + 1){
                q.push({cost + 1, nr, nc});
                dist[nr][nc] = cost + 1;
            }
        }
    }
    return -1;
}


int main(){
	vector<vector<int>> grid = {{1, 1, 1, 1, 1},
            {1, 1, 1, 1, 1},
            {1, 1, 1, 1, 0},
            {1, 0, 1, 0, 1}};
    cout<<shortestPath(grid, {0, 0}, {3, 4})<<endl;

    vector<vector<int>> grid2 = {{1, 1, 1, 1},
            {1, 1, 0, 1},
            {1, 1, 1, 1},
            {1, 1, 0, 0},
            {1, 0, 0, 1}};
    cout<<shortestPath(grid2, {0, 1}, {2, 2});
}