#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>
#include "notebutton.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

/**
 * @brief Main application window for the Notebook application
 * 
 * This class manages the main interface including the notes list,
 * note creation, editing, and deletion functionality.
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief Constructs the main window
     * @param parent Parent widget
     */
    explicit MainWindow(QWidget *parent = nullptr);
    
    /**
     * @brief Destructor
     */
    ~MainWindow() override;

    /**
     * @brief Sets the information panel to display note details
     * @param shortText Short text to display in the label
     * @param note Pointer to the note button that was selected
     */
    void setNoteInfo(const QString& shortText, NoteButton* note);

private slots:
    /**
     * @brief Handles new note button click
     */
    void onNewNoteButtonClicked();
    
    /**
     * @brief Adds a new note to the notes container
     * @param shortText Short text for the note
     * @param noteLevel Priority level of the note
     * @param addWindow Pointer to the add note dialog (for closing)
     */
    void addNote(const QString& shortText, NoteButton::Priority noteLevel, QWidget* addWindow);
    
    /**
     * @brief Deletes the specified note
     * @param note Pointer to the note button to delete
     */
    void deleteNote(NoteButton* note);
    
    /**
     * @brief Handles delete button click
     */
    void onDeleteButtonClicked();

private:
    Ui::MainWindow* m_ui;              ///< UI components
    NoteButton* m_currentNote;         ///< Currently selected note
    
    /**
     * @brief Initializes the UI components and settings
     */
    void setupUI();
    
    /**
     * @brief Connects note signals to main window slots
     * @param note Note button to connect
     */
    void connectNoteSignals(NoteButton* note);
    
    /**
     * @brief Hides the note information panel
     */
    void hideNoteInfo();
    
    /**
     * @brief Shows the note information panel
     */
    void showNoteInfo();
};

#endif // MAINWINDOW_H
