#ifndef FILEREADER_H
#define FILEREADER_H

#include <fstream>
#include <iostream>
#include <vector>
#include <iterator>
#include <sstream>
#include <map>

namespace util
{
	class FileReader 
	{
	public:
		FileReader() = delete;
		FileReader(std::string fileName);
		std::string readText();
		std::map<std::string,std::string> readMap();
		std::vector<std::string> readByBlank();
		std::vector<std::string> readByEndl();
		~FileReader();
	protected:
		std::ifstream fin;
	};
}

#endif
