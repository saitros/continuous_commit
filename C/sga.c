#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define DATANO 20
#define POOLSIZE 30
#define LASTG 200
#define MRATE 0.01
#define SEED 65535
#define YES 1
#define NO 0
#define VALUE 499
#define MAXFIT 1000

int evalfit(int gene[]);
void moating(int pool[POOLSIZE][DATANO]);
void mutation(int pool[POOLSIZE][DATANO]);
void printp(int pool[POOLSIZE][DATANO]);
void initpool(int pool[POOLSIZE][DATANO]);

int rndn();
int notval(int v);
int select(int roulette[POOLSIZE], int totalfiness);
void copypool(int pool[POOLSIZE][DATANO], int nextpool[POOLSIZE][DATANO]);

void crossing(int m[], int p[], int c1[], int c2[]);

int q[] = {31, 41, 59, 26, 53, 58, 97, 93, 23, 84, -62, -64, -33, -83, -27, -95, -2, -88, -41, -97};

int main(int argc, char *argv[]){
  int pool[POOLSIZE][DATANO];
  int generation;

  srand(SEED);

  initpool(pool);

  for(generation = 0; generation < LASTG; ++generation){
    printf(" %d세대 \n", generation);
    mating(pool);
    mutation(pool);
    printp(pool);
  }

  return 0;
}

int select(int roulette[POOLSIZE], int totalfiness){
  int i;
  int ball;
  int acc = 0;

  ball = rndn(totalfiness);
  for(i = 0; i < POOLSIZE ; ++i){
    acc += roulette[i];
    if(acc>ball) break;
  }

  return i;
}

void mating(int pool[POOLSIZE][DATANO]){
  int i;
  int totalfiness = 0;
  int nextpool[POOLSIZE][DATANO];
  int roulette[POOLSIZE];
  int mama, papa;

  for(i = 0; i < POOLSIZE ; ++i){
    roulette[i] = evalfit(pool[i]);
    totalfiness += roulette[i];
  }

  for(i = 0; i < POOLSIZE / 2; ++i){
    do{
      mama = select(roulette, totalfiness);
      papa = select(roulette, totalfiness);
    }while(mama == papa);
    crossing(pool[mama], pool[papa], nextpool[i*2], nextpool[i*2 + 1]);
  }

  copypool(pool, nextpool);
}

void crossing(int m[], int p[], int c1[], int c2[]){
  int j;
  int cp;

  cp = rndn(DATANO);

  for(j=0; j<cp; ++j){
    c1[j] = m[j];
    c2[j] = p[j];
  }

  for(j=0; j<DATANO; ++j){
    c2[j] = m[j];
    c1[j] = p[j];
  }
}
