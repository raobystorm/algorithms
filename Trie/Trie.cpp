// Trie.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
using namespace std;

#define MAX 26
class TrieNode {
public:
	bool end;
	TrieNode* children[MAX];
	// Initialize your data structure here.
	TrieNode() {
		end = false;
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
			}
			else{
				ptr->children[c - 'a'] = new TrieNode();
				ptr = ptr->children[c - 'a'];
			}
		}
		ptr->end = true;
	}

	// Returns if the word is in the trie.
	bool search(string key) {
		char c;
		TrieNode* ptr = root;
		for (int i = 0; i < key.size(); i++){
			c = key[i];
			if (ptr->children[c - 'a'] == nullptr) return false;
			else{
				ptr = ptr->children[c - 'a'];
			}
		}
		return ptr->end;
	}

	// Returns if there is any word in the trie
	// that starts with the given prefix.
	bool startsWith(string prefix) {
		char c;
		TrieNode* ptr = root;
		for (int i = 0; i < prefix.size(); i++){
			c = prefix[i];
			if (ptr->children[c - 'a'] == nullptr) return false;
			else{
				ptr = ptr->children[c - 'a'];
			}
		}
		return true;
	}

private:
	TrieNode* root;
};


int _tmain(int argc, _TCHAR* argv[])
{
	Trie trie; bool res;
	trie.insert("something");
	res = trie.search("some");
	res = trie.startsWith("some");
	return 0;
}

