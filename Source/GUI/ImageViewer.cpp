#include "ImageViewer.h"

ImageViewer::ImageViewer( QWidget* parent )
	: QGraphicsView( parent )
	, Scene_()
	, Box_()
	, Image_( 0 )
	, ClickPoint_( -1, -1 )
	, ZoomArea_( -2, -2, -1, -1)
	, MouseDown_( false )
{
	setScene( &Scene_ );
	ScaleImage_();

	
}

void ImageViewer::mousePressEvent( QMouseEvent* press_event )
{
	if( Image_ != 0 && press_event->button() == Qt::LeftButton ) {
		MouseDown_ = true;
		ClickPoint_ = mapToScene( press_event->pos().x(), press_event->pos().y() );
		ZoomArea_.setTopLeft( ClickPoint_ );
	}
	QGraphicsView::mousePressEvent( press_event );
}

void ImageViewer::mouseMoveEvent( QMouseEvent* move_event )
{
	if( Image_ != 0 && MouseDown_ ) {
		ZoomArea_.setBottomRight( mapToScene( move_event->pos().x(), move_event->pos().y() ) );

		if( Box_ == 0 ) {
			Box_ = Scene_.addRect( -2, -2, -1, -1 );
		}
		Box_->setRect( QRectF( ZoomArea_ ) );
	}
	QGraphicsView::mouseMoveEvent( move_event );
}

void ImageViewer::mouseReleaseEvent( QMouseEvent* release_event )
{
	if( release_event->button() == Qt::LeftButton) {
		MouseDown_ = false;
	}
	QGraphicsView::mouseReleaseEvent( release_event );
}

void ImageViewer::resizeEvent( QResizeEvent* resize_event )
{
	QGraphicsView::resizeEvent( resize_event );
	ScaleImage_( &( resize_event->size() ) );
}

void ImageViewer::SetImage( const QImage* image )
{
	Image_ = image;
	ScaleImage_();	
}

void ImageViewer::ScaleImage_( QSize const* new_size )
{
	if( Image_ != 0 ) {
		if( new_size == 0 ) new_size = &( this->size() );
		Scene_.clear();
		Scene_.addPixmap( QPixmap::fromImage( *Image_ ).scaled( this->size(), Qt::KeepAspectRatio, Qt::FastTransformation ) );
	}
}