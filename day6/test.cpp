#include<iostream>
using namespace std;

/*
    无论模板函数传入的参数是什么类型，a的类型都是传入的参数原本的类型去掉引用符&
*/

template <typename T>
void f1(T& a){
    a=2;
    cout<<a<<"\n";
}

class myvec{
private:
    int *data;
    int size;
public:
    myvec():data{nullptr},size{0}{}

    myvec(myvec&& v){
        data=v.data;
        size=v.size;
        cout<<"myvec.移动构造 \n";
    }

    //const  和非const函数可以使得函数重载
    int& operator[](int i){
        return data[i];
    }
    /*
        const & 作返回值本质上就是不允许 函数调用者修改返回值
    */
    const int& operator[](int i)const {
        return data[i];
    }
};
int main(){
    int i=1;
    int &i1=i;
    const int &i2=i;
    // f1(0);
    f1(i);
    f1(i1);
    f1(i2);
}