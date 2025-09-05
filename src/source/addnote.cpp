#include "addnote.h"
#include "ui_addnote.h"
#include <QDebug>
#include "notebutton.h"
addnote::addnote(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::addnote)
{
    ui->setupUi(this);
    this->setWindowTitle("NOTE INFO");
    group = new QButtonGroup(this);
    group->addButton(ui->low_button, 1);  // id = 1
    group->addButton(ui->med_button, 2);  // id = 2
    group->addButton(ui->high_button, 3);  // id = 3
    group->setExclusive(true); // строго одна кнопка может быть выбрана
}

addnote::~addnote()
{
    delete ui;
}


void addnote::on_save_note_button_clicked()
{
    QString shortText = ui->shorttxt_line->text();
    int id = group->checkedId();
    notebutton::Priority note_level = static_cast<notebutton::Priority>(id);
    emit ready_to_save(shortText , note_level , this);
}

