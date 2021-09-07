#include "NifNodeTree.h"
#include "..\niflib\include\ObjectRegistry.h"
#include "..\SharedCode\SharedCode_StringFunctions\StringFunctions.h"
#include <typeinfo>

void NifNodeTreeData::NifNodeTree::AddNodeToTree(std::string TargetNodeType, std::string TargetMenuMaster, std::string SpecialModifier/* = ""*/, std::string ItemName/* = ""*/, std::string InternalName/* = ""*/)
{
	AddMenuItemData(TargetMenuMaster, SpecialModifier, ItemName, InternalName);
	FixCurrentNodeData();
	CurrentNode->NodeType = TargetNodeType;
	size_t Index;
	//Now add actual node to ObjectRegistry(ObjectRegistry Section)
	if(TargetNodeType == "NiObject")
	{
		Index = TargetObjectRegistry.NiObject_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "Ni3dsAlphaAnimator")
	{
		Index = TargetObjectRegistry.Ni3dsAlphaAnimator_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "Ni3dsAnimationNode")
	{
		Index = TargetObjectRegistry.Ni3dsAnimationNode_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "Ni3dsColorAnimator")
	{
		Index = TargetObjectRegistry.Ni3dsColorAnimator_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "Ni3dsMorphShape")
	{
		Index = TargetObjectRegistry.Ni3dsMorphShape_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "Ni3dsParticleSystem")
	{
		Index = TargetObjectRegistry.Ni3dsParticleSystem_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "Ni3dsPathController")
	{
		Index = TargetObjectRegistry.Ni3dsPathController_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiParticleModifier")
	{
		Index = TargetObjectRegistry.NiParticleModifier_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiPSysCollider")
	{
		Index = TargetObjectRegistry.NiPSysCollider_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "bhkRefObject")
	{
		Index = TargetObjectRegistry.bhkRefObject_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "bhkSerializable")
	{
		Index = TargetObjectRegistry.bhkSerializable_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "bhkWorldObject")
	{
		Index = TargetObjectRegistry.bhkWorldObject_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "bhkPhantom")
	{
		Index = TargetObjectRegistry.bhkPhantom_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "bhkShapePhantom")
	{
		Index = TargetObjectRegistry.bhkShapePhantom_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "bhkSimpleShapePhantom")
	{
		Index = TargetObjectRegistry.bhkSimpleShapePhantom_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "bhkEntity")
	{
		Index = TargetObjectRegistry.bhkEntity_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "bhkRigidBody")
	{
		Index = TargetObjectRegistry.bhkRigidBody_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "bhkRigidBodyT")
	{
		Index = TargetObjectRegistry.bhkRigidBodyT_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "bhkConstraint")
	{
		Index = TargetObjectRegistry.bhkConstraint_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "bhkLimitedHingeConstraint")
	{
		Index = TargetObjectRegistry.bhkLimitedHingeConstraint_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "bhkMalleableConstraint")
	{
		Index = TargetObjectRegistry.bhkMalleableConstraint_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "bhkStiffSpringConstraint")
	{
		Index = TargetObjectRegistry.bhkStiffSpringConstraint_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "bhkRagdollConstraint")
	{
		Index = TargetObjectRegistry.bhkRagdollConstraint_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "bhkPrismaticConstraint")
	{
		Index = TargetObjectRegistry.bhkPrismaticConstraint_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "bhkHingeConstraint")
	{
		Index = TargetObjectRegistry.bhkHingeConstraint_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "bhkBallAndSocketConstraint")
	{
		Index = TargetObjectRegistry.bhkBallAndSocketConstraint_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "bhkBallSocketConstraintChain")
	{
		Index = TargetObjectRegistry.bhkBallSocketConstraintChain_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "bhkShape")
	{
		Index = TargetObjectRegistry.bhkShape_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "bhkTransformShape")
	{
		Index = TargetObjectRegistry.bhkTransformShape_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "bhkSphereRepShape")
	{
		Index = TargetObjectRegistry.bhkSphereRepShape_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "bhkConvexShape")
	{
		Index = TargetObjectRegistry.bhkConvexShape_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "bhkSphereShape")
	{
		Index = TargetObjectRegistry.bhkSphereShape_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "bhkCapsuleShape")
	{
		Index = TargetObjectRegistry.bhkCapsuleShape_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "bhkBoxShape")
	{
		Index = TargetObjectRegistry.bhkBoxShape_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "bhkConvexVerticesShape")
	{
		Index = TargetObjectRegistry.bhkConvexVerticesShape_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "bhkConvexTransformShape")
	{
		Index = TargetObjectRegistry.bhkConvexTransformShape_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "bhkMultiSphereShape")
	{
		Index = TargetObjectRegistry.bhkMultiSphereShape_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "bhkBvTreeShape")
	{
		Index = TargetObjectRegistry.bhkBvTreeShape_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "bhkMoppBvTreeShape")
	{
		Index = TargetObjectRegistry.bhkMoppBvTreeShape_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "bhkShapeCollection")
	{
		Index = TargetObjectRegistry.bhkShapeCollection_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "bhkListShape")
	{
		Index = TargetObjectRegistry.bhkListShape_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "bhkMeshShape")
	{
		Index = TargetObjectRegistry.bhkMeshShape_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "bhkPackedNiTriStripsShape")
	{
		Index = TargetObjectRegistry.bhkPackedNiTriStripsShape_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "bhkNiTriStripsShape")
	{
		Index = TargetObjectRegistry.bhkNiTriStripsShape_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiExtraData")
	{
		Index = TargetObjectRegistry.NiExtraData_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiInterpolator")
	{
		Index = TargetObjectRegistry.NiInterpolator_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiKeyBasedInterpolator")
	{
		Index = TargetObjectRegistry.NiKeyBasedInterpolator_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiFloatInterpolator")
	{
		Index = TargetObjectRegistry.NiFloatInterpolator_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiTransformInterpolator")
	{
		Index = TargetObjectRegistry.NiTransformInterpolator_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiPoint3Interpolator")
	{
		Index = TargetObjectRegistry.NiPoint3Interpolator_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiPathInterpolator")
	{
		Index = TargetObjectRegistry.NiPathInterpolator_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiBoolInterpolator")
	{
		Index = TargetObjectRegistry.NiBoolInterpolator_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiBoolTimelineInterpolator")
	{
		Index = TargetObjectRegistry.NiBoolTimelineInterpolator_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiBlendInterpolator")
	{
		Index = TargetObjectRegistry.NiBlendInterpolator_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiBSplineInterpolator")
	{
		Index = TargetObjectRegistry.NiBSplineInterpolator_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiObjectNET")
	{
		Index = TargetObjectRegistry.NiObjectNET_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiCollisionObject")
	{
		Index = TargetObjectRegistry.NiCollisionObject_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiCollisionData")
	{
		Index = TargetObjectRegistry.NiCollisionData_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "bhkNiCollisionObject")
	{
		Index = TargetObjectRegistry.bhkNiCollisionObject_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "bhkCollisionObject")
	{
		Index = TargetObjectRegistry.bhkCollisionObject_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "bhkBlendCollisionObject")
	{
		Index = TargetObjectRegistry.bhkBlendCollisionObject_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "bhkPCollisionObject")
	{
		Index = TargetObjectRegistry.bhkPCollisionObject_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "bhkSPCollisionObject")
	{
		Index = TargetObjectRegistry.bhkSPCollisionObject_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiAVObject")
	{
		Index = TargetObjectRegistry.NiAVObject_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiDynamicEffect")
	{
		Index = TargetObjectRegistry.NiDynamicEffect_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiLight")
	{
		Index = TargetObjectRegistry.NiLight_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiProperty")
	{
		Index = TargetObjectRegistry.NiProperty_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiTransparentProperty")
	{
		Index = TargetObjectRegistry.NiTransparentProperty_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiPSysModifier")
	{
		Index = TargetObjectRegistry.NiPSysModifier_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiPSysEmitter")
	{
		Index = TargetObjectRegistry.NiPSysEmitter_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiPSysVolumeEmitter")
	{
		Index = TargetObjectRegistry.NiPSysVolumeEmitter_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiTimeController")
	{
		Index = TargetObjectRegistry.NiTimeController_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiInterpController")
	{
		Index = TargetObjectRegistry.NiInterpController_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiMultiTargetTransformController")
	{
		Index = TargetObjectRegistry.NiMultiTargetTransformController_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiGeomMorpherController")
	{
		Index = TargetObjectRegistry.NiGeomMorpherController_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiMorphController")
	{
		Index = TargetObjectRegistry.NiMorphController_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiMorpherController")
	{
		Index = TargetObjectRegistry.NiMorpherController_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiSingleInterpController")
	{
		Index = TargetObjectRegistry.NiSingleInterpController_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiKeyframeController")
	{
		Index = TargetObjectRegistry.NiKeyframeController_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiTransformController")
	{
		Index = TargetObjectRegistry.NiTransformController_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiPSysModifierCtlr")
	{
		Index = TargetObjectRegistry.NiPSysModifierCtlr_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiPSysEmitterCtlr")
	{
		Index = TargetObjectRegistry.NiPSysEmitterCtlr_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiPSysModifierBoolCtlr")
	{
		Index = TargetObjectRegistry.NiPSysModifierBoolCtlr_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiPSysModifierActiveCtlr")
	{
		Index = TargetObjectRegistry.NiPSysModifierActiveCtlr_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiPSysModifierFloatCtlr")
	{
		Index = TargetObjectRegistry.NiPSysModifierFloatCtlr_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiPSysEmitterDeclinationCtlr")
	{
		Index = TargetObjectRegistry.NiPSysEmitterDeclinationCtlr_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiPSysEmitterDeclinationVarCtlr")
	{
		Index = TargetObjectRegistry.NiPSysEmitterDeclinationVarCtlr_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiPSysEmitterInitialRadiusCtlr")
	{
		Index = TargetObjectRegistry.NiPSysEmitterInitialRadiusCtlr_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiPSysEmitterLifeSpanCtlr")
	{
		Index = TargetObjectRegistry.NiPSysEmitterLifeSpanCtlr_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiPSysEmitterSpeedCtlr")
	{
		Index = TargetObjectRegistry.NiPSysEmitterSpeedCtlr_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiPSysGravityStrengthCtlr")
	{
		Index = TargetObjectRegistry.NiPSysGravityStrengthCtlr_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiFloatInterpController")
	{
		Index = TargetObjectRegistry.NiFloatInterpController_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiFlipController")
	{
		Index = TargetObjectRegistry.NiFlipController_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiAlphaController")
	{
		Index = TargetObjectRegistry.NiAlphaController_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiTextureTransformController")
	{
		Index = TargetObjectRegistry.NiTextureTransformController_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiLightDimmerController")
	{
		Index = TargetObjectRegistry.NiLightDimmerController_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiBoolInterpController")
	{
		Index = TargetObjectRegistry.NiBoolInterpController_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiVisController")
	{
		Index = TargetObjectRegistry.NiVisController_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiPoint3InterpController")
	{
		Index = TargetObjectRegistry.NiPoint3InterpController_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiMaterialColorController")
	{
		Index = TargetObjectRegistry.NiMaterialColorController_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiLightColorController")
	{
		Index = TargetObjectRegistry.NiLightColorController_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiExtraDataController")
	{
		Index = TargetObjectRegistry.NiExtraDataController_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiFloatExtraDataController")
	{
		Index = TargetObjectRegistry.NiFloatExtraDataController_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiBoneLODController")
	{
		Index = TargetObjectRegistry.NiBoneLODController_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiBSBoneLODController")
	{
		Index = TargetObjectRegistry.NiBSBoneLODController_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiGeometry")
	{
		Index = TargetObjectRegistry.NiGeometry_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiTriBasedGeom")
	{
		Index = TargetObjectRegistry.NiTriBasedGeom_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiGeometryData")
	{
		Index = TargetObjectRegistry.NiGeometryData_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "AbstractAdditionalGeometryData")
	{
		Index = TargetObjectRegistry.AbstractAdditionalGeometryData_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiTriBasedGeomData")
	{
		Index = TargetObjectRegistry.NiTriBasedGeomData_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "bhkBlendController")
	{
		Index = TargetObjectRegistry.bhkBlendController_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "BSBound")
	{
		Index = TargetObjectRegistry.BSBound_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "BSFurnitureMarker")
	{
		Index = TargetObjectRegistry.BSFurnitureMarker_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "BSParentVelocityModifier")
	{
		Index = TargetObjectRegistry.BSParentVelocityModifier_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "BSPSysArrayEmitter")
	{
		Index = TargetObjectRegistry.BSPSysArrayEmitter_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "BSWindModifier")
	{
		Index = TargetObjectRegistry.BSWindModifier_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "hkPackedNiTriStripsData")
	{
		Index = TargetObjectRegistry.hkPackedNiTriStripsData_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiAlphaProperty")
	{
		Index = TargetObjectRegistry.NiAlphaProperty_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiAmbientLight")
	{
		Index = TargetObjectRegistry.NiAmbientLight_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiParticlesData")
	{
		Index = TargetObjectRegistry.NiParticlesData_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiRotatingParticlesData")
	{
		Index = TargetObjectRegistry.NiRotatingParticlesData_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiAutoNormalParticlesData")
	{
		Index = TargetObjectRegistry.NiAutoNormalParticlesData_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiPSysData")
	{
		Index = TargetObjectRegistry.NiPSysData_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiMeshPSysData")
	{
		Index = TargetObjectRegistry.NiMeshPSysData_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiBinaryExtraData")
	{
		Index = TargetObjectRegistry.NiBinaryExtraData_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiBinaryVoxelExtraData")
	{
		Index = TargetObjectRegistry.NiBinaryVoxelExtraData_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiBinaryVoxelData")
	{
		Index = TargetObjectRegistry.NiBinaryVoxelData_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiBlendBoolInterpolator")
	{
		Index = TargetObjectRegistry.NiBlendBoolInterpolator_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiBlendFloatInterpolator")
	{
		Index = TargetObjectRegistry.NiBlendFloatInterpolator_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiBlendPoint3Interpolator")
	{
		Index = TargetObjectRegistry.NiBlendPoint3Interpolator_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiBlendTransformInterpolator")
	{
		Index = TargetObjectRegistry.NiBlendTransformInterpolator_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiBoolData")
	{
		Index = TargetObjectRegistry.NiBoolData_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiBooleanExtraData")
	{
		Index = TargetObjectRegistry.NiBooleanExtraData_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiBSplineBasisData")
	{
		Index = TargetObjectRegistry.NiBSplineBasisData_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiBSplineFloatInterpolator")
	{
		Index = TargetObjectRegistry.NiBSplineFloatInterpolator_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiBSplineCompFloatInterpolator")
	{
		Index = TargetObjectRegistry.NiBSplineCompFloatInterpolator_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiBSplinePoint3Interpolator")
	{
		Index = TargetObjectRegistry.NiBSplinePoint3Interpolator_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiBSplineCompPoint3Interpolator")
	{
		Index = TargetObjectRegistry.NiBSplineCompPoint3Interpolator_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiBSplineTransformInterpolator")
	{
		Index = TargetObjectRegistry.NiBSplineTransformInterpolator_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiBSplineCompTransformInterpolator")
	{
		Index = TargetObjectRegistry.NiBSplineCompTransformInterpolator_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "BSRotAccumTransfInterpolator")
	{
		Index = TargetObjectRegistry.BSRotAccumTransfInterpolator_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiBSplineData")
	{
		Index = TargetObjectRegistry.NiBSplineData_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiCamera")
	{
		Index = TargetObjectRegistry.NiCamera_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiColorData")
	{
		Index = TargetObjectRegistry.NiColorData_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiColorExtraData")
	{
		Index = TargetObjectRegistry.NiColorExtraData_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiControllerManager")
	{
		Index = TargetObjectRegistry.NiControllerManager_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiSequence")
	{
		Index = TargetObjectRegistry.NiSequence_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiControllerSequence")
	{
		Index = TargetObjectRegistry.NiControllerSequence_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiAVObjectPalette")
	{
		Index = TargetObjectRegistry.NiAVObjectPalette_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiDefaultAVObjectPalette")
	{
		Index = TargetObjectRegistry.NiDefaultAVObjectPalette_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiDirectionalLight")
	{
		Index = TargetObjectRegistry.NiDirectionalLight_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiDitherProperty")
	{
		Index = TargetObjectRegistry.NiDitherProperty_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiRollController")
	{
		Index = TargetObjectRegistry.NiRollController_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiFloatData")
	{
		Index = TargetObjectRegistry.NiFloatData_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiFloatExtraData")
	{
		Index = TargetObjectRegistry.NiFloatExtraData_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiFloatsExtraData")
	{
		Index = TargetObjectRegistry.NiFloatsExtraData_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiFogProperty")
	{
		Index = TargetObjectRegistry.NiFogProperty_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiGravity")
	{
		Index = TargetObjectRegistry.NiGravity_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiIntegerExtraData")
	{
		Index = TargetObjectRegistry.NiIntegerExtraData_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "BSXFlags")
	{
		Index = TargetObjectRegistry.BSXFlags_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiIntegersExtraData")
	{
		Index = TargetObjectRegistry.NiIntegersExtraData_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "BSKeyframeController")
	{
		Index = TargetObjectRegistry.BSKeyframeController_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiKeyframeData")
	{
		Index = TargetObjectRegistry.NiKeyframeData_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiLookAtController")
	{
		Index = TargetObjectRegistry.NiLookAtController_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiLookAtInterpolator")
	{
		Index = TargetObjectRegistry.NiLookAtInterpolator_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiMaterialProperty")
	{
		Index = TargetObjectRegistry.NiMaterialProperty_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiMorphData")
	{
		Index = TargetObjectRegistry.NiMorphData_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiNode")
	{
		Index = TargetObjectRegistry.NiNode_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiBone")
	{
		Index = TargetObjectRegistry.NiBone_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "AvoidNode")
	{
		Index = TargetObjectRegistry.AvoidNode_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "FxWidget")
	{
		Index = TargetObjectRegistry.FxWidget_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "FxButton")
	{
		Index = TargetObjectRegistry.FxButton_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "FxRadioButton")
	{
		Index = TargetObjectRegistry.FxRadioButton_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiBillboardNode")
	{
		Index = TargetObjectRegistry.NiBillboardNode_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiBSAnimationNode")
	{
		Index = TargetObjectRegistry.NiBSAnimationNode_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiBSParticleNode")
	{
		Index = TargetObjectRegistry.NiBSParticleNode_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiSwitchNode")
	{
		Index = TargetObjectRegistry.NiSwitchNode_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiLODNode")
	{
		Index = TargetObjectRegistry.NiLODNode_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiPalette")
	{
		Index = TargetObjectRegistry.NiPalette_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiParticleBomb")
	{
		Index = TargetObjectRegistry.NiParticleBomb_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiParticleColorModifier")
	{
		Index = TargetObjectRegistry.NiParticleColorModifier_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiParticleGrowFade")
	{
		Index = TargetObjectRegistry.NiParticleGrowFade_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiParticleMeshModifier")
	{
		Index = TargetObjectRegistry.NiParticleMeshModifier_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiParticleRotation")
	{
		Index = TargetObjectRegistry.NiParticleRotation_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiParticles")
	{
		Index = TargetObjectRegistry.NiParticles_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiAutoNormalParticles")
	{
		Index = TargetObjectRegistry.NiAutoNormalParticles_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiParticleMeshes")
	{
		Index = TargetObjectRegistry.NiParticleMeshes_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiParticleMeshesData")
	{
		Index = TargetObjectRegistry.NiParticleMeshesData_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiParticleSystem")
	{
		Index = TargetObjectRegistry.NiParticleSystem_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiMeshParticleSystem")
	{
		Index = TargetObjectRegistry.NiMeshParticleSystem_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiParticleSystemController")
	{
		Index = TargetObjectRegistry.NiParticleSystemController_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiBSPArrayController")
	{
		Index = TargetObjectRegistry.NiBSPArrayController_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiPathController")
	{
		Index = TargetObjectRegistry.NiPathController_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "ATextureRenderData")
	{
		Index = TargetObjectRegistry.ATextureRenderData_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiPersistentSrcTextureRendererData")
	{
		Index = TargetObjectRegistry.NiPersistentSrcTextureRendererData_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiPixelData")
	{
		Index = TargetObjectRegistry.NiPixelData_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiPlanarCollider")
	{
		Index = TargetObjectRegistry.NiPlanarCollider_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiPointLight")
	{
		Index = TargetObjectRegistry.NiPointLight_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiPosData")
	{
		Index = TargetObjectRegistry.NiPosData_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiPSysAgeDeathModifier")
	{
		Index = TargetObjectRegistry.NiPSysAgeDeathModifier_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiPSysBombModifier")
	{
		Index = TargetObjectRegistry.NiPSysBombModifier_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiPSysBoundUpdateModifier")
	{
		Index = TargetObjectRegistry.NiPSysBoundUpdateModifier_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiPSysBoxEmitter")
	{
		Index = TargetObjectRegistry.NiPSysBoxEmitter_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiPSysColliderManager")
	{
		Index = TargetObjectRegistry.NiPSysColliderManager_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiPSysColorModifier")
	{
		Index = TargetObjectRegistry.NiPSysColorModifier_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiPSysCylinderEmitter")
	{
		Index = TargetObjectRegistry.NiPSysCylinderEmitter_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiPSysDragModifier")
	{
		Index = TargetObjectRegistry.NiPSysDragModifier_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiPSysEmitterCtlrData")
	{
		Index = TargetObjectRegistry.NiPSysEmitterCtlrData_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiPSysGravityModifier")
	{
		Index = TargetObjectRegistry.NiPSysGravityModifier_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiPSysGrowFadeModifier")
	{
		Index = TargetObjectRegistry.NiPSysGrowFadeModifier_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiPSysMeshEmitter")
	{
		Index = TargetObjectRegistry.NiPSysMeshEmitter_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiPSysMeshUpdateModifier")
	{
		Index = TargetObjectRegistry.NiPSysMeshUpdateModifier_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "BSPSysInheritVelocityModifier")
	{
		Index = TargetObjectRegistry.BSPSysInheritVelocityModifier_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "BSPSysHavokUpdateModifier")
	{
		Index = TargetObjectRegistry.BSPSysHavokUpdateModifier_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "BSPSysRecycleBoundModifier")
	{
		Index = TargetObjectRegistry.BSPSysRecycleBoundModifier_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "BSPSysSubTexModifier")
	{
		Index = TargetObjectRegistry.BSPSysSubTexModifier_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiPSysPlanarCollider")
	{
		Index = TargetObjectRegistry.NiPSysPlanarCollider_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiPSysSphericalCollider")
	{
		Index = TargetObjectRegistry.NiPSysSphericalCollider_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiPSysPositionModifier")
	{
		Index = TargetObjectRegistry.NiPSysPositionModifier_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiPSysResetOnLoopCtlr")
	{
		Index = TargetObjectRegistry.NiPSysResetOnLoopCtlr_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiPSysRotationModifier")
	{
		Index = TargetObjectRegistry.NiPSysRotationModifier_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiPSysSpawnModifier")
	{
		Index = TargetObjectRegistry.NiPSysSpawnModifier_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiPSysSphereEmitter")
	{
		Index = TargetObjectRegistry.NiPSysSphereEmitter_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiPSysUpdateCtlr")
	{
		Index = TargetObjectRegistry.NiPSysUpdateCtlr_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiPSysFieldModifier")
	{
		Index = TargetObjectRegistry.NiPSysFieldModifier_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiPSysVortexFieldModifier")
	{
		Index = TargetObjectRegistry.NiPSysVortexFieldModifier_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiPSysGravityFieldModifier")
	{
		Index = TargetObjectRegistry.NiPSysGravityFieldModifier_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiPSysDragFieldModifier")
	{
		Index = TargetObjectRegistry.NiPSysDragFieldModifier_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiPSysTurbulenceFieldModifier")
	{
		Index = TargetObjectRegistry.NiPSysTurbulenceFieldModifier_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "BSPSysLODModifier")
	{
		Index = TargetObjectRegistry.BSPSysLODModifier_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "BSPSysScaleModifier")
	{
		Index = TargetObjectRegistry.BSPSysScaleModifier_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiPSysFieldMagnitudeCtlr")
	{
		Index = TargetObjectRegistry.NiPSysFieldMagnitudeCtlr_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiPSysFieldAttenuationCtlr")
	{
		Index = TargetObjectRegistry.NiPSysFieldAttenuationCtlr_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiPSysFieldMaxDistanceCtlr")
	{
		Index = TargetObjectRegistry.NiPSysFieldMaxDistanceCtlr_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiPSysAirFieldAirFrictionCtlr")
	{
		Index = TargetObjectRegistry.NiPSysAirFieldAirFrictionCtlr_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiPSysAirFieldInheritVelocityCtlr")
	{
		Index = TargetObjectRegistry.NiPSysAirFieldInheritVelocityCtlr_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiPSysAirFieldSpreadCtlr")
	{
		Index = TargetObjectRegistry.NiPSysAirFieldSpreadCtlr_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiPSysInitialRotSpeedCtlr")
	{
		Index = TargetObjectRegistry.NiPSysInitialRotSpeedCtlr_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiPSysInitialRotSpeedVarCtlr")
	{
		Index = TargetObjectRegistry.NiPSysInitialRotSpeedVarCtlr_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiPSysInitialRotAngleCtlr")
	{
		Index = TargetObjectRegistry.NiPSysInitialRotAngleCtlr_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiPSysInitialRotAngleVarCtlr")
	{
		Index = TargetObjectRegistry.NiPSysInitialRotAngleVarCtlr_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiPSysEmitterPlanarAngleCtlr")
	{
		Index = TargetObjectRegistry.NiPSysEmitterPlanarAngleCtlr_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiPSysEmitterPlanarAngleVarCtlr")
	{
		Index = TargetObjectRegistry.NiPSysEmitterPlanarAngleVarCtlr_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiPSysAirFieldModifier")
	{
		Index = TargetObjectRegistry.NiPSysAirFieldModifier_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiPSysTrailEmitter")
	{
		Index = TargetObjectRegistry.NiPSysTrailEmitter_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiLightIntensityController")
	{
		Index = TargetObjectRegistry.NiLightIntensityController_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiPSysRadialFieldModifier")
	{
		Index = TargetObjectRegistry.NiPSysRadialFieldModifier_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiLODData")
	{
		Index = TargetObjectRegistry.NiLODData_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiRangeLODData")
	{
		Index = TargetObjectRegistry.NiRangeLODData_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiScreenLODData")
	{
		Index = TargetObjectRegistry.NiScreenLODData_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiRotatingParticles")
	{
		Index = TargetObjectRegistry.NiRotatingParticles_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiSequenceStreamHelper")
	{
		Index = TargetObjectRegistry.NiSequenceStreamHelper_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiShadeProperty")
	{
		Index = TargetObjectRegistry.NiShadeProperty_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiSkinData")
	{
		Index = TargetObjectRegistry.NiSkinData_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiSkinInstance")
	{
		Index = TargetObjectRegistry.NiSkinInstance_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiTriShapeSkinController")
	{
		Index = TargetObjectRegistry.NiTriShapeSkinController_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiClodSkinInstance")
	{
		Index = TargetObjectRegistry.NiClodSkinInstance_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiSkinPartition")
	{
		Index = TargetObjectRegistry.NiSkinPartition_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiTexture")
	{
		Index = TargetObjectRegistry.NiTexture_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiSourceTexture")
	{
		Index = TargetObjectRegistry.NiSourceTexture_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiSpecularProperty")
	{
		Index = TargetObjectRegistry.NiSpecularProperty_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiSphericalCollider")
	{
		Index = TargetObjectRegistry.NiSphericalCollider_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiSpotLight")
	{
		Index = TargetObjectRegistry.NiSpotLight_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiStencilProperty")
	{
		Index = TargetObjectRegistry.NiStencilProperty_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiStringExtraData")
	{
		Index = TargetObjectRegistry.NiStringExtraData_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiStringPalette")
	{
		Index = TargetObjectRegistry.NiStringPalette_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiStringsExtraData")
	{
		Index = TargetObjectRegistry.NiStringsExtraData_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiTextKeyExtraData")
	{
		Index = TargetObjectRegistry.NiTextKeyExtraData_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiTextureEffect")
	{
		Index = TargetObjectRegistry.NiTextureEffect_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiTextureModeProperty")
	{
		Index = TargetObjectRegistry.NiTextureModeProperty_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiImage")
	{
		Index = TargetObjectRegistry.NiImage_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiTextureProperty")
	{
		Index = TargetObjectRegistry.NiTextureProperty_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiMultiTextureProperty")
	{
		Index = TargetObjectRegistry.NiMultiTextureProperty_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiTexturingProperty")
	{
		Index = TargetObjectRegistry.NiTexturingProperty_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiTransformData")
	{
		Index = TargetObjectRegistry.NiTransformData_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiTriShape")
	{
		Index = TargetObjectRegistry.NiTriShape_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiTriShapeData")
	{
		Index = TargetObjectRegistry.NiTriShapeData_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiTriStrips")
	{
		Index = TargetObjectRegistry.NiTriStrips_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiTriStripsData")
	{
		Index = TargetObjectRegistry.NiTriStripsData_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiEnvMappedTriShape")
	{
		Index = TargetObjectRegistry.NiEnvMappedTriShape_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiEnvMappedTriShapeData")
	{
		Index = TargetObjectRegistry.NiEnvMappedTriShapeData_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiBezierTriangle4")
	{
		Index = TargetObjectRegistry.NiBezierTriangle4_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiBezierMesh")
	{
		Index = TargetObjectRegistry.NiBezierMesh_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiClod")
	{
		Index = TargetObjectRegistry.NiClod_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiClodData")
	{
		Index = TargetObjectRegistry.NiClodData_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiUVController")
	{
		Index = TargetObjectRegistry.NiUVController_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiUVData")
	{
		Index = TargetObjectRegistry.NiUVData_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiVectorExtraData")
	{
		Index = TargetObjectRegistry.NiVectorExtraData_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiVertexColorProperty")
	{
		Index = TargetObjectRegistry.NiVertexColorProperty_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiVertWeightsExtraData")
	{
		Index = TargetObjectRegistry.NiVertWeightsExtraData_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiVisData")
	{
		Index = TargetObjectRegistry.NiVisData_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiWireframeProperty")
	{
		Index = TargetObjectRegistry.NiWireframeProperty_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiZBufferProperty")
	{
		Index = TargetObjectRegistry.NiZBufferProperty_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "RootCollisionNode")
	{
		Index = TargetObjectRegistry.RootCollisionNode_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiRawImageData")
	{
		Index = TargetObjectRegistry.NiRawImageData_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiSortAdjustNode")
	{
		Index = TargetObjectRegistry.NiSortAdjustNode_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiSourceCubeMap")
	{
		Index = TargetObjectRegistry.NiSourceCubeMap_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiPhysXProp")
	{
		Index = TargetObjectRegistry.NiPhysXProp_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiPhysXPropDesc")
	{
		Index = TargetObjectRegistry.NiPhysXPropDesc_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiPhysXActorDesc")
	{
		Index = TargetObjectRegistry.NiPhysXActorDesc_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiPhysXBodyDesc")
	{
		Index = TargetObjectRegistry.NiPhysXBodyDesc_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiPhysXD6JointDesc")
	{
		Index = TargetObjectRegistry.NiPhysXD6JointDesc_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiPhysXShapeDesc")
	{
		Index = TargetObjectRegistry.NiPhysXShapeDesc_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiPhysXMeshDesc")
	{
		Index = TargetObjectRegistry.NiPhysXMeshDesc_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiPhysXMaterialDesc")
	{
		Index = TargetObjectRegistry.NiPhysXMaterialDesc_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiPhysXKinematicSrc")
	{
		Index = TargetObjectRegistry.NiPhysXKinematicSrc_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiPhysXTransformDest")
	{
		Index = TargetObjectRegistry.NiPhysXTransformDest_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiArkAnimationExtraData")
	{
		Index = TargetObjectRegistry.NiArkAnimationExtraData_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiArkImporterExtraData")
	{
		Index = TargetObjectRegistry.NiArkImporterExtraData_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiArkTextureExtraData")
	{
		Index = TargetObjectRegistry.NiArkTextureExtraData_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiArkViewportInfoExtraData")
	{
		Index = TargetObjectRegistry.NiArkViewportInfoExtraData_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiArkShaderExtraData")
	{
		Index = TargetObjectRegistry.NiArkShaderExtraData_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiLines")
	{
		Index = TargetObjectRegistry.NiLines_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiLinesData")
	{
		Index = TargetObjectRegistry.NiLinesData_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiScreenElementsData")
	{
		Index = TargetObjectRegistry.NiScreenElementsData_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiScreenElements")
	{
		Index = TargetObjectRegistry.NiScreenElements_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiRoomGroup")
	{
		Index = TargetObjectRegistry.NiRoomGroup_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiRoom")
	{
		Index = TargetObjectRegistry.NiRoom_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiPortal")
	{
		Index = TargetObjectRegistry.NiPortal_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "BSFadeNode")
	{
		Index = TargetObjectRegistry.BSFadeNode_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "BSShaderProperty")
	{
		Index = TargetObjectRegistry.BSShaderProperty_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "BSShaderLightingProperty")
	{
		Index = TargetObjectRegistry.BSShaderLightingProperty_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "BSShaderNoLightingProperty")
	{
		Index = TargetObjectRegistry.BSShaderNoLightingProperty_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "BSShaderPPLightingProperty")
	{
		Index = TargetObjectRegistry.BSShaderPPLightingProperty_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "BSEffectShaderPropertyFloatController")
	{
		Index = TargetObjectRegistry.BSEffectShaderPropertyFloatController_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "BSEffectShaderPropertyColorController")
	{
		Index = TargetObjectRegistry.BSEffectShaderPropertyColorController_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "BSLightingShaderPropertyFloatController")
	{
		Index = TargetObjectRegistry.BSLightingShaderPropertyFloatController_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "BSLightingShaderPropertyColorController")
	{
		Index = TargetObjectRegistry.BSLightingShaderPropertyColorController_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "BSNiAlphaPropertyTestRefController")
	{
		Index = TargetObjectRegistry.BSNiAlphaPropertyTestRefController_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "BSProceduralLightningController")
	{
		Index = TargetObjectRegistry.BSProceduralLightningController_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "BSShaderTextureSet")
	{
		Index = TargetObjectRegistry.BSShaderTextureSet_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "WaterShaderProperty")
	{
		Index = TargetObjectRegistry.WaterShaderProperty_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "SkyShaderProperty")
	{
		Index = TargetObjectRegistry.SkyShaderProperty_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "TileShaderProperty")
	{
		Index = TargetObjectRegistry.TileShaderProperty_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "DistantLODShaderProperty")
	{
		Index = TargetObjectRegistry.DistantLODShaderProperty_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "BSDistantTreeShaderProperty")
	{
		Index = TargetObjectRegistry.BSDistantTreeShaderProperty_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "TallGrassShaderProperty")
	{
		Index = TargetObjectRegistry.TallGrassShaderProperty_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "VolumetricFogShaderProperty")
	{
		Index = TargetObjectRegistry.VolumetricFogShaderProperty_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "HairShaderProperty")
	{
		Index = TargetObjectRegistry.HairShaderProperty_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "Lighting30ShaderProperty")
	{
		Index = TargetObjectRegistry.Lighting30ShaderProperty_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "BSLightingShaderProperty")
	{
		Index = TargetObjectRegistry.BSLightingShaderProperty_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "BSEffectShaderProperty")
	{
		Index = TargetObjectRegistry.BSEffectShaderProperty_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "BSWaterShaderProperty")
	{
		Index = TargetObjectRegistry.BSWaterShaderProperty_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "BSSkyShaderProperty")
	{
		Index = TargetObjectRegistry.BSSkyShaderProperty_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "BSDismemberSkinInstance")
	{
		Index = TargetObjectRegistry.BSDismemberSkinInstance_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "BSDecalPlacementVectorExtraData")
	{
		Index = TargetObjectRegistry.BSDecalPlacementVectorExtraData_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "BSPSysSimpleColorModifier")
	{
		Index = TargetObjectRegistry.BSPSysSimpleColorModifier_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "BSValueNode")
	{
		Index = TargetObjectRegistry.BSValueNode_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "BSStripParticleSystem")
	{
		Index = TargetObjectRegistry.BSStripParticleSystem_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "BSStripPSysData")
	{
		Index = TargetObjectRegistry.BSStripPSysData_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "BSPSysStripUpdateModifier")
	{
		Index = TargetObjectRegistry.BSPSysStripUpdateModifier_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "BSMaterialEmittanceMultController")
	{
		Index = TargetObjectRegistry.BSMaterialEmittanceMultController_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "BSMasterParticleSystem")
	{
		Index = TargetObjectRegistry.BSMasterParticleSystem_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "BSPSysMultiTargetEmitterCtlr")
	{
		Index = TargetObjectRegistry.BSPSysMultiTargetEmitterCtlr_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "BSRefractionStrengthController")
	{
		Index = TargetObjectRegistry.BSRefractionStrengthController_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "BSOrderedNode")
	{
		Index = TargetObjectRegistry.BSOrderedNode_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "BSBlastNode")
	{
		Index = TargetObjectRegistry.BSBlastNode_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "BSDamageStage")
	{
		Index = TargetObjectRegistry.BSDamageStage_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "BSRefractionFirePeriodController")
	{
		Index = TargetObjectRegistry.BSRefractionFirePeriodController_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "bhkConvexListShape")
	{
		Index = TargetObjectRegistry.bhkConvexListShape_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "BSTreadTransfInterpolator")
	{
		Index = TargetObjectRegistry.BSTreadTransfInterpolator_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "BSAnimNotes")
	{
		Index = TargetObjectRegistry.BSAnimNotes_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "bhkLiquidAction")
	{
		Index = TargetObjectRegistry.bhkLiquidAction_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "BSMultiBoundNode")
	{
		Index = TargetObjectRegistry.BSMultiBoundNode_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "BSMultiBound")
	{
		Index = TargetObjectRegistry.BSMultiBound_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "BSMultiBoundData")
	{
		Index = TargetObjectRegistry.BSMultiBoundData_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "BSMultiBoundOBB")
	{
		Index = TargetObjectRegistry.BSMultiBoundOBB_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "BSMultiBoundSphere")
	{
		Index = TargetObjectRegistry.BSMultiBoundSphere_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "BSSegmentedTriShape")
	{
		Index = TargetObjectRegistry.BSSegmentedTriShape_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "BSMultiBoundAABB")
	{
		Index = TargetObjectRegistry.BSMultiBoundAABB_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiAdditionalGeometryData")
	{
		Index = TargetObjectRegistry.NiAdditionalGeometryData_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "BSPackedAdditionalGeometryData")
	{
		Index = TargetObjectRegistry.BSPackedAdditionalGeometryData_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "BSWArray")
	{
		Index = TargetObjectRegistry.BSWArray_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "bhkAabbPhantom")
	{
		Index = TargetObjectRegistry.bhkAabbPhantom_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "BSFrustumFOVController")
	{
		Index = TargetObjectRegistry.BSFrustumFOVController_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "BSDebrisNode")
	{
		Index = TargetObjectRegistry.BSDebrisNode_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "bhkBreakableConstraint")
	{
		Index = TargetObjectRegistry.bhkBreakableConstraint_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "bhkOrientHingedBodyAction")
	{
		Index = TargetObjectRegistry.bhkOrientHingedBodyAction_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiDataStream")
	{
		Index = TargetObjectRegistry.NiDataStream_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiRenderObject")
	{
		Index = TargetObjectRegistry.NiRenderObject_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiMeshModifier")
	{
		Index = TargetObjectRegistry.NiMeshModifier_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiMesh")
	{
		Index = TargetObjectRegistry.NiMesh_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiMorphWeightsController")
	{
		Index = TargetObjectRegistry.NiMorphWeightsController_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiMorphMeshModifier")
	{
		Index = TargetObjectRegistry.NiMorphMeshModifier_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiSkinningMeshModifier")
	{
		Index = TargetObjectRegistry.NiSkinningMeshModifier_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiInstancingMeshModifier")
	{
		Index = TargetObjectRegistry.NiInstancingMeshModifier_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiSkinningLODController")
	{
		Index = TargetObjectRegistry.NiSkinningLODController_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiPSParticleSystem")
	{
		Index = TargetObjectRegistry.NiPSParticleSystem_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiPSMeshParticleSystem")
	{
		Index = TargetObjectRegistry.NiPSMeshParticleSystem_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiPSEmitParticlesCtlr")
	{
		Index = TargetObjectRegistry.NiPSEmitParticlesCtlr_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiPSForceActiveCtlr")
	{
		Index = TargetObjectRegistry.NiPSForceActiveCtlr_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiPSSimulator")
	{
		Index = TargetObjectRegistry.NiPSSimulator_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiPSSimulatorStep")
	{
		Index = TargetObjectRegistry.NiPSSimulatorStep_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiPSSimulatorGeneralStep")
	{
		Index = TargetObjectRegistry.NiPSSimulatorGeneralStep_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiPSSimulatorForcesStep")
	{
		Index = TargetObjectRegistry.NiPSSimulatorForcesStep_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiPSSimulatorCollidersStep")
	{
		Index = TargetObjectRegistry.NiPSSimulatorCollidersStep_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiPSSimulatorMeshAlignStep")
	{
		Index = TargetObjectRegistry.NiPSSimulatorMeshAlignStep_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiPSSimulatorFinalStep")
	{
		Index = TargetObjectRegistry.NiPSSimulatorFinalStep_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiPSFacingQuadGenerator")
	{
		Index = TargetObjectRegistry.NiPSFacingQuadGenerator_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiShadowGenerator")
	{
		Index = TargetObjectRegistry.NiShadowGenerator_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiPSBoundUpdater")
	{
		Index = TargetObjectRegistry.NiPSBoundUpdater_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiPSDragForce")
	{
		Index = TargetObjectRegistry.NiPSDragForce_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiPSGravityForce")
	{
		Index = TargetObjectRegistry.NiPSGravityForce_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiPSBoxEmitter")
	{
		Index = TargetObjectRegistry.NiPSBoxEmitter_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiPSMeshEmitter")
	{
		Index = TargetObjectRegistry.NiPSMeshEmitter_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiPSGravityStrengthCtlr")
	{
		Index = TargetObjectRegistry.NiPSGravityStrengthCtlr_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiPSPlanarCollider")
	{
		Index = TargetObjectRegistry.NiPSPlanarCollider_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiPSEmitterSpeedCtlr")
	{
		Index = TargetObjectRegistry.NiPSEmitterSpeedCtlr_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiPSEmitterRadiusCtlr")
	{
		Index = TargetObjectRegistry.NiPSEmitterRadiusCtlr_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiPSResetOnLoopCtlr")
	{
		Index = TargetObjectRegistry.NiPSResetOnLoopCtlr_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiPSSphereEmitter")
	{
		Index = TargetObjectRegistry.NiPSSphereEmitter_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiPSCylinderEmitter")
	{
		Index = TargetObjectRegistry.NiPSCylinderEmitter_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiPSEmitterDeclinationCtlr")
	{
		Index = TargetObjectRegistry.NiPSEmitterDeclinationCtlr_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiPSEmitterDeclinationVarCtlr")
	{
		Index = TargetObjectRegistry.NiPSEmitterDeclinationVarCtlr_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiPSEmitterPlanarAngleCtlr")
	{
		Index = TargetObjectRegistry.NiPSEmitterPlanarAngleCtlr_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiPSEmitterPlanarAngleVarCtlr")
	{
		Index = TargetObjectRegistry.NiPSEmitterPlanarAngleVarCtlr_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiPSEmitterRotAngleCtlr")
	{
		Index = TargetObjectRegistry.NiPSEmitterRotAngleCtlr_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiPSEmitterRotAngleVarCtlr")
	{
		Index = TargetObjectRegistry.NiPSEmitterRotAngleVarCtlr_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiPSEmitterRotSpeedCtlr")
	{
		Index = TargetObjectRegistry.NiPSEmitterRotSpeedCtlr_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiPSEmitterRotSpeedVarCtlr")
	{
		Index = TargetObjectRegistry.NiPSEmitterRotSpeedVarCtlr_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiPSEmitterLifeSpanCtlr")
	{
		Index = TargetObjectRegistry.NiPSEmitterLifeSpanCtlr_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiPSBombForce")
	{
		Index = TargetObjectRegistry.NiPSBombForce_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiPSSphericalCollider")
	{
		Index = TargetObjectRegistry.NiPSSphericalCollider_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiPSSpawner")
	{
		Index = TargetObjectRegistry.NiPSSpawner_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiSequenceData")
	{
		Index = TargetObjectRegistry.NiSequenceData_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiTransformEvaluator")
	{
		Index = TargetObjectRegistry.NiTransformEvaluator_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiBSplineCompTransformEvaluator")
	{
		Index = TargetObjectRegistry.NiBSplineCompTransformEvaluator_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiMeshHWInstance")
	{
		Index = TargetObjectRegistry.NiMeshHWInstance_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiFurSpringController")
	{
		Index = TargetObjectRegistry.NiFurSpringController_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "CStreamableAssetData")
	{
		Index = TargetObjectRegistry.CStreamableAssetData_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "bhkCompressedMeshShape")
	{
		Index = TargetObjectRegistry.bhkCompressedMeshShape_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "bhkCompressedMeshShapeData")
	{
		Index = TargetObjectRegistry.bhkCompressedMeshShapeData_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "BSInvMarker")
	{
		Index = TargetObjectRegistry.BSInvMarker_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "BSBoneLODExtraData")
	{
		Index = TargetObjectRegistry.BSBoneLODExtraData_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "BSBehaviorGraphExtraData")
	{
		Index = TargetObjectRegistry.BSBehaviorGraphExtraData_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "BSLagBoneController")
	{
		Index = TargetObjectRegistry.BSLagBoneController_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "BSLODTriShape")
	{
		Index = TargetObjectRegistry.BSLODTriShape_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "BSFurnitureMarkerNode")
	{
		Index = TargetObjectRegistry.BSFurnitureMarkerNode_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "BSLeafAnimNode")
	{
		Index = TargetObjectRegistry.BSLeafAnimNode_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "BSTreeNode")
	{
		Index = TargetObjectRegistry.BSTreeNode_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "NiLightRadiusController")
	{
		Index = TargetObjectRegistry.NiLightRadiusController_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "BSShape")
	{
		Index = TargetObjectRegistry.BSShape_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "BSTriShape")
	{
		Index = TargetObjectRegistry.BSTriShape_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "BSSubIndexTriShape")
	{
		Index = TargetObjectRegistry.BSSubIndexTriShape_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "BSMeshLODTriShape")
	{
		Index = TargetObjectRegistry.BSMeshLODTriShape_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "bhkNPCollisionObject")
	{
		Index = TargetObjectRegistry.bhkNPCollisionObject_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "BSExtraData")
	{
		Index = TargetObjectRegistry.BSExtraData_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "bhkPhysicsSystem")
	{
		Index = TargetObjectRegistry.bhkPhysicsSystem_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "bhkRagdollSystem")
	{
		Index = TargetObjectRegistry.bhkRagdollSystem_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "BSClothExtraData")
	{
		Index = TargetObjectRegistry.BSClothExtraData_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "BSSkin__Instance")
	{
		Index = TargetObjectRegistry.BSSkin__Instance_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "BSSkin__BoneData")
	{
		Index = TargetObjectRegistry.BSSkin__BoneData_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "BSPositionData")
	{
		Index = TargetObjectRegistry.BSPositionData_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "BSConnectPoint__Parents")
	{
		Index = TargetObjectRegistry.BSConnectPoint__Parents_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	if(TargetNodeType == "BSConnectPoint__Children")
	{
		Index = TargetObjectRegistry.BSConnectPoint__Children_Registry.AddDataV2(this, CurrentNode->InternalName);
	}
	//End of ObjectRegistry Section
	FixCurrentNodeData();
	CurrentNode->IndexInRegistry = Index;
}

void NifNodeTreeData::NifNodeTree::CopyNodeToTree(Niflib::NiObjectRef TargetNodeData, NifNode TargetNode)
{
	size_t TreeIndex = Size();
	Add(TargetNode);
	CurrentNode = GetElementPointerV2(TreeIndex);
	CurrentNodeInternalName = CurrentNode->InternalName;
	BaseLooseNode.Add(CurrentNodeInternalName);
	size_t Index;
	std::string const TargetNodeType = TargetNode.NodeType;
	//Now add actual node to ObjectRegistry
	if(TargetNodeType == "NiObject")
	{
		Index = TargetObjectRegistry.NiObject_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "Ni3dsAlphaAnimator")
	{
		Index = TargetObjectRegistry.Ni3dsAlphaAnimator_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "Ni3dsAnimationNode")
	{
		Index = TargetObjectRegistry.Ni3dsAnimationNode_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "Ni3dsColorAnimator")
	{
		Index = TargetObjectRegistry.Ni3dsColorAnimator_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "Ni3dsMorphShape")
	{
		Index = TargetObjectRegistry.Ni3dsMorphShape_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "Ni3dsParticleSystem")
	{
		Index = TargetObjectRegistry.Ni3dsParticleSystem_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "Ni3dsPathController")
	{
		Index = TargetObjectRegistry.Ni3dsPathController_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiParticleModifier")
	{
		Index = TargetObjectRegistry.NiParticleModifier_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiPSysCollider")
	{
		Index = TargetObjectRegistry.NiPSysCollider_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "bhkRefObject")
	{
		Index = TargetObjectRegistry.bhkRefObject_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "bhkSerializable")
	{
		Index = TargetObjectRegistry.bhkSerializable_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "bhkWorldObject")
	{
		Index = TargetObjectRegistry.bhkWorldObject_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "bhkPhantom")
	{
		Index = TargetObjectRegistry.bhkPhantom_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "bhkShapePhantom")
	{
		Index = TargetObjectRegistry.bhkShapePhantom_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "bhkSimpleShapePhantom")
	{
		Index = TargetObjectRegistry.bhkSimpleShapePhantom_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "bhkEntity")
	{
		Index = TargetObjectRegistry.bhkEntity_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "bhkRigidBody")
	{
		Index = TargetObjectRegistry.bhkRigidBody_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "bhkRigidBodyT")
	{
		Index = TargetObjectRegistry.bhkRigidBodyT_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "bhkConstraint")
	{
		Index = TargetObjectRegistry.bhkConstraint_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "bhkLimitedHingeConstraint")
	{
		Index = TargetObjectRegistry.bhkLimitedHingeConstraint_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "bhkMalleableConstraint")
	{
		Index = TargetObjectRegistry.bhkMalleableConstraint_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "bhkStiffSpringConstraint")
	{
		Index = TargetObjectRegistry.bhkStiffSpringConstraint_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "bhkRagdollConstraint")
	{
		Index = TargetObjectRegistry.bhkRagdollConstraint_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "bhkPrismaticConstraint")
	{
		Index = TargetObjectRegistry.bhkPrismaticConstraint_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "bhkHingeConstraint")
	{
		Index = TargetObjectRegistry.bhkHingeConstraint_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "bhkBallAndSocketConstraint")
	{
		Index = TargetObjectRegistry.bhkBallAndSocketConstraint_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "bhkBallSocketConstraintChain")
	{
		Index = TargetObjectRegistry.bhkBallSocketConstraintChain_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "bhkShape")
	{
		Index = TargetObjectRegistry.bhkShape_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "bhkTransformShape")
	{
		Index = TargetObjectRegistry.bhkTransformShape_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "bhkSphereRepShape")
	{
		Index = TargetObjectRegistry.bhkSphereRepShape_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "bhkConvexShape")
	{
		Index = TargetObjectRegistry.bhkConvexShape_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "bhkSphereShape")
	{
		Index = TargetObjectRegistry.bhkSphereShape_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "bhkCapsuleShape")
	{
		Index = TargetObjectRegistry.bhkCapsuleShape_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "bhkBoxShape")
	{
		Index = TargetObjectRegistry.bhkBoxShape_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "bhkConvexVerticesShape")
	{
		Index = TargetObjectRegistry.bhkConvexVerticesShape_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "bhkConvexTransformShape")
	{
		Index = TargetObjectRegistry.bhkConvexTransformShape_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "bhkMultiSphereShape")
	{
		Index = TargetObjectRegistry.bhkMultiSphereShape_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "bhkBvTreeShape")
	{
		Index = TargetObjectRegistry.bhkBvTreeShape_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "bhkMoppBvTreeShape")
	{
		Index = TargetObjectRegistry.bhkMoppBvTreeShape_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "bhkShapeCollection")
	{
		Index = TargetObjectRegistry.bhkShapeCollection_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "bhkListShape")
	{
		Index = TargetObjectRegistry.bhkListShape_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "bhkMeshShape")
	{
		Index = TargetObjectRegistry.bhkMeshShape_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "bhkPackedNiTriStripsShape")
	{
		Index = TargetObjectRegistry.bhkPackedNiTriStripsShape_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "bhkNiTriStripsShape")
	{
		Index = TargetObjectRegistry.bhkNiTriStripsShape_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiExtraData")
	{
		Index = TargetObjectRegistry.NiExtraData_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiInterpolator")
	{
		Index = TargetObjectRegistry.NiInterpolator_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiKeyBasedInterpolator")
	{
		Index = TargetObjectRegistry.NiKeyBasedInterpolator_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiFloatInterpolator")
	{
		Index = TargetObjectRegistry.NiFloatInterpolator_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiTransformInterpolator")
	{
		Index = TargetObjectRegistry.NiTransformInterpolator_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiPoint3Interpolator")
	{
		Index = TargetObjectRegistry.NiPoint3Interpolator_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiPathInterpolator")
	{
		Index = TargetObjectRegistry.NiPathInterpolator_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiBoolInterpolator")
	{
		Index = TargetObjectRegistry.NiBoolInterpolator_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiBoolTimelineInterpolator")
	{
		Index = TargetObjectRegistry.NiBoolTimelineInterpolator_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiBlendInterpolator")
	{
		Index = TargetObjectRegistry.NiBlendInterpolator_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiBSplineInterpolator")
	{
		Index = TargetObjectRegistry.NiBSplineInterpolator_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiObjectNET")
	{
		Index = TargetObjectRegistry.NiObjectNET_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiCollisionObject")
	{
		Index = TargetObjectRegistry.NiCollisionObject_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiCollisionData")
	{
		Index = TargetObjectRegistry.NiCollisionData_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "bhkNiCollisionObject")
	{
		Index = TargetObjectRegistry.bhkNiCollisionObject_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "bhkCollisionObject")
	{
		Index = TargetObjectRegistry.bhkCollisionObject_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "bhkBlendCollisionObject")
	{
		Index = TargetObjectRegistry.bhkBlendCollisionObject_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "bhkPCollisionObject")
	{
		Index = TargetObjectRegistry.bhkPCollisionObject_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "bhkSPCollisionObject")
	{
		Index = TargetObjectRegistry.bhkSPCollisionObject_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiAVObject")
	{
		Index = TargetObjectRegistry.NiAVObject_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiDynamicEffect")
	{
		Index = TargetObjectRegistry.NiDynamicEffect_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiLight")
	{
		Index = TargetObjectRegistry.NiLight_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiProperty")
	{
		Index = TargetObjectRegistry.NiProperty_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiTransparentProperty")
	{
		Index = TargetObjectRegistry.NiTransparentProperty_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiPSysModifier")
	{
		Index = TargetObjectRegistry.NiPSysModifier_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiPSysEmitter")
	{
		Index = TargetObjectRegistry.NiPSysEmitter_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiPSysVolumeEmitter")
	{
		Index = TargetObjectRegistry.NiPSysVolumeEmitter_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiTimeController")
	{
		Index = TargetObjectRegistry.NiTimeController_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiInterpController")
	{
		Index = TargetObjectRegistry.NiInterpController_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiMultiTargetTransformController")
	{
		Index = TargetObjectRegistry.NiMultiTargetTransformController_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiGeomMorpherController")
	{
		Index = TargetObjectRegistry.NiGeomMorpherController_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiMorphController")
	{
		Index = TargetObjectRegistry.NiMorphController_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiMorpherController")
	{
		Index = TargetObjectRegistry.NiMorpherController_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiSingleInterpController")
	{
		Index = TargetObjectRegistry.NiSingleInterpController_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiKeyframeController")
	{
		Index = TargetObjectRegistry.NiKeyframeController_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiTransformController")
	{
		Index = TargetObjectRegistry.NiTransformController_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiPSysModifierCtlr")
	{
		Index = TargetObjectRegistry.NiPSysModifierCtlr_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiPSysEmitterCtlr")
	{
		Index = TargetObjectRegistry.NiPSysEmitterCtlr_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiPSysModifierBoolCtlr")
	{
		Index = TargetObjectRegistry.NiPSysModifierBoolCtlr_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiPSysModifierActiveCtlr")
	{
		Index = TargetObjectRegistry.NiPSysModifierActiveCtlr_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiPSysModifierFloatCtlr")
	{
		Index = TargetObjectRegistry.NiPSysModifierFloatCtlr_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiPSysEmitterDeclinationCtlr")
	{
		Index = TargetObjectRegistry.NiPSysEmitterDeclinationCtlr_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiPSysEmitterDeclinationVarCtlr")
	{
		Index = TargetObjectRegistry.NiPSysEmitterDeclinationVarCtlr_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiPSysEmitterInitialRadiusCtlr")
	{
		Index = TargetObjectRegistry.NiPSysEmitterInitialRadiusCtlr_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiPSysEmitterLifeSpanCtlr")
	{
		Index = TargetObjectRegistry.NiPSysEmitterLifeSpanCtlr_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiPSysEmitterSpeedCtlr")
	{
		Index = TargetObjectRegistry.NiPSysEmitterSpeedCtlr_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiPSysGravityStrengthCtlr")
	{
		Index = TargetObjectRegistry.NiPSysGravityStrengthCtlr_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiFloatInterpController")
	{
		Index = TargetObjectRegistry.NiFloatInterpController_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiFlipController")
	{
		Index = TargetObjectRegistry.NiFlipController_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiAlphaController")
	{
		Index = TargetObjectRegistry.NiAlphaController_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiTextureTransformController")
	{
		Index = TargetObjectRegistry.NiTextureTransformController_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiLightDimmerController")
	{
		Index = TargetObjectRegistry.NiLightDimmerController_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiBoolInterpController")
	{
		Index = TargetObjectRegistry.NiBoolInterpController_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiVisController")
	{
		Index = TargetObjectRegistry.NiVisController_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiPoint3InterpController")
	{
		Index = TargetObjectRegistry.NiPoint3InterpController_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiMaterialColorController")
	{
		Index = TargetObjectRegistry.NiMaterialColorController_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiLightColorController")
	{
		Index = TargetObjectRegistry.NiLightColorController_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiExtraDataController")
	{
		Index = TargetObjectRegistry.NiExtraDataController_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiFloatExtraDataController")
	{
		Index = TargetObjectRegistry.NiFloatExtraDataController_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiBoneLODController")
	{
		Index = TargetObjectRegistry.NiBoneLODController_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiBSBoneLODController")
	{
		Index = TargetObjectRegistry.NiBSBoneLODController_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiGeometry")
	{
		Index = TargetObjectRegistry.NiGeometry_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiTriBasedGeom")
	{
		Index = TargetObjectRegistry.NiTriBasedGeom_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiGeometryData")
	{
		Index = TargetObjectRegistry.NiGeometryData_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "AbstractAdditionalGeometryData")
	{
		Index = TargetObjectRegistry.AbstractAdditionalGeometryData_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiTriBasedGeomData")
	{
		Index = TargetObjectRegistry.NiTriBasedGeomData_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "bhkBlendController")
	{
		Index = TargetObjectRegistry.bhkBlendController_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "BSBound")
	{
		Index = TargetObjectRegistry.BSBound_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "BSFurnitureMarker")
	{
		Index = TargetObjectRegistry.BSFurnitureMarker_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "BSParentVelocityModifier")
	{
		Index = TargetObjectRegistry.BSParentVelocityModifier_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "BSPSysArrayEmitter")
	{
		Index = TargetObjectRegistry.BSPSysArrayEmitter_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "BSWindModifier")
	{
		Index = TargetObjectRegistry.BSWindModifier_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "hkPackedNiTriStripsData")
	{
		Index = TargetObjectRegistry.hkPackedNiTriStripsData_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiAlphaProperty")
	{
		Index = TargetObjectRegistry.NiAlphaProperty_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiAmbientLight")
	{
		Index = TargetObjectRegistry.NiAmbientLight_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiParticlesData")
	{
		Index = TargetObjectRegistry.NiParticlesData_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiRotatingParticlesData")
	{
		Index = TargetObjectRegistry.NiRotatingParticlesData_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiAutoNormalParticlesData")
	{
		Index = TargetObjectRegistry.NiAutoNormalParticlesData_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiPSysData")
	{
		Index = TargetObjectRegistry.NiPSysData_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiMeshPSysData")
	{
		Index = TargetObjectRegistry.NiMeshPSysData_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiBinaryExtraData")
	{
		Index = TargetObjectRegistry.NiBinaryExtraData_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiBinaryVoxelExtraData")
	{
		Index = TargetObjectRegistry.NiBinaryVoxelExtraData_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiBinaryVoxelData")
	{
		Index = TargetObjectRegistry.NiBinaryVoxelData_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiBlendBoolInterpolator")
	{
		Index = TargetObjectRegistry.NiBlendBoolInterpolator_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiBlendFloatInterpolator")
	{
		Index = TargetObjectRegistry.NiBlendFloatInterpolator_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiBlendPoint3Interpolator")
	{
		Index = TargetObjectRegistry.NiBlendPoint3Interpolator_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiBlendTransformInterpolator")
	{
		Index = TargetObjectRegistry.NiBlendTransformInterpolator_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiBoolData")
	{
		Index = TargetObjectRegistry.NiBoolData_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiBooleanExtraData")
	{
		Index = TargetObjectRegistry.NiBooleanExtraData_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiBSplineBasisData")
	{
		Index = TargetObjectRegistry.NiBSplineBasisData_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiBSplineFloatInterpolator")
	{
		Index = TargetObjectRegistry.NiBSplineFloatInterpolator_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiBSplineCompFloatInterpolator")
	{
		Index = TargetObjectRegistry.NiBSplineCompFloatInterpolator_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiBSplinePoint3Interpolator")
	{
		Index = TargetObjectRegistry.NiBSplinePoint3Interpolator_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiBSplineCompPoint3Interpolator")
	{
		Index = TargetObjectRegistry.NiBSplineCompPoint3Interpolator_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiBSplineTransformInterpolator")
	{
		Index = TargetObjectRegistry.NiBSplineTransformInterpolator_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiBSplineCompTransformInterpolator")
	{
		Index = TargetObjectRegistry.NiBSplineCompTransformInterpolator_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "BSRotAccumTransfInterpolator")
	{
		Index = TargetObjectRegistry.BSRotAccumTransfInterpolator_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiBSplineData")
	{
		Index = TargetObjectRegistry.NiBSplineData_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiCamera")
	{
		Index = TargetObjectRegistry.NiCamera_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiColorData")
	{
		Index = TargetObjectRegistry.NiColorData_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiColorExtraData")
	{
		Index = TargetObjectRegistry.NiColorExtraData_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiControllerManager")
	{
		Index = TargetObjectRegistry.NiControllerManager_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiSequence")
	{
		Index = TargetObjectRegistry.NiSequence_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiControllerSequence")
	{
		Index = TargetObjectRegistry.NiControllerSequence_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiAVObjectPalette")
	{
		Index = TargetObjectRegistry.NiAVObjectPalette_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiDefaultAVObjectPalette")
	{
		Index = TargetObjectRegistry.NiDefaultAVObjectPalette_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiDirectionalLight")
	{
		Index = TargetObjectRegistry.NiDirectionalLight_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiDitherProperty")
	{
		Index = TargetObjectRegistry.NiDitherProperty_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiRollController")
	{
		Index = TargetObjectRegistry.NiRollController_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiFloatData")
	{
		Index = TargetObjectRegistry.NiFloatData_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiFloatExtraData")
	{
		Index = TargetObjectRegistry.NiFloatExtraData_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiFloatsExtraData")
	{
		Index = TargetObjectRegistry.NiFloatsExtraData_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiFogProperty")
	{
		Index = TargetObjectRegistry.NiFogProperty_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiGravity")
	{
		Index = TargetObjectRegistry.NiGravity_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiIntegerExtraData")
	{
		Index = TargetObjectRegistry.NiIntegerExtraData_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "BSXFlags")
	{
		Index = TargetObjectRegistry.BSXFlags_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiIntegersExtraData")
	{
		Index = TargetObjectRegistry.NiIntegersExtraData_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "BSKeyframeController")
	{
		Index = TargetObjectRegistry.BSKeyframeController_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiKeyframeData")
	{
		Index = TargetObjectRegistry.NiKeyframeData_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiLookAtController")
	{
		Index = TargetObjectRegistry.NiLookAtController_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiLookAtInterpolator")
	{
		Index = TargetObjectRegistry.NiLookAtInterpolator_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiMaterialProperty")
	{
		Index = TargetObjectRegistry.NiMaterialProperty_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiMorphData")
	{
		Index = TargetObjectRegistry.NiMorphData_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiNode")
	{
		Index = TargetObjectRegistry.NiNode_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiBone")
	{
		Index = TargetObjectRegistry.NiBone_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "AvoidNode")
	{
		Index = TargetObjectRegistry.AvoidNode_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "FxWidget")
	{
		Index = TargetObjectRegistry.FxWidget_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "FxButton")
	{
		Index = TargetObjectRegistry.FxButton_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "FxRadioButton")
	{
		Index = TargetObjectRegistry.FxRadioButton_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiBillboardNode")
	{
		Index = TargetObjectRegistry.NiBillboardNode_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiBSAnimationNode")
	{
		Index = TargetObjectRegistry.NiBSAnimationNode_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiBSParticleNode")
	{
		Index = TargetObjectRegistry.NiBSParticleNode_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiSwitchNode")
	{
		Index = TargetObjectRegistry.NiSwitchNode_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiLODNode")
	{
		Index = TargetObjectRegistry.NiLODNode_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiPalette")
	{
		Index = TargetObjectRegistry.NiPalette_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiParticleBomb")
	{
		Index = TargetObjectRegistry.NiParticleBomb_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiParticleColorModifier")
	{
		Index = TargetObjectRegistry.NiParticleColorModifier_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiParticleGrowFade")
	{
		Index = TargetObjectRegistry.NiParticleGrowFade_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiParticleMeshModifier")
	{
		Index = TargetObjectRegistry.NiParticleMeshModifier_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiParticleRotation")
	{
		Index = TargetObjectRegistry.NiParticleRotation_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiParticles")
	{
		Index = TargetObjectRegistry.NiParticles_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiAutoNormalParticles")
	{
		Index = TargetObjectRegistry.NiAutoNormalParticles_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiParticleMeshes")
	{
		Index = TargetObjectRegistry.NiParticleMeshes_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiParticleMeshesData")
	{
		Index = TargetObjectRegistry.NiParticleMeshesData_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiParticleSystem")
	{
		Index = TargetObjectRegistry.NiParticleSystem_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiMeshParticleSystem")
	{
		Index = TargetObjectRegistry.NiMeshParticleSystem_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiParticleSystemController")
	{
		Index = TargetObjectRegistry.NiParticleSystemController_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiBSPArrayController")
	{
		Index = TargetObjectRegistry.NiBSPArrayController_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiPathController")
	{
		Index = TargetObjectRegistry.NiPathController_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "ATextureRenderData")
	{
		Index = TargetObjectRegistry.ATextureRenderData_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiPersistentSrcTextureRendererData")
	{
		Index = TargetObjectRegistry.NiPersistentSrcTextureRendererData_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiPixelData")
	{
		Index = TargetObjectRegistry.NiPixelData_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiPlanarCollider")
	{
		Index = TargetObjectRegistry.NiPlanarCollider_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiPointLight")
	{
		Index = TargetObjectRegistry.NiPointLight_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiPosData")
	{
		Index = TargetObjectRegistry.NiPosData_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiPSysAgeDeathModifier")
	{
		Index = TargetObjectRegistry.NiPSysAgeDeathModifier_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiPSysBombModifier")
	{
		Index = TargetObjectRegistry.NiPSysBombModifier_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiPSysBoundUpdateModifier")
	{
		Index = TargetObjectRegistry.NiPSysBoundUpdateModifier_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiPSysBoxEmitter")
	{
		Index = TargetObjectRegistry.NiPSysBoxEmitter_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiPSysColliderManager")
	{
		Index = TargetObjectRegistry.NiPSysColliderManager_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiPSysColorModifier")
	{
		Index = TargetObjectRegistry.NiPSysColorModifier_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiPSysCylinderEmitter")
	{
		Index = TargetObjectRegistry.NiPSysCylinderEmitter_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiPSysDragModifier")
	{
		Index = TargetObjectRegistry.NiPSysDragModifier_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiPSysEmitterCtlrData")
	{
		Index = TargetObjectRegistry.NiPSysEmitterCtlrData_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiPSysGravityModifier")
	{
		Index = TargetObjectRegistry.NiPSysGravityModifier_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiPSysGrowFadeModifier")
	{
		Index = TargetObjectRegistry.NiPSysGrowFadeModifier_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiPSysMeshEmitter")
	{
		Index = TargetObjectRegistry.NiPSysMeshEmitter_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiPSysMeshUpdateModifier")
	{
		Index = TargetObjectRegistry.NiPSysMeshUpdateModifier_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "BSPSysInheritVelocityModifier")
	{
		Index = TargetObjectRegistry.BSPSysInheritVelocityModifier_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "BSPSysHavokUpdateModifier")
	{
		Index = TargetObjectRegistry.BSPSysHavokUpdateModifier_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "BSPSysRecycleBoundModifier")
	{
		Index = TargetObjectRegistry.BSPSysRecycleBoundModifier_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "BSPSysSubTexModifier")
	{
		Index = TargetObjectRegistry.BSPSysSubTexModifier_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiPSysPlanarCollider")
	{
		Index = TargetObjectRegistry.NiPSysPlanarCollider_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiPSysSphericalCollider")
	{
		Index = TargetObjectRegistry.NiPSysSphericalCollider_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiPSysPositionModifier")
	{
		Index = TargetObjectRegistry.NiPSysPositionModifier_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiPSysResetOnLoopCtlr")
	{
		Index = TargetObjectRegistry.NiPSysResetOnLoopCtlr_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiPSysRotationModifier")
	{
		Index = TargetObjectRegistry.NiPSysRotationModifier_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiPSysSpawnModifier")
	{
		Index = TargetObjectRegistry.NiPSysSpawnModifier_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiPSysSphereEmitter")
	{
		Index = TargetObjectRegistry.NiPSysSphereEmitter_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiPSysUpdateCtlr")
	{
		Index = TargetObjectRegistry.NiPSysUpdateCtlr_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiPSysFieldModifier")
	{
		Index = TargetObjectRegistry.NiPSysFieldModifier_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiPSysVortexFieldModifier")
	{
		Index = TargetObjectRegistry.NiPSysVortexFieldModifier_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiPSysGravityFieldModifier")
	{
		Index = TargetObjectRegistry.NiPSysGravityFieldModifier_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiPSysDragFieldModifier")
	{
		Index = TargetObjectRegistry.NiPSysDragFieldModifier_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiPSysTurbulenceFieldModifier")
	{
		Index = TargetObjectRegistry.NiPSysTurbulenceFieldModifier_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "BSPSysLODModifier")
	{
		Index = TargetObjectRegistry.BSPSysLODModifier_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "BSPSysScaleModifier")
	{
		Index = TargetObjectRegistry.BSPSysScaleModifier_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiPSysFieldMagnitudeCtlr")
	{
		Index = TargetObjectRegistry.NiPSysFieldMagnitudeCtlr_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiPSysFieldAttenuationCtlr")
	{
		Index = TargetObjectRegistry.NiPSysFieldAttenuationCtlr_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiPSysFieldMaxDistanceCtlr")
	{
		Index = TargetObjectRegistry.NiPSysFieldMaxDistanceCtlr_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiPSysAirFieldAirFrictionCtlr")
	{
		Index = TargetObjectRegistry.NiPSysAirFieldAirFrictionCtlr_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiPSysAirFieldInheritVelocityCtlr")
	{
		Index = TargetObjectRegistry.NiPSysAirFieldInheritVelocityCtlr_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiPSysAirFieldSpreadCtlr")
	{
		Index = TargetObjectRegistry.NiPSysAirFieldSpreadCtlr_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiPSysInitialRotSpeedCtlr")
	{
		Index = TargetObjectRegistry.NiPSysInitialRotSpeedCtlr_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiPSysInitialRotSpeedVarCtlr")
	{
		Index = TargetObjectRegistry.NiPSysInitialRotSpeedVarCtlr_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiPSysInitialRotAngleCtlr")
	{
		Index = TargetObjectRegistry.NiPSysInitialRotAngleCtlr_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiPSysInitialRotAngleVarCtlr")
	{
		Index = TargetObjectRegistry.NiPSysInitialRotAngleVarCtlr_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiPSysEmitterPlanarAngleCtlr")
	{
		Index = TargetObjectRegistry.NiPSysEmitterPlanarAngleCtlr_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiPSysEmitterPlanarAngleVarCtlr")
	{
		Index = TargetObjectRegistry.NiPSysEmitterPlanarAngleVarCtlr_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiPSysAirFieldModifier")
	{
		Index = TargetObjectRegistry.NiPSysAirFieldModifier_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiPSysTrailEmitter")
	{
		Index = TargetObjectRegistry.NiPSysTrailEmitter_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiLightIntensityController")
	{
		Index = TargetObjectRegistry.NiLightIntensityController_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiPSysRadialFieldModifier")
	{
		Index = TargetObjectRegistry.NiPSysRadialFieldModifier_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiLODData")
	{
		Index = TargetObjectRegistry.NiLODData_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiRangeLODData")
	{
		Index = TargetObjectRegistry.NiRangeLODData_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiScreenLODData")
	{
		Index = TargetObjectRegistry.NiScreenLODData_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiRotatingParticles")
	{
		Index = TargetObjectRegistry.NiRotatingParticles_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiSequenceStreamHelper")
	{
		Index = TargetObjectRegistry.NiSequenceStreamHelper_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiShadeProperty")
	{
		Index = TargetObjectRegistry.NiShadeProperty_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiSkinData")
	{
		Index = TargetObjectRegistry.NiSkinData_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiSkinInstance")
	{
		Index = TargetObjectRegistry.NiSkinInstance_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiTriShapeSkinController")
	{
		Index = TargetObjectRegistry.NiTriShapeSkinController_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiClodSkinInstance")
	{
		Index = TargetObjectRegistry.NiClodSkinInstance_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiSkinPartition")
	{
		Index = TargetObjectRegistry.NiSkinPartition_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiTexture")
	{
		Index = TargetObjectRegistry.NiTexture_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiSourceTexture")
	{
		Index = TargetObjectRegistry.NiSourceTexture_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiSpecularProperty")
	{
		Index = TargetObjectRegistry.NiSpecularProperty_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiSphericalCollider")
	{
		Index = TargetObjectRegistry.NiSphericalCollider_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiSpotLight")
	{
		Index = TargetObjectRegistry.NiSpotLight_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiStencilProperty")
	{
		Index = TargetObjectRegistry.NiStencilProperty_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiStringExtraData")
	{
		Index = TargetObjectRegistry.NiStringExtraData_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiStringPalette")
	{
		Index = TargetObjectRegistry.NiStringPalette_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiStringsExtraData")
	{
		Index = TargetObjectRegistry.NiStringsExtraData_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiTextKeyExtraData")
	{
		Index = TargetObjectRegistry.NiTextKeyExtraData_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiTextureEffect")
	{
		Index = TargetObjectRegistry.NiTextureEffect_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiTextureModeProperty")
	{
		Index = TargetObjectRegistry.NiTextureModeProperty_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiImage")
	{
		Index = TargetObjectRegistry.NiImage_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiTextureProperty")
	{
		Index = TargetObjectRegistry.NiTextureProperty_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiMultiTextureProperty")
	{
		Index = TargetObjectRegistry.NiMultiTextureProperty_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiTexturingProperty")
	{
		Index = TargetObjectRegistry.NiTexturingProperty_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiTransformData")
	{
		Index = TargetObjectRegistry.NiTransformData_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiTriShape")
	{
		Index = TargetObjectRegistry.NiTriShape_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiTriShapeData")
	{
		Index = TargetObjectRegistry.NiTriShapeData_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiTriStrips")
	{
		Index = TargetObjectRegistry.NiTriStrips_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiTriStripsData")
	{
		Index = TargetObjectRegistry.NiTriStripsData_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiEnvMappedTriShape")
	{
		Index = TargetObjectRegistry.NiEnvMappedTriShape_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiEnvMappedTriShapeData")
	{
		Index = TargetObjectRegistry.NiEnvMappedTriShapeData_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiBezierTriangle4")
	{
		Index = TargetObjectRegistry.NiBezierTriangle4_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiBezierMesh")
	{
		Index = TargetObjectRegistry.NiBezierMesh_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiClod")
	{
		Index = TargetObjectRegistry.NiClod_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiClodData")
	{
		Index = TargetObjectRegistry.NiClodData_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiUVController")
	{
		Index = TargetObjectRegistry.NiUVController_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiUVData")
	{
		Index = TargetObjectRegistry.NiUVData_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiVectorExtraData")
	{
		Index = TargetObjectRegistry.NiVectorExtraData_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiVertexColorProperty")
	{
		Index = TargetObjectRegistry.NiVertexColorProperty_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiVertWeightsExtraData")
	{
		Index = TargetObjectRegistry.NiVertWeightsExtraData_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiVisData")
	{
		Index = TargetObjectRegistry.NiVisData_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiWireframeProperty")
	{
		Index = TargetObjectRegistry.NiWireframeProperty_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiZBufferProperty")
	{
		Index = TargetObjectRegistry.NiZBufferProperty_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "RootCollisionNode")
	{
		Index = TargetObjectRegistry.RootCollisionNode_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiRawImageData")
	{
		Index = TargetObjectRegistry.NiRawImageData_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiSortAdjustNode")
	{
		Index = TargetObjectRegistry.NiSortAdjustNode_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiSourceCubeMap")
	{
		Index = TargetObjectRegistry.NiSourceCubeMap_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiPhysXProp")
	{
		Index = TargetObjectRegistry.NiPhysXProp_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiPhysXPropDesc")
	{
		Index = TargetObjectRegistry.NiPhysXPropDesc_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiPhysXActorDesc")
	{
		Index = TargetObjectRegistry.NiPhysXActorDesc_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiPhysXBodyDesc")
	{
		Index = TargetObjectRegistry.NiPhysXBodyDesc_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiPhysXD6JointDesc")
	{
		Index = TargetObjectRegistry.NiPhysXD6JointDesc_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiPhysXShapeDesc")
	{
		Index = TargetObjectRegistry.NiPhysXShapeDesc_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiPhysXMeshDesc")
	{
		Index = TargetObjectRegistry.NiPhysXMeshDesc_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiPhysXMaterialDesc")
	{
		Index = TargetObjectRegistry.NiPhysXMaterialDesc_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiPhysXKinematicSrc")
	{
		Index = TargetObjectRegistry.NiPhysXKinematicSrc_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiPhysXTransformDest")
	{
		Index = TargetObjectRegistry.NiPhysXTransformDest_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiArkAnimationExtraData")
	{
		Index = TargetObjectRegistry.NiArkAnimationExtraData_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiArkImporterExtraData")
	{
		Index = TargetObjectRegistry.NiArkImporterExtraData_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiArkTextureExtraData")
	{
		Index = TargetObjectRegistry.NiArkTextureExtraData_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiArkViewportInfoExtraData")
	{
		Index = TargetObjectRegistry.NiArkViewportInfoExtraData_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiArkShaderExtraData")
	{
		Index = TargetObjectRegistry.NiArkShaderExtraData_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiLines")
	{
		Index = TargetObjectRegistry.NiLines_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiLinesData")
	{
		Index = TargetObjectRegistry.NiLinesData_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiScreenElementsData")
	{
		Index = TargetObjectRegistry.NiScreenElementsData_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiScreenElements")
	{
		Index = TargetObjectRegistry.NiScreenElements_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiRoomGroup")
	{
		Index = TargetObjectRegistry.NiRoomGroup_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiRoom")
	{
		Index = TargetObjectRegistry.NiRoom_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiPortal")
	{
		Index = TargetObjectRegistry.NiPortal_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "BSFadeNode")
	{
		Index = TargetObjectRegistry.BSFadeNode_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "BSShaderProperty")
	{
		Index = TargetObjectRegistry.BSShaderProperty_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "BSShaderLightingProperty")
	{
		Index = TargetObjectRegistry.BSShaderLightingProperty_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "BSShaderNoLightingProperty")
	{
		Index = TargetObjectRegistry.BSShaderNoLightingProperty_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "BSShaderPPLightingProperty")
	{
		Index = TargetObjectRegistry.BSShaderPPLightingProperty_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "BSEffectShaderPropertyFloatController")
	{
		Index = TargetObjectRegistry.BSEffectShaderPropertyFloatController_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "BSEffectShaderPropertyColorController")
	{
		Index = TargetObjectRegistry.BSEffectShaderPropertyColorController_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "BSLightingShaderPropertyFloatController")
	{
		Index = TargetObjectRegistry.BSLightingShaderPropertyFloatController_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "BSLightingShaderPropertyColorController")
	{
		Index = TargetObjectRegistry.BSLightingShaderPropertyColorController_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "BSNiAlphaPropertyTestRefController")
	{
		Index = TargetObjectRegistry.BSNiAlphaPropertyTestRefController_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "BSProceduralLightningController")
	{
		Index = TargetObjectRegistry.BSProceduralLightningController_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "BSShaderTextureSet")
	{
		Index = TargetObjectRegistry.BSShaderTextureSet_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "WaterShaderProperty")
	{
		Index = TargetObjectRegistry.WaterShaderProperty_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "SkyShaderProperty")
	{
		Index = TargetObjectRegistry.SkyShaderProperty_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "TileShaderProperty")
	{
		Index = TargetObjectRegistry.TileShaderProperty_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "DistantLODShaderProperty")
	{
		Index = TargetObjectRegistry.DistantLODShaderProperty_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "BSDistantTreeShaderProperty")
	{
		Index = TargetObjectRegistry.BSDistantTreeShaderProperty_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "TallGrassShaderProperty")
	{
		Index = TargetObjectRegistry.TallGrassShaderProperty_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "VolumetricFogShaderProperty")
	{
		Index = TargetObjectRegistry.VolumetricFogShaderProperty_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "HairShaderProperty")
	{
		Index = TargetObjectRegistry.HairShaderProperty_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "Lighting30ShaderProperty")
	{
		Index = TargetObjectRegistry.Lighting30ShaderProperty_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "BSLightingShaderProperty")
	{
		Index = TargetObjectRegistry.BSLightingShaderProperty_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "BSEffectShaderProperty")
	{
		Index = TargetObjectRegistry.BSEffectShaderProperty_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "BSWaterShaderProperty")
	{
		Index = TargetObjectRegistry.BSWaterShaderProperty_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "BSSkyShaderProperty")
	{
		Index = TargetObjectRegistry.BSSkyShaderProperty_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "BSDismemberSkinInstance")
	{
		Index = TargetObjectRegistry.BSDismemberSkinInstance_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "BSDecalPlacementVectorExtraData")
	{
		Index = TargetObjectRegistry.BSDecalPlacementVectorExtraData_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "BSPSysSimpleColorModifier")
	{
		Index = TargetObjectRegistry.BSPSysSimpleColorModifier_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "BSValueNode")
	{
		Index = TargetObjectRegistry.BSValueNode_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "BSStripParticleSystem")
	{
		Index = TargetObjectRegistry.BSStripParticleSystem_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "BSStripPSysData")
	{
		Index = TargetObjectRegistry.BSStripPSysData_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "BSPSysStripUpdateModifier")
	{
		Index = TargetObjectRegistry.BSPSysStripUpdateModifier_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "BSMaterialEmittanceMultController")
	{
		Index = TargetObjectRegistry.BSMaterialEmittanceMultController_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "BSMasterParticleSystem")
	{
		Index = TargetObjectRegistry.BSMasterParticleSystem_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "BSPSysMultiTargetEmitterCtlr")
	{
		Index = TargetObjectRegistry.BSPSysMultiTargetEmitterCtlr_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "BSRefractionStrengthController")
	{
		Index = TargetObjectRegistry.BSRefractionStrengthController_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "BSOrderedNode")
	{
		Index = TargetObjectRegistry.BSOrderedNode_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "BSBlastNode")
	{
		Index = TargetObjectRegistry.BSBlastNode_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "BSDamageStage")
	{
		Index = TargetObjectRegistry.BSDamageStage_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "BSRefractionFirePeriodController")
	{
		Index = TargetObjectRegistry.BSRefractionFirePeriodController_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "bhkConvexListShape")
	{
		Index = TargetObjectRegistry.bhkConvexListShape_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "BSTreadTransfInterpolator")
	{
		Index = TargetObjectRegistry.BSTreadTransfInterpolator_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "BSAnimNotes")
	{
		Index = TargetObjectRegistry.BSAnimNotes_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "bhkLiquidAction")
	{
		Index = TargetObjectRegistry.bhkLiquidAction_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "BSMultiBoundNode")
	{
		Index = TargetObjectRegistry.BSMultiBoundNode_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "BSMultiBound")
	{
		Index = TargetObjectRegistry.BSMultiBound_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "BSMultiBoundData")
	{
		Index = TargetObjectRegistry.BSMultiBoundData_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "BSMultiBoundOBB")
	{
		Index = TargetObjectRegistry.BSMultiBoundOBB_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "BSMultiBoundSphere")
	{
		Index = TargetObjectRegistry.BSMultiBoundSphere_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "BSSegmentedTriShape")
	{
		Index = TargetObjectRegistry.BSSegmentedTriShape_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "BSMultiBoundAABB")
	{
		Index = TargetObjectRegistry.BSMultiBoundAABB_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiAdditionalGeometryData")
	{
		Index = TargetObjectRegistry.NiAdditionalGeometryData_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "BSPackedAdditionalGeometryData")
	{
		Index = TargetObjectRegistry.BSPackedAdditionalGeometryData_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "BSWArray")
	{
		Index = TargetObjectRegistry.BSWArray_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "bhkAabbPhantom")
	{
		Index = TargetObjectRegistry.bhkAabbPhantom_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "BSFrustumFOVController")
	{
		Index = TargetObjectRegistry.BSFrustumFOVController_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "BSDebrisNode")
	{
		Index = TargetObjectRegistry.BSDebrisNode_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "bhkBreakableConstraint")
	{
		Index = TargetObjectRegistry.bhkBreakableConstraint_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "bhkOrientHingedBodyAction")
	{
		Index = TargetObjectRegistry.bhkOrientHingedBodyAction_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiDataStream")
	{
		Index = TargetObjectRegistry.NiDataStream_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiRenderObject")
	{
		Index = TargetObjectRegistry.NiRenderObject_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiMeshModifier")
	{
		Index = TargetObjectRegistry.NiMeshModifier_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiMesh")
	{
		Index = TargetObjectRegistry.NiMesh_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiMorphWeightsController")
	{
		Index = TargetObjectRegistry.NiMorphWeightsController_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiMorphMeshModifier")
	{
		Index = TargetObjectRegistry.NiMorphMeshModifier_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiSkinningMeshModifier")
	{
		Index = TargetObjectRegistry.NiSkinningMeshModifier_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiInstancingMeshModifier")
	{
		Index = TargetObjectRegistry.NiInstancingMeshModifier_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiSkinningLODController")
	{
		Index = TargetObjectRegistry.NiSkinningLODController_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiPSParticleSystem")
	{
		Index = TargetObjectRegistry.NiPSParticleSystem_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiPSMeshParticleSystem")
	{
		Index = TargetObjectRegistry.NiPSMeshParticleSystem_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiPSEmitParticlesCtlr")
	{
		Index = TargetObjectRegistry.NiPSEmitParticlesCtlr_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiPSForceActiveCtlr")
	{
		Index = TargetObjectRegistry.NiPSForceActiveCtlr_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiPSSimulator")
	{
		Index = TargetObjectRegistry.NiPSSimulator_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiPSSimulatorStep")
	{
		Index = TargetObjectRegistry.NiPSSimulatorStep_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiPSSimulatorGeneralStep")
	{
		Index = TargetObjectRegistry.NiPSSimulatorGeneralStep_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiPSSimulatorForcesStep")
	{
		Index = TargetObjectRegistry.NiPSSimulatorForcesStep_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiPSSimulatorCollidersStep")
	{
		Index = TargetObjectRegistry.NiPSSimulatorCollidersStep_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiPSSimulatorMeshAlignStep")
	{
		Index = TargetObjectRegistry.NiPSSimulatorMeshAlignStep_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiPSSimulatorFinalStep")
	{
		Index = TargetObjectRegistry.NiPSSimulatorFinalStep_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiPSFacingQuadGenerator")
	{
		Index = TargetObjectRegistry.NiPSFacingQuadGenerator_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiShadowGenerator")
	{
		Index = TargetObjectRegistry.NiShadowGenerator_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiPSBoundUpdater")
	{
		Index = TargetObjectRegistry.NiPSBoundUpdater_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiPSDragForce")
	{
		Index = TargetObjectRegistry.NiPSDragForce_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiPSGravityForce")
	{
		Index = TargetObjectRegistry.NiPSGravityForce_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiPSBoxEmitter")
	{
		Index = TargetObjectRegistry.NiPSBoxEmitter_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiPSMeshEmitter")
	{
		Index = TargetObjectRegistry.NiPSMeshEmitter_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiPSGravityStrengthCtlr")
	{
		Index = TargetObjectRegistry.NiPSGravityStrengthCtlr_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiPSPlanarCollider")
	{
		Index = TargetObjectRegistry.NiPSPlanarCollider_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiPSEmitterSpeedCtlr")
	{
		Index = TargetObjectRegistry.NiPSEmitterSpeedCtlr_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiPSEmitterRadiusCtlr")
	{
		Index = TargetObjectRegistry.NiPSEmitterRadiusCtlr_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiPSResetOnLoopCtlr")
	{
		Index = TargetObjectRegistry.NiPSResetOnLoopCtlr_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiPSSphereEmitter")
	{
		Index = TargetObjectRegistry.NiPSSphereEmitter_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiPSCylinderEmitter")
	{
		Index = TargetObjectRegistry.NiPSCylinderEmitter_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiPSEmitterDeclinationCtlr")
	{
		Index = TargetObjectRegistry.NiPSEmitterDeclinationCtlr_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiPSEmitterDeclinationVarCtlr")
	{
		Index = TargetObjectRegistry.NiPSEmitterDeclinationVarCtlr_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiPSEmitterPlanarAngleCtlr")
	{
		Index = TargetObjectRegistry.NiPSEmitterPlanarAngleCtlr_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiPSEmitterPlanarAngleVarCtlr")
	{
		Index = TargetObjectRegistry.NiPSEmitterPlanarAngleVarCtlr_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiPSEmitterRotAngleCtlr")
	{
		Index = TargetObjectRegistry.NiPSEmitterRotAngleCtlr_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiPSEmitterRotAngleVarCtlr")
	{
		Index = TargetObjectRegistry.NiPSEmitterRotAngleVarCtlr_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiPSEmitterRotSpeedCtlr")
	{
		Index = TargetObjectRegistry.NiPSEmitterRotSpeedCtlr_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiPSEmitterRotSpeedVarCtlr")
	{
		Index = TargetObjectRegistry.NiPSEmitterRotSpeedVarCtlr_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiPSEmitterLifeSpanCtlr")
	{
		Index = TargetObjectRegistry.NiPSEmitterLifeSpanCtlr_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiPSBombForce")
	{
		Index = TargetObjectRegistry.NiPSBombForce_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiPSSphericalCollider")
	{
		Index = TargetObjectRegistry.NiPSSphericalCollider_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiPSSpawner")
	{
		Index = TargetObjectRegistry.NiPSSpawner_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiSequenceData")
	{
		Index = TargetObjectRegistry.NiSequenceData_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiTransformEvaluator")
	{
		Index = TargetObjectRegistry.NiTransformEvaluator_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiBSplineCompTransformEvaluator")
	{
		Index = TargetObjectRegistry.NiBSplineCompTransformEvaluator_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiMeshHWInstance")
	{
		Index = TargetObjectRegistry.NiMeshHWInstance_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiFurSpringController")
	{
		Index = TargetObjectRegistry.NiFurSpringController_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "CStreamableAssetData")
	{
		Index = TargetObjectRegistry.CStreamableAssetData_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "bhkCompressedMeshShape")
	{
		Index = TargetObjectRegistry.bhkCompressedMeshShape_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "bhkCompressedMeshShapeData")
	{
		Index = TargetObjectRegistry.bhkCompressedMeshShapeData_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "BSInvMarker")
	{
		Index = TargetObjectRegistry.BSInvMarker_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "BSBoneLODExtraData")
	{
		Index = TargetObjectRegistry.BSBoneLODExtraData_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "BSBehaviorGraphExtraData")
	{
		Index = TargetObjectRegistry.BSBehaviorGraphExtraData_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "BSLagBoneController")
	{
		Index = TargetObjectRegistry.BSLagBoneController_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "BSLODTriShape")
	{
		Index = TargetObjectRegistry.BSLODTriShape_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "BSFurnitureMarkerNode")
	{
		Index = TargetObjectRegistry.BSFurnitureMarkerNode_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "BSLeafAnimNode")
	{
		Index = TargetObjectRegistry.BSLeafAnimNode_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "BSTreeNode")
	{
		Index = TargetObjectRegistry.BSTreeNode_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "NiLightRadiusController")
	{
		Index = TargetObjectRegistry.NiLightRadiusController_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "BSShape")
	{
		Index = TargetObjectRegistry.BSShape_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "BSTriShape")
	{
		Index = TargetObjectRegistry.BSTriShape_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "BSSubIndexTriShape")
	{
		Index = TargetObjectRegistry.BSSubIndexTriShape_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "BSMeshLODTriShape")
	{
		Index = TargetObjectRegistry.BSMeshLODTriShape_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "bhkNPCollisionObject")
	{
		Index = TargetObjectRegistry.bhkNPCollisionObject_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "BSExtraData")
	{
		Index = TargetObjectRegistry.BSExtraData_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "bhkPhysicsSystem")
	{
		Index = TargetObjectRegistry.bhkPhysicsSystem_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "bhkRagdollSystem")
	{
		Index = TargetObjectRegistry.bhkRagdollSystem_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "BSClothExtraData")
	{
		Index = TargetObjectRegistry.BSClothExtraData_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "BSSkin__Instance")
	{
		Index = TargetObjectRegistry.BSSkin__Instance_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "BSSkin__BoneData")
	{
		Index = TargetObjectRegistry.BSSkin__BoneData_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "BSPositionData")
	{
		Index = TargetObjectRegistry.BSPositionData_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "BSConnectPoint__Parents")
	{
		Index = TargetObjectRegistry.BSConnectPoint__Parents_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	if(TargetNodeType == "BSConnectPoint__Children")
	{
		Index = TargetObjectRegistry.BSConnectPoint__Children_Registry.AddData(TargetNode.InternalName, TargetNodeData);
	}
	//End of ObjectRegistry Section
	FixCurrentNodeData();
	CurrentNode->IndexInRegistry = Index;
}

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
	NifNode StorageNode;

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
	//vector<NiObjectRef> obj_list; //Vector to hold links in the order they were created.
	list<unsigned int> link_stack; //List to add link values to as they're read in from the file
	std::string objectType;
	stringstream errStream;

	std::streampos headerpos = in.tellg();
	std::streampos nextobjpos = headerpos;

	//Loop through all objects in the file
	size_t i = 0;
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

	//Need to create alternative version of NiObjectRef that skips using Niflib::ObjectRegistry altogether later
	if(CreateObject(objectType)==false)
	{
		errStream << "Unknown object type encountered during file read:  " << objectType << endl;
		throw runtime_error(errStream.str());
	}
	size_t index;
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
	//Read new object data from Stream
	FixCurrentNodeData();
	CurrentNode->internal_block_number = index;
	ReadObjectFromStream(objectType, in, link_stack, *info);

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

	//delete info if it was dynamically allocated
	if(delete_info)
	{
		delete info;
	}

	// clear the header pointer in the stream.  Should be in try/catch block
	hdrInfo hinfo2(NULL);
	in >> hinfo2;

	//obj_list;
	//Now Arrange and add nodes from obj_list to NodeTree in correct order(move from LooseNodes section to tree/Extra Data links as find nodes)
	//First try finding
	//"NiAVObjectRef
	std::string InternalNameTemp;
	std::string RootInternalName = "";
	NifNode* NodePointer = nullptr;
	size_t SizeTemp = BaseLooseNode.Size();
	for(size_t Index = 0; Index < SizeTemp&&RootInternalName == "";++Index)
	{
		//Note:The actual node data isn't moved at all here
		InternalNameTemp = BaseLooseNode.ElementAt(Index);
		NodePointer = GetNodePointerFromInternalName(InternalNameTemp);
		if(NodePointer->NodeType=="NiAVObjectRef")
		{
			RootInternalName = NodePointer->InternalName;
			
			//Finish moving up chain code later
			//NodePointer
			//Move up the chain to the root node
			//while(root->GetParent() != NULL)
			//{
			//	root = StaticCast<NiAVObject>(root->GetParent());
			//}
			
		}
	}
	//Make sure a node was found, if not return first node
	if(RootInternalName=="")
	{
		NodePointer = GetElementPointerV2(0);
		RootInternalName = NodePointer->InternalName;
	}
	//Move RootPointer from LooseNode list and add to RootNodelist
	MoveNode(RootInternalName,"(Core)");
	//Organize and move rest from looseNode list
}

void NifNodeTreeData::NifNodeTree::DestroyTargetNodeAndAllItsChildrenV2(NifNode* TargetNode)
{
	//Need to refactor IndexInRegistry for all with index for all destroyed
	NodeTypeDestructionDataList DestructionData;
	DestructionData.UpdateDestructionData(TargetNode);
	std::string const TargetNodeInternalName = TargetNode->InternalName;
	StringVectorList InternalNamesOfNodesToDestroy;
	InternalNamesOfNodesToDestroy.Add(TargetNodeInternalName);
	//Remove node from child list of parent
	std::string ParentNodeName = TargetNode->ParentInternalName;
	if(ParentNodeName == "(Core)")
	{
		RootInternalNodes.RemoveElementWithMatchingValue(TargetNodeInternalName);
	}
	else if(ParentNodeName == "(LooseNodes)")
	{
		BaseLooseNode.RemoveElementWithMatchingValue(TargetNodeInternalName);
	}
	else
	{
		NifNode* ParentNode = GetNodePointerFromInternalName(ParentNodeName);
		if(ParentNode != nullptr)
		{
			ParentNode->ChildInternalNames.RemoveElementWithMatchingValue(TargetNodeInternalName);
		}
	}
	size_t SizeTemp;
	std::string TargetNameTemp;
	TargetNode = GetNodePointerFromInternalName(TargetNodeInternalName);
	//Search children and childrens children (and add internal Names to list)
	SizeTemp = TargetNode->ChildInternalNames.Size();
	//Copying Child list to prevent pointer messups from messing up child search
	StringVectorList ChildList = TargetNode->ChildInternalNames;
	for(size_t Index = 0; Index < SizeTemp; ++Index)
	{
		TargetNameTemp = ChildList.ElementAt(Index);
		InternalNamesOfNodesToDestroy.Add(TargetNameTemp);
		//Now search childrens...children etc
		TargetNode = GetNodePointerFromInternalName(TargetNameTemp);
		//Need to auto-update reference of NodeTree class type in just to ensure it updates the NodeTree reference when derived (I'll try to see if auto-updates derived class type first)
		TargetNode->ObtainAllChildNodeNamesForDestructionV2(DestructionData, this, InternalNamesOfNodesToDestroy);//<std::typeid(NodeTree)>
	}
	//Now destroy all nodes in list set to destroy
	SizeTemp = InternalNamesOfNodesToDestroy.Size();
	for(size_t Index = 0; Index < SizeTemp; ++Index)
	{
		TargetNameTemp = InternalNamesOfNodesToDestroy.ElementAt(Index);
		TargetNode = GetNodePointerFromInternalName(TargetNameTemp);
		if(TargetNode != nullptr)
		{
			//First Destroy Actual Node Data
			TargetNode->DestroyNodeData(&TargetObjectRegistry);
			//----------------------------------------------
			Remove(GetIndexOfInternalName(TargetNameTemp));
		}
	}
	//Now update Registry Based on DestructionData
	SizeTemp = DestructionData.Size();
	NodeTypeDestructionData ElementData;
	for(size_t Index = 0; Index < SizeTemp; ++Index)
	{
		ElementData = DestructionData.ElementAt(Index);
		for(size_t Index02 = 0; Index02 < Size(); ++Index02)
		{
			TargetNode = GetElementPointerV2(Index02);
			if(TargetNode->NodeType == ElementData.NodeType)
			{
				TargetNode->IndexInRegistry -= ElementData.NumberOfNodes;
			}
		}
	}
}

void NifNodeTreeData::NifNodeTree::ReadObjectFromStream(std::string ObjectType,istream& in, list<unsigned int> & link_stack, const Niflib::NifInfo & info)
{
	//Load Read( in, link_stack, info ) from current Node inside VariableList holding actual NodeData
	if(ObjectType == "NiObject") { TargetObjectRegistry.NiObject_Registry.Read(in, link_stack, info); }
	if(ObjectType == "Ni3dsAlphaAnimator") { TargetObjectRegistry.Ni3dsAlphaAnimator_Registry.Read(in, link_stack, info); }
	if(ObjectType == "Ni3dsAnimationNode") { TargetObjectRegistry.Ni3dsAnimationNode_Registry.Read(in, link_stack, info); }
	if(ObjectType == "Ni3dsColorAnimator") { TargetObjectRegistry.Ni3dsColorAnimator_Registry.Read(in, link_stack, info); }
	if(ObjectType == "Ni3dsMorphShape") { TargetObjectRegistry.Ni3dsMorphShape_Registry.Read(in, link_stack, info); }
	if(ObjectType == "Ni3dsParticleSystem") { TargetObjectRegistry.Ni3dsParticleSystem_Registry.Read(in, link_stack, info); }
	if(ObjectType == "Ni3dsPathController") { TargetObjectRegistry.Ni3dsPathController_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiParticleModifier") { TargetObjectRegistry.NiParticleModifier_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiPSysCollider") { TargetObjectRegistry.NiPSysCollider_Registry.Read(in, link_stack, info); }
	if(ObjectType == "bhkRefObject") { TargetObjectRegistry.bhkRefObject_Registry.Read(in, link_stack, info); }
	if(ObjectType == "bhkSerializable") { TargetObjectRegistry.bhkSerializable_Registry.Read(in, link_stack, info); }
	if(ObjectType == "bhkWorldObject") { TargetObjectRegistry.bhkWorldObject_Registry.Read(in, link_stack, info); }
	if(ObjectType == "bhkPhantom") { TargetObjectRegistry.bhkPhantom_Registry.Read(in, link_stack, info); }
	if(ObjectType == "bhkShapePhantom") { TargetObjectRegistry.bhkShapePhantom_Registry.Read(in, link_stack, info); }
	if(ObjectType == "bhkSimpleShapePhantom") { TargetObjectRegistry.bhkSimpleShapePhantom_Registry.Read(in, link_stack, info); }
	if(ObjectType == "bhkEntity") { TargetObjectRegistry.bhkEntity_Registry.Read(in, link_stack, info); }
	if(ObjectType == "bhkRigidBody") { TargetObjectRegistry.bhkRigidBody_Registry.Read(in, link_stack, info); }
	if(ObjectType == "bhkRigidBodyT") { TargetObjectRegistry.bhkRigidBodyT_Registry.Read(in, link_stack, info); }
	if(ObjectType == "bhkConstraint") { TargetObjectRegistry.bhkConstraint_Registry.Read(in, link_stack, info); }
	if(ObjectType == "bhkLimitedHingeConstraint") { TargetObjectRegistry.bhkLimitedHingeConstraint_Registry.Read(in, link_stack, info); }
	if(ObjectType == "bhkMalleableConstraint") { TargetObjectRegistry.bhkMalleableConstraint_Registry.Read(in, link_stack, info); }
	if(ObjectType == "bhkStiffSpringConstraint") { TargetObjectRegistry.bhkStiffSpringConstraint_Registry.Read(in, link_stack, info); }
	if(ObjectType == "bhkRagdollConstraint") { TargetObjectRegistry.bhkRagdollConstraint_Registry.Read(in, link_stack, info); }
	if(ObjectType == "bhkPrismaticConstraint") { TargetObjectRegistry.bhkPrismaticConstraint_Registry.Read(in, link_stack, info); }
	if(ObjectType == "bhkHingeConstraint") { TargetObjectRegistry.bhkHingeConstraint_Registry.Read(in, link_stack, info); }
	if(ObjectType == "bhkBallAndSocketConstraint") { TargetObjectRegistry.bhkBallAndSocketConstraint_Registry.Read(in, link_stack, info); }
	if(ObjectType == "bhkBallSocketConstraintChain") { TargetObjectRegistry.bhkBallSocketConstraintChain_Registry.Read(in, link_stack, info); }
	if(ObjectType == "bhkShape") { TargetObjectRegistry.bhkShape_Registry.Read(in, link_stack, info); }
	if(ObjectType == "bhkTransformShape") { TargetObjectRegistry.bhkTransformShape_Registry.Read(in, link_stack, info); }
	if(ObjectType == "bhkSphereRepShape") { TargetObjectRegistry.bhkSphereRepShape_Registry.Read(in, link_stack, info); }
	if(ObjectType == "bhkConvexShape") { TargetObjectRegistry.bhkConvexShape_Registry.Read(in, link_stack, info); }
	if(ObjectType == "bhkSphereShape") { TargetObjectRegistry.bhkSphereShape_Registry.Read(in, link_stack, info); }
	if(ObjectType == "bhkCapsuleShape") { TargetObjectRegistry.bhkCapsuleShape_Registry.Read(in, link_stack, info); }
	if(ObjectType == "bhkBoxShape") { TargetObjectRegistry.bhkBoxShape_Registry.Read(in, link_stack, info); }
	if(ObjectType == "bhkConvexVerticesShape") { TargetObjectRegistry.bhkConvexVerticesShape_Registry.Read(in, link_stack, info); }
	if(ObjectType == "bhkConvexTransformShape") { TargetObjectRegistry.bhkConvexTransformShape_Registry.Read(in, link_stack, info); }
	if(ObjectType == "bhkMultiSphereShape") { TargetObjectRegistry.bhkMultiSphereShape_Registry.Read(in, link_stack, info); }
	if(ObjectType == "bhkBvTreeShape") { TargetObjectRegistry.bhkBvTreeShape_Registry.Read(in, link_stack, info); }
	if(ObjectType == "bhkMoppBvTreeShape") { TargetObjectRegistry.bhkMoppBvTreeShape_Registry.Read(in, link_stack, info); }
	if(ObjectType == "bhkShapeCollection") { TargetObjectRegistry.bhkShapeCollection_Registry.Read(in, link_stack, info); }
	if(ObjectType == "bhkListShape") { TargetObjectRegistry.bhkListShape_Registry.Read(in, link_stack, info); }
	if(ObjectType == "bhkMeshShape") { TargetObjectRegistry.bhkMeshShape_Registry.Read(in, link_stack, info); }
	if(ObjectType == "bhkPackedNiTriStripsShape") { TargetObjectRegistry.bhkPackedNiTriStripsShape_Registry.Read(in, link_stack, info); }
	if(ObjectType == "bhkNiTriStripsShape") { TargetObjectRegistry.bhkNiTriStripsShape_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiExtraData") { TargetObjectRegistry.NiExtraData_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiInterpolator") { TargetObjectRegistry.NiInterpolator_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiKeyBasedInterpolator") { TargetObjectRegistry.NiKeyBasedInterpolator_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiFloatInterpolator") { TargetObjectRegistry.NiFloatInterpolator_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiTransformInterpolator") { TargetObjectRegistry.NiTransformInterpolator_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiPoint3Interpolator") { TargetObjectRegistry.NiPoint3Interpolator_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiPathInterpolator") { TargetObjectRegistry.NiPathInterpolator_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiBoolInterpolator") { TargetObjectRegistry.NiBoolInterpolator_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiBoolTimelineInterpolator") { TargetObjectRegistry.NiBoolTimelineInterpolator_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiBlendInterpolator") { TargetObjectRegistry.NiBlendInterpolator_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiBSplineInterpolator") { TargetObjectRegistry.NiBSplineInterpolator_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiObjectNET") { TargetObjectRegistry.NiObjectNET_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiCollisionObject") { TargetObjectRegistry.NiCollisionObject_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiCollisionData") { TargetObjectRegistry.NiCollisionData_Registry.Read(in, link_stack, info); }
	if(ObjectType == "bhkNiCollisionObject") { TargetObjectRegistry.bhkNiCollisionObject_Registry.Read(in, link_stack, info); }
	if(ObjectType == "bhkCollisionObject") { TargetObjectRegistry.bhkCollisionObject_Registry.Read(in, link_stack, info); }
	if(ObjectType == "bhkBlendCollisionObject") { TargetObjectRegistry.bhkBlendCollisionObject_Registry.Read(in, link_stack, info); }
	if(ObjectType == "bhkPCollisionObject") { TargetObjectRegistry.bhkPCollisionObject_Registry.Read(in, link_stack, info); }
	if(ObjectType == "bhkSPCollisionObject") { TargetObjectRegistry.bhkSPCollisionObject_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiAVObject") { TargetObjectRegistry.NiAVObject_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiDynamicEffect") { TargetObjectRegistry.NiDynamicEffect_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiLight") { TargetObjectRegistry.NiLight_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiProperty") { TargetObjectRegistry.NiProperty_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiTransparentProperty") { TargetObjectRegistry.NiTransparentProperty_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiPSysModifier") { TargetObjectRegistry.NiPSysModifier_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiPSysEmitter") { TargetObjectRegistry.NiPSysEmitter_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiPSysVolumeEmitter") { TargetObjectRegistry.NiPSysVolumeEmitter_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiTimeController") { TargetObjectRegistry.NiTimeController_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiInterpController") { TargetObjectRegistry.NiInterpController_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiMultiTargetTransformController") { TargetObjectRegistry.NiMultiTargetTransformController_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiGeomMorpherController") { TargetObjectRegistry.NiGeomMorpherController_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiMorphController") { TargetObjectRegistry.NiMorphController_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiMorpherController") { TargetObjectRegistry.NiMorpherController_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiSingleInterpController") { TargetObjectRegistry.NiSingleInterpController_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiKeyframeController") { TargetObjectRegistry.NiKeyframeController_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiTransformController") { TargetObjectRegistry.NiTransformController_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiPSysModifierCtlr") { TargetObjectRegistry.NiPSysModifierCtlr_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiPSysEmitterCtlr") { TargetObjectRegistry.NiPSysEmitterCtlr_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiPSysModifierBoolCtlr") { TargetObjectRegistry.NiPSysModifierBoolCtlr_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiPSysModifierActiveCtlr") { TargetObjectRegistry.NiPSysModifierActiveCtlr_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiPSysModifierFloatCtlr") { TargetObjectRegistry.NiPSysModifierFloatCtlr_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiPSysEmitterDeclinationCtlr") { TargetObjectRegistry.NiPSysEmitterDeclinationCtlr_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiPSysEmitterDeclinationVarCtlr") { TargetObjectRegistry.NiPSysEmitterDeclinationVarCtlr_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiPSysEmitterInitialRadiusCtlr") { TargetObjectRegistry.NiPSysEmitterInitialRadiusCtlr_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiPSysEmitterLifeSpanCtlr") { TargetObjectRegistry.NiPSysEmitterLifeSpanCtlr_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiPSysEmitterSpeedCtlr") { TargetObjectRegistry.NiPSysEmitterSpeedCtlr_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiPSysGravityStrengthCtlr") { TargetObjectRegistry.NiPSysGravityStrengthCtlr_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiFloatInterpController") { TargetObjectRegistry.NiFloatInterpController_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiFlipController") { TargetObjectRegistry.NiFlipController_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiAlphaController") { TargetObjectRegistry.NiAlphaController_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiTextureTransformController") { TargetObjectRegistry.NiTextureTransformController_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiLightDimmerController") { TargetObjectRegistry.NiLightDimmerController_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiBoolInterpController") { TargetObjectRegistry.NiBoolInterpController_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiVisController") { TargetObjectRegistry.NiVisController_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiPoint3InterpController") { TargetObjectRegistry.NiPoint3InterpController_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiMaterialColorController") { TargetObjectRegistry.NiMaterialColorController_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiLightColorController") { TargetObjectRegistry.NiLightColorController_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiExtraDataController") { TargetObjectRegistry.NiExtraDataController_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiFloatExtraDataController") { TargetObjectRegistry.NiFloatExtraDataController_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiBoneLODController") { TargetObjectRegistry.NiBoneLODController_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiBSBoneLODController") { TargetObjectRegistry.NiBSBoneLODController_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiGeometry") { TargetObjectRegistry.NiGeometry_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiTriBasedGeom") { TargetObjectRegistry.NiTriBasedGeom_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiGeometryData") { TargetObjectRegistry.NiGeometryData_Registry.Read(in, link_stack, info); }
	if(ObjectType == "AbstractAdditionalGeometryData") { TargetObjectRegistry.AbstractAdditionalGeometryData_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiTriBasedGeomData") { TargetObjectRegistry.NiTriBasedGeomData_Registry.Read(in, link_stack, info); }
	if(ObjectType == "bhkBlendController") { TargetObjectRegistry.bhkBlendController_Registry.Read(in, link_stack, info); }
	if(ObjectType == "BSBound") { TargetObjectRegistry.BSBound_Registry.Read(in, link_stack, info); }
	if(ObjectType == "BSFurnitureMarker") { TargetObjectRegistry.BSFurnitureMarker_Registry.Read(in, link_stack, info); }
	if(ObjectType == "BSParentVelocityModifier") { TargetObjectRegistry.BSParentVelocityModifier_Registry.Read(in, link_stack, info); }
	if(ObjectType == "BSPSysArrayEmitter") { TargetObjectRegistry.BSPSysArrayEmitter_Registry.Read(in, link_stack, info); }
	if(ObjectType == "BSWindModifier") { TargetObjectRegistry.BSWindModifier_Registry.Read(in, link_stack, info); }
	if(ObjectType == "hkPackedNiTriStripsData") { TargetObjectRegistry.hkPackedNiTriStripsData_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiAlphaProperty") { TargetObjectRegistry.NiAlphaProperty_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiAmbientLight") { TargetObjectRegistry.NiAmbientLight_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiParticlesData") { TargetObjectRegistry.NiParticlesData_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiRotatingParticlesData") { TargetObjectRegistry.NiRotatingParticlesData_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiAutoNormalParticlesData") { TargetObjectRegistry.NiAutoNormalParticlesData_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiPSysData") { TargetObjectRegistry.NiPSysData_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiMeshPSysData") { TargetObjectRegistry.NiMeshPSysData_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiBinaryExtraData") { TargetObjectRegistry.NiBinaryExtraData_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiBinaryVoxelExtraData") { TargetObjectRegistry.NiBinaryVoxelExtraData_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiBinaryVoxelData") { TargetObjectRegistry.NiBinaryVoxelData_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiBlendBoolInterpolator") { TargetObjectRegistry.NiBlendBoolInterpolator_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiBlendFloatInterpolator") { TargetObjectRegistry.NiBlendFloatInterpolator_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiBlendPoint3Interpolator") { TargetObjectRegistry.NiBlendPoint3Interpolator_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiBlendTransformInterpolator") { TargetObjectRegistry.NiBlendTransformInterpolator_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiBoolData") { TargetObjectRegistry.NiBoolData_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiBooleanExtraData") { TargetObjectRegistry.NiBooleanExtraData_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiBSplineBasisData") { TargetObjectRegistry.NiBSplineBasisData_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiBSplineFloatInterpolator") { TargetObjectRegistry.NiBSplineFloatInterpolator_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiBSplineCompFloatInterpolator") { TargetObjectRegistry.NiBSplineCompFloatInterpolator_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiBSplinePoint3Interpolator") { TargetObjectRegistry.NiBSplinePoint3Interpolator_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiBSplineCompPoint3Interpolator") { TargetObjectRegistry.NiBSplineCompPoint3Interpolator_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiBSplineTransformInterpolator") { TargetObjectRegistry.NiBSplineTransformInterpolator_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiBSplineCompTransformInterpolator") { TargetObjectRegistry.NiBSplineCompTransformInterpolator_Registry.Read(in, link_stack, info); }
	if(ObjectType == "BSRotAccumTransfInterpolator") { TargetObjectRegistry.BSRotAccumTransfInterpolator_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiBSplineData") { TargetObjectRegistry.NiBSplineData_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiCamera") { TargetObjectRegistry.NiCamera_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiColorData") { TargetObjectRegistry.NiColorData_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiColorExtraData") { TargetObjectRegistry.NiColorExtraData_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiControllerManager") { TargetObjectRegistry.NiControllerManager_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiSequence") { TargetObjectRegistry.NiSequence_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiControllerSequence") { TargetObjectRegistry.NiControllerSequence_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiAVObjectPalette") { TargetObjectRegistry.NiAVObjectPalette_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiDefaultAVObjectPalette") { TargetObjectRegistry.NiDefaultAVObjectPalette_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiDirectionalLight") { TargetObjectRegistry.NiDirectionalLight_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiDitherProperty") { TargetObjectRegistry.NiDitherProperty_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiRollController") { TargetObjectRegistry.NiRollController_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiFloatData") { TargetObjectRegistry.NiFloatData_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiFloatExtraData") { TargetObjectRegistry.NiFloatExtraData_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiFloatsExtraData") { TargetObjectRegistry.NiFloatsExtraData_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiFogProperty") { TargetObjectRegistry.NiFogProperty_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiGravity") { TargetObjectRegistry.NiGravity_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiIntegerExtraData") { TargetObjectRegistry.NiIntegerExtraData_Registry.Read(in, link_stack, info); }
	if(ObjectType == "BSXFlags") { TargetObjectRegistry.BSXFlags_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiIntegersExtraData") { TargetObjectRegistry.NiIntegersExtraData_Registry.Read(in, link_stack, info); }
	if(ObjectType == "BSKeyframeController") { TargetObjectRegistry.BSKeyframeController_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiKeyframeData") { TargetObjectRegistry.NiKeyframeData_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiLookAtController") { TargetObjectRegistry.NiLookAtController_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiLookAtInterpolator") { TargetObjectRegistry.NiLookAtInterpolator_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiMaterialProperty") { TargetObjectRegistry.NiMaterialProperty_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiMorphData") { TargetObjectRegistry.NiMorphData_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiNode") { TargetObjectRegistry.NiNode_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiBone") { TargetObjectRegistry.NiBone_Registry.Read(in, link_stack, info); }
	if(ObjectType == "AvoidNode") { TargetObjectRegistry.AvoidNode_Registry.Read(in, link_stack, info); }
	if(ObjectType == "FxWidget") { TargetObjectRegistry.FxWidget_Registry.Read(in, link_stack, info); }
	if(ObjectType == "FxButton") { TargetObjectRegistry.FxButton_Registry.Read(in, link_stack, info); }
	if(ObjectType == "FxRadioButton") { TargetObjectRegistry.FxRadioButton_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiBillboardNode") { TargetObjectRegistry.NiBillboardNode_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiBSAnimationNode") { TargetObjectRegistry.NiBSAnimationNode_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiBSParticleNode") { TargetObjectRegistry.NiBSParticleNode_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiSwitchNode") { TargetObjectRegistry.NiSwitchNode_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiLODNode") { TargetObjectRegistry.NiLODNode_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiPalette") { TargetObjectRegistry.NiPalette_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiParticleBomb") { TargetObjectRegistry.NiParticleBomb_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiParticleColorModifier") { TargetObjectRegistry.NiParticleColorModifier_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiParticleGrowFade") { TargetObjectRegistry.NiParticleGrowFade_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiParticleMeshModifier") { TargetObjectRegistry.NiParticleMeshModifier_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiParticleRotation") { TargetObjectRegistry.NiParticleRotation_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiParticles") { TargetObjectRegistry.NiParticles_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiAutoNormalParticles") { TargetObjectRegistry.NiAutoNormalParticles_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiParticleMeshes") { TargetObjectRegistry.NiParticleMeshes_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiParticleMeshesData") { TargetObjectRegistry.NiParticleMeshesData_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiParticleSystem") { TargetObjectRegistry.NiParticleSystem_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiMeshParticleSystem") { TargetObjectRegistry.NiMeshParticleSystem_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiParticleSystemController") { TargetObjectRegistry.NiParticleSystemController_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiBSPArrayController") { TargetObjectRegistry.NiBSPArrayController_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiPathController") { TargetObjectRegistry.NiPathController_Registry.Read(in, link_stack, info); }
	if(ObjectType == "ATextureRenderData") { TargetObjectRegistry.ATextureRenderData_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiPersistentSrcTextureRendererData") { TargetObjectRegistry.NiPersistentSrcTextureRendererData_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiPixelData") { TargetObjectRegistry.NiPixelData_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiPlanarCollider") { TargetObjectRegistry.NiPlanarCollider_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiPointLight") { TargetObjectRegistry.NiPointLight_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiPosData") { TargetObjectRegistry.NiPosData_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiPSysAgeDeathModifier") { TargetObjectRegistry.NiPSysAgeDeathModifier_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiPSysBombModifier") { TargetObjectRegistry.NiPSysBombModifier_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiPSysBoundUpdateModifier") { TargetObjectRegistry.NiPSysBoundUpdateModifier_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiPSysBoxEmitter") { TargetObjectRegistry.NiPSysBoxEmitter_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiPSysColliderManager") { TargetObjectRegistry.NiPSysColliderManager_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiPSysColorModifier") { TargetObjectRegistry.NiPSysColorModifier_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiPSysCylinderEmitter") { TargetObjectRegistry.NiPSysCylinderEmitter_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiPSysDragModifier") { TargetObjectRegistry.NiPSysDragModifier_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiPSysEmitterCtlrData") { TargetObjectRegistry.NiPSysEmitterCtlrData_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiPSysGravityModifier") { TargetObjectRegistry.NiPSysGravityModifier_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiPSysGrowFadeModifier") { TargetObjectRegistry.NiPSysGrowFadeModifier_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiPSysMeshEmitter") { TargetObjectRegistry.NiPSysMeshEmitter_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiPSysMeshUpdateModifier") { TargetObjectRegistry.NiPSysMeshUpdateModifier_Registry.Read(in, link_stack, info); }
	if(ObjectType == "BSPSysInheritVelocityModifier") { TargetObjectRegistry.BSPSysInheritVelocityModifier_Registry.Read(in, link_stack, info); }
	if(ObjectType == "BSPSysHavokUpdateModifier") { TargetObjectRegistry.BSPSysHavokUpdateModifier_Registry.Read(in, link_stack, info); }
	if(ObjectType == "BSPSysRecycleBoundModifier") { TargetObjectRegistry.BSPSysRecycleBoundModifier_Registry.Read(in, link_stack, info); }
	if(ObjectType == "BSPSysSubTexModifier") { TargetObjectRegistry.BSPSysSubTexModifier_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiPSysPlanarCollider") { TargetObjectRegistry.NiPSysPlanarCollider_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiPSysSphericalCollider") { TargetObjectRegistry.NiPSysSphericalCollider_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiPSysPositionModifier") { TargetObjectRegistry.NiPSysPositionModifier_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiPSysResetOnLoopCtlr") { TargetObjectRegistry.NiPSysResetOnLoopCtlr_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiPSysRotationModifier") { TargetObjectRegistry.NiPSysRotationModifier_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiPSysSpawnModifier") { TargetObjectRegistry.NiPSysSpawnModifier_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiPSysSphereEmitter") { TargetObjectRegistry.NiPSysSphereEmitter_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiPSysUpdateCtlr") { TargetObjectRegistry.NiPSysUpdateCtlr_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiPSysFieldModifier") { TargetObjectRegistry.NiPSysFieldModifier_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiPSysVortexFieldModifier") { TargetObjectRegistry.NiPSysVortexFieldModifier_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiPSysGravityFieldModifier") { TargetObjectRegistry.NiPSysGravityFieldModifier_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiPSysDragFieldModifier") { TargetObjectRegistry.NiPSysDragFieldModifier_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiPSysTurbulenceFieldModifier") { TargetObjectRegistry.NiPSysTurbulenceFieldModifier_Registry.Read(in, link_stack, info); }
	if(ObjectType == "BSPSysLODModifier") { TargetObjectRegistry.BSPSysLODModifier_Registry.Read(in, link_stack, info); }
	if(ObjectType == "BSPSysScaleModifier") { TargetObjectRegistry.BSPSysScaleModifier_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiPSysFieldMagnitudeCtlr") { TargetObjectRegistry.NiPSysFieldMagnitudeCtlr_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiPSysFieldAttenuationCtlr") { TargetObjectRegistry.NiPSysFieldAttenuationCtlr_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiPSysFieldMaxDistanceCtlr") { TargetObjectRegistry.NiPSysFieldMaxDistanceCtlr_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiPSysAirFieldAirFrictionCtlr") { TargetObjectRegistry.NiPSysAirFieldAirFrictionCtlr_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiPSysAirFieldInheritVelocityCtlr") { TargetObjectRegistry.NiPSysAirFieldInheritVelocityCtlr_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiPSysAirFieldSpreadCtlr") { TargetObjectRegistry.NiPSysAirFieldSpreadCtlr_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiPSysInitialRotSpeedCtlr") { TargetObjectRegistry.NiPSysInitialRotSpeedCtlr_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiPSysInitialRotSpeedVarCtlr") { TargetObjectRegistry.NiPSysInitialRotSpeedVarCtlr_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiPSysInitialRotAngleCtlr") { TargetObjectRegistry.NiPSysInitialRotAngleCtlr_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiPSysInitialRotAngleVarCtlr") { TargetObjectRegistry.NiPSysInitialRotAngleVarCtlr_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiPSysEmitterPlanarAngleCtlr") { TargetObjectRegistry.NiPSysEmitterPlanarAngleCtlr_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiPSysEmitterPlanarAngleVarCtlr") { TargetObjectRegistry.NiPSysEmitterPlanarAngleVarCtlr_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiPSysAirFieldModifier") { TargetObjectRegistry.NiPSysAirFieldModifier_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiPSysTrailEmitter") { TargetObjectRegistry.NiPSysTrailEmitter_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiLightIntensityController") { TargetObjectRegistry.NiLightIntensityController_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiPSysRadialFieldModifier") { TargetObjectRegistry.NiPSysRadialFieldModifier_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiLODData") { TargetObjectRegistry.NiLODData_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiRangeLODData") { TargetObjectRegistry.NiRangeLODData_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiScreenLODData") { TargetObjectRegistry.NiScreenLODData_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiRotatingParticles") { TargetObjectRegistry.NiRotatingParticles_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiSequenceStreamHelper") { TargetObjectRegistry.NiSequenceStreamHelper_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiShadeProperty") { TargetObjectRegistry.NiShadeProperty_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiSkinData") { TargetObjectRegistry.NiSkinData_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiSkinInstance") { TargetObjectRegistry.NiSkinInstance_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiTriShapeSkinController") { TargetObjectRegistry.NiTriShapeSkinController_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiClodSkinInstance") { TargetObjectRegistry.NiClodSkinInstance_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiSkinPartition") { TargetObjectRegistry.NiSkinPartition_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiTexture") { TargetObjectRegistry.NiTexture_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiSourceTexture") { TargetObjectRegistry.NiSourceTexture_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiSpecularProperty") { TargetObjectRegistry.NiSpecularProperty_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiSphericalCollider") { TargetObjectRegistry.NiSphericalCollider_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiSpotLight") { TargetObjectRegistry.NiSpotLight_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiStencilProperty") { TargetObjectRegistry.NiStencilProperty_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiStringExtraData") { TargetObjectRegistry.NiStringExtraData_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiStringPalette") { TargetObjectRegistry.NiStringPalette_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiStringsExtraData") { TargetObjectRegistry.NiStringsExtraData_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiTextKeyExtraData") { TargetObjectRegistry.NiTextKeyExtraData_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiTextureEffect") { TargetObjectRegistry.NiTextureEffect_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiTextureModeProperty") { TargetObjectRegistry.NiTextureModeProperty_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiImage") { TargetObjectRegistry.NiImage_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiTextureProperty") { TargetObjectRegistry.NiTextureProperty_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiMultiTextureProperty") { TargetObjectRegistry.NiMultiTextureProperty_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiTexturingProperty") { TargetObjectRegistry.NiTexturingProperty_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiTransformData") { TargetObjectRegistry.NiTransformData_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiTriShape") { TargetObjectRegistry.NiTriShape_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiTriShapeData") { TargetObjectRegistry.NiTriShapeData_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiTriStrips") { TargetObjectRegistry.NiTriStrips_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiTriStripsData") { TargetObjectRegistry.NiTriStripsData_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiEnvMappedTriShape") { TargetObjectRegistry.NiEnvMappedTriShape_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiEnvMappedTriShapeData") { TargetObjectRegistry.NiEnvMappedTriShapeData_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiBezierTriangle4") { TargetObjectRegistry.NiBezierTriangle4_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiBezierMesh") { TargetObjectRegistry.NiBezierMesh_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiClod") { TargetObjectRegistry.NiClod_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiClodData") { TargetObjectRegistry.NiClodData_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiUVController") { TargetObjectRegistry.NiUVController_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiUVData") { TargetObjectRegistry.NiUVData_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiVectorExtraData") { TargetObjectRegistry.NiVectorExtraData_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiVertexColorProperty") { TargetObjectRegistry.NiVertexColorProperty_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiVertWeightsExtraData") { TargetObjectRegistry.NiVertWeightsExtraData_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiVisData") { TargetObjectRegistry.NiVisData_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiWireframeProperty") { TargetObjectRegistry.NiWireframeProperty_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiZBufferProperty") { TargetObjectRegistry.NiZBufferProperty_Registry.Read(in, link_stack, info); }
	if(ObjectType == "RootCollisionNode") { TargetObjectRegistry.RootCollisionNode_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiRawImageData") { TargetObjectRegistry.NiRawImageData_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiSortAdjustNode") { TargetObjectRegistry.NiSortAdjustNode_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiSourceCubeMap") { TargetObjectRegistry.NiSourceCubeMap_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiPhysXProp") { TargetObjectRegistry.NiPhysXProp_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiPhysXPropDesc") { TargetObjectRegistry.NiPhysXPropDesc_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiPhysXActorDesc") { TargetObjectRegistry.NiPhysXActorDesc_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiPhysXBodyDesc") { TargetObjectRegistry.NiPhysXBodyDesc_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiPhysXD6JointDesc") { TargetObjectRegistry.NiPhysXD6JointDesc_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiPhysXShapeDesc") { TargetObjectRegistry.NiPhysXShapeDesc_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiPhysXMeshDesc") { TargetObjectRegistry.NiPhysXMeshDesc_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiPhysXMaterialDesc") { TargetObjectRegistry.NiPhysXMaterialDesc_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiPhysXKinematicSrc") { TargetObjectRegistry.NiPhysXKinematicSrc_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiPhysXTransformDest") { TargetObjectRegistry.NiPhysXTransformDest_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiArkAnimationExtraData") { TargetObjectRegistry.NiArkAnimationExtraData_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiArkImporterExtraData") { TargetObjectRegistry.NiArkImporterExtraData_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiArkTextureExtraData") { TargetObjectRegistry.NiArkTextureExtraData_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiArkViewportInfoExtraData") { TargetObjectRegistry.NiArkViewportInfoExtraData_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiArkShaderExtraData") { TargetObjectRegistry.NiArkShaderExtraData_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiLines") { TargetObjectRegistry.NiLines_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiLinesData") { TargetObjectRegistry.NiLinesData_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiScreenElementsData") { TargetObjectRegistry.NiScreenElementsData_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiScreenElements") { TargetObjectRegistry.NiScreenElements_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiRoomGroup") { TargetObjectRegistry.NiRoomGroup_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiRoom") { TargetObjectRegistry.NiRoom_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiPortal") { TargetObjectRegistry.NiPortal_Registry.Read(in, link_stack, info); }
	if(ObjectType == "BSFadeNode") { TargetObjectRegistry.BSFadeNode_Registry.Read(in, link_stack, info); }
	if(ObjectType == "BSShaderProperty") { TargetObjectRegistry.BSShaderProperty_Registry.Read(in, link_stack, info); }
	if(ObjectType == "BSShaderLightingProperty") { TargetObjectRegistry.BSShaderLightingProperty_Registry.Read(in, link_stack, info); }
	if(ObjectType == "BSShaderNoLightingProperty") { TargetObjectRegistry.BSShaderNoLightingProperty_Registry.Read(in, link_stack, info); }
	if(ObjectType == "BSShaderPPLightingProperty") { TargetObjectRegistry.BSShaderPPLightingProperty_Registry.Read(in, link_stack, info); }
	if(ObjectType == "BSEffectShaderPropertyFloatController") { TargetObjectRegistry.BSEffectShaderPropertyFloatController_Registry.Read(in, link_stack, info); }
	if(ObjectType == "BSEffectShaderPropertyColorController") { TargetObjectRegistry.BSEffectShaderPropertyColorController_Registry.Read(in, link_stack, info); }
	if(ObjectType == "BSLightingShaderPropertyFloatController") { TargetObjectRegistry.BSLightingShaderPropertyFloatController_Registry.Read(in, link_stack, info); }
	if(ObjectType == "BSLightingShaderPropertyColorController") { TargetObjectRegistry.BSLightingShaderPropertyColorController_Registry.Read(in, link_stack, info); }
	if(ObjectType == "BSNiAlphaPropertyTestRefController") { TargetObjectRegistry.BSNiAlphaPropertyTestRefController_Registry.Read(in, link_stack, info); }
	if(ObjectType == "BSProceduralLightningController") { TargetObjectRegistry.BSProceduralLightningController_Registry.Read(in, link_stack, info); }
	if(ObjectType == "BSShaderTextureSet") { TargetObjectRegistry.BSShaderTextureSet_Registry.Read(in, link_stack, info); }
	if(ObjectType == "WaterShaderProperty") { TargetObjectRegistry.WaterShaderProperty_Registry.Read(in, link_stack, info); }
	if(ObjectType == "SkyShaderProperty") { TargetObjectRegistry.SkyShaderProperty_Registry.Read(in, link_stack, info); }
	if(ObjectType == "TileShaderProperty") { TargetObjectRegistry.TileShaderProperty_Registry.Read(in, link_stack, info); }
	if(ObjectType == "DistantLODShaderProperty") { TargetObjectRegistry.DistantLODShaderProperty_Registry.Read(in, link_stack, info); }
	if(ObjectType == "BSDistantTreeShaderProperty") { TargetObjectRegistry.BSDistantTreeShaderProperty_Registry.Read(in, link_stack, info); }
	if(ObjectType == "TallGrassShaderProperty") { TargetObjectRegistry.TallGrassShaderProperty_Registry.Read(in, link_stack, info); }
	if(ObjectType == "VolumetricFogShaderProperty") { TargetObjectRegistry.VolumetricFogShaderProperty_Registry.Read(in, link_stack, info); }
	if(ObjectType == "HairShaderProperty") { TargetObjectRegistry.HairShaderProperty_Registry.Read(in, link_stack, info); }
	if(ObjectType == "Lighting30ShaderProperty") { TargetObjectRegistry.Lighting30ShaderProperty_Registry.Read(in, link_stack, info); }
	if(ObjectType == "BSLightingShaderProperty") { TargetObjectRegistry.BSLightingShaderProperty_Registry.Read(in, link_stack, info); }
	if(ObjectType == "BSEffectShaderProperty") { TargetObjectRegistry.BSEffectShaderProperty_Registry.Read(in, link_stack, info); }
	if(ObjectType == "BSWaterShaderProperty") { TargetObjectRegistry.BSWaterShaderProperty_Registry.Read(in, link_stack, info); }
	if(ObjectType == "BSSkyShaderProperty") { TargetObjectRegistry.BSSkyShaderProperty_Registry.Read(in, link_stack, info); }
	if(ObjectType == "BSDismemberSkinInstance") { TargetObjectRegistry.BSDismemberSkinInstance_Registry.Read(in, link_stack, info); }
	if(ObjectType == "BSDecalPlacementVectorExtraData") { TargetObjectRegistry.BSDecalPlacementVectorExtraData_Registry.Read(in, link_stack, info); }
	if(ObjectType == "BSPSysSimpleColorModifier") { TargetObjectRegistry.BSPSysSimpleColorModifier_Registry.Read(in, link_stack, info); }
	if(ObjectType == "BSValueNode") { TargetObjectRegistry.BSValueNode_Registry.Read(in, link_stack, info); }
	if(ObjectType == "BSStripParticleSystem") { TargetObjectRegistry.BSStripParticleSystem_Registry.Read(in, link_stack, info); }
	if(ObjectType == "BSStripPSysData") { TargetObjectRegistry.BSStripPSysData_Registry.Read(in, link_stack, info); }
	if(ObjectType == "BSPSysStripUpdateModifier") { TargetObjectRegistry.BSPSysStripUpdateModifier_Registry.Read(in, link_stack, info); }
	if(ObjectType == "BSMaterialEmittanceMultController") { TargetObjectRegistry.BSMaterialEmittanceMultController_Registry.Read(in, link_stack, info); }
	if(ObjectType == "BSMasterParticleSystem") { TargetObjectRegistry.BSMasterParticleSystem_Registry.Read(in, link_stack, info); }
	if(ObjectType == "BSPSysMultiTargetEmitterCtlr") { TargetObjectRegistry.BSPSysMultiTargetEmitterCtlr_Registry.Read(in, link_stack, info); }
	if(ObjectType == "BSRefractionStrengthController") { TargetObjectRegistry.BSRefractionStrengthController_Registry.Read(in, link_stack, info); }
	if(ObjectType == "BSOrderedNode") { TargetObjectRegistry.BSOrderedNode_Registry.Read(in, link_stack, info); }
	if(ObjectType == "BSBlastNode") { TargetObjectRegistry.BSBlastNode_Registry.Read(in, link_stack, info); }
	if(ObjectType == "BSDamageStage") { TargetObjectRegistry.BSDamageStage_Registry.Read(in, link_stack, info); }
	if(ObjectType == "BSRefractionFirePeriodController") { TargetObjectRegistry.BSRefractionFirePeriodController_Registry.Read(in, link_stack, info); }
	if(ObjectType == "bhkConvexListShape") { TargetObjectRegistry.bhkConvexListShape_Registry.Read(in, link_stack, info); }
	if(ObjectType == "BSTreadTransfInterpolator") { TargetObjectRegistry.BSTreadTransfInterpolator_Registry.Read(in, link_stack, info); }
	if(ObjectType == "BSAnimNotes") { TargetObjectRegistry.BSAnimNotes_Registry.Read(in, link_stack, info); }
	if(ObjectType == "bhkLiquidAction") { TargetObjectRegistry.bhkLiquidAction_Registry.Read(in, link_stack, info); }
	if(ObjectType == "BSMultiBoundNode") { TargetObjectRegistry.BSMultiBoundNode_Registry.Read(in, link_stack, info); }
	if(ObjectType == "BSMultiBound") { TargetObjectRegistry.BSMultiBound_Registry.Read(in, link_stack, info); }
	if(ObjectType == "BSMultiBoundData") { TargetObjectRegistry.BSMultiBoundData_Registry.Read(in, link_stack, info); }
	if(ObjectType == "BSMultiBoundOBB") { TargetObjectRegistry.BSMultiBoundOBB_Registry.Read(in, link_stack, info); }
	if(ObjectType == "BSMultiBoundSphere") { TargetObjectRegistry.BSMultiBoundSphere_Registry.Read(in, link_stack, info); }
	if(ObjectType == "BSSegmentedTriShape") { TargetObjectRegistry.BSSegmentedTriShape_Registry.Read(in, link_stack, info); }
	if(ObjectType == "BSMultiBoundAABB") { TargetObjectRegistry.BSMultiBoundAABB_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiAdditionalGeometryData") { TargetObjectRegistry.NiAdditionalGeometryData_Registry.Read(in, link_stack, info); }
	if(ObjectType == "BSPackedAdditionalGeometryData") { TargetObjectRegistry.BSPackedAdditionalGeometryData_Registry.Read(in, link_stack, info); }
	if(ObjectType == "BSWArray") { TargetObjectRegistry.BSWArray_Registry.Read(in, link_stack, info); }
	if(ObjectType == "bhkAabbPhantom") { TargetObjectRegistry.bhkAabbPhantom_Registry.Read(in, link_stack, info); }
	if(ObjectType == "BSFrustumFOVController") { TargetObjectRegistry.BSFrustumFOVController_Registry.Read(in, link_stack, info); }
	if(ObjectType == "BSDebrisNode") { TargetObjectRegistry.BSDebrisNode_Registry.Read(in, link_stack, info); }
	if(ObjectType == "bhkBreakableConstraint") { TargetObjectRegistry.bhkBreakableConstraint_Registry.Read(in, link_stack, info); }
	if(ObjectType == "bhkOrientHingedBodyAction") { TargetObjectRegistry.bhkOrientHingedBodyAction_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiDataStream") { TargetObjectRegistry.NiDataStream_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiRenderObject") { TargetObjectRegistry.NiRenderObject_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiMeshModifier") { TargetObjectRegistry.NiMeshModifier_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiMesh") { TargetObjectRegistry.NiMesh_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiMorphWeightsController") { TargetObjectRegistry.NiMorphWeightsController_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiMorphMeshModifier") { TargetObjectRegistry.NiMorphMeshModifier_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiSkinningMeshModifier") { TargetObjectRegistry.NiSkinningMeshModifier_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiInstancingMeshModifier") { TargetObjectRegistry.NiInstancingMeshModifier_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiSkinningLODController") { TargetObjectRegistry.NiSkinningLODController_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiPSParticleSystem") { TargetObjectRegistry.NiPSParticleSystem_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiPSMeshParticleSystem") { TargetObjectRegistry.NiPSMeshParticleSystem_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiPSEmitParticlesCtlr") { TargetObjectRegistry.NiPSEmitParticlesCtlr_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiPSForceActiveCtlr") { TargetObjectRegistry.NiPSForceActiveCtlr_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiPSSimulator") { TargetObjectRegistry.NiPSSimulator_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiPSSimulatorStep") { TargetObjectRegistry.NiPSSimulatorStep_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiPSSimulatorGeneralStep") { TargetObjectRegistry.NiPSSimulatorGeneralStep_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiPSSimulatorForcesStep") { TargetObjectRegistry.NiPSSimulatorForcesStep_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiPSSimulatorCollidersStep") { TargetObjectRegistry.NiPSSimulatorCollidersStep_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiPSSimulatorMeshAlignStep") { TargetObjectRegistry.NiPSSimulatorMeshAlignStep_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiPSSimulatorFinalStep") { TargetObjectRegistry.NiPSSimulatorFinalStep_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiPSFacingQuadGenerator") { TargetObjectRegistry.NiPSFacingQuadGenerator_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiShadowGenerator") { TargetObjectRegistry.NiShadowGenerator_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiPSBoundUpdater") { TargetObjectRegistry.NiPSBoundUpdater_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiPSDragForce") { TargetObjectRegistry.NiPSDragForce_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiPSGravityForce") { TargetObjectRegistry.NiPSGravityForce_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiPSBoxEmitter") { TargetObjectRegistry.NiPSBoxEmitter_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiPSMeshEmitter") { TargetObjectRegistry.NiPSMeshEmitter_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiPSGravityStrengthCtlr") { TargetObjectRegistry.NiPSGravityStrengthCtlr_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiPSPlanarCollider") { TargetObjectRegistry.NiPSPlanarCollider_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiPSEmitterSpeedCtlr") { TargetObjectRegistry.NiPSEmitterSpeedCtlr_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiPSEmitterRadiusCtlr") { TargetObjectRegistry.NiPSEmitterRadiusCtlr_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiPSResetOnLoopCtlr") { TargetObjectRegistry.NiPSResetOnLoopCtlr_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiPSSphereEmitter") { TargetObjectRegistry.NiPSSphereEmitter_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiPSCylinderEmitter") { TargetObjectRegistry.NiPSCylinderEmitter_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiPSEmitterDeclinationCtlr") { TargetObjectRegistry.NiPSEmitterDeclinationCtlr_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiPSEmitterDeclinationVarCtlr") { TargetObjectRegistry.NiPSEmitterDeclinationVarCtlr_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiPSEmitterPlanarAngleCtlr") { TargetObjectRegistry.NiPSEmitterPlanarAngleCtlr_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiPSEmitterPlanarAngleVarCtlr") { TargetObjectRegistry.NiPSEmitterPlanarAngleVarCtlr_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiPSEmitterRotAngleCtlr") { TargetObjectRegistry.NiPSEmitterRotAngleCtlr_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiPSEmitterRotAngleVarCtlr") { TargetObjectRegistry.NiPSEmitterRotAngleVarCtlr_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiPSEmitterRotSpeedCtlr") { TargetObjectRegistry.NiPSEmitterRotSpeedCtlr_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiPSEmitterRotSpeedVarCtlr") { TargetObjectRegistry.NiPSEmitterRotSpeedVarCtlr_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiPSEmitterLifeSpanCtlr") { TargetObjectRegistry.NiPSEmitterLifeSpanCtlr_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiPSBombForce") { TargetObjectRegistry.NiPSBombForce_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiPSSphericalCollider") { TargetObjectRegistry.NiPSSphericalCollider_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiPSSpawner") { TargetObjectRegistry.NiPSSpawner_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiSequenceData") { TargetObjectRegistry.NiSequenceData_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiTransformEvaluator") { TargetObjectRegistry.NiTransformEvaluator_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiBSplineCompTransformEvaluator") { TargetObjectRegistry.NiBSplineCompTransformEvaluator_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiMeshHWInstance") { TargetObjectRegistry.NiMeshHWInstance_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiFurSpringController") { TargetObjectRegistry.NiFurSpringController_Registry.Read(in, link_stack, info); }
	if(ObjectType == "CStreamableAssetData") { TargetObjectRegistry.CStreamableAssetData_Registry.Read(in, link_stack, info); }
	if(ObjectType == "bhkCompressedMeshShape") { TargetObjectRegistry.bhkCompressedMeshShape_Registry.Read(in, link_stack, info); }
	if(ObjectType == "bhkCompressedMeshShapeData") { TargetObjectRegistry.bhkCompressedMeshShapeData_Registry.Read(in, link_stack, info); }
	if(ObjectType == "BSInvMarker") { TargetObjectRegistry.BSInvMarker_Registry.Read(in, link_stack, info); }
	if(ObjectType == "BSBoneLODExtraData") { TargetObjectRegistry.BSBoneLODExtraData_Registry.Read(in, link_stack, info); }
	if(ObjectType == "BSBehaviorGraphExtraData") { TargetObjectRegistry.BSBehaviorGraphExtraData_Registry.Read(in, link_stack, info); }
	if(ObjectType == "BSLagBoneController") { TargetObjectRegistry.BSLagBoneController_Registry.Read(in, link_stack, info); }
	if(ObjectType == "BSLODTriShape") { TargetObjectRegistry.BSLODTriShape_Registry.Read(in, link_stack, info); }
	if(ObjectType == "BSFurnitureMarkerNode") { TargetObjectRegistry.BSFurnitureMarkerNode_Registry.Read(in, link_stack, info); }
	if(ObjectType == "BSLeafAnimNode") { TargetObjectRegistry.BSLeafAnimNode_Registry.Read(in, link_stack, info); }
	if(ObjectType == "BSTreeNode") { TargetObjectRegistry.BSTreeNode_Registry.Read(in, link_stack, info); }
	if(ObjectType == "NiLightRadiusController") { TargetObjectRegistry.NiLightRadiusController_Registry.Read(in, link_stack, info); }
	if(ObjectType == "BSShape") { TargetObjectRegistry.BSShape_Registry.Read(in, link_stack, info); }
	if(ObjectType == "BSTriShape") { TargetObjectRegistry.BSTriShape_Registry.Read(in, link_stack, info); }
	if(ObjectType == "BSSubIndexTriShape") { TargetObjectRegistry.BSSubIndexTriShape_Registry.Read(in, link_stack, info); }
	if(ObjectType == "BSMeshLODTriShape") { TargetObjectRegistry.BSMeshLODTriShape_Registry.Read(in, link_stack, info); }
	if(ObjectType == "bhkNPCollisionObject") { TargetObjectRegistry.bhkNPCollisionObject_Registry.Read(in, link_stack, info); }
	if(ObjectType == "BSExtraData") { TargetObjectRegistry.BSExtraData_Registry.Read(in, link_stack, info); }
	if(ObjectType == "bhkPhysicsSystem") { TargetObjectRegistry.bhkPhysicsSystem_Registry.Read(in, link_stack, info); }
	if(ObjectType == "bhkRagdollSystem") { TargetObjectRegistry.bhkRagdollSystem_Registry.Read(in, link_stack, info); }
	if(ObjectType == "BSClothExtraData") { TargetObjectRegistry.BSClothExtraData_Registry.Read(in, link_stack, info); }
	if(ObjectType == "BSSkin__Instance") { TargetObjectRegistry.BSSkin__Instance_Registry.Read(in, link_stack, info); }
	if(ObjectType == "BSSkin__BoneData") { TargetObjectRegistry.BSSkin__BoneData_Registry.Read(in, link_stack, info); }
	if(ObjectType == "BSPositionData") { TargetObjectRegistry.BSPositionData_Registry.Read(in, link_stack, info); }
	if(ObjectType == "BSConnectPoint__Parents") { TargetObjectRegistry.BSConnectPoint__Parents_Registry.Read(in, link_stack, info); }
	if(ObjectType == "BSConnectPoint__Children") { TargetObjectRegistry.BSConnectPoint__Children_Registry.Read(in, link_stack, info); }
}

bool NifNodeTreeData::NifNodeTree::CreateObject(const std::string ObjectType)
{
	size_t TreeIndex = Size();
	AddData();
	//StorageNode.NodeName = ConvertPointerToStringAddress(new_obj);
	std::string InternalNameTemp = GenerateUnusedInternalName("Node_");
	CurrentNode = GetElementPointerV2(TreeIndex);
	CurrentNode->InternalName = InternalNameTemp;
	CurrentNodeInternalName = CurrentNode->InternalName;
	BaseLooseNode.Add(CurrentNodeInternalName);
	size_t Index=NodeTreeGlobals::ValueNotSet();
	//Now add actual node to ObjectRegistry
	if(ObjectType == "NiObject")
	{
		Index = TargetObjectRegistry.NiObject_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "Ni3dsAlphaAnimator")
	{
		Index = TargetObjectRegistry.Ni3dsAlphaAnimator_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "Ni3dsAnimationNode")
	{
		Index = TargetObjectRegistry.Ni3dsAnimationNode_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "Ni3dsColorAnimator")
	{
		Index = TargetObjectRegistry.Ni3dsColorAnimator_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "Ni3dsMorphShape")
	{
		Index = TargetObjectRegistry.Ni3dsMorphShape_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "Ni3dsParticleSystem")
	{
		Index = TargetObjectRegistry.Ni3dsParticleSystem_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "Ni3dsPathController")
	{
		Index = TargetObjectRegistry.Ni3dsPathController_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiParticleModifier")
	{
		Index = TargetObjectRegistry.NiParticleModifier_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiPSysCollider")
	{
		Index = TargetObjectRegistry.NiPSysCollider_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "bhkRefObject")
	{
		Index = TargetObjectRegistry.bhkRefObject_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "bhkSerializable")
	{
		Index = TargetObjectRegistry.bhkSerializable_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "bhkWorldObject")
	{
		Index = TargetObjectRegistry.bhkWorldObject_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "bhkPhantom")
	{
		Index = TargetObjectRegistry.bhkPhantom_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "bhkShapePhantom")
	{
		Index = TargetObjectRegistry.bhkShapePhantom_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "bhkSimpleShapePhantom")
	{
		Index = TargetObjectRegistry.bhkSimpleShapePhantom_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "bhkEntity")
	{
		Index = TargetObjectRegistry.bhkEntity_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "bhkRigidBody")
	{
		Index = TargetObjectRegistry.bhkRigidBody_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "bhkRigidBodyT")
	{
		Index = TargetObjectRegistry.bhkRigidBodyT_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "bhkConstraint")
	{
		Index = TargetObjectRegistry.bhkConstraint_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "bhkLimitedHingeConstraint")
	{
		Index = TargetObjectRegistry.bhkLimitedHingeConstraint_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "bhkMalleableConstraint")
	{
		Index = TargetObjectRegistry.bhkMalleableConstraint_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "bhkStiffSpringConstraint")
	{
		Index = TargetObjectRegistry.bhkStiffSpringConstraint_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "bhkRagdollConstraint")
	{
		Index = TargetObjectRegistry.bhkRagdollConstraint_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "bhkPrismaticConstraint")
	{
		Index = TargetObjectRegistry.bhkPrismaticConstraint_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "bhkHingeConstraint")
	{
		Index = TargetObjectRegistry.bhkHingeConstraint_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "bhkBallAndSocketConstraint")
	{
		Index = TargetObjectRegistry.bhkBallAndSocketConstraint_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "bhkBallSocketConstraintChain")
	{
		Index = TargetObjectRegistry.bhkBallSocketConstraintChain_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "bhkShape")
	{
		Index = TargetObjectRegistry.bhkShape_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "bhkTransformShape")
	{
		Index = TargetObjectRegistry.bhkTransformShape_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "bhkSphereRepShape")
	{
		Index = TargetObjectRegistry.bhkSphereRepShape_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "bhkConvexShape")
	{
		Index = TargetObjectRegistry.bhkConvexShape_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "bhkSphereShape")
	{
		Index = TargetObjectRegistry.bhkSphereShape_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "bhkCapsuleShape")
	{
		Index = TargetObjectRegistry.bhkCapsuleShape_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "bhkBoxShape")
	{
		Index = TargetObjectRegistry.bhkBoxShape_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "bhkConvexVerticesShape")
	{
		Index = TargetObjectRegistry.bhkConvexVerticesShape_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "bhkConvexTransformShape")
	{
		Index = TargetObjectRegistry.bhkConvexTransformShape_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "bhkMultiSphereShape")
	{
		Index = TargetObjectRegistry.bhkMultiSphereShape_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "bhkBvTreeShape")
	{
		Index = TargetObjectRegistry.bhkBvTreeShape_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "bhkMoppBvTreeShape")
	{
		Index = TargetObjectRegistry.bhkMoppBvTreeShape_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "bhkShapeCollection")
	{
		Index = TargetObjectRegistry.bhkShapeCollection_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "bhkListShape")
	{
		Index = TargetObjectRegistry.bhkListShape_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "bhkMeshShape")
	{
		Index = TargetObjectRegistry.bhkMeshShape_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "bhkPackedNiTriStripsShape")
	{
		Index = TargetObjectRegistry.bhkPackedNiTriStripsShape_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "bhkNiTriStripsShape")
	{
		Index = TargetObjectRegistry.bhkNiTriStripsShape_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiExtraData")
	{
		Index = TargetObjectRegistry.NiExtraData_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiInterpolator")
	{
		Index = TargetObjectRegistry.NiInterpolator_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiKeyBasedInterpolator")
	{
		Index = TargetObjectRegistry.NiKeyBasedInterpolator_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiFloatInterpolator")
	{
		Index = TargetObjectRegistry.NiFloatInterpolator_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiTransformInterpolator")
	{
		Index = TargetObjectRegistry.NiTransformInterpolator_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiPoint3Interpolator")
	{
		Index = TargetObjectRegistry.NiPoint3Interpolator_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiPathInterpolator")
	{
		Index = TargetObjectRegistry.NiPathInterpolator_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiBoolInterpolator")
	{
		Index = TargetObjectRegistry.NiBoolInterpolator_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiBoolTimelineInterpolator")
	{
		Index = TargetObjectRegistry.NiBoolTimelineInterpolator_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiBlendInterpolator")
	{
		Index = TargetObjectRegistry.NiBlendInterpolator_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiBSplineInterpolator")
	{
		Index = TargetObjectRegistry.NiBSplineInterpolator_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiObjectNET")
	{
		Index = TargetObjectRegistry.NiObjectNET_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiCollisionObject")
	{
		Index = TargetObjectRegistry.NiCollisionObject_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiCollisionData")
	{
		Index = TargetObjectRegistry.NiCollisionData_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "bhkNiCollisionObject")
	{
		Index = TargetObjectRegistry.bhkNiCollisionObject_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "bhkCollisionObject")
	{
		Index = TargetObjectRegistry.bhkCollisionObject_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "bhkBlendCollisionObject")
	{
		Index = TargetObjectRegistry.bhkBlendCollisionObject_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "bhkPCollisionObject")
	{
		Index = TargetObjectRegistry.bhkPCollisionObject_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "bhkSPCollisionObject")
	{
		Index = TargetObjectRegistry.bhkSPCollisionObject_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiAVObject")
	{
		Index = TargetObjectRegistry.NiAVObject_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiDynamicEffect")
	{
		Index = TargetObjectRegistry.NiDynamicEffect_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiLight")
	{
		Index = TargetObjectRegistry.NiLight_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiProperty")
	{
		Index = TargetObjectRegistry.NiProperty_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiTransparentProperty")
	{
		Index = TargetObjectRegistry.NiTransparentProperty_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiPSysModifier")
	{
		Index = TargetObjectRegistry.NiPSysModifier_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiPSysEmitter")
	{
		Index = TargetObjectRegistry.NiPSysEmitter_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiPSysVolumeEmitter")
	{
		Index = TargetObjectRegistry.NiPSysVolumeEmitter_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiTimeController")
	{
		Index = TargetObjectRegistry.NiTimeController_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiInterpController")
	{
		Index = TargetObjectRegistry.NiInterpController_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiMultiTargetTransformController")
	{
		Index = TargetObjectRegistry.NiMultiTargetTransformController_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiGeomMorpherController")
	{
		Index = TargetObjectRegistry.NiGeomMorpherController_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiMorphController")
	{
		Index = TargetObjectRegistry.NiMorphController_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiMorpherController")
	{
		Index = TargetObjectRegistry.NiMorpherController_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiSingleInterpController")
	{
		Index = TargetObjectRegistry.NiSingleInterpController_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiKeyframeController")
	{
		Index = TargetObjectRegistry.NiKeyframeController_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiTransformController")
	{
		Index = TargetObjectRegistry.NiTransformController_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiPSysModifierCtlr")
	{
		Index = TargetObjectRegistry.NiPSysModifierCtlr_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiPSysEmitterCtlr")
	{
		Index = TargetObjectRegistry.NiPSysEmitterCtlr_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiPSysModifierBoolCtlr")
	{
		Index = TargetObjectRegistry.NiPSysModifierBoolCtlr_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiPSysModifierActiveCtlr")
	{
		Index = TargetObjectRegistry.NiPSysModifierActiveCtlr_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiPSysModifierFloatCtlr")
	{
		Index = TargetObjectRegistry.NiPSysModifierFloatCtlr_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiPSysEmitterDeclinationCtlr")
	{
		Index = TargetObjectRegistry.NiPSysEmitterDeclinationCtlr_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiPSysEmitterDeclinationVarCtlr")
	{
		Index = TargetObjectRegistry.NiPSysEmitterDeclinationVarCtlr_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiPSysEmitterInitialRadiusCtlr")
	{
		Index = TargetObjectRegistry.NiPSysEmitterInitialRadiusCtlr_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiPSysEmitterLifeSpanCtlr")
	{
		Index = TargetObjectRegistry.NiPSysEmitterLifeSpanCtlr_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiPSysEmitterSpeedCtlr")
	{
		Index = TargetObjectRegistry.NiPSysEmitterSpeedCtlr_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiPSysGravityStrengthCtlr")
	{
		Index = TargetObjectRegistry.NiPSysGravityStrengthCtlr_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiFloatInterpController")
	{
		Index = TargetObjectRegistry.NiFloatInterpController_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiFlipController")
	{
		Index = TargetObjectRegistry.NiFlipController_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiAlphaController")
	{
		Index = TargetObjectRegistry.NiAlphaController_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiTextureTransformController")
	{
		Index = TargetObjectRegistry.NiTextureTransformController_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiLightDimmerController")
	{
		Index = TargetObjectRegistry.NiLightDimmerController_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiBoolInterpController")
	{
		Index = TargetObjectRegistry.NiBoolInterpController_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiVisController")
	{
		Index = TargetObjectRegistry.NiVisController_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiPoint3InterpController")
	{
		Index = TargetObjectRegistry.NiPoint3InterpController_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiMaterialColorController")
	{
		Index = TargetObjectRegistry.NiMaterialColorController_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiLightColorController")
	{
		Index = TargetObjectRegistry.NiLightColorController_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiExtraDataController")
	{
		Index = TargetObjectRegistry.NiExtraDataController_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiFloatExtraDataController")
	{
		Index = TargetObjectRegistry.NiFloatExtraDataController_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiBoneLODController")
	{
		Index = TargetObjectRegistry.NiBoneLODController_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiBSBoneLODController")
	{
		Index = TargetObjectRegistry.NiBSBoneLODController_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiGeometry")
	{
		Index = TargetObjectRegistry.NiGeometry_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiTriBasedGeom")
	{
		Index = TargetObjectRegistry.NiTriBasedGeom_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiGeometryData")
	{
		Index = TargetObjectRegistry.NiGeometryData_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "AbstractAdditionalGeometryData")
	{
		Index = TargetObjectRegistry.AbstractAdditionalGeometryData_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiTriBasedGeomData")
	{
		Index = TargetObjectRegistry.NiTriBasedGeomData_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "bhkBlendController")
	{
		Index = TargetObjectRegistry.bhkBlendController_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "BSBound")
	{
		Index = TargetObjectRegistry.BSBound_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "BSFurnitureMarker")
	{
		Index = TargetObjectRegistry.BSFurnitureMarker_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "BSParentVelocityModifier")
	{
		Index = TargetObjectRegistry.BSParentVelocityModifier_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "BSPSysArrayEmitter")
	{
		Index = TargetObjectRegistry.BSPSysArrayEmitter_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "BSWindModifier")
	{
		Index = TargetObjectRegistry.BSWindModifier_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "hkPackedNiTriStripsData")
	{
		Index = TargetObjectRegistry.hkPackedNiTriStripsData_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiAlphaProperty")
	{
		Index = TargetObjectRegistry.NiAlphaProperty_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiAmbientLight")
	{
		Index = TargetObjectRegistry.NiAmbientLight_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiParticlesData")
	{
		Index = TargetObjectRegistry.NiParticlesData_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiRotatingParticlesData")
	{
		Index = TargetObjectRegistry.NiRotatingParticlesData_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiAutoNormalParticlesData")
	{
		Index = TargetObjectRegistry.NiAutoNormalParticlesData_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiPSysData")
	{
		Index = TargetObjectRegistry.NiPSysData_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiMeshPSysData")
	{
		Index = TargetObjectRegistry.NiMeshPSysData_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiBinaryExtraData")
	{
		Index = TargetObjectRegistry.NiBinaryExtraData_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiBinaryVoxelExtraData")
	{
		Index = TargetObjectRegistry.NiBinaryVoxelExtraData_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiBinaryVoxelData")
	{
		Index = TargetObjectRegistry.NiBinaryVoxelData_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiBlendBoolInterpolator")
	{
		Index = TargetObjectRegistry.NiBlendBoolInterpolator_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiBlendFloatInterpolator")
	{
		Index = TargetObjectRegistry.NiBlendFloatInterpolator_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiBlendPoint3Interpolator")
	{
		Index = TargetObjectRegistry.NiBlendPoint3Interpolator_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiBlendTransformInterpolator")
	{
		Index = TargetObjectRegistry.NiBlendTransformInterpolator_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiBoolData")
	{
		Index = TargetObjectRegistry.NiBoolData_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiBooleanExtraData")
	{
		Index = TargetObjectRegistry.NiBooleanExtraData_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiBSplineBasisData")
	{
		Index = TargetObjectRegistry.NiBSplineBasisData_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiBSplineFloatInterpolator")
	{
		Index = TargetObjectRegistry.NiBSplineFloatInterpolator_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiBSplineCompFloatInterpolator")
	{
		Index = TargetObjectRegistry.NiBSplineCompFloatInterpolator_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiBSplinePoint3Interpolator")
	{
		Index = TargetObjectRegistry.NiBSplinePoint3Interpolator_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiBSplineCompPoint3Interpolator")
	{
		Index = TargetObjectRegistry.NiBSplineCompPoint3Interpolator_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiBSplineTransformInterpolator")
	{
		Index = TargetObjectRegistry.NiBSplineTransformInterpolator_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiBSplineCompTransformInterpolator")
	{
		Index = TargetObjectRegistry.NiBSplineCompTransformInterpolator_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "BSRotAccumTransfInterpolator")
	{
		Index = TargetObjectRegistry.BSRotAccumTransfInterpolator_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiBSplineData")
	{
		Index = TargetObjectRegistry.NiBSplineData_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiCamera")
	{
		Index = TargetObjectRegistry.NiCamera_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiColorData")
	{
		Index = TargetObjectRegistry.NiColorData_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiColorExtraData")
	{
		Index = TargetObjectRegistry.NiColorExtraData_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiControllerManager")
	{
		Index = TargetObjectRegistry.NiControllerManager_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiSequence")
	{
		Index = TargetObjectRegistry.NiSequence_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiControllerSequence")
	{
		Index = TargetObjectRegistry.NiControllerSequence_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiAVObjectPalette")
	{
		Index = TargetObjectRegistry.NiAVObjectPalette_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiDefaultAVObjectPalette")
	{
		Index = TargetObjectRegistry.NiDefaultAVObjectPalette_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiDirectionalLight")
	{
		Index = TargetObjectRegistry.NiDirectionalLight_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiDitherProperty")
	{
		Index = TargetObjectRegistry.NiDitherProperty_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiRollController")
	{
		Index = TargetObjectRegistry.NiRollController_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiFloatData")
	{
		Index = TargetObjectRegistry.NiFloatData_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiFloatExtraData")
	{
		Index = TargetObjectRegistry.NiFloatExtraData_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiFloatsExtraData")
	{
		Index = TargetObjectRegistry.NiFloatsExtraData_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiFogProperty")
	{
		Index = TargetObjectRegistry.NiFogProperty_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiGravity")
	{
		Index = TargetObjectRegistry.NiGravity_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiIntegerExtraData")
	{
		Index = TargetObjectRegistry.NiIntegerExtraData_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "BSXFlags")
	{
		Index = TargetObjectRegistry.BSXFlags_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiIntegersExtraData")
	{
		Index = TargetObjectRegistry.NiIntegersExtraData_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "BSKeyframeController")
	{
		Index = TargetObjectRegistry.BSKeyframeController_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiKeyframeData")
	{
		Index = TargetObjectRegistry.NiKeyframeData_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiLookAtController")
	{
		Index = TargetObjectRegistry.NiLookAtController_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiLookAtInterpolator")
	{
		Index = TargetObjectRegistry.NiLookAtInterpolator_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiMaterialProperty")
	{
		Index = TargetObjectRegistry.NiMaterialProperty_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiMorphData")
	{
		Index = TargetObjectRegistry.NiMorphData_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiNode")
	{
		Index = TargetObjectRegistry.NiNode_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiBone")
	{
		Index = TargetObjectRegistry.NiBone_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "AvoidNode")
	{
		Index = TargetObjectRegistry.AvoidNode_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "FxWidget")
	{
		Index = TargetObjectRegistry.FxWidget_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "FxButton")
	{
		Index = TargetObjectRegistry.FxButton_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "FxRadioButton")
	{
		Index = TargetObjectRegistry.FxRadioButton_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiBillboardNode")
	{
		Index = TargetObjectRegistry.NiBillboardNode_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiBSAnimationNode")
	{
		Index = TargetObjectRegistry.NiBSAnimationNode_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiBSParticleNode")
	{
		Index = TargetObjectRegistry.NiBSParticleNode_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiSwitchNode")
	{
		Index = TargetObjectRegistry.NiSwitchNode_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiLODNode")
	{
		Index = TargetObjectRegistry.NiLODNode_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiPalette")
	{
		Index = TargetObjectRegistry.NiPalette_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiParticleBomb")
	{
		Index = TargetObjectRegistry.NiParticleBomb_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiParticleColorModifier")
	{
		Index = TargetObjectRegistry.NiParticleColorModifier_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiParticleGrowFade")
	{
		Index = TargetObjectRegistry.NiParticleGrowFade_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiParticleMeshModifier")
	{
		Index = TargetObjectRegistry.NiParticleMeshModifier_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiParticleRotation")
	{
		Index = TargetObjectRegistry.NiParticleRotation_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiParticles")
	{
		Index = TargetObjectRegistry.NiParticles_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiAutoNormalParticles")
	{
		Index = TargetObjectRegistry.NiAutoNormalParticles_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiParticleMeshes")
	{
		Index = TargetObjectRegistry.NiParticleMeshes_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiParticleMeshesData")
	{
		Index = TargetObjectRegistry.NiParticleMeshesData_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiParticleSystem")
	{
		Index = TargetObjectRegistry.NiParticleSystem_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiMeshParticleSystem")
	{
		Index = TargetObjectRegistry.NiMeshParticleSystem_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiParticleSystemController")
	{
		Index = TargetObjectRegistry.NiParticleSystemController_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiBSPArrayController")
	{
		Index = TargetObjectRegistry.NiBSPArrayController_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiPathController")
	{
		Index = TargetObjectRegistry.NiPathController_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "ATextureRenderData")
	{
		Index = TargetObjectRegistry.ATextureRenderData_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiPersistentSrcTextureRendererData")
	{
		Index = TargetObjectRegistry.NiPersistentSrcTextureRendererData_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiPixelData")
	{
		Index = TargetObjectRegistry.NiPixelData_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiPlanarCollider")
	{
		Index = TargetObjectRegistry.NiPlanarCollider_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiPointLight")
	{
		Index = TargetObjectRegistry.NiPointLight_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiPosData")
	{
		Index = TargetObjectRegistry.NiPosData_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiPSysAgeDeathModifier")
	{
		Index = TargetObjectRegistry.NiPSysAgeDeathModifier_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiPSysBombModifier")
	{
		Index = TargetObjectRegistry.NiPSysBombModifier_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiPSysBoundUpdateModifier")
	{
		Index = TargetObjectRegistry.NiPSysBoundUpdateModifier_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiPSysBoxEmitter")
	{
		Index = TargetObjectRegistry.NiPSysBoxEmitter_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiPSysColliderManager")
	{
		Index = TargetObjectRegistry.NiPSysColliderManager_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiPSysColorModifier")
	{
		Index = TargetObjectRegistry.NiPSysColorModifier_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiPSysCylinderEmitter")
	{
		Index = TargetObjectRegistry.NiPSysCylinderEmitter_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiPSysDragModifier")
	{
		Index = TargetObjectRegistry.NiPSysDragModifier_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiPSysEmitterCtlrData")
	{
		Index = TargetObjectRegistry.NiPSysEmitterCtlrData_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiPSysGravityModifier")
	{
		Index = TargetObjectRegistry.NiPSysGravityModifier_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiPSysGrowFadeModifier")
	{
		Index = TargetObjectRegistry.NiPSysGrowFadeModifier_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiPSysMeshEmitter")
	{
		Index = TargetObjectRegistry.NiPSysMeshEmitter_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiPSysMeshUpdateModifier")
	{
		Index = TargetObjectRegistry.NiPSysMeshUpdateModifier_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "BSPSysInheritVelocityModifier")
	{
		Index = TargetObjectRegistry.BSPSysInheritVelocityModifier_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "BSPSysHavokUpdateModifier")
	{
		Index = TargetObjectRegistry.BSPSysHavokUpdateModifier_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "BSPSysRecycleBoundModifier")
	{
		Index = TargetObjectRegistry.BSPSysRecycleBoundModifier_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "BSPSysSubTexModifier")
	{
		Index = TargetObjectRegistry.BSPSysSubTexModifier_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiPSysPlanarCollider")
	{
		Index = TargetObjectRegistry.NiPSysPlanarCollider_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiPSysSphericalCollider")
	{
		Index = TargetObjectRegistry.NiPSysSphericalCollider_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiPSysPositionModifier")
	{
		Index = TargetObjectRegistry.NiPSysPositionModifier_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiPSysResetOnLoopCtlr")
	{
		Index = TargetObjectRegistry.NiPSysResetOnLoopCtlr_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiPSysRotationModifier")
	{
		Index = TargetObjectRegistry.NiPSysRotationModifier_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiPSysSpawnModifier")
	{
		Index = TargetObjectRegistry.NiPSysSpawnModifier_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiPSysSphereEmitter")
	{
		Index = TargetObjectRegistry.NiPSysSphereEmitter_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiPSysUpdateCtlr")
	{
		Index = TargetObjectRegistry.NiPSysUpdateCtlr_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiPSysFieldModifier")
	{
		Index = TargetObjectRegistry.NiPSysFieldModifier_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiPSysVortexFieldModifier")
	{
		Index = TargetObjectRegistry.NiPSysVortexFieldModifier_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiPSysGravityFieldModifier")
	{
		Index = TargetObjectRegistry.NiPSysGravityFieldModifier_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiPSysDragFieldModifier")
	{
		Index = TargetObjectRegistry.NiPSysDragFieldModifier_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiPSysTurbulenceFieldModifier")
	{
		Index = TargetObjectRegistry.NiPSysTurbulenceFieldModifier_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "BSPSysLODModifier")
	{
		Index = TargetObjectRegistry.BSPSysLODModifier_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "BSPSysScaleModifier")
	{
		Index = TargetObjectRegistry.BSPSysScaleModifier_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiPSysFieldMagnitudeCtlr")
	{
		Index = TargetObjectRegistry.NiPSysFieldMagnitudeCtlr_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiPSysFieldAttenuationCtlr")
	{
		Index = TargetObjectRegistry.NiPSysFieldAttenuationCtlr_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiPSysFieldMaxDistanceCtlr")
	{
		Index = TargetObjectRegistry.NiPSysFieldMaxDistanceCtlr_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiPSysAirFieldAirFrictionCtlr")
	{
		Index = TargetObjectRegistry.NiPSysAirFieldAirFrictionCtlr_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiPSysAirFieldInheritVelocityCtlr")
	{
		Index = TargetObjectRegistry.NiPSysAirFieldInheritVelocityCtlr_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiPSysAirFieldSpreadCtlr")
	{
		Index = TargetObjectRegistry.NiPSysAirFieldSpreadCtlr_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiPSysInitialRotSpeedCtlr")
	{
		Index = TargetObjectRegistry.NiPSysInitialRotSpeedCtlr_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiPSysInitialRotSpeedVarCtlr")
	{
		Index = TargetObjectRegistry.NiPSysInitialRotSpeedVarCtlr_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiPSysInitialRotAngleCtlr")
	{
		Index = TargetObjectRegistry.NiPSysInitialRotAngleCtlr_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiPSysInitialRotAngleVarCtlr")
	{
		Index = TargetObjectRegistry.NiPSysInitialRotAngleVarCtlr_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiPSysEmitterPlanarAngleCtlr")
	{
		Index = TargetObjectRegistry.NiPSysEmitterPlanarAngleCtlr_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiPSysEmitterPlanarAngleVarCtlr")
	{
		Index = TargetObjectRegistry.NiPSysEmitterPlanarAngleVarCtlr_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiPSysAirFieldModifier")
	{
		Index = TargetObjectRegistry.NiPSysAirFieldModifier_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiPSysTrailEmitter")
	{
		Index = TargetObjectRegistry.NiPSysTrailEmitter_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiLightIntensityController")
	{
		Index = TargetObjectRegistry.NiLightIntensityController_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiPSysRadialFieldModifier")
	{
		Index = TargetObjectRegistry.NiPSysRadialFieldModifier_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiLODData")
	{
		Index = TargetObjectRegistry.NiLODData_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiRangeLODData")
	{
		Index = TargetObjectRegistry.NiRangeLODData_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiScreenLODData")
	{
		Index = TargetObjectRegistry.NiScreenLODData_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiRotatingParticles")
	{
		Index = TargetObjectRegistry.NiRotatingParticles_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiSequenceStreamHelper")
	{
		Index = TargetObjectRegistry.NiSequenceStreamHelper_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiShadeProperty")
	{
		Index = TargetObjectRegistry.NiShadeProperty_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiSkinData")
	{
		Index = TargetObjectRegistry.NiSkinData_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiSkinInstance")
	{
		Index = TargetObjectRegistry.NiSkinInstance_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiTriShapeSkinController")
	{
		Index = TargetObjectRegistry.NiTriShapeSkinController_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiClodSkinInstance")
	{
		Index = TargetObjectRegistry.NiClodSkinInstance_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiSkinPartition")
	{
		Index = TargetObjectRegistry.NiSkinPartition_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiTexture")
	{
		Index = TargetObjectRegistry.NiTexture_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiSourceTexture")
	{
		Index = TargetObjectRegistry.NiSourceTexture_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiSpecularProperty")
	{
		Index = TargetObjectRegistry.NiSpecularProperty_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiSphericalCollider")
	{
		Index = TargetObjectRegistry.NiSphericalCollider_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiSpotLight")
	{
		Index = TargetObjectRegistry.NiSpotLight_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiStencilProperty")
	{
		Index = TargetObjectRegistry.NiStencilProperty_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiStringExtraData")
	{
		Index = TargetObjectRegistry.NiStringExtraData_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiStringPalette")
	{
		Index = TargetObjectRegistry.NiStringPalette_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiStringsExtraData")
	{
		Index = TargetObjectRegistry.NiStringsExtraData_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiTextKeyExtraData")
	{
		Index = TargetObjectRegistry.NiTextKeyExtraData_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiTextureEffect")
	{
		Index = TargetObjectRegistry.NiTextureEffect_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiTextureModeProperty")
	{
		Index = TargetObjectRegistry.NiTextureModeProperty_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiImage")
	{
		Index = TargetObjectRegistry.NiImage_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiTextureProperty")
	{
		Index = TargetObjectRegistry.NiTextureProperty_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiMultiTextureProperty")
	{
		Index = TargetObjectRegistry.NiMultiTextureProperty_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiTexturingProperty")
	{
		Index = TargetObjectRegistry.NiTexturingProperty_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiTransformData")
	{
		Index = TargetObjectRegistry.NiTransformData_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiTriShape")
	{
		Index = TargetObjectRegistry.NiTriShape_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiTriShapeData")
	{
		Index = TargetObjectRegistry.NiTriShapeData_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiTriStrips")
	{
		Index = TargetObjectRegistry.NiTriStrips_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiTriStripsData")
	{
		Index = TargetObjectRegistry.NiTriStripsData_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiEnvMappedTriShape")
	{
		Index = TargetObjectRegistry.NiEnvMappedTriShape_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiEnvMappedTriShapeData")
	{
		Index = TargetObjectRegistry.NiEnvMappedTriShapeData_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiBezierTriangle4")
	{
		Index = TargetObjectRegistry.NiBezierTriangle4_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiBezierMesh")
	{
		Index = TargetObjectRegistry.NiBezierMesh_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiClod")
	{
		Index = TargetObjectRegistry.NiClod_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiClodData")
	{
		Index = TargetObjectRegistry.NiClodData_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiUVController")
	{
		Index = TargetObjectRegistry.NiUVController_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiUVData")
	{
		Index = TargetObjectRegistry.NiUVData_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiVectorExtraData")
	{
		Index = TargetObjectRegistry.NiVectorExtraData_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiVertexColorProperty")
	{
		Index = TargetObjectRegistry.NiVertexColorProperty_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiVertWeightsExtraData")
	{
		Index = TargetObjectRegistry.NiVertWeightsExtraData_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiVisData")
	{
		Index = TargetObjectRegistry.NiVisData_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiWireframeProperty")
	{
		Index = TargetObjectRegistry.NiWireframeProperty_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiZBufferProperty")
	{
		Index = TargetObjectRegistry.NiZBufferProperty_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "RootCollisionNode")
	{
		Index = TargetObjectRegistry.RootCollisionNode_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiRawImageData")
	{
		Index = TargetObjectRegistry.NiRawImageData_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiSortAdjustNode")
	{
		Index = TargetObjectRegistry.NiSortAdjustNode_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiSourceCubeMap")
	{
		Index = TargetObjectRegistry.NiSourceCubeMap_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiPhysXProp")
	{
		Index = TargetObjectRegistry.NiPhysXProp_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiPhysXPropDesc")
	{
		Index = TargetObjectRegistry.NiPhysXPropDesc_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiPhysXActorDesc")
	{
		Index = TargetObjectRegistry.NiPhysXActorDesc_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiPhysXBodyDesc")
	{
		Index = TargetObjectRegistry.NiPhysXBodyDesc_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiPhysXD6JointDesc")
	{
		Index = TargetObjectRegistry.NiPhysXD6JointDesc_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiPhysXShapeDesc")
	{
		Index = TargetObjectRegistry.NiPhysXShapeDesc_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiPhysXMeshDesc")
	{
		Index = TargetObjectRegistry.NiPhysXMeshDesc_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiPhysXMaterialDesc")
	{
		Index = TargetObjectRegistry.NiPhysXMaterialDesc_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiPhysXKinematicSrc")
	{
		Index = TargetObjectRegistry.NiPhysXKinematicSrc_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiPhysXTransformDest")
	{
		Index = TargetObjectRegistry.NiPhysXTransformDest_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiArkAnimationExtraData")
	{
		Index = TargetObjectRegistry.NiArkAnimationExtraData_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiArkImporterExtraData")
	{
		Index = TargetObjectRegistry.NiArkImporterExtraData_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiArkTextureExtraData")
	{
		Index = TargetObjectRegistry.NiArkTextureExtraData_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiArkViewportInfoExtraData")
	{
		Index = TargetObjectRegistry.NiArkViewportInfoExtraData_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiArkShaderExtraData")
	{
		Index = TargetObjectRegistry.NiArkShaderExtraData_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiLines")
	{
		Index = TargetObjectRegistry.NiLines_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiLinesData")
	{
		Index = TargetObjectRegistry.NiLinesData_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiScreenElementsData")
	{
		Index = TargetObjectRegistry.NiScreenElementsData_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiScreenElements")
	{
		Index = TargetObjectRegistry.NiScreenElements_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiRoomGroup")
	{
		Index = TargetObjectRegistry.NiRoomGroup_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiRoom")
	{
		Index = TargetObjectRegistry.NiRoom_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiPortal")
	{
		Index = TargetObjectRegistry.NiPortal_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "BSFadeNode")
	{
		Index = TargetObjectRegistry.BSFadeNode_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "BSShaderProperty")
	{
		Index = TargetObjectRegistry.BSShaderProperty_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "BSShaderLightingProperty")
	{
		Index = TargetObjectRegistry.BSShaderLightingProperty_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "BSShaderNoLightingProperty")
	{
		Index = TargetObjectRegistry.BSShaderNoLightingProperty_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "BSShaderPPLightingProperty")
	{
		Index = TargetObjectRegistry.BSShaderPPLightingProperty_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "BSEffectShaderPropertyFloatController")
	{
		Index = TargetObjectRegistry.BSEffectShaderPropertyFloatController_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "BSEffectShaderPropertyColorController")
	{
		Index = TargetObjectRegistry.BSEffectShaderPropertyColorController_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "BSLightingShaderPropertyFloatController")
	{
		Index = TargetObjectRegistry.BSLightingShaderPropertyFloatController_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "BSLightingShaderPropertyColorController")
	{
		Index = TargetObjectRegistry.BSLightingShaderPropertyColorController_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "BSNiAlphaPropertyTestRefController")
	{
		Index = TargetObjectRegistry.BSNiAlphaPropertyTestRefController_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "BSProceduralLightningController")
	{
		Index = TargetObjectRegistry.BSProceduralLightningController_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "BSShaderTextureSet")
	{
		Index = TargetObjectRegistry.BSShaderTextureSet_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "WaterShaderProperty")
	{
		Index = TargetObjectRegistry.WaterShaderProperty_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "SkyShaderProperty")
	{
		Index = TargetObjectRegistry.SkyShaderProperty_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "TileShaderProperty")
	{
		Index = TargetObjectRegistry.TileShaderProperty_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "DistantLODShaderProperty")
	{
		Index = TargetObjectRegistry.DistantLODShaderProperty_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "BSDistantTreeShaderProperty")
	{
		Index = TargetObjectRegistry.BSDistantTreeShaderProperty_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "TallGrassShaderProperty")
	{
		Index = TargetObjectRegistry.TallGrassShaderProperty_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "VolumetricFogShaderProperty")
	{
		Index = TargetObjectRegistry.VolumetricFogShaderProperty_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "HairShaderProperty")
	{
		Index = TargetObjectRegistry.HairShaderProperty_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "Lighting30ShaderProperty")
	{
		Index = TargetObjectRegistry.Lighting30ShaderProperty_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "BSLightingShaderProperty")
	{
		Index = TargetObjectRegistry.BSLightingShaderProperty_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "BSEffectShaderProperty")
	{
		Index = TargetObjectRegistry.BSEffectShaderProperty_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "BSWaterShaderProperty")
	{
		Index = TargetObjectRegistry.BSWaterShaderProperty_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "BSSkyShaderProperty")
	{
		Index = TargetObjectRegistry.BSSkyShaderProperty_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "BSDismemberSkinInstance")
	{
		Index = TargetObjectRegistry.BSDismemberSkinInstance_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "BSDecalPlacementVectorExtraData")
	{
		Index = TargetObjectRegistry.BSDecalPlacementVectorExtraData_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "BSPSysSimpleColorModifier")
	{
		Index = TargetObjectRegistry.BSPSysSimpleColorModifier_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "BSValueNode")
	{
		Index = TargetObjectRegistry.BSValueNode_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "BSStripParticleSystem")
	{
		Index = TargetObjectRegistry.BSStripParticleSystem_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "BSStripPSysData")
	{
		Index = TargetObjectRegistry.BSStripPSysData_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "BSPSysStripUpdateModifier")
	{
		Index = TargetObjectRegistry.BSPSysStripUpdateModifier_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "BSMaterialEmittanceMultController")
	{
		Index = TargetObjectRegistry.BSMaterialEmittanceMultController_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "BSMasterParticleSystem")
	{
		Index = TargetObjectRegistry.BSMasterParticleSystem_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "BSPSysMultiTargetEmitterCtlr")
	{
		Index = TargetObjectRegistry.BSPSysMultiTargetEmitterCtlr_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "BSRefractionStrengthController")
	{
		Index = TargetObjectRegistry.BSRefractionStrengthController_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "BSOrderedNode")
	{
		Index = TargetObjectRegistry.BSOrderedNode_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "BSBlastNode")
	{
		Index = TargetObjectRegistry.BSBlastNode_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "BSDamageStage")
	{
		Index = TargetObjectRegistry.BSDamageStage_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "BSRefractionFirePeriodController")
	{
		Index = TargetObjectRegistry.BSRefractionFirePeriodController_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "bhkConvexListShape")
	{
		Index = TargetObjectRegistry.bhkConvexListShape_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "BSTreadTransfInterpolator")
	{
		Index = TargetObjectRegistry.BSTreadTransfInterpolator_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "BSAnimNotes")
	{
		Index = TargetObjectRegistry.BSAnimNotes_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "bhkLiquidAction")
	{
		Index = TargetObjectRegistry.bhkLiquidAction_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "BSMultiBoundNode")
	{
		Index = TargetObjectRegistry.BSMultiBoundNode_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "BSMultiBound")
	{
		Index = TargetObjectRegistry.BSMultiBound_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "BSMultiBoundData")
	{
		Index = TargetObjectRegistry.BSMultiBoundData_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "BSMultiBoundOBB")
	{
		Index = TargetObjectRegistry.BSMultiBoundOBB_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "BSMultiBoundSphere")
	{
		Index = TargetObjectRegistry.BSMultiBoundSphere_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "BSSegmentedTriShape")
	{
		Index = TargetObjectRegistry.BSSegmentedTriShape_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "BSMultiBoundAABB")
	{
		Index = TargetObjectRegistry.BSMultiBoundAABB_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiAdditionalGeometryData")
	{
		Index = TargetObjectRegistry.NiAdditionalGeometryData_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "BSPackedAdditionalGeometryData")
	{
		Index = TargetObjectRegistry.BSPackedAdditionalGeometryData_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "BSWArray")
	{
		Index = TargetObjectRegistry.BSWArray_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "bhkAabbPhantom")
	{
		Index = TargetObjectRegistry.bhkAabbPhantom_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "BSFrustumFOVController")
	{
		Index = TargetObjectRegistry.BSFrustumFOVController_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "BSDebrisNode")
	{
		Index = TargetObjectRegistry.BSDebrisNode_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "bhkBreakableConstraint")
	{
		Index = TargetObjectRegistry.bhkBreakableConstraint_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "bhkOrientHingedBodyAction")
	{
		Index = TargetObjectRegistry.bhkOrientHingedBodyAction_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiDataStream")
	{
		Index = TargetObjectRegistry.NiDataStream_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiRenderObject")
	{
		Index = TargetObjectRegistry.NiRenderObject_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiMeshModifier")
	{
		Index = TargetObjectRegistry.NiMeshModifier_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiMesh")
	{
		Index = TargetObjectRegistry.NiMesh_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiMorphWeightsController")
	{
		Index = TargetObjectRegistry.NiMorphWeightsController_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiMorphMeshModifier")
	{
		Index = TargetObjectRegistry.NiMorphMeshModifier_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiSkinningMeshModifier")
	{
		Index = TargetObjectRegistry.NiSkinningMeshModifier_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiInstancingMeshModifier")
	{
		Index = TargetObjectRegistry.NiInstancingMeshModifier_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiSkinningLODController")
	{
		Index = TargetObjectRegistry.NiSkinningLODController_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiPSParticleSystem")
	{
		Index = TargetObjectRegistry.NiPSParticleSystem_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiPSMeshParticleSystem")
	{
		Index = TargetObjectRegistry.NiPSMeshParticleSystem_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiPSEmitParticlesCtlr")
	{
		Index = TargetObjectRegistry.NiPSEmitParticlesCtlr_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiPSForceActiveCtlr")
	{
		Index = TargetObjectRegistry.NiPSForceActiveCtlr_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiPSSimulator")
	{
		Index = TargetObjectRegistry.NiPSSimulator_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiPSSimulatorStep")
	{
		Index = TargetObjectRegistry.NiPSSimulatorStep_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiPSSimulatorGeneralStep")
	{
		Index = TargetObjectRegistry.NiPSSimulatorGeneralStep_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiPSSimulatorForcesStep")
	{
		Index = TargetObjectRegistry.NiPSSimulatorForcesStep_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiPSSimulatorCollidersStep")
	{
		Index = TargetObjectRegistry.NiPSSimulatorCollidersStep_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiPSSimulatorMeshAlignStep")
	{
		Index = TargetObjectRegistry.NiPSSimulatorMeshAlignStep_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiPSSimulatorFinalStep")
	{
		Index = TargetObjectRegistry.NiPSSimulatorFinalStep_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiPSFacingQuadGenerator")
	{
		Index = TargetObjectRegistry.NiPSFacingQuadGenerator_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiShadowGenerator")
	{
		Index = TargetObjectRegistry.NiShadowGenerator_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiPSBoundUpdater")
	{
		Index = TargetObjectRegistry.NiPSBoundUpdater_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiPSDragForce")
	{
		Index = TargetObjectRegistry.NiPSDragForce_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiPSGravityForce")
	{
		Index = TargetObjectRegistry.NiPSGravityForce_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiPSBoxEmitter")
	{
		Index = TargetObjectRegistry.NiPSBoxEmitter_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiPSMeshEmitter")
	{
		Index = TargetObjectRegistry.NiPSMeshEmitter_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiPSGravityStrengthCtlr")
	{
		Index = TargetObjectRegistry.NiPSGravityStrengthCtlr_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiPSPlanarCollider")
	{
		Index = TargetObjectRegistry.NiPSPlanarCollider_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiPSEmitterSpeedCtlr")
	{
		Index = TargetObjectRegistry.NiPSEmitterSpeedCtlr_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiPSEmitterRadiusCtlr")
	{
		Index = TargetObjectRegistry.NiPSEmitterRadiusCtlr_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiPSResetOnLoopCtlr")
	{
		Index = TargetObjectRegistry.NiPSResetOnLoopCtlr_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiPSSphereEmitter")
	{
		Index = TargetObjectRegistry.NiPSSphereEmitter_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiPSCylinderEmitter")
	{
		Index = TargetObjectRegistry.NiPSCylinderEmitter_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiPSEmitterDeclinationCtlr")
	{
		Index = TargetObjectRegistry.NiPSEmitterDeclinationCtlr_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiPSEmitterDeclinationVarCtlr")
	{
		Index = TargetObjectRegistry.NiPSEmitterDeclinationVarCtlr_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiPSEmitterPlanarAngleCtlr")
	{
		Index = TargetObjectRegistry.NiPSEmitterPlanarAngleCtlr_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiPSEmitterPlanarAngleVarCtlr")
	{
		Index = TargetObjectRegistry.NiPSEmitterPlanarAngleVarCtlr_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiPSEmitterRotAngleCtlr")
	{
		Index = TargetObjectRegistry.NiPSEmitterRotAngleCtlr_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiPSEmitterRotAngleVarCtlr")
	{
		Index = TargetObjectRegistry.NiPSEmitterRotAngleVarCtlr_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiPSEmitterRotSpeedCtlr")
	{
		Index = TargetObjectRegistry.NiPSEmitterRotSpeedCtlr_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiPSEmitterRotSpeedVarCtlr")
	{
		Index = TargetObjectRegistry.NiPSEmitterRotSpeedVarCtlr_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiPSEmitterLifeSpanCtlr")
	{
		Index = TargetObjectRegistry.NiPSEmitterLifeSpanCtlr_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiPSBombForce")
	{
		Index = TargetObjectRegistry.NiPSBombForce_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiPSSphericalCollider")
	{
		Index = TargetObjectRegistry.NiPSSphericalCollider_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiPSSpawner")
	{
		Index = TargetObjectRegistry.NiPSSpawner_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiSequenceData")
	{
		Index = TargetObjectRegistry.NiSequenceData_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiTransformEvaluator")
	{
		Index = TargetObjectRegistry.NiTransformEvaluator_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiBSplineCompTransformEvaluator")
	{
		Index = TargetObjectRegistry.NiBSplineCompTransformEvaluator_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiMeshHWInstance")
	{
		Index = TargetObjectRegistry.NiMeshHWInstance_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiFurSpringController")
	{
		Index = TargetObjectRegistry.NiFurSpringController_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "CStreamableAssetData")
	{
		Index = TargetObjectRegistry.CStreamableAssetData_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "bhkCompressedMeshShape")
	{
		Index = TargetObjectRegistry.bhkCompressedMeshShape_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "bhkCompressedMeshShapeData")
	{
		Index = TargetObjectRegistry.bhkCompressedMeshShapeData_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "BSInvMarker")
	{
		Index = TargetObjectRegistry.BSInvMarker_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "BSBoneLODExtraData")
	{
		Index = TargetObjectRegistry.BSBoneLODExtraData_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "BSBehaviorGraphExtraData")
	{
		Index = TargetObjectRegistry.BSBehaviorGraphExtraData_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "BSLagBoneController")
	{
		Index = TargetObjectRegistry.BSLagBoneController_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "BSLODTriShape")
	{
		Index = TargetObjectRegistry.BSLODTriShape_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "BSFurnitureMarkerNode")
	{
		Index = TargetObjectRegistry.BSFurnitureMarkerNode_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "BSLeafAnimNode")
	{
		Index = TargetObjectRegistry.BSLeafAnimNode_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "BSTreeNode")
	{
		Index = TargetObjectRegistry.BSTreeNode_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "NiLightRadiusController")
	{
		Index = TargetObjectRegistry.NiLightRadiusController_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "BSShape")
	{
		Index = TargetObjectRegistry.BSShape_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "BSTriShape")
	{
		Index = TargetObjectRegistry.BSTriShape_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "BSSubIndexTriShape")
	{
		Index = TargetObjectRegistry.BSSubIndexTriShape_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "BSMeshLODTriShape")
	{
		Index = TargetObjectRegistry.BSMeshLODTriShape_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "bhkNPCollisionObject")
	{
		Index = TargetObjectRegistry.bhkNPCollisionObject_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "BSExtraData")
	{
		Index = TargetObjectRegistry.BSExtraData_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "bhkPhysicsSystem")
	{
		Index = TargetObjectRegistry.bhkPhysicsSystem_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "bhkRagdollSystem")
	{
		Index = TargetObjectRegistry.bhkRagdollSystem_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "BSClothExtraData")
	{
		Index = TargetObjectRegistry.BSClothExtraData_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "BSSkin__Instance")
	{
		Index = TargetObjectRegistry.BSSkin__Instance_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "BSSkin__BoneData")
	{
		Index = TargetObjectRegistry.BSSkin__BoneData_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "BSPositionData")
	{
		Index = TargetObjectRegistry.BSPositionData_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "BSConnectPoint__Parents")
	{
		Index = TargetObjectRegistry.BSConnectPoint__Parents_Registry.AddData(CurrentNode->InternalName);
	}
	if(ObjectType == "BSConnectPoint__Children")
	{
		Index = TargetObjectRegistry.BSConnectPoint__Children_Registry.AddData(CurrentNode->InternalName);
	}
	//End of ObjectRegistry Section
	FixCurrentNodeData();
	CurrentNode->IndexInRegistry = Index;
	if(Index==NodeTreeGlobals::ValueNotSet())
	{
		return false;
	}
	else
	{
		return true;
	}
}

std::string NifNodeTreeData::NifNodeTree::ReturnPointerStringOfNodeInObjectRegistry(NifNode* TargetNode)
{
	return StringFunctions::ConvertPointerToStringAddressV2(TargetNode);
}

template <typename DataType>
std::string NifNodeTreeData::NifNodeTree::GetInternalNameOfNodeData(DataType* DataNode, std::string NodeType)
{
	std::string RetrievedData="";
	std::string DataPointerString = StringFunctions::ConvertPointerToStringAddressV2(DataNode);
	if(NodeType=="")
	{
		NodeType = DataNode.GetDataType();
		if(NodeType == ""){return "";}
	}
	std::cout << "NodeType Detected as: " << NodeType << ".\n";
	system("timeout /t 1");
	size_t ListSize;
	//Separating Scope of ElementData Retrieval For Easier updating of code after generating code
	{
		if(NodeType == "NiObject" || NodeType == "NiObjectNode")
		{
			ListSize = TargetObjectRegistry.NiObject_Registry.Size();
			ObjectRegistryClasses::NiObjectNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "Ni3dsAlphaAnimator" || NodeType == "Ni3dsAlphaAnimatorNode")
		{
			ListSize = TargetObjectRegistry.Ni3dsAlphaAnimator_Registry.Size();
			ObjectRegistryClasses::Ni3dsAlphaAnimatorNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "Ni3dsAnimationNode" || NodeType == "Ni3dsAnimationNodeNode")
		{
			ListSize = TargetObjectRegistry.Ni3dsAnimationNode_Registry.Size();
			ObjectRegistryClasses::Ni3dsAnimationNodeNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "Ni3dsColorAnimator" || NodeType == "Ni3dsColorAnimatorNode")
		{
			ListSize = TargetObjectRegistry.Ni3dsColorAnimator_Registry.Size();
			ObjectRegistryClasses::Ni3dsColorAnimatorNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "Ni3dsMorphShape" || NodeType == "Ni3dsMorphShapeNode")
		{
			ListSize = TargetObjectRegistry.Ni3dsMorphShape_Registry.Size();
			ObjectRegistryClasses::Ni3dsMorphShapeNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "Ni3dsParticleSystem" || NodeType == "Ni3dsParticleSystemNode")
		{
			ListSize = TargetObjectRegistry.Ni3dsParticleSystem_Registry.Size();
			ObjectRegistryClasses::Ni3dsParticleSystemNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "Ni3dsPathController" || NodeType == "Ni3dsPathControllerNode")
		{
			ListSize = TargetObjectRegistry.Ni3dsPathController_Registry.Size();
			ObjectRegistryClasses::Ni3dsPathControllerNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiParticleModifier" || NodeType == "NiParticleModifierNode")
		{
			ListSize = TargetObjectRegistry.NiParticleModifier_Registry.Size();
			ObjectRegistryClasses::NiParticleModifierNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiPSysCollider" || NodeType == "NiPSysColliderNode")
		{
			ListSize = TargetObjectRegistry.NiPSysCollider_Registry.Size();
			ObjectRegistryClasses::NiPSysColliderNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "bhkRefObject" || NodeType == "bhkRefObjectNode")
		{
			ListSize = TargetObjectRegistry.bhkRefObject_Registry.Size();
			ObjectRegistryClasses::bhkRefObjectNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "bhkSerializable" || NodeType == "bhkSerializableNode")
		{
			ListSize = TargetObjectRegistry.bhkSerializable_Registry.Size();
			ObjectRegistryClasses::bhkSerializableNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "bhkWorldObject" || NodeType == "bhkWorldObjectNode")
		{
			ListSize = TargetObjectRegistry.bhkWorldObject_Registry.Size();
			ObjectRegistryClasses::bhkWorldObjectNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "bhkPhantom" || NodeType == "bhkPhantomNode")
		{
			ListSize = TargetObjectRegistry.bhkPhantom_Registry.Size();
			ObjectRegistryClasses::bhkPhantomNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "bhkShapePhantom" || NodeType == "bhkShapePhantomNode")
		{
			ListSize = TargetObjectRegistry.bhkShapePhantom_Registry.Size();
			ObjectRegistryClasses::bhkShapePhantomNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "bhkSimpleShapePhantom" || NodeType == "bhkSimpleShapePhantomNode")
		{
			ListSize = TargetObjectRegistry.bhkSimpleShapePhantom_Registry.Size();
			ObjectRegistryClasses::bhkSimpleShapePhantomNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "bhkEntity" || NodeType == "bhkEntityNode")
		{
			ListSize = TargetObjectRegistry.bhkEntity_Registry.Size();
			ObjectRegistryClasses::bhkEntityNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "bhkRigidBody" || NodeType == "bhkRigidBodyNode")
		{
			ListSize = TargetObjectRegistry.bhkRigidBody_Registry.Size();
			ObjectRegistryClasses::bhkRigidBodyNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "bhkRigidBodyT" || NodeType == "bhkRigidBodyTNode")
		{
			ListSize = TargetObjectRegistry.bhkRigidBodyT_Registry.Size();
			ObjectRegistryClasses::bhkRigidBodyTNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "bhkConstraint" || NodeType == "bhkConstraintNode")
		{
			ListSize = TargetObjectRegistry.bhkConstraint_Registry.Size();
			ObjectRegistryClasses::bhkConstraintNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "bhkLimitedHingeConstraint" || NodeType == "bhkLimitedHingeConstraintNode")
		{
			ListSize = TargetObjectRegistry.bhkLimitedHingeConstraint_Registry.Size();
			ObjectRegistryClasses::bhkLimitedHingeConstraintNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "bhkMalleableConstraint" || NodeType == "bhkMalleableConstraintNode")
		{
			ListSize = TargetObjectRegistry.bhkMalleableConstraint_Registry.Size();
			ObjectRegistryClasses::bhkMalleableConstraintNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "bhkStiffSpringConstraint" || NodeType == "bhkStiffSpringConstraintNode")
		{
			ListSize = TargetObjectRegistry.bhkStiffSpringConstraint_Registry.Size();
			ObjectRegistryClasses::bhkStiffSpringConstraintNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "bhkRagdollConstraint" || NodeType == "bhkRagdollConstraintNode")
		{
			ListSize = TargetObjectRegistry.bhkRagdollConstraint_Registry.Size();
			ObjectRegistryClasses::bhkRagdollConstraintNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "bhkPrismaticConstraint" || NodeType == "bhkPrismaticConstraintNode")
		{
			ListSize = TargetObjectRegistry.bhkPrismaticConstraint_Registry.Size();
			ObjectRegistryClasses::bhkPrismaticConstraintNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "bhkHingeConstraint" || NodeType == "bhkHingeConstraintNode")
		{
			ListSize = TargetObjectRegistry.bhkHingeConstraint_Registry.Size();
			ObjectRegistryClasses::bhkHingeConstraintNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "bhkBallAndSocketConstraint" || NodeType == "bhkBallAndSocketConstraintNode")
		{
			ListSize = TargetObjectRegistry.bhkBallAndSocketConstraint_Registry.Size();
			ObjectRegistryClasses::bhkBallAndSocketConstraintNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "bhkBallSocketConstraintChain" || NodeType == "bhkBallSocketConstraintChainNode")
		{
			ListSize = TargetObjectRegistry.bhkBallSocketConstraintChain_Registry.Size();
			ObjectRegistryClasses::bhkBallSocketConstraintChainNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "bhkShape" || NodeType == "bhkShapeNode")
		{
			ListSize = TargetObjectRegistry.bhkShape_Registry.Size();
			ObjectRegistryClasses::bhkShapeNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "bhkTransformShape" || NodeType == "bhkTransformShapeNode")
		{
			ListSize = TargetObjectRegistry.bhkTransformShape_Registry.Size();
			ObjectRegistryClasses::bhkTransformShapeNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "bhkSphereRepShape" || NodeType == "bhkSphereRepShapeNode")
		{
			ListSize = TargetObjectRegistry.bhkSphereRepShape_Registry.Size();
			ObjectRegistryClasses::bhkSphereRepShapeNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "bhkConvexShape" || NodeType == "bhkConvexShapeNode")
		{
			ListSize = TargetObjectRegistry.bhkConvexShape_Registry.Size();
			ObjectRegistryClasses::bhkConvexShapeNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "bhkSphereShape" || NodeType == "bhkSphereShapeNode")
		{
			ListSize = TargetObjectRegistry.bhkSphereShape_Registry.Size();
			ObjectRegistryClasses::bhkSphereShapeNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "bhkCapsuleShape" || NodeType == "bhkCapsuleShapeNode")
		{
			ListSize = TargetObjectRegistry.bhkCapsuleShape_Registry.Size();
			ObjectRegistryClasses::bhkCapsuleShapeNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "bhkBoxShape" || NodeType == "bhkBoxShapeNode")
		{
			ListSize = TargetObjectRegistry.bhkBoxShape_Registry.Size();
			ObjectRegistryClasses::bhkBoxShapeNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "bhkConvexVerticesShape" || NodeType == "bhkConvexVerticesShapeNode")
		{
			ListSize = TargetObjectRegistry.bhkConvexVerticesShape_Registry.Size();
			ObjectRegistryClasses::bhkConvexVerticesShapeNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "bhkConvexTransformShape" || NodeType == "bhkConvexTransformShapeNode")
		{
			ListSize = TargetObjectRegistry.bhkConvexTransformShape_Registry.Size();
			ObjectRegistryClasses::bhkConvexTransformShapeNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "bhkMultiSphereShape" || NodeType == "bhkMultiSphereShapeNode")
		{
			ListSize = TargetObjectRegistry.bhkMultiSphereShape_Registry.Size();
			ObjectRegistryClasses::bhkMultiSphereShapeNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "bhkBvTreeShape" || NodeType == "bhkBvTreeShapeNode")
		{
			ListSize = TargetObjectRegistry.bhkBvTreeShape_Registry.Size();
			ObjectRegistryClasses::bhkBvTreeShapeNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "bhkMoppBvTreeShape" || NodeType == "bhkMoppBvTreeShapeNode")
		{
			ListSize = TargetObjectRegistry.bhkMoppBvTreeShape_Registry.Size();
			ObjectRegistryClasses::bhkMoppBvTreeShapeNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "bhkShapeCollection" || NodeType == "bhkShapeCollectionNode")
		{
			ListSize = TargetObjectRegistry.bhkShapeCollection_Registry.Size();
			ObjectRegistryClasses::bhkShapeCollectionNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "bhkListShape" || NodeType == "bhkListShapeNode")
		{
			ListSize = TargetObjectRegistry.bhkListShape_Registry.Size();
			ObjectRegistryClasses::bhkListShapeNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "bhkMeshShape" || NodeType == "bhkMeshShapeNode")
		{
			ListSize = TargetObjectRegistry.bhkMeshShape_Registry.Size();
			ObjectRegistryClasses::bhkMeshShapeNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "bhkPackedNiTriStripsShape" || NodeType == "bhkPackedNiTriStripsShapeNode")
		{
			ListSize = TargetObjectRegistry.bhkPackedNiTriStripsShape_Registry.Size();
			ObjectRegistryClasses::bhkPackedNiTriStripsShapeNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "bhkNiTriStripsShape" || NodeType == "bhkNiTriStripsShapeNode")
		{
			ListSize = TargetObjectRegistry.bhkNiTriStripsShape_Registry.Size();
			ObjectRegistryClasses::bhkNiTriStripsShapeNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiExtraData" || NodeType == "NiExtraDataNode")
		{
			ListSize = TargetObjectRegistry.NiExtraData_Registry.Size();
			ObjectRegistryClasses::NiExtraDataNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiInterpolator" || NodeType == "NiInterpolatorNode")
		{
			ListSize = TargetObjectRegistry.NiInterpolator_Registry.Size();
			ObjectRegistryClasses::NiInterpolatorNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiKeyBasedInterpolator" || NodeType == "NiKeyBasedInterpolatorNode")
		{
			ListSize = TargetObjectRegistry.NiKeyBasedInterpolator_Registry.Size();
			ObjectRegistryClasses::NiKeyBasedInterpolatorNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiFloatInterpolator" || NodeType == "NiFloatInterpolatorNode")
		{
			ListSize = TargetObjectRegistry.NiFloatInterpolator_Registry.Size();
			ObjectRegistryClasses::NiFloatInterpolatorNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiTransformInterpolator" || NodeType == "NiTransformInterpolatorNode")
		{
			ListSize = TargetObjectRegistry.NiTransformInterpolator_Registry.Size();
			ObjectRegistryClasses::NiTransformInterpolatorNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiPoint3Interpolator" || NodeType == "NiPoint3InterpolatorNode")
		{
			ListSize = TargetObjectRegistry.NiPoint3Interpolator_Registry.Size();
			ObjectRegistryClasses::NiPoint3InterpolatorNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiPathInterpolator" || NodeType == "NiPathInterpolatorNode")
		{
			ListSize = TargetObjectRegistry.NiPathInterpolator_Registry.Size();
			ObjectRegistryClasses::NiPathInterpolatorNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiBoolInterpolator" || NodeType == "NiBoolInterpolatorNode")
		{
			ListSize = TargetObjectRegistry.NiBoolInterpolator_Registry.Size();
			ObjectRegistryClasses::NiBoolInterpolatorNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiBoolTimelineInterpolator" || NodeType == "NiBoolTimelineInterpolatorNode")
		{
			ListSize = TargetObjectRegistry.NiBoolTimelineInterpolator_Registry.Size();
			ObjectRegistryClasses::NiBoolTimelineInterpolatorNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiBlendInterpolator" || NodeType == "NiBlendInterpolatorNode")
		{
			ListSize = TargetObjectRegistry.NiBlendInterpolator_Registry.Size();
			ObjectRegistryClasses::NiBlendInterpolatorNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiBSplineInterpolator" || NodeType == "NiBSplineInterpolatorNode")
		{
			ListSize = TargetObjectRegistry.NiBSplineInterpolator_Registry.Size();
			ObjectRegistryClasses::NiBSplineInterpolatorNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiObjectNET" || NodeType == "NiObjectNETNode")
		{
			ListSize = TargetObjectRegistry.NiObjectNET_Registry.Size();
			ObjectRegistryClasses::NiObjectNETNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiCollisionObject" || NodeType == "NiCollisionObjectNode")
		{
			ListSize = TargetObjectRegistry.NiCollisionObject_Registry.Size();
			ObjectRegistryClasses::NiCollisionObjectNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiCollisionData" || NodeType == "NiCollisionDataNode")
		{
			ListSize = TargetObjectRegistry.NiCollisionData_Registry.Size();
			ObjectRegistryClasses::NiCollisionDataNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "bhkNiCollisionObject" || NodeType == "bhkNiCollisionObjectNode")
		{
			ListSize = TargetObjectRegistry.bhkNiCollisionObject_Registry.Size();
			ObjectRegistryClasses::bhkNiCollisionObjectNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "bhkCollisionObject" || NodeType == "bhkCollisionObjectNode")
		{
			ListSize = TargetObjectRegistry.bhkCollisionObject_Registry.Size();
			ObjectRegistryClasses::bhkCollisionObjectNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "bhkBlendCollisionObject" || NodeType == "bhkBlendCollisionObjectNode")
		{
			ListSize = TargetObjectRegistry.bhkBlendCollisionObject_Registry.Size();
			ObjectRegistryClasses::bhkBlendCollisionObjectNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "bhkPCollisionObject" || NodeType == "bhkPCollisionObjectNode")
		{
			ListSize = TargetObjectRegistry.bhkPCollisionObject_Registry.Size();
			ObjectRegistryClasses::bhkPCollisionObjectNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "bhkSPCollisionObject" || NodeType == "bhkSPCollisionObjectNode")
		{
			ListSize = TargetObjectRegistry.bhkSPCollisionObject_Registry.Size();
			ObjectRegistryClasses::bhkSPCollisionObjectNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiAVObject" || NodeType == "NiAVObjectNode")
		{
			ListSize = TargetObjectRegistry.NiAVObject_Registry.Size();
			ObjectRegistryClasses::NiAVObjectNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiDynamicEffect" || NodeType == "NiDynamicEffectNode")
		{
			ListSize = TargetObjectRegistry.NiDynamicEffect_Registry.Size();
			ObjectRegistryClasses::NiDynamicEffectNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiLight" || NodeType == "NiLightNode")
		{
			ListSize = TargetObjectRegistry.NiLight_Registry.Size();
			ObjectRegistryClasses::NiLightNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiProperty" || NodeType == "NiPropertyNode")
		{
			ListSize = TargetObjectRegistry.NiProperty_Registry.Size();
			ObjectRegistryClasses::NiPropertyNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiTransparentProperty" || NodeType == "NiTransparentPropertyNode")
		{
			ListSize = TargetObjectRegistry.NiTransparentProperty_Registry.Size();
			ObjectRegistryClasses::NiTransparentPropertyNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiPSysModifier" || NodeType == "NiPSysModifierNode")
		{
			ListSize = TargetObjectRegistry.NiPSysModifier_Registry.Size();
			ObjectRegistryClasses::NiPSysModifierNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiPSysEmitter" || NodeType == "NiPSysEmitterNode")
		{
			ListSize = TargetObjectRegistry.NiPSysEmitter_Registry.Size();
			ObjectRegistryClasses::NiPSysEmitterNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiPSysVolumeEmitter" || NodeType == "NiPSysVolumeEmitterNode")
		{
			ListSize = TargetObjectRegistry.NiPSysVolumeEmitter_Registry.Size();
			ObjectRegistryClasses::NiPSysVolumeEmitterNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiTimeController" || NodeType == "NiTimeControllerNode")
		{
			ListSize = TargetObjectRegistry.NiTimeController_Registry.Size();
			ObjectRegistryClasses::NiTimeControllerNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiInterpController" || NodeType == "NiInterpControllerNode")
		{
			ListSize = TargetObjectRegistry.NiInterpController_Registry.Size();
			ObjectRegistryClasses::NiInterpControllerNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiMultiTargetTransformController" || NodeType == "NiMultiTargetTransformControllerNode")
		{
			ListSize = TargetObjectRegistry.NiMultiTargetTransformController_Registry.Size();
			ObjectRegistryClasses::NiMultiTargetTransformControllerNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiGeomMorpherController" || NodeType == "NiGeomMorpherControllerNode")
		{
			ListSize = TargetObjectRegistry.NiGeomMorpherController_Registry.Size();
			ObjectRegistryClasses::NiGeomMorpherControllerNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiMorphController" || NodeType == "NiMorphControllerNode")
		{
			ListSize = TargetObjectRegistry.NiMorphController_Registry.Size();
			ObjectRegistryClasses::NiMorphControllerNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiMorpherController" || NodeType == "NiMorpherControllerNode")
		{
			ListSize = TargetObjectRegistry.NiMorpherController_Registry.Size();
			ObjectRegistryClasses::NiMorpherControllerNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiSingleInterpController" || NodeType == "NiSingleInterpControllerNode")
		{
			ListSize = TargetObjectRegistry.NiSingleInterpController_Registry.Size();
			ObjectRegistryClasses::NiSingleInterpControllerNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiKeyframeController" || NodeType == "NiKeyframeControllerNode")
		{
			ListSize = TargetObjectRegistry.NiKeyframeController_Registry.Size();
			ObjectRegistryClasses::NiKeyframeControllerNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiTransformController" || NodeType == "NiTransformControllerNode")
		{
			ListSize = TargetObjectRegistry.NiTransformController_Registry.Size();
			ObjectRegistryClasses::NiTransformControllerNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiPSysModifierCtlr" || NodeType == "NiPSysModifierCtlrNode")
		{
			ListSize = TargetObjectRegistry.NiPSysModifierCtlr_Registry.Size();
			ObjectRegistryClasses::NiPSysModifierCtlrNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiPSysEmitterCtlr" || NodeType == "NiPSysEmitterCtlrNode")
		{
			ListSize = TargetObjectRegistry.NiPSysEmitterCtlr_Registry.Size();
			ObjectRegistryClasses::NiPSysEmitterCtlrNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiPSysModifierBoolCtlr" || NodeType == "NiPSysModifierBoolCtlrNode")
		{
			ListSize = TargetObjectRegistry.NiPSysModifierBoolCtlr_Registry.Size();
			ObjectRegistryClasses::NiPSysModifierBoolCtlrNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiPSysModifierActiveCtlr" || NodeType == "NiPSysModifierActiveCtlrNode")
		{
			ListSize = TargetObjectRegistry.NiPSysModifierActiveCtlr_Registry.Size();
			ObjectRegistryClasses::NiPSysModifierActiveCtlrNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiPSysModifierFloatCtlr" || NodeType == "NiPSysModifierFloatCtlrNode")
		{
			ListSize = TargetObjectRegistry.NiPSysModifierFloatCtlr_Registry.Size();
			ObjectRegistryClasses::NiPSysModifierFloatCtlrNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiPSysEmitterDeclinationCtlr" || NodeType == "NiPSysEmitterDeclinationCtlrNode")
		{
			ListSize = TargetObjectRegistry.NiPSysEmitterDeclinationCtlr_Registry.Size();
			ObjectRegistryClasses::NiPSysEmitterDeclinationCtlrNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiPSysEmitterDeclinationVarCtlr" || NodeType == "NiPSysEmitterDeclinationVarCtlrNode")
		{
			ListSize = TargetObjectRegistry.NiPSysEmitterDeclinationVarCtlr_Registry.Size();
			ObjectRegistryClasses::NiPSysEmitterDeclinationVarCtlrNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiPSysEmitterInitialRadiusCtlr" || NodeType == "NiPSysEmitterInitialRadiusCtlrNode")
		{
			ListSize = TargetObjectRegistry.NiPSysEmitterInitialRadiusCtlr_Registry.Size();
			ObjectRegistryClasses::NiPSysEmitterInitialRadiusCtlrNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiPSysEmitterLifeSpanCtlr" || NodeType == "NiPSysEmitterLifeSpanCtlrNode")
		{
			ListSize = TargetObjectRegistry.NiPSysEmitterLifeSpanCtlr_Registry.Size();
			ObjectRegistryClasses::NiPSysEmitterLifeSpanCtlrNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiPSysEmitterSpeedCtlr" || NodeType == "NiPSysEmitterSpeedCtlrNode")
		{
			ListSize = TargetObjectRegistry.NiPSysEmitterSpeedCtlr_Registry.Size();
			ObjectRegistryClasses::NiPSysEmitterSpeedCtlrNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiPSysGravityStrengthCtlr" || NodeType == "NiPSysGravityStrengthCtlrNode")
		{
			ListSize = TargetObjectRegistry.NiPSysGravityStrengthCtlr_Registry.Size();
			ObjectRegistryClasses::NiPSysGravityStrengthCtlrNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiFloatInterpController" || NodeType == "NiFloatInterpControllerNode")
		{
			ListSize = TargetObjectRegistry.NiFloatInterpController_Registry.Size();
			ObjectRegistryClasses::NiFloatInterpControllerNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiFlipController" || NodeType == "NiFlipControllerNode")
		{
			ListSize = TargetObjectRegistry.NiFlipController_Registry.Size();
			ObjectRegistryClasses::NiFlipControllerNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiAlphaController" || NodeType == "NiAlphaControllerNode")
		{
			ListSize = TargetObjectRegistry.NiAlphaController_Registry.Size();
			ObjectRegistryClasses::NiAlphaControllerNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiTextureTransformController" || NodeType == "NiTextureTransformControllerNode")
		{
			ListSize = TargetObjectRegistry.NiTextureTransformController_Registry.Size();
			ObjectRegistryClasses::NiTextureTransformControllerNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiLightDimmerController" || NodeType == "NiLightDimmerControllerNode")
		{
			ListSize = TargetObjectRegistry.NiLightDimmerController_Registry.Size();
			ObjectRegistryClasses::NiLightDimmerControllerNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiBoolInterpController" || NodeType == "NiBoolInterpControllerNode")
		{
			ListSize = TargetObjectRegistry.NiBoolInterpController_Registry.Size();
			ObjectRegistryClasses::NiBoolInterpControllerNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiVisController" || NodeType == "NiVisControllerNode")
		{
			ListSize = TargetObjectRegistry.NiVisController_Registry.Size();
			ObjectRegistryClasses::NiVisControllerNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiPoint3InterpController" || NodeType == "NiPoint3InterpControllerNode")
		{
			ListSize = TargetObjectRegistry.NiPoint3InterpController_Registry.Size();
			ObjectRegistryClasses::NiPoint3InterpControllerNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiMaterialColorController" || NodeType == "NiMaterialColorControllerNode")
		{
			ListSize = TargetObjectRegistry.NiMaterialColorController_Registry.Size();
			ObjectRegistryClasses::NiMaterialColorControllerNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiLightColorController" || NodeType == "NiLightColorControllerNode")
		{
			ListSize = TargetObjectRegistry.NiLightColorController_Registry.Size();
			ObjectRegistryClasses::NiLightColorControllerNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiExtraDataController" || NodeType == "NiExtraDataControllerNode")
		{
			ListSize = TargetObjectRegistry.NiExtraDataController_Registry.Size();
			ObjectRegistryClasses::NiExtraDataControllerNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiFloatExtraDataController" || NodeType == "NiFloatExtraDataControllerNode")
		{
			ListSize = TargetObjectRegistry.NiFloatExtraDataController_Registry.Size();
			ObjectRegistryClasses::NiFloatExtraDataControllerNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiBoneLODController" || NodeType == "NiBoneLODControllerNode")
		{
			ListSize = TargetObjectRegistry.NiBoneLODController_Registry.Size();
			ObjectRegistryClasses::NiBoneLODControllerNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiBSBoneLODController" || NodeType == "NiBSBoneLODControllerNode")
		{
			ListSize = TargetObjectRegistry.NiBSBoneLODController_Registry.Size();
			ObjectRegistryClasses::NiBSBoneLODControllerNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiGeometry" || NodeType == "NiGeometryNode")
		{
			ListSize = TargetObjectRegistry.NiGeometry_Registry.Size();
			ObjectRegistryClasses::NiGeometryNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiTriBasedGeom" || NodeType == "NiTriBasedGeomNode")
		{
			ListSize = TargetObjectRegistry.NiTriBasedGeom_Registry.Size();
			ObjectRegistryClasses::NiTriBasedGeomNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiGeometryData" || NodeType == "NiGeometryDataNode")
		{
			ListSize = TargetObjectRegistry.NiGeometryData_Registry.Size();
			ObjectRegistryClasses::NiGeometryDataNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "AbstractAdditionalGeometryData" || NodeType == "AbstractAdditionalGeometryDataNode")
		{
			ListSize = TargetObjectRegistry.AbstractAdditionalGeometryData_Registry.Size();
			ObjectRegistryClasses::AbstractAdditionalGeometryDataNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiTriBasedGeomData" || NodeType == "NiTriBasedGeomDataNode")
		{
			ListSize = TargetObjectRegistry.NiTriBasedGeomData_Registry.Size();
			ObjectRegistryClasses::NiTriBasedGeomDataNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "bhkBlendController" || NodeType == "bhkBlendControllerNode")
		{
			ListSize = TargetObjectRegistry.bhkBlendController_Registry.Size();
			ObjectRegistryClasses::bhkBlendControllerNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "BSBound" || NodeType == "BSBoundNode")
		{
			ListSize = TargetObjectRegistry.BSBound_Registry.Size();
			ObjectRegistryClasses::BSBoundNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "BSFurnitureMarker" || NodeType == "BSFurnitureMarkerNode")
		{
			ListSize = TargetObjectRegistry.BSFurnitureMarker_Registry.Size();
			ObjectRegistryClasses::BSFurnitureMarkerNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "BSParentVelocityModifier" || NodeType == "BSParentVelocityModifierNode")
		{
			ListSize = TargetObjectRegistry.BSParentVelocityModifier_Registry.Size();
			ObjectRegistryClasses::BSParentVelocityModifierNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "BSPSysArrayEmitter" || NodeType == "BSPSysArrayEmitterNode")
		{
			ListSize = TargetObjectRegistry.BSPSysArrayEmitter_Registry.Size();
			ObjectRegistryClasses::BSPSysArrayEmitterNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "BSWindModifier" || NodeType == "BSWindModifierNode")
		{
			ListSize = TargetObjectRegistry.BSWindModifier_Registry.Size();
			ObjectRegistryClasses::BSWindModifierNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "hkPackedNiTriStripsData" || NodeType == "hkPackedNiTriStripsDataNode")
		{
			ListSize = TargetObjectRegistry.hkPackedNiTriStripsData_Registry.Size();
			ObjectRegistryClasses::hkPackedNiTriStripsDataNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiAlphaProperty" || NodeType == "NiAlphaPropertyNode")
		{
			ListSize = TargetObjectRegistry.NiAlphaProperty_Registry.Size();
			ObjectRegistryClasses::NiAlphaPropertyNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiAmbientLight" || NodeType == "NiAmbientLightNode")
		{
			ListSize = TargetObjectRegistry.NiAmbientLight_Registry.Size();
			ObjectRegistryClasses::NiAmbientLightNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiParticlesData" || NodeType == "NiParticlesDataNode")
		{
			ListSize = TargetObjectRegistry.NiParticlesData_Registry.Size();
			ObjectRegistryClasses::NiParticlesDataNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiRotatingParticlesData" || NodeType == "NiRotatingParticlesDataNode")
		{
			ListSize = TargetObjectRegistry.NiRotatingParticlesData_Registry.Size();
			ObjectRegistryClasses::NiRotatingParticlesDataNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiAutoNormalParticlesData" || NodeType == "NiAutoNormalParticlesDataNode")
		{
			ListSize = TargetObjectRegistry.NiAutoNormalParticlesData_Registry.Size();
			ObjectRegistryClasses::NiAutoNormalParticlesDataNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiPSysData" || NodeType == "NiPSysDataNode")
		{
			ListSize = TargetObjectRegistry.NiPSysData_Registry.Size();
			ObjectRegistryClasses::NiPSysDataNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiMeshPSysData" || NodeType == "NiMeshPSysDataNode")
		{
			ListSize = TargetObjectRegistry.NiMeshPSysData_Registry.Size();
			ObjectRegistryClasses::NiMeshPSysDataNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiBinaryExtraData" || NodeType == "NiBinaryExtraDataNode")
		{
			ListSize = TargetObjectRegistry.NiBinaryExtraData_Registry.Size();
			ObjectRegistryClasses::NiBinaryExtraDataNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiBinaryVoxelExtraData" || NodeType == "NiBinaryVoxelExtraDataNode")
		{
			ListSize = TargetObjectRegistry.NiBinaryVoxelExtraData_Registry.Size();
			ObjectRegistryClasses::NiBinaryVoxelExtraDataNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiBinaryVoxelData" || NodeType == "NiBinaryVoxelDataNode")
		{
			ListSize = TargetObjectRegistry.NiBinaryVoxelData_Registry.Size();
			ObjectRegistryClasses::NiBinaryVoxelDataNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiBlendBoolInterpolator" || NodeType == "NiBlendBoolInterpolatorNode")
		{
			ListSize = TargetObjectRegistry.NiBlendBoolInterpolator_Registry.Size();
			ObjectRegistryClasses::NiBlendBoolInterpolatorNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiBlendFloatInterpolator" || NodeType == "NiBlendFloatInterpolatorNode")
		{
			ListSize = TargetObjectRegistry.NiBlendFloatInterpolator_Registry.Size();
			ObjectRegistryClasses::NiBlendFloatInterpolatorNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiBlendPoint3Interpolator" || NodeType == "NiBlendPoint3InterpolatorNode")
		{
			ListSize = TargetObjectRegistry.NiBlendPoint3Interpolator_Registry.Size();
			ObjectRegistryClasses::NiBlendPoint3InterpolatorNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiBlendTransformInterpolator" || NodeType == "NiBlendTransformInterpolatorNode")
		{
			ListSize = TargetObjectRegistry.NiBlendTransformInterpolator_Registry.Size();
			ObjectRegistryClasses::NiBlendTransformInterpolatorNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiBoolData" || NodeType == "NiBoolDataNode")
		{
			ListSize = TargetObjectRegistry.NiBoolData_Registry.Size();
			ObjectRegistryClasses::NiBoolDataNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiBooleanExtraData" || NodeType == "NiBooleanExtraDataNode")
		{
			ListSize = TargetObjectRegistry.NiBooleanExtraData_Registry.Size();
			ObjectRegistryClasses::NiBooleanExtraDataNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiBSplineBasisData" || NodeType == "NiBSplineBasisDataNode")
		{
			ListSize = TargetObjectRegistry.NiBSplineBasisData_Registry.Size();
			ObjectRegistryClasses::NiBSplineBasisDataNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiBSplineFloatInterpolator" || NodeType == "NiBSplineFloatInterpolatorNode")
		{
			ListSize = TargetObjectRegistry.NiBSplineFloatInterpolator_Registry.Size();
			ObjectRegistryClasses::NiBSplineFloatInterpolatorNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiBSplineCompFloatInterpolator" || NodeType == "NiBSplineCompFloatInterpolatorNode")
		{
			ListSize = TargetObjectRegistry.NiBSplineCompFloatInterpolator_Registry.Size();
			ObjectRegistryClasses::NiBSplineCompFloatInterpolatorNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiBSplinePoint3Interpolator" || NodeType == "NiBSplinePoint3InterpolatorNode")
		{
			ListSize = TargetObjectRegistry.NiBSplinePoint3Interpolator_Registry.Size();
			ObjectRegistryClasses::NiBSplinePoint3InterpolatorNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiBSplineCompPoint3Interpolator" || NodeType == "NiBSplineCompPoint3InterpolatorNode")
		{
			ListSize = TargetObjectRegistry.NiBSplineCompPoint3Interpolator_Registry.Size();
			ObjectRegistryClasses::NiBSplineCompPoint3InterpolatorNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiBSplineTransformInterpolator" || NodeType == "NiBSplineTransformInterpolatorNode")
		{
			ListSize = TargetObjectRegistry.NiBSplineTransformInterpolator_Registry.Size();
			ObjectRegistryClasses::NiBSplineTransformInterpolatorNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiBSplineCompTransformInterpolator" || NodeType == "NiBSplineCompTransformInterpolatorNode")
		{
			ListSize = TargetObjectRegistry.NiBSplineCompTransformInterpolator_Registry.Size();
			ObjectRegistryClasses::NiBSplineCompTransformInterpolatorNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "BSRotAccumTransfInterpolator" || NodeType == "BSRotAccumTransfInterpolatorNode")
		{
			ListSize = TargetObjectRegistry.BSRotAccumTransfInterpolator_Registry.Size();
			ObjectRegistryClasses::BSRotAccumTransfInterpolatorNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiBSplineData" || NodeType == "NiBSplineDataNode")
		{
			ListSize = TargetObjectRegistry.NiBSplineData_Registry.Size();
			ObjectRegistryClasses::NiBSplineDataNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiCamera" || NodeType == "NiCameraNode")
		{
			ListSize = TargetObjectRegistry.NiCamera_Registry.Size();
			ObjectRegistryClasses::NiCameraNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiColorData" || NodeType == "NiColorDataNode")
		{
			ListSize = TargetObjectRegistry.NiColorData_Registry.Size();
			ObjectRegistryClasses::NiColorDataNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiColorExtraData" || NodeType == "NiColorExtraDataNode")
		{
			ListSize = TargetObjectRegistry.NiColorExtraData_Registry.Size();
			ObjectRegistryClasses::NiColorExtraDataNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiControllerManager" || NodeType == "NiControllerManagerNode")
		{
			ListSize = TargetObjectRegistry.NiControllerManager_Registry.Size();
			ObjectRegistryClasses::NiControllerManagerNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiSequence" || NodeType == "NiSequenceNode")
		{
			ListSize = TargetObjectRegistry.NiSequence_Registry.Size();
			ObjectRegistryClasses::NiSequenceNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiControllerSequence" || NodeType == "NiControllerSequenceNode")
		{
			ListSize = TargetObjectRegistry.NiControllerSequence_Registry.Size();
			ObjectRegistryClasses::NiControllerSequenceNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiAVObjectPalette" || NodeType == "NiAVObjectPaletteNode")
		{
			ListSize = TargetObjectRegistry.NiAVObjectPalette_Registry.Size();
			ObjectRegistryClasses::NiAVObjectPaletteNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiDefaultAVObjectPalette" || NodeType == "NiDefaultAVObjectPaletteNode")
		{
			ListSize = TargetObjectRegistry.NiDefaultAVObjectPalette_Registry.Size();
			ObjectRegistryClasses::NiDefaultAVObjectPaletteNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiDirectionalLight" || NodeType == "NiDirectionalLightNode")
		{
			ListSize = TargetObjectRegistry.NiDirectionalLight_Registry.Size();
			ObjectRegistryClasses::NiDirectionalLightNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiDitherProperty" || NodeType == "NiDitherPropertyNode")
		{
			ListSize = TargetObjectRegistry.NiDitherProperty_Registry.Size();
			ObjectRegistryClasses::NiDitherPropertyNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiRollController" || NodeType == "NiRollControllerNode")
		{
			ListSize = TargetObjectRegistry.NiRollController_Registry.Size();
			ObjectRegistryClasses::NiRollControllerNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiFloatData" || NodeType == "NiFloatDataNode")
		{
			ListSize = TargetObjectRegistry.NiFloatData_Registry.Size();
			ObjectRegistryClasses::NiFloatDataNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiFloatExtraData" || NodeType == "NiFloatExtraDataNode")
		{
			ListSize = TargetObjectRegistry.NiFloatExtraData_Registry.Size();
			ObjectRegistryClasses::NiFloatExtraDataNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiFloatsExtraData" || NodeType == "NiFloatsExtraDataNode")
		{
			ListSize = TargetObjectRegistry.NiFloatsExtraData_Registry.Size();
			ObjectRegistryClasses::NiFloatsExtraDataNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiFogProperty" || NodeType == "NiFogPropertyNode")
		{
			ListSize = TargetObjectRegistry.NiFogProperty_Registry.Size();
			ObjectRegistryClasses::NiFogPropertyNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiGravity" || NodeType == "NiGravityNode")
		{
			ListSize = TargetObjectRegistry.NiGravity_Registry.Size();
			ObjectRegistryClasses::NiGravityNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiIntegerExtraData" || NodeType == "NiIntegerExtraDataNode")
		{
			ListSize = TargetObjectRegistry.NiIntegerExtraData_Registry.Size();
			ObjectRegistryClasses::NiIntegerExtraDataNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "BSXFlags" || NodeType == "BSXFlagsNode")
		{
			ListSize = TargetObjectRegistry.BSXFlags_Registry.Size();
			ObjectRegistryClasses::BSXFlagsNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiIntegersExtraData" || NodeType == "NiIntegersExtraDataNode")
		{
			ListSize = TargetObjectRegistry.NiIntegersExtraData_Registry.Size();
			ObjectRegistryClasses::NiIntegersExtraDataNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "BSKeyframeController" || NodeType == "BSKeyframeControllerNode")
		{
			ListSize = TargetObjectRegistry.BSKeyframeController_Registry.Size();
			ObjectRegistryClasses::BSKeyframeControllerNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiKeyframeData" || NodeType == "NiKeyframeDataNode")
		{
			ListSize = TargetObjectRegistry.NiKeyframeData_Registry.Size();
			ObjectRegistryClasses::NiKeyframeDataNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiLookAtController" || NodeType == "NiLookAtControllerNode")
		{
			ListSize = TargetObjectRegistry.NiLookAtController_Registry.Size();
			ObjectRegistryClasses::NiLookAtControllerNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiLookAtInterpolator" || NodeType == "NiLookAtInterpolatorNode")
		{
			ListSize = TargetObjectRegistry.NiLookAtInterpolator_Registry.Size();
			ObjectRegistryClasses::NiLookAtInterpolatorNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiMaterialProperty" || NodeType == "NiMaterialPropertyNode")
		{
			ListSize = TargetObjectRegistry.NiMaterialProperty_Registry.Size();
			ObjectRegistryClasses::NiMaterialPropertyNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiMorphData" || NodeType == "NiMorphDataNode")
		{
			ListSize = TargetObjectRegistry.NiMorphData_Registry.Size();
			ObjectRegistryClasses::NiMorphDataNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiNode" || NodeType == "NiNodeNode")
		{
			ListSize = TargetObjectRegistry.NiNode_Registry.Size();
			ObjectRegistryClasses::NiNodeNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiBone" || NodeType == "NiBoneNode")
		{
			ListSize = TargetObjectRegistry.NiBone_Registry.Size();
			ObjectRegistryClasses::NiBoneNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "AvoidNode" || NodeType == "AvoidNodeNode")
		{
			ListSize = TargetObjectRegistry.AvoidNode_Registry.Size();
			ObjectRegistryClasses::AvoidNodeNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "FxWidget" || NodeType == "FxWidgetNode")
		{
			ListSize = TargetObjectRegistry.FxWidget_Registry.Size();
			ObjectRegistryClasses::FxWidgetNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "FxButton" || NodeType == "FxButtonNode")
		{
			ListSize = TargetObjectRegistry.FxButton_Registry.Size();
			ObjectRegistryClasses::FxButtonNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "FxRadioButton" || NodeType == "FxRadioButtonNode")
		{
			ListSize = TargetObjectRegistry.FxRadioButton_Registry.Size();
			ObjectRegistryClasses::FxRadioButtonNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiBillboardNode" || NodeType == "NiBillboardNodeNode")
		{
			ListSize = TargetObjectRegistry.NiBillboardNode_Registry.Size();
			ObjectRegistryClasses::NiBillboardNodeNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiBSAnimationNode" || NodeType == "NiBSAnimationNodeNode")
		{
			ListSize = TargetObjectRegistry.NiBSAnimationNode_Registry.Size();
			ObjectRegistryClasses::NiBSAnimationNodeNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiBSParticleNode" || NodeType == "NiBSParticleNodeNode")
		{
			ListSize = TargetObjectRegistry.NiBSParticleNode_Registry.Size();
			ObjectRegistryClasses::NiBSParticleNodeNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiSwitchNode" || NodeType == "NiSwitchNodeNode")
		{
			ListSize = TargetObjectRegistry.NiSwitchNode_Registry.Size();
			ObjectRegistryClasses::NiSwitchNodeNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiLODNode" || NodeType == "NiLODNodeNode")
		{
			ListSize = TargetObjectRegistry.NiLODNode_Registry.Size();
			ObjectRegistryClasses::NiLODNodeNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiPalette" || NodeType == "NiPaletteNode")
		{
			ListSize = TargetObjectRegistry.NiPalette_Registry.Size();
			ObjectRegistryClasses::NiPaletteNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiParticleBomb" || NodeType == "NiParticleBombNode")
		{
			ListSize = TargetObjectRegistry.NiParticleBomb_Registry.Size();
			ObjectRegistryClasses::NiParticleBombNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiParticleColorModifier" || NodeType == "NiParticleColorModifierNode")
		{
			ListSize = TargetObjectRegistry.NiParticleColorModifier_Registry.Size();
			ObjectRegistryClasses::NiParticleColorModifierNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiParticleGrowFade" || NodeType == "NiParticleGrowFadeNode")
		{
			ListSize = TargetObjectRegistry.NiParticleGrowFade_Registry.Size();
			ObjectRegistryClasses::NiParticleGrowFadeNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiParticleMeshModifier" || NodeType == "NiParticleMeshModifierNode")
		{
			ListSize = TargetObjectRegistry.NiParticleMeshModifier_Registry.Size();
			ObjectRegistryClasses::NiParticleMeshModifierNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiParticleRotation" || NodeType == "NiParticleRotationNode")
		{
			ListSize = TargetObjectRegistry.NiParticleRotation_Registry.Size();
			ObjectRegistryClasses::NiParticleRotationNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiParticles" || NodeType == "NiParticlesNode")
		{
			ListSize = TargetObjectRegistry.NiParticles_Registry.Size();
			ObjectRegistryClasses::NiParticlesNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiAutoNormalParticles" || NodeType == "NiAutoNormalParticlesNode")
		{
			ListSize = TargetObjectRegistry.NiAutoNormalParticles_Registry.Size();
			ObjectRegistryClasses::NiAutoNormalParticlesNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiParticleMeshes" || NodeType == "NiParticleMeshesNode")
		{
			ListSize = TargetObjectRegistry.NiParticleMeshes_Registry.Size();
			ObjectRegistryClasses::NiParticleMeshesNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiParticleMeshesData" || NodeType == "NiParticleMeshesDataNode")
		{
			ListSize = TargetObjectRegistry.NiParticleMeshesData_Registry.Size();
			ObjectRegistryClasses::NiParticleMeshesDataNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiParticleSystem" || NodeType == "NiParticleSystemNode")
		{
			ListSize = TargetObjectRegistry.NiParticleSystem_Registry.Size();
			ObjectRegistryClasses::NiParticleSystemNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiMeshParticleSystem" || NodeType == "NiMeshParticleSystemNode")
		{
			ListSize = TargetObjectRegistry.NiMeshParticleSystem_Registry.Size();
			ObjectRegistryClasses::NiMeshParticleSystemNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiParticleSystemController" || NodeType == "NiParticleSystemControllerNode")
		{
			ListSize = TargetObjectRegistry.NiParticleSystemController_Registry.Size();
			ObjectRegistryClasses::NiParticleSystemControllerNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiBSPArrayController" || NodeType == "NiBSPArrayControllerNode")
		{
			ListSize = TargetObjectRegistry.NiBSPArrayController_Registry.Size();
			ObjectRegistryClasses::NiBSPArrayControllerNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiPathController" || NodeType == "NiPathControllerNode")
		{
			ListSize = TargetObjectRegistry.NiPathController_Registry.Size();
			ObjectRegistryClasses::NiPathControllerNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "ATextureRenderData" || NodeType == "ATextureRenderDataNode")
		{
			ListSize = TargetObjectRegistry.ATextureRenderData_Registry.Size();
			ObjectRegistryClasses::ATextureRenderDataNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiPersistentSrcTextureRendererData" || NodeType == "NiPersistentSrcTextureRendererDataNode")
		{
			ListSize = TargetObjectRegistry.NiPersistentSrcTextureRendererData_Registry.Size();
			ObjectRegistryClasses::NiPersistentSrcTextureRendererDataNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiPixelData" || NodeType == "NiPixelDataNode")
		{
			ListSize = TargetObjectRegistry.NiPixelData_Registry.Size();
			ObjectRegistryClasses::NiPixelDataNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiPlanarCollider" || NodeType == "NiPlanarColliderNode")
		{
			ListSize = TargetObjectRegistry.NiPlanarCollider_Registry.Size();
			ObjectRegistryClasses::NiPlanarColliderNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiPointLight" || NodeType == "NiPointLightNode")
		{
			ListSize = TargetObjectRegistry.NiPointLight_Registry.Size();
			ObjectRegistryClasses::NiPointLightNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiPosData" || NodeType == "NiPosDataNode")
		{
			ListSize = TargetObjectRegistry.NiPosData_Registry.Size();
			ObjectRegistryClasses::NiPosDataNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiPSysAgeDeathModifier" || NodeType == "NiPSysAgeDeathModifierNode")
		{
			ListSize = TargetObjectRegistry.NiPSysAgeDeathModifier_Registry.Size();
			ObjectRegistryClasses::NiPSysAgeDeathModifierNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiPSysBombModifier" || NodeType == "NiPSysBombModifierNode")
		{
			ListSize = TargetObjectRegistry.NiPSysBombModifier_Registry.Size();
			ObjectRegistryClasses::NiPSysBombModifierNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiPSysBoundUpdateModifier" || NodeType == "NiPSysBoundUpdateModifierNode")
		{
			ListSize = TargetObjectRegistry.NiPSysBoundUpdateModifier_Registry.Size();
			ObjectRegistryClasses::NiPSysBoundUpdateModifierNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiPSysBoxEmitter" || NodeType == "NiPSysBoxEmitterNode")
		{
			ListSize = TargetObjectRegistry.NiPSysBoxEmitter_Registry.Size();
			ObjectRegistryClasses::NiPSysBoxEmitterNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiPSysColliderManager" || NodeType == "NiPSysColliderManagerNode")
		{
			ListSize = TargetObjectRegistry.NiPSysColliderManager_Registry.Size();
			ObjectRegistryClasses::NiPSysColliderManagerNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiPSysColorModifier" || NodeType == "NiPSysColorModifierNode")
		{
			ListSize = TargetObjectRegistry.NiPSysColorModifier_Registry.Size();
			ObjectRegistryClasses::NiPSysColorModifierNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiPSysCylinderEmitter" || NodeType == "NiPSysCylinderEmitterNode")
		{
			ListSize = TargetObjectRegistry.NiPSysCylinderEmitter_Registry.Size();
			ObjectRegistryClasses::NiPSysCylinderEmitterNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiPSysDragModifier" || NodeType == "NiPSysDragModifierNode")
		{
			ListSize = TargetObjectRegistry.NiPSysDragModifier_Registry.Size();
			ObjectRegistryClasses::NiPSysDragModifierNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiPSysEmitterCtlrData" || NodeType == "NiPSysEmitterCtlrDataNode")
		{
			ListSize = TargetObjectRegistry.NiPSysEmitterCtlrData_Registry.Size();
			ObjectRegistryClasses::NiPSysEmitterCtlrDataNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiPSysGravityModifier" || NodeType == "NiPSysGravityModifierNode")
		{
			ListSize = TargetObjectRegistry.NiPSysGravityModifier_Registry.Size();
			ObjectRegistryClasses::NiPSysGravityModifierNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiPSysGrowFadeModifier" || NodeType == "NiPSysGrowFadeModifierNode")
		{
			ListSize = TargetObjectRegistry.NiPSysGrowFadeModifier_Registry.Size();
			ObjectRegistryClasses::NiPSysGrowFadeModifierNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiPSysMeshEmitter" || NodeType == "NiPSysMeshEmitterNode")
		{
			ListSize = TargetObjectRegistry.NiPSysMeshEmitter_Registry.Size();
			ObjectRegistryClasses::NiPSysMeshEmitterNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiPSysMeshUpdateModifier" || NodeType == "NiPSysMeshUpdateModifierNode")
		{
			ListSize = TargetObjectRegistry.NiPSysMeshUpdateModifier_Registry.Size();
			ObjectRegistryClasses::NiPSysMeshUpdateModifierNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "BSPSysInheritVelocityModifier" || NodeType == "BSPSysInheritVelocityModifierNode")
		{
			ListSize = TargetObjectRegistry.BSPSysInheritVelocityModifier_Registry.Size();
			ObjectRegistryClasses::BSPSysInheritVelocityModifierNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "BSPSysHavokUpdateModifier" || NodeType == "BSPSysHavokUpdateModifierNode")
		{
			ListSize = TargetObjectRegistry.BSPSysHavokUpdateModifier_Registry.Size();
			ObjectRegistryClasses::BSPSysHavokUpdateModifierNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "BSPSysRecycleBoundModifier" || NodeType == "BSPSysRecycleBoundModifierNode")
		{
			ListSize = TargetObjectRegistry.BSPSysRecycleBoundModifier_Registry.Size();
			ObjectRegistryClasses::BSPSysRecycleBoundModifierNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "BSPSysSubTexModifier" || NodeType == "BSPSysSubTexModifierNode")
		{
			ListSize = TargetObjectRegistry.BSPSysSubTexModifier_Registry.Size();
			ObjectRegistryClasses::BSPSysSubTexModifierNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiPSysPlanarCollider" || NodeType == "NiPSysPlanarColliderNode")
		{
			ListSize = TargetObjectRegistry.NiPSysPlanarCollider_Registry.Size();
			ObjectRegistryClasses::NiPSysPlanarColliderNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiPSysSphericalCollider" || NodeType == "NiPSysSphericalColliderNode")
		{
			ListSize = TargetObjectRegistry.NiPSysSphericalCollider_Registry.Size();
			ObjectRegistryClasses::NiPSysSphericalColliderNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiPSysPositionModifier" || NodeType == "NiPSysPositionModifierNode")
		{
			ListSize = TargetObjectRegistry.NiPSysPositionModifier_Registry.Size();
			ObjectRegistryClasses::NiPSysPositionModifierNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiPSysResetOnLoopCtlr" || NodeType == "NiPSysResetOnLoopCtlrNode")
		{
			ListSize = TargetObjectRegistry.NiPSysResetOnLoopCtlr_Registry.Size();
			ObjectRegistryClasses::NiPSysResetOnLoopCtlrNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiPSysRotationModifier" || NodeType == "NiPSysRotationModifierNode")
		{
			ListSize = TargetObjectRegistry.NiPSysRotationModifier_Registry.Size();
			ObjectRegistryClasses::NiPSysRotationModifierNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiPSysSpawnModifier" || NodeType == "NiPSysSpawnModifierNode")
		{
			ListSize = TargetObjectRegistry.NiPSysSpawnModifier_Registry.Size();
			ObjectRegistryClasses::NiPSysSpawnModifierNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiPSysSphereEmitter" || NodeType == "NiPSysSphereEmitterNode")
		{
			ListSize = TargetObjectRegistry.NiPSysSphereEmitter_Registry.Size();
			ObjectRegistryClasses::NiPSysSphereEmitterNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiPSysUpdateCtlr" || NodeType == "NiPSysUpdateCtlrNode")
		{
			ListSize = TargetObjectRegistry.NiPSysUpdateCtlr_Registry.Size();
			ObjectRegistryClasses::NiPSysUpdateCtlrNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiPSysFieldModifier" || NodeType == "NiPSysFieldModifierNode")
		{
			ListSize = TargetObjectRegistry.NiPSysFieldModifier_Registry.Size();
			ObjectRegistryClasses::NiPSysFieldModifierNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiPSysVortexFieldModifier" || NodeType == "NiPSysVortexFieldModifierNode")
		{
			ListSize = TargetObjectRegistry.NiPSysVortexFieldModifier_Registry.Size();
			ObjectRegistryClasses::NiPSysVortexFieldModifierNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiPSysGravityFieldModifier" || NodeType == "NiPSysGravityFieldModifierNode")
		{
			ListSize = TargetObjectRegistry.NiPSysGravityFieldModifier_Registry.Size();
			ObjectRegistryClasses::NiPSysGravityFieldModifierNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiPSysDragFieldModifier" || NodeType == "NiPSysDragFieldModifierNode")
		{
			ListSize = TargetObjectRegistry.NiPSysDragFieldModifier_Registry.Size();
			ObjectRegistryClasses::NiPSysDragFieldModifierNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiPSysTurbulenceFieldModifier" || NodeType == "NiPSysTurbulenceFieldModifierNode")
		{
			ListSize = TargetObjectRegistry.NiPSysTurbulenceFieldModifier_Registry.Size();
			ObjectRegistryClasses::NiPSysTurbulenceFieldModifierNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "BSPSysLODModifier" || NodeType == "BSPSysLODModifierNode")
		{
			ListSize = TargetObjectRegistry.BSPSysLODModifier_Registry.Size();
			ObjectRegistryClasses::BSPSysLODModifierNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "BSPSysScaleModifier" || NodeType == "BSPSysScaleModifierNode")
		{
			ListSize = TargetObjectRegistry.BSPSysScaleModifier_Registry.Size();
			ObjectRegistryClasses::BSPSysScaleModifierNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiPSysFieldMagnitudeCtlr" || NodeType == "NiPSysFieldMagnitudeCtlrNode")
		{
			ListSize = TargetObjectRegistry.NiPSysFieldMagnitudeCtlr_Registry.Size();
			ObjectRegistryClasses::NiPSysFieldMagnitudeCtlrNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiPSysFieldAttenuationCtlr" || NodeType == "NiPSysFieldAttenuationCtlrNode")
		{
			ListSize = TargetObjectRegistry.NiPSysFieldAttenuationCtlr_Registry.Size();
			ObjectRegistryClasses::NiPSysFieldAttenuationCtlrNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiPSysFieldMaxDistanceCtlr" || NodeType == "NiPSysFieldMaxDistanceCtlrNode")
		{
			ListSize = TargetObjectRegistry.NiPSysFieldMaxDistanceCtlr_Registry.Size();
			ObjectRegistryClasses::NiPSysFieldMaxDistanceCtlrNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiPSysAirFieldAirFrictionCtlr" || NodeType == "NiPSysAirFieldAirFrictionCtlrNode")
		{
			ListSize = TargetObjectRegistry.NiPSysAirFieldAirFrictionCtlr_Registry.Size();
			ObjectRegistryClasses::NiPSysAirFieldAirFrictionCtlrNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiPSysAirFieldInheritVelocityCtlr" || NodeType == "NiPSysAirFieldInheritVelocityCtlrNode")
		{
			ListSize = TargetObjectRegistry.NiPSysAirFieldInheritVelocityCtlr_Registry.Size();
			ObjectRegistryClasses::NiPSysAirFieldInheritVelocityCtlrNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiPSysAirFieldSpreadCtlr" || NodeType == "NiPSysAirFieldSpreadCtlrNode")
		{
			ListSize = TargetObjectRegistry.NiPSysAirFieldSpreadCtlr_Registry.Size();
			ObjectRegistryClasses::NiPSysAirFieldSpreadCtlrNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiPSysInitialRotSpeedCtlr" || NodeType == "NiPSysInitialRotSpeedCtlrNode")
		{
			ListSize = TargetObjectRegistry.NiPSysInitialRotSpeedCtlr_Registry.Size();
			ObjectRegistryClasses::NiPSysInitialRotSpeedCtlrNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiPSysInitialRotSpeedVarCtlr" || NodeType == "NiPSysInitialRotSpeedVarCtlrNode")
		{
			ListSize = TargetObjectRegistry.NiPSysInitialRotSpeedVarCtlr_Registry.Size();
			ObjectRegistryClasses::NiPSysInitialRotSpeedVarCtlrNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiPSysInitialRotAngleCtlr" || NodeType == "NiPSysInitialRotAngleCtlrNode")
		{
			ListSize = TargetObjectRegistry.NiPSysInitialRotAngleCtlr_Registry.Size();
			ObjectRegistryClasses::NiPSysInitialRotAngleCtlrNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiPSysInitialRotAngleVarCtlr" || NodeType == "NiPSysInitialRotAngleVarCtlrNode")
		{
			ListSize = TargetObjectRegistry.NiPSysInitialRotAngleVarCtlr_Registry.Size();
			ObjectRegistryClasses::NiPSysInitialRotAngleVarCtlrNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiPSysEmitterPlanarAngleCtlr" || NodeType == "NiPSysEmitterPlanarAngleCtlrNode")
		{
			ListSize = TargetObjectRegistry.NiPSysEmitterPlanarAngleCtlr_Registry.Size();
			ObjectRegistryClasses::NiPSysEmitterPlanarAngleCtlrNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiPSysEmitterPlanarAngleVarCtlr" || NodeType == "NiPSysEmitterPlanarAngleVarCtlrNode")
		{
			ListSize = TargetObjectRegistry.NiPSysEmitterPlanarAngleVarCtlr_Registry.Size();
			ObjectRegistryClasses::NiPSysEmitterPlanarAngleVarCtlrNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiPSysAirFieldModifier" || NodeType == "NiPSysAirFieldModifierNode")
		{
			ListSize = TargetObjectRegistry.NiPSysAirFieldModifier_Registry.Size();
			ObjectRegistryClasses::NiPSysAirFieldModifierNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiPSysTrailEmitter" || NodeType == "NiPSysTrailEmitterNode")
		{
			ListSize = TargetObjectRegistry.NiPSysTrailEmitter_Registry.Size();
			ObjectRegistryClasses::NiPSysTrailEmitterNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiLightIntensityController" || NodeType == "NiLightIntensityControllerNode")
		{
			ListSize = TargetObjectRegistry.NiLightIntensityController_Registry.Size();
			ObjectRegistryClasses::NiLightIntensityControllerNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiPSysRadialFieldModifier" || NodeType == "NiPSysRadialFieldModifierNode")
		{
			ListSize = TargetObjectRegistry.NiPSysRadialFieldModifier_Registry.Size();
			ObjectRegistryClasses::NiPSysRadialFieldModifierNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiLODData" || NodeType == "NiLODDataNode")
		{
			ListSize = TargetObjectRegistry.NiLODData_Registry.Size();
			ObjectRegistryClasses::NiLODDataNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiRangeLODData" || NodeType == "NiRangeLODDataNode")
		{
			ListSize = TargetObjectRegistry.NiRangeLODData_Registry.Size();
			ObjectRegistryClasses::NiRangeLODDataNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiScreenLODData" || NodeType == "NiScreenLODDataNode")
		{
			ListSize = TargetObjectRegistry.NiScreenLODData_Registry.Size();
			ObjectRegistryClasses::NiScreenLODDataNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiRotatingParticles" || NodeType == "NiRotatingParticlesNode")
		{
			ListSize = TargetObjectRegistry.NiRotatingParticles_Registry.Size();
			ObjectRegistryClasses::NiRotatingParticlesNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiSequenceStreamHelper" || NodeType == "NiSequenceStreamHelperNode")
		{
			ListSize = TargetObjectRegistry.NiSequenceStreamHelper_Registry.Size();
			ObjectRegistryClasses::NiSequenceStreamHelperNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiShadeProperty" || NodeType == "NiShadePropertyNode")
		{
			ListSize = TargetObjectRegistry.NiShadeProperty_Registry.Size();
			ObjectRegistryClasses::NiShadePropertyNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiSkinData" || NodeType == "NiSkinDataNode")
		{
			ListSize = TargetObjectRegistry.NiSkinData_Registry.Size();
			ObjectRegistryClasses::NiSkinDataNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiSkinInstance" || NodeType == "NiSkinInstanceNode")
		{
			ListSize = TargetObjectRegistry.NiSkinInstance_Registry.Size();
			ObjectRegistryClasses::NiSkinInstanceNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiTriShapeSkinController" || NodeType == "NiTriShapeSkinControllerNode")
		{
			ListSize = TargetObjectRegistry.NiTriShapeSkinController_Registry.Size();
			ObjectRegistryClasses::NiTriShapeSkinControllerNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiClodSkinInstance" || NodeType == "NiClodSkinInstanceNode")
		{
			ListSize = TargetObjectRegistry.NiClodSkinInstance_Registry.Size();
			ObjectRegistryClasses::NiClodSkinInstanceNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiSkinPartition" || NodeType == "NiSkinPartitionNode")
		{
			ListSize = TargetObjectRegistry.NiSkinPartition_Registry.Size();
			ObjectRegistryClasses::NiSkinPartitionNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiTexture" || NodeType == "NiTextureNode")
		{
			ListSize = TargetObjectRegistry.NiTexture_Registry.Size();
			ObjectRegistryClasses::NiTextureNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiSourceTexture" || NodeType == "NiSourceTextureNode")
		{
			ListSize = TargetObjectRegistry.NiSourceTexture_Registry.Size();
			ObjectRegistryClasses::NiSourceTextureNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiSpecularProperty" || NodeType == "NiSpecularPropertyNode")
		{
			ListSize = TargetObjectRegistry.NiSpecularProperty_Registry.Size();
			ObjectRegistryClasses::NiSpecularPropertyNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiSphericalCollider" || NodeType == "NiSphericalColliderNode")
		{
			ListSize = TargetObjectRegistry.NiSphericalCollider_Registry.Size();
			ObjectRegistryClasses::NiSphericalColliderNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiSpotLight" || NodeType == "NiSpotLightNode")
		{
			ListSize = TargetObjectRegistry.NiSpotLight_Registry.Size();
			ObjectRegistryClasses::NiSpotLightNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiStencilProperty" || NodeType == "NiStencilPropertyNode")
		{
			ListSize = TargetObjectRegistry.NiStencilProperty_Registry.Size();
			ObjectRegistryClasses::NiStencilPropertyNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiStringExtraData" || NodeType == "NiStringExtraDataNode")
		{
			ListSize = TargetObjectRegistry.NiStringExtraData_Registry.Size();
			ObjectRegistryClasses::NiStringExtraDataNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiStringPalette" || NodeType == "NiStringPaletteNode")
		{
			ListSize = TargetObjectRegistry.NiStringPalette_Registry.Size();
			ObjectRegistryClasses::NiStringPaletteNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiStringsExtraData" || NodeType == "NiStringsExtraDataNode")
		{
			ListSize = TargetObjectRegistry.NiStringsExtraData_Registry.Size();
			ObjectRegistryClasses::NiStringsExtraDataNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiTextKeyExtraData" || NodeType == "NiTextKeyExtraDataNode")
		{
			ListSize = TargetObjectRegistry.NiTextKeyExtraData_Registry.Size();
			ObjectRegistryClasses::NiTextKeyExtraDataNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiTextureEffect" || NodeType == "NiTextureEffectNode")
		{
			ListSize = TargetObjectRegistry.NiTextureEffect_Registry.Size();
			ObjectRegistryClasses::NiTextureEffectNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiTextureModeProperty" || NodeType == "NiTextureModePropertyNode")
		{
			ListSize = TargetObjectRegistry.NiTextureModeProperty_Registry.Size();
			ObjectRegistryClasses::NiTextureModePropertyNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiImage" || NodeType == "NiImageNode")
		{
			ListSize = TargetObjectRegistry.NiImage_Registry.Size();
			ObjectRegistryClasses::NiImageNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiTextureProperty" || NodeType == "NiTexturePropertyNode")
		{
			ListSize = TargetObjectRegistry.NiTextureProperty_Registry.Size();
			ObjectRegistryClasses::NiTexturePropertyNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiMultiTextureProperty" || NodeType == "NiMultiTexturePropertyNode")
		{
			ListSize = TargetObjectRegistry.NiMultiTextureProperty_Registry.Size();
			ObjectRegistryClasses::NiMultiTexturePropertyNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiTexturingProperty" || NodeType == "NiTexturingPropertyNode")
		{
			ListSize = TargetObjectRegistry.NiTexturingProperty_Registry.Size();
			ObjectRegistryClasses::NiTexturingPropertyNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiTransformData" || NodeType == "NiTransformDataNode")
		{
			ListSize = TargetObjectRegistry.NiTransformData_Registry.Size();
			ObjectRegistryClasses::NiTransformDataNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiTriShape" || NodeType == "NiTriShapeNode")
		{
			ListSize = TargetObjectRegistry.NiTriShape_Registry.Size();
			ObjectRegistryClasses::NiTriShapeNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiTriShapeData" || NodeType == "NiTriShapeDataNode")
		{
			ListSize = TargetObjectRegistry.NiTriShapeData_Registry.Size();
			ObjectRegistryClasses::NiTriShapeDataNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiTriStrips" || NodeType == "NiTriStripsNode")
		{
			ListSize = TargetObjectRegistry.NiTriStrips_Registry.Size();
			ObjectRegistryClasses::NiTriStripsNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiTriStripsData" || NodeType == "NiTriStripsDataNode")
		{
			ListSize = TargetObjectRegistry.NiTriStripsData_Registry.Size();
			ObjectRegistryClasses::NiTriStripsDataNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiEnvMappedTriShape" || NodeType == "NiEnvMappedTriShapeNode")
		{
			ListSize = TargetObjectRegistry.NiEnvMappedTriShape_Registry.Size();
			ObjectRegistryClasses::NiEnvMappedTriShapeNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiEnvMappedTriShapeData" || NodeType == "NiEnvMappedTriShapeDataNode")
		{
			ListSize = TargetObjectRegistry.NiEnvMappedTriShapeData_Registry.Size();
			ObjectRegistryClasses::NiEnvMappedTriShapeDataNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiBezierTriangle4" || NodeType == "NiBezierTriangle4Node")
		{
			ListSize = TargetObjectRegistry.NiBezierTriangle4_Registry.Size();
			ObjectRegistryClasses::NiBezierTriangle4Node* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiBezierMesh" || NodeType == "NiBezierMeshNode")
		{
			ListSize = TargetObjectRegistry.NiBezierMesh_Registry.Size();
			ObjectRegistryClasses::NiBezierMeshNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiClod" || NodeType == "NiClodNode")
		{
			ListSize = TargetObjectRegistry.NiClod_Registry.Size();
			ObjectRegistryClasses::NiClodNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiClodData" || NodeType == "NiClodDataNode")
		{
			ListSize = TargetObjectRegistry.NiClodData_Registry.Size();
			ObjectRegistryClasses::NiClodDataNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiUVController" || NodeType == "NiUVControllerNode")
		{
			ListSize = TargetObjectRegistry.NiUVController_Registry.Size();
			ObjectRegistryClasses::NiUVControllerNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiUVData" || NodeType == "NiUVDataNode")
		{
			ListSize = TargetObjectRegistry.NiUVData_Registry.Size();
			ObjectRegistryClasses::NiUVDataNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiVectorExtraData" || NodeType == "NiVectorExtraDataNode")
		{
			ListSize = TargetObjectRegistry.NiVectorExtraData_Registry.Size();
			ObjectRegistryClasses::NiVectorExtraDataNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiVertexColorProperty" || NodeType == "NiVertexColorPropertyNode")
		{
			ListSize = TargetObjectRegistry.NiVertexColorProperty_Registry.Size();
			ObjectRegistryClasses::NiVertexColorPropertyNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiVertWeightsExtraData" || NodeType == "NiVertWeightsExtraDataNode")
		{
			ListSize = TargetObjectRegistry.NiVertWeightsExtraData_Registry.Size();
			ObjectRegistryClasses::NiVertWeightsExtraDataNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiVisData" || NodeType == "NiVisDataNode")
		{
			ListSize = TargetObjectRegistry.NiVisData_Registry.Size();
			ObjectRegistryClasses::NiVisDataNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiWireframeProperty" || NodeType == "NiWireframePropertyNode")
		{
			ListSize = TargetObjectRegistry.NiWireframeProperty_Registry.Size();
			ObjectRegistryClasses::NiWireframePropertyNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiZBufferProperty" || NodeType == "NiZBufferPropertyNode")
		{
			ListSize = TargetObjectRegistry.NiZBufferProperty_Registry.Size();
			ObjectRegistryClasses::NiZBufferPropertyNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "RootCollisionNode" || NodeType == "RootCollisionNodeNode")
		{
			ListSize = TargetObjectRegistry.RootCollisionNode_Registry.Size();
			ObjectRegistryClasses::RootCollisionNodeNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiRawImageData" || NodeType == "NiRawImageDataNode")
		{
			ListSize = TargetObjectRegistry.NiRawImageData_Registry.Size();
			ObjectRegistryClasses::NiRawImageDataNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiSortAdjustNode" || NodeType == "NiSortAdjustNodeNode")
		{
			ListSize = TargetObjectRegistry.NiSortAdjustNode_Registry.Size();
			ObjectRegistryClasses::NiSortAdjustNodeNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiSourceCubeMap" || NodeType == "NiSourceCubeMapNode")
		{
			ListSize = TargetObjectRegistry.NiSourceCubeMap_Registry.Size();
			ObjectRegistryClasses::NiSourceCubeMapNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiPhysXProp" || NodeType == "NiPhysXPropNode")
		{
			ListSize = TargetObjectRegistry.NiPhysXProp_Registry.Size();
			ObjectRegistryClasses::NiPhysXPropNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiPhysXPropDesc" || NodeType == "NiPhysXPropDescNode")
		{
			ListSize = TargetObjectRegistry.NiPhysXPropDesc_Registry.Size();
			ObjectRegistryClasses::NiPhysXPropDescNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiPhysXActorDesc" || NodeType == "NiPhysXActorDescNode")
		{
			ListSize = TargetObjectRegistry.NiPhysXActorDesc_Registry.Size();
			ObjectRegistryClasses::NiPhysXActorDescNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiPhysXBodyDesc" || NodeType == "NiPhysXBodyDescNode")
		{
			ListSize = TargetObjectRegistry.NiPhysXBodyDesc_Registry.Size();
			ObjectRegistryClasses::NiPhysXBodyDescNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiPhysXD6JointDesc" || NodeType == "NiPhysXD6JointDescNode")
		{
			ListSize = TargetObjectRegistry.NiPhysXD6JointDesc_Registry.Size();
			ObjectRegistryClasses::NiPhysXD6JointDescNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiPhysXShapeDesc" || NodeType == "NiPhysXShapeDescNode")
		{
			ListSize = TargetObjectRegistry.NiPhysXShapeDesc_Registry.Size();
			ObjectRegistryClasses::NiPhysXShapeDescNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiPhysXMeshDesc" || NodeType == "NiPhysXMeshDescNode")
		{
			ListSize = TargetObjectRegistry.NiPhysXMeshDesc_Registry.Size();
			ObjectRegistryClasses::NiPhysXMeshDescNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiPhysXMaterialDesc" || NodeType == "NiPhysXMaterialDescNode")
		{
			ListSize = TargetObjectRegistry.NiPhysXMaterialDesc_Registry.Size();
			ObjectRegistryClasses::NiPhysXMaterialDescNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiPhysXKinematicSrc" || NodeType == "NiPhysXKinematicSrcNode")
		{
			ListSize = TargetObjectRegistry.NiPhysXKinematicSrc_Registry.Size();
			ObjectRegistryClasses::NiPhysXKinematicSrcNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiPhysXTransformDest" || NodeType == "NiPhysXTransformDestNode")
		{
			ListSize = TargetObjectRegistry.NiPhysXTransformDest_Registry.Size();
			ObjectRegistryClasses::NiPhysXTransformDestNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiArkAnimationExtraData" || NodeType == "NiArkAnimationExtraDataNode")
		{
			ListSize = TargetObjectRegistry.NiArkAnimationExtraData_Registry.Size();
			ObjectRegistryClasses::NiArkAnimationExtraDataNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiArkImporterExtraData" || NodeType == "NiArkImporterExtraDataNode")
		{
			ListSize = TargetObjectRegistry.NiArkImporterExtraData_Registry.Size();
			ObjectRegistryClasses::NiArkImporterExtraDataNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiArkTextureExtraData" || NodeType == "NiArkTextureExtraDataNode")
		{
			ListSize = TargetObjectRegistry.NiArkTextureExtraData_Registry.Size();
			ObjectRegistryClasses::NiArkTextureExtraDataNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiArkViewportInfoExtraData" || NodeType == "NiArkViewportInfoExtraDataNode")
		{
			ListSize = TargetObjectRegistry.NiArkViewportInfoExtraData_Registry.Size();
			ObjectRegistryClasses::NiArkViewportInfoExtraDataNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiArkShaderExtraData" || NodeType == "NiArkShaderExtraDataNode")
		{
			ListSize = TargetObjectRegistry.NiArkShaderExtraData_Registry.Size();
			ObjectRegistryClasses::NiArkShaderExtraDataNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiLines" || NodeType == "NiLinesNode")
		{
			ListSize = TargetObjectRegistry.NiLines_Registry.Size();
			ObjectRegistryClasses::NiLinesNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiLinesData" || NodeType == "NiLinesDataNode")
		{
			ListSize = TargetObjectRegistry.NiLinesData_Registry.Size();
			ObjectRegistryClasses::NiLinesDataNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiScreenElementsData" || NodeType == "NiScreenElementsDataNode")
		{
			ListSize = TargetObjectRegistry.NiScreenElementsData_Registry.Size();
			ObjectRegistryClasses::NiScreenElementsDataNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiScreenElements" || NodeType == "NiScreenElementsNode")
		{
			ListSize = TargetObjectRegistry.NiScreenElements_Registry.Size();
			ObjectRegistryClasses::NiScreenElementsNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiRoomGroup" || NodeType == "NiRoomGroupNode")
		{
			ListSize = TargetObjectRegistry.NiRoomGroup_Registry.Size();
			ObjectRegistryClasses::NiRoomGroupNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiRoom" || NodeType == "NiRoomNode")
		{
			ListSize = TargetObjectRegistry.NiRoom_Registry.Size();
			ObjectRegistryClasses::NiRoomNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiPortal" || NodeType == "NiPortalNode")
		{
			ListSize = TargetObjectRegistry.NiPortal_Registry.Size();
			ObjectRegistryClasses::NiPortalNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "BSFadeNode" || NodeType == "BSFadeNodeNode")
		{
			ListSize = TargetObjectRegistry.BSFadeNode_Registry.Size();
			ObjectRegistryClasses::BSFadeNodeNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "BSShaderProperty" || NodeType == "BSShaderPropertyNode")
		{
			ListSize = TargetObjectRegistry.BSShaderProperty_Registry.Size();
			ObjectRegistryClasses::BSShaderPropertyNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "BSShaderLightingProperty" || NodeType == "BSShaderLightingPropertyNode")
		{
			ListSize = TargetObjectRegistry.BSShaderLightingProperty_Registry.Size();
			ObjectRegistryClasses::BSShaderLightingPropertyNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "BSShaderNoLightingProperty" || NodeType == "BSShaderNoLightingPropertyNode")
		{
			ListSize = TargetObjectRegistry.BSShaderNoLightingProperty_Registry.Size();
			ObjectRegistryClasses::BSShaderNoLightingPropertyNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "BSShaderPPLightingProperty" || NodeType == "BSShaderPPLightingPropertyNode")
		{
			ListSize = TargetObjectRegistry.BSShaderPPLightingProperty_Registry.Size();
			ObjectRegistryClasses::BSShaderPPLightingPropertyNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "BSEffectShaderPropertyFloatController" || NodeType == "BSEffectShaderPropertyFloatControllerNode")
		{
			ListSize = TargetObjectRegistry.BSEffectShaderPropertyFloatController_Registry.Size();
			ObjectRegistryClasses::BSEffectShaderPropertyFloatControllerNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "BSEffectShaderPropertyColorController" || NodeType == "BSEffectShaderPropertyColorControllerNode")
		{
			ListSize = TargetObjectRegistry.BSEffectShaderPropertyColorController_Registry.Size();
			ObjectRegistryClasses::BSEffectShaderPropertyColorControllerNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "BSLightingShaderPropertyFloatController" || NodeType == "BSLightingShaderPropertyFloatControllerNode")
		{
			ListSize = TargetObjectRegistry.BSLightingShaderPropertyFloatController_Registry.Size();
			ObjectRegistryClasses::BSLightingShaderPropertyFloatControllerNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "BSLightingShaderPropertyColorController" || NodeType == "BSLightingShaderPropertyColorControllerNode")
		{
			ListSize = TargetObjectRegistry.BSLightingShaderPropertyColorController_Registry.Size();
			ObjectRegistryClasses::BSLightingShaderPropertyColorControllerNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "BSNiAlphaPropertyTestRefController" || NodeType == "BSNiAlphaPropertyTestRefControllerNode")
		{
			ListSize = TargetObjectRegistry.BSNiAlphaPropertyTestRefController_Registry.Size();
			ObjectRegistryClasses::BSNiAlphaPropertyTestRefControllerNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "BSProceduralLightningController" || NodeType == "BSProceduralLightningControllerNode")
		{
			ListSize = TargetObjectRegistry.BSProceduralLightningController_Registry.Size();
			ObjectRegistryClasses::BSProceduralLightningControllerNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "BSShaderTextureSet" || NodeType == "BSShaderTextureSetNode")
		{
			ListSize = TargetObjectRegistry.BSShaderTextureSet_Registry.Size();
			ObjectRegistryClasses::BSShaderTextureSetNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "WaterShaderProperty" || NodeType == "WaterShaderPropertyNode")
		{
			ListSize = TargetObjectRegistry.WaterShaderProperty_Registry.Size();
			ObjectRegistryClasses::WaterShaderPropertyNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "SkyShaderProperty" || NodeType == "SkyShaderPropertyNode")
		{
			ListSize = TargetObjectRegistry.SkyShaderProperty_Registry.Size();
			ObjectRegistryClasses::SkyShaderPropertyNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "TileShaderProperty" || NodeType == "TileShaderPropertyNode")
		{
			ListSize = TargetObjectRegistry.TileShaderProperty_Registry.Size();
			ObjectRegistryClasses::TileShaderPropertyNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "DistantLODShaderProperty" || NodeType == "DistantLODShaderPropertyNode")
		{
			ListSize = TargetObjectRegistry.DistantLODShaderProperty_Registry.Size();
			ObjectRegistryClasses::DistantLODShaderPropertyNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "BSDistantTreeShaderProperty" || NodeType == "BSDistantTreeShaderPropertyNode")
		{
			ListSize = TargetObjectRegistry.BSDistantTreeShaderProperty_Registry.Size();
			ObjectRegistryClasses::BSDistantTreeShaderPropertyNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "TallGrassShaderProperty" || NodeType == "TallGrassShaderPropertyNode")
		{
			ListSize = TargetObjectRegistry.TallGrassShaderProperty_Registry.Size();
			ObjectRegistryClasses::TallGrassShaderPropertyNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "VolumetricFogShaderProperty" || NodeType == "VolumetricFogShaderPropertyNode")
		{
			ListSize = TargetObjectRegistry.VolumetricFogShaderProperty_Registry.Size();
			ObjectRegistryClasses::VolumetricFogShaderPropertyNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "HairShaderProperty" || NodeType == "HairShaderPropertyNode")
		{
			ListSize = TargetObjectRegistry.HairShaderProperty_Registry.Size();
			ObjectRegistryClasses::HairShaderPropertyNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "Lighting30ShaderProperty" || NodeType == "Lighting30ShaderPropertyNode")
		{
			ListSize = TargetObjectRegistry.Lighting30ShaderProperty_Registry.Size();
			ObjectRegistryClasses::Lighting30ShaderPropertyNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "BSLightingShaderProperty" || NodeType == "BSLightingShaderPropertyNode")
		{
			ListSize = TargetObjectRegistry.BSLightingShaderProperty_Registry.Size();
			ObjectRegistryClasses::BSLightingShaderPropertyNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "BSEffectShaderProperty" || NodeType == "BSEffectShaderPropertyNode")
		{
			ListSize = TargetObjectRegistry.BSEffectShaderProperty_Registry.Size();
			ObjectRegistryClasses::BSEffectShaderPropertyNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "BSWaterShaderProperty" || NodeType == "BSWaterShaderPropertyNode")
		{
			ListSize = TargetObjectRegistry.BSWaterShaderProperty_Registry.Size();
			ObjectRegistryClasses::BSWaterShaderPropertyNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "BSSkyShaderProperty" || NodeType == "BSSkyShaderPropertyNode")
		{
			ListSize = TargetObjectRegistry.BSSkyShaderProperty_Registry.Size();
			ObjectRegistryClasses::BSSkyShaderPropertyNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "BSDismemberSkinInstance" || NodeType == "BSDismemberSkinInstanceNode")
		{
			ListSize = TargetObjectRegistry.BSDismemberSkinInstance_Registry.Size();
			ObjectRegistryClasses::BSDismemberSkinInstanceNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "BSDecalPlacementVectorExtraData" || NodeType == "BSDecalPlacementVectorExtraDataNode")
		{
			ListSize = TargetObjectRegistry.BSDecalPlacementVectorExtraData_Registry.Size();
			ObjectRegistryClasses::BSDecalPlacementVectorExtraDataNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "BSPSysSimpleColorModifier" || NodeType == "BSPSysSimpleColorModifierNode")
		{
			ListSize = TargetObjectRegistry.BSPSysSimpleColorModifier_Registry.Size();
			ObjectRegistryClasses::BSPSysSimpleColorModifierNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "BSValueNode" || NodeType == "BSValueNodeNode")
		{
			ListSize = TargetObjectRegistry.BSValueNode_Registry.Size();
			ObjectRegistryClasses::BSValueNodeNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "BSStripParticleSystem" || NodeType == "BSStripParticleSystemNode")
		{
			ListSize = TargetObjectRegistry.BSStripParticleSystem_Registry.Size();
			ObjectRegistryClasses::BSStripParticleSystemNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "BSStripPSysData" || NodeType == "BSStripPSysDataNode")
		{
			ListSize = TargetObjectRegistry.BSStripPSysData_Registry.Size();
			ObjectRegistryClasses::BSStripPSysDataNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "BSPSysStripUpdateModifier" || NodeType == "BSPSysStripUpdateModifierNode")
		{
			ListSize = TargetObjectRegistry.BSPSysStripUpdateModifier_Registry.Size();
			ObjectRegistryClasses::BSPSysStripUpdateModifierNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "BSMaterialEmittanceMultController" || NodeType == "BSMaterialEmittanceMultControllerNode")
		{
			ListSize = TargetObjectRegistry.BSMaterialEmittanceMultController_Registry.Size();
			ObjectRegistryClasses::BSMaterialEmittanceMultControllerNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "BSMasterParticleSystem" || NodeType == "BSMasterParticleSystemNode")
		{
			ListSize = TargetObjectRegistry.BSMasterParticleSystem_Registry.Size();
			ObjectRegistryClasses::BSMasterParticleSystemNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "BSPSysMultiTargetEmitterCtlr" || NodeType == "BSPSysMultiTargetEmitterCtlrNode")
		{
			ListSize = TargetObjectRegistry.BSPSysMultiTargetEmitterCtlr_Registry.Size();
			ObjectRegistryClasses::BSPSysMultiTargetEmitterCtlrNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "BSRefractionStrengthController" || NodeType == "BSRefractionStrengthControllerNode")
		{
			ListSize = TargetObjectRegistry.BSRefractionStrengthController_Registry.Size();
			ObjectRegistryClasses::BSRefractionStrengthControllerNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "BSOrderedNode" || NodeType == "BSOrderedNodeNode")
		{
			ListSize = TargetObjectRegistry.BSOrderedNode_Registry.Size();
			ObjectRegistryClasses::BSOrderedNodeNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "BSBlastNode" || NodeType == "BSBlastNodeNode")
		{
			ListSize = TargetObjectRegistry.BSBlastNode_Registry.Size();
			ObjectRegistryClasses::BSBlastNodeNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "BSDamageStage" || NodeType == "BSDamageStageNode")
		{
			ListSize = TargetObjectRegistry.BSDamageStage_Registry.Size();
			ObjectRegistryClasses::BSDamageStageNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "BSRefractionFirePeriodController" || NodeType == "BSRefractionFirePeriodControllerNode")
		{
			ListSize = TargetObjectRegistry.BSRefractionFirePeriodController_Registry.Size();
			ObjectRegistryClasses::BSRefractionFirePeriodControllerNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "bhkConvexListShape" || NodeType == "bhkConvexListShapeNode")
		{
			ListSize = TargetObjectRegistry.bhkConvexListShape_Registry.Size();
			ObjectRegistryClasses::bhkConvexListShapeNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "BSTreadTransfInterpolator" || NodeType == "BSTreadTransfInterpolatorNode")
		{
			ListSize = TargetObjectRegistry.BSTreadTransfInterpolator_Registry.Size();
			ObjectRegistryClasses::BSTreadTransfInterpolatorNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "BSAnimNotes" || NodeType == "BSAnimNotesNode")
		{
			ListSize = TargetObjectRegistry.BSAnimNotes_Registry.Size();
			ObjectRegistryClasses::BSAnimNotesNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "bhkLiquidAction" || NodeType == "bhkLiquidActionNode")
		{
			ListSize = TargetObjectRegistry.bhkLiquidAction_Registry.Size();
			ObjectRegistryClasses::bhkLiquidActionNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "BSMultiBoundNode" || NodeType == "BSMultiBoundNodeNode")
		{
			ListSize = TargetObjectRegistry.BSMultiBoundNode_Registry.Size();
			ObjectRegistryClasses::BSMultiBoundNodeNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "BSMultiBound" || NodeType == "BSMultiBoundNode")
		{
			ListSize = TargetObjectRegistry.BSMultiBound_Registry.Size();
			ObjectRegistryClasses::BSMultiBoundNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "BSMultiBoundData" || NodeType == "BSMultiBoundDataNode")
		{
			ListSize = TargetObjectRegistry.BSMultiBoundData_Registry.Size();
			ObjectRegistryClasses::BSMultiBoundDataNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "BSMultiBoundOBB" || NodeType == "BSMultiBoundOBBNode")
		{
			ListSize = TargetObjectRegistry.BSMultiBoundOBB_Registry.Size();
			ObjectRegistryClasses::BSMultiBoundOBBNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "BSMultiBoundSphere" || NodeType == "BSMultiBoundSphereNode")
		{
			ListSize = TargetObjectRegistry.BSMultiBoundSphere_Registry.Size();
			ObjectRegistryClasses::BSMultiBoundSphereNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "BSSegmentedTriShape" || NodeType == "BSSegmentedTriShapeNode")
		{
			ListSize = TargetObjectRegistry.BSSegmentedTriShape_Registry.Size();
			ObjectRegistryClasses::BSSegmentedTriShapeNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "BSMultiBoundAABB" || NodeType == "BSMultiBoundAABBNode")
		{
			ListSize = TargetObjectRegistry.BSMultiBoundAABB_Registry.Size();
			ObjectRegistryClasses::BSMultiBoundAABBNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiAdditionalGeometryData" || NodeType == "NiAdditionalGeometryDataNode")
		{
			ListSize = TargetObjectRegistry.NiAdditionalGeometryData_Registry.Size();
			ObjectRegistryClasses::NiAdditionalGeometryDataNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "BSPackedAdditionalGeometryData" || NodeType == "BSPackedAdditionalGeometryDataNode")
		{
			ListSize = TargetObjectRegistry.BSPackedAdditionalGeometryData_Registry.Size();
			ObjectRegistryClasses::BSPackedAdditionalGeometryDataNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "BSWArray" || NodeType == "BSWArrayNode")
		{
			ListSize = TargetObjectRegistry.BSWArray_Registry.Size();
			ObjectRegistryClasses::BSWArrayNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "bhkAabbPhantom" || NodeType == "bhkAabbPhantomNode")
		{
			ListSize = TargetObjectRegistry.bhkAabbPhantom_Registry.Size();
			ObjectRegistryClasses::bhkAabbPhantomNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "BSFrustumFOVController" || NodeType == "BSFrustumFOVControllerNode")
		{
			ListSize = TargetObjectRegistry.BSFrustumFOVController_Registry.Size();
			ObjectRegistryClasses::BSFrustumFOVControllerNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "BSDebrisNode" || NodeType == "BSDebrisNodeNode")
		{
			ListSize = TargetObjectRegistry.BSDebrisNode_Registry.Size();
			ObjectRegistryClasses::BSDebrisNodeNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "bhkBreakableConstraint" || NodeType == "bhkBreakableConstraintNode")
		{
			ListSize = TargetObjectRegistry.bhkBreakableConstraint_Registry.Size();
			ObjectRegistryClasses::bhkBreakableConstraintNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "bhkOrientHingedBodyAction" || NodeType == "bhkOrientHingedBodyActionNode")
		{
			ListSize = TargetObjectRegistry.bhkOrientHingedBodyAction_Registry.Size();
			ObjectRegistryClasses::bhkOrientHingedBodyActionNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiDataStream" || NodeType == "NiDataStreamNode")
		{
			ListSize = TargetObjectRegistry.NiDataStream_Registry.Size();
			ObjectRegistryClasses::NiDataStreamNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiRenderObject" || NodeType == "NiRenderObjectNode")
		{
			ListSize = TargetObjectRegistry.NiRenderObject_Registry.Size();
			ObjectRegistryClasses::NiRenderObjectNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiMeshModifier" || NodeType == "NiMeshModifierNode")
		{
			ListSize = TargetObjectRegistry.NiMeshModifier_Registry.Size();
			ObjectRegistryClasses::NiMeshModifierNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiMesh" || NodeType == "NiMeshNode")
		{
			ListSize = TargetObjectRegistry.NiMesh_Registry.Size();
			ObjectRegistryClasses::NiMeshNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiMorphWeightsController" || NodeType == "NiMorphWeightsControllerNode")
		{
			ListSize = TargetObjectRegistry.NiMorphWeightsController_Registry.Size();
			ObjectRegistryClasses::NiMorphWeightsControllerNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiMorphMeshModifier" || NodeType == "NiMorphMeshModifierNode")
		{
			ListSize = TargetObjectRegistry.NiMorphMeshModifier_Registry.Size();
			ObjectRegistryClasses::NiMorphMeshModifierNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiSkinningMeshModifier" || NodeType == "NiSkinningMeshModifierNode")
		{
			ListSize = TargetObjectRegistry.NiSkinningMeshModifier_Registry.Size();
			ObjectRegistryClasses::NiSkinningMeshModifierNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiInstancingMeshModifier" || NodeType == "NiInstancingMeshModifierNode")
		{
			ListSize = TargetObjectRegistry.NiInstancingMeshModifier_Registry.Size();
			ObjectRegistryClasses::NiInstancingMeshModifierNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiSkinningLODController" || NodeType == "NiSkinningLODControllerNode")
		{
			ListSize = TargetObjectRegistry.NiSkinningLODController_Registry.Size();
			ObjectRegistryClasses::NiSkinningLODControllerNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiPSParticleSystem" || NodeType == "NiPSParticleSystemNode")
		{
			ListSize = TargetObjectRegistry.NiPSParticleSystem_Registry.Size();
			ObjectRegistryClasses::NiPSParticleSystemNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiPSMeshParticleSystem" || NodeType == "NiPSMeshParticleSystemNode")
		{
			ListSize = TargetObjectRegistry.NiPSMeshParticleSystem_Registry.Size();
			ObjectRegistryClasses::NiPSMeshParticleSystemNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiPSEmitParticlesCtlr" || NodeType == "NiPSEmitParticlesCtlrNode")
		{
			ListSize = TargetObjectRegistry.NiPSEmitParticlesCtlr_Registry.Size();
			ObjectRegistryClasses::NiPSEmitParticlesCtlrNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiPSForceActiveCtlr" || NodeType == "NiPSForceActiveCtlrNode")
		{
			ListSize = TargetObjectRegistry.NiPSForceActiveCtlr_Registry.Size();
			ObjectRegistryClasses::NiPSForceActiveCtlrNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiPSSimulator" || NodeType == "NiPSSimulatorNode")
		{
			ListSize = TargetObjectRegistry.NiPSSimulator_Registry.Size();
			ObjectRegistryClasses::NiPSSimulatorNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiPSSimulatorStep" || NodeType == "NiPSSimulatorStepNode")
		{
			ListSize = TargetObjectRegistry.NiPSSimulatorStep_Registry.Size();
			ObjectRegistryClasses::NiPSSimulatorStepNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiPSSimulatorGeneralStep" || NodeType == "NiPSSimulatorGeneralStepNode")
		{
			ListSize = TargetObjectRegistry.NiPSSimulatorGeneralStep_Registry.Size();
			ObjectRegistryClasses::NiPSSimulatorGeneralStepNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiPSSimulatorForcesStep" || NodeType == "NiPSSimulatorForcesStepNode")
		{
			ListSize = TargetObjectRegistry.NiPSSimulatorForcesStep_Registry.Size();
			ObjectRegistryClasses::NiPSSimulatorForcesStepNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiPSSimulatorCollidersStep" || NodeType == "NiPSSimulatorCollidersStepNode")
		{
			ListSize = TargetObjectRegistry.NiPSSimulatorCollidersStep_Registry.Size();
			ObjectRegistryClasses::NiPSSimulatorCollidersStepNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiPSSimulatorMeshAlignStep" || NodeType == "NiPSSimulatorMeshAlignStepNode")
		{
			ListSize = TargetObjectRegistry.NiPSSimulatorMeshAlignStep_Registry.Size();
			ObjectRegistryClasses::NiPSSimulatorMeshAlignStepNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiPSSimulatorFinalStep" || NodeType == "NiPSSimulatorFinalStepNode")
		{
			ListSize = TargetObjectRegistry.NiPSSimulatorFinalStep_Registry.Size();
			ObjectRegistryClasses::NiPSSimulatorFinalStepNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiPSFacingQuadGenerator" || NodeType == "NiPSFacingQuadGeneratorNode")
		{
			ListSize = TargetObjectRegistry.NiPSFacingQuadGenerator_Registry.Size();
			ObjectRegistryClasses::NiPSFacingQuadGeneratorNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiShadowGenerator" || NodeType == "NiShadowGeneratorNode")
		{
			ListSize = TargetObjectRegistry.NiShadowGenerator_Registry.Size();
			ObjectRegistryClasses::NiShadowGeneratorNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiPSBoundUpdater" || NodeType == "NiPSBoundUpdaterNode")
		{
			ListSize = TargetObjectRegistry.NiPSBoundUpdater_Registry.Size();
			ObjectRegistryClasses::NiPSBoundUpdaterNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiPSDragForce" || NodeType == "NiPSDragForceNode")
		{
			ListSize = TargetObjectRegistry.NiPSDragForce_Registry.Size();
			ObjectRegistryClasses::NiPSDragForceNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiPSGravityForce" || NodeType == "NiPSGravityForceNode")
		{
			ListSize = TargetObjectRegistry.NiPSGravityForce_Registry.Size();
			ObjectRegistryClasses::NiPSGravityForceNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiPSBoxEmitter" || NodeType == "NiPSBoxEmitterNode")
		{
			ListSize = TargetObjectRegistry.NiPSBoxEmitter_Registry.Size();
			ObjectRegistryClasses::NiPSBoxEmitterNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiPSMeshEmitter" || NodeType == "NiPSMeshEmitterNode")
		{
			ListSize = TargetObjectRegistry.NiPSMeshEmitter_Registry.Size();
			ObjectRegistryClasses::NiPSMeshEmitterNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiPSGravityStrengthCtlr" || NodeType == "NiPSGravityStrengthCtlrNode")
		{
			ListSize = TargetObjectRegistry.NiPSGravityStrengthCtlr_Registry.Size();
			ObjectRegistryClasses::NiPSGravityStrengthCtlrNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiPSPlanarCollider" || NodeType == "NiPSPlanarColliderNode")
		{
			ListSize = TargetObjectRegistry.NiPSPlanarCollider_Registry.Size();
			ObjectRegistryClasses::NiPSPlanarColliderNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiPSEmitterSpeedCtlr" || NodeType == "NiPSEmitterSpeedCtlrNode")
		{
			ListSize = TargetObjectRegistry.NiPSEmitterSpeedCtlr_Registry.Size();
			ObjectRegistryClasses::NiPSEmitterSpeedCtlrNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiPSEmitterRadiusCtlr" || NodeType == "NiPSEmitterRadiusCtlrNode")
		{
			ListSize = TargetObjectRegistry.NiPSEmitterRadiusCtlr_Registry.Size();
			ObjectRegistryClasses::NiPSEmitterRadiusCtlrNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiPSResetOnLoopCtlr" || NodeType == "NiPSResetOnLoopCtlrNode")
		{
			ListSize = TargetObjectRegistry.NiPSResetOnLoopCtlr_Registry.Size();
			ObjectRegistryClasses::NiPSResetOnLoopCtlrNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiPSSphereEmitter" || NodeType == "NiPSSphereEmitterNode")
		{
			ListSize = TargetObjectRegistry.NiPSSphereEmitter_Registry.Size();
			ObjectRegistryClasses::NiPSSphereEmitterNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiPSCylinderEmitter" || NodeType == "NiPSCylinderEmitterNode")
		{
			ListSize = TargetObjectRegistry.NiPSCylinderEmitter_Registry.Size();
			ObjectRegistryClasses::NiPSCylinderEmitterNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiPSEmitterDeclinationCtlr" || NodeType == "NiPSEmitterDeclinationCtlrNode")
		{
			ListSize = TargetObjectRegistry.NiPSEmitterDeclinationCtlr_Registry.Size();
			ObjectRegistryClasses::NiPSEmitterDeclinationCtlrNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiPSEmitterDeclinationVarCtlr" || NodeType == "NiPSEmitterDeclinationVarCtlrNode")
		{
			ListSize = TargetObjectRegistry.NiPSEmitterDeclinationVarCtlr_Registry.Size();
			ObjectRegistryClasses::NiPSEmitterDeclinationVarCtlrNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiPSEmitterPlanarAngleCtlr" || NodeType == "NiPSEmitterPlanarAngleCtlrNode")
		{
			ListSize = TargetObjectRegistry.NiPSEmitterPlanarAngleCtlr_Registry.Size();
			ObjectRegistryClasses::NiPSEmitterPlanarAngleCtlrNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiPSEmitterPlanarAngleVarCtlr" || NodeType == "NiPSEmitterPlanarAngleVarCtlrNode")
		{
			ListSize = TargetObjectRegistry.NiPSEmitterPlanarAngleVarCtlr_Registry.Size();
			ObjectRegistryClasses::NiPSEmitterPlanarAngleVarCtlrNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiPSEmitterRotAngleCtlr" || NodeType == "NiPSEmitterRotAngleCtlrNode")
		{
			ListSize = TargetObjectRegistry.NiPSEmitterRotAngleCtlr_Registry.Size();
			ObjectRegistryClasses::NiPSEmitterRotAngleCtlrNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiPSEmitterRotAngleVarCtlr" || NodeType == "NiPSEmitterRotAngleVarCtlrNode")
		{
			ListSize = TargetObjectRegistry.NiPSEmitterRotAngleVarCtlr_Registry.Size();
			ObjectRegistryClasses::NiPSEmitterRotAngleVarCtlrNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiPSEmitterRotSpeedCtlr" || NodeType == "NiPSEmitterRotSpeedCtlrNode")
		{
			ListSize = TargetObjectRegistry.NiPSEmitterRotSpeedCtlr_Registry.Size();
			ObjectRegistryClasses::NiPSEmitterRotSpeedCtlrNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiPSEmitterRotSpeedVarCtlr" || NodeType == "NiPSEmitterRotSpeedVarCtlrNode")
		{
			ListSize = TargetObjectRegistry.NiPSEmitterRotSpeedVarCtlr_Registry.Size();
			ObjectRegistryClasses::NiPSEmitterRotSpeedVarCtlrNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiPSEmitterLifeSpanCtlr" || NodeType == "NiPSEmitterLifeSpanCtlrNode")
		{
			ListSize = TargetObjectRegistry.NiPSEmitterLifeSpanCtlr_Registry.Size();
			ObjectRegistryClasses::NiPSEmitterLifeSpanCtlrNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiPSBombForce" || NodeType == "NiPSBombForceNode")
		{
			ListSize = TargetObjectRegistry.NiPSBombForce_Registry.Size();
			ObjectRegistryClasses::NiPSBombForceNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiPSSphericalCollider" || NodeType == "NiPSSphericalColliderNode")
		{
			ListSize = TargetObjectRegistry.NiPSSphericalCollider_Registry.Size();
			ObjectRegistryClasses::NiPSSphericalColliderNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiPSSpawner" || NodeType == "NiPSSpawnerNode")
		{
			ListSize = TargetObjectRegistry.NiPSSpawner_Registry.Size();
			ObjectRegistryClasses::NiPSSpawnerNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiSequenceData" || NodeType == "NiSequenceDataNode")
		{
			ListSize = TargetObjectRegistry.NiSequenceData_Registry.Size();
			ObjectRegistryClasses::NiSequenceDataNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiTransformEvaluator" || NodeType == "NiTransformEvaluatorNode")
		{
			ListSize = TargetObjectRegistry.NiTransformEvaluator_Registry.Size();
			ObjectRegistryClasses::NiTransformEvaluatorNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiBSplineCompTransformEvaluator" || NodeType == "NiBSplineCompTransformEvaluatorNode")
		{
			ListSize = TargetObjectRegistry.NiBSplineCompTransformEvaluator_Registry.Size();
			ObjectRegistryClasses::NiBSplineCompTransformEvaluatorNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiMeshHWInstance" || NodeType == "NiMeshHWInstanceNode")
		{
			ListSize = TargetObjectRegistry.NiMeshHWInstance_Registry.Size();
			ObjectRegistryClasses::NiMeshHWInstanceNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiFurSpringController" || NodeType == "NiFurSpringControllerNode")
		{
			ListSize = TargetObjectRegistry.NiFurSpringController_Registry.Size();
			ObjectRegistryClasses::NiFurSpringControllerNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "CStreamableAssetData" || NodeType == "CStreamableAssetDataNode")
		{
			ListSize = TargetObjectRegistry.CStreamableAssetData_Registry.Size();
			ObjectRegistryClasses::CStreamableAssetDataNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "bhkCompressedMeshShape" || NodeType == "bhkCompressedMeshShapeNode")
		{
			ListSize = TargetObjectRegistry.bhkCompressedMeshShape_Registry.Size();
			ObjectRegistryClasses::bhkCompressedMeshShapeNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "bhkCompressedMeshShapeData" || NodeType == "bhkCompressedMeshShapeDataNode")
		{
			ListSize = TargetObjectRegistry.bhkCompressedMeshShapeData_Registry.Size();
			ObjectRegistryClasses::bhkCompressedMeshShapeDataNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "BSInvMarker" || NodeType == "BSInvMarkerNode")
		{
			ListSize = TargetObjectRegistry.BSInvMarker_Registry.Size();
			ObjectRegistryClasses::BSInvMarkerNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "BSBoneLODExtraData" || NodeType == "BSBoneLODExtraDataNode")
		{
			ListSize = TargetObjectRegistry.BSBoneLODExtraData_Registry.Size();
			ObjectRegistryClasses::BSBoneLODExtraDataNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "BSBehaviorGraphExtraData" || NodeType == "BSBehaviorGraphExtraDataNode")
		{
			ListSize = TargetObjectRegistry.BSBehaviorGraphExtraData_Registry.Size();
			ObjectRegistryClasses::BSBehaviorGraphExtraDataNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "BSLagBoneController" || NodeType == "BSLagBoneControllerNode")
		{
			ListSize = TargetObjectRegistry.BSLagBoneController_Registry.Size();
			ObjectRegistryClasses::BSLagBoneControllerNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "BSLODTriShape" || NodeType == "BSLODTriShapeNode")
		{
			ListSize = TargetObjectRegistry.BSLODTriShape_Registry.Size();
			ObjectRegistryClasses::BSLODTriShapeNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "BSFurnitureMarkerNode" || NodeType == "BSFurnitureMarkerNodeNode")
		{
			ListSize = TargetObjectRegistry.BSFurnitureMarkerNode_Registry.Size();
			ObjectRegistryClasses::BSFurnitureMarkerNodeNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "BSLeafAnimNode" || NodeType == "BSLeafAnimNodeNode")
		{
			ListSize = TargetObjectRegistry.BSLeafAnimNode_Registry.Size();
			ObjectRegistryClasses::BSLeafAnimNodeNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "BSTreeNode" || NodeType == "BSTreeNodeNode")
		{
			ListSize = TargetObjectRegistry.BSTreeNode_Registry.Size();
			ObjectRegistryClasses::BSTreeNodeNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "NiLightRadiusController" || NodeType == "NiLightRadiusControllerNode")
		{
			ListSize = TargetObjectRegistry.NiLightRadiusController_Registry.Size();
			ObjectRegistryClasses::NiLightRadiusControllerNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "BSShape" || NodeType == "BSShapeNode")
		{
			ListSize = TargetObjectRegistry.BSShape_Registry.Size();
			ObjectRegistryClasses::BSShapeNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "BSTriShape" || NodeType == "BSTriShapeNode")
		{
			ListSize = TargetObjectRegistry.BSTriShape_Registry.Size();
			ObjectRegistryClasses::BSTriShapeNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "BSSubIndexTriShape" || NodeType == "BSSubIndexTriShapeNode")
		{
			ListSize = TargetObjectRegistry.BSSubIndexTriShape_Registry.Size();
			ObjectRegistryClasses::BSSubIndexTriShapeNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "BSMeshLODTriShape" || NodeType == "BSMeshLODTriShapeNode")
		{
			ListSize = TargetObjectRegistry.BSMeshLODTriShape_Registry.Size();
			ObjectRegistryClasses::BSMeshLODTriShapeNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "bhkNPCollisionObject" || NodeType == "bhkNPCollisionObjectNode")
		{
			ListSize = TargetObjectRegistry.bhkNPCollisionObject_Registry.Size();
			ObjectRegistryClasses::bhkNPCollisionObjectNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "BSExtraData" || NodeType == "BSExtraDataNode")
		{
			ListSize = TargetObjectRegistry.BSExtraData_Registry.Size();
			ObjectRegistryClasses::BSExtraDataNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "bhkPhysicsSystem" || NodeType == "bhkPhysicsSystemNode")
		{
			ListSize = TargetObjectRegistry.bhkPhysicsSystem_Registry.Size();
			ObjectRegistryClasses::bhkPhysicsSystemNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "bhkRagdollSystem" || NodeType == "bhkRagdollSystemNode")
		{
			ListSize = TargetObjectRegistry.bhkRagdollSystem_Registry.Size();
			ObjectRegistryClasses::bhkRagdollSystemNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "BSClothExtraData" || NodeType == "BSClothExtraDataNode")
		{
			ListSize = TargetObjectRegistry.BSClothExtraData_Registry.Size();
			ObjectRegistryClasses::BSClothExtraDataNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "BSSkin__Instance" || NodeType == "BSSkin__InstanceNode")
		{
			ListSize = TargetObjectRegistry.BSSkin__Instance_Registry.Size();
			ObjectRegistryClasses::BSSkin__InstanceNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "BSSkin__BoneData" || NodeType == "BSSkin__BoneDataNode")
		{
			ListSize = TargetObjectRegistry.BSSkin__BoneData_Registry.Size();
			ObjectRegistryClasses::BSSkin__BoneDataNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "BSPositionData" || NodeType == "BSPositionDataNode")
		{
			ListSize = TargetObjectRegistry.BSPositionData_Registry.Size();
			ObjectRegistryClasses::BSPositionDataNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "BSConnectPoint__Parents" || NodeType == "BSConnectPoint__ParentsNode")
		{
			ListSize = TargetObjectRegistry.BSConnectPoint__Parents_Registry.Size();
			ObjectRegistryClasses::BSConnectPoint__ParentsNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
		if(NodeType == "BSConnectPoint__Children" || NodeType == "BSConnectPoint__ChildrenNode")
		{
			ListSize = TargetObjectRegistry.BSConnectPoint__Children_Registry.Size();
			ObjectRegistryClasses::BSConnectPoint__ChildrenNode* ElementData = nullptr;
			for(size_t Index = 0; Index < ListSize&&RetrievedData == ""; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }
				else if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }
			}
		}
	}
	return RetrievedData;
}