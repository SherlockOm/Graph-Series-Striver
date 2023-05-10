//https://leetcode.com/problems/accounts-merge/
//https://practice.geeksforgeeks.org/problems/merging-details/1
#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

class DisjointSet{
	vector<int> parent, size;
public: 
	DisjointSet(int V ){
		parent.resize(V+1);
		size.resize(V+1,1);
		for(int i=0;i<=V;i++)
			parent[i] = i;
	}
	int findUltParent(int n){
		if(n == parent[n])return n;
		return parent[n] = findUltParent(parent[n]);
	}

	void unionBySize(int u, int v){
		int ultU = findUltParent(u);
		int ultV = findUltParent(v);
		if(ultU == ultV )return;
		if(size[ultV] > size[ultU]){
			size[ultV]+= size[ultU];
			parent[ultU] = ultV;
		}
		else {
			size[ultU]+= size[ultV];
			parent[ultV] = ultU;
		}
	}
};


vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
	int n= accounts.size();
	DisjointSet ds(n);

	unordered_map<string, int > mails;
	for(int i=0;i<n;i++){
		for(int j=1;j<accounts[i].size();j++){
			string mail = accounts[i][j];
			if(mails.find(mail) == mails.end()){
				mails[mail]=i;
			}
			else {
				ds.unionBySize(mails[mail], i);
			}
		}
	}

	vector<string> mergedMail[n];
	for(auto p : mails){
		string mail = p.first;
		int node = p.second;

		mergedMail[ds.findUltParent(node)].push_back(mail);
	}

	vector<vector<string>> ans;

	for(int i=0;i<n;i++){
		if(mergedMail[i].size()==0)continue;
		vector<string>temp = {accounts[i][0]};
		sort(mergedMail[i].begin(), mergedMail[i].end());
		temp.insert(temp.end(), mergedMail[i].begin(), mergedMail[i].end());
		ans.push_back(temp);
	}

	return ans;
}


int main(){
	vector<vector<string>> accounts = {{"John","johnsmith@mail.com","john_newyork@mail.com"},
		{"John","johnsmith@mail.com","john00@mail.com"},
		{"Mary","mary@mail.com"},
		{"John","johnnybravo@mail.com"}};

	auto ans = accountsMerge(accounts);
	for(auto v : ans){
		for(auto e : v)cout<<e<<" ";
		cout<<endl;
	}
}