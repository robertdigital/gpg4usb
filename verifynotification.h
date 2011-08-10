#ifndef VERIFYNOTIFICATION_H
#define VERIFYNOTIFICATION_H

#include <QLabel>
#include <QHBoxLayout>
#include <QMenu>
#include <QPushButton>

#include <QWidget>

#include "keyserverimportdialog.h"
#include "context.h"
#include <gpgme.h>


class VerifyNotification : public QWidget
{
    Q_OBJECT
public:
    explicit VerifyNotification(GpgME::Context *ctx,QWidget *parent = 0 );
    // set the text of verifynotification
    /****************************************************************************************
     * Name:                setVerifyLabel
     * Description:         set the text of verify notification
     * Parameters:          none
     * Return Values:       none
     * Change on members:   none
    */
    void setVerifyLabel(QString text);
    /****************************************************************************************
     * Name:                showImportAction
     * Description:         show the action in detailsmenu
     * Parameters:          none
     * Return Values:       none
     * Change on members:   none
    */
    void showImportAction();
    /****************************************************************************************
     * Name:                hideImportAction
     * Description:         hide the action in detailsmenu
     * Parameters:          none
     * Return Values:       none
     * Change on members:   none
    */
    void hideImportAction();

    /****************************************************************************************
     * Name:                setVerifyDetailText
     * Description:         set the text of verify-detail dialog
     * Parameters:          QString containing the text
     * Return Values:       none
     * Change on members:   verifyDetailText changes to text
    */
    void setVerifyDetailText(QString text);

    /****************************************************************************************
     * Name:                keysNotInList
     * Description:         List holding the keys in signature, which are not in the keylist
    */
    QStringList *keysNotInList;
    // set text shown in verifydetails dialog

signals:

public slots:
    // import missing key from keyserver
    void importFromKeyserver();
    // show verify details
    void showVerifyDetails();

private:
    QMenu *detailMenu; // Menu for te Button in verfiyNotification
    QAction *importFromKeyserverAct;
    QAction *showVerifyDetailsAct;
    QString *verifyDetailText; // Text showed in VerifiyNotification
    QPushButton *detailsButton; // Button shown in verifynotification
    QLabel *verifyLabel; // Label holding the text shown in verifyNotification
    GpgME::Context *mCtx;
    QHBoxLayout *notificationWidgetLayout;
};
#endif // VERIFYNOTIFICATION_H
