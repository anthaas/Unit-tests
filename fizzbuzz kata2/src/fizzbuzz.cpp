#include "fizzbuzz.h"
using namespace std;
string FizzBuzz::Convert(int number)
{
	string strNumber = string();
	strNumber = to_string(number);

	string ret = string();
	ret = CheckDictionary(divisionDict, [&](int x, string s) { return number % x == 0; });
	ret += CheckDictionary(containDict, [&](int x, string s) { return strNumber.find(to_string(x)) != string::npos && ret.find(s) == string::npos; } );

	if (ret.empty())
		return strNumber;

	return ret;
}

string FizzBuzz::CheckDictionary(map<int,string> dict, function<bool(int, string)> test)
{
	string returnValue = string();
	for (auto entry : dict) {
		if (test(entry.first, entry.second))
			returnValue += entry.second;
	}
	return returnValue;
}
