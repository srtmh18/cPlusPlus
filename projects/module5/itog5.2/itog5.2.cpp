#include <iostream>

using namespace std;

int getRandomNumber(int min, int max)
{
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
    return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

int a = getRandomNumber(1, 100); 

void gameLoop() 
{
    cout << "Please, enter a number betwen 1 and 100: ";
    int a = getRandomNumber(1, 100);
    for (int p = 1; p <= 7; ++p)
    {
        int i;
        cin >> i;

        if (i > a)
        {
            cout << "Value is to high" << "\n";
        }

        if (i < a)
        {
            cout << "Value is to small" << "\n";
        }

        if (i == a)
        {
            cout << "Well done! Would you restart?(1 is for no and other value is for yes) " << "\n";
            break;
        }
        
        if (i != a && p == 7)
        {
            cout << "Sorry, correct answer is " << a << ". Would you restart?(1 is for no and other value is for yes) " << "\n";
            break;
        }
    }
}


void game()
{
    int choice;
    do
    {
        gameLoop();
        cin >> choice;
    } while (choice != 1);

    cout << "Have a nice day!";
}

int main()
{
	srand(static_cast<unsigned int>(time(0)));
    rand();

    game();

	return 0;
}

