#include "QtImageViewerMainWindow.h"
#include "ui_QtImageViewerMainWindow.h"

QtImageViewerMainWindow::QtImageViewerMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::QtImageViewerMainWindow)
{
    ui->setupUi(this);
}

QtImageViewerMainWindow::~QtImageViewerMainWindow()
{
    delete ui;
}
