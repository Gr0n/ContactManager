#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "DatabaseSolution/DatabaseClass.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
    ui->starterWidget->setCurrentIndex(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}






void MainWindow::on_personalny_Radio_released()
{
    ui->starterWidget->setCurrentIndex(1);
}


void MainWindow::on_biznesowy_Radio_released()
{
    ui->starterWidget->setCurrentIndex(2);
}


void MainWindow::on_utworzBuiss_B2N_clicked()
{
    Database db;
    string first_name=ui->imieBuiss_Input->text().toStdString();
    string last_name=ui->nazwiskoBuiss_Input->text().toStdString();
    string company=ui->companyInput->text().toStdString();
    string nrTel=ui->nrTelBuiss_Input->text().toStdString();
    string email=ui->emailBuiss_Input->text().toStdString();
    PrivateContact contact(first_name, last_name, nrTel, email, company);
    db.addContact(contact);

    ui->imieBuiss_Input->clear();
    ui->nazwiskoBuiss_Input->clear();
    ui->companyInput->clear();
    ui->nrTelBuiss_Input->clear();
    ui->emailBuiss_Input->clear();
    QMessageBox::information(this, "Sukces", "Dodano kontakt.");
}
void MainWindow::on_utworzPers_B2n_clicked()
{
    Database db;
    QString first_name=ui->imiePers_Input->text();
    QString last_name=ui->nazwiskoPers_Input->text();
    QString nickname=ui->nickPers_Input->text();
    QString nrTel=ui->nrTelPers_Input->text();
    QString email=ui->emailPers_Input->text();
    QString uroziny=ui->urodzinyInput->text();

    PersonalContact contact(first_name.toStdString(), last_name.toStdString(), nrTel.toStdString(), email.toStdString(), uroziny.toStdString(), nickname.toStdString());
    db.addContact(contact);
    ui->imiePers_Input->clear();
    ui->nazwiskoPers_Input->clear();
    ui->nickPers_Input->clear();
    ui->nrTelPers_Input->clear();
    ui->emailPers_Input->clear();
    ui->urodzinyInput->clear();
    QMessageBox::information(this, "Sukces", "Dodano kontakt.");

}
void MainWindow::on_utworzContact_B2N_clicked()
{
    Database db;/*
    string first_name=ui->imieContact_Input->text().toStdString();
    string last_name=ui->nazwiskoContact_Input->text().toStdString();
    string nrTel=ui->nrTelContact_Input->text().toStdString();
    string email=ui->emailContact_Input->text().toStdString();
    Contact contact(first_name, last_name, nrTel, email);
    db.addContact(&contact);

    ui->imieContact_Input->clear();
    ui->nazwiskoContact_Input->clear();
    ui->nrTelContact_Input->clear();
    ui->emailContact_Input->clear();*/
    QMessageBox::information(this, "Sukces", "Dodano kontakt.");
}

void MainWindow::on_powrot_B2N_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);

}


void MainWindow::on_buttonimg_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);

}

void MainWindow::on_zobaczContacty_B2N_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);

}


void MainWindow::on_powrotLista_B2N_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);

}




void MainWindow::on_buttonimg_2_clicked()
{
    QString first_name=ui->imieInput_5->text();

}
/////////////////////////////////////////////////////

void MainWindow::on_nowyContact_B2N_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);

}



void MainWindow::on_powrotMain_B2N_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

