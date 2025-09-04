#ifndef NOTEBUTTON_H
#define NOTEBUTTON_H

#include <QLabel>

namespace Ui {
class notebutton;
}

class notebutton : public QLabel
{
    Q_OBJECT

public:
    explicit notebutton(QWidget *parent = nullptr);
    ~notebutton();


private:
    Ui::notebutton *ui;
};

#endif // NOTEBUTTON_H
