#include<iostream>

int fabonaci(int n,int depth=0,int maxdepth=1000){
    if(depth>maxdepth){
        return -1;
    }
    if(n<=0){
        return 0;
    }
    if(n==1){
        return 1;
    }
    return fabonaci(n-1,depth+1,maxdepth)+fabonaci(n-2,depth+2,maxdepth);
    
    
}


int main(){
    int n;
    std::cout<<"input the num of arrlist"<<std::endl;
    std::cin>>n;
    std::cout<<"result is:"<<fabonaci(n)<<std::endl;
    return 0;
}