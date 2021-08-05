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
	/// <summary>�������� ������� �� �����.</summary>
	static bool IsPrimal(uint64_t number, Memory &memoryForKeeper)
	{
		vector<uint64_t> keeper = memoryForKeeper.GetKeeper();
		//��������� ������ ���� ���.
		uint64_t sqrtNumber = sqrt(number);
		uint64_t keeperSize = keeper.size();
		//�������� �� ������ ��� �������� �����.

		for(int i=0;i<keeperSize;++i)
		{
			//���� ������� - ������.
			if (number % keeper[i] == 0)
				return false;
			//���� ������ ��� �������, �� ������ ��� ������ �������� - ��� ��.
			if (sqrtNumber < keeper[i])
				return true;
		}
		//��� �� ������� �� ��������, ��� �� ����.
		//�� ����� �����, ��� ������� �������� ������������(��� �������� ����).
		return true;
	}

	/// <summary>�������� �� �������� ���� ����� � ��������� � ���������� �� � ������-���������.</summary>
	static void RangeCheck(uint64_t &numberStart, const uint64_t &range, Memory &memoryForKeeper)
	{

		vector<uint64_t> keeper = memoryForKeeper.GetKeeper();
		//��������� ��������
		uint64_t numberMax = numberStart + range;
		//������� �� �������� 5
		uint64_t currentNumber = numberStart;
		if (currentNumber % 2 == 0)
			++currentNumber;
		while (!(currentNumber % 2 == 1 && currentNumber % 5 == 0))
		{
			if (IsPrimal(currentNumber, memoryForKeeper)) { keeper.push_back(currentNumber); }
			currentNumber += 2;
		}
		//������ currentNumber �� ������� �� 2, � �� 5 �������.
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

	/// <summary>�������� �� �������� ���� ����� � ��������� � ����������� �� ��������� �������.</summary>
	static vector<uint64_t> GetListPrimalNumbers(uint64_t &numberStart, const uint64_t &range, Memory &memoryForKeeper)
	{
		//��������� ��������
		uint64_t numberMax = numberStart + range;
		//������� ��������� ������ ��� �������� ������� �����
		vector<uint64_t> localKeeper;
		//������� �� �������� 5
		uint64_t currentNumber = numberStart;
		if (currentNumber % 2 == 0)
			++currentNumber;
		while( !(currentNumber % 2 == 1 && currentNumber %5 == 0))
		{
			if (IsPrimal(currentNumber, memoryForKeeper)) { localKeeper.push_back(currentNumber); }
			currentNumber+=2;
		}
		//������ currentNumber �� ������� �� 2, � �� 5 �������.
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