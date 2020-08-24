#include <appengine.h>


int main(int argc, char *argv[])
{

    QApplication k(argc,argv);
    AppEngine *program = new AppEngine();

    k.exec();
    delete program;
    return 0;
}
