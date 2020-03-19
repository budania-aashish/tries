#include <bits/stdc++.h>
using namespace std;
const int ALPHABATE_SIZE =26;
struct Node
{
	bool isEndOfWord;
	struct Node * children[ALPHABATE_SIZE];//each of type node 
};
struct Node * getParentNode()
{
	struct Node * newnode = new Node();
	newnode->isEndOfWord=false;
	for (int i = 0; i < 26; ++i)
	{
		newnode->children[i]=NULL;
	}
	return newnode;
}
void insert(struct Node *root, string key)
{
	struct Node *tempNode = root;
	//abcd
	for (int i = 0; i < key.size(); ++i)
	 {
	 	int index = (int)(key[i]-'a') ;
	 	if (tempNode->children[index]==NULL)
	 	{
	 		tempNode->children[index]=getParentNode();
	 		tempNode=tempNode->children[index];
	 	}
	 } 
	 tempNode->isEndOfWord=true;
}
bool searchKey(struct Node *root, string key)
{
	struct Node *tempNode= root;
	for (int i = 0; i < key.size(); ++i)
	{
		int index = (int)(key[i]-'a');
		if (tempNode->children[index]==NULL)
		{
			return false;
		}
		tempNode=tempNode->children[index];
	}
	return (tempNode->isEndOfWord&&tempNode!=NULL); 
}
int main(int argc, char const *argv[])
{
	string keys[]={"aabc", "aab", "abcd", "def"};
	int n = sizeof(keys)/sizeof(keys[0]);
	struct Node *root = getParentNode();
	for (int i = 0; i < n; ++i)
	{
		insert(root,keys[i]);
	}
	string s= "aabc";
	cout<<searchKey(root,"aabc")<<endl;
	cout<<searchKey(root,"wxy")<<endl;
	cout<<searchKey(root,"def")<<endl;
	cout<<searchKey(root,"defg")<<endl;
	return 0;
}