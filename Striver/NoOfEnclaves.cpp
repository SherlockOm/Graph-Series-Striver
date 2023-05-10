//Question : https://leetcode.com/problems/number-of-enclaves/
//https://practice.geeksforgeeks.org/problems/number-of-enclaves/1
#include<iostream>
#include<vector>
using namespace std;

void DFS(int r, int c, int ix[], int iy[], 
	vector<vector<int>> &mat, vector<vector<bool>> &vis){
	vis[r][c] =1;
	for(int i=0;i<4;i++){
		int nr = r + ix[i];
		int nc = c + iy[i];
		if(nr>=0 and nc>=0 and
		   nr<mat.size() and nc<mat[0].size() and 
		   !vis[nr][nc] and mat[nr][nc]==1)
		   DFS(nr, nc, ix, iy, mat, vis);		
	}
}

int NoOfEnclaves(vector<vector<int>> &mat){
	int n= mat.size();
	int m= mat[0].size();

	int ix[] = {0,0,1,-1};
	int iy[] = {1,-1,0,0};
	vector<vector<bool>> vis(n,vector<bool>(m, 0));
	for(int i=0;i<m;i++){
		if(mat[0][i]==1 and !vis[0][i])
			DFS(0, i, ix, iy, mat, vis);
		if(mat[n-1][i]==1 and !vis[n-1][i])
			DFS(n-1, i, ix, iy, mat, vis);
	}
	for(int i=0;i<n;i++){
		if(mat[i][0]==1 and !vis[i][0])
			DFS(i, 0, ix, iy, mat, vis);
		if(mat[i][m-1]==1 and !vis[i][m-1])
			DFS(i, m-1, ix, iy, mat, vis);
	}
	int count{0};
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(!vis[i][j] and mat[i][j] ==1)
				count++;
		}
	}
	return count;
}


int main(){
	vector<vector<int>> mat = {
		{0,0,0,1},
		{0,0,1,0},
		{0,1,1,0},
		{0,0,0,1}
	};

	cout<<NoOfEnclaves(mat);
}