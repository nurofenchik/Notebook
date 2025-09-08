#include "notebutton.h"
#include "ui_notebutton.h"
#include "mainwindow.h"
notebutton::notebutton(QWidget *parent)
    : QPushButton(parent)
    , ui(new Ui::notebutton)
    , creationDate(QDateTime::currentDateTime())
    , document(new QTextDocument(this))
{
    ui->setupUi(this);
    this->setFixedSize(125, 50);
    ui->date_label->setText(creationDate.toString("dd.MM.yyyy"));
}

notebutton::~notebutton()
{
    delete document;
    delete ui;
}

void notebutton::SetLabelText(const QString &ShortText)
{
    QString displayText = ShortText;
    // Ограничиваем текст для отображения в маленьком виджете
    if (displayText.length() > 20) {
        displayText = displayText.left(17) + "...";
    }
    ui->note_text_label->setText(displayText);
}


void notebutton::SetNoteColor(Priority priority)
{
    QString color;

    switch(priority) {
    case LOW:    color = "#3700ff"; break;
    case MEDIUM: color = "#6142cf"; break;
    case HIGH:   color = "#1d0e52"; break;
    default:     color = "#333333"; break;
    }
    this->setStyleSheet(QString("QWidget { color: white; background-color: %1; padding: 2px; border-radius: 12px; }").arg(color));
}

void notebutton::SetCreationDate(const QDateTime &date)
{
    creationDate = date;
    ui->date_label->setText(creationDate.toString("dd.MM.yyyy"));
}

QDateTime notebutton::GetCreationDate() const
{
    return creationDate;
}

void notebutton::on_notebutton_clicked()
{
    emit set_global_info(ui->note_text_label->text() , this);
}



