#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define ALPHABET_SIZE 26

#define CHAR_TO_INDEX(c) ((int)c - (int)'a')

typedef struct trie_node {
  struct trie_node *children[ALPHABET_SIZE];
  char ch;
  bool is_end_of_word;
  int word_counting;
} node;

node *get_node(void) {
  node *p_node = NULL;

  p_node = (node*) malloc(sizeof(node));

  if (p_node) {
    p_node->is_end_of_word = false;
    for (int i = 0; i < ALPHABET_SIZE; i++) {
      p_node->children[i] = NULL;
    }
  }
  return p_node;
}

void insert_node(node *root, char *word) {
  unsigned int index;
  node *current = root;
  for (unsigned int i = 0; i < strlen(word); i++) {
    if (!(isalpha(word[i]))) {
      continue;
    }
    word[i] = tolower(word[i]);

    if (current->children[CHAR_TO_INDEX(word[i])] == NULL) {
      current->children[CHAR_TO_INDEX(word[i])] = get_node();
    }
    current = current->children[CHAR_TO_INDEX(word[i])];
    current->ch = word[i];
  }
  current->is_end_of_word = true;
  current->word_counting += 1;
}

bool search(node *root, char *word) {
  for (unsigned int i = 0; i < strlen(word); i++) {
    if (root->children[CHAR_TO_INDEX(word[i])] == NULL) {
      return false;
    }
    root = root->children[CHAR_TO_INDEX(word[i])];
  }
  return root->is_end_of_word;
}

int main(int argc, char *argv[]) {
  node *p = get_node();
  FILE *f;
  char x[1024];

  f = fopen(argv[1],"r");

  while (fscanf(f, " %1023s", x) == 1) {
    insert_node(p, x);
  }

  printf("%d\n", search(p, "filipe"));
  printf("%d\n", search(p, "method"));
  printf("%d\n", search(p, "or"));

  return 0;
}
