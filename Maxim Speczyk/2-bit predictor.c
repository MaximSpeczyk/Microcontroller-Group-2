#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<float.h>
#include <unistd.h>

int correct = 0;
int x = 0;
                //1 = Strong - Not taken
                //2 = Weak - Not taken
                //3 = Weak - Taken
                //4 = Strong - Taken

int main(){

    int loop;

    printf("How often do you want the computer to predict?\n");
    scanf("%d",&loop);

    while(x<loop){


    int predict = rand() % 4;
    int number1 = rand() % 2;
    int number2 = rand() % 2;
    
    if(predict==0){
        printf("\nThe computer predicts Strong - Not taken\n");
    }
    else if(predict==1){
        printf("\nThe computer predicts Weak - Not taken\n");
    }
    else if(predict==2){
        printf("\nThe computer predicts Weak - Taken\n");
    }
    else{
        printf("\nThe computer predicts Strong - Taken\n");
    }

    printf("\n%d\n",predict);
    printf("%d%d\n",number1,number2);
    int status;
    if(number1==0 && number2==0){
        printf("Strong - Not taken\n");
        status = 1;
    }
    else if(number1==0 && number2==1){
        printf("Weak - Not taken\n");
        status = 2;
    }
        else if(number1==1 && number2==0){
        printf("Weak - Taken\n");
        status = 3;
    }
    else{
        printf("Strong - Taken\n");
        status = 4;
    }
    
    if(status==1 && predict==0||status==2 && predict==1||status==3 && predict==2||status==4 && predict==3){
        printf("The computer was correct\n");
        x++;
        correct++;
    }
    else{
        printf("The computer was not correct\n");
        x++;
    }

    }
    printf("\nThe prediction rate is %.2f ",correct/loop);
    return 0;
}