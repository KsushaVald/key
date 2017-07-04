#include <stdio.h>
#include <pthread.h>
#include "lib.h"

void func(void){
  char *buf;
  buf=print_n(10);
  printf("thread->%s\n", buf);
}

int main(void){
  char *buf;
  int status;
  pthread_t t;
  buf=print_n(15);
//  printf("%s %p\n", buf, buf);
  pthread_create(&t, NULL,(void*)func, NULL);
  pthread_join(t,(void**)&status);
  printf("Main->%s %p\n", buf, buf); 
return 0;
}

