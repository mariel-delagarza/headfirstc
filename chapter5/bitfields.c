#include <stdio.h>

typedef struct {
  unsigned int first_visit:1;
  unsigned int come_again:1;
  unsigned int fingers_lost:4;
  unsigned int shark_attack:1;
  unsigned int days_a_week:3;
} survey;

// 1 bit can store 2 values: true/false
// 4 bits are needed to store numbers up to 10
// 3 bits can store numbers up to 7
