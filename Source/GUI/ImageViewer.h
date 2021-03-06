#ifndef IMAGEVIEWER_H
#define IMAGEVIEWER_H

#include <QGraphicsView>
#include <QMouseEvent>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QResizeEvent>
#include <QImage>


class ImageViewer: public QGraphicsView
{
	Q_OBJECT

public:
	ImageViewer( QWidget* parent = 0 );
	~ImageViewer();

	void				mouseMoveEvent ( QMouseEvent* move_event );
	void				mousePressEvent ( QMouseEvent* press_event);
	void				mouseReleaseEvent ( QMouseEvent* release_event );
	void				resizeEvent( QResizeEvent* resize_event );
	bool				LoadImage( const QString& filename );
	QImage const*		Image();
	void				NewZoomRect( const QRectF& zoom_box );
	QRectF				ZoomRect();
	void				SetAspectRatioMode( const Qt::AspectRatioMode ratio_mode );

signals:
	void				ZoomBoxDrawn( const QRectF& zoom_box );

private:
	void				ScaleImage_();
	void				UpdateZoomRect_( QRectF& in_rect );
	QGraphicsScene*		Scene_;
	QGraphicsRectItem*	Box_;
	QImage				Image_;
	QPixmap				ImagePixels_;
	QGraphicsPixmapItem* PixmapItem_;
	QPointF				ClickPoint_;
	QPointF				ReleasePoint_;
	QRectF				ZoomArea_;
	QRectF				BoxArea_;
	QPointF				ZoomOffset_;
	bool				MouseDown_;
	Qt::AspectRatioMode	RatioMode_;
};

#endif