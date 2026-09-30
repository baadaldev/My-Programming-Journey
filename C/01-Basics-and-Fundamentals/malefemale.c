#include <stdio.h>
int main (){
    int gender,marks;
    printf("Enter your gender:");
     scanf("%d", &gender);
    printf("Enter your marks:");
    scanf("%d", &marks);
    switch (gender)
    {
        case 1:
            printf("You are male\n");
            switch (marks)
            {
            case 40:
                printf("You have scored 40 marks\n");
                break;
            
            default:
                printf("You have not scored 40 marks\n");
                break;
            }
            break;
        case 2:
            printf("You are female\n");
            switch (marks)
            {
                case 50:
                printf ("you have scored 50 marks\n");
                break;
                default:
                printf("You have not scored 50 marks\n");
            }
            break;
        default:
            printf("You are not male or female\n");
            break;
    }
    return 0;
}