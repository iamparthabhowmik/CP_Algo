/* iamparthabhowmik */
#include<bits/stdc++.h>

using namespace std;

#define py cout<<"YES"<<endl
#define pn cout<<"NO"<<endl


struct Node
{
public:
    Node* links[26];
    bool flag=false;

    bool isPresent(char c){
        return links[c-'a']!=NULL;
    }
    void put(char c, Node* newNode){
        links[c-'a']=newNode;
    }
    Node* get(char c){
        return links[c-'a'];
    }
    void setTrue(){
        flag=true;
    }
    bool getFlag(){
        return flag;
    }
};

class Trie{
public:
    Node* root;
    Trie(){
        root=new Node();
    }
    void insert(string str){
        Node* node=root;
        for(auto it: str){
            if(!node->isPresent(it)){
                node->put(it,new Node());
            }
            node=node->get(it);
        }
        node->setTrue();
    }
    bool search(string str){
        Node* node=root;
        for(auto it: str){
            if(!node->isPresent(it)) return false;
            node=node->get(it);
        }
        return node->getFlag();
    }
    bool startsWith(string str){
        Node* node=root;
        for(auto it: str){
            if(!node->isPresent(it)) return false;
            node=node->get(it);
        }
        return true;
    }
};

int32_t main(){

    Trie dataStructure;

    dataStructure.insert("partha");
    dataStructure.insert("suman");
    dataStructure.insert("parda");
    dataStructure.insert("psuman");

    if(dataStructure.search("suman")) py;
    else pn;
    if(dataStructure.search("partha")) py;
    else pn;
    if(dataStructure.startsWith("parda")) py;
    else pn;
    if(dataStructure.startsWith("psut")) py;
    else pn;


    return 0;
}                            