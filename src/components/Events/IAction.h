#pragma once

template<typename Arg>
class IAction {
public:
	virtual void OnAction(Arg arg) = 0;
};