#pragma once

#define CheckNull(p) { if (p == nullptr) return; }
#define CheckNullResult(p, result) { if (p == nullptr) return result; }

#define CheckTrue(p) { if (p == true) return; }
#define CheckTrueResult(p, result) { if (p == true) return result; }

#define CheckFalse(p) { if (p == false) return; }
#define CheckFalseResult(p, result) { if (p == false) return result; }

class U04_BASICSYNTAX_API CHelpers
{
public:
	template<typename T>
	static void CreateSceneComponent(AActor* InActor, T** OutComp, FName InName, USceneComponent* InParent = nullptr)
	{
		*OutComp = InActor->CreateDefaultSubobject<T>(InName);

		if (!!InParent)
		{
			(*OutComp)->SetupAttachment(InParent);
			return;
		}
		
		InActor->SetRootComponent(*OutComp);
	}
};