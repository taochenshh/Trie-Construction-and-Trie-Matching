# Trie-Construction-and-Trie-Matching

**trie.cpp**

This file constructs a trie from a collection of patterns.

* Input: An integer n and a collection of strings Patterns={p1, ... , pn} (each string is given on a separate line).
* Output: The adjacency list corresponding to Trie(Patterns), in the following format. If
Trie(Patterns) has 𝑛 nodes, first label the root with 0 and then label the remaining nodes with the
integers 1 through 𝑛−1 in any order you like. Each edge of the adjacency list of Trie(Patterns) will be
encoded by a triple: the first two members of the triple must be the integers 𝑖, 𝑗 labeling the initial and
terminal nodes of the edge, respectively; the third member of the triple must be the symbol 𝑐 labeling
the edge; output each such triple in the format u->v:c (with no spaces) on a separate line.

###Example:
####Input:
```
3
AT
AG
AC
```
####Output:
```
0->1:A
1->4:C
1->3:G
1->2:T
```

**trie_matching.cpp**

Given a string Text and Trie(Patterns), we can quickly check whether any string from Patterns matches a prefix of Text.

* Input: The first line of the input contains a string Text, the second line contains an integer 𝑛 ,each of the following 𝑛 lines contains a pattern from Patterns = {𝑝1, . . . , 𝑝𝑛}
* Output: All starting positions in Text where a string from Patterns appears as a substring in increasing order (assuming that Text is a 0-based array of symbols).
###Example:
####Input:
```
AATCGGGTTCAATCGGGGT
2
ATCG
GGGT
```
####Output:
```
1 4 11 15
```
**trie_matching_extended.cpp**

Extend TrieMatching algorithm so that it handles correctly cases when one of the patterns is a prefix of another one
###Example:
####Input:
```
ACATA
3
AT
A
AG
```
####Output:
```
0 2 4
```
