#include "ImageViewer.h"

ImageViewer::ImageViewer( QWidget* parent )
	: QGraphicsView( parent )
	, Scene_( new QGraphicsScene( this ) )
	, Box_()
	, Image_()
	, ClickPoint_( -1, -1 )
	, ZoomArea_( -2, -2, -1, -1 )
	, BoxArea_( -2, -2, -1, -1 )
	, ZoomOffset_( 0, 0 )
	, MouseDown_( false )
	, PixmapItem_( NULL )
	, RatioMode_( Qt::KeepAspectRatio )
{
	setScene( Scene_ );
}

ImageViewer::~ImageViewer()
{
	delete Scene_;
}

void ImageViewer::mousePressEvent( QMouseEvent* press_event )
{
	if( !Image_.isNull() && press_event->button() == Qt::LeftButton ) {
		if( Box_ == 0 ) {
			Box_ = Scene_->addRect( -2, -2, -1, -1 );
		}
		MouseDown_ = true;
		ClickPoint_ = mapToScene( press_event->pos().x(), press_event->pos().y() );
	}
	QGraphicsView::mousePressEvent( press_event );
}

void ImageViewer::mouseMoveEvent( QMouseEvent* move_event )
{
	if( !Image_.isNull() && MouseDown_ ) {
		ReleasePoint_ = mapToScene( move_event->pos().x(), move_event->pos().y() );
		UpdateZoomRect_( BoxArea_ );
		Box_->setRect( BoxArea_ );
	}
	QGraphicsView::mouseMoveEvent( move_event );
}

void ImageViewer::mouseReleaseEvent( QMouseEvent* release_event )
{
	QRectF NewZoomBox;
	if( release_event->button() == Qt::LeftButton) {
		MouseDown_ = false;
		ReleasePoint_ = mapToScene( release_event->pos().x(), release_event->pos().y() );
		UpdateZoomRect_( NewZoomBox );
		Box_->setRect( -2, -2, -1, -1 );
		emit ZoomBoxDrawn( NewZoomBox );
	}
	QGraphicsView::mouseReleaseEvent( release_event );
}

void ImageViewer::NewZoomRect( const QRectF& zoom_box )
{
	ZoomArea_ = zoom_box;
	
	fitInView( ZoomArea_, RatioMode_ );
}

QRectF ImageViewer::ZoomRect()
{
	return ZoomArea_;
}

void ImageViewer::SetAspectRatioMode( const Qt::AspectRatioMode ratio_mode )
{
	RatioMode_ = ratio_mode;
	ScaleImage_();
}

void ImageViewer::resizeEvent( QResizeEvent* resize_event )
{
	ScaleImage_();
	QGraphicsView::resizeEvent( resize_event );
}

bool ImageViewer::LoadImage( const QString& filename )
{
	bool LoadSuccessful = false;
	Image_.load( filename );
	if( !Image_.isNull() ) {
		Scene_->removeItem( PixmapItem_ );
		PixmapItem_ = Scene_->addPixmap( QPixmap::fromImage( Image_ ) );
		ScaleImage_();

		LoadSuccessful = true;
	}

	return LoadSuccessful;
}

void ImageViewer::ScaleImage_()
{
	if( !Image_.isNull() ) {
		fitInView( PixmapItem_, RatioMode_ );
		ZoomArea_ = sceneRect();
	}
}

void ImageViewer::UpdateZoomRect_( QRectF& in_box )
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

	in_box.setCoords( x1, y1, x2, y2 );
}
