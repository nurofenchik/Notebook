#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "notelabel.h"
#include "addnote.h"
#include <QMessageBox>
#include <QScrollArea>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::add_note(const QString &shortText, const QString &fullText) {
    auto *note = new NoteLabel(shortText, fullText, this);
    note->show();
}


void MainWindow::on_new_note_button_clicked()
{
    auto* addnote_wnd = new addnote(this);
    addnote_wnd->show();
    connect(addnote_wnd , &addnote::ready_to_save , this , &MainWindow::add_note );
}

