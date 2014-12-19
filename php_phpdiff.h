/*
 * bsdiff license
 */

/*-
 * Copyright 2003-2005 Colin Percival
 * All rights reserved
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted providing that the following conditions 
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
 * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

/*
  +----------------------------------------------------------------------+
  | PHP Version 5                                                        |
  +----------------------------------------------------------------------+
  | Copyright (c) 1997-2014 The PHP Group                                |
  +----------------------------------------------------------------------+
  | This source file is subject to version 3.01 of the PHP license,      |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.php.net/license/3_01.txt                                  |
  | If you did not receive a copy of the PHP license and are unable to   |
  | obtain it through the world-wide-web, please send a note to          |
  | license@php.net so we can mail you a copy immediately.               |
  +----------------------------------------------------------------------+
  | PHP Extension Author: eagle(0x07de@gmail.com)                        |
  | Diff Arithmetic: bsdiff(http://www.daemonology.net/bsdiff/)          |
  +----------------------------------------------------------------------+
*/

/* $Id$ */

#ifndef PHP_PHPDIFF_H
#define PHP_PHPDIFF_H

extern zend_module_entry phpdiff_module_entry;
#define phpext_phpdiff_ptr &phpdiff_module_entry

#define PHP_PHPDIFF_VERSION "0.1.0" /* Replace with version number for your extension */

#ifdef PHP_WIN32
# define PHP_PHPDIFF_API __declspec(dllexport)
#elif defined(__GNUC__) && __GNUC__ >= 4
# define PHP_PHPDIFF_API __attribute__ ((visibility("default")))
#else
# define PHP_PHPDIFF_API
#endif

#ifdef ZTS
#include "TSRM.h"
#endif

#include <sys/types.h>

#include <bzlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MIN(x,y) (((x)<(y)) ? (x) : (y))

PHP_MINIT_FUNCTION(phpdiff);
PHP_MSHUTDOWN_FUNCTION(phpdiff);
PHP_RINIT_FUNCTION(phpdiff);
PHP_RSHUTDOWN_FUNCTION(phpdiff);
PHP_MINFO_FUNCTION(phpdiff);

PHP_FUNCTION(bsdiff);
PHP_FUNCTION(bspatch);


#define BSDIFF_VERSION 4.3
/*
 bsdiff.c
*/
static void split(off_t *I,off_t *V,off_t start,off_t len,off_t h);
static void qsufsort(off_t *I,off_t *V,u_char *old,off_t oldsize);
static off_t matchlen(u_char *old,off_t oldsize,u_char *new,off_t newsize);
static off_t search(off_t *I,u_char *old,off_t oldsize,
    u_char *new,off_t newsize,off_t st,off_t en,off_t *pos);
static void offtout(off_t x,u_char *buf);

/*
 * bspatch.c
 */
static off_t offtin(u_char *buf);

/* 
    Declare any global variables you may need between the BEGIN
  and END macros here:     

ZEND_BEGIN_MODULE_GLOBALS(phpdiff)
  long  global_value;
  char *global_string;
ZEND_END_MODULE_GLOBALS(phpdiff)
*/

/* In every utility function you add that needs to use variables 
   in php_phpdiff_globals, call TSRMLS_FETCH(); after declaring other 
   variables used by that function, or better yet, pass in TSRMLS_CC
   after the last function argument and declare your utility function
   with TSRMLS_DC after the last declared argument.  Always refer to
   the globals in your function as PHPDIFF_G(variable).  You are 
   encouraged to rename these macros something shorter, see
   examples in any other php module directory.
*/

#ifdef ZTS
#define PHPDIFF_G(v) TSRMG(phpdiff_globals_id, zend_phpdiff_globals *, v)
#else
#define PHPDIFF_G(v) (phpdiff_globals.v)
#endif

#endif  /* PHP_PHPDIFF_H */


/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
