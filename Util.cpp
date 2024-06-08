// Util.cpp
// Calvin Tallent

#ifndef UTIL_CPP
#define UTIL_CPP

#include <fcntl.h>
#include <queue>
#include <stdio.h>
#include <termios.h>
#include <unistd.h>

// Whats for any key to be pressed.
// Taken from https://stackoverflow.com/a/1449355
int kbhit(void) {
  struct termios oldt, newt;
  int ch;
  int oldf;

  tcgetattr(STDIN_FILENO, &oldt);
  newt = oldt;
  newt.c_lflag &= ~(ICANON | ECHO);
  tcsetattr(STDIN_FILENO, TCSANOW, &newt);
  oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
  fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

  ch = getchar();

  tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
  fcntl(STDIN_FILENO, F_SETFL, oldf);

  if (ch != EOF) {
    ungetc(ch, stdin);
    return 1;
  }

  return 0;
}

int anyKeyToContinue() {
  printf("Press any key to continue:");
  fflush(stdout);
  while (!kbhit()) {
  }
  puts("Done.");
  return 0;
}

#endif
