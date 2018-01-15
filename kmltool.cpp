#include "kmltool.h"
#include "ui_kmltool.h"

KmlTool::KmlTool(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::KmlTool)
{
    ui->setupUi(this);

    // Set window icon
    QIcon winIcon(":/images/icons/16x16/google_earth.png");
    this->setWindowIcon(winIcon);

    connect(ui->browseButton, SIGNAL(pressed()),       SLOT(selectFileName()));
    connect(ui->parseButton,  SIGNAL(pressed()),       SLOT(parseFile()));
    connect(ui->actionOpen,   SIGNAL(triggered(bool)), SLOT(selectFileName()));
    connect(ui->actionParse,  SIGNAL(triggered(bool)), SLOT(parseFile()));
    connect(ui->actionAbout,  SIGNAL(triggered(bool)), SLOT(about()));
    connect(ui->actionSave,   SIGNAL(triggered(bool)), SLOT(saveFile()));
    connect(ui->actionHelp,   SIGNAL(triggered(bool)), SLOT(help()));
}

KmlTool::~KmlTool()
{
    delete ui;
}

void KmlTool::about()
{
    AboutDialog aboutDlg;
    aboutDlg.exec();
}

void KmlTool::selectFileName()
{
    _fileName = QFileDialog::getOpenFileName(this, tr("Select KML File"), QDir::homePath(), tr("KML files (*.kml)"));
    ui->lineEdit->setText(_fileName);
}

void KmlTool::parseFile()
{
    if (!_fileName.isEmpty()) {
        KmlParser parser(this, _fileName);
        _coordinates = parser.coordinates();
    }

    QString coordText = _coordinates.join("\n");

    ui->plainTextEdit->setPlainText(coordText);
}

void KmlTool::saveFile()
{
    QString textFile = QFileDialog::getSaveFileName(this, tr("Save text file"), QDir::homePath(), tr("Text files (*.txt)"));

    if (textFile.isEmpty())
        return;

//    QFileInfo saveFileInfo(textFile);

//    if (saveFileInfo.exists()) {
//        // Replace?
//        QMessageBox msgBox;
//        msgBox.setWindowTitle(tr("Document already exists"));
//        msgBox.setText(tr("The document already exists. Do you want to replace it?"));
//        msgBox.setInformativeText(tr("A file or directory already exists in this location. Replacing it will overwrite its current content."));
//        msgBox.setIcon(QMessageBox::Warning);
//        msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Cancel);
//        msgBox.setDefaultButton(QMessageBox::Save);
//        int replace = msgBox.exec();

//        if (replace == QMessageBox::Cancel)
//            return;
//    }

    // Save the coordinates to a text file
    QFile txtFile(textFile);
    if (txtFile.open(QFile::WriteOnly)) {
        QTextStream text(&txtFile);
        text << ui->plainTextEdit->toPlainText(); // Get content from text edit field
    }
}

void KmlTool::help()
{
    HelpDialog helpDlg;
    helpDlg.exec();
}
