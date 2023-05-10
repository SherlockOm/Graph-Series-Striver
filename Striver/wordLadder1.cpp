#include<iostream>
#include<vector>
#include<unordered_set>
#include<unordered_map>
#include<queue>
#include<utility>
#include<climits>
#include<algorithm>
using namespace std;

//word ladder I
//https://practice.geeksforgeeks.org/problems/word-ladder/1/
int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
	unordered_set<string> s(wordList.begin(), wordList.end());
	s.erase(beginWord);

	queue<pair<string, int>> q;
	q.push({beginWord, 1});

	while(!q.empty()){
		auto p = q.front();
		string word = p.first;
		int size = p.second;
		q.pop();

		if(word == endWord)
			return size;
		for(int i=0;i<word.size();i++){
			char org =word[i];
			for(char ch= 'a';ch<='z';ch++){
				word[i] = ch;
				if(s.find(word)!=s.end()){
					s.erase(word);
					q.push({word, size+1});
				}
			}
			word[i] = org;
		}
	}
	return 0;
}


//word ladder II
//https://practice.geeksforgeeks.org/problems/word-ladder-ii/1
vector<vector<string>> findSequences(string beginWord, string endWord,
 vector<string>& wordList) {
    vector<vector<string>> ans;
    unordered_set<string> s(wordList.begin(), wordList.end());
	s.erase(beginWord);

	queue<vector<string>> q;
	q.push({beginWord});

	int level{0};
	while(!q.empty()){
		
		vector<string> v = q.front();
		string word = v[v.size() -1]; 
		q.pop();

		if(word == endWord ){
			if(ans.size()==0 ){
				level = v.size();
				ans.push_back(v);
			}
			else if(v.size() == level)
				ans.push_back(v);
			else return ans;
		}
		for(int i=0;i<word.size();i++){
			char org =word[i];
			for(char ch= 'a';ch<='z';ch++){
				word[i] = ch;
				if(s.find(word)!=s.end() and ch!=org){
					vector<string> newVec(v.begin(), v.end());
					newVec.push_back(word);
					q.push(newVec);
				}
			}
			word[i] = org;
			s.erase(word);
		}
	}
	return ans;
}

//==========================================================================================================
//optimized word ladder II
void DFS(string begin, string word, unordered_map<string, int> &m,
vector<string> &seq, vector<vector<string>> &ans, int sz){
	seq.push_back(word);
	if(begin == word){
		reverse(seq.begin(), seq.end());
		ans.push_back(seq);
		reverse(seq.begin(), seq.end());
		return ;
	}
	int steps = m[word];
	for(int i=0;i<sz;i++){
		char org = word[i];
		for(char ch = 'a';ch<='z';ch++){
			word[i] = ch;
			if(m[word] and m[word] == steps - 1){
				DFS(begin, word, m, seq, ans, sz);
				seq.pop_back();
			}
		}
		word[i] = org;
	}
}

vector<vector<string>> findSequencesOpt(string beginWord, string endWord,
 vector<string>& wordList) {
    vector<vector<string>> ans;
    unordered_set<string> s(wordList.begin(), wordList.end());
	s.erase(beginWord);

	queue<string> q;
	q.push(beginWord);

	unordered_map<string, int> m;
	m[beginWord] = 1;

	while(!q.empty()){
		string word= q.front();
		q.pop();
		if(word == endWord)break;
		int steps = m[word];

		for(int i=0;i<word.size();i++){
			char org =word[i];
			for(char ch= 'a';ch<='z';ch++){
				word[i] = ch;
				if(s.find(word)!=s.end() and ch!=org){
					q.push(word);
					m[word] = steps + 1;
					s.erase(word);
				}
			}
			word[i] = org;
		}
	}
	if(m.find(endWord)!=m.end()){
		vector<string> seq;
		DFS(beginWord, endWord, m, seq, ans, endWord.size());
	}
	return ans;
}


int main(){
	string beginWord = "hit", endWord = "cog";
	vector<string> wordList = {"hot","dot","dog","lot","cog"};
	vector<string> wordList2 = {"hot","dot","dog","lot","log","cog"};
	// cout<<ladderLength(beginWord, endWord, wordList2)<<endl;

	// vector<vector<string>> ans = findSequences(beginWord, endWord, wordList2);	
	
	vector<vector<string>> ans = findSequencesOpt(beginWord, endWord, wordList2);	
	
	for(auto v : ans){
		for(auto e : v)cout<<e<<" ";
		cout<<endl;
	}
}