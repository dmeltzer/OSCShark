#ifndef IPCHOOSER_H
#define IPCHOOSER_H

#include <QFrame>
#include <QAbstractItemModel>

class QLineEdit;
class QWidget;

class IpChooser : public QFrame
{
    Q_OBJECT

public:
    explicit IpChooser(QWidget *parent = nullptr);
    ~IpChooser();
    // Header:
    virtual bool eventFilter(QObject *watched, QEvent *event);

public slots:
    void slotTextChanged( QLineEdit* pEdit );

signals:
    void signalTextChanged( QLineEdit *pEdit );

private:
    enum
    {
        QT_UTL_IP_SIZE  = 4,
        MAX_DIGITS      = 3,
    };

    QLineEdit *(m_pLineEdit[QT_UTL_IP_SIZE]);
    void MoveNextLineEdit( int i );
    void MovePreviousLineEdit( int i );
};

#endif // IPCHOOSER_H
