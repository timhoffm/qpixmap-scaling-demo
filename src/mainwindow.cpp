#include "QHBoxLayout"

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "renderwidget.h"

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	QWidget *central = new QWidget();
	central->setLayout(new QHBoxLayout());
	central->layout()->addWidget(new RenderWidget());
	central->layout()->addWidget(new RenderWidget(true));
	setCentralWidget(central);
}

MainWindow::~MainWindow()
{
	delete ui;
}
