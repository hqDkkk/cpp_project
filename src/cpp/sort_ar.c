#include<stdio.h>
#include<time.h>
#include<stdlib.h>

#define N 10
void init_arr(int* arr,int length){
	for(int i=0;i<length;i++){
		arr[i] = rand() % 20 +1;
	}

}

void print_arr(int* arry,int length){
	for(int i=0;i<length;i++){
		printf("arr[%d]=%d\n",i,arry[i]);
	}
}

void sort(int* arr1,int len){
	int j,big,tmp;
	for(int i=0;i<len-1;i++){
	      int big=i;
		for(j=i+1;j<len;j++){
			if(arr1[big]>arr1[j]){
				big=j;
			}
				
		}
	if(big!=i){
		int tmp;
		tmp=arr1[i];
		arr1[i]=arr1[big];
		arr1[big]=tmp;
	}	
	}
}

int main(){
	int  arr[N];
	srand(time(NULL));
	init_arr(arr,N);
	print_arr(arr,N);
	sort(arr,N);
	print_arr(arr,N);
	printf("after sort:\n");
	print_arr(arr,N);
	return 0;
}
