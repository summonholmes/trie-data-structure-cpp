#include <iostream>
#include <fstream>

using namespace std;

class Node
{
public:
    int value;
    Node* children[26];
    Node* pNext;
    char node_char;

    Node()
    {
        value = 0;
        for (int i=0;i<26;i++)
        {
            children[i] = NULL;
        }
    }
    Node(char Letter)
            : node_char(Letter){
        for (int i=0;i<26;i++)
        {
            children[i] = NULL;
        }
    }
    ~Node(){};
};

class Trie
{
    friend class Node;
private:
    Node* root;
    int Counter;
public:
    Trie()
    {
        root = new Node();
        Counter = 0;
    }
    ~Trie(){};
    
    void import_txt()
{
	int Counter = 0;
	string term;

    ifstream get_file("Dictionary.txt");
    
    if(!get_file)
	{
        cout<< "Couldn't open file" <<endl;
        return;
	}     

    while(!get_file.eof()) 
	{
        getline(get_file, term);
        //cout << term << "\n";
    	insert(term);
        Counter++;
        
        
        if(Counter >= 28102) 
		{
			break;
    	}
    }
    
   	cout<< "Inserted " << Counter << " words\n" <<endl;
	get_file.close();
}


    void insert(string term)
    {
        Node *p = root;
        long int len = term.size();
        for (int x = 0; x < len; x++)
        {
            int i = term[x] - 'a';
            //cout << i << endl;
            if (i < 0)
            {
            	cout << "Term " << term << " cannot be inserted.  No numbers or symbols allowed!" << endl;
            	return;
            }

            if (!p->children[i])
            {
                p->children[i] = new Node(term[x]);
            }
            p = p->children[i];
        }
        Counter++;
        p->value = Counter;
    }

    bool search(string key)
    {
        Node *p = root;
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

    bool get_prefix(string prefix) {
        Node *p = root;
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

    void dfs (Node* p, string prefix)
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

    void dfs2 (Node* p, string prefix)
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
};

int main ()
{
    Trie trie;
    string get_String;
    trie.import_txt();
    

    cout << "What do you want to search? ";
    cin >> get_String;

    trie.search(get_String);
    trie.get_prefix(get_String);
    
    cin.get();
    return 0;
}


