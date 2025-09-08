#include "MyTextEdit.h"
#include "notebutton.h"
MyTextEdit::MyTextEdit(QWidget* parent)
    : QTextEdit(parent) {}

void MyTextEdit::insertFromMimeData(const QMimeData *source) {
    QTextCursor cursor = textCursor();

    if (source->hasImage()) {
        QImage img = qvariant_cast<QImage>(source->imageData());
        if (!img.isNull()) {
            QString imgName = QString("img_%1").arg(QDateTime::currentMSecsSinceEpoch());
            document()->addResource(QTextDocument::ImageResource, QUrl(imgName), img);

            QTextImageFormat format;
            format.setName(imgName);
            cursor.insertImage(format);
            setTextCursor(cursor);
            return;
        }
    }

    // Если пришёл URL (например, картинка из браузера)
    if (source->hasUrls()) {
        for (const QUrl &url : source->urls()) {
            QImage img(url.toLocalFile());
            if (!img.isNull()) {
                QString imgName = QString("img_%1").arg(QDateTime::currentMSecsSinceEpoch());
                document()->addResource(QTextDocument::ImageResource, QUrl(imgName), img);

                QTextImageFormat format;
                format.setName(imgName);
                cursor.insertImage(format);
                setTextCursor(cursor);
                return;
            }
        }
    }

    // Фоллбэк: обычный текст или html
    QTextEdit::insertFromMimeData(source);
}
