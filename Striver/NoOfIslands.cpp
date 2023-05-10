//Question : https://www.geeksforgeeks.org/find-the-number-of-islands-using-dfs/
#include<iostream>
#include<utility>
#include<vector>
#include<queue>
using namespace std;

void BFS(int r, int c,const  vector<vector<int>> &mat, vector<vector<bool>> &vis){
	queue<pair<int, int>> q;
	vis[r][c] = 1;
	q.push({r,c});
	while(!q.empty()){
		r = q.front().first;
		c = q.front().second;
		q.pop();
		for(int i=-1;i<=1;i++){
			for(int j=-1;j<=1;j++){
				int nr = i + r;
				int nc = j + c;
				if(nr>=0 and nr<mat.size() and 
					nc>=0 and nc<mat[0].size() and 
					!vis[nr][nc] and mat[nr][nc] ==1){
					vis[nr][nc] = 1;
					q.push({nr, nc});
				}
			}	
		}
	}
}

void DFS(int r, int c, vector<vector<int>> &mat, vector<vector<bool>> &vis){
	vis[r][c] = 1;
	for(int i=-1;i<=1;i++){
		for(int j=-1;j<=1;j++){
			int nr = i + r;
			int nc = j + c;
			if(nr>=0 and nr<mat.size() and 
				nc>=0 and nc<mat[0].size() and 
				!vis[nr][nc] and mat[nr][nc] ==1){
				vis[nr][nc] = 1;
				DFS(nr, nc, mat, vis);	
			}
		}	
	}
}

int NoOfIslands(vector<vector<int>> &mat, vector<vector<bool>> &vis){
	int count{0};
	
	for(int r=0;r<mat.size();r++){
		for(int c =0;c<mat[0].size();c++){
			if(!vis[r][c] and mat[r][c] == 1){
				count++;
				BFS(r, c, mat, vis);
				// DFS(r, c, mat, vis);
			}
		}
	}
	return count;
}


int main(){
	vector<vector<int>> mat =
	{{1, 1, 0, 0, 0},
    {0, 1, 0, 0, 1},
    {1, 0, 0, 1, 1},
    {0, 0, 0, 0, 0},
    {1, 0, 1, 0, 0}};
	// Output: 4

    vector<vector<bool>> vis (mat.size(), vector<bool> (mat[0].size(), 0));
    cout<<NoOfIslands(mat, vis);
}