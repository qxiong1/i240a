#include <iostream>
#include <string>
#include <fstream>
#include <utility>
#include <list>
#include <iterator>
using namespace std;
list<pair<int, string>> l;
bool comp(pair<int, string> p1, pair<int, string> p2)
{
	if(p1.first > p2.first)
		return true;
	else
		return false;
}
int found(string word)
{
	int n = 0;
	for(list<pair<int, string>>::iterator i = l.begin(); i != l.end(); i++, n++)
	{
		if(i->second == word)
		{
			return n;
		}
	}
	return -1;
}
int main(int argc, char **argv)
{
	unsigned int n = atoi(argv[1]);
	unsigned int n2 = atoi(argv[2]);
	unsigned int n3 = atoi(argv[3]);
	if(argc < 5)
	{
		cout << "usage: ./wordcounts MAX_N_OUT MIN_WORD_LEN MAX_WORD_LEN FILE..." << endl;
		exit(EXIT_FAILURE);
	}
	if(n < 0)
	{
		cout << "MAX_N_OUT cannot be less than 0" << endl;
		exit(EXIT_FAILURE);
	}
	if(n2 > n3)
	{
		cout << "MIN_WORD_LEN " << n2 << " is greater than MAX_WORD_LEN " << n3 << endl;
		exit(EXIT_FAILURE);
	}
	int j = 4;
	while(j < argc)
	{
		ifstream readFile;
		readFile.open(argv[j]);
		if(!readFile)
		{
			cout << "FAILED TO OPEN " << argv[j] << endl;
			exit(EXIT_FAILURE);
		}
		string word = "", temp = "";
		while(!readFile.eof())
		{
			readFile >> word;
			if(readFile.eof())
				break;
			for(unsigned int k = 0; k < word.size(); k++)
			{
				//get only letters of word.
				if(((unsigned int)word[k] >= 65 && (unsigned int)word[k] < 91) || ((unsigned int)word[k] >= 97 && (unsigned int)word[k] < 123))
				{
					temp += tolower(word[k]);
				}
				else
				{
					continue;
				}
			}
			if(found(temp) != -1)
			{
				list<pair<int, string>>::iterator i = l.begin();
				advance(i, found(temp));
				i->first++;
				temp = "";
				continue;
			}
			else
			{
				l.push_back(make_pair(1, temp));
				temp = "";
			}
		}
		readFile.close();
		j++;
	}
	l.sort(comp);
	for(list<pair<int, string>>::iterator i = l.begin(); i != l.end() && n > 0; n--, i++)
	{
		if(i->second.size() < n2 || i->second.size() > n3)
		{
			n++;
			continue;
		}
		cout << i->second << ": " << i->first << endl;
	}
}
