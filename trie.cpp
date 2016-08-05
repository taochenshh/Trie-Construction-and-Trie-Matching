#include <string>
#include <iostream>
#include <vector>
#include <map>

using std::map;
using std::vector;
using std::string;

typedef map<char, int> edges;
typedef vector<edges> trie;

trie build_trie(vector<string> & patterns) {
  trie t;
  edges root;
  t.push_back(root);
  int nodeNum = 0;
  for (vector<string>::iterator it = patterns.begin(); it!=patterns.end(); ++it)
  {
  	int currentNode = 0;
  	for (int i = 0; i < (*it).length(); i++)
  	{
  		char currentSymbol = (*it)[i];
  		edges::iterator edgeIt = t[currentNode].find(currentSymbol);
  		if(edgeIt != t[currentNode].end())
  		{
  			currentNode = edgeIt->second;
  		}
  		else
  		{
  			t[currentNode][currentSymbol] = ++nodeNum;
  			edges temp;
  			t.push_back(temp);
  			currentNode = nodeNum;
  		}
  	}
  }
  return t;
}

int main() {
  size_t n;
  std::cin >> n;
  vector<string> patterns;
  for (size_t i = 0; i < n; i++) {
    string s;
    std::cin >> s;
    patterns.push_back(s);
  }

  trie t = build_trie(patterns);
  for (size_t i = 0; i < t.size(); ++i) {
    for (const auto & j : t[i]) {
      std::cout << i << "->" << j.second << ":" << j.first << "\n";
    }
  }

  return 0;
}
