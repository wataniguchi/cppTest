//
//  app.cpp
//  cppTest
//
//  Created by Wataru Taniguchi on 2019/04/28.
//  Copyright © 2019 Wataru Taniguchi. All rights reserved.
//

#include <iostream>
#include "crew.hpp"
using namespace std;

Captain* captain;
Observer* observer;
Navigator* activeNavigator = NULL;

// a cyclic handler to activate a task
void task_activator(intptr_t tskid) {
    //ER ercd = act_tsk(tskid);
    //assert(ercd == E_OK);
}

// Captain's periodic task
void captain_task(intptr_t unused) {
    captain->operate();
}

// Observer's periodic task
void observer_task(intptr_t unused) {
    observer->operate();
}

// Navigator's periodic task
void navigator_task(intptr_t unused) {
    activeNavigator->operate();
}

int main(int argc, const char * argv[]) {
    captain = new Captain;
    
    captain->takeoff();
    // infinite loop until stop condition is met
    for (int i = 0; i < 4; i++) {
        observer_task(NULL);
        navigator_task(NULL);
        captain_task(NULL);
    }
    
    captain->land();
    
    delete captain;
    return 0;
}
