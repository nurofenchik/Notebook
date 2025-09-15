#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "addnote.h"
#include "notebutton.h"
#include <QMessageBox>
#include <QScrollArea>
#include <QScrollBar>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , m_ui(new Ui::MainWindow)
    , m_currentNote(nullptr)
{
    m_ui->setupUi(this);
    setupUI();
    
    // Connect UI signals
    connect(m_ui->new_note_button, &QPushButton::clicked, 
            this, &MainWindow::onNewNoteButtonClicked);
    connect(m_ui->del_button, &QPushButton::clicked, 
            this, &MainWindow::onDeleteButtonClicked);
}

MainWindow::~MainWindow()
{
    delete m_ui;
}

void MainWindow::setupUI()
{
    setWindowTitle("NOTEBOOK::IO");
    
    // Configure scroll area
    m_ui->notes_scroll_area->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    m_ui->notes_scroll_area->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    m_ui->notes_scroll_area->setLayoutDirection(Qt::RightToLeft);
    m_ui->notes_scroll_area->verticalScrollBar()->setLayoutDirection(Qt::LeftToRight);
    
    // Add stretch to keep notes at top
    m_ui->notes_container->addStretch();
    
    // Initially hide note info panel
    hideNoteInfo();
}

void MainWindow::addNote(const QString& shortText, NoteButton::Priority noteLevel, QWidget* addWindow)
{
    if (shortText.isEmpty()) {
        QMessageBox::warning(this, tr("Warning"), tr("Note text cannot be empty"));
        return;
    }
    
    // Create new note button
    auto* note = new NoteButton(this);
    note->setNoteColor(noteLevel);
    note->setLabelText(shortText);
    
    // Insert note before the stretch item
    const int index = m_ui->notes_container->count() - 1;
    m_ui->notes_container->insertWidget(index, note, 0, Qt::AlignCenter);
    
    // Connect note signals
    connectNoteSignals(note);
    
    // Close the add note dialog
    if (addWindow) {
        addWindow->close();
    }
}

void MainWindow::connectNoteSignals(NoteButton* note)
{
    if (!note) {
        qWarning("MainWindow::connectNoteSignals: null note pointer");
        return;
    }
    
    connect(note, &NoteButton::globalInfoRequested, 
            this, [this](const QString& shortText, NoteButton* notePtr) {
                setNoteInfo(shortText, notePtr);
            });
}

void MainWindow::onNewNoteButtonClicked()
{
    auto* addNoteDialog = new AddNote(this);
    addNoteDialog->show();
    
    connect(addNoteDialog, &AddNote::readyToSave, 
            this, &MainWindow::addNote);
}

void MainWindow::setNoteInfo(const QString& shortText, NoteButton* note)
{
    if (!note) {
        qWarning("MainWindow::setNoteInfo: null note pointer");
        return;
    }
    
    m_ui->note_label->setText(shortText);
    m_currentNote = note;
    
    // Set up the editor with note's document
    m_ui->note_edito->setDocument(note->getDocument());
    
    if (note->getDocument()->toPlainText().isEmpty()) {
        m_ui->note_edito->setPlainText("");
        m_ui->note_edito->setPlaceholderText(tr("Enter full note text here..."));
    }
    
    showNoteInfo();
}

void MainWindow::deleteNote(NoteButton* note)
{
    if (!note) {
        qWarning("MainWindow::deleteNote: null note pointer");
        return;
    }
    
    // Remove from layout
    m_ui->notes_container->removeWidget(note);
    
    // Hide info panel if this was the current note
    if (m_currentNote == note) {
        hideNoteInfo();
        m_currentNote = nullptr;
    }
    
    // Schedule for deletion
    note->deleteLater();
}

void MainWindow::onDeleteButtonClicked()
{
    if (!m_currentNote) {
        QMessageBox::information(this, tr("Information"), 
                               tr("No note selected for deletion"));
        return;
    }
    
    const int result = QMessageBox::question(this, tr("Confirm Deletion"), 
                                           tr("Are you sure you want to delete this note?"),
                                           QMessageBox::Yes | QMessageBox::No);
    
    if (result == QMessageBox::Yes) {
        deleteNote(m_currentNote);
    }
}

void MainWindow::hideNoteInfo()
{
    m_ui->note_label->hide();
    m_ui->del_button->hide();
    m_ui->note_edito->hide();
}

void MainWindow::showNoteInfo()
{
    m_ui->note_label->show();
    m_ui->del_button->show();
    m_ui->note_edito->show();
}


