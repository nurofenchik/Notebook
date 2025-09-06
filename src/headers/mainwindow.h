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

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void SetInfo(const QString& ShortText);
    ~MainWindow();

private slots:
    void on_new_note_button_clicked();
    void add_note(const QString& short_txt , notebutton::Priority note_level , QWidget* add_window);
    void delete_note(notebutton* note);

    void on_del_button_clicked();

private:
    Ui::MainWindow *ui;
    notebutton* currentNote = nullptr;
};
#endif // MAINWINDOW_H
