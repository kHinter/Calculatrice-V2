#ifndef __FUNCTION_H__
#define __FUNCTION_H__

#include <string>
#include <vector>

void removeSpaces(std::string & text); //CHECK
void warningMessage(); //CHECK
void strSplit(std::string text, std::vector<std::string>& strText); //CHECK
void clearAll(std::string& text, std::vector<std::string>& strText); //CHECK

/*
	Double
*/

double calc(std::vector<std::string>& strText);

/*
	Integer
*/

//append -> vector<std::string>
int partAppend(std::string& part, std::vector<std::string>& strText, int i); //CHECK

/*
	Booléens
*/

bool verifyChar(std::string& text); //CHECK
bool verifyOrder(std::vector<std::string> & strText); //CHECK
bool isstrconvert(std::string str); //CHECK

/*
	Vérificateurs de caractères
*/
bool isoperand(char c); //CHECK
bool isconvert(char c); //CHECK

#endif