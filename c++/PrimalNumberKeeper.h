
#include <vector>
using namespace std;

/// <summary>
///	Класс памяти, который содержит хранителя чисел и методы для него.
/// </summary>
class Memory
{
public:
	/// <summary>
	///	Создать экземпляр памяти и сразу заполнить хранителя(список для хранения) первыми значениями.
	/// </summary>
	Memory()
	{
		CreateKeeper();
	}
	/*Копирующий конструктор*/
public:	Memory(const Memory& sourse)
	{
		this->keeper = nullptr;
		if (sourse.keeper != nullptr)
		{
			int sourseKeeperSize = sourse.keeper->size();
			vector<uint64_t>* keeperForCopyFrom = sourse.keeper;
			vector<uint64_t>* keeperForCopyTo = this->keeper;
			//глубокое копирование
			for (int i = 0; i < sourseKeeperSize; ++i)
			{
				keeperForCopyTo[i] = keeperForCopyFrom[i];
			}
		}
	}
	/*перемещающий конструктор*/
public:	Memory(Memory&& sourse)
	{
		this->keeper = nullptr;
		if (sourse.keeper != nullptr)
		{
			this->keeper = sourse.keeper;
			sourse.keeper = nullptr;
		}
	}


public:	~Memory()
	{
		delete this->keeper;
	}

private:
	/// <summary>
	///	Список для хранения простых чисел.
	/// </summary>
	vector<uint64_t>* keeper;
public:

	/// <summary>
	///	Заполнить хранителя(список для хранения) первыми значениями.
	/// </summary>
	void CreateKeeper()
	{
		this->keeper = new vector<uint64_t>();
		(*this->keeper) = { 3, 5, 7 };
	}

	/// <summary>
	///	Добавить к концу хранителя список чисел.
	/// </summary>
public: _inline	void AddKeeper(vector<uint64_t> *addList)
	{
		int sizeList = (*addList).size();
		for(int i=0;i< sizeList;++i)
			(*this->keeper).push_back((*addList)[i]);
		delete addList;
	}

	/// <summary>
	///	Получить хранителя(список найдены протых чисел).
	/// </summary>
public: _inline	vector<uint64_t>* GetKeeper()
	{
		return keeper;
	}
	/// <summary>
	///	Получить хранителя(список найдены протых чисел).
	/// </summary>
public:  _inline void SetKeeper(vector<uint64_t> *newKeeper)
{
	//Если ссылки равны, то ничего не делать
	if (newKeeper == this->keeper)
	{
		return;
	}
	//Если не равны, то взять большую
	if ((*newKeeper).size() > (*this->keeper).size())
	{
		vector<uint64_t>* oldKeeper=this->keeper;
		this->keeper = newKeeper;
		delete oldKeeper;//Удаление только для ц++
	}
	else
	{
		delete newKeeper;
	}

}

};