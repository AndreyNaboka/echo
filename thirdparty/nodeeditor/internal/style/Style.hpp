#pragma once

#include <QtCore/QString>

class Style
{
public:
    virtual ~Style() = default;

private:
    // load
    virtual void loadJsonText(QString jsonText) = 0;
    virtual void loadJsonFile(QString fileName) = 0;
    virtual void loadJsonFromByteArray(QByteArray const &byteArray) = 0;
};
