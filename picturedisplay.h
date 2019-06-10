#ifndef PICTUREDISPLAY_H
#define PICTUREDISPLAY_H

#include <QObject>
#include <QWidget>
#include <QLabel>

#include <QMouseEvent>
#include <QRubberBand>
#include <QPoint>
#include <QColor>

#include <cstdlib>
#include <ctime>
#include <iostream>


class PictureDisplay : public QLabel
{
    Q_OBJECT


public:
    PictureDisplay(QWidget *parent = 0);
    ~PictureDisplay();


private:
    void mousePressEvent(QMouseEvent* event_mouse);
    void mouseMoveEvent(QMouseEvent* event_mouse);
    void mouseReleaseEvent(QMouseEvent* event_mouse);

    QColor generateColor();
    QPalette generatePalette(QColor color);

    int index_rubberBandDrawn;
    bool bool_mousePressed;

    QPoint point_mousePressed;
    QPoint point_mouseMove;

    std::vector<QRubberBand*> vector_rubberBandDrawn;

signals:
    void sendMousePressPosition(QPoint&);
    void sendMouseCurrentPosition(QPoint&);   
    void sendMouseReleasePosition(QPoint&);
    void sendRubberBandVector(std::vector<QRubberBand*>&);
};

#endif // PICTUREDISPLAY_H
