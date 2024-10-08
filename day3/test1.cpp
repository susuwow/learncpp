#include<iostream>
#include<fstream>

struct can_not_open_file{};

int main(){
    bool try_open=true;

    do{
        try{
            std::string fname;
            std::cin>>fname;
            std::fstream ofs(fname);
            if(!ofs.is_open()){
                throw can_not_open_file{};//若抛出异常，运行到这一行节结束了，直接去找对应的catch代码块
            }
            try_open=false; 
        }catch(const can_not_open_file& e){
            std::cerr<<"cannot_open_file \n";
            //try_open=true; 
        }

    }while(try_open);
}