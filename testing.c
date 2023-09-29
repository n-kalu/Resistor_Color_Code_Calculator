#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

int main()
{
    printf("\n");

    // char name1[20];
    // char *ptr1 = name1;

    // char *name2[] = {"michael", "emeka", "jane"};

    // printf("Enter First Name: ");
    // fgets(ptr1, 20, stdin);
    // int len1 = strlen(ptr1);
    // name1[len1 - 1] = '\0';
    
    // char buf[20];    
    // if(strcmp(ptr1, name2[2]) == 0)
    // {
    //     printf("\nNames Match");
    // }
    // else
    // {
    //     printf("\nNames do not match");
    //     // printf("Length of string: %d", len);
    // }
    // printf("\nBig Number: %.lf", 1e9);

    char *num[] = {"2", "5", "8", "9"};
    char arr[]= "Jane";
    char buf[10];
    char buf2[10];

    int num1;
    int num2;
    int sum;


    for (int i = 0; i < 4; i++)
    {
        if (i==0)
        {
            strcpy(buf, num[i]);
        }
        if(i==2)
        {
            strcat(buf, num[i]);
        }
        if(i==1)
        {
            strcpy(buf2, num[i]);
        }
        if(i==3)
        {
            strcat(buf2, num[i]);
        }
        
    }

    printf("%d + %d = %d", atoi(buf), atoi(buf2), atoi(buf) + atoi(buf2));
    

    printf("\n");
    return(0);
}