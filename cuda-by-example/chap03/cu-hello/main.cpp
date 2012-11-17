#include <QtCore/QCoreApplication>

extern "C"
void runCudaPart();
void kernel(void);

int main(int argc, char *argv[]) {

    QCoreApplication a(argc, argv);

    runCudaPart();

    return a.exec();

}
