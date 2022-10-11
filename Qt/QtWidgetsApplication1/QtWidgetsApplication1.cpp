#include "QtWidgetsApplication1.h"
#include "MyOwnButton.h"


QtWidgetsApplication1::QtWidgetsApplication1(QWidget *parent)
    : QMainWindow(parent)
{
    //�����½�button�ķ���
    QPushButton* _btn_01 = new QPushButton;
    _btn_01->setText(" first button test... ");
    _btn_01->adjustSize();
    _btn_01->setParent(this);
    

    QPushButton* _btn_02 = new QPushButton("second button", this);
    
    //�׼�λ��
    _btn_01->move(0, 100);
    _btn_02->move(100, 0);
    ui.setupUi(this);

    //���ô��ڴ�С
    resize(600, 600);

    //���ô��ڵı���
    setWindowTitle(" first window's title...");

    //���ò�������Ĵ���
    setFixedSize(600, 600);

    //����һ��MyOwnButton���͵Ķ���
    MyOwnButton *_myBtn01 = new MyOwnButton(0);
    _myBtn01->setText("my own button");
    _myBtn01->move(150, 100);
    _myBtn01->adjustSize();
    _myBtn01->setParent(this);

    /*
    �з�Ӧ�İ�ť - �źŲ�
    ����1���źŷ�����
    ����2�����͵��źţ������ĵ�ַ��
    ����3�������źŵĶ���
    ����4�������źŵĲۺ����������ĵ�ַ��
    */
    connect(_myBtn01, &QPushButton::clicked, this, &QWidget::close);

}

QtWidgetsApplication1::~QtWidgetsApplication1()
{}
