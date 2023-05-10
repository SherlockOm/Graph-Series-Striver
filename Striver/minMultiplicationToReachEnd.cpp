//Question : https://practice.geeksforgeeks.org/problems/minimum-multiplications-to-reach-end/1
#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;


int minimumMultiplications(vector<int>& arr, int start, int end) {
    vector<int> dist(100000, INT_MAX);
    dist[start] = 0;

    queue<vector<int>> q;
    q.push({0, start});

    while(!q.empty()){
    	auto v = q.front();
    	int curD = v[0];
    	int n = v[1];
    	q.pop();
    	
		if(n == end) return curD;
    	for(auto nbr : arr){
    		int num = (nbr* n) % 100000;
    		if(dist[num] > curD+1 ){
    			dist[num] = curD + 1;
    			q.push({curD + 1, num});
    		}
    	}
    }
    return -1;
}


int main(){
	vector<int> arr = {2, 5, 7};
	cout<<minimumMultiplications(arr, 3, 30);
	cout<<
	"Aasdf";
}