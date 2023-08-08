#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtDataVisualization>
#include <QSurface>
#include <QBoxLayout>

#pragma execution_character_set("utf-8")

using namespace QtDataVisualization;
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


public:
    void timeout();                  // 定时器槽函数

private slots:

    void on_pushButton_clicked();    // 显示3d平面图

    void on_pushButton_2_clicked();  // 显示3d柱状图

private:
    Ui::MainWindow *ui;

    QtDataVisualization::Q3DSurface flatSurface;

    Q3DBars bars;

    QTimer * timer = new QTimer;
};
#endif // MAINWINDOW_H
