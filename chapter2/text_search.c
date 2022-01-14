//stdio gives you printf() and scanf()
#include <stdio.h>
//string gives you strstr()
#include <string.h>

//array of avail tracks
//set outside main() and find_track()
//so they will be usable everywhere
char tracks[][80] = {
  "I left my heart in Harvard Med School",
  "Newark, Newark - a wonderful town",
  "Dancing with a Dork",
  "From here to maternity",
  "The girl from Iwo Jima",
};

//declared before being called from main()
void find_track(char search_for[])
{
  int i;
  for (i = 0; i < 5; i++) {
    //display all matching tracks
    if (strstr(tracks[i], search_for))
      printf("Track %i: '%s'\n", i, tracks[i]);
  }
}

//main is the starting point of the program
int main()
{
  char search_for[80];
  //ask user for search text
  printf("Search for: ");
  scanf("%79s", search_for);
  search_for[strlen(search_for) - 1] = '\0';
  //call find_track and display matching tracks
  find_track(search_for);
  return 0;
}
