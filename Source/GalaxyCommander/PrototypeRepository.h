
#pragma once

#include "CoreMinimal.h"
#include "Prototype.h"

template<typename T1, typename T2>
class GALAXYCOMMANDER_API PrototypeRepository
{
public:
	T1* Build(FName Name)
	{
		T1* object = nullptr;

		if (PrototypeMap.Contains(Name))
		{
			object = PrototypeMap[Name]->Clone();
		}

		return object;
	};

protected:
	virtual Prototype<T1>* BuildPrototype(T2 Data) = 0;

	TMap<FName, Prototype<T1>*> PrototypeMap;
};
