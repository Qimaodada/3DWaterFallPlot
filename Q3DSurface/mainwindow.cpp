#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //旋转图形按住鼠标右键并移动鼠标    缩放使用鼠标滚轮

    // 创建一个3D表面对象
    surface.setFlags(surface.flags() ^ Qt::FramelessWindowHint); // 取消窗口边框 显示主界面菜单栏
    surface.setWidth(800);
    surface.setHeight(600);

    surface.axisX()->setTitle("X轴");
    surface.axisX()->setTitleVisible(true);
    surface.axisX()->setRange(0,100);
    surface.axisY()->setTitle("Y轴");
    surface.axisY()->setTitleVisible(true);
    surface.axisY()->setRange(0,100);
    surface.axisZ()->setTitle("Z轴");
    surface.axisZ()->setTitleVisible(true);
    surface.axisZ()->setRange(0,50);

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
    surface.addSeries(series);

    // 显示窗口
    surface.show();

}

MainWindow::~MainWindow()
{
    delete ui;
}
