#include<iostream>
#include<vector>
#include<initializer_list>
#include<algorithm>
using namespace std;

class sd{
public:
    int data;
    int size;

// explicit sd(int data1,int size):data{data1},size{size}{//explict防止隐式构造
//     cout<<"sd有参构造"<<"\n";
// }
sd(int data1,int size):data{data1},size{size}{
    cout<<"sd有参构造"<<"\n";
}
sd& operator=(const sd &s){
    if(this!= &s){
        this->data=s.data;
        this->size=s.size;
    }
    cout<<"sd赋值构造 \n";
    return *this;
}

sd(const sd &s){
    this->data=s.data;
    this->size=s.size;
    cout<<"sd拷贝构造 \n";
}

};

class ds{    
private:
    int data;
    int size;
    int *datas;
    sd &s;
public:
    // ds(){
    //     cout<<"无参构造 \n";
    // }
    ds(int data=0,int size=0,int* datas=nullptr,sd s={1,2}):data{data},size{size},datas{datas},s{s}{//临时对象无法绑定到非 const 引用
        cout<<"ds带缺省的构造 \n";
    }
    // ds(int data,int size,int* datas,const sd& s):data{data},size{size},datas{datas},s{s}{
    //     cout<<"ds带缺省的构造 \n";
    // }
    int get_data(){
        return data;
    }

    friend void test(const ds& d);//定义友元方法
    friend class friendclass;//定义友元类
};

void test(const ds& d){
    cout<<"友元方法test "<<d.data<<"\n";

}

class friendclass{
    public:
    void test(const ds& d){
        cout<<"友元类的test "<<d.data<<"\n";
    }
};

class myVec{
private:
    int *arr;
    int size;
public:
    myVec(int *arr = nullptr,int size = 0):arr{arr},size{size}{
        cout<<"myVec构造函数 \n";
    }
    myVec(myVec &&m1) noexcept:arr{m1.arr},size(m1.size){
        m1.arr=nullptr;
        m1.size=0;

        cout<<"myVec的移动构造 \n";
    }
    myVec(const initializer_list<int> &values):size(values.size()),arr{new int [size]}{
        copy(begin(values),end(values),arr);
        cout<<"myVec的initializer_list 初始化 拷贝构造\n";
    }

    // myVec& operator=(initializer_list<int> values){
    //     copy(begin(values),end(values),arr);
    //     cout<<"myVec的initializer_list 初始化 重载=构造\n";
    //     return *this;
    // }

    ~myVec(){
        delete []arr;
        size=0;
        cout<<"myVec析构函数 \n";
    }
};

class complex{
private:
    double real;
    double vir;
public:
    complex(double real=0,double vir=0):real{real},vir{vir}{
        cout<<"complex的构造函数 \n";
    }
    complex(const complex& com){
        real=com.real;
        vir=com.vir;
        cout<<"complex的拷贝构造 \n";
    }

    complex& operator=(const complex& com){
        if(this!=&com){
            real=com.real;
            vir=com.vir;
            cout<<"complex的=重载 \n";
        }
        return *this;
    }
};

inline vector<int> ones(int n){
    vector<int> v(n);
    for(unsigned i = 1;i<=n;i++) 
        v[i]=1;
    
    return v;
}

inline myVec oness(int n){
    myVec v;
    return v;
    
}

int main(){
    // ds d;
    // cout<<d.get_data()<<"\n";
    // ds *d1=new ds();
    // cout<<d1->get_data()<<"\n";
    // test(*d1);
    // friendclass fc;
    // fc.test(d);
    // sd s{1,2};

    // sd s{1,2};
    // ds d{0,0,nullptr,{1,2}};
    // myVec *p = new myVec{nullptr,1};
    // delete p;
    // myVec m;

    // complex c{1,1};
    // // complex c1={1,2};
    // complex c2={1};
    // complex c3 = c2;//只要是新赋值操作都是拷贝构造
    // c=c3;
    //complex{1}; //构造出来无名的对象
    // complex c3{c2};

    // myVec v{1,2,3};

    // myVec v1;

    // myVec v2 = move(v);

    myVec w=move(oness(3));
}