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
    ui->starterWidget->setCurrentIndex(1);
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
    db.load_from_file("contacts.txt");
    string first_name=ui->imieBuiss_Input->text().toStdString();
    string last_name=ui->nazwiskoBuiss_Input->text().toStdString();
    string company=ui->companyInput->text().toStdString();
    string nrTel=ui->nrTelBuiss_Input->text().toStdString();
    string email=ui->emailBuiss_Input->text().toStdString();
    PrivateContact contact(first_name, last_name, nrTel, email, company);
    db.addContact(contact);
    db.save_to_file();

    ui->imieBuiss_Input->clear();
    ui->nazwiskoBuiss_Input->clear();
    ui->companyInput->clear();
    ui->nrTelBuiss_Input->clear();
    ui->emailBuiss_Input->clear();
    QMessageBox::information(this, "Sukces", "Dodano biznesowy kontakt.");
    db.save_to_file();

}
void MainWindow::on_utworzPers_B2n_clicked()
{
    Database db;
    db.load_from_file("contacts.txt");
    QString first_name=ui->imiePers_Input->text();
    QString last_name=ui->nazwiskoPers_Input->text();
    QString nickname=ui->nickPers_Input->text();
    QString nrTel=ui->nrTelPers_Input->text();
    QString email=ui->emailPers_Input->text();
    QString uroziny=ui->urodzinyInput->text();

    PersonalContact contact(first_name.toStdString(), last_name.toStdString(), nrTel.toStdString(), email.toStdString(), uroziny.toStdString(), nickname.toStdString());
    PersonalContact perskont("James", "bond", "99999", "mail@bond", "03/03/03", "bodzio");
    db.addContact(contact);
    db.addContact(perskont);

    db.save_to_file();

    ui->imiePers_Input->clear();
    ui->nazwiskoPers_Input->clear();
    ui->nickPers_Input->clear();
    ui->nrTelPers_Input->clear();
    ui->emailPers_Input->clear();
    ui->urodzinyInput->clear();
    QMessageBox::information(this, "Sukces", "Dodano personalny kontakt.");

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
  /*  ui->wyswietlPers_listWidget->clear();
    db.load_from_file("contacts.txt");
    for(int i=0; i<db.personal_contacts.size(); i++){
        string name = db.personal_contacts[i].getFirstName();
        string last = db.personal_contacts[i].getLastName();
        string nick = db.personal_contacts[i].getNickname();
        string bd = db.personal_contacts[i].getBirthday();
        string phone = db.personal_contacts[i].getPhoneNumber();
        ui->wyswietlPers_listWidget->addItem(QString::fromStdString(name));
        ui->wyswietlPers_listWidget->addItem(QString::fromStdString(last));
        ui->wyswietlPers_listWidget->addItem(QString::fromStdString(nick));
        ui->wyswietlPers_listWidget->addItem(QString::fromStdString(bd));
        ui->wyswietlPers_listWidget->addItem(QString::fromStdString(phone));
    }*/
       // ui->label_2->setText(QString::fromStdString(last));
       // ui->label_3->setText(QString::fromStdString(nick));
       // ui->label_4->setText(QString::fromStdString(bd));
       // ui->label_5->setText(QString::fromStdString(phone));
       // db.displayContacts();



void MainWindow::on_powrotLista_B2N_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);

}




void MainWindow::on_buttonimg_2_clicked()
{
    Database db;
    db.load_from_file("contacts.txt");

    QString first_name=ui->imieInput_5->text();
    db.personal_contacts[currentEditingContactIndex].setFirstName(first_name.toStdString());

    QString last_name=ui->nazwiskoInput_4->text();
    db.personal_contacts[currentEditingContactIndex].setLastName(last_name.toStdString());

    QString nickname=ui->nickInput_3->text();
    db.personal_contacts[currentEditingContactIndex].setNickname(nickname.toStdString());

    QString nrTel=ui->nrTelInput_4->text();
    db.personal_contacts[currentEditingContactIndex].setPhoneNumber(nrTel.toStdString());

    QString email=ui->emailInput_4->text();
    db.personal_contacts[currentEditingContactIndex].setEmail(email.toStdString());

    QString uroziny=ui->urodzinyInput->text();
    db.personal_contacts[currentEditingContactIndex].setBirthday(uroziny.toStdString());
    db.save_to_file();
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


/*void MainWindow::on_persContatsWyswietl_Radio_released()
{
    Database db;

    ui->wyswietlPers_listWidget->clear();
    ui->lista_Widget->setCurrentIndex(0);

    for(int i=0; i<db.personal_contacts.size(); i++){
        string name = db.personal_contacts[i].getFirstName();
        string last = db.personal_contacts[i].getLastName();
        string nick = db.personal_contacts[i].getNickname();
        string bd = db.personal_contacts[i].getBirthday();
        string phone = db.personal_contacts[i].getPhoneNumber();
        ui->wyswietlPers_listWidget->addItem(QString::fromStdString(name));
        ui->wyswietlPers_listWidget->addItem(QString::fromStdString(last));
        ui->wyswietlPers_listWidget->addItem(QString::fromStdString(nick));
        ui->wyswietlPers_listWidget->addItem(QString::fromStdString(bd));
        ui->wyswietlPers_listWidget->addItem(QString::fromStdString(phone));}
}

*/





void MainWindow::on_buisContatsWyswietl_Radio_released()
{
    Database db;
    db.load_from_file("contacts.txt");
    ui->lista_Widget->setCurrentIndex(1);

    // Ustaw nagłówki kolumn
    ui->wyswietlBuiss_tableWidget->setColumnCount(4);
    QStringList headers;
    headers << "Nazwisko" << "Imię" << "Telefon" << "Akcje";
    ui->wyswietlBuiss_tableWidget->setHorizontalHeaderLabels(headers);

    // Ustaw liczbę wierszy
    ui->wyswietlBuiss_tableWidget->setRowCount(db.private_contacts.size());

    for(int i = 0; i < db.private_contacts.size(); i++){
        string name = db.private_contacts[i].getFirstName();
        string last = db.private_contacts[i].getLastName();
        string phone = db.private_contacts[i].getPhoneNumber();

        // Dodaj dane do komórek
        ui->wyswietlBuiss_tableWidget->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(last)));
        ui->wyswietlBuiss_tableWidget->setItem(i, 1, new QTableWidgetItem(QString::fromStdString(name)));
        ui->wyswietlBuiss_tableWidget->setItem(i, 2, new QTableWidgetItem(QString::fromStdString(phone)));

        // Dodaj przycisk edycji
        QPushButton* editBtn = new QPushButton("Edytuj");
        connect(editBtn, &QPushButton::clicked, [this, i](){
            this->editContact(i);
        });
        ui->wyswietlBuiss_tableWidget->setCellWidget(i, 3, editBtn);
    }

    // Dostosuj szerokość kolumn
    ui->wyswietlBuiss_tableWidget->resizeColumnsToContents();
    ui->wyswietlBuiss_tableWidget->horizontalHeader()->setStretchLastSection(false);
    db.save_to_file();

}


void MainWindow::on_persContatsWyswietl_Radio_released()
{
        Database db;
        db.load_from_file("contacts.txt");

        ui->wyswietlPers_tableWidget->clear();
        ui->lista_Widget->setCurrentIndex(0);


        // Ustaw nagłówki kolumn
        ui->wyswietlPers_tableWidget->setColumnCount(4);
        QStringList headers;
        headers << "Nazwisko" << "Imię" << "Telefon" << "Akcje";
        ui->wyswietlPers_tableWidget->setHorizontalHeaderLabels(headers);

        // Ustaw liczbę wierszy
        ui->wyswietlPers_tableWidget->setRowCount(db.personal_contacts.size());

        for(int i = 0; i < db.personal_contacts.size(); i++){
            string name = db.personal_contacts[i].getFirstName();
            string last = db.personal_contacts[i].getLastName();
            string phone = db.personal_contacts[i].getPhoneNumber();

            // Dodaj dane do komórek
            ui->wyswietlPers_tableWidget->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(last)));
            ui->wyswietlPers_tableWidget->setItem(i, 1, new QTableWidgetItem(QString::fromStdString(name)));
            ui->wyswietlPers_tableWidget->setItem(i, 2, new QTableWidgetItem(QString::fromStdString(phone)));

            // Dodaj przycisk edycji
            QPushButton* editBtn = new QPushButton("Edytuj");
            connect(editBtn, &QPushButton::clicked, [this, i](){
                this->editContact(i);
            });
            ui->wyswietlPers_tableWidget->setCellWidget(i, 3, editBtn);
        }

        // Dostosuj szerokość kolumn
        ui->wyswietlPers_tableWidget->resizeColumnsToContents();
        ui->wyswietlPers_tableWidget->horizontalHeader()->setStretchLastSection(false);
        db.save_to_file();

}


/*void MainWindow::on_buisContatsWyswietl_Radio_released()
{
    Database db;
    db.load_from_file("contacts.txt");

    ui->wyswietlPers_listWidget->clear();
    ui->lista_Widget->setCurrentIndex(0);

    for(int i = 0; i < db.private_contacts.size(); i++){
        string name = db.private_contacts[i].getFirstName();
        string last = db.private_contacts[i].getLastName();
        string phone = db.private_contacts[i].getPhoneNumber();

        // Formatowanie tekstu z odpowiednimi odstępami
        QString contactInfo = QString("%1 %2").arg(QString::fromStdString(last), -15)
                                  .arg(QString::fromStdString(name), -15) +
                              QString::fromStdString(phone);

        ui->wyswietlPers_listWidget->addItem(contactInfo);
    }
    ui->contactsTableWidget->resizeColumnsToContents();
    ui->contactsTableWidget->horizontalHeader()->setStretchLastSection(false);
}

*/
void MainWindow::editContact(int index)
{
    Database db;
    db.load_from_file("contacts.txt");

    ui->stackedWidget->setCurrentIndex(3);


    PersonalContact& contact = db.personal_contacts[index];

    ui->imieInput_5->setText(QString::fromStdString(contact.getFirstName()));
    ui->nazwiskoInput_4->setText(QString::fromStdString(contact.getLastName()));
    ui->nickInput_3->setText(QString::fromStdString(contact.getNickname()));
    ui->nrTelInput_4->setText(QString::fromStdString(contact.getPhoneNumber()));
    ui->emailInput_4->setText(QString::fromStdString(contact.getEmail()));
    ui->urodzinyInput->setText(QString::fromStdString(contact.getBirthday()));


    connect(ui->buttonimg_2, &QPushButton::clicked, [this, index](){
        int currentEditingContactIndex = index;
        QString currentEditingContactType = "personal"; // "personal" lub "business"
        this->on_buttonimg_2_clicked();
    });
    db.save_to_file();
   // ui->wyswietlBuiss_tableWidget->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(last)));
   // ui->wyswietlBuiss_tableWidget->setItem(i, 1, new QTableWidgetItem(QString::fromStdString(name)));
   // ui->wyswietlBuiss_tableWidget->setItem(i, 2, new QTableWidgetItem(QString::fromStdString(phone)));

}
