#ifndef IMAGEVIEWERWINDOW_H
#define IMAGEVIEWERWINDOW_H

#include <QString>
#include <QMdiSubWindow>
#include <QCloseEvent>
#include <QLabel>
#include <QImage>
#include <QPixmap>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QGraphicsView>
#include <QVBoxLayout>
#include <QResizeEvent>
#include <QSizePolicy>

class ImageViewer: public QGraphicsView
{
public:
    ImageViewer();
    ~ImageViewer();

    bool LoadImageFile( QString filename );
    void ZoomIn();
    void ZoomOut();

protected:
	void			resizeEvent( QResizeEvent* resize_event );
    QLabel*         ImageLabel_;
    QImage          Image_;

	QGraphicsScene*	Scene_;
};

#endif