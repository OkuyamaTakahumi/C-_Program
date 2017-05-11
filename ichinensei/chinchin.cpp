#include <iostream>
#include <string>
#include<math.h>
using namespace std;

int main(){
	srand((unsigned)time(NULL));
	
	for(int i = 0;i<10;i++){
		int x=rand()%4+1;
	
		switch(x){
			case 1:
			cout<<"大吉 "<<x<<endl;
			break;
			
			case 2:
			cout<<"中吉 "<<x<<endl;
			break;
			
			case 3:
			cout<<"吉 "<<x<<endl;
			break;
			
			
	}
	
	
	
	
	
	}
	return 0;
}