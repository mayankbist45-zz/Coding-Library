#include <bits/stdc++.h>

using namespace std;

class node {
public:
    map<char, node *> h;
    bool is_terminal = false;
};

class Trie {
    node *root;
public:
    Trie() { root = new node(); }

    void addWord(string &word) {
        node *temp = root;
        for (char ch : word)
            if (temp->h.count(ch) == 0) {
                node *child = new node();
                temp->h[ch] = child;
                temp = child;
            } else
                temp = temp->h[ch];
        temp->is_terminal = true;
    }

    bool isPresent(string &word) {
        node *temp = root;
        for (char ch : word)
            if (temp->h.count(ch))
                temp = temp->h[ch];
            else
                return false;
        return temp->is_terminal;
    }
};

int main() {
    vector<string> word = {"Mayank", "Superman", "Maya", "News", "Aman", "Ravi"};
    Trie t;
    for (auto &x:word)
        t.addWord(x);

    string s;
    cin >> s;

    if (t.isPresent(s)) {
        cout << "Found";
    } else
        cout << "Not Found";
    return 0;
}
