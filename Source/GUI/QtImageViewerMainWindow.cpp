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
    // Menu bar
    connect( ui->actionOpen,        SIGNAL( triggered() ),       this,       SLOT( Open_() ) );
    connect( ui->actionExit,        SIGNAL( triggered() ),       this,       SLOT( Exit_() ) );
    connect( ui->actionUndo,        SIGNAL( triggered() ),       this,       SLOT( Undo_() ) );
    connect( ui->actionRedo,        SIGNAL( triggered() ),       this,       SLOT( Redo_() ) );
    connect( ui->actionAbout,       SIGNAL( tirggered() ),       this,       SLOT( About_() ) );
    connect( ui->actionHowToUse,    SIGNAL( triggered() ),       this,       SLOT( HowToUse_() ) );

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

	QAction* ZoomAction = new QAction( "Zoom In", this );
	ui->menuEdit->addAction( ZoomAction );
	connect( ZoomAction,			SIGNAL( triggered() ),		this,		SLOT( ZoomIn_() ) );

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

void QtImageViewerMainWindow::ZoomIn_()
{
	UndoStack_->push( new ZoomCommand( Scene_, &Image_, QRect( 50, 50, 120, 120 ) ) );
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

