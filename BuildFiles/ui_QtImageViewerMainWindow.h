/********************************************************************************
** Form generated from reading UI file 'QtImageViewerMainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTIMAGEVIEWERMAINWINDOW_H
#define UI_QTIMAGEVIEWERMAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMdiArea>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtImageViewerMainWindow
{
public:
    QAction *actionOpen;
    QAction *actionExit;
    QAction *actionUndo;
    QAction *actionRedo;
    QAction *actionAbout;
    QAction *actionHow_to_Use;
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QMdiArea *mdiArea;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menuWindows;
    QMenu *menuHelp;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *QtImageViewerMainWindow)
    {
        if (QtImageViewerMainWindow->objectName().isEmpty())
            QtImageViewerMainWindow->setObjectName(QStringLiteral("QtImageViewerMainWindow"));
        QtImageViewerMainWindow->resize(555, 545);
        actionOpen = new QAction(QtImageViewerMainWindow);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        actionExit = new QAction(QtImageViewerMainWindow);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        actionUndo = new QAction(QtImageViewerMainWindow);
        actionUndo->setObjectName(QStringLiteral("actionUndo"));
        actionRedo = new QAction(QtImageViewerMainWindow);
        actionRedo->setObjectName(QStringLiteral("actionRedo"));
        actionAbout = new QAction(QtImageViewerMainWindow);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        actionHow_to_Use = new QAction(QtImageViewerMainWindow);
        actionHow_to_Use->setObjectName(QStringLiteral("actionHow_to_Use"));
        centralwidget = new QWidget(QtImageViewerMainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        mdiArea = new QMdiArea(centralwidget);
        mdiArea->setObjectName(QStringLiteral("mdiArea"));

        horizontalLayout->addWidget(mdiArea);

        QtImageViewerMainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(QtImageViewerMainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 555, 21));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuEdit = new QMenu(menubar);
        menuEdit->setObjectName(QStringLiteral("menuEdit"));
        menuWindows = new QMenu(menubar);
        menuWindows->setObjectName(QStringLiteral("menuWindows"));
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        QtImageViewerMainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(QtImageViewerMainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        QtImageViewerMainWindow->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuEdit->menuAction());
        menubar->addAction(menuWindows->menuAction());
        menubar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionOpen);
        menuFile->addSeparator();
        menuFile->addAction(actionExit);
        menuEdit->addAction(actionUndo);
        menuEdit->addAction(actionRedo);
        menuHelp->addAction(actionAbout);
        menuHelp->addAction(actionHow_to_Use);

        retranslateUi(QtImageViewerMainWindow);

        QMetaObject::connectSlotsByName(QtImageViewerMainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *QtImageViewerMainWindow)
    {
        QtImageViewerMainWindow->setWindowTitle(QApplication::translate("QtImageViewerMainWindow", "MainWindow", 0));
        actionOpen->setText(QApplication::translate("QtImageViewerMainWindow", "Open...", 0));
        actionExit->setText(QApplication::translate("QtImageViewerMainWindow", "Exit", 0));
        actionUndo->setText(QApplication::translate("QtImageViewerMainWindow", "Undo", 0));
        actionRedo->setText(QApplication::translate("QtImageViewerMainWindow", "Redo", 0));
        actionAbout->setText(QApplication::translate("QtImageViewerMainWindow", "About", 0));
        actionHow_to_Use->setText(QApplication::translate("QtImageViewerMainWindow", "How to Use", 0));
        menuFile->setTitle(QApplication::translate("QtImageViewerMainWindow", "File", 0));
        menuEdit->setTitle(QApplication::translate("QtImageViewerMainWindow", "Edit", 0));
        menuWindows->setTitle(QApplication::translate("QtImageViewerMainWindow", "Windows", 0));
        menuHelp->setTitle(QApplication::translate("QtImageViewerMainWindow", "Help", 0));
    } // retranslateUi

};

namespace Ui {
    class QtImageViewerMainWindow: public Ui_QtImageViewerMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTIMAGEVIEWERMAINWINDOW_H
