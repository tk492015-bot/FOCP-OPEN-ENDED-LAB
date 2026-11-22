README:

Design:
                         We created a cryptographic text game using C++ programming language.The main idea of the game is that there are 10 levels in total.Each level has its own category assigned to it and each category has total of 5 words in it.

When the user plays each level a random word is selected from the levels category.
The word is then shuffled randomly and is displayed to the user.
The user  sees the shuffled word and the category to which the word belongs to which is also displayed .

 The user then has to make a guess seeing the displayed information.If the user  guesses the word correctly then he gets 10 points for that correct guess,the level goes on until the user guesses the correct word.

No points are deducted for an incorrect guess.If the user is stuck on a level he can ask for a hint by entering ‘H’ as the guess.there are total of three hints that become availible when the tries become 3,6 and 10.

The first hint reveals the first letter of the original unshuffled word, the second hint reveals the last letter of the original word and the third hint reveals the answer.
The first two hints cost 2 points and the last hint costs 5 points.

The last hint reveals the answer but it also resets the word and chooses another word from the same category and shuffles it.it also resets the tries and hints used for that level giving the user a fresh start.

The guess the user enters can be in lower or upper case but if it is lower case it is converted to upper case.Each incorrect guess and hint also displays a funny message selected randomly to make the game more enjoyable for the user.

After all 10 levels the final  score is calculated and is displayed.based on the score the users IQ is also calculated by formula:
                                            
IQ = Score ÷ 2

The Range of the score of the score is from 0-100 and the score cannot be negative.Similarly the range of IQ is from 0-50 and it is also not negative.for the first level the hints are free but they are unlocked based on the tries as mentioned earlier.
Based on the calculated IQ, a Different message is displayed for different IQ’s.

Code-information:
                                   The code uses conditions,loops,functions,arrays and strings.
There are five header files used in the code which are:

#include<iostream>: For basic input/output operations
#include<cstdlib>: For random function
#include<ctime>: For time function
#include<string>: For string functions
#include<cctype>: For toupper function
 
There are also total of four functions used in the code which are:

format: Used for formatting the output on the console
hintmsg: Used for printing  funny messages randomly
shuffleword: Used to shuffle the random string of words
main:The main function where most of the code lies.

The code uses cin as input by the user and cout to display information or output which are present in iostream.

The user can enter his guess by cin as a string in upper or lower case, but lower case characters of the string will be converted into upper case by toupper() function present in cctype in the body of for loop.

A do-while loop is used and it runs untill the user does not enter the correct guess.in it there are multiple operations happening such as the user entering a guess,the lower case characters of the guess being converted into upper case, if user entered ‘H’( lower-case ‘h’ is converted to upper case) then if condition is used that checks whether the user has reached enough tries to unlock a hint or not and also it does not allow more than three hints.

A for loop is also used  and runs untill its variable remains less than levels.the loop selects a random word from 0-4 and then selects that word from the array and shuffles it.

There are two arrays used in the code,the first one contains all the categories for each level and its size is equal to levels,the second array is a 2-dimensional array that has size of levels and words and it contains all the words for all of the categories.the levels of the array indicate the rows and the words indicate the columns.

if the user enters a correct guess the do-while loop present in the for loop ends and 10 is added to the score and is displayed after every level. After end of the for loop the final score is calculated and is displayed on the console. Based on that score an IQ is also calculated and different messages are displayed based on the IQ.
