#include<iostream>
#include<map>
using namespace std;
int main(){

    // C++ 中，std::map 的 insert 方法返回的是一个 std::pair，其中包含两个元素：
    //第一个元素：一个指向新插入元素或已存在元素的迭代器（iterator）。
    //第二个元素：一个 bool 类型的值，表示是否成功插入。如果插入成功，值为 true；如果键已经存在，值为 false。

    //这里在if的判断括号中使用map的insert方法插入一个数据，返回的pair元组是只有本if语句中可以使用
    map<string,double> contants={{"srl",1.0},{"pi",3.141592654}};
    if(auto result = contants.insert({"ss",9.0});result.second){
        cout<<result.first->first<<endl<<result.second<<endl;
    }else{
        result.first->second;
    }
    
}