class cNode
{
public:
	string key;
	cNode *left;
	cNode *right;
	cNode *previous;
	cNode();
};
class cBST
{
public:
	cNode *root;
	cBST();
	cNode* getNode(string Data);
	cNode* insert(string key);
	cNode* search(cNode* root, string key);
	void Inorder(cNode* Node);
};
class spellCheck
{
public:

	cBST DictHolder;
	void LoadDictionory();//must
	void printDictionory();
	bool spellChecker(string Myword);
	void wordFinder(cNode* root, string wrongWord);
	void spellCorrector(cNode* root, string wrongWord);
};