#include <stdio.h>
#include <stdlib.h>
int main(void){
      int random;
      int i;
      int rd;
  for ( i = 0; i < 40; i++)
  {
     rd = rand() % 31;
     printf( " numero " "%d" , rd  );

    if (rd == 30)
    {
    printf( " ERROR "  );
     }
     printf("\n\n");
  }
  
}
