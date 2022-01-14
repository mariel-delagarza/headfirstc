#include <stdio.h>

int main()
{
  float latitude;
  float longitude;
  char info[80];
  //set started to 0, which means false
  int started = 0;

  puts("data=[");
  // need & on the variables - scanf() needs pointers
  while (scanf("%f,%f,%79[^\n]", &latitude, &longitude, info) == 3) {
    if (started) 
      //only display comma if you've already displayed a previous line
      printf(",\n");
    else 
      //once loop has started, set "started" to 1 for "true"
      started = 1;

    //validate data
    if ((latitude < -90.0) || (latitude > 90.0)) {
      fprintf(stderr, "Invalid latitude: %f\n", latitude);
      return 2;
    }
    if ((longitude < -180.0) || (longitude > 180.0)) {
      fprintf(stderr, "Invalid longitutde: %f\n", longitude);
      return 2;
    }

    //don't need & on latitude/longitude because printf() is using the 
    //values, not the addresses of the numbers
    printf("{latitude: %f, longitude: %f, info: '%s'}", latitude, longitude, info);
  }
  puts("\n]");
  return 0;
}
