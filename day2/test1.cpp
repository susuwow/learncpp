#include<iostream>
using namespace std;
int main(){
    int op=0;
    int nums[]={1,2,3,4,5,6,7,8,9};

//c++11新特性
    for(int i:nums)
        op+=i;
//c++20新特性，支持在for循环中定义数组并且使用
    for(int prime[]={1,2};int i:prime)
        op+=i;


//fallthrough 避免应为没有break的警告
    switch(op){
        case 1:break;
        case 2:op+=2;[[fallthrough]];
        default:break;
    }

    cout<<op<<endl;
}