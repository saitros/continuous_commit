'''
The purpose was to tell you what the structure would be
when the heap was created, freed and used again.
About to know Use After Free attack or Warning when using heap

Source : https://shayete.tistory.com/entry/7-Use-After-Free
'''

#include <stdio.h>
#include <malloc.h>

typedef struct test{
  char *name[30];
  void (*greetings)(void *name);  // Function pointer
  void (*bye)(void *name);
}VULN;

void *say_hello(void *name){
  printf("Hello! %s\n", (char*)name);
}

void *say_goodbye(void *name){
  printf("Goodbye! %s\n", (char*)name);
}

void main(){
  void *vuln_test;
  VULN *vuln = (char*)malloc(100);

  vuln -> greetings = say_hello;

  vuln -> bye = say_goodbye;

  printf("Input Your name : ");
  scanf("%s\n", (char*)vuln -> name );

  vuln -> greetings(vuln -> name);

  free(vuln);

  vlun_test = (char*)malloc(100);

  printf("realloc 100, Input String : ");
  scanf("%s\n", (char*)vuln_test);

  printf("Tour message is : %s\n", (char*)vuln_test);
  vuln -> bye(vuln -> name);
  free(vuln_test);
}
