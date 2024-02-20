#pragma once

#include <QlistWidget>
#include <QScrollArea>
#include <QStringList>
#include <QtWidgets/QWidget>
//#include "ui_QtTestXunlei.h"

class QtTestXunlei : public QWidget
{
    Q_OBJECT

public:
    QtTestXunlei(QWidget *parent = nullptr);
    ~QtTestXunlei();
private slots:
private:
    //Ui::QtTestXunleiClass ui;
    QListWidget* m_pListWidget = nullptr;
    QScrollArea* m_pScrollArea = nullptr;
    QStringList m_textList;
};
