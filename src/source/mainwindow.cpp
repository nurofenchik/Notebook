#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "notelabel.h"
#include "addnote.h"
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
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::add_note(const QString &shortText, const QString &fullText) {
    auto *note = new NoteLabel(shortText, fullText, this);
    note->setStyleSheet("color: white; background-color: #3f4156; padding: 8px; border-radius: 8px;");
    ui->notes_container->addWidget(note);
}


void MainWindow::on_new_note_button_clicked()
{
    auto* addnote_wnd = new addnote(this);
    addnote_wnd->show();
    connect(addnote_wnd , &addnote::ready_to_save , this , &MainWindow::add_note );
}

