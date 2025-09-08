#pragma once

#include <QTextEdit>
#include <QMimeData>
#include <QTextCursor>
#include <QTextImageFormat>
#include <QTextDocument>
#include <QDateTime>
#include <QImage>
#include <QUrl>
#include <QVariant>

class MyTextEdit : public QTextEdit {
    Q_OBJECT
public:
    explicit MyTextEdit(QWidget* parent = nullptr);

protected:
    void insertFromMimeData(const QMimeData *source) override;
};

