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
		if( Box_ == 0 ) {
			Box_ = Scene_.addRect( -2, -2, -1, -1 );
		}
		MouseDown_ = true;
		ClickPoint_ = mapToScene( press_event->pos().x(), press_event->pos().y() );
	}
	QGraphicsView::mousePressEvent( press_event );
}

void ImageViewer::mouseMoveEvent( QMouseEvent* move_event )
{
	if( Image_ != 0 && MouseDown_ ) {
		ReleasePoint_ = mapToScene( move_event->pos().x(), move_event->pos().y() );
		
		UpdateZoomRect_();
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

void ImageViewer::UpdateZoomRect_()
{
	// Need to determine which point belongs in which position in order to support drawing 
	// boxes in any direction.

	qreal x1, x2, y1, y2;

	// Is ClickPoint_ the left most point?
	if( ClickPoint_.x() > ReleasePoint_.x() ) {
		// ReleasePoint_ is the left most point
		x1 = ReleasePoint_.x();
		x2 = ClickPoint_.x();
	} else {
		// ClickPoint_ is the left most point
		x1 = ClickPoint_.x();
		x2 = ReleasePoint_.x();
	}

	// Is ClickPoint the top most point?
	if( ClickPoint_.y() > ReleasePoint_.y() ) {
		// ReleasePoint_ is the top most point
		y1 = ReleasePoint_.y();
		y2 = ClickPoint_.y();
	} else {
		// ClickPoint_ is the top most point
		y1 = ClickPoint_.y();
		y2 = ReleasePoint_.y();
	}

	ZoomArea_.setCoords( x1, y1, x2, y2 );
	Box_->setRect( ZoomArea_ );
}