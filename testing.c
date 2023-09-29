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

    // char *num[] = {"2", "5", "8", "9"};
    // // char arr[]= "Jane";
    // char buf[10];
    // char *buff = buf;

    // char buf2[10];
    // char *buff2 = buf2;

    // int num1;
    // int num2;
    // int sum;


    // for (int i = 0; i < 4; i++)
    // {
    //     if (i==0)
    //     {
    //         strcpy(buff, num[i]);
    //     }
    //     if(i==2)
    //     {
    //         strcat(buff, num[i]);
    //     }
    //     if(i==1)
    //     {
    //         strcpy(buff2, num[i]);
    //     }
    //     if(i==3)
    //     {
    //         strcat(buff2, num[i]);
    //     }
        
    // }

    // printf("%d + %d = %d", atoi(buff), atoi(buff2), atoi(buff) + atoi(buff2));
    



    char name[20];
    char *name1 = name;
    char c = ' ';

    
    printf("Enter Name: ");
    fgets(name1, 20, stdin);
    // scanf("%s", name1);
    
    int len = strlen(name1);
    // name[len - 1] = '\0';

    // printf("\nYou entered: %s", name1);

    char buf[10];

    for(int i; i < len - 1; i++)
    {
        if(name1[i] == ' ')
        {
            printf("Empty String\n");
        }
        else
        {
            printf("%c\n", name1[i]);
        }
    }
    


    printf("\n");
    return(0);
}