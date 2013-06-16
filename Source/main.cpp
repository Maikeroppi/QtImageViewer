#include "GUI/QtImageViewerMainWindow.h"
#include <QApplication>

using namespace std;

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
    QtImageViewerMainWindow w;
    w.show();
    
    
	return a.exec();
}

