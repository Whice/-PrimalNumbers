
#include <vector>
using namespace std;

/// <summary>
///	 ласс пам€ти, который содержит хранител€ чисел и методы дл€ него.
/// </summary>
class Memory
{
public:
	/// <summary>
	///	—оздать экземпл€р пам€ти и сразу заполнить хранител€(список дл€ хранени€) первыми значени€ми.
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
	///	—писок дл€ хранени€ простых чисел.
	/// </summary>
	vector<uint64_t> keeper;
public:

	/// <summary>
	///	«аполнить хранител€(список дл€ хранени€) первыми значени€ми.
	/// </summary>
	void CreateKeeper()
	{
		keeper = { 3, 5, 7 };
	}

	/// <summary>
	///	ƒобавить к концу хранител€ список чисел.
	/// </summary>
	void AddKeeper(vector<uint64_t> addList)
	{
		for (uint64_t num : addList)
			keeper.push_back(num);
	}

	/// <summary>
	///	ѕолучить хранител€(список найдены протых чисел).
	/// </summary>
	vector<uint64_t> GetKeeper()
	{
		return keeper;
	}
	/// <summary>
	///	ѕолучить хранител€(список найдены протых чисел).
	/// </summary>
	void SetKeeper(vector<uint64_t> &newKeeper)
	{
		if(newKeeper.size()> this->keeper.size())
		this->keeper = newKeeper;
	}

};