#include "fizzbuzz.h"
using namespace std;
string FizzBuzz::Convert(int number)
{
	string strNumber = string();
	strNumber = to_string(number);

	string ret = string();
	ret = CheckDictionary(divisionDict /*, anonymous function */);
	ret += CheckDictionary(containDict /*, anonymous function */);

	if (ret.empty())
		return strNumber;

	return ret;
}

string FizzBuzz::CheckDictionary(map<int,string> /*, anonymous function */)
{
	string returnValue = string();

	return returnValue;
}
