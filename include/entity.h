#pragma once

#include <vector>
#include <memory>

class Entity {
    
public:
	Entity( int maxHealth );
	~Entity( );

	int getHealth( ) const;
	void setHealth( int health );

	void damage( int damage );
	void heal( int healthHealed );

	bool isAlive( ) const;

	void setOrigionalBody( std::shared_ptr< Entity > origionalBody ); 


private:
	const int MIN_HEALTH = 0;

	int maxHealth = 0;
	int health = 0;

	std::shared_ptr<Entity> origionalBody;

};