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
		TargetObjectRegistry.NiObject_Registry.GetElementPointerV2(Index)->InternalName = InternalName;
	}
	if(TargetNodeType == "Ni3dsAlphaAnimator")
	{
		Index = TargetObjectRegistry.Ni3dsAlphaAnimator_Registry.AddData();
	}
	if(TargetNodeType == "Ni3dsAnimationNode")
	{
		Index = TargetObjectRegistry.Ni3dsAnimationNode_Registry.AddData();
	}
	if(TargetNodeType == "Ni3dsColorAnimator")
	{
		Index = TargetObjectRegistry.Ni3dsColorAnimator_Registry.AddData();
	}
	if(TargetNodeType == "Ni3dsMorphShape")
	{
		Index = TargetObjectRegistry.Ni3dsMorphShape_Registry.AddData();
	}
	if(TargetNodeType == "Ni3dsParticleSystem")
	{
		Index = TargetObjectRegistry.Ni3dsParticleSystem_Registry.AddData();
	}
	if(TargetNodeType == "Ni3dsPathController")
	{
		Index = TargetObjectRegistry.Ni3dsPathController_Registry.AddData();
	}
	if(TargetNodeType == "NiParticleModifier")
	{
		Index = TargetObjectRegistry.NiParticleModifier_Registry.AddData();
	}
	if(TargetNodeType == "NiPSysCollider")
	{
		Index = TargetObjectRegistry.NiPSysCollider_Registry.AddData();
	}
	if(TargetNodeType == "bhkRefObject")
	{
		Index = TargetObjectRegistry.bhkRefObject_Registry.AddData();
	}
	if(TargetNodeType == "bhkSerializable")
	{
		Index = TargetObjectRegistry.bhkSerializable_Registry.AddData();
	}
	if(TargetNodeType == "bhkWorldObject")
	{
		Index = TargetObjectRegistry.bhkWorldObject_Registry.AddData();
	}
	if(TargetNodeType == "bhkPhantom")
	{
		Index = TargetObjectRegistry.bhkPhantom_Registry.AddData();
	}
	if(TargetNodeType == "bhkShapePhantom")
	{
		Index = TargetObjectRegistry.bhkShapePhantom_Registry.AddData();
	}
	if(TargetNodeType == "bhkSimpleShapePhantom")
	{
		Index = TargetObjectRegistry.bhkSimpleShapePhantom_Registry.AddData();
	}
	if(TargetNodeType == "bhkEntity")
	{
		Index = TargetObjectRegistry.bhkEntity_Registry.AddData();
	}
	if(TargetNodeType == "bhkRigidBody")
	{
		Index = TargetObjectRegistry.bhkRigidBody_Registry.AddData();
	}
	if(TargetNodeType == "bhkRigidBodyT")
	{
		Index = TargetObjectRegistry.bhkRigidBodyT_Registry.AddData();
	}
	if(TargetNodeType == "bhkConstraint")
	{
		Index = TargetObjectRegistry.bhkConstraint_Registry.AddData();
	}
	if(TargetNodeType == "bhkLimitedHingeConstraint")
	{
		Index = TargetObjectRegistry.bhkLimitedHingeConstraint_Registry.AddData();
	}
	if(TargetNodeType == "bhkMalleableConstraint")
	{
		Index = TargetObjectRegistry.bhkMalleableConstraint_Registry.AddData();
	}
	if(TargetNodeType == "bhkStiffSpringConstraint")
	{
		Index = TargetObjectRegistry.bhkStiffSpringConstraint_Registry.AddData();
	}
	if(TargetNodeType == "bhkRagdollConstraint")
	{
		Index = TargetObjectRegistry.bhkRagdollConstraint_Registry.AddData();
	}
	if(TargetNodeType == "bhkPrismaticConstraint")
	{
		Index = TargetObjectRegistry.bhkPrismaticConstraint_Registry.AddData();
	}
	if(TargetNodeType == "bhkHingeConstraint")
	{
		Index = TargetObjectRegistry.bhkHingeConstraint_Registry.AddData();
	}
	if(TargetNodeType == "bhkBallAndSocketConstraint")
	{
		Index = TargetObjectRegistry.bhkBallAndSocketConstraint_Registry.AddData();
	}
	if(TargetNodeType == "bhkBallSocketConstraintChain")
	{
		Index = TargetObjectRegistry.bhkBallSocketConstraintChain_Registry.AddData();
	}
	if(TargetNodeType == "bhkShape")
	{
		Index = TargetObjectRegistry.bhkShape_Registry.AddData();
	}
	if(TargetNodeType == "bhkTransformShape")
	{
		Index = TargetObjectRegistry.bhkTransformShape_Registry.AddData();
	}
	if(TargetNodeType == "bhkSphereRepShape")
	{
		Index = TargetObjectRegistry.bhkSphereRepShape_Registry.AddData();
	}
	if(TargetNodeType == "bhkConvexShape")
	{
		Index = TargetObjectRegistry.bhkConvexShape_Registry.AddData();
	}
	if(TargetNodeType == "bhkSphereShape")
	{
		Index = TargetObjectRegistry.bhkSphereShape_Registry.AddData();
	}
	if(TargetNodeType == "bhkCapsuleShape")
	{
		Index = TargetObjectRegistry.bhkCapsuleShape_Registry.AddData();
	}
	if(TargetNodeType == "bhkBoxShape")
	{
		Index = TargetObjectRegistry.bhkBoxShape_Registry.AddData();
	}
	if(TargetNodeType == "bhkConvexVerticesShape")
	{
		Index = TargetObjectRegistry.bhkConvexVerticesShape_Registry.AddData();
	}
	if(TargetNodeType == "bhkConvexTransformShape")
	{
		Index = TargetObjectRegistry.bhkConvexTransformShape_Registry.AddData();
	}
	if(TargetNodeType == "bhkMultiSphereShape")
	{
		Index = TargetObjectRegistry.bhkMultiSphereShape_Registry.AddData();
	}
	if(TargetNodeType == "bhkBvTreeShape")
	{
		Index = TargetObjectRegistry.bhkBvTreeShape_Registry.AddData();
	}
	if(TargetNodeType == "bhkMoppBvTreeShape")
	{
		Index = TargetObjectRegistry.bhkMoppBvTreeShape_Registry.AddData();
	}
	if(TargetNodeType == "bhkShapeCollection")
	{
		Index = TargetObjectRegistry.bhkShapeCollection_Registry.AddData();
	}
	if(TargetNodeType == "bhkListShape")
	{
		Index = TargetObjectRegistry.bhkListShape_Registry.AddData();
	}
	if(TargetNodeType == "bhkMeshShape")
	{
		Index = TargetObjectRegistry.bhkMeshShape_Registry.AddData();
	}
	if(TargetNodeType == "bhkPackedNiTriStripsShape")
	{
		Index = TargetObjectRegistry.bhkPackedNiTriStripsShape_Registry.AddData();
	}
	if(TargetNodeType == "bhkNiTriStripsShape")
	{
		Index = TargetObjectRegistry.bhkNiTriStripsShape_Registry.AddData();
	}
	if(TargetNodeType == "NiExtraData")
	{
		Index = TargetObjectRegistry.NiExtraData_Registry.AddData();
	}
	if(TargetNodeType == "NiInterpolator")
	{
		Index = TargetObjectRegistry.NiInterpolator_Registry.AddData();
	}
	if(TargetNodeType == "NiKeyBasedInterpolator")
	{
		Index = TargetObjectRegistry.NiKeyBasedInterpolator_Registry.AddData();
	}
	if(TargetNodeType == "NiFloatInterpolator")
	{
		Index = TargetObjectRegistry.NiFloatInterpolator_Registry.AddData();
	}
	if(TargetNodeType == "NiTransformInterpolator")
	{
		Index = TargetObjectRegistry.NiTransformInterpolator_Registry.AddData();
	}
	if(TargetNodeType == "NiPoint3Interpolator")
	{
		Index = TargetObjectRegistry.NiPoint3Interpolator_Registry.AddData();
	}
	if(TargetNodeType == "NiPathInterpolator")
	{
		Index = TargetObjectRegistry.NiPathInterpolator_Registry.AddData();
	}
	if(TargetNodeType == "NiBoolInterpolator")
	{
		Index = TargetObjectRegistry.NiBoolInterpolator_Registry.AddData();
	}
	if(TargetNodeType == "NiBoolTimelineInterpolator")
	{
		Index = TargetObjectRegistry.NiBoolTimelineInterpolator_Registry.AddData();
	}
	if(TargetNodeType == "NiBlendInterpolator")
	{
		Index = TargetObjectRegistry.NiBlendInterpolator_Registry.AddData();
	}
	if(TargetNodeType == "NiBSplineInterpolator")
	{
		Index = TargetObjectRegistry.NiBSplineInterpolator_Registry.AddData();
	}
	if(TargetNodeType == "NiObjectNET")
	{
		Index = TargetObjectRegistry.NiObjectNET_Registry.AddData();
	}
	if(TargetNodeType == "NiCollisionObject")
	{
		Index = TargetObjectRegistry.NiCollisionObject_Registry.AddData();
	}
	if(TargetNodeType == "NiCollisionData")
	{
		Index = TargetObjectRegistry.NiCollisionData_Registry.AddData();
	}
	if(TargetNodeType == "bhkNiCollisionObject")
	{
		Index = TargetObjectRegistry.bhkNiCollisionObject_Registry.AddData();
	}
	if(TargetNodeType == "bhkCollisionObject")
	{
		Index = TargetObjectRegistry.bhkCollisionObject_Registry.AddData();
	}
	if(TargetNodeType == "bhkBlendCollisionObject")
	{
		Index = TargetObjectRegistry.bhkBlendCollisionObject_Registry.AddData();
	}
	if(TargetNodeType == "bhkPCollisionObject")
	{
		Index = TargetObjectRegistry.bhkPCollisionObject_Registry.AddData();
	}
	if(TargetNodeType == "bhkSPCollisionObject")
	{
		Index = TargetObjectRegistry.bhkSPCollisionObject_Registry.AddData();
	}
	if(TargetNodeType == "NiAVObject")
	{
		Index = TargetObjectRegistry.NiAVObject_Registry.AddData();
	}
	if(TargetNodeType == "NiDynamicEffect")
	{
		Index = TargetObjectRegistry.NiDynamicEffect_Registry.AddData();
	}
	if(TargetNodeType == "NiLight")
	{
		Index = TargetObjectRegistry.NiLight_Registry.AddData();
	}
	if(TargetNodeType == "NiProperty")
	{
		Index = TargetObjectRegistry.NiProperty_Registry.AddData();
	}
	if(TargetNodeType == "NiTransparentProperty")
	{
		Index = TargetObjectRegistry.NiTransparentProperty_Registry.AddData();
	}
	if(TargetNodeType == "NiPSysModifier")
	{
		Index = TargetObjectRegistry.NiPSysModifier_Registry.AddData();
	}
	if(TargetNodeType == "NiPSysEmitter")
	{
		Index = TargetObjectRegistry.NiPSysEmitter_Registry.AddData();
	}
	if(TargetNodeType == "NiPSysVolumeEmitter")
	{
		Index = TargetObjectRegistry.NiPSysVolumeEmitter_Registry.AddData();
	}
	if(TargetNodeType == "NiTimeController")
	{
		Index = TargetObjectRegistry.NiTimeController_Registry.AddData();
	}
	if(TargetNodeType == "NiInterpController")
	{
		Index = TargetObjectRegistry.NiInterpController_Registry.AddData();
	}
	if(TargetNodeType == "NiMultiTargetTransformController")
	{
		Index = TargetObjectRegistry.NiMultiTargetTransformController_Registry.AddData();
	}
	if(TargetNodeType == "NiGeomMorpherController")
	{
		Index = TargetObjectRegistry.NiGeomMorpherController_Registry.AddData();
	}
	if(TargetNodeType == "NiMorphController")
	{
		Index = TargetObjectRegistry.NiMorphController_Registry.AddData();
	}
	if(TargetNodeType == "NiMorpherController")
	{
		Index = TargetObjectRegistry.NiMorpherController_Registry.AddData();
	}
	if(TargetNodeType == "NiSingleInterpController")
	{
		Index = TargetObjectRegistry.NiSingleInterpController_Registry.AddData();
	}
	if(TargetNodeType == "NiKeyframeController")
	{
		Index = TargetObjectRegistry.NiKeyframeController_Registry.AddData();
	}
	if(TargetNodeType == "NiTransformController")
	{
		Index = TargetObjectRegistry.NiTransformController_Registry.AddData();
	}
	if(TargetNodeType == "NiPSysModifierCtlr")
	{
		Index = TargetObjectRegistry.NiPSysModifierCtlr_Registry.AddData();
	}
	if(TargetNodeType == "NiPSysEmitterCtlr")
	{
		Index = TargetObjectRegistry.NiPSysEmitterCtlr_Registry.AddData();
	}
	if(TargetNodeType == "NiPSysModifierBoolCtlr")
	{
		Index = TargetObjectRegistry.NiPSysModifierBoolCtlr_Registry.AddData();
	}
	if(TargetNodeType == "NiPSysModifierActiveCtlr")
	{
		Index = TargetObjectRegistry.NiPSysModifierActiveCtlr_Registry.AddData();
	}
	if(TargetNodeType == "NiPSysModifierFloatCtlr")
	{
		Index = TargetObjectRegistry.NiPSysModifierFloatCtlr_Registry.AddData();
	}
	if(TargetNodeType == "NiPSysEmitterDeclinationCtlr")
	{
		Index = TargetObjectRegistry.NiPSysEmitterDeclinationCtlr_Registry.AddData();
	}
	if(TargetNodeType == "NiPSysEmitterDeclinationVarCtlr")
	{
		Index = TargetObjectRegistry.NiPSysEmitterDeclinationVarCtlr_Registry.AddData();
	}
	if(TargetNodeType == "NiPSysEmitterInitialRadiusCtlr")
	{
		Index = TargetObjectRegistry.NiPSysEmitterInitialRadiusCtlr_Registry.AddData();
	}
	if(TargetNodeType == "NiPSysEmitterLifeSpanCtlr")
	{
		Index = TargetObjectRegistry.NiPSysEmitterLifeSpanCtlr_Registry.AddData();
	}
	if(TargetNodeType == "NiPSysEmitterSpeedCtlr")
	{
		Index = TargetObjectRegistry.NiPSysEmitterSpeedCtlr_Registry.AddData();
	}
	if(TargetNodeType == "NiPSysGravityStrengthCtlr")
	{
		Index = TargetObjectRegistry.NiPSysGravityStrengthCtlr_Registry.AddData();
	}
	if(TargetNodeType == "NiFloatInterpController")
	{
		Index = TargetObjectRegistry.NiFloatInterpController_Registry.AddData();
	}
	if(TargetNodeType == "NiFlipController")
	{
		Index = TargetObjectRegistry.NiFlipController_Registry.AddData();
	}
	if(TargetNodeType == "NiAlphaController")
	{
		Index = TargetObjectRegistry.NiAlphaController_Registry.AddData();
	}
	if(TargetNodeType == "NiTextureTransformController")
	{
		Index = TargetObjectRegistry.NiTextureTransformController_Registry.AddData();
	}
	if(TargetNodeType == "NiLightDimmerController")
	{
		Index = TargetObjectRegistry.NiLightDimmerController_Registry.AddData();
	}
	if(TargetNodeType == "NiBoolInterpController")
	{
		Index = TargetObjectRegistry.NiBoolInterpController_Registry.AddData();
	}
	if(TargetNodeType == "NiVisController")
	{
		Index = TargetObjectRegistry.NiVisController_Registry.AddData();
	}
	if(TargetNodeType == "NiPoint3InterpController")
	{
		Index = TargetObjectRegistry.NiPoint3InterpController_Registry.AddData();
	}
	if(TargetNodeType == "NiMaterialColorController")
	{
		Index = TargetObjectRegistry.NiMaterialColorController_Registry.AddData();
	}
	if(TargetNodeType == "NiLightColorController")
	{
		Index = TargetObjectRegistry.NiLightColorController_Registry.AddData();
	}
	if(TargetNodeType == "NiExtraDataController")
	{
		Index = TargetObjectRegistry.NiExtraDataController_Registry.AddData();
	}
	if(TargetNodeType == "NiFloatExtraDataController")
	{
		Index = TargetObjectRegistry.NiFloatExtraDataController_Registry.AddData();
	}
	if(TargetNodeType == "NiBoneLODController")
	{
		Index = TargetObjectRegistry.NiBoneLODController_Registry.AddData();
	}
	if(TargetNodeType == "NiBSBoneLODController")
	{
		Index = TargetObjectRegistry.NiBSBoneLODController_Registry.AddData();
	}
	if(TargetNodeType == "NiGeometry")
	{
		Index = TargetObjectRegistry.NiGeometry_Registry.AddData();
	}
	if(TargetNodeType == "NiTriBasedGeom")
	{
		Index = TargetObjectRegistry.NiTriBasedGeom_Registry.AddData();
	}
	if(TargetNodeType == "NiGeometryData")
	{
		Index = TargetObjectRegistry.NiGeometryData_Registry.AddData();
	}
	if(TargetNodeType == "AbstractAdditionalGeometryData")
	{
		Index = TargetObjectRegistry.AbstractAdditionalGeometryData_Registry.AddData();
	}
	if(TargetNodeType == "NiTriBasedGeomData")
	{
		Index = TargetObjectRegistry.NiTriBasedGeomData_Registry.AddData();
	}
	if(TargetNodeType == "bhkBlendController")
	{
		Index = TargetObjectRegistry.bhkBlendController_Registry.AddData();
	}
	if(TargetNodeType == "BSBound")
	{
		Index = TargetObjectRegistry.BSBound_Registry.AddData();
	}
	if(TargetNodeType == "BSFurnitureMarker")
	{
		Index = TargetObjectRegistry.BSFurnitureMarker_Registry.AddData();
	}
	if(TargetNodeType == "BSParentVelocityModifier")
	{
		Index = TargetObjectRegistry.BSParentVelocityModifier_Registry.AddData();
	}
	if(TargetNodeType == "BSPSysArrayEmitter")
	{
		Index = TargetObjectRegistry.BSPSysArrayEmitter_Registry.AddData();
	}
	if(TargetNodeType == "BSWindModifier")
	{
		Index = TargetObjectRegistry.BSWindModifier_Registry.AddData();
	}
	if(TargetNodeType == "hkPackedNiTriStripsData")
	{
		Index = TargetObjectRegistry.hkPackedNiTriStripsData_Registry.AddData();
	}
	if(TargetNodeType == "NiAlphaProperty")
	{
		Index = TargetObjectRegistry.NiAlphaProperty_Registry.AddData();
	}
	if(TargetNodeType == "NiAmbientLight")
	{
		Index = TargetObjectRegistry.NiAmbientLight_Registry.AddData();
	}
	if(TargetNodeType == "NiParticlesData")
	{
		Index = TargetObjectRegistry.NiParticlesData_Registry.AddData();
	}
	if(TargetNodeType == "NiRotatingParticlesData")
	{
		Index = TargetObjectRegistry.NiRotatingParticlesData_Registry.AddData();
	}
	if(TargetNodeType == "NiAutoNormalParticlesData")
	{
		Index = TargetObjectRegistry.NiAutoNormalParticlesData_Registry.AddData();
	}
	if(TargetNodeType == "NiPSysData")
	{
		Index = TargetObjectRegistry.NiPSysData_Registry.AddData();
	}
	if(TargetNodeType == "NiMeshPSysData")
	{
		Index = TargetObjectRegistry.NiMeshPSysData_Registry.AddData();
	}
	if(TargetNodeType == "NiBinaryExtraData")
	{
		Index = TargetObjectRegistry.NiBinaryExtraData_Registry.AddData();
	}
	if(TargetNodeType == "NiBinaryVoxelExtraData")
	{
		Index = TargetObjectRegistry.NiBinaryVoxelExtraData_Registry.AddData();
	}
	if(TargetNodeType == "NiBinaryVoxelData")
	{
		Index = TargetObjectRegistry.NiBinaryVoxelData_Registry.AddData();
	}
	if(TargetNodeType == "NiBlendBoolInterpolator")
	{
		Index = TargetObjectRegistry.NiBlendBoolInterpolator_Registry.AddData();
	}
	if(TargetNodeType == "NiBlendFloatInterpolator")
	{
		Index = TargetObjectRegistry.NiBlendFloatInterpolator_Registry.AddData();
	}
	if(TargetNodeType == "NiBlendPoint3Interpolator")
	{
		Index = TargetObjectRegistry.NiBlendPoint3Interpolator_Registry.AddData();
	}
	if(TargetNodeType == "NiBlendTransformInterpolator")
	{
		Index = TargetObjectRegistry.NiBlendTransformInterpolator_Registry.AddData();
	}
	if(TargetNodeType == "NiBoolData")
	{
		Index = TargetObjectRegistry.NiBoolData_Registry.AddData();
	}
	if(TargetNodeType == "NiBooleanExtraData")
	{
		Index = TargetObjectRegistry.NiBooleanExtraData_Registry.AddData();
	}
	if(TargetNodeType == "NiBSplineBasisData")
	{
		Index = TargetObjectRegistry.NiBSplineBasisData_Registry.AddData();
	}
	if(TargetNodeType == "NiBSplineFloatInterpolator")
	{
		Index = TargetObjectRegistry.NiBSplineFloatInterpolator_Registry.AddData();
	}
	if(TargetNodeType == "NiBSplineCompFloatInterpolator")
	{
		Index = TargetObjectRegistry.NiBSplineCompFloatInterpolator_Registry.AddData();
	}
	if(TargetNodeType == "NiBSplinePoint3Interpolator")
	{
		Index = TargetObjectRegistry.NiBSplinePoint3Interpolator_Registry.AddData();
	}
	if(TargetNodeType == "NiBSplineCompPoint3Interpolator")
	{
		Index = TargetObjectRegistry.NiBSplineCompPoint3Interpolator_Registry.AddData();
	}
	if(TargetNodeType == "NiBSplineTransformInterpolator")
	{
		Index = TargetObjectRegistry.NiBSplineTransformInterpolator_Registry.AddData();
	}
	if(TargetNodeType == "NiBSplineCompTransformInterpolator")
	{
		Index = TargetObjectRegistry.NiBSplineCompTransformInterpolator_Registry.AddData();
	}
	if(TargetNodeType == "BSRotAccumTransfInterpolator")
	{
		Index = TargetObjectRegistry.BSRotAccumTransfInterpolator_Registry.AddData();
	}
	if(TargetNodeType == "NiBSplineData")
	{
		Index = TargetObjectRegistry.NiBSplineData_Registry.AddData();
	}
	if(TargetNodeType == "NiCamera")
	{
		Index = TargetObjectRegistry.NiCamera_Registry.AddData();
	}
	if(TargetNodeType == "NiColorData")
	{
		Index = TargetObjectRegistry.NiColorData_Registry.AddData();
	}
	if(TargetNodeType == "NiColorExtraData")
	{
		Index = TargetObjectRegistry.NiColorExtraData_Registry.AddData();
	}
	if(TargetNodeType == "NiControllerManager")
	{
		Index = TargetObjectRegistry.NiControllerManager_Registry.AddData();
	}
	if(TargetNodeType == "NiSequence")
	{
		Index = TargetObjectRegistry.NiSequence_Registry.AddData();
	}
	if(TargetNodeType == "NiControllerSequence")
	{
		Index = TargetObjectRegistry.NiControllerSequence_Registry.AddData();
	}
	if(TargetNodeType == "NiAVObjectPalette")
	{
		Index = TargetObjectRegistry.NiAVObjectPalette_Registry.AddData();
	}
	if(TargetNodeType == "NiDefaultAVObjectPalette")
	{
		Index = TargetObjectRegistry.NiDefaultAVObjectPalette_Registry.AddData();
	}
	if(TargetNodeType == "NiDirectionalLight")
	{
		Index = TargetObjectRegistry.NiDirectionalLight_Registry.AddData();
	}
	if(TargetNodeType == "NiDitherProperty")
	{
		Index = TargetObjectRegistry.NiDitherProperty_Registry.AddData();
	}
	if(TargetNodeType == "NiRollController")
	{
		Index = TargetObjectRegistry.NiRollController_Registry.AddData();
	}
	if(TargetNodeType == "NiFloatData")
	{
		Index = TargetObjectRegistry.NiFloatData_Registry.AddData();
	}
	if(TargetNodeType == "NiFloatExtraData")
	{
		Index = TargetObjectRegistry.NiFloatExtraData_Registry.AddData();
	}
	if(TargetNodeType == "NiFloatsExtraData")
	{
		Index = TargetObjectRegistry.NiFloatsExtraData_Registry.AddData();
	}
	if(TargetNodeType == "NiFogProperty")
	{
		Index = TargetObjectRegistry.NiFogProperty_Registry.AddData();
	}
	if(TargetNodeType == "NiGravity")
	{
		Index = TargetObjectRegistry.NiGravity_Registry.AddData();
	}
	if(TargetNodeType == "NiIntegerExtraData")
	{
		Index = TargetObjectRegistry.NiIntegerExtraData_Registry.AddData();
	}
	if(TargetNodeType == "BSXFlags")
	{
		Index = TargetObjectRegistry.BSXFlags_Registry.AddData();
	}
	if(TargetNodeType == "NiIntegersExtraData")
	{
		Index = TargetObjectRegistry.NiIntegersExtraData_Registry.AddData();
	}
	if(TargetNodeType == "BSKeyframeController")
	{
		Index = TargetObjectRegistry.BSKeyframeController_Registry.AddData();
	}
	if(TargetNodeType == "NiKeyframeData")
	{
		Index = TargetObjectRegistry.NiKeyframeData_Registry.AddData();
	}
	if(TargetNodeType == "NiLookAtController")
	{
		Index = TargetObjectRegistry.NiLookAtController_Registry.AddData();
	}
	if(TargetNodeType == "NiLookAtInterpolator")
	{
		Index = TargetObjectRegistry.NiLookAtInterpolator_Registry.AddData();
	}
	if(TargetNodeType == "NiMaterialProperty")
	{
		Index = TargetObjectRegistry.NiMaterialProperty_Registry.AddData();
	}
	if(TargetNodeType == "NiMorphData")
	{
		Index = TargetObjectRegistry.NiMorphData_Registry.AddData();
	}
	if(TargetNodeType == "NiNode")
	{
		Index = TargetObjectRegistry.NiNode_Registry.AddData();
	}
	if(TargetNodeType == "NiBone")
	{
		Index = TargetObjectRegistry.NiBone_Registry.AddData();
	}
	if(TargetNodeType == "AvoidNode")
	{
		Index = TargetObjectRegistry.AvoidNode_Registry.AddData();
	}
	if(TargetNodeType == "FxWidget")
	{
		Index = TargetObjectRegistry.FxWidget_Registry.AddData();
	}
	if(TargetNodeType == "FxButton")
	{
		Index = TargetObjectRegistry.FxButton_Registry.AddData();
	}
	if(TargetNodeType == "FxRadioButton")
	{
		Index = TargetObjectRegistry.FxRadioButton_Registry.AddData();
	}
	if(TargetNodeType == "NiBillboardNode")
	{
		Index = TargetObjectRegistry.NiBillboardNode_Registry.AddData();
	}
	if(TargetNodeType == "NiBSAnimationNode")
	{
		Index = TargetObjectRegistry.NiBSAnimationNode_Registry.AddData();
	}
	if(TargetNodeType == "NiBSParticleNode")
	{
		Index = TargetObjectRegistry.NiBSParticleNode_Registry.AddData();
	}
	if(TargetNodeType == "NiSwitchNode")
	{
		Index = TargetObjectRegistry.NiSwitchNode_Registry.AddData();
	}
	if(TargetNodeType == "NiLODNode")
	{
		Index = TargetObjectRegistry.NiLODNode_Registry.AddData();
	}
	if(TargetNodeType == "NiPalette")
	{
		Index = TargetObjectRegistry.NiPalette_Registry.AddData();
	}
	if(TargetNodeType == "NiParticleBomb")
	{
		Index = TargetObjectRegistry.NiParticleBomb_Registry.AddData();
	}
	if(TargetNodeType == "NiParticleColorModifier")
	{
		Index = TargetObjectRegistry.NiParticleColorModifier_Registry.AddData();
	}
	if(TargetNodeType == "NiParticleGrowFade")
	{
		Index = TargetObjectRegistry.NiParticleGrowFade_Registry.AddData();
	}
	if(TargetNodeType == "NiParticleMeshModifier")
	{
		Index = TargetObjectRegistry.NiParticleMeshModifier_Registry.AddData();
	}
	if(TargetNodeType == "NiParticleRotation")
	{
		Index = TargetObjectRegistry.NiParticleRotation_Registry.AddData();
	}
	if(TargetNodeType == "NiParticles")
	{
		Index = TargetObjectRegistry.NiParticles_Registry.AddData();
	}
	if(TargetNodeType == "NiAutoNormalParticles")
	{
		Index = TargetObjectRegistry.NiAutoNormalParticles_Registry.AddData();
	}
	if(TargetNodeType == "NiParticleMeshes")
	{
		Index = TargetObjectRegistry.NiParticleMeshes_Registry.AddData();
	}
	if(TargetNodeType == "NiParticleMeshesData")
	{
		Index = TargetObjectRegistry.NiParticleMeshesData_Registry.AddData();
	}
	if(TargetNodeType == "NiParticleSystem")
	{
		Index = TargetObjectRegistry.NiParticleSystem_Registry.AddData();
	}
	if(TargetNodeType == "NiMeshParticleSystem")
	{
		Index = TargetObjectRegistry.NiMeshParticleSystem_Registry.AddData();
	}
	if(TargetNodeType == "NiParticleSystemController")
	{
		Index = TargetObjectRegistry.NiParticleSystemController_Registry.AddData();
	}
	if(TargetNodeType == "NiBSPArrayController")
	{
		Index = TargetObjectRegistry.NiBSPArrayController_Registry.AddData();
	}
	if(TargetNodeType == "NiPathController")
	{
		Index = TargetObjectRegistry.NiPathController_Registry.AddData();
	}
	if(TargetNodeType == "ATextureRenderData")
	{
		Index = TargetObjectRegistry.ATextureRenderData_Registry.AddData();
	}
	if(TargetNodeType == "NiPersistentSrcTextureRendererData")
	{
		Index = TargetObjectRegistry.NiPersistentSrcTextureRendererData_Registry.AddData();
	}
	if(TargetNodeType == "NiPixelData")
	{
		Index = TargetObjectRegistry.NiPixelData_Registry.AddData();
	}
	if(TargetNodeType == "NiPlanarCollider")
	{
		Index = TargetObjectRegistry.NiPlanarCollider_Registry.AddData();
	}
	if(TargetNodeType == "NiPointLight")
	{
		Index = TargetObjectRegistry.NiPointLight_Registry.AddData();
	}
	if(TargetNodeType == "NiPosData")
	{
		Index = TargetObjectRegistry.NiPosData_Registry.AddData();
	}
	if(TargetNodeType == "NiPSysAgeDeathModifier")
	{
		Index = TargetObjectRegistry.NiPSysAgeDeathModifier_Registry.AddData();
	}
	if(TargetNodeType == "NiPSysBombModifier")
	{
		Index = TargetObjectRegistry.NiPSysBombModifier_Registry.AddData();
	}
	if(TargetNodeType == "NiPSysBoundUpdateModifier")
	{
		Index = TargetObjectRegistry.NiPSysBoundUpdateModifier_Registry.AddData();
	}
	if(TargetNodeType == "NiPSysBoxEmitter")
	{
		Index = TargetObjectRegistry.NiPSysBoxEmitter_Registry.AddData();
	}
	if(TargetNodeType == "NiPSysColliderManager")
	{
		Index = TargetObjectRegistry.NiPSysColliderManager_Registry.AddData();
	}
	if(TargetNodeType == "NiPSysColorModifier")
	{
		Index = TargetObjectRegistry.NiPSysColorModifier_Registry.AddData();
	}
	if(TargetNodeType == "NiPSysCylinderEmitter")
	{
		Index = TargetObjectRegistry.NiPSysCylinderEmitter_Registry.AddData();
	}
	if(TargetNodeType == "NiPSysDragModifier")
	{
		Index = TargetObjectRegistry.NiPSysDragModifier_Registry.AddData();
	}
	if(TargetNodeType == "NiPSysEmitterCtlrData")
	{
		Index = TargetObjectRegistry.NiPSysEmitterCtlrData_Registry.AddData();
	}
	if(TargetNodeType == "NiPSysGravityModifier")
	{
		Index = TargetObjectRegistry.NiPSysGravityModifier_Registry.AddData();
	}
	if(TargetNodeType == "NiPSysGrowFadeModifier")
	{
		Index = TargetObjectRegistry.NiPSysGrowFadeModifier_Registry.AddData();
	}
	if(TargetNodeType == "NiPSysMeshEmitter")
	{
		Index = TargetObjectRegistry.NiPSysMeshEmitter_Registry.AddData();
	}
	if(TargetNodeType == "NiPSysMeshUpdateModifier")
	{
		Index = TargetObjectRegistry.NiPSysMeshUpdateModifier_Registry.AddData();
	}
	if(TargetNodeType == "BSPSysInheritVelocityModifier")
	{
		Index = TargetObjectRegistry.BSPSysInheritVelocityModifier_Registry.AddData();
	}
	if(TargetNodeType == "BSPSysHavokUpdateModifier")
	{
		Index = TargetObjectRegistry.BSPSysHavokUpdateModifier_Registry.AddData();
	}
	if(TargetNodeType == "BSPSysRecycleBoundModifier")
	{
		Index = TargetObjectRegistry.BSPSysRecycleBoundModifier_Registry.AddData();
	}
	if(TargetNodeType == "BSPSysSubTexModifier")
	{
		Index = TargetObjectRegistry.BSPSysSubTexModifier_Registry.AddData();
	}
	if(TargetNodeType == "NiPSysPlanarCollider")
	{
		Index = TargetObjectRegistry.NiPSysPlanarCollider_Registry.AddData();
	}
	if(TargetNodeType == "NiPSysSphericalCollider")
	{
		Index = TargetObjectRegistry.NiPSysSphericalCollider_Registry.AddData();
	}
	if(TargetNodeType == "NiPSysPositionModifier")
	{
		Index = TargetObjectRegistry.NiPSysPositionModifier_Registry.AddData();
	}
	if(TargetNodeType == "NiPSysResetOnLoopCtlr")
	{
		Index = TargetObjectRegistry.NiPSysResetOnLoopCtlr_Registry.AddData();
	}
	if(TargetNodeType == "NiPSysRotationModifier")
	{
		Index = TargetObjectRegistry.NiPSysRotationModifier_Registry.AddData();
	}
	if(TargetNodeType == "NiPSysSpawnModifier")
	{
		Index = TargetObjectRegistry.NiPSysSpawnModifier_Registry.AddData();
	}
	if(TargetNodeType == "NiPSysSphereEmitter")
	{
		Index = TargetObjectRegistry.NiPSysSphereEmitter_Registry.AddData();
	}
	if(TargetNodeType == "NiPSysUpdateCtlr")
	{
		Index = TargetObjectRegistry.NiPSysUpdateCtlr_Registry.AddData();
	}
	if(TargetNodeType == "NiPSysFieldModifier")
	{
		Index = TargetObjectRegistry.NiPSysFieldModifier_Registry.AddData();
	}
	if(TargetNodeType == "NiPSysVortexFieldModifier")
	{
		Index = TargetObjectRegistry.NiPSysVortexFieldModifier_Registry.AddData();
	}
	if(TargetNodeType == "NiPSysGravityFieldModifier")
	{
		Index = TargetObjectRegistry.NiPSysGravityFieldModifier_Registry.AddData();
	}
	if(TargetNodeType == "NiPSysDragFieldModifier")
	{
		Index = TargetObjectRegistry.NiPSysDragFieldModifier_Registry.AddData();
	}
	if(TargetNodeType == "NiPSysTurbulenceFieldModifier")
	{
		Index = TargetObjectRegistry.NiPSysTurbulenceFieldModifier_Registry.AddData();
	}
	if(TargetNodeType == "BSPSysLODModifier")
	{
		Index = TargetObjectRegistry.BSPSysLODModifier_Registry.AddData();
	}
	if(TargetNodeType == "BSPSysScaleModifier")
	{
		Index = TargetObjectRegistry.BSPSysScaleModifier_Registry.AddData();
	}
	if(TargetNodeType == "NiPSysFieldMagnitudeCtlr")
	{
		Index = TargetObjectRegistry.NiPSysFieldMagnitudeCtlr_Registry.AddData();
	}
	if(TargetNodeType == "NiPSysFieldAttenuationCtlr")
	{
		Index = TargetObjectRegistry.NiPSysFieldAttenuationCtlr_Registry.AddData();
	}
	if(TargetNodeType == "NiPSysFieldMaxDistanceCtlr")
	{
		Index = TargetObjectRegistry.NiPSysFieldMaxDistanceCtlr_Registry.AddData();
	}
	if(TargetNodeType == "NiPSysAirFieldAirFrictionCtlr")
	{
		Index = TargetObjectRegistry.NiPSysAirFieldAirFrictionCtlr_Registry.AddData();
	}
	if(TargetNodeType == "NiPSysAirFieldInheritVelocityCtlr")
	{
		Index = TargetObjectRegistry.NiPSysAirFieldInheritVelocityCtlr_Registry.AddData();
	}
	if(TargetNodeType == "NiPSysAirFieldSpreadCtlr")
	{
		Index = TargetObjectRegistry.NiPSysAirFieldSpreadCtlr_Registry.AddData();
	}
	if(TargetNodeType == "NiPSysInitialRotSpeedCtlr")
	{
		Index = TargetObjectRegistry.NiPSysInitialRotSpeedCtlr_Registry.AddData();
	}
	if(TargetNodeType == "NiPSysInitialRotSpeedVarCtlr")
	{
		Index = TargetObjectRegistry.NiPSysInitialRotSpeedVarCtlr_Registry.AddData();
	}
	if(TargetNodeType == "NiPSysInitialRotAngleCtlr")
	{
		Index = TargetObjectRegistry.NiPSysInitialRotAngleCtlr_Registry.AddData();
	}
	if(TargetNodeType == "NiPSysInitialRotAngleVarCtlr")
	{
		Index = TargetObjectRegistry.NiPSysInitialRotAngleVarCtlr_Registry.AddData();
	}
	if(TargetNodeType == "NiPSysEmitterPlanarAngleCtlr")
	{
		Index = TargetObjectRegistry.NiPSysEmitterPlanarAngleCtlr_Registry.AddData();
	}
	if(TargetNodeType == "NiPSysEmitterPlanarAngleVarCtlr")
	{
		Index = TargetObjectRegistry.NiPSysEmitterPlanarAngleVarCtlr_Registry.AddData();
	}
	if(TargetNodeType == "NiPSysAirFieldModifier")
	{
		Index = TargetObjectRegistry.NiPSysAirFieldModifier_Registry.AddData();
	}
	if(TargetNodeType == "NiPSysTrailEmitter")
	{
		Index = TargetObjectRegistry.NiPSysTrailEmitter_Registry.AddData();
	}
	if(TargetNodeType == "NiLightIntensityController")
	{
		Index = TargetObjectRegistry.NiLightIntensityController_Registry.AddData();
	}
	if(TargetNodeType == "NiPSysRadialFieldModifier")
	{
		Index = TargetObjectRegistry.NiPSysRadialFieldModifier_Registry.AddData();
	}
	if(TargetNodeType == "NiLODData")
	{
		Index = TargetObjectRegistry.NiLODData_Registry.AddData();
	}
	if(TargetNodeType == "NiRangeLODData")
	{
		Index = TargetObjectRegistry.NiRangeLODData_Registry.AddData();
	}
	if(TargetNodeType == "NiScreenLODData")
	{
		Index = TargetObjectRegistry.NiScreenLODData_Registry.AddData();
	}
	if(TargetNodeType == "NiRotatingParticles")
	{
		Index = TargetObjectRegistry.NiRotatingParticles_Registry.AddData();
	}
	if(TargetNodeType == "NiSequenceStreamHelper")
	{
		Index = TargetObjectRegistry.NiSequenceStreamHelper_Registry.AddData();
	}
	if(TargetNodeType == "NiShadeProperty")
	{
		Index = TargetObjectRegistry.NiShadeProperty_Registry.AddData();
	}
	if(TargetNodeType == "NiSkinData")
	{
		Index = TargetObjectRegistry.NiSkinData_Registry.AddData();
	}
	if(TargetNodeType == "NiSkinInstance")
	{
		Index = TargetObjectRegistry.NiSkinInstance_Registry.AddData();
	}
	if(TargetNodeType == "NiTriShapeSkinController")
	{
		Index = TargetObjectRegistry.NiTriShapeSkinController_Registry.AddData();
	}
	if(TargetNodeType == "NiClodSkinInstance")
	{
		Index = TargetObjectRegistry.NiClodSkinInstance_Registry.AddData();
	}
	if(TargetNodeType == "NiSkinPartition")
	{
		Index = TargetObjectRegistry.NiSkinPartition_Registry.AddData();
	}
	if(TargetNodeType == "NiTexture")
	{
		Index = TargetObjectRegistry.NiTexture_Registry.AddData();
	}
	if(TargetNodeType == "NiSourceTexture")
	{
		Index = TargetObjectRegistry.NiSourceTexture_Registry.AddData();
	}
	if(TargetNodeType == "NiSpecularProperty")
	{
		Index = TargetObjectRegistry.NiSpecularProperty_Registry.AddData();
	}
	if(TargetNodeType == "NiSphericalCollider")
	{
		Index = TargetObjectRegistry.NiSphericalCollider_Registry.AddData();
	}
	if(TargetNodeType == "NiSpotLight")
	{
		Index = TargetObjectRegistry.NiSpotLight_Registry.AddData();
	}
	if(TargetNodeType == "NiStencilProperty")
	{
		Index = TargetObjectRegistry.NiStencilProperty_Registry.AddData();
	}
	if(TargetNodeType == "NiStringExtraData")
	{
		Index = TargetObjectRegistry.NiStringExtraData_Registry.AddData();
	}
	if(TargetNodeType == "NiStringPalette")
	{
		Index = TargetObjectRegistry.NiStringPalette_Registry.AddData();
	}
	if(TargetNodeType == "NiStringsExtraData")
	{
		Index = TargetObjectRegistry.NiStringsExtraData_Registry.AddData();
	}
	if(TargetNodeType == "NiTextKeyExtraData")
	{
		Index = TargetObjectRegistry.NiTextKeyExtraData_Registry.AddData();
	}
	if(TargetNodeType == "NiTextureEffect")
	{
		Index = TargetObjectRegistry.NiTextureEffect_Registry.AddData();
	}
	if(TargetNodeType == "NiTextureModeProperty")
	{
		Index = TargetObjectRegistry.NiTextureModeProperty_Registry.AddData();
	}
	if(TargetNodeType == "NiImage")
	{
		Index = TargetObjectRegistry.NiImage_Registry.AddData();
	}
	if(TargetNodeType == "NiTextureProperty")
	{
		Index = TargetObjectRegistry.NiTextureProperty_Registry.AddData();
	}
	if(TargetNodeType == "NiMultiTextureProperty")
	{
		Index = TargetObjectRegistry.NiMultiTextureProperty_Registry.AddData();
	}
	if(TargetNodeType == "NiTexturingProperty")
	{
		Index = TargetObjectRegistry.NiTexturingProperty_Registry.AddData();
	}
	if(TargetNodeType == "NiTransformData")
	{
		Index = TargetObjectRegistry.NiTransformData_Registry.AddData();
	}
	if(TargetNodeType == "NiTriShape")
	{
		Index = TargetObjectRegistry.NiTriShape_Registry.AddData();
	}
	if(TargetNodeType == "NiTriShapeData")
	{
		Index = TargetObjectRegistry.NiTriShapeData_Registry.AddData();
	}
	if(TargetNodeType == "NiTriStrips")
	{
		Index = TargetObjectRegistry.NiTriStrips_Registry.AddData();
	}
	if(TargetNodeType == "NiTriStripsData")
	{
		Index = TargetObjectRegistry.NiTriStripsData_Registry.AddData();
	}
	if(TargetNodeType == "NiEnvMappedTriShape")
	{
		Index = TargetObjectRegistry.NiEnvMappedTriShape_Registry.AddData();
	}
	if(TargetNodeType == "NiEnvMappedTriShapeData")
	{
		Index = TargetObjectRegistry.NiEnvMappedTriShapeData_Registry.AddData();
	}
	if(TargetNodeType == "NiBezierTriangle4")
	{
		Index = TargetObjectRegistry.NiBezierTriangle4_Registry.AddData();
	}
	if(TargetNodeType == "NiBezierMesh")
	{
		Index = TargetObjectRegistry.NiBezierMesh_Registry.AddData();
	}
	if(TargetNodeType == "NiClod")
	{
		Index = TargetObjectRegistry.NiClod_Registry.AddData();
	}
	if(TargetNodeType == "NiClodData")
	{
		Index = TargetObjectRegistry.NiClodData_Registry.AddData();
	}
	if(TargetNodeType == "NiUVController")
	{
		Index = TargetObjectRegistry.NiUVController_Registry.AddData();
	}
	if(TargetNodeType == "NiUVData")
	{
		Index = TargetObjectRegistry.NiUVData_Registry.AddData();
	}
	if(TargetNodeType == "NiVectorExtraData")
	{
		Index = TargetObjectRegistry.NiVectorExtraData_Registry.AddData();
	}
	if(TargetNodeType == "NiVertexColorProperty")
	{
		Index = TargetObjectRegistry.NiVertexColorProperty_Registry.AddData();
	}
	if(TargetNodeType == "NiVertWeightsExtraData")
	{
		Index = TargetObjectRegistry.NiVertWeightsExtraData_Registry.AddData();
	}
	if(TargetNodeType == "NiVisData")
	{
		Index = TargetObjectRegistry.NiVisData_Registry.AddData();
	}
	if(TargetNodeType == "NiWireframeProperty")
	{
		Index = TargetObjectRegistry.NiWireframeProperty_Registry.AddData();
	}
	if(TargetNodeType == "NiZBufferProperty")
	{
		Index = TargetObjectRegistry.NiZBufferProperty_Registry.AddData();
	}
	if(TargetNodeType == "RootCollisionNode")
	{
		Index = TargetObjectRegistry.RootCollisionNode_Registry.AddData();
	}
	if(TargetNodeType == "NiRawImageData")
	{
		Index = TargetObjectRegistry.NiRawImageData_Registry.AddData();
	}
	if(TargetNodeType == "NiSortAdjustNode")
	{
		Index = TargetObjectRegistry.NiSortAdjustNode_Registry.AddData();
	}
	if(TargetNodeType == "NiSourceCubeMap")
	{
		Index = TargetObjectRegistry.NiSourceCubeMap_Registry.AddData();
	}
	if(TargetNodeType == "NiPhysXProp")
	{
		Index = TargetObjectRegistry.NiPhysXProp_Registry.AddData();
	}
	if(TargetNodeType == "NiPhysXPropDesc")
	{
		Index = TargetObjectRegistry.NiPhysXPropDesc_Registry.AddData();
	}
	if(TargetNodeType == "NiPhysXActorDesc")
	{
		Index = TargetObjectRegistry.NiPhysXActorDesc_Registry.AddData();
	}
	if(TargetNodeType == "NiPhysXBodyDesc")
	{
		Index = TargetObjectRegistry.NiPhysXBodyDesc_Registry.AddData();
	}
	if(TargetNodeType == "NiPhysXD6JointDesc")
	{
		Index = TargetObjectRegistry.NiPhysXD6JointDesc_Registry.AddData();
	}
	if(TargetNodeType == "NiPhysXShapeDesc")
	{
		Index = TargetObjectRegistry.NiPhysXShapeDesc_Registry.AddData();
	}
	if(TargetNodeType == "NiPhysXMeshDesc")
	{
		Index = TargetObjectRegistry.NiPhysXMeshDesc_Registry.AddData();
	}
	if(TargetNodeType == "NiPhysXMaterialDesc")
	{
		Index = TargetObjectRegistry.NiPhysXMaterialDesc_Registry.AddData();
	}
	if(TargetNodeType == "NiPhysXKinematicSrc")
	{
		Index = TargetObjectRegistry.NiPhysXKinematicSrc_Registry.AddData();
	}
	if(TargetNodeType == "NiPhysXTransformDest")
	{
		Index = TargetObjectRegistry.NiPhysXTransformDest_Registry.AddData();
	}
	if(TargetNodeType == "NiArkAnimationExtraData")
	{
		Index = TargetObjectRegistry.NiArkAnimationExtraData_Registry.AddData();
	}
	if(TargetNodeType == "NiArkImporterExtraData")
	{
		Index = TargetObjectRegistry.NiArkImporterExtraData_Registry.AddData();
	}
	if(TargetNodeType == "NiArkTextureExtraData")
	{
		Index = TargetObjectRegistry.NiArkTextureExtraData_Registry.AddData();
	}
	if(TargetNodeType == "NiArkViewportInfoExtraData")
	{
		Index = TargetObjectRegistry.NiArkViewportInfoExtraData_Registry.AddData();
	}
	if(TargetNodeType == "NiArkShaderExtraData")
	{
		Index = TargetObjectRegistry.NiArkShaderExtraData_Registry.AddData();
	}
	if(TargetNodeType == "NiLines")
	{
		Index = TargetObjectRegistry.NiLines_Registry.AddData();
	}
	if(TargetNodeType == "NiLinesData")
	{
		Index = TargetObjectRegistry.NiLinesData_Registry.AddData();
	}
	if(TargetNodeType == "NiScreenElementsData")
	{
		Index = TargetObjectRegistry.NiScreenElementsData_Registry.AddData();
	}
	if(TargetNodeType == "NiScreenElements")
	{
		Index = TargetObjectRegistry.NiScreenElements_Registry.AddData();
	}
	if(TargetNodeType == "NiRoomGroup")
	{
		Index = TargetObjectRegistry.NiRoomGroup_Registry.AddData();
	}
	if(TargetNodeType == "NiRoom")
	{
		Index = TargetObjectRegistry.NiRoom_Registry.AddData();
	}
	if(TargetNodeType == "NiPortal")
	{
		Index = TargetObjectRegistry.NiPortal_Registry.AddData();
	}
	if(TargetNodeType == "BSFadeNode")
	{
		Index = TargetObjectRegistry.BSFadeNode_Registry.AddData();
	}
	if(TargetNodeType == "BSShaderProperty")
	{
		Index = TargetObjectRegistry.BSShaderProperty_Registry.AddData();
	}
	if(TargetNodeType == "BSShaderLightingProperty")
	{
		Index = TargetObjectRegistry.BSShaderLightingProperty_Registry.AddData();
	}
	if(TargetNodeType == "BSShaderNoLightingProperty")
	{
		Index = TargetObjectRegistry.BSShaderNoLightingProperty_Registry.AddData();
	}
	if(TargetNodeType == "BSShaderPPLightingProperty")
	{
		Index = TargetObjectRegistry.BSShaderPPLightingProperty_Registry.AddData();
	}
	if(TargetNodeType == "BSEffectShaderPropertyFloatController")
	{
		Index = TargetObjectRegistry.BSEffectShaderPropertyFloatController_Registry.AddData();
	}
	if(TargetNodeType == "BSEffectShaderPropertyColorController")
	{
		Index = TargetObjectRegistry.BSEffectShaderPropertyColorController_Registry.AddData();
	}
	if(TargetNodeType == "BSLightingShaderPropertyFloatController")
	{
		Index = TargetObjectRegistry.BSLightingShaderPropertyFloatController_Registry.AddData();
	}
	if(TargetNodeType == "BSLightingShaderPropertyColorController")
	{
		Index = TargetObjectRegistry.BSLightingShaderPropertyColorController_Registry.AddData();
	}
	if(TargetNodeType == "BSNiAlphaPropertyTestRefController")
	{
		Index = TargetObjectRegistry.BSNiAlphaPropertyTestRefController_Registry.AddData();
	}
	if(TargetNodeType == "BSProceduralLightningController")
	{
		Index = TargetObjectRegistry.BSProceduralLightningController_Registry.AddData();
	}
	if(TargetNodeType == "BSShaderTextureSet")
	{
		Index = TargetObjectRegistry.BSShaderTextureSet_Registry.AddData();
	}
	if(TargetNodeType == "WaterShaderProperty")
	{
		Index = TargetObjectRegistry.WaterShaderProperty_Registry.AddData();
	}
	if(TargetNodeType == "SkyShaderProperty")
	{
		Index = TargetObjectRegistry.SkyShaderProperty_Registry.AddData();
	}
	if(TargetNodeType == "TileShaderProperty")
	{
		Index = TargetObjectRegistry.TileShaderProperty_Registry.AddData();
	}
	if(TargetNodeType == "DistantLODShaderProperty")
	{
		Index = TargetObjectRegistry.DistantLODShaderProperty_Registry.AddData();
	}
	if(TargetNodeType == "BSDistantTreeShaderProperty")
	{
		Index = TargetObjectRegistry.BSDistantTreeShaderProperty_Registry.AddData();
	}
	if(TargetNodeType == "TallGrassShaderProperty")
	{
		Index = TargetObjectRegistry.TallGrassShaderProperty_Registry.AddData();
	}
	if(TargetNodeType == "VolumetricFogShaderProperty")
	{
		Index = TargetObjectRegistry.VolumetricFogShaderProperty_Registry.AddData();
	}
	if(TargetNodeType == "HairShaderProperty")
	{
		Index = TargetObjectRegistry.HairShaderProperty_Registry.AddData();
	}
	if(TargetNodeType == "Lighting30ShaderProperty")
	{
		Index = TargetObjectRegistry.Lighting30ShaderProperty_Registry.AddData();
	}
	if(TargetNodeType == "BSLightingShaderProperty")
	{
		Index = TargetObjectRegistry.BSLightingShaderProperty_Registry.AddData();
	}
	if(TargetNodeType == "BSEffectShaderProperty")
	{
		Index = TargetObjectRegistry.BSEffectShaderProperty_Registry.AddData();
	}
	if(TargetNodeType == "BSWaterShaderProperty")
	{
		Index = TargetObjectRegistry.BSWaterShaderProperty_Registry.AddData();
	}
	if(TargetNodeType == "BSSkyShaderProperty")
	{
		Index = TargetObjectRegistry.BSSkyShaderProperty_Registry.AddData();
	}
	if(TargetNodeType == "BSDismemberSkinInstance")
	{
		Index = TargetObjectRegistry.BSDismemberSkinInstance_Registry.AddData();
	}
	if(TargetNodeType == "BSDecalPlacementVectorExtraData")
	{
		Index = TargetObjectRegistry.BSDecalPlacementVectorExtraData_Registry.AddData();
	}
	if(TargetNodeType == "BSPSysSimpleColorModifier")
	{
		Index = TargetObjectRegistry.BSPSysSimpleColorModifier_Registry.AddData();
	}
	if(TargetNodeType == "BSValueNode")
	{
		Index = TargetObjectRegistry.BSValueNode_Registry.AddData();
	}
	if(TargetNodeType == "BSStripParticleSystem")
	{
		Index = TargetObjectRegistry.BSStripParticleSystem_Registry.AddData();
	}
	if(TargetNodeType == "BSStripPSysData")
	{
		Index = TargetObjectRegistry.BSStripPSysData_Registry.AddData();
	}
	if(TargetNodeType == "BSPSysStripUpdateModifier")
	{
		Index = TargetObjectRegistry.BSPSysStripUpdateModifier_Registry.AddData();
	}
	if(TargetNodeType == "BSMaterialEmittanceMultController")
	{
		Index = TargetObjectRegistry.BSMaterialEmittanceMultController_Registry.AddData();
	}
	if(TargetNodeType == "BSMasterParticleSystem")
	{
		Index = TargetObjectRegistry.BSMasterParticleSystem_Registry.AddData();
	}
	if(TargetNodeType == "BSPSysMultiTargetEmitterCtlr")
	{
		Index = TargetObjectRegistry.BSPSysMultiTargetEmitterCtlr_Registry.AddData();
	}
	if(TargetNodeType == "BSRefractionStrengthController")
	{
		Index = TargetObjectRegistry.BSRefractionStrengthController_Registry.AddData();
	}
	if(TargetNodeType == "BSOrderedNode")
	{
		Index = TargetObjectRegistry.BSOrderedNode_Registry.AddData();
	}
	if(TargetNodeType == "BSBlastNode")
	{
		Index = TargetObjectRegistry.BSBlastNode_Registry.AddData();
	}
	if(TargetNodeType == "BSDamageStage")
	{
		Index = TargetObjectRegistry.BSDamageStage_Registry.AddData();
	}
	if(TargetNodeType == "BSRefractionFirePeriodController")
	{
		Index = TargetObjectRegistry.BSRefractionFirePeriodController_Registry.AddData();
	}
	if(TargetNodeType == "bhkConvexListShape")
	{
		Index = TargetObjectRegistry.bhkConvexListShape_Registry.AddData();
	}
	if(TargetNodeType == "BSTreadTransfInterpolator")
	{
		Index = TargetObjectRegistry.BSTreadTransfInterpolator_Registry.AddData();
	}
	if(TargetNodeType == "BSAnimNotes")
	{
		Index = TargetObjectRegistry.BSAnimNotes_Registry.AddData();
	}
	if(TargetNodeType == "bhkLiquidAction")
	{
		Index = TargetObjectRegistry.bhkLiquidAction_Registry.AddData();
	}
	if(TargetNodeType == "BSMultiBoundNode")
	{
		Index = TargetObjectRegistry.BSMultiBoundNode_Registry.AddData();
	}
	if(TargetNodeType == "BSMultiBound")
	{
		Index = TargetObjectRegistry.BSMultiBound_Registry.AddData();
	}
	if(TargetNodeType == "BSMultiBoundData")
	{
		Index = TargetObjectRegistry.BSMultiBoundData_Registry.AddData();
	}
	if(TargetNodeType == "BSMultiBoundOBB")
	{
		Index = TargetObjectRegistry.BSMultiBoundOBB_Registry.AddData();
	}
	if(TargetNodeType == "BSMultiBoundSphere")
	{
		Index = TargetObjectRegistry.BSMultiBoundSphere_Registry.AddData();
	}
	if(TargetNodeType == "BSSegmentedTriShape")
	{
		Index = TargetObjectRegistry.BSSegmentedTriShape_Registry.AddData();
	}
	if(TargetNodeType == "BSMultiBoundAABB")
	{
		Index = TargetObjectRegistry.BSMultiBoundAABB_Registry.AddData();
	}
	if(TargetNodeType == "NiAdditionalGeometryData")
	{
		Index = TargetObjectRegistry.NiAdditionalGeometryData_Registry.AddData();
	}
	if(TargetNodeType == "BSPackedAdditionalGeometryData")
	{
		Index = TargetObjectRegistry.BSPackedAdditionalGeometryData_Registry.AddData();
	}
	if(TargetNodeType == "BSWArray")
	{
		Index = TargetObjectRegistry.BSWArray_Registry.AddData();
	}
	if(TargetNodeType == "bhkAabbPhantom")
	{
		Index = TargetObjectRegistry.bhkAabbPhantom_Registry.AddData();
	}
	if(TargetNodeType == "BSFrustumFOVController")
	{
		Index = TargetObjectRegistry.BSFrustumFOVController_Registry.AddData();
	}
	if(TargetNodeType == "BSDebrisNode")
	{
		Index = TargetObjectRegistry.BSDebrisNode_Registry.AddData();
	}
	if(TargetNodeType == "bhkBreakableConstraint")
	{
		Index = TargetObjectRegistry.bhkBreakableConstraint_Registry.AddData();
	}
	if(TargetNodeType == "bhkOrientHingedBodyAction")
	{
		Index = TargetObjectRegistry.bhkOrientHingedBodyAction_Registry.AddData();
	}
	if(TargetNodeType == "NiDataStream")
	{
		Index = TargetObjectRegistry.NiDataStream_Registry.AddData();
	}
	if(TargetNodeType == "NiRenderObject")
	{
		Index = TargetObjectRegistry.NiRenderObject_Registry.AddData();
	}
	if(TargetNodeType == "NiMeshModifier")
	{
		Index = TargetObjectRegistry.NiMeshModifier_Registry.AddData();
	}
	if(TargetNodeType == "NiMesh")
	{
		Index = TargetObjectRegistry.NiMesh_Registry.AddData();
	}
	if(TargetNodeType == "NiMorphWeightsController")
	{
		Index = TargetObjectRegistry.NiMorphWeightsController_Registry.AddData();
	}
	if(TargetNodeType == "NiMorphMeshModifier")
	{
		Index = TargetObjectRegistry.NiMorphMeshModifier_Registry.AddData();
	}
	if(TargetNodeType == "NiSkinningMeshModifier")
	{
		Index = TargetObjectRegistry.NiSkinningMeshModifier_Registry.AddData();
	}
	if(TargetNodeType == "NiInstancingMeshModifier")
	{
		Index = TargetObjectRegistry.NiInstancingMeshModifier_Registry.AddData();
	}
	if(TargetNodeType == "NiSkinningLODController")
	{
		Index = TargetObjectRegistry.NiSkinningLODController_Registry.AddData();
	}
	if(TargetNodeType == "NiPSParticleSystem")
	{
		Index = TargetObjectRegistry.NiPSParticleSystem_Registry.AddData();
	}
	if(TargetNodeType == "NiPSMeshParticleSystem")
	{
		Index = TargetObjectRegistry.NiPSMeshParticleSystem_Registry.AddData();
	}
	if(TargetNodeType == "NiPSEmitParticlesCtlr")
	{
		Index = TargetObjectRegistry.NiPSEmitParticlesCtlr_Registry.AddData();
	}
	if(TargetNodeType == "NiPSForceActiveCtlr")
	{
		Index = TargetObjectRegistry.NiPSForceActiveCtlr_Registry.AddData();
	}
	if(TargetNodeType == "NiPSSimulator")
	{
		Index = TargetObjectRegistry.NiPSSimulator_Registry.AddData();
	}
	if(TargetNodeType == "NiPSSimulatorStep")
	{
		Index = TargetObjectRegistry.NiPSSimulatorStep_Registry.AddData();
	}
	if(TargetNodeType == "NiPSSimulatorGeneralStep")
	{
		Index = TargetObjectRegistry.NiPSSimulatorGeneralStep_Registry.AddData();
	}
	if(TargetNodeType == "NiPSSimulatorForcesStep")
	{
		Index = TargetObjectRegistry.NiPSSimulatorForcesStep_Registry.AddData();
	}
	if(TargetNodeType == "NiPSSimulatorCollidersStep")
	{
		Index = TargetObjectRegistry.NiPSSimulatorCollidersStep_Registry.AddData();
	}
	if(TargetNodeType == "NiPSSimulatorMeshAlignStep")
	{
		Index = TargetObjectRegistry.NiPSSimulatorMeshAlignStep_Registry.AddData();
	}
	if(TargetNodeType == "NiPSSimulatorFinalStep")
	{
		Index = TargetObjectRegistry.NiPSSimulatorFinalStep_Registry.AddData();
	}
	if(TargetNodeType == "NiPSFacingQuadGenerator")
	{
		Index = TargetObjectRegistry.NiPSFacingQuadGenerator_Registry.AddData();
	}
	if(TargetNodeType == "NiShadowGenerator")
	{
		Index = TargetObjectRegistry.NiShadowGenerator_Registry.AddData();
	}
	if(TargetNodeType == "NiPSBoundUpdater")
	{
		Index = TargetObjectRegistry.NiPSBoundUpdater_Registry.AddData();
	}
	if(TargetNodeType == "NiPSDragForce")
	{
		Index = TargetObjectRegistry.NiPSDragForce_Registry.AddData();
	}
	if(TargetNodeType == "NiPSGravityForce")
	{
		Index = TargetObjectRegistry.NiPSGravityForce_Registry.AddData();
	}
	if(TargetNodeType == "NiPSBoxEmitter")
	{
		Index = TargetObjectRegistry.NiPSBoxEmitter_Registry.AddData();
	}
	if(TargetNodeType == "NiPSMeshEmitter")
	{
		Index = TargetObjectRegistry.NiPSMeshEmitter_Registry.AddData();
	}
	if(TargetNodeType == "NiPSGravityStrengthCtlr")
	{
		Index = TargetObjectRegistry.NiPSGravityStrengthCtlr_Registry.AddData();
	}
	if(TargetNodeType == "NiPSPlanarCollider")
	{
		Index = TargetObjectRegistry.NiPSPlanarCollider_Registry.AddData();
	}
	if(TargetNodeType == "NiPSEmitterSpeedCtlr")
	{
		Index = TargetObjectRegistry.NiPSEmitterSpeedCtlr_Registry.AddData();
	}
	if(TargetNodeType == "NiPSEmitterRadiusCtlr")
	{
		Index = TargetObjectRegistry.NiPSEmitterRadiusCtlr_Registry.AddData();
	}
	if(TargetNodeType == "NiPSResetOnLoopCtlr")
	{
		Index = TargetObjectRegistry.NiPSResetOnLoopCtlr_Registry.AddData();
	}
	if(TargetNodeType == "NiPSSphereEmitter")
	{
		Index = TargetObjectRegistry.NiPSSphereEmitter_Registry.AddData();
	}
	if(TargetNodeType == "NiPSCylinderEmitter")
	{
		Index = TargetObjectRegistry.NiPSCylinderEmitter_Registry.AddData();
	}
	if(TargetNodeType == "NiPSEmitterDeclinationCtlr")
	{
		Index = TargetObjectRegistry.NiPSEmitterDeclinationCtlr_Registry.AddData();
	}
	if(TargetNodeType == "NiPSEmitterDeclinationVarCtlr")
	{
		Index = TargetObjectRegistry.NiPSEmitterDeclinationVarCtlr_Registry.AddData();
	}
	if(TargetNodeType == "NiPSEmitterPlanarAngleCtlr")
	{
		Index = TargetObjectRegistry.NiPSEmitterPlanarAngleCtlr_Registry.AddData();
	}
	if(TargetNodeType == "NiPSEmitterPlanarAngleVarCtlr")
	{
		Index = TargetObjectRegistry.NiPSEmitterPlanarAngleVarCtlr_Registry.AddData();
	}
	if(TargetNodeType == "NiPSEmitterRotAngleCtlr")
	{
		Index = TargetObjectRegistry.NiPSEmitterRotAngleCtlr_Registry.AddData();
	}
	if(TargetNodeType == "NiPSEmitterRotAngleVarCtlr")
	{
		Index = TargetObjectRegistry.NiPSEmitterRotAngleVarCtlr_Registry.AddData();
	}
	if(TargetNodeType == "NiPSEmitterRotSpeedCtlr")
	{
		Index = TargetObjectRegistry.NiPSEmitterRotSpeedCtlr_Registry.AddData();
	}
	if(TargetNodeType == "NiPSEmitterRotSpeedVarCtlr")
	{
		Index = TargetObjectRegistry.NiPSEmitterRotSpeedVarCtlr_Registry.AddData();
	}
	if(TargetNodeType == "NiPSEmitterLifeSpanCtlr")
	{
		Index = TargetObjectRegistry.NiPSEmitterLifeSpanCtlr_Registry.AddData();
	}
	if(TargetNodeType == "NiPSBombForce")
	{
		Index = TargetObjectRegistry.NiPSBombForce_Registry.AddData();
	}
	if(TargetNodeType == "NiPSSphericalCollider")
	{
		Index = TargetObjectRegistry.NiPSSphericalCollider_Registry.AddData();
	}
	if(TargetNodeType == "NiPSSpawner")
	{
		Index = TargetObjectRegistry.NiPSSpawner_Registry.AddData();
	}
	if(TargetNodeType == "NiSequenceData")
	{
		Index = TargetObjectRegistry.NiSequenceData_Registry.AddData();
	}
	if(TargetNodeType == "NiTransformEvaluator")
	{
		Index = TargetObjectRegistry.NiTransformEvaluator_Registry.AddData();
	}
	if(TargetNodeType == "NiBSplineCompTransformEvaluator")
	{
		Index = TargetObjectRegistry.NiBSplineCompTransformEvaluator_Registry.AddData();
	}
	if(TargetNodeType == "NiMeshHWInstance")
	{
		Index = TargetObjectRegistry.NiMeshHWInstance_Registry.AddData();
	}
	if(TargetNodeType == "NiFurSpringController")
	{
		Index = TargetObjectRegistry.NiFurSpringController_Registry.AddData();
	}
	if(TargetNodeType == "CStreamableAssetData")
	{
		Index = TargetObjectRegistry.CStreamableAssetData_Registry.AddData();
	}
	if(TargetNodeType == "bhkCompressedMeshShape")
	{
		Index = TargetObjectRegistry.bhkCompressedMeshShape_Registry.AddData();
	}
	if(TargetNodeType == "bhkCompressedMeshShapeData")
	{
		Index = TargetObjectRegistry.bhkCompressedMeshShapeData_Registry.AddData();
	}
	if(TargetNodeType == "BSInvMarker")
	{
		Index = TargetObjectRegistry.BSInvMarker_Registry.AddData();
	}
	if(TargetNodeType == "BSBoneLODExtraData")
	{
		Index = TargetObjectRegistry.BSBoneLODExtraData_Registry.AddData();
	}
	if(TargetNodeType == "BSBehaviorGraphExtraData")
	{
		Index = TargetObjectRegistry.BSBehaviorGraphExtraData_Registry.AddData();
	}
	if(TargetNodeType == "BSLagBoneController")
	{
		Index = TargetObjectRegistry.BSLagBoneController_Registry.AddData();
	}
	if(TargetNodeType == "BSLODTriShape")
	{
		Index = TargetObjectRegistry.BSLODTriShape_Registry.AddData();
	}
	if(TargetNodeType == "BSFurnitureMarkerNode")
	{
		Index = TargetObjectRegistry.BSFurnitureMarkerNode_Registry.AddData();
	}
	if(TargetNodeType == "BSLeafAnimNode")
	{
		Index = TargetObjectRegistry.BSLeafAnimNode_Registry.AddData();
	}
	if(TargetNodeType == "BSTreeNode")
	{
		Index = TargetObjectRegistry.BSTreeNode_Registry.AddData();
	}
	if(TargetNodeType == "NiLightRadiusController")
	{
		Index = TargetObjectRegistry.NiLightRadiusController_Registry.AddData();
	}
	if(TargetNodeType == "BSShape")
	{
		Index = TargetObjectRegistry.BSShape_Registry.AddData();
	}
	if(TargetNodeType == "BSTriShape")
	{
		Index = TargetObjectRegistry.BSTriShape_Registry.AddData();
	}
	if(TargetNodeType == "BSSubIndexTriShape")
	{
		Index = TargetObjectRegistry.BSSubIndexTriShape_Registry.AddData();
	}
	if(TargetNodeType == "BSMeshLODTriShape")
	{
		Index = TargetObjectRegistry.BSMeshLODTriShape_Registry.AddData();
	}
	if(TargetNodeType == "bhkNPCollisionObject")
	{
		Index = TargetObjectRegistry.bhkNPCollisionObject_Registry.AddData();
	}
	if(TargetNodeType == "BSExtraData")
	{
		Index = TargetObjectRegistry.BSExtraData_Registry.AddData();
	}
	if(TargetNodeType == "bhkPhysicsSystem")
	{
		Index = TargetObjectRegistry.bhkPhysicsSystem_Registry.AddData();
	}
	if(TargetNodeType == "bhkRagdollSystem")
	{
		Index = TargetObjectRegistry.bhkRagdollSystem_Registry.AddData();
	}
	if(TargetNodeType == "BSClothExtraData")
	{
		Index = TargetObjectRegistry.BSClothExtraData_Registry.AddData();
	}
	if(TargetNodeType == "BSSkin__Instance")
	{
		Index = TargetObjectRegistry.BSSkin__Instance_Registry.AddData();
	}
	if(TargetNodeType == "BSSkin__BoneData")
	{
		Index = TargetObjectRegistry.BSSkin__BoneData_Registry.AddData();
	}
	if(TargetNodeType == "BSPositionData")
	{
		Index = TargetObjectRegistry.BSPositionData_Registry.AddData();
	}
	if(TargetNodeType == "BSConnectPoint__Parents")
	{
		Index = TargetObjectRegistry.BSConnectPoint__Parents_Registry.AddData();
	}
	if(TargetNodeType == "BSConnectPoint__Children")
	{
		Index = TargetObjectRegistry.BSConnectPoint__Children_Registry.AddData();
	}
	FixCurrentNodeData();
	CurrentNode->IndexInRegistry = Index;
}

void NifNodeTreeData::NifNode::DestroyNodeData(ObjectRegistry* TargetObjectRegistry)
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
