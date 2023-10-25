#include "Calculate.h"

//This variable/buffer was created to hold the color input from the user after it has been stripped of all empty characters.
//See the "removeEmptyCharacters()" & "calculation()" functions for it's use.
//Large size(100) allocated to array to accomodate crazy amounts of empty character from the user so as not to break the code.
char bu[100];
char *colBuff = bu;

//This variable stores the length of the "colBuff" variable/array.
int lenB;

//Clear the Stdin Buffer.
void clearBuffer()
{
    while (getchar() != '\n'){ }
}

char *removeEmptyCharacters(char *coll)
{
    int lenC = strlen(coll);    
    lenB = strlen(colBuff);

    //Empty the colBuff buffer/array if there is already existing data.
    if(lenB > 1)
    {
        for(int m = 0; m < lenB; m++)
        {
            colBuff[m] = '\0';
        }
    }

    int j = 0;

    //Ignore empty characters and copy actual color input from the user into "colBuff".
    for(int i = 0; i < lenC - 1; i++)
    {
        if(coll[i] != ' ')
        {         
            colBuff[j] = coll[i];
            j++;
        }
        else
        {
            //Do Nothing!
        }
    }
    return colBuff;
}

int calculation(int *n)
{
    //Band Colors in words placed in Array. 
    //Large size(100) allocated to array to accomodate crazy amounts of empty character from the user so as not to break the code.
    char sCol[100];
    char *selCol = sCol;
    char *color[] = {"black", "brown", "red", "orange", "yellow", "green", "blue", "violet", "grey", "white", "gold", "silver"};

    //Corresponding numbers for band color in Array
    char *nband[] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};

    //Corresponding Multiplier array
    double mult[] = {1, 10, 100, 1e3, 10e3, 100e3, 1e6, 10e6, 100e6, 1e9, 0.1, 0.01};
    double *multP = mult;

    //Corresponding Tolerance
    char *tole[] = {"0", "1% (F)", "2% (G)", "0.05% (W)", "0.02% (P)", "0.5% (D)", "0.25% (C)", "0.1% (B)", "0.01% (L)", "0", "5% (J)", "10% (K)"};

    //Corresponding Temperature Coefficient
    char *tempCon[] = {"250 ppm/K (U)", "100 ppm/K (S)", "50 ppm/K (R)", "15 ppm/K (P)", "25 ppm/K (Q)", "20 ppm/K (Z)", "10 ppm/K (Z)", "5 ppm/K (M)", "1 ppm/K (K)", "0", "0", "0"};

    //Variables to store color in numbers
    char bCol[10];
    char *bColNum = bCol;

    char buff[10];
    char *bColNumBuff = buff;

    double bMult;
    double *bMultiP = &bMult;

    char tCoeff[30];
    char *tCoefficient = tCoeff;

    char tol[20];
    char *tolerance = tol;
     
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
                fgets(selCol, 100, stdin);

                //Remove all empty characters from the input provided by user
                removeEmptyCharacters(selCol);       
            }
            else
            {
                printf("\nEnter Multiplier Band Color: ", i + 1);
                fgets(selCol, 100, stdin);

                //Remove all empty characters from the input provided by user. This returns the "colBuff"variable which now replaces the "selCol" variable.
                removeEmptyCharacters(selCol);
            }
            
            //Convert string input from user to lowercase. Use the string stored in "colBuff" instead of the one stored in "selCol".
            char lwrSelCol[100];
            strcpy(lwrSelCol, strlwr(colBuff));

            for(int j = 0; j < 12; j++)
            {
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
                            //Copy corresponding(already defined) numerical equivalent(stored in the "nband" array) of the color the user 
                            //entered in the stdin terminal into the "bColNumBuff" buffer
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
                                //Copy corresponding(already defined) numerical equivalent(stored in the "nband" array) of the color the user 
                                //entered in the stdin terminal into the "bColNumBuff" buffer.
                                strcat(bColNumBuff, nband[j]);
                            }
                        }
                        else
                        {
                            //Multiplier color band code
                            *bMultiP = multP[j];
                        }
                    }

                    //break out of this iteration if the color that the user input is correct and matches the corresponding color in the "color" array.
                    break;
                }
                else
                {
                    //Error Message if the user enters an invalid color (after comparing it to each element of the "color" array) then exit the application. 
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
        printf("\n\nRESISTANCE = %.2lf Ohms", *resistance);
        break;

    case 4:
         for(int i = 0; i < *n; i++)
         {
            //Present different instruction to the user depending on which band color is to be entered(e.g. Multiplier, Tolerance, etc).
            if(i < 2)
            {
                printf("\nEnter Band color %d: ", i + 1);
                fgets(selCol, 100, stdin);

                //Remove all empty characters from the input provided by user
                removeEmptyCharacters(selCol);       
            }
            else if(i == 2)
            {
                printf("\nEnter Multiplier Band Color: ", i + 1);
                fgets(selCol, 100, stdin);

                //Remove all empty characters from the input provided by user. This returns the "colBuff"variable which now replaces the "selCol" variable.
                removeEmptyCharacters(selCol);

            }
            else
            {
                printf("\nEnter Tolerance Band Color: ", i + 1);
                fgets(selCol, 100, stdin);

                //Remove all empty characters from the input provided by user. This returns the "colBuff"variable which now replaces the "selCol" variable.
                removeEmptyCharacters(selCol);
            }
            
            //Convert string input from user to lowercase. Use the string stored in "colBuff" instead of the one stored in "selCol".
            char lwrSelCol[100];
            strcpy(lwrSelCol, strlwr(colBuff));

            for(int j = 0; j < 12; j++)
            {
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
                            //Copy corresponding(already defined) numerical equivalent(stored in the "nband" array) of the color the user 
                            //entered in the stdin terminal into the "bColNumBuff" buffer
                            strcpy(bColNumBuff, nband[j]);
                        }
                    }
                    else
                    {
                        if(i == 1)
                        {
                            //Show Error if user enters "gold" or "silver" for the second entry (Note that this is for a resistor with 3 color bands). Exit the application afterwards.
                            if(strcmp(lwrSelCol, "gold") == 0 || strcmp(lwrSelCol, "silver") == 0)
                            {
                                printf("\nERROR: '%s' is a Multiplier color. Please try again!", lwrSelCol);
                                return (1);
                            }
                            else
                            {
                                //Copy corresponding(already defined) numerical equivalent(stored in the "nband" array) of the color the user 
                                //entered in the stdin terminal into the "bColNumBuff" buffer.
                                strcat(bColNumBuff, nband[j]);
                            }
                        }
                        else if(i == 2)
                        {
                            //Multiplier color band code
                            *bMultiP = multP[j];
                        }
                        else
                        {
                            if(strcmp(lwrSelCol, "black") == 0 || strcmp(lwrSelCol, "white") == 0)
                            {
                               strcpy(tolerance, "No Tolerance");
                            }
                            else
                            {
                                strcpy(tolerance, tole[j]);
                            }
                        }
                    }

                    //break out of this iteration if the color that the user input is correct and matches the corresponding color in the "color" array.
                    break;
                }
                else
                {
                    //Error Message if the user enters an invalid color (after comparing it to each element of the "color" array) then exit the application. 
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

        //Display Resistance
        printf("\n\nRESISTANCE = %.2lf Ohms", *resistance);

        if(strcmp(tolerance,"No Tolerance") == 0)
        {
            printf("\nTOLERANCE  = %s", tolerance);
        }
        else
        {
            printf("\nTOLERANCE  = +/- %s", tolerance);
        }

        break;

    case 5:
        for(int i = 0; i < *n; i++)
        {
            //Present different instruction to the user depending on which band color is to be entered(e.g. Multiplier, Tolerance, etc).
            if(i < 3)
            {
                printf("\nEnter Band color %d: ", i + 1);
                fgets(selCol, 100, stdin);

                //Remove all empty characters from the input provided by user
                removeEmptyCharacters(selCol);       
            }
            else if(i == 3)
            {
                printf("\nEnter Multiplier Band Color: ", i + 1);
                fgets(selCol, 100, stdin);

                //Remove all empty characters from the input provided by user. This returns the "colBuff"variable which now replaces the "selCol" variable.
                removeEmptyCharacters(selCol);

            }
            else
            {
                printf("\nEnter Tolerance Band Color: ", i + 1);
                fgets(selCol, 100, stdin);

                //Remove all empty characters from the input provided by user. This returns the "colBuff"variable which now replaces the "selCol" variable.
                removeEmptyCharacters(selCol);
            }
            
            //Convert string input from user to lowercase. Use the string stored in "colBuff" instead of the one stored in "selCol".
            char lwrSelCol[100];
            strcpy(lwrSelCol, strlwr(colBuff));

            for(int j = 0; j < 12; j++)
            {
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
                            //Copy corresponding(already defined) numerical equivalent(stored in the "nband" array) of the color the user 
                            //entered in the stdin terminal into the "bColNumBuff" buffer
                            strcpy(bColNumBuff, nband[j]);
                        }
                    }
                    else
                    {
                        if(i < 3)
                        {
                            //Show Error if user enters "gold" or "silver" for the second entry (Note that this is for a resistor with 3 color bands). Exit the application afterwards.
                            if(strcmp(lwrSelCol, "gold") == 0 || strcmp(lwrSelCol, "silver") == 0)
                            {
                                printf("\nERROR: '%s' is a Multiplier color. Please try again!", lwrSelCol);
                                return (1);
                            }
                            else
                            {
                                //Copy corresponding(already defined) numerical equivalent(stored in the "nband" array) of the color the user 
                                //entered in the stdin terminal into the "bColNumBuff" buffer.
                                strcat(bColNumBuff, nband[j]);
                            }
                        }
                        else if(i == 3)
                        {
                            //Multiplier color band code
                            *bMultiP = multP[j];
                        }
                        else
                        {
                            if(strcmp(lwrSelCol, "black") == 0 || strcmp(lwrSelCol, "white") == 0)
                            {
                               strcpy(tolerance, "No Tolerance");
                            }
                            else
                            {
                                strcpy(tolerance, tole[j]);
                            }
                        }
                    }

                    //break out of this iteration if the color that the user input is correct and matches the corresponding color in the "color" array.
                    break;
                }
                else
                {
                    //Error Message if the user enters an invalid color (after comparing it to each element of the "color" array) then exit the application. 
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

        //Display Resistance
        printf("\n\nRESISTANCE = %.2lf Ohms", *resistance);

        //Display Tolerance
        if(strcmp(tolerance,"No Tolerance") == 0)
        {
            printf("\nTOLERANCE  = %s", tolerance);
        }
        else
        {
            printf("\nTOLERANCE  = +/- %s", tolerance);
        }
        break;

    case 6:
        for(int i = 0; i < *n; i++)
        {
            //Present different instruction to the user depending on which band color is to be entered(e.g. Multiplier, Tolerance, etc).
            if(i < 3)
            {
                printf("\nEnter Band color %d: ", i + 1);
                fgets(selCol, 100, stdin);

                //Remove all empty characters from the input provided by user
                removeEmptyCharacters(selCol);       
            }
            else if(i == 3)
            {
                printf("\nEnter Multiplier Band Color: ", i + 1);
                fgets(selCol, 100, stdin);

                //Remove all empty characters from the input provided by user. This returns the "colBuff"variable which now replaces the "selCol" variable.
                removeEmptyCharacters(selCol);

            }
            else if(i == 4)
            {
                printf("\nEnter Tolerance Band Color: ", i + 1);
                fgets(selCol, 100, stdin);

                //Remove all empty characters from the input provided by user. This returns the "colBuff"variable which now replaces the "selCol" variable.
                removeEmptyCharacters(selCol);
            }
            else
            {
                printf("\nEnter Temperature Coefficient Band Color: ", i + 1);
                fgets(selCol, 100, stdin);

                //Remove all empty characters from the input provided by user. This returns the "colBuff"variable which now replaces the "selCol" variable.
                removeEmptyCharacters(selCol);
            }
            
            //Convert string input from user to lowercase. Use the string stored in "colBuff" instead of the one stored in "selCol".
            char lwrSelCol[100];
            strcpy(lwrSelCol, strlwr(colBuff));

            for(int j = 0; j < 12; j++)
            {
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
                            //Copy corresponding(already defined) numerical equivalent(stored in the "nband" array) of the color the user 
                            //entered in the stdin terminal into the "bColNumBuff" buffer
                            strcpy(bColNumBuff, nband[j]);
                        }
                    }
                    else
                    {
                        if(i < 3)
                        {
                            //Show Error if user enters "gold" or "silver" for the second entry (Note that this is for a resistor with 3 color bands). Exit the application afterwards.
                            if(strcmp(lwrSelCol, "gold") == 0 || strcmp(lwrSelCol, "silver") == 0)
                            {
                                printf("\nERROR: '%s' is a Multiplier color. Please try again!", lwrSelCol);
                                return (1);
                            }
                            else
                            {
                                //Copy corresponding(already defined) numerical equivalent(stored in the "nband" array) of the color the user 
                                //entered in the stdin terminal into the "bColNumBuff" buffer.
                                strcat(bColNumBuff, nband[j]);
                            }
                        }
                        else if(i == 3)
                        {
                            //Multiplier color band code
                            *bMultiP = multP[j];
                        }
                        else if(i == 4)
                        {
                            if(strcmp(lwrSelCol, "black") == 0 || strcmp(lwrSelCol, "white") == 0)
                            {
                               strcpy(tolerance, "No Tolerance");
                            }
                            else
                            {
                                strcpy(tolerance, tole[j]);
                            }
                        }
                        else
                        {
                            if(strcmp(lwrSelCol, "white") == 0 || strcmp(lwrSelCol, "gold") == 0 || strcmp(lwrSelCol, "silver") == 0)
                            {
                               strcpy(tCoefficient, "No Temperature Coefficient");
                            }
                            else
                            {
                                strcpy(tCoefficient, tempCon[j]);
                            }
                        }
                    }

                    //break out of this iteration if the color that the user input is correct and matches the corresponding color in the "color" array.
                    break;
                }
                else
                {
                    //Error Message if the user enters an invalid color (after comparing it to each element of the "color" array) then exit the application. 
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

        //Display Calculated Resistance
        printf("\n\nRESISTANCE = %.2lf Ohms", *resistance);

        //Display Tolerance
        if(strcmp(tolerance,"No Tolerance") == 0)
        {
            printf("\nTOLERANCE  = %s", tolerance);
        }
        else
        {
            printf("\nTOLERANCE  = +/- %s", tolerance);
        }

        //Display Temperature Coefficient
        if(strcmp(tCoefficient,"No Temperature Coefficient") == 0)
        {
            printf("\nTEMPERATURE COEFFICIENT  = %s", tCoefficient);
        }
        else
        {
            printf("\nTEMPERATURE COEFFICIENT  = %s", tCoefficient);
        }
        break;
    
    default:
        printf("\nERROR: Wrong Input. The number of Color Bands should be a single digit/number(Integer) from 3 to 6");
        break;
    }
}