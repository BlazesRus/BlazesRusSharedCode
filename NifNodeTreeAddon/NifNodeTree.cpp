#include "NifNodeTree.h"

void NifNodeTreeData::NifNodeTree::AddNodeToTree(std::string TargetNodeType, std::string TargetMenuMaster, std::string SpecialModifier/* = ""*/, std::string ItemName/* = ""*/, std::string InternalName/* = ""*/)
{
	AddMenuItemData(TargetMenuMaster, SpecialModifier, ItemName, InternalName);
	FixCurrentNodeData();
	CurrentNode->NodeType = TargetNodeType;
	size_t Index;
	//Now add actual node to ObjectRegistry
	if(TargetNodeType == "NiObject")
	{
		Index = TargetObjectRegistry.NiObject_Registry.AddData();
		TargetObjectRegistry.NiObject_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "Ni3dsAlphaAnimator")
	{
		Index = TargetObjectRegistry.Ni3dsAlphaAnimator_Registry.AddData();
		TargetObjectRegistry.Ni3dsAlphaAnimator_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "Ni3dsAnimationNode")
	{
		Index = TargetObjectRegistry.Ni3dsAnimationNode_Registry.AddData();
		TargetObjectRegistry.Ni3dsAnimationNode_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "Ni3dsColorAnimator")
	{
		Index = TargetObjectRegistry.Ni3dsColorAnimator_Registry.AddData();
		TargetObjectRegistry.Ni3dsColorAnimator_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "Ni3dsMorphShape")
	{
		Index = TargetObjectRegistry.Ni3dsMorphShape_Registry.AddData();
		TargetObjectRegistry.Ni3dsMorphShape_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "Ni3dsParticleSystem")
	{
		Index = TargetObjectRegistry.Ni3dsParticleSystem_Registry.AddData();
		TargetObjectRegistry.Ni3dsParticleSystem_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "Ni3dsPathController")
	{
		Index = TargetObjectRegistry.Ni3dsPathController_Registry.AddData();
		TargetObjectRegistry.Ni3dsPathController_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiParticleModifier")
	{
		Index = TargetObjectRegistry.NiParticleModifier_Registry.AddData();
		TargetObjectRegistry.NiParticleModifier_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPSysCollider")
	{
		Index = TargetObjectRegistry.NiPSysCollider_Registry.AddData();
		TargetObjectRegistry.NiPSysCollider_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "bhkRefObject")
	{
		Index = TargetObjectRegistry.bhkRefObject_Registry.AddData();
		TargetObjectRegistry.bhkRefObject_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "bhkSerializable")
	{
		Index = TargetObjectRegistry.bhkSerializable_Registry.AddData();
		TargetObjectRegistry.bhkSerializable_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "bhkWorldObject")
	{
		Index = TargetObjectRegistry.bhkWorldObject_Registry.AddData();
		TargetObjectRegistry.bhkWorldObject_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "bhkPhantom")
	{
		Index = TargetObjectRegistry.bhkPhantom_Registry.AddData();
		TargetObjectRegistry.bhkPhantom_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "bhkShapePhantom")
	{
		Index = TargetObjectRegistry.bhkShapePhantom_Registry.AddData();
		TargetObjectRegistry.bhkShapePhantom_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "bhkSimpleShapePhantom")
	{
		Index = TargetObjectRegistry.bhkSimpleShapePhantom_Registry.AddData();
		TargetObjectRegistry.bhkSimpleShapePhantom_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "bhkEntity")
	{
		Index = TargetObjectRegistry.bhkEntity_Registry.AddData();
		TargetObjectRegistry.bhkEntity_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "bhkRigidBody")
	{
		Index = TargetObjectRegistry.bhkRigidBody_Registry.AddData();
		TargetObjectRegistry.bhkRigidBody_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "bhkRigidBodyT")
	{
		Index = TargetObjectRegistry.bhkRigidBodyT_Registry.AddData();
		TargetObjectRegistry.bhkRigidBodyT_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "bhkConstraint")
	{
		Index = TargetObjectRegistry.bhkConstraint_Registry.AddData();
		TargetObjectRegistry.bhkConstraint_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "bhkLimitedHingeConstraint")
	{
		Index = TargetObjectRegistry.bhkLimitedHingeConstraint_Registry.AddData();
		TargetObjectRegistry.bhkLimitedHingeConstraint_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "bhkMalleableConstraint")
	{
		Index = TargetObjectRegistry.bhkMalleableConstraint_Registry.AddData();
		TargetObjectRegistry.bhkMalleableConstraint_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "bhkStiffSpringConstraint")
	{
		Index = TargetObjectRegistry.bhkStiffSpringConstraint_Registry.AddData();
		TargetObjectRegistry.bhkStiffSpringConstraint_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "bhkRagdollConstraint")
	{
		Index = TargetObjectRegistry.bhkRagdollConstraint_Registry.AddData();
		TargetObjectRegistry.bhkRagdollConstraint_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "bhkPrismaticConstraint")
	{
		Index = TargetObjectRegistry.bhkPrismaticConstraint_Registry.AddData();
		TargetObjectRegistry.bhkPrismaticConstraint_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "bhkHingeConstraint")
	{
		Index = TargetObjectRegistry.bhkHingeConstraint_Registry.AddData();
		TargetObjectRegistry.bhkHingeConstraint_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "bhkBallAndSocketConstraint")
	{
		Index = TargetObjectRegistry.bhkBallAndSocketConstraint_Registry.AddData();
		TargetObjectRegistry.bhkBallAndSocketConstraint_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "bhkBallSocketConstraintChain")
	{
		Index = TargetObjectRegistry.bhkBallSocketConstraintChain_Registry.AddData();
		TargetObjectRegistry.bhkBallSocketConstraintChain_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "bhkShape")
	{
		Index = TargetObjectRegistry.bhkShape_Registry.AddData();
		TargetObjectRegistry.bhkShape_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "bhkTransformShape")
	{
		Index = TargetObjectRegistry.bhkTransformShape_Registry.AddData();
		TargetObjectRegistry.bhkTransformShape_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "bhkSphereRepShape")
	{
		Index = TargetObjectRegistry.bhkSphereRepShape_Registry.AddData();
		TargetObjectRegistry.bhkSphereRepShape_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "bhkConvexShape")
	{
		Index = TargetObjectRegistry.bhkConvexShape_Registry.AddData();
		TargetObjectRegistry.bhkConvexShape_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "bhkSphereShape")
	{
		Index = TargetObjectRegistry.bhkSphereShape_Registry.AddData();
		TargetObjectRegistry.bhkSphereShape_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "bhkCapsuleShape")
	{
		Index = TargetObjectRegistry.bhkCapsuleShape_Registry.AddData();
		TargetObjectRegistry.bhkCapsuleShape_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "bhkBoxShape")
	{
		Index = TargetObjectRegistry.bhkBoxShape_Registry.AddData();
		TargetObjectRegistry.bhkBoxShape_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "bhkConvexVerticesShape")
	{
		Index = TargetObjectRegistry.bhkConvexVerticesShape_Registry.AddData();
		TargetObjectRegistry.bhkConvexVerticesShape_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "bhkConvexTransformShape")
	{
		Index = TargetObjectRegistry.bhkConvexTransformShape_Registry.AddData();
		TargetObjectRegistry.bhkConvexTransformShape_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "bhkMultiSphereShape")
	{
		Index = TargetObjectRegistry.bhkMultiSphereShape_Registry.AddData();
		TargetObjectRegistry.bhkMultiSphereShape_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "bhkBvTreeShape")
	{
		Index = TargetObjectRegistry.bhkBvTreeShape_Registry.AddData();
		TargetObjectRegistry.bhkBvTreeShape_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "bhkMoppBvTreeShape")
	{
		Index = TargetObjectRegistry.bhkMoppBvTreeShape_Registry.AddData();
		TargetObjectRegistry.bhkMoppBvTreeShape_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "bhkShapeCollection")
	{
		Index = TargetObjectRegistry.bhkShapeCollection_Registry.AddData();
		TargetObjectRegistry.bhkShapeCollection_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "bhkListShape")
	{
		Index = TargetObjectRegistry.bhkListShape_Registry.AddData();
		TargetObjectRegistry.bhkListShape_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "bhkMeshShape")
	{
		Index = TargetObjectRegistry.bhkMeshShape_Registry.AddData();
		TargetObjectRegistry.bhkMeshShape_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "bhkPackedNiTriStripsShape")
	{
		Index = TargetObjectRegistry.bhkPackedNiTriStripsShape_Registry.AddData();
		TargetObjectRegistry.bhkPackedNiTriStripsShape_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "bhkNiTriStripsShape")
	{
		Index = TargetObjectRegistry.bhkNiTriStripsShape_Registry.AddData();
		TargetObjectRegistry.bhkNiTriStripsShape_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiExtraData")
	{
		Index = TargetObjectRegistry.NiExtraData_Registry.AddData();
		TargetObjectRegistry.NiExtraData_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiInterpolator")
	{
		Index = TargetObjectRegistry.NiInterpolator_Registry.AddData();
		TargetObjectRegistry.NiInterpolator_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiKeyBasedInterpolator")
	{
		Index = TargetObjectRegistry.NiKeyBasedInterpolator_Registry.AddData();
		TargetObjectRegistry.NiKeyBasedInterpolator_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiFloatInterpolator")
	{
		Index = TargetObjectRegistry.NiFloatInterpolator_Registry.AddData();
		TargetObjectRegistry.NiFloatInterpolator_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiTransformInterpolator")
	{
		Index = TargetObjectRegistry.NiTransformInterpolator_Registry.AddData();
		TargetObjectRegistry.NiTransformInterpolator_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPoint3Interpolator")
	{
		Index = TargetObjectRegistry.NiPoint3Interpolator_Registry.AddData();
		TargetObjectRegistry.NiPoint3Interpolator_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPathInterpolator")
	{
		Index = TargetObjectRegistry.NiPathInterpolator_Registry.AddData();
		TargetObjectRegistry.NiPathInterpolator_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiBoolInterpolator")
	{
		Index = TargetObjectRegistry.NiBoolInterpolator_Registry.AddData();
		TargetObjectRegistry.NiBoolInterpolator_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiBoolTimelineInterpolator")
	{
		Index = TargetObjectRegistry.NiBoolTimelineInterpolator_Registry.AddData();
		TargetObjectRegistry.NiBoolTimelineInterpolator_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiBlendInterpolator")
	{
		Index = TargetObjectRegistry.NiBlendInterpolator_Registry.AddData();
		TargetObjectRegistry.NiBlendInterpolator_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiBSplineInterpolator")
	{
		Index = TargetObjectRegistry.NiBSplineInterpolator_Registry.AddData();
		TargetObjectRegistry.NiBSplineInterpolator_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiObjectNET")
	{
		Index = TargetObjectRegistry.NiObjectNET_Registry.AddData();
		TargetObjectRegistry.NiObjectNET_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiCollisionObject")
	{
		Index = TargetObjectRegistry.NiCollisionObject_Registry.AddData();
		TargetObjectRegistry.NiCollisionObject_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiCollisionData")
	{
		Index = TargetObjectRegistry.NiCollisionData_Registry.AddData();
		TargetObjectRegistry.NiCollisionData_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "bhkNiCollisionObject")
	{
		Index = TargetObjectRegistry.bhkNiCollisionObject_Registry.AddData();
		TargetObjectRegistry.bhkNiCollisionObject_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "bhkCollisionObject")
	{
		Index = TargetObjectRegistry.bhkCollisionObject_Registry.AddData();
		TargetObjectRegistry.bhkCollisionObject_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "bhkBlendCollisionObject")
	{
		Index = TargetObjectRegistry.bhkBlendCollisionObject_Registry.AddData();
		TargetObjectRegistry.bhkBlendCollisionObject_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "bhkPCollisionObject")
	{
		Index = TargetObjectRegistry.bhkPCollisionObject_Registry.AddData();
		TargetObjectRegistry.bhkPCollisionObject_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "bhkSPCollisionObject")
	{
		Index = TargetObjectRegistry.bhkSPCollisionObject_Registry.AddData();
		TargetObjectRegistry.bhkSPCollisionObject_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiAVObject")
	{
		Index = TargetObjectRegistry.NiAVObject_Registry.AddData();
		TargetObjectRegistry.NiAVObject_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiDynamicEffect")
	{
		Index = TargetObjectRegistry.NiDynamicEffect_Registry.AddData();
		TargetObjectRegistry.NiDynamicEffect_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiLight")
	{
		Index = TargetObjectRegistry.NiLight_Registry.AddData();
		TargetObjectRegistry.NiLight_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiProperty")
	{
		Index = TargetObjectRegistry.NiProperty_Registry.AddData();
		TargetObjectRegistry.NiProperty_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiTransparentProperty")
	{
		Index = TargetObjectRegistry.NiTransparentProperty_Registry.AddData();
		TargetObjectRegistry.NiTransparentProperty_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPSysModifier")
	{
		Index = TargetObjectRegistry.NiPSysModifier_Registry.AddData();
		TargetObjectRegistry.NiPSysModifier_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPSysEmitter")
	{
		Index = TargetObjectRegistry.NiPSysEmitter_Registry.AddData();
		TargetObjectRegistry.NiPSysEmitter_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPSysVolumeEmitter")
	{
		Index = TargetObjectRegistry.NiPSysVolumeEmitter_Registry.AddData();
		TargetObjectRegistry.NiPSysVolumeEmitter_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiTimeController")
	{
		Index = TargetObjectRegistry.NiTimeController_Registry.AddData();
		TargetObjectRegistry.NiTimeController_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiInterpController")
	{
		Index = TargetObjectRegistry.NiInterpController_Registry.AddData();
		TargetObjectRegistry.NiInterpController_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiMultiTargetTransformController")
	{
		Index = TargetObjectRegistry.NiMultiTargetTransformController_Registry.AddData();
		TargetObjectRegistry.NiMultiTargetTransformController_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiGeomMorpherController")
	{
		Index = TargetObjectRegistry.NiGeomMorpherController_Registry.AddData();
		TargetObjectRegistry.NiGeomMorpherController_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiMorphController")
	{
		Index = TargetObjectRegistry.NiMorphController_Registry.AddData();
		TargetObjectRegistry.NiMorphController_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiMorpherController")
	{
		Index = TargetObjectRegistry.NiMorpherController_Registry.AddData();
		TargetObjectRegistry.NiMorpherController_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiSingleInterpController")
	{
		Index = TargetObjectRegistry.NiSingleInterpController_Registry.AddData();
		TargetObjectRegistry.NiSingleInterpController_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiKeyframeController")
	{
		Index = TargetObjectRegistry.NiKeyframeController_Registry.AddData();
		TargetObjectRegistry.NiKeyframeController_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiTransformController")
	{
		Index = TargetObjectRegistry.NiTransformController_Registry.AddData();
		TargetObjectRegistry.NiTransformController_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPSysModifierCtlr")
	{
		Index = TargetObjectRegistry.NiPSysModifierCtlr_Registry.AddData();
		TargetObjectRegistry.NiPSysModifierCtlr_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPSysEmitterCtlr")
	{
		Index = TargetObjectRegistry.NiPSysEmitterCtlr_Registry.AddData();
		TargetObjectRegistry.NiPSysEmitterCtlr_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPSysModifierBoolCtlr")
	{
		Index = TargetObjectRegistry.NiPSysModifierBoolCtlr_Registry.AddData();
		TargetObjectRegistry.NiPSysModifierBoolCtlr_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPSysModifierActiveCtlr")
	{
		Index = TargetObjectRegistry.NiPSysModifierActiveCtlr_Registry.AddData();
		TargetObjectRegistry.NiPSysModifierActiveCtlr_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPSysModifierFloatCtlr")
	{
		Index = TargetObjectRegistry.NiPSysModifierFloatCtlr_Registry.AddData();
		TargetObjectRegistry.NiPSysModifierFloatCtlr_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPSysEmitterDeclinationCtlr")
	{
		Index = TargetObjectRegistry.NiPSysEmitterDeclinationCtlr_Registry.AddData();
		TargetObjectRegistry.NiPSysEmitterDeclinationCtlr_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPSysEmitterDeclinationVarCtlr")
	{
		Index = TargetObjectRegistry.NiPSysEmitterDeclinationVarCtlr_Registry.AddData();
		TargetObjectRegistry.NiPSysEmitterDeclinationVarCtlr_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPSysEmitterInitialRadiusCtlr")
	{
		Index = TargetObjectRegistry.NiPSysEmitterInitialRadiusCtlr_Registry.AddData();
		TargetObjectRegistry.NiPSysEmitterInitialRadiusCtlr_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPSysEmitterLifeSpanCtlr")
	{
		Index = TargetObjectRegistry.NiPSysEmitterLifeSpanCtlr_Registry.AddData();
		TargetObjectRegistry.NiPSysEmitterLifeSpanCtlr_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPSysEmitterSpeedCtlr")
	{
		Index = TargetObjectRegistry.NiPSysEmitterSpeedCtlr_Registry.AddData();
		TargetObjectRegistry.NiPSysEmitterSpeedCtlr_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPSysGravityStrengthCtlr")
	{
		Index = TargetObjectRegistry.NiPSysGravityStrengthCtlr_Registry.AddData();
		TargetObjectRegistry.NiPSysGravityStrengthCtlr_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiFloatInterpController")
	{
		Index = TargetObjectRegistry.NiFloatInterpController_Registry.AddData();
		TargetObjectRegistry.NiFloatInterpController_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiFlipController")
	{
		Index = TargetObjectRegistry.NiFlipController_Registry.AddData();
		TargetObjectRegistry.NiFlipController_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiAlphaController")
	{
		Index = TargetObjectRegistry.NiAlphaController_Registry.AddData();
		TargetObjectRegistry.NiAlphaController_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiTextureTransformController")
	{
		Index = TargetObjectRegistry.NiTextureTransformController_Registry.AddData();
		TargetObjectRegistry.NiTextureTransformController_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiLightDimmerController")
	{
		Index = TargetObjectRegistry.NiLightDimmerController_Registry.AddData();
		TargetObjectRegistry.NiLightDimmerController_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiBoolInterpController")
	{
		Index = TargetObjectRegistry.NiBoolInterpController_Registry.AddData();
		TargetObjectRegistry.NiBoolInterpController_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiVisController")
	{
		Index = TargetObjectRegistry.NiVisController_Registry.AddData();
		TargetObjectRegistry.NiVisController_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPoint3InterpController")
	{
		Index = TargetObjectRegistry.NiPoint3InterpController_Registry.AddData();
		TargetObjectRegistry.NiPoint3InterpController_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiMaterialColorController")
	{
		Index = TargetObjectRegistry.NiMaterialColorController_Registry.AddData();
		TargetObjectRegistry.NiMaterialColorController_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiLightColorController")
	{
		Index = TargetObjectRegistry.NiLightColorController_Registry.AddData();
		TargetObjectRegistry.NiLightColorController_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiExtraDataController")
	{
		Index = TargetObjectRegistry.NiExtraDataController_Registry.AddData();
		TargetObjectRegistry.NiExtraDataController_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiFloatExtraDataController")
	{
		Index = TargetObjectRegistry.NiFloatExtraDataController_Registry.AddData();
		TargetObjectRegistry.NiFloatExtraDataController_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiBoneLODController")
	{
		Index = TargetObjectRegistry.NiBoneLODController_Registry.AddData();
		TargetObjectRegistry.NiBoneLODController_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiBSBoneLODController")
	{
		Index = TargetObjectRegistry.NiBSBoneLODController_Registry.AddData();
		TargetObjectRegistry.NiBSBoneLODController_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiGeometry")
	{
		Index = TargetObjectRegistry.NiGeometry_Registry.AddData();
		TargetObjectRegistry.NiGeometry_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiTriBasedGeom")
	{
		Index = TargetObjectRegistry.NiTriBasedGeom_Registry.AddData();
		TargetObjectRegistry.NiTriBasedGeom_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiGeometryData")
	{
		Index = TargetObjectRegistry.NiGeometryData_Registry.AddData();
		TargetObjectRegistry.NiGeometryData_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "AbstractAdditionalGeometryData")
	{
		Index = TargetObjectRegistry.AbstractAdditionalGeometryData_Registry.AddData();
		TargetObjectRegistry.AbstractAdditionalGeometryData_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiTriBasedGeomData")
	{
		Index = TargetObjectRegistry.NiTriBasedGeomData_Registry.AddData();
		TargetObjectRegistry.NiTriBasedGeomData_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "bhkBlendController")
	{
		Index = TargetObjectRegistry.bhkBlendController_Registry.AddData();
		TargetObjectRegistry.bhkBlendController_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "BSBound")
	{
		Index = TargetObjectRegistry.BSBound_Registry.AddData();
		TargetObjectRegistry.BSBound_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "BSFurnitureMarker")
	{
		Index = TargetObjectRegistry.BSFurnitureMarker_Registry.AddData();
		TargetObjectRegistry.BSFurnitureMarker_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "BSParentVelocityModifier")
	{
		Index = TargetObjectRegistry.BSParentVelocityModifier_Registry.AddData();
		TargetObjectRegistry.BSParentVelocityModifier_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "BSPSysArrayEmitter")
	{
		Index = TargetObjectRegistry.BSPSysArrayEmitter_Registry.AddData();
		TargetObjectRegistry.BSPSysArrayEmitter_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "BSWindModifier")
	{
		Index = TargetObjectRegistry.BSWindModifier_Registry.AddData();
		TargetObjectRegistry.BSWindModifier_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "hkPackedNiTriStripsData")
	{
		Index = TargetObjectRegistry.hkPackedNiTriStripsData_Registry.AddData();
		TargetObjectRegistry.hkPackedNiTriStripsData_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiAlphaProperty")
	{
		Index = TargetObjectRegistry.NiAlphaProperty_Registry.AddData();
		TargetObjectRegistry.NiAlphaProperty_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiAmbientLight")
	{
		Index = TargetObjectRegistry.NiAmbientLight_Registry.AddData();
		TargetObjectRegistry.NiAmbientLight_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiParticlesData")
	{
		Index = TargetObjectRegistry.NiParticlesData_Registry.AddData();
		TargetObjectRegistry.NiParticlesData_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiRotatingParticlesData")
	{
		Index = TargetObjectRegistry.NiRotatingParticlesData_Registry.AddData();
		TargetObjectRegistry.NiRotatingParticlesData_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiAutoNormalParticlesData")
	{
		Index = TargetObjectRegistry.NiAutoNormalParticlesData_Registry.AddData();
		TargetObjectRegistry.NiAutoNormalParticlesData_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPSysData")
	{
		Index = TargetObjectRegistry.NiPSysData_Registry.AddData();
		TargetObjectRegistry.NiPSysData_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiMeshPSysData")
	{
		Index = TargetObjectRegistry.NiMeshPSysData_Registry.AddData();
		TargetObjectRegistry.NiMeshPSysData_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiBinaryExtraData")
	{
		Index = TargetObjectRegistry.NiBinaryExtraData_Registry.AddData();
		TargetObjectRegistry.NiBinaryExtraData_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiBinaryVoxelExtraData")
	{
		Index = TargetObjectRegistry.NiBinaryVoxelExtraData_Registry.AddData();
		TargetObjectRegistry.NiBinaryVoxelExtraData_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiBinaryVoxelData")
	{
		Index = TargetObjectRegistry.NiBinaryVoxelData_Registry.AddData();
		TargetObjectRegistry.NiBinaryVoxelData_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiBlendBoolInterpolator")
	{
		Index = TargetObjectRegistry.NiBlendBoolInterpolator_Registry.AddData();
		TargetObjectRegistry.NiBlendBoolInterpolator_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiBlendFloatInterpolator")
	{
		Index = TargetObjectRegistry.NiBlendFloatInterpolator_Registry.AddData();
		TargetObjectRegistry.NiBlendFloatInterpolator_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiBlendPoint3Interpolator")
	{
		Index = TargetObjectRegistry.NiBlendPoint3Interpolator_Registry.AddData();
		TargetObjectRegistry.NiBlendPoint3Interpolator_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiBlendTransformInterpolator")
	{
		Index = TargetObjectRegistry.NiBlendTransformInterpolator_Registry.AddData();
		TargetObjectRegistry.NiBlendTransformInterpolator_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiBoolData")
	{
		Index = TargetObjectRegistry.NiBoolData_Registry.AddData();
		TargetObjectRegistry.NiBoolData_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiBooleanExtraData")
	{
		Index = TargetObjectRegistry.NiBooleanExtraData_Registry.AddData();
		TargetObjectRegistry.NiBooleanExtraData_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiBSplineBasisData")
	{
		Index = TargetObjectRegistry.NiBSplineBasisData_Registry.AddData();
		TargetObjectRegistry.NiBSplineBasisData_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiBSplineFloatInterpolator")
	{
		Index = TargetObjectRegistry.NiBSplineFloatInterpolator_Registry.AddData();
		TargetObjectRegistry.NiBSplineFloatInterpolator_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiBSplineCompFloatInterpolator")
	{
		Index = TargetObjectRegistry.NiBSplineCompFloatInterpolator_Registry.AddData();
		TargetObjectRegistry.NiBSplineCompFloatInterpolator_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiBSplinePoint3Interpolator")
	{
		Index = TargetObjectRegistry.NiBSplinePoint3Interpolator_Registry.AddData();
		TargetObjectRegistry.NiBSplinePoint3Interpolator_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiBSplineCompPoint3Interpolator")
	{
		Index = TargetObjectRegistry.NiBSplineCompPoint3Interpolator_Registry.AddData();
		TargetObjectRegistry.NiBSplineCompPoint3Interpolator_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiBSplineTransformInterpolator")
	{
		Index = TargetObjectRegistry.NiBSplineTransformInterpolator_Registry.AddData();
		TargetObjectRegistry.NiBSplineTransformInterpolator_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiBSplineCompTransformInterpolator")
	{
		Index = TargetObjectRegistry.NiBSplineCompTransformInterpolator_Registry.AddData();
		TargetObjectRegistry.NiBSplineCompTransformInterpolator_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "BSRotAccumTransfInterpolator")
	{
		Index = TargetObjectRegistry.BSRotAccumTransfInterpolator_Registry.AddData();
		TargetObjectRegistry.BSRotAccumTransfInterpolator_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiBSplineData")
	{
		Index = TargetObjectRegistry.NiBSplineData_Registry.AddData();
		TargetObjectRegistry.NiBSplineData_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiCamera")
	{
		Index = TargetObjectRegistry.NiCamera_Registry.AddData();
		TargetObjectRegistry.NiCamera_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiColorData")
	{
		Index = TargetObjectRegistry.NiColorData_Registry.AddData();
		TargetObjectRegistry.NiColorData_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiColorExtraData")
	{
		Index = TargetObjectRegistry.NiColorExtraData_Registry.AddData();
		TargetObjectRegistry.NiColorExtraData_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiControllerManager")
	{
		Index = TargetObjectRegistry.NiControllerManager_Registry.AddData();
		TargetObjectRegistry.NiControllerManager_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiSequence")
	{
		Index = TargetObjectRegistry.NiSequence_Registry.AddData();
		TargetObjectRegistry.NiSequence_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiControllerSequence")
	{
		Index = TargetObjectRegistry.NiControllerSequence_Registry.AddData();
		TargetObjectRegistry.NiControllerSequence_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiAVObjectPalette")
	{
		Index = TargetObjectRegistry.NiAVObjectPalette_Registry.AddData();
		TargetObjectRegistry.NiAVObjectPalette_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiDefaultAVObjectPalette")
	{
		Index = TargetObjectRegistry.NiDefaultAVObjectPalette_Registry.AddData();
		TargetObjectRegistry.NiDefaultAVObjectPalette_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiDirectionalLight")
	{
		Index = TargetObjectRegistry.NiDirectionalLight_Registry.AddData();
		TargetObjectRegistry.NiDirectionalLight_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiDitherProperty")
	{
		Index = TargetObjectRegistry.NiDitherProperty_Registry.AddData();
		TargetObjectRegistry.NiDitherProperty_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiRollController")
	{
		Index = TargetObjectRegistry.NiRollController_Registry.AddData();
		TargetObjectRegistry.NiRollController_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiFloatData")
	{
		Index = TargetObjectRegistry.NiFloatData_Registry.AddData();
		TargetObjectRegistry.NiFloatData_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiFloatExtraData")
	{
		Index = TargetObjectRegistry.NiFloatExtraData_Registry.AddData();
		TargetObjectRegistry.NiFloatExtraData_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiFloatsExtraData")
	{
		Index = TargetObjectRegistry.NiFloatsExtraData_Registry.AddData();
		TargetObjectRegistry.NiFloatsExtraData_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiFogProperty")
	{
		Index = TargetObjectRegistry.NiFogProperty_Registry.AddData();
		TargetObjectRegistry.NiFogProperty_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiGravity")
	{
		Index = TargetObjectRegistry.NiGravity_Registry.AddData();
		TargetObjectRegistry.NiGravity_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiIntegerExtraData")
	{
		Index = TargetObjectRegistry.NiIntegerExtraData_Registry.AddData();
		TargetObjectRegistry.NiIntegerExtraData_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "BSXFlags")
	{
		Index = TargetObjectRegistry.BSXFlags_Registry.AddData();
		TargetObjectRegistry.BSXFlags_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiIntegersExtraData")
	{
		Index = TargetObjectRegistry.NiIntegersExtraData_Registry.AddData();
		TargetObjectRegistry.NiIntegersExtraData_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "BSKeyframeController")
	{
		Index = TargetObjectRegistry.BSKeyframeController_Registry.AddData();
		TargetObjectRegistry.BSKeyframeController_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiKeyframeData")
	{
		Index = TargetObjectRegistry.NiKeyframeData_Registry.AddData();
		TargetObjectRegistry.NiKeyframeData_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiLookAtController")
	{
		Index = TargetObjectRegistry.NiLookAtController_Registry.AddData();
		TargetObjectRegistry.NiLookAtController_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiLookAtInterpolator")
	{
		Index = TargetObjectRegistry.NiLookAtInterpolator_Registry.AddData();
		TargetObjectRegistry.NiLookAtInterpolator_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiMaterialProperty")
	{
		Index = TargetObjectRegistry.NiMaterialProperty_Registry.AddData();
		TargetObjectRegistry.NiMaterialProperty_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiMorphData")
	{
		Index = TargetObjectRegistry.NiMorphData_Registry.AddData();
		TargetObjectRegistry.NiMorphData_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiNode")
	{
		Index = TargetObjectRegistry.NiNode_Registry.AddData();
		TargetObjectRegistry.NiNode_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiBone")
	{
		Index = TargetObjectRegistry.NiBone_Registry.AddData();
		TargetObjectRegistry.NiBone_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "AvoidNode")
	{
		Index = TargetObjectRegistry.AvoidNode_Registry.AddData();
		TargetObjectRegistry.AvoidNode_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "FxWidget")
	{
		Index = TargetObjectRegistry.FxWidget_Registry.AddData();
		TargetObjectRegistry.FxWidget_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "FxButton")
	{
		Index = TargetObjectRegistry.FxButton_Registry.AddData();
		TargetObjectRegistry.FxButton_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "FxRadioButton")
	{
		Index = TargetObjectRegistry.FxRadioButton_Registry.AddData();
		TargetObjectRegistry.FxRadioButton_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiBillboardNode")
	{
		Index = TargetObjectRegistry.NiBillboardNode_Registry.AddData();
		TargetObjectRegistry.NiBillboardNode_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiBSAnimationNode")
	{
		Index = TargetObjectRegistry.NiBSAnimationNode_Registry.AddData();
		TargetObjectRegistry.NiBSAnimationNode_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiBSParticleNode")
	{
		Index = TargetObjectRegistry.NiBSParticleNode_Registry.AddData();
		TargetObjectRegistry.NiBSParticleNode_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiSwitchNode")
	{
		Index = TargetObjectRegistry.NiSwitchNode_Registry.AddData();
		TargetObjectRegistry.NiSwitchNode_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiLODNode")
	{
		Index = TargetObjectRegistry.NiLODNode_Registry.AddData();
		TargetObjectRegistry.NiLODNode_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPalette")
	{
		Index = TargetObjectRegistry.NiPalette_Registry.AddData();
		TargetObjectRegistry.NiPalette_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiParticleBomb")
	{
		Index = TargetObjectRegistry.NiParticleBomb_Registry.AddData();
		TargetObjectRegistry.NiParticleBomb_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiParticleColorModifier")
	{
		Index = TargetObjectRegistry.NiParticleColorModifier_Registry.AddData();
		TargetObjectRegistry.NiParticleColorModifier_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiParticleGrowFade")
	{
		Index = TargetObjectRegistry.NiParticleGrowFade_Registry.AddData();
		TargetObjectRegistry.NiParticleGrowFade_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiParticleMeshModifier")
	{
		Index = TargetObjectRegistry.NiParticleMeshModifier_Registry.AddData();
		TargetObjectRegistry.NiParticleMeshModifier_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiParticleRotation")
	{
		Index = TargetObjectRegistry.NiParticleRotation_Registry.AddData();
		TargetObjectRegistry.NiParticleRotation_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiParticles")
	{
		Index = TargetObjectRegistry.NiParticles_Registry.AddData();
		TargetObjectRegistry.NiParticles_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiAutoNormalParticles")
	{
		Index = TargetObjectRegistry.NiAutoNormalParticles_Registry.AddData();
		TargetObjectRegistry.NiAutoNormalParticles_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiParticleMeshes")
	{
		Index = TargetObjectRegistry.NiParticleMeshes_Registry.AddData();
		TargetObjectRegistry.NiParticleMeshes_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiParticleMeshesData")
	{
		Index = TargetObjectRegistry.NiParticleMeshesData_Registry.AddData();
		TargetObjectRegistry.NiParticleMeshesData_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiParticleSystem")
	{
		Index = TargetObjectRegistry.NiParticleSystem_Registry.AddData();
		TargetObjectRegistry.NiParticleSystem_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiMeshParticleSystem")
	{
		Index = TargetObjectRegistry.NiMeshParticleSystem_Registry.AddData();
		TargetObjectRegistry.NiMeshParticleSystem_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiParticleSystemController")
	{
		Index = TargetObjectRegistry.NiParticleSystemController_Registry.AddData();
		TargetObjectRegistry.NiParticleSystemController_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiBSPArrayController")
	{
		Index = TargetObjectRegistry.NiBSPArrayController_Registry.AddData();
		TargetObjectRegistry.NiBSPArrayController_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPathController")
	{
		Index = TargetObjectRegistry.NiPathController_Registry.AddData();
		TargetObjectRegistry.NiPathController_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "ATextureRenderData")
	{
		Index = TargetObjectRegistry.ATextureRenderData_Registry.AddData();
		TargetObjectRegistry.ATextureRenderData_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPersistentSrcTextureRendererData")
	{
		Index = TargetObjectRegistry.NiPersistentSrcTextureRendererData_Registry.AddData();
		TargetObjectRegistry.NiPersistentSrcTextureRendererData_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPixelData")
	{
		Index = TargetObjectRegistry.NiPixelData_Registry.AddData();
		TargetObjectRegistry.NiPixelData_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPlanarCollider")
	{
		Index = TargetObjectRegistry.NiPlanarCollider_Registry.AddData();
		TargetObjectRegistry.NiPlanarCollider_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPointLight")
	{
		Index = TargetObjectRegistry.NiPointLight_Registry.AddData();
		TargetObjectRegistry.NiPointLight_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPosData")
	{
		Index = TargetObjectRegistry.NiPosData_Registry.AddData();
		TargetObjectRegistry.NiPosData_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPSysAgeDeathModifier")
	{
		Index = TargetObjectRegistry.NiPSysAgeDeathModifier_Registry.AddData();
		TargetObjectRegistry.NiPSysAgeDeathModifier_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPSysBombModifier")
	{
		Index = TargetObjectRegistry.NiPSysBombModifier_Registry.AddData();
		TargetObjectRegistry.NiPSysBombModifier_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPSysBoundUpdateModifier")
	{
		Index = TargetObjectRegistry.NiPSysBoundUpdateModifier_Registry.AddData();
		TargetObjectRegistry.NiPSysBoundUpdateModifier_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPSysBoxEmitter")
	{
		Index = TargetObjectRegistry.NiPSysBoxEmitter_Registry.AddData();
		TargetObjectRegistry.NiPSysBoxEmitter_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPSysColliderManager")
	{
		Index = TargetObjectRegistry.NiPSysColliderManager_Registry.AddData();
		TargetObjectRegistry.NiPSysColliderManager_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPSysColorModifier")
	{
		Index = TargetObjectRegistry.NiPSysColorModifier_Registry.AddData();
		TargetObjectRegistry.NiPSysColorModifier_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPSysCylinderEmitter")
	{
		Index = TargetObjectRegistry.NiPSysCylinderEmitter_Registry.AddData();
		TargetObjectRegistry.NiPSysCylinderEmitter_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPSysDragModifier")
	{
		Index = TargetObjectRegistry.NiPSysDragModifier_Registry.AddData();
		TargetObjectRegistry.NiPSysDragModifier_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPSysEmitterCtlrData")
	{
		Index = TargetObjectRegistry.NiPSysEmitterCtlrData_Registry.AddData();
		TargetObjectRegistry.NiPSysEmitterCtlrData_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPSysGravityModifier")
	{
		Index = TargetObjectRegistry.NiPSysGravityModifier_Registry.AddData();
		TargetObjectRegistry.NiPSysGravityModifier_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPSysGrowFadeModifier")
	{
		Index = TargetObjectRegistry.NiPSysGrowFadeModifier_Registry.AddData();
		TargetObjectRegistry.NiPSysGrowFadeModifier_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPSysMeshEmitter")
	{
		Index = TargetObjectRegistry.NiPSysMeshEmitter_Registry.AddData();
		TargetObjectRegistry.NiPSysMeshEmitter_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPSysMeshUpdateModifier")
	{
		Index = TargetObjectRegistry.NiPSysMeshUpdateModifier_Registry.AddData();
		TargetObjectRegistry.NiPSysMeshUpdateModifier_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "BSPSysInheritVelocityModifier")
	{
		Index = TargetObjectRegistry.BSPSysInheritVelocityModifier_Registry.AddData();
		TargetObjectRegistry.BSPSysInheritVelocityModifier_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "BSPSysHavokUpdateModifier")
	{
		Index = TargetObjectRegistry.BSPSysHavokUpdateModifier_Registry.AddData();
		TargetObjectRegistry.BSPSysHavokUpdateModifier_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "BSPSysRecycleBoundModifier")
	{
		Index = TargetObjectRegistry.BSPSysRecycleBoundModifier_Registry.AddData();
		TargetObjectRegistry.BSPSysRecycleBoundModifier_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "BSPSysSubTexModifier")
	{
		Index = TargetObjectRegistry.BSPSysSubTexModifier_Registry.AddData();
		TargetObjectRegistry.BSPSysSubTexModifier_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPSysPlanarCollider")
	{
		Index = TargetObjectRegistry.NiPSysPlanarCollider_Registry.AddData();
		TargetObjectRegistry.NiPSysPlanarCollider_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPSysSphericalCollider")
	{
		Index = TargetObjectRegistry.NiPSysSphericalCollider_Registry.AddData();
		TargetObjectRegistry.NiPSysSphericalCollider_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPSysPositionModifier")
	{
		Index = TargetObjectRegistry.NiPSysPositionModifier_Registry.AddData();
		TargetObjectRegistry.NiPSysPositionModifier_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPSysResetOnLoopCtlr")
	{
		Index = TargetObjectRegistry.NiPSysResetOnLoopCtlr_Registry.AddData();
		TargetObjectRegistry.NiPSysResetOnLoopCtlr_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPSysRotationModifier")
	{
		Index = TargetObjectRegistry.NiPSysRotationModifier_Registry.AddData();
		TargetObjectRegistry.NiPSysRotationModifier_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPSysSpawnModifier")
	{
		Index = TargetObjectRegistry.NiPSysSpawnModifier_Registry.AddData();
		TargetObjectRegistry.NiPSysSpawnModifier_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPSysSphereEmitter")
	{
		Index = TargetObjectRegistry.NiPSysSphereEmitter_Registry.AddData();
		TargetObjectRegistry.NiPSysSphereEmitter_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPSysUpdateCtlr")
	{
		Index = TargetObjectRegistry.NiPSysUpdateCtlr_Registry.AddData();
		TargetObjectRegistry.NiPSysUpdateCtlr_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPSysFieldModifier")
	{
		Index = TargetObjectRegistry.NiPSysFieldModifier_Registry.AddData();
		TargetObjectRegistry.NiPSysFieldModifier_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPSysVortexFieldModifier")
	{
		Index = TargetObjectRegistry.NiPSysVortexFieldModifier_Registry.AddData();
		TargetObjectRegistry.NiPSysVortexFieldModifier_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPSysGravityFieldModifier")
	{
		Index = TargetObjectRegistry.NiPSysGravityFieldModifier_Registry.AddData();
		TargetObjectRegistry.NiPSysGravityFieldModifier_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPSysDragFieldModifier")
	{
		Index = TargetObjectRegistry.NiPSysDragFieldModifier_Registry.AddData();
		TargetObjectRegistry.NiPSysDragFieldModifier_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPSysTurbulenceFieldModifier")
	{
		Index = TargetObjectRegistry.NiPSysTurbulenceFieldModifier_Registry.AddData();
		TargetObjectRegistry.NiPSysTurbulenceFieldModifier_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "BSPSysLODModifier")
	{
		Index = TargetObjectRegistry.BSPSysLODModifier_Registry.AddData();
		TargetObjectRegistry.BSPSysLODModifier_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "BSPSysScaleModifier")
	{
		Index = TargetObjectRegistry.BSPSysScaleModifier_Registry.AddData();
		TargetObjectRegistry.BSPSysScaleModifier_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPSysFieldMagnitudeCtlr")
	{
		Index = TargetObjectRegistry.NiPSysFieldMagnitudeCtlr_Registry.AddData();
		TargetObjectRegistry.NiPSysFieldMagnitudeCtlr_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPSysFieldAttenuationCtlr")
	{
		Index = TargetObjectRegistry.NiPSysFieldAttenuationCtlr_Registry.AddData();
		TargetObjectRegistry.NiPSysFieldAttenuationCtlr_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPSysFieldMaxDistanceCtlr")
	{
		Index = TargetObjectRegistry.NiPSysFieldMaxDistanceCtlr_Registry.AddData();
		TargetObjectRegistry.NiPSysFieldMaxDistanceCtlr_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPSysAirFieldAirFrictionCtlr")
	{
		Index = TargetObjectRegistry.NiPSysAirFieldAirFrictionCtlr_Registry.AddData();
		TargetObjectRegistry.NiPSysAirFieldAirFrictionCtlr_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPSysAirFieldInheritVelocityCtlr")
	{
		Index = TargetObjectRegistry.NiPSysAirFieldInheritVelocityCtlr_Registry.AddData();
		TargetObjectRegistry.NiPSysAirFieldInheritVelocityCtlr_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPSysAirFieldSpreadCtlr")
	{
		Index = TargetObjectRegistry.NiPSysAirFieldSpreadCtlr_Registry.AddData();
		TargetObjectRegistry.NiPSysAirFieldSpreadCtlr_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPSysInitialRotSpeedCtlr")
	{
		Index = TargetObjectRegistry.NiPSysInitialRotSpeedCtlr_Registry.AddData();
		TargetObjectRegistry.NiPSysInitialRotSpeedCtlr_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPSysInitialRotSpeedVarCtlr")
	{
		Index = TargetObjectRegistry.NiPSysInitialRotSpeedVarCtlr_Registry.AddData();
		TargetObjectRegistry.NiPSysInitialRotSpeedVarCtlr_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPSysInitialRotAngleCtlr")
	{
		Index = TargetObjectRegistry.NiPSysInitialRotAngleCtlr_Registry.AddData();
		TargetObjectRegistry.NiPSysInitialRotAngleCtlr_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPSysInitialRotAngleVarCtlr")
	{
		Index = TargetObjectRegistry.NiPSysInitialRotAngleVarCtlr_Registry.AddData();
		TargetObjectRegistry.NiPSysInitialRotAngleVarCtlr_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPSysEmitterPlanarAngleCtlr")
	{
		Index = TargetObjectRegistry.NiPSysEmitterPlanarAngleCtlr_Registry.AddData();
		TargetObjectRegistry.NiPSysEmitterPlanarAngleCtlr_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPSysEmitterPlanarAngleVarCtlr")
	{
		Index = TargetObjectRegistry.NiPSysEmitterPlanarAngleVarCtlr_Registry.AddData();
		TargetObjectRegistry.NiPSysEmitterPlanarAngleVarCtlr_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPSysAirFieldModifier")
	{
		Index = TargetObjectRegistry.NiPSysAirFieldModifier_Registry.AddData();
		TargetObjectRegistry.NiPSysAirFieldModifier_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPSysTrailEmitter")
	{
		Index = TargetObjectRegistry.NiPSysTrailEmitter_Registry.AddData();
		TargetObjectRegistry.NiPSysTrailEmitter_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiLightIntensityController")
	{
		Index = TargetObjectRegistry.NiLightIntensityController_Registry.AddData();
		TargetObjectRegistry.NiLightIntensityController_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPSysRadialFieldModifier")
	{
		Index = TargetObjectRegistry.NiPSysRadialFieldModifier_Registry.AddData();
		TargetObjectRegistry.NiPSysRadialFieldModifier_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiLODData")
	{
		Index = TargetObjectRegistry.NiLODData_Registry.AddData();
		TargetObjectRegistry.NiLODData_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiRangeLODData")
	{
		Index = TargetObjectRegistry.NiRangeLODData_Registry.AddData();
		TargetObjectRegistry.NiRangeLODData_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiScreenLODData")
	{
		Index = TargetObjectRegistry.NiScreenLODData_Registry.AddData();
		TargetObjectRegistry.NiScreenLODData_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiRotatingParticles")
	{
		Index = TargetObjectRegistry.NiRotatingParticles_Registry.AddData();
		TargetObjectRegistry.NiRotatingParticles_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiSequenceStreamHelper")
	{
		Index = TargetObjectRegistry.NiSequenceStreamHelper_Registry.AddData();
		TargetObjectRegistry.NiSequenceStreamHelper_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiShadeProperty")
	{
		Index = TargetObjectRegistry.NiShadeProperty_Registry.AddData();
		TargetObjectRegistry.NiShadeProperty_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiSkinData")
	{
		Index = TargetObjectRegistry.NiSkinData_Registry.AddData();
		TargetObjectRegistry.NiSkinData_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiSkinInstance")
	{
		Index = TargetObjectRegistry.NiSkinInstance_Registry.AddData();
		TargetObjectRegistry.NiSkinInstance_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiTriShapeSkinController")
	{
		Index = TargetObjectRegistry.NiTriShapeSkinController_Registry.AddData();
		TargetObjectRegistry.NiTriShapeSkinController_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiClodSkinInstance")
	{
		Index = TargetObjectRegistry.NiClodSkinInstance_Registry.AddData();
		TargetObjectRegistry.NiClodSkinInstance_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiSkinPartition")
	{
		Index = TargetObjectRegistry.NiSkinPartition_Registry.AddData();
		TargetObjectRegistry.NiSkinPartition_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiTexture")
	{
		Index = TargetObjectRegistry.NiTexture_Registry.AddData();
		TargetObjectRegistry.NiTexture_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiSourceTexture")
	{
		Index = TargetObjectRegistry.NiSourceTexture_Registry.AddData();
		TargetObjectRegistry.NiSourceTexture_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiSpecularProperty")
	{
		Index = TargetObjectRegistry.NiSpecularProperty_Registry.AddData();
		TargetObjectRegistry.NiSpecularProperty_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiSphericalCollider")
	{
		Index = TargetObjectRegistry.NiSphericalCollider_Registry.AddData();
		TargetObjectRegistry.NiSphericalCollider_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiSpotLight")
	{
		Index = TargetObjectRegistry.NiSpotLight_Registry.AddData();
		TargetObjectRegistry.NiSpotLight_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiStencilProperty")
	{
		Index = TargetObjectRegistry.NiStencilProperty_Registry.AddData();
		TargetObjectRegistry.NiStencilProperty_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiStringExtraData")
	{
		Index = TargetObjectRegistry.NiStringExtraData_Registry.AddData();
		TargetObjectRegistry.NiStringExtraData_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiStringPalette")
	{
		Index = TargetObjectRegistry.NiStringPalette_Registry.AddData();
		TargetObjectRegistry.NiStringPalette_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiStringsExtraData")
	{
		Index = TargetObjectRegistry.NiStringsExtraData_Registry.AddData();
		TargetObjectRegistry.NiStringsExtraData_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiTextKeyExtraData")
	{
		Index = TargetObjectRegistry.NiTextKeyExtraData_Registry.AddData();
		TargetObjectRegistry.NiTextKeyExtraData_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiTextureEffect")
	{
		Index = TargetObjectRegistry.NiTextureEffect_Registry.AddData();
		TargetObjectRegistry.NiTextureEffect_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiTextureModeProperty")
	{
		Index = TargetObjectRegistry.NiTextureModeProperty_Registry.AddData();
		TargetObjectRegistry.NiTextureModeProperty_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiImage")
	{
		Index = TargetObjectRegistry.NiImage_Registry.AddData();
		TargetObjectRegistry.NiImage_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiTextureProperty")
	{
		Index = TargetObjectRegistry.NiTextureProperty_Registry.AddData();
		TargetObjectRegistry.NiTextureProperty_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiMultiTextureProperty")
	{
		Index = TargetObjectRegistry.NiMultiTextureProperty_Registry.AddData();
		TargetObjectRegistry.NiMultiTextureProperty_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiTexturingProperty")
	{
		Index = TargetObjectRegistry.NiTexturingProperty_Registry.AddData();
		TargetObjectRegistry.NiTexturingProperty_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiTransformData")
	{
		Index = TargetObjectRegistry.NiTransformData_Registry.AddData();
		TargetObjectRegistry.NiTransformData_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiTriShape")
	{
		Index = TargetObjectRegistry.NiTriShape_Registry.AddData();
		TargetObjectRegistry.NiTriShape_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiTriShapeData")
	{
		Index = TargetObjectRegistry.NiTriShapeData_Registry.AddData();
		TargetObjectRegistry.NiTriShapeData_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiTriStrips")
	{
		Index = TargetObjectRegistry.NiTriStrips_Registry.AddData();
		TargetObjectRegistry.NiTriStrips_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiTriStripsData")
	{
		Index = TargetObjectRegistry.NiTriStripsData_Registry.AddData();
		TargetObjectRegistry.NiTriStripsData_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiEnvMappedTriShape")
	{
		Index = TargetObjectRegistry.NiEnvMappedTriShape_Registry.AddData();
		TargetObjectRegistry.NiEnvMappedTriShape_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiEnvMappedTriShapeData")
	{
		Index = TargetObjectRegistry.NiEnvMappedTriShapeData_Registry.AddData();
		TargetObjectRegistry.NiEnvMappedTriShapeData_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiBezierTriangle4")
	{
		Index = TargetObjectRegistry.NiBezierTriangle4_Registry.AddData();
		TargetObjectRegistry.NiBezierTriangle4_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiBezierMesh")
	{
		Index = TargetObjectRegistry.NiBezierMesh_Registry.AddData();
		TargetObjectRegistry.NiBezierMesh_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiClod")
	{
		Index = TargetObjectRegistry.NiClod_Registry.AddData();
		TargetObjectRegistry.NiClod_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiClodData")
	{
		Index = TargetObjectRegistry.NiClodData_Registry.AddData();
		TargetObjectRegistry.NiClodData_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiUVController")
	{
		Index = TargetObjectRegistry.NiUVController_Registry.AddData();
		TargetObjectRegistry.NiUVController_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiUVData")
	{
		Index = TargetObjectRegistry.NiUVData_Registry.AddData();
		TargetObjectRegistry.NiUVData_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiVectorExtraData")
	{
		Index = TargetObjectRegistry.NiVectorExtraData_Registry.AddData();
		TargetObjectRegistry.NiVectorExtraData_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiVertexColorProperty")
	{
		Index = TargetObjectRegistry.NiVertexColorProperty_Registry.AddData();
		TargetObjectRegistry.NiVertexColorProperty_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiVertWeightsExtraData")
	{
		Index = TargetObjectRegistry.NiVertWeightsExtraData_Registry.AddData();
		TargetObjectRegistry.NiVertWeightsExtraData_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiVisData")
	{
		Index = TargetObjectRegistry.NiVisData_Registry.AddData();
		TargetObjectRegistry.NiVisData_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiWireframeProperty")
	{
		Index = TargetObjectRegistry.NiWireframeProperty_Registry.AddData();
		TargetObjectRegistry.NiWireframeProperty_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiZBufferProperty")
	{
		Index = TargetObjectRegistry.NiZBufferProperty_Registry.AddData();
		TargetObjectRegistry.NiZBufferProperty_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "RootCollisionNode")
	{
		Index = TargetObjectRegistry.RootCollisionNode_Registry.AddData();
		TargetObjectRegistry.RootCollisionNode_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiRawImageData")
	{
		Index = TargetObjectRegistry.NiRawImageData_Registry.AddData();
		TargetObjectRegistry.NiRawImageData_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiSortAdjustNode")
	{
		Index = TargetObjectRegistry.NiSortAdjustNode_Registry.AddData();
		TargetObjectRegistry.NiSortAdjustNode_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiSourceCubeMap")
	{
		Index = TargetObjectRegistry.NiSourceCubeMap_Registry.AddData();
		TargetObjectRegistry.NiSourceCubeMap_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPhysXProp")
	{
		Index = TargetObjectRegistry.NiPhysXProp_Registry.AddData();
		TargetObjectRegistry.NiPhysXProp_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPhysXPropDesc")
	{
		Index = TargetObjectRegistry.NiPhysXPropDesc_Registry.AddData();
		TargetObjectRegistry.NiPhysXPropDesc_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPhysXActorDesc")
	{
		Index = TargetObjectRegistry.NiPhysXActorDesc_Registry.AddData();
		TargetObjectRegistry.NiPhysXActorDesc_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPhysXBodyDesc")
	{
		Index = TargetObjectRegistry.NiPhysXBodyDesc_Registry.AddData();
		TargetObjectRegistry.NiPhysXBodyDesc_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPhysXD6JointDesc")
	{
		Index = TargetObjectRegistry.NiPhysXD6JointDesc_Registry.AddData();
		TargetObjectRegistry.NiPhysXD6JointDesc_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPhysXShapeDesc")
	{
		Index = TargetObjectRegistry.NiPhysXShapeDesc_Registry.AddData();
		TargetObjectRegistry.NiPhysXShapeDesc_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPhysXMeshDesc")
	{
		Index = TargetObjectRegistry.NiPhysXMeshDesc_Registry.AddData();
		TargetObjectRegistry.NiPhysXMeshDesc_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPhysXMaterialDesc")
	{
		Index = TargetObjectRegistry.NiPhysXMaterialDesc_Registry.AddData();
		TargetObjectRegistry.NiPhysXMaterialDesc_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPhysXKinematicSrc")
	{
		Index = TargetObjectRegistry.NiPhysXKinematicSrc_Registry.AddData();
		TargetObjectRegistry.NiPhysXKinematicSrc_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPhysXTransformDest")
	{
		Index = TargetObjectRegistry.NiPhysXTransformDest_Registry.AddData();
		TargetObjectRegistry.NiPhysXTransformDest_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiArkAnimationExtraData")
	{
		Index = TargetObjectRegistry.NiArkAnimationExtraData_Registry.AddData();
		TargetObjectRegistry.NiArkAnimationExtraData_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiArkImporterExtraData")
	{
		Index = TargetObjectRegistry.NiArkImporterExtraData_Registry.AddData();
		TargetObjectRegistry.NiArkImporterExtraData_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiArkTextureExtraData")
	{
		Index = TargetObjectRegistry.NiArkTextureExtraData_Registry.AddData();
		TargetObjectRegistry.NiArkTextureExtraData_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiArkViewportInfoExtraData")
	{
		Index = TargetObjectRegistry.NiArkViewportInfoExtraData_Registry.AddData();
		TargetObjectRegistry.NiArkViewportInfoExtraData_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiArkShaderExtraData")
	{
		Index = TargetObjectRegistry.NiArkShaderExtraData_Registry.AddData();
		TargetObjectRegistry.NiArkShaderExtraData_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiLines")
	{
		Index = TargetObjectRegistry.NiLines_Registry.AddData();
		TargetObjectRegistry.NiLines_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiLinesData")
	{
		Index = TargetObjectRegistry.NiLinesData_Registry.AddData();
		TargetObjectRegistry.NiLinesData_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiScreenElementsData")
	{
		Index = TargetObjectRegistry.NiScreenElementsData_Registry.AddData();
		TargetObjectRegistry.NiScreenElementsData_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiScreenElements")
	{
		Index = TargetObjectRegistry.NiScreenElements_Registry.AddData();
		TargetObjectRegistry.NiScreenElements_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiRoomGroup")
	{
		Index = TargetObjectRegistry.NiRoomGroup_Registry.AddData();
		TargetObjectRegistry.NiRoomGroup_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiRoom")
	{
		Index = TargetObjectRegistry.NiRoom_Registry.AddData();
		TargetObjectRegistry.NiRoom_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPortal")
	{
		Index = TargetObjectRegistry.NiPortal_Registry.AddData();
		TargetObjectRegistry.NiPortal_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "BSFadeNode")
	{
		Index = TargetObjectRegistry.BSFadeNode_Registry.AddData();
		TargetObjectRegistry.BSFadeNode_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "BSShaderProperty")
	{
		Index = TargetObjectRegistry.BSShaderProperty_Registry.AddData();
		TargetObjectRegistry.BSShaderProperty_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "BSShaderLightingProperty")
	{
		Index = TargetObjectRegistry.BSShaderLightingProperty_Registry.AddData();
		TargetObjectRegistry.BSShaderLightingProperty_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "BSShaderNoLightingProperty")
	{
		Index = TargetObjectRegistry.BSShaderNoLightingProperty_Registry.AddData();
		TargetObjectRegistry.BSShaderNoLightingProperty_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "BSShaderPPLightingProperty")
	{
		Index = TargetObjectRegistry.BSShaderPPLightingProperty_Registry.AddData();
		TargetObjectRegistry.BSShaderPPLightingProperty_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "BSEffectShaderPropertyFloatController")
	{
		Index = TargetObjectRegistry.BSEffectShaderPropertyFloatController_Registry.AddData();
		TargetObjectRegistry.BSEffectShaderPropertyFloatController_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "BSEffectShaderPropertyColorController")
	{
		Index = TargetObjectRegistry.BSEffectShaderPropertyColorController_Registry.AddData();
		TargetObjectRegistry.BSEffectShaderPropertyColorController_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "BSLightingShaderPropertyFloatController")
	{
		Index = TargetObjectRegistry.BSLightingShaderPropertyFloatController_Registry.AddData();
		TargetObjectRegistry.BSLightingShaderPropertyFloatController_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "BSLightingShaderPropertyColorController")
	{
		Index = TargetObjectRegistry.BSLightingShaderPropertyColorController_Registry.AddData();
		TargetObjectRegistry.BSLightingShaderPropertyColorController_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "BSNiAlphaPropertyTestRefController")
	{
		Index = TargetObjectRegistry.BSNiAlphaPropertyTestRefController_Registry.AddData();
		TargetObjectRegistry.BSNiAlphaPropertyTestRefController_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "BSProceduralLightningController")
	{
		Index = TargetObjectRegistry.BSProceduralLightningController_Registry.AddData();
		TargetObjectRegistry.BSProceduralLightningController_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "BSShaderTextureSet")
	{
		Index = TargetObjectRegistry.BSShaderTextureSet_Registry.AddData();
		TargetObjectRegistry.BSShaderTextureSet_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "WaterShaderProperty")
	{
		Index = TargetObjectRegistry.WaterShaderProperty_Registry.AddData();
		TargetObjectRegistry.WaterShaderProperty_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "SkyShaderProperty")
	{
		Index = TargetObjectRegistry.SkyShaderProperty_Registry.AddData();
		TargetObjectRegistry.SkyShaderProperty_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "TileShaderProperty")
	{
		Index = TargetObjectRegistry.TileShaderProperty_Registry.AddData();
		TargetObjectRegistry.TileShaderProperty_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "DistantLODShaderProperty")
	{
		Index = TargetObjectRegistry.DistantLODShaderProperty_Registry.AddData();
		TargetObjectRegistry.DistantLODShaderProperty_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "BSDistantTreeShaderProperty")
	{
		Index = TargetObjectRegistry.BSDistantTreeShaderProperty_Registry.AddData();
		TargetObjectRegistry.BSDistantTreeShaderProperty_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "TallGrassShaderProperty")
	{
		Index = TargetObjectRegistry.TallGrassShaderProperty_Registry.AddData();
		TargetObjectRegistry.TallGrassShaderProperty_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "VolumetricFogShaderProperty")
	{
		Index = TargetObjectRegistry.VolumetricFogShaderProperty_Registry.AddData();
		TargetObjectRegistry.VolumetricFogShaderProperty_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "HairShaderProperty")
	{
		Index = TargetObjectRegistry.HairShaderProperty_Registry.AddData();
		TargetObjectRegistry.HairShaderProperty_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "Lighting30ShaderProperty")
	{
		Index = TargetObjectRegistry.Lighting30ShaderProperty_Registry.AddData();
		TargetObjectRegistry.Lighting30ShaderProperty_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "BSLightingShaderProperty")
	{
		Index = TargetObjectRegistry.BSLightingShaderProperty_Registry.AddData();
		TargetObjectRegistry.BSLightingShaderProperty_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "BSEffectShaderProperty")
	{
		Index = TargetObjectRegistry.BSEffectShaderProperty_Registry.AddData();
		TargetObjectRegistry.BSEffectShaderProperty_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "BSWaterShaderProperty")
	{
		Index = TargetObjectRegistry.BSWaterShaderProperty_Registry.AddData();
		TargetObjectRegistry.BSWaterShaderProperty_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "BSSkyShaderProperty")
	{
		Index = TargetObjectRegistry.BSSkyShaderProperty_Registry.AddData();
		TargetObjectRegistry.BSSkyShaderProperty_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "BSDismemberSkinInstance")
	{
		Index = TargetObjectRegistry.BSDismemberSkinInstance_Registry.AddData();
		TargetObjectRegistry.BSDismemberSkinInstance_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "BSDecalPlacementVectorExtraData")
	{
		Index = TargetObjectRegistry.BSDecalPlacementVectorExtraData_Registry.AddData();
		TargetObjectRegistry.BSDecalPlacementVectorExtraData_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "BSPSysSimpleColorModifier")
	{
		Index = TargetObjectRegistry.BSPSysSimpleColorModifier_Registry.AddData();
		TargetObjectRegistry.BSPSysSimpleColorModifier_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "BSValueNode")
	{
		Index = TargetObjectRegistry.BSValueNode_Registry.AddData();
		TargetObjectRegistry.BSValueNode_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "BSStripParticleSystem")
	{
		Index = TargetObjectRegistry.BSStripParticleSystem_Registry.AddData();
		TargetObjectRegistry.BSStripParticleSystem_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "BSStripPSysData")
	{
		Index = TargetObjectRegistry.BSStripPSysData_Registry.AddData();
		TargetObjectRegistry.BSStripPSysData_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "BSPSysStripUpdateModifier")
	{
		Index = TargetObjectRegistry.BSPSysStripUpdateModifier_Registry.AddData();
		TargetObjectRegistry.BSPSysStripUpdateModifier_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "BSMaterialEmittanceMultController")
	{
		Index = TargetObjectRegistry.BSMaterialEmittanceMultController_Registry.AddData();
		TargetObjectRegistry.BSMaterialEmittanceMultController_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "BSMasterParticleSystem")
	{
		Index = TargetObjectRegistry.BSMasterParticleSystem_Registry.AddData();
		TargetObjectRegistry.BSMasterParticleSystem_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "BSPSysMultiTargetEmitterCtlr")
	{
		Index = TargetObjectRegistry.BSPSysMultiTargetEmitterCtlr_Registry.AddData();
		TargetObjectRegistry.BSPSysMultiTargetEmitterCtlr_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "BSRefractionStrengthController")
	{
		Index = TargetObjectRegistry.BSRefractionStrengthController_Registry.AddData();
		TargetObjectRegistry.BSRefractionStrengthController_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "BSOrderedNode")
	{
		Index = TargetObjectRegistry.BSOrderedNode_Registry.AddData();
		TargetObjectRegistry.BSOrderedNode_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "BSBlastNode")
	{
		Index = TargetObjectRegistry.BSBlastNode_Registry.AddData();
		TargetObjectRegistry.BSBlastNode_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "BSDamageStage")
	{
		Index = TargetObjectRegistry.BSDamageStage_Registry.AddData();
		TargetObjectRegistry.BSDamageStage_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "BSRefractionFirePeriodController")
	{
		Index = TargetObjectRegistry.BSRefractionFirePeriodController_Registry.AddData();
		TargetObjectRegistry.BSRefractionFirePeriodController_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "bhkConvexListShape")
	{
		Index = TargetObjectRegistry.bhkConvexListShape_Registry.AddData();
		TargetObjectRegistry.bhkConvexListShape_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "BSTreadTransfInterpolator")
	{
		Index = TargetObjectRegistry.BSTreadTransfInterpolator_Registry.AddData();
		TargetObjectRegistry.BSTreadTransfInterpolator_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "BSAnimNotes")
	{
		Index = TargetObjectRegistry.BSAnimNotes_Registry.AddData();
		TargetObjectRegistry.BSAnimNotes_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "bhkLiquidAction")
	{
		Index = TargetObjectRegistry.bhkLiquidAction_Registry.AddData();
		TargetObjectRegistry.bhkLiquidAction_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "BSMultiBoundNode")
	{
		Index = TargetObjectRegistry.BSMultiBoundNode_Registry.AddData();
		TargetObjectRegistry.BSMultiBoundNode_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "BSMultiBound")
	{
		Index = TargetObjectRegistry.BSMultiBound_Registry.AddData();
		TargetObjectRegistry.BSMultiBound_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "BSMultiBoundData")
	{
		Index = TargetObjectRegistry.BSMultiBoundData_Registry.AddData();
		TargetObjectRegistry.BSMultiBoundData_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "BSMultiBoundOBB")
	{
		Index = TargetObjectRegistry.BSMultiBoundOBB_Registry.AddData();
		TargetObjectRegistry.BSMultiBoundOBB_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "BSMultiBoundSphere")
	{
		Index = TargetObjectRegistry.BSMultiBoundSphere_Registry.AddData();
		TargetObjectRegistry.BSMultiBoundSphere_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "BSSegmentedTriShape")
	{
		Index = TargetObjectRegistry.BSSegmentedTriShape_Registry.AddData();
		TargetObjectRegistry.BSSegmentedTriShape_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "BSMultiBoundAABB")
	{
		Index = TargetObjectRegistry.BSMultiBoundAABB_Registry.AddData();
		TargetObjectRegistry.BSMultiBoundAABB_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiAdditionalGeometryData")
	{
		Index = TargetObjectRegistry.NiAdditionalGeometryData_Registry.AddData();
		TargetObjectRegistry.NiAdditionalGeometryData_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "BSPackedAdditionalGeometryData")
	{
		Index = TargetObjectRegistry.BSPackedAdditionalGeometryData_Registry.AddData();
		TargetObjectRegistry.BSPackedAdditionalGeometryData_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "BSWArray")
	{
		Index = TargetObjectRegistry.BSWArray_Registry.AddData();
		TargetObjectRegistry.BSWArray_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "bhkAabbPhantom")
	{
		Index = TargetObjectRegistry.bhkAabbPhantom_Registry.AddData();
		TargetObjectRegistry.bhkAabbPhantom_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "BSFrustumFOVController")
	{
		Index = TargetObjectRegistry.BSFrustumFOVController_Registry.AddData();
		TargetObjectRegistry.BSFrustumFOVController_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "BSDebrisNode")
	{
		Index = TargetObjectRegistry.BSDebrisNode_Registry.AddData();
		TargetObjectRegistry.BSDebrisNode_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "bhkBreakableConstraint")
	{
		Index = TargetObjectRegistry.bhkBreakableConstraint_Registry.AddData();
		TargetObjectRegistry.bhkBreakableConstraint_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "bhkOrientHingedBodyAction")
	{
		Index = TargetObjectRegistry.bhkOrientHingedBodyAction_Registry.AddData();
		TargetObjectRegistry.bhkOrientHingedBodyAction_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiDataStream")
	{
		Index = TargetObjectRegistry.NiDataStream_Registry.AddData();
		TargetObjectRegistry.NiDataStream_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiRenderObject")
	{
		Index = TargetObjectRegistry.NiRenderObject_Registry.AddData();
		TargetObjectRegistry.NiRenderObject_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiMeshModifier")
	{
		Index = TargetObjectRegistry.NiMeshModifier_Registry.AddData();
		TargetObjectRegistry.NiMeshModifier_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiMesh")
	{
		Index = TargetObjectRegistry.NiMesh_Registry.AddData();
		TargetObjectRegistry.NiMesh_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiMorphWeightsController")
	{
		Index = TargetObjectRegistry.NiMorphWeightsController_Registry.AddData();
		TargetObjectRegistry.NiMorphWeightsController_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiMorphMeshModifier")
	{
		Index = TargetObjectRegistry.NiMorphMeshModifier_Registry.AddData();
		TargetObjectRegistry.NiMorphMeshModifier_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiSkinningMeshModifier")
	{
		Index = TargetObjectRegistry.NiSkinningMeshModifier_Registry.AddData();
		TargetObjectRegistry.NiSkinningMeshModifier_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiInstancingMeshModifier")
	{
		Index = TargetObjectRegistry.NiInstancingMeshModifier_Registry.AddData();
		TargetObjectRegistry.NiInstancingMeshModifier_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiSkinningLODController")
	{
		Index = TargetObjectRegistry.NiSkinningLODController_Registry.AddData();
		TargetObjectRegistry.NiSkinningLODController_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPSParticleSystem")
	{
		Index = TargetObjectRegistry.NiPSParticleSystem_Registry.AddData();
		TargetObjectRegistry.NiPSParticleSystem_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPSMeshParticleSystem")
	{
		Index = TargetObjectRegistry.NiPSMeshParticleSystem_Registry.AddData();
		TargetObjectRegistry.NiPSMeshParticleSystem_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPSEmitParticlesCtlr")
	{
		Index = TargetObjectRegistry.NiPSEmitParticlesCtlr_Registry.AddData();
		TargetObjectRegistry.NiPSEmitParticlesCtlr_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPSForceActiveCtlr")
	{
		Index = TargetObjectRegistry.NiPSForceActiveCtlr_Registry.AddData();
		TargetObjectRegistry.NiPSForceActiveCtlr_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPSSimulator")
	{
		Index = TargetObjectRegistry.NiPSSimulator_Registry.AddData();
		TargetObjectRegistry.NiPSSimulator_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPSSimulatorStep")
	{
		Index = TargetObjectRegistry.NiPSSimulatorStep_Registry.AddData();
		TargetObjectRegistry.NiPSSimulatorStep_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPSSimulatorGeneralStep")
	{
		Index = TargetObjectRegistry.NiPSSimulatorGeneralStep_Registry.AddData();
		TargetObjectRegistry.NiPSSimulatorGeneralStep_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPSSimulatorForcesStep")
	{
		Index = TargetObjectRegistry.NiPSSimulatorForcesStep_Registry.AddData();
		TargetObjectRegistry.NiPSSimulatorForcesStep_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPSSimulatorCollidersStep")
	{
		Index = TargetObjectRegistry.NiPSSimulatorCollidersStep_Registry.AddData();
		TargetObjectRegistry.NiPSSimulatorCollidersStep_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPSSimulatorMeshAlignStep")
	{
		Index = TargetObjectRegistry.NiPSSimulatorMeshAlignStep_Registry.AddData();
		TargetObjectRegistry.NiPSSimulatorMeshAlignStep_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPSSimulatorFinalStep")
	{
		Index = TargetObjectRegistry.NiPSSimulatorFinalStep_Registry.AddData();
		TargetObjectRegistry.NiPSSimulatorFinalStep_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPSFacingQuadGenerator")
	{
		Index = TargetObjectRegistry.NiPSFacingQuadGenerator_Registry.AddData();
		TargetObjectRegistry.NiPSFacingQuadGenerator_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiShadowGenerator")
	{
		Index = TargetObjectRegistry.NiShadowGenerator_Registry.AddData();
		TargetObjectRegistry.NiShadowGenerator_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPSBoundUpdater")
	{
		Index = TargetObjectRegistry.NiPSBoundUpdater_Registry.AddData();
		TargetObjectRegistry.NiPSBoundUpdater_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPSDragForce")
	{
		Index = TargetObjectRegistry.NiPSDragForce_Registry.AddData();
		TargetObjectRegistry.NiPSDragForce_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPSGravityForce")
	{
		Index = TargetObjectRegistry.NiPSGravityForce_Registry.AddData();
		TargetObjectRegistry.NiPSGravityForce_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPSBoxEmitter")
	{
		Index = TargetObjectRegistry.NiPSBoxEmitter_Registry.AddData();
		TargetObjectRegistry.NiPSBoxEmitter_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPSMeshEmitter")
	{
		Index = TargetObjectRegistry.NiPSMeshEmitter_Registry.AddData();
		TargetObjectRegistry.NiPSMeshEmitter_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPSGravityStrengthCtlr")
	{
		Index = TargetObjectRegistry.NiPSGravityStrengthCtlr_Registry.AddData();
		TargetObjectRegistry.NiPSGravityStrengthCtlr_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPSPlanarCollider")
	{
		Index = TargetObjectRegistry.NiPSPlanarCollider_Registry.AddData();
		TargetObjectRegistry.NiPSPlanarCollider_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPSEmitterSpeedCtlr")
	{
		Index = TargetObjectRegistry.NiPSEmitterSpeedCtlr_Registry.AddData();
		TargetObjectRegistry.NiPSEmitterSpeedCtlr_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPSEmitterRadiusCtlr")
	{
		Index = TargetObjectRegistry.NiPSEmitterRadiusCtlr_Registry.AddData();
		TargetObjectRegistry.NiPSEmitterRadiusCtlr_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPSResetOnLoopCtlr")
	{
		Index = TargetObjectRegistry.NiPSResetOnLoopCtlr_Registry.AddData();
		TargetObjectRegistry.NiPSResetOnLoopCtlr_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPSSphereEmitter")
	{
		Index = TargetObjectRegistry.NiPSSphereEmitter_Registry.AddData();
		TargetObjectRegistry.NiPSSphereEmitter_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPSCylinderEmitter")
	{
		Index = TargetObjectRegistry.NiPSCylinderEmitter_Registry.AddData();
		TargetObjectRegistry.NiPSCylinderEmitter_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPSEmitterDeclinationCtlr")
	{
		Index = TargetObjectRegistry.NiPSEmitterDeclinationCtlr_Registry.AddData();
		TargetObjectRegistry.NiPSEmitterDeclinationCtlr_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPSEmitterDeclinationVarCtlr")
	{
		Index = TargetObjectRegistry.NiPSEmitterDeclinationVarCtlr_Registry.AddData();
		TargetObjectRegistry.NiPSEmitterDeclinationVarCtlr_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPSEmitterPlanarAngleCtlr")
	{
		Index = TargetObjectRegistry.NiPSEmitterPlanarAngleCtlr_Registry.AddData();
		TargetObjectRegistry.NiPSEmitterPlanarAngleCtlr_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPSEmitterPlanarAngleVarCtlr")
	{
		Index = TargetObjectRegistry.NiPSEmitterPlanarAngleVarCtlr_Registry.AddData();
		TargetObjectRegistry.NiPSEmitterPlanarAngleVarCtlr_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPSEmitterRotAngleCtlr")
	{
		Index = TargetObjectRegistry.NiPSEmitterRotAngleCtlr_Registry.AddData();
		TargetObjectRegistry.NiPSEmitterRotAngleCtlr_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPSEmitterRotAngleVarCtlr")
	{
		Index = TargetObjectRegistry.NiPSEmitterRotAngleVarCtlr_Registry.AddData();
		TargetObjectRegistry.NiPSEmitterRotAngleVarCtlr_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPSEmitterRotSpeedCtlr")
	{
		Index = TargetObjectRegistry.NiPSEmitterRotSpeedCtlr_Registry.AddData();
		TargetObjectRegistry.NiPSEmitterRotSpeedCtlr_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPSEmitterRotSpeedVarCtlr")
	{
		Index = TargetObjectRegistry.NiPSEmitterRotSpeedVarCtlr_Registry.AddData();
		TargetObjectRegistry.NiPSEmitterRotSpeedVarCtlr_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPSEmitterLifeSpanCtlr")
	{
		Index = TargetObjectRegistry.NiPSEmitterLifeSpanCtlr_Registry.AddData();
		TargetObjectRegistry.NiPSEmitterLifeSpanCtlr_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPSBombForce")
	{
		Index = TargetObjectRegistry.NiPSBombForce_Registry.AddData();
		TargetObjectRegistry.NiPSBombForce_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPSSphericalCollider")
	{
		Index = TargetObjectRegistry.NiPSSphericalCollider_Registry.AddData();
		TargetObjectRegistry.NiPSSphericalCollider_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPSSpawner")
	{
		Index = TargetObjectRegistry.NiPSSpawner_Registry.AddData();
		TargetObjectRegistry.NiPSSpawner_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiSequenceData")
	{
		Index = TargetObjectRegistry.NiSequenceData_Registry.AddData();
		TargetObjectRegistry.NiSequenceData_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiTransformEvaluator")
	{
		Index = TargetObjectRegistry.NiTransformEvaluator_Registry.AddData();
		TargetObjectRegistry.NiTransformEvaluator_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiBSplineCompTransformEvaluator")
	{
		Index = TargetObjectRegistry.NiBSplineCompTransformEvaluator_Registry.AddData();
		TargetObjectRegistry.NiBSplineCompTransformEvaluator_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiMeshHWInstance")
	{
		Index = TargetObjectRegistry.NiMeshHWInstance_Registry.AddData();
		TargetObjectRegistry.NiMeshHWInstance_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiFurSpringController")
	{
		Index = TargetObjectRegistry.NiFurSpringController_Registry.AddData();
		TargetObjectRegistry.NiFurSpringController_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "CStreamableAssetData")
	{
		Index = TargetObjectRegistry.CStreamableAssetData_Registry.AddData();
		TargetObjectRegistry.CStreamableAssetData_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "bhkCompressedMeshShape")
	{
		Index = TargetObjectRegistry.bhkCompressedMeshShape_Registry.AddData();
		TargetObjectRegistry.bhkCompressedMeshShape_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "bhkCompressedMeshShapeData")
	{
		Index = TargetObjectRegistry.bhkCompressedMeshShapeData_Registry.AddData();
		TargetObjectRegistry.bhkCompressedMeshShapeData_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "BSInvMarker")
	{
		Index = TargetObjectRegistry.BSInvMarker_Registry.AddData();
		TargetObjectRegistry.BSInvMarker_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "BSBoneLODExtraData")
	{
		Index = TargetObjectRegistry.BSBoneLODExtraData_Registry.AddData();
		TargetObjectRegistry.BSBoneLODExtraData_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "BSBehaviorGraphExtraData")
	{
		Index = TargetObjectRegistry.BSBehaviorGraphExtraData_Registry.AddData();
		TargetObjectRegistry.BSBehaviorGraphExtraData_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "BSLagBoneController")
	{
		Index = TargetObjectRegistry.BSLagBoneController_Registry.AddData();
		TargetObjectRegistry.BSLagBoneController_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "BSLODTriShape")
	{
		Index = TargetObjectRegistry.BSLODTriShape_Registry.AddData();
		TargetObjectRegistry.BSLODTriShape_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "BSFurnitureMarkerNode")
	{
		Index = TargetObjectRegistry.BSFurnitureMarkerNode_Registry.AddData();
		TargetObjectRegistry.BSFurnitureMarkerNode_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "BSLeafAnimNode")
	{
		Index = TargetObjectRegistry.BSLeafAnimNode_Registry.AddData();
		TargetObjectRegistry.BSLeafAnimNode_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "BSTreeNode")
	{
		Index = TargetObjectRegistry.BSTreeNode_Registry.AddData();
		TargetObjectRegistry.BSTreeNode_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiLightRadiusController")
	{
		Index = TargetObjectRegistry.NiLightRadiusController_Registry.AddData();
		TargetObjectRegistry.NiLightRadiusController_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "BSShape")
	{
		Index = TargetObjectRegistry.BSShape_Registry.AddData();
		TargetObjectRegistry.BSShape_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "BSTriShape")
	{
		Index = TargetObjectRegistry.BSTriShape_Registry.AddData();
		TargetObjectRegistry.BSTriShape_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "BSSubIndexTriShape")
	{
		Index = TargetObjectRegistry.BSSubIndexTriShape_Registry.AddData();
		TargetObjectRegistry.BSSubIndexTriShape_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "BSMeshLODTriShape")
	{
		Index = TargetObjectRegistry.BSMeshLODTriShape_Registry.AddData();
		TargetObjectRegistry.BSMeshLODTriShape_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "bhkNPCollisionObject")
	{
		Index = TargetObjectRegistry.bhkNPCollisionObject_Registry.AddData();
		TargetObjectRegistry.bhkNPCollisionObject_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "BSExtraData")
	{
		Index = TargetObjectRegistry.BSExtraData_Registry.AddData();
		TargetObjectRegistry.BSExtraData_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "bhkPhysicsSystem")
	{
		Index = TargetObjectRegistry.bhkPhysicsSystem_Registry.AddData();
		TargetObjectRegistry.bhkPhysicsSystem_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "bhkRagdollSystem")
	{
		Index = TargetObjectRegistry.bhkRagdollSystem_Registry.AddData();
		TargetObjectRegistry.bhkRagdollSystem_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "BSClothExtraData")
	{
		Index = TargetObjectRegistry.BSClothExtraData_Registry.AddData();
		TargetObjectRegistry.BSClothExtraData_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "BSSkin__Instance")
	{
		Index = TargetObjectRegistry.BSSkin__Instance_Registry.AddData();
		TargetObjectRegistry.BSSkin__Instance_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "BSSkin__BoneData")
	{
		Index = TargetObjectRegistry.BSSkin__BoneData_Registry.AddData();
		TargetObjectRegistry.BSSkin__BoneData_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "BSPositionData")
	{
		Index = TargetObjectRegistry.BSPositionData_Registry.AddData();
		TargetObjectRegistry.BSPositionData_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "BSConnectPoint__Parents")
	{
		Index = TargetObjectRegistry.BSConnectPoint__Parents_Registry.AddData();
		TargetObjectRegistry.BSConnectPoint__Parents_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "BSConnectPoint__Children")
	{
		Index = TargetObjectRegistry.BSConnectPoint__Children_Registry.AddData();
		TargetObjectRegistry.BSConnectPoint__Children_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	FixCurrentNodeData();
	CurrentNode->IndexInRegistry = Index;
}

#ifndef NifNodeTreeAddon_DLL
void NifNodeTreeData::NifNodeTree::CopyNodeToTree(Niflib::NiObjectRef TargetNode, std::string TargetMenuMaster, std::string SpecialModifier /*= ""*/, std::string ItemName /*= ""*/, std::string InternalName /*= ""*/)
{
	AddMenuItemData(TargetMenuMaster, SpecialModifier, ItemName, InternalName);
	FixCurrentNodeData();
	std::string TargetNodeType = TargetNode->TYPE.GetTypeName();
	CurrentNode->NodeType = TargetNodeType;
	if(ItemName != "") { CurrentNode->NodeName = ItemName; }
	else
	{
		CurrentNode->NodeName = ConvertPointerToStringAddress(TargetNode);
	}
	size_t Index;
	//Now add actual node to ObjectRegistry
	if(TargetNodeType == "NiObject")
	{
		Index = TargetObjectRegistry.NiObject_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiObject_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "Ni3dsAlphaAnimator")
	{
		Index = TargetObjectRegistry.Ni3dsAlphaAnimator_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.Ni3dsAlphaAnimator_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "Ni3dsAnimationNode")
	{
		Index = TargetObjectRegistry.Ni3dsAnimationNode_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.Ni3dsAnimationNode_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "Ni3dsColorAnimator")
	{
		Index = TargetObjectRegistry.Ni3dsColorAnimator_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.Ni3dsColorAnimator_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "Ni3dsMorphShape")
	{
		Index = TargetObjectRegistry.Ni3dsMorphShape_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.Ni3dsMorphShape_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "Ni3dsParticleSystem")
	{
		Index = TargetObjectRegistry.Ni3dsParticleSystem_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.Ni3dsParticleSystem_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "Ni3dsPathController")
	{
		Index = TargetObjectRegistry.Ni3dsPathController_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.Ni3dsPathController_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiParticleModifier")
	{
		Index = TargetObjectRegistry.NiParticleModifier_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiParticleModifier_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPSysCollider")
	{
		Index = TargetObjectRegistry.NiPSysCollider_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiPSysCollider_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "bhkRefObject")
	{
		Index = TargetObjectRegistry.bhkRefObject_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.bhkRefObject_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "bhkSerializable")
	{
		Index = TargetObjectRegistry.bhkSerializable_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.bhkSerializable_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "bhkWorldObject")
	{
		Index = TargetObjectRegistry.bhkWorldObject_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.bhkWorldObject_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "bhkPhantom")
	{
		Index = TargetObjectRegistry.bhkPhantom_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.bhkPhantom_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "bhkShapePhantom")
	{
		Index = TargetObjectRegistry.bhkShapePhantom_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.bhkShapePhantom_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "bhkSimpleShapePhantom")
	{
		Index = TargetObjectRegistry.bhkSimpleShapePhantom_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.bhkSimpleShapePhantom_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "bhkEntity")
	{
		Index = TargetObjectRegistry.bhkEntity_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.bhkEntity_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "bhkRigidBody")
	{
		Index = TargetObjectRegistry.bhkRigidBody_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.bhkRigidBody_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "bhkRigidBodyT")
	{
		Index = TargetObjectRegistry.bhkRigidBodyT_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.bhkRigidBodyT_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "bhkConstraint")
	{
		Index = TargetObjectRegistry.bhkConstraint_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.bhkConstraint_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "bhkLimitedHingeConstraint")
	{
		Index = TargetObjectRegistry.bhkLimitedHingeConstraint_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.bhkLimitedHingeConstraint_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "bhkMalleableConstraint")
	{
		Index = TargetObjectRegistry.bhkMalleableConstraint_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.bhkMalleableConstraint_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "bhkStiffSpringConstraint")
	{
		Index = TargetObjectRegistry.bhkStiffSpringConstraint_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.bhkStiffSpringConstraint_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "bhkRagdollConstraint")
	{
		Index = TargetObjectRegistry.bhkRagdollConstraint_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.bhkRagdollConstraint_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "bhkPrismaticConstraint")
	{
		Index = TargetObjectRegistry.bhkPrismaticConstraint_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.bhkPrismaticConstraint_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "bhkHingeConstraint")
	{
		Index = TargetObjectRegistry.bhkHingeConstraint_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.bhkHingeConstraint_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "bhkBallAndSocketConstraint")
	{
		Index = TargetObjectRegistry.bhkBallAndSocketConstraint_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.bhkBallAndSocketConstraint_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "bhkBallSocketConstraintChain")
	{
		Index = TargetObjectRegistry.bhkBallSocketConstraintChain_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.bhkBallSocketConstraintChain_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "bhkShape")
	{
		Index = TargetObjectRegistry.bhkShape_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.bhkShape_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "bhkTransformShape")
	{
		Index = TargetObjectRegistry.bhkTransformShape_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.bhkTransformShape_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "bhkSphereRepShape")
	{
		Index = TargetObjectRegistry.bhkSphereRepShape_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.bhkSphereRepShape_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "bhkConvexShape")
	{
		Index = TargetObjectRegistry.bhkConvexShape_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.bhkConvexShape_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "bhkSphereShape")
	{
		Index = TargetObjectRegistry.bhkSphereShape_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.bhkSphereShape_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "bhkCapsuleShape")
	{
		Index = TargetObjectRegistry.bhkCapsuleShape_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.bhkCapsuleShape_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "bhkBoxShape")
	{
		Index = TargetObjectRegistry.bhkBoxShape_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.bhkBoxShape_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "bhkConvexVerticesShape")
	{
		Index = TargetObjectRegistry.bhkConvexVerticesShape_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.bhkConvexVerticesShape_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "bhkConvexTransformShape")
	{
		Index = TargetObjectRegistry.bhkConvexTransformShape_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.bhkConvexTransformShape_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "bhkMultiSphereShape")
	{
		Index = TargetObjectRegistry.bhkMultiSphereShape_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.bhkMultiSphereShape_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "bhkBvTreeShape")
	{
		Index = TargetObjectRegistry.bhkBvTreeShape_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.bhkBvTreeShape_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "bhkMoppBvTreeShape")
	{
		Index = TargetObjectRegistry.bhkMoppBvTreeShape_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.bhkMoppBvTreeShape_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "bhkShapeCollection")
	{
		Index = TargetObjectRegistry.bhkShapeCollection_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.bhkShapeCollection_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "bhkListShape")
	{
		Index = TargetObjectRegistry.bhkListShape_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.bhkListShape_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "bhkMeshShape")
	{
		Index = TargetObjectRegistry.bhkMeshShape_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.bhkMeshShape_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "bhkPackedNiTriStripsShape")
	{
		Index = TargetObjectRegistry.bhkPackedNiTriStripsShape_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.bhkPackedNiTriStripsShape_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "bhkNiTriStripsShape")
	{
		Index = TargetObjectRegistry.bhkNiTriStripsShape_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.bhkNiTriStripsShape_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiExtraData")
	{
		Index = TargetObjectRegistry.NiExtraData_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiExtraData_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiInterpolator")
	{
		Index = TargetObjectRegistry.NiInterpolator_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiInterpolator_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiKeyBasedInterpolator")
	{
		Index = TargetObjectRegistry.NiKeyBasedInterpolator_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiKeyBasedInterpolator_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiFloatInterpolator")
	{
		Index = TargetObjectRegistry.NiFloatInterpolator_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiFloatInterpolator_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiTransformInterpolator")
	{
		Index = TargetObjectRegistry.NiTransformInterpolator_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiTransformInterpolator_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPoint3Interpolator")
	{
		Index = TargetObjectRegistry.NiPoint3Interpolator_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiPoint3Interpolator_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPathInterpolator")
	{
		Index = TargetObjectRegistry.NiPathInterpolator_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiPathInterpolator_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiBoolInterpolator")
	{
		Index = TargetObjectRegistry.NiBoolInterpolator_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiBoolInterpolator_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiBoolTimelineInterpolator")
	{
		Index = TargetObjectRegistry.NiBoolTimelineInterpolator_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiBoolTimelineInterpolator_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiBlendInterpolator")
	{
		Index = TargetObjectRegistry.NiBlendInterpolator_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiBlendInterpolator_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiBSplineInterpolator")
	{
		Index = TargetObjectRegistry.NiBSplineInterpolator_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiBSplineInterpolator_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiObjectNET")
	{
		Index = TargetObjectRegistry.NiObjectNET_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiObjectNET_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiCollisionObject")
	{
		Index = TargetObjectRegistry.NiCollisionObject_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiCollisionObject_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiCollisionData")
	{
		Index = TargetObjectRegistry.NiCollisionData_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiCollisionData_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "bhkNiCollisionObject")
	{
		Index = TargetObjectRegistry.bhkNiCollisionObject_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.bhkNiCollisionObject_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "bhkCollisionObject")
	{
		Index = TargetObjectRegistry.bhkCollisionObject_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.bhkCollisionObject_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "bhkBlendCollisionObject")
	{
		Index = TargetObjectRegistry.bhkBlendCollisionObject_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.bhkBlendCollisionObject_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "bhkPCollisionObject")
	{
		Index = TargetObjectRegistry.bhkPCollisionObject_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.bhkPCollisionObject_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "bhkSPCollisionObject")
	{
		Index = TargetObjectRegistry.bhkSPCollisionObject_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.bhkSPCollisionObject_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiAVObject")
	{
		Index = TargetObjectRegistry.NiAVObject_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiAVObject_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiDynamicEffect")
	{
		Index = TargetObjectRegistry.NiDynamicEffect_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiDynamicEffect_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiLight")
	{
		Index = TargetObjectRegistry.NiLight_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiLight_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiProperty")
	{
		Index = TargetObjectRegistry.NiProperty_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiProperty_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiTransparentProperty")
	{
		Index = TargetObjectRegistry.NiTransparentProperty_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiTransparentProperty_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPSysModifier")
	{
		Index = TargetObjectRegistry.NiPSysModifier_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiPSysModifier_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPSysEmitter")
	{
		Index = TargetObjectRegistry.NiPSysEmitter_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiPSysEmitter_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPSysVolumeEmitter")
	{
		Index = TargetObjectRegistry.NiPSysVolumeEmitter_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiPSysVolumeEmitter_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiTimeController")
	{
		Index = TargetObjectRegistry.NiTimeController_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiTimeController_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiInterpController")
	{
		Index = TargetObjectRegistry.NiInterpController_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiInterpController_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiMultiTargetTransformController")
	{
		Index = TargetObjectRegistry.NiMultiTargetTransformController_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiMultiTargetTransformController_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiGeomMorpherController")
	{
		Index = TargetObjectRegistry.NiGeomMorpherController_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiGeomMorpherController_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiMorphController")
	{
		Index = TargetObjectRegistry.NiMorphController_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiMorphController_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiMorpherController")
	{
		Index = TargetObjectRegistry.NiMorpherController_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiMorpherController_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiSingleInterpController")
	{
		Index = TargetObjectRegistry.NiSingleInterpController_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiSingleInterpController_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiKeyframeController")
	{
		Index = TargetObjectRegistry.NiKeyframeController_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiKeyframeController_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiTransformController")
	{
		Index = TargetObjectRegistry.NiTransformController_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiTransformController_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPSysModifierCtlr")
	{
		Index = TargetObjectRegistry.NiPSysModifierCtlr_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiPSysModifierCtlr_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPSysEmitterCtlr")
	{
		Index = TargetObjectRegistry.NiPSysEmitterCtlr_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiPSysEmitterCtlr_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPSysModifierBoolCtlr")
	{
		Index = TargetObjectRegistry.NiPSysModifierBoolCtlr_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiPSysModifierBoolCtlr_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPSysModifierActiveCtlr")
	{
		Index = TargetObjectRegistry.NiPSysModifierActiveCtlr_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiPSysModifierActiveCtlr_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPSysModifierFloatCtlr")
	{
		Index = TargetObjectRegistry.NiPSysModifierFloatCtlr_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiPSysModifierFloatCtlr_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPSysEmitterDeclinationCtlr")
	{
		Index = TargetObjectRegistry.NiPSysEmitterDeclinationCtlr_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiPSysEmitterDeclinationCtlr_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPSysEmitterDeclinationVarCtlr")
	{
		Index = TargetObjectRegistry.NiPSysEmitterDeclinationVarCtlr_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiPSysEmitterDeclinationVarCtlr_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPSysEmitterInitialRadiusCtlr")
	{
		Index = TargetObjectRegistry.NiPSysEmitterInitialRadiusCtlr_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiPSysEmitterInitialRadiusCtlr_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPSysEmitterLifeSpanCtlr")
	{
		Index = TargetObjectRegistry.NiPSysEmitterLifeSpanCtlr_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiPSysEmitterLifeSpanCtlr_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPSysEmitterSpeedCtlr")
	{
		Index = TargetObjectRegistry.NiPSysEmitterSpeedCtlr_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiPSysEmitterSpeedCtlr_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPSysGravityStrengthCtlr")
	{
		Index = TargetObjectRegistry.NiPSysGravityStrengthCtlr_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiPSysGravityStrengthCtlr_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiFloatInterpController")
	{
		Index = TargetObjectRegistry.NiFloatInterpController_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiFloatInterpController_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiFlipController")
	{
		Index = TargetObjectRegistry.NiFlipController_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiFlipController_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiAlphaController")
	{
		Index = TargetObjectRegistry.NiAlphaController_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiAlphaController_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiTextureTransformController")
	{
		Index = TargetObjectRegistry.NiTextureTransformController_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiTextureTransformController_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiLightDimmerController")
	{
		Index = TargetObjectRegistry.NiLightDimmerController_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiLightDimmerController_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiBoolInterpController")
	{
		Index = TargetObjectRegistry.NiBoolInterpController_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiBoolInterpController_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiVisController")
	{
		Index = TargetObjectRegistry.NiVisController_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiVisController_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPoint3InterpController")
	{
		Index = TargetObjectRegistry.NiPoint3InterpController_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiPoint3InterpController_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiMaterialColorController")
	{
		Index = TargetObjectRegistry.NiMaterialColorController_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiMaterialColorController_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiLightColorController")
	{
		Index = TargetObjectRegistry.NiLightColorController_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiLightColorController_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiExtraDataController")
	{
		Index = TargetObjectRegistry.NiExtraDataController_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiExtraDataController_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiFloatExtraDataController")
	{
		Index = TargetObjectRegistry.NiFloatExtraDataController_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiFloatExtraDataController_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiBoneLODController")
	{
		Index = TargetObjectRegistry.NiBoneLODController_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiBoneLODController_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiBSBoneLODController")
	{
		Index = TargetObjectRegistry.NiBSBoneLODController_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiBSBoneLODController_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiGeometry")
	{
		Index = TargetObjectRegistry.NiGeometry_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiGeometry_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiTriBasedGeom")
	{
		Index = TargetObjectRegistry.NiTriBasedGeom_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiTriBasedGeom_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiGeometryData")
	{
		Index = TargetObjectRegistry.NiGeometryData_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiGeometryData_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "AbstractAdditionalGeometryData")
	{
		Index = TargetObjectRegistry.AbstractAdditionalGeometryData_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.AbstractAdditionalGeometryData_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiTriBasedGeomData")
	{
		Index = TargetObjectRegistry.NiTriBasedGeomData_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiTriBasedGeomData_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "bhkBlendController")
	{
		Index = TargetObjectRegistry.bhkBlendController_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.bhkBlendController_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "BSBound")
	{
		Index = TargetObjectRegistry.BSBound_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.BSBound_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "BSFurnitureMarker")
	{
		Index = TargetObjectRegistry.BSFurnitureMarker_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.BSFurnitureMarker_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "BSParentVelocityModifier")
	{
		Index = TargetObjectRegistry.BSParentVelocityModifier_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.BSParentVelocityModifier_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "BSPSysArrayEmitter")
	{
		Index = TargetObjectRegistry.BSPSysArrayEmitter_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.BSPSysArrayEmitter_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "BSWindModifier")
	{
		Index = TargetObjectRegistry.BSWindModifier_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.BSWindModifier_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "hkPackedNiTriStripsData")
	{
		Index = TargetObjectRegistry.hkPackedNiTriStripsData_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.hkPackedNiTriStripsData_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiAlphaProperty")
	{
		Index = TargetObjectRegistry.NiAlphaProperty_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiAlphaProperty_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiAmbientLight")
	{
		Index = TargetObjectRegistry.NiAmbientLight_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiAmbientLight_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiParticlesData")
	{
		Index = TargetObjectRegistry.NiParticlesData_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiParticlesData_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiRotatingParticlesData")
	{
		Index = TargetObjectRegistry.NiRotatingParticlesData_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiRotatingParticlesData_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiAutoNormalParticlesData")
	{
		Index = TargetObjectRegistry.NiAutoNormalParticlesData_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiAutoNormalParticlesData_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPSysData")
	{
		Index = TargetObjectRegistry.NiPSysData_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiPSysData_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiMeshPSysData")
	{
		Index = TargetObjectRegistry.NiMeshPSysData_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiMeshPSysData_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiBinaryExtraData")
	{
		Index = TargetObjectRegistry.NiBinaryExtraData_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiBinaryExtraData_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiBinaryVoxelExtraData")
	{
		Index = TargetObjectRegistry.NiBinaryVoxelExtraData_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiBinaryVoxelExtraData_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiBinaryVoxelData")
	{
		Index = TargetObjectRegistry.NiBinaryVoxelData_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiBinaryVoxelData_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiBlendBoolInterpolator")
	{
		Index = TargetObjectRegistry.NiBlendBoolInterpolator_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiBlendBoolInterpolator_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiBlendFloatInterpolator")
	{
		Index = TargetObjectRegistry.NiBlendFloatInterpolator_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiBlendFloatInterpolator_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiBlendPoint3Interpolator")
	{
		Index = TargetObjectRegistry.NiBlendPoint3Interpolator_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiBlendPoint3Interpolator_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiBlendTransformInterpolator")
	{
		Index = TargetObjectRegistry.NiBlendTransformInterpolator_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiBlendTransformInterpolator_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiBoolData")
	{
		Index = TargetObjectRegistry.NiBoolData_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiBoolData_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiBooleanExtraData")
	{
		Index = TargetObjectRegistry.NiBooleanExtraData_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiBooleanExtraData_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiBSplineBasisData")
	{
		Index = TargetObjectRegistry.NiBSplineBasisData_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiBSplineBasisData_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiBSplineFloatInterpolator")
	{
		Index = TargetObjectRegistry.NiBSplineFloatInterpolator_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiBSplineFloatInterpolator_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiBSplineCompFloatInterpolator")
	{
		Index = TargetObjectRegistry.NiBSplineCompFloatInterpolator_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiBSplineCompFloatInterpolator_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiBSplinePoint3Interpolator")
	{
		Index = TargetObjectRegistry.NiBSplinePoint3Interpolator_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiBSplinePoint3Interpolator_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiBSplineCompPoint3Interpolator")
	{
		Index = TargetObjectRegistry.NiBSplineCompPoint3Interpolator_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiBSplineCompPoint3Interpolator_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiBSplineTransformInterpolator")
	{
		Index = TargetObjectRegistry.NiBSplineTransformInterpolator_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiBSplineTransformInterpolator_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiBSplineCompTransformInterpolator")
	{
		Index = TargetObjectRegistry.NiBSplineCompTransformInterpolator_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiBSplineCompTransformInterpolator_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "BSRotAccumTransfInterpolator")
	{
		Index = TargetObjectRegistry.BSRotAccumTransfInterpolator_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.BSRotAccumTransfInterpolator_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiBSplineData")
	{
		Index = TargetObjectRegistry.NiBSplineData_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiBSplineData_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiCamera")
	{
		Index = TargetObjectRegistry.NiCamera_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiCamera_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiColorData")
	{
		Index = TargetObjectRegistry.NiColorData_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiColorData_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiColorExtraData")
	{
		Index = TargetObjectRegistry.NiColorExtraData_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiColorExtraData_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiControllerManager")
	{
		Index = TargetObjectRegistry.NiControllerManager_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiControllerManager_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiSequence")
	{
		Index = TargetObjectRegistry.NiSequence_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiSequence_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiControllerSequence")
	{
		Index = TargetObjectRegistry.NiControllerSequence_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiControllerSequence_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiAVObjectPalette")
	{
		Index = TargetObjectRegistry.NiAVObjectPalette_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiAVObjectPalette_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiDefaultAVObjectPalette")
	{
		Index = TargetObjectRegistry.NiDefaultAVObjectPalette_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiDefaultAVObjectPalette_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiDirectionalLight")
	{
		Index = TargetObjectRegistry.NiDirectionalLight_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiDirectionalLight_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiDitherProperty")
	{
		Index = TargetObjectRegistry.NiDitherProperty_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiDitherProperty_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiRollController")
	{
		Index = TargetObjectRegistry.NiRollController_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiRollController_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiFloatData")
	{
		Index = TargetObjectRegistry.NiFloatData_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiFloatData_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiFloatExtraData")
	{
		Index = TargetObjectRegistry.NiFloatExtraData_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiFloatExtraData_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiFloatsExtraData")
	{
		Index = TargetObjectRegistry.NiFloatsExtraData_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiFloatsExtraData_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiFogProperty")
	{
		Index = TargetObjectRegistry.NiFogProperty_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiFogProperty_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiGravity")
	{
		Index = TargetObjectRegistry.NiGravity_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiGravity_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiIntegerExtraData")
	{
		Index = TargetObjectRegistry.NiIntegerExtraData_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiIntegerExtraData_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "BSXFlags")
	{
		Index = TargetObjectRegistry.BSXFlags_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.BSXFlags_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiIntegersExtraData")
	{
		Index = TargetObjectRegistry.NiIntegersExtraData_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiIntegersExtraData_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "BSKeyframeController")
	{
		Index = TargetObjectRegistry.BSKeyframeController_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.BSKeyframeController_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiKeyframeData")
	{
		Index = TargetObjectRegistry.NiKeyframeData_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiKeyframeData_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiLookAtController")
	{
		Index = TargetObjectRegistry.NiLookAtController_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiLookAtController_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiLookAtInterpolator")
	{
		Index = TargetObjectRegistry.NiLookAtInterpolator_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiLookAtInterpolator_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiMaterialProperty")
	{
		Index = TargetObjectRegistry.NiMaterialProperty_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiMaterialProperty_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiMorphData")
	{
		Index = TargetObjectRegistry.NiMorphData_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiMorphData_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiNode")
	{
		Index = TargetObjectRegistry.NiNode_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiNode_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiBone")
	{
		Index = TargetObjectRegistry.NiBone_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiBone_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "AvoidNode")
	{
		Index = TargetObjectRegistry.AvoidNode_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.AvoidNode_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "FxWidget")
	{
		Index = TargetObjectRegistry.FxWidget_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.FxWidget_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "FxButton")
	{
		Index = TargetObjectRegistry.FxButton_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.FxButton_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "FxRadioButton")
	{
		Index = TargetObjectRegistry.FxRadioButton_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.FxRadioButton_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiBillboardNode")
	{
		Index = TargetObjectRegistry.NiBillboardNode_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiBillboardNode_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiBSAnimationNode")
	{
		Index = TargetObjectRegistry.NiBSAnimationNode_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiBSAnimationNode_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiBSParticleNode")
	{
		Index = TargetObjectRegistry.NiBSParticleNode_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiBSParticleNode_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiSwitchNode")
	{
		Index = TargetObjectRegistry.NiSwitchNode_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiSwitchNode_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiLODNode")
	{
		Index = TargetObjectRegistry.NiLODNode_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiLODNode_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPalette")
	{
		Index = TargetObjectRegistry.NiPalette_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiPalette_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiParticleBomb")
	{
		Index = TargetObjectRegistry.NiParticleBomb_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiParticleBomb_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiParticleColorModifier")
	{
		Index = TargetObjectRegistry.NiParticleColorModifier_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiParticleColorModifier_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiParticleGrowFade")
	{
		Index = TargetObjectRegistry.NiParticleGrowFade_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiParticleGrowFade_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiParticleMeshModifier")
	{
		Index = TargetObjectRegistry.NiParticleMeshModifier_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiParticleMeshModifier_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiParticleRotation")
	{
		Index = TargetObjectRegistry.NiParticleRotation_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiParticleRotation_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiParticles")
	{
		Index = TargetObjectRegistry.NiParticles_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiParticles_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiAutoNormalParticles")
	{
		Index = TargetObjectRegistry.NiAutoNormalParticles_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiAutoNormalParticles_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiParticleMeshes")
	{
		Index = TargetObjectRegistry.NiParticleMeshes_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiParticleMeshes_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiParticleMeshesData")
	{
		Index = TargetObjectRegistry.NiParticleMeshesData_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiParticleMeshesData_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiParticleSystem")
	{
		Index = TargetObjectRegistry.NiParticleSystem_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiParticleSystem_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiMeshParticleSystem")
	{
		Index = TargetObjectRegistry.NiMeshParticleSystem_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiMeshParticleSystem_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiParticleSystemController")
	{
		Index = TargetObjectRegistry.NiParticleSystemController_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiParticleSystemController_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiBSPArrayController")
	{
		Index = TargetObjectRegistry.NiBSPArrayController_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiBSPArrayController_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPathController")
	{
		Index = TargetObjectRegistry.NiPathController_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiPathController_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "ATextureRenderData")
	{
		Index = TargetObjectRegistry.ATextureRenderData_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.ATextureRenderData_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPersistentSrcTextureRendererData")
	{
		Index = TargetObjectRegistry.NiPersistentSrcTextureRendererData_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiPersistentSrcTextureRendererData_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPixelData")
	{
		Index = TargetObjectRegistry.NiPixelData_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiPixelData_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPlanarCollider")
	{
		Index = TargetObjectRegistry.NiPlanarCollider_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiPlanarCollider_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPointLight")
	{
		Index = TargetObjectRegistry.NiPointLight_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiPointLight_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPosData")
	{
		Index = TargetObjectRegistry.NiPosData_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiPosData_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPSysAgeDeathModifier")
	{
		Index = TargetObjectRegistry.NiPSysAgeDeathModifier_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiPSysAgeDeathModifier_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPSysBombModifier")
	{
		Index = TargetObjectRegistry.NiPSysBombModifier_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiPSysBombModifier_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPSysBoundUpdateModifier")
	{
		Index = TargetObjectRegistry.NiPSysBoundUpdateModifier_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiPSysBoundUpdateModifier_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPSysBoxEmitter")
	{
		Index = TargetObjectRegistry.NiPSysBoxEmitter_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiPSysBoxEmitter_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPSysColliderManager")
	{
		Index = TargetObjectRegistry.NiPSysColliderManager_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiPSysColliderManager_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPSysColorModifier")
	{
		Index = TargetObjectRegistry.NiPSysColorModifier_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiPSysColorModifier_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPSysCylinderEmitter")
	{
		Index = TargetObjectRegistry.NiPSysCylinderEmitter_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiPSysCylinderEmitter_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPSysDragModifier")
	{
		Index = TargetObjectRegistry.NiPSysDragModifier_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiPSysDragModifier_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPSysEmitterCtlrData")
	{
		Index = TargetObjectRegistry.NiPSysEmitterCtlrData_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiPSysEmitterCtlrData_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPSysGravityModifier")
	{
		Index = TargetObjectRegistry.NiPSysGravityModifier_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiPSysGravityModifier_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPSysGrowFadeModifier")
	{
		Index = TargetObjectRegistry.NiPSysGrowFadeModifier_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiPSysGrowFadeModifier_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPSysMeshEmitter")
	{
		Index = TargetObjectRegistry.NiPSysMeshEmitter_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiPSysMeshEmitter_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPSysMeshUpdateModifier")
	{
		Index = TargetObjectRegistry.NiPSysMeshUpdateModifier_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiPSysMeshUpdateModifier_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "BSPSysInheritVelocityModifier")
	{
		Index = TargetObjectRegistry.BSPSysInheritVelocityModifier_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.BSPSysInheritVelocityModifier_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "BSPSysHavokUpdateModifier")
	{
		Index = TargetObjectRegistry.BSPSysHavokUpdateModifier_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.BSPSysHavokUpdateModifier_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "BSPSysRecycleBoundModifier")
	{
		Index = TargetObjectRegistry.BSPSysRecycleBoundModifier_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.BSPSysRecycleBoundModifier_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "BSPSysSubTexModifier")
	{
		Index = TargetObjectRegistry.BSPSysSubTexModifier_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.BSPSysSubTexModifier_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPSysPlanarCollider")
	{
		Index = TargetObjectRegistry.NiPSysPlanarCollider_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiPSysPlanarCollider_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPSysSphericalCollider")
	{
		Index = TargetObjectRegistry.NiPSysSphericalCollider_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiPSysSphericalCollider_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPSysPositionModifier")
	{
		Index = TargetObjectRegistry.NiPSysPositionModifier_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiPSysPositionModifier_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPSysResetOnLoopCtlr")
	{
		Index = TargetObjectRegistry.NiPSysResetOnLoopCtlr_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiPSysResetOnLoopCtlr_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPSysRotationModifier")
	{
		Index = TargetObjectRegistry.NiPSysRotationModifier_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiPSysRotationModifier_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPSysSpawnModifier")
	{
		Index = TargetObjectRegistry.NiPSysSpawnModifier_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiPSysSpawnModifier_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPSysSphereEmitter")
	{
		Index = TargetObjectRegistry.NiPSysSphereEmitter_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiPSysSphereEmitter_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPSysUpdateCtlr")
	{
		Index = TargetObjectRegistry.NiPSysUpdateCtlr_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiPSysUpdateCtlr_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPSysFieldModifier")
	{
		Index = TargetObjectRegistry.NiPSysFieldModifier_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiPSysFieldModifier_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPSysVortexFieldModifier")
	{
		Index = TargetObjectRegistry.NiPSysVortexFieldModifier_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiPSysVortexFieldModifier_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPSysGravityFieldModifier")
	{
		Index = TargetObjectRegistry.NiPSysGravityFieldModifier_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiPSysGravityFieldModifier_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPSysDragFieldModifier")
	{
		Index = TargetObjectRegistry.NiPSysDragFieldModifier_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiPSysDragFieldModifier_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPSysTurbulenceFieldModifier")
	{
		Index = TargetObjectRegistry.NiPSysTurbulenceFieldModifier_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiPSysTurbulenceFieldModifier_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "BSPSysLODModifier")
	{
		Index = TargetObjectRegistry.BSPSysLODModifier_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.BSPSysLODModifier_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "BSPSysScaleModifier")
	{
		Index = TargetObjectRegistry.BSPSysScaleModifier_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.BSPSysScaleModifier_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPSysFieldMagnitudeCtlr")
	{
		Index = TargetObjectRegistry.NiPSysFieldMagnitudeCtlr_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiPSysFieldMagnitudeCtlr_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPSysFieldAttenuationCtlr")
	{
		Index = TargetObjectRegistry.NiPSysFieldAttenuationCtlr_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiPSysFieldAttenuationCtlr_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPSysFieldMaxDistanceCtlr")
	{
		Index = TargetObjectRegistry.NiPSysFieldMaxDistanceCtlr_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiPSysFieldMaxDistanceCtlr_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPSysAirFieldAirFrictionCtlr")
	{
		Index = TargetObjectRegistry.NiPSysAirFieldAirFrictionCtlr_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiPSysAirFieldAirFrictionCtlr_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPSysAirFieldInheritVelocityCtlr")
	{
		Index = TargetObjectRegistry.NiPSysAirFieldInheritVelocityCtlr_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiPSysAirFieldInheritVelocityCtlr_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPSysAirFieldSpreadCtlr")
	{
		Index = TargetObjectRegistry.NiPSysAirFieldSpreadCtlr_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiPSysAirFieldSpreadCtlr_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPSysInitialRotSpeedCtlr")
	{
		Index = TargetObjectRegistry.NiPSysInitialRotSpeedCtlr_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiPSysInitialRotSpeedCtlr_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPSysInitialRotSpeedVarCtlr")
	{
		Index = TargetObjectRegistry.NiPSysInitialRotSpeedVarCtlr_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiPSysInitialRotSpeedVarCtlr_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPSysInitialRotAngleCtlr")
	{
		Index = TargetObjectRegistry.NiPSysInitialRotAngleCtlr_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiPSysInitialRotAngleCtlr_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPSysInitialRotAngleVarCtlr")
	{
		Index = TargetObjectRegistry.NiPSysInitialRotAngleVarCtlr_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiPSysInitialRotAngleVarCtlr_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPSysEmitterPlanarAngleCtlr")
	{
		Index = TargetObjectRegistry.NiPSysEmitterPlanarAngleCtlr_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiPSysEmitterPlanarAngleCtlr_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPSysEmitterPlanarAngleVarCtlr")
	{
		Index = TargetObjectRegistry.NiPSysEmitterPlanarAngleVarCtlr_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiPSysEmitterPlanarAngleVarCtlr_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPSysAirFieldModifier")
	{
		Index = TargetObjectRegistry.NiPSysAirFieldModifier_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiPSysAirFieldModifier_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPSysTrailEmitter")
	{
		Index = TargetObjectRegistry.NiPSysTrailEmitter_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiPSysTrailEmitter_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiLightIntensityController")
	{
		Index = TargetObjectRegistry.NiLightIntensityController_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiLightIntensityController_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPSysRadialFieldModifier")
	{
		Index = TargetObjectRegistry.NiPSysRadialFieldModifier_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiPSysRadialFieldModifier_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiLODData")
	{
		Index = TargetObjectRegistry.NiLODData_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiLODData_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiRangeLODData")
	{
		Index = TargetObjectRegistry.NiRangeLODData_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiRangeLODData_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiScreenLODData")
	{
		Index = TargetObjectRegistry.NiScreenLODData_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiScreenLODData_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiRotatingParticles")
	{
		Index = TargetObjectRegistry.NiRotatingParticles_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiRotatingParticles_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiSequenceStreamHelper")
	{
		Index = TargetObjectRegistry.NiSequenceStreamHelper_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiSequenceStreamHelper_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiShadeProperty")
	{
		Index = TargetObjectRegistry.NiShadeProperty_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiShadeProperty_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiSkinData")
	{
		Index = TargetObjectRegistry.NiSkinData_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiSkinData_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiSkinInstance")
	{
		Index = TargetObjectRegistry.NiSkinInstance_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiSkinInstance_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiTriShapeSkinController")
	{
		Index = TargetObjectRegistry.NiTriShapeSkinController_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiTriShapeSkinController_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiClodSkinInstance")
	{
		Index = TargetObjectRegistry.NiClodSkinInstance_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiClodSkinInstance_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiSkinPartition")
	{
		Index = TargetObjectRegistry.NiSkinPartition_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiSkinPartition_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiTexture")
	{
		Index = TargetObjectRegistry.NiTexture_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiTexture_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiSourceTexture")
	{
		Index = TargetObjectRegistry.NiSourceTexture_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiSourceTexture_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiSpecularProperty")
	{
		Index = TargetObjectRegistry.NiSpecularProperty_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiSpecularProperty_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiSphericalCollider")
	{
		Index = TargetObjectRegistry.NiSphericalCollider_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiSphericalCollider_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiSpotLight")
	{
		Index = TargetObjectRegistry.NiSpotLight_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiSpotLight_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiStencilProperty")
	{
		Index = TargetObjectRegistry.NiStencilProperty_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiStencilProperty_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiStringExtraData")
	{
		Index = TargetObjectRegistry.NiStringExtraData_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiStringExtraData_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiStringPalette")
	{
		Index = TargetObjectRegistry.NiStringPalette_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiStringPalette_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiStringsExtraData")
	{
		Index = TargetObjectRegistry.NiStringsExtraData_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiStringsExtraData_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiTextKeyExtraData")
	{
		Index = TargetObjectRegistry.NiTextKeyExtraData_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiTextKeyExtraData_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiTextureEffect")
	{
		Index = TargetObjectRegistry.NiTextureEffect_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiTextureEffect_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiTextureModeProperty")
	{
		Index = TargetObjectRegistry.NiTextureModeProperty_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiTextureModeProperty_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiImage")
	{
		Index = TargetObjectRegistry.NiImage_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiImage_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiTextureProperty")
	{
		Index = TargetObjectRegistry.NiTextureProperty_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiTextureProperty_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiMultiTextureProperty")
	{
		Index = TargetObjectRegistry.NiMultiTextureProperty_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiMultiTextureProperty_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiTexturingProperty")
	{
		Index = TargetObjectRegistry.NiTexturingProperty_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiTexturingProperty_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiTransformData")
	{
		Index = TargetObjectRegistry.NiTransformData_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiTransformData_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiTriShape")
	{
		Index = TargetObjectRegistry.NiTriShape_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiTriShape_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiTriShapeData")
	{
		Index = TargetObjectRegistry.NiTriShapeData_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiTriShapeData_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiTriStrips")
	{
		Index = TargetObjectRegistry.NiTriStrips_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiTriStrips_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiTriStripsData")
	{
		Index = TargetObjectRegistry.NiTriStripsData_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiTriStripsData_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiEnvMappedTriShape")
	{
		Index = TargetObjectRegistry.NiEnvMappedTriShape_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiEnvMappedTriShape_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiEnvMappedTriShapeData")
	{
		Index = TargetObjectRegistry.NiEnvMappedTriShapeData_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiEnvMappedTriShapeData_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiBezierTriangle4")
	{
		Index = TargetObjectRegistry.NiBezierTriangle4_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiBezierTriangle4_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiBezierMesh")
	{
		Index = TargetObjectRegistry.NiBezierMesh_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiBezierMesh_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiClod")
	{
		Index = TargetObjectRegistry.NiClod_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiClod_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiClodData")
	{
		Index = TargetObjectRegistry.NiClodData_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiClodData_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiUVController")
	{
		Index = TargetObjectRegistry.NiUVController_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiUVController_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiUVData")
	{
		Index = TargetObjectRegistry.NiUVData_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiUVData_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiVectorExtraData")
	{
		Index = TargetObjectRegistry.NiVectorExtraData_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiVectorExtraData_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiVertexColorProperty")
	{
		Index = TargetObjectRegistry.NiVertexColorProperty_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiVertexColorProperty_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiVertWeightsExtraData")
	{
		Index = TargetObjectRegistry.NiVertWeightsExtraData_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiVertWeightsExtraData_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiVisData")
	{
		Index = TargetObjectRegistry.NiVisData_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiVisData_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiWireframeProperty")
	{
		Index = TargetObjectRegistry.NiWireframeProperty_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiWireframeProperty_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiZBufferProperty")
	{
		Index = TargetObjectRegistry.NiZBufferProperty_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiZBufferProperty_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "RootCollisionNode")
	{
		Index = TargetObjectRegistry.RootCollisionNode_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.RootCollisionNode_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiRawImageData")
	{
		Index = TargetObjectRegistry.NiRawImageData_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiRawImageData_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiSortAdjustNode")
	{
		Index = TargetObjectRegistry.NiSortAdjustNode_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiSortAdjustNode_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiSourceCubeMap")
	{
		Index = TargetObjectRegistry.NiSourceCubeMap_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiSourceCubeMap_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPhysXProp")
	{
		Index = TargetObjectRegistry.NiPhysXProp_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiPhysXProp_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPhysXPropDesc")
	{
		Index = TargetObjectRegistry.NiPhysXPropDesc_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiPhysXPropDesc_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPhysXActorDesc")
	{
		Index = TargetObjectRegistry.NiPhysXActorDesc_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiPhysXActorDesc_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPhysXBodyDesc")
	{
		Index = TargetObjectRegistry.NiPhysXBodyDesc_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiPhysXBodyDesc_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPhysXD6JointDesc")
	{
		Index = TargetObjectRegistry.NiPhysXD6JointDesc_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiPhysXD6JointDesc_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPhysXShapeDesc")
	{
		Index = TargetObjectRegistry.NiPhysXShapeDesc_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiPhysXShapeDesc_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPhysXMeshDesc")
	{
		Index = TargetObjectRegistry.NiPhysXMeshDesc_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiPhysXMeshDesc_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPhysXMaterialDesc")
	{
		Index = TargetObjectRegistry.NiPhysXMaterialDesc_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiPhysXMaterialDesc_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPhysXKinematicSrc")
	{
		Index = TargetObjectRegistry.NiPhysXKinematicSrc_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiPhysXKinematicSrc_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPhysXTransformDest")
	{
		Index = TargetObjectRegistry.NiPhysXTransformDest_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiPhysXTransformDest_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiArkAnimationExtraData")
	{
		Index = TargetObjectRegistry.NiArkAnimationExtraData_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiArkAnimationExtraData_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiArkImporterExtraData")
	{
		Index = TargetObjectRegistry.NiArkImporterExtraData_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiArkImporterExtraData_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiArkTextureExtraData")
	{
		Index = TargetObjectRegistry.NiArkTextureExtraData_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiArkTextureExtraData_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiArkViewportInfoExtraData")
	{
		Index = TargetObjectRegistry.NiArkViewportInfoExtraData_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiArkViewportInfoExtraData_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiArkShaderExtraData")
	{
		Index = TargetObjectRegistry.NiArkShaderExtraData_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiArkShaderExtraData_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiLines")
	{
		Index = TargetObjectRegistry.NiLines_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiLines_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiLinesData")
	{
		Index = TargetObjectRegistry.NiLinesData_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiLinesData_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiScreenElementsData")
	{
		Index = TargetObjectRegistry.NiScreenElementsData_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiScreenElementsData_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiScreenElements")
	{
		Index = TargetObjectRegistry.NiScreenElements_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiScreenElements_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiRoomGroup")
	{
		Index = TargetObjectRegistry.NiRoomGroup_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiRoomGroup_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiRoom")
	{
		Index = TargetObjectRegistry.NiRoom_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiRoom_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPortal")
	{
		Index = TargetObjectRegistry.NiPortal_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiPortal_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "BSFadeNode")
	{
		Index = TargetObjectRegistry.BSFadeNode_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.BSFadeNode_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "BSShaderProperty")
	{
		Index = TargetObjectRegistry.BSShaderProperty_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.BSShaderProperty_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "BSShaderLightingProperty")
	{
		Index = TargetObjectRegistry.BSShaderLightingProperty_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.BSShaderLightingProperty_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "BSShaderNoLightingProperty")
	{
		Index = TargetObjectRegistry.BSShaderNoLightingProperty_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.BSShaderNoLightingProperty_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "BSShaderPPLightingProperty")
	{
		Index = TargetObjectRegistry.BSShaderPPLightingProperty_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.BSShaderPPLightingProperty_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "BSEffectShaderPropertyFloatController")
	{
		Index = TargetObjectRegistry.BSEffectShaderPropertyFloatController_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.BSEffectShaderPropertyFloatController_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "BSEffectShaderPropertyColorController")
	{
		Index = TargetObjectRegistry.BSEffectShaderPropertyColorController_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.BSEffectShaderPropertyColorController_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "BSLightingShaderPropertyFloatController")
	{
		Index = TargetObjectRegistry.BSLightingShaderPropertyFloatController_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.BSLightingShaderPropertyFloatController_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "BSLightingShaderPropertyColorController")
	{
		Index = TargetObjectRegistry.BSLightingShaderPropertyColorController_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.BSLightingShaderPropertyColorController_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "BSNiAlphaPropertyTestRefController")
	{
		Index = TargetObjectRegistry.BSNiAlphaPropertyTestRefController_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.BSNiAlphaPropertyTestRefController_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "BSProceduralLightningController")
	{
		Index = TargetObjectRegistry.BSProceduralLightningController_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.BSProceduralLightningController_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "BSShaderTextureSet")
	{
		Index = TargetObjectRegistry.BSShaderTextureSet_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.BSShaderTextureSet_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "WaterShaderProperty")
	{
		Index = TargetObjectRegistry.WaterShaderProperty_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.WaterShaderProperty_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "SkyShaderProperty")
	{
		Index = TargetObjectRegistry.SkyShaderProperty_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.SkyShaderProperty_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "TileShaderProperty")
	{
		Index = TargetObjectRegistry.TileShaderProperty_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.TileShaderProperty_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "DistantLODShaderProperty")
	{
		Index = TargetObjectRegistry.DistantLODShaderProperty_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.DistantLODShaderProperty_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "BSDistantTreeShaderProperty")
	{
		Index = TargetObjectRegistry.BSDistantTreeShaderProperty_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.BSDistantTreeShaderProperty_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "TallGrassShaderProperty")
	{
		Index = TargetObjectRegistry.TallGrassShaderProperty_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.TallGrassShaderProperty_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "VolumetricFogShaderProperty")
	{
		Index = TargetObjectRegistry.VolumetricFogShaderProperty_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.VolumetricFogShaderProperty_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "HairShaderProperty")
	{
		Index = TargetObjectRegistry.HairShaderProperty_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.HairShaderProperty_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "Lighting30ShaderProperty")
	{
		Index = TargetObjectRegistry.Lighting30ShaderProperty_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.Lighting30ShaderProperty_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "BSLightingShaderProperty")
	{
		Index = TargetObjectRegistry.BSLightingShaderProperty_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.BSLightingShaderProperty_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "BSEffectShaderProperty")
	{
		Index = TargetObjectRegistry.BSEffectShaderProperty_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.BSEffectShaderProperty_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "BSWaterShaderProperty")
	{
		Index = TargetObjectRegistry.BSWaterShaderProperty_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.BSWaterShaderProperty_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "BSSkyShaderProperty")
	{
		Index = TargetObjectRegistry.BSSkyShaderProperty_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.BSSkyShaderProperty_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "BSDismemberSkinInstance")
	{
		Index = TargetObjectRegistry.BSDismemberSkinInstance_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.BSDismemberSkinInstance_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "BSDecalPlacementVectorExtraData")
	{
		Index = TargetObjectRegistry.BSDecalPlacementVectorExtraData_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.BSDecalPlacementVectorExtraData_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "BSPSysSimpleColorModifier")
	{
		Index = TargetObjectRegistry.BSPSysSimpleColorModifier_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.BSPSysSimpleColorModifier_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "BSValueNode")
	{
		Index = TargetObjectRegistry.BSValueNode_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.BSValueNode_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "BSStripParticleSystem")
	{
		Index = TargetObjectRegistry.BSStripParticleSystem_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.BSStripParticleSystem_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "BSStripPSysData")
	{
		Index = TargetObjectRegistry.BSStripPSysData_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.BSStripPSysData_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "BSPSysStripUpdateModifier")
	{
		Index = TargetObjectRegistry.BSPSysStripUpdateModifier_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.BSPSysStripUpdateModifier_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "BSMaterialEmittanceMultController")
	{
		Index = TargetObjectRegistry.BSMaterialEmittanceMultController_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.BSMaterialEmittanceMultController_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "BSMasterParticleSystem")
	{
		Index = TargetObjectRegistry.BSMasterParticleSystem_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.BSMasterParticleSystem_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "BSPSysMultiTargetEmitterCtlr")
	{
		Index = TargetObjectRegistry.BSPSysMultiTargetEmitterCtlr_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.BSPSysMultiTargetEmitterCtlr_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "BSRefractionStrengthController")
	{
		Index = TargetObjectRegistry.BSRefractionStrengthController_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.BSRefractionStrengthController_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "BSOrderedNode")
	{
		Index = TargetObjectRegistry.BSOrderedNode_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.BSOrderedNode_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "BSBlastNode")
	{
		Index = TargetObjectRegistry.BSBlastNode_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.BSBlastNode_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "BSDamageStage")
	{
		Index = TargetObjectRegistry.BSDamageStage_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.BSDamageStage_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "BSRefractionFirePeriodController")
	{
		Index = TargetObjectRegistry.BSRefractionFirePeriodController_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.BSRefractionFirePeriodController_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "bhkConvexListShape")
	{
		Index = TargetObjectRegistry.bhkConvexListShape_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.bhkConvexListShape_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "BSTreadTransfInterpolator")
	{
		Index = TargetObjectRegistry.BSTreadTransfInterpolator_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.BSTreadTransfInterpolator_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "BSAnimNotes")
	{
		Index = TargetObjectRegistry.BSAnimNotes_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.BSAnimNotes_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "bhkLiquidAction")
	{
		Index = TargetObjectRegistry.bhkLiquidAction_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.bhkLiquidAction_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "BSMultiBoundNode")
	{
		Index = TargetObjectRegistry.BSMultiBoundNode_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.BSMultiBoundNode_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "BSMultiBound")
	{
		Index = TargetObjectRegistry.BSMultiBound_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.BSMultiBound_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "BSMultiBoundData")
	{
		Index = TargetObjectRegistry.BSMultiBoundData_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.BSMultiBoundData_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "BSMultiBoundOBB")
	{
		Index = TargetObjectRegistry.BSMultiBoundOBB_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.BSMultiBoundOBB_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "BSMultiBoundSphere")
	{
		Index = TargetObjectRegistry.BSMultiBoundSphere_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.BSMultiBoundSphere_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "BSSegmentedTriShape")
	{
		Index = TargetObjectRegistry.BSSegmentedTriShape_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.BSSegmentedTriShape_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "BSMultiBoundAABB")
	{
		Index = TargetObjectRegistry.BSMultiBoundAABB_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.BSMultiBoundAABB_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiAdditionalGeometryData")
	{
		Index = TargetObjectRegistry.NiAdditionalGeometryData_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiAdditionalGeometryData_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "BSPackedAdditionalGeometryData")
	{
		Index = TargetObjectRegistry.BSPackedAdditionalGeometryData_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.BSPackedAdditionalGeometryData_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "BSWArray")
	{
		Index = TargetObjectRegistry.BSWArray_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.BSWArray_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "bhkAabbPhantom")
	{
		Index = TargetObjectRegistry.bhkAabbPhantom_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.bhkAabbPhantom_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "BSFrustumFOVController")
	{
		Index = TargetObjectRegistry.BSFrustumFOVController_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.BSFrustumFOVController_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "BSDebrisNode")
	{
		Index = TargetObjectRegistry.BSDebrisNode_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.BSDebrisNode_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "bhkBreakableConstraint")
	{
		Index = TargetObjectRegistry.bhkBreakableConstraint_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.bhkBreakableConstraint_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "bhkOrientHingedBodyAction")
	{
		Index = TargetObjectRegistry.bhkOrientHingedBodyAction_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.bhkOrientHingedBodyAction_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiDataStream")
	{
		Index = TargetObjectRegistry.NiDataStream_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiDataStream_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiRenderObject")
	{
		Index = TargetObjectRegistry.NiRenderObject_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiRenderObject_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiMeshModifier")
	{
		Index = TargetObjectRegistry.NiMeshModifier_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiMeshModifier_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiMesh")
	{
		Index = TargetObjectRegistry.NiMesh_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiMesh_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiMorphWeightsController")
	{
		Index = TargetObjectRegistry.NiMorphWeightsController_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiMorphWeightsController_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiMorphMeshModifier")
	{
		Index = TargetObjectRegistry.NiMorphMeshModifier_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiMorphMeshModifier_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiSkinningMeshModifier")
	{
		Index = TargetObjectRegistry.NiSkinningMeshModifier_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiSkinningMeshModifier_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiInstancingMeshModifier")
	{
		Index = TargetObjectRegistry.NiInstancingMeshModifier_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiInstancingMeshModifier_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiSkinningLODController")
	{
		Index = TargetObjectRegistry.NiSkinningLODController_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiSkinningLODController_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPSParticleSystem")
	{
		Index = TargetObjectRegistry.NiPSParticleSystem_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiPSParticleSystem_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPSMeshParticleSystem")
	{
		Index = TargetObjectRegistry.NiPSMeshParticleSystem_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiPSMeshParticleSystem_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPSEmitParticlesCtlr")
	{
		Index = TargetObjectRegistry.NiPSEmitParticlesCtlr_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiPSEmitParticlesCtlr_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPSForceActiveCtlr")
	{
		Index = TargetObjectRegistry.NiPSForceActiveCtlr_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiPSForceActiveCtlr_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPSSimulator")
	{
		Index = TargetObjectRegistry.NiPSSimulator_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiPSSimulator_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPSSimulatorStep")
	{
		Index = TargetObjectRegistry.NiPSSimulatorStep_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiPSSimulatorStep_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPSSimulatorGeneralStep")
	{
		Index = TargetObjectRegistry.NiPSSimulatorGeneralStep_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiPSSimulatorGeneralStep_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPSSimulatorForcesStep")
	{
		Index = TargetObjectRegistry.NiPSSimulatorForcesStep_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiPSSimulatorForcesStep_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPSSimulatorCollidersStep")
	{
		Index = TargetObjectRegistry.NiPSSimulatorCollidersStep_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiPSSimulatorCollidersStep_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPSSimulatorMeshAlignStep")
	{
		Index = TargetObjectRegistry.NiPSSimulatorMeshAlignStep_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiPSSimulatorMeshAlignStep_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPSSimulatorFinalStep")
	{
		Index = TargetObjectRegistry.NiPSSimulatorFinalStep_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiPSSimulatorFinalStep_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPSFacingQuadGenerator")
	{
		Index = TargetObjectRegistry.NiPSFacingQuadGenerator_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiPSFacingQuadGenerator_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiShadowGenerator")
	{
		Index = TargetObjectRegistry.NiShadowGenerator_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiShadowGenerator_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPSBoundUpdater")
	{
		Index = TargetObjectRegistry.NiPSBoundUpdater_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiPSBoundUpdater_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPSDragForce")
	{
		Index = TargetObjectRegistry.NiPSDragForce_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiPSDragForce_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPSGravityForce")
	{
		Index = TargetObjectRegistry.NiPSGravityForce_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiPSGravityForce_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPSBoxEmitter")
	{
		Index = TargetObjectRegistry.NiPSBoxEmitter_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiPSBoxEmitter_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPSMeshEmitter")
	{
		Index = TargetObjectRegistry.NiPSMeshEmitter_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiPSMeshEmitter_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPSGravityStrengthCtlr")
	{
		Index = TargetObjectRegistry.NiPSGravityStrengthCtlr_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiPSGravityStrengthCtlr_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPSPlanarCollider")
	{
		Index = TargetObjectRegistry.NiPSPlanarCollider_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiPSPlanarCollider_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPSEmitterSpeedCtlr")
	{
		Index = TargetObjectRegistry.NiPSEmitterSpeedCtlr_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiPSEmitterSpeedCtlr_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPSEmitterRadiusCtlr")
	{
		Index = TargetObjectRegistry.NiPSEmitterRadiusCtlr_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiPSEmitterRadiusCtlr_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPSResetOnLoopCtlr")
	{
		Index = TargetObjectRegistry.NiPSResetOnLoopCtlr_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiPSResetOnLoopCtlr_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPSSphereEmitter")
	{
		Index = TargetObjectRegistry.NiPSSphereEmitter_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiPSSphereEmitter_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPSCylinderEmitter")
	{
		Index = TargetObjectRegistry.NiPSCylinderEmitter_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiPSCylinderEmitter_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPSEmitterDeclinationCtlr")
	{
		Index = TargetObjectRegistry.NiPSEmitterDeclinationCtlr_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiPSEmitterDeclinationCtlr_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPSEmitterDeclinationVarCtlr")
	{
		Index = TargetObjectRegistry.NiPSEmitterDeclinationVarCtlr_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiPSEmitterDeclinationVarCtlr_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPSEmitterPlanarAngleCtlr")
	{
		Index = TargetObjectRegistry.NiPSEmitterPlanarAngleCtlr_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiPSEmitterPlanarAngleCtlr_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPSEmitterPlanarAngleVarCtlr")
	{
		Index = TargetObjectRegistry.NiPSEmitterPlanarAngleVarCtlr_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiPSEmitterPlanarAngleVarCtlr_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPSEmitterRotAngleCtlr")
	{
		Index = TargetObjectRegistry.NiPSEmitterRotAngleCtlr_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiPSEmitterRotAngleCtlr_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPSEmitterRotAngleVarCtlr")
	{
		Index = TargetObjectRegistry.NiPSEmitterRotAngleVarCtlr_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiPSEmitterRotAngleVarCtlr_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPSEmitterRotSpeedCtlr")
	{
		Index = TargetObjectRegistry.NiPSEmitterRotSpeedCtlr_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiPSEmitterRotSpeedCtlr_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPSEmitterRotSpeedVarCtlr")
	{
		Index = TargetObjectRegistry.NiPSEmitterRotSpeedVarCtlr_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiPSEmitterRotSpeedVarCtlr_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPSEmitterLifeSpanCtlr")
	{
		Index = TargetObjectRegistry.NiPSEmitterLifeSpanCtlr_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiPSEmitterLifeSpanCtlr_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPSBombForce")
	{
		Index = TargetObjectRegistry.NiPSBombForce_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiPSBombForce_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPSSphericalCollider")
	{
		Index = TargetObjectRegistry.NiPSSphericalCollider_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiPSSphericalCollider_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiPSSpawner")
	{
		Index = TargetObjectRegistry.NiPSSpawner_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiPSSpawner_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiSequenceData")
	{
		Index = TargetObjectRegistry.NiSequenceData_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiSequenceData_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiTransformEvaluator")
	{
		Index = TargetObjectRegistry.NiTransformEvaluator_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiTransformEvaluator_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiBSplineCompTransformEvaluator")
	{
		Index = TargetObjectRegistry.NiBSplineCompTransformEvaluator_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiBSplineCompTransformEvaluator_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiMeshHWInstance")
	{
		Index = TargetObjectRegistry.NiMeshHWInstance_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiMeshHWInstance_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiFurSpringController")
	{
		Index = TargetObjectRegistry.NiFurSpringController_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiFurSpringController_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "CStreamableAssetData")
	{
		Index = TargetObjectRegistry.CStreamableAssetData_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.CStreamableAssetData_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "bhkCompressedMeshShape")
	{
		Index = TargetObjectRegistry.bhkCompressedMeshShape_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.bhkCompressedMeshShape_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "bhkCompressedMeshShapeData")
	{
		Index = TargetObjectRegistry.bhkCompressedMeshShapeData_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.bhkCompressedMeshShapeData_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "BSInvMarker")
	{
		Index = TargetObjectRegistry.BSInvMarker_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.BSInvMarker_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "BSBoneLODExtraData")
	{
		Index = TargetObjectRegistry.BSBoneLODExtraData_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.BSBoneLODExtraData_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "BSBehaviorGraphExtraData")
	{
		Index = TargetObjectRegistry.BSBehaviorGraphExtraData_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.BSBehaviorGraphExtraData_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "BSLagBoneController")
	{
		Index = TargetObjectRegistry.BSLagBoneController_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.BSLagBoneController_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "BSLODTriShape")
	{
		Index = TargetObjectRegistry.BSLODTriShape_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.BSLODTriShape_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "BSFurnitureMarkerNode")
	{
		Index = TargetObjectRegistry.BSFurnitureMarkerNode_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.BSFurnitureMarkerNode_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "BSLeafAnimNode")
	{
		Index = TargetObjectRegistry.BSLeafAnimNode_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.BSLeafAnimNode_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "BSTreeNode")
	{
		Index = TargetObjectRegistry.BSTreeNode_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.BSTreeNode_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "NiLightRadiusController")
	{
		Index = TargetObjectRegistry.NiLightRadiusController_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.NiLightRadiusController_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "BSShape")
	{
		Index = TargetObjectRegistry.BSShape_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.BSShape_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "BSTriShape")
	{
		Index = TargetObjectRegistry.BSTriShape_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.BSTriShape_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "BSSubIndexTriShape")
	{
		Index = TargetObjectRegistry.BSSubIndexTriShape_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.BSSubIndexTriShape_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "BSMeshLODTriShape")
	{
		Index = TargetObjectRegistry.BSMeshLODTriShape_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.BSMeshLODTriShape_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "bhkNPCollisionObject")
	{
		Index = TargetObjectRegistry.bhkNPCollisionObject_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.bhkNPCollisionObject_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "BSExtraData")
	{
		Index = TargetObjectRegistry.BSExtraData_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.BSExtraData_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "bhkPhysicsSystem")
	{
		Index = TargetObjectRegistry.bhkPhysicsSystem_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.bhkPhysicsSystem_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "bhkRagdollSystem")
	{
		Index = TargetObjectRegistry.bhkRagdollSystem_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.bhkRagdollSystem_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "BSClothExtraData")
	{
		Index = TargetObjectRegistry.BSClothExtraData_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.BSClothExtraData_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "BSSkin__Instance")
	{
		Index = TargetObjectRegistry.BSSkin__Instance_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.BSSkin__Instance_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "BSSkin__BoneData")
	{
		Index = TargetObjectRegistry.BSSkin__BoneData_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.BSSkin__BoneData_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "BSPositionData")
	{
		Index = TargetObjectRegistry.BSPositionData_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.BSPositionData_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "BSConnectPoint__Parents")
	{
		Index = TargetObjectRegistry.BSConnectPoint__Parents_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.BSConnectPoint__Parents_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	if(TargetNodeType == "BSConnectPoint__Children")
	{
		Index = TargetObjectRegistry.BSConnectPoint__Children_Registry.AddDataCopy(TargetNode);
		TargetObjectRegistry.BSConnectPoint__Children_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;
	}
	FixCurrentNodeData();
	CurrentNode->IndexInRegistry = Index;
}
#endif

void NifNodeTreeData::NifNodeTree::ReadNifNodeTree(string const & file_name, Niflib::NifInfo * info /*= NULL*/)
{
	using namespace Niflib;
	if(Size() != 0)
	{
		ResetData();
	}
	//--Open File--//
	ifstream in(file_name.c_str(), ifstream::binary);
	ReadNifNodeTree(in, info);
	in.close();
}

void NifNodeTreeData::NifNodeTree::ReadNifNodeTree(istream & in, Niflib::NifInfo * info)
{
	using namespace Niflib;
	if(Size() != 0)
	{
		ResetData();
	}
	list<NiObjectRef> missing_link_stack;
	ReadNifNodeTree(in, missing_link_stack, info);
}

void NifNodeTreeData::NifNode::DestroyNodeData(NifTreeObjectRegistry* TargetObjectRegistry)
{
	if(NodeType == "NiObject")
	{
		TargetObjectRegistry->NiObject_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "Ni3dsAlphaAnimator")
	{
		TargetObjectRegistry->Ni3dsAlphaAnimator_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "Ni3dsAnimationNode")
	{
		TargetObjectRegistry->Ni3dsAnimationNode_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "Ni3dsColorAnimator")
	{
		TargetObjectRegistry->Ni3dsColorAnimator_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "Ni3dsMorphShape")
	{
		TargetObjectRegistry->Ni3dsMorphShape_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "Ni3dsParticleSystem")
	{
		TargetObjectRegistry->Ni3dsParticleSystem_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "Ni3dsPathController")
	{
		TargetObjectRegistry->Ni3dsPathController_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiParticleModifier")
	{
		TargetObjectRegistry->NiParticleModifier_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiPSysCollider")
	{
		TargetObjectRegistry->NiPSysCollider_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "bhkRefObject")
	{
		TargetObjectRegistry->bhkRefObject_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "bhkSerializable")
	{
		TargetObjectRegistry->bhkSerializable_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "bhkWorldObject")
	{
		TargetObjectRegistry->bhkWorldObject_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "bhkPhantom")
	{
		TargetObjectRegistry->bhkPhantom_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "bhkShapePhantom")
	{
		TargetObjectRegistry->bhkShapePhantom_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "bhkSimpleShapePhantom")
	{
		TargetObjectRegistry->bhkSimpleShapePhantom_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "bhkEntity")
	{
		TargetObjectRegistry->bhkEntity_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "bhkRigidBody")
	{
		TargetObjectRegistry->bhkRigidBody_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "bhkRigidBodyT")
	{
		TargetObjectRegistry->bhkRigidBodyT_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "bhkConstraint")
	{
		TargetObjectRegistry->bhkConstraint_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "bhkLimitedHingeConstraint")
	{
		TargetObjectRegistry->bhkLimitedHingeConstraint_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "bhkMalleableConstraint")
	{
		TargetObjectRegistry->bhkMalleableConstraint_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "bhkStiffSpringConstraint")
	{
		TargetObjectRegistry->bhkStiffSpringConstraint_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "bhkRagdollConstraint")
	{
		TargetObjectRegistry->bhkRagdollConstraint_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "bhkPrismaticConstraint")
	{
		TargetObjectRegistry->bhkPrismaticConstraint_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "bhkHingeConstraint")
	{
		TargetObjectRegistry->bhkHingeConstraint_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "bhkBallAndSocketConstraint")
	{
		TargetObjectRegistry->bhkBallAndSocketConstraint_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "bhkBallSocketConstraintChain")
	{
		TargetObjectRegistry->bhkBallSocketConstraintChain_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "bhkShape")
	{
		TargetObjectRegistry->bhkShape_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "bhkTransformShape")
	{
		TargetObjectRegistry->bhkTransformShape_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "bhkSphereRepShape")
	{
		TargetObjectRegistry->bhkSphereRepShape_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "bhkConvexShape")
	{
		TargetObjectRegistry->bhkConvexShape_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "bhkSphereShape")
	{
		TargetObjectRegistry->bhkSphereShape_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "bhkCapsuleShape")
	{
		TargetObjectRegistry->bhkCapsuleShape_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "bhkBoxShape")
	{
		TargetObjectRegistry->bhkBoxShape_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "bhkConvexVerticesShape")
	{
		TargetObjectRegistry->bhkConvexVerticesShape_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "bhkConvexTransformShape")
	{
		TargetObjectRegistry->bhkConvexTransformShape_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "bhkMultiSphereShape")
	{
		TargetObjectRegistry->bhkMultiSphereShape_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "bhkBvTreeShape")
	{
		TargetObjectRegistry->bhkBvTreeShape_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "bhkMoppBvTreeShape")
	{
		TargetObjectRegistry->bhkMoppBvTreeShape_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "bhkShapeCollection")
	{
		TargetObjectRegistry->bhkShapeCollection_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "bhkListShape")
	{
		TargetObjectRegistry->bhkListShape_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "bhkMeshShape")
	{
		TargetObjectRegistry->bhkMeshShape_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "bhkPackedNiTriStripsShape")
	{
		TargetObjectRegistry->bhkPackedNiTriStripsShape_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "bhkNiTriStripsShape")
	{
		TargetObjectRegistry->bhkNiTriStripsShape_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiExtraData")
	{
		TargetObjectRegistry->NiExtraData_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiInterpolator")
	{
		TargetObjectRegistry->NiInterpolator_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiKeyBasedInterpolator")
	{
		TargetObjectRegistry->NiKeyBasedInterpolator_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiFloatInterpolator")
	{
		TargetObjectRegistry->NiFloatInterpolator_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiTransformInterpolator")
	{
		TargetObjectRegistry->NiTransformInterpolator_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiPoint3Interpolator")
	{
		TargetObjectRegistry->NiPoint3Interpolator_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiPathInterpolator")
	{
		TargetObjectRegistry->NiPathInterpolator_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiBoolInterpolator")
	{
		TargetObjectRegistry->NiBoolInterpolator_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiBoolTimelineInterpolator")
	{
		TargetObjectRegistry->NiBoolTimelineInterpolator_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiBlendInterpolator")
	{
		TargetObjectRegistry->NiBlendInterpolator_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiBSplineInterpolator")
	{
		TargetObjectRegistry->NiBSplineInterpolator_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiObjectNET")
	{
		TargetObjectRegistry->NiObjectNET_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiCollisionObject")
	{
		TargetObjectRegistry->NiCollisionObject_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiCollisionData")
	{
		TargetObjectRegistry->NiCollisionData_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "bhkNiCollisionObject")
	{
		TargetObjectRegistry->bhkNiCollisionObject_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "bhkCollisionObject")
	{
		TargetObjectRegistry->bhkCollisionObject_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "bhkBlendCollisionObject")
	{
		TargetObjectRegistry->bhkBlendCollisionObject_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "bhkPCollisionObject")
	{
		TargetObjectRegistry->bhkPCollisionObject_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "bhkSPCollisionObject")
	{
		TargetObjectRegistry->bhkSPCollisionObject_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiAVObject")
	{
		TargetObjectRegistry->NiAVObject_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiDynamicEffect")
	{
		TargetObjectRegistry->NiDynamicEffect_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiLight")
	{
		TargetObjectRegistry->NiLight_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiProperty")
	{
		TargetObjectRegistry->NiProperty_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiTransparentProperty")
	{
		TargetObjectRegistry->NiTransparentProperty_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiPSysModifier")
	{
		TargetObjectRegistry->NiPSysModifier_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiPSysEmitter")
	{
		TargetObjectRegistry->NiPSysEmitter_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiPSysVolumeEmitter")
	{
		TargetObjectRegistry->NiPSysVolumeEmitter_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiTimeController")
	{
		TargetObjectRegistry->NiTimeController_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiInterpController")
	{
		TargetObjectRegistry->NiInterpController_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiMultiTargetTransformController")
	{
		TargetObjectRegistry->NiMultiTargetTransformController_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiGeomMorpherController")
	{
		TargetObjectRegistry->NiGeomMorpherController_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiMorphController")
	{
		TargetObjectRegistry->NiMorphController_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiMorpherController")
	{
		TargetObjectRegistry->NiMorpherController_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiSingleInterpController")
	{
		TargetObjectRegistry->NiSingleInterpController_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiKeyframeController")
	{
		TargetObjectRegistry->NiKeyframeController_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiTransformController")
	{
		TargetObjectRegistry->NiTransformController_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiPSysModifierCtlr")
	{
		TargetObjectRegistry->NiPSysModifierCtlr_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiPSysEmitterCtlr")
	{
		TargetObjectRegistry->NiPSysEmitterCtlr_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiPSysModifierBoolCtlr")
	{
		TargetObjectRegistry->NiPSysModifierBoolCtlr_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiPSysModifierActiveCtlr")
	{
		TargetObjectRegistry->NiPSysModifierActiveCtlr_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiPSysModifierFloatCtlr")
	{
		TargetObjectRegistry->NiPSysModifierFloatCtlr_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiPSysEmitterDeclinationCtlr")
	{
		TargetObjectRegistry->NiPSysEmitterDeclinationCtlr_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiPSysEmitterDeclinationVarCtlr")
	{
		TargetObjectRegistry->NiPSysEmitterDeclinationVarCtlr_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiPSysEmitterInitialRadiusCtlr")
	{
		TargetObjectRegistry->NiPSysEmitterInitialRadiusCtlr_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiPSysEmitterLifeSpanCtlr")
	{
		TargetObjectRegistry->NiPSysEmitterLifeSpanCtlr_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiPSysEmitterSpeedCtlr")
	{
		TargetObjectRegistry->NiPSysEmitterSpeedCtlr_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiPSysGravityStrengthCtlr")
	{
		TargetObjectRegistry->NiPSysGravityStrengthCtlr_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiFloatInterpController")
	{
		TargetObjectRegistry->NiFloatInterpController_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiFlipController")
	{
		TargetObjectRegistry->NiFlipController_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiAlphaController")
	{
		TargetObjectRegistry->NiAlphaController_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiTextureTransformController")
	{
		TargetObjectRegistry->NiTextureTransformController_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiLightDimmerController")
	{
		TargetObjectRegistry->NiLightDimmerController_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiBoolInterpController")
	{
		TargetObjectRegistry->NiBoolInterpController_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiVisController")
	{
		TargetObjectRegistry->NiVisController_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiPoint3InterpController")
	{
		TargetObjectRegistry->NiPoint3InterpController_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiMaterialColorController")
	{
		TargetObjectRegistry->NiMaterialColorController_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiLightColorController")
	{
		TargetObjectRegistry->NiLightColorController_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiExtraDataController")
	{
		TargetObjectRegistry->NiExtraDataController_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiFloatExtraDataController")
	{
		TargetObjectRegistry->NiFloatExtraDataController_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiBoneLODController")
	{
		TargetObjectRegistry->NiBoneLODController_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiBSBoneLODController")
	{
		TargetObjectRegistry->NiBSBoneLODController_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiGeometry")
	{
		TargetObjectRegistry->NiGeometry_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiTriBasedGeom")
	{
		TargetObjectRegistry->NiTriBasedGeom_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiGeometryData")
	{
		TargetObjectRegistry->NiGeometryData_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "AbstractAdditionalGeometryData")
	{
		TargetObjectRegistry->AbstractAdditionalGeometryData_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiTriBasedGeomData")
	{
		TargetObjectRegistry->NiTriBasedGeomData_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "bhkBlendController")
	{
		TargetObjectRegistry->bhkBlendController_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "BSBound")
	{
		TargetObjectRegistry->BSBound_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "BSFurnitureMarker")
	{
		TargetObjectRegistry->BSFurnitureMarker_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "BSParentVelocityModifier")
	{
		TargetObjectRegistry->BSParentVelocityModifier_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "BSPSysArrayEmitter")
	{
		TargetObjectRegistry->BSPSysArrayEmitter_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "BSWindModifier")
	{
		TargetObjectRegistry->BSWindModifier_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "hkPackedNiTriStripsData")
	{
		TargetObjectRegistry->hkPackedNiTriStripsData_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiAlphaProperty")
	{
		TargetObjectRegistry->NiAlphaProperty_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiAmbientLight")
	{
		TargetObjectRegistry->NiAmbientLight_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiParticlesData")
	{
		TargetObjectRegistry->NiParticlesData_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiRotatingParticlesData")
	{
		TargetObjectRegistry->NiRotatingParticlesData_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiAutoNormalParticlesData")
	{
		TargetObjectRegistry->NiAutoNormalParticlesData_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiPSysData")
	{
		TargetObjectRegistry->NiPSysData_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiMeshPSysData")
	{
		TargetObjectRegistry->NiMeshPSysData_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiBinaryExtraData")
	{
		TargetObjectRegistry->NiBinaryExtraData_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiBinaryVoxelExtraData")
	{
		TargetObjectRegistry->NiBinaryVoxelExtraData_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiBinaryVoxelData")
	{
		TargetObjectRegistry->NiBinaryVoxelData_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiBlendBoolInterpolator")
	{
		TargetObjectRegistry->NiBlendBoolInterpolator_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiBlendFloatInterpolator")
	{
		TargetObjectRegistry->NiBlendFloatInterpolator_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiBlendPoint3Interpolator")
	{
		TargetObjectRegistry->NiBlendPoint3Interpolator_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiBlendTransformInterpolator")
	{
		TargetObjectRegistry->NiBlendTransformInterpolator_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiBoolData")
	{
		TargetObjectRegistry->NiBoolData_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiBooleanExtraData")
	{
		TargetObjectRegistry->NiBooleanExtraData_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiBSplineBasisData")
	{
		TargetObjectRegistry->NiBSplineBasisData_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiBSplineFloatInterpolator")
	{
		TargetObjectRegistry->NiBSplineFloatInterpolator_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiBSplineCompFloatInterpolator")
	{
		TargetObjectRegistry->NiBSplineCompFloatInterpolator_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiBSplinePoint3Interpolator")
	{
		TargetObjectRegistry->NiBSplinePoint3Interpolator_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiBSplineCompPoint3Interpolator")
	{
		TargetObjectRegistry->NiBSplineCompPoint3Interpolator_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiBSplineTransformInterpolator")
	{
		TargetObjectRegistry->NiBSplineTransformInterpolator_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiBSplineCompTransformInterpolator")
	{
		TargetObjectRegistry->NiBSplineCompTransformInterpolator_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "BSRotAccumTransfInterpolator")
	{
		TargetObjectRegistry->BSRotAccumTransfInterpolator_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiBSplineData")
	{
		TargetObjectRegistry->NiBSplineData_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiCamera")
	{
		TargetObjectRegistry->NiCamera_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiColorData")
	{
		TargetObjectRegistry->NiColorData_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiColorExtraData")
	{
		TargetObjectRegistry->NiColorExtraData_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiControllerManager")
	{
		TargetObjectRegistry->NiControllerManager_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiSequence")
	{
		TargetObjectRegistry->NiSequence_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiControllerSequence")
	{
		TargetObjectRegistry->NiControllerSequence_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiAVObjectPalette")
	{
		TargetObjectRegistry->NiAVObjectPalette_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiDefaultAVObjectPalette")
	{
		TargetObjectRegistry->NiDefaultAVObjectPalette_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiDirectionalLight")
	{
		TargetObjectRegistry->NiDirectionalLight_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiDitherProperty")
	{
		TargetObjectRegistry->NiDitherProperty_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiRollController")
	{
		TargetObjectRegistry->NiRollController_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiFloatData")
	{
		TargetObjectRegistry->NiFloatData_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiFloatExtraData")
	{
		TargetObjectRegistry->NiFloatExtraData_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiFloatsExtraData")
	{
		TargetObjectRegistry->NiFloatsExtraData_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiFogProperty")
	{
		TargetObjectRegistry->NiFogProperty_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiGravity")
	{
		TargetObjectRegistry->NiGravity_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiIntegerExtraData")
	{
		TargetObjectRegistry->NiIntegerExtraData_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "BSXFlags")
	{
		TargetObjectRegistry->BSXFlags_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiIntegersExtraData")
	{
		TargetObjectRegistry->NiIntegersExtraData_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "BSKeyframeController")
	{
		TargetObjectRegistry->BSKeyframeController_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiKeyframeData")
	{
		TargetObjectRegistry->NiKeyframeData_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiLookAtController")
	{
		TargetObjectRegistry->NiLookAtController_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiLookAtInterpolator")
	{
		TargetObjectRegistry->NiLookAtInterpolator_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiMaterialProperty")
	{
		TargetObjectRegistry->NiMaterialProperty_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiMorphData")
	{
		TargetObjectRegistry->NiMorphData_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiNode")
	{
		TargetObjectRegistry->NiNode_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiBone")
	{
		TargetObjectRegistry->NiBone_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "AvoidNode")
	{
		TargetObjectRegistry->AvoidNode_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "FxWidget")
	{
		TargetObjectRegistry->FxWidget_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "FxButton")
	{
		TargetObjectRegistry->FxButton_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "FxRadioButton")
	{
		TargetObjectRegistry->FxRadioButton_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiBillboardNode")
	{
		TargetObjectRegistry->NiBillboardNode_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiBSAnimationNode")
	{
		TargetObjectRegistry->NiBSAnimationNode_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiBSParticleNode")
	{
		TargetObjectRegistry->NiBSParticleNode_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiSwitchNode")
	{
		TargetObjectRegistry->NiSwitchNode_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiLODNode")
	{
		TargetObjectRegistry->NiLODNode_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiPalette")
	{
		TargetObjectRegistry->NiPalette_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiParticleBomb")
	{
		TargetObjectRegistry->NiParticleBomb_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiParticleColorModifier")
	{
		TargetObjectRegistry->NiParticleColorModifier_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiParticleGrowFade")
	{
		TargetObjectRegistry->NiParticleGrowFade_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiParticleMeshModifier")
	{
		TargetObjectRegistry->NiParticleMeshModifier_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiParticleRotation")
	{
		TargetObjectRegistry->NiParticleRotation_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiParticles")
	{
		TargetObjectRegistry->NiParticles_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiAutoNormalParticles")
	{
		TargetObjectRegistry->NiAutoNormalParticles_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiParticleMeshes")
	{
		TargetObjectRegistry->NiParticleMeshes_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiParticleMeshesData")
	{
		TargetObjectRegistry->NiParticleMeshesData_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiParticleSystem")
	{
		TargetObjectRegistry->NiParticleSystem_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiMeshParticleSystem")
	{
		TargetObjectRegistry->NiMeshParticleSystem_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiParticleSystemController")
	{
		TargetObjectRegistry->NiParticleSystemController_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiBSPArrayController")
	{
		TargetObjectRegistry->NiBSPArrayController_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiPathController")
	{
		TargetObjectRegistry->NiPathController_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "ATextureRenderData")
	{
		TargetObjectRegistry->ATextureRenderData_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiPersistentSrcTextureRendererData")
	{
		TargetObjectRegistry->NiPersistentSrcTextureRendererData_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiPixelData")
	{
		TargetObjectRegistry->NiPixelData_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiPlanarCollider")
	{
		TargetObjectRegistry->NiPlanarCollider_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiPointLight")
	{
		TargetObjectRegistry->NiPointLight_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiPosData")
	{
		TargetObjectRegistry->NiPosData_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiPSysAgeDeathModifier")
	{
		TargetObjectRegistry->NiPSysAgeDeathModifier_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiPSysBombModifier")
	{
		TargetObjectRegistry->NiPSysBombModifier_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiPSysBoundUpdateModifier")
	{
		TargetObjectRegistry->NiPSysBoundUpdateModifier_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiPSysBoxEmitter")
	{
		TargetObjectRegistry->NiPSysBoxEmitter_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiPSysColliderManager")
	{
		TargetObjectRegistry->NiPSysColliderManager_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiPSysColorModifier")
	{
		TargetObjectRegistry->NiPSysColorModifier_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiPSysCylinderEmitter")
	{
		TargetObjectRegistry->NiPSysCylinderEmitter_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiPSysDragModifier")
	{
		TargetObjectRegistry->NiPSysDragModifier_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiPSysEmitterCtlrData")
	{
		TargetObjectRegistry->NiPSysEmitterCtlrData_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiPSysGravityModifier")
	{
		TargetObjectRegistry->NiPSysGravityModifier_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiPSysGrowFadeModifier")
	{
		TargetObjectRegistry->NiPSysGrowFadeModifier_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiPSysMeshEmitter")
	{
		TargetObjectRegistry->NiPSysMeshEmitter_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiPSysMeshUpdateModifier")
	{
		TargetObjectRegistry->NiPSysMeshUpdateModifier_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "BSPSysInheritVelocityModifier")
	{
		TargetObjectRegistry->BSPSysInheritVelocityModifier_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "BSPSysHavokUpdateModifier")
	{
		TargetObjectRegistry->BSPSysHavokUpdateModifier_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "BSPSysRecycleBoundModifier")
	{
		TargetObjectRegistry->BSPSysRecycleBoundModifier_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "BSPSysSubTexModifier")
	{
		TargetObjectRegistry->BSPSysSubTexModifier_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiPSysPlanarCollider")
	{
		TargetObjectRegistry->NiPSysPlanarCollider_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiPSysSphericalCollider")
	{
		TargetObjectRegistry->NiPSysSphericalCollider_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiPSysPositionModifier")
	{
		TargetObjectRegistry->NiPSysPositionModifier_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiPSysResetOnLoopCtlr")
	{
		TargetObjectRegistry->NiPSysResetOnLoopCtlr_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiPSysRotationModifier")
	{
		TargetObjectRegistry->NiPSysRotationModifier_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiPSysSpawnModifier")
	{
		TargetObjectRegistry->NiPSysSpawnModifier_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiPSysSphereEmitter")
	{
		TargetObjectRegistry->NiPSysSphereEmitter_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiPSysUpdateCtlr")
	{
		TargetObjectRegistry->NiPSysUpdateCtlr_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiPSysFieldModifier")
	{
		TargetObjectRegistry->NiPSysFieldModifier_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiPSysVortexFieldModifier")
	{
		TargetObjectRegistry->NiPSysVortexFieldModifier_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiPSysGravityFieldModifier")
	{
		TargetObjectRegistry->NiPSysGravityFieldModifier_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiPSysDragFieldModifier")
	{
		TargetObjectRegistry->NiPSysDragFieldModifier_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiPSysTurbulenceFieldModifier")
	{
		TargetObjectRegistry->NiPSysTurbulenceFieldModifier_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "BSPSysLODModifier")
	{
		TargetObjectRegistry->BSPSysLODModifier_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "BSPSysScaleModifier")
	{
		TargetObjectRegistry->BSPSysScaleModifier_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiPSysFieldMagnitudeCtlr")
	{
		TargetObjectRegistry->NiPSysFieldMagnitudeCtlr_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiPSysFieldAttenuationCtlr")
	{
		TargetObjectRegistry->NiPSysFieldAttenuationCtlr_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiPSysFieldMaxDistanceCtlr")
	{
		TargetObjectRegistry->NiPSysFieldMaxDistanceCtlr_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiPSysAirFieldAirFrictionCtlr")
	{
		TargetObjectRegistry->NiPSysAirFieldAirFrictionCtlr_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiPSysAirFieldInheritVelocityCtlr")
	{
		TargetObjectRegistry->NiPSysAirFieldInheritVelocityCtlr_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiPSysAirFieldSpreadCtlr")
	{
		TargetObjectRegistry->NiPSysAirFieldSpreadCtlr_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiPSysInitialRotSpeedCtlr")
	{
		TargetObjectRegistry->NiPSysInitialRotSpeedCtlr_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiPSysInitialRotSpeedVarCtlr")
	{
		TargetObjectRegistry->NiPSysInitialRotSpeedVarCtlr_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiPSysInitialRotAngleCtlr")
	{
		TargetObjectRegistry->NiPSysInitialRotAngleCtlr_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiPSysInitialRotAngleVarCtlr")
	{
		TargetObjectRegistry->NiPSysInitialRotAngleVarCtlr_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiPSysEmitterPlanarAngleCtlr")
	{
		TargetObjectRegistry->NiPSysEmitterPlanarAngleCtlr_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiPSysEmitterPlanarAngleVarCtlr")
	{
		TargetObjectRegistry->NiPSysEmitterPlanarAngleVarCtlr_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiPSysAirFieldModifier")
	{
		TargetObjectRegistry->NiPSysAirFieldModifier_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiPSysTrailEmitter")
	{
		TargetObjectRegistry->NiPSysTrailEmitter_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiLightIntensityController")
	{
		TargetObjectRegistry->NiLightIntensityController_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiPSysRadialFieldModifier")
	{
		TargetObjectRegistry->NiPSysRadialFieldModifier_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiLODData")
	{
		TargetObjectRegistry->NiLODData_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiRangeLODData")
	{
		TargetObjectRegistry->NiRangeLODData_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiScreenLODData")
	{
		TargetObjectRegistry->NiScreenLODData_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiRotatingParticles")
	{
		TargetObjectRegistry->NiRotatingParticles_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiSequenceStreamHelper")
	{
		TargetObjectRegistry->NiSequenceStreamHelper_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiShadeProperty")
	{
		TargetObjectRegistry->NiShadeProperty_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiSkinData")
	{
		TargetObjectRegistry->NiSkinData_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiSkinInstance")
	{
		TargetObjectRegistry->NiSkinInstance_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiTriShapeSkinController")
	{
		TargetObjectRegistry->NiTriShapeSkinController_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiClodSkinInstance")
	{
		TargetObjectRegistry->NiClodSkinInstance_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiSkinPartition")
	{
		TargetObjectRegistry->NiSkinPartition_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiTexture")
	{
		TargetObjectRegistry->NiTexture_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiSourceTexture")
	{
		TargetObjectRegistry->NiSourceTexture_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiSpecularProperty")
	{
		TargetObjectRegistry->NiSpecularProperty_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiSphericalCollider")
	{
		TargetObjectRegistry->NiSphericalCollider_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiSpotLight")
	{
		TargetObjectRegistry->NiSpotLight_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiStencilProperty")
	{
		TargetObjectRegistry->NiStencilProperty_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiStringExtraData")
	{
		TargetObjectRegistry->NiStringExtraData_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiStringPalette")
	{
		TargetObjectRegistry->NiStringPalette_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiStringsExtraData")
	{
		TargetObjectRegistry->NiStringsExtraData_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiTextKeyExtraData")
	{
		TargetObjectRegistry->NiTextKeyExtraData_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiTextureEffect")
	{
		TargetObjectRegistry->NiTextureEffect_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiTextureModeProperty")
	{
		TargetObjectRegistry->NiTextureModeProperty_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiImage")
	{
		TargetObjectRegistry->NiImage_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiTextureProperty")
	{
		TargetObjectRegistry->NiTextureProperty_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiMultiTextureProperty")
	{
		TargetObjectRegistry->NiMultiTextureProperty_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiTexturingProperty")
	{
		TargetObjectRegistry->NiTexturingProperty_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiTransformData")
	{
		TargetObjectRegistry->NiTransformData_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiTriShape")
	{
		TargetObjectRegistry->NiTriShape_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiTriShapeData")
	{
		TargetObjectRegistry->NiTriShapeData_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiTriStrips")
	{
		TargetObjectRegistry->NiTriStrips_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiTriStripsData")
	{
		TargetObjectRegistry->NiTriStripsData_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiEnvMappedTriShape")
	{
		TargetObjectRegistry->NiEnvMappedTriShape_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiEnvMappedTriShapeData")
	{
		TargetObjectRegistry->NiEnvMappedTriShapeData_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiBezierTriangle4")
	{
		TargetObjectRegistry->NiBezierTriangle4_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiBezierMesh")
	{
		TargetObjectRegistry->NiBezierMesh_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiClod")
	{
		TargetObjectRegistry->NiClod_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiClodData")
	{
		TargetObjectRegistry->NiClodData_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiUVController")
	{
		TargetObjectRegistry->NiUVController_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiUVData")
	{
		TargetObjectRegistry->NiUVData_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiVectorExtraData")
	{
		TargetObjectRegistry->NiVectorExtraData_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiVertexColorProperty")
	{
		TargetObjectRegistry->NiVertexColorProperty_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiVertWeightsExtraData")
	{
		TargetObjectRegistry->NiVertWeightsExtraData_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiVisData")
	{
		TargetObjectRegistry->NiVisData_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiWireframeProperty")
	{
		TargetObjectRegistry->NiWireframeProperty_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiZBufferProperty")
	{
		TargetObjectRegistry->NiZBufferProperty_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "RootCollisionNode")
	{
		TargetObjectRegistry->RootCollisionNode_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiRawImageData")
	{
		TargetObjectRegistry->NiRawImageData_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiSortAdjustNode")
	{
		TargetObjectRegistry->NiSortAdjustNode_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiSourceCubeMap")
	{
		TargetObjectRegistry->NiSourceCubeMap_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiPhysXProp")
	{
		TargetObjectRegistry->NiPhysXProp_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiPhysXPropDesc")
	{
		TargetObjectRegistry->NiPhysXPropDesc_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiPhysXActorDesc")
	{
		TargetObjectRegistry->NiPhysXActorDesc_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiPhysXBodyDesc")
	{
		TargetObjectRegistry->NiPhysXBodyDesc_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiPhysXD6JointDesc")
	{
		TargetObjectRegistry->NiPhysXD6JointDesc_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiPhysXShapeDesc")
	{
		TargetObjectRegistry->NiPhysXShapeDesc_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiPhysXMeshDesc")
	{
		TargetObjectRegistry->NiPhysXMeshDesc_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiPhysXMaterialDesc")
	{
		TargetObjectRegistry->NiPhysXMaterialDesc_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiPhysXKinematicSrc")
	{
		TargetObjectRegistry->NiPhysXKinematicSrc_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiPhysXTransformDest")
	{
		TargetObjectRegistry->NiPhysXTransformDest_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiArkAnimationExtraData")
	{
		TargetObjectRegistry->NiArkAnimationExtraData_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiArkImporterExtraData")
	{
		TargetObjectRegistry->NiArkImporterExtraData_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiArkTextureExtraData")
	{
		TargetObjectRegistry->NiArkTextureExtraData_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiArkViewportInfoExtraData")
	{
		TargetObjectRegistry->NiArkViewportInfoExtraData_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiArkShaderExtraData")
	{
		TargetObjectRegistry->NiArkShaderExtraData_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiLines")
	{
		TargetObjectRegistry->NiLines_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiLinesData")
	{
		TargetObjectRegistry->NiLinesData_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiScreenElementsData")
	{
		TargetObjectRegistry->NiScreenElementsData_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiScreenElements")
	{
		TargetObjectRegistry->NiScreenElements_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiRoomGroup")
	{
		TargetObjectRegistry->NiRoomGroup_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiRoom")
	{
		TargetObjectRegistry->NiRoom_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiPortal")
	{
		TargetObjectRegistry->NiPortal_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "BSFadeNode")
	{
		TargetObjectRegistry->BSFadeNode_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "BSShaderProperty")
	{
		TargetObjectRegistry->BSShaderProperty_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "BSShaderLightingProperty")
	{
		TargetObjectRegistry->BSShaderLightingProperty_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "BSShaderNoLightingProperty")
	{
		TargetObjectRegistry->BSShaderNoLightingProperty_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "BSShaderPPLightingProperty")
	{
		TargetObjectRegistry->BSShaderPPLightingProperty_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "BSEffectShaderPropertyFloatController")
	{
		TargetObjectRegistry->BSEffectShaderPropertyFloatController_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "BSEffectShaderPropertyColorController")
	{
		TargetObjectRegistry->BSEffectShaderPropertyColorController_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "BSLightingShaderPropertyFloatController")
	{
		TargetObjectRegistry->BSLightingShaderPropertyFloatController_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "BSLightingShaderPropertyColorController")
	{
		TargetObjectRegistry->BSLightingShaderPropertyColorController_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "BSNiAlphaPropertyTestRefController")
	{
		TargetObjectRegistry->BSNiAlphaPropertyTestRefController_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "BSProceduralLightningController")
	{
		TargetObjectRegistry->BSProceduralLightningController_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "BSShaderTextureSet")
	{
		TargetObjectRegistry->BSShaderTextureSet_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "WaterShaderProperty")
	{
		TargetObjectRegistry->WaterShaderProperty_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "SkyShaderProperty")
	{
		TargetObjectRegistry->SkyShaderProperty_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "TileShaderProperty")
	{
		TargetObjectRegistry->TileShaderProperty_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "DistantLODShaderProperty")
	{
		TargetObjectRegistry->DistantLODShaderProperty_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "BSDistantTreeShaderProperty")
	{
		TargetObjectRegistry->BSDistantTreeShaderProperty_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "TallGrassShaderProperty")
	{
		TargetObjectRegistry->TallGrassShaderProperty_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "VolumetricFogShaderProperty")
	{
		TargetObjectRegistry->VolumetricFogShaderProperty_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "HairShaderProperty")
	{
		TargetObjectRegistry->HairShaderProperty_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "Lighting30ShaderProperty")
	{
		TargetObjectRegistry->Lighting30ShaderProperty_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "BSLightingShaderProperty")
	{
		TargetObjectRegistry->BSLightingShaderProperty_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "BSEffectShaderProperty")
	{
		TargetObjectRegistry->BSEffectShaderProperty_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "BSWaterShaderProperty")
	{
		TargetObjectRegistry->BSWaterShaderProperty_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "BSSkyShaderProperty")
	{
		TargetObjectRegistry->BSSkyShaderProperty_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "BSDismemberSkinInstance")
	{
		TargetObjectRegistry->BSDismemberSkinInstance_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "BSDecalPlacementVectorExtraData")
	{
		TargetObjectRegistry->BSDecalPlacementVectorExtraData_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "BSPSysSimpleColorModifier")
	{
		TargetObjectRegistry->BSPSysSimpleColorModifier_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "BSValueNode")
	{
		TargetObjectRegistry->BSValueNode_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "BSStripParticleSystem")
	{
		TargetObjectRegistry->BSStripParticleSystem_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "BSStripPSysData")
	{
		TargetObjectRegistry->BSStripPSysData_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "BSPSysStripUpdateModifier")
	{
		TargetObjectRegistry->BSPSysStripUpdateModifier_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "BSMaterialEmittanceMultController")
	{
		TargetObjectRegistry->BSMaterialEmittanceMultController_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "BSMasterParticleSystem")
	{
		TargetObjectRegistry->BSMasterParticleSystem_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "BSPSysMultiTargetEmitterCtlr")
	{
		TargetObjectRegistry->BSPSysMultiTargetEmitterCtlr_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "BSRefractionStrengthController")
	{
		TargetObjectRegistry->BSRefractionStrengthController_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "BSOrderedNode")
	{
		TargetObjectRegistry->BSOrderedNode_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "BSBlastNode")
	{
		TargetObjectRegistry->BSBlastNode_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "BSDamageStage")
	{
		TargetObjectRegistry->BSDamageStage_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "BSRefractionFirePeriodController")
	{
		TargetObjectRegistry->BSRefractionFirePeriodController_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "bhkConvexListShape")
	{
		TargetObjectRegistry->bhkConvexListShape_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "BSTreadTransfInterpolator")
	{
		TargetObjectRegistry->BSTreadTransfInterpolator_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "BSAnimNotes")
	{
		TargetObjectRegistry->BSAnimNotes_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "bhkLiquidAction")
	{
		TargetObjectRegistry->bhkLiquidAction_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "BSMultiBoundNode")
	{
		TargetObjectRegistry->BSMultiBoundNode_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "BSMultiBound")
	{
		TargetObjectRegistry->BSMultiBound_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "BSMultiBoundData")
	{
		TargetObjectRegistry->BSMultiBoundData_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "BSMultiBoundOBB")
	{
		TargetObjectRegistry->BSMultiBoundOBB_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "BSMultiBoundSphere")
	{
		TargetObjectRegistry->BSMultiBoundSphere_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "BSSegmentedTriShape")
	{
		TargetObjectRegistry->BSSegmentedTriShape_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "BSMultiBoundAABB")
	{
		TargetObjectRegistry->BSMultiBoundAABB_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiAdditionalGeometryData")
	{
		TargetObjectRegistry->NiAdditionalGeometryData_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "BSPackedAdditionalGeometryData")
	{
		TargetObjectRegistry->BSPackedAdditionalGeometryData_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "BSWArray")
	{
		TargetObjectRegistry->BSWArray_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "bhkAabbPhantom")
	{
		TargetObjectRegistry->bhkAabbPhantom_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "BSFrustumFOVController")
	{
		TargetObjectRegistry->BSFrustumFOVController_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "BSDebrisNode")
	{
		TargetObjectRegistry->BSDebrisNode_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "bhkBreakableConstraint")
	{
		TargetObjectRegistry->bhkBreakableConstraint_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "bhkOrientHingedBodyAction")
	{
		TargetObjectRegistry->bhkOrientHingedBodyAction_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiDataStream")
	{
		TargetObjectRegistry->NiDataStream_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiRenderObject")
	{
		TargetObjectRegistry->NiRenderObject_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiMeshModifier")
	{
		TargetObjectRegistry->NiMeshModifier_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiMesh")
	{
		TargetObjectRegistry->NiMesh_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiMorphWeightsController")
	{
		TargetObjectRegistry->NiMorphWeightsController_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiMorphMeshModifier")
	{
		TargetObjectRegistry->NiMorphMeshModifier_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiSkinningMeshModifier")
	{
		TargetObjectRegistry->NiSkinningMeshModifier_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiInstancingMeshModifier")
	{
		TargetObjectRegistry->NiInstancingMeshModifier_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiSkinningLODController")
	{
		TargetObjectRegistry->NiSkinningLODController_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiPSParticleSystem")
	{
		TargetObjectRegistry->NiPSParticleSystem_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiPSMeshParticleSystem")
	{
		TargetObjectRegistry->NiPSMeshParticleSystem_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiPSEmitParticlesCtlr")
	{
		TargetObjectRegistry->NiPSEmitParticlesCtlr_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiPSForceActiveCtlr")
	{
		TargetObjectRegistry->NiPSForceActiveCtlr_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiPSSimulator")
	{
		TargetObjectRegistry->NiPSSimulator_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiPSSimulatorStep")
	{
		TargetObjectRegistry->NiPSSimulatorStep_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiPSSimulatorGeneralStep")
	{
		TargetObjectRegistry->NiPSSimulatorGeneralStep_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiPSSimulatorForcesStep")
	{
		TargetObjectRegistry->NiPSSimulatorForcesStep_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiPSSimulatorCollidersStep")
	{
		TargetObjectRegistry->NiPSSimulatorCollidersStep_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiPSSimulatorMeshAlignStep")
	{
		TargetObjectRegistry->NiPSSimulatorMeshAlignStep_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiPSSimulatorFinalStep")
	{
		TargetObjectRegistry->NiPSSimulatorFinalStep_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiPSFacingQuadGenerator")
	{
		TargetObjectRegistry->NiPSFacingQuadGenerator_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiShadowGenerator")
	{
		TargetObjectRegistry->NiShadowGenerator_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiPSBoundUpdater")
	{
		TargetObjectRegistry->NiPSBoundUpdater_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiPSDragForce")
	{
		TargetObjectRegistry->NiPSDragForce_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiPSGravityForce")
	{
		TargetObjectRegistry->NiPSGravityForce_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiPSBoxEmitter")
	{
		TargetObjectRegistry->NiPSBoxEmitter_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiPSMeshEmitter")
	{
		TargetObjectRegistry->NiPSMeshEmitter_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiPSGravityStrengthCtlr")
	{
		TargetObjectRegistry->NiPSGravityStrengthCtlr_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiPSPlanarCollider")
	{
		TargetObjectRegistry->NiPSPlanarCollider_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiPSEmitterSpeedCtlr")
	{
		TargetObjectRegistry->NiPSEmitterSpeedCtlr_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiPSEmitterRadiusCtlr")
	{
		TargetObjectRegistry->NiPSEmitterRadiusCtlr_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiPSResetOnLoopCtlr")
	{
		TargetObjectRegistry->NiPSResetOnLoopCtlr_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiPSSphereEmitter")
	{
		TargetObjectRegistry->NiPSSphereEmitter_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiPSCylinderEmitter")
	{
		TargetObjectRegistry->NiPSCylinderEmitter_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiPSEmitterDeclinationCtlr")
	{
		TargetObjectRegistry->NiPSEmitterDeclinationCtlr_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiPSEmitterDeclinationVarCtlr")
	{
		TargetObjectRegistry->NiPSEmitterDeclinationVarCtlr_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiPSEmitterPlanarAngleCtlr")
	{
		TargetObjectRegistry->NiPSEmitterPlanarAngleCtlr_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiPSEmitterPlanarAngleVarCtlr")
	{
		TargetObjectRegistry->NiPSEmitterPlanarAngleVarCtlr_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiPSEmitterRotAngleCtlr")
	{
		TargetObjectRegistry->NiPSEmitterRotAngleCtlr_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiPSEmitterRotAngleVarCtlr")
	{
		TargetObjectRegistry->NiPSEmitterRotAngleVarCtlr_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiPSEmitterRotSpeedCtlr")
	{
		TargetObjectRegistry->NiPSEmitterRotSpeedCtlr_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiPSEmitterRotSpeedVarCtlr")
	{
		TargetObjectRegistry->NiPSEmitterRotSpeedVarCtlr_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiPSEmitterLifeSpanCtlr")
	{
		TargetObjectRegistry->NiPSEmitterLifeSpanCtlr_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiPSBombForce")
	{
		TargetObjectRegistry->NiPSBombForce_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiPSSphericalCollider")
	{
		TargetObjectRegistry->NiPSSphericalCollider_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiPSSpawner")
	{
		TargetObjectRegistry->NiPSSpawner_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiSequenceData")
	{
		TargetObjectRegistry->NiSequenceData_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiTransformEvaluator")
	{
		TargetObjectRegistry->NiTransformEvaluator_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiBSplineCompTransformEvaluator")
	{
		TargetObjectRegistry->NiBSplineCompTransformEvaluator_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiMeshHWInstance")
	{
		TargetObjectRegistry->NiMeshHWInstance_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiFurSpringController")
	{
		TargetObjectRegistry->NiFurSpringController_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "CStreamableAssetData")
	{
		TargetObjectRegistry->CStreamableAssetData_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "bhkCompressedMeshShape")
	{
		TargetObjectRegistry->bhkCompressedMeshShape_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "bhkCompressedMeshShapeData")
	{
		TargetObjectRegistry->bhkCompressedMeshShapeData_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "BSInvMarker")
	{
		TargetObjectRegistry->BSInvMarker_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "BSBoneLODExtraData")
	{
		TargetObjectRegistry->BSBoneLODExtraData_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "BSBehaviorGraphExtraData")
	{
		TargetObjectRegistry->BSBehaviorGraphExtraData_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "BSLagBoneController")
	{
		TargetObjectRegistry->BSLagBoneController_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "BSLODTriShape")
	{
		TargetObjectRegistry->BSLODTriShape_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "BSFurnitureMarkerNode")
	{
		TargetObjectRegistry->BSFurnitureMarkerNode_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "BSLeafAnimNode")
	{
		TargetObjectRegistry->BSLeafAnimNode_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "BSTreeNode")
	{
		TargetObjectRegistry->BSTreeNode_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "NiLightRadiusController")
	{
		TargetObjectRegistry->NiLightRadiusController_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "BSShape")
	{
		TargetObjectRegistry->BSShape_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "BSTriShape")
	{
		TargetObjectRegistry->BSTriShape_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "BSSubIndexTriShape")
	{
		TargetObjectRegistry->BSSubIndexTriShape_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "BSMeshLODTriShape")
	{
		TargetObjectRegistry->BSMeshLODTriShape_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "bhkNPCollisionObject")
	{
		TargetObjectRegistry->bhkNPCollisionObject_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "BSExtraData")
	{
		TargetObjectRegistry->BSExtraData_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "bhkPhysicsSystem")
	{
		TargetObjectRegistry->bhkPhysicsSystem_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "bhkRagdollSystem")
	{
		TargetObjectRegistry->bhkRagdollSystem_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "BSClothExtraData")
	{
		TargetObjectRegistry->BSClothExtraData_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "BSSkin__Instance")
	{
		TargetObjectRegistry->BSSkin__Instance_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "BSSkin__BoneData")
	{
		TargetObjectRegistry->BSSkin__BoneData_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "BSPositionData")
	{
		TargetObjectRegistry->BSPositionData_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "BSConnectPoint__Parents")
	{
		TargetObjectRegistry->BSConnectPoint__Parents_Registry.Remove(IndexInRegistry);
	}
	if(NodeType == "BSConnectPoint__Children")
	{
		TargetObjectRegistry->BSConnectPoint__Children_Registry.Remove(IndexInRegistry);
	}
}

Niflib::NiObjectRef NifNodeTreeData::FindRoot_NodeTree(vector<Niflib::NiObjectRef> const & objects)
{
	using namespace Niflib;
	//--Look for a NiNode that has no parents--//
	//Find the first NiObjectNET derived object
	NiAVObjectRef root;
	for(size_t i = 0; i < objects.size(); ++i)
	{
		root = DynamicCast<NiAVObject>(objects[i]);
		if(root != NULL)
		{
			break;
		}
	}
	//Make sure a node was found, if not return first node
	if(root == NULL)
		return objects[0];
	//Move up the chain to the root node
	while(root->GetParent() != NULL)
	{
		root = StaticCast<NiAVObject>(root->GetParent());
	}
	return StaticCast<NiObject>(root);
}


void NifNodeTreeData::NifNodeTree::ReadNifNodeTree(istream & in, NiObjectList & missing_link_stack, Niflib::NifInfo * info /*= NULL*/)
{
	using namespace Niflib;
	if(Size() != 0)
	{
		ResetData();
	}
	////Ensure that objects are registered
	//if(g_objects_registered == false)
	//{
	//	g_objects_registered = true;
	//	RegisterObjects();
	//}

	//--Read Header--//
	Header header;
	hdrInfo hinfo(&header);

	// set the header pointer in the stream
	in >> hinfo;

	//Create a new NifInfo if one isn't given.
	bool delete_info = false;
	if(info == NULL)
	{
		info = new NifInfo();
		delete_info = true;
	}

	//Read header.
	*info = header.Read(in);

	//If NifInfo structure is provided, fill it with info from header
	info->version = header.version;
	info->userVersion = header.userVersion;
	info->userVersion2 = header.userVersion2;
	info->endian = EndianType(header.endianType);
	info->creator = header.exportInfo.creator.str;
	info->exportInfo1 = header.exportInfo.exportInfo1.str;
	info->exportInfo2 = header.exportInfo.exportInfo2.str;

#ifdef DEBUG_HEADER_FOOTER
	//Print debug output for header
	cout << header.asString();
#endif

#ifdef PRINT_OBJECT_NAMES
	cout << endl << "Reading Objects:";
#endif

	//--Read Objects--//
	size_t numObjects = header.numBlocks;
	map<unsigned, NiObjectRef> objects; //Map to hold objects by number
	vector<NiObjectRef> obj_list; //Vector to hold links in the order they were created.
	list<unsigned int> link_stack; //List to add link values to as they're read in from the file
	string objectType;
	stringstream errStream;

	std::streampos headerpos = in.tellg();
	std::streampos nextobjpos = headerpos;

	//Loop through all objects in the file
	unsigned int i = 0;
	NiObjectRef new_obj;
	while(true)
	{
		// Check if the size information matches in version 20.3 and greater
		if(header.version >= VER_20_3_0_3)
		{
			if(nextobjpos != in.tellg())
			{
				// incorrect positioning seek to expected location
				in.seekg(nextobjpos);
			}
			// update next location
			nextobjpos += header.blockSize[i];
		}

		//Check for EOF
		if(in.eof())
		{
			errStream << "End of file reached prematurely.  This NIF may be corrupt or improperly supported." << endl;
			if(new_obj != NULL)
			{
				errStream << "Last successfuly read object was:  " << endl;
				errStream << "====[ " << "Object " << i - 1 << " | " << new_obj->GetType().GetTypeName() << " ]====" << endl;
				errStream << new_obj->asString();
			}
			else
			{
				errStream << "No objects were read successfully." << endl;
			}
			throw runtime_error(errStream.str());
		}

		// Starting position of block in stream
		std::streampos startobjpos = in.tellg();

		//There are two main ways to read objects
		//One before version 5.0.0.1 and one after
		if(header.version >= 0x05000001)
		{
			//From version 5.0.0.1 to version 10.0.1.106  there is a zero byte at the begining of each object

			if(header.version <= VER_10_1_0_106)
			{
				unsigned int checkValue = ReadUInt(in);
				if(checkValue != 0)
				{
					//Throw an exception if it's not zero
					errStream << "Read failue - Bad object position.  Invalid check value:  " << checkValue << endl;
					if(new_obj != NULL)
					{
						errStream << "Last successfuly read object was:  " << endl;
						errStream << "====[ " << "Object " << i - 1 << " | " << new_obj->GetType().GetTypeName() << " ]====" << endl;
						errStream << new_obj->asString();
					}
					else
					{
						errStream << "No objects were read successfully." << endl;
					}
					throw runtime_error(errStream.str());
				}
			}

			// Find which NIF object type this is by using the header arrays
			objectType = header.blockTypes[header.blockTypeIndex[i]];

#ifdef PRINT_OBJECT_NAMES
			cout << endl << i << ":  " << objectType;
#endif
		}
		else
		{
			// Find which object type this is by reading the string at this location
			unsigned int objectTypeLength = ReadUInt(in);
			if(objectTypeLength > 30 || objectTypeLength < 6)
			{
				errStream << "Read failue - Bad object position.  Invalid Type Name Length:  " << objectTypeLength << endl;
				if(new_obj != NULL)
				{
					errStream << "Last successfuly read object was:  " << endl;
					errStream << "====[ " << "Object " << i - 1 << " | " << new_obj->GetType().GetTypeName() << " ]====" << endl;
					errStream << new_obj->asString();
				}
				else
				{
					errStream << "No objects were read successfully." << endl;
				}
				throw runtime_error(errStream.str());
			}
			char* charobjectType = new char[objectTypeLength + 1];
			in.read(charobjectType, objectTypeLength);
			charobjectType[objectTypeLength] = 0;
			objectType = string(charobjectType);
			delete [] charobjectType;

#ifdef PRINT_OBJECT_NAMES
			cout << endl << i << ":  " << objectType;
#endif

			if(header.version < VER_3_3_0_13)
			{
				//There can be special commands instead of object names
				//in these versions

				if(objectType == "Top Level Object")
				{
					//Just continue on to the next object
					continue;
				}

				if(objectType == "End Of File")
				{
					//File is finished
					break;
				}
			}
		}

		////Create object of the type that was found
		//new_obj = ObjectRegistry::CreateObject(objectType);

		////Check for an unknown object type
		//if(new_obj == NULL)
		//{
		//	errStream << "Unknown object type encountered during file read:  " << objectType << endl;
		//	if(new_obj != NULL)
		//	{
		//		errStream << "Last successfully read object was:  " << endl;
		//		errStream << "====[ " << "Object " << i - 1 << " | " << new_obj->GetType().GetTypeName() << " ]====" << endl;
		//		errStream << new_obj->asString();
		//	}
		//	else
		//	{
		//		errStream << "No objects were read successfully." << endl;
		//	}
		//	throw runtime_error(errStream.str());
		//}

		unsigned int index;
		if(header.version < VER_3_3_0_13)
		{
			//These old versions have a pointer value after the name
			//which is used as the index
			index = ReadUInt(in);
		}
		else
		{
			//These newer verisons use their position in the file as their index
			index = i;
		}

		//Read new object
		new_obj->Read(in, link_stack, *info);

		//Add object to map
		objects[index] = new_obj;

		//Add object to list
		obj_list.push_back(new_obj);

		//Store block number
		new_obj->internal_block_number = index;

		// Ending position of block in stream
		std::streampos endobjpos = in.tellg();

		// Check if the size information matches
		if(header.version >= VER_20_3_0_3)
		{
			std::streamsize calcobjsize = endobjpos - startobjpos;
			unsigned int objsize = header.blockSize[i];
			if(calcobjsize != objsize)
			{
				errStream << "Object size mismatch occurred during file read:" << endl;
				errStream << "====[ " << "Object " << i << " | " << objectType << " ]====" << endl;
				errStream << "  Start: " << startobjpos << "  Expected Size: " << objsize << "  Read Size: " << calcobjsize << endl;
				errStream << endl;
			}
		}

#ifdef PRINT_OBJECT_CONTENTS
		cout << endl << new_obj->asString() << endl;
#endif

		if(header.version >= VER_3_3_0_13)
		{
			//We know the number of objects, so increment the count
			//and break if we've finished
			++i;
			if(i >= numObjects)
			{
				break;
			}
		}
	}

	//--Read Footer--//
	Footer footer;
	footer.Read(in, link_stack, *info);

#ifdef DEBUG_HEADER_FOOTER
	//Print footer debug output
	footer.asString();
#endif

	// Check for accumulated warnings
	if(errStream.tellp() > 0)
	{
		throw runtime_error(errStream.str());
	}

#ifdef DEBUG_LINK_PHASE
	cout << "Link Stack:" << endl;
	list<unsigned int>::iterator it;
	for(it = link_stack.begin(); it != link_stack.end(); ++it)
	{
		cout << *it << endl;
	}

	cout << "Fixing Links:" << endl;
#endif
	//--Now that all objects are read, go back and fix the links--//

	for(unsigned int i = 0; i < obj_list.size(); ++i)
	{
#ifdef DEBUG_LINK_PHASE
		cout << "   " << i << ":  " << obj_list[i] << endl;
#endif
		//Fix links & other pre-processing
		obj_list[i]->FixLinks(objects, link_stack, missing_link_stack, *info);
	}

	//delete info if it was dynamically allocated
	if(delete_info)
	{
		delete info;
	}

	// clear the header pointer in the stream.  Should be in try/catch block
	hdrInfo hinfo2(NULL);
	in >> hinfo2;

	//obj_list;
	//Now Arrange and add nodes from obj_list to NodeTree in correct order
}
