#include "notelabel.h"

NoteLabel::NoteLabel( const QString& short_text , const QString& self_full_text , QWidget* parent ) : QLabel(short_text , parent) , full_text(self_full_text)
{
    setStyleSheet("QLabel { background-color: #292a3c; padding: 8px; border-radius: 5px; }");
    setWordWrap(true);
}
