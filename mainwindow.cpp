#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSslError>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{   
    ui->setupUi(this);
    setWindowState(Qt::WindowMaximized);

    ui->webView->page()->setLinkDelegationPolicy(QWebPage::DelegateExternalLinks);
    this->progress = new QProgressBar;
    ui->statusBar->addWidget(this->progress);
    ui->lineEdit->setText("https://www.baidu.com/");
    QObject::connect(ui->webView,SIGNAL(urlChanged(QUrl)),this,SLOT(setUrlSlot(QUrl)));
    QObject::connect(ui->webView,SIGNAL(titleChanged(QString)),this,SLOT(setTitleSlot(QString)));
    QObject::connect(ui->webView,SIGNAL(loadProgress(int)),this->progress,SLOT(setValue(int)));
    QObject::connect(ui->webView,SIGNAL(loadFinished(bool)),this,SLOT(deleteProgressBarSlot(bool)));
    QObject::connect(ui->lineEdit,SIGNAL(returnPressed()),this,SLOT(browserWebSlot()));
    QObject::connect(ui->forwardButton,SIGNAL(clicked()),this,SLOT(browserWebSlot()));
    QObject::connect(ui->webView,SIGNAL(linkClicked(QUrl)),this,SLOT(openNewWebSlot( QUrl )));



}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::setUrlSlot( QUrl url)
{
    qDebug()<<"setText";
    ui->lineEdit->setText(url.toString());
}
void MainWindow::setTitleSlot( QString title )
{
    this->setWindowTitle(title);
}

void MainWindow::browserWebSlot()
{
    qDebug()<<ui->lineEdit->text();
    ui->webView->load(QUrl(ui->lineEdit->text()));

}

void MainWindow::deleteProgressBarSlot(bool ok)
{
    if(ok)
    {
        delete this->progress;
        this->progress = NULL;
        this->ui->statusBar->showMessage("Load finished",5*1000);
    }
}

void MainWindow::openNewWebSlot( QUrl url )
{
    qDebug()<<url.toString();
    ui->webView->load(url);
}

void MainWindow::voidssss( )
{
    qDebug() << "handleSslErrors: ";



}
