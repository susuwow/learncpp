#include<iostream>
using namespace std;
int main(){
    //0打头表示8进制
    int oct = 072;
    //0x打头是16进制
    int hex = 0xab;
    //若不足32位，则默认0填充
    unsigned int  b1 = 0b11111111;
    //'号可以分割数字，看起来更清楚
    int  b2 = 0b1111'1111'1111'1111'1111'1111'1111'1110;
    //用16进制表示浮点数,c++用的是754标准，但是在用16进制表示的时候前面的0x后跟的是16进制的尾数。p后面跟的是10进制的指数，以2为底
    float f1 = 0x10.1p0f;
    double d1 = 0x1ffp10;
    cout<<b1<<endl<<b2<<endl<<oct<<endl<<hex<<endl<<f1<<endl<<d1<<endl;
}