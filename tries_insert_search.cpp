#include <bits/stdc++.h>
using namespace std;
const int size = 256;
struct Node
{
	bool isEndOfWord;
	struct Node * children[size];
};
struct Node * getNode()
{
	struct Node *temp;
	temp = new Node();
	temp->isEndOfWord= false;
	for(int i=0;i<26;i++)
	{
		temp->children[i]=NULL;
	}
	return temp;
}

void insert(struct Node *root, string key)
{
	struct Node *temp=root;
	for(int i=0;i<key.size();i++)
	{
		int index = (int)(key[i]-'a');
		if (temp->children[index]==NULL)
		{
			temp->children[index]=getNode();
		}
		temp=temp->children[index];
	}
	temp->isEndOfWord=true;
	return ;
}
bool search(struct Node *root, string key)
{
	struct Node *temp=root;
	for(int i=0;i<key.size();i++)
	{
		int index = (int)(key[i]-'a');
		if (temp->children[index]==NULL)
		{
			return false;
		}
		temp=temp->children[index];
	}
	return (temp->isEndOfWord&&temp->children!=NULL);
}

int main(int argc, char const *argv[])
{
	string keys[]={"abCd", "abcd","1234","abc", "abd", "def"};
	int n = sizeof(keys)/sizeof(keys[0]);
	Node *root = getNode();
	for(int i=0;i<n;i++)
	{
		insert(root,keys[i]);
	}
	cout<<search(root,"abCd")<<endl;
	cout<<search(root,"abcd")<<endl;
	cout<<search(root,"1234")<<endl;
	cout<<search(root,"psqr")<<endl;
	cout<<search(root,"def")<<endl;
	cout<<search(root,"abd")<<endl;
	cout<<search(root,"abcde")<<endl;
	return 0;
}
