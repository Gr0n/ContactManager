#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_buttonimg_clicked();

    void on_buttonimg_2_clicked();

    void on_nowyContact_B2N_clicked();

    void on_zobaczContacty_B2N_clicked();

    void on_utworzBuiss_B2N_clicked();

    void on_utworzContact_B2N_clicked();

    void on_utworzPers_B2n_clicked();

    void on_powrot_B2N_clicked();

    void on_powrotLista_B2N_clicked();

    void on_powrotMain_B2N_clicked();

    void on_personalny_Radio_released();

    void on_biznesowy_Radio_released();


private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
