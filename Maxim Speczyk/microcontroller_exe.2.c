#include <stdio.h>

int main(int fun){
    int x;
    do{
        printf("Do you want a loop\n1 for yes\n");
        scanf("%d", &fun);

        if(fun == 1)
        {
            x = 1;
        }
        else
        {
            x=2;
        }
    }while(x == 1);
}