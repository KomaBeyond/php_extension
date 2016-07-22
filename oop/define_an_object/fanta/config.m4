dnl $Id$
dnl config.m4 for extension fanta

dnl Comments in this file start with the string 'dnl'.
dnl Remove where necessary. This file will not work
dnl without editing.

dnl If your extension references something external, use with:

dnl PHP_ARG_WITH(fanta, for fanta support,
dnl Make sure that the comment is aligned:
dnl [  --with-fanta             Include fanta support])

dnl Otherwise use enable:

PHP_ARG_ENABLE(fanta, whether to enable fanta support,
dnl Make sure that the comment is aligned:
[  --enable-fanta           Enable fanta support])

if test "$PHP_FANTA" != "no"; then
  dnl Write more examples of tests here...

  dnl # --with-fanta -> check with-path
  dnl SEARCH_PATH="/usr/local /usr"     # you might want to change this
  dnl SEARCH_FOR="/include/fanta.h"  # you most likely want to change this
  dnl if test -r $PHP_FANTA/$SEARCH_FOR; then # path given as parameter
  dnl   FANTA_DIR=$PHP_FANTA
  dnl else # search default path list
  dnl   AC_MSG_CHECKING([for fanta files in default path])
  dnl   for i in $SEARCH_PATH ; do
  dnl     if test -r $i/$SEARCH_FOR; then
  dnl       FANTA_DIR=$i
  dnl       AC_MSG_RESULT(found in $i)
  dnl     fi
  dnl   done
  dnl fi
  dnl
  dnl if test -z "$FANTA_DIR"; then
  dnl   AC_MSG_RESULT([not found])
  dnl   AC_MSG_ERROR([Please reinstall the fanta distribution])
  dnl fi

  dnl # --with-fanta -> add include path
  dnl PHP_ADD_INCLUDE($FANTA_DIR/include)

  dnl # --with-fanta -> check for lib and symbol presence
  dnl LIBNAME=fanta # you may want to change this
  dnl LIBSYMBOL=fanta # you most likely want to change this 

  dnl PHP_CHECK_LIBRARY($LIBNAME,$LIBSYMBOL,
  dnl [
  dnl   PHP_ADD_LIBRARY_WITH_PATH($LIBNAME, $FANTA_DIR/lib, FANTA_SHARED_LIBADD)
  dnl   AC_DEFINE(HAVE_FANTALIB,1,[ ])
  dnl ],[
  dnl   AC_MSG_ERROR([wrong fanta lib version or lib not found])
  dnl ],[
  dnl   -L$FANTA_DIR/lib -lm
  dnl ])
  dnl
  dnl PHP_SUBST(FANTA_SHARED_LIBADD)

  PHP_NEW_EXTENSION(fanta, fanta.c, $ext_shared)
fi
