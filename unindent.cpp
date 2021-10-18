#include <iostream>
#include <fstream>
#include "unindent.h"

std::string removeLeadingSpaces(std::ifstream& file){
	std::string formattedFile = "";
	std::string inputFromFile;
	
	while (getline(file, inputFromFile)){
		formattedFile += removeLeadingSpaces(inputFromFile);
		formattedFile += "\n";
	}

	return formattedFile;
}

std::string removeLeadingSpaces(std::string line){
	std::string formattedStr = "";
	
	int i = 0;
	while (isspace(line[i])) i++;
	while (i < line.length()) formattedStr += line[i++];
	
	return formattedStr;
}
