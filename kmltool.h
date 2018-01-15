#ifndef KMLTOOL_H
#define KMLTOOL_H

#include <QFileDialog>
#include <QMainWindow>
#include <QMessageBox>
#include "kmlparser.h"
#include "aboutdialog.h"
#include "helpdialog.h"

namespace Ui {
class KmlTool;
}

class KmlTool : public QMainWindow
{
    Q_OBJECT

public:
    explicit KmlTool(QWidget *parent = 0);
    ~KmlTool();

private:
    Ui::KmlTool *ui;

    QString _fileName;
    QStringList _coordinates;

private slots:
    void about();
    void selectFileName();
    void parseFile();
    void saveFile();
    void help();
};

#endif // KMLTOOL_H
