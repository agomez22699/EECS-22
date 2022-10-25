We begin our journey through my code towards the define area on top. Here we find a handful of lines that defines the colors that could be used to print. Here we use red, green, and essentially reset.

Next we define the max name length to be 64 as given in the example slides.

In the next bunch of definitions, we have a trio of numbers from 0-2 to define if a number is called to be green, if its already been called to red, and not called to the same color. This will be important later. 

This next chunk makes a player structure that holds name, check board, number board, and if the player has won.

"has_called" is in charge of comparing a number and deciding if its been called then return a value to decide whther to print the colors in another function.

The purpose of in_board is to check off the numbers that have been called. This was shortened in previous versions but bugs did not allow this to work properly. So this is why marking off numbers is done through another function.


For the is_winner, here we are going through multiple for loops to go through each of the elements of the check matrix. We add the elements and if it is equal to the dimension then it will notify the caller that it is true and carry on with the analysis.


Print board is essentially just a condensed printf statement that prints colors from the has called function.



In the main, we begin by opening the file, checking if the name is the same as the input file. We then extract the players and dimension.

So the player structure is essentially a pointer to pointers. 
For instance, when you call player 0, then attached is the name, board, check, and win.
This is very dynamic for the specifications given in the criteria.


The rest of the for loops is just populating the structure with the information given in the input file.

Then we make another array just for the caller so we can keep track of all the numbers while doing the analysis. 

Here we print the initial boards with no coloring and aaccessing the player structure.


With the start of the bingo simulation, we begin another for loop that iterates through the caller numbers and calls the if winner function. Then, it will print the winning player if the conditions have been met

if not, then it will continue and cycle over the players and win conditions.

at the very end, it will print the winning number and end the loop to finish the program. 
