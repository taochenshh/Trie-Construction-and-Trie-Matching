#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int const Letters =    4;
int const NA      =   -1;

struct Node
{
	int next [Letters];
	bool patternEnd;

	Node ()
	{
		fill (next, next + Letters, NA);
		patternEnd = false;
	}
};
typedef vector<Node> trie;

int letterToIndex (char letter)
{
	switch (letter)
	{
		case 'A': return 0; break;
		case 'C': return 1; break;
		case 'G': return 2; break;
		case 'T': return 3; break;
		default: assert (false); return -1;
	}
}

trie build_trie(vector<string> & patterns) {
  trie t;
  Node root;
  t.push_back(root);
  int nodeNum = 0;
  for (vector<string>::iterator it = patterns.begin(); it!=patterns.end(); ++it)
  {
  	int currentNode = 0;
  	for (unsigned int i = 0; i < (*it).length(); i++)
  	{
  		char currentSymbol = (*it)[i];
  		int currentIndex = letterToIndex(currentSymbol);
  		int nextNode = t[currentNode].next[currentIndex];
  		if(nextNode != NA)
  		{
  			if(i == (*it).length() - 1)
  			{
  				t[nextNode].patternEnd = true;
  			}
  			else
  			{
  				currentNode = nextNode;
  			}
  		}
  		else
  		{
  			t[currentNode].next[currentIndex] = ++nodeNum;
  			Node temp;
  			if(i == (*it).length() - 1)
  			{
  				temp.patternEnd = true;
  			}
  			t.push_back(temp);
  			currentNode = nodeNum;
  		}
  	}
  }
  return t;
}

int prefixTrieMatching(string text, trie &t)
{
	char currentSymbol = text[0];
	Node currentNode = t[0];
	unsigned int letterId = 0;
	int currentSymToInd = letterToIndex(currentSymbol);
	while(true)
	{
		if(currentNode.patternEnd)
		{
			return 1;
		}
		else if(currentNode.next[currentSymToInd] != NA)
		{
			currentNode = t[currentNode.next[currentSymToInd]];
			if (letterId < text.size() - 1)
			{
				currentSymbol = text[++letterId];
				currentSymToInd = letterToIndex(currentSymbol);
			}
			else
			{
				if(currentNode.patternEnd)
				{
					return 1;
				}
				else
				{
					return 0;
				}
			}

		}
		else
		{
			return 0;
		}
	}

}
vector <int> solve (string text, int n, vector <string> patterns)
{
	vector <int> result;

	trie t = build_trie(patterns);
	for (unsigned int i = 0; i < text.length(); i++)
	{
		string newText = text.substr(i, text.length() - i);
		int containPattern = prefixTrieMatching(newText,t);
		if (containPattern)
		{
			result.push_back(i);
		}
	}

	return result;
}

int main (void)
{
	string t;
	cin >> t;

	int n;
	cin >> n;

	vector <string> patterns(n);
	for (int i = 0; i < n; i++)
	{
		cin >> patterns[i];
	}

	vector <int> ans;
	ans = solve (t, n, patterns);

	for (int i = 0; i < (int) ans.size (); i++)
	{
		cout << ans[i];
		if (i + 1 < (int) ans.size ())
		{
			cout << " ";
		}
		else
		{
			cout << endl;
		}
	}

	return 0;
}
