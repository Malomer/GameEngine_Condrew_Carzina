#include <list>

class Component {

public:
	virtual void Awake(void) { }
	virtual void Update(int deltaMs) { }

	virtual const char GetName() const = 0;
};