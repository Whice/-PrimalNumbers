#include <iostream>
#include <math.h>
#include "CheckForPrimals.h"
#include <ctime>
#include <chrono>
#include <conio.h>



int main()
{
	//Установить русский
	setlocale(LC_ALL, "");

	cout << "До какого числа искать? (печатается каждый последний из 100 000 наденых.)"<<endl;
	uint64_t maxNumber = 0;
	cin >> maxNumber;

	//Выдать первоначальные значения хранителю
	Memory memoryForKeeper = Memory();

	//Диапазон для проверки и текущий номер
	//Он обязательно должен быть кратен 10
	const uint64_t rangeForCheck = 100'000;
	uint64_t currentNumber = 8;

	//Запомнить время запуска.
	auto start = std::chrono::system_clock::now();

	while (maxNumber > currentNumber)
	{
		vector<uint64_t>* keeper = memoryForKeeper.GetKeeper();
		//Пребор и проверка
		if ((*keeper).back() < rangeForCheck)
		{
			CheckForPrimals::RangeCheck(currentNumber, rangeForCheck, memoryForKeeper);
		}
		else
		{
			//добавить к хранителю все числа диапазона, которые оказались простыми.
			memoryForKeeper.AddKeeper(CheckForPrimals::GetListPrimalNumbers(currentNumber, rangeForCheck, memoryForKeeper));
		}
		std::cout<< (*keeper).back() <<endl;
		currentNumber += rangeForCheck;
	}
	auto end = std::chrono::system_clock::now();
	std::cout <<"Выполнение заняло: "<<  ((std::chrono::duration<double>)(end-start)).count();

	_getch();
}