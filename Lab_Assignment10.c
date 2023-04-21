#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Trie{
    int count;
    struct Trie *children[26];
};

//THIS ABOVE IS CODE I MADE JUST IN CASE I CONFU``SE WHATS WHAT
void insert(struct Trie *ppTrie, char *word);
int numberOfOccurances(struct Trie *pTrie, char *word);
struct Trie *deallocateTrie(struct Trie *pTrie);
struct Trie *c_Node(void);//Creates Node


int main(void)
{
      //read the number of the words in the dictionary
      // parse line  by line, and insert each word to the trie data structure
      struct Trie *trie = c_Node();
      char *pWords[] = {"notaword", "ucf", "no", "note", "corg"};

      for(int x = 0; x < 5; x++)
      {
        insert(trie, pWords[x]);
      }
      for (int i=0;i<5;i++)
      {
          printf("\t%s : %d\n",pWords[i], numberOfOccurances(trie, pWords[i]));
     }
    trie = deallocateTrie(trie);
    if (trie != NULL)
       printf("There is an error in this program\n");
    return 0;
}
struct Trie *deallocateTrie(struct Trie *pTrie)
{
    if(pTrie==NULL)
    {
        return NULL;
    }
    for(int x = 0 ; x < 26; x++)
    {
        if(pTrie->children[x] != NULL)
        {
            pTrie = pTrie->children[x];
            deallocateTrie(pTrie);
        }
    }
    free(pTrie);
    return NULL;
}

void insert(struct Trie *ppTrie, char *word)
{
    struct Trie *tmp = ppTrie;
    for(int x = 0; x < strlen(word); x++)
    {
        if(tmp->children[word[x]-'a'] == NULL)
        {
            tmp->children[word[x]-'a'] = c_Node();
        }    
        tmp = tmp->children[word[x]-'a'];
    }
    tmp->count++;
}
//THIS BELOW IS CODE I MADE
int numberOfOccurances(struct Trie *pTrie, char *word)
{
    //inserting, already doing the count
    //searching to see 
    struct Trie *tmp = pTrie;
    for(int x = 0; x < strlen(word); x++)
    {
        if(tmp->children[word[x] - 'a'] == NULL)
        {
            return tmp->count;
        }
        tmp = tmp->children[word[x] - 'a'];
    }
    return tmp->count;
}

struct Trie *c_Node(void)
{
    struct Trie *trie = malloc(sizeof(struct Trie));//Made this
      trie->count = 0;
      for(int x = 0; x < 26; x++)
      {
        trie->children[x] = NULL;
      }
    return trie;
}