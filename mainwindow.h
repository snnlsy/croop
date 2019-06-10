#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>

#include <QRubberBand>
#include <QPainter>
#include <QRegExp>
#include <QStandardItemModel>
#include <QTime>
#include <QKeyEvent>

#include <QJsonObject>
#include <QJsonValue>
#include <QJsonArray>
#include <QJsonDocument>

#include <QIODevice>
#include <QFileDevice>
#include <QFile>
#include <QDir>
#include <QFileDialog>
#include <QDirIterator>

#include <QList>
#include <QString>

#include <iostream>

#include "newmodel.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void getRubberBandVector(std::vector<QRubberBand*> &rubberBandVectorFromPictureDisplay);

private:
    Ui::MainWindow *ui;
    NewModel *newModel;

    bool bool_selected_unlabData;
    bool bool_selected_rubberBand;
    bool bool_selected_refData;
    bool bool_selected_model;

    int index_currentPic;
    int index_selectedRefData;
    int number_unlabeledImage;

    QPoint point_mousePress;
    QPoint point_mouseRelease;

    QStringList list_path_unlabData;
    QStringList list_path_endSubDirectory;
    QStringList list_path_refData_woutHome;
    QStringList list_path_dir_labData;
    QStringList list_name_title_refData;

    QList<int> indexList;
    QList<int> list_number_rubberBandPerPic;

    QString name_dir_refData;
    QString path_dir_jsonFile;
    QString path_dir_refData;
    QString fileSearchFor;

    QColor generateColor();
    QPalette generatePalette(QColor color);

    std::vector<QRubberBand*> vector_rubberBandDrawn;
    std::vector<QRubberBand*> vector_tempRubberBand;
    std::vector<QStandardItem*> vector_item_pic;
    std::vector<QStandardItem*> vector_item_name;
    std::vector<QJsonObject> vector_jsonObject;

    QFileDialog dialog_refData;
    QFileDialog dialog_labData;

    void keyPressEvent(QKeyEvent *event_keyPress);

    void setEnable_prevNextButton();
    void setEnable_labDataButton();
    void setEnable_unlabDataButton();
    void setEnable_cropButton();

    void makeList_path_data(QString path_dir, QStringList &list);
    void makeList_jsonObject();
    void makeDir_labData(QString path_dir_labData);
    void makeDir_json(QString path_dir_labData);
    void makeVector_item(std::vector<QStandardItem*> &vector_item_pic, std::vector<QStandardItem*> &vector_item_name, int size_table);

    void display_unLabData();
    void traverse_refDataSubDir();
    void drawRubberBandUsingJson(int tempX1, int tempX2, int tempY1, int tempY2);
    void searchJsonFile();
    void readJsonFile();
    void destroyTempRubberBands();
    void drawAndPushRubberBandUsingJson();
    void openDirectoryChooser(QFileDialog &dialog);
    void calculate_ratio(double &x, double &y);
    void setRatio(double ratioX, double ratioY); 
    void cropAndSave();
    void createDoc(QJsonDocument &doc);
    void writeJsonFile(QJsonDocument doc);
    void closeTempRubberBands();
    void setIndexsToList(QList<int> &list_index_table, QStringList &filtered);
    void cleanTable();
    void filterTable(QString arg, QStringList &filtered);
    void hideTableElement();
    void showFilteredTableElements(QList<int> list_index_table);
    void setItemToTable(std::vector<QStandardItem*> &vector_item_pic, std::vector<QStandardItem*> &vector_item_name, QStringList list_path_refData, int size_table, QStandardItemModel *model);
    void show_itemOnTable(QStandardItemModel *model);
    int generate_randomNumber();
    void createNewModelDirectory(QString brand, QString type, QString model, QString year, QString path_newModelImage);
    void runRefData();
    void runLabData();
    void clean_vectors_lists();
    void setIndexToLabel();
    void readJsonCoor(double ratioX, double ratioY, QString jsonContent);


private slots:
    void on_pushButton_referenceData_clicked();
    void on_pushButton_unlabeledData_clicked();
    void on_pushButton_labeledData_clicked();

    void on_pushButton_crop_clicked();
    void on_pushButton_previousPicture_clicked();
    void on_pushButton_nextPixture_clicked();

    void on_lineEdit_search_textChanged(const QString &arg1);
    void on_tableView_photoWithDirection_clicked(const QModelIndex &index);

    void setMousePressPosition(QPoint& position_mouse);
    void setMouseReleasePosition(QPoint& position_mouse);

    void showMouseCurrentPosition(QPoint& position_mouse);
    void on_pushButton_revomeSelection_clicked();
    void on_pushButton_addNewModel_clicked();

    void getModelInfo(QString& brand, QString& type, QString& model, QString& year, QString& path_newModelImage);
    void on_pushButton_goIndex_clicked();

signals:
    void sendPicInfo(int&, QStringList&);

};

#endif // MAINWINDOW_H
