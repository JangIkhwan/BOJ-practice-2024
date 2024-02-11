/*
18:24

2
GCF
ACDEB

  753
98764

풀이 방법
- 트라이?
- bfs
*/
#include <iostream>
#include <string>
#include <queue>
#include <cstring>
using namespace std;

const int MAX = 26;
typedef struct TrieNode {
	TrieNode* children[MAX];
	bool visited;
	TrieNode() {
		for (int i = 0; i < MAX; i++) {
			children[i] = NULL;
			visited = false;
		}
	}
	void insert(char *ch) {
		int cur = *ch - 'A';
		if (ch != NULL) {
			if (children[cur])
				children[cur] = (TrieNode*)malloc(sizeof(TrieNode));
			children[cur]->insert(ch + 1);
		}
	}
	int find(char* ch) {
		
	}
	~TrieNode() {
		for (int i = 0; i < MAX; i++) {
			free(children[i]);
		}
	}
}TrieNode;

void bfs(TrieNode* root) {
	int weight = 9;
	queue<TrieNode*>qu;
	root->visited = true;
	qu.push(root);
	while (!qu.empty()) {
		TrieNode* cur = qu.front();
		qu.pop();
		for (int i = 0; i < MAX; i++) {
			TrieNode* next = cur->children[i];
			if (next != NULL) {
				if (!next->visited) {
					if (alphabet[i] != -1) {
						alphabet[i] = weight;
					}
					next->visited = true;
					qu.push(next);
				}
			}
		}
	}
}

int N;
char word[11][11];
int alphabet[MAX];

int main(void) {
	memset(alphabet, -1, sizeof(alphabet));
	return 0;
}