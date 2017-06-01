#include<iostream>
#include<string>
#include<stdlib.h>

//#include<algorithm>

//#include<random>
using namespace std;

static const int MAX = 100;

int S[MAX];
int top = 0;

void initialize(){
  top = 0;
}
bool isEmpty(){
  return top == 0;
}
bool isFull(){
  return top >= MAX;
}
void push(int x){
  if(isFull()){
    //cout<<"Stack is full";
    return;
  }
  top++;
  S[top] = x;
}
int pop(){
  if(isEmpty()){
    //cout<<"Stack is empty";
    return 0;
  }
  top--;
  return S[top+1];
}
int main(){
  int x;
  string s ;
  //initialize();
  while(cin >> s){
    if(s == "+"){
      push(pop()+pop());
    }
    else if(s == "-"){
      x = pop();
      push(pop()-x);
    }
    else if(s == "*"){
      push(pop()*pop());
    }
    else{
      push(atoi(s.c_str()));
    }

  }
  cout << pop() << endl;
  return 0;
}
