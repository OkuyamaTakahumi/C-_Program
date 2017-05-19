#include <iostream>
#include <string>
#include<math.h>
using namespace std;

int main() {
   
   int money=120;
   char kigo='m';
   int count=0;

   if(money>=120 && kigo=='m'){
      count+=1;
   }
	   
   count += (money<20) ? 1:5;


   switch(money){
      case 10:
	      count+=1;
	      break;
      case 120:
	      count+=10;
	      break;
      default:
	      count+=100;
              break;
   }
    
   cout<<count<<endl;	   
	   
   return 0;
}
