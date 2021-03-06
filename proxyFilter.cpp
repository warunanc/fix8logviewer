#include <proxyFilter.h>
#include <QDebug>
#include <QtScript>

int ProxyFilter::senderIDRole = Qt::UserRole+3;

ProxyFilter::ProxyFilter(QObject *parent): QSortFilterProxyModel(parent)
{
    //setDynamicSortFilter(true);
    rowAccepted =  false;

}
void ProxyFilter::setAcceptedSendIDs(QStringList sendIDs)
{
    invalidate();
    senderIDs = sendIDs;
}
void ProxyFilter::setLogicFilterIndexes(QVector<qint32> indexes,WorkSheetData::FilterMode fm,bool &CancelFlag)
{
    //resetInternalData();
    cancelFlag = &CancelFlag;
    //invalidate();
    logicFilterIndexes = indexes;

    filterMode = fm;
}
void ProxyFilter::setLogicFilterMode(WorkSheetData::FilterMode fm)
{
    invalidate();
    filterMode = fm;
}

bool ProxyFilter::filterAcceptsRow (int row, 
                                    const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    rowAccepted =  true;
    bool acceptSymbol    = true;
    bool bstatus;
    QStandardItemModel *sm =
            (QStandardItemModel *) sourceModel();
    QModelIndex mi = sm->index(row,0);
    QString str = mi.data(senderIDRole).toString();
    if (str.length() < 1)
        acceptSymbol = false;
    else if(senderIDs.contains(str))
        acceptSymbol = false;
    if (!acceptSymbol) {
       rowAccepted =  false;
       return false;
     }
    if (filterMode == WorkSheetData::Off)
     return true;
    if (logicFilterIndexes.count() < 1) {
        if (filterMode == WorkSheetData::Exclusive)
            return false;
        else
            return true;
    }

    if (filterMode == WorkSheetData::Exclusive) {
        if (logicFilterIndexes.contains(row) )
            return false;
        else
            return true;
    }
    else if (filterMode == WorkSheetData::Inclusive) {
        if (logicFilterIndexes.contains(row) )
            return true;
        else
            return false;
    }
    return false;
}

bool ProxyFilter::isRowAccepted()
{
    qDebug() << "IS ROW ACCEPETED = " << rowAccepted << __FILE__ << __LINE__;
    return rowAccepted;
}
