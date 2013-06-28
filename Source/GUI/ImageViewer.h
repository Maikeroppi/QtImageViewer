#ifndef IMAGEVIEWSCENE_H
#define IMAGEVIEWSCENE_H

#include <QGraphicsView>
#include <QMouseEvent>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QResizeEvent>
#include <QImage>


class ImageViewer: public QGraphicsView
{
public:
	ImageViewer( QWidget* parent = 0 );

	void				mouseMoveEvent ( QMouseEvent* move_event );
	void				mousePressEvent ( QMouseEvent* press_event);
	void				mouseReleaseEvent ( QMouseEvent* release_event );
	void				resizeEvent( QResizeEvent* resize_event );
	void				SetImage( const QImage* image );
	QImage const*		Image(); 

private:
	void				ScaleImage_( QSize const * new_size = 0 );
	void				UpdateZoomRect_();
	QGraphicsScene		Scene_;
	QGraphicsRectItem*	Box_;
	const QImage*		Image_;
	QPixmap				ImagePixels_;
	QGraphicsPixmapItem* PixmapItem_;
	QPointF				ClickPoint_;
	QPointF				ReleasePoint_;
	QRectF				ZoomArea_;
	QPointF				ZoomOffset_;
	bool				MouseDown_;
};

#endif