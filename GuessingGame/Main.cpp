#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <string>
using namespace std;

const double MAX_ALLOWED = 20;

int main()
{
    int mainMenuSelect, userGuess, randNumber = 0, correctGuesses = 0, missedGuesses = 0, gamesPlayed = 0;
    double balance = 0, amount = 0, moneyLost = 0, moneyWon = 0;
    bool mainLoop = true, gameLoop = true;
    string playerName;
    ofstream playerStats;

    while (mainLoop)
    {
        cout << "*** MAIN MENU ***\n" << endl;
        cout << "Please select one of the following:\n" << endl;
        cout << "\t1. Display my available credit\n\t2. Add credits to my account\n\t3. Play the Guessing Game\n\t4. Display my statistics\n\t5. Save my statistics\n\t6. Exit" << endl;

        cin >> mainMenuSelect;

        switch (mainMenuSelect)
        {
        case 1:
            cout << "Your available balance is $" << balance << "." << endl;

            system("pause");
            system("CLS");
            break;

        case 2:
            cout << "Please enter the amount you would like to add: $";
            cin >> amount;
            cout << endl;
            while (amount > MAX_ALLOWED || amount < 0)
            {
                cout << "Maximum allowable credit is $20.00.\nPlease enter a different amount and try again." << endl;
                cout << "$";
                cin >> amount;
                cout << endl;
            }

            balance = balance + amount;
            cout << "Amount successfully added." << endl;
            cout << "Balance: $" << balance << endl;

            system("pause");
            system("CLS");
            break;

        case 3:
            gameLoop = true;

            while (gameLoop)
            {
                randNumber = 1 + (rand() % 20);

                cout << "Guess a number between 1 and 20." << endl;
                cin >> userGuess;

                if (userGuess < 0 || userGuess > 20)
                {
                    cout << "You did not enter a value within the valid range. Try again." << endl;
                    continue;
                }
                else if (randNumber == userGuess)
                {
                    cout << "Correct! You guessed the correct the number and earned $50." << endl;

                    moneyWon += 50;
                    balance += 50;
                    correctGuesses += 1;
                    cout << "You entered: " << userGuess << endl;
                    cout << "The number was: " << randNumber << endl << endl;
                    cout << "Balance: $" << balance << endl;
                    gamesPlayed += 1;
                    gameLoop = false;
                }
                else
                {
                    cout << "Oh no. Unfortunately, your guess was not correct. You lost $35." << endl;

                    moneyLost += 35;
                    balance -= 35;
                    missedGuesses += 1;
                    cout << "You entered: " << userGuess << endl;
                    cout << "The number was: " << randNumber << endl << endl;
                    cout << "Balance: $" << balance << endl;
                    gamesPlayed += 1;
                    gameLoop = false;
                }
            }

            system("pause");
            system("CLS");
            break;

        case 4:
            cout << "What is your name?" << endl;
            cin >> playerName;

            cout << endl << endl;
            cout << "CURRENT SESSION STATISTICS:" << endl;
            cout << __DATE__ << " " << __TIME__ << endl;
            cout << playerName << endl;
            cout << "Available credit: $" << balance << endl;
            cout << "Games played: " << gamesPlayed << endl;
            cout << "Correct guesses: " << correctGuesses << endl;
            cout << "Missed guesses: " << missedGuesses << endl;
            cout << "Money you won: " << moneyWon << endl;
            cout << "Money you lost: " << moneyLost << endl;

            system("pause");
            system("CLS");
            break;

        case 5:
            cout << "What is your name?" << endl;
            cin >> playerName;

            playerStats.open(playerName);

            playerStats << playerName << "'s most recent session statistics: \n" << __DATE__ << " " << __TIME__ << endl <<
                playerName << endl <<
                "Available credit: $" << balance << endl <<
                "Games played: " << gamesPlayed << endl <<
                "Correct guesses: " << correctGuesses << endl <<
                "Missed guesses: " << missedGuesses << endl <<
                "Money you won: " << moneyWon << endl <<
                "Money you lost: " << moneyLost << endl;

            playerStats.close();

            cout << "Your statistics have been saved." << endl;

            system("pause");
            system("CLS");
            break;

        case 6:
            cout << "Thank you for using my software. Goodbye!" << endl;
            mainLoop = false;
            break;

        default:
            cout << "You must enter a value between 1-6." << endl;
            system("pause");
            system("CLS");
            break;
        }
    }

    system("pause");
    return 0;
}


