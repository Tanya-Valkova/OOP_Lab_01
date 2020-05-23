#include <iostream>
#include <list>
#include <fstream>
#include <string>

using namespace std;

void Numbers();
void FileNumbers();

int main()
{
	cout << " *Version with console*" << endl;
	Numbers();
	cout << "\n -----------------------------------" << endl;
	cout << " *Version with files*" << endl;
	FileNumbers();
	return 0;
}

void Numbers()
{
	list<int>* number = new list<int>;

	number->push_back(60);
	number->push_back(70);
	number->push_back(80);
	number->push_back(90);
	number->push_front(50);
	number->push_front(40);
	number->push_front(30);
	number->push_front(20);
	number->push_front(10);

	cout << "\n" << " List of digits before reverse:" << endl;
	for (int value : *number)
	{
		cout << "\t\t\t\t" << value << endl;
	}

	number->reverse();

	cout << "\n" << " List of digits after reverse:" << endl;
	while (!number->empty())
	{
		cout << "\t\t\t\t" << number->front() << endl;
		number->pop_front();
	}
	delete number;
}

void FileNumbers()
{
	ifstream datafile;
	string dfilename = "Digits.txt";
	datafile.open(dfilename, ifstream::in);

	if (datafile.is_open())
	{
		cout << "\n" << " File is open!" << endl;
	}
	else
	{
		cout << "\n" << " Error opening file!" << endl;
		return;
	}

	list<int> number;
	int value;

	cout << "\n" << " List of digits before reverse:" << endl;
	while (!datafile.eof())
	{
		datafile >> value;
		cout << "\t\t\t\t" << value << endl;
		number.push_back(value);
	}

	number.reverse();

	ofstream resultfile;
	string rfilename = "Result.txt";
	resultfile.open(rfilename, ofstream::out);

	cout << "\n" << " List of digits after reverse:" << endl;

	for (auto value = number.begin(); value != number.end(); value++)
	{
		cout << "\t\t\t\t" << *value << endl;
		resultfile << *value << endl;
	}
	cout << "\n" << " The result is written to the file \"" << rfilename << "\"" << endl;

	number.clear();
	datafile.close();
	resultfile.close();
}