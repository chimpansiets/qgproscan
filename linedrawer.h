#ifndef LINEDRAWER_H
#define LINEDRAWER_H

#include "drawwidget.h"

class LineDrawer : public DrawWidget
{
    public:
        LineDrawer();
        void drawCursorFollow(QPainter *painter);

};

#endif // LINEDRAWER_H
