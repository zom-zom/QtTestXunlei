#pragma once
#include <QWidget>
#include <QLabel>
#include <QPushButton>



class CTitleBar :public QWidget
{
	friend class MainWidget;
	Q_OBJECT
		
public:
	CTitleBar(QWidget* p = nullptr);
	~CTitleBar();

private:
	void initUI();//初始化界面
private slots:
	void onClicked();
signals:
	void sig_close();
private:
	void mouseDoubleClickEvent(QMouseEvent* event) override;
public:

private:
	QLabel* m_pLogo;
	QLabel* m_titleTextLabel;
	QPushButton* m_pCloseBtn;
	QPushButton* m_pSetBtn;
	QPushButton* m_pMinBtn;
	QPushButton* m_pMaxBtn;
};

