/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <picturedisplay.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    PictureDisplay *label_Picture;
    QLabel *label_Coordinate;
    QPushButton *pushButton_unlabeledData;
    QPushButton *pushButton_previousPicture;
    QPushButton *pushButton_nextPixture;
    QPushButton *pushButton_crop;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_search;
    QLineEdit *lineEdit_search;
    QTableView *tableView_photoWithDirection;
    QPushButton *pushButton_referenceData;
    QPushButton *pushButton_labeledData;
    QListWidget *listWidget_photoWithDirection;
    QPushButton *pushButton_revomeSelection;
    QPushButton *pushButton_addNewModel;
    QLineEdit *lineEdit_goIndex;
    QLabel *label_goPicture;
    QPushButton *pushButton_goIndex;
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_index_currentPic;
    QLabel *label_slash1;
    QLabel *label_number_totalPic;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1083, 735);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label_Picture = new PictureDisplay(centralWidget);
        label_Picture->setObjectName(QStringLiteral("label_Picture"));
        label_Picture->setGeometry(QRect(30, 30, 640, 480));
        label_Picture->setStyleSheet(QStringLiteral("background-color: rgb(222, 222, 222);"));
        label_Picture->setFrameShape(QFrame::Box);
        label_Coordinate = new QLabel(centralWidget);
        label_Coordinate->setObjectName(QStringLiteral("label_Coordinate"));
        label_Coordinate->setGeometry(QRect(570, 530, 101, 41));
        label_Coordinate->setFrameShape(QFrame::Box);
        pushButton_unlabeledData = new QPushButton(centralWidget);
        pushButton_unlabeledData->setObjectName(QStringLiteral("pushButton_unlabeledData"));
        pushButton_unlabeledData->setGeometry(QRect(30, 580, 121, 41));
        pushButton_previousPicture = new QPushButton(centralWidget);
        pushButton_previousPicture->setObjectName(QStringLiteral("pushButton_previousPicture"));
        pushButton_previousPicture->setGeometry(QRect(190, 530, 71, 41));
        pushButton_nextPixture = new QPushButton(centralWidget);
        pushButton_nextPixture->setObjectName(QStringLiteral("pushButton_nextPixture"));
        pushButton_nextPixture->setGeometry(QRect(460, 530, 71, 41));
        pushButton_crop = new QPushButton(centralWidget);
        pushButton_crop->setObjectName(QStringLiteral("pushButton_crop"));
        pushButton_crop->setGeometry(QRect(810, 530, 131, 41));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(700, 30, 351, 481));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_search = new QLabel(layoutWidget);
        label_search->setObjectName(QStringLiteral("label_search"));

        horizontalLayout->addWidget(label_search);

        lineEdit_search = new QLineEdit(layoutWidget);
        lineEdit_search->setObjectName(QStringLiteral("lineEdit_search"));

        horizontalLayout->addWidget(lineEdit_search);


        verticalLayout->addLayout(horizontalLayout);

        tableView_photoWithDirection = new QTableView(layoutWidget);
        tableView_photoWithDirection->setObjectName(QStringLiteral("tableView_photoWithDirection"));

        verticalLayout->addWidget(tableView_photoWithDirection);

        pushButton_referenceData = new QPushButton(centralWidget);
        pushButton_referenceData->setObjectName(QStringLiteral("pushButton_referenceData"));
        pushButton_referenceData->setGeometry(QRect(30, 530, 121, 41));
        pushButton_labeledData = new QPushButton(centralWidget);
        pushButton_labeledData->setObjectName(QStringLiteral("pushButton_labeledData"));
        pushButton_labeledData->setGeometry(QRect(30, 630, 121, 41));
        listWidget_photoWithDirection = new QListWidget(centralWidget);
        listWidget_photoWithDirection->setObjectName(QStringLiteral("listWidget_photoWithDirection"));
        listWidget_photoWithDirection->setGeometry(QRect(870, 540, 20, 20));
        pushButton_revomeSelection = new QPushButton(centralWidget);
        pushButton_revomeSelection->setObjectName(QStringLiteral("pushButton_revomeSelection"));
        pushButton_revomeSelection->setGeometry(QRect(810, 580, 131, 41));
        pushButton_addNewModel = new QPushButton(centralWidget);
        pushButton_addNewModel->setObjectName(QStringLiteral("pushButton_addNewModel"));
        pushButton_addNewModel->setGeometry(QRect(810, 630, 131, 41));
        lineEdit_goIndex = new QLineEdit(centralWidget);
        lineEdit_goIndex->setObjectName(QStringLiteral("lineEdit_goIndex"));
        lineEdit_goIndex->setGeometry(QRect(380, 590, 51, 25));
        label_goPicture = new QLabel(centralWidget);
        label_goPicture->setObjectName(QStringLiteral("label_goPicture"));
        label_goPicture->setGeometry(QRect(290, 590, 111, 20));
        pushButton_goIndex = new QPushButton(centralWidget);
        pushButton_goIndex->setObjectName(QStringLiteral("pushButton_goIndex"));
        pushButton_goIndex->setGeometry(QRect(330, 630, 51, 31));
        layoutWidget_2 = new QWidget(centralWidget);
        layoutWidget_2->setObjectName(QStringLiteral("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(280, 540, 161, 21));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget_2);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_index_currentPic = new QLabel(layoutWidget_2);
        label_index_currentPic->setObjectName(QStringLiteral("label_index_currentPic"));

        horizontalLayout_2->addWidget(label_index_currentPic);

        label_slash1 = new QLabel(layoutWidget_2);
        label_slash1->setObjectName(QStringLiteral("label_slash1"));

        horizontalLayout_2->addWidget(label_slash1);

        label_number_totalPic = new QLabel(layoutWidget_2);
        label_number_totalPic->setObjectName(QStringLiteral("label_number_totalPic"));

        horizontalLayout_2->addWidget(label_number_totalPic);

        MainWindow->setCentralWidget(centralWidget);
        listWidget_photoWithDirection->raise();
        pushButton_crop->raise();
        label_Picture->raise();
        label_Coordinate->raise();
        pushButton_unlabeledData->raise();
        pushButton_previousPicture->raise();
        pushButton_nextPixture->raise();
        layoutWidget->raise();
        pushButton_referenceData->raise();
        pushButton_labeledData->raise();
        pushButton_revomeSelection->raise();
        pushButton_addNewModel->raise();
        lineEdit_goIndex->raise();
        label_goPicture->raise();
        pushButton_goIndex->raise();
        layoutWidget_2->raise();
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1083, 22));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Croop", nullptr));
        label_Picture->setText(QString());
        label_Coordinate->setText(QString());
        pushButton_unlabeledData->setText(QApplication::translate("MainWindow", "Unlabeled Data", nullptr));
        pushButton_previousPicture->setText(QApplication::translate("MainWindow", "<", nullptr));
        pushButton_nextPixture->setText(QApplication::translate("MainWindow", ">", nullptr));
        pushButton_crop->setText(QApplication::translate("MainWindow", "Crop", nullptr));
        label_search->setText(QApplication::translate("MainWindow", "Search:", nullptr));
        pushButton_referenceData->setText(QApplication::translate("MainWindow", "Reference Data", nullptr));
        pushButton_labeledData->setText(QApplication::translate("MainWindow", "Labeled Data", nullptr));
        pushButton_revomeSelection->setText(QApplication::translate("MainWindow", "Remove Selection", nullptr));
        pushButton_addNewModel->setText(QApplication::translate("MainWindow", "Add New Model", nullptr));
        label_goPicture->setText(QApplication::translate("MainWindow", "Enter Index:", nullptr));
        pushButton_goIndex->setText(QApplication::translate("MainWindow", "Go", nullptr));
        label_index_currentPic->setText(QApplication::translate("MainWindow", "0", nullptr));
        label_slash1->setText(QApplication::translate("MainWindow", "/", nullptr));
        label_number_totalPic->setText(QApplication::translate("MainWindow", "0", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
