#include <iostream>
#include <fstream>
#include "indent.h"
#include "unindent.h"

int countChar(std::string line, char c){
	int occurrenceOfCharacter = 0;
	
	for (int i=0; i<line.length(); ++i){
		if (line[i] == c) occurrenceOfCharacter++;
	}
	
	return occurrenceOfCharacter;
}

std::string indentFile(std::ifstream& file){
	std::cout << file;
	std::string line;
	
	std::string indentedStr = "\n";
	int openBrackets = 0;
	while (getline(file, line)){
		line = removeLeadingSpaces(line);
		int currentClosedBrackets = countChar(line, '}');
		int currentOpenBrackets = countChar(line, '{');
		
		if (currentClosedBrackets ==  currentOpenBrackets){
				currentOpenBrackets = 0;
				currentClosedBrackets = 0;
		}
		else{
			openBrackets -= currentClosedBrackets;
		}
		
		for (int i=1; i<=openBrackets; ++i){
			line = "\t" + line;
		}
		
		openBrackets += currentOpenBrackets;
		indentedStr += (line+"\n");
	}
	
	return indentedStr;
}	
