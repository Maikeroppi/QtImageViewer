#ifndef QTIMAGEVIEWERCOMMANDS_H
#define QTIMAGEVIEWERCOMMANDS_H

#include <QUndoCommand>
#include <QSize>
#include <QWidget>

QT_FORWARD_DECLARE_CLASS( QtImageViewerMainWindow )

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

#endif