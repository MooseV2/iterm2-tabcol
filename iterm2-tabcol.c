#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
  
  if (argc != 2 && argc != 4) {
    printf("usage: %s [! | r g b | hexcode]\n", argv[0]);
    exit(0);
  }
  int r, g, b;

  // rgb
  if (argc == 4) {
    r = strtol(argv[1], NULL, 10);
    g = strtol(argv[2], NULL, 10);
    b = strtol(argv[3], NULL, 10);
  } else if (argc == 2) { // hex or reset
    if (argv[1][0] == '!') {
      printf("\033]6;1;bg;*;default\a");
      exit(0);
    } else {
      long rgb = strtol(argv[1], NULL, 16);
      r = rgb >> 16; 
      g = (rgb & 0x00ff00) >> 8;
      b = (rgb & 0x0000ff);
    }
  }
  printf("\033]6;1;bg;red;brightness;%d\a", r);
  printf("\033]6;1;bg;green;brightness;%d\a", g);
  printf("\033]6;1;bg;blue;brightness;%d\a", b);
  return 0;
}
