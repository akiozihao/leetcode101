//
// Created by akio on 2021/1/25.
//
#include <string>

using namespace std;

class TrieNode {
public:
    TrieNode *childNode[26];
    bool isVal;

    TrieNode() : isVal(false) {
        for (int i = 0; i < 26; ++i) {
            childNode[i] = nullptr;
        }
    }
};

class Trie {
    TrieNode *root;
public:
    Trie() : root(new TrieNode()) {}

    void insert(string word) {
        TrieNode *node = root;
        for (char i : word) {
            if (!node->childNode[i - 'a']) {
                node->childNode[i - 'a'] = new TrieNode();
            }
            node = node->childNode[i - 'a'];
        }
        node->isVal = true;
    }

    bool search(string word) {
        TrieNode *node = root;
        for (char i:word) {
            if (!node)
                break;
            node = node->childNode[i - 'a'];
        }
        return node ? node->isVal : false;
    }

    bool startsWith(string prefix) {
        TrieNode *node = root;
        for (char i:prefix) {
            if (!node)
                break;
            node = node->childNode[i - 'a'];
        }
        return node;
    }
};