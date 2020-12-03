#include "pch.h"
#include <string>
#include <vector>
#include "PersonParsing.h"

//Фамилия Имя Отчество;Фамилия Имя  Отчество;   Фамилия Имя Отчество;Фамилия Имя Отчество ;Фамилия Имя  Отчество;   Фамилия Имя Отчество

//(std::vector)
//И.О. Фамилия
//И.О. Фамилия
//И.О. Фамилия   

TEST(ParseTest, emptyStr) {
	EXPECT_TRUE(Parse("").empty());
}

TEST(FormatTest, emptyStr) {
	EXPECT_TRUE(Format("").empty());
}

TEST(StringToPersonTest, emptyStr) {
	Person person("");	
	EXPECT_EQ(person.firstName, "");
	EXPECT_EQ(person.secondName, "");
	EXPECT_EQ(person.patronymic, "");
}

TEST(StringToPersonTest, firstName) {
	Person person("Ivanov Petro Vasylievich");
	EXPECT_EQ(person.firstName, "Ivanov");
}

TEST(StringToPersonTest, firstNameWithSpace) {
	Person person(" Ivanov Petro Vasylievich");
	EXPECT_EQ(person.firstName, "Ivanov");
}

TEST(StringToPersonTest, firstNameWithSeveralSpaces) {
	Person person("  Ivanov Petro Vasylievich");
	EXPECT_EQ(person.firstName, "Ivanov");
}

TEST(StringToPersonTest, secondName) {
	Person person("Ivanov Petro Vasylievich");
	EXPECT_EQ(person.secondName, "Petro");
}

TEST(StringToPersonTest, patronymic) {
	Person person("Ivanov Petro Vasylievich");
	EXPECT_EQ(person.patronymic, "Vasylievich");
}

TEST(StringToPersonTest, generalTest) {
	Person person("Ivanov Petro Vasylievich");
	EXPECT_EQ(person.firstName, "Ivanov");
	EXPECT_EQ(person.secondName, "Petro");
	EXPECT_EQ(person.patronymic, "Vasylievich");
}

TEST(StringToPersonTest, nonSpacedelimeter) {
	Person person("Ivanov .Petro. Vasylievich");
	EXPECT_EQ(person.firstName, "Ivanov");
	EXPECT_EQ(person.secondName, "Petro");
	EXPECT_EQ(person.patronymic, "Vasylievich");
}

TEST(FormatTest, general) {
	EXPECT_EQ("P.V. Ivanov", Format("Ivanov Petro Vasylievich"));
}

TEST(FormatTest, general) {
	EXPECT_EQ("P.V. Ivanov", Format("Ivanov Petro Vasylievich"));
}



//Home task
//TEST(StringToPersonTest, lowcase) {
//	Person person = StringToPerson("  ivanov   petro   vasylievich  ");
//	EXPECT_EQ(person.firstName, "Ivanov");
//	EXPECT_EQ(person.secondName, "Petro");
//	EXPECT_EQ(person.patronymic, "Vasylievich");
//}

//TEST(StringToPersonTest, doubleFirstName) {
//	Person person = StringToPerson("Ivanov-Ivanov Petro-Petro Vasylievich");
//	EXPECT_EQ(person.firstName, "Ivanov-Ivanov");
//	EXPECT_EQ(person.secondName, "Petro");
//	EXPECT_EQ(person.patronymic, "Vasylievich");
//}

//TEST(StringToPersonTest, corrupted) {
//	Person person("Petro Vasylievich");
//	EXPECT_EQ(person.firstName, "");
//	EXPECT_EQ(person.secondName, "");
//	EXPECT_EQ(person.patronymic, "");
//}

//TEST(StringToPersonTest, corrupted) {
//	Person person("4623742638428");
//	EXPECT_EQ(person.firstName, "");
//	EXPECT_EQ(person.secondName, "");
//	EXPECT_EQ(person.patronymic, "");
//}
//


//
//TEST(StringToPersonTest, corrupted) {
//	//EXPECT_THROW();
//	Person person("Petro Vasylievich");
//	EXPECT_EQ(person.firstName, "");
//	EXPECT_EQ(person.secondName, "");
//	EXPECT_EQ(person.patronymic, "");
//}

//TEST(FormatTest, general) {
//	EXPECT_EQ("P.V. Ivanov", Format("Ivanov Petro Vasylievich"));
//}

//1. разбить по элементам и/или заполнить Фамилия Имя Отчество;Фамилия Имя  Отчество;   Фамилия Имя Отчество;Фамилия Имя Отчество ;Фамилия Имя  Отчество;   Фамилия Имя Отчество >> Фамилия Имя Отчество|Фамилия Имя Отчество|Фамилия Имя Отчество|
//2. форматирование Фамилия Имя Отчество -> И.О. Фамилия
