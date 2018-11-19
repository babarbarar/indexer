#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define ALPHABET_SIZE 26;

int main() {

  struct trie_node {
    struct trie_node *children[ALPHABET_SIZE];
    bool is_end_of_word;
  }

  struct trie_node *get_node {
    struct trie_node *p_node = NULL;

    p_node = (struct trie_node*) malloc(sizeof(struct trie_node));

    if (p_node) {
      p_node->is_end_of_word = false;
      for (int i = 0; i < ALPHABET_SIZE; i++) {
        p_node->children[i] = NULL;
      }
    }
    return p_node;
  }

  return 0;
}
