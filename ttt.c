/*
	Author : Neeraj Lagwankar & Ishan Joshi

	Date Created : 25th June 2016

	Location : Pune

	Please use Atom text editor to the code in the best way.

	*/

#include <stdio.h>
main()
{
	int row, column, switchcase, var, i, j, user = 0, play;

	/*The variables row and column will be used to set the location of dot or cross.
	Switchcase is a variable used in switch-case-for user to select Dot or Cross. Variable var is used to run the
	While Loop for exactly 9 times.
	Integer i and j will be used to print the whole array at the end.
	They will also be used to check the number of times the loop runs.
	The variable user is used below to let the players know whose it is.
	*/

	char array[3][3]={0,0,0,0,0,0,0,0,0};

	//The Array, array[3][3] is declared as an charachter array, so that it can store the Dots and Crosses.

	playagain:

	for(var = 0;var < 9;var++)//While loop is not working(running till infinity)
	{
		/*
		The if and else statements are to print the player which will play next.
		*/
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

	int flag=0, flag2=0;
	//The two flag variables will be used to decide if the player has won or not.
  	for( row = 0 ; row < 3 ; row++ )//First checking the values of all columns keeping row constant.
		{
			for( column = 0 ; column < 3 ; column++ )
			{
				if(array[row][column]=='X')
				{
					flag++;
				}
				if (array[row][column]=='O')
				{
					flag2++;
				}
				if(flag==3||flag2==3)
				{
					printf("You Win\n");
					goto exit;
				}
				flag=0,flag2=0;
			}
		}

		for( column = 0; column < 3; column++)//Now checking the values of all rows keeping column constant.
		{
			for(row = 0; row < 3; row++)
			{
				if(array[row][column]=='X')
				{
					flag++;
				}
				if (array[row][column]=='O')
				{
					flag2++;
				}
				if(flag==3||flag2==3)
				{
					printf("You Win\n");
					goto exit;
				}
				flag=0,flag2=0;
			}
		}

		for(row=0,column=0;row<3,column<3;row++,column++)//Now checking the values diagonally
		{
			if(array[row][column]=='X')
			{
				flag++;
			}
			if (array[row][column]=='O')
			{
				flag2++;
			}
			if(flag==3||flag2==3)
			{
				printf("You Win\n");
				goto exit;
			}
			flag=0,flag2=0;
		}

		for(row=2,column=0;row>=0,column<3;row--,column++)//Now checking the values diagonally but from the opposite side.
		//for statement might have some error. Look into it
		{
			if(array[row][column]=='X')
			{
				flag++;
			}
			if (array[row][column]=='O')
			{
				flag2++;
			}
			if(flag==3||flag2==3)
			{
				printf("You Win\n");
				goto exit;
			}
			flag=0,flag2=0;

		}

		for( i = 0 ; i < 3 ; i++)
		{
			for( j = 0 ; j < 3 ; j++)
			{
				printf("|\t%c\t|",array[i][j]);//See if you can draw horizontal lines above and below joining the vertical lines.(For Ishan)
			}
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
	printf("Do you want to play the Game again\n1. Yes\n2. No\n");
	scanf("%d",&play);
	if(play==1)
	{
		var=0;
		goto playagain;
	}
	exit://used to end the game.
	for( i = 0 ; i < 3 ; i++)
	{
		for( j = 0 ; j < 3 ; j++)
		{
			printf("|\t%c\t|",array[i][j]);//See if you can draw horizontal lines above and below joining the vertical lines.(For Ishan)
		}
		printf("\n");
	}
	printf("Done\n");
}
