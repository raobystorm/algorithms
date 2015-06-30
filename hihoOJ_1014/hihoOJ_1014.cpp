// hihoOJ_1014.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

#define MAX 26
class TrieNode {
public:
	bool end;
	int cnt;
	TrieNode* children[MAX];
	// Initialize your data structure here.
	TrieNode() {
		end = false;
		cnt = 0;
		for (int i = 0; i < MAX; i++)
			children[i] = nullptr;
	}
};

class Trie {
public:
	Trie() {
		root = new TrieNode();
	}

	// Inserts a word into the trie.
	void insert(string s) {
		char c;
		TrieNode* ptr = root;
		for (int i = 0; i < s.size(); i++){
			c = s[i];
			if (ptr->children[c - 'a'] != nullptr){
				ptr = ptr->children[c - 'a'];
				(ptr->cnt)++;
			}
			else{
				ptr->children[c - 'a'] = new TrieNode();
				ptr = ptr->children[c - 'a'];
				(ptr->cnt)++;
			}
		}
		ptr->end = true;
	}

	// Returns if the word is in the trie.
	int countPrefix(string prefix) {
		char c;
		TrieNode* ptr = root;
		for (int i = 0; i < prefix.size(); i++){
			c = prefix[i];
			if (ptr->children[c - 'a'] == nullptr) return 0;
			else{
				ptr = ptr->children[c - 'a'];
			}
		}
		return ptr->cnt;
	}

private:
	TrieNode* root;
};


int _tmain(int argc, _TCHAR* argv[])
{
	Trie trie;
	int n, res;
	string tmp;
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> tmp;
		trie.insert(tmp);
	}
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> tmp;
		cout << trie.countPrefix(tmp) << endl;
	}

	return 0;
}
