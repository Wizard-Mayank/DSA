#include <iostream>
using namespace std;

class TrieNode
{
public:
    char data;
    TrieNode *children[26];
    bool isTerminal;

    TrieNode(char ch)
    {
        data = ch;
        for (int i = 0; i < 26; ++i)
        {
            children[i] = nullptr;
        }
        isTerminal = false;
    }
};

class Trie
{
private:
    void insertUtil(TrieNode *node, string word)
    {
        if (word.size() == 0)
        {
            node->isTerminal = true;
            return;
        }

        int index = word[0] - 'a';
        TrieNode *child;

        // present
        if (node->children[index] != nullptr)
        {
            child = node->children[index];
        }

        // absent
        else
        {
            child = new TrieNode(word[0]);
            node->children[index] = child;
        }

        // recursion
        insertUtil(child, word.substr(1));
    }

    bool searchUtil(TrieNode *node, string word)
    {
        // base case
        if (word.size() == 0)
        {
            return node->isTerminal;
        }

        int index = word[0] - 'a';
        TrieNode *child = node->children[index];

        // recursion
        if (child != nullptr)
            return searchUtil(child, word.substr(1));
        else
            return false;
    }

    bool startsWithUtil(TrieNode *node, string word)
    {

        // base case
        if (word.size() == 0)
            return !(node->isTerminal);

        int index = word[0] - 'a';
        TrieNode *child = node->children[index];

        // recursion
        if (child != nullptr)
            return startsWithUtil(child, word.substr(1));
    }

public:
    TrieNode *root;

    Trie()
    {
        // Constructor
        root = new TrieNode('\0');
    }

    void insert(string word)
    {
        insertUtil(root, word);
    }

    bool search(string word)
    {
        return searchUtil(root, word);
    }

    bool startsWith(string word)
    {
        return startsWithUtil(root, word);
    }
};

int main()
{
    Trie *t = new Trie();

    t->insert("abcd"); // insert
    t->insert("dog");  // insert

    cout << "\nsearch" << endl;
    cout << (t->search("abcd") ? "Found\n" : "Not Found\n"); // Found
    cout << (t->search("ab") ? "Found\n" : "Not Found\n");   // Not Found
    cout << (t->search("dog") ? "Found\n" : "Not Found\n");  // Found
    cout << (t->search("do") ? "Found\n" : "Not Found\n");   // Not Found
    cout << (t->search("cat") ? "Found\n" : "Not Found\n");  // Not Found

    cout << "\nstartsWith" << endl;
    cout << (t->startsWith("ab") ? "Found\n" : "Not Found\n");  // Not Found
    cout << (t->startsWith("d") ? "Found\n" : "Not Found\n");   // Not Found
    cout << (t->startsWith("dog") ? "Found\n" : "Not Found\n"); // Not Found

    return 0;
}