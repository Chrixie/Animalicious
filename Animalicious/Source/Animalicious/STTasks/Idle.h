//USTRUCT()
//
//struct FNAMEInstanceData
//{
//	GENERATED_BODY()
//
//	// Add variables here
//};
//
//USTRUCT(meta = (DisplayName = "NAME"))
//struct FNAME : public FStateTreeTaskCommonBase
//{
//	GENERATED_BODY()
//
//	using FInstanceDataType = FNAMEInstanceData;
//	virtual const UStruct* GetInstanceDataType() const override { return FInstanceDataType::StaticStruct(); }
//
//	virtual EStateTreeRunStatus EnterState(FStateTreeExecutionContext& Context,
//	                                       const FStateTreeTransitionResult& Transition) const override;
//	virtual EStateTreeRunStatus Tick(FStateTreeExecutionContext& Context, const float DeltaTime) const override;
//};
