#include<iostream>

using namespace std;

class myvec{
private:
    int *data;
    int size;
public:
    myvec():data{nullptr},size{0}{}
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

class complex{
private:
    double real;
    double vir;
public:
    complex(double real=0,double vir=0):real{real},vir{vir}{
        cout<<"complex.构造函数\n";
    }
    complex(const complex& com){
        real=com.real;
        vir=com.vir;
        cout<<"complex.拷贝构造 \n";
    };
    int getreal()const{
        cout<<"complex.const getreal\n";
        return real;
    }
    int getreal(){
        cout<<"complex.getreal\n";
        return real;
    }
    int getvir()const {
        cout<<"complex.const getvir\n";
        return vir;
    }

    complex operator+(const complex& com)const {
        /*
        由于返回值优化（RVO）,编译器会直接在目标对象构造新对象，不存在先构造在拷贝的情况
        */
        return complex{real+com.real,vir+com.vir};
    }
};

class dancer{
public:
    void show() &{
        cout<<"dancer.左值对象调用 \n";
    }
    void show() &&{
        cout<<"dancer.右边值对象调用 \n";
    }
};


int main(){
    complex c1{1,2};
    const complex c2{2,3};
/*
    const 对象只能调用const方法，非const对象既能调用const方法也能调用非const方法，const方法修饰成员函数，本质上是在函数体内不允许你修改成员变量的值
*/

    c1.getreal();
    c2.getreal();
    c1.getvir();
    c2.getvir();

/*
    左值对象调用与右值对象调用
*/   

    dancer d;
    d.show();
    move(d).show();
/*
    编译器直接构造c3,而不会先构造中间量
*/
    complex c3=c1+c2;
}