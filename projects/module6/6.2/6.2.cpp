#include <iostream>
#include <array>
#include <ctime>
#include <cstdlib> 
using namespace std;

enum Suit
{
    BUBNA,
    CHIRVA,
    PIKA,
    KRESTIA,
    SUIT_END
};

enum Value
{
    DVA,
    TRI,
    CHET,
    PYAT,
    SHEST,
    SEM,
    VOSEM,
    DEVYAT,
    DESAT,
    VALET,
    DAMA,
    KING,
    ACE,
    VALUE_END
};

struct Card
{
    Suit suit;
    Value value;
};



void printCard(const Card &ref) {
    switch (ref.suit)
    {
    case PIKA:
        cout << "p";
        break;
    case BUBNA:
        cout << "b";
        break;
    case CHIRVA:
        cout << "ch";
        break;
    case KRESTIA:
        cout << "k";
        break;
    };

    switch (ref.value)
    {
    case DVA:
        cout << "2";
        break;
    case TRI:
        cout << "3";
        break;
    case CHET:
        cout << "4";
        break;
    case PYAT:
        cout << "5";
        break;
    case SHEST:
        cout << "6";
        break;
    case SEM:
        cout << "7";
        break;
    case VOSEM:
        cout << "8";
        break;
    case DEVYAT:
        cout << "9";
        break;
    case DESAT:
        cout << "10";
        break;
    case VALET:
        cout << "v";
        break;
    case DAMA:
        cout << "d";
        break;
    case KING:
        cout << "k";
        break;
    case ACE:
        cout << "a";
        break;
    }
}

void printDeck(const std::array<Card, 52>& deck) //priniaet ssylku na masiv i vivodit vse karty iz masiva
{
    for (const auto& card : deck)
    {
        printCard(card);
        std::cout << ' ';
    }

    std::cout << '\n';
}

void swapCard(Card& a, Card& b)
{
    Card temp = a;
    a = b;
    b = temp;
}

int getRandomNumber(int min, int max)
{
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
    return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

void shuffleDeck(std::array<Card, 52>& deck)
{
  
    for (int index = 0; index < 52; ++index)
    {
        int swapIndex = getRandomNumber(0, 51);
        swapCard(deck[index], deck[swapIndex]);
    }
}

int getCardValue(const Card& card)
{
    switch (card.value)
    {
    case DVA:		return 2;
    case TRI:		return 3;
    case CHET:		return 4;
    case PYAT:		return 5;
    case SHEST:		return 6;
    case SEM:		return 7;
    case VOSEM:		return 8;
    case DEVYAT:		return 9;
    case DESAT:		return 10;
    case VALET:	return 10;
    case DAMA:	        return 10;
    case KING:	return 10;
    case ACE:		return 11;
    }

    return 0;
}

char getPlayerChoice()
{
    std::cout << "(h) to hit, or (s) to stand: ";
    char choice;
    do
    {
        std::cin >> choice;
    } while (choice != 'h' && choice != 's');

    return choice;
}

bool playBlackjack(const std::array<Card, 52>& deck)
{
    // Настраиваем стартовый режим игры
    const Card* cardPtr = &deck[0];

    int playerTotal = 0;
    int dealerTotal = 0;

    // Дилер получает одну карту
    dealerTotal += getCardValue(*cardPtr++);
    std::cout << "The dealer is showing: " << dealerTotal << '\n';

    // Игрок получает две карты
    playerTotal += getCardValue(*cardPtr++);
    playerTotal += getCardValue(*cardPtr++);

    // Игрок начинает
    while (1)
    {
        std::cout << "You have: " << playerTotal << '\n';

        // Смотрим, не больше ли 21 очка у игрока
        if (playerTotal > 21)
            return false;

        char choice = getPlayerChoice();
        if (choice == 's')
            break;

        playerTotal += getCardValue(*cardPtr++);
    }

    // Если игрок не проиграл и у него не больше 21 очка, то тогда дилер получает карты до тех пор, пока у него не получится в сумме 17 очков
    while (dealerTotal < 17)
    {
        dealerTotal += getCardValue(*cardPtr++);
        std::cout << "The dealer now has: " << dealerTotal << '\n';
    }

    // Если у дилера больше 21 очка, то игрок победил
    if (dealerTotal > 21)
        return true;

    return (playerTotal > dealerTotal);
}

int main()
{

    srand(static_cast<unsigned int>(time(0))); 
    rand(); 

    std::array<Card, 52> deck;

    int card = 0;
    for (int suit = 0; suit < SUIT_END; ++suit)
    for (int value = 0; value < VALUE_END; ++value)
    {
        deck[card].suit = static_cast<Suit>(suit);
        deck[card].value = static_cast<Value>(value);
        ++card;
    }

    shuffleDeck(deck);

    if (playBlackjack(deck))
        std::cout << "You win!\n";
    else
        std::cout << "You lose!\n";
    
    return 0;


}

