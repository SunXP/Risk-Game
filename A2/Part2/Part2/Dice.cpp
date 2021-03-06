#include <iostream>
#include <vector>
#include <time.h>
#include <stdlib.h>
#include "Dice.h"

using namespace std;

float Dice::num1;
float Dice::num2;
float Dice::num3;
float Dice::num4;
float Dice::num5;
float Dice::num6;
float Dice::timesRolled;
Dice::Dice()
{
	//Initiating numbers as 0

	srand(time(0));

	//timesTolled will store the number of times a dice has been rolled so far to get the percentage at the end
	float timesRolled = 0;
	//6 float variables to store ech time one of the numbers (1-6) is the result of the dice
	//num1 will store how many 1's so far, num2 will store how many 2's so far and so on
	float num1 = 0;
	float num2 = 0;
	float num3 = 0;
	float num4 = 0;
	float num5 = 0;
	float num6 = 0;
}

//roll method that takes number of dices to be rolled as input
vector<int> Dice::roll(int x)
{
	//if number of dices entered is less than 1 or bigger than 3 return an error
	if (x < 1 || x>3)
	{
		cout << "Error! invalid number of dice! \n";
		system("pause");
		exit(1);
	}

	//vector to push hte result of the dice in
	vector<int> vect;

	for (int i = 0; i < x; i++)
	{
		int x = (rand() % 6) + 1;
		timesRolled++;
		if (x == 1)
		{
			num1++;
		}
		else if (x == 2)
		{
			num2++;
		}
		else if (x == 3)
		{
			num3++;
		}
		else if (x == 4)
		{
			num4++;
		}
		else if (x == 5)
		{
			num5++;
		}
		else
			num6++;
		vect.push_back(x);
	}
	return vect;
}

//a method to return how many rolls so far
int Dice::getNum() const
{
	return numRoll;
}

//a method to return the percentage of a specific number
float Dice::getPerc(int x)
{
	if (timesRolled == 0)
	{
		cout << "Error! you haven't rolled a single tim yet! ";
		exit(0);
	}
	if (x == 1)
	{
		return ((num1 / timesRolled) * 100);
	}
	else if (x == 2)
	{
		return ((num2 / timesRolled) * 100);
	}
	else if (x == 3)
	{
		return ((num3 / timesRolled) * 100);
	}
	else if (x == 4)
	{
		return ((num4 / timesRolled) * 100);
	}
	else if (x == 5)
	{
		return ((num5 / timesRolled) * 100);
	}
	else
		return ((num6 / timesRolled) * 100);

}

//a method to return the percentage of all the numbers rolled so far
vector<float> Dice::getPer()
{
	if (timesRolled == 0)
	{
		cout << "Error! you haven't rolled a single tim yet! ";
		exit(0);
	}
	vector<float> vect;
	vect.push_back((num1 / timesRolled) * 100);
	vect.push_back((num2 / timesRolled) * 100);
	vect.push_back((num3 / timesRolled) * 100);
	vect.push_back((num4 / timesRolled) * 100);
	vect.push_back((num5 / timesRolled) * 100);
	vect.push_back((num6 / timesRolled) * 100);

	return vect;
}