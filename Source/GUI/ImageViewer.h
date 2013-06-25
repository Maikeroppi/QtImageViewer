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
	QGraphicsScene		Scene_;
	QGraphicsRectItem*	Box_;
	const QImage*		Image_;
	QPointF				ClickPoint_;
	QRectF				ZoomArea_;	
	bool				MouseDown_;
};

#endif