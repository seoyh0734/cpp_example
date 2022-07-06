#include <iostream>

#include <cstdlib>

#include <termio.h>
#include <cstdio>
int getch(void)
{
  int ch;

  struct termios buf;
  struct termios save;

  tcgetattr(0, &save);
  buf = save;

  buf.c_lflag &= ~(ICANON|ECHO);
  buf.c_cc[VMIN] = 1;
  buf.c_cc[VTIME] = 0;

  tcsetattr(0, TCSAFLUSH, &buf);
  ch = getchar();
  tcsetattr(0, TCSAFLUSH, &save);
  return ch;
}

int main(int argc, char** argv)
{
  std::cout << (char)getch() << std::endl;
  return 0;
}
