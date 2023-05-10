//Question : https://practice.geeksforgeeks.org/problems/implementing-floyd-warshall2042/1

#include<iostream>
#include<vector>
#include<climits>
using namespace std;

//only returns distacne matrix
void shortest_distance(vector<vector<int>>&matrix){
    int v = matrix.size();
    for(int via = 0;via<v;via++){
    	for(int r =0;r<v;r++){
    		for(int c = 0;c<v;c++){
    			if(matrix[r][via]!=-1 and matrix[via][c]!=-1){
    				if(matrix[r][c] > matrix[r][via] + matrix[via][c])
    					matrix[r][c] = matrix[r][via] + matrix[via][c];
    			}
    		}
    	}
    }
}

//with negative cycle detection
void floydWarshall(vector<vector<int>>&matrix){
    int v = matrix.size();

    //if -1 denotes that there is not path from u to v
    for(int r =0;r<v;r++){
		for(int c = 0;c<v;c++){
			if(matrix[r][c] == -1)
				matrix[r][c] = INT_MAX;
			if(r==c)matrix[r][c] = 0;
		}
	}

    //only this loop is enough to calculate distance matrix
    //others are for detecting negative cycles
    for(int via = 0;via<v;via++){
    	for(int r =0;r<v;r++){
    		for(int c = 0;c<v;c++){
    			if(matrix[r][via]!=-1 and matrix[via][c]!=-1){
    				if(matrix[r][c] > matrix[r][via] + matrix[via][c])
    					matrix[r][c] = matrix[r][via] + matrix[via][c];
    			}
    		}
    	}
    }

    //detect -ve cycles
    for(int i=0;i<v;i++){
    	if(matrix[i][i] < 0)
    		return {-1};
    }

    //if -1 denotes that there is not path from u to v 
    for(int i=0;i<v;i++){
    	for(int j=0;j<v;j++){
    		if(matrix[i][j] == 1e9)
    			matrix[i][j] = -1;
    	}
    }
}

int main(){
	vector<vector<int>> matrix = {{0,1,43},{1,0,6},{-1,-1,0}};
	shortest_distance(matrix);
}