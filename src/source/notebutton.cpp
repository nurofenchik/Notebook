#include "notebutton.h"
#include "ui_notebutton.h"
#include <algorithm>

NoteButton::NoteButton(QWidget *parent)
    : QPushButton(parent)
    , m_ui(new Ui::notebutton)
    , m_creationDate(QDateTime::currentDateTime())
    , m_document(new QTextDocument(this))
{
    m_ui->setupUi(this);
    
    // Set fixed size for consistent appearance
    setFixedSize(BUTTON_WIDTH, BUTTON_HEIGHT);
    
    // Display creation date
    m_ui->date_label->setText(m_creationDate.toString("dd.MM.yyyy"));
    
    // Connect click signal
    connect(this, &QPushButton::clicked, this, &NoteButton::onButtonClicked);
}

NoteButton::~NoteButton()
{
    delete m_ui;
    // m_document is deleted automatically as it's a child of this widget
}

void NoteButton::setLabelText(const QString& shortText)
{
    if (shortText.isEmpty()) {
        m_ui->note_text_label->setText(tr("Empty note"));
        return;
    }
    
    QString displayText = shortText;
    
    // Truncate text if it's too long for display
    if (displayText.length() > MAX_DISPLAY_LENGTH) {
        displayText = displayText.left(TRUNCATE_LENGTH) + "...";
    }
    
    m_ui->note_text_label->setText(displayText);
}

void NoteButton::setNoteColor(Priority priority)
{
    const QString color = getColorForPriority(priority);
    const QString styleSheet = QString(
        "QWidget { "
        "color: white; "
        "background-color: %1; "
        "padding: 2px; "
        "border-radius: 12px; "
        "}"
    ).arg(color);
    
    setStyleSheet(styleSheet);
}

void NoteButton::setCreationDate(const QDateTime& date)
{
    if (!date.isValid()) {
        qWarning("NoteButton::setCreationDate: Invalid date provided");
        return;
    }
    
    m_creationDate = date;
    m_ui->date_label->setText(m_creationDate.toString("dd.MM.yyyy"));
}

QDateTime NoteButton::getCreationDate() const
{
    return m_creationDate;
}

QTextDocument* NoteButton::getDocument() const
{
    return m_document;
}

void NoteButton::onButtonClicked()
{
    const QString shortText = m_ui->note_text_label->text();
    emit globalInfoRequested(shortText, this);
}

QString NoteButton::getColorForPriority(Priority priority) const
{
    switch (priority) {
        case Priority::Low:    return "#3700ff";  // Blue
        case Priority::Medium: return "#6142cf";  // Purple  
        case Priority::High:   return "#1d0e52";  // Dark purple
        default:
            qWarning("NoteButton::getColorForPriority: Unknown priority level");
            return "#333333";  // Default gray
    }
}



