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

int main()
{
	vector<string>buildTree;
	displayTree(buildTree);
	Binary_Tree<string> morse;
	morse.read_tree(buildTree);
	displayTree(buildTree);

	return 0;
}