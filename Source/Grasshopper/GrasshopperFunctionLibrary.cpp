// Fill out your copyright notice in the Description page of Project Settings.


#include "GrasshopperFunctionLibrary.h"
#include "git-describe.h"
#include "SceneView.h"

AActor* UGrasshopperFunctionLibrary::getNetOwner(const AActor* a)
{
	if (a)
		return (AActor*)a->GetNetOwner();
	return nullptr;
}

UPlayer* UGrasshopperFunctionLibrary::getNetOwningPlayer(AActor*a)
{
	if (a)
		return a->GetNetOwningPlayer();
	return nullptr;
}

AActor* UGrasshopperFunctionLibrary::getActorOwner(AActor*a)
{
	if (a)
		return a->GetOwner();
	return nullptr;
}

APlayerController* UGrasshopperFunctionLibrary::GetActorPlayerController(AActor* a)
{
	if (a) 
	{
		UPlayer *player = a->GetNetOwningPlayer();
		if (player && a->GetWorld())
		{
			return player->GetPlayerController(a->GetWorld());
		}
	}
		
	return nullptr;
}

FString UGrasshopperFunctionLibrary::getCodeCommit()
{
	return FString(GIT_COMMIT);
}

FString UGrasshopperFunctionLibrary::getGitDescribe()
{
	return FString(GIT_DESCRIBE);
}

FString UGrasshopperFunctionLibrary::getCodeBranch()
{
	return FString(GIT_BRANCH);
}

void UGrasshopperFunctionLibrary::sortActorArray(const TArray<AActor*>& array, TArray<AActor*>& outArray, FActorComparator cmp)
{
	outArray = array;
	Algo::Sort(outArray, [cmp](auto o1, auto o2) {
		return cmp.Execute(o1, o2);
	});
}

void UGrasshopperFunctionLibrary::deprojectWidgetToWorld(const FVector2D& widgetPos, const FVector2D& widgetSize,
	const FMatrix& InvViewMatrix, const FMatrix& InvProjMatrix, FVector& worldOrigin, FVector& worldDirection)
{
	FIntRect viewRect(0, 0, (int32)widgetSize.X, (int32)widgetSize.Y);
	FSceneView::DeprojectScreenToWorld(widgetPos, viewRect, InvViewMatrix, InvProjMatrix, worldOrigin, worldDirection);
}