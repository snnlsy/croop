/********************************************************************************
** Form generated from reading UI file 'newmodel.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWMODEL_H
#define UI_NEWMODEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NewModel
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QComboBox *comboBox_type;
    QWidget *layoutWidget_2;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_4;
    QLineEdit *lineEdit_year;
    QWidget *layoutWidget_3;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_3;
    QLineEdit *lineEdit_model;
    QWidget *layoutWidget_4;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *lineEdit_brand;
    QPushButton *pushButton_add;
    QPushButton *pushButton_chooseImage;
    QPushButton *pushButton_useCurrentPic;

    void setupUi(QDialog *NewModel)
    {
        if (NewModel->objectName().isEmpty())
            NewModel->setObjectName(QStringLiteral("NewModel"));
        NewModel->resize(193, 464);
        layoutWidget = new QWidget(NewModel);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(30, 30, 131, 50));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout_2->addWidget(label_2);

        comboBox_type = new QComboBox(layoutWidget);
        comboBox_type->setObjectName(QStringLiteral("comboBox_type"));

        verticalLayout_2->addWidget(comboBox_type);

        layoutWidget_2 = new QWidget(NewModel);
        layoutWidget_2->setObjectName(QStringLiteral("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(30, 240, 131, 50));
        verticalLayout_4 = new QVBoxLayout(layoutWidget_2);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(layoutWidget_2);
        label_4->setObjectName(QStringLiteral("label_4"));

        verticalLayout_4->addWidget(label_4);

        lineEdit_year = new QLineEdit(layoutWidget_2);
        lineEdit_year->setObjectName(QStringLiteral("lineEdit_year"));

        verticalLayout_4->addWidget(lineEdit_year);

        layoutWidget_3 = new QWidget(NewModel);
        layoutWidget_3->setObjectName(QStringLiteral("layoutWidget_3"));
        layoutWidget_3->setGeometry(QRect(30, 170, 131, 50));
        verticalLayout_3 = new QVBoxLayout(layoutWidget_3);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(layoutWidget_3);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout_3->addWidget(label_3);

        lineEdit_model = new QLineEdit(layoutWidget_3);
        lineEdit_model->setObjectName(QStringLiteral("lineEdit_model"));

        verticalLayout_3->addWidget(lineEdit_model);

        layoutWidget_4 = new QWidget(NewModel);
        layoutWidget_4->setObjectName(QStringLiteral("layoutWidget_4"));
        layoutWidget_4->setGeometry(QRect(30, 100, 131, 50));
        verticalLayout = new QVBoxLayout(layoutWidget_4);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget_4);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        lineEdit_brand = new QLineEdit(layoutWidget_4);
        lineEdit_brand->setObjectName(QStringLiteral("lineEdit_brand"));

        verticalLayout->addWidget(lineEdit_brand);

        pushButton_add = new QPushButton(NewModel);
        pushButton_add->setObjectName(QStringLiteral("pushButton_add"));
        pushButton_add->setGeometry(QRect(40, 400, 111, 31));
        pushButton_chooseImage = new QPushButton(NewModel);
        pushButton_chooseImage->setObjectName(QStringLiteral("pushButton_chooseImage"));
        pushButton_chooseImage->setGeometry(QRect(40, 320, 111, 31));
        pushButton_useCurrentPic = new QPushButton(NewModel);
        pushButton_useCurrentPic->setObjectName(QStringLiteral("pushButton_useCurrentPic"));
        pushButton_useCurrentPic->setGeometry(QRect(40, 360, 111, 31));

        retranslateUi(NewModel);

        QMetaObject::connectSlotsByName(NewModel);
    } // setupUi

    void retranslateUi(QDialog *NewModel)
    {
        NewModel->setWindowTitle(QApplication::translate("NewModel", "Add New Model", nullptr));
        label_2->setText(QApplication::translate("NewModel", "Type", nullptr));
        label_4->setText(QApplication::translate("NewModel", "Year", nullptr));
        label_3->setText(QApplication::translate("NewModel", "Model", nullptr));
        lineEdit_model->setText(QString());
        label->setText(QApplication::translate("NewModel", "Brand", nullptr));
        lineEdit_brand->setText(QString());
        pushButton_add->setText(QApplication::translate("NewModel", "Add", nullptr));
        pushButton_chooseImage->setText(QApplication::translate("NewModel", "Choose Image", nullptr));
        pushButton_useCurrentPic->setText(QApplication::translate("NewModel", "Use Current Pic", nullptr));
    } // retranslateUi

};

namespace Ui {
    class NewModel: public Ui_NewModel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWMODEL_H
