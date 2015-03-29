#include "CUnit/CUnit.h"
#include "CUnit/Basic.h"
#include "CUnit/Automated.h"
#include "CUnit/Console.h"

#include "shift.h"

#include <stdio.h>


/* Test Suite setup and cleanup functions: */

int init_suite(void) { return 0; }
int clean_suite(void) { return 0; }

/************* Test case functions ****************/
void test_shift_string(void) {
	
	char ch[]="a";
	char str_short[]="abcde";
	char str_eight[]="abcdefg ";
	char str_long[]="abcdefghijklmno ";
	
	CU_ASSERT_STRING_EQUAL(shift_left(ch),"a");
	CU_ASSERT_STRING_EQUAL(shift_left(str_short),"bcdea");
	CU_ASSERT_STRING_EQUAL(shift_left(str_eight),"bcdefg a");
	CU_ASSERT_STRING_EQUAL(shift_left(str_long),"bcdefghijklmno a");
}

/************* Test Runner Code goes here **************/

int main ( void )
{
   CU_pSuite pSuite = NULL;

   /* initialize the CUnit test registry */
   if ( CUE_SUCCESS != CU_initialize_registry() )
      return CU_get_error();

   /* add a suite to the registry */
   pSuite = CU_add_suite( "shift_testsuite", init_suite, clean_suite );
   if ( NULL == pSuite ) {
      CU_cleanup_registry();
      return CU_get_error();
   }
	
   /* add the tests to the suite */
   if ( 
		(NULL == CU_add_test(pSuite, "Shift string", test_shift_string))
      )
   {
      CU_cleanup_registry();
      return CU_get_error();
   }



   // Run all tests using the basic interface
   CU_basic_set_mode(CU_BRM_VERBOSE);
   CU_basic_run_tests();
   printf("\n");
   CU_basic_show_failures(CU_get_failure_list());
   printf("\n\n");

   // Run all tests using the automated interface
   CU_automated_run_tests();
   CU_list_tests_to_file();

   // Run all tests using the console interface
   CU_console_run_tests();

   /* Clean up registry and return */
   CU_cleanup_registry();
   return CU_get_error();
}
