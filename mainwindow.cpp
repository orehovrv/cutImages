#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget * parent): QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    centralWidget = new QWidget(this);

    mainHorizontalLayout = new QHBoxLayout(centralWidget);

    verticalLayout = new QVBoxLayout();

    openButton = new QPushButton(centralWidget);
    openButton->setText("Открыть папку");
    openButton->setMinimumWidth(200);
    openButton->setMaximumWidth(200);

    cutCheckBox = new QCheckBox(centralWidget);
    cutCheckBox->setText("Обрезать картинку");
    cutCheckBox->setMinimumWidth(200);
    cutCheckBox->setMaximumWidth(200);

    artsButton = new QPushButton(centralWidget);
    artsButton->setText("Сохранить в Arts");
    artsButton->setMinimumWidth(200);
    artsButton->setMaximumWidth(200);
    hartsButton = new QPushButton(centralWidget);
    hartsButton->setText("Сохранить в HArts");
    hartsButton->setMinimumWidth(200);
    hartsButton->setMaximumWidth(200);
    deleteButton = new QPushButton(centralWidget);
    deleteButton->setText("Сохранить в Delete");
    deleteButton->setMinimumWidth(200);
    deleteButton->setMaximumWidth(200);

    inscriptionCheckBox = new QCheckBox(centralWidget);
    inscriptionCheckBox->setText("Добавить надпись");
    inscriptionCheckBox->setMinimumWidth(200);
    inscriptionCheckBox->setMaximumWidth(200);

    textLineEdit = new QLineEdit(centralWidget);
    textLineEdit->setMinimumWidth(200);
    textLineEdit->setMaximumWidth(200);
    textLineEdit->setText("Сон");
    textLineEdit->setDisabled(true);

    angleHorizontalLayout = new QHBoxLayout();

    angleLabel = new QLabel(centralWidget);
    angleLabel->setMinimumSize(QSize(137, 0));
    angleLabel->setMaximumSize(QSize(137, 16777215));
    angleLabel->setText("Угол поворота надписи");
    angleLabel->setDisabled(true);

    angleSpinBox = new QSpinBox(centralWidget);
    angleSpinBox->setAlignment(Qt::AlignCenter);
    angleSpinBox->setRange(-360, 360);
    angleSpinBox->setDisabled(true);

    angleHorizontalLayout->addWidget(angleLabel);
    angleHorizontalLayout->addWidget(angleSpinBox);

    indentHorizontalLayout = new QHBoxLayout();

    indentLabel = new QLabel(centralWidget);
    indentLabel->setMinimumSize(QSize(60, 0));
    indentLabel->setMaximumSize(QSize(60, 16777215));
    indentLabel->setText("Отступ");
    indentLabel->setDisabled(true);

    indentLineEdit = new QLineEdit(centralWidget);
    indentLineEdit->setAlignment(Qt::AlignCenter);
    indentLineEdit->setValidator(new QRegExpValidator(QRegExp("[-]{,1}[0-9]{,5}"), indentLineEdit));
    indentLineEdit->setText(QString::number(100));
    indentLineEdit->setDisabled(true);
    indentLineEdit->setMinimumWidth(200 - 60 - 6);
    indentLineEdit->setMaximumWidth(200 - 60 - 6);

    indentHorizontalLayout->addWidget(indentLabel);
    indentHorizontalLayout->addWidget(indentLineEdit);

    heightHorizontalLayout = new QHBoxLayout();

    heightLabel = new QLabel(centralWidget);
    heightLabel->setMinimumSize(QSize(60, 0));
    heightLabel->setMaximumSize(QSize(60, 16777215));
    heightLabel->setText("Высота");
    heightLabel->setDisabled(true);

    heightLineEdit = new QLineEdit(centralWidget);
    heightLineEdit->setAlignment(Qt::AlignCenter);
    heightLineEdit->setValidator(new QRegExpValidator(QRegExp("[1-9][0-9]{,5}"), heightLineEdit));
    heightLineEdit->setText(QString::number(120));
    heightLineEdit->setDisabled(true);
    heightLineEdit->setMinimumWidth(200 - 60 - 6);
    heightLineEdit->setMaximumWidth(200 - 60 - 6);

    heightHorizontalLayout->addWidget(heightLabel);
    heightHorizontalLayout->addWidget(heightLineEdit);

    ratioCheckBox = new QCheckBox(centralWidget);
    ratioCheckBox->setText("Изменить соотношение сторон");
    ratioCheckBox->setMinimumWidth(200);
    ratioCheckBox->setMaximumWidth(200);

    ratioLabel = new QLabel(centralWidget);
    ratioLabel->setMinimumSize(QSize(92, 0));
    ratioLabel->setMaximumSize(QSize(92, 16777215));
    ratioLabel->setText("Высота / ширину:");
    ratioLabel->setDisabled(true);

    ratioLineEdit = new QLineEdit(centralWidget);
    ratioLineEdit->setAlignment(Qt::AlignCenter);
    ratioLineEdit->setValidator(new QRegExpValidator(QRegExp("[0-9]*\\.{,1}[0-9]{,5}"), ratioLineEdit));
    ratioLineEdit->setText(QString::number(ratio));
    ratioLineEdit->setDisabled(true);
    ratioLineEdit->setMinimumWidth(200 - 92 - 6);
    ratioLineEdit->setMaximumWidth(200 - 92 - 6);

    ratioHorizontalLayout = new QHBoxLayout();
    ratioHorizontalLayout->addWidget(ratioLabel);
    ratioHorizontalLayout->addWidget(ratioLineEdit);

    scaledCheckBox = new QCheckBox(centralWidget);
    scaledCheckBox->setText("Сжать картинку");
    scaledCheckBox->setMinimumWidth(200);
    scaledCheckBox->setMaximumWidth(200);

    widthLabel = new QLabel(centralWidget);
    widthLabel->setMinimumSize(QSize(92, 0));
    widthLabel->setMaximumSize(QSize(92, 16777215));
    widthLabel->setText("Ширина картинки");
    widthLabel->setDisabled(true);

    widthLineEdit = new QLineEdit(centralWidget);
    widthLineEdit->setAlignment(Qt::AlignCenter);
    widthLineEdit->setValidator(new QRegExpValidator(QRegExp("[1-9][0-9]{,4}"), widthLineEdit));
    widthLineEdit->setText(QString::number(imageWidth));
    widthLineEdit->setDisabled(true);
    widthLineEdit->setMinimumWidth(200 - 92 - 6);
    widthLineEdit->setMaximumWidth(200 - 92 - 6);

    widthHorizontalLayout = new QHBoxLayout();
    widthHorizontalLayout->addWidget(widthLabel);
    widthHorizontalLayout->addWidget(widthLineEdit);

    listNameWidget = new QListWidget(centralWidget);
    listNameWidget->setMinimumWidth(200);
    listNameWidget->setMaximumWidth(200);

    textLabel = new QLabel(centralWidget);
    textLabel->setMinimumWidth(200);
    textLabel->setMaximumWidth(200);

    verticalLayout->addWidget(openButton);
    verticalLayout->addWidget(cutCheckBox);
    verticalLayout->addWidget(artsButton);
    verticalLayout->addWidget(hartsButton);
    verticalLayout->addWidget(deleteButton);
    verticalLayout->addWidget(inscriptionCheckBox);
    verticalLayout->addWidget(textLineEdit);
    verticalLayout->addLayout(angleHorizontalLayout);
    verticalLayout->addLayout(indentHorizontalLayout);
    verticalLayout->addLayout(heightHorizontalLayout);
    verticalLayout->addWidget(ratioCheckBox);
    verticalLayout->addLayout(ratioHorizontalLayout);
    verticalLayout->addWidget(scaledCheckBox);
    verticalLayout->addLayout(widthHorizontalLayout);
    verticalLayout->addWidget(listNameWidget);
    verticalLayout->addWidget(textLabel);

    imageVerticalSlider = new QSlider(centralWidget);
    imageVerticalSlider->setOrientation(Qt::Vertical);
    imageVerticalSlider->setValue(50);
    imageVerticalSlider->setDisabled(true);

    imageWidget = new QWidget(centralWidget);
    imageWidget->setMinimumSize(QSize(labelWidgetMaxWidth, labelWidgetMaxHeight));
    imageWidget->setMaximumSize(QSize(labelWidgetMaxWidth, labelWidgetMaxHeight));
    imageWidget->setStyleSheet("QWidget { border: 1 solid #828790; background-color: white }");

    imageVerticalLayout = new QVBoxLayout(imageWidget);
    imageVerticalLayout->setContentsMargins(0, 0, 0, 0);
    imageHorizontalLayout = new QHBoxLayout();
    imageHorizontalLayout->setContentsMargins(0, 0, 0, 0);

    imageLabel = new QLabel(centralWidget);
    imageLabel->setScaledContents(true);
    imageLabel->setStyleSheet("QWidget { border: 0; background-color: white }");
    imageLabel->setMinimumSize(QSize(labelWidgetMaxWidth - 2, labelWidgetMaxHeight - 2));
    imageLabel->setMaximumSize(QSize(labelWidgetMaxWidth - 2, labelWidgetMaxHeight - 2));

    imageHorizontalLayout->addWidget(imageLabel);
    imageVerticalLayout->addLayout(imageHorizontalLayout);

    imageHorizontalSlider = new QSlider(centralWidget);
    imageHorizontalSlider->setMaximumSize(QSize(labelWidgetMaxWidth, 16777215));
    imageHorizontalSlider->setOrientation(Qt::Horizontal);
    imageHorizontalSlider->setValue(50);
    imageHorizontalSlider->setDisabled(true);

    inscriptionVerticalSlider = new QSlider(centralWidget);
    inscriptionVerticalSlider->setOrientation(Qt::Vertical);
    inscriptionVerticalSlider->setValue(50);
    inscriptionVerticalSlider->setDisabled(true);

    inscriptionHorizontalSlider = new QSlider(centralWidget);
    inscriptionHorizontalSlider->setMaximumSize(QSize(labelWidgetMaxWidth, 16777215));
    inscriptionHorizontalSlider->setOrientation(Qt::Horizontal);
    inscriptionHorizontalSlider->setValue(50);
    inscriptionHorizontalSlider->setDisabled(true);

    gridLayout = new QGridLayout();
    gridLayout->addWidget(imageVerticalSlider, 0, 1, 1, 1);
    gridLayout->addWidget(imageWidget, 0, 0, 1, 1);
    gridLayout->addWidget(imageHorizontalSlider, 1, 0, 1, 1);
    gridLayout->addWidget(inscriptionVerticalSlider, 0, 2, 1, 1);
    gridLayout->addWidget(inscriptionHorizontalSlider, 2, 0, 1, 1);

    mainHorizontalLayout->addLayout(verticalLayout);
    mainHorizontalLayout->addLayout(gridLayout);

    statusbar = new QStatusBar(this);

    this->setCentralWidget(centralWidget);
    this->setStatusBar(statusbar);
    //this->resize(0, 0);
    this->setGeometry(500, 50, 0, 0);

    connect(openButton, SIGNAL(clicked()), this, SLOT(openButton_clicked()));
    connect(artsButton, SIGNAL(clicked()), this, SLOT(artsButton_clicked()));
    connect(hartsButton, SIGNAL(clicked()), this, SLOT(hartsButton_clicked()));
    connect(deleteButton, SIGNAL(clicked()), this, SLOT(deleteButton_clicked()));

    connect(listNameWidget, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(listNameWidget_itemClicked()));

    connect(cutCheckBox, SIGNAL(clicked()), this, SLOT(cutCheckBox_clicked()));
    connect(inscriptionCheckBox, SIGNAL(clicked()), this, SLOT(inscriptionCheckBox_clicked()));
    connect(ratioCheckBox, SIGNAL(clicked()), this, SLOT(ratioCheckBox_clicked()));
    connect(scaledCheckBox, SIGNAL(clicked()), this, SLOT(scaledCheckBox_clicked()));

    connect(imageVerticalSlider, SIGNAL(valueChanged(int)), this, SLOT(imageUpdate()));
    connect(imageHorizontalSlider, SIGNAL(valueChanged(int)), this, SLOT(imageUpdate()));
    connect(inscriptionVerticalSlider, SIGNAL(valueChanged(int)), this, SLOT(imageUpdate()));
    connect(inscriptionHorizontalSlider, SIGNAL(valueChanged(int)), this, SLOT(imageUpdate()));

    connect(ratioLineEdit, SIGNAL(editingFinished()), this, SLOT(ratioLineEdit_editingFinished()));
    connect(widthLineEdit, SIGNAL(editingFinished()), this, SLOT(widthLineEdit_editingFinished()));
    connect(indentLineEdit, SIGNAL(editingFinished()), this, SLOT(imageUpdate()));
    connect(heightLineEdit, SIGNAL(editingFinished()), this, SLOT(imageUpdate()));
    connect(textLineEdit, SIGNAL(textEdited(const QString &)), this, SLOT(imageUpdate()));

    connect(angleSpinBox, SIGNAL(valueChanged(int)), this, SLOT(imageUpdate()));
}

MainWindow::~MainWindow() {
    delete ui;
}

//=============================================================================

void MainWindow::openButton_clicked() {
    mPath = QFileDialog::getExistingDirectory(this, tr("Open folder with images"), "C:/", QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);

    QDir nDir(mPath);
    if(!nDir.exists()) {
        mPath = "";
        return;
    }

    picturesNameList = nDir.entryList(QStringList() << "*.png" << "*.jpg" << "*.jpeg" << "*.webp" << "*.gif", QDir::Files);

    listNameWidget->clear();
    listNameWidget->addItems(picturesNameList);

    textLabel->setText("Количество изображений: " + QString::number(picturesNameList.count()));

    if(!picturesNameList.count()) return;

    listNameWidget->setCurrentRow(0);
    listNameWidget_itemClicked();
}

void MainWindow::artsButton_clicked() {
    saveFile("Arts");
}

void MainWindow::hartsButton_clicked() {
    saveFile("HArts");
}

void MainWindow::deleteButton_clicked() {
    saveFile("Delete");
}

//=============================================================================

void MainWindow::listNameWidget_itemClicked() {
    int index = listNameWidget->currentRow();

    if(-1 < index && index < picturesNameList.count())
        imageLoad(mPath + "/" + picturesNameList[index]);
}

//=============================================================================

void MainWindow::cutCheckBox_clicked() {
    if(cutCheckBox->checkState()) {
        imageHorizontalSlider->setDisabled(true);
        imageVerticalSlider->setDisabled(true);
    }

    if(!picturesNameList.count()) return;

    resizeFile();
    imageUpdate();

    if(inscriptionCheckBox->checkState()) {
        inscriptionVerticalSlider->setValue(tempImage.height() / 2);
        inscriptionHorizontalSlider->setValue(tempImage.width() / 2);
        imageUpdate();
    }
}

void MainWindow::inscriptionCheckBox_clicked() {
    if(!picturesNameList.count()) return;

    inscriptionVerticalSlider->setDisabled(!inscriptionCheckBox->checkState());
    inscriptionHorizontalSlider->setDisabled(!inscriptionCheckBox->checkState());
    textLineEdit->setDisabled(!inscriptionCheckBox->checkState());
    angleLabel->setDisabled(!inscriptionCheckBox->checkState());
    indentLabel->setDisabled(!inscriptionCheckBox->checkState());
    heightLabel->setDisabled(!inscriptionCheckBox->checkState());
    angleSpinBox->setDisabled(!inscriptionCheckBox->checkState());
    indentLineEdit->setDisabled(!inscriptionCheckBox->checkState());
    heightLineEdit->setDisabled(!inscriptionCheckBox->checkState());

    resizeFile();
    imageUpdate();

    if(inscriptionCheckBox->checkState()) {
        inscriptionVerticalSlider->setValue(tempImage.height() / 2);
        inscriptionHorizontalSlider->setValue(tempImage.width() / 2);
        imageUpdate();
    }
}

void MainWindow::ratioCheckBox_clicked() {
    ratioLabel->setDisabled(!ratioCheckBox->checkState());
    ratioLineEdit->setDisabled(!ratioCheckBox->checkState());
}

void MainWindow::scaledCheckBox_clicked() {
    widthLabel->setDisabled(!scaledCheckBox->checkState());
    widthLineEdit->setDisabled(!scaledCheckBox->checkState());
}

//=============================================================================

void MainWindow::ratioLineEdit_editingFinished() {
    ratio = ratioLineEdit->text().toDouble();

    labelWidgetMaxWidth = ceil(labelWidgetMaxHeight / ratio);

    imageWidget->setMinimumSize(QSize(labelWidgetMaxWidth, labelWidgetMaxHeight));
    imageWidget->setMaximumSize(QSize(labelWidgetMaxWidth, labelWidgetMaxHeight));

    imageHorizontalSlider->setMinimumWidth(labelWidgetMaxWidth);
    imageHorizontalSlider->setMaximumWidth(labelWidgetMaxWidth);

    inscriptionHorizontalSlider->setMinimumWidth(labelWidgetMaxWidth);
    inscriptionHorizontalSlider->setMaximumWidth(labelWidgetMaxWidth);

    if(!picturesNameList.count()) return;

    resizeFile();
    imageUpdate();
}

void MainWindow::widthLineEdit_editingFinished() {
    imageWidth = widthLineEdit->text().toInt();

    if(!picturesNameList.count()) return;

    resizeFile();
    imageUpdate();
}

//=============================================================================

void MainWindow::imageLoad(QString path_in) {
    image.load(path_in);

    resizeFile();
    imageUpdate();
}

void MainWindow::resizeFile() {
    double imageRatio = (double)image.height() / image.width();

    if(cutCheckBox->checkState()) {
        if(imageRatio - 0.001 <= ratio && ratio <= imageRatio + 0.001) {
            imageHorizontalSlider->setDisabled(true);
            imageVerticalSlider->setDisabled(true);
        } else if(imageRatio <= ratio) {
            imageHorizontalSlider->setDisabled(false);
            imageVerticalSlider->setDisabled(true);

            horizntalSliderMax = image.width() - ceil(image.height() / ratio);

            imageHorizontalSlider->setRange(0, horizntalSliderMax);
            //qDebug() << "Horizontal slider range is " << 0 << " to " << horizntalSliderMax;

            imageHorizontalSlider->setValue(horizntalSliderMax / 2);
        } else {
            imageHorizontalSlider->setDisabled(true);
            imageVerticalSlider->setDisabled(false);

            verticalSliderMax = image.height() - ceil(image.width() * ratio);

            imageVerticalSlider->setRange(0, verticalSliderMax);
            //qDebug() << "Vertical slider range is " << 0 << " to " << verticalSliderMax;

            imageVerticalSlider->setValue(verticalSliderMax / 2);
        }

        imageLabel->setMinimumSize(QSize(labelWidgetMaxWidth - 2, labelWidgetMaxHeight - 2));
        imageLabel->setMaximumSize(QSize(labelWidgetMaxWidth - 2, labelWidgetMaxHeight - 2));
    } else {
        if(imageRatio - 0.001 <= ratio && ratio <= imageRatio + 0.001) {
            imageLabel->setMinimumSize(QSize(labelWidgetMaxWidth - 2, labelWidgetMaxHeight - 2));
            imageLabel->setMaximumSize(QSize(labelWidgetMaxWidth - 2, labelWidgetMaxHeight - 2));
        } else if(imageRatio <= ratio) {
            imageLabel->setMinimumSize(QSize(labelWidgetMaxWidth - 2, ceil((labelWidgetMaxWidth - 2) * imageRatio)));
            imageLabel->setMaximumSize(QSize(labelWidgetMaxWidth - 2, ceil((labelWidgetMaxWidth - 2) * imageRatio)));
        } else {
            imageLabel->setMinimumSize(QSize(ceil((labelWidgetMaxHeight - 2) / imageRatio), labelWidgetMaxHeight - 2));
            imageLabel->setMaximumSize(QSize(ceil((labelWidgetMaxHeight - 2) / imageRatio), labelWidgetMaxHeight - 2));
        }
    }
}

void MainWindow::newCord(int x, int y, int * x1, int * y1) {
    int angle = angleSpinBox->value();

    *x1 = x * cos(angle * M_PI / 180) + y * sin(angle * M_PI / 180);
    *y1 = y * cos(angle * M_PI / 180) - x * sin(angle * M_PI / 180);
}

void MainWindow::imageUpdate() {
    if(!picturesNameList.count()) return;

    imageLabel->setPixmap(tempImage);

    if(cutCheckBox->checkState()) {
        double ratioImage = (double)image.height() / image.width();
        if(ratioImage - 0.001 <= ratio && ratio <= ratioImage + 0.001) {
            imageCutRect.setRect(0, 0, image.width(), image.height());
        } else if(ratioImage <= ratio) {
            imageCutRect.setRect(imageHorizontalSlider->value(), 0, ceil(image.height() / ratio), image.height());
        } else {
            imageCutRect.setRect(0, verticalSliderMax - imageVerticalSlider->value(), image.width(), ceil(image.width() * ratio));
        }
    } else imageCutRect.setRect(0, 0, image.width(), image.height());

    tempImage = image.copy(imageCutRect);

    if(scaledCheckBox->checkState() && imageWidth < image.width())
        tempImage = tempImage.scaled(imageWidth, imageWidth * ((double)tempImage.height() / tempImage.width()), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);

    inscriptionVerticalSlider->setRange(0, tempImage.height());
    inscriptionHorizontalSlider->setRange(0, tempImage.width());

    if(inscriptionCheckBox->checkState()) {
        int heightRect = heightLineEdit->text().toInt();
        int indent = indentLineEdit->text().toInt();
        int dEllipse = 62;

        int angle = angleSpinBox->value();
        int x0 = inscriptionHorizontalSlider->value();
        int y0 = tempImage.height() - inscriptionVerticalSlider->value();

        int x1 = x0 * cos(angle * M_PI / 180) + y0 * sin(angle * M_PI / 180);
        int y1 = y0 * cos(angle * M_PI / 180) - x0 * sin(angle * M_PI / 180);

        QPainter painter(&tempImage);
        QPainterPath path;
        QPen pen(Qt::black, 3);

        painter.rotate(angle);
        painter.translate(x1, y1);

        painter.setRenderHint(QPainter::Antialiasing);
        painter.setPen(pen);

        int xCenter = -((tempImage.width() - indent * 2) / 2);
        int yCenter = -heightRect / 2;

        path.addRoundedRect(QRectF(xCenter, yCenter, tempImage.width() - indent * 2, heightRect), 30, 30);
        painter.fillPath(path, Qt::white);
        painter.drawPath(path);

        painter.drawEllipse(xCenter + (heightRect - dEllipse) / 2, yCenter + (heightRect - dEllipse) / 2, dEllipse, dEllipse);

        painter.setFont(QFont("Calibri", 40));

        //QStringList temp = picturesNameList[listNameWidget->currentRow()].split(".", QString::SkipEmptyParts);

        painter.drawText(xCenter + (heightRect - dEllipse) / 2 + 25, yCenter + (heightRect - dEllipse) / 2 + 48, "i");
        //painter.drawText(xCenter + (heightRect - dEllipse) / 2 + 80, yCenter + (heightRect - dEllipse) / 2 + 48, temp[0].toUtf8().toBase64());
        painter.drawText(xCenter + (heightRect - dEllipse) / 2 + 80, yCenter + (heightRect - dEllipse) / 2 + 48, textLineEdit->text());
    }

    imageLabel->setPixmap(tempImage);
}

void MainWindow::saveFile(QString folderName_in) {
    int index = listNameWidget->currentRow();

    if(-1 == index || picturesNameList.count() <= index) return;

    QDir nDir(mPath + "/" + folderName_in);

    if(!nDir.exists()) {
        nDir.setPath(mPath);
        nDir.mkdir(folderName_in);
    }

    tempImage.save(mPath + "/" + folderName_in + "/" + picturesNameList[index]);
    picturesNameList.removeAt(picturesNameList.indexOf(picturesNameList[index]));

    listNameWidget->clear();
    if(picturesNameList.count()) {
        listNameWidget->addItems(picturesNameList);
        if(index == picturesNameList.count()) listNameWidget->setCurrentRow(index - 1);
        else if(index > 0) listNameWidget->setCurrentRow(index);
        else listNameWidget->setCurrentRow(0);
        listNameWidget_itemClicked();
        textLabel->setText("Количество изображений: " + QString::number(picturesNameList.count()));
    } else {
        textLabel->setText("");
        imageLabel->clear();
    }
}
