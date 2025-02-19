#include<iostream>
#include<cstdlib> //random num
#include<limits>
#include<ctime>
#include<algorithm>

int main(){
    int secretNum;
    int diffculty;
    int usrGuess;
    int maxAttemps;
    int attemps=0;
    
    srand(static_cast<unsigned int>(time(0)));
    std::cout<<"input your level:(1-3)"<<std::endl;

    std::cin>>diffculty;
    switch(diffculty){
        case 1:
            secretNum=rand() % 50 + 1;
            maxAttemps = 10;
            std::cout<<"you select easy level"<<std::endl;
            break;
        case 2:
            secretNum=rand() % 100 + 1;
            maxAttemps = 7;
            std::cout<<"you select middle level"<<std::endl;
            break;
        case 3:
            secretNum = rand() % 200 + 1;
            maxAttemps = 5;
            std::cout<<"you select diffcult level"<<std::endl;
            break;
        default:
            std::cout<<"invalid input game over"<<std::endl;
            return 1;
    }

    std::cout<<"num is ready now you can guess:"<<std::endl;

    while(attemps<=maxAttemps){
        std::cout<<"please input your guess remainning times: "<<maxAttemps-attemps<<std::endl;
        std::cin>>usrGuess;
        //input problem
        if(std::cin.fail()){
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        attemps++;
        if(usrGuess>secretNum){
            std::cout<<"too big"<<std::endl;
            continue;
        }else if(usrGuess<secretNum){
            std::cout<<"too small"<<std::endl;
        }else{
            std::cout<<"correct!!! num is :"<<secretNum<<"you use "<<attemps<<"  times"<<std::endl;
            return 0;
        }
        
     
    }
    std::cout<<"pity you fail"<<std::endl;
    return 0;
}
