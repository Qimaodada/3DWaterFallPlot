#include "my3dwfplot.h"

My3DWFPlot::My3DWFPlot(QObject *parent) : QObject(parent)
{
    m_p3DSurface = new Q3DSurface();
    m_widget3DContain = QWidget::createWindowContainer(m_p3DSurface);

    if(!m_p3DSurface->hasContext()){
        QMessageBox msgBox;
        msgBox.setText("Couldn't initialize the OpenGL context.");
        return ;
    }
    QSize screenSize = m_p3DSurface->screen()->size();
    m_widget3DContain->setMinimumSize(QSize(screenSize.width() / 2, screenSize.height() / 1.6));
    m_widget3DContain->setMaximumSize(screenSize);
    m_widget3DContain->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    m_widget3DContain->setFocusPolicy(Qt::StrongFocus);
}

My3DWFPlot::~My3DWFPlot()
{
    if(m_p3DSurface != nullptr){
        delete m_p3DSurface;
        m_p3DSurface = nullptr;
    }

}
