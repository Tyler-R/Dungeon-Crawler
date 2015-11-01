#include "reset/Reset.h"

Reset::Reset(std::shared_ptr<Room> room) : room(move(room)) {

}

bool Reset::shouldPerformReset(std::chrono::milliseconds currentTime) {
	return ( currentTime - timeLastResetWasPerformed ) >= timeBetweenResets;
}

void Reset::setTimeBetweenResets(std::chrono::milliseconds newTimeBetweenResets) {
	timeBetweenResets = newTimeBetweenResets;
}

Reset::~Reset() {

}
