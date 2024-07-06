#!/bin/sh

TOPDIR=${TOPDIR:-$(git rev-parse --show-toplevel)}
SRCDIR=${SRCDIR:-$TOPDIR/src}
MANDIR=${MANDIR:-$TOPDIR/doc/man}

DOGPUD=${DOGPUD:-$SRCDIR/dogpud}
DOGPUCLI=${DOGPUCLI:-$SRCDIR/dogpu-cli}
DOGPUTX=${DOGPUTX:-$SRCDIR/dogpu-tx}
DOGPUQT=${DOGPUQT:-$SRCDIR/qt/dogpu-qt}

[ ! -x $DOGPUD ] && echo "$DOGPUD not found or not executable." && exit 1

# The autodetected version git tag can screw up manpage output a little bit
DOGPUSVER=($($DOGPUCLI --version | head -n1 | awk -F'[ -]' '{ print $6, $7 }'))

# Create a footer file with copyright content.
# This gets autodetected fine for dogpud if --version-string is not set,
# but has different outcomes for dogpu-qt and dogpu-cli.
echo "[COPYRIGHT]" > footer.h2m
$DOGPUD --version | sed -n '1!p' >> footer.h2m

for cmd in $DOGPUD $DOGPUCLI $DOGPUTX $DOGPUQT; do
  cmdname="${cmd##*/}"
  help2man -N --version-string=${DOGPUSVER[0]} --include=footer.h2m -o ${MANDIR}/${cmdname}.1 ${cmd}
  sed -i "s/\\\-${DOGPUSVER[1]}//g" ${MANDIR}/${cmdname}.1
done

rm -f footer.h2m
