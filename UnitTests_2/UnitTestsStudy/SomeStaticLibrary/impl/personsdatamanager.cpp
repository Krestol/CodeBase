#include "include/personsdatamanager.h"
#include "utils.h"

namespace
{
    std::string Read(const IReader& reader, const IErrorObserver& errorObserver)
    {
        std::string str;
        try
        {
            str = reader.Read();
        }
        catch (const std::exception& ex)
        {
            errorObserver.OnError("Reader erro");
            throw;
        }
        return str;
    }

    void Write(const std::vector<std::string>& result, const IWriter& writer, const IErrorObserver& errorObserver)
    {
        try
        {
            writer.Write(result);
        }
        catch (const std::exception& /*ex*/)
        {
            errorObserver.OnError("Write erro");
            throw;
        }
    }
}

void ManagePersonsData(const IReader& reader, const IWriter& writer, const IErrorObserver& errorObserver)
{
    std::string str;
    try
    {
        str = Read(reader, errorObserver);
        if (str.empty())
        {
            errorObserver.OnError("Cann't parse empty string");
        }
        else
        {
            auto result = Parse(str);
            Write(result, writer, errorObserver);
        }
    }
    catch (const std::exception& /*ex*/)
    {
        return;
    }
}
