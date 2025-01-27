#include <cs50.h>
#include <stdio.h>

/*
Visit https://cs50.harvard.edu/indonesia/2023/psets/1/mario/less/ for more decsription

Toward the end of World 1-1 in Nintendo’s Super Mario Brothers, Mario must ascend right-aligned pyramid of blocks,
Let’s recreate that pyramid in C, albeit in text, using hashes (#) for bricks, a la the below. Each hash is a bit taller than it is wide, so the pyramid itself will also be taller than it is wide.

       #
      ##
     ###
    ####
   #####
  ######
 #######
########
The program we’ll write will be called mario. And let’s allow the user to decide just how tall the pyramid should be by first prompting them for a positive integer between, say, 1 and 8, inclusive.

Here’s how the program might work if the user inputs 8 when prompted:

$ ./mario
Height: 8
       #
      ##
     ###
    ####
   #####
  ######
 #######
########
Here’s how the program might work if the user inputs 4 when prompted:

$ ./mario
Height: 4
   #
  ##
 ###
####
Here’s how the program might work if the user inputs 2 when prompted:

$ ./mario
Height: 2
 #
##
And here’s how the program might work if the user inputs 1 when prompted:

$ ./mario
Height: 1
#
If the user doesn’t, in fact, input a positive integer between 1 and 8, inclusive, when prompted, the program should re-prompt the user until they cooperate:

$ ./mario
Height: -1
Height: 0
Height: 42
Height: 50
Height: 4
   #
  ##
 ###
####

*/

int main(void)
{
    int height = 0;
    int i, j, k; //initialize variables

    //ask for height
    while ((height <= 0) || (height > 8))
    {
        height = get_int("Height: ");
    }

    //loop for the numbers of rows
    for (i = 0; i < height; i++)
    {
        for (k = height; k > i + 1; k--) //loops for the numbers of spaces
        {
            printf(" ");
        }

        for (j = 0; j <= i; j++) //loops for the numbers of #
        {
            printf("#");
        }
        printf("\n"); //new row
    }

}