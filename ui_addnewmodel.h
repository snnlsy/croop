/********************************************************************************
** Form generated from reading UI file 'addnewmodel.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDNEWMODEL_H
#define UI_ADDNEWMODEL_H

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

class Ui_AddNewModel
{
public:
    QPushButton *pushButton_2;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *lineEdit_brand;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QComboBox *comboBox_type;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_3;
    QLineEdit *lineEdit_model;
    QWidget *layoutWidget3;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_4;
    QLineEdit *lineEdit_year;
    QPushButton *pushButton_chooseImage;

    void setupUi(QDialog *AddNewModel)
    {
        if (AddNewModel->objectName().isEmpty())
            AddNewModel->setObjectName(QStringLiteral("AddNewModel"));
        AddNewModel->resize(619, 171);
        pushButton_2 = new QPushButton(AddNewModel);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(260, 110, 91, 31));
        layoutWidget = new QWidget(AddNewModel);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 30, 144, 50));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        lineEdit_brand = new QLineEdit(layoutWidget);
        lineEdit_brand->setObjectName(QStringLiteral("lineEdit_brand"));

        verticalLayout->addWidget(lineEdit_brand);

        layoutWidget1 = new QWidget(AddNewModel);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(160, 30, 141, 50));
        verticalLayout_2 = new QVBoxLayout(layoutWidget1);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget1);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout_2->addWidget(label_2);

        comboBox_type = new QComboBox(layoutWidget1);
        comboBox_type->setObjectName(QStringLiteral("comboBox_type"));

        verticalLayout_2->addWidget(comboBox_type);

        layoutWidget2 = new QWidget(AddNewModel);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(310, 30, 144, 50));
        verticalLayout_3 = new QVBoxLayout(layoutWidget2);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(layoutWidget2);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout_3->addWidget(label_3);

        lineEdit_model = new QLineEdit(layoutWidget2);
        lineEdit_model->setObjectName(QStringLiteral("lineEdit_model"));

        verticalLayout_3->addWidget(lineEdit_model);

        layoutWidget3 = new QWidget(AddNewModel);
        layoutWidget3->setObjectName(QStringLiteral("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(460, 30, 144, 50));
        verticalLayout_4 = new QVBoxLayout(layoutWidget3);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(layoutWidget3);
        label_4->setObjectName(QStringLiteral("label_4"));

        verticalLayout_4->addWidget(label_4);

        lineEdit_year = new QLineEdit(layoutWidget3);
        lineEdit_year->setObjectName(QStringLiteral("lineEdit_year"));

        verticalLayout_4->addWidget(lineEdit_year);

        pushButton_chooseImage = new QPushButton(AddNewModel);
        pushButton_chooseImage->setObjectName(QStringLiteral("pushButton_chooseImage"));
        pushButton_chooseImage->setGeometry(QRect(20, 110, 111, 31));

        retranslateUi(AddNewModel);

        QMetaObject::connectSlotsByName(AddNewModel);
    } // setupUi

    void retranslateUi(QDialog *AddNewModel)
    {
        AddNewModel->setWindowTitle(QApplication::translate("AddNewModel", "Add New Model", nullptr));
        pushButton_2->setText(QApplication::translate("AddNewModel", "Add", nullptr));
        label->setText(QApplication::translate("AddNewModel", "Brand", nullptr));
        lineEdit_brand->setText(QString());
        label_2->setText(QApplication::translate("AddNewModel", "Type", nullptr));
        label_3->setText(QApplication::translate("AddNewModel", "Model", nullptr));
        lineEdit_model->setText(QString());
        label_4->setText(QApplication::translate("AddNewModel", "Year", nullptr));
        pushButton_chooseImage->setText(QApplication::translate("AddNewModel", "Choose Image", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddNewModel: public Ui_AddNewModel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDNEWMODEL_H
