
#include <bits/stdc++.h>

using namespace std;

#define hashmap unordered_map<char , node* > 

class node{

	public:
	char data;
	hashmap h;
	bool is_terminal;

	node(char d){
		data = d;
		is_terminal = false;
	}
};

class Trie{
	node *root;

public:
	Trie(){
		root = new node('\0');
	}

	//Insertion 
	void addWord(char * word){

		node *temp = root;
		for(int i=0;word[i]!='\0';i++){
			 char ch = word[i];
			 if(temp->h.count(ch)==0){
			     node *child = new node(ch);
			     temp->h[ch] = child;
			     temp = child; 
			 }
			 else
			 	temp = temp->h[ch];
		}
		temp->is_terminal = true;
	}

	//Lookup
	bool isPresent(char*word){
		node *temp = root;

		for (int i = 0; word[i]!='\0' ;  ++i)
		{
			char ch = word[i];
			if(temp->h.count(ch)){
				temp = temp->h[ch];
			}
			else
				return false;
		}
		return temp->is_terminal;
	}
};

int main() {

	char word[][20 ] = {"Mayank","Superman","Maya","News","Aman","Ravi"};
	Trie t;

	for (int i = 0; i < 6; ++i)
	{		
		t.addWord(word[i]);
	}

	char search[100];
	cin.getline(search, 100);

	if(t.isPresent(search)){
		cout<<"Found";
	}
	else
		cout<<"Not Found";
	return 0;
}