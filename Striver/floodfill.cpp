//Question : https://www.geeksforgeeks.org/flood-fill-algorithm/

#include<iostream>
#include<vector>
#include<queue>
#include<utility>
using namespace std;
// sr, sc, color, initialColor,ix, iy mat

void BFS(int sr, int sc, int color, int initialColor, 
	int ix[], int iy[], vector<vector<int>> &mat,
	vector<vector<bool>> &vis){
	queue<pair<int, int >> q;
	q.push({sr,sc});
	while(!q.empty()){
		int r = q.front().first;
		int c = q.front().second;
		q.pop();
		vis[r][c] = 1;
		for(int i=0;i<4;i++){
			int nr = r + ix[i];
			int nc = c + iy[i];
			if(nc>=0 and nc<mat.size() and 
			   nr>=0 and nr<mat[0].size() and
			   ix[i]!=iy[i] and mat[nr][nc]==initialColor and
			   !vis[nr][nc]){
				q.push({nr, nc});
				mat[nr][nc] = color;
			}
		
		}
	}
}
void DFS(int sr, int sc, int color, int initialColor,
 int ix[], int iy[], vector<vector<int>> & mat, 
  vector<vector<int>> &vis){
	vis[sr][sc] =1;
	mat[sr][sc] = color;
	for(int i=0;i<4;i++){
		int nr = sr + ix[i];
		int nc = sc + iy[i];

		if(nr>=0 and nr<mat.size() and 
		   nc>=0 and nc<mat[0].size() and 
		   mat[nr][nc]==initialColor)
			DFS(nr,nc,color, initialColor,ix, iy, mat, vis);
	}
}
void floodFill(int sr, int sc, int color, vector<vector<int>> &mat){
	int initialColor = mat[sr][sc];
	mat[sr][sc] = color;
	int ix[] = {0,1,-1,0};
	int iy[] = {1,0,0,-1};
	vector<vector<bool>> vis(mat.size(), vector<bool>(mat[0].size(),0));
	BFS(sr, sc, color, initialColor,ix, iy, mat, vis);
	// DFS(sr,sc,color, initialColor, ix, iy, mat);

}


int main(){
	vector<vector<int>> mat {
    {1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 0, 2},
    {1, 0, 0, 1, 1, 0, 1, 1},
    {1, 2, 2, 2, 2, 0, 1, 0},
    {1, 1, 1, 2, 2, 0, 1, 0},
    {1, 1, 1, 2, 2, 2, 2, 0},
    {1, 1, 1, 1, 1, 2, 1, 1},
    {1, 1, 1, 1, 1, 2, 2, 1}};

    floodFill(4, 4, 2, mat);

    for(auto v : mat){
    	for(auto e : v)
    		cout<<e<<" ";
    	cout<<endl;
    }
    cout<<"asdf";
}