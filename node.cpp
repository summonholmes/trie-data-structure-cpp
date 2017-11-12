#include <iostream>
#include "node.h"

node::node()
{
    value = 0;
    for (int i=0;i<26;i++)
    {
        children[i] = NULL;
    }
}
node::node(char Letter)
        : node_char(Letter){
    for (int i=0;i<26;i++)
    {
        children[i] = NULL;
    }
}

