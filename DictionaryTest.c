//==============================================================================
// DictionaryTest.c
// This will be used to test my Dictionary ADT as it is being built.
//==============================================================================

#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include"Dictionary.h"

int main(){
   Dictionary D = newDictionary();
   printf("iE: %d\n",isEmpty(D));
   printf("s(): %d\n",size(D));
   delete(D,"something");
   insert(D,"key","value");
   delete(D,"key");

   printf("s(): %d\n",size(D));
   insert(D,"butt", "face");
   printf("iE: %d\n",isEmpty(D));

   char* v;
   char* k;
   char* word1[] = {"one","two","three","four","five","six","seven"};
   char* word2[] = {"foo","bar","blah","galumph","happy","sad","blue"};
   int i;

   for(i=0; i<7; i++){
      insert(D, word1[i], word2[i]);
   }

   //printDictionary(stdout, A);

   printDictionary(stdout, D);
   printf("s(): %d\n",size(D));
   v = lookup(D, "one");
   printf("%s\n",v);
   //printf("before lookup()\n");
   v = lookup(D, "key");
   //printf("after lookup()\n");
   if(v==NULL) {
      printf("not fount\n");
   } else {
      printf("%s\n",v);
   }
   //printf("after print\n");
   v = lookup(D, "six");
   printf("%s\n",v);

   for(i=0; i<7; i++){
      k = word1[i];
      v = lookup(D, k);
      printf("key=\"%s\" %s\"%s\"\n", k, (v==NULL?"not found ":"value="), v);
   }

   insert(D,"four", "word");
   insert(D,"new", "word");
   //delete(D,"new");
   //delete(D,"butt");
   //delete(D,"seven");
   //delete(D,"six");
   //delete(D,"one");

   printDictionary(stdout, D);
   makeEmpty(D);

   printDictionary(stdout, D);
   printf("s(): %d\n",size(D));

   insert(D,"please","work");
   printDictionary(stdout, D);
   printf("s(): %d\n",size(D));
   exit(EXIT_SUCCESS);
}
