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
  | Author:                                                              |
  +----------------------------------------------------------------------+
*/

/* $Id$ */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ini.h"
#include "ext/standard/info.h"
#include "php_fanta.h"

/* If you declare any globals in php_fanta.h uncomment this:
ZEND_DECLARE_MODULE_GLOBALS(fanta)
*/

/* True global resources - no need for thread safety here */
static int le_fanta;
static zend_class_entry *fanta_class_entry_ptr;

const zend_function_entry fanta_methods[] = {
	ZEND_ME(fanta, run, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

/* {{{ fanta_functions[]
 *
 * Every user visible function must have an entry in fanta_functions[].
 */
const zend_function_entry fanta_functions[] = {
	PHP_FE_END	/* Must be the last line in fanta_functions[] */
};
/* }}} */

/* {{{ fanta_module_entry
 */
zend_module_entry fanta_module_entry = {
#if ZEND_MODULE_API_NO >= 20010901
	STANDARD_MODULE_HEADER,
#endif
	"fanta",
	fanta_functions,
	PHP_MINIT(fanta),
	PHP_MSHUTDOWN(fanta),
	PHP_RINIT(fanta),		/* Replace with NULL if there's nothing to do at request start */
	PHP_RSHUTDOWN(fanta),	/* Replace with NULL if there's nothing to do at request end */
	PHP_MINFO(fanta),
#if ZEND_MODULE_API_NO >= 20010901
	PHP_FANTA_VERSION,
#endif
	STANDARD_MODULE_PROPERTIES
};
/* }}} */

#ifdef COMPILE_DL_FANTA
ZEND_GET_MODULE(fanta)
#endif

/* {{{ PHP_INI
 */
/* Remove comments and fill if you need to have entries in php.ini
PHP_INI_BEGIN()
    STD_PHP_INI_ENTRY("fanta.global_value",      "42", PHP_INI_ALL, OnUpdateLong, global_value, zend_fanta_globals, fanta_globals)
    STD_PHP_INI_ENTRY("fanta.global_string", "foobar", PHP_INI_ALL, OnUpdateString, global_string, zend_fanta_globals, fanta_globals)
PHP_INI_END()
*/
/* }}} */

/* {{{ php_fanta_init_globals
 */
/* Uncomment this function if you have INI entries
static void php_fanta_init_globals(zend_fanta_globals *fanta_globals)
{
	fanta_globals->global_value = 0;
	fanta_globals->global_string = NULL;
}
*/
/* }}} */

/* {{{ PHP_MINIT_FUNCTION
 */
PHP_MINIT_FUNCTION(fanta)
{
	/* If you have INI entries, uncomment these lines 
	REGISTER_INI_ENTRIES();
	*/
	zend_class_entry fanta_class_entry;

	INIT_CLASS_ENTRY(fanta_class_entry, "fanta", fanta_methods);
	fanta_class_entry_ptr = zend_register_internal_class(&fanta_class_entry TSRMLS_CC);

	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MSHUTDOWN_FUNCTION
 */
PHP_MSHUTDOWN_FUNCTION(fanta)
{
	/* uncomment this line if you have INI entries
	UNREGISTER_INI_ENTRIES();
	*/
	return SUCCESS;
}
/* }}} */

/* Remove if there's nothing to do at request start */
/* {{{ PHP_RINIT_FUNCTION
 */
PHP_RINIT_FUNCTION(fanta)
{
	return SUCCESS;
}
/* }}} */

/* Remove if there's nothing to do at request end */
/* {{{ PHP_RSHUTDOWN_FUNCTION
 */
PHP_RSHUTDOWN_FUNCTION(fanta)
{
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MINFO_FUNCTION
 */
PHP_MINFO_FUNCTION(fanta)
{
	php_info_print_table_start();
	php_info_print_table_header(2, "fanta support", "enabled");
	php_info_print_table_end();

	/* Remove comments if you have entries in php.ini
	DISPLAY_INI_ENTRIES();
	*/
}
/* }}} */


/* {{{ fanta->run
 */
ZEND_METHOD(fanta, run)
{
	php_printf("Im run...");
}
/* }}} */

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
