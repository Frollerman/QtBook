#include <QtWidgets>

int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    QFileSystemModel model;
    QTreeView treeView;

    model.setRootPath(QDir::rootPath());
    treeView.setModel(&model);

//    QModelIndex index = model.index(QDir::currentPath());
//    treeView.setRootIndex(index);

    treeView.show();

    return app.exec();
}
