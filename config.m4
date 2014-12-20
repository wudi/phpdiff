dnl $Id$
dnl config.m4 for extension phpdiff

dnl Comments in this file start with the string 'dnl'.
dnl Remove where necessary. This file will not work
dnl without editing.

dnl If your extension references something external, use with:

PHP_ARG_WITH(phpdiff, for phpdiff support,
Make sure that the comment is aligned:
[  --with-phpdiff             Include phpdiff support])

dnl Otherwise use enable:

dnl PHP_ARG_ENABLE(phpdiff, whether to enable phpdiff support,
dnl Make sure that the comment is aligned:
dnl [  --enable-phpdiff           Enable phpdiff support])

if test "$PHP_PHPDIFF" != "no"; then
  dnl Write more examples of tests here...

  dnl # --with-phpdiff -> check with-path
  dnl SEARCH_PATH="/usr/local /usr"     # you might want to change this
  dnl SEARCH_FOR="/include/phpdiff.h"  # you most likely want to change this
  dnl if test -r $PHP_PHPDIFF/$SEARCH_FOR; then # path given as parameter
  dnl   PHPDIFF_DIR=$PHP_PHPDIFF
  dnl else # search default path list
  dnl   AC_MSG_CHECKING([for phpdiff files in default path])
  dnl   for i in $SEARCH_PATH ; do
  dnl     if test -r $i/$SEARCH_FOR; then
  dnl       PHPDIFF_DIR=$i
  dnl       AC_MSG_RESULT(found in $i)
  dnl     fi
  dnl   done
  dnl fi
  dnl
  dnl if test -z "$PHPDIFF_DIR"; then
  dnl   AC_MSG_RESULT([not found])
  dnl   AC_MSG_ERROR([Please reinstall the phpdiff distribution])
  dnl fi

  dnl # --with-phpdiff -> add include path
  dnl PHP_ADD_INCLUDE($PHPDIFF_DIR/include)

  dnl # --with-phpdiff -> check for lib and symbol presence
  dnl LIBNAME=phpdiff # you may want to change this
  dnl LIBSYMBOL=phpdiff # you most likely want to change this 

  dnl PHP_CHECK_LIBRARY($LIBNAME,$LIBSYMBOL,
  dnl [
  dnl   PHP_ADD_LIBRARY_WITH_PATH($LIBNAME, $PHPDIFF_DIR/$PHP_LIBDIR, PHPDIFF_SHARED_LIBADD)
  dnl   AC_DEFINE(HAVE_PHPDIFFLIB,1,[ ])
  dnl ],[
  dnl   AC_MSG_ERROR([wrong phpdiff lib version or lib not found])
  dnl ],[
  dnl   -L$PHPDIFF_DIR/$PHP_LIBDIR -lm
  dnl ])
  dnl
  dnl PHP_SUBST(PHPDIFF_SHARED_LIBADD)

  PHP_NEW_EXTENSION(phpdiff, phpdiff.c, $ext_shared)
fi
