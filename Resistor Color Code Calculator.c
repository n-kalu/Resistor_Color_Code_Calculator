#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>

#define GOLD_TOLERANCE 5
#define SILVER_TOLERANCE 10


int calculation(int *n);
void clearBuffer();

int main()
{
    printf("\n");

    int ncb;
    int *ncBands = &ncb;

    printf("--------------------RESISTOR COLOR CODE CALCULATOR-----------------\n\n");

    //Ask user to input number of color bands for the resistor.
    printf("Number of Color Bands: ");
    scanf("%d", ncBands);

    //clear the stdin buffer after "scanf()".
    clearBuffer();


    calculation(ncBands);
   

    printf("\n");
    return(0);
}

void clearBuffer()
{
    while (getchar() != '\n'){ }
}

int calculation(int *n)
{
    //Band Colors in words placed in Array. 
    char sCol[20];
    char *selCol = sCol;
    char *color[] = {"black", "brown", "red", "orange", "yellow", "green", "blue", "violet", "grey", "white", "gold", "silver"};

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
    char *bColNumBuff = buff;

    int tol, tCoeff;
    double bMult;
    double *bMultiP = &bMult;
    int *tolerance = &tol;
    int *tCoefficient = &tCoeff;

    double res;
    double *resistance = &res;
    
    switch (*n)
    {
    case 3:
        for(int i = 0; i < *n; i++)
        {
            //Present different instruction to the user depending on which band color is to be entered(e.g. Multiplier, Tolerance, etc).
            if(i < 2)
            {
                printf("\nEnter Band color %d: ", i + 1);
                fgets(selCol, 20, stdin);
                // scanf("%s", selCol);
                // clearBuffer();
            }
            else
            {
                printf("\nEnter Multiplier Band Color: ", i + 1);
                fgets(selCol, 20, stdin);
                // scanf("%s", selCol);
                // clearBuffer();
            }
            
            //Remove the trailing '\n' character from the input supplied by the user so the string matches a string defined in teh "color" array.  
            int length = strlen(selCol);
            selCol[length - 1] = '\0';

            for(int j = 0; j < 12; j++)
            {
                //Convert string input from user to lowercase
                char lwrSelCol[20];
                strcpy(lwrSelCol, strlwr(selCol));
                
                //Compare string input from user with the string defined in the "color" array.
                if(strcmp(lwrSelCol, color[j]) == 0)
                {
                    if (i == 0)
                    {
                        //Show Error if user enters "gold" or "silver" for the first entry (Note that this is for a resistor with 3 color bands). Exit the application afterwards.
                        if(strcmp(lwrSelCol, "gold") == 0 || strcmp(lwrSelCol, "silver") == 0)
                        {
                            printf("\nERROR: '%s' is a Multiplier color. Please try again!", lwrSelCol);
                            return (1);
                        }
                        else
                        {
                            /*Copy corresponding(already defined) numerical equivalent(stored in the "nband" array) of the color the user 
                              entered in the stdin terminal into the "bColNumBuff" buffer.*/
                            strcpy(bColNumBuff, nband[j]);
                        }
                    }
                    else
                    {
                        if(i < (*n - 1))
                        {
                            //Show Error if user enters "gold" or "silver" for the second entry (Note that this is for a resistor with 3 color bands). Exit the application afterwards.
                            if(strcmp(lwrSelCol, "gold") == 0 || strcmp(lwrSelCol, "silver") == 0)
                            {
                                printf("\nERROR: '%s' is a Multiplier color. Please try again!", lwrSelCol);
                                return (1);
                            }
                            else
                            {
                                /*Copy corresponding(already defined) numerical equivalent(stored in the "nband" array) of the color the user 
                                  entered in the stdin terminal into the "bColNumBuff" buffer.*/
                                strcat(bColNumBuff, nband[j]);
                            }
                        }
                        else
                        {
                            // //Multiplier color band code
                            *bMultiP = multP[j];
                        }
                    }
                    //break out of this iteration if the color that the user input is correct and matches the corresponding color in the "color" array.
                    break;
                }
                else
                {
                    //Output Error Message if the user enters an invalid color then exit the application. 
                    if(j == 11)
                    {
                        printf("\nERROR: '%s' is an Invalid Color. Please try again!", lwrSelCol);
                        return (1);
                    }
                }
            }

        }

        //convert string to int using "atoi", then multiply by the value of the "Multiplier" band
        *resistance = atoi(bColNumBuff) * (*bMultiP);

        //Ohm symbol can be displayed using "\u2126"
        printf("\n\nRESISTANCE = %.2lf \u2126", *resistance);
        break;

    case 4:
        printf("Case 4");
        break;

    case 5:
        printf("Case 5");
        break;

    case 6:
        printf("Case 6");
        break;
    
    default:
        printf("\nERROR: Wrong Input. The number of Color Bands should be any Integer from 3 to 6");
        break;
    }
    
}