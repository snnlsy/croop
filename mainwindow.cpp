#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "json.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->label_Picture, SIGNAL(sendMouseCurrentPosition(QPoint&)),                this, SLOT(showMouseCurrentPosition(QPoint&)));
    connect(ui->label_Picture, SIGNAL(sendMousePressPosition(QPoint&)),                  this, SLOT(setMousePressPosition(QPoint&)));
    connect(ui->label_Picture, SIGNAL(sendMouseReleasePosition(QPoint&)),                this, SLOT(setMouseReleasePosition(QPoint&)));
    connect(ui->label_Picture, SIGNAL(sendRubberBandVector(std::vector<QRubberBand*>&)), this, SLOT(getRubberBandVector(std::vector<QRubberBand*>&)), Qt::DirectConnection);

    bool_selected_rubberBand = false;
    bool_selected_unlabData = false;
    bool_selected_refData = false;
    bool_selected_model = false;


    setEnable_cropButton();
    setEnable_prevNextButton();
    setEnable_unlabDataButton();
    setEnable_labDataButton();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_referenceData_clicked()
{
    openDirectoryChooser(dialog_refData);

    if (dialog_refData.exec())
    {
        runRefData();
    }
}

void MainWindow::runRefData()
{
    bool_selected_refData = true;

    // e.g. "/home/sinan/Desktop/vecPhoto"

    path_dir_refData = dialog_refData.directory().path();

    // e.g. "vecPhoto"
    name_dir_refData = dialog_refData.directory().dirName();

    // traverse all reference data sub directories and gets path of end-sub-directories
    traverse_refDataSubDir();

    // enables unlabeled data button
    setEnable_unlabDataButton();
}

void MainWindow::traverse_refDataSubDir()
{
    clean_vectors_lists();

    QDirIterator it(path_dir_refData, QDir::Dirs, QDirIterator::Subdirectories);

    QStringList list_path_refData;

    QString path_endSubDirectory;

    while(it.hasNext()) {

        // e.g. "/home/user/Desktop/vecPhoto/vec/model10"
        path_endSubDirectory = it.next();

        if(!path_endSubDirectory.contains(".") )
        {
            QDir dir(path_endSubDirectory);
            QStringList list_name_perEndSubDir = dir.entryList(QStringList() << "*.jpg" << "*.png" << "*.jpeg" << "JPEG", QDir::Files);
            if(!list_name_perEndSubDir.isEmpty())
            {
                // e.g. "10.jpg"
                QString name_refData;
                name_refData = list_name_perEndSubDir.at(0);

                // e.g. "/home/user/Desktop/vecPhoto/model3/car/3_car.jpg"
                QString path_refData;
                path_refData = path_endSubDirectory + "/" + name_refData;

                // e.g. "/home/sinan/Desktop/vecPhoto/model3/car/"
                path_endSubDirectory = path_refData;
                path_endSubDirectory.remove(name_refData);

                list_path_refData.append(path_refData);

                // e.g. [ "/home/sinan/Desktop/",  "/model3/car/" ]
                QRegExp separator(name_dir_refData);
                QStringList list = path_refData.split(separator); // ["", ""]

                // e.g. "/model3/car/3_car.jpg/"
                QString name_title_refData;
                name_title_refData = list.last();

                // e.g. "/model3/car/3_car.jpg/"
                QString temp = name_title_refData;

                // e.g. "/model3/car/"
                temp.remove(name_refData);
                list_path_refData_woutHome.push_back(temp);

                name_title_refData.replace(name_refData, "");
                name_title_refData.replace("/","-");

                // removes first char of string
                name_title_refData.remove(0, 1);

                // removes last char of string
                name_title_refData.remove(name_title_refData.size()-1, name_title_refData.size()-1);

                // name_title_refData becomes brand-type-model-year
                list_name_title_refData.append(name_title_refData);

            }
        }

    }




    QStandardItemModel *model = new QStandardItemModel();

    show_itemOnTable(model);

    std::vector<QStandardItem*> vector_item_pic;
    std::vector<QStandardItem*> vector_item_name;
    int size_table;

    size_table = list_name_title_refData.size();

    makeVector_item(vector_item_pic, vector_item_name, size_table);

    setItemToTable(vector_item_pic, vector_item_name, list_path_refData, size_table, model);
}

void MainWindow::clean_vectors_lists()
{
    for(int i=0; i<vector_item_pic.size(); i++)
    {
        delete vector_item_pic.at(i);
        delete vector_item_name.at(i);
    }

    vector_item_name.clear();
    vector_item_pic.clear();

    list_name_title_refData.clear();
    //list_number_rubberBandPerPic.clear();
    list_path_dir_labData.clear();
    list_path_endSubDirectory.clear();
    list_path_refData_woutHome.clear();
    //list_path_unlabData.clear();
}


void MainWindow::on_pushButton_unlabeledData_clicked()
{
    QFileDialog dialog(this);
    openDirectoryChooser(dialog);

    if (dialog.exec())
    {
        bool_selected_unlabData = true;

        // e.g. "/home/user/unlabeledData";
        QString path_dir_unlab = dialog.directory().path();
        path_dir_unlab = dialog.directory().path();

        // makes unlabeled data path list e.g. "/home/user/unlabeledData" + "/" + "1.jpg"
        // result list_path_unlabData = [ "/home/user/unlabeledData/1.jpg", ... ]
        makeList_path_data(path_dir_unlab, list_path_unlabData);

        //starts from first picture among the selected files
        index_currentPic = 0;

        // displays unlabeled pictures on QLabel
        display_unLabData();

        setEnable_prevNextButton();
        setEnable_unlabDataButton();
        setEnable_labDataButton();

        number_unlabeledImage = list_path_unlabData.size();
        ui->label_number_totalPic->setText( QVariant(number_unlabeledImage-1).toString() );
    }

    //creates json objects as much as unlabeled data
    makeList_jsonObject();
}

void MainWindow::makeList_path_data(QString path_dir, QStringList &list)
{
    // purpose is e.g. "/home/user/unlabeledData" + "/" + "1.jpg"

    // e.g. path_dir = "/home/user/unlabeledData"
    QDir dir_data(path_dir);

    // e.g. list = ["1.jpg", "2.png", ...]
    list = dir_data.entryList(QStringList() << "*.jpg" << "*.png" << "*.jpeg" << "*.JPEG", QDir::Files);

    for(int i=0; i<list.count(); i++)
    {
        list.replace(i, path_dir + "/" + list.at(i));
    }
}

void MainWindow::makeList_jsonObject()
{
    // creates list of json object
    for(int i=0; i<list_path_unlabData.size(); i++)
    {
        QJsonObject obj;
        vector_jsonObject.push_back(obj);

        int j = 0;
        list_number_rubberBandPerPic.push_back(j);
    }
}



void MainWindow::on_pushButton_labeledData_clicked()
{
    openDirectoryChooser(dialog_labData);

    if (dialog_labData.exec())
    {
        runLabData();
    }
}

void MainWindow::runLabData()
{
    // e.g. "/home/user/labeledData"
    QString path_dir_labData;
    path_dir_labData = dialog_labData.directory().path();

    // creates copy of reference directrory for labeled data directory
    makeDir_labData(path_dir_labData);

    // creates directory for json files
    makeDir_json(path_dir_labData);
}

void MainWindow::makeDir_labData(QString path_dir_labData)
{
    // e.g. list_path_refData = [ "/model3/car/", ...]
    list_path_dir_labData = list_path_refData_woutHome;

    // becomes list_path_refData = [ "/home/user/labeledData/model3/car/", ...]
    for(int i=0; i<list_path_dir_labData.count(); i++)
    {
        list_path_dir_labData.replace(i, path_dir_labData + list_path_dir_labData.at(i));
    }

    //creates directories for labeled datas
    for(int i = 0; i < list_path_dir_labData.count(); i++)
    {
        QDir dir(list_path_dir_labData.at(i));
        if (!dir.exists())
        {
            dir.mkpath(".");
        }
    }
}

void MainWindow::makeDir_json(QString path_dir_labData)
{
    //create directory for json files
    path_dir_jsonFile = path_dir_labData + "/" + "json files";
    QDir dir(path_dir_jsonFile);
    if (!dir.exists())
    {
        dir.mkpath(".");
    }
}



void MainWindow::on_pushButton_crop_clicked()
{
    double ratioX, ratioY;
    calculate_ratio(ratioX, ratioY);

    setRatio(ratioX, ratioY);

    cropAndSave();

    QJsonDocument doc;
    createDoc(doc);

    writeJsonFile(doc);

    ui->pushButton_crop->setEnabled(false);
}

void MainWindow::calculate_ratio(double &ratioX, double &ratioY)
{
    QPixmap pix(list_path_unlabData.at(index_currentPic));

    int width_label_picture = ui->label_Picture->width();
    int height_label_picture = ui->label_Picture->height();

    int width_pic = pix.width();
    int height_pic = pix.height();

    ratioX = (double) width_pic / (double) width_label_picture;
    ratioY = (double) height_pic / (double) height_label_picture;
}

void MainWindow::setRatio(double ratioX, double ratioY)
{
    point_mousePress.setX(point_mousePress.x() * ratioX);
    point_mousePress.setY(point_mousePress.y() * ratioY);
    point_mouseRelease.setX(point_mouseRelease.x() * ratioX);
    point_mouseRelease.setY(point_mouseRelease.y() * ratioY);
}

int MainWindow::generate_randomNumber()
{
    QTime timer;
    timer.start();

    return timer.msecsSinceStartOfDay();
}

void MainWindow::cropAndSave()
{
    int randomID = generate_randomNumber();

    // creates file for cropped images
    QFile file_croppedPic(QVariant(randomID).toString() + "-" + QVariant(list_name_title_refData.at(index_selectedRefData)).toString() + ".png");

    QDir dir(list_path_dir_labData.at(index_selectedRefData));

    // sets name for cropped picture
    file_croppedPic.setFileName(dir.absoluteFilePath(QVariant(randomID).toString() + "-" + QVariant(list_name_title_refData.at(index_selectedRefData)).toString() + ".png"));

    QRect rect(point_mousePress, point_mouseRelease);
    QPixmap pix(list_path_unlabData.at(index_currentPic));
    QPixmap original(pix);
    QPixmap cropped = original.copy(rect);

    file_croppedPic.open(QIODevice::WriteOnly);
    cropped.save(&file_croppedPic, "PNG");
}

void MainWindow::createDoc(QJsonDocument &doc)
{
    QJsonObject object_json_coor;

    object_json_coor.insert("x1", QJsonValue::fromVariant(point_mousePress.x()));
    object_json_coor.insert("x2", QJsonValue::fromVariant(point_mouseRelease.x()));
    object_json_coor.insert("y1", QJsonValue::fromVariant(point_mousePress.y()));
    object_json_coor.insert("y2", QJsonValue::fromVariant(point_mouseRelease.y()));

    int number_rubberBand;
    number_rubberBand = list_number_rubberBandPerPic.at(index_currentPic);

    vector_jsonObject.at(index_currentPic).insert(QVariant(list_number_rubberBandPerPic.at(index_currentPic) ).toString(), object_json_coor);

    list_number_rubberBandPerPic.replace(index_currentPic, ++number_rubberBand);

    doc.setObject(vector_jsonObject.at(index_currentPic));
}

void MainWindow::writeJsonFile(QJsonDocument doc)
{
    QDir dir(path_dir_jsonFile);
    QFile jsonFile(QVariant(index_currentPic).toString() + ".json");

    jsonFile.setFileName(dir.absoluteFilePath(QVariant(index_currentPic).toString() + ".json"));
    jsonFile.open(QFile::WriteOnly);
    jsonFile.write(doc.toJson());
}



void MainWindow::on_pushButton_previousPicture_clicked()
{
    index_currentPic--;

    setIndexToLabel();

    setEnable_prevNextButton();

    display_unLabData();

    closeTempRubberBands();

    bool_selected_rubberBand = false;
    setEnable_cropButton();

    destroyTempRubberBands();

    searchJsonFile();
}

void MainWindow::on_pushButton_nextPixture_clicked()
{
    index_currentPic++;

    setIndexToLabel();

    setEnable_prevNextButton();

    display_unLabData();

    closeTempRubberBands();

    bool_selected_rubberBand = false;
    setEnable_cropButton();

    destroyTempRubberBands();

    searchJsonFile();
}

void MainWindow::closeTempRubberBands()
{
    for(int i = 0; i < vector_rubberBandDrawn.size(); i++)
    {
        vector_rubberBandDrawn.at(i)->close();
    }
}



void MainWindow::on_lineEdit_search_textChanged(const QString &arg)
{
    cleanTable();

    QList<int> list_index_table;
    QStringList filtered;

    cleanTable();

    filterTable(arg, filtered);

    setIndexsToList(list_index_table, filtered);

    hideTableElement();

    showFilteredTableElements(list_index_table);

    //cleans the list_index_table
    list_index_table.clear();
}

void MainWindow::cleanTable()
{
    // cleans table completely
    ui->listWidget_photoWithDirection->clear();
}

void MainWindow::filterTable(QString arg, QStringList &filtered)
{
    QRegExp regExp(arg, Qt::CaseInsensitive, QRegExp::Wildcard);

    filtered = list_name_title_refData.filter(regExp);
    ui->listWidget_photoWithDirection->addItems(filtered);
}

void MainWindow::setIndexsToList(QList<int> &list_index_table, QStringList &filtered)
{
    // sets indexs into list

    for(int i=0; i<list_name_title_refData.count(); i++)
    {
        for(int j=0; j<filtered.count(); j++)
        {
            if(filtered.at(j) == list_name_title_refData.at(i))
            {
                list_index_table.push_back(i);
                break;
            }
        }
    }
}

void MainWindow::hideTableElement()
{
    for(int i=0; i<list_name_title_refData.count(); i++)
    {
        ui->tableView_photoWithDirection->hideRow(i);
    }
}

void MainWindow::showFilteredTableElements(QList<int> list_index_table)
{
    for(int i=0; i<list_index_table.count(); i++)
    {
        ui->tableView_photoWithDirection->showRow(list_index_table.at(i));
    }
}



void MainWindow::on_tableView_photoWithDirection_clicked(const QModelIndex &index)
{
    index_selectedRefData = index.row();
    bool_selected_model = true;

    setEnable_cropButton();
}



void MainWindow::setEnable_prevNextButton()
{
    if(bool_selected_unlabData)
    {
        //if only one picture is loaded
        if(list_path_unlabData.count() == 1)
        {
            ui->pushButton_previousPicture->setEnabled(false);
            ui->pushButton_nextPixture->setEnabled(false);
        }

        //if the current picture is the first one
        else if(index_currentPic == 0)
        {
            ui->pushButton_previousPicture->setEnabled(false);
            ui->pushButton_nextPixture->setEnabled(true);
        }

        //if the current picture is the last one
        else if(list_path_unlabData.count()-1 == index_currentPic)
        {
            ui->pushButton_previousPicture->setEnabled(true);
            ui->pushButton_nextPixture->setEnabled(false);
        }

        else
        {
            ui->pushButton_previousPicture->setEnabled(true);
            ui->pushButton_nextPixture->setEnabled(true);
        }
    }

    else
    {
        ui->pushButton_previousPicture->setEnabled(false);
        ui->pushButton_nextPixture->setEnabled(false);
    }
}

void MainWindow::setEnable_cropButton()
{
    if(bool_selected_rubberBand && bool_selected_model)
    {
        ui->pushButton_crop->setEnabled(true);
    }

    else
    {
        ui->pushButton_crop->setEnabled(false);
    }
}

void MainWindow::setEnable_labDataButton()
{
    if(bool_selected_unlabData)
    {
        ui->pushButton_labeledData->setEnabled(true);
    }

    else
    {
        ui->pushButton_labeledData->setEnabled(false);
    }
}

void MainWindow::setEnable_unlabDataButton()
{
    if(bool_selected_refData)
    {
        ui->pushButton_unlabeledData->setEnabled(true);
    }

    else
    {
        ui->pushButton_unlabeledData->setEnabled(false);
    }
}



void MainWindow::setMousePressPosition(QPoint &position_mouse)
{
    point_mousePress = position_mouse;
    bool_selected_rubberBand = false;



    setEnable_cropButton();
}

void MainWindow::setMouseReleasePosition(QPoint &position_mouse)
{
    bool_selected_rubberBand = true;
    point_mouseRelease = position_mouse;
}



void MainWindow::makeVector_item(std::vector<QStandardItem *> &vector_item_pic, std::vector<QStandardItem *> &vector_item_name, int size_table)
{
    for(int i=0; i<size_table; i++)
    {
        QStandardItem *item_pic = new QStandardItem();
        QStandardItem *item_name = new QStandardItem();

        vector_item_pic.push_back(item_pic);
        vector_item_name.push_back(item_name);
    }
}

void MainWindow::setItemToTable(std::vector<QStandardItem *> &vector_item_pic, std::vector<QStandardItem *> &vector_item_name, QStringList list_path_refData, int size_table, QStandardItemModel *model)
{
    QString path_refData;

    for(int i=0; i<size_table; i++)
    {
        path_refData = list_path_refData.at(i);

        QPixmap pix(path_refData);
        pix = pix.scaled(150,150, Qt::KeepAspectRatio);

        vector_item_name.at(i)->setText( list_name_title_refData.at(i) );
        vector_item_pic.at(i)->setData(QVariant(pix), Qt::DecorationRole);
        model->setItem(i, 0, vector_item_pic.at(i));
        model->setItem(i, 1, vector_item_name.at(i));
    }
}

void MainWindow::show_itemOnTable(QStandardItemModel *model)
{
    ui->tableView_photoWithDirection->setModel( model );
    ui->tableView_photoWithDirection->horizontalHeader()->setDefaultSectionSize(150);
    ui->tableView_photoWithDirection->verticalHeader()->setDefaultSectionSize(150);

    //disable class name edit
    ui->tableView_photoWithDirection->setEditTriggers(QAbstractItemView::NoEditTriggers);
}



void MainWindow::drawRubberBandUsingJson(int tempX1, int tempX2, int tempY1, int tempY2)
{
    QPoint top, bottom;

    top.setX(tempX1);
    top.setY(tempY1);
    bottom.setX(tempX2);
    bottom.setY(tempY2);


    QColor color_rubberBand;
    color_rubberBand = generateColor();

    // makes rubberBands colorful
    QPalette palette;
    palette = generatePalette(color_rubberBand);

    QRubberBand *rubberBand = new QRubberBand(QRubberBand::Rectangle);
    rubberBand->setParent(ui->label_Picture);
    rubberBand->setPalette(palette);
    rubberBand->setGeometry(QRect(top, QSize()));
    rubberBand->show();
    rubberBand->setGeometry(QRect(top, bottom).normalized());

    vector_tempRubberBand.push_back(rubberBand);
}

QColor MainWindow::generateColor()
{
    int r, g, b;

    srand(time(NULL));
    r = rand() % 255;
    g = rand() % 255;
    b = rand() % 255;

    QColor color(r,g,b);

    return color;
}

QPalette MainWindow::generatePalette(QColor color)
{
    QPalette palette;
    palette.setBrush(QPalette::Highlight, QBrush(color));

    return palette;
}



void MainWindow::searchJsonFile()
{
    QDir jsonDir(path_dir_jsonFile);
    QStringList jsonFilesPathList = jsonDir.entryList(QStringList() << "*.json", QDir::Files); // e.g. "0.json"

    int numberOfFiles;

    fileSearchFor = QVariant(index_currentPic).toString() + ".json";

    numberOfFiles = jsonFilesPathList.size();

    for(int i=0; i<numberOfFiles; i++)
    {
        if( !fileSearchFor.compare(jsonFilesPathList.at(i)) )
        {
            readJsonFile();
            break;
        }
    }
}

void MainWindow::readJsonFile()
{
    QString jsonFilePath = path_dir_jsonFile + "/" + fileSearchFor;

    QFile file(jsonFilePath);
    file.open(QIODevice::ReadWrite);

    QString jsonContent = file.readAll();

    double ratioX, ratioY;
    calculate_ratio(ratioX, ratioY);

    readJsonCoor(ratioX, ratioY, jsonContent);
}

void MainWindow::readJsonCoor(double ratioX, double ratioY, QString jsonContent)
{
    int i = 0;

    while(true)
    {
        QtJson::JsonObject result = QtJson::parse(jsonContent).toMap();
        QtJson::JsonObject nested = result[QVariant(i).toString()].toMap();

        int tempX1 = (int) (nested["x1"].toInt() / ratioX);
        int tempX2 = (int) (nested["x2"].toInt() / ratioX);
        int tempY1 = (int) (nested["y1"].toInt() / ratioY);
        int tempY2 = (int) (nested["y2"].toInt() / ratioY);


        if(!tempX1 && !tempX2 && !tempY1 && !tempY2)
        {
            break;
        }

        i++;

        drawRubberBandUsingJson(tempX1, tempX2, tempY1, tempY2);
    }
}


void MainWindow::destroyTempRubberBands()
{
    for(int i=0; i<vector_tempRubberBand.size(); i++)
    {
        delete vector_tempRubberBand.at(i);
    }

    vector_tempRubberBand.clear();
}

void MainWindow::openDirectoryChooser(QFileDialog &dialog)
{
    dialog.setDirectory(QDir::homePath());
    dialog.setFileMode(QFileDialog::DirectoryOnly);
}



void MainWindow::display_unLabData()
{
    QPixmap pix(list_path_unlabData[index_currentPic]);
    int pixWidth = ui->label_Picture->width();
    int pixHeight = ui->label_Picture->height();

    ui->label_Picture->setPixmap(pix.scaled(pixWidth, pixHeight, Qt::IgnoreAspectRatio));
}

void MainWindow::showMouseCurrentPosition(QPoint &position_mouse)
{
    ui->label_Coordinate->setText("x: " + QString::number(position_mouse.x()) + "  y: " + QString::number(position_mouse.y()));
}


void MainWindow::getRubberBandVector(std::vector<QRubberBand *> &rubberBandVectorFromPictureDisplay)
{
    vector_rubberBandDrawn = rubberBandVectorFromPictureDisplay;
}

void MainWindow::on_pushButton_revomeSelection_clicked()
{
    for(int i = 0; i < vector_rubberBandDrawn.size(); i++)
    {
        vector_rubberBandDrawn.at(i)->close();
    }

    destroyTempRubberBands();
    searchJsonFile();
}



void MainWindow::on_pushButton_addNewModel_clicked()
{
    newModel = new NewModel();
    newModel->show();

    connect(newModel, SIGNAL(sendModelInfo(QString&, QString&, QString&, QString&, QString&)), this, SLOT(getModelInfo(QString&, QString&, QString&, QString&, QString&)));
    connect(this, SIGNAL(sendPicInfo(int&, QStringList&)), newModel, SLOT(getPicInfo(int&, QStringList&)));
    emit sendPicInfo(index_currentPic, list_path_unlabData);
}

void MainWindow::getModelInfo(QString &brand, QString &type, QString &model, QString &year, QString &path_newModelImage)
{
    createNewModelDirectory(brand, type, model, year, path_newModelImage);
    runRefData();
    runLabData();

    delete newModel;
}


void MainWindow::createNewModelDirectory(QString brand, QString type, QString model, QString year, QString path_newModelImage)
{
    // e.g. "/home/sinan/Desktop/vecPhoto/vec/1/Car/2/3"
    QString path_newModel = path_dir_refData + "/" + brand + "/" + type + "/" + model + "/" + year;

    QDir dir(path_newModel);
    if (!dir.exists()) {
        dir.mkpath(".");
    }


    // saves sample image
    QPixmap pix(path_newModelImage);
    QFile file("sample.png");
    file.setFileName(dir.absoluteFilePath("sample.png"));
    file.open(QIODevice::WriteOnly);
    pix.save(&file, "PNG");
}



void MainWindow::keyPressEvent(QKeyEvent *event_keyPress)
{
    if(event_keyPress->key() == Qt::Key_A)
    {
        ui->pushButton_previousPicture->click();
    }

    else if(event_keyPress->key() == Qt::Key_D)
    {
        ui->pushButton_nextPixture->click();
    }
}



void MainWindow::on_pushButton_goIndex_clicked()
{
    int index = QVariant(ui->lineEdit_goIndex->text()).toInt();

    if( index >= 0  &&  index <= (number_unlabeledImage-1) )
    {
        index_currentPic = index;

        display_unLabData();

        setIndexToLabel();

        setEnable_prevNextButton();

    }
}

void MainWindow::setIndexToLabel()
{
    ui->label_index_currentPic->setText(QVariant( index_currentPic ).toString());
}


