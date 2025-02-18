#include<iostream>
#include<iomanip>
class Bmi{
public:
    void cal(double h,double w){
        if(h<0||w<0){
            throw std::invalid_argument("your in must be >0");
        }
        bmi = w/(h*h);
        if(bmi>0&&bmi<18.5){
            std::cout<<"thinner and bmi is : "<<bmi<<std::endl;

        }else if(bmi>18.5&&bmi<24.9){
            std::cout<<"normal and bmi is : "<<bmi<<std::endl;
        }else if(bmi>24.9&&bmi<29.9){
            std::cout<<"overweight and bmi is : "<<bmi<<std::endl;
        }else{
            std::cout<<"fat and bmi is : "<<bmi<<std::endl;
        }
        return;
    }



    double bmi;
    double h;
    double w;
};



int main(){
    Bmi b1;
    std::cout<<std::fixed<<std::setprecision(13);
    try{
        //input
        std::cout<<"input your height:"<<std::endl;
        std::cin>>b1.h;
        std::cout<<"input your weight:"<<std::endl;
        std::cin>>b1.w;
        //calculate
        b1.cal(b1.h,b1.w);

    }catch(const std::invalid_argument&e){
        std::cerr<<e.what()<<std::endl;
    }
    

    return 0;
}