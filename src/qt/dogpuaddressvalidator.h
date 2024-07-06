// Copyright (c) 2011-2014 The Bitcoin Core developers
// Copyright (c) 2017-2019 The Raven Core developers
// Copyright (c) 2024 The Dogpu Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef DOGPU_QT_DOGPUADDRESSVALIDATOR_H
#define DOGPU_QT_DOGPUADDRESSVALIDATOR_H

#include <QValidator>

/** Base58 entry widget validator, checks for valid characters and
 * removes some whitespace.
 */
class DogpuAddressEntryValidator : public QValidator
{
    Q_OBJECT

public:
    explicit DogpuAddressEntryValidator(QObject *parent);

    State validate(QString &input, int &pos) const;
};

/** Dogpu address widget validator, checks for a valid dogpu address.
 */
class DogpuAddressCheckValidator : public QValidator
{
    Q_OBJECT

public:
    explicit DogpuAddressCheckValidator(QObject *parent);

    State validate(QString &input, int &pos) const;
};

#endif // DOGPU_QT_DOGPUADDRESSVALIDATOR_H
