﻿#include <iostream>
#include "constants.h"

// Получаем начальную высоту от пользователя и возвращаем её
double getInitialHeight()
{
	std::cout << "Enter the initial height of the tower in meters: ";
	double initialHeight;
	std::cin >> initialHeight;
	return initialHeight;
}

// Возвращаем расстояние от земли после "..." секунд падения
double calculateHeight(double initialHeight, int seconds)
{
	// Используем формулу: [ s = u * t + (a * t^2) / 2 ], где u(начальная скорость) = 0
	double distanceFallen = (myConstants::gravity * seconds * seconds) / 2;
	double currentHeight = initialHeight - distanceFallen;

	return currentHeight;
}

// Выводим высоту, на которой находится мячик после каждой секунды падения
void printHeight(double height, int seconds)
{
	if (height > 0.0)
	{
		std::cout << "At " << seconds << " seconds, the ball is at height:\t" << height <<
			" meters\n";
	}
	else
		std::cout << "At " << seconds << " seconds, the ball is on the ground.\n";
}


void cyclicHeight(double initialHeight)
{
    for (int seconds=0; initialHeight > 0.0; ++seconds)
	{
	   double height = calculateHeight(initialHeight, seconds);
	   printHeight(height, seconds);
	   if (height < 0.0)
		   break;
	}
}


int main()
{
	const double initialHeight = getInitialHeight();

	cyclicHeight(initialHeight);

	return 0;
}