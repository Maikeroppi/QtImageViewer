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
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include "ImageViewer.h"

QT_BEGIN_NAMESPACE

class Ui_QtImageViewerMainWindow
{
public:
    QAction *actionOpen;
    QAction *actionExit;
    QAction *actionUndo;
    QAction *actionRedo;
    QAction *actionAbout;
    QAction *actionHowToUse;
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    ImageViewer *ImageView;
    QStatusBar *statusbar;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menuHelp;

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
        actionHowToUse = new QAction(QtImageViewerMainWindow);
        actionHowToUse->setObjectName(QStringLiteral("actionHowToUse"));
        centralwidget = new QWidget(QtImageViewerMainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        ImageView = new ImageViewer(centralwidget);
        ImageView->setObjectName(QStringLiteral("ImageView"));
        ImageView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        ImageView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        horizontalLayout->addWidget(ImageView);

        QtImageViewerMainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(QtImageViewerMainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        QtImageViewerMainWindow->setStatusBar(statusbar);
        menubar = new QMenuBar(QtImageViewerMainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 555, 21));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuEdit = new QMenu(menubar);
        menuEdit->setObjectName(QStringLiteral("menuEdit"));
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        QtImageViewerMainWindow->setMenuBar(menubar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuEdit->menuAction());
        menubar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionOpen);
        menuFile->addSeparator();
        menuFile->addAction(actionExit);
        menuHelp->addAction(actionAbout);
        menuHelp->addAction(actionHowToUse);

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
        actionHowToUse->setText(QApplication::translate("QtImageViewerMainWindow", "How to Use", 0));
        menuFile->setTitle(QApplication::translate("QtImageViewerMainWindow", "File", 0));
        menuEdit->setTitle(QApplication::translate("QtImageViewerMainWindow", "Edit", 0));
        menuHelp->setTitle(QApplication::translate("QtImageViewerMainWindow", "Help", 0));
    } // retranslateUi

};

namespace Ui {
    class QtImageViewerMainWindow: public Ui_QtImageViewerMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTIMAGEVIEWERMAINWINDOW_H
