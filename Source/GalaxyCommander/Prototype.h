
#pragma once

#include "CoreMinimal.h"

template<typename T>
class GALAXYCOMMANDER_API Prototype
{
public:
	virtual T* Clone() = 0;
};