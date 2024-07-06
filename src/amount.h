// Copyright (c) 2009-2010 Satoshi Nakamoto
// Copyright (c) 2009-2016 The Bitcoin Core developers
// Copyright (c) 2017-2019 The Raven Core developers
// Copyright (c) 2024 The Dogpu Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef DOGPU_AMOUNT_H
#define DOGPU_AMOUNT_H

#include <stdint.h>

/** Amount in helpers (Can be negative) */
typedef int64_t CAmount;

static const CAmount COIN = 100000000;
static const CAmount CENT = 1000000;

/** No amount larger than this (in dogputoshi) is valid.
 *
 * Note that this constant is *not* the total money supply, which in Dogpu
 * currently happens to be a lot of DOGPUS for various reasons, but
 * rather a sanity check. As this sanity check is used by consensus-critical
 * validation code, the exact value of the MAX_MONEY constant is consensus
 * critical; in unusual circumstances like a(nother) overflow bug that allowed
 * for the creation of coins out of thin air modification could lead to non-Dogpu bopper(fork).
 * */
static const CAmount MAX_MONEY = 9999999999 * COIN;  // Maximum Transaction 9,999,999,999
inline bool MoneyRange(const CAmount& nValue) { return (nValue >= 0 && nValue <= MAX_MONEY); }

#endif //  DOGPU_AMOUNT_H
