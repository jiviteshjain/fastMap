//
//  trie.hpp
//  data_structures
//
//  Created by Shashank Gupta on 31/10/19.
//  Copyright © 2019 Shashank Gupta. All rights reserved.
//

#ifndef trie_h
#define trie_h

#include <iostream>
#include <map>
#include <memory>
using namespace std;

struct TrieNode {
    map<char, unique_ptr<TrieNode>> children;
    bool isLeaf;
};

class Trie {
    unique_ptr<TrieNode> root;
public:
    Trie();
    void insert(const string& word);
    bool startsWith(const string& word); // returns true if this string matches with prefix of any string in trie
    bool search(const string& word); // returns true only if complete string matches
};

struct Slice{
    uint8_t size;
    char*   data;
};

struct CompressedTrieNode {
    map<char, unique_ptr<CompressedTrieNode> > children;
    string edgelabel;
    bool isLeaf;
    int num_leafs;
    CompressedTrieNode* parent;
    unique_ptr<Slice> value;
    CompressedTrieNode() : num_leafs(0){};
};

class CompressedTrie {
    unique_ptr<CompressedTrieNode> root;
    void inc(CompressedTrieNode* curr_node, const int& val);
public:
    CompressedTrie();
    bool insert(const Slice& key, const Slice& value);
    Slice* search(const Slice& key) const;
    bool del(const Slice& key);
    string search(const int& N);
    bool startsWith(const string& word) const;
};

#endif /* trie_h */
