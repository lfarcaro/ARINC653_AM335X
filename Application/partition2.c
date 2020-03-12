// Partition include
#include "partition2.h"

// SNIPPET_START GLOBAL_INCLUDES
// Test include
#include "test.h"

// Measure include
#include "measure.h"

// Algorithm include
#include "algorithm.h"
// SNIPPET_END

// -------------------- PARTITION DESCRIPTION START --------------------
// SNIPPET_START PARTITION2_PARTITION_DESCRIPTION
// SNIPPET_END
// -------------------- PARTITION DESCRIPTION END --------------------

// SNIPPET_START PARTITION2_PARTITION_INCLUDES
// SNIPPET_END

// PARTITION2_PROCESS1 process identifier
static PROCESS_ID_TYPE PARTITION2_PROCESS1_PROCESS_ID;

// PARTITION2_PROCESS2 process identifier
static PROCESS_ID_TYPE PARTITION2_PROCESS2_PROCESS_ID;

// SNIPPET_START PARTITION2_PARTITION_GLOBAL_DEFINITIONS
// SNIPPET_END

// SNIPPET_START PARTITION2_PARTITION_GLOBAL_VARIABLES
// SNIPPET_END

// SNIPPET_START PARTITION2_PARTITION_FUNCTIONS
// SNIPPET_END

// -------------------- PARTITION2_PROCESS1 PROCESS START --------------------

// SNIPPET_START PARTITION2_PARTITION_PARTITION2_PROCESS1_PROCESS_GLOBAL_VARIABLES
// SNIPPET_END

// SNIPPET_START PARTITION2_PARTITION_PARTITION2_PROCESS1_PROCESS_FUNCTIONS
// SNIPPET_END

// PARTITION2_PROCESS1 process
static void PARTITION2_PROCESS1(void) {
	RETURN_CODE_TYPE RETURN_CODE;
	// SNIPPET_START PARTITION2_PARTITION_PARTITION2_PROCESS1_PROCESS_VARIABLES
	// SNIPPET_END

	// SNIPPET_START PARTITION2_PARTITION_PARTITION2_PROCESS1_PROCESS_INITIALIZATION
	// SNIPPET_END

	// Main loop
	while (true) {

		// SNIPPET_START PARTITION2_PARTITION_PARTITION2_PROCESS1_PROCESS_BEFORE_SUSPENSION_CODE
		// SNIPPET_END

		// Waits for next period
		PERIODIC_WAIT(&RETURN_CODE);
		if (RETURN_CODE != NO_ERROR) {
			// SNIPPET_START PERIODIC_WAIT_ERROR_HANDLING_CODE
			while (true) {
			}
			// SNIPPET_END
		}

		// SNIPPET_START PARTITION2_PARTITION_PARTITION2_PROCESS1_PROCESS_AFTER_SUSPENSION_CODE
		// SNIPPET_END
	}
}

// PARTITION2_PROCESS1 process attributes
static PROCESS_ATTRIBUTE_TYPE PARTITION2_PROCESS1_PROCESS_ATTRIBUTE = {
/*NAME*/(PROCESS_NAME_TYPE) "PARTITION2_PROCESS1",
/*ENTRY_POINT*/(SYSTEM_ADDRESS_TYPE) &PARTITION2_PROCESS1,
/*STACK_SIZE*/(STACK_SIZE_TYPE) 256,
/*BASE_PRIORITY*/(PRIORITY_TYPE) 10,
/*PERIOD*/(SYSTEM_TIME_TYPE) 200000000,
/*TIME_CAPACITY*/(SYSTEM_TIME_TYPE) 50000000,
/*DEADLINE*/(DEADLINE_TYPE) HARD };

// -------------------- PARTITION2_PROCESS1 PROCESS END --------------------

// -------------------- PARTITION2_PROCESS2 PROCESS START --------------------

// SNIPPET_START PARTITION2_PARTITION_PARTITION2_PROCESS2_PROCESS_GLOBAL_VARIABLES
// SNIPPET_END

// SNIPPET_START PARTITION2_PARTITION_PARTITION2_PROCESS2_PROCESS_FUNCTIONS
// SNIPPET_END

// PARTITION2_PROCESS2 process
static void PARTITION2_PROCESS2(void) {
	RETURN_CODE_TYPE RETURN_CODE;
	// SNIPPET_START PARTITION2_PARTITION_PARTITION2_PROCESS2_PROCESS_VARIABLES
	// SNIPPET_END

	// SNIPPET_START PARTITION2_PARTITION_PARTITION2_PROCESS2_PROCESS_INITIALIZATION
	// SNIPPET_END

	// Main loop
	while (true) {

		// SNIPPET_START PARTITION2_PARTITION_PARTITION2_PROCESS2_PROCESS_BEFORE_SUSPENSION_CODE
		// SNIPPET_END

		// Waits for next period
		PERIODIC_WAIT(&RETURN_CODE);
		if (RETURN_CODE != NO_ERROR) {
			// SNIPPET_START PERIODIC_WAIT_ERROR_HANDLING_CODE
			while (true) {
			}
			// SNIPPET_END
		}

		// SNIPPET_START PARTITION2_PARTITION_PARTITION2_PROCESS2_PROCESS_AFTER_SUSPENSION_CODE
		// SNIPPET_END
	}
}

// PARTITION2_PROCESS2 process attributes
static PROCESS_ATTRIBUTE_TYPE PARTITION2_PROCESS2_PROCESS_ATTRIBUTE = {
/*NAME*/(PROCESS_NAME_TYPE) "PARTITION2_PROCESS2",
/*ENTRY_POINT*/(SYSTEM_ADDRESS_TYPE) &PARTITION2_PROCESS2,
/*STACK_SIZE*/(STACK_SIZE_TYPE) 256,
/*BASE_PRIORITY*/(PRIORITY_TYPE) 20,
/*PERIOD*/(SYSTEM_TIME_TYPE) 200000000,
/*TIME_CAPACITY*/(SYSTEM_TIME_TYPE) 25000000,
/*DEADLINE*/(DEADLINE_TYPE) HARD };

// -------------------- PARTITION2_PROCESS2 PROCESS END --------------------

// PARTITION2 partition default process
void PARTITION2_DEFAULTPROCESS(void) {
	RETURN_CODE_TYPE RETURN_CODE;
	// SNIPPET_START PARTITION2_PARTITION_DEFAULTPROCESS_VARIABLES
	// SNIPPET_END

	// Creates PARTITION2_PROCESS1 process
	CREATE_PROCESS(&PARTITION2_PROCESS1_PROCESS_ATTRIBUTE, &PARTITION2_PROCESS1_PROCESS_ID, &RETURN_CODE);
	if (RETURN_CODE != NO_ERROR) {
		// SNIPPET_START CREATE_PROCESS_ERROR_HANDLING_CODE
		while (true) {
		}
		// SNIPPET_END
	}

	// Creates PARTITION2_PROCESS2 process
	CREATE_PROCESS(&PARTITION2_PROCESS2_PROCESS_ATTRIBUTE, &PARTITION2_PROCESS2_PROCESS_ID, &RETURN_CODE);
	if (RETURN_CODE != NO_ERROR) {
		// SNIPPET_START CREATE_PROCESS_ERROR_HANDLING_CODE
		while (true) {
		}
		// SNIPPET_END
	}

	// Starts PARTITION2_PROCESS1 process
	START(PARTITION2_PROCESS1_PROCESS_ID, &RETURN_CODE);
	if (RETURN_CODE != NO_ERROR) {
		// SNIPPET_START START_ERROR_HANDLING_CODE
		while (true) {
		}
		// SNIPPET_END
	}

	// Starts PARTITION2_PROCESS2 process
	START(PARTITION2_PROCESS2_PROCESS_ID, &RETURN_CODE);
	if (RETURN_CODE != NO_ERROR) {
		// SNIPPET_START START_ERROR_HANDLING_CODE
		while (true) {
		}
		// SNIPPET_END
	}

	// SNIPPET_START PARTITION2_PARTITION_DEFAULTPROCESS_INITIALIZATION
	// SNIPPET_END

	// Sets partition mode
	SET_PARTITION_MODE(NORMAL, &RETURN_CODE);
	if (RETURN_CODE != NO_ERROR) {
		// SNIPPET_START SET_PARTITION_MODE_ERROR_HANDLING_CODE
		while (true) {
		}
		// SNIPPET_END
	}

	// Start of idle process

	// SNIPPET_START PARTITION2_PARTITION_IDLEPROCESS_INITIALIZATION
	// SNIPPET_END

	// Main loop
	while (true) {

		// SNIPPET_START PARTITION2_PARTITION_IDLEPROCESS_CODE
		// Sets LEDs pattern
		TEST_LED1_OFF();
		TEST_LED2_ON();
		// SNIPPET_END
	}
}
