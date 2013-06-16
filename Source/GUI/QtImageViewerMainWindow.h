#ifndef QTIMAGEVIEWERMAINWINDOW_H
#define QTIMAGEVIEWERMAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class QtImageViewerMainWindow;
}

class QtImageViewerMainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit QtImageViewerMainWindow(QWidget *parent = 0);
    ~QtImageViewerMainWindow();
    
private:
    Ui::QtImageViewerMainWindow *ui;
};

#endif // QTIMAGEVIEWERMAINWINDOW_H
