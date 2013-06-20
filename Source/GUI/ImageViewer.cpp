#include "ImageViewer.h"

ImageViewer::ImageViewer()
    : ImageLabel_( new QLabel() )
    , Image_()
	, Scene_( 0 )
{
     ImageLabel_->setBackgroundRole( QPalette::Base );
     ImageLabel_->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );
     ImageLabel_->setScaledContents( true );
     //setWidget( ImageLabel_ );

	 Scene_ = new QGraphicsScene();

	 this->setScene( Scene_ );
	 Scene_->setSceneRect( 0.0, 0.0, 200.0, 200.0 );
	 Scene_->addRect( 20, 20, 90, 90, QPen(), QBrush( QColor( "orchid" ) ) );

	 this->setLayout( new QVBoxLayout() );
}

ImageViewer::~ImageViewer()
{
	delete Scene_;
	delete ImageLabel_;
}

bool ImageViewer::LoadImageFile( const QString filename )
{
    bool OpOkay = false;
    Image_.load( filename );

    if( !Image_.isNull() ) {
		Scene_->clear();
        resize( 200, 200 );
		OpOkay = true;
    }

    return OpOkay;
}
void ImageViewer::resizeEvent( QResizeEvent* resize_event)
{
	QSize size = this->size();
	Scene_->clear();
	Scene_->setSceneRect( 0, 0, resize_event->size().width(), resize_event->size().height() );
	QGraphicsPixmapItem* Pixmap = Scene_->addPixmap( QPixmap::fromImage( Image_ ).scaled( resize_event->size() ) );
	Pixmap->setPos( 0, 0);
	
}