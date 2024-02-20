#pragma once
#include "CTitleBar.h"
#include <QtWidgets/QWidget>
#include <QPoint>

class MainWidget : public QWidget
{
    Q_OBJECT
        
public:
    MainWidget(QWidget *parent = nullptr);
    ~MainWidget();
public slots:
    void onClose();
private:
    void mouseMoveEvent(QMouseEvent* event) override;
    void mousePressEvent(QMouseEvent* event) override;
    
    //bool nativeEvent(const QByteArray& eventType, void* message, long* result) override;
private:
    void initUI();

    void paintEvent(QPaintEvent* event) override;
    CTitleBar* m_pTitleBar = nullptr;
private:
    QPoint diff_pos;//鼠标和窗口的相对位移
    QPoint mouse_pos;
    QPoint window_pos;
};
