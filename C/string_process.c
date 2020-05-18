#include <stdio.h>
#include <string.h>

int main(void){
  char s1 [80], s2 [80];
  int nn;

  strcpy(s1, "abcde");
  strcpy(s2, "FGHIJ");
  printf("s1=%s s2=%s\n", s1, s2);

  nn = strlen(s1);
  printf("len=%d\n", nn);

  if (strcmp(s1, s2) > 0)
    printf("Left Large\n");
  if (strcmp(s1, s2) < 0)
    printf("Right Large\n");
  if (strcmp(s1, s2) == 0)
    printf("Same\n");
  if (strcmp(s1, s2) != 0)
    printf("Not Same\n");

  strcat(s1, s2);
  print("s1 + s2 = %s\n", s1);

  return 0
}
