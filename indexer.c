#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define ALPHABET_SIZE 26

#define CHAR_TO_INDEX(c) ((int)c - (int)'a')

typedef struct trie_node {
  struct trie_node *children[ALPHABET_SIZE];
  bool is_end_of_word;
  int word_counting;
} node;

node *get_node() {
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
  node *p_node = NULL;
  p_node = (node*) malloc(sizeof(node));

  for (unsigned int i = 0; i < strlen(word); i++) {
    index = CHAR_TO_INDEX(word[i]);
    if (root->children[index] == NULL) {
      root->children[index] = p_node;
    }
    root = root->children[index];
  }
  root->is_end_of_word = true;
  root->word_counting++;
}

int main() {
  node p = *get_node();
  char *ch = "abelha";
  insert_node(&p, ch);
  return 0;
}
