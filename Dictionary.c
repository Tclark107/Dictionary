//------------------------------------------------------------------------------
// Dictionary.c
// My Dictionary ADT in C
//------------------------------------------------------------------------------

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
#include"Dictionary.h"

//-----------------------------------------------------------------------------
// private types
//-----------------------------------------------------------------------------

typedef struct NodeObj{
   char* key;
   char* value;
   struct NodeObj* next;
} NodeObj;

typedef NodeObj* Node;

// Node Constructor
Node NewNode(char* key, char* value) {
   Node N = malloc(sizeof(NodeObj));
   assert(N!=NULL);
   N->key = key;
   N->value = value;
   N->next = NULL;
   return(N);
}

void freeNode(Node* p) {
   if(*p != NULL && p != NULL) {
      free(*p);
      *p = NULL; 
   }
}

typedef struct DictionaryObj {
   int numItems;
   Node head;
   Node tail;
} DictionaryObj;

// findKey()
// returns a reference to the Node containing key, otherwise it returns NULL
Node findKey(Dictionary D, char* key) { 
   Node N = malloc(sizeof(NodeObj));
   assert(N!=NULL);
   for(N = D->head; N != NULL; N = N->next) {
      printf("in for loop\n");
      if(!strcmp(N->key,key)) return N;
   }
   printf("after for loop\n");
   return NULL;
}

//-----------------------------------------------------------------------------
// public types
//-----------------------------------------------------------------------------

// newDictionary()
// Dictionary Constructor
Dictionary newDictionary(void) {
   Dictionary D = malloc(sizeof(DictionaryObj));
   assert(D!=NULL);
   D->numItems = 0;
   D->head = NULL;
   return D;
}

// freeDictionary() 
// destructor for the Dictionary type
void freeDictionary(Dictionary* pD) {
   if(*pD != NULL && pD != NULL) {
      //if(!isEmpty(*pD)) makeEmpty(*pD);
      free(*pD);
      *pD = NULL;
   }
}

// isEmpty()
// returns true if D is empty, false otherwise
// pre: none
int isEmpty(Dictionary D) {
   if(D==NULL) {
      fprintf(stderr,"Stack Error: calling isEmpty() on NULL Stack reference\n");
      exit(EXIT_FAILURE);
   }
   return (D->numItems == 0);
}

// size()
// returns the number of (key,value) pairs in D
// pre: none
int size(Dictionary D) {
   if(D==NULL) {
      fprintf(stderr,"Stack Error: calling size() on NULL Stack reference\n");
      exit(EXIT_FAILURE);
   }
   return D->numItems;
}

// lookup()
// returns the value v such that (k,v) is in D, or returns NULL if no
// such value exists.
// pre: none
char* lookup(Dictionary D, char* k) {
   if(D==NULL) {
      fprintf(stderr,"Stack Error: calling lookup() on NULL Stack reference\n");
      exit(EXIT_FAILURE);
   }
   Node N = malloc(sizeof(NodeObj));
   assert(N!=NULL);
   for(N = D->head; N!=NULL; N = N->next) {
      if(!strcmp(k,N->key)) {
         return N->value;
      }
   }
   return NULL;
}

// insert()
// inserts a new (key,value) pair into D
// pre: lookup(D,k)==NULL
void insert(Dictionary D, char* k, char* v) {
   if(D==NULL) {
      fprintf(stderr,"Stack Error: calling insert() on NULL Stack reference\n");
      exit(EXIT_FAILURE);
   }
   Node N = malloc(sizeof(NodeObj));
   assert(N!=NULL);
   N->key = k;
   N->value = v;
   if(D->numItems==0) {
      D->head = N;
      D->tail = N;
   } else {
      D->tail->next = N;
      D->tail = N;
   }
   D->numItems++; 
}

// delete()
// deletes a pair with the key k
// pre: lookup(D, k)!=NULL
void delete(Dictionary D, char* k) {
   if(D==NULL) {
      fprintf(stderr,"Stack Error: calling insert() on NULL Stack reference\n");
      exit(EXIT_FAILURE);
   }
}

// makeEmpty()
// re-sets D to the empty state.
// pre: none
void makeEmpty(Dictionary D) {
   if(D==NULL) {
      fprintf(stderr,"Stack Error: calling insert() on NULL Stack reference\n");
      exit(EXIT_FAILURE);
   }
}

// printDictionary()
// prints a text representations of D to the file pointed to by out
// pre: none
void printDictionary(FILE* out, Dictionary D) {
   if(D==NULL) {
      fprintf(stderr,"Stack Error: calling printDictionary() on NULL Stack reference\n");
      exit(EXIT_FAILURE);
   }
   if(D->numItems>0) {
      Node N = malloc(sizeof(NodeObj));
      assert(N!=NULL);
      for(N = D->head; N != NULL; N = N->next) {
         fprintf(out,"%s %s\n",N->key,N->value);
      }
   }
}
