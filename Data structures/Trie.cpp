/*
Data structure: Trie
Time complexity:
    Insert O(n) [where n is length of string]
    Look up O(n) [where n is length of string]
Memory complexity: O(|s1|+|s2|+...+|sk|) [where |si| is length of ith string present in the trie]
*/

#include <bits/stdc++.h>
using namespace std;

const int N=1e5+10;
const int ALPHABET=26;

int trie[N][ALPHABET], k;

void add (int node, char *s, int pos, int n)
{
    if (pos==n) return;

    int c=s[pos]-'a';
    if (!trie[node][c]) trie[node][c]=++k;
    add (trie[node][c], s, pos+1, n);
}

bool lookup (int node, char *s, int pos, int n)
{
    if (pos==n) return 1;

    int c=s[pos]-'a';
    if (!trie[node][c]) return 0;
    return lookup (trie[node][c], s, pos+1, n);
}

int main()
{
    char s[100];
    scanf ("%s", s);
    int n=strlen(s);

    add (0, s, 0, n);
    printf ("%d\n", lookup(0, s, 0, n));

    return 0;
}

