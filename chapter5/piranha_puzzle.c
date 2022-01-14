#include <stdio.h>

struct exercise {
  const char *description;
  float duration;
};

struct meal {
  const char *ingredients;
  float weight;
};

struct preferences {
  struct meal food;
  struct exercise exercise;
};

struct fish {
  const char *name;
  const char *species;
  int teeth;
  int age;
  struct preferences care;
};

void catalog(struct fish a)
{
  printf("%s is a %s with %i teeth. He is %i.\n", a.name, a.species, a.teeth, a.age);
  printf("Feed with %2.2f lbs of %s and allow to %s for %2.2f hours.\n", a.care.food.weight, a.care.food.ingredients, a.care.exercise.description, a.care.exercise.duration);
}

int main()
{
  struct fish snappy = {"Snappy", "Piranha", 69, 4, {{"meat", 0.2}, {"swim in the jacuzzi", 7.5}}};
  catalog(snappy);
  /* We're skipping calling label for now */
  return 0;
}
