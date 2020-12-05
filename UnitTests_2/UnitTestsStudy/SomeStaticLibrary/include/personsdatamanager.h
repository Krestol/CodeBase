#ifndef PERSONSDATAMANAGER_H
#define PERSONSDATAMANAGER_H
#include "ierrorobserver.h"
#include "ireader.h"
#include "iwriter.h"

void ManagePersonsData(const IReader& reader, const IWriter& writer, const IErrorObserver& errorObserver);

#endif // PERSONSDATAMANAGER_H
