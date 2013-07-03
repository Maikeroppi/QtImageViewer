#include "QtImageViewerMainWindow.h"
#include "ui_QtImageViewerMainWindow.h"

QtImageViewerMainWindow::QtImageViewerMainWindow(QWidget *parent) 
	: QMainWindow( parent )
	, ui( new Ui::QtImageViewerMainWindow )
	, UndoStack_()
{
    ui->setupUi( this );

    // Connect up signals
	// Trying out new Qt5 connect syntax with function pointers. Checks for valid connects at compile time, but does not support default parameters.
    // Menu bar
	connect( ui->actionOpen,		&QAction::triggered,	   this,       &QtImageViewerMainWindow::Open_ );
    connect( ui->actionExit,        &QAction::triggered,	   this,       &QtImageViewerMainWindow::Exit_ );
    connect( ui->actionAbout,       &QAction::triggered,       this,       &QtImageViewerMainWindow::About_ );
	connect( ui->actionLockAspectRatio, &QAction::triggered,   this,	   &QtImageViewerMainWindow::ToggleLockAspectRatio_ );
   
	// New Signal/Slot syntax doesn't work when passing parameters
	connect( ui->ImageView,			SIGNAL( ZoomBoxDrawn( const QRectF& ) ), this, SLOT( HandleZoomBox_( const QRectF& ) ) );

	// Initialize GUI elements
	UndoStack_	= new QUndoStack( this );
    Scene_		= new QGraphicsScene();

	this->setLayout( new QVBoxLayout() );
		
	UndoAction_ = UndoStack_->createUndoAction( this, "&Undo" );
    UndoAction_->setShortcuts( QKeySequence::Undo );
	UndoAction_->setIcon( QIcon( ":/normal/blue/normal/003_51.png" ) );
	ui->menuEdit->insertAction( ui->actionLockAspectRatio, UndoAction_ );
	ui->toolbar->insertAction( ui->actionLockAspectRatio, UndoAction_ );
	
    RedoAction_ = UndoStack_->createRedoAction( this, "&Redo" );
	RedoAction_->setShortcuts( QKeySequence::Redo );
	RedoAction_->setIcon( QIcon( ":/normal/blue/normal/003_49.png" ) );
	ui->menuEdit->insertAction( ui->actionLockAspectRatio, RedoAction_ );
	ui->menuEdit->insertSeparator( ui->actionLockAspectRatio );
	ui->toolbar->insertAction( ui->actionLockAspectRatio, RedoAction_ );
	
	ui->actionLockAspectRatio->setChecked( true );

	// Load an image for quick testing.
	/*LoadImageFile_( "C:\\Users\\Public\\Pictures\\Sample Pictures\\Penguins.jpg" );
	ui->ImageView->SetImage( &Image_ );*/
}

QtImageViewerMainWindow::~QtImageViewerMainWindow()
{
	delete UndoStack_;
	delete Scene_;
	delete UndoAction_;
	delete RedoAction_;
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
        if( ui->ImageView->LoadImage( FileName ) ) {
		    statusBar()->showMessage( "Image file loaded: " + FileName, 2000 );

			// With a new image, the UndoStack_ commands don't mean anything
			UndoStack_->clear();
        } else {
			statusBar()->showMessage( "Error loading file: " + FileName, 2000 );
        }
    }
}

void QtImageViewerMainWindow::Exit_()
{
	this->close();
}


void QtImageViewerMainWindow::About_()
{
	QMessageBox::information( this
		, "About QtImageViewer"
		, "A simple QtImageViewer with box zoom and undo/redo"
		);
}

void QtImageViewerMainWindow::ToggleLockAspectRatio_()
{
	Qt::AspectRatioMode RatioMode =
		( ui->actionLockAspectRatio->isChecked() )? Qt::KeepAspectRatio : Qt::IgnoreAspectRatio;
	ui->ImageView->SetAspectRatioMode( RatioMode );
}

void QtImageViewerMainWindow::HandleZoomBox_( const QRectF& zoom_box )
{
	UndoStack_->push( new ZoomCommand( ui->ImageView, ui->ImageView->ZoomRect(), zoom_box ) );
}

void QtImageViewerMainWindow::SetSceneSize( const QSize& new_size )
{
	Scene_->clear();
	Scene_->setSceneRect( 0, 0, new_size.width(), new_size.height() );
}

