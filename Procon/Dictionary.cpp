#include<iostream>
#include<string>
#include<stdlib.h>
#include<stdio.h>
#include<algorithm>

#include<vector>
#include<list>
#include<stack>
#define N 1000003
#define L 14

using namespace std;

long long H[N];


int toInt(char c){
  if(c=='A'){
    return 1;
  }
  else if(c=='C'){
    return 2;
  }
  else if(c=='G'){
    return 3;
  }
  else { //c==T
    return 4;
  }
}

int getKey(char s[]){
  int x = 1;
  int key = 0;
  for(int i=0; s[i]!='\0';i++){
    key += x*toInt(s[i]);
    x *= 4;
  }
  return key;
}

int h1(int key){
  return key%N;
}
int h2(int key){
  return key%(N-1);
}

void insert(char s[]){
  int key = getKey(s);
  int hash = h1(key)%N;

  int i = 1;
  while(H[hash] != 0){
    hash = (h1(key) + i*h2(key))%N;
    i++;
  }
  H[hash] = key;
}

int find(char s[]){
  int key = getKey(s);
  int hash;

  for(int i=0; ;i++){
    hash = (h1(key) + i*h2(key))%N;
    if(H[hash]==key){
      return 1;
    }
    else if(H[hash]==0){
      return 0;
    }
  }
}



int main(){
  int n;
  char cmd[10];
  char str[L];
  scanf("%d",&n);
  for(int i=0; i<n; i++){
    scanf("%s%s",cmd,str);
    if(cmd[0]=='i'){
      insert(str);
    }
    else if(cmd[0]=='f'){
      if(find(str)){
        printf("yes\n");
      }
      else{
        printf("no\n");
      }
    }
  }
  return 0;
}
