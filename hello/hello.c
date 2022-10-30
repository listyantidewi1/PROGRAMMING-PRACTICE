  #include <cs50.h>
  #include <stdio.h>

  int main(int argc, string argv[])
  {
      if (argc >= 2)
      {
          printf("hello, %s %s %s\n", argv[1], argv[2], argv[3]);
      }
      else
      {
          printf("hello, world\n");
      }
  }