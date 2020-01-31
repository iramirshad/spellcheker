#include <iostream>
#include <fstream>
using namespace std;
#include <string>
#include"Header.h"
int main()
{
	spellCheck myTree;
	bool status = true;
	string word = "";
	int input;
	myTree.LoadDictionory();//load dictionary from test.txt file
	while (status)
	{
		cout << "enter a word: ";
		cin >> word;
		myTree.spellCorrector(myTree.DictHolder.root, word);
		cout << "want to retry?" << endl;
		cout << "press 0 to exit or 1 to countinue: ";
		cin >> input;
		system("CLS");
		if (input == 0)
			status = false;
	}
	system("pause");
}