//Question : https://www.geeksforgeeks.org/minimum-time-required-so-that-all-oranges-become-rotten/

#include<iostream>
#include<vector>
#include<queue>
#include<utility>
using namespace std;

// void BFS(int r, int c, vector<vector<int>> &mat, 
// 		int &fresh, int ix[], int iy[], queue<vector<int>> q){
// 	mat[r][c] = 2;
// 	fresh--;
	
// }

int rotOrange(vector<vector<int>> &mat){
	int time{0};
	int n= mat.size();
	int m = mat[0].size();

	int freshOr{0};
	queue<vector<int>> q;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(mat[i][j] == 1)freshOr++;
			else if(mat[i][j] == 2){
				vector<int> temp = {i, j ,0};
				q.push(temp);
			}
		}
	}
	int ix[] = {0,1,0,-1};
	int iy[] = {1,0,-1,0};
	while(!q.empty()){
		int r = q.front()[0];
		int c = q.front()[1];
		int t = q.front()[2];
		q.pop();
		for(int i=0;i<4;i++){
			int nr = ix[i] + r;
			int nc = iy[i] + c;
			if(nr>=0 and nr<n and
			   nc>=0 and nc<m and
			   mat[nr][nc]==1){
			   	mat[nr][nc] =2;
				vector<int> temp = {nr, nc, t +1};
				q.push(temp);
				freshOr--;
			}
		}
		time = max(time, t);
	}
	if(freshOr!=0)return -1;
	return time;
}

int main(){
	vector<vector<int>> mat = {
		{2, 1, 0, 2, 1},
		{1, 0, 1, 2, 1},
		{1, 0, 0, 2, 1}
	};

	cout<<rotOrange(mat)<<endl;
	for(auto v : mat){
		for(auto e : v)
			cout<<e<<" ";
		cout<<endl;
	}

}