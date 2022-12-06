  #include <stdio.h>

  int main(void)
  {
      int x = 1; //index kiri atas
      int y = 2; //index kanan atas

      int tmp = x;
      x = y;
      y = tmp;

      printf("x is %i, y is %i\n", x, y);
      //swap(&x, &y);
      printf("x is %i, y is %i\n", x, y);
  }

