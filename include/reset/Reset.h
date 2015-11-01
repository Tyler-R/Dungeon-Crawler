#pragma once

#include "room.h"

#include <iostream>
#include <memory>

#include <chrono>

class Reset {
public:
    Reset( std::shared_ptr< Room > room );
    ~Reset( );

    virtual void performReset( std::chrono::milliseconds currentTimeSinceEpoch ) = 0;

    void setTimeBetweenResets(std::chrono::milliseconds newTimeBetweenResets);


private:

protected:
    std::shared_ptr< Room > room;

    std::chrono::milliseconds timeLastResetWasPerformed = std::chrono::milliseconds( 0 );

    std::chrono::milliseconds timeBetweenResets = std::chrono::milliseconds( 50 );

    bool shouldPerformReset( std::chrono::milliseconds currentTime );

};
