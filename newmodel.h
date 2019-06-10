#ifndef NEWMODEL_H
#define NEWMODEL_H

#include <QDialog>
#include <QFileDialog>
#include <QString>
#include <QDebug>

namespace Ui {
class NewModel;
}

class NewModel : public QDialog
{
    Q_OBJECT

public:
    explicit NewModel(QWidget *parent = 0);
    ~NewModel();

private slots:
    void on_pushButton_chooseImage_clicked();

    void on_pushButton_add_clicked();

    void on_pushButton_useCurrentPic_clicked();

    void getPicInfo(int& index_currentPic, QStringList& list_path_unlabData);

private:
    Ui::NewModel *ui;

    int index_currentPic;

    QString brand;
    QString type;
    QString model;
    QString year;
    QString path_newModelImage;

    QStringList list_path_unlabData;

signals:
    void sendModelInfo(QString&, QString&, QString&, QString&, QString&);
};

#endif // NEWMODEL_H
