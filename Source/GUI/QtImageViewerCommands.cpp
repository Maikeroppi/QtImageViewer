#include "QtImageViewerCommands.h"

ResizeCommand::ResizeCommand( QWidget* target, QSize old_size, QSize new_size )
	: Target_( target )
	, OldSize_( old_size )
	, NewSize_( new_size )
{
	Target_->resize( new_size );
}

void ResizeCommand::undo()
{
	Target_->resize( OldSize_ );
}

void ResizeCommand::redo()
{
	Target_->resize( NewSize_ );
}

ZoomCommand::ZoomCommand( QGraphicsScene* scene, QImage* image, QRect zoom_area )
	: Scene_( scene )
	, Image_( image )
	, ZoomArea_( zoom_area )
{
	Scene_->clear();
	Scene_->addPixmap( QPixmap::fromImage( Image_->copy( ZoomArea_ ) ).scaled( Scene_->width(), Scene_->height() ) );
}

void ZoomCommand::undo()
{
}

void ZoomCommand::redo()
{
}