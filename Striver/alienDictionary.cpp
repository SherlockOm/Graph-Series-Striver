//Questions : https://www.geeksforgeeks.org/given-sorted-dictionary-find-precedence-characters/
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void makeGraph(int N, string dict[], vector<vector<int>> &graph){
	for(int i=0;i<N-1;i++){
		string s1 = dict[i];
		string s2 = dict[i+1];

		int l = min(s1.length(), s2.length());
		for(int j=0;j<l;j++){
			if(s1[j] != s2[j]){
				graph[s1[j] - 'a'].push_back(s2[j] - 'a');
				break;
			}
		}
	}
}

string findOrder(string dict[], int N, int K) {
	string ans = "";
    vector<vector<int>> graph(K);
    makeGraph(N, dict, graph);

    vector<int> inDeg(K, 0);
    for(int i=0;i<K;i++){
    	for(auto nbr : graph[i])inDeg[nbr]++;
    }
	
	queue<int> q;
	for(int i=0;i<K;i++)if(inDeg[i] == 0)q.push(i);

	while(!q.empty()){
		int n= q.front();
		q.pop();
		ans += char('a'  + n);
		for(auto nbr : graph[n]){
			inDeg[nbr] -- ;
			if(inDeg[nbr] == 0)
				q.push(nbr);
		}
	}
    return ans;
}

int main(){
	string dict[] = {"baa","abcd","abca","cab","cad"};
	cout<<findOrder(dict, 5,4);\
}