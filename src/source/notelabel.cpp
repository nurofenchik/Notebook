#include "notelabel.h"

NoteLabel::NoteLabel( const QString& shortText , const QString& fullText , QWidget* parent ) : QLabel(shortText , parent) , full_text(fullText)
{
    setStyleSheet("QLabel { background-color: #292a3c; padding: 8px; border-radius: 5px; }");
    setWordWrap(true);
}
