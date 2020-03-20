#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TEXTLENGTH 256
#define DATANO 256
#define ATTNO 4
#define YES 1
#define NO 0

'''
Q1.
param yorn is FLAG? 
'''

int readdata(int dataset[DATANO][ATTNO + 1]);
void evalp(int dataset[DATANO][ATTNO + 1], int no, int i, int yorn);

int main(int argc, char *argv[]){
  int no;
  int i;
  int dataset[DATANO][ATTNO + 1] = {0};

  no = readdata(dataset);

  for(i = 0; i < ATTNO; ++i){
    printf("\np%d\n", i + 1);
    printf("Yes")
    evapl(dataset, no, i, YES);
    printf("No");
    evapl(dataset, no, i, NO);
  }
  return 0;
}

int readdata(int dataset[DATANO][ATTNO + 1]){
  int no = 0;
  int att = 0;

  while(scanf("%d\n", &dataset[no][att]) != EOF){
    ++ att;
    if(att>ATTNO){
      att = 0;
      ++no;
    }
  }
  return no;
}

void evalp(int dataset[DATANO][ATTNO + 1], int no, int i, int yorn){
  int j;
  int total, point;

  j = 0;
  total = point = 0;
  while(j<no){
    if(dataset[j][i] == yorn){
      ++total;
      if(dataset[j][i] == dataset[j][ATTNO])
      ++point;
    }
    ++j;
  }
  printf("%d/%d %lf\n", point, total, (double)point/total)
}
