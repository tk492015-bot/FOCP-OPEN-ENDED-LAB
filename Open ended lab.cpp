#include<iostream>
#include<cstdlib>
#include<ctime>
#include<string>
#include<cctype>
using namespace std;

// prints a line of dashes
void format()
{
    for (int i = 1; i <= 50; i++)
    {
        cout << "-";
    }
    cout << endl;
}

// shuffles the letters of the word randomly
string shuffleword(string word)
{
    // start from the last letter and swap each letter with
    // a random letter that comes before it (or itself)
    for (int i = word.length() - 1; i > 0; i--)
    {
        int j = rand() % (i + 1);
        char temp = word[i];
        word[i] = word[j];
        word[j] = temp;
    }
    return word;
}

// prints a random message
void hintmsg()
{
    int randomNumber;

    string messages[10] = {
        "Kyun? Hawa nikal gai? :)",
        "Dimagh ghar bhool aaye ho kya? ",
        "Word shuffle hua tha, tumhara dimagh nahi!",
        "Itna confidence, aur answer zero!",
        "Ye answer tha ya keyboard ka accident?",
        "Google bhi confuse ho gaya!",
        "Bhai, thora dimagh lagao!",
        "Guess kar rahe ho ya tukke laga rahe ho?",
        "Dictionary bhi tumse naraz hai!",
        "Bas karo bhai, word solve karna hai!"
    };

    // random number from 0 to 9 decides which message is shown
    randomNumber = rand() % 10;

	cout << messages[randomNumber] << endl; // Display the selected message
}
int main()
{
	srand(time(0));// seed the random number generator with the current time
    const int levels = 10, words = 5;
    int tries;      // wrong guesses in the current word
    int hints;      // hints used in the current word
    int score = 0;
    string guess;

    // category names, array_1[i] belongs to level i
    string array_1[levels] = { "SCIENCE", "GEOGRAPHY", "COMPUTING", "HUMAN BODY", "SPACE", "MUSICAL INSTRUMENTS", "THINKERS AND SCIENTISTS", "GREEK MYTHOLOGY", "SPICES AND FOODS", "GEMSTONES" };

    // each row has the 5 words of one category (same order as array_1)
    string array_2[levels][words] = {
    {"ELECTRON", "MOLECULE", "NEUTRINO", "CATALYST", "ISOTOPES"},
    {"PLATEAUS", "GLACIERS", "TSUNAMIS", "MONSOONS", "SAVANNAH"},
    {"COMPILER", "DATABASE", "PROTOCOL", "FIREWALL", "VARIABLE"},
    {"PANCREAS", "VERTEBRA", "PLATELET", "CEREBRUM", "BRONCHUS"},
    {"ASTEROID", "ECLIPSES", "SOLSTICE", "APHELION", "UNIVERSE"},
    {"CLARINET", "TROMBONE", "BAGPIPES", "TRIANGLE", "MANDOLIN"},
    {"EINSTEIN", "FRANKLIN", "AVOGADRO", "CHADWICK", "SOCRATES"},
    {"MINOTAUR", "HERCULES", "ODYSSEUS", "POSEIDON", "ACHILLES"},
    {"CINNAMON", "TURMERIC", "TAMARIND", "CARDAMOM", "BROCCOLI"},
    {"SAPPHIRE", "AMETHYST", "EMERALDS", "OBSIDIAN", "ZIRCONIA"}
    };
    // Formats and Displays the rules of the game
    cout << endl;
    format();
    cout << "\t\tWELCOME TO WORD SCRAMBLE GAME!" << endl;
    format();
    cout << "\nGAME RULES:" << endl;
    cout << "1. Complete all 10 levels." << endl;
    cout << "2. Enter H for hint after 3 wrong attempts." << endl;
    cout << "3. Maximum 3 hints per level." << endl;
    cout << "4. Each hint deducts 2 points." << endl;
    cout << "5.The 3rd hint will reveal the answer" << endl;
    cout << "6. Revealing the 3rd hint  deducts 5 points." << endl;
    cout << "7. A new word will be given after revealing." << endl;

    // one loop run is one level
    for (int i = 0; i < levels; i++)
    {
        // counters start from zero in every level
        tries = 0;
        hints = 0;

        // picks a random word of this level and jumble it
        int randomWord = rand() % words;
        string originalWord = array_2[i][randomWord];
        string jumbledWord = shuffleword(originalWord);

        // shuffles again if the word came out the same as the original
        while (jumbledWord == originalWord)
        {
            jumbledWord = shuffleword(originalWord);
        }
        cout << endl;
        format();
        cout << "\n\t\t ============= Level " << i + 1 << " ============ \n" << endl;
        format();
        cout << "\n\n\t\tCategory: " << array_1[i] << endl;
        format();
        cout << "\n\t\tJumbled Word: " << jumbledWord << endl;

        // keeps asking until the player guesses the word
        do
        {
            cout << "Enter your guess or 'H' for hint : ";
            cin >> guess;

            // convert guess to capital letters so it can match the word
            for (int j = 0; j < guess.length(); j++)
            {
                guess[j] = toupper(guess[j]);
            }

            if (guess == "H")
            {
                // hints unlock after 3, 6 and 10 wrong tries
                // so if the tries are less, the hint is refused
                if (tries < 3 || (hints >= 1 && tries < 6) || (hints >= 2 && tries < 10))
                {
                    cout << "Not enough tries to unlock hint " << endl;
                    hintmsg();
                }
                else if (hints < 3)
                {
                    hints++;
                    // hint 1 gives the first letter
                    if (hints == 1)
                    {
                        score -= 2;

                        // score should not become negative
                        if (score < 0)
                        {
                            score = 0;
                        }
                        hintmsg();
                        cout << "Hint " << hints << ": " <<  "The first letter of the word is: " << originalWord[0] << endl;
                    }
                    // hint 2 gives the last letter
                    else if (hints == 2)
                    {
                        score -= 2;
                        // score should not become negative
                        if (score < 0)
                        {
                            score = 0;
                        }
                        hintmsg();
                        cout << "Hint " << hints << ": " << "The last letter of the word is: " << originalWord[originalWord.length() - 1] << endl;
                    }
                    // hint 3 shows the answer and then gives a new word
                    else if (hints == 3)
                    {
                        hintmsg();
                        cout << "\n The correct answer is: " << originalWord << endl;
                        score -= 5;
                        if (score < 0)
                        {
                            score = 0;
                        }

                        cout << "5 points deducted" << endl;
                        cout << "\n Selecting another word from the same category..." << endl;

                        // chooses a different word from the same category
                        // random number is from 0 to 3, and if it is equal or
                        // greater than the old index we add 1 to skip the old word
                        int newWord = rand() % (words - 1);
                        if (newWord >= randomWord)
                        {
                            newWord++;
                        }
                        randomWord = newWord;
                        originalWord = array_2[i][randomWord];
                        jumbledWord = shuffleword(originalWord);
                        while (jumbledWord == originalWord)
                        {
                            jumbledWord = shuffleword(originalWord);
                        }

                        // tries and hints start again for the new word
                        tries = 0;
                        hints = 0;
                        cout << "\n\t\tNew Jumbled Word: " << jumbledWord << endl;
                    }
                }
                else
                {
                    hintmsg();
                    cout << "You have used all your hints!" << endl;
                }
            }

            // correct guess, the do while condition below will end the loop
            else if (guess == originalWord)
            {
                cout << "Correct! You guessed the word in " << tries + 1 << " tries." << endl;
                cout << "Moving on to the next level!" << endl;
            }
            // anything else is a wrong guess
            else
            {
                tries++;
                cout << "Incorrect guess! Try again." << endl;
                hintmsg();
            }
        } while (guess != originalWord);

        // points are given once the word is solved
        score += 10;
        cout << endl;
        format();
        cout << "LEVEL " << i + 1 << " COMPLETED!" << endl;
        cout << "10 points awarded!" << endl;
        cout << "Your Total Score: " << score << endl;
        format();
    }
    cout << endl;
    format();
    cout << "\n Final score : " << score << "/100" << endl;

    // iq is half of the score
    int iq = score / 2;


    cout << "YOUR GAME IQ : " << iq << "/50" << endl;
    format();
    cout << "\n\t\t ========    IQ RESULT    =========" << endl;

    // message depends on which range the iq falls in
    if (iq == 50)
    {
        cout << "Your IQ is " << iq << ". You are a genius!" << endl;
    }
    else if (iq < 50 && iq >= 40)
    {
        cout << "Your IQ is " << iq << ". You are above average!" << endl;
    }
    else if (iq < 40 && iq >= 30)
    {
        cout << "Your IQ is " << iq << ". You are average!" << endl;
    }
    else if (iq < 30 && iq >= 20)
    {
        cout << "Your IQ is " << iq << ". You are below average!" << endl;
    }
    else
    {
        cout << "Your IQ is " << iq << ". You need to work on your brain!" << endl;
    }
    format();

    return 0;
}
