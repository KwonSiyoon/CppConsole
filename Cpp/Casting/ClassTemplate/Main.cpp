#include "iostream"

// 클래스 템플릿.
template<typename T>
class Data
{
public:
	Data(T newData) : data(newData)
	{

	}

	void SetData(T newData)
	{
		data = newData;
	}

	T GetData()	const { return data; }

private:
	T data;
};


int main()
{
	Data<int> data(10);
	Data<float> pi(3.141592f);
	std::cout << data.GetData() << "\n";
	std::cout << pi.GetData() << "\n";
}