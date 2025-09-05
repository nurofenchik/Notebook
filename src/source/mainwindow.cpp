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
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::add_note(const QString &shortText , notebutton::Priority note_level  ,QWidget* add_window) {
    auto *note = new notebutton();
    note->SetNoteColor(note_level);
    note->SetLabelText(shortText);
    // Добавляем заметку перед последним элементом (stretch)
    int index = ui->notes_container->count() - 1;
    ui->notes_container->insertWidget(index, note , 0 , Qt::AlignCenter);
    connect(  note , &notebutton::set_global_info , this , &MainWindow::SetInfo);
    add_window->close();
}


void MainWindow::on_new_note_button_clicked()
{
    auto* addnote_wnd = new addnote(this);
    addnote_wnd->show();
    connect(addnote_wnd , &addnote::ready_to_save , this , &MainWindow::add_note );
}

void MainWindow::SetInfo(const QString& ShortText)
{
    ui->note_label->setText(ShortText);
}


/*TODO
 * сделать поле вывода основной инфы по заметке
 * сделать кнопки удаления заметки
 * сделать поле редактирования заметки
 *
*/
