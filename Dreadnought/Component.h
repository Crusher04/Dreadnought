#pragma once
#include <memory>
#include "Enums.h"

template<typename T>
using Ref = std::shared_ptr <T>;

class Component {
public:

	Component(): isCreated(false) {}
	virtual ~Component() = default;
	virtual bool OnCreate() = 0;
	virtual void OnDestroy() = 0;

protected:
	bool isCreated;

};