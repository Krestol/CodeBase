#pragma once

std::vector<std::string> Parse(const std::string& str);

std::string Format(const std::string& str);

enum stage : int
{
	beforeFirstNameStage = 0,
	firstNameStage,
	secondNameStage,
	patronymicStage
};

struct Person
{
	Person(const std::string& str)
	{
		stage indecator = beforeFirstNameStage;
		for (const auto& ch : str)
		{
			if (ch >= 'A' && ch <= 'Z')
			{
				indecator = static_cast<stage>(indecator + 1);
			}

			if (!isalpha(ch))
			{
				continue;
			}

			if (indecator == firstNameStage)
			{
				firstName += ch;
			}
			else if (indecator == secondNameStage)
			{
				secondName += ch;
			}
			else if (indecator == patronymicStage)
			{
				patronymic += ch;
			}
		}
	}

	std::string ToString()
	{
		return secondName.substr(0, 1)
			+ "." + patronymic.substr(0, 1)
			+ ". " + firstName;
	}

	std::string firstName;
	std::string secondName;
	std::string patronymic;
};
