#include "Binary_Search_Tree.h"
#include <fstream>
#include <iostream>


using namespace std;

void displayTree(vector<string> &a)
{

	string textOutput;
	ifstream inf;
	inf.open("morseTree.txt");
	while (!inf.eof())
	{
		getline(inf, textOutput);
		a.push_back(textOutput);
		// cout << textOutput << endl; 
	}
}

string encodeText(string& str) //encode message ie.: "ch" to •_  _•_•
{
	char letter;
	string output;
	for (int i = 0; i < str.length(); i++)
	{
		letter = tolower(str[i]);			//check/change all to lowercase
		if (letter >= 'a' && letter <= 'z') //check within limits
		{												//return morse code in string
			//output = const char* find(const char& i) const;		//dont know what to do here
		}
	output.push_back(' ');					//add space
	}
	return output;
}

int main()
{
	vector<string>buildTree;
	displayTree(buildTree);
	Binary_Tree<string> morse;
	morse.read_tree(buildTree);
	displayTree(buildTree);
	return 0;
}