#pragma once

#include "CondrewCarzina.h"

#include <map>

class PingPongPing : public CondrewCarzina {

public:

	virtual void Setup();
	virtual void GameLoop(INT32 ms);
	virtual void Render();
};
