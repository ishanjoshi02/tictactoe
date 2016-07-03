/*
	Author : Neeraj Lagwankar & Ishan Joshi

	Date Created : 25th June 2016

	Location : Pune

	Please use Atom text editor to the code in the best way.

	*/

#include <stdio.h>
void main()
{
	int row, column, switchcase, var, i, j, user, play;
	int scene;

	/*The variables row and column will be used to set the location of dot or cross.
	Switchcase is a variable used in switch-case-for user to select Dot or Cross. Variable var is used to run the
	While Loop for exactly 9 times.
	Integer i and j will be used to print the whole array at the end.
	They will also be used to check the number of times the loop runs.
	The variable user is used below to let the players know whose it is.
	*/

	char array[3][3]={0,0,0,0,0,0,0,0,0};

	//The Array, array[3][3] is declared as an charachter array, so that it can store the Dots and Crosses.

	loop1:

	for(var = 0;var < 9;var++)//While loop is not working(running till infinity)
	{
		/*
		The if and else statements are to print the player which will play next.
		*/
		printf("Select user 1 or 2\n");
		scanf("%d", &user);

		if(user==1)
		{

			printf("Now User 1 will enter\n");
			goto loop;
		}


		if(user==2)
		{

			printf("Now User 2 will enter \n");
			goto loop;
		}

		else
		{
			printf("Invalid user\n");
			goto loop1;
		}

		loop://Is used again and again so as to provide the user with a logical flow while playing.

		printf("Enter the Row and Column\n");

		scanf("%1d %1d",&row ,&column);
		if( (array[row][column]=='X') || (array[row][column]=='O'))
		{
			printf("The row and column already has an input\n");
			goto loop;
		}

		if ( ( row < 3 ) && ( column < 3 ) && ( row >= 0) && ( row >= 0 ) )
		//If statement is used so that there is no problem during inputting the values in the array.
		{
			printf("Choose one, by entering the number:\n1. Cross (X) 2. Dot (O)\n");

			scanf("%d",&switchcase);

			switch ( switchcase )
				{
					case 1:
					{

						array[row][column] = 'X';//Assigns X to the selected row and column.
						break;

					}
					case 2:
					{

						array[row][column] = 'O';//Assigns O to the selected row and column
						break;

					}
				}
		}
		else
		{
	  	printf("Input Error. Program will now terminate\n");
  		goto exit;
		}

		printf("\n");
		//New code goes here(WIN code):
		//Win code is the code which will be used to analyse whether one of the user has won or not.
		//If he/she wins, the goto statements send it to the label 'exit'.

  	for( row = 0 ; row < 3 ; row++ )//First checking the values of all columns keeping row constant.
		{
			if((array[row][0]==array[row][1] && array[row][0]==array[row][2] && array[row][0]!=0) && ((array[row][0]=='X')))
			{
				goto time1;
				{
					time1:
					printf("X Wins\n");
					goto loop2;
				}
			}
			else if((array[row][0]==array[row][1] && array[row][0]==array[row][2] && array[row][0]!=0) && ((array[row][0]=='O')))
			{
				goto time2;
				{
					time2:
					printf("O Wins\n");
					goto loop2;
				}
			}
		}

		for( column = 0; column < 3; column++)//Now checking the values of all rows keeping column constant.
		{
			if((array[0][column]==array[1][column] && array[0][column]==array[2][column] && array[0][column]!=0) && ((array[0][column]=='X')))
			{
				goto time3;
				{
					time3:
					printf("X Wins\n");
					goto loop2;
				}
			}

			else if((array[0][column]==array[1][column] && array[0][column]==array[2][column] && array[0][column]!=0) && ((array[0][column]=='O')))
			{
				goto time4;
				{
					time4:
					printf("O Wins\n");
					goto loop2;
				}
			}
		}


		if((array[0][0]==array[1][1] && array[0][0]==array[2][2] && array[0][0]!=0) && array[0][0] == 'X')
		{
			printf("X Wins\n");
			goto loop2;
		}

		else if((array[0][0]==array[1][1] && array[0][0]==array[2][2] && array[0][0]!=0) && array[0][0] == 'O')
		{
			printf("O Wins\n");
			goto loop2;
		}

		if((array[0][2]==array[1][1] && array[1][1]==array[2][0] && array[0][2]!=0) && array[0][2] == 'O')
		{
			printf("O Wins\n");
			goto loop2;
		}
		else if((array[0][2]==array[1][1] && array[1][1]==array[2][0] && array[0][2]!=0) && array[0][2] == 'X')
		{
			printf("X Wins\n");
			goto loop2;
		}

		for( i = 0 ; i < 3 ; i++)
		{
			for( j = 0 ; j < 3 ; j++)
			{
				printf("|_%c",array[i][j]);
				//printf(" ");//See if you can draw horizontal lines above and below joining the vertical lines.(For Ishan)
			}
			printf("_|");
			printf("\n");
		}
		row = 0, column = 0;
		if(user==1)
		{

			user=2;

		}
		if(user==2)
		{

			user=1;

		}

	}
	//add swithcase if the users want to play the game again.(Done)
	loop2:

	printf("Do you want to play again?\n");
	printf("1: Yes\n2: No\n");
	scanf("%d", &scene);

	switch (scene)
	{

			case 1:
			{
				goto exit1;
				break;
			}

			case 2:
			{
				goto exit;
				break;
			}
	}
	exit1://used to end the game.
	for( i = 0 ; i < 3 ; i++)
	{
		for( j = 0 ; j < 3 ; j++)
		{
			printf("|_%c",array[i][j]);//See if you can draw horizontal lines above and below joining the vertical lines.(For Ishan)
		}
		printf("_|");
		printf("\n");
	}
	printf("Done\n");
	for(i=0; i<3; i++)
	{
		for(j=0; j<3; j++)
		{
			array[i][j] = array[row][column];
		}
	}
	goto loop1;

	exit://used to end the game.
	for( i = 0 ; i < 3 ; i++)
	{
		for( j = 0 ; j < 3 ; j++)
		{
			printf("|_%c",array[i][j]);//See if you can draw horizontal lines above and below joining the vertical lines.(For Ishan)
		}
		printf("_|");
		printf("\n");
	}
	printf("Done\n");
}
