#ifndef ADDNOTE_H
#define ADDNOTE_H

#include <QDialog>
#include <QButtonGroup>
#include "notebutton.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class addnote;
}
QT_END_NAMESPACE

/**
 * @brief Dialog for creating new notes
 * 
 * This dialog allows users to enter a short text for a note
 * and select its priority level before saving.
 */
class AddNote : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief Constructs the add note dialog
     * @param parent Parent widget
     */
    explicit AddNote(QWidget *parent = nullptr);
    
    /**
     * @brief Destructor
     */
    ~AddNote() override;

signals:
    /**
     * @brief Emitted when user wants to save the note
     * @param shortText Short text entered by user
     * @param priorityLevel Selected priority level
     * @param addWindow Pointer to this dialog (for closing)
     */
    void readyToSave(const QString& shortText, 
                     NoteButton::Priority priorityLevel, 
                     QWidget* addWindow);

private slots:
    /**
     * @brief Handles save button click
     */
    void onSaveNoteButtonClicked();

private:
    Ui::addnote* m_ui;                 ///< UI components
    QButtonGroup* m_priorityGroup;     ///< Button group for priority selection
    
    /**
     * @brief Sets up the UI and connects signals
     */
    void setupUI();
    
    /**
     * @brief Validates user input
     * @return true if input is valid, false otherwise
     */
    bool validateInput() const;
    
    /**
     * @brief Gets the selected priority level
     * @return Selected priority or Low if none selected
     */
    NoteButton::Priority getSelectedPriority() const;
};

#endif // ADDNOTE_H
