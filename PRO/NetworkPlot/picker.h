#ifndef PICKER_H
#define PICKER_H

#include "qwt.h"
#include "qwt_picker.h"

class picker: public QwtPlotPicker
{
public:
    Picker( QWidget *canvas ):QwtPlotPicker( canvas )
    {
    }
protected:
    virtual QwtText trackerTextF( const QPointF &pos ) const
    {
        QString text;
        QDateTime dt;
        dt.setTime_t( ( int )pos.x() ); //获取时间
        text = dt.toString("mm:ss");
        text += " " + QString( "%1" ).arg( pos.y(), 0, 'f', 1 );
        QwtText qwttext( text );
        return qwttext;
    }
};

#endif // PICKER_H
