#include "mainwindow.h"

#include <QApplication>
#include <QDebug>
#include <iostream>
#include <stdlib.h>
#include "constants.h"

struct InputParameters
{
    int ticTacToeSize;
    // add others in needed
};

InputParameters mainArgsParser(int argc, char *argv[])
{
    if (argc > (::numOfInputParameters + 1)) // +1 exec name
    {
        std::cout << "Too many input parameters!\n";
        exit(1);
    }

    // echo
    std::cout << "Input parameters:\n";
    for (int arg = 1; arg < argc; ++arg) // skip exec name
    {
        int strIdx = 0;
        while (*(argv[arg] + strIdx) != '\0')
        {
            std::cout << *(argv[arg] + strIdx);
            ++strIdx;
        }
        std::cout << '\n';
    }

    // assemble params
    InputParameters params;
    int firstParam = atoi(argv[1]);
    if (!firstParam)
    {
        std::cout << "Not a number!\n";
        exit(1);
    }
    params.ticTacToeSize = firstParam;
    return params;
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    InputParameters gameParams = mainArgsParser(argc, argv);
    Q_UNUSED(gameParams);

    return a.exec();
}
