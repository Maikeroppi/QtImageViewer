#include "QtImageViewerMainWindow.h"
#include "ui_QtImageViewerMainWindow.h"

QtImageViewerMainWindow::QtImageViewerMainWindow(QWidget *parent) 
	: QMainWindow( parent )
	, ui( new Ui::QtImageViewerMainWindow )
	, Image_()
	, UndoStack_()
{
    ui->setupUi( this );

    // Connect up signals
	// Trying out new Qt5 connect syntax with function pointers. Checks for valid connects at compile time, but does not support default parameters.
    // Menu bar
	connect( ui->actionOpen,		&QAction::triggered,	   this,       &QtImageViewerMainWindow::Open_ );
    connect( ui->actionExit,        &QAction::triggered,	   this,       &QtImageViewerMainWindow::Exit_ );
    connect( ui->actionUndo,        &QAction::triggered,       this,       &QtImageViewerMainWindow::Undo_ );
    connect( ui->actionRedo,        &QAction::triggered,       this,       &QtImageViewerMainWindow::Redo_ );
    connect( ui->actionAbout,       &QAction::triggered,       this,       &QtImageViewerMainWindow::About_ );
    connect( ui->actionHowToUse,    &QAction::triggered,       this,       &QtImageViewerMainWindow::HowToUse_ );

	// Initialize GUI elements
	UndoStack_	= new QUndoStack( this );
    Scene_		= new QGraphicsScene();

	//ui->ImageView->setScene( Scene_ );
	this->setLayout( new QVBoxLayout() );

	 
	UndoAction_ = UndoStack_->createUndoAction( this, "&Undo" );
    UndoAction_->setShortcuts( QKeySequence::Undo );
	ui->menuEdit->addAction( UndoAction_ );
	

    RedoAction_ = UndoStack_->createRedoAction( this, "&Redo" );
	RedoAction_->setShortcuts( QKeySequence::Redo );
	ui->menuEdit->addAction( RedoAction_ );

	LoadImageFile_( "C:\\Users\\Public\\Pictures\\Sample Pictures\\Penguins.jpg" );
	ui->ImageView->SetImage( &Image_ );
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
    LoadImageFile_( FileName ); 
}

void QtImageViewerMainWindow::LoadImageFile_( const QString& filename ) 
{
	   if ( !filename.isEmpty() ) {
        Image_.load( filename );

		if( !Image_.isNull() ) {
			ui->ImageView->SetImage( &Image_ );
		    statusBar()->showMessage( "Image file loaded: " + filename, 2000 );
        } else {
			statusBar()->showMessage( "Error loading file: " + filename, 2000 );
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

