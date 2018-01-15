#ifndef KMLPARSER_H
#define KMLPARSER_H

#include <QObject>
#include <QStringList>
#include <QString>
#include <QFileInfo>
#include <QDebug>
#include <QFile>
#include <QXmlStreamReader>

class KmlParser : public QObject
{
    Q_OBJECT
public:
    explicit KmlParser(QObject *parent = nullptr, QString fileName = "");

    QStringList coordinates() const;
    void setCoordinates(const QStringList &coordinates);

//signals:

//public slots:

private:
    QString _fileName;
    QStringList _coordinates;
    QStringList _content;

private slots:
    bool fileExists();
    void readKmlFile();
};

#endif // KMLPARSER_H
