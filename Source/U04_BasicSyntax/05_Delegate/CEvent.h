#pragma once

#include "CoreMinimal.h"
#include "04_Collision/CBox.h"
#include "CEvent.generated.h"



UCLASS()
class U04_BASICSYNTAX_API ACEvent : public ACBox
{
	GENERATED_BODY()
	
public:
	DECLARE_EVENT_OneParam(ACEvent, FEventSignature, int32);

	FEventSignature OnEvent;
	//Todo. 컴파일 아직 안함.
};
