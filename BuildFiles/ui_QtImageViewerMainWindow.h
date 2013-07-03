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
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include "ImageViewer.h"

QT_BEGIN_NAMESPACE

class Ui_QtImageViewerMainWindow
{
public:
    QAction *actionOpen;
    QAction *actionExit;
    QAction *actionAbout;
    QAction *actionHowToUse;
    QAction *actionLockAspectRatio;
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    ImageViewer *ImageView;
    QStatusBar *statusbar;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menuHelp;
    QToolBar *toolbar;

    void setupUi(QMainWindow *QtImageViewerMainWindow)
    {
        if (QtImageViewerMainWindow->objectName().isEmpty())
            QtImageViewerMainWindow->setObjectName(QStringLiteral("QtImageViewerMainWindow"));
        QtImageViewerMainWindow->resize(555, 545);
        QIcon icon;
        icon.addFile(QStringLiteral(":/normal/blue/normal/003_03.png"), QSize(), QIcon::Normal, QIcon::Off);
        QtImageViewerMainWindow->setWindowIcon(icon);
        actionOpen = new QAction(QtImageViewerMainWindow);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/normal/blue/normal/003_43.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpen->setIcon(icon1);
        actionExit = new QAction(QtImageViewerMainWindow);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/normal/blue/normal/003_75.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionExit->setIcon(icon2);
        actionAbout = new QAction(QtImageViewerMainWindow);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        actionHowToUse = new QAction(QtImageViewerMainWindow);
        actionHowToUse->setObjectName(QStringLiteral("actionHowToUse"));
        actionLockAspectRatio = new QAction(QtImageViewerMainWindow);
        actionLockAspectRatio->setObjectName(QStringLiteral("actionLockAspectRatio"));
        actionLockAspectRatio->setCheckable(true);
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/normal/blue/normal/003_12.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionLockAspectRatio->setIcon(icon3);
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
        toolbar = new QToolBar(QtImageViewerMainWindow);
        toolbar->setObjectName(QStringLiteral("toolbar"));
        QtImageViewerMainWindow->addToolBar(Qt::TopToolBarArea, toolbar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuEdit->menuAction());
        menubar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionOpen);
        menuFile->addSeparator();
        menuFile->addAction(actionExit);
        menuEdit->addSeparator();
        menuEdit->addAction(actionLockAspectRatio);
        menuHelp->addAction(actionAbout);
        toolbar->addAction(actionOpen);
        toolbar->addAction(actionLockAspectRatio);

        retranslateUi(QtImageViewerMainWindow);

        QMetaObject::connectSlotsByName(QtImageViewerMainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *QtImageViewerMainWindow)
    {
        QtImageViewerMainWindow->setWindowTitle(QApplication::translate("QtImageViewerMainWindow", "QtImageViewer", 0));
        actionOpen->setText(QApplication::translate("QtImageViewerMainWindow", "Open...", 0));
        actionExit->setText(QApplication::translate("QtImageViewerMainWindow", "Exit", 0));
        actionAbout->setText(QApplication::translate("QtImageViewerMainWindow", "About", 0));
        actionHowToUse->setText(QApplication::translate("QtImageViewerMainWindow", "How to Use", 0));
        actionLockAspectRatio->setText(QApplication::translate("QtImageViewerMainWindow", "Lock Aspect Ratio", 0));
        menuFile->setTitle(QApplication::translate("QtImageViewerMainWindow", "File", 0));
        menuEdit->setTitle(QApplication::translate("QtImageViewerMainWindow", "Edit", 0));
        menuHelp->setTitle(QApplication::translate("QtImageViewerMainWindow", "Help", 0));
        toolbar->setWindowTitle(QApplication::translate("QtImageViewerMainWindow", "toolBar", 0));
    } // retranslateUi

};

namespace Ui {
    class QtImageViewerMainWindow: public Ui_QtImageViewerMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTIMAGEVIEWERMAINWINDOW_H
