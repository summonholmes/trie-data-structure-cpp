#include <iostream>
#include "trie.h"

using namespace std;

int main ()
{
    trie t;

    t.get_file();

    string get_String;

    cout << "What do you want to search? ";
    cin >> get_String;

    t.search(get_String);
    t.Prefix(get_String);

    cin.get();
    return 0;
}

