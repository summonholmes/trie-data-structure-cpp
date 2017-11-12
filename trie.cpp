#include "trie.h"
#include <fstream>


trie::trie()
{
    root = new node();
    Counter = 0;
}

trie::~trie(){};

void trie::get_file()
{
    int Counter = 0;
    string term;

    ifstream get_file("C:\\Users\\Doritos\\Desktop\\Dictionary.txt");//Add your dictionary location here

    if(!get_file)
    {
        cout<< "Couldn't open file" <<endl;
        return;
    }

    while(!get_file.eof())
    {
        getline(get_file, term);
        insert(term);
        Counter++;


        if(Counter >= 28102)
        {
            break;
        }
    }

    cout<< "All words successfully entered.\n" <<endl;
    get_file.close();
}


void trie::insert(string term)
{
    node *p = root;
    long int len = term.size();
    for (int x = 0; x < len; x++)
    {
        int i = term[x] - 'a';
        if(i<0)
        {
            //No numbers or symbols allowed.
            return;
        }
        if (!p->children[i])
        {
            p->children[i] = new node(term[x]);
        }
        p = p->children[i];
    }
    Counter++;
    p->value = Counter;
}

bool trie::search(string key)
{
    node *p = root;
    long int len = key.size();
    for (int x = 0; x < len; x++)
    {
        int i = key[x] - 'a';
        if (p->children[i])
        {
            p = p->children[i];
        }
        else
        {
            cout << "String not found!\n" << endl;
            return false;
        }
    }
    cout << "String " << key << " successfully found\n" << endl;
    if (p->value != 0)
    {
        return true;
    }
    else
    {
        return false;
    }

}
bool trie::Prefix(string prefix) {
    node *p = root;
    long int len = prefix.size();
    cout << "Prefix \"" << prefix << "\" strings found:" << endl;
    for (int x = 0; x < len; x++) {
        int i = prefix[x] - 'a';
        if (p->children[i]) {
            p = p->children[i];
        }

        else {
            cout << "Prefix invalid!" << endl;
            return false;
        }
    }
    dfs(p, prefix);
    return true;
}

void trie::dfs (node* p, string prefix)
{
    int y = 0;
    while (y<26)
    {
        if (p->children[y] != NULL)
        {
            dfs2(p->children[y], prefix);
        }
        y++;
    }
    cout << endl;
}

void trie::dfs2 (node* p, string prefix)
{

    cout << prefix;
    cout << p->node_char;

    while (p!=NULL)
    {
        int y = 0;
        while (p->children[y] == NULL && y<26)
        {
            y++;
        }
        p=p->children[y];

        if (p != NULL)
        {
            cout << p->node_char;
        }
    }
    cout << endl;
}


