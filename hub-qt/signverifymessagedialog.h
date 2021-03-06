/*
 * This file is part of the Flowee project
 * Copyright (C) 2011-2015 The Bitcoin Core developers
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef FLOWEE_QT_SIGNVERIFYMESSAGEDIALOG_H
#define FLOWEE_QT_SIGNVERIFYMESSAGEDIALOG_H

#include <QDialog>

class PlatformStyle;
class WalletModel;

namespace Ui {
    class SignVerifyMessageDialog;
}

class SignVerifyMessageDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SignVerifyMessageDialog(const PlatformStyle *platformStyle, QWidget *parent);
    ~SignVerifyMessageDialog();

    void setModel(WalletModel *model);
    void setAddress_SM(const QString &address);
    void setAddress_VM(const QString &address);

    void showTab_SM(bool fShow);
    void showTab_VM(bool fShow);

protected:
    bool eventFilter(QObject *object, QEvent *event);

private:
    Ui::SignVerifyMessageDialog *ui;
    WalletModel *model;
    const PlatformStyle *platformStyle;

private Q_SLOTS:
    /* sign message */
    void on_addressBookButton_SM_clicked();
    void on_pasteButton_SM_clicked();
    void on_signMessageButton_SM_clicked();
    void on_copySignatureButton_SM_clicked();
    void on_clearButton_SM_clicked();
    /* verify message */
    void on_addressBookButton_VM_clicked();
    void on_verifyMessageButton_VM_clicked();
    void on_clearButton_VM_clicked();
};

#endif
