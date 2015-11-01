#pragma once

#include "Reset.h"
#include "item.h"

class ItemReset : public Reset {
public:
    ItemReset( std::shared_ptr< Room > room, std::shared_ptr< Item > item );
    ~ItemReset( );

    virtual void performReset( std::chrono::milliseconds currentTimeSinceEpoch );

private:
	std::shared_ptr< Item > item;
};
