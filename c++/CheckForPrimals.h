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
	/// <summary>Проверка простое ли число.</summary>
	static bool IsPrimal(uint64_t number, Memory &memoryForKeeper)
	{
		vector<uint64_t> keeper = memoryForKeeper.GetKeeper();
		//Вычислить корень один раз.
		uint64_t sqrtNumber = sqrt(number);
		uint64_t keeperSize = keeper.size();
		//Пройтись по списку уже найденых чисел.

		for(int i=0;i<keeperSize;++i)
		{
			//Если делится - отстой.
			if (number % keeper[i] == 0)
				return false;
			//Если корень был пройден, то дальше нет смысла смотреть - все ок.
			if (sqrtNumber < keeper[i])
				return true;
		}
		//Тут мы никогда не побываем, как на море.
		//Но пусть будет, оно придает ощущение безопасности(как картинка моря).
		return true;
	}

	/// <summary>Проверка на простоту всех чисел в диапазоне и добавление их в список-хранитель.</summary>
	static void RangeCheck(uint64_t &numberStart, const uint64_t &range, Memory &memoryForKeeper)
	{

		vector<uint64_t> keeper = memoryForKeeper.GetKeeper();
		//Посчитать максимум
		uint64_t numberMax = numberStart + range;
		//Довести до значения 5
		uint64_t currentNumber = numberStart;
		if (currentNumber % 2 == 0)
			++currentNumber;
		while (!(currentNumber % 2 == 1 && currentNumber % 5 == 0))
		{
			if (IsPrimal(currentNumber, memoryForKeeper)) { keeper.push_back(currentNumber); }
			currentNumber += 2;
		}
		//Теперь currentNumber не делится на 2, а на 5 делится.
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

	/// <summary>Проверка на простоту всех чисел в диапазоне и возвращение их отдельным списком.</summary>
	static vector<uint64_t>* GetListPrimalNumbers(uint64_t &numberStart, const uint64_t &range, Memory &memoryForKeeper)
	{
		//Посичтать максимум
		uint64_t numberMax = numberStart + range;
		//завести локальный список для найденых простых чисел
		vector<uint64_t>* localKeeper = new vector<uint64_t>();
		//Довести до значения 5
		uint64_t currentNumber = numberStart;
		if (currentNumber % 2 == 0)
			++currentNumber;
		while( !(currentNumber % 2 == 1 && currentNumber %5 == 0))
		{
			if (IsPrimal(currentNumber, memoryForKeeper)) { localKeeper->push_back(currentNumber); }
			currentNumber+=2;
		}
		//Теперь currentNumber не делится на 2, а на 5 делится.
		for (uint64_t i = currentNumber; i < numberMax; i += 10)
		{
			//XXX7
			if (IsPrimal(i+2, memoryForKeeper)) { localKeeper->push_back(i+2); }
			//XXX9
			if (IsPrimal(i+4, memoryForKeeper)) { localKeeper->push_back(i+4); }
			//XXX1
			if (IsPrimal(i+6, memoryForKeeper)) { localKeeper->push_back(i+6); }
			//XXX3
			if (IsPrimal(i+8, memoryForKeeper)) { localKeeper->push_back(i+8); }

		}

		return localKeeper;
	}

};