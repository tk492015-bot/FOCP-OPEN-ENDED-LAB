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
void wrongMessage()
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

int main()
{
    srand(time(0));

    wrongMessage();

    return 0;
}
