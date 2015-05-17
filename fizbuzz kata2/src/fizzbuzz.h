#ifndef FIZZBUZZ_H__
#define FIZZBUZZ_H__
#include <map>
#include <string>
class FizzBuzz
{
	public:
		std::string Convert(int number);
	private:
		std::map<int,std::string> divisionDict;
		std::map<int,std::string> containDict;
		std::string CheckDictionary(std::map<int,std::string>);
};

#endif
