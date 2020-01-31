#include <iostream>
#include <fstream>
using namespace std;
#include <string>
#include"Header.h"
string word = "";
string previousword = "";
cNode::cNode()
{
	this->key = "";
	this->previous = NULL;
	this->right = NULL;
	this->left = NULL;
}

cBST::cBST()
{
	this->root = NULL;
}
cNode* cBST::getNode(string Data)
{
	cNode *newNode = new cNode();
	newNode->key = Data;
	return newNode;
}

cNode* cBST::insert(string key)
{
	cNode* newnode = new cNode();
	newnode->key = key;

	cNode* tp = root;
	cNode* tempPtr = NULL;

	while (tp != NULL) {
		tempPtr = tp;
		if (key.compare(tp->key)<0)
			tp = tp->left;
		else
			tp = tp->right;
	}
	if (tempPtr == NULL)
		tempPtr = newnode;

	else if (key.compare(tempPtr->key) < 0)
	{
		tempPtr->left = newnode;
	}
	else
	{
		tempPtr->right = newnode;
	}
	newnode->previous = tempPtr;
	return tempPtr;
}
void cBST::Inorder(cNode* root)
{
	if (root == NULL)
		return;
	else
	{
		Inorder(root->left);
		cout << root->key << " ";
		Inorder(root->right);
	}
}
cNode* cBST::search(cNode* root, string key)
{
	if (root == NULL || key.compare(root->key) == 0)
	{
		return root;
	}
	else if (key.compare(root->key) < 0)
		return search(root->left, key);
	else
		return search(root->right, key);
}


void spellCheck::LoadDictionory()
{
	string STRING;
	ifstream infile;
	infile.open("test.txt");
	infile >> STRING;
	this->DictHolder.root = this->DictHolder.insert(STRING);
	while (!infile.eof())
	{
		infile >> STRING;
		this->DictHolder.insert(STRING);
	}
	infile.close();
}

void spellCheck::printDictionory()
{
	this->DictHolder.Inorder(DictHolder.root);
}

bool spellCheck::spellChecker(string Myword)
{
	if (this->DictHolder.search(DictHolder.root, Myword) != NULL)
	{
		return true;
	}
	return false;
}
size_t uiLevenshteinDistance(const string &s1, const string &s2)
{
	const size_t m(s1.size());
	const size_t n(s2.size());

	if (m == 0) return n;
	if (n == 0) return m;

	size_t *costs = new size_t[n + 1];

	for (size_t k = 0; k <= n; k++) costs[k] = k;

	size_t i = 0;
	for (std::string::const_iterator it1 = s1.begin(); it1 != s1.end(); ++it1, ++i)
	{
		costs[0] = i + 1;
		size_t corner = i;

		size_t j = 0;
		for (std::string::const_iterator it2 = s2.begin(); it2 != s2.end(); ++it2, ++j)
		{
			size_t upper = costs[j + 1];
			if (*it1 == *it2)
			{
				costs[j + 1] = corner;
			}
			else
			{
				size_t t(upper<corner ? upper : corner);
				costs[j + 1] = (costs[j]<t ? costs[j] : t) + 1;
			}

			corner = upper;
		}
	}

	size_t result = costs[n];
	delete[] costs;

	return result;
}
void spellCheck::wordFinder(cNode* root, string wrongWord)
{
	if (root == NULL)
		return;
	else
	{
		if (!this->spellChecker(wrongWord))
		{
			if (uiLevenshteinDistance(root->key, wrongWord) <3 && previousword != root->key)
			{
				word = word + root->key + " ";
			}
			previousword = root->key;
		}
		wordFinder(root->left, wrongWord);
		wordFinder(root->right, wrongWord);
	}
}

void spellCheck::spellCorrector(cNode* root, string wrongWord)
{
	this->wordFinder(root, wrongWord);
	if (word == "")
	{
		cout << "either a true word or not possible match found" << endl;
	}
	else
		cout << word << endl;
}