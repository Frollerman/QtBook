#include <QtWidgets>
#include <QPrinter>

int main (int argc, char** argv)
{
    QApplication app(argc, argv);
    QWidget wgt;

    QTextEdit* ptxt = new QTextEdit("This is a <b>TEST</b>");
    QPrinter printer(QPrinter::HighResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName("output.pdf");
    ptxt->document()->print(&printer);

    wgt.show();

    return app.exec();
}
