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
    NoteLabel( const QString& shortText , const QString& fullText , QWidget* parent = nullptr );
};

#endif // NOTELABEL_H
