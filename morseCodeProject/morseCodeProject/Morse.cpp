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

string encodeText(string& str, Binary_Tree<string> morse) 
{
	char letter;
	string output;
	for (int i = 0; i < str.length(); i++)
	{
		letter = tolower(str[i]);			
		if (letter >= 'a' && letter <= 'z') 
		{	
			switch (str[i])
			{
			case 'a':
				output = "•-";
				break;
			case 'b':
				output = "-•••";
				break;
			case 'c':
				output = "-•-•";
				break;
			case 'd':
				output = "-••";
				break;
			case 'e':
				output = "•";
				break;
			case 'f':
				output = "••-•";
				break;
			case 'g':
				output = "--•";
				break;
			case 'h':
				output = "••••";
				break;
			case 'i':
				output = "••";
				break;
			case 'j':
				output = "•---";
				break;
			case 'k':
				output = "-•-";
				break;
			case 'l':
				output = "•-••";
				break;
			case 'm':
				output = "--";
				break;
			case 'n':
				output = "-•";
				break;
			case 'o':
				output = "---";
				break;
			case 'p':
				output = "•--•";
				break;
			case 'q':
				output = "--•-";
				break;
			case 'r':
				output = "•-•";
				break;
			case 's':
				output = "•••";
				break;
			case 't':
				output = "-";
				break;
			case 'u':
				output = "••-";
				break; 
			case 'v':
				output = "•••-";
				break; 
			case 'w':
				output = "•--";
				break;
			case 'x':
				output = "-••-";
				break;
			case 'y':
				output = "-•--";
				break;
			case 'z':
				output = "--••";
				break;
			default:
				cout << "Not a valid entry.";
			}

			//output = const char* find(const char& i) const;
		}
	output.push_back(' ');				
	}
	return output;
}

string decodeMorse(string &str, Binary_Tree<string> morse)
{
	string output = "";
	BTNode<string>* root = morse.getRoot();
	BTNode<string>* current = root;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == '-')
		{
			current = current->right;
		}
		if (str[i] == '•')
		{
			current = current->left;
		}
		if (str[i] == ' ' || i == str.length()-1)
		{
			output += current->to_string();
			current = root;
		}
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

	string myStr = "ch";
	cout << encodeText(myStr, morse) << endl;
	
	return 0;
}