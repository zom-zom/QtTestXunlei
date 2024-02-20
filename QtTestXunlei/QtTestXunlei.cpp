#include "QtTestXunlei.h"
#include <QHBoxLayout>
#include <string>
using namespace std;
QtTestXunlei::QtTestXunlei(QWidget *parent)
    : QWidget(parent)
{
    setFixedSize(150 + 1000 + 30, 900);

    m_pListWidget = new QListWidget(this);
    m_pListWidget->setFixedWidth(150);
    m_pScrollArea = new QScrollArea(this);
    m_pScrollArea->setFixedWidth(1000 + 30);


    QHBoxLayout* hlay = new QHBoxLayout(this);
    hlay->addWidget(m_pListWidget);
    hlay->addWidget(m_pScrollArea);
    m_textList << u8"基本设置" << u8"云盘设置" << u8"下载设置" << u8"接管设置" << u8"任务管理" << u8"题型" << u8"悬浮窗" << u8"高级设置";
    m_pListWidget->addItems(m_textList);

    string lw_qss = R"(
        QListWidget
        {
            /*border:1px solid gray;*/
            background:rgb(26,26,26);
            color:rgb(200,200,200);
            font-size:15px;
            border-radius:1px;
        }

        QListWidget::item
        {
            height:40px;
            /*padding-left:10px;*/
        }
        
        QListWidget::item:!active
        {
            background:rgb(26,26,26);
            margin:5px 20px 1px 20px;
        }
        
        QListWidget::item:hover
        {
            background:rgb(56,56,56);
            /*padding-left:30px;*/
        }

        QListWidget::item:selected
        {
            border-radius:12px;
            background:lightblue;
            color:rgb(100,100,255);
        }

        QListWidget::item:selected:!active
        {
            background:rgb(51,51,51);
            color:#3F85FF;
        )";
    m_pListWidget->setStyleSheet(QString::fromStdString(lw_qss));
    this->setStyleSheet("background-color:rgb(26,26,26)");
    m_pListWidget->setFrameShape(QFrame::NoFrame);
    m_pListWidget->setFocusPolicy(Qt::NoFocus);




}

QtTestXunlei::~QtTestXunlei()
{}
