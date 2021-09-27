#include <stdio.h>

    int main(){
        int month;
        printf("which season is the montht?");
        scanf("%d", &month);

            switch (month)
            {
            case 12: printf("Winter");
                break;
            case 1: printf("Winter");
                break;
            case 2: printf("Winter");
                break;
            case 3: printf("Spring");
                break;
            case 4: printf("Spring");
                break;
            case 5: printf("Spring");
                break;
            case 6: printf("Summer");
                break;
            case 7: printf("Summer");
                break;
            case 8: printf("Summer");
                break;
            case 9: printf("Autumn");
                break;
             case 10: printf("Autumn");
                break;
             case 11: printf("Autumn");
                break;
            
            
            default: printf("Unknown month");
                break;
            }
        return 0;
    }