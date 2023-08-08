﻿#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()    // 显示3d平面图
{
    // 创建一个3D表面对象
    flatSurface.setFlags(flatSurface.flags() ^ Qt::FramelessWindowHint); // 取消窗口边框 显示主界面菜单栏
    flatSurface.setWidth(800);
    flatSurface.setHeight(600);

    flatSurface.axisX()->setTitle("X轴");
    flatSurface.axisX()->setTitleVisible(true);
    flatSurface.axisX()->setRange(0,100);
    flatSurface.axisY()->setTitle("Y轴");
    flatSurface.axisY()->setTitleVisible(true);
    flatSurface.axisY()->setRange(0,100);
    flatSurface.axisZ()->setTitle("Z轴");
    flatSurface.axisZ()->setTitleVisible(true);
    flatSurface.axisZ()->setRange(0,50);

    flatSurface.activeTheme()->setGridEnabled(true);   // 坐标子网格线

    // 创建一个3D表面数据代理对象
    QtDataVisualization::QSurfaceDataProxy *proxy = new QtDataVisualization::QSurfaceDataProxy();

    // 创建一个3D表面系列对象
    QtDataVisualization::QSurface3DSeries *series = new QtDataVisualization::QSurface3DSeries(proxy);
    series->setDrawMode(QtDataVisualization::QSurface3DSeries::DrawSurfaceAndWireframe);   // 默认不写这个是带网格线的
    series->setFlatShadingEnabled(false);  // 是否启用曲面平铺阴影

    // 创建一个数据集
    QtDataVisualization::QSurfaceDataArray *dataArray = new QtDataVisualization::QSurfaceDataArray();
    QtDataVisualization::QSurfaceDataRow *dataRow;
//    for (float x = -10; x <= 10; x += 0.1) {
//        dataRow = new QtDataVisualization::QSurfaceDataRow();
//        for (float z = -10; z <= 10; z += 0.1) {
//            float r = sqrt(x * x + z * z);
//            float y = sin(r) / r;
//            *dataRow << QVector3D(x, y, z);
//        }
//        *dataArray << dataRow;
//    }

    for (float n = 0; n < 50; n += 0.1) {
        dataRow = new QtDataVisualization::QSurfaceDataRow();
        for (float m = 0; m < 100; m ++) {
            if(m>=40 && m<=60){
                *dataRow << QVector3D(m, 50+qrand() % 5, n);
            }else{
                *dataRow << QVector3D(m, 10+qrand() % 5, n);
            }
        }
        *dataArray << dataRow;
    }

//    dataRow = new QtDataVisualization::QSurfaceDataRow();
//    for (float m = 0; m < 100; m ++)
//    {
//        *dataRow << QVector3D(m, qrand() % 100, 5);
//    }

//    *dataArray << dataRow;
//    dataRow = new QtDataVisualization::QSurfaceDataRow();
//    for (float m = 0; m < 100; m ++)
//        *dataRow << QVector3D(m, qrand() % 100, 40);

//    *dataArray << dataRow;

    // 设置数据集
    proxy->resetArray(dataArray);
    flatSurface.addSeries(series);

    // 显示窗口
    flatSurface.show();
}

void MainWindow::on_pushButton_2_clicked()      // 显示3d柱状图
{
    bars.setFlags(bars.flags() ^ Qt::FramelessWindowHint); // 取消窗口边框 显示主界面菜单栏
    bars.setWidth(800);
    bars.setHeight(600);

    bars.rowAxis()->setRange(0, 100);
    bars.columnAxis()->setRange(0, 100);
    QBar3DSeries *seriesBar = new QBar3DSeries;

    for(int j = 0;j < 100; j++)
    {
        QBarDataRow *dataBar = new QBarDataRow;
        for(float i = 0; i < 100; i+=1)
        {
            if(i >= 40 && i <=60){
                *dataBar << 50 + rand() % 10;
            }else{
                *dataBar << rand() % 30;
            }
        }
        seriesBar->dataProxy()->addRow(dataBar);
    }

    bars.addSeries(seriesBar);
    bars.show();

}
