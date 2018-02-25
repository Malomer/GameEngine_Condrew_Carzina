#include <windows.h>
#include <vector>
#include <map>
#include "Component.h"
#include "Matrices.h"

class GameObject { 

public: 
	GameObject() { parent = NULL; } 
	~GameObject(void); 
	
	void SetTransform(const Matrix4 &matrix) { 
		transform = matrix; 
	} 
	
	Matrix4 GetTransform() { 
		return transform; 
	} 
	
	Matrix4 GetWorldTransform() { 
		return worldTransform; 
	} 
	
	void SetParent(GameObject& p) {
		parent = &p; 
	} 
	
	void AddChild(GameObject* s);
	void Update(float msec);

	void Awake(void); 
	void Destroy(void);
	virtual void Update(int deltaMs);

protected: 
	GameObject* parent; 
	Matrix4 worldTransform;
	Matrix4 transform; 
	std::vector<GameObject*> children;
	std::map<std::string, Component> actorComponents;
};