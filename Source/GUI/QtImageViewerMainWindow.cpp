#include "QtImageViewerMainWindow.h"
#include "ui_QtImageViewerMainWindow.h"

QtImageViewerMainWindow::QtImageViewerMainWindow(QWidget *parent) 
	: QMainWindow( parent )
	, ui( new Ui::QtImageViewerMainWindow )
	, Image_()
	, Scene_( 0 )
	, UndoStack_( 0 )
{
    ui->setupUi( this );

    // Connect up signals
    // Menu bar
    connect( ui->actionOpen,        SIGNAL( triggered() ),       this,       SLOT( Open_() ) );
    connect( ui->actionExit,        SIGNAL( triggered() ),       this,       SLOT( Exit_() ) );
    connect( ui->actionUndo,        SIGNAL( triggered() ),       this,       SLOT( Undo_() ) );
    connect( ui->actionRedo,        SIGNAL( triggered() ),       this,       SLOT( Redo_() ) );
    connect( ui->actionAbout,       SIGNAL( tirggered() ),       this,       SLOT( About_() ) );
    connect( ui->actionHowToUse,    SIGNAL( triggered() ),       this,       SLOT( HowToUse_() ) );

	// Initialize GUI elements
	UndoStack_ = new QUndoStack( this );
    Scene_ = new QGraphicsScene();

	ui->ImageViewer->setScene( Scene_ );
	this->setLayout( new QVBoxLayout() );

	 
	UndoAction_ = UndoStack_->createUndoAction( this, "&Undo" );
    UndoAction_->setShortcuts( QKeySequence::Undo );
	ui->menuEdit->addAction( UndoAction_ );
	

    RedoAction_ = UndoStack_->createRedoAction( this, "&Redo" );
	RedoAction_->setShortcuts( QKeySequence::Redo );
	ui->menuEdit->addAction( RedoAction_ );
}

QtImageViewerMainWindow::~QtImageViewerMainWindow()
{
    delete ui;
}

void QtImageViewerMainWindow::Open_()
{
    QString FileName = QFileDialog::getOpenFileName(this, 
        "Open an Image File",
        QDir::currentPath(),
        "Images (*.png *.bmp *.jpg)"
    ); 
    
    if ( !FileName.isEmpty() ) {
        Image_.load( FileName );

		if( !Image_.isNull() ) {
			Scene_->clear();
			Scene_->addPixmap( QPixmap::fromImage( Image_ ).scaled( ui->ImageViewer->size() ) );

		    statusBar()->showMessage( "Image file loaded: " + FileName, 2000 );
        } else {
			statusBar()->showMessage( "Error loading file: " + FileName, 2000 );
        }
    }
}

void QtImageViewerMainWindow::Exit_()
{
}

void QtImageViewerMainWindow::Redo_()
{

}

void QtImageViewerMainWindow::Undo_()
{
}

void QtImageViewerMainWindow::About_()
{
}

void QtImageViewerMainWindow::HowToUse_()
{
}

void QtImageViewerMainWindow::SetSceneSize( const QSize& new_size )
{
	Scene_->clear();
	Scene_->setSceneRect( 0, 0, new_size.width(), new_size.height() );
	QGraphicsPixmapItem* Pixmap = Scene_->addPixmap( QPixmap::fromImage( Image_ ).scaled( new_size ) );
	Pixmap->setPos( 0, 0);
}
void QtImageViewerMainWindow::resizeEvent( QResizeEvent* resize_event)
{
	ResizeCommand* Resize = new ResizeCommand( this, this->size(), resize_event->size() );
	Resize->setText( "Resize" );
	UndoStack_->push( Resize );
}

