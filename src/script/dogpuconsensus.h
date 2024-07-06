// Copyright (c) 2009-2010 Satoshi Nakamoto
// Copyright (c) 2009-2016 The Bitcoin Core developers
// Copyright (c) 2017-2019 The Raven Core developers
// Copyright (c) 2024 The Dogpu Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef DOGPU_DOGPUCONSENSUS_H
#define DOGPU_DOGPUCONSENSUS_H

#include <stdint.h>

#if defined(BUILD_DOGPU_INTERNAL) && defined(HAVE_CONFIG_H)
#include "config/dogpu-config.h"
  #if defined(_WIN32)
    #if defined(DLL_EXPORT)
      #if defined(HAVE_FUNC_ATTRIBUTE_DLLEXPORT)
        #define EXPORT_SYMBOL __declspec(dllexport)
      #else
        #define EXPORT_SYMBOL
      #endif
    #endif
  #elif defined(HAVE_FUNC_ATTRIBUTE_VISIBILITY)
    #define EXPORT_SYMBOL __attribute__ ((visibility ("default")))
  #endif
#elif defined(MSC_VER) && !defined(STATIC_LIBDOGPUCONSENSUS)
  #define EXPORT_SYMBOL __declspec(dllimport)
#endif

#ifndef EXPORT_SYMBOL
  #define EXPORT_SYMBOL
#endif

#ifdef __cplusplus
extern "C" {
#endif

#define DOGPUCONSENSUS_API_VER 1

typedef enum dogpuconsensus_error_t
{
    dogpuconsensus_ERR_OK = 0,
    dogpuconsensus_ERR_TX_INDEX,
    dogpuconsensus_ERR_TX_SIZE_MISMATCH,
    dogpuconsensus_ERR_TX_DESERIALIZE,
    dogpuconsensus_ERR_AMOUNT_REQUIRED,
    dogpuconsensus_ERR_INVALID_FLAGS,
} dogpuconsensus_error;

/** Script verification flags */
enum
{
    dogpuconsensus_SCRIPT_FLAGS_VERIFY_NONE                = 0,
    dogpuconsensus_SCRIPT_FLAGS_VERIFY_P2SH                = (1U << 0), // evaluate P2SH (BIP16) subscripts
    dogpuconsensus_SCRIPT_FLAGS_VERIFY_DERSIG              = (1U << 2), // enforce strict DER (BIP66) compliance
    dogpuconsensus_SCRIPT_FLAGS_VERIFY_NULLDUMMY           = (1U << 4), // enforce NULLDUMMY (BIP147)
    dogpuconsensus_SCRIPT_FLAGS_VERIFY_CHECKLOCKTIMEVERIFY = (1U << 9), // enable CHECKLOCKTIMEVERIFY (BIP65)
    dogpuconsensus_SCRIPT_FLAGS_VERIFY_CHECKSEQUENCEVERIFY = (1U << 10), // enable CHECKSEQUENCEVERIFY (BIP112)
    dogpuconsensus_SCRIPT_FLAGS_VERIFY_WITNESS             = (1U << 11), // enable WITNESS (BIP141)
    dogpuconsensus_SCRIPT_FLAGS_VERIFY_ALL                 = dogpuconsensus_SCRIPT_FLAGS_VERIFY_P2SH | dogpuconsensus_SCRIPT_FLAGS_VERIFY_DERSIG |
                                                               dogpuconsensus_SCRIPT_FLAGS_VERIFY_NULLDUMMY | dogpuconsensus_SCRIPT_FLAGS_VERIFY_CHECKLOCKTIMEVERIFY |
                                                               dogpuconsensus_SCRIPT_FLAGS_VERIFY_CHECKSEQUENCEVERIFY | dogpuconsensus_SCRIPT_FLAGS_VERIFY_WITNESS
};

/// Returns 1 if the input nIn of the serialized transaction pointed to by
/// txTo correctly spends the scriptPubKey pointed to by scriptPubKey under
/// the additional constraints specified by flags.
/// If not nullptr, err will contain an error/success code for the operation
EXPORT_SYMBOL int dogpuconsensus_verify_script(const unsigned char *scriptPubKey, unsigned int scriptPubKeyLen,
                                                 const unsigned char *txTo        , unsigned int txToLen,
                                                 unsigned int nIn, unsigned int flags, dogpuconsensus_error* err);

EXPORT_SYMBOL int dogpuconsensus_verify_script_with_amount(const unsigned char *scriptPubKey, unsigned int scriptPubKeyLen, int64_t amount,
                                    const unsigned char *txTo        , unsigned int txToLen,
                                    unsigned int nIn, unsigned int flags, dogpuconsensus_error* err);

EXPORT_SYMBOL unsigned int dogpuconsensus_version();

#ifdef __cplusplus
} // extern "C"
#endif

#undef EXPORT_SYMBOL

#endif // DOGPU_DOGPUCONSENSUS_H
