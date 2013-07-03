#ifndef QTIMAGEVIEWERMAINWINDOW_H
#define QTIMAGEVIEWERMAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QCloseEvent>
#include <QLabel>
#include <QImage>
#include <QPixmap>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QGraphicsView>
#include <QVBoxLayout>
#include <QResizeEvent>
#include <QSizePolicy>
#include <QUndoStack>
#include <QUndoCommand>
#include <QAction>
#include <QIcon>
#include <QMessageBox>


#include "ImageViewer.h"
#include "QtImageViewerCommands.h"


namespace Ui {
class QtImageViewerMainWindow;
}

class QtImageViewerMainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit QtImageViewerMainWindow(QWidget *parent = 0);
    ~QtImageViewerMainWindow();

private slots:
    void				Open_();
    void				Exit_();
    void				About_();
	void				ToggleLockAspectRatio_();
    void				HandleZoomBox_( const QRectF& zoom_box );
	
    
private:
    Ui::QtImageViewerMainWindow *ui;
	QGraphicsScene*		Scene_;
	QUndoStack*			UndoStack_;
	QAction*			UndoAction_;
	QAction*			RedoAction_;

	void				SetSceneSize( const QSize& new_size );
};

#endif // QTIMAGEVIEWERMAINWINDOW_H
