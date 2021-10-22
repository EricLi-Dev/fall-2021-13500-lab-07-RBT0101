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
	std::string line;
	
	//Final output
	std::string indentedStr = "";
	
	//Number of tabs to indent 
	int numberOfTabs = 0;
	
	//Get each line from the input file
	while (getline(file	, line)){
		line = removeLeadingSpaces(line);
		int currentClosedBrackets = countChar(line, '}');
		int currentOpenBrackets = countChar(line, '{');
		char firstSpecialChar = line[0];
		
		//If the first character is a closing bracket, then it must match the previously opened bracket's indentation, which is
		//# of open brackets - 1.
		if (firstSpecialChar == '}'){
			numberOfTabs--;
			currentClosedBrackets--;
		}
		
		for (int i=1; i<=numberOfTabs; ++i){
				line = '\t' + line;
		}
		
		numberOfTabs += currentOpenBrackets - currentClosedBrackets;
		indentedStr += line + "\n";
	}

	std::cout << "Output: \n" << indentedStr << "\n";
	return indentedStr;
}	
