#include "picturedisplay.h"


PictureDisplay::PictureDisplay(QWidget* parent) : QLabel(parent)
{
    this->setMouseTracking(true);

    bool_mousePressed = false;
}

PictureDisplay::~PictureDisplay()
{

}

void PictureDisplay::mousePressEvent(QMouseEvent *event_mouse)
{
    bool_mousePressed = true;
    point_mousePressed = event_mouse->pos();

    emit sendMousePressPosition(point_mousePressed);

    QRubberBand* rubberBand = new QRubberBand(QRubberBand::Rectangle, this);

    // generates random color for rubberBand
    QColor random_color = generateColor();

    // generates palette using generated color for coloring
    QPalette palette = generatePalette( random_color );

    // makes rubberBands colorful
    rubberBand->setPalette( palette );

    // send rectangle to vector
    vector_rubberBandDrawn.push_back( rubberBand );

    // gets its index to use on following lines
    index_rubberBandDrawn = vector_rubberBandDrawn.size() - 1;

    // starts drawing rectangle
    vector_rubberBandDrawn.at(index_rubberBandDrawn)->setGeometry( QRect(point_mousePressed, event_mouse->pos()).normalized() );
    vector_rubberBandDrawn.at(index_rubberBandDrawn)->show();
}

void PictureDisplay::mouseMoveEvent(QMouseEvent *event_mouse)
{
    point_mouseMove = event_mouse->pos();

    // sends coordinates to mainwindow class
    // conditions avoid exceeding the border
    if((point_mouseMove.x() <= this->size().width() - 1) && (point_mouseMove.y() <= this->size().height() - 1))
    {
        if(point_mouseMove.x() >= 0 && point_mouseMove.y() >= 0)
        {
            emit sendMouseCurrentPosition(point_mouseMove);
        }
    }

    // draws rectangele while moving mouse
    if(bool_mousePressed)
    {
        vector_rubberBandDrawn.at(index_rubberBandDrawn)->setGeometry(QRect(point_mousePressed, event_mouse->pos()).normalized());
    }
}

void PictureDisplay::mouseReleaseEvent(QMouseEvent *event_mouse)
{
    bool_mousePressed = false;

    point_mouseMove = event_mouse->pos();

    emit sendMouseReleasePosition(point_mouseMove);
    emit sendRubberBandVector(vector_rubberBandDrawn);
}


QColor PictureDisplay::generateColor()
{
    int r, g, b;

    srand(time(NULL));
    r = rand() % 255;
    g = rand() % 255;
    b = rand() % 255;

    QColor color(r,g,b);

    return color;
}

QPalette PictureDisplay::generatePalette(QColor color)
{
    QPalette palette;
    palette.setBrush(QPalette::Highlight, QBrush(color));

    return palette;
}
