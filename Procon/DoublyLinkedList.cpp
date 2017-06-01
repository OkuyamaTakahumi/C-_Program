#include<iostream>
#include<string>
#include<stdlib.h>
#include<stdio.h>

#include<vector>
#include<list>

using namespace std;

int main(){
  int n, x;
  char com[10];
  list<int> L;
  scanf("%d", &n);
  for(int i=0;i<n;i++){
    scanf("%s", com);
    if(com[0]=='i'){
      scanf("%d", &x);
      L.push_front(x);
    }
    else if(com[6]=='F'){
      L.pop_front();
    }
    else if(com[6]=='L'){
      L.pop_back();
    }
    else {
      scanf("%d", &x);
      for(list<int>::iterator it=L.begin(); it != L.end(); it++){
        if(*it==x){
          L.erase(it);
          break;
        }
      }
    }
  }
  int val = 0;
  for(list<int>::iterator it=L.begin();it!=L.end();it++){
    if(val){
      printf(" ");
    }
    val++;

    printf("%d",*it);
    //val++;
  }
  printf("\n");
  return 0;
}
