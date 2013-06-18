#ifndef IMAGEVIEWERWINDOW_H
#define IMAGEVIEWERWINDOW_H

#include <QString>
#include <QMdiSubWindow>
#include <QCloseEvent>
#include <QLabel>
#include <QImage>
#include <QPixmap>

class ImageViewerWindow: public QMdiSubWindow
{
public:
    ImageViewerWindow();
    ~ImageViewerWindow();


    bool LoadImageFile( QString filename );
    void ZoomIn();
    void ZoomOut();

protected:
    void        closeEvent(QCloseEvent* close_event);
    QLabel*      ImageLabel_;
    QImage        Image_;
};

#endif