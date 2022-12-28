#include "C01_Log.h"
#include "Global.h"

// Sets default values
AC01_Log::AC01_Log()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AC01_Log::BeginPlay()
{
	Super::BeginPlay();

	CLog::Print(100);
	//CLog::Log(200);
	CLog::Log(2.15f);

	CLog::Print(20, 1);
	CLog::Print(30, 2, 20.0f, FColor::Red);
	CLog::Print(40, 2, 20.0f, FColor::Red);

	CLog::Print("Unreal Gameplay!");
	CLog::Print(GetActorLocation());
	CLog::Print(GetActorRotation());

	CLog::Log("=========================");

	CLog::Log(10);
	CLog::Log(PI);
	CLog::Log("Unreal Gameplay!");
	CLog::Log(GetActorLocation());
	CLog::Log(GetActorRotation());

	CLog::Log(this);
	//CLog::Log(__FUNCTION__, __LINE__);
	PrintLine();
	
}

// Called every frame
void AC01_Log::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	Time += DeltaTime;
	//CLog::Print(Time); // ���ʿ� �����°� �ֽ�
	//CLog::Print(Time ,3); // ���ڸ����� �ٲ�
	//CLog::Print(Time ,0); // �ᱹ 0, -1 ����..
	//CLog::Print(Time ,1); // �ᱹ 0, -1 ����..
	CLog::Print(Time ,2); // �ᱹ 0, -1 ����..



}

