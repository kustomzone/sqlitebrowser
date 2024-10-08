#ifndef EDITINDEXDIALOG_H
#define EDITINDEXDIALOG_H

#include "sql/ObjectIdentifier.h"
#include "sql/sqlitetypes.h"

#include <QDialog>
#include <QModelIndex>

class DBBrowserDB;

namespace Ui {
class EditIndexDialog;
}

class EditIndexDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EditIndexDialog(DBBrowserDB& db, const sqlb::ObjectIdentifier& indexName, bool createIndex, QWidget* parent = nullptr);
    ~EditIndexDialog() override;

private slots:
    void accept() override;
    void reject() override;

    void tableChanged(int table_name_idx);
    void checkInput();
    void addToIndex(const QModelIndex& idx = QModelIndex());
    void removeFromIndex(const QModelIndex& idx = QModelIndex());
    void moveColumnUp();
    void moveColumnDown();
    void addExpressionColumn();

private:
    DBBrowserDB& pdb;
    sqlb::ObjectIdentifier curIndex;
    sqlb::Index index;
    bool newIndex;
    Ui::EditIndexDialog* ui;
    std::string m_sRestorePointName;

    void updateColumnLists();
    void updateSqlText();
    void moveCurrentColumn(bool down);
    void tableChanged(const QString& new_table, bool initialLoad);
};

#endif
