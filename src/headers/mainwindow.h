#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>
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
    void add_note(const QString& short_txt , const QString& full_txt);
    ~MainWindow();

private slots:
    void on_new_note_button_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
