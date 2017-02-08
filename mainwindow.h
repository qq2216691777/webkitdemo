#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui>
#include <QMainWindow>
#include <QUrl>
#include <QtWebKit/QtWebKit>

#include <QProgressBar>

#include <QNetworkRequest>


#include <QDebug>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private slots:
    void setUrlSlot( QUrl );
    void browserWebSlot();
    void setTitleSlot( QString );
    void deleteProgressBarSlot(bool);
    void openNewWebSlot(QUrl);
    void voidssss( );

private:
    Ui::MainWindow *ui;
    QProgressBar *progress;
};

#endif // MAINWINDOW_H
