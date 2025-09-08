#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "addnote.h"
#include "notebutton.h"
#include <QMessageBox>
#include <QScrollArea>
#include <QScrollBar>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("NOTEBOOK::IO");
    ui->notes_scroll_area->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    ui->notes_scroll_area->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->notes_scroll_area->setLayoutDirection(Qt::RightToLeft);
    ui->notes_scroll_area->verticalScrollBar()->setLayoutDirection(Qt::LeftToRight);
    ui->notes_container->addStretch();
    ui->note_label->hide();
    ui->del_button->hide();
    ui->note_edito->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::add_note(const QString &shortText, notebutton::Priority note_level, QWidget* add_window) {
    auto *note = new notebutton();
    note->SetNoteColor(note_level);
    note->SetLabelText(shortText);
    
    int index = ui->notes_container->count() - 1;
    ui->notes_container->insertWidget(index, note, 0, Qt::AlignCenter);
    
    // Подключаем сигнал для отображения информации о заметке
    connect(note, &notebutton::set_global_info, this, [this, note](const QString &shortText) {
        SetInfo(shortText, note);
    });

    add_window->close();
}


void MainWindow::on_new_note_button_clicked()
{
    addnote* addnote_wnd = new addnote(this);
    addnote_wnd->show();
    connect(addnote_wnd , &addnote::ready_to_save , this , &MainWindow::add_note );
}

void MainWindow::SetInfo(const QString& ShortText, notebutton* note)
{
    ui->note_label->setText(ShortText);
    ui->note_label->show();
    ui->del_button->show();
    ui->note_edito->show();
    
    // Устанавливаем текущую заметку
    currentNote = note;
    ui->note_edito->setDocument(note->getdocument());
    // Загружаем полный текст заметки в редактор
    if (!note->getdocument()->toPlainText().isEmpty()) {
        ui->note_edito->setDocument(note->getdocument());
    } else {
        ui->note_edito->setPlainText("");
        ui->note_edito->setPlaceholderText("Введите полный текст заметки...");
    }
}



void MainWindow::delete_note(notebutton* note)
{
    // Убираем виджет из layout
    ui->notes_container->removeWidget(note);

    // Удаляем сам виджет
    note->deleteLater();

    // Скрываем панель с инфой, если она была открыта
    ui->note_label->hide();
    ui->del_button->hide();
    ui->note_edito->hide();
    delete note;
}


void MainWindow::on_del_button_clicked()
{
    if( currentNote )
    {
        delete_note(currentNote);
        currentNote = nullptr;
    }
}


