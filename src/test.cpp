#include<iostream>
#include <iomanip>
class test_bmi{
public:
    double bmi=0;
    void test(double height,double weight){
        if(height<=0||weight<=0){
            throw std::invalid_argument("height must>0");
        }


        bmi = weight/(height*height);
        

        if(bmi<18.5){
            std::cout<<"thin and bmi is:"<<bmi<<std::endl;
        }else if(bmi>=18.5&&bmi<24.9){
            std::cout<<"normalnd bmi is:"<<bmi<<std::endl;
        }else if(bmi>24.9&&bmi<29.9){
            std::cout<<"overweight bmi is:"<<bmi<<std::endl;
        }else{
            std::cout<<"fat bmi is:"<<bmi<<std::endl;
        }
    }

    double height;
    double weight;
};

int main(){
    test_bmi t1;
    std::cout<<std::fixed<<std::setprecision(3);
    try{
        std::cout<<"welcome to use your BMI calculator"<<std::endl;
        std::cout<<"please input your height:(m)"<<std::endl;
        std::cin>>t1.height;
        std::cout<<"please input your weight:(kg)"<<std::endl;
        std::cin>>t1.weight;
        t1.test(t1.height,t1.weight);
    }catch(const std::invalid_argument&e){
        std::cerr<<"error:"<<e.what()<<std::endl;
    };
    return 0;
}