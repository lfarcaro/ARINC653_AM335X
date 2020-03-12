// Module include
#include "module.h"

// Configuration include
#include "configuration.h"

// SNIPPET_START GLOBAL_INCLUDES
// Test include
#include "test.h"

// Measure include
#include "measure.h"

// Algorithm include
#include "algorithm.h"
// SNIPPET_END

// -------------------- MODULE DESCRIPTION START --------------------
// SNIPPET_START MODULE_DESCRIPTION
// SNIPPET_END
// -------------------- MODULE DESCRIPTION END --------------------

// SNIPPET_START MODULE_INCLUDES
// SNIPPET_END

// PARTITION1 partition attributes
static PARTITION_ATTRIBUTE_TYPE PARTITION1_PARTITION_ATTRIBUTE = {
/*NAME*/(PARTITION_NAME_TYPE) "PARTITION1",
/*ENTRY_POINT*/(SYSTEM_ADDRESS_TYPE) &PARTITION1_DEFAULTPROCESS,
/*STACK_SIZE*/(STACK_SIZE_TYPE) 256,
/*SYSTEMPARTITION*/(BOOLEAN_TYPE) false };

// PARTITION1 partition identifier
static PARTITION_ID_TYPE PARTITION1_PARTITION_ID;

// PARTITION2 partition attributes
static PARTITION_ATTRIBUTE_TYPE PARTITION2_PARTITION_ATTRIBUTE = {
/*NAME*/(PARTITION_NAME_TYPE) "PARTITION2",
/*ENTRY_POINT*/(SYSTEM_ADDRESS_TYPE) &PARTITION2_DEFAULTPROCESS,
/*STACK_SIZE*/(STACK_SIZE_TYPE) 256,
/*SYSTEMPARTITION*/(BOOLEAN_TYPE) false };

// PARTITION2 partition identifier
static PARTITION_ID_TYPE PARTITION2_PARTITION_ID;

// PARTITION3 partition attributes
static PARTITION_ATTRIBUTE_TYPE PARTITION3_PARTITION_ATTRIBUTE = {
/*NAME*/(PARTITION_NAME_TYPE) "PARTITION3",
/*ENTRY_POINT*/(SYSTEM_ADDRESS_TYPE) &PARTITION3_DEFAULTPROCESS,
/*STACK_SIZE*/(STACK_SIZE_TYPE) 256,
/*SYSTEMPARTITION*/(BOOLEAN_TYPE) false };

// PARTITION3 partition identifier
static PARTITION_ID_TYPE PARTITION3_PARTITION_ID;

// SNIPPET_START MODULE_GLOBAL_DEFINITIONS
// Definitions
#define COMMAND_HANDSHAKE 0x005AA500
#define COMMAND_CONFIGURE 0x11000011
#define COMMAND_MEASURE 0xFF0000FF
#define RESPONSE_ERROR 0x00000000
#define RESPONSE_SUCCESS 0x11111111

// Definitions
#define COMMAND_CONFIGURE_BPRED_DIS MEASURE_FLAG_BPRED_DIS
#define COMMAND_CONFIGURE_BPRED_ENA MEASURE_FLAG_BPRED_ENA
#define COMMAND_CONFIGURE_BPRED_CLR MEASURE_FLAG_BPRED_CLR
#define COMMAND_CONFIGURE_DCACHE_DIS MEASURE_FLAG_DCACHE_DIS
#define COMMAND_CONFIGURE_DCACHE_ENA MEASURE_FLAG_DCACHE_ENA
#define COMMAND_CONFIGURE_DCACHE_CLR MEASURE_FLAG_DCACHE_CLR
#define COMMAND_CONFIGURE_ICACHE_DIS MEASURE_FLAG_ICACHE_DIS
#define COMMAND_CONFIGURE_ICACHE_ENA MEASURE_FLAG_ICACHE_ENA
#define COMMAND_CONFIGURE_ICACHE_CLR MEASURE_FLAG_ICACHE_CLR
// SNIPPET_END

// SNIPPET_START MODULE_GLOBAL_VARIABLES
// SNIPPET_END

// SNIPPET_START MODULE_FUNCTIONS
portBOOLEAN READ_INTEGER(portUINT32 *INTEGER) {
	portINT32 BYTE1, BYTE2, BYTE3, BYTE4;

	// Receives bytes
	if ((BYTE1 = UARTConsoleGetcTimeout(5000000)) == -1) {
        return false;
    }
	if ((BYTE2 = UARTConsoleGetcTimeout(5000)) == -1) {
	    return false;
	}
	if ((BYTE3 = UARTConsoleGetcTimeout(5000)) == -1) {
        return false;
    }
	if ((BYTE4 = UARTConsoleGetcTimeout(5000)) == -1) {
        return false;
    }

	// Returns
	*INTEGER = ((BYTE1 & 0xFF) << 24) | ((BYTE2 & 0xFF) << 16) | ((BYTE3 & 0xFF) << 8) | ((BYTE4 & 0xFF) << 0);
	return true;
}

void WRITE_INTEGER(portUINT32 INTEGER) {
	portBYTE BYTE1, BYTE2, BYTE3, BYTE4;

	// Splits
	BYTE1 = (INTEGER >> 24) & 0xFF;
	BYTE2 = (INTEGER >> 16) & 0xFF;
	BYTE3 = (INTEGER >> 8) & 0xFF;
	BYTE4 = INTEGER & 0xFF;

	// Transmits
	UARTConsolePutc(BYTE1);
	UARTConsolePutc(BYTE2);
	UARTConsolePutc(BYTE3);
	UARTConsolePutc(BYTE4);
}
// SNIPPET_END

// Module default partition
void MODULE_DEFAULTPARTITION(void) {
	RETURN_CODE_TYPE RETURN_CODE;
	// SNIPPET_START MODULE_DEFAULTPARTITION_VARIABLES
	portUINT32 VALUE;
	// SNIPPET_END

	// Starts system up
	STARTUP_SYSTEM(&RETURN_CODE);
	if (RETURN_CODE != NO_ERROR) {
		// SNIPPET_START STARTUP_SYSTEM_ERROR_HANDLING_CODE
		while (true) {
		}
		// SNIPPET_END
	}

	// Starts module up
	STARTUP_MODULE(&RETURN_CODE);
	if (RETURN_CODE != NO_ERROR) {
		// SNIPPET_START STARTUP_MODULE_ERROR_HANDLING_CODE
		while (true) {
		}
		// SNIPPET_END
	}

	// Creates PARTITION1 partition
	CREATE_PARTITION(&PARTITION1_PARTITION_ATTRIBUTE, &PARTITION1_PARTITION_ID, &RETURN_CODE);
	if (RETURN_CODE != NO_ERROR) {
		// SNIPPET_START CREATE_PARTITION_ERROR_HANDLING_CODE
		while (true) {
		}
		// SNIPPET_END
	}

	// Creates PARTITION2 partition
	CREATE_PARTITION(&PARTITION2_PARTITION_ATTRIBUTE, &PARTITION2_PARTITION_ID, &RETURN_CODE);
	if (RETURN_CODE != NO_ERROR) {
		// SNIPPET_START CREATE_PARTITION_ERROR_HANDLING_CODE
		while (true) {
		}
		// SNIPPET_END
	}

	// Creates PARTITION3 partition
	CREATE_PARTITION(&PARTITION3_PARTITION_ATTRIBUTE, &PARTITION3_PARTITION_ID, &RETURN_CODE);
	if (RETURN_CODE != NO_ERROR) {
		// SNIPPET_START CREATE_PARTITION_ERROR_HANDLING_CODE
		while (true) {
		}
		// SNIPPET_END
	}

	// SNIPPET_START MODULE_DEFAULTPARTITION_INITIALIZATION
	// Starts up test
	TEST_STARTUP();

	// Starts up measure
	MEASURE_STARTUP();

	// Starts up algorithm
	ALGORITHM_STARTUP();
	// SNIPPET_END

	// Sets module mode
	SET_MODULE_MODE(NORMAL, &RETURN_CODE);
	if (RETURN_CODE != NO_ERROR) {
		// SNIPPET_START SET_MODULE_MODE_ERROR_HANDLING_CODE
		while (true) {
		}
		// SNIPPET_END
	}

	// Start of idle partition

	// SNIPPET_START MODULE_IDLEPARTITION_INITIALIZATION
	// SNIPPET_END

	// Main loop
	while (true) {

		// SNIPPET_START MODULE_IDLEPARTITION_CODE
        // Reads command
        if (!READ_INTEGER(&VALUE)) {
            continue;
        }

        // Verifies command
        if (VALUE == COMMAND_HANDSHAKE) {

            // Replies handshake
            WRITE_INTEGER(VALUE);
        } else if (VALUE == COMMAND_CONFIGURE) {

            // Reads flags
            if (!READ_INTEGER(&VALUE)) {
                continue;
            }

            // Configures measurement
            MEASURE_CONFIGURE(VALUE);
        } else if (VALUE == COMMAND_MEASURE) {

            // Confirms command
            WRITE_INTEGER(VALUE);

            // Initializes algorithm
            ALGORITHM_INITIALIZE();

            // Triggers measurement
            MEASURE_TRIGGER();

            // Reads measurement
            VALUE = MEASURE_READ();

            // Writes measurement
            WRITE_INTEGER(VALUE);
        } else {

            // Writes response
            WRITE_INTEGER(RESPONSE_ERROR);
        }
		// SNIPPET_END
	}
}
