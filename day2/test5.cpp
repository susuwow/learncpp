#include<iostream>
using namespace std;
//使用[[nodiscard]]来表示当前函数的返回值必须要被使用，
//表现为必须在调用处使用变量去接收该返回值，否则编译即使通过了，也会发出警告
[[nodiscard]]int add(int i1,int i2){
    return i1+i2;
}
int main(){
    int i = add(1,2);
}