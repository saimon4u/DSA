#include<stdio.h>
#include<time.h>
struct student{
    char name[100];
    float cgpa;
    int roll;
    struct student *ptr;
}s[5];
int main(){
    double initial,final;
    initial=(double)clock();
    int i,j,index[5];
    float cg[5],temp;
    for(i=0; i<5; i++){
        printf("Enter %dth roll: ",i+1);
        scanf("%d",&s[i].roll);
        scanf("%c");
        printf("Enter %dth name: ",i+1);
        gets(s[i].name);
        printf("Enter %dth cgpa: ",i+1);
        scanf("%f",&s[i].cgpa);
        cg[i]=s[i].cgpa;
        s[i].ptr=NULL;
    }
    for(i=0; i<5; i++){
        for(j=i; j<5; j++){
            if(cg[i]<cg[j]){
                temp=cg[i];
                cg[i]=cg[j];
                cg[j]=temp;
            }
        }
    }
    for(i=0; i<5; i++){
        for(j=0; j<5; j++){
            if(cg[i]==s[j].cgpa){
                index[i]=j;
                break;
            }
        }
    }
    for(i=0; i<4; i++){
        s[index[i]].ptr=&s[index[i+1]];
    }
    puts(s[index[0]].name);
    for(i=0; i<4; i++){
        printf("%s\n",s[index[i]].ptr->name);
    }
    final=(double) clock();
    printf("Total time: %lf\n",(double)((final-initial)/CLOCKS_PER_SEC));
    return 0;
}