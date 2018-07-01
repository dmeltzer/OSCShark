#include "ipchooser.h"

#include <QHBoxLayout>
IpChooser::IpChooser(QWidget *parent)
    : QFrame(parent)
{
    setFrameShape( QFrame::StyledPanel );
    setFrameShadow( QFrame::Sunken );

    QHBoxLayout *pLayout = new QHBoxLayout( this );
    setLayout(pLayout);
    pLayout->setContentsMargins(0,0,0,0);
    pLayout->setSpacing( 0 );

}



