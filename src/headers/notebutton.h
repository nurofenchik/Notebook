#ifndef NOTEBUTTON_H
#define NOTEBUTTON_H

#include <QLabel>

namespace Ui {
class notebutton;
}

class notebutton : public QLabel
{
    Q_OBJECT
private:
    Ui::notebutton *ui;

public:
    explicit notebutton(QWidget *parent = nullptr);
    ~notebutton();
    enum Priority
    {
        LOW,
        MEDIUM,
        HIGH
    };
    void SetLabelText( const QString& ShortText);
    void SetNoteColor(  Priority priority);

};

#endif // NOTEBUTTON_H
