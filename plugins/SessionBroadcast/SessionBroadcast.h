/*
 * Copyright (C) 2013 Canonical, Ltd.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; version 3.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Authors: Michael Terry <michael.terry@canonical.com>
 */

#ifndef UNITY_SESSIONBROADCAST_H
#define UNITY_SESSIONBROADCAST_H

#include <QObject>
#include <QString>

class QDBusInterface;

class SessionBroadcast: public QObject
{
    Q_OBJECT

public:
    explicit SessionBroadcast(QObject *parent = 0);

    Q_INVOKABLE void requestApplicationStart(const QString &username, const QString &appId);

Q_SIGNALS:
    // This signal isn't actually used by the shell
    // (unity-greeter-session-broadcast handles launching an app for us), but
    // it's useful for testing the plugin.
    void startApplication(const QString &appId);
    void showHome();

private Q_SLOTS:
    void onStartApplication(const QString &username, const QString &appId);
    void onShowHome(const QString &username);

private:
    QDBusInterface *m_broadcaster;
};

#endif
