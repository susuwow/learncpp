#include<iostream>
using namespace std;
int main(){
    string name = "123456"s;//申明为string类型
    char name1[] ="123456";

    cout<<name<<endl;
    char *p = name1;
    while(*p!='\0'){
        cout<<*p++<<endl;
    }

}