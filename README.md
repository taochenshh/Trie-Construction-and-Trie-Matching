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
`
3
AT
AG
AC
`
####Output:
`
0->1:A
1->4:C
1->3:G
1->2:T
`

**trie_matching.cpp**
###Example:
####Input:
`
3
AT
AG
AC
`
####Output:
`
0->1:A
1->4:C
1->3:G
1->2:T
`
**trie_matching_extended.cpp**
###Example:
####Input:
`
3
AT
AG
AC
`
####Output:
`
0->1:A
1->4:C
1->3:G
1->2:T
`
