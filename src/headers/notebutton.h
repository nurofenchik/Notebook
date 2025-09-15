#ifndef NOTEBUTTON_H
#define NOTEBUTTON_H

#include <QPushButton>
#include <QDateTime>
#include <QColor>
#include <QTextDocument>

QT_BEGIN_NAMESPACE
namespace Ui {
class notebutton;
}
QT_END_NAMESPACE

/**
 * @brief A custom QPushButton representing a note with priority and content
 * 
 * This class extends QPushButton to create interactive note widgets that display
 * short text, creation date, and have different priority levels with corresponding colors.
 */
class NoteButton : public QPushButton
{
    Q_OBJECT

public:
    /**
     * @brief Priority levels for notes
     */
    enum class Priority : int {
        Low = 1,    ///< Low priority note (blue color)
        Medium = 2, ///< Medium priority note (purple color)
        High = 3    ///< High priority note (dark purple color)
    };

    /**
     * @brief Constructs a new note button
     * @param parent Parent widget
     */
    explicit NoteButton(QWidget *parent = nullptr);
    
    /**
     * @brief Destructor
     */
    ~NoteButton() override;

    /**
     * @brief Sets the display text for the note
     * @param shortText Text to display (will be truncated if too long)
     */
    void setLabelText(const QString& shortText);
    
    /**
     * @brief Sets the note color based on priority
     * @param priority Priority level that determines the color
     */
    void setNoteColor(Priority priority);
    
    /**
     * @brief Sets the creation date for the note
     * @param date Creation date
     */
    void setCreationDate(const QDateTime& date);
    
    /**
     * @brief Gets the creation date of the note
     * @return Creation date
     */
    QDateTime getCreationDate() const;
    
    /**
     * @brief Gets the text document associated with this note
     * @return Pointer to the QTextDocument containing full note content
     */
    QTextDocument* getDocument() const;

signals:
    /**
     * @brief Emitted when note is clicked to display its information
     * @param shortText Short text displayed on the button
     * @param note Pointer to this note button
     */
    void globalInfoRequested(const QString& shortText, NoteButton* note);

private slots:
    /**
     * @brief Handles button click events
     */
    void onButtonClicked();

private:
    /// Maximum characters to display on button before truncation
    static constexpr int MAX_DISPLAY_LENGTH = 20;
    /// Number of characters to show before adding ellipsis
    static constexpr int TRUNCATE_LENGTH = 17;
    /// Fixed width for note buttons
    static constexpr int BUTTON_WIDTH = 125;
    /// Fixed height for note buttons  
    static constexpr int BUTTON_HEIGHT = 50;

    Ui::notebutton* m_ui;              ///< UI components
    QDateTime m_creationDate;          ///< Note creation timestamp
    QTextDocument* m_document;         ///< Full content document
    
    /**
     * @brief Gets color string for given priority
     * @param priority Priority level
     * @return Hex color string
     */
    QString getColorForPriority(Priority priority) const;
};

#endif // NOTEBUTTON_H
