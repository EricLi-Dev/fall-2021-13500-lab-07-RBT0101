#include <iostream>
#include <fstream>
#include "unindent.h"
#include "indent.h"

int main(){
	//Task A
	std::ifstream badFormatFile ("bad-code.cpp");
	if (badFormatFile.is_open()){
		std::cout << "bad-code.cpp has been opened for reading" << std::endl;
	}
	else{
		std::cout << "invalid attempt to open bad-code.cpp for reading!" << std::endl;
	}
	std::cout << "Testing removeLeadingSpaces() method on \"bad-code.cpp\": \n" << removeLeadingSpaces(badFormatFile) << std::endl;
	badFormatFile.close();
	//Task B 
	std::ifstream badFormatFileTaskB ("bad-code.cpp");
	std::ofstream fixedFile ("fixed-code.cpp");
	
	std::cout << "Testing indent.cpp (formatted output will be stored to 'fixed-code.cpp')" << std::endl;
	std::string indentedFile = indentFile(badFormatFileTaskB);
	fixedFile << indentedFile;
	
	badFormatFileTaskB.close();
	fixedFile.close();
	return 0;
}
