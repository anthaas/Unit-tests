#ifndef FIZZBUZZ_H__
#define FIZZBUZZ_H__
#include <utility>
#include <map>
#include <string>
#include <functional>
class FizzBuzz
{
	public:
		std::string Convert(int number);
	private:
		std::map<int,std::string> divisionDict = {{3, "Fizz"}, {5, "Buzz"}, {7, "Whiz"}};
		std::map<int,std::string> containDict = {{3, "Fizz"}, {5, "Buzz"}, {2, "Fizz"}, {4, "Whiz"}};
		std::string CheckDictionary(std::map<int,std::string>, std::function<bool(std::pair<int, std::string>)>);
};

#endif
