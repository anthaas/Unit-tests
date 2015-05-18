#include "fizzbuzz.h"
using namespace std;
string FizzBuzz::Convert(int number)
{
	string strNumber = string();
	strNumber = to_string(number);

	string ret = string();
	ret = CheckDictionary(divisionDict, [&](pair<int, string> p) { return number % p.first == 0; });
	ret += CheckDictionary(containDict, [&](pair<int, string> p) { return strNumber.find(to_string(p.first)) != string::npos && ret.find(p.second) == string::npos; } );

	if (ret.empty())
		return strNumber;

	return ret;
}

string FizzBuzz::CheckDictionary(map<int,string> dict, function<bool(pair<int, string>)> test)
{
	string returnValue = string();
	for (auto entry : dict) {
		if (test(entry))
			returnValue += entry.second;
	}
	return returnValue;
}
