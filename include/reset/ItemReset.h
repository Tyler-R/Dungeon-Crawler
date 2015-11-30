#pragma once

#include "Reset.h"
#include "item.h"

class ItemReset : public Reset {
public:
    ItemReset( std::shared_ptr< Room > room, std::shared_ptr< Item > item );
    ~ItemReset( );

    virtual void performReset( );

private:
	std::shared_ptr< Item > item;
};
