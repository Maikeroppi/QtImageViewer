#ifndef QTIMAGEVIEWERCOMMANDS_H
#define QTIMAGEVIEWERCOMMANDS_H

#include <QUndoCommand>
#include <QSize>
#include <QWidget>
#include <QGraphicsScene>
#include <QRect>

class ResizeCommand: public QUndoCommand
{
public:
	ResizeCommand( QWidget* target, QSize old_size, QSize new_size );
	void						undo();
	void						redo();

private:
	QSize						OldSize_;
	QSize						NewSize_;
	QWidget*					Target_;

};

class ZoomCommand: public QUndoCommand
{
public:
	ZoomCommand( QGraphicsScene* scene, QImage* image, QRect zoom_area );
	void						undo();
	void						redo();

private:
	QGraphicsScene*				Scene_;
	QRect						ZoomArea_;
	QImage*						Image_;
};

#endif