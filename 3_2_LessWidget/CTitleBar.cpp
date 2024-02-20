#include "CTitleBar.h"
#include "MainWidget.h"
#include <QHBoxLayout>
#include <QMessageBox>

CTitleBar::CTitleBar(QWidget* p /*= nullptr*/)
{
	initUI();
}

CTitleBar::~CTitleBar()
{

}

//************************************
// Method:    initUI
// FullName:  CTitleBar::initUI
// Access:    private 
// Returns:   void
// Qualifier:
//************************************
void CTitleBar::initUI()
{
	//禁止父窗口影响子窗口样式
	setAttribute(Qt::WA_StyledBackground);
	this->setFixedHeight(32 + 5 * 2);
	this->setStyleSheet("background-color:rgb(54,54,54)");

	m_pLogo = new QLabel(this);
	//m_pLogo->setText(u8"hello");
	m_pLogo->setFixedWidth(32);
	m_pLogo->setStyleSheet("background-image:url(:/MainWidget/resource/titlebar/title_icon.png);border:none");

	m_titleTextLabel = new QLabel(this);
	m_titleTextLabel->setText(u8"我是标题");
	m_titleTextLabel->setFixedWidth(120);

	m_pSetBtn = new QPushButton(this);
	m_pSetBtn->setFixedSize(32, 32);
	m_pSetBtn->setStyleSheet("background-image:url(:/MainWidget/resource/titlebar/set.svg);border:none");


	m_pMinBtn = new QPushButton(this);
	m_pMinBtn->setFixedSize(32, 32);
	m_pMinBtn->setStyleSheet("background-image:url(:/MainWidget/resource/titlebar/min.svg);border:none");


	m_pMaxBtn = new QPushButton(this);
	m_pMaxBtn->setFixedSize(32, 32);
	m_pMaxBtn->setStyleSheet("background-image:url(:/MainWidget/resource/titlebar/max.svg);border:none");


	m_pCloseBtn = new QPushButton(this);
	m_pCloseBtn->setFixedSize(32, 32);
	m_pCloseBtn->setStyleSheet("background-image:url(:/MainWidget/resource/titlebar/close.svg);border:none");


	QHBoxLayout* pHlay = new QHBoxLayout(this);
	pHlay->addWidget(m_pLogo);
	pHlay->addWidget(m_titleTextLabel);
	pHlay->addStretch();
	pHlay->addWidget(m_pSetBtn);
	pHlay->addWidget(m_pMinBtn);
	pHlay->addWidget(m_pMaxBtn);
	pHlay->addWidget(m_pCloseBtn);
	pHlay->setContentsMargins(5, 5, 5, 5);

	connect(m_pMinBtn, &QPushButton::clicked, this, &CTitleBar::onClicked);
	connect(m_pMaxBtn, &QPushButton::clicked, this, &CTitleBar::onClicked);
	connect(m_pCloseBtn, &QPushButton::clicked, this, &CTitleBar::onClicked);

}

void CTitleBar::onClicked()
{
	QPushButton* pButton = qobject_cast<QPushButton*>(sender());
	QWidget* pWindow = this->window();
	if (pButton == m_pMinBtn)
	{
		pWindow->showMinimized();
	}
	else if (pButton == m_pMaxBtn)
	{
		if (pWindow->isMaximized())
		{
			pWindow->showNormal();
		}
		else
		{
			pWindow->showMaximized();
		}
	}
	else if (pButton == m_pCloseBtn)
	{
		//pWindow->close();
		//MainWidget* p1 = new MainWidget;
		//connect(this, SIGNAL(sig_close()), p1, SLOT(onClose()));
		emit sig_close();
	}

}


void CTitleBar::mouseDoubleClickEvent(QMouseEvent* event)
{
	m_pMaxBtn->click();
}
