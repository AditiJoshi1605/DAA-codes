//memory exceed of large strings 
#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct node {
    //bool isWord;
    node* child[26];
};

node* newnode() {
    node* temp = new node();
    //temp->isWord = false;
    for (int i = 0; i < 26; i++) {
        temp->child[i] = nullptr;
    }
    return temp;
}

void insert(node* root, string str) {
    for (char ch : str) {
        if (root->child[ch - 'a'] == nullptr) {
            root->child[ch - 'a'] = newnode();
        }
        root = root->child[ch - 'a'];
    }
    //root->isWord = true;  
}

void search(node* root, string substr) {
    for (char ch : substr) {
        if (root->child[ch - 'a'] == nullptr) {
            cout << "NO" << endl;
            return;
        }
        root = root->child[ch - 'a'];
    }
    cout << "YES" << endl;
}

int main() {
    string str;
    cin >> str;
    int k;
    cin >> k;
    node* root = newnode();
    for (int i = 0; i < str.length(); i++) {
        insert(root, str.substr(i));
    }
    while (k--) {
        string substr;
        cin >> substr;

        if (substr.length() > str.length()) {
            cout << "NO" << endl;
        } else {
            search(root, substr);
        }
    }
    return 0;
}
