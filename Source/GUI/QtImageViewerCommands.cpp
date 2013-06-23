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