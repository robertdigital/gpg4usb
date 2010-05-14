#include "attachmenttablemodel.h"

/** compare with http://doc.qt.nokia.com/4.6/itemviews-addressbook.html
 */

AttachmentTableModel::AttachmentTableModel(QObject *parent) :
    QAbstractTableModel(parent)
{
}

AttachmentTableModel::AttachmentTableModel(QList<MimePart> mimeparts, QObject *parent) :
    QAbstractTableModel(parent)
{
    listOfMimeparts = mimeparts;
}

void AttachmentTableModel::add(MimePart mp) {
   listOfMimeparts.append(mp);
   //QModelIndex changedIndex0 = createIndex(listOfMimeparts.size(), 0);
   //QModelIndex changedIndex1 = createIndex(listOfMimeparts.size(), 1);

   //emit(dataChanged(changedIndex0, changedIndex1));
   // TODO: check the data-changed function
   reset();
}

int AttachmentTableModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return listOfMimeparts.size();
}

int AttachmentTableModel::columnCount(const QModelIndex &parent) const
 {
     Q_UNUSED(parent);
     return 2;
 }

QVariant AttachmentTableModel::data(const QModelIndex &index, int role) const
{

    //qDebug() << "called, index: " << index.column();

    if (!index.isValid())
        return QVariant();

    if (index.row() >= listOfMimeparts.size() || index.row() < 0)
        return QVariant();

    if (role == Qt::DisplayRole) {
        MimePart mp = listOfMimeparts.at(index.row());

        if (index.column() == 0)
            return mp.getParam("Content-Type", "name");
        if (index.column() == 1)
            return mp.getValue("Content-Type");
    }
    return QVariant();
}

QVariant AttachmentTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    //qDebug() << "called, section: " << section;
    if (role != Qt::DisplayRole)
        return QVariant();

    if (orientation == Qt::Horizontal) {
        switch (section) {
            case 0:
                return tr("Filename");

            case 1:
                return tr("Contenttype");

            default:
                return QVariant();
        }
    }
    return QVariant();
}
