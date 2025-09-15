#include "addnote.h"
#include "ui_addnote.h"
#include "notebutton.h"
#include <QMessageBox>
#include <QDebug>

AddNote::AddNote(QWidget *parent)
    : QDialog(parent)
    , m_ui(new Ui::addnote)
    , m_priorityGroup(new QButtonGroup(this))
{
    m_ui->setupUi(this);
    setupUI();
    
    // Connect save button
    connect(m_ui->save_note_button, &QPushButton::clicked,
            this, &AddNote::onSaveNoteButtonClicked);
}

AddNote::~AddNote()
{
    delete m_ui;
}

void AddNote::setupUI()
{
    setWindowTitle(tr("Note Information"));
    
    // Set up priority button group
    m_priorityGroup->addButton(m_ui->low_button, static_cast<int>(NoteButton::Priority::Low));
    m_priorityGroup->addButton(m_ui->med_button, static_cast<int>(NoteButton::Priority::Medium));
    m_priorityGroup->addButton(m_ui->high_button, static_cast<int>(NoteButton::Priority::High));
    m_priorityGroup->setExclusive(true);
    
    // Set default selection to Low priority
    m_ui->low_button->setChecked(true);
    
    // Set focus to text input
    m_ui->shorttxt_line->setFocus();
}

void AddNote::onSaveNoteButtonClicked()
{
    if (!validateInput()) {
        return;
    }
    
    const QString shortText = m_ui->shorttxt_line->text().trimmed();
    const NoteButton::Priority priority = getSelectedPriority();
    
    emit readyToSave(shortText, priority, this);
}

bool AddNote::validateInput() const
{
    const QString shortText = m_ui->shorttxt_line->text().trimmed();
    
    if (shortText.isEmpty()) {
        QMessageBox::warning(const_cast<AddNote*>(this), 
                           tr("Input Error"), 
                           tr("Please enter some text for the note."));
        return false;
    }
    
    if (shortText.length() > 100) {
        QMessageBox::warning(const_cast<AddNote*>(this), 
                           tr("Input Error"), 
                           tr("Note text is too long. Maximum 100 characters allowed."));
        return false;
    }
    
    return true;
}

NoteButton::Priority AddNote::getSelectedPriority() const
{
    const int checkedId = m_priorityGroup->checkedId();
    
    // Validate the ID and return corresponding priority
    switch (checkedId) {
        case static_cast<int>(NoteButton::Priority::Low):
            return NoteButton::Priority::Low;
        case static_cast<int>(NoteButton::Priority::Medium):
            return NoteButton::Priority::Medium;
        case static_cast<int>(NoteButton::Priority::High):
            return NoteButton::Priority::High;
        default:
            qWarning("AddNote::getSelectedPriority: Unknown priority ID, defaulting to Low");
            return NoteButton::Priority::Low;
    }
}

