#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 32

void setlastch(int n, char chr, char lastch[]);
void printngram(int n, char lastch[]);

int main(int argc, char *argv[]){
  int n;
  char lastch[N];
  char chr;

  /* Check arugment */
  if(argc !=2){
    fprintf(stderr, "Usage $./ngram (N value) <(input file)> (output file)\n");
    exit(1);
  }

  /* Check N Value */
  if(((n = atoi(argv[1])) < 1) || (n >= N)){
    fprintf(stderr, "Wrong N Value\n");
    exit(1);
  }

  while((chr = getchar()) != EOF){
    if(chr != '\n'){

      setlastch(n, chr, lastch);

      printngram(n, lastch);
    }
  }
  return 0;
}

void setlastch(int n, char chr, char lastch[]){
  int i;

  for(i = n-2; i>= 0; --i)
  lastch[i+1] = lastch[i];

  lastch[0] = chr;
}

void printngram(int n, char lastch[]){
  int i;

  for(i = n-1; i>=0; i--)
  printf("%c", lastch[i]);
  printf("\n");
}
