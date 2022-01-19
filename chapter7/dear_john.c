#include <stdio.h>
#include <string.h>
#include <stdlib.h>

enum response_type {DUMP, SECOND_CHANCE, MARRIAGE};

typedef struct {
  char *name;
  enum response_type type;
} response;

void dump(response r) 
{
  printf("Dear %s, \n", r.name);
  puts("Unfortunately your last date contacted us to");
  puts("say that they will not be seeing you again");
}

void second_chance(response r)
{
  printf("Dear %s, \n", r.name);
  puts("Good news: your last date has asked us to");
  puts("arrange another meeting. Please call ASAP.");
}

void marriage(response r)
{
  printf("Dear %s, \n", r.name);
  puts("Congratulations! Your last date has contacted");
  puts("us with a proposal of marriage.");
}

void (*replies[])(response) = {dump, second_chance, marriage};

int main()
{
  response r[] = {
    {"Mike", DUMP}, {"Luis", SECOND_CHANCE},
    {"Matt", SECOND_CHANCE}, {"William", MARRIAGE}
  };

  int i;

  for (i = 0; i < 4; i++) {
    (replies[r[i].type])(r[i]);
  }
  return 0;
}

//replies[r][i].type -> a function, like "dump"
//replies[] -> array of function names
//[r[i].type] -> value like 0 for DUMP or 2 for marriage
//(r[i]) -> calling the function and passing it the response data
