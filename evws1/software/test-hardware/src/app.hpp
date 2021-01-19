#ifndef APP_HPP
#define APP_HPP

#include "global.h"
#include "sys.hpp"

// declarations

namespace app {
    
    const sys::Event EVENT_0 = (1 << 0);
    const sys::Event EVENT_1 = (1 << 1);
    const sys::Event EVENT_2 = (1 << 2);
    const sys::Event EVENT_3 = (1 << 3);
    const sys::Event EVENT_4 = (1 << 4);
    const sys::Event EVENT_5 = (1 << 5);
    const sys::Event EVENT_6 = (1 << 6);
    const sys::Event EVENT_7 = (1 << 7);
    
    void init ();
    void main ();
    
    void task1ms ();
    void task2ms ();
    void task4ms ();
    void task8ms ();
    void task16ms ();
    void task32ms ();
    void task64ms ();
    void task128ms ();
    
}

#endif /* APP_HPP */

