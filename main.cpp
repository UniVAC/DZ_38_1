#include <QApplication>
#include <QPushButton>
#include <QWidget>
#include <iostream>

#include "circleButton.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    circleButton circlebutton(nullptr);
    QObject::connect(&circlebutton, &QPushButton::clicked, [](){
        std::cout << "cliced";
    });

    circlebutton.resize(300, 300);
    circlebutton.show();
    return a.exec();
}
