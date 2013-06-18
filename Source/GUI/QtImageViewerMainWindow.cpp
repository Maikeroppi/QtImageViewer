#include "QtImageViewerMainWindow.h"
#include "ui_QtImageViewerMainWindow.h"

QtImageViewerMainWindow::QtImageViewerMainWindow(QWidget *parent) :
    QMainWindow( parent ),
    ui( new Ui::QtImageViewerMainWindow )
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
        ImageViewerWindow* Window = CreateImageViewerWindow_();
        if ( Window->LoadImageFile( FileName ) ) {
            statusBar()->showMessage( "Image file loaded: " + FileName, 2000);
            Window->show();
        } else {
            Window->close();
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

ImageViewerWindow* QtImageViewerMainWindow::CreateImageViewerWindow_()
{
    ImageViewerWindow* Window = new ImageViewerWindow();
    ui->mdiArea->addSubWindow( Window );
    return Window;
}


