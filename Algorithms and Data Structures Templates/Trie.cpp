#include <bits/stdc++.h>
using namespace std;

struct Trie {
	bool isLeaf; //stores if a word ends at node
	unordered_map<char, Trie*> map;
};

Trie* head = nullptr;

Trie* getNewTrieNode() {
	Trie* node = new Trie;
	node->isLeaf = false;
	return node;
}

//Time Complexity: O(n), where n is the length of the word
void ins(Trie*& head, char* str) {
    if (head == nullptr)
        head = getNewTrieNode();

	Trie* curr = head;
	while (*str) {
		if (curr -> map.find(*str) == curr -> map.end())
            curr->map[*str] = getNewTrieNode();

		curr = curr->map[*str];
		str++;
	}
	curr->isLeaf = true;
}

//Time Complexity: O(n), where n is the length of the word
bool srch(Trie* head, char* str) {
    if (head == nullptr)
        return false;

    Trie* curr = head;
    while (*str) {
        curr = curr->map[*str];
        if (curr == nullptr)
            return false;
        str++;
    }
    return curr->isLeaf;
}

bool haveChildren(Trie const* curr) {
	for (auto it : curr->map)
		if (it.second != nullptr)
			return true;
	return false;
}

//Time Complexity: O(n), where n is the length of the word
bool del(Trie*& curr, char* str) {
	if (curr == nullptr) return false;
	if (*str) {
		if (curr != nullptr &&  curr -> map.find(*str) != curr -> map.end() &&
			del(curr->map[*str], str + 1) && curr->isLeaf == false) {
		    if (!haveChildren(curr)) {
				curr = nullptr;
				return true;
			}
			else {
				return false;
			}
		}
	}

	if (*str == '\0' && curr->isLeaf) {
		if (!haveChildren(curr)) {
			curr = nullptr;
			return true;
		}
		else {
			curr->isLeaf = false;
			return false;
		}
	}
	return false;
}

void driver(){
	ins(head, "hello");
	srch(head, "hello");
	del(head, "hello");
}