#include<stdio.h>
#include<pthread.h>
#include<malloc.h>
#include "lib.h"

pthread_key_t key;
pthread_once_t once=PTHREAD_ONCE_INIT;

void dist(void *buf)
{
 free(buf);
}

void keyer(void)
{
   pthread_key_create(&key,dist);
}

char* print_n(int n)
{
  char *buf=NULL;
  pthread_once(&once, keyer);
  pthread_getspecific(key);
  if(buf==NULL){
   buf=malloc(50*sizeof(char));
  }
  snprintf(buf, 50,"Number %d\n", n);
  pthread_setspecific(key, buf);
  return buf;
}
