TEMPLATE = subdirs
CONFIG += ordered
SUBDIRS = SomeStaticLibrary \
        ConsolePersonReaderWriter \
        UnitTestsProject

ConsolePersonReaderWriter.depends = SomeStaticLibrary
UnitTestsProject.depends = SomeStaticLibrary
