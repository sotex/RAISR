#include "raisrwidget.hpp"
#include "ui_raisrwidget.h"

#include "RAISR.h"

#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <vector>

#include <QFileDialog>


RAISRWidget::RAISRWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RAISRWidget)
{
    ui->setupUi(this);
}

RAISRWidget::~RAISRWidget()
{
    delete ui;
}

void RAISRWidget::on_pbtn_selfile_clicked()
{
    QString inFile = QFileDialog::getOpenFileName(this,
                                                  QStringLiteral("选择图片"),
                                                  QString(),
                                                  QStringLiteral("Images (*.png *.jpeg *.jpg)"));
    QImage inImage;
    if(!inImage.load(inFile)){
        ui->pbtn_doraisr->setEnabled(false);
        return;
    }

    ui->lned_input->setText(inFile);
    ui->lab_input->setPixmap(QPixmap::fromImage(inImage));
    ui->pbtn_doraisr->setEnabled(true);
}

void RAISRWidget::on_pbtn_doraisr_clicked()
{
    std::vector<cv::Mat> inMatList;
    inMatList.push_back(cv::imread(ui->lned_input->text().toStdString()));

    RAISR model(inMatList,4,11,9);
    model.train();
    model.writeOutFilter(std::string("./filterOut"));



}
