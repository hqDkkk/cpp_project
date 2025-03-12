#include<iostream>
#include<string>
class Test{
public:
    Test(const std::string& name_,unsigned old_);
    ~Test();
    void outPut()const{
        std::cout<<"name:"<<this->name<<"     old:"<<this->old<<std::endl;

    }

    void setName(const std::string&name){
        this->name = name;        
    }
private:
    std::string name;
    unsigned old;

};


Test:: Test(const std::string& name_,unsigned old_):name(name_),old(old_){


}

Test::~Test(){

}





int main(){
    Test t1("lucy",20);
    t1.setName("wangda");
    t1.outPut();
    
    Test t2("opp",36);
    t2.setName("afoiah");
    t2.outPut();

    return 0;
}