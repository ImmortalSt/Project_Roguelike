#pragma once
#include "IAction.h"
#include <list>

template<typename Arg>
class IEvent {
	virtual void Register(IAction<Arg>* action) = 0;
	virtual void Notice(Arg arg) = 0;
	virtual void UnRegister(IAction<Arg>* action) = 0;
};