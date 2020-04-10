#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 32
#define ITEMNO 65535*3
#define NUMF 4

int uniq(int n, char ngram[ITEMNO][N], char result[ITEMNO][N + NUMF]);
int rescmp(const char *a, const char *b);

char ngram[ITEMNO][N];
char result[ITEMNO][N + NUMF];

int main(int argc, char *argv[]){
  int i, j;
  int no;

  /* read N gram */
  i = 0;
  while(fgets(ngram[i], N, stdin) != NULL){
    if(i >= ITEMNO){
      fprintf(stderr, "End ngram\n");
      break;
    }
    ++i;
  }

  qsort(ngram, i, N, (int (*)(const void *, const void *))strcmp);

  no = uniq(i, ngram, result);

  qsort(result, no, N + NUMF, (int (*)(const void *, const void *))rescmp);

  for(j = 0; j < i; ++j) printf("%s", result[j]);

  return 0;
}

int uniq(int n, char ngram[ITEMNO][N], char result[ITEMNO][N + NUMF]){
  int i, j;
  int c;
  char lastgram[N];

  strncpy(lastgram, ngram[0], N);
  j = 0;
  c = 1;

  for(i = 1; i < n; ++i){
    if(strcmp(lastgram, ngram[i])==0){
      // Check ngram overlap
      ++c;
    }
    else{
      // insert result
      sprintf(result[j], "%d\t%s", c, lastgram);
      strncpy(lastgram, ngram[i], N);
      c = 1;
      ++j;
    }
  }

  sprintf(result[j], "%d\t%s", c, lastgram);
  strncpy(lastgram, ngram[i], N);
  ++j;
  return j;
}

int rescmp(const char *a, const char *b){
  int numa, numb;

  numa = atoi(a); numb = atoi(b);

  if(numa > numb) return -1;
  else if(numa < numb) return 1;
  else return 0;
}
