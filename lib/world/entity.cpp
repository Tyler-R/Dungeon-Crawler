#include "entity.h"

Entity::Entity( int maxHealth ) : maxHealth( maxHealth ) {
	setOrigionalBody( std::make_shared< Entity >( *this ) ); 
	setHealth( maxHealth );
}

Entity::~Entity() {

}

int Entity::getHealth( ) const {
	return health;
}	

void Entity::setHealth( int health ) {
	this->health = health;

	if( this->health > maxHealth ) {
		this->health = maxHealth;
	}

	if( this->health < MIN_HEALTH ) {
		this->health = MIN_HEALTH;
	} 
}


void Entity::damage( int damage ) {
	int currentHealth = getHealth( );

	setHealth( currentHealth - damage );
}

void Entity::heal( int healthHealed ) {
	int currentHealth = getHealth( );
	setHealth( currentHealth + healthHealed );

}

bool Entity::isAlive() const {
	if(health <= MIN_HEALTH) {
		return false;
	}

	return true;
}

void Entity::setOrigionalBody( std::shared_ptr< Entity > origionalBody ) {
	this->origionalBody = origionalBody;
}
