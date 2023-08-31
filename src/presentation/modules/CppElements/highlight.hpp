#pragma once
#include <QColor>
#include <QList>
#include <QRectF>

namespace cpp_elements
{

struct Highlight
{
    QColor color;
    QList<QRectF> rects;
};

}  // namespace cpp_elements