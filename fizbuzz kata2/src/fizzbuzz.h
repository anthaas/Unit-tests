#ifndef FIZZBUZZ_H__
#define FIZZBUZZ_H__
#include <map>
#include <string>
#include <functional>
class FizzBuzz
{
	public:
		std::string Convert(int number);
	private:
		std::map<int,std::string> divisionDict;
		std::map<int,std::string> containDict;
		std::string CheckDictionary(std::map<int,std::string>);
		std::function<std::string (std::string)> func;
};

#endif
