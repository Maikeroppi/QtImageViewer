#ifndef QTIMAGEVIEWERCOMMANDS_H
#define QTIMAGEVIEWERCOMMANDS_H

#include <QUndoCommand>
#include <QSize>
#include <QWidget>
#include <QGraphicsScene>
#include <QRect>

#include "ImageViewer.h"

class ZoomCommand: public QUndoCommand
{
public:
	ZoomCommand( ImageViewer* viewer, const QRectF& old_zoom, const QRectF& new_zoom );
	void						undo();
	void						redo();

private:
	ImageViewer*				Viewer_;
	QRectF						OldZoom_;
	QRectF						NewZoom_;
};

#endif