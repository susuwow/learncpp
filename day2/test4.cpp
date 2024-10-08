#include<iostream>
#include<cassert>
#include<cmath>

//宏定义 DNDEBUG在编译的时候使用g++ test4.cpp -o test4 -O3 -DNDEBUG来禁用所有assert
#define DNDEBUG

using namespace std;
int main(){
    int i=4;
    //assert函数检查传入的表达式的值是否为true，若为false则直接停止程序执行
    assert(sqrt(i)>=0);
    return 0;
}