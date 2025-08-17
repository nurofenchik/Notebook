#include "addnote.h"
#include "ui_addnote.h"
#include <QDebug>
addnote::addnote(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::addnote)
{
    ui->setupUi(this);
}

addnote::~addnote()
{
    delete ui;
}


void addnote::on_save_note_button_clicked()
{
    QString shortText = ui->shorttxt_line->text();
    QString fullText = ui->fulltxt_line->text();
    emit ready_to_save(shortText , fullText , this);
}

