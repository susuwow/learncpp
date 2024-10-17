#include<iostream>
using namespace std;

class sd{
public:
    int data;
    int size;

// explicit sd(int data1,int size):data{data1},size{size}{
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
    ds d{0,0,nullptr,{1,2}};
}