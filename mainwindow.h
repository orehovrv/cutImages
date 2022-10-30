#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtCore>
#include <QMainWindow>

#include <QGridLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>

#include <QPushButton>
#include <QCheckBox>
#include <QLabel>
#include <QLineEdit>
#include <QSpinBox>
#include <QListWidget>
#include <QSlider>

#include <QStatusBar>

#include <QDir>
#include <QFileDialog>

#include <QPixmap>
#include <QPainter>
#include <QPainterPath>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

    QWidget * centralWidget, * imageWidget;

    QHBoxLayout * mainHorizontalLayout;

    QHBoxLayout * angleHorizontalLayout;
    QHBoxLayout * indentHorizontalLayout;
    QHBoxLayout * heightHorizontalLayout;

    QHBoxLayout * ratioHorizontalLayout;
    QHBoxLayout * widthHorizontalLayout;
    QHBoxLayout * imageHorizontalLayout;

    QVBoxLayout * verticalLayout;
    QVBoxLayout * imageVerticalLayout;

    QGridLayout * gridLayout;

    QPushButton * openButton;
    QPushButton * artsButton;
    QPushButton * hartsButton;
    QPushButton * deleteButton;

    QCheckBox * cutCheckBox;
    QCheckBox * inscriptionCheckBox;
    QCheckBox * ratioCheckBox;
    QCheckBox * scaledCheckBox;

    QLabel * angleLabel;
    QLabel * indentLabel;
    QLabel * heightLabel;
    QLabel * ratioLabel;
    QLabel * widthLabel;
    QLabel * textLabel;
    QLabel * imageLabel;

    QLineEdit * textLineEdit;
    QLineEdit * indentLineEdit;
    QLineEdit * heightLineEdit;
    QLineEdit * ratioLineEdit;
    QLineEdit * widthLineEdit;

    QSpinBox * angleSpinBox;

    QListWidget * listNameWidget;

    QSlider * imageVerticalSlider;
    QSlider * imageHorizontalSlider;
    QSlider * inscriptionVerticalSlider;
    QSlider * inscriptionHorizontalSlider;

    QStatusBar * statusbar;

    private:
        Ui::MainWindow * ui;

        QString mPath;
        QStringList picturesNameList;

        QPixmap image, tempImage;
        QRect imageCutRect;
		int imageWidth = 1264;

		double ratio = 1.32911;

        const int labelWidgetMaxHeight = 900;
        int labelWidgetMaxWidth = ceil(labelWidgetMaxHeight / ratio);

        int verticalSliderMax;
        int horizntalSliderMax;

        void imageLoad(QString);
        void resizeFile();


        void newCord(int, int, int *, int *);

        void saveFile(QString);

    private slots:
        void openButton_clicked();
        void artsButton_clicked();
        void hartsButton_clicked();
        void deleteButton_clicked();

        void listNameWidget_itemClicked();

        void cutCheckBox_clicked();
        void inscriptionCheckBox_clicked();
        void ratioCheckBox_clicked();
        void scaledCheckBox_clicked();

        void ratioLineEdit_editingFinished();
        void widthLineEdit_editingFinished();

        void imageUpdate();

    public:
        MainWindow(QWidget *parent = nullptr);
        ~MainWindow();
};
#endif // MAINWINDOW_H
