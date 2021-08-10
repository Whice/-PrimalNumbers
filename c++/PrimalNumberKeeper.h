
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

	~Memory()
	{
	}

private:
	/// <summary>
	///	Список для хранения простых чисел.
	/// </summary>
	vector<uint64_t> keeper;
public:

	/// <summary>
	///	Заполнить хранителя(список для хранения) первыми значениями.
	/// </summary>
	void CreateKeeper()
	{
		keeper = { 3, 5, 7 };
	}

	/// <summary>
	///	Добавить к концу хранителя список чисел.
	/// </summary>
	void AddKeeper(vector<uint64_t> *addList)
	{
		int sizeList = (*addList).size();
		for(int i=0;i< sizeList;++i)
			keeper.push_back((*addList)[i]);
		delete addList;
	}

	/// <summary>
	///	Получить хранителя(список найдены протых чисел).
	/// </summary>
	vector<uint64_t> GetKeeper()
	{
		return keeper;
	}
	/// <summary>
	///	Получить хранителя(список найдены протых чисел).
	/// </summary>
	void SetKeeper(vector<uint64_t> &newKeeper)
	{
		if(newKeeper.size()> this->keeper.size())
		this->keeper = newKeeper;
	}

};