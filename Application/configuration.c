// Module include
#include "module.h"

// PARTITION1 partition configuration schedule window
static PARTITION_CONFIGURATION_SCHEDULE_WINDOW_TYPE PARTITION1_PARTITION_CONFIGURATION_SCHEDULE_WINDOW[2] = {
/*1*/{/*START*/(SYSTEM_TIME_TYPE) 0, /*DURATION*/(SYSTEM_TIME_TYPE) 1000000000, /*PERIOD_START*/(BOOLEAN_TYPE) true },
/*2*/{/*START*/(SYSTEM_TIME_TYPE) 2000000000, /*DURATION*/(SYSTEM_TIME_TYPE) 1000000000, /*PERIOD_START*/(BOOLEAN_TYPE) true } };

// PARTITION1 partition configuration schedule
static PARTITION_CONFIGURATION_SCHEDULE_TYPE PARTITION1_PARTITION_CONFIGURATION_SCHEDULE = {
/*PERIOD*/(SYSTEM_TIME_TYPE) 2000000000,
/*DURATION*/(SYSTEM_TIME_TYPE) 1000000000,
/*SCHEDULE_WINDOW_SIZE*/(SIZE_TYPE) 2,
/*SCHEDULE_WINDOW*/PARTITION1_PARTITION_CONFIGURATION_SCHEDULE_WINDOW };

// PARTITION2 partition configuration schedule window
static PARTITION_CONFIGURATION_SCHEDULE_WINDOW_TYPE PARTITION2_PARTITION_CONFIGURATION_SCHEDULE_WINDOW[2] = {
/*1*/{/*START*/(SYSTEM_TIME_TYPE) 1000000000, /*DURATION*/(SYSTEM_TIME_TYPE) 500000000, /*PERIOD_START*/(BOOLEAN_TYPE) true },
/*2*/{/*START*/(SYSTEM_TIME_TYPE) 3000000000, /*DURATION*/(SYSTEM_TIME_TYPE) 500000000, /*PERIOD_START*/(BOOLEAN_TYPE) true } };

// PARTITION2 partition configuration schedule
static PARTITION_CONFIGURATION_SCHEDULE_TYPE PARTITION2_PARTITION_CONFIGURATION_SCHEDULE = {
/*PERIOD*/(SYSTEM_TIME_TYPE) 2000000000,
/*DURATION*/(SYSTEM_TIME_TYPE) 500000000,
/*SCHEDULE_WINDOW_SIZE*/(SIZE_TYPE) 2,
/*SCHEDULE_WINDOW*/PARTITION2_PARTITION_CONFIGURATION_SCHEDULE_WINDOW };

// PARTITION3 partition configuration schedule window
static PARTITION_CONFIGURATION_SCHEDULE_WINDOW_TYPE PARTITION3_PARTITION_CONFIGURATION_SCHEDULE_WINDOW[1] = {
/*1*/{/*START*/(SYSTEM_TIME_TYPE) 1500000000, /*DURATION*/(SYSTEM_TIME_TYPE) 250000000, /*PERIOD_START*/(BOOLEAN_TYPE) true } };

// PARTITION3 partition configuration schedule
static PARTITION_CONFIGURATION_SCHEDULE_TYPE PARTITION3_PARTITION_CONFIGURATION_SCHEDULE = {
/*PERIOD*/(SYSTEM_TIME_TYPE) 4000000000,
/*DURATION*/(SYSTEM_TIME_TYPE) 250000000,
/*SCHEDULE_WINDOW_SIZE*/(SIZE_TYPE) 1,
/*SCHEDULE_WINDOW*/PARTITION3_PARTITION_CONFIGURATION_SCHEDULE_WINDOW };

// Partition configuration
static PARTITION_CONFIGURATION_TYPE PARTITION_CONFIGURATION[3] = {

/*PARTITION1 partition*/{
/*EXTERNAL_IDENTIFIER*/(PARTITION_ID_TYPE) 1,
/*NAME*/(PARTITION_NAME_TYPE) "PARTITION1",
/*MAXIMUM_PROCESS_COUNT*/(SIZE_TYPE) 0,
/*MAXIMUM_ERRORSTATUS_COUNT*/(SIZE_TYPE) 0,
/*MAXIMUM_SAMPLINGPORT_COUNT*/(SIZE_TYPE) 0,
/*MAXIMUM_QUEUINGPORT_COUNT*/(SIZE_TYPE) 0,
/*MAXIMUM_BUFFER_COUNT*/(SIZE_TYPE) 0,
/*MAXIMUM_BLACKBOARD_COUNT*/(SIZE_TYPE) 0,
/*MAXIMUM_SEMAPHORE_COUNT*/(SIZE_TYPE) 0,
/*MAXIMUM_EVENT_COUNT*/(SIZE_TYPE) 0,
/*PARTITION_CODE_ADDRESS*/(SYSTEM_ADDRESS_TYPE) 0x80025000,
/*PARTITION_CODE_SIZE*/(SIZE_TYPE) 0x00001000,
/*PARTITION_DATA_ADDRESS*/(SYSTEM_ADDRESS_TYPE) 0x80026000,
/*PARTITION_DATA_SIZE*/(SIZE_TYPE) 0x00001000,
/*PARTITION_DATA_IMAGE_ADDRESS*/(SYSTEM_ADDRESS_TYPE) 0x80338000,
/*PARTITION_DATA_IMAGE_SIZE*/(SIZE_TYPE) 0x00001000,
/*PARTITION_HEAP_ADDRESS*/(SYSTEM_ADDRESS_TYPE) 0x80134000,
/*PARTITION_HEAP_SIZE*/(SIZE_TYPE) 0x00001000,
/*PARTITION_DEFAULTPROCESS_STACK_ADDRESS*/(SYSTEM_ADDRESS_TYPE) 0x80030000,
/*PARTITION_DEFAULTPROCESS_STACK_SIZE*/(SIZE_TYPE) 0x00001000,
/*PARTITION_ERRORHANDLER_STACK_ADDRESS*/(SYSTEM_ADDRESS_TYPE) null,
/*PARTITION_ERRORHANDLER_STACK_SIZE*/(SIZE_TYPE) null,
/*PARTITION_HMCALLBACK_STACK_ADDRESS*/(SYSTEM_ADDRESS_TYPE) null,
/*PARTITION_HMCALLBACK_STACK_SIZE*/(SIZE_TYPE) null,
/*PARTITION_CONFIGURATION_SCHEDULE*/&PARTITION1_PARTITION_CONFIGURATION_SCHEDULE,
/*PARTITION_CONFIGURATION_HEALTHMONITORING*/(PARTITION_CONFIGURATION_HEALTHMONITORING_TYPE *) null,
/*PROCESS_CONFIGURATION_SIZE*/(SIZE_TYPE) 0,
/*PROCESS_CONFIGURATION*/(PROCESS_CONFIGURATION_TYPE *) null,
/*PORT_PARTITION_CONFIGURATION*/(SYSTEM_ADDRESS_TYPE) null },

/*PARTITION2 partition*/{
/*EXTERNAL_IDENTIFIER*/(PARTITION_ID_TYPE) 2,
/*NAME*/(PARTITION_NAME_TYPE) "PARTITION2",
/*MAXIMUM_PROCESS_COUNT*/(SIZE_TYPE) 0,
/*MAXIMUM_ERRORSTATUS_COUNT*/(SIZE_TYPE) 0,
/*MAXIMUM_SAMPLINGPORT_COUNT*/(SIZE_TYPE) 0,
/*MAXIMUM_QUEUINGPORT_COUNT*/(SIZE_TYPE) 0,
/*MAXIMUM_BUFFER_COUNT*/(SIZE_TYPE) 0,
/*MAXIMUM_BLACKBOARD_COUNT*/(SIZE_TYPE) 0,
/*MAXIMUM_SEMAPHORE_COUNT*/(SIZE_TYPE) 0,
/*MAXIMUM_EVENT_COUNT*/(SIZE_TYPE) 0,
/*PARTITION_CODE_ADDRESS*/(SYSTEM_ADDRESS_TYPE) 0x80027000,
/*PARTITION_CODE_SIZE*/(SIZE_TYPE) 0x00001000,
/*PARTITION_DATA_ADDRESS*/(SYSTEM_ADDRESS_TYPE) 0x80028000,
/*PARTITION_DATA_SIZE*/(SIZE_TYPE) 0x00001000,
/*PARTITION_DATA_IMAGE_ADDRESS*/(SYSTEM_ADDRESS_TYPE) 0x80339000,
/*PARTITION_DATA_IMAGE_SIZE*/(SIZE_TYPE) 0x00001000,
/*PARTITION_HEAP_ADDRESS*/(SYSTEM_ADDRESS_TYPE) 0x80135000,
/*PARTITION_HEAP_SIZE*/(SIZE_TYPE) 0x00001000,
/*PARTITION_DEFAULTPROCESS_STACK_ADDRESS*/(SYSTEM_ADDRESS_TYPE) 0x80031000,
/*PARTITION_DEFAULTPROCESS_STACK_SIZE*/(SIZE_TYPE) 0x00001000,
/*PARTITION_ERRORHANDLER_STACK_ADDRESS*/(SYSTEM_ADDRESS_TYPE) null,
/*PARTITION_ERRORHANDLER_STACK_SIZE*/(SIZE_TYPE) null,
/*PARTITION_HMCALLBACK_STACK_ADDRESS*/(SYSTEM_ADDRESS_TYPE) null,
/*PARTITION_HMCALLBACK_STACK_SIZE*/(SIZE_TYPE) null,
/*PARTITION_CONFIGURATION_SCHEDULE*/&PARTITION2_PARTITION_CONFIGURATION_SCHEDULE,
/*PARTITION_CONFIGURATION_HEALTHMONITORING*/(PARTITION_CONFIGURATION_HEALTHMONITORING_TYPE *) null,
/*PROCESS_CONFIGURATION_SIZE*/(SIZE_TYPE) 0,
/*PROCESS_CONFIGURATION*/(PROCESS_CONFIGURATION_TYPE *) null,
/*PORT_PARTITION_CONFIGURATION*/(SYSTEM_ADDRESS_TYPE) null },

/*PARTITION3 partition*/{
/*EXTERNAL_IDENTIFIER*/(PARTITION_ID_TYPE) 3,
/*NAME*/(PARTITION_NAME_TYPE) "PARTITION3",
/*MAXIMUM_PROCESS_COUNT*/(SIZE_TYPE) 0,
/*MAXIMUM_ERRORSTATUS_COUNT*/(SIZE_TYPE) 0,
/*MAXIMUM_SAMPLINGPORT_COUNT*/(SIZE_TYPE) 0,
/*MAXIMUM_QUEUINGPORT_COUNT*/(SIZE_TYPE) 0,
/*MAXIMUM_BUFFER_COUNT*/(SIZE_TYPE) 0,
/*MAXIMUM_BLACKBOARD_COUNT*/(SIZE_TYPE) 0,
/*MAXIMUM_SEMAPHORE_COUNT*/(SIZE_TYPE) 0,
/*MAXIMUM_EVENT_COUNT*/(SIZE_TYPE) 0,
/*PARTITION_CODE_ADDRESS*/(SYSTEM_ADDRESS_TYPE) 0x80029000,
/*PARTITION_CODE_SIZE*/(SIZE_TYPE) 0x00001000,
/*PARTITION_DATA_ADDRESS*/(SYSTEM_ADDRESS_TYPE) 0x8002A000,
/*PARTITION_DATA_SIZE*/(SIZE_TYPE) 0x00001000,
/*PARTITION_DATA_IMAGE_ADDRESS*/(SYSTEM_ADDRESS_TYPE) 0x8033A000,
/*PARTITION_DATA_IMAGE_SIZE*/(SIZE_TYPE) 0x00001000,
/*PARTITION_HEAP_ADDRESS*/(SYSTEM_ADDRESS_TYPE) 0x80136000,
/*PARTITION_HEAP_SIZE*/(SIZE_TYPE) 0x00001000,
/*PARTITION_DEFAULTPROCESS_STACK_ADDRESS*/(SYSTEM_ADDRESS_TYPE) 0x80032000,
/*PARTITION_DEFAULTPROCESS_STACK_SIZE*/(SIZE_TYPE) 0x00001000,
/*PARTITION_ERRORHANDLER_STACK_ADDRESS*/(SYSTEM_ADDRESS_TYPE) null,
/*PARTITION_ERRORHANDLER_STACK_SIZE*/(SIZE_TYPE) null,
/*PARTITION_HMCALLBACK_STACK_ADDRESS*/(SYSTEM_ADDRESS_TYPE) null,
/*PARTITION_HMCALLBACK_STACK_SIZE*/(SIZE_TYPE) null,
/*PARTITION_CONFIGURATION_SCHEDULE*/&PARTITION3_PARTITION_CONFIGURATION_SCHEDULE,
/*PARTITION_CONFIGURATION_HEALTHMONITORING*/(PARTITION_CONFIGURATION_HEALTHMONITORING_TYPE *) null,
/*PROCESS_CONFIGURATION_SIZE*/(SIZE_TYPE) 0,
/*PROCESS_CONFIGURATION*/(PROCESS_CONFIGURATION_TYPE *) null,
/*PORT_PARTITION_CONFIGURATION*/(SYSTEM_ADDRESS_TYPE) null } };

// Port module configuration
static PORT_MODULE_CONFIGURATION_TYPE PORT_MODULE_CONFIGURATION = {
/*STACK_AREA_START_ADDRESS*/(portADDRESS) 0x8002B000,
/*STACK_AREA_END_ADDRESS*/(portADDRESS) 0x80034000,
/*MODULE_NETWORK_PHYSICAL_ADDRESS*/{ 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 1, 1, 16, 16 } };

// Module configuration
MODULE_CONFIGURATION_TYPE MODULE_CONFIGURATION = {
/*MAXIMUM_PARTITION_COUNT*/(SIZE_TYPE) 3,
/*MODULE_CODE_ADDRESS*/(SYSTEM_ADDRESS_TYPE) 0x80023000,
/*MODULE_CODE_SIZE*/(SIZE_TYPE) 0x00001000,
/*MODULE_DATA_ADDRESS*/(SYSTEM_ADDRESS_TYPE) 0x80024000,
/*MODULE_DATA_SIZE*/(SIZE_TYPE) 0x00001000,
/*MODULE_HMCALLBACK_STACK_ADDRESS*/(SYSTEM_ADDRESS_TYPE) null,
/*MODULE_HMCALLBACK_STACK_SIZE*/(SIZE_TYPE) null,
/*MAJORFRAME_DURATION*/(SYSTEM_TIME_TYPE) 4000000000,
/*MODULE_CONFIGURATION_CONNECTIONTABLE*/(MODULE_CONFIGURATION_CONNECTIONTABLE_TYPE *) null,
/*MODULE_CONFIGURATION_HEALTHMONITORING*/(MODULE_CONFIGURATION_HEALTHMONITORING_TYPE *) null,
/*PARTITION_CONFIGURATION_SIZE*/(SIZE_TYPE) 3,
/*PARTITION_CONFIGURATION*/PARTITION_CONFIGURATION,
/*PORT_MODULE_CONFIGURATION*/(SYSTEM_ADDRESS_TYPE) &PORT_MODULE_CONFIGURATION };

// Port system configuration
static PORT_SYSTEM_CONFIGURATION_TYPE PORT_SYSTEM_CONFIGURATION = {
/*VECTORTABLE_ADDRESS*/(portADDRESS) 0x40300000,
/*VECTORTABLE_SIZE*/(portSIZE) 0x00001000,
/*PERIPHERALS_ADDRESS*/(portADDRESS) 0x44000000,
/*PERIPHERALS_SIZE*/(portSIZE) 0x3C000000,
/*SYSTEM_BOOT_ADDRESS*/(portADDRESS) 0x80000000,
/*SYSTEM_BOOT_SIZE*/(portSIZE) 0x00001000,
/*SYSTEM_FLTRANSLATIONTABLE_ADDRESS*/(portADDRESS) 0x80138000,
/*SYSTEM_FLTRANSLATIONTABLE_SIZE*/(portSIZE) 0x00100000,
/*SYSTEM_SLTRANSLATIONTABLE_ADDRESS*/(portADDRESS) 0x80238000,
/*SYSTEM_SLTRANSLATIONTABLE_SIZE*/(portSIZE) 0x00100000,
/*SYSTEM_GLOBAL_FLTRANSLATIONTABLE_ADDRESS (Filled by system)*/(unsigned int *) null };

// System configuration
SYSTEM_CONFIGURATION_TYPE SYSTEM_CONFIGURATION = {
/*SYSTEM_STACK_ADDRESS*/(SYSTEM_ADDRESS_TYPE) 0x8002C000,
/*SYSTEM_STACK_SIZE*/(SIZE_TYPE) 0x00004000,
/*SYSTEM_CODE_ADDRESS*/(SYSTEM_ADDRESS_TYPE) 0x80001000,
/*SYSTEM_CODE_SIZE*/(SIZE_TYPE) 0x00020000,
/*SYSTEM_DATA_ADDRESS*/(SYSTEM_ADDRESS_TYPE) 0x80021000,
/*SYSTEM_DATA_SIZE*/(SIZE_TYPE) 0x00002000,
/*SYSTEM_HEAP_ADDRESS*/(SYSTEM_ADDRESS_TYPE) 0x80034000,
/*SYSTEM_HEAP_SIZE*/(SIZE_TYPE) 0x00100000,
/*SYSTEM_CONFIGURATION_HEALTHMONITORING*/(SYSTEM_CONFIGURATION_HEALTHMONITORING_TYPE *) null,
/*PORT_SYSTEM_CONFIGURATION*/(SYSTEM_ADDRESS_TYPE) &PORT_SYSTEM_CONFIGURATION };