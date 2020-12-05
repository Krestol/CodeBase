#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

using namespace testing;

#include <gtest/gtest.h>
#include "impl/person.h"
#include "impl/utils.h"
#include "include/personsdatamanager.h"
#include "readermock.h"
#include "writermock.h"
#include "errorobservermock.h"

//Firstname Secondname Paronymic;Firstname Secondname  Paronymic;   Firstname Secondname Paronymic;Firstname Secondname Paronymic ;Firstname Secondname  Paronymic;   Firstname Secondname Paronymic

//(std::vector)
//И.О. Фамилия
//И.О. Фамилия
//И.О. Фамилия

TEST(ManagePersonsDataTest, checkReaderCalled)
{
    ReaderMock reader;
    WriterMock writer;
    ErrorObserverMock errorObserver;

    EXPECT_CALL(reader, Read());
    ManagePersonsData(reader, writer, errorObserver);
}

TEST(ManagePersonsDataTest, checkWriterCalled)
{
    ReaderMock reader;
    WriterMock writer;
    ErrorObserverMock errorObserver;

    ON_CALL(reader, Read()).WillByDefault(::testing::Return(std::string("Firstname Secondname Paronymic;")));
    EXPECT_CALL(writer, Write(::testing::_));
    ManagePersonsData(reader, writer, errorObserver);
}

TEST(ManagePersonsDataTest, checkWriterParams)
{
    ReaderMock reader;
    WriterMock writer;
    ErrorObserverMock errorObserver;

    ON_CALL(reader, Read()).WillByDefault(::testing::Return(
                    std::string("Firstname Secondname Paronymic;Firstname Secondname  Paronymic;")));
    std::vector<std::string> expected;
    expected.push_back("S.P. Firstname");
    expected.push_back("S.P. Firstname");
    EXPECT_CALL(writer, Write(expected));
    ManagePersonsData(reader, writer, errorObserver);
}

TEST(ManagePersonsDataTest, readerReturnsEmptyString)
{
    ReaderMock reader;
    WriterMock writer;
    ErrorObserverMock errorObserver;

    ON_CALL(reader, Read()).WillByDefault(::testing::Return(std::string()));
    EXPECT_CALL(writer, Write(::testing::_)).Times(0);
    EXPECT_CALL(errorObserver, OnError("Cann't parse empty string"));

    ManagePersonsData(reader, writer, errorObserver);
}

TEST(ManagePersonsDataTest, readerThrows)
{
    ReaderMock reader;
    WriterMock writer;
    ErrorObserverMock errorObserver;

    ON_CALL(reader, Read()).WillByDefault(::testing::Throw(std::exception()));
    EXPECT_CALL(writer, Write(::testing::_)).Times(0);
    EXPECT_CALL(errorObserver, OnError("Reader erro"));

    ManagePersonsData(reader, writer, errorObserver);
}

TEST(ManagePersonsDataTest, writerThrows)
{
    ReaderMock reader;
    WriterMock writer;
    ErrorObserverMock errorObserver;

    ON_CALL(writer, Write(::testing::_)).WillByDefault(::testing::Throw(std::exception()));
    ON_CALL(reader, Read()).WillByDefault(::testing::Return(
                    std::string("Firstname Secondname Paronymic;Firstname Secondname  Paronymic;")));
    EXPECT_CALL(errorObserver, OnError("Write erro"));

    ManagePersonsData(reader, writer, errorObserver);
}

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

TEST(FormatTest, general_2) {
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
