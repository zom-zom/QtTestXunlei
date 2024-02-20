#include "CBaseSetWidget.h"
#include <QHBoxLAyout>
#include <QVBoxLAyout>
#include <QCheckBox>
#include <QLabel>
#include <QLineEdit>
#include <QRadioButton>
#include <QPushButton>

CBaseSetWidget::CBaseSetWidget(QWidget* parent)
	:QWidget(parent)
{
	QLabel* pBasesetLabel = new QLabel(this);
	pBasesetLabel->setText(u8"基本设置");

	QCheckBox* pCheckKaijiqidong = new QCheckBox(this);
	pCheckKaijiqidong->setText(u8"开机启动");
	QCheckBox* pCheckMiandarao;
	QLabel* p1;

	QCheckBox* pCheckBosskey;
	QLineEdit* pLineEdit;
	QLabel* p2;
	QCheckBox* pCheckNewShowMainUI;

	QLabel* pXiazaimoshi;
	QRadioButton* pQuansuxiazai;
	QRadioButton* pJisuxiazai;
	QPushButton* pBtnModify;
} 

CBaseSetWidget::~CBaseSetWidget()
{

}

