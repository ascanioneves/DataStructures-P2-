#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node Node;

struct Node {
	char ch;
	int freq;
	Node* next;
};

Node* create_blank_list() { return NULL; }

Node* add(Node* head, char item, int f) {
	Node* new_node = (Node*) malloc(sizeof(Node));
	new_node -> ch = item;
	new_node -> freq = f;
	new_node -> next = head;
	return new_node;
}
void print_list(Node *node) {
	while(node != NULL) {
		printf("%c %d\n", node -> ch, node -> freq);
		node = node -> next;
	}
}
int main() {
	int i, j;
	char str[10000];
	scanf("%[^\n]", str);
	Node* list = create_blank_list();
	for(i = 0; i < 256; i++) {
		int ans = 0;
		for(j = 0; j < strlen(str); j++) {
			ans += (str[j] == (char)i);
		}
		if(ans) {
			list = add(list, (char)i, ans);
		}
	}
	print_list(list);
	return 0;
}