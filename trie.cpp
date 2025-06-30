#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class trie{
    private:
        struct node{
            node *child[26];
            bool isWord;
        };

        node *root;

        node *createnode(){
            node *nd=new node;
            for(int i=0;i<26;i++){
                nd->child[i]=nullptr;
            }
            nd->isWord=false;
            return nd;
        }

    public:
        trie(){
            root=createnode();
        }

        void insert(string str){
            node *temp=root;
            for(char ch:str){
                if(!temp->child[ch-'a']){
                    temp->child[ch-'a']=createnode();
                }
                temp=temp->child[ch-'a'];
            }
            temp->isWord=true;
        }

        bool search(string str){
            node *temp=root;
            for(char ch:str){
                if(!temp->child[ch-'a']){
                   return false;
                }
                temp=temp->child[ch-'a'];
            }
            if(temp->isWord){
                return true;
            }
            return false;
        }

        bool prefixSearch(string pre){
            node *temp=root;
            for(char ch:pre){
                if(!temp->child[ch-'a']){
                    return false;
                }
                temp=temp->child[ch-'a'];
            }
            return true;
        }

        void dfs(node *root,string str){
            if(root->isWord){
                cout << str << endl;
            }
            for(int i=0;i<26;i++){
                if(root->child[i]){
                    dfs(root->child[i],str+char(i+'a'));
                }
            }
        }

        void printFromPrefix(string pre){
            node *temp=root;
            for(char ch:pre){
                if(!temp->child[ch-'a']){
                    cout << "Prefix does not Exist...";
                    return;
                }
                temp=temp->child[ch-'a'];
            }
            dfs(temp,pre);
        }

        void softdelete(string str){
            node *temp=root;
            for(char ch:str){
                if(!temp->child[ch-'a']){
                    cout << "Word does not exist..." << endl;
                    return;
                }
                temp=temp->child[ch-'a'];
            }
            if(temp->isWord){
                temp->isWord=false;
                cout << "Word deleted(soft)..." << endl;
            }
            else{
                cout << "Word does not exist..." << endl;
            }
        }

        bool nochildren(node *root){
            for(int i=0;i<26;i++){
                if(root->child[i]){
                    return false;
                }
            }
            return true;
        }

        bool harddel(node *root,string str,int depth){
            if(!root){  // node does not exist
                return false;
            }
            if(depth==str.size()){ // on reaching last node
                if(!root->isWord){return false;} // ending flag is not marked so it means it is not a valid word in the dictionary
                // if the last node have any children, we cannot delete it
                root->isWord=false; 
                if(nochildren(root)){
                    delete root;
                    root=nullptr;
                    return true;
                }
                return false;
            }
            int i=str[depth]-'a'; // calculate to which node (next char in stirng) we should go to
            if(!root->child[i]){return false;} // if it does not exist, return false
            bool shouldDelete=harddel(root->child[i],str,depth+1);
            if(shouldDelete){
                if(!root->isWord && nochildren(root)){
                    delete root;
                    root=nullptr;
                    return true;
                }
            }
            return false;
        }

        void harddelete(string str){
            if(harddel(root,str,0)){
                cout << "Word deleted (hard)..." << endl;
            }
            else{
                cout << "Word cannot be deleted or does not exist..." << endl;
            }
        }
};

int main(){
    int choice;
    trie *obj=new trie();
    while(true){
        cout << "1. Insert word" << endl;
        cout << "2. Search word" << endl;
        cout << "3. Serach Prefix" << endl;
        cout << "4. Print Prefix" << endl;
        cout << "5. Soft Delete" << endl;
        cout << "6. Hard Delete" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice){
            case 1:{
                string str;
                cout << "Enter string to insert: ";
                cin >> str;
                obj->insert(str);
                cout << "String added to trie..." << endl;
                break;
            }
            case 2:{
                string str;
                cout << "Enter string to Search: ";
                cin >> str;
                if(obj->search(str)){
                    cout << "The word is present in the Trie..." << endl;
                }
                else{
                    cout << "The word is NOT present in the Trie..." << endl;
                }
                break;
            }
            case 3:{
                string str;
                cout << "Enter Prefix to Search: ";
                cin >> str;
                if(obj->prefixSearch(str)){
                    cout << "The prefix is present in the Trie..." <<endl;
                }
                else{
                    cout << "The prefix is NOT present in the Trie..." <<endl;
                }
                break;
            }
            case 4:{
                string str;
                cout << "Enter Prefix to print: ";
                cin >> str;
                cout << "Word starting with the prefix: " << endl;
                obj->printFromPrefix(str);
                break;
            }
            case 5:{
                string str;
                cout << "Enter String for soft deletion: ";
                cin >> str;
                obj->softdelete(str);
                break;
            }
            case 6:{
                string str;
                cout << "Enter String for hard deletion: ";
                cin >> str;
                obj->harddelete(str);
                break;
            }
            case 7:{
                cout << "Program Ended..." << endl;
                exit(0);
            }
            default:{
                cout << "Invalid option..." << endl;
                break;
            }
        }
    }
    return 0;
}