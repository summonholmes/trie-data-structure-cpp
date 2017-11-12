#ifndef TRIE_H
#define TRIE_H
#include"node.h"
#include<iostream>

using namespace std;

class trie
{
    friend class node;
private:
    node* root;
    int Counter;
public:
    trie();
    ~trie();

    void get_file();

    void insert(string);

    bool search(string);

    bool Prefix(string);

    void dfs (node*, string);

    void dfs2 (node*, string);

};
#endif // TRIE_H
