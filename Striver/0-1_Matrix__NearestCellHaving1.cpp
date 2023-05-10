#include<iostream>
#include<queue>
#include<vector>
using namespace std;

void NCHO(vector<vector<int>> &mat, vector<vector<int>> &ans){
	vector<vector<bool>> vis(mat.size(), vector<bool> (mat[0].size(),0)); 
	queue<vector<int>> q;
	int n = mat.size();
	int m = mat[0].size();

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++)
			if(mat[i][j]==1){
				vis[i][j] = 1;
				q.push({i,j,0});
			}
	}

	int ix[] = {0,0,1,-1};
	int iy[] = {1,-1,0,0};
	while(!q.empty()){
		auto it = q.front();
		int r = it[0];
		int c = it[1];
		int d = it[2];
		ans[r][c] = d;
		q.pop();

		for(int i=0;i<4;i++){
			int nr = r + ix[i];
			int nc = c + iy[i];

			if(nr>=0 and nc>= 0 and 
			   nr<n and nc<m and !vis[nr][nc]){
				q.push({nr, nc, d +1});
				vis[nr][nc] = 1;
			}
		}
	}
}

int main(){
	vector<vector<int>> mat = {
				{0, 0, 0, 1},
				{0, 0, 1, 1},
				{0, 1, 1, 0}
	};
	vector<vector<int>> ans(mat.size(), vector<int> (mat[0].size()));

	NCHO(mat,ans);
	for(auto v : ans){
		for(auto e : v)
			cout<<e<<" ";
		cout<<endl;
	}
	cout<<"hemlo";
}