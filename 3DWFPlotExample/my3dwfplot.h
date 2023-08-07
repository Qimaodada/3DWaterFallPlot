#ifndef MY3DWFPLOT_H
#define MY3DWFPLOT_H

#include <QWidget>
#include "surfacegraph.h"

#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMessageBox>
#include <QtGui/QPainter>
#include <QtGui/QScreen>

class My3DWFPlot : public QObject
{
    Q_OBJECT
public:
    explicit My3DWFPlot(QObject *parent = nullptr);
    ~My3DWFPlot();

    QWidget* m_widget3DContain;
private:
    Q3DSurface *m_p3DSurface;

signals:

};

#endif // MY3DWFPLOT_H
