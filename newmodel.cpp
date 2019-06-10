#include "newmodel.h"
#include "ui_newmodel.h"

NewModel::NewModel(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewModel)
{
    ui->setupUi(this);
    ui->pushButton_add->setEnabled(false);

    ui->comboBox_type->addItem("Car");
    ui->comboBox_type->addItem("Suv");
    ui->comboBox_type->addItem("Truck");
    ui->comboBox_type->addItem("Van");
    ui->comboBox_type->addItem("Bus");
    ui->comboBox_type->addItem("Pickup");
}

NewModel::~NewModel()
{
    delete ui;
}

void NewModel::on_pushButton_chooseImage_clicked()
{
    QFileDialog dialog(this);
    dialog.setDirectory(QDir::homePath());
    dialog.setFileMode(QFileDialog::ExistingFile);

    if (dialog.exec())
    {
        path_newModelImage = dialog.selectedFiles().at(0);  // e.g. "/home/sinan/Downloads/1 (3).jpg"
        ui->pushButton_add->setEnabled(true);
    }
}

void NewModel::on_pushButton_add_clicked()
{
    brand = ui->lineEdit_brand->text().toUpper();
    type = ui->comboBox_type->itemText( ui->comboBox_type->currentIndex() ).toUpper();
    model = ui->lineEdit_model->text().toUpper();
    year = ui->lineEdit_year->text();

    emit sendModelInfo(brand, type, model, year, path_newModelImage);
}

void NewModel::on_pushButton_useCurrentPic_clicked()
{
    path_newModelImage = list_path_unlabData.at(index_currentPic);
    ui->pushButton_add->setEnabled(true);
}

void NewModel::getPicInfo(int &_index_currentPic, QStringList &_list_path_unlabData)
{
    index_currentPic = _index_currentPic;
    list_path_unlabData = _list_path_unlabData;
}
