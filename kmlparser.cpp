#include "kmlparser.h"

KmlParser::KmlParser(QObject *parent, QString fileName) : QObject(parent)
{
    _fileName = fileName;

    if (fileExists()) {
        readKmlFile();
    }
}

QStringList KmlParser::coordinates() const
{
    return _coordinates;
}

void KmlParser::setCoordinates(const QStringList &coordinates)
{
    _coordinates = coordinates;
}

bool KmlParser::fileExists()
{
    QFileInfo kmlfile(_fileName);
    if (!kmlfile.exists())
        return false;
    return true;
}

void KmlParser::readKmlFile()
{

    /*!
         * \brief Opens a KML file and read its content
         * return:
         */

    _coordinates.clear();
    _content.clear();

    bool isPlacemark {false};
    bool isName {false};
    bool isAttibute {false};
    bool areCoordinates {false};
    QFile kmlfile(_fileName);

    // Open the KML file
    if (!kmlfile.open(QFile::ReadOnly | QFile::Text)) {
        qDebug() << "Error: Cannot open file "
                 << _fileName
                 << "for writing.";
        return;
    }

    QXmlStreamReader reader(&kmlfile);
    while(!reader.atEnd()) {
        // Read next element and switch according its content
        switch (reader.readNext()) {
        case 0:
            qDebug() << "NoToken";
            break;
        case 1:
            qDebug() << "Invalid";
            break;
        case 2:
            qDebug() << "StartDocument";
            continue;
            break;
        case 3:
            qDebug() << "EndDocument";
            break;
        case 4:
        {
            qDebug() << "StartElement";
            // Get the name of element
            QString name;
            name = reader.name().toString().trimmed();
            if (name == "Placemark")
                isPlacemark = true;
            if (name == "name")
                isName = true;
            if (name == "Polygon" || name == "LineString" || name == "Point") {
                isAttibute = true;
                _coordinates.append("Type: " + name);
            }
            if (name == "coordinates")
                areCoordinates = true;
            qDebug() << "  Element:" << name;
            break;
        }
        case 5:
        {
            qDebug() << "EndElement";

            // Get the name of element
            QString name;
            name = reader.name().toString().trimmed();
            if (name == "Placemark")
                isPlacemark = false;
            if (name == "name")
                isName = false;
            if (name == "Polygon" || name == "LineString" || name == "Point")
                isAttibute = false;
            if (name == "coordinates")
                areCoordinates = false;
            qDebug() << "  Element:" << name;
            break;
        }
        case 6:
        {
            qDebug() << "Characters";

            QString text;
            text = reader.text().toString().trimmed();
            qDebug() << text;

            if (!text.isEmpty())
                _content.append(text);

            // Append name of placemark
            if (isPlacemark && isName)
                _coordinates.append("Name: " + text);

            // Append the coordinates
            if (areCoordinates && isAttibute) {
                QStringList coords = text.split(" ");
                foreach (QString coord, coords) {
                    _coordinates.append(coord);
                }
            }
            break;
        }
        case 7:
            qDebug() << "Comment";
            break;
        case 8:
            qDebug() << "DTD";
            break;
        case 9:
            qDebug() << "EntityReference";
            break;
        case 10:
            qDebug() << "ProcessingInstruction";
            break;
        default:
            break;
        }
    }
    if (reader.hasError()) {
        qDebug() << "Error reading file.";
        return;
    }

    qDebug() << "XML file readed successfully!";

    return;
}
