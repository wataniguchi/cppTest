//
//  crew.hpp
//  cppTest
//
//  Created by Wataru Taniguchi on 2019/04/28.
//  Copyright © 2019 Wataru Taniguchi. All rights reserved.
//

#ifndef crew_hpp
#define crew_hpp

#include <iostream>

class Observer {
private:
    int16_t* psensor;
protected:
public:
    Observer();
    Observer(int16_t*);
    void goOnDuty();
    void operate(); // method to invoke from the cyclic handler
    void goOffDuty();
    ~Observer();
};

class Navigator {
protected:
    int16_t* pmotor;
public:
    Navigator();
    virtual void goOnDuty() = 0;
    virtual void operate() = 0;
    virtual void goOffDuty() = 0;
    virtual ~Navigator();
};

class LineTracer : public Navigator {
protected:
public:
    LineTracer();
    LineTracer(int16_t*);
    void goOnDuty();
    void operate(); // method to invoke from the cyclic handler
    void goOffDuty();
    ~LineTracer();
};

class SeesawCrimber : public Navigator {
protected:
public:
    SeesawCrimber();
    SeesawCrimber(int16_t*);
    void goOnDuty();
    void operate(); // method to invoke from the cyclic handler
    void goOffDuty();
    ~SeesawCrimber();
};

class LimboDancer : public Navigator {
protected:
public:
    LimboDancer();
    LimboDancer(int16_t*);
    void goOnDuty();
    void operate(); // method to invoke from the cyclic handler
    void goOffDuty();
    ~LimboDancer();
};

class Captain {
protected:
    int16_t sensor;
    int16_t motor;
    LineTracer* lineTracer;
    SeesawCrimber* seesawCrimber;
    LimboDancer* limboDancer;
public:
    Captain();
    void takeoff();
    void operate(); // method to invoke from the cyclic handler
    void land();
    ~Captain();
};

#endif /* crew_hpp */
