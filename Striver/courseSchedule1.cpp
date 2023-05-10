//Question : https://leetcode.com/problems/course-schedule/
//Question : course schedule II : https://www.geeksforgeeks.org/find-the-ordering-of-tasks-from-given-dependencies/
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

bool courseSchedule(int numCourses, vector<vector<int>> &graph){
	vector<vector<int>> adj (numCourses);
	for(auto p : graph){
		adj[p[0]].push_back(p[1]);
	}

	vector<int> inDeg(numCourses, 0);
	for(auto p : graph){
		inDeg[p[1]]++;
	}
	
	queue<int> q;
	for(int i=0;i<numCourses;i++){
		if(inDeg[i]==0)q.push(i);
	}

	int count{0};
	while(!q.empty()){
		int n= q.front();
		q.pop();
		count++;
		for(auto nbr : adj[n]){
			inDeg[nbr] -- ;
			if(inDeg[nbr] == 0)q.push(nbr);
		}
	}	return count == numCourses? 1 : 0;
}

vector<int> courseSchedule2(int numCourses, vector<vector<int>> &graph){
	vector<vector<int>> adj (numCourses);
	for(auto p : graph){
		adj[p[0]].push_back(p[1]);
	}

	vector<int> inDeg(numCourses, 0);
	for(auto p : graph){
		inDeg[p[1]]++;
	}
	
	queue<int> q;
	for(int i=0;i<numCourses;i++){
		if(inDeg[i]==0)q.push(i);
	}

	vector<int> ans;
	while(!q.empty()){
		int n= q.front();
		q.pop();
		ans.push_back(n);
		for(auto nbr : adj[n]){
			inDeg[nbr] -- ;
			if(inDeg[nbr] == 0)q.push(nbr);
		}
	}	
	reverse(ans.begin(), ans.end());
	if(ans.size() != numCourses)ans.clear();
	return ans;
}


int main(){
	vector<vector<int>> prerequisites = {
				 {1, 0},
                 {2, 0},
                 {3, 1},
                 {3, 2}};

    // cout<<courseSchedule(4,prerequisites);
    vector<int> ans = courseSchedule2(4, prerequisites);
    for(auto e : ans)cout<<e<<" ";
}