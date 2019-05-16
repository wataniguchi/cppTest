//
//  app.h
//  cppTest
//
//  Created by Wataru Taniguchi on 2019/05/08.
//  Copyright © 2019 Wataru Taniguchi. All rights reserved.
//

#ifndef cppTest_h
#define cppTest_h

extern "C" {

/**
 * Common header files
 */
//#include "ev3api.h"
//#include "target_test.h"

/**
 * Task priorities (smaller number has higher priority)
 */
#define PRIORITY_CAP_TSK TMIN_APP_TPRI
#define PRIORITY_OBS_TSK TMIN_APP_TPRI
#define PRIORITY_NAV_TSK TMIN_APP_TPRI
#define PRIORITY_MAIN_TASK (TMIN_APP_TPRI + 1)

/**
 * Task periods in ms
 */
#define PERIOD_CAP_TSK  (40)
#define PERIOD_OBS_TSK  (40)
#define PERIOD_NAV_TSK  (4)

/**
 * Default task stack size in bytes
 */
#ifndef STACK_SIZE
#define STACK_SIZE      4096
#endif /* STACK_SIZE */
    
/**
 * Prototypes for configuration
 */
#ifndef TOPPERS_MACRO_ONLY

extern void main_task(intptr_t unused);
extern void captain_task(intptr_t unused);
extern void observer_task(intptr_t unused);
extern void navigator_task(intptr_t unused);

extern void task_activator(intptr_t tskid);

#endif /* TOPPERS_MACRO_ONLY */

}
#endif /* cppTest_h */
