#ifndef CIRCLEBUTTON_H
#define CIRCLEBUTTON_H

#include <QPushButton>
#include <QtMultimedia>

class circleButton : public QPushButton{
    Q_OBJECT
public:
    circleButton(QWidget *parent);

    QSize sizeHint() const override;
    QSize minimumSizeHint() const override;
    void paintEvent(QPaintEvent *e) override;
    void keyPressEvent(QKeyEvent *e) override;

public slots:
    void setUp();
    void setDown();
private:
    QMediaPlayer sound;
    QPixmap current;
    QPixmap redUp;
    QPixmap redDown;
};


#endif // CIRCLEBUTTON_H
