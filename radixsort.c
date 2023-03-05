#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void radix(int *arr, int size,int pos);
int main(){
    srand((int)time(0));
    int n=5,i,max,arr[n];
    for(i=0; i<n; i++)
        arr[i]=rand()%100;
    max=arr[0];
    for(i=0; i<n; i++){
        if(arr[i]>max)
            max=arr[i];
    }
    for(i=1; max/i>0; i*=10){
        radix(arr,n,i);
    }
    for(i=0; i<n; i++)
        printf("%d ",arr[i]);
    return 0;
}
void radix(int *arr, int size,int pos){
    int result[size+1];
    int count[10]={0};
    for(int i=0; i<size; i++){
        count[(arr[i]/pos)%10]++;
    }
    for(int i=1; i<10; i++){
        count[i]+=count[i-1];
    }
    for(int i=size-1; i>=0; i--){
        result[count[(arr[i]/pos)%10]-1]=arr[i];
        count[(arr[i]/pos)%10]--;
    }
    for(int i=0; i<size; i++){
        arr[i]=result[i];
    }
}