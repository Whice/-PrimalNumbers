#include "PrimalNumberKeeper.h"

class CheckForPrimals
{
public:
	CheckForPrimals()
	{

	}
	~CheckForPrimals()
	{

	}
	/// <summary>ѕроверка простое ли число.</summary>
	static bool IsPrimal(uint64_t number, Memory &memoryForKeeper)
	{
		vector<uint64_t> keeper = memoryForKeeper.GetKeeper();
		//¬ычислить корень один раз.
		uint64_t sqrtNumber = sqrt(number);
		uint64_t keeperSize = keeper.size();
		//ѕройтись по списку уже найденых чисел.

		for(int i=0;i<keeperSize;++i)
		{
			//≈сли делитс€ - отстой.
			if (number % keeper[i] == 0)
				return false;
			//≈сли корень был пройден, то дальше нет смысла смотреть - все ок.
			if (sqrtNumber < keeper[i])
				return true;
		}
		//“ут мы никогда не побываем, как на море.
		//Ќо пусть будет, оно придает ощущение безопасности(как картинка мор€).
		return true;
	}

	/// <summary>ѕроверка на простоту всех чисел в диапазоне и добавление их в список-хранитель.</summary>
	static void RangeCheck(uint64_t &numberStart, const uint64_t &range, Memory &memoryForKeeper)
	{

		vector<uint64_t> keeper = memoryForKeeper.GetKeeper();
		//ѕосчитать максимум
		uint64_t numberMax = numberStart + range;
		//ƒовести до значени€ 5
		uint64_t currentNumber = numberStart;
		if (currentNumber % 2 == 0)
			++currentNumber;
		while (!(currentNumber % 2 == 1 && currentNumber % 5 == 0))
		{
			if (IsPrimal(currentNumber, memoryForKeeper)) { keeper.push_back(currentNumber); }
			currentNumber += 2;
		}
		//“еперь currentNumber не делитс€ на 2, а на 5 делитс€.
		for (uint64_t i = currentNumber; i < numberMax; i += 10)
		{
			//XXX7
			if (IsPrimal(i + 2, memoryForKeeper)) { keeper.push_back(i+2); }
			//XXX9
			if (IsPrimal(i + 4, memoryForKeeper)) { keeper.push_back(i+4); }
			//XXX1
			if (IsPrimal(i + 6, memoryForKeeper)) { keeper.push_back(i+6); }
			//XXX3
			if (IsPrimal(i + 8, memoryForKeeper)) { keeper.push_back(i+8); }

		}
		memoryForKeeper.SetKeeper(keeper);
	}

	/// <summary>ѕроверка на простоту всех чисел в диапазоне и возвращение их отдельным списком.</summary>
	static vector<uint64_t> GetListPrimalNumbers(uint64_t &numberStart, const uint64_t &range, Memory &memoryForKeeper)
	{
		//ѕосичтать максимум
		uint64_t numberMax = numberStart + range;
		//завести локальный список дл€ найденых простых чисел
		vector<uint64_t> localKeeper;
		//ƒовести до значени€ 5
		uint64_t currentNumber = numberStart;
		if (currentNumber % 2 == 0)
			++currentNumber;
		while( !(currentNumber % 2 == 1 && currentNumber %5 == 0))
		{
			if (IsPrimal(currentNumber, memoryForKeeper)) { localKeeper.push_back(currentNumber); }
			currentNumber+=2;
		}
		//“еперь currentNumber не делитс€ на 2, а на 5 делитс€.
		for (uint64_t i = currentNumber; i < numberMax; i += 10)
		{
			//XXX7
			if (IsPrimal(i+2, memoryForKeeper)) { localKeeper.push_back(i+2); }
			//XXX9
			if (IsPrimal(i+4, memoryForKeeper)) { localKeeper.push_back(i+4); }
			//XXX1
			if (IsPrimal(i+6, memoryForKeeper)) { localKeeper.push_back(i+6); }
			//XXX3
			if (IsPrimal(i+8, memoryForKeeper)) { localKeeper.push_back(i+8); }

		}

		return localKeeper;
	}

};