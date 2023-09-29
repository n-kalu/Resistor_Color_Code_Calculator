#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>

#define GOLD_TOLERANCE 0.05
#define SILVER_TOLERANCE 0.10

double calculation(int *n);
void clearBuffer();

int main()
{
    printf("\n");

    int ncb;
    int *ncBands = &ncb;

    // char col[10];
    // char *bColor = col;
    
    
    printf("--------------------RESISTOR COLOR CODE CALCULATOR-----------------\n\n");

    //Ask user to input number of color bands for the resistor.
    printf("Number of Color Bands: ");
    scanf("%d", ncBands);
    clearBuffer();
    // printf("\n");


    calculation(ncBands);
   

    printf("\n");
    return(0);
}

void clearBuffer()
{
    while (getchar() != '\n'){ }
}

double calculation(int *n)
{
    //Band Colors in words placed in Array. 
    char sCol[20];
    char *selCol = sCol;
    char *color[] = {"black", "brown", "red", "orange", "yellow", "green", "blue", "violet", "grey", "white", "gold", "silver"};

    //Variables to store color in words
    // char co[7];
    // char *col = co;

    //Corresponding numbers for band color in Array
    char *nband[] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};

    //Corresponding Multiplier array
    double mult[] = {1, 10, 100, 1e3, 10e3, 100e3, 1e6, 10e6, 100e6, 1e9, 0.1, 0.01};
    double *multP = mult;

    //Corresponding Tolerance
    double to[] = {0, 1, 2, 0.05, 0.02, 0.5, 0.25, 0.1, 0.01, 0, 5, 10};
    double *tole = to;

    //Corresponding Temperature Coefficient
    int tc[] = {250, 100, 50, 15, 25, 20, 10, 5, 1};
    int *tempCon = tc;


    //Variables to store color in numbers
    char bCol[10];
    char *bColNum = bCol;
    char buff[10];
    // char *bColNumBuff = buff;

    int bMult, tol, tCoeff;
    int *bMultiP = &bMult;
    int *tolerance = &tol;
    int *tCoefficient = &tCoeff;

    double res;
    double *resistance = &res;

    
    switch (*n)
    {
    case 3:
        for(int i = 0; i < *n; i++)
        {
            printf("\nEnter Band color %d: ", i + 1);
            fgets(selCol, 20, stdin);
            
            //Remove the trailing '\n' character from the input supplied by the user. 
            int length = strlen(selCol);
            selCol[length - 1] = '\0';

            for(int j = 0; j < 12; j++)
            {
                if(strcmp(selCol, color[j]) == 0)
                {
                    if (i == 0)
                    {
                        strcpy(buff, band);
                        // printf("%d", nBand[j]);
                    }
                    else
                    {
                        if(i < (*n - 1))
                        {
                            // strcat(bColNumBuff, nBand + j);
                            // printf("\n%d", nBand[j]);
                            strcpy(buff, band);
                            // printf("\nYou Entered: %c", bColNumBuff[0]);
                            
                        }
                        else
                        {
                            *bMultiP = multP[j];
                            
                        }
                        
                    }
                    
                }
            }

        }

        // *resistance = atoi(*bColNumBuff) * (*bMultiP);
        // printf("Hello");
        break;

    case 4:
        /* code */
        break;

    case 5:
        /* code */
        break;

    case 6:
        /* code */
        break;
    
    default:
        break;
    }
    
    return *resistance;
}