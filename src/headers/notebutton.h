#ifndef NOTEBUTTON_H
#define NOTEBUTTON_H

#include <QPushButton>
#include <QDateTime>
#include <QColor>

namespace Ui {
class notebutton;
}

class notebutton : public QPushButton
{
    Q_OBJECT
private:
    Ui::notebutton *ui;
    QDateTime creationDate;
    QString fullText;
public:
    explicit notebutton(QWidget *parent = nullptr);
    ~notebutton();
    enum Priority
    {
        LOW = 1,
        MEDIUM = 2,
        HIGH = 3
    };
    void SetLabelText(const QString& ShortText);
    void SetFullText(const QString& FullText);
    void SetNoteColor(Priority priority);
    void SetCreationDate(const QDateTime& date);
    QString getNoteText() const { return fullText; }
    QDateTime GetCreationDate() const;
signals:
    void set_global_info(const QString& short_text,const QString& full_txt , notebutton* note);
    void noteSelected(const QString &text);
private slots:
    void on_notebutton_clicked();
};

#endif // NOTEBUTTON_H
