#include "notebutton.h"
#include "ui_notebutton.h"

notebutton::notebutton(QWidget *parent)
    : QLabel(parent)
    , ui(new Ui::notebutton)
{
    ui->setupUi(this);
    this->setFixedSize(125, 50); //12 symbols
}

notebutton::~notebutton()
{
    delete ui;
}

