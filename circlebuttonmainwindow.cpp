#include "circleButton.h"
#include <QPainter>
#include <QPaintEvent>
#include <QTimer>

circleButton::circleButton(QWidget *parent){
    setParent(parent);

    redUp = QPixmap(":/image/redUP.png");
    redDown = QPixmap(":/image/redDOWN.png");
    current = redUp;
    setGeometry(current.rect());

    sound.setMedia(QUrl("qrc:/sound/aa.mp3"));
    sound.setVolume(50);
    connect(this, &QPushButton::clicked, this, &circleButton::setDown);
};

void circleButton::paintEvent(QPaintEvent *e){
    QPainter p(this);
    p.drawPixmap(e->rect(), current);
};

void circleButton::setUp(){
    current = redUp;
    update();
};

void circleButton::setDown(){
    current = redDown;
    sound.stop();
    sound.play();
    update();
    QTimer::singleShot(80, this, &circleButton::setUp);
};

void circleButton::keyPressEvent(QKeyEvent *e){
    setDown();
};

QSize circleButton::sizeHint() const{
    return QSize(300, 300);
};

QSize circleButton::minimumSizeHint() const{
    return sizeHint();
};
