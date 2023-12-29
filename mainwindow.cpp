
#include "entidad.h"
#include "mainwindow.h"
#include "ordinaria.h"
#include "plazofijo.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    c=admin.getCuenta(0);
    ui->rOrdinaria->setChecked(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_4_clicked()
{
    ui->lista1->setText(admin.getListString());
}


void MainWindow::on_pushButton_5_clicked()
{
    ui->list2BySaldo->setText(admin.getListBySaldo(ui->editSaldoF->text().toInt()));
}


void MainWindow::on_pushButton_8_clicked()
{
    ui->tiposCuenta->setText(admin.getCantidadCuentas());
}


void MainWindow::on_pushButton_9_clicked()
{
    ui->mayorInteres->setText(admin.nameMayorPlazoFijo());
}


void MainWindow::on_pushButton_6_clicked()
{ui->mayorSaldo->setText(admin.getCuenta(admin.posMayorSaldo())->getName());
}


void MainWindow::on_rOrdinaria_clicked()
{
    ui->label_5->hide();
        ui->label_6->hide();
        ui->direcPeriodo->hide();
        ui->spinIngreso->hide();
}


void MainWindow::on_rPlazoFijo_clicked()
{
        ui->label_5->show();
        ui->label_5->setText("Periodo Ingreso");
        ui->label_6->show();
        ui->direcPeriodo->show();
        ui->spinIngreso->show();
}


void MainWindow::on_rEntidad_clicked()
{
        ui->label_5->show();
        ui->label_5->setText("Direccion");
        ui->label_6->hide();
        ui->direcPeriodo->show();
        ui->spinIngreso->hide();
}


void MainWindow::on_pushButton_2_clicked()
{
        if(ui->rOrdinaria->isChecked()){
            admin.addAccount(new Ordinaria(ui->name->text(),
                                           ui->id->text(),
                                           ui->spinBox_2->text().toInt()));
        }
        else if(ui->rPlazoFijo->isChecked()){
            admin.addAccount(new PlazoFijo(ui->name->text(),
                                           ui->id->text(),
                                           ui->spinBox_2->text().toInt(),
                                           ui->direcPeriodo->text(),
                                           ui->spinIngreso->text().toInt()));
        }else if(ui->rEntidad->isChecked()){
            admin.addAccount(new Entidad(ui->name->text(),
                                           ui->id->text(),
                                           ui->spinBox_2->text().toInt(),
                                           ui->direcPeriodo->text()));
        }
}


void MainWindow::on_pushButton_clicked()
{
        if(admin.getAccountbyId(ui->lineID->text())!=-1){
            ui->labelState->setText("Seleccionado");
            this->c=admin.getCuenta(admin.getAccountbyId(ui->lineID->text()));
        }else{
            ui->labelState->setText("No se encontro");
        }

}


void MainWindow::on_pushButton_3_clicked()
{
        if(ui->rExtraer->isChecked()){
            c->withdraw(ui->spinAmmount->text().toInt());
        }else if(ui->rDepositar->isChecked()){
            c->deposit(ui->spinAmmount->text().toInt());
        }
}


void MainWindow::on_pushButton_7_clicked()
{
        ui->historylabel->setText(c->getHistory());
}

