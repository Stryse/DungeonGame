#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

//This class is managing different windows that appear in viewport
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    //CTOR
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

private slots:

    //Displays window in viewport
    void changeWindow(QWidget* window);

};
#endif // MAINWINDOW_H
