#ifndef QTIMAGEVIEWERMAINWINDOW_H
#define QTIMAGEVIEWERMAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>

#include "ImageViewer.h"

namespace Ui {
class QtImageViewerMainWindow;
}

class QtImageViewerMainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit QtImageViewerMainWindow(QWidget *parent = 0);
    ~QtImageViewerMainWindow();

private slots:
    void Open_();
    void Exit_();
    void Undo_();
    void Redo_();
    void About_();
    void HowToUse_();

    
private:
    Ui::QtImageViewerMainWindow *ui;

    ImageViewer* CreateImageViewerWindow_();
};

#endif // QTIMAGEVIEWERMAINWINDOW_H
