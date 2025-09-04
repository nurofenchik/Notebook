#include "notebutton.h"
#include "ui_notebutton.h"

notebutton::notebutton(QWidget *parent)
    : QLabel(parent)
    , ui(new Ui::notebutton)
{
    ui->setupUi(this);
    this->setFixedSize(125, 50);
}

notebutton::~notebutton()
{
    delete ui;
}

void notebutton::SetLabelText(const QString &ShortText)
{
    ui->note_label->setText(ShortText);
}

void notebutton::SetNoteColor(Priority priority)
{
    QString color;

    switch(priority) {
    case LOW:    color = "#4caf50"; break;  // зелёный
    case MEDIUM: color = "#ffb74d"; break;  // оранжевый
    case HIGH:   color = "#e53935"; break;  // красный
    default:     color = "#ffffff"; break;  // белый на всякий случай
    }
    this->setStyleSheet(QString("color: white;background-color: %1; padding: 8px;border-radius: 12px;").arg(color));
}
