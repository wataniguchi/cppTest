//
//  crew.cpp
//  cppTest
//
//  Created by Wataru Taniguchi on 2019/04/28.
//  Copyright © 2019 Wataru Taniguchi. All rights reserved.
//

#include "crew.hpp"
using namespace std;

extern Observer* observer;
extern Navigator* activeNavigator;

Observer::Observer() {
    cout << "Observer default constructor" << endl;
}

Observer::Observer(int16_t* s) {
    cout << "Observer constructor" << endl;
    psensor = s;
}

void Observer::goOnDuty() {
    // register cyclic handler to EV3RT
    cout << "Observer handler set" << endl;
}

void Observer::operate() {
    cout << "Observer is in action..." << endl;
    (*psensor)++;
    cout << "sensor = " << *psensor << endl;
}

void Observer::goOffDuty() {
    // deregister cyclic handler from EV3RT
    cout << "Observer handler unset" << endl;
}

Observer::~Observer() {
    cout << "Observer destructor" << endl;
}

Navigator::Navigator() {
    cout << "Navigator default constructor" << endl;
}

Navigator::~Navigator() {
    cout << "Navigator destructor" << endl;
}

LineTracer::LineTracer() {
    cout << "LineTracer default constructor" << endl;
}

LineTracer::LineTracer(int16_t* m) {
    cout << "LineTracer constructor" << endl;
    pmotor = m;
}

void LineTracer::goOnDuty() {
    cout << "LineTracer goes on duty" << endl;
    if (activeNavigator == NULL) {
        activeNavigator = this;
        // register cyclic handler to EV3RT
        cout << "Navigator handler set" << endl;
    }
}

void LineTracer::operate() {
    cout << "LineTracer is in action..." << endl;
    (*pmotor)++;
    cout << "motor = " << *pmotor << endl;
}

void LineTracer::goOffDuty() {
    cout << "LineTracer goes off duty" << endl;
    if (activeNavigator == this) {
        // deregister cyclic handler from EV3RT
        cout << "Navigator handler unset" << endl;
        activeNavigator = NULL;
    }
}

LineTracer::~LineTracer() {
    cout << "LineTracer destructor" << endl;
}

SeesawCrimber::SeesawCrimber() {
    cout << "SeesawCrimber default constructor" << endl;
}

SeesawCrimber::SeesawCrimber(int16_t* m) {
    cout << "SeesawCrimber constructor" << endl;
    pmotor = m;
}

void SeesawCrimber::goOnDuty() {
    cout << "SeesawCrimber goes on duty" << endl;
    if (activeNavigator == NULL) {
        activeNavigator = this;
        // register cyclic handler to EV3RT
        cout << "Navigator handler set" << endl;
    }
}

void SeesawCrimber::operate() {
    cout << "SeesawCrimber is in action..." << endl;
    (*pmotor)++;
    cout << "motor = " << *pmotor << endl;
}

void SeesawCrimber::goOffDuty() {
    cout << "SeesawCrimber goes off duty" << endl;
    if (activeNavigator == this) {
        // deregister cyclic handler from EV3RT
        cout << "Navigator handler unset" << endl;
        activeNavigator = NULL;
    }
}

SeesawCrimber::~SeesawCrimber() {
    cout << "SeesawCrimber destructor" << endl;
}

LimboDancer::LimboDancer() {
    cout << "LimboDancer default constructor" << endl;
}

void LimboDancer::goOnDuty() {
}

void LimboDancer::operate() {
}

void LimboDancer::goOffDuty() {
}

LimboDancer::~LimboDancer() {
    cout << "LimboDancer destructor" << endl;
}

Captain::Captain() {
    cout << "Captain default constructor" << endl;
}

void Captain::takeoff() {
    sensor = 0;
    motor = 0;
    cout << "sensor = " << sensor << ", motor = " << motor << endl;
    // register cyclic handler to EV3RT
    cout << "Captain handler set" << endl;
    observer = new Observer(&sensor);
    observer->goOnDuty();
    lineTracer = new LineTracer(&motor);
    seesawCrimber = new SeesawCrimber(&motor);
    lineTracer->goOnDuty();
}

void Captain::operate() {
    cout << "Captain is in action..." << endl;
    if (motor % 2 != 0) {
        activeNavigator->goOffDuty();
        seesawCrimber->goOnDuty();
    } else {
        activeNavigator->goOffDuty();
        lineTracer->goOnDuty();
    }
}

void Captain::land() {
    if (activeNavigator != NULL) {
        activeNavigator->goOffDuty();
    }
    delete lineTracer;
    observer->goOffDuty();
    delete observer;
    // deregister cyclic handler from EV3RT
    cout << "Captain handler unset" << endl;
    cout << "sensor = " << sensor << ", motor = " << motor << endl;
}

Captain::~Captain() {
    cout << "Captain destructor" << endl;
}
