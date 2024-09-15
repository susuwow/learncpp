#include<iostream>
using namespace std;
int main(){
    //窄化初始化，即编译器检验在赋值过程中-1.9能否被int类型的变量n表示，若不能直接编译报错
    int n = {-1.9};

    unsigned int u = 1u;

    int i = {u};

    long l1 = {1234567890123};
    //l1转换成double的时候丢失了精度
    long l2 = l1+1.0f-1.0;
    long l3 = l1+(1.0f-1.0);


    cout<<n<<endl<<i<<endl<<double(l1)<<endl<<l2<<endl<<l3<<endl;
}