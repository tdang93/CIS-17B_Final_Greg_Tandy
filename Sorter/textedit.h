#ifndef TEXTEDIT_H
#define TEXTEDIT_H

#include <QWidget>
#include <QTextEdit>

namespace Ui {
class TextEdit;
}

class TextEdit : public QTextEdit
{
    Q_OBJECT

public:
    ~TextEdit();

public slots:
    void SetText(QString);

private:
    Ui::TextEdit *ui;
};

#endif // TEXTEDIT_H
