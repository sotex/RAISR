#ifndef RAISRWIDGET_HPP
#define RAISRWIDGET_HPP

#include <QWidget>

namespace Ui {
class RAISRWidget;
}

class RAISRWidget : public QWidget
{
    Q_OBJECT

public:
    explicit RAISRWidget(QWidget *parent = nullptr);
    ~RAISRWidget();

private slots:
    void on_pbtn_selfile_clicked();

    void on_pbtn_doraisr_clicked();

private:
    Ui::RAISRWidget *ui;
};

#endif // RAISRWIDGET_HPP
