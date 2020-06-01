#pragma once

#include "Modules/ModuleManager.h"

class FSHModule : public FDefaultGameModuleImpl {
public:
	virtual bool IsGameModule() const override { return true; }
};