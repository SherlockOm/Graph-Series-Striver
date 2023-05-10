//Question : https://www.geeksforgeeks.org/given-matrix-o-x-replace-o-x-surrounded-x/
#include<iostream>
#include<vector>
using namespace std;

void DFS(int ix[], int iy[], int r, int c, vector<vector<char>> &mat, vector<vector<bool>> &vis){
	vis[r][c] =1;
	for(int i=0;i<4;i++){
		int nr = r + ix[i];
		int nc = c + iy[i];
		if(nr>=0 and nc>=0 and
		   nr<mat.size() and nc<mat[0].size() and
		   !vis[nr][nc] and mat[nr][nc] == '0')
			DFS(ix, iy, nr, nc, mat, vis);
	}
}

void surrByX(vector<vector<char>> &mat){
	int n = mat.size();
	int m = mat[0].size();

	vector<vector<bool>> vis (mat.size(),vector<bool> (mat[0].size(), 0));
	int ix[] = {0,0,1,-1};
	int iy[] = {1,-1,0,0};

	for(int i=0;i<m;i++){
		if(!vis[0][i] and mat[0][i] == '0')
			DFS(ix, iy, 0, i, mat, vis);
		if(!vis[n-1][i] and mat[n-1][i] == '0')
			DFS(ix, iy, n-1, i, mat, vis);
	}
	for(int i=0;i<n;i++){
		if(!vis[i][0] and mat[i][0] == '0')
			DFS(ix, iy, i, 0, mat, vis);
		if(!vis[i][m-1] and mat[i][m-1] == '0')
			DFS(ix, iy, i, m-1, mat, vis);
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(!vis[i][j] and mat[i][j]=='0')
				mat[i][j] = 'X';
		}
	}
}

int main(){
	// vector<vector<char>> mat2 = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]];
	vector<vector<char>> mat = {
		{'X','X','X','X'},
		{'X','0','0','X'},
		{'X','X','0','X'},
		{'X','0','X','X'},
	};
	vector<vector<char>> ans (mat.size(),vector<char> (mat[0].size()));
	surrByX(mat);
	for(auto v : mat){
		for(auto e : v)
			cout<<e<<" ";
		cout<<endl;
	}
}