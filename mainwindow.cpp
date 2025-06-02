#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "DatabaseSolution/DatabaseClass.h"
#include <QMessageBox>
#include <QIcon>
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

void MainWindow::refreshCurrentView()
{
    // Determine which view is currently active and refresh it
    int currentListIndex = ui->lista_Widget->currentIndex();
    if (currentListIndex == 0) {
        // Personal contacts view is active
        on_persContatsWyswietl_Radio_released();
    } else if (currentListIndex == 1) {
        // Business contacts view is active
        on_buisContatsWyswietl_Radio_released();
    }
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

    db.addContact(contact);


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
    Database db;

    QMessageBox::information(this, "Sukces", "Dodano kontakt.");
}

void MainWindow::on_powrot_B2N_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);

}


void MainWindow::on_buttonimg_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
    refreshCurrentView();


}

void MainWindow::on_zobaczContacty_B2N_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
    ui->lista_Widget->setCurrentIndex(0);
    refreshCurrentView();
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
    refreshCurrentView();
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

            QWidget* buttonWidget = new QWidget();
            QHBoxLayout* buttonLayout = new QHBoxLayout(buttonWidget);
            buttonLayout->setContentsMargins(5, 2, 5, 2);
            buttonLayout->setSpacing(5);

            QPushButton* editBtn2 = new QPushButton("Edytuj");
            editBtn2->setStyleSheet("QPushButton {\n"
                                    "    background-color: rgb(142, 138, 255);\n"
                                    "    color: rgb(6, 6, 6);\n"
                                    "    font-family: 'e-Ukraine';\n"
                                    "    padding: 5px 10px;\n"
                                    "    border-radius: 5px;\n"
                                    "    border: none;\n"
                                    "}\n"
                                    "QPushButton:hover {\n"
                                    "    background-color: rgb(96, 93, 227);\n"
                                    "}\n"
                                    "QPushButton:pressed {\n"
                                    "    background-color: rgb(64, 62, 162);\n"
                                    "    color: rgb(255, 255, 255);\n"
                                    "}");
            editBtn2->setIcon(QIcon::fromTheme(QIcon::ThemeIcon::MailMessageNew));
            connect(editBtn2, &QPushButton::clicked, [this, i](){
                this->editContactBuiss(i);
            });

            // Dodaj przycisk usuwania
            QPushButton* usunBtn2 = new QPushButton("Usuń");
            usunBtn2->setStyleSheet("QPushButton {\n"
                                    "    background-color: rgb(245, 123, 93);\n"
                                    "    color: rgb(6, 6, 6);\n"
                                    "    font-family: 'e-Ukraine';\n"
                                    "    padding: 5px 10px;\n"
                                    "    border-radius: 5px;\n"
                                    "    border: none;\n"
                                    "}\n"
                                    "QPushButton:hover {\n"
                                    "    background-color: rgb(254, 167, 145);\n"
                                    "}\n"
                                    "QPushButton:pressed {\n"
                                    "    background-color: rgb(204, 95, 68);\n"
                                    "    color: rgb(255, 255, 255);\n"
                                    "}");
            usunBtn2->setIcon(QIcon::fromTheme(QIcon::ThemeIcon::EditDelete));
            // POPRAWKA: Połącz przycisk usuń z odpowiednią funkcją
            connect(usunBtn2, &QPushButton::clicked, [this, i](){
                Database db;
                db.load_from_file("contacts.txt");
                db.removeContact(1, i);
                db.save_to_file(); // Zapisz zmiany
                // Odśwież widok tabeli
refreshCurrentView();
            });

            // Dodaj przyciski do layoutu
            buttonLayout->addWidget(editBtn2);
            buttonLayout->addWidget(usunBtn2);

            // Ustaw widget w komórce tabeli
            ui->wyswietlBuiss_tableWidget->setCellWidget(i, 3, buttonWidget);}

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

            ui->wyswietlPers_tableWidget->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(last)));
            ui->wyswietlPers_tableWidget->setItem(i, 1, new QTableWidgetItem(QString::fromStdString(name)));
            ui->wyswietlPers_tableWidget->setItem(i, 2, new QTableWidgetItem(QString::fromStdString(phone)));

            QWidget* buttonWidget = new QWidget();
            QHBoxLayout* buttonLayout = new QHBoxLayout(buttonWidget);
            buttonLayout->setContentsMargins(5, 2, 5, 2);
            buttonLayout->setSpacing(5);

            QPushButton* editBtn = new QPushButton("Edytuj");
            editBtn->setStyleSheet("QPushButton {\n"
                                    "    background-color: rgb(142, 138, 255);\n"
                                    "    color: rgb(6, 6, 6);\n"
                                    "    font-family: 'e-Ukraine';\n"
                                    "    padding: 5px 10px;\n"
                                    "    border-radius: 5px;\n"
                                    "    border: none;\n"
                                    "}\n"
                                    "QPushButton:hover {\n"
                                    "    background-color: rgb(96, 93, 227);\n"
                                    "}\n"
                                    "QPushButton:pressed {\n"
                                    "    background-color: rgb(64, 62, 162);\n"
                                    "    color: rgb(255, 255, 255);\n"
                                    "}");
            editBtn->setIcon(QIcon::fromTheme(QIcon::ThemeIcon::MailMessageNew));
            connect(editBtn, &QPushButton::clicked, [this, i](){
                this->editContact(i);
            });

            // przycisk usuwania
            QPushButton* usunBtn = new QPushButton("Usuń");
            usunBtn->setStyleSheet("QPushButton {\n"
                                    "    background-color: rgb(245, 123, 93);\n"
                                    "    color: rgb(6, 6, 6);\n"
                                    "    font-family: 'e-Ukraine';\n"
                                    "    padding: 5px 10px;\n"
                                    "    border-radius: 5px;\n"
                                    "    border: none;\n"
                                    "}\n"
                                    "QPushButton:hover {\n"
                                    "    background-color: rgb(254, 167, 145);\n"
                                    "}\n"
                                    "QPushButton:pressed {\n"
                                    "    background-color: rgb(204, 95, 68);\n"
                                    "    color: rgb(255, 255, 255);\n"
                                    "}");
            usunBtn->setIcon(QIcon::fromTheme(QIcon::ThemeIcon::EditDelete));

            connect(usunBtn, &QPushButton::clicked, [this, i](){
                Database db;
                db.load_from_file("contacts.txt");
                db.removeContact(0, i);
                db.save_to_file(); // Zapisz zmiany
                // Odśwież widok tabeli
                refreshCurrentView();
            });

            // Dodaj przyciski do layoutu
            buttonLayout->addWidget(editBtn);
            buttonLayout->addWidget(usunBtn);

            // Ustaw widget w komórce tabeli
            ui->wyswietlPers_tableWidget->setCellWidget(i, 3, buttonWidget);}


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
void MainWindow::on_buttonimg_3_clicked()
{
    Database db;
    db.load_from_file("contacts.txt");

    QString first_name=ui->imieInput_7->text();
    db.private_contacts[currentEditingContactIndex].setFirstName(first_name.toStdString());

    QString last_name=ui->nazwiskoInput_6->text();
    db.private_contacts[currentEditingContactIndex].setLastName(last_name.toStdString());

    QString company=ui->company_Input->text();
    db.private_contacts[currentEditingContactIndex].setCompanyName(company.toStdString());

    QString nrTel=ui->nrTelInput_6->text();
    db.private_contacts[currentEditingContactIndex].setPhoneNumber(nrTel.toStdString());

    QString email=ui->emailInput_6->text();
    db.private_contacts[currentEditingContactIndex].setEmail(email.toStdString());

    db.save_to_file();
    ui->stackedWidget->setCurrentIndex(2);
    refreshCurrentView();
   // ui->stackedWidget->setCurrentIndex(2);
   // ui->lista_Widget->setCurrentIndex(1);
    //on_buisContatsWyswietl_Radio_released();
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
    ui->stackedWidget->setCurrentIndex(2);
    refreshCurrentView();

}
void MainWindow::editContactBuiss(int i){
    Database db;
    db.load_from_file("contacts.txt");

    ui->stackedWidget->setCurrentIndex(4);

    currentEditingContactIndex = i;

    PrivateContact& contact = db.private_contacts[i];

    ui->imieInput_7->setText(QString::fromStdString(contact.getFirstName()));
    ui->nazwiskoInput_6->setText(QString::fromStdString(contact.getLastName()));
    ui->companyInput->setText(QString::fromStdString(contact.getCompanyName()));
    ui->nrTelInput_6->setText(QString::fromStdString(contact.getPhoneNumber()));
    ui->emailInput_6->setText(QString::fromStdString(contact.getEmail()));


    connect(ui->buttonimg_3, &QPushButton::clicked, [this, i](){
        QString currentEditingContactType = "business"; // "personal" lub "business"
        this->on_buttonimg_3_clicked();
    });
    db.save_to_file();



}
void MainWindow::editContact(int index)
{
    Database db;
    db.load_from_file("contacts.txt");

    ui->stackedWidget->setCurrentIndex(3);

    currentEditingContactIndex = index;

    PersonalContact& contact = db.personal_contacts[index];

    ui->imieInput_5->setText(QString::fromStdString(contact.getFirstName()));
    ui->nazwiskoInput_4->setText(QString::fromStdString(contact.getLastName()));
    ui->nickInput_3->setText(QString::fromStdString(contact.getNickname()));
    ui->nrTelInput_4->setText(QString::fromStdString(contact.getPhoneNumber()));
    ui->emailInput_4->setText(QString::fromStdString(contact.getEmail()));
    ui->urodzinyInput->setText(QString::fromStdString(contact.getBirthday()));


    connect(ui->buttonimg_2, &QPushButton::clicked, [this, index](){
        QString currentEditingContactType = "personal"; // "personal" lub "business"
        this->on_buttonimg_2_clicked();
    });
    db.save_to_file();

}

void MainWindow::on_powrotLista_B2N_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
    on_persContatsWyswietl_Radio_released();
    on_buisContatsWyswietl_Radio_released();
}
