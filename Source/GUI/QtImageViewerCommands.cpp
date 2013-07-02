#include "QtImageViewerCommands.h"

ZoomCommand::ZoomCommand( ImageViewer* viewer, const QRectF& old_zoom, const QRectF& new_zoom )
	: Viewer_( viewer )
	, OldZoom_( old_zoom )
	, NewZoom_( new_zoom )
{
	Viewer_->NewZoomRect( NewZoom_ );
}

void ZoomCommand::undo()
{
	Viewer_->NewZoomRect( OldZoom_ );
}

void ZoomCommand::redo()
{
	Viewer_->NewZoomRect( NewZoom_ );
}