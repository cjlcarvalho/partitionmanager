/*************************************************************************
 *  Copyright (C) 2016 by Chantara Tith <tith.chantara@gmail.com>        *
 *                                                                       *
 *  This program is free software; you can redistribute it and/or        *
 *  modify it under the terms of the GNU General Public License as       *
 *  published by the Free Software Foundation; either version 3 of       *
 *  the License, or (at your option) any later version.                  *
 *                                                                       *
 *  This program is distributed in the hope that it will be useful,      *
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of       *
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the        *
 *  GNU General Public License for more details.                         *
 *                                                                       *
 *  You should have received a copy of the GNU General Public License    *
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.*
 *************************************************************************/

#if !defined(VOLUMEDIALOG__H)

#define VOLUMEDIALOG__H

#include <QDialog>

class VolumeWidget;
class Partition;

class QDialogButtonBox;
class QPushButton;
class QVBoxLayout;
class QWidget;
class QString;

class VolumeDialog : public QDialog
{
    Q_DISABLE_COPY(VolumeDialog)

public:
    VolumeDialog(QWidget* parent, QString& vgname, QList<Partition*>& pvlist);
    ~VolumeDialog();

protected:
    virtual void setupDialog();
    virtual void setupConstraints();
    virtual void setupConnections();

    virtual void updateOkButtonStatus();
    virtual void updatePartTable();
    virtual void updateSizeInfos();

    VolumeWidget& dialogWidget() {
        Q_ASSERT(m_DialogWidget);
        return *m_DialogWidget;
    }
    const VolumeWidget& dialogWidget() const {
        Q_ASSERT(m_DialogWidget);
        return *m_DialogWidget;
    }

    const QString originalName() const {
        return m_OriginalName;
    }

protected:
    virtual void onPartitionListChanged();

protected:
    VolumeWidget* m_DialogWidget;
    QString m_OriginalName;

    QDialogButtonBox* dialogButtonBox;
    QPushButton* okButton;
    QPushButton* cancelButton;
    QVBoxLayout *mainLayout;
};

#endif