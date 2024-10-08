#include<iostream>
using namespace std;


//函数重载

void f(int i){
    cout<<"int i"<<endl;
}
void f(const int & i){
    cout<<"const int & i"<<endl;
}
void f(int & i){
    cout<<"int & i"<<endl;
}

int main(){
    int i=3;
    f(i);
}