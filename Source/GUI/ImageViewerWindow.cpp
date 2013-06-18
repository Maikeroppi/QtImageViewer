#include "ImageViewerWindow.h"

ImageViewerWindow::ImageViewerWindow()
    : ImageLabel_( new QLabel() )
    , Image_()
{
     ImageLabel_->setBackgroundRole( QPalette::Base );
     ImageLabel_->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );
     ImageLabel_->setScaledContents( true );
     setWidget( ImageLabel_ );
}

ImageViewerWindow::~ImageViewerWindow()
{
    delete ImageLabel_;
}

bool ImageViewerWindow::LoadImageFile( const QString filename )
{
    bool OpOkay = false;
    Image_.load( filename );

    if( !Image_.isNull() ) {
        ImageLabel_->setPixmap( QPixmap::fromImage( Image_ ) );
        resize( 100, 100 );
        OpOkay = true;
    }

    return OpOkay;
}

void ImageViewerWindow::closeEvent( QCloseEvent* close_event )
{
}