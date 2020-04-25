#include "Function.h"
#include <algorithm>
#include <ctype.h>
#include <iostream>

void removeSpaces(std::string & text)
{
	auto del{ std::remove(text.begin(), text.end(), ' ') };
	text.erase(del, text.end());
}

void warningMessage()
{
	std::cout << "Synthax error please try again !" << std::endl;
}

void strSplit(std::string text, std::vector<std::string>& strText)
{
	std::string part;
	int i = 1;
	
	//délimiteur de fin
	text.push_back('+');

	for (auto it{ std::begin(text) }; it != std::end(text); it++)
	{
		if (isconvert(*it))
		{
			if (*it == '-')
			{
				if (!std::empty(part))
				{
					i = partAppend(part, strText, i);
				}
				if (i % 2 == 0)
				{
					part.push_back(*it);
					i = partAppend(part, strText, i);
				}
				else
				{
					part.push_back(*it);
				}
			}
			else
			{
				part.push_back(*it);
			}
		}
		else
		{
			//si it - 1 est convertible (nombre) alors on l'ajoute au vector<std::string>
			if (!std::empty(part))
			{
				i = partAppend(part, strText, i);
			}

			//ajoute l'opération au vector
			part.push_back(*it);
			i = partAppend(part, strText, i);
		}
	}

	//enlève le délimiteur à la fin
	strText.erase(strText.end()-1);
}

double calc(std::vector<std::string>& strText)
{
	double result = std::stod(strText.front());

	for (int i = 0; i < strText.size(); i++)
	{
		if (i % 2 == 1)
		{
			switch (strText[i].front())
			{
				case '+': result += std::stod(strText[i + 1]);
					break;
				case '-' : result -= std::stod(strText[i + 1]);
					break;
				case '*' : result *= std::stod(strText[i + 1]);
					break;
				case '/' : result /= std::stod(strText[i + 1]);
					break;
			}
		}
	}
	return result;
}

int partAppend(std::string & part, std::vector<std::string>& strText, int i)
{
	strText.push_back(part);
	part.clear();
	return ++i;
}

bool verifyChar(std::string&  text)
{
	for (auto elem : text)
	{
		if (!(isdigit(elem) || isoperand(elem) || elem == '.'))
		{
			return false;
		}
		return true;
	}
}

bool verifyOrder(std::vector<std::string>& strText)
{
	for (int i = 0; i < strText.size(); i++)
	{
		if (i % 2 == 0)
		{
			if (!isstrconvert(strText[i]))
			{
				return false;
			}
		}
		else
		{
			if (isstrconvert(strText[i]))
			{
				return false;
			}
		}
	}
	return true;
}

bool isconvert(char c)
{
	return (isdigit(c) || c == '.' || c == '-');
}

bool isoperand(char c)
{
	return (c == '+' || c == '-' || c == '*' || c == '/');
}

bool isstrconvert(std::string str)
{
	if (str.size() == 1 && isoperand(str.front()))
	{
		return false;
	}
	else
	{
		return true;
	}
}