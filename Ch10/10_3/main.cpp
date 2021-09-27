#include <QtWidgets>

int main (int argc, char** argv)
{
    QApplication app(argc, argv);
    QWidget wgt;

    QTextEdit* ptxt = new QTextEdit("This is a <b>TEST</b>");
    QTextDocumentWriter writer;
    writer.setFormat("odf");
    writer.setFileName("output.odf");
    writer.write(ptxt->document());

    wgt.show();

    return app.exec();
}
