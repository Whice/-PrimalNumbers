
#include <vector>
using namespace std;

/// <summary>
///	����� ������, ������� �������� ��������� ����� � ������ ��� ����.
/// </summary>
class Memory
{
public:
	/// <summary>
	///	������� ��������� ������ � ����� ��������� ���������(������ ��� ��������) ������� ����������.
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
	///	������ ��� �������� ������� �����.
	/// </summary>
	vector<uint64_t> keeper;
public:

	/// <summary>
	///	��������� ���������(������ ��� ��������) ������� ����������.
	/// </summary>
	void CreateKeeper()
	{
		keeper = { 3, 5, 7 };
	}

	/// <summary>
	///	�������� � ����� ��������� ������ �����.
	/// </summary>
	void AddKeeper(vector<uint64_t> addList)
	{
		for (uint64_t num : addList)
			keeper.push_back(num);
	}

	/// <summary>
	///	�������� ���������(������ ������� ������ �����).
	/// </summary>
	vector<uint64_t> GetKeeper()
	{
		return keeper;
	}
	/// <summary>
	///	�������� ���������(������ ������� ������ �����).
	/// </summary>
	void SetKeeper(vector<uint64_t> &newKeeper)
	{
		if(newKeeper.size()> this->keeper.size())
		this->keeper = newKeeper;
	}

};