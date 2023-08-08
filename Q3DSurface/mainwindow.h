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
    QtDataVisualization::Q3DSurface surface;

private slots:

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
