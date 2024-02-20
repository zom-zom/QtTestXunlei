#include "MainWidget.h"

#include <QVBoxLayout>
#include <QMouseEvent>
#include <QMessageBox>
#include <QPainter>
#include <QRect>



MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
{
    this->setAttribute(Qt::WA_TranslucentBackground);
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowMinMaxButtonsHint);
    //this->setAttribute(Qt::WA_Hover);//很重要
    initUI();
	//MainWidget* p1 = new MainWidget;
    connect(m_pTitleBar, SIGNAL(sig_close()), this, SLOT(onClose()));
}

MainWidget::~MainWidget()
{}

void MainWidget::onClose()
{
	QMessageBox::StandardButton _exit = QMessageBox::warning(this, u8"提示", u8"确定要退出吗",
		QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
	if (_exit == QMessageBox::Yes)
	{
		this->close();
	}
}

void MainWidget::mouseMoveEvent(QMouseEvent* event)
{
    QPoint pos = event->globalPos();
    this->move(pos-diff_pos);
}

void MainWidget::mousePressEvent(QMouseEvent* event)
{
    mouse_pos = event->globalPos();
    window_pos = this->pos();
    diff_pos = mouse_pos - window_pos;
}


//bool MainWidget::nativeEvent(const QByteArray& eventType, void* message, long* result)
//{
//    return true;
//}

void MainWidget::initUI()
{
	
    m_pTitleBar = new CTitleBar(this);
    QWidget* w = new QWidget(this);
	w->setMinimumSize(800, 600);
    QVBoxLayout* pVlay = new QVBoxLayout(this);
    pVlay->addWidget(m_pTitleBar);
    pVlay->addWidget(w);
    pVlay->setContentsMargins(0, 0, 0, 0);
}

void MainWidget::paintEvent(QPaintEvent* event)
{
    QPainter painter(this);
	painter.setRenderHint(QPainter::Antialiasing);
	painter.setBrush(QBrush(QColor(255, 255, 255)));
	painter.setPen(Qt::transparent);
    QRect rect = this->rect();
    painter.drawRoundedRect(rect, 15, 15);//设置窗口圆角
}

