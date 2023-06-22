#include "CSpheres.h"
#include "Global.h"

ACSpheres::ACSpheres()
{
	CHelpers::CreateSceneComponent(this, &Root, "Root");
	
	for (int32 i = 0; i < 3; i++)
	{
		FString name;
		name.Append("Sphere");
		name.Append(FString::FromInt(i + 1));

		CHelpers::CreateSceneComponent(this, &Spheres[i], FName(name), Root);
	}
	//Todo. 
}

void ACSpheres::BeginPlay()
{
	Super::BeginPlay();
	
}

