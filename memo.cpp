#include<iostream>
#include<string>
#include<stdlib.h>
#include<stdio.h>
#include<algorithm>

#include<vector>
#include<list>
#include<stack>

#define N 5
using namespace std;



int main(){
  int A[120]={1,2,3,4,5,6,7,8,9,10};
  for(int i=0;A[i]!=0;i++){
    cout<<A[i]<<" ";
  }
  cout<<endl;

  cout<<5/2<<endl; //2

  cout<<N<<endl; //5

  /*
  char str[20];
  char t[20];
  for(int i=0;i<5;i++){
     scanf("%s%s",str,t);
  }
  */
  char s[120]="okuyamatakahfumi";
  for(int i=0;s[i]!='\0';i++){ //s[i]が空になるまで
    cout<<s[i]<<" ";
  }
  cout<<endl;

  char str1[] = "ABC";
  char str2[] = "ABC";
  char str3[] = "ABD";
  char str4[] = "AAAA";
  //strcmp -> 文字列が一致してたら0
  printf("strcmp(%s, %s) = %d\n", str1, str2, strcmp(str1, str2));//0
  printf("strcmp(%s, %s) = %d\n", str1, str3, strcmp(str1, str3));//-1or1
  printf("strcmp(%s, %s) = %d\n", str1, str4, strcmp(str1, str4));//-1or1
  strcpy(str2,str4);//str2にstr4をコピー
  printf("%s\n",str2);
  cout<<strlen(str3)<<endl;//文字数を取得




  return 0;
}
