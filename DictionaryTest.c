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
   insert(D,"key","value");
   insert(D,"butt", "face");

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

   v = lookup(D, "one");
   printf("%s\n",v);
   printf("before lookup()\n");
   v = lookup(D, "face");
   //printf("after lookup()\n");
   if(v==NULL) {
      printf("not fount");
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

   exit(EXIT_SUCCESS);
}
