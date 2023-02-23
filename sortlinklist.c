#include<stdio.h>
#include<string.h>
#include<time.h>
struct student{
    int roll;
    char name[100];
    float cgpa;
    struct student *ptr;
}s[5],temp,*head;
int main(){
    time_t initial,final;
    initial = time(NULL);
    int i,j;
    for(i=0; i<5; i++){
        printf("Enter %dth roll: ",i+1);
        scanf("%d",&s[i].roll);
        scanf("%c");
        printf("Enter %dth name: ",i+1);
        scanf("%s",&s[i].name);
        printf("Enter %dth cgpa: ",i+1);
        scanf("%f",&s[i].cgpa);
        s[i].ptr=NULL;
    }
    for(i=0; i<5; i++){
        for(j=i; j<5; j++){
            if(s[i].cgpa<s[j].cgpa){
                strcpy(temp.name,s[j].name);
                temp.roll=s[j].roll;
                temp.cgpa=s[j].cgpa;
                strcpy(s[j].name,s[i].name);
                s[j].roll=s[i].roll;
                s[j].cgpa=s[i].cgpa;
                strcpy(s[i].name,temp.name);
                s[i].roll=temp.roll;
                s[i].cgpa=temp.cgpa;
            }
        }
    }
    head=&s[0];
    for(i=0; i<4; i++){
        s[i].ptr=&s[i+1];
    }
    i=0;
    while(head){
        printf("%s\n",head->name);
        head=s[i].ptr;
        i++;
    }
    final=time(NULL);
    printf("Total time: %ld\n",final-initial);
    return 0;
}