#include "pch.h"
#include "PersonParsing.h"
#include <ctype.h>
#include <stdio.h>

std::vector<std::string> Parse(const std::string& str)
{
	return std::vector<std::string>();
}

std::string Format(const std::string& str)
{
	if (str.empty())
	{
		return "";
	}
	return Person(str).ToString();
}
