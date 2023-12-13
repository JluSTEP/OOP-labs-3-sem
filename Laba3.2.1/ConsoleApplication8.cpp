#include <iostream>
#include <fstream>
#include <string>


using namespace std;

class CustomException :public exception
{
public:
	CustomException(const char* msg, int code): exception(msg, code){
		data = code;
	}

	int code() const { return data; }

private:
	int data;
};

double funcForZ1(int x) {
	if ((pow(x, 2) - 9) < 0) {
		throw CustomException("отрицательное значение под корнем!!!", x);
	}
	if (((x - 1) * sqrt(pow(x, 2) - 9) + pow(x, 2) - 2 * x - 3) == 0) {
		throw CustomException("значение нуль в знаменателе!!!", x);
	}
	return ((x + 1) * sqrt(pow(x, 2) - 9) + x * (x + 2) - 3) / ((x - 1) * sqrt(pow(x, 2) - 9) + pow(x, 2) - 2 * x - 3);
}

double funcForZ2(int x) {
	if ((x - 3) == 0) {
		throw CustomException("значение нуль в знаменателе!!!", x);
	}
	if ((x + 3) / (x - 3) < 0) {
		throw CustomException("отрицательное значение под корнем!!!", x);
	}
	return (sqrt((x + 3) / (x - 3)));
}

int main()
{
	setlocale(0, "rus");
	int x;
	double z1, z2;

	cout << " Enter b value: ";
	cin >> x;

	try
	{
		cout << "=============== Z1 ===============" << endl;
		z1 = funcForZ1(x);
		cout << "Z1 = " << z1;
		cout << endl;
		cout << "=============== Z2 ===============" << endl;
		z2 = funcForZ2(x);
		cout << "Z2 = " << z2;

	}
	catch (const CustomException& ex)
	{
		cout << ex.what() << endl << ex.code();
	}
	catch (const exception& ex)
	{

	}

	return 0;
}

