#ifndef ADDNOTE_H
#define ADDNOTE_H

#include <QDialog>
QT_BEGIN_NAMESPACE
namespace Ui {
class addnote;
}
QT_END_NAMESPACE
class addnote : public QDialog
{
    Q_OBJECT

public:
    addnote(QWidget *parent = nullptr);
    ~addnote();


signals:
    void ready_to_save(QString shortText , QString fullText , QWidget* add_window);
private slots:

    void on_save_note_button_clicked();

private:
    Ui::addnote *ui;
};

#endif // ADDNOTE_H
