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
class addnote : public QDialog
{
    Q_OBJECT

public:
    addnote(QWidget *parent = nullptr);
    ~addnote();


signals:
    void ready_to_save(QString shortText, notebutton::Priority priority_level, QWidget* add_window);
private slots:

    void on_save_note_button_clicked();

private:
    Ui::addnote *ui;
    QButtonGroup* group;
};

#endif // ADDNOTE_H
