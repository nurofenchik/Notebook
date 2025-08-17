#ifndef NOTELABEL_H
#define NOTELABEL_H
#include <QLabel>
#include <QString>
#include <QMouseEvent>
class NoteLabel : public QLabel
{
    Q_OBJECT

private:
    QString full_text;

public:
    NoteLabel( const QString& short_text , const QString& self_full_text , QWidget* parent = nullptr );
};

#endif // NOTELABEL_H
