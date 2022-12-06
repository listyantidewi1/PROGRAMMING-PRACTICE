  #include <stdio.h>

  int main(void)
  {
      int x = 1; //index kiri atas
      int y = 2; //index kanan atas

      printf("x is %i, y is %i\n", x, y);

      //swap
      int tmp = x;
      x = y;
      y = tmp;

      printf("x is %i, y is %i\n", x, y);
  }

