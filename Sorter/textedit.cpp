#include "textedit.h"
#include "ui_textedit.h"
#include "consumer.h"

TextEdit::~TextEdit()
{
    delete ui;
}

void TextEdit::SetText(QString QS)
{
    insertPlainText(QS);
}
