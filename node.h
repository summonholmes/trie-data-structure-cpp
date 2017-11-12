#ifndef NODE_H
#define NODE_H

class node
{
public:

        int value;
        node* children[26];
        node* pNext;
        char node_char;

        node();
        node(char);
        ~node(){};
};

#endif // NODE_H
