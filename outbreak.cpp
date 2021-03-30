#include <iostream>
#include <cstring>
#include <string>
#include <stdio.h>
using namespace std;

	int const SIZE = 7;



//************************************************************

/*==================================================================
Function:	Print Heading

Parameters:	NONE

Return:		NONE

Description:	Printing the heading

====================================================================*/

	void PrintHeading()
{

	printf("\n");
	printf("\n");
	printf("+-------------------------------------------------------+\n");
	printf("|							|\n");
	printf("|	     Computer Science and Engineering		|\n");
	printf("|							|\n");
	printf("|	      CSCE 1030 - Computer Science I		|\n");
	printf("|							|\n");
	printf("|	Marco Aguilera ~ ma0882 ~ ma0882@my.unt.edu	|\n");
	printf("|							|\n");
	printf("+-------------------------------------------------------+\n");
	printf("\n");
	printf("\n");


}


/*========================================================================================
Function:	Slots in array s

Retrun:		NONE

Description:	****

	Here this nested for - loop creates the begining of the 2D array and initializes
the 7 by 7 board with each cell containing a "S" inside which represents the group of
49 people that are suseptible to the disease.

==========================================================================================*/

	void Disease_Model(char Model[][SIZE], int size)
{

	for(int i = 0; i < size; ++i)
	{
		for(int j = 0; j < size; ++j)
		{
		Model[i][j] = 's';
		}
	}

}

/*=========================================================================================
Function:	Model Value

Return:		NONE

Description:	****

	Here is a function created just to simply out put the 2D array created for the
initialization of the "S" using a for- loop.

==========================================================================================*/

	void  Model_Format(char Model[][SIZE], int size)
{


	 for(int i = 0; i < size; ++i)
        {
               for(int j = 0; j < size; ++j)
               {


			cout << Model[i][j] << " ";
               }
        printf("\n");
        }
	printf("\n");


}

/*===============================================================================================
Function: 	Count Number of i

Return:		An Integer

Description:	****

	This function allows the program to use a nested for -  loop and let the "i" be counted
while the iterating the suseptible are being infected using a count and returning that value.

================================================================================================*/

	int CountNum_i(char Model[][SIZE], int size)
{
	int count = 0;

	for(int i = 0; i < size; ++i)
	{
		for(int j = 0; j < size; ++j)
		{
			if(Model[i][j] == 'i')
			{
			count++;
			}
		}
	}

	return count; //should return integer
}


/*================================================================================================
Function:       Spread of Disease

Return:         NONE

Description:    ****

	This is the part of the program that can be done using for-loops or branches or if-elses
the following part of the program takes some what of a finess because depending on what the user
chooses as the cordinates infected then it will have affected the cells in the region around
the infected. So basically the user may choose coordinates that are inside the bounds. When the
user chooses then the "i" and "j" will update to which cell the user is trying to access once
program accesses that specific cell the conditions are set in if-elses.
	If the user choose anything that is in the middle then there will most likly be 8 cells
that change to Infected on the next day and so on it will keep iterating until the region is
completly recovered, so this specific part of the program will be towards the end of the funtion
that specifically checks on the surrounding cells of the infected cell.
	If the user chooses anything that is on the outer edges then it will do the same thing
however this time is will simply check and change the surrounding 5 cells that will be changed
to infected cell.
	If the user chooses anything in the coner then is will simply do a very similar thing,
but will change the 3 cells around it to infected and so on.
	The condition will check the whole region so if the cells that are not next to the one
choosen by the user at the start of the program then will be left alone and not changed until
they are adjencent themselves with an infected Column or Row.

=================================================================================================*/
void DiseaseSpread(char Current[][SIZE], char NextDay[][SIZE], int size)
{
        for(int i = 0; i < size; ++i)
        {
                for(int j = 0; j < size; ++j)
                {

        if(Current[i][j] == 's')
        {
                if(i == 0)
                {
                        if(j == 0)
                        {
                                if(Current[i][j+1] == 'i' || Current[i+1][j] == 'i' || Current[i+1][j+1] == 'i')
                                {
                                NextDay[i][j] = 'i';
                                }
                                else{
                                NextDay[i][j] = 's';
                                }
                        }
                       else  if(j == size-1)
                        {
                                if(Current[i][j-1] == 'i' || Current[i+1][j-1] == 'i' || Current[i+1][j] == 'i')
                                {
                                NextDay[i][j] = 'i';
                                }
                                else{
                                NextDay[i][j] = 's';
                                }
                        }

                        else{
                                if(Current[i][j-1] == 'i' || Current[i][j+1] == 'i' || Current[i+1][j-1] == 'i' || Current[i+1][j] == 'i' || Current[i+1][j+1] == 'i')
                                {
                                NextDay[i][j] = 'i';
                                }
                                else{
                                NextDay[i][j] = 's';
                                }
                        }

                }
    	else if(i == size-1)
        {
                        if(j==0)
                        {
                                if(Current[i][j+1] == 'i' || Current[i-1][j] == 'i' || Current[i-1][j+1] == 'i')
                                {
                                NextDay[i][j] = 'i';
                                }
                                else{
                                NextDay[i][j]= 's';
                                }
                        }

                else if(j == size-1)
                {
                        if(Current[i][j-1] == 'i' || Current[i-1][j-1] == 'i' || Current[i-1][j] == 'i')
                        {
                        NextDay[i][j] = 'i';
                        }
                        else{
                        NextDay[i][j] = 's';
                        }
                }

                else{

                        if(Current[i][j-1] == 'i' || Current[i][j+1] == 'i' || Current[i-1][j-1] == 'i' || Current[i-1][j] == 'i' || Current[i-1][j+1] == 'i')
                        {
                        NextDay[i][j] = 'i';
                        }
                        else{
                        NextDay[i][j] = 's';
                        }
                }
        }


        else{
                        if(j == 0)
                        {
                                if(Current[i-1][j] == 'i' || Current[i-1][j+1] == 'i' || Current[i][j+1] == 'i' || Current[i+1][j+1] == 'i' || Current[i+1][j] == 'i')
                                {
                                NextDay[i][j] = 'i';
                                }
                                else{
                                NextDay[i][j] = 's';
                                }
                        }

                        else if(j == size-1)
                        {
                                if(Current[i-1][j] == 'i' || Current[i-1][j-1] == 'i' || Current[i][j-1] == 'i' || Current[i+1][j-1] == 'i' || Current[i+1][j] == 'i')
                                {
                                NextDay[i][j] = 'i';
                                }
                                else{
                                NextDay[i][j] = 's';
                                }
                        }

			else
                        {
                                if(Current[i-1][j-1] == 'i' || Current[i-1][j] == 'i' || Current[i-1][j+1] == 'i' || Current[i][j-1] == 'i' || Current[i][j+1] == 'i' || Current[i+1][j-1] == 'i' || Current[i+1][j] == 'i' || Current[i+1][j+1] == 'i')
                                {
                                NextDay[i][j] = 'i';
                                }
                                else{
                                NextDay[i][j] = 's';
                                }
                        }
                }

        }



                }

        }



}



/*=======================================================================================
Function:       Infected to Recovered

Return:         NONE

Description:    ****

	This part of the program sets a condition in which if the following characters are
infected that for the next day that will be outputed it should turn or change the infected
to Recovered.

========================================================================================*/

        void InfectToRecov(char Current[][SIZE], char NextDay[][SIZE], int size)
{

        for(int i = 0; i < size; ++i)
        {
                for(int j = 0; j < size; ++j)
                {
                        if(Current[i][j] == 'i')
                        {
                        NextDay[i][j] = 'r';
                        }
                }
        }



}

/*==============================================================================================
Function:	UpdateNexttoCurr

Return:         NONE

Description:    *****

	This part of the program updates the current day every time that the nextday has seen a
change which will simply iterate in the do-while loop to output the region plus the day that the
Infected turn to Recovered. This function was not asked for specifically in the instruction
however it will compile if implimented in the previous funtions. I decided to make it its own
proper function to make it more readable to any user.

================================================================================================*/


	void UpdateNexttoCurrent(char Current[][SIZE], char NextDay[][SIZE], int size)
{

	for(int i = 0; i < SIZE; ++i)
        {
                for(int j  = 0; j < SIZE; ++j)
                {
                        Current[i][j] = NextDay[i][j];

                }
	}



}

/*===============================================================================================
Function:       MAIN

Return:         NONE

Description:    *****

	This is the main which will out put everything that is in the other function by calling
to the functions according to the name that was choosen by me. Here the questions asked to the
user are also implimented this creates a really clean code that is very easy and simple to read
incase anyone happens to look through it. There are a few style of loops that itterate when a
given answer is wrong which will automatically ask the user again until the correct coordinates
are used. I have also implimented the day that itterates  to a new day every time the Infected
turns into recovered.

===============================================================================================*/

	int main ()
{

	char Current[SIZE][SIZE];
	char NextDay[SIZE][SIZE];
	int NumDay = 0;
	int Row, Column;
	int size;
		PrintHeading();
		Disease_Model(Current, SIZE);
		Disease_Model(NextDay, SIZE);

	printf("Please enter a location to infect: \n");

	scanf("%d", &Row);
	scanf("%d", &Column);

	Row = Row - 1;
	Column = Column - 1;

	while(Row < 0 || Row >= SIZE || Column < 0 || Column >= SIZE)
	{
		printf("Those coordinates are outside the bounds of this region!!! \n");
		printf("Please enter a new location to infect: \n");

		scanf("%d", &Row);
		scanf("%d", &Column);

		Row = Row - 1;
        	Column = Column - 1;

	}

	Current[Row][Column] = 'i';


	do
	{
		printf(" Day : %d \n", NumDay);

		Model_Format(Current, SIZE);
		DiseaseSpread(Current, NextDay, SIZE);
		InfectToRecov(Current, NextDay, SIZE);

		NumDay++;
		UpdateNexttoCurrent(Current, NextDay, SIZE);

		if(CountNum_i(Current,SIZE) == 0)
		{
		break;
		}

	}while(true);

	printf(" Day : %d \n", NumDay);

	Model_Format(Current,SIZE);

	printf(" It took %d days for the outbreak to end!!! \n \n", NumDay);



	return 0;
}
