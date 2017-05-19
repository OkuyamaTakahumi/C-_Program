#include <stdio.h>
  #include <stdlib.h>
  
  #define BSIZE 5
  
  int main()
  {
          int n;
          char buf[BSIZE];
  
          n = read(0,buf,BSIZE);
          write(1,buf,n);
          exit(0);
  }
