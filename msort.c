#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void sort(int *arr,int *temp,int left, int right);
void merge(int *arr, int *temp,int leftpos,int rightpos, int rightinsert);
int main(){
    double start,end;
    start=(double)clock();
    int n=1000;
    int arr[n],temp[n],i,j;
    for(i=0; i<n; i++)
        arr[i]=rand()%10000;
    sort(arr,temp,0,n-1);
    for(i=0; i<n; i++)
        printf("%d\n",arr[i]);
    end=(double)clock();
    printf("Time takes to complete this code: %lf seconds.\n",(double)((end-start)/CLOCKS_PER_SEC));
    return 0;
}
void sort(int *arr, int *temp, int left, int right){
    int mid;
    if(left<right){
        mid=(left+right)/2;
        sort(arr,temp,left,mid);
        sort(arr,temp,mid+1,right);
        merge(arr,temp,left,mid+1,right);
    }
}
void merge(int *arr, int *temp, int leftpos, int rightpos, int rightinsert){
    int leftinsert,temppos,i,elementnumber;
    elementnumber=rightinsert-leftpos+1;
    leftinsert=rightpos-1;
    temppos=leftpos;
    while(leftpos<=leftinsert && rightpos<=rightinsert){
        if(arr[leftpos]<arr[rightpos])
            temp[temppos++]=arr[leftpos++];
        else
            temp[temppos++]=arr[rightpos++];
    }
    while(leftpos<=leftinsert)
        temp[temppos++]=arr[leftpos++];
    while(rightpos<=rightinsert)
        temp[temppos++]=arr[rightpos++];
    for(i=0; i<elementnumber; i++){
        arr[rightinsert]=temp[rightinsert];
        rightinsert--;
    }
}