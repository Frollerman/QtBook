#include <QtWidgets>

int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    QTextEdit txt;

    txt.setHtml("<HTML>"
                "<BODY BGCOLOR=YELLOW"
                "<CENTER><IMG SRC=\":/MetroGnome.png\"></CENTER>"
                "<H2><CENTER>Gnome Poem</CENTER></H2>"
                "<FONT COLOR=BLUE>"
                "<P ALIGN=\"center\">"
                    "<I>"
                    "Magic! Magic!<BR>"
                    "Magic! Magic!<BR>"
                    "Magic! Magic!<BR>"
                    "..."
                "</I>"
                "</P>"
                "</FONT>"
                "</BODY>"
                "</HTML>"
               );
    txt.resize(320, 360);
    txt.show();

    return app.exec();
}
