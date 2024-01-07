#include "FileReader.h"

namespace util
{
	FileReader::FileReader(std::string fileName)
	{
		this->fin.open(fileName);
	}
	
	std::string FileReader::readText()
	{
		std::string text;
		fin >> text;
		return text;
	}
	
	std::map<std::string,std::string> FileReader::readMap()
	{
		std::string a {};
		std::string b {};
		std::map<std::string,std::string> result;
		auto getPair = [&]()->std::ifstream&
		{
			std::getline(fin,a);
			std::getline(fin,b);
			return fin;
		};
		while(getPair())
		{
			result[a] = b;
		}
		return result;
	}
	
	std::vector<std::string> FileReader::readByBlank()
	{
		return std::vector<std::string>(std::istream_iterator<std::string>(fin),std::istream_iterator<std::string>());
	}
	
	std::vector<std::string> FileReader::readByEndl()
	{
		std::vector<std::string> result;
		while(fin)
		{
			std::string tempLine;
			getline(fin,tempLine);
			result.push_back(tempLine);
		}
		return result;
	}
	
	FileReader::~FileReader()
	{
		this->fin.close();
	}
}
