#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>
#include<cctype>
#include<algorithm>
using namespace std;
int index(int s)
{
	return rand() % s;
}
string ShuffleWord(string word)
{
	random_shuffle(word.begin(), word.end());
	return word;
}

string userinput(string word)
{
	return toupper(word)
}
void hintmsg()
{
    int randomNumber;

    string messages[10] = {
        "Kyun? Hawa nikal gai? 😂",
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

    randomNumber = rand() % 10;

    cout << messages[randomNumber] << endl;
}
void hint(int i,string word)
{
	if (i == 3)
		cout << "THE FIRST LETTER OF WORD IS " << word[0];
	else if (i == 6)
		cout << "THE LAST LETTER OF WORD IS " << word[-1];
	else if (i == 10)
		cout << "SECOND LAST AND THIRD LAST LETTERS ARE " << word[-2] << "..." << word[-3];
	else
		cout << "NO HINT";
}

int main()
{
    srand(time(0));
	const int LEVELS = 10;
const int WORDS = 5;
string array_1[LEVELS] = { "SCIENCE","GEOGRAPHY","COMPUTING","HUMAN BODY","SPACE","MUSICAL INSTRUMENTS","THINKERS AND SCIENTIST","GREEK MYTHOLOGY","SPICES AND FOODS","GEMSTONES" };
string array_2[LEVELS][WORDS] = {
	{"electron", "molecule", "neutrino", "catalyst", "isotopes"},
	{ "plateaus", "glaciers", "tsunamis", "monsoons", "savannah" },
	{ "compiler", "database", "protocol", "firewall", "variable" },
	{ "pancreas", "vertebra", "platelet", "cerebrum", "bronchus" },
    {"asteroid", "eclipses", "solstice", "aphelion", "universe"},
    {"clarinet", "trombone", "bagpipes", "triangle", "mandolin"},
    {"einstein", "franklin", "avogadro", "chadwick", "socrates"},
    {"minotaur", "hercules", "odysseus", "poseidon", "achilles"},
    {"cinnamon", "turmeric", "tamarind", "cardamom", "broccoli"},
    {"sapphire", "amethyst", "emeralds", "obsidian", "zirconia"}

};

    hintmsg();

    return 0;
}
