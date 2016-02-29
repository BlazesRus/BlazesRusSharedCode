#pragma once
#ifndef NifTreeObjectRegistryClasses_IncludeGuard
#define NifTreeObjectRegistryClasses_IncludeGuard


#include "..\..\GlobalCode\GlobalCode_NodeTrees\LooseNodeTreeTemplate.h"
#include <typeinfo> 

#include "obj\NiObject.h"
#include "obj\Ni3dsAlphaAnimator.h"
#include "obj\Ni3dsAnimationNode.h"
#include "obj\Ni3dsColorAnimator.h"
#include "obj\Ni3dsMorphShape.h"
#include "obj\Ni3dsParticleSystem.h"
#include "obj\Ni3dsPathController.h"
#include "obj\NiParticleModifier.h"
#include "obj\NiPSysCollider.h"
#include "obj\bhkRefObject.h"
#include "obj\bhkSerializable.h"
#include "obj\bhkWorldObject.h"
#include "obj\bhkPhantom.h"
#include "obj\bhkShapePhantom.h"
#include "obj\bhkSimpleShapePhantom.h"
#include "obj\bhkEntity.h"
#include "obj\bhkRigidBody.h"
#include "obj\bhkRigidBodyT.h"
#include "obj\bhkConstraint.h"
#include "obj\bhkLimitedHingeConstraint.h"
#include "obj\bhkMalleableConstraint.h"
#include "obj\bhkStiffSpringConstraint.h"
#include "obj\bhkRagdollConstraint.h"
#include "obj\bhkPrismaticConstraint.h"
#include "obj\bhkHingeConstraint.h"
#include "obj\bhkBallAndSocketConstraint.h"
#include "obj\bhkBallSocketConstraintChain.h"
#include "obj\bhkShape.h"
#include "obj\bhkTransformShape.h"
#include "obj\bhkSphereRepShape.h"
#include "obj\bhkConvexShape.h"
#include "obj\bhkSphereShape.h"
#include "obj\bhkCapsuleShape.h"
#include "obj\bhkBoxShape.h"
#include "obj\bhkConvexVerticesShape.h"
#include "obj\bhkConvexTransformShape.h"
#include "obj\bhkMultiSphereShape.h"
#include "obj\bhkBvTreeShape.h"
#include "obj\bhkMoppBvTreeShape.h"
#include "obj\bhkShapeCollection.h"
#include "obj\bhkListShape.h"
#include "obj\bhkMeshShape.h"
#include "obj\bhkPackedNiTriStripsShape.h"
#include "obj\bhkNiTriStripsShape.h"
#include "obj\NiExtraData.h"
#include "obj\NiInterpolator.h"
#include "obj\NiKeyBasedInterpolator.h"
#include "obj\NiFloatInterpolator.h"
#include "obj\NiTransformInterpolator.h"
#include "obj\NiPoint3Interpolator.h"
#include "obj\NiPathInterpolator.h"
#include "obj\NiBoolInterpolator.h"
#include "obj\NiBoolTimelineInterpolator.h"
#include "obj\NiBlendInterpolator.h"
#include "obj\NiBSplineInterpolator.h"
#include "obj\NiObjectNET.h"
#include "obj\NiCollisionObject.h"
#include "obj\NiCollisionData.h"
#include "obj\bhkNiCollisionObject.h"
#include "obj\bhkCollisionObject.h"
#include "obj\bhkBlendCollisionObject.h"
#include "obj\bhkPCollisionObject.h"
#include "obj\bhkSPCollisionObject.h"
#include "obj\NiAVObject.h"
#include "obj\NiDynamicEffect.h"
#include "obj\NiLight.h"
#include "obj\NiProperty.h"
#include "obj\NiTransparentProperty.h"
#include "obj\NiPSysModifier.h"
#include "obj\NiPSysEmitter.h"
#include "obj\NiPSysVolumeEmitter.h"
#include "obj\NiTimeController.h"
#include "obj\NiInterpController.h"
#include "obj\NiMultiTargetTransformController.h"
#include "obj\NiGeomMorpherController.h"
#include "obj\NiMorphController.h"
#include "obj\NiMorpherController.h"
#include "obj\NiSingleInterpController.h"
#include "obj\NiKeyframeController.h"
#include "obj\NiTransformController.h"
#include "obj\NiPSysModifierCtlr.h"
#include "obj\NiPSysEmitterCtlr.h"
#include "obj\NiPSysModifierBoolCtlr.h"
#include "obj\NiPSysModifierActiveCtlr.h"
#include "obj\NiPSysModifierFloatCtlr.h"
#include "obj\NiPSysEmitterDeclinationCtlr.h"
#include "obj\NiPSysEmitterDeclinationVarCtlr.h"
#include "obj\NiPSysEmitterInitialRadiusCtlr.h"
#include "obj\NiPSysEmitterLifeSpanCtlr.h"
#include "obj\NiPSysEmitterSpeedCtlr.h"
#include "obj\NiPSysGravityStrengthCtlr.h"
#include "obj\NiFloatInterpController.h"
#include "obj\NiFlipController.h"
#include "obj\NiAlphaController.h"
#include "obj\NiTextureTransformController.h"
#include "obj\NiLightDimmerController.h"
#include "obj\NiBoolInterpController.h"
#include "obj\NiVisController.h"
#include "obj\NiPoint3InterpController.h"
#include "obj\NiMaterialColorController.h"
#include "obj\NiLightColorController.h"
#include "obj\NiExtraDataController.h"
#include "obj\NiFloatExtraDataController.h"
#include "obj\NiBoneLODController.h"
#include "obj\NiBSBoneLODController.h"
#include "obj\NiGeometry.h"
#include "obj\NiTriBasedGeom.h"
#include "obj\NiGeometryData.h"
#include "obj\AbstractAdditionalGeometryData.h"
#include "obj\NiTriBasedGeomData.h"
#include "obj\bhkBlendController.h"
#include "obj\BSBound.h"
#include "obj\BSFurnitureMarker.h"
#include "obj\BSParentVelocityModifier.h"
#include "obj\BSPSysArrayEmitter.h"
#include "obj\BSWindModifier.h"
#include "obj\hkPackedNiTriStripsData.h"
#include "obj\NiAlphaProperty.h"
#include "obj\NiAmbientLight.h"
#include "obj\NiParticlesData.h"
#include "obj\NiRotatingParticlesData.h"
#include "obj\NiAutoNormalParticlesData.h"
#include "obj\NiPSysData.h"
#include "obj\NiMeshPSysData.h"
#include "obj\NiBinaryExtraData.h"
#include "obj\NiBinaryVoxelExtraData.h"
#include "obj\NiBinaryVoxelData.h"
#include "obj\NiBlendBoolInterpolator.h"
#include "obj\NiBlendFloatInterpolator.h"
#include "obj\NiBlendPoint3Interpolator.h"
#include "obj\NiBlendTransformInterpolator.h"
#include "obj\NiBoolData.h"
#include "obj\NiBooleanExtraData.h"
#include "obj\NiBSplineBasisData.h"
#include "obj\NiBSplineFloatInterpolator.h"
#include "obj\NiBSplineCompFloatInterpolator.h"
#include "obj\NiBSplinePoint3Interpolator.h"
#include "obj\NiBSplineCompPoint3Interpolator.h"
#include "obj\NiBSplineTransformInterpolator.h"
#include "obj\NiBSplineCompTransformInterpolator.h"
#include "obj\BSRotAccumTransfInterpolator.h"
#include "obj\NiBSplineData.h"
#include "obj\NiCamera.h"
#include "obj\NiColorData.h"
#include "obj\NiColorExtraData.h"
#include "obj\NiControllerManager.h"
#include "obj\NiSequence.h"
#include "obj\NiControllerSequence.h"
#include "obj\NiAVObjectPalette.h"
#include "obj\NiDefaultAVObjectPalette.h"
#include "obj\NiDirectionalLight.h"
#include "obj\NiDitherProperty.h"
#include "obj\NiRollController.h"
#include "obj\NiFloatData.h"
#include "obj\NiFloatExtraData.h"
#include "obj\NiFloatsExtraData.h"
#include "obj\NiFogProperty.h"
#include "obj\NiGravity.h"
#include "obj\NiIntegerExtraData.h"
#include "obj\BSXFlags.h"
#include "obj\NiIntegersExtraData.h"
#include "obj\BSKeyframeController.h"
#include "obj\NiKeyframeData.h"
#include "obj\NiLookAtController.h"
#include "obj\NiLookAtInterpolator.h"
#include "obj\NiMaterialProperty.h"
#include "obj\NiMorphData.h"
#include "obj\NiNode.h"
#include "obj\NiBone.h"
#include "obj\AvoidNode.h"
#include "obj\FxWidget.h"
#include "obj\FxButton.h"
#include "obj\FxRadioButton.h"
#include "obj\NiBillboardNode.h"
#include "obj\NiBSAnimationNode.h"
#include "obj\NiBSParticleNode.h"
#include "obj\NiSwitchNode.h"
#include "obj\NiLODNode.h"
#include "obj\NiPalette.h"
#include "obj\NiParticleBomb.h"
#include "obj\NiParticleColorModifier.h"
#include "obj\NiParticleGrowFade.h"
#include "obj\NiParticleMeshModifier.h"
#include "obj\NiParticleRotation.h"
#include "obj\NiParticles.h"
#include "obj\NiAutoNormalParticles.h"
#include "obj\NiParticleMeshes.h"
#include "obj\NiParticleMeshesData.h"
#include "obj\NiParticleSystem.h"
#include "obj\NiMeshParticleSystem.h"
#include "obj\NiParticleSystemController.h"
#include "obj\NiBSPArrayController.h"
#include "obj\NiPathController.h"
#include "obj\ATextureRenderData.h"
#include "obj\NiPersistentSrcTextureRendererData.h"
#include "obj\NiPixelData.h"
#include "obj\NiPlanarCollider.h"
#include "obj\NiPointLight.h"
#include "obj\NiPosData.h"
#include "obj\NiPSysAgeDeathModifier.h"
#include "obj\NiPSysBombModifier.h"
#include "obj\NiPSysBoundUpdateModifier.h"
#include "obj\NiPSysBoxEmitter.h"
#include "obj\NiPSysColliderManager.h"
#include "obj\NiPSysColorModifier.h"
#include "obj\NiPSysCylinderEmitter.h"
#include "obj\NiPSysDragModifier.h"
#include "obj\NiPSysEmitterCtlrData.h"
#include "obj\NiPSysGravityModifier.h"
#include "obj\NiPSysGrowFadeModifier.h"
#include "obj\NiPSysMeshEmitter.h"
#include "obj\NiPSysMeshUpdateModifier.h"
#include "obj\BSPSysInheritVelocityModifier.h"
#include "obj\BSPSysHavokUpdateModifier.h"
#include "obj\BSPSysRecycleBoundModifier.h"
#include "obj\BSPSysSubTexModifier.h"
#include "obj\NiPSysPlanarCollider.h"
#include "obj\NiPSysSphericalCollider.h"
#include "obj\NiPSysPositionModifier.h"
#include "obj\NiPSysResetOnLoopCtlr.h"
#include "obj\NiPSysRotationModifier.h"
#include "obj\NiPSysSpawnModifier.h"
#include "obj\NiPSysSphereEmitter.h"
#include "obj\NiPSysUpdateCtlr.h"
#include "obj\NiPSysFieldModifier.h"
#include "obj\NiPSysVortexFieldModifier.h"
#include "obj\NiPSysGravityFieldModifier.h"
#include "obj\NiPSysDragFieldModifier.h"
#include "obj\NiPSysTurbulenceFieldModifier.h"
#include "obj\BSPSysLODModifier.h"
#include "obj\BSPSysScaleModifier.h"
#include "obj\NiPSysFieldMagnitudeCtlr.h"
#include "obj\NiPSysFieldAttenuationCtlr.h"
#include "obj\NiPSysFieldMaxDistanceCtlr.h"
#include "obj\NiPSysAirFieldAirFrictionCtlr.h"
#include "obj\NiPSysAirFieldInheritVelocityCtlr.h"
#include "obj\NiPSysAirFieldSpreadCtlr.h"
#include "obj\NiPSysInitialRotSpeedCtlr.h"
#include "obj\NiPSysInitialRotSpeedVarCtlr.h"
#include "obj\NiPSysInitialRotAngleCtlr.h"
#include "obj\NiPSysInitialRotAngleVarCtlr.h"
#include "obj\NiPSysEmitterPlanarAngleCtlr.h"
#include "obj\NiPSysEmitterPlanarAngleVarCtlr.h"
#include "obj\NiPSysAirFieldModifier.h"
#include "obj\NiPSysTrailEmitter.h"
#include "obj\NiLightIntensityController.h"
#include "obj\NiPSysRadialFieldModifier.h"
#include "obj\NiLODData.h"
#include "obj\NiRangeLODData.h"
#include "obj\NiScreenLODData.h"
#include "obj\NiRotatingParticles.h"
#include "obj\NiSequenceStreamHelper.h"
#include "obj\NiShadeProperty.h"
#include "obj\NiSkinData.h"
#include "obj\NiSkinInstance.h"
#include "obj\NiTriShapeSkinController.h"
#include "obj\NiClodSkinInstance.h"
#include "obj\NiSkinPartition.h"
#include "obj\NiTexture.h"
#include "obj\NiSourceTexture.h"
#include "obj\NiSpecularProperty.h"
#include "obj\NiSphericalCollider.h"
#include "obj\NiSpotLight.h"
#include "obj\NiStencilProperty.h"
#include "obj\NiStringExtraData.h"
#include "obj\NiStringPalette.h"
#include "obj\NiStringsExtraData.h"
#include "obj\NiTextKeyExtraData.h"
#include "obj\NiTextureEffect.h"
#include "obj\NiTextureModeProperty.h"
#include "obj\NiImage.h"
#include "obj\NiTextureProperty.h"
#include "obj\NiMultiTextureProperty.h"
#include "obj\NiTexturingProperty.h"
#include "obj\NiTransformData.h"
#include "obj\NiTriShape.h"
#include "obj\NiTriShapeData.h"
#include "obj\NiTriStrips.h"
#include "obj\NiTriStripsData.h"
#include "obj\NiEnvMappedTriShape.h"
#include "obj\NiEnvMappedTriShapeData.h"
#include "obj\NiBezierTriangle4.h"
#include "obj\NiBezierMesh.h"
#include "obj\NiClod.h"
#include "obj\NiClodData.h"
#include "obj\NiUVController.h"
#include "obj\NiUVData.h"
#include "obj\NiVectorExtraData.h"
#include "obj\NiVertexColorProperty.h"
#include "obj\NiVertWeightsExtraData.h"
#include "obj\NiVisData.h"
#include "obj\NiWireframeProperty.h"
#include "obj\NiZBufferProperty.h"
#include "obj\RootCollisionNode.h"
#include "obj\NiRawImageData.h"
#include "obj\NiSortAdjustNode.h"
#include "obj\NiSourceCubeMap.h"
#include "obj\NiPhysXProp.h"
#include "obj\NiPhysXPropDesc.h"
#include "obj\NiPhysXActorDesc.h"
#include "obj\NiPhysXBodyDesc.h"
#include "obj\NiPhysXD6JointDesc.h"
#include "obj\NiPhysXShapeDesc.h"
#include "obj\NiPhysXMeshDesc.h"
#include "obj\NiPhysXMaterialDesc.h"
#include "obj\NiPhysXKinematicSrc.h"
#include "obj\NiPhysXTransformDest.h"
#include "obj\NiArkAnimationExtraData.h"
#include "obj\NiArkImporterExtraData.h"
#include "obj\NiArkTextureExtraData.h"
#include "obj\NiArkViewportInfoExtraData.h"
#include "obj\NiArkShaderExtraData.h"
#include "obj\NiLines.h"
#include "obj\NiLinesData.h"
#include "obj\NiScreenElementsData.h"
#include "obj\NiScreenElements.h"
#include "obj\NiRoomGroup.h"
#include "obj\NiRoom.h"
#include "obj\NiPortal.h"
#include "obj\BSFadeNode.h"
#include "obj\BSShaderProperty.h"
#include "obj\BSShaderLightingProperty.h"
#include "obj\BSShaderNoLightingProperty.h"
#include "obj\BSShaderPPLightingProperty.h"
#include "obj\BSEffectShaderPropertyFloatController.h"
#include "obj\BSEffectShaderPropertyColorController.h"
#include "obj\BSLightingShaderPropertyFloatController.h"
#include "obj\BSLightingShaderPropertyColorController.h"
#include "obj\BSNiAlphaPropertyTestRefController.h"
#include "obj\BSProceduralLightningController.h"
#include "obj\BSShaderTextureSet.h"
#include "obj\WaterShaderProperty.h"
#include "obj\SkyShaderProperty.h"
#include "obj\TileShaderProperty.h"
#include "obj\DistantLODShaderProperty.h"
#include "obj\BSDistantTreeShaderProperty.h"
#include "obj\TallGrassShaderProperty.h"
#include "obj\VolumetricFogShaderProperty.h"
#include "obj\HairShaderProperty.h"
#include "obj\Lighting30ShaderProperty.h"
#include "obj\BSLightingShaderProperty.h"
#include "obj\BSEffectShaderProperty.h"
#include "obj\BSWaterShaderProperty.h"
#include "obj\BSSkyShaderProperty.h"
#include "obj\BSDismemberSkinInstance.h"
#include "obj\BSDecalPlacementVectorExtraData.h"
#include "obj\BSPSysSimpleColorModifier.h"
#include "obj\BSValueNode.h"
#include "obj\BSStripParticleSystem.h"
#include "obj\BSStripPSysData.h"
#include "obj\BSPSysStripUpdateModifier.h"
#include "obj\BSMaterialEmittanceMultController.h"
#include "obj\BSMasterParticleSystem.h"
#include "obj\BSPSysMultiTargetEmitterCtlr.h"
#include "obj\BSRefractionStrengthController.h"
#include "obj\BSOrderedNode.h"
#include "obj\BSBlastNode.h"
#include "obj\BSDamageStage.h"
#include "obj\BSRefractionFirePeriodController.h"
#include "obj\bhkConvexListShape.h"
#include "obj\BSTreadTransfInterpolator.h"
#include "obj\BSAnimNotes.h"
#include "obj\bhkLiquidAction.h"
#include "obj\BSMultiBoundNode.h"
#include "obj\BSMultiBound.h"
#include "obj\BSMultiBoundData.h"
#include "obj\BSMultiBoundOBB.h"
#include "obj\BSMultiBoundSphere.h"
#include "obj\BSSegmentedTriShape.h"
#include "obj\BSMultiBoundAABB.h"
#include "obj\NiAdditionalGeometryData.h"
#include "obj\BSPackedAdditionalGeometryData.h"
#include "obj\BSWArray.h"
#include "obj\bhkAabbPhantom.h"
#include "obj\BSFrustumFOVController.h"
#include "obj\BSDebrisNode.h"
#include "obj\bhkBreakableConstraint.h"
#include "obj\bhkOrientHingedBodyAction.h"
#include "obj\NiDataStream.h"
#include "obj\NiRenderObject.h"
#include "obj\NiMeshModifier.h"
#include "obj\NiMesh.h"
#include "obj\NiMorphWeightsController.h"
#include "obj\NiMorphMeshModifier.h"
#include "obj\NiSkinningMeshModifier.h"
#include "obj\NiInstancingMeshModifier.h"
#include "obj\NiSkinningLODController.h"
#include "obj\NiPSParticleSystem.h"
#include "obj\NiPSMeshParticleSystem.h"
#include "obj\NiPSEmitParticlesCtlr.h"
#include "obj\NiPSForceActiveCtlr.h"
#include "obj\NiPSSimulator.h"
#include "obj\NiPSSimulatorStep.h"
#include "obj\NiPSSimulatorGeneralStep.h"
#include "obj\NiPSSimulatorForcesStep.h"
#include "obj\NiPSSimulatorCollidersStep.h"
#include "obj\NiPSSimulatorMeshAlignStep.h"
#include "obj\NiPSSimulatorFinalStep.h"
#include "obj\NiPSFacingQuadGenerator.h"
#include "obj\NiShadowGenerator.h"
#include "obj\NiPSBoundUpdater.h"
#include "obj\NiPSDragForce.h"
#include "obj\NiPSGravityForce.h"
#include "obj\NiPSBoxEmitter.h"
#include "obj\NiPSMeshEmitter.h"
#include "obj\NiPSGravityStrengthCtlr.h"
#include "obj\NiPSPlanarCollider.h"
#include "obj\NiPSEmitterSpeedCtlr.h"
#include "obj\NiPSEmitterRadiusCtlr.h"
#include "obj\NiPSResetOnLoopCtlr.h"
#include "obj\NiPSSphereEmitter.h"
#include "obj\NiPSCylinderEmitter.h"
#include "obj\NiPSEmitterDeclinationCtlr.h"
#include "obj\NiPSEmitterDeclinationVarCtlr.h"
#include "obj\NiPSEmitterPlanarAngleCtlr.h"
#include "obj\NiPSEmitterPlanarAngleVarCtlr.h"
#include "obj\NiPSEmitterRotAngleCtlr.h"
#include "obj\NiPSEmitterRotAngleVarCtlr.h"
#include "obj\NiPSEmitterRotSpeedCtlr.h"
#include "obj\NiPSEmitterRotSpeedVarCtlr.h"
#include "obj\NiPSEmitterLifeSpanCtlr.h"
#include "obj\NiPSBombForce.h"
#include "obj\NiPSSphericalCollider.h"
#include "obj\NiPSSpawner.h"
#include "obj\NiSequenceData.h"
#include "obj\NiTransformEvaluator.h"
#include "obj\NiBSplineCompTransformEvaluator.h"
#include "obj\NiMeshHWInstance.h"
#include "obj\NiFurSpringController.h"
#include "obj\CStreamableAssetData.h"
#include "obj\bhkCompressedMeshShape.h"
#include "obj\bhkCompressedMeshShapeData.h"
#include "obj\BSInvMarker.h"
#include "obj\BSBoneLODExtraData.h"
#include "obj\BSBehaviorGraphExtraData.h"
#include "obj\BSLagBoneController.h"
#include "obj\BSLODTriShape.h"
#include "obj\BSFurnitureMarkerNode.h"
#include "obj\BSLeafAnimNode.h"
#include "obj\BSTreeNode.h"
#include "obj\NiLightRadiusController.h"
#include "obj\BSShape.h"
#include "obj\BSTriShape.h"
#include "obj\BSSubIndexTriShape.h"
#include "obj\BSMeshLODTriShape.h"
#include "obj\bhkNPCollisionObject.h"
#include "obj\BSExtraData.h"
#include "obj\bhkPhysicsSystem.h"
#include "obj\bhkRagdollSystem.h"
#include "obj\BSClothExtraData.h"
#include "obj\BSSkin__Instance.h"
#include "obj\BSSkin__BoneData.h"
#include "obj\BSPositionData.h"
#include "obj\BSConnectPoint__Parents.h"
#include "obj\BSConnectPoint__Children.h"
#include "obj\BSEyeCenterExtraData.h"
#include "..\..\GlobalCode\GlobalCode_VariableLists\VariableList.h"

namespace ObjectRegistryClasses
{
	struct BasicNode
	{
		//Keep the name of the actual Node connected to(For use with functions like auto-connect nodes)
		std::string InternalName;
	};
	template <typename NodeType>
	class ObjectStorage : public VariableList<NodeType>
	{
	public:
		//************************************
		// Attempt to ObjectNode data into storage(need to fix data copying from TargetNode later)(Incomplete)
		// Method:    AddDataCopy
		// FullName:  ObjectRegistryClasses::ObjectStorage<NodeType>::AddDataCopy
		// Access:    private 
		// Returns:   size_t
		// Qualifier:
		// Parameter: Niflib::NiObjectRef TargetNode
		//************************************
		size_t AddDataCopy(Niflib::NiObjectRef TargetNode)
		{
			//Need to fix the conversion from Niflib::NiObjectRef to NodeType
			//Add(DynamicCast<NodeType>(TargetNode));
			//For now just adding blank data and manually copying some data from the inherited classes
			AddData();
			size_t Index = Size()-1;
			NodeType* TargetIndex = GetElementPointerV2(Index);
			//if(NodeType.typename() == "bhkRigidBody")
			//{
		///*! Unknown. Could be 2 shorts corresponding to Unknown 7 Shorts[1] and [2]. */
		//int unknownInt1;
				//TargetIndex->unknownInt1 = TargetNode->unknownInt1;
		///*! Unknown. */
		//int unknownInt2;
		///*! Unknown. Could be 3 floats. */
		//array<3, int > unknown3Ints;
		///*! The collision response. See hkResponseType for hkpWorld default implementations. */
		//hkResponseType collisionResponse_;
		///*! Unknown */
		//byte unknownByte;
		///*!
		// * Lowers the frequency for processContactCallbacks. A value of 5 means that a
		// * callback is raised every 5th frame.
		// */
		//unsigned short processContactCallbackDelay_;
		///*! Unknown. */
		//array<2, unsigned short > unknown2Shorts;
		///*! Copy of Layer value? */
		//OblivionLayer layerCopy;
		///*! Copy of Col Filter value? */
		//byte colFilterCopy;
		///*! Copy of Skyrim Layer value? */
		//SkyrimLayer skyrimLayerCopy;
		///*! Copy of Flags & Part number? */
		//byte flagsAndPartNumberCopy;
		///*!
		// * Unknown.
		// *             Oblivion defaults: 0 21280 2481 62977 65535 44 0
		// *             Skyrim defaults: 0 56896 1343 0 0 1 65535 (fourth and fifth element
		// * *must* be zero)
		// */
		//array<7, unsigned short > unknown7Shorts;
		///*!
		// * A vector that moves the body by the specified amount. Only enabled in
		// * bhkRigidBodyT objects.
		// */
		//Vector4 translation;
		///*!
		// * The rotation Yaw/Pitch/Roll to apply to the body. Only enabled in bhkRigidBodyT
		// * objects.
		// */
		//QuaternionXYZW rotation;
		///*! Linear velocity. */
		//Vector4 linearVelocity;
		///*! Angular velocity. */
		//Vector4 angularVelocity;
		///*! Defines how the mass is distributed among the body. */
		//InertiaMatrix inertia;
		///*!
		// * This seems to be used to relocate the object's center of mass. Useful for
		// * balancing objects in contraints.
		// */
		//Vector4 center;
		///*! The body's mass in kg. A mass of zero represents an immovable object. */
		//float mass;
		///*!
		// * Damping value for linear movement. A value that is too small fixes the object in
		// * place.
		// */
		//float linearDamping;
		///*! Damping value for angular movement. */
		//float angularDamping;
		///*! Unknown. */
		//float unknownTimefactorOrGravityfactor1;
		///*! Unknown. */
		//float unknownTimefactorOrGravityfactor2;
		///*! The body's friction. */
		//float friction;
		///*! Unknown. */
		//float rollingfrictionmultiplier_;
		///*!
		// * The body's restitution (elasticity).
		// *             If the restitution is not 0.0 the object will need extra CPU for all
		// * new collisions.
		// *             Try to set restitution to 0 for maximum performance (e.g. collapsing
		// * buildings)
		// */
		//float restitution;
		///*! Maximal linear velocity. */
		//float maxLinearVelocity;
		///*! Maximal angular velocity. Pi x 10? */
		//float maxAngularVelocity;
		///*!
		// * The maximum allowed penetration for this object.
		// *             This is a hint to the engine to see how much CPU the engine should
		// * invest to keep this object from penetrating.
		// *             A good choice is 5% - 20% of the smallest diameter of the object.
		// */
		//float penetrationDepth;
		///*! Motion system? Overrides Quality when on Keyframed? */
		//MotionSystem motionSystem;
		///*! The initial deactivator type of the body. */
		//DeactivatorType deactivatorType;
		///*!
		// * Usually set to 1 for fixed objects, or set to 2 for moving ones.  Seems to
		// * always be same as Unknown Byte 1.
		// */
		//SolverDeactivation solverDeactivation;
		///*! The motion type. Determines quality of motion? */
		//MotionQuality qualityType;
		///*! Unknown. */
		//unsigned int unknownInt6;
		///*! Unknown. */
		//unsigned int unknownInt7;
		///*! Unknown. */
		//unsigned int unknownInt8;
		///*! Unknown. Skyrim only. */
		//unsigned int unknownInt81;
		///*! The number of constraints this object is bound to. */
		//mutable unsigned int numConstraints;
		///*! Unknown. */
		//vector<Ref<bhkSerializable > > constraints;
		///*! 0 = do not respond to wind, 1 = respond to wind (?) */
		//unsigned int unknownInt9;
		///*! Unknown. */
		//unsigned short unknownInt91;
			//}

			return Size();
		}
	};
	class NiObject : public BasicNode, public Niflib::NiObject {};
	class NiObject_Storage : public ObjectStorage <NiObject> 
	{
	};
	class Ni3dsAlphaAnimator : public BasicNode, public Niflib::Ni3dsAlphaAnimator {};
	class Ni3dsAlphaAnimator_Storage : public ObjectStorage <Ni3dsAlphaAnimator> {};
	class Ni3dsAnimationNode : public BasicNode, public Niflib::Ni3dsAnimationNode {};
	class Ni3dsAnimationNode_Storage : public ObjectStorage <Ni3dsAnimationNode> {};
	class Ni3dsColorAnimator : public BasicNode, public Niflib::Ni3dsColorAnimator {};
	class Ni3dsColorAnimator_Storage : public ObjectStorage <Ni3dsColorAnimator> {};
	class Ni3dsMorphShape : public BasicNode, public Niflib::Ni3dsMorphShape {};
	class Ni3dsMorphShape_Storage : public ObjectStorage <Ni3dsMorphShape> {};
	class Ni3dsParticleSystem : public BasicNode, public Niflib::Ni3dsParticleSystem {};
	class Ni3dsParticleSystem_Storage : public ObjectStorage <Ni3dsParticleSystem> {};
	class Ni3dsPathController : public BasicNode, public Niflib::Ni3dsPathController {};
	class Ni3dsPathController_Storage : public ObjectStorage <Ni3dsPathController> {};
	class NiParticleModifier : public BasicNode, public Niflib::NiParticleModifier {};
	class NiParticleModifier_Storage : public ObjectStorage <NiParticleModifier> {};
	class NiPSysCollider : public BasicNode, public Niflib::NiPSysCollider {};
	class NiPSysCollider_Storage : public ObjectStorage <NiPSysCollider> {};
	class bhkRefObject : public BasicNode, public Niflib::bhkRefObject {};
	class bhkRefObject_Storage : public ObjectStorage <bhkRefObject> {};
	class bhkSerializable : public BasicNode, public Niflib::bhkSerializable {};
	class bhkSerializable_Storage : public ObjectStorage <bhkSerializable> {};
	class bhkWorldObject : public BasicNode, public Niflib::bhkWorldObject {};
	class bhkWorldObject_Storage : public ObjectStorage <bhkWorldObject> {};
	class bhkPhantom : public BasicNode, public Niflib::bhkPhantom {};
	class bhkPhantom_Storage : public ObjectStorage <bhkPhantom> {};
	class bhkShapePhantom : public BasicNode, public Niflib::bhkShapePhantom {};
	class bhkShapePhantom_Storage : public ObjectStorage <bhkShapePhantom> {};
	class bhkSimpleShapePhantom : public BasicNode, public Niflib::bhkSimpleShapePhantom {};
	class bhkSimpleShapePhantom_Storage : public ObjectStorage <bhkSimpleShapePhantom> {};
	class bhkEntity : public BasicNode, public Niflib::bhkEntity {};
	class bhkEntity_Storage : public ObjectStorage <bhkEntity> {};
	class bhkRigidBody : public BasicNode, public Niflib::bhkRigidBody {};
	class bhkRigidBody_Storage : public ObjectStorage <bhkRigidBody> {};
	class bhkRigidBodyT : public BasicNode, public Niflib::bhkRigidBodyT {};
	class bhkRigidBodyT_Storage : public ObjectStorage <bhkRigidBodyT> {};
	class bhkConstraint : public BasicNode, public Niflib::bhkConstraint {};
	class bhkConstraint_Storage : public ObjectStorage <bhkConstraint> {};
	class bhkLimitedHingeConstraint : public BasicNode, public Niflib::bhkLimitedHingeConstraint {};
	class bhkLimitedHingeConstraint_Storage : public ObjectStorage <bhkLimitedHingeConstraint> {};
	class bhkMalleableConstraint : public BasicNode, public Niflib::bhkMalleableConstraint {};
	class bhkMalleableConstraint_Storage : public ObjectStorage <bhkMalleableConstraint> {};
	class bhkStiffSpringConstraint : public BasicNode, public Niflib::bhkStiffSpringConstraint {};
	class bhkStiffSpringConstraint_Storage : public ObjectStorage <bhkStiffSpringConstraint> {};
	class bhkRagdollConstraint : public BasicNode, public Niflib::bhkRagdollConstraint {};
	class bhkRagdollConstraint_Storage : public ObjectStorage <bhkRagdollConstraint> {};
	class bhkPrismaticConstraint : public BasicNode, public Niflib::bhkPrismaticConstraint {};
	class bhkPrismaticConstraint_Storage : public ObjectStorage <bhkPrismaticConstraint> {};
	class bhkHingeConstraint : public BasicNode, public Niflib::bhkHingeConstraint {};
	class bhkHingeConstraint_Storage : public ObjectStorage <bhkHingeConstraint> {};
	class bhkBallAndSocketConstraint : public BasicNode, public Niflib::bhkBallAndSocketConstraint {};
	class bhkBallAndSocketConstraint_Storage : public ObjectStorage <bhkBallAndSocketConstraint> {};
	class bhkBallSocketConstraintChain : public BasicNode, public Niflib::bhkBallSocketConstraintChain {};
	class bhkBallSocketConstraintChain_Storage : public ObjectStorage <bhkBallSocketConstraintChain> {};
	class bhkShape : public BasicNode, public Niflib::bhkShape {};
	class bhkShape_Storage : public ObjectStorage <bhkShape> {};
	class bhkTransformShape : public BasicNode, public Niflib::bhkTransformShape {};
	class bhkTransformShape_Storage : public ObjectStorage <bhkTransformShape> {};
	class bhkSphereRepShape : public BasicNode, public Niflib::bhkSphereRepShape {};
	class bhkSphereRepShape_Storage : public ObjectStorage <bhkSphereRepShape> {};
	class bhkConvexShape : public BasicNode, public Niflib::bhkConvexShape {};
	class bhkConvexShape_Storage : public ObjectStorage <bhkConvexShape> {};
	class bhkSphereShape : public BasicNode, public Niflib::bhkSphereShape {};
	class bhkSphereShape_Storage : public ObjectStorage <bhkSphereShape> {};
	class bhkCapsuleShape : public BasicNode, public Niflib::bhkCapsuleShape {};
	class bhkCapsuleShape_Storage : public ObjectStorage <bhkCapsuleShape> {};
	class bhkBoxShape : public BasicNode, public Niflib::bhkBoxShape {};
	class bhkBoxShape_Storage : public ObjectStorage <bhkBoxShape> {};
	class bhkConvexVerticesShape : public BasicNode, public Niflib::bhkConvexVerticesShape {};
	class bhkConvexVerticesShape_Storage : public ObjectStorage <bhkConvexVerticesShape> {};
	class bhkConvexTransformShape : public BasicNode, public Niflib::bhkConvexTransformShape {};
	class bhkConvexTransformShape_Storage : public ObjectStorage <bhkConvexTransformShape> {};
	class bhkMultiSphereShape : public BasicNode, public Niflib::bhkMultiSphereShape {};
	class bhkMultiSphereShape_Storage : public ObjectStorage <bhkMultiSphereShape> {};
	class bhkBvTreeShape : public BasicNode, public Niflib::bhkBvTreeShape {};
	class bhkBvTreeShape_Storage : public ObjectStorage <bhkBvTreeShape> {};
	class bhkMoppBvTreeShape : public BasicNode, public Niflib::bhkMoppBvTreeShape {};
	class bhkMoppBvTreeShape_Storage : public ObjectStorage <bhkMoppBvTreeShape> {};
	class bhkShapeCollection : public BasicNode, public Niflib::bhkShapeCollection {};
	class bhkShapeCollection_Storage : public ObjectStorage <bhkShapeCollection> {};
	class bhkListShape : public BasicNode, public Niflib::bhkListShape {};
	class bhkListShape_Storage : public ObjectStorage <bhkListShape> {};
	class bhkMeshShape : public BasicNode, public Niflib::bhkMeshShape {};
	class bhkMeshShape_Storage : public ObjectStorage <bhkMeshShape> {};
	class bhkPackedNiTriStripsShape : public BasicNode, public Niflib::bhkPackedNiTriStripsShape {};
	class bhkPackedNiTriStripsShape_Storage : public ObjectStorage <bhkPackedNiTriStripsShape> {};
	class bhkNiTriStripsShape : public BasicNode, public Niflib::bhkNiTriStripsShape {};
	class bhkNiTriStripsShape_Storage : public ObjectStorage <bhkNiTriStripsShape> {};
	class NiExtraData : public BasicNode, public Niflib::NiExtraData {};
	class NiExtraData_Storage : public ObjectStorage <NiExtraData> {};
	class NiInterpolator : public BasicNode, public Niflib::NiInterpolator {};
	class NiInterpolator_Storage : public ObjectStorage <NiInterpolator> {};
	class NiKeyBasedInterpolator : public BasicNode, public Niflib::NiKeyBasedInterpolator {};
	class NiKeyBasedInterpolator_Storage : public ObjectStorage <NiKeyBasedInterpolator> {};
	class NiFloatInterpolator : public BasicNode, public Niflib::NiFloatInterpolator {};
	class NiFloatInterpolator_Storage : public ObjectStorage <NiFloatInterpolator> {};
	class NiTransformInterpolator : public BasicNode, public Niflib::NiTransformInterpolator {};
	class NiTransformInterpolator_Storage : public ObjectStorage <NiTransformInterpolator> {};
	class NiPoint3Interpolator : public BasicNode, public Niflib::NiPoint3Interpolator {};
	class NiPoint3Interpolator_Storage : public ObjectStorage <NiPoint3Interpolator> {};
	class NiPathInterpolator : public BasicNode, public Niflib::NiPathInterpolator {};
	class NiPathInterpolator_Storage : public ObjectStorage <NiPathInterpolator> {};
	class NiBoolInterpolator : public BasicNode, public Niflib::NiBoolInterpolator {};
	class NiBoolInterpolator_Storage : public ObjectStorage <NiBoolInterpolator> {};
	class NiBoolTimelineInterpolator : public BasicNode, public Niflib::NiBoolTimelineInterpolator {};
	class NiBoolTimelineInterpolator_Storage : public ObjectStorage <NiBoolTimelineInterpolator> {};
	class NiBlendInterpolator : public BasicNode, public Niflib::NiBlendInterpolator {};
	class NiBlendInterpolator_Storage : public ObjectStorage <NiBlendInterpolator> {};
	class NiBSplineInterpolator : public BasicNode, public Niflib::NiBSplineInterpolator {};
	class NiBSplineInterpolator_Storage : public ObjectStorage <NiBSplineInterpolator> {};
	class NiObjectNET : public BasicNode, public Niflib::NiObjectNET {};
	class NiObjectNET_Storage : public ObjectStorage <NiObjectNET> {};
	class NiCollisionObject : public BasicNode, public Niflib::NiCollisionObject {};
	class NiCollisionObject_Storage : public ObjectStorage <NiCollisionObject> {};
	class NiCollisionData : public BasicNode, public Niflib::NiCollisionData {};
	class NiCollisionData_Storage : public ObjectStorage <NiCollisionData> {};
	class bhkNiCollisionObject : public BasicNode, public Niflib::bhkNiCollisionObject {};
	class bhkNiCollisionObject_Storage : public ObjectStorage <bhkNiCollisionObject> {};
	class bhkCollisionObject : public BasicNode, public Niflib::bhkCollisionObject {};
	class bhkCollisionObject_Storage : public ObjectStorage <bhkCollisionObject> {};
	class bhkBlendCollisionObject : public BasicNode, public Niflib::bhkBlendCollisionObject {};
	class bhkBlendCollisionObject_Storage : public ObjectStorage <bhkBlendCollisionObject> {};
	class bhkPCollisionObject : public BasicNode, public Niflib::bhkPCollisionObject {};
	class bhkPCollisionObject_Storage : public ObjectStorage <bhkPCollisionObject> {};
	class bhkSPCollisionObject : public BasicNode, public Niflib::bhkSPCollisionObject {};
	class bhkSPCollisionObject_Storage : public ObjectStorage <bhkSPCollisionObject> {};
	class NiAVObject : public BasicNode, public Niflib::NiAVObject {};
	class NiAVObject_Storage : public ObjectStorage <NiAVObject> {};
	class NiDynamicEffect : public BasicNode, public Niflib::NiDynamicEffect {};
	class NiDynamicEffect_Storage : public ObjectStorage <NiDynamicEffect> {};
	class NiLight : public BasicNode, public Niflib::NiLight {};
	class NiLight_Storage : public ObjectStorage <NiLight> {};
	class NiProperty : public BasicNode, public Niflib::NiProperty {};
	class NiProperty_Storage : public ObjectStorage <NiProperty> {};
	class NiTransparentProperty : public BasicNode, public Niflib::NiTransparentProperty {};
	class NiTransparentProperty_Storage : public ObjectStorage <NiTransparentProperty> {};
	class NiPSysModifier : public BasicNode, public Niflib::NiPSysModifier {};
	class NiPSysModifier_Storage : public ObjectStorage <NiPSysModifier> {};
	class NiPSysEmitter : public BasicNode, public Niflib::NiPSysEmitter {};
	class NiPSysEmitter_Storage : public ObjectStorage <NiPSysEmitter> {};
	class NiPSysVolumeEmitter : public BasicNode, public Niflib::NiPSysVolumeEmitter {};
	class NiPSysVolumeEmitter_Storage : public ObjectStorage <NiPSysVolumeEmitter> {};
	class NiTimeController : public BasicNode, public Niflib::NiTimeController {};
	class NiTimeController_Storage : public ObjectStorage <NiTimeController> {};
	class NiInterpController : public BasicNode, public Niflib::NiInterpController {};
	class NiInterpController_Storage : public ObjectStorage <NiInterpController> {};
	class NiMultiTargetTransformController : public BasicNode, public Niflib::NiMultiTargetTransformController {};
	class NiMultiTargetTransformController_Storage : public ObjectStorage <NiMultiTargetTransformController> {};
	class NiGeomMorpherController : public BasicNode, public Niflib::NiGeomMorpherController {};
	class NiGeomMorpherController_Storage : public ObjectStorage <NiGeomMorpherController> {};
	class NiMorphController : public BasicNode, public Niflib::NiMorphController {};
	class NiMorphController_Storage : public ObjectStorage <NiMorphController> {};
	class NiMorpherController : public BasicNode, public Niflib::NiMorpherController {};
	class NiMorpherController_Storage : public ObjectStorage <NiMorpherController> {};
	class NiSingleInterpController : public BasicNode, public Niflib::NiSingleInterpController {};
	class NiSingleInterpController_Storage : public ObjectStorage <NiSingleInterpController> {};
	class NiKeyframeController : public BasicNode, public Niflib::NiKeyframeController {};
	class NiKeyframeController_Storage : public ObjectStorage <NiKeyframeController> {};
	class NiTransformController : public BasicNode, public Niflib::NiTransformController {};
	class NiTransformController_Storage : public ObjectStorage <NiTransformController> {};
	class NiPSysModifierCtlr : public BasicNode, public Niflib::NiPSysModifierCtlr {};
	class NiPSysModifierCtlr_Storage : public ObjectStorage <NiPSysModifierCtlr> {};
	class NiPSysEmitterCtlr : public BasicNode, public Niflib::NiPSysEmitterCtlr {};
	class NiPSysEmitterCtlr_Storage : public ObjectStorage <NiPSysEmitterCtlr> {};
	class NiPSysModifierBoolCtlr : public BasicNode, public Niflib::NiPSysModifierBoolCtlr {};
	class NiPSysModifierBoolCtlr_Storage : public ObjectStorage <NiPSysModifierBoolCtlr> {};
	class NiPSysModifierActiveCtlr : public BasicNode, public Niflib::NiPSysModifierActiveCtlr {};
	class NiPSysModifierActiveCtlr_Storage : public ObjectStorage <NiPSysModifierActiveCtlr> {};
	class NiPSysModifierFloatCtlr : public BasicNode, public Niflib::NiPSysModifierFloatCtlr {};
	class NiPSysModifierFloatCtlr_Storage : public ObjectStorage <NiPSysModifierFloatCtlr> {};
	class NiPSysEmitterDeclinationCtlr : public BasicNode, public Niflib::NiPSysEmitterDeclinationCtlr {};
	class NiPSysEmitterDeclinationCtlr_Storage : public ObjectStorage <NiPSysEmitterDeclinationCtlr> {};
	class NiPSysEmitterDeclinationVarCtlr : public BasicNode, public Niflib::NiPSysEmitterDeclinationVarCtlr {};
	class NiPSysEmitterDeclinationVarCtlr_Storage : public ObjectStorage <NiPSysEmitterDeclinationVarCtlr> {};
	class NiPSysEmitterInitialRadiusCtlr : public BasicNode, public Niflib::NiPSysEmitterInitialRadiusCtlr {};
	class NiPSysEmitterInitialRadiusCtlr_Storage : public ObjectStorage <NiPSysEmitterInitialRadiusCtlr> {};
	class NiPSysEmitterLifeSpanCtlr : public BasicNode, public Niflib::NiPSysEmitterLifeSpanCtlr {};
	class NiPSysEmitterLifeSpanCtlr_Storage : public ObjectStorage <NiPSysEmitterLifeSpanCtlr> {};
	class NiPSysEmitterSpeedCtlr : public BasicNode, public Niflib::NiPSysEmitterSpeedCtlr {};
	class NiPSysEmitterSpeedCtlr_Storage : public ObjectStorage <NiPSysEmitterSpeedCtlr> {};
	class NiPSysGravityStrengthCtlr : public BasicNode, public Niflib::NiPSysGravityStrengthCtlr {};
	class NiPSysGravityStrengthCtlr_Storage : public ObjectStorage <NiPSysGravityStrengthCtlr> {};
	class NiFloatInterpController : public BasicNode, public Niflib::NiFloatInterpController {};
	class NiFloatInterpController_Storage : public ObjectStorage <NiFloatInterpController> {};
	class NiFlipController : public BasicNode, public Niflib::NiFlipController {};
	class NiFlipController_Storage : public ObjectStorage <NiFlipController> {};
	class NiAlphaController : public BasicNode, public Niflib::NiAlphaController {};
	class NiAlphaController_Storage : public ObjectStorage <NiAlphaController> {};
	class NiTextureTransformController : public BasicNode, public Niflib::NiTextureTransformController {};
	class NiTextureTransformController_Storage : public ObjectStorage <NiTextureTransformController> {};
	class NiLightDimmerController : public BasicNode, public Niflib::NiLightDimmerController {};
	class NiLightDimmerController_Storage : public ObjectStorage <NiLightDimmerController> {};
	class NiBoolInterpController : public BasicNode, public Niflib::NiBoolInterpController {};
	class NiBoolInterpController_Storage : public ObjectStorage <NiBoolInterpController> {};
	class NiVisController : public BasicNode, public Niflib::NiVisController {};
	class NiVisController_Storage : public ObjectStorage <NiVisController> {};
	class NiPoint3InterpController : public BasicNode, public Niflib::NiPoint3InterpController {};
	class NiPoint3InterpController_Storage : public ObjectStorage <NiPoint3InterpController> {};
	class NiMaterialColorController : public BasicNode, public Niflib::NiMaterialColorController {};
	class NiMaterialColorController_Storage : public ObjectStorage <NiMaterialColorController> {};
	class NiLightColorController : public BasicNode, public Niflib::NiLightColorController {};
	class NiLightColorController_Storage : public ObjectStorage <NiLightColorController> {};
	class NiExtraDataController : public BasicNode, public Niflib::NiExtraDataController {};
	class NiExtraDataController_Storage : public ObjectStorage <NiExtraDataController> {};
	class NiFloatExtraDataController : public BasicNode, public Niflib::NiFloatExtraDataController {};
	class NiFloatExtraDataController_Storage : public ObjectStorage <NiFloatExtraDataController> {};
	class NiBoneLODController : public BasicNode, public Niflib::NiBoneLODController {};
	class NiBoneLODController_Storage : public ObjectStorage <NiBoneLODController> {};
	class NiBSBoneLODController : public BasicNode, public Niflib::NiBSBoneLODController {};
	class NiBSBoneLODController_Storage : public ObjectStorage <NiBSBoneLODController> {};
	class NiGeometry : public BasicNode, public Niflib::NiGeometry {};
	class NiGeometry_Storage : public ObjectStorage <NiGeometry> {};
	class NiTriBasedGeom : public BasicNode, public Niflib::NiTriBasedGeom {};
	class NiTriBasedGeom_Storage : public ObjectStorage <NiTriBasedGeom> {};
	class NiGeometryData : public BasicNode, public Niflib::NiGeometryData {};
	class NiGeometryData_Storage : public ObjectStorage <NiGeometryData> {};
	class AbstractAdditionalGeometryData : public BasicNode, public Niflib::AbstractAdditionalGeometryData {};
	class AbstractAdditionalGeometryData_Storage : public ObjectStorage <AbstractAdditionalGeometryData> {};
	class NiTriBasedGeomData : public BasicNode, public Niflib::NiTriBasedGeomData {};
	class NiTriBasedGeomData_Storage : public ObjectStorage <NiTriBasedGeomData> {};
	class bhkBlendController : public BasicNode, public Niflib::bhkBlendController {};
	class bhkBlendController_Storage : public ObjectStorage <bhkBlendController> {};
	class BSBound : public BasicNode, public Niflib::BSBound {};
	class BSBound_Storage : public ObjectStorage <BSBound> {};
	class BSFurnitureMarker : public BasicNode, public Niflib::BSFurnitureMarker {};
	class BSFurnitureMarker_Storage : public ObjectStorage <BSFurnitureMarker> {};
	class BSParentVelocityModifier : public BasicNode, public Niflib::BSParentVelocityModifier {};
	class BSParentVelocityModifier_Storage : public ObjectStorage <BSParentVelocityModifier> {};
	class BSPSysArrayEmitter : public BasicNode, public Niflib::BSPSysArrayEmitter {};
	class BSPSysArrayEmitter_Storage : public ObjectStorage <BSPSysArrayEmitter> {};
	class BSWindModifier : public BasicNode, public Niflib::BSWindModifier {};
	class BSWindModifier_Storage : public ObjectStorage <BSWindModifier> {};
	class hkPackedNiTriStripsData : public BasicNode, public Niflib::hkPackedNiTriStripsData {};
	class hkPackedNiTriStripsData_Storage : public ObjectStorage <hkPackedNiTriStripsData> {};
	class NiAlphaProperty : public BasicNode, public Niflib::NiAlphaProperty {};
	class NiAlphaProperty_Storage : public ObjectStorage <NiAlphaProperty> {};
	class NiAmbientLight : public BasicNode, public Niflib::NiAmbientLight {};
	class NiAmbientLight_Storage : public ObjectStorage <NiAmbientLight> {};
	class NiParticlesData : public BasicNode, public Niflib::NiParticlesData {};
	class NiParticlesData_Storage : public ObjectStorage <NiParticlesData> {};
	class NiRotatingParticlesData : public BasicNode, public Niflib::NiRotatingParticlesData {};
	class NiRotatingParticlesData_Storage : public ObjectStorage <NiRotatingParticlesData> {};
	class NiAutoNormalParticlesData : public BasicNode, public Niflib::NiAutoNormalParticlesData {};
	class NiAutoNormalParticlesData_Storage : public ObjectStorage <NiAutoNormalParticlesData> {};
	class NiPSysData : public BasicNode, public Niflib::NiPSysData {};
	class NiPSysData_Storage : public ObjectStorage <NiPSysData> {};
	class NiMeshPSysData : public BasicNode, public Niflib::NiMeshPSysData {};
	class NiMeshPSysData_Storage : public ObjectStorage <NiMeshPSysData> {};
	class NiBinaryExtraData : public BasicNode, public Niflib::NiBinaryExtraData {};
	class NiBinaryExtraData_Storage : public ObjectStorage <NiBinaryExtraData> {};
	class NiBinaryVoxelExtraData : public BasicNode, public Niflib::NiBinaryVoxelExtraData {};
	class NiBinaryVoxelExtraData_Storage : public ObjectStorage <NiBinaryVoxelExtraData> {};
	class NiBinaryVoxelData : public BasicNode, public Niflib::NiBinaryVoxelData {};
	class NiBinaryVoxelData_Storage : public ObjectStorage <NiBinaryVoxelData> {};
	class NiBlendBoolInterpolator : public BasicNode, public Niflib::NiBlendBoolInterpolator {};
	class NiBlendBoolInterpolator_Storage : public ObjectStorage <NiBlendBoolInterpolator> {};
	class NiBlendFloatInterpolator : public BasicNode, public Niflib::NiBlendFloatInterpolator {};
	class NiBlendFloatInterpolator_Storage : public ObjectStorage <NiBlendFloatInterpolator> {};
	class NiBlendPoint3Interpolator : public BasicNode, public Niflib::NiBlendPoint3Interpolator {};
	class NiBlendPoint3Interpolator_Storage : public ObjectStorage <NiBlendPoint3Interpolator> {};
	class NiBlendTransformInterpolator : public BasicNode, public Niflib::NiBlendTransformInterpolator {};
	class NiBlendTransformInterpolator_Storage : public ObjectStorage <NiBlendTransformInterpolator> {};
	class NiBoolData : public BasicNode, public Niflib::NiBoolData {};
	class NiBoolData_Storage : public ObjectStorage <NiBoolData> {};
	class NiBooleanExtraData : public BasicNode, public Niflib::NiBooleanExtraData {};
	class NiBooleanExtraData_Storage : public ObjectStorage <NiBooleanExtraData> {};
	class NiBSplineBasisData : public BasicNode, public Niflib::NiBSplineBasisData {};
	class NiBSplineBasisData_Storage : public ObjectStorage <NiBSplineBasisData> {};
	class NiBSplineFloatInterpolator : public BasicNode, public Niflib::NiBSplineFloatInterpolator {};
	class NiBSplineFloatInterpolator_Storage : public ObjectStorage <NiBSplineFloatInterpolator> {};
	class NiBSplineCompFloatInterpolator : public BasicNode, public Niflib::NiBSplineCompFloatInterpolator {};
	class NiBSplineCompFloatInterpolator_Storage : public ObjectStorage <NiBSplineCompFloatInterpolator> {};
	class NiBSplinePoint3Interpolator : public BasicNode, public Niflib::NiBSplinePoint3Interpolator {};
	class NiBSplinePoint3Interpolator_Storage : public ObjectStorage <NiBSplinePoint3Interpolator> {};
	class NiBSplineCompPoint3Interpolator : public BasicNode, public Niflib::NiBSplineCompPoint3Interpolator {};
	class NiBSplineCompPoint3Interpolator_Storage : public ObjectStorage <NiBSplineCompPoint3Interpolator> {};
	class NiBSplineTransformInterpolator : public BasicNode, public Niflib::NiBSplineTransformInterpolator {};
	class NiBSplineTransformInterpolator_Storage : public ObjectStorage <NiBSplineTransformInterpolator> {};
	class NiBSplineCompTransformInterpolator : public BasicNode, public Niflib::NiBSplineCompTransformInterpolator {};
	class NiBSplineCompTransformInterpolator_Storage : public ObjectStorage <NiBSplineCompTransformInterpolator> {};
	class BSRotAccumTransfInterpolator : public BasicNode, public Niflib::BSRotAccumTransfInterpolator {};
	class BSRotAccumTransfInterpolator_Storage : public ObjectStorage <BSRotAccumTransfInterpolator> {};
	class NiBSplineData : public BasicNode, public Niflib::NiBSplineData {};
	class NiBSplineData_Storage : public ObjectStorage <NiBSplineData> {};
	class NiCamera : public BasicNode, public Niflib::NiCamera {};
	class NiCamera_Storage : public ObjectStorage <NiCamera> {};
	class NiColorData : public BasicNode, public Niflib::NiColorData {};
	class NiColorData_Storage : public ObjectStorage <NiColorData> {};
	class NiColorExtraData : public BasicNode, public Niflib::NiColorExtraData {};
	class NiColorExtraData_Storage : public ObjectStorage <NiColorExtraData> {};
	class NiControllerManager : public BasicNode, public Niflib::NiControllerManager {};
	class NiControllerManager_Storage : public ObjectStorage <NiControllerManager> {};
	class NiSequence : public BasicNode, public Niflib::NiSequence {};
	class NiSequence_Storage : public ObjectStorage <NiSequence> {};
	class NiControllerSequence : public BasicNode, public Niflib::NiControllerSequence {};
	class NiControllerSequence_Storage : public ObjectStorage <NiControllerSequence> {};
	class NiAVObjectPalette : public BasicNode, public Niflib::NiAVObjectPalette {};
	class NiAVObjectPalette_Storage : public ObjectStorage <NiAVObjectPalette> {};
	class NiDefaultAVObjectPalette : public BasicNode, public Niflib::NiDefaultAVObjectPalette {};
	class NiDefaultAVObjectPalette_Storage : public ObjectStorage <NiDefaultAVObjectPalette> {};
	class NiDirectionalLight : public BasicNode, public Niflib::NiDirectionalLight {};
	class NiDirectionalLight_Storage : public ObjectStorage <NiDirectionalLight> {};
	class NiDitherProperty : public BasicNode, public Niflib::NiDitherProperty {};
	class NiDitherProperty_Storage : public ObjectStorage <NiDitherProperty> {};
	class NiRollController : public BasicNode, public Niflib::NiRollController {};
	class NiRollController_Storage : public ObjectStorage <NiRollController> {};
	class NiFloatData : public BasicNode, public Niflib::NiFloatData {};
	class NiFloatData_Storage : public ObjectStorage <NiFloatData> {};
	class NiFloatExtraData : public BasicNode, public Niflib::NiFloatExtraData {};
	class NiFloatExtraData_Storage : public ObjectStorage <NiFloatExtraData> {};
	class NiFloatsExtraData : public BasicNode, public Niflib::NiFloatsExtraData {};
	class NiFloatsExtraData_Storage : public ObjectStorage <NiFloatsExtraData> {};
	class NiFogProperty : public BasicNode, public Niflib::NiFogProperty {};
	class NiFogProperty_Storage : public ObjectStorage <NiFogProperty> {};
	class NiGravity : public BasicNode, public Niflib::NiGravity {};
	class NiGravity_Storage : public ObjectStorage <NiGravity> {};
	class NiIntegerExtraData : public BasicNode, public Niflib::NiIntegerExtraData {};
	class NiIntegerExtraData_Storage : public ObjectStorage <NiIntegerExtraData> {};
	class BSXFlags : public BasicNode, public Niflib::BSXFlags {};
	class BSXFlags_Storage : public ObjectStorage <BSXFlags> {};
	class NiIntegersExtraData : public BasicNode, public Niflib::NiIntegersExtraData {};
	class NiIntegersExtraData_Storage : public ObjectStorage <NiIntegersExtraData> {};
	class BSKeyframeController : public BasicNode, public Niflib::BSKeyframeController {};
	class BSKeyframeController_Storage : public ObjectStorage <BSKeyframeController> {};
	class NiKeyframeData : public BasicNode, public Niflib::NiKeyframeData {};
	class NiKeyframeData_Storage : public ObjectStorage <NiKeyframeData> {};
	class NiLookAtController : public BasicNode, public Niflib::NiLookAtController {};
	class NiLookAtController_Storage : public ObjectStorage <NiLookAtController> {};
	class NiLookAtInterpolator : public BasicNode, public Niflib::NiLookAtInterpolator {};
	class NiLookAtInterpolator_Storage : public ObjectStorage <NiLookAtInterpolator> {};
	class NiMaterialProperty : public BasicNode, public Niflib::NiMaterialProperty {};
	class NiMaterialProperty_Storage : public ObjectStorage <NiMaterialProperty> {};
	class NiMorphData : public BasicNode, public Niflib::NiMorphData {};
	class NiMorphData_Storage : public ObjectStorage <NiMorphData> {};
	class NiNode : public BasicNode, public Niflib::NiNode {};
	class NiNode_Storage : public ObjectStorage <NiNode> {};
	class NiBone : public BasicNode, public Niflib::NiBone {};
	class NiBone_Storage : public ObjectStorage <NiBone> {};
	class AvoidNode : public BasicNode, public Niflib::AvoidNode {};
	class AvoidNode_Storage : public ObjectStorage <AvoidNode> {};
	class FxWidget : public BasicNode, public Niflib::FxWidget {};
	class FxWidget_Storage : public ObjectStorage <FxWidget> {};
	class FxButton : public BasicNode, public Niflib::FxButton {};
	class FxButton_Storage : public ObjectStorage <FxButton> {};
	class FxRadioButton : public BasicNode, public Niflib::FxRadioButton {};
	class FxRadioButton_Storage : public ObjectStorage <FxRadioButton> {};
	class NiBillboardNode : public BasicNode, public Niflib::NiBillboardNode {};
	class NiBillboardNode_Storage : public ObjectStorage <NiBillboardNode> {};
	class NiBSAnimationNode : public BasicNode, public Niflib::NiBSAnimationNode {};
	class NiBSAnimationNode_Storage : public ObjectStorage <NiBSAnimationNode> {};
	class NiBSParticleNode : public BasicNode, public Niflib::NiBSParticleNode {};
	class NiBSParticleNode_Storage : public ObjectStorage <NiBSParticleNode> {};
	class NiSwitchNode : public BasicNode, public Niflib::NiSwitchNode {};
	class NiSwitchNode_Storage : public ObjectStorage <NiSwitchNode> {};
	class NiLODNode : public BasicNode, public Niflib::NiLODNode {};
	class NiLODNode_Storage : public ObjectStorage <NiLODNode> {};
	class NiPalette : public BasicNode, public Niflib::NiPalette {};
	class NiPalette_Storage : public ObjectStorage <NiPalette> {};
	class NiParticleBomb : public BasicNode, public Niflib::NiParticleBomb {};
	class NiParticleBomb_Storage : public ObjectStorage <NiParticleBomb> {};
	class NiParticleColorModifier : public BasicNode, public Niflib::NiParticleColorModifier {};
	class NiParticleColorModifier_Storage : public ObjectStorage <NiParticleColorModifier> {};
	class NiParticleGrowFade : public BasicNode, public Niflib::NiParticleGrowFade {};
	class NiParticleGrowFade_Storage : public ObjectStorage <NiParticleGrowFade> {};
	class NiParticleMeshModifier : public BasicNode, public Niflib::NiParticleMeshModifier {};
	class NiParticleMeshModifier_Storage : public ObjectStorage <NiParticleMeshModifier> {};
	class NiParticleRotation : public BasicNode, public Niflib::NiParticleRotation {};
	class NiParticleRotation_Storage : public ObjectStorage <NiParticleRotation> {};
	class NiParticles : public BasicNode, public Niflib::NiParticles {};
	class NiParticles_Storage : public ObjectStorage <NiParticles> {};
	class NiAutoNormalParticles : public BasicNode, public Niflib::NiAutoNormalParticles {};
	class NiAutoNormalParticles_Storage : public ObjectStorage <NiAutoNormalParticles> {};
	class NiParticleMeshes : public BasicNode, public Niflib::NiParticleMeshes {};
	class NiParticleMeshes_Storage : public ObjectStorage <NiParticleMeshes> {};
	class NiParticleMeshesData : public BasicNode, public Niflib::NiParticleMeshesData {};
	class NiParticleMeshesData_Storage : public ObjectStorage <NiParticleMeshesData> {};
	class NiParticleSystem : public BasicNode, public Niflib::NiParticleSystem {};
	class NiParticleSystem_Storage : public ObjectStorage <NiParticleSystem> {};
	class NiMeshParticleSystem : public BasicNode, public Niflib::NiMeshParticleSystem {};
	class NiMeshParticleSystem_Storage : public ObjectStorage <NiMeshParticleSystem> {};
	class NiParticleSystemController : public BasicNode, public Niflib::NiParticleSystemController {};
	class NiParticleSystemController_Storage : public ObjectStorage <NiParticleSystemController> {};
	class NiBSPArrayController : public BasicNode, public Niflib::NiBSPArrayController {};
	class NiBSPArrayController_Storage : public ObjectStorage <NiBSPArrayController> {};
	class NiPathController : public BasicNode, public Niflib::NiPathController {};
	class NiPathController_Storage : public ObjectStorage <NiPathController> {};
	class ATextureRenderData : public BasicNode, public Niflib::ATextureRenderData {};
	class ATextureRenderData_Storage : public ObjectStorage <ATextureRenderData> {};
	class NiPersistentSrcTextureRendererData : public BasicNode, public Niflib::NiPersistentSrcTextureRendererData {};
	class NiPersistentSrcTextureRendererData_Storage : public ObjectStorage <NiPersistentSrcTextureRendererData> {};
	class NiPixelData : public BasicNode, public Niflib::NiPixelData {};
	class NiPixelData_Storage : public ObjectStorage <NiPixelData> {};
	class NiPlanarCollider : public BasicNode, public Niflib::NiPlanarCollider {};
	class NiPlanarCollider_Storage : public ObjectStorage <NiPlanarCollider> {};
	class NiPointLight : public BasicNode, public Niflib::NiPointLight {};
	class NiPointLight_Storage : public ObjectStorage <NiPointLight> {};
	class NiPosData : public BasicNode, public Niflib::NiPosData {};
	class NiPosData_Storage : public ObjectStorage <NiPosData> {};
	class NiPSysAgeDeathModifier : public BasicNode, public Niflib::NiPSysAgeDeathModifier {};
	class NiPSysAgeDeathModifier_Storage : public ObjectStorage <NiPSysAgeDeathModifier> {};
	class NiPSysBombModifier : public BasicNode, public Niflib::NiPSysBombModifier {};
	class NiPSysBombModifier_Storage : public ObjectStorage <NiPSysBombModifier> {};
	class NiPSysBoundUpdateModifier : public BasicNode, public Niflib::NiPSysBoundUpdateModifier {};
	class NiPSysBoundUpdateModifier_Storage : public ObjectStorage <NiPSysBoundUpdateModifier> {};
	class NiPSysBoxEmitter : public BasicNode, public Niflib::NiPSysBoxEmitter {};
	class NiPSysBoxEmitter_Storage : public ObjectStorage <NiPSysBoxEmitter> {};
	class NiPSysColliderManager : public BasicNode, public Niflib::NiPSysColliderManager {};
	class NiPSysColliderManager_Storage : public ObjectStorage <NiPSysColliderManager> {};
	class NiPSysColorModifier : public BasicNode, public Niflib::NiPSysColorModifier {};
	class NiPSysColorModifier_Storage : public ObjectStorage <NiPSysColorModifier> {};
	class NiPSysCylinderEmitter : public BasicNode, public Niflib::NiPSysCylinderEmitter {};
	class NiPSysCylinderEmitter_Storage : public ObjectStorage <NiPSysCylinderEmitter> {};
	class NiPSysDragModifier : public BasicNode, public Niflib::NiPSysDragModifier {};
	class NiPSysDragModifier_Storage : public ObjectStorage <NiPSysDragModifier> {};
	class NiPSysEmitterCtlrData : public BasicNode, public Niflib::NiPSysEmitterCtlrData {};
	class NiPSysEmitterCtlrData_Storage : public ObjectStorage <NiPSysEmitterCtlrData> {};
	class NiPSysGravityModifier : public BasicNode, public Niflib::NiPSysGravityModifier {};
	class NiPSysGravityModifier_Storage : public ObjectStorage <NiPSysGravityModifier> {};
	class NiPSysGrowFadeModifier : public BasicNode, public Niflib::NiPSysGrowFadeModifier {};
	class NiPSysGrowFadeModifier_Storage : public ObjectStorage <NiPSysGrowFadeModifier> {};
	class NiPSysMeshEmitter : public BasicNode, public Niflib::NiPSysMeshEmitter {};
	class NiPSysMeshEmitter_Storage : public ObjectStorage <NiPSysMeshEmitter> {};
	class NiPSysMeshUpdateModifier : public BasicNode, public Niflib::NiPSysMeshUpdateModifier {};
	class NiPSysMeshUpdateModifier_Storage : public ObjectStorage <NiPSysMeshUpdateModifier> {};
	class BSPSysInheritVelocityModifier : public BasicNode, public Niflib::BSPSysInheritVelocityModifier {};
	class BSPSysInheritVelocityModifier_Storage : public ObjectStorage <BSPSysInheritVelocityModifier> {};
	class BSPSysHavokUpdateModifier : public BasicNode, public Niflib::BSPSysHavokUpdateModifier {};
	class BSPSysHavokUpdateModifier_Storage : public ObjectStorage <BSPSysHavokUpdateModifier> {};
	class BSPSysRecycleBoundModifier : public BasicNode, public Niflib::BSPSysRecycleBoundModifier {};
	class BSPSysRecycleBoundModifier_Storage : public ObjectStorage <BSPSysRecycleBoundModifier> {};
	class BSPSysSubTexModifier : public BasicNode, public Niflib::BSPSysSubTexModifier {};
	class BSPSysSubTexModifier_Storage : public ObjectStorage <BSPSysSubTexModifier> {};
	class NiPSysPlanarCollider : public BasicNode, public Niflib::NiPSysPlanarCollider {};
	class NiPSysPlanarCollider_Storage : public ObjectStorage <NiPSysPlanarCollider> {};
	class NiPSysSphericalCollider : public BasicNode, public Niflib::NiPSysSphericalCollider {};
	class NiPSysSphericalCollider_Storage : public ObjectStorage <NiPSysSphericalCollider> {};
	class NiPSysPositionModifier : public BasicNode, public Niflib::NiPSysPositionModifier {};
	class NiPSysPositionModifier_Storage : public ObjectStorage <NiPSysPositionModifier> {};
	class NiPSysResetOnLoopCtlr : public BasicNode, public Niflib::NiPSysResetOnLoopCtlr {};
	class NiPSysResetOnLoopCtlr_Storage : public ObjectStorage <NiPSysResetOnLoopCtlr> {};
	class NiPSysRotationModifier : public BasicNode, public Niflib::NiPSysRotationModifier {};
	class NiPSysRotationModifier_Storage : public ObjectStorage <NiPSysRotationModifier> {};
	class NiPSysSpawnModifier : public BasicNode, public Niflib::NiPSysSpawnModifier {};
	class NiPSysSpawnModifier_Storage : public ObjectStorage <NiPSysSpawnModifier> {};
	class NiPSysSphereEmitter : public BasicNode, public Niflib::NiPSysSphereEmitter {};
	class NiPSysSphereEmitter_Storage : public ObjectStorage <NiPSysSphereEmitter> {};
	class NiPSysUpdateCtlr : public BasicNode, public Niflib::NiPSysUpdateCtlr {};
	class NiPSysUpdateCtlr_Storage : public ObjectStorage <NiPSysUpdateCtlr> {};
	class NiPSysFieldModifier : public BasicNode, public Niflib::NiPSysFieldModifier {};
	class NiPSysFieldModifier_Storage : public ObjectStorage <NiPSysFieldModifier> {};
	class NiPSysVortexFieldModifier : public BasicNode, public Niflib::NiPSysVortexFieldModifier {};
	class NiPSysVortexFieldModifier_Storage : public ObjectStorage <NiPSysVortexFieldModifier> {};
	class NiPSysGravityFieldModifier : public BasicNode, public Niflib::NiPSysGravityFieldModifier {};
	class NiPSysGravityFieldModifier_Storage : public ObjectStorage <NiPSysGravityFieldModifier> {};
	class NiPSysDragFieldModifier : public BasicNode, public Niflib::NiPSysDragFieldModifier {};
	class NiPSysDragFieldModifier_Storage : public ObjectStorage <NiPSysDragFieldModifier> {};
	class NiPSysTurbulenceFieldModifier : public BasicNode, public Niflib::NiPSysTurbulenceFieldModifier {};
	class NiPSysTurbulenceFieldModifier_Storage : public ObjectStorage <NiPSysTurbulenceFieldModifier> {};
	class BSPSysLODModifier : public BasicNode, public Niflib::BSPSysLODModifier {};
	class BSPSysLODModifier_Storage : public ObjectStorage <BSPSysLODModifier> {};
	class BSPSysScaleModifier : public BasicNode, public Niflib::BSPSysScaleModifier {};
	class BSPSysScaleModifier_Storage : public ObjectStorage <BSPSysScaleModifier> {};
	class NiPSysFieldMagnitudeCtlr : public BasicNode, public Niflib::NiPSysFieldMagnitudeCtlr {};
	class NiPSysFieldMagnitudeCtlr_Storage : public ObjectStorage <NiPSysFieldMagnitudeCtlr> {};
	class NiPSysFieldAttenuationCtlr : public BasicNode, public Niflib::NiPSysFieldAttenuationCtlr {};
	class NiPSysFieldAttenuationCtlr_Storage : public ObjectStorage <NiPSysFieldAttenuationCtlr> {};
	class NiPSysFieldMaxDistanceCtlr : public BasicNode, public Niflib::NiPSysFieldMaxDistanceCtlr {};
	class NiPSysFieldMaxDistanceCtlr_Storage : public ObjectStorage <NiPSysFieldMaxDistanceCtlr> {};
	class NiPSysAirFieldAirFrictionCtlr : public BasicNode, public Niflib::NiPSysAirFieldAirFrictionCtlr {};
	class NiPSysAirFieldAirFrictionCtlr_Storage : public ObjectStorage <NiPSysAirFieldAirFrictionCtlr> {};
	class NiPSysAirFieldInheritVelocityCtlr : public BasicNode, public Niflib::NiPSysAirFieldInheritVelocityCtlr {};
	class NiPSysAirFieldInheritVelocityCtlr_Storage : public ObjectStorage <NiPSysAirFieldInheritVelocityCtlr> {};
	class NiPSysAirFieldSpreadCtlr : public BasicNode, public Niflib::NiPSysAirFieldSpreadCtlr {};
	class NiPSysAirFieldSpreadCtlr_Storage : public ObjectStorage <NiPSysAirFieldSpreadCtlr> {};
	class NiPSysInitialRotSpeedCtlr : public BasicNode, public Niflib::NiPSysInitialRotSpeedCtlr {};
	class NiPSysInitialRotSpeedCtlr_Storage : public ObjectStorage <NiPSysInitialRotSpeedCtlr> {};
	class NiPSysInitialRotSpeedVarCtlr : public BasicNode, public Niflib::NiPSysInitialRotSpeedVarCtlr {};
	class NiPSysInitialRotSpeedVarCtlr_Storage : public ObjectStorage <NiPSysInitialRotSpeedVarCtlr> {};
	class NiPSysInitialRotAngleCtlr : public BasicNode, public Niflib::NiPSysInitialRotAngleCtlr {};
	class NiPSysInitialRotAngleCtlr_Storage : public ObjectStorage <NiPSysInitialRotAngleCtlr> {};
	class NiPSysInitialRotAngleVarCtlr : public BasicNode, public Niflib::NiPSysInitialRotAngleVarCtlr {};
	class NiPSysInitialRotAngleVarCtlr_Storage : public ObjectStorage <NiPSysInitialRotAngleVarCtlr> {};
	class NiPSysEmitterPlanarAngleCtlr : public BasicNode, public Niflib::NiPSysEmitterPlanarAngleCtlr {};
	class NiPSysEmitterPlanarAngleCtlr_Storage : public ObjectStorage <NiPSysEmitterPlanarAngleCtlr> {};
	class NiPSysEmitterPlanarAngleVarCtlr : public BasicNode, public Niflib::NiPSysEmitterPlanarAngleVarCtlr {};
	class NiPSysEmitterPlanarAngleVarCtlr_Storage : public ObjectStorage <NiPSysEmitterPlanarAngleVarCtlr> {};
	class NiPSysAirFieldModifier : public BasicNode, public Niflib::NiPSysAirFieldModifier {};
	class NiPSysAirFieldModifier_Storage : public ObjectStorage <NiPSysAirFieldModifier> {};
	class NiPSysTrailEmitter : public BasicNode, public Niflib::NiPSysTrailEmitter {};
	class NiPSysTrailEmitter_Storage : public ObjectStorage <NiPSysTrailEmitter> {};
	class NiLightIntensityController : public BasicNode, public Niflib::NiLightIntensityController {};
	class NiLightIntensityController_Storage : public ObjectStorage <NiLightIntensityController> {};
	class NiPSysRadialFieldModifier : public BasicNode, public Niflib::NiPSysRadialFieldModifier {};
	class NiPSysRadialFieldModifier_Storage : public ObjectStorage <NiPSysRadialFieldModifier> {};
	class NiLODData : public BasicNode, public Niflib::NiLODData {};
	class NiLODData_Storage : public ObjectStorage <NiLODData> {};
	class NiRangeLODData : public BasicNode, public Niflib::NiRangeLODData {};
	class NiRangeLODData_Storage : public ObjectStorage <NiRangeLODData> {};
	class NiScreenLODData : public BasicNode, public Niflib::NiScreenLODData {};
	class NiScreenLODData_Storage : public ObjectStorage <NiScreenLODData> {};
	class NiRotatingParticles : public BasicNode, public Niflib::NiRotatingParticles {};
	class NiRotatingParticles_Storage : public ObjectStorage <NiRotatingParticles> {};
	class NiSequenceStreamHelper : public BasicNode, public Niflib::NiSequenceStreamHelper {};
	class NiSequenceStreamHelper_Storage : public ObjectStorage <NiSequenceStreamHelper> {};
	class NiShadeProperty : public BasicNode, public Niflib::NiShadeProperty {};
	class NiShadeProperty_Storage : public ObjectStorage <NiShadeProperty> {};
	class NiSkinData : public BasicNode, public Niflib::NiSkinData {};
	class NiSkinData_Storage : public ObjectStorage <NiSkinData> {};
	class NiSkinInstance : public BasicNode, public Niflib::NiSkinInstance {};
	class NiSkinInstance_Storage : public ObjectStorage <NiSkinInstance> {};
	class NiTriShapeSkinController : public BasicNode, public Niflib::NiTriShapeSkinController {};
	class NiTriShapeSkinController_Storage : public ObjectStorage <NiTriShapeSkinController> {};
	class NiClodSkinInstance : public BasicNode, public Niflib::NiClodSkinInstance {};
	class NiClodSkinInstance_Storage : public ObjectStorage <NiClodSkinInstance> {};
	class NiSkinPartition : public BasicNode, public Niflib::NiSkinPartition {};
	class NiSkinPartition_Storage : public ObjectStorage <NiSkinPartition> {};
	class NiTexture : public BasicNode, public Niflib::NiTexture {};
	class NiTexture_Storage : public ObjectStorage <NiTexture> {};
	class NiSourceTexture : public BasicNode, public Niflib::NiSourceTexture {};
	class NiSourceTexture_Storage : public ObjectStorage <NiSourceTexture> {};
	class NiSpecularProperty : public BasicNode, public Niflib::NiSpecularProperty {};
	class NiSpecularProperty_Storage : public ObjectStorage <NiSpecularProperty> {};
	class NiSphericalCollider : public BasicNode, public Niflib::NiSphericalCollider {};
	class NiSphericalCollider_Storage : public ObjectStorage <NiSphericalCollider> {};
	class NiSpotLight : public BasicNode, public Niflib::NiSpotLight {};
	class NiSpotLight_Storage : public ObjectStorage <NiSpotLight> {};
	class NiStencilProperty : public BasicNode, public Niflib::NiStencilProperty {};
	class NiStencilProperty_Storage : public ObjectStorage <NiStencilProperty> {};
	class NiStringExtraData : public BasicNode, public Niflib::NiStringExtraData {};
	class NiStringExtraData_Storage : public ObjectStorage <NiStringExtraData> {};
	class NiStringPalette : public BasicNode, public Niflib::NiStringPalette {};
	class NiStringPalette_Storage : public ObjectStorage <NiStringPalette> {};
	class NiStringsExtraData : public BasicNode, public Niflib::NiStringsExtraData {};
	class NiStringsExtraData_Storage : public ObjectStorage <NiStringsExtraData> {};
	class NiTextKeyExtraData : public BasicNode, public Niflib::NiTextKeyExtraData {};
	class NiTextKeyExtraData_Storage : public ObjectStorage <NiTextKeyExtraData> {};
	class NiTextureEffect : public BasicNode, public Niflib::NiTextureEffect {};
	class NiTextureEffect_Storage : public ObjectStorage <NiTextureEffect> {};
	class NiTextureModeProperty : public BasicNode, public Niflib::NiTextureModeProperty {};
	class NiTextureModeProperty_Storage : public ObjectStorage <NiTextureModeProperty> {};
	class NiImage : public BasicNode, public Niflib::NiImage {};
	class NiImage_Storage : public ObjectStorage <NiImage> {};
	class NiTextureProperty : public BasicNode, public Niflib::NiTextureProperty {};
	class NiTextureProperty_Storage : public ObjectStorage <NiTextureProperty> {};
	class NiMultiTextureProperty : public BasicNode, public Niflib::NiMultiTextureProperty {};
	class NiMultiTextureProperty_Storage : public ObjectStorage <NiMultiTextureProperty> {};
	class NiTexturingProperty : public BasicNode, public Niflib::NiTexturingProperty {};
	class NiTexturingProperty_Storage : public ObjectStorage <NiTexturingProperty> {};
	class NiTransformData : public BasicNode, public Niflib::NiTransformData {};
	class NiTransformData_Storage : public ObjectStorage <NiTransformData> {};
	class NiTriShape : public BasicNode, public Niflib::NiTriShape {};
	class NiTriShape_Storage : public ObjectStorage <NiTriShape> {};
	class NiTriShapeData : public BasicNode, public Niflib::NiTriShapeData {};
	class NiTriShapeData_Storage : public ObjectStorage <NiTriShapeData> {};
	class NiTriStrips : public BasicNode, public Niflib::NiTriStrips {};
	class NiTriStrips_Storage : public ObjectStorage <NiTriStrips> {};
	class NiTriStripsData : public BasicNode, public Niflib::NiTriStripsData {};
	class NiTriStripsData_Storage : public ObjectStorage <NiTriStripsData> {};
	class NiEnvMappedTriShape : public BasicNode, public Niflib::NiEnvMappedTriShape {};
	class NiEnvMappedTriShape_Storage : public ObjectStorage <NiEnvMappedTriShape> {};
	class NiEnvMappedTriShapeData : public BasicNode, public Niflib::NiEnvMappedTriShapeData {};
	class NiEnvMappedTriShapeData_Storage : public ObjectStorage <NiEnvMappedTriShapeData> {};
	class NiBezierTriangle4 : public BasicNode, public Niflib::NiBezierTriangle4 {};
	class NiBezierTriangle4_Storage : public ObjectStorage <NiBezierTriangle4> {};
	class NiBezierMesh : public BasicNode, public Niflib::NiBezierMesh {};
	class NiBezierMesh_Storage : public ObjectStorage <NiBezierMesh> {};
	class NiClod : public BasicNode, public Niflib::NiClod {};
	class NiClod_Storage : public ObjectStorage <NiClod> {};
	class NiClodData : public BasicNode, public Niflib::NiClodData {};
	class NiClodData_Storage : public ObjectStorage <NiClodData> {};
	class NiUVController : public BasicNode, public Niflib::NiUVController {};
	class NiUVController_Storage : public ObjectStorage <NiUVController> {};
	class NiUVData : public BasicNode, public Niflib::NiUVData {};
	class NiUVData_Storage : public ObjectStorage <NiUVData> {};
	class NiVectorExtraData : public BasicNode, public Niflib::NiVectorExtraData {};
	class NiVectorExtraData_Storage : public ObjectStorage <NiVectorExtraData> {};
	class NiVertexColorProperty : public BasicNode, public Niflib::NiVertexColorProperty {};
	class NiVertexColorProperty_Storage : public ObjectStorage <NiVertexColorProperty> {};
	class NiVertWeightsExtraData : public BasicNode, public Niflib::NiVertWeightsExtraData {};
	class NiVertWeightsExtraData_Storage : public ObjectStorage <NiVertWeightsExtraData> {};
	class NiVisData : public BasicNode, public Niflib::NiVisData {};
	class NiVisData_Storage : public ObjectStorage <NiVisData> {};
	class NiWireframeProperty : public BasicNode, public Niflib::NiWireframeProperty {};
	class NiWireframeProperty_Storage : public ObjectStorage <NiWireframeProperty> {};
	class NiZBufferProperty : public BasicNode, public Niflib::NiZBufferProperty {};
	class NiZBufferProperty_Storage : public ObjectStorage <NiZBufferProperty> {};
	class RootCollisionNode : public BasicNode, public Niflib::RootCollisionNode {};
	class RootCollisionNode_Storage : public ObjectStorage <RootCollisionNode> {};
	class NiRawImageData : public BasicNode, public Niflib::NiRawImageData {};
	class NiRawImageData_Storage : public ObjectStorage <NiRawImageData> {};
	class NiSortAdjustNode : public BasicNode, public Niflib::NiSortAdjustNode {};
	class NiSortAdjustNode_Storage : public ObjectStorage <NiSortAdjustNode> {};
	class NiSourceCubeMap : public BasicNode, public Niflib::NiSourceCubeMap {};
	class NiSourceCubeMap_Storage : public ObjectStorage <NiSourceCubeMap> {};
	class NiPhysXProp : public BasicNode, public Niflib::NiPhysXProp {};
	class NiPhysXProp_Storage : public ObjectStorage <NiPhysXProp> {};
	class NiPhysXPropDesc : public BasicNode, public Niflib::NiPhysXPropDesc {};
	class NiPhysXPropDesc_Storage : public ObjectStorage <NiPhysXPropDesc> {};
	class NiPhysXActorDesc : public BasicNode, public Niflib::NiPhysXActorDesc {};
	class NiPhysXActorDesc_Storage : public ObjectStorage <NiPhysXActorDesc> {};
	class NiPhysXBodyDesc : public BasicNode, public Niflib::NiPhysXBodyDesc {};
	class NiPhysXBodyDesc_Storage : public ObjectStorage <NiPhysXBodyDesc> {};
	class NiPhysXD6JointDesc : public BasicNode, public Niflib::NiPhysXD6JointDesc {};
	class NiPhysXD6JointDesc_Storage : public ObjectStorage <NiPhysXD6JointDesc> {};
	class NiPhysXShapeDesc : public BasicNode, public Niflib::NiPhysXShapeDesc {};
	class NiPhysXShapeDesc_Storage : public ObjectStorage <NiPhysXShapeDesc> {};
	class NiPhysXMeshDesc : public BasicNode, public Niflib::NiPhysXMeshDesc {};
	class NiPhysXMeshDesc_Storage : public ObjectStorage <NiPhysXMeshDesc> {};
	class NiPhysXMaterialDesc : public BasicNode, public Niflib::NiPhysXMaterialDesc {};
	class NiPhysXMaterialDesc_Storage : public ObjectStorage <NiPhysXMaterialDesc> {};
	class NiPhysXKinematicSrc : public BasicNode, public Niflib::NiPhysXKinematicSrc {};
	class NiPhysXKinematicSrc_Storage : public ObjectStorage <NiPhysXKinematicSrc> {};
	class NiPhysXTransformDest : public BasicNode, public Niflib::NiPhysXTransformDest {};
	class NiPhysXTransformDest_Storage : public ObjectStorage <NiPhysXTransformDest> {};
	class NiArkAnimationExtraData : public BasicNode, public Niflib::NiArkAnimationExtraData {};
	class NiArkAnimationExtraData_Storage : public ObjectStorage <NiArkAnimationExtraData> {};
	class NiArkImporterExtraData : public BasicNode, public Niflib::NiArkImporterExtraData {};
	class NiArkImporterExtraData_Storage : public ObjectStorage <NiArkImporterExtraData> {};
	class NiArkTextureExtraData : public BasicNode, public Niflib::NiArkTextureExtraData {};
	class NiArkTextureExtraData_Storage : public ObjectStorage <NiArkTextureExtraData> {};
	class NiArkViewportInfoExtraData : public BasicNode, public Niflib::NiArkViewportInfoExtraData {};
	class NiArkViewportInfoExtraData_Storage : public ObjectStorage <NiArkViewportInfoExtraData> {};
	class NiArkShaderExtraData : public BasicNode, public Niflib::NiArkShaderExtraData {};
	class NiArkShaderExtraData_Storage : public ObjectStorage <NiArkShaderExtraData> {};
	class NiLines : public BasicNode, public Niflib::NiLines {};
	class NiLines_Storage : public ObjectStorage <NiLines> {};
	class NiLinesData : public BasicNode, public Niflib::NiLinesData {};
	class NiLinesData_Storage : public ObjectStorage <NiLinesData> {};
	class NiScreenElementsData : public BasicNode, public Niflib::NiScreenElementsData {};
	class NiScreenElementsData_Storage : public ObjectStorage <NiScreenElementsData> {};
	class NiScreenElements : public BasicNode, public Niflib::NiScreenElements {};
	class NiScreenElements_Storage : public ObjectStorage <NiScreenElements> {};
	class NiRoomGroup : public BasicNode, public Niflib::NiRoomGroup {};
	class NiRoomGroup_Storage : public ObjectStorage <NiRoomGroup> {};
	class NiRoom : public BasicNode, public Niflib::NiRoom {};
	class NiRoom_Storage : public ObjectStorage <NiRoom> {};
	class NiPortal : public BasicNode, public Niflib::NiPortal {};
	class NiPortal_Storage : public ObjectStorage <NiPortal> {};
	class BSFadeNode : public BasicNode, public Niflib::BSFadeNode {};
	class BSFadeNode_Storage : public ObjectStorage <BSFadeNode> {};
	class BSShaderProperty : public BasicNode, public Niflib::BSShaderProperty {};
	class BSShaderProperty_Storage : public ObjectStorage <BSShaderProperty> {};
	class BSShaderLightingProperty : public BasicNode, public Niflib::BSShaderLightingProperty {};
	class BSShaderLightingProperty_Storage : public ObjectStorage <BSShaderLightingProperty> {};
	class BSShaderNoLightingProperty : public BasicNode, public Niflib::BSShaderNoLightingProperty {};
	class BSShaderNoLightingProperty_Storage : public ObjectStorage <BSShaderNoLightingProperty> {};
	class BSShaderPPLightingProperty : public BasicNode, public Niflib::BSShaderPPLightingProperty {};
	class BSShaderPPLightingProperty_Storage : public ObjectStorage <BSShaderPPLightingProperty> {};
	class BSEffectShaderPropertyFloatController : public BasicNode, public Niflib::BSEffectShaderPropertyFloatController {};
	class BSEffectShaderPropertyFloatController_Storage : public ObjectStorage <BSEffectShaderPropertyFloatController> {};
	class BSEffectShaderPropertyColorController : public BasicNode, public Niflib::BSEffectShaderPropertyColorController {};
	class BSEffectShaderPropertyColorController_Storage : public ObjectStorage <BSEffectShaderPropertyColorController> {};
	class BSLightingShaderPropertyFloatController : public BasicNode, public Niflib::BSLightingShaderPropertyFloatController {};
	class BSLightingShaderPropertyFloatController_Storage : public ObjectStorage <BSLightingShaderPropertyFloatController> {};
	class BSLightingShaderPropertyColorController : public BasicNode, public Niflib::BSLightingShaderPropertyColorController {};
	class BSLightingShaderPropertyColorController_Storage : public ObjectStorage <BSLightingShaderPropertyColorController> {};
	class BSNiAlphaPropertyTestRefController : public BasicNode, public Niflib::BSNiAlphaPropertyTestRefController {};
	class BSNiAlphaPropertyTestRefController_Storage : public ObjectStorage <BSNiAlphaPropertyTestRefController> {};
	class BSProceduralLightningController : public BasicNode, public Niflib::BSProceduralLightningController {};
	class BSProceduralLightningController_Storage : public ObjectStorage <BSProceduralLightningController> {};
	class BSShaderTextureSet : public BasicNode, public Niflib::BSShaderTextureSet {};
	class BSShaderTextureSet_Storage : public ObjectStorage <BSShaderTextureSet> {};
	class WaterShaderProperty : public BasicNode, public Niflib::WaterShaderProperty {};
	class WaterShaderProperty_Storage : public ObjectStorage <WaterShaderProperty> {};
	class SkyShaderProperty : public BasicNode, public Niflib::SkyShaderProperty {};
	class SkyShaderProperty_Storage : public ObjectStorage <SkyShaderProperty> {};
	class TileShaderProperty : public BasicNode, public Niflib::TileShaderProperty {};
	class TileShaderProperty_Storage : public ObjectStorage <TileShaderProperty> {};
	class DistantLODShaderProperty : public BasicNode, public Niflib::DistantLODShaderProperty {};
	class DistantLODShaderProperty_Storage : public ObjectStorage <DistantLODShaderProperty> {};
	class BSDistantTreeShaderProperty : public BasicNode, public Niflib::BSDistantTreeShaderProperty {};
	class BSDistantTreeShaderProperty_Storage : public ObjectStorage <BSDistantTreeShaderProperty> {};
	class TallGrassShaderProperty : public BasicNode, public Niflib::TallGrassShaderProperty {};
	class TallGrassShaderProperty_Storage : public ObjectStorage <TallGrassShaderProperty> {};
	class VolumetricFogShaderProperty : public BasicNode, public Niflib::VolumetricFogShaderProperty {};
	class VolumetricFogShaderProperty_Storage : public ObjectStorage <VolumetricFogShaderProperty> {};
	class HairShaderProperty : public BasicNode, public Niflib::HairShaderProperty {};
	class HairShaderProperty_Storage : public ObjectStorage <HairShaderProperty> {};
	class Lighting30ShaderProperty : public BasicNode, public Niflib::Lighting30ShaderProperty {};
	class Lighting30ShaderProperty_Storage : public ObjectStorage <Lighting30ShaderProperty> {};
	class BSLightingShaderProperty : public BasicNode, public Niflib::BSLightingShaderProperty {};
	class BSLightingShaderProperty_Storage : public ObjectStorage <BSLightingShaderProperty> {};
	class BSEffectShaderProperty : public BasicNode, public Niflib::BSEffectShaderProperty {};
	class BSEffectShaderProperty_Storage : public ObjectStorage <BSEffectShaderProperty> {};
	class BSWaterShaderProperty : public BasicNode, public Niflib::BSWaterShaderProperty {};
	class BSWaterShaderProperty_Storage : public ObjectStorage <BSWaterShaderProperty> {};
	class BSSkyShaderProperty : public BasicNode, public Niflib::BSSkyShaderProperty {};
	class BSSkyShaderProperty_Storage : public ObjectStorage <BSSkyShaderProperty> {};
	class BSDismemberSkinInstance : public BasicNode, public Niflib::BSDismemberSkinInstance {};
	class BSDismemberSkinInstance_Storage : public ObjectStorage <BSDismemberSkinInstance> {};
	class BSDecalPlacementVectorExtraData : public BasicNode, public Niflib::BSDecalPlacementVectorExtraData {};
	class BSDecalPlacementVectorExtraData_Storage : public ObjectStorage <BSDecalPlacementVectorExtraData> {};
	class BSPSysSimpleColorModifier : public BasicNode, public Niflib::BSPSysSimpleColorModifier {};
	class BSPSysSimpleColorModifier_Storage : public ObjectStorage <BSPSysSimpleColorModifier> {};
	class BSValueNode : public BasicNode, public Niflib::BSValueNode {};
	class BSValueNode_Storage : public ObjectStorage <BSValueNode> {};
	class BSStripParticleSystem : public BasicNode, public Niflib::BSStripParticleSystem {};
	class BSStripParticleSystem_Storage : public ObjectStorage <BSStripParticleSystem> {};
	class BSStripPSysData : public BasicNode, public Niflib::BSStripPSysData {};
	class BSStripPSysData_Storage : public ObjectStorage <BSStripPSysData> {};
	class BSPSysStripUpdateModifier : public BasicNode, public Niflib::BSPSysStripUpdateModifier {};
	class BSPSysStripUpdateModifier_Storage : public ObjectStorage <BSPSysStripUpdateModifier> {};
	class BSMaterialEmittanceMultController : public BasicNode, public Niflib::BSMaterialEmittanceMultController {};
	class BSMaterialEmittanceMultController_Storage : public ObjectStorage <BSMaterialEmittanceMultController> {};
	class BSMasterParticleSystem : public BasicNode, public Niflib::BSMasterParticleSystem {};
	class BSMasterParticleSystem_Storage : public ObjectStorage <BSMasterParticleSystem> {};
	class BSPSysMultiTargetEmitterCtlr : public BasicNode, public Niflib::BSPSysMultiTargetEmitterCtlr {};
	class BSPSysMultiTargetEmitterCtlr_Storage : public ObjectStorage <BSPSysMultiTargetEmitterCtlr> {};
	class BSRefractionStrengthController : public BasicNode, public Niflib::BSRefractionStrengthController {};
	class BSRefractionStrengthController_Storage : public ObjectStorage <BSRefractionStrengthController> {};
	class BSOrderedNode : public BasicNode, public Niflib::BSOrderedNode {};
	class BSOrderedNode_Storage : public ObjectStorage <BSOrderedNode> {};
	class BSBlastNode : public BasicNode, public Niflib::BSBlastNode {};
	class BSBlastNode_Storage : public ObjectStorage <BSBlastNode> {};
	class BSDamageStage : public BasicNode, public Niflib::BSDamageStage {};
	class BSDamageStage_Storage : public ObjectStorage <BSDamageStage> {};
	class BSRefractionFirePeriodController : public BasicNode, public Niflib::BSRefractionFirePeriodController {};
	class BSRefractionFirePeriodController_Storage : public ObjectStorage <BSRefractionFirePeriodController> {};
	class bhkConvexListShape : public BasicNode, public Niflib::bhkConvexListShape {};
	class bhkConvexListShape_Storage : public ObjectStorage <bhkConvexListShape> {};
	class BSTreadTransfInterpolator : public BasicNode, public Niflib::BSTreadTransfInterpolator {};
	class BSTreadTransfInterpolator_Storage : public ObjectStorage <BSTreadTransfInterpolator> {};
	class BSAnimNotes : public BasicNode, public Niflib::BSAnimNotes {};
	class BSAnimNotes_Storage : public ObjectStorage <BSAnimNotes> {};
	class bhkLiquidAction : public BasicNode, public Niflib::bhkLiquidAction {};
	class bhkLiquidAction_Storage : public ObjectStorage <bhkLiquidAction> {};
	class BSMultiBoundNode : public BasicNode, public Niflib::BSMultiBoundNode {};
	class BSMultiBoundNode_Storage : public ObjectStorage <BSMultiBoundNode> {};
	class BSMultiBound : public BasicNode, public Niflib::BSMultiBound {};
	class BSMultiBound_Storage : public ObjectStorage <BSMultiBound> {};
	class BSMultiBoundData : public BasicNode, public Niflib::BSMultiBoundData {};
	class BSMultiBoundData_Storage : public ObjectStorage <BSMultiBoundData> {};
	class BSMultiBoundOBB : public BasicNode, public Niflib::BSMultiBoundOBB {};
	class BSMultiBoundOBB_Storage : public ObjectStorage <BSMultiBoundOBB> {};
	class BSMultiBoundSphere : public BasicNode, public Niflib::BSMultiBoundSphere {};
	class BSMultiBoundSphere_Storage : public ObjectStorage <BSMultiBoundSphere> {};
	class BSSegmentedTriShape : public BasicNode, public Niflib::BSSegmentedTriShape {};
	class BSSegmentedTriShape_Storage : public ObjectStorage <BSSegmentedTriShape> {};
	class BSMultiBoundAABB : public BasicNode, public Niflib::BSMultiBoundAABB {};
	class BSMultiBoundAABB_Storage : public ObjectStorage <BSMultiBoundAABB> {};
	class NiAdditionalGeometryData : public BasicNode, public Niflib::NiAdditionalGeometryData {};
	class NiAdditionalGeometryData_Storage : public ObjectStorage <NiAdditionalGeometryData> {};
	class BSPackedAdditionalGeometryData : public BasicNode, public Niflib::BSPackedAdditionalGeometryData {};
	class BSPackedAdditionalGeometryData_Storage : public ObjectStorage <BSPackedAdditionalGeometryData> {};
	class BSWArray : public BasicNode, public Niflib::BSWArray {};
	class BSWArray_Storage : public ObjectStorage <BSWArray> {};
	class bhkAabbPhantom : public BasicNode, public Niflib::bhkAabbPhantom {};
	class bhkAabbPhantom_Storage : public ObjectStorage <bhkAabbPhantom> {};
	class BSFrustumFOVController : public BasicNode, public Niflib::BSFrustumFOVController {};
	class BSFrustumFOVController_Storage : public ObjectStorage <BSFrustumFOVController> {};
	class BSDebrisNode : public BasicNode, public Niflib::BSDebrisNode {};
	class BSDebrisNode_Storage : public ObjectStorage <BSDebrisNode> {};
	class bhkBreakableConstraint : public BasicNode, public Niflib::bhkBreakableConstraint {};
	class bhkBreakableConstraint_Storage : public ObjectStorage <bhkBreakableConstraint> {};
	class bhkOrientHingedBodyAction : public BasicNode, public Niflib::bhkOrientHingedBodyAction {};
	class bhkOrientHingedBodyAction_Storage : public ObjectStorage <bhkOrientHingedBodyAction> {};
	class NiDataStream : public BasicNode, public Niflib::NiDataStream {};
	class NiDataStream_Storage : public ObjectStorage <NiDataStream> {};
	class NiRenderObject : public BasicNode, public Niflib::NiRenderObject {};
	class NiRenderObject_Storage : public ObjectStorage <NiRenderObject> {};
	class NiMeshModifier : public BasicNode, public Niflib::NiMeshModifier {};
	class NiMeshModifier_Storage : public ObjectStorage <NiMeshModifier> {};
	class NiMesh : public BasicNode, public Niflib::NiMesh {};
	class NiMesh_Storage : public ObjectStorage <NiMesh> {};
	class NiMorphWeightsController : public BasicNode, public Niflib::NiMorphWeightsController {};
	class NiMorphWeightsController_Storage : public ObjectStorage <NiMorphWeightsController> {};
	class NiMorphMeshModifier : public BasicNode, public Niflib::NiMorphMeshModifier {};
	class NiMorphMeshModifier_Storage : public ObjectStorage <NiMorphMeshModifier> {};
	class NiSkinningMeshModifier : public BasicNode, public Niflib::NiSkinningMeshModifier {};
	class NiSkinningMeshModifier_Storage : public ObjectStorage <NiSkinningMeshModifier> {};
	class NiInstancingMeshModifier : public BasicNode, public Niflib::NiInstancingMeshModifier {};
	class NiInstancingMeshModifier_Storage : public ObjectStorage <NiInstancingMeshModifier> {};
	class NiSkinningLODController : public BasicNode, public Niflib::NiSkinningLODController {};
	class NiSkinningLODController_Storage : public ObjectStorage <NiSkinningLODController> {};
	class NiPSParticleSystem : public BasicNode, public Niflib::NiPSParticleSystem {};
	class NiPSParticleSystem_Storage : public ObjectStorage <NiPSParticleSystem> {};
	class NiPSMeshParticleSystem : public BasicNode, public Niflib::NiPSMeshParticleSystem {};
	class NiPSMeshParticleSystem_Storage : public ObjectStorage <NiPSMeshParticleSystem> {};
	class NiPSEmitParticlesCtlr : public BasicNode, public Niflib::NiPSEmitParticlesCtlr {};
	class NiPSEmitParticlesCtlr_Storage : public ObjectStorage <NiPSEmitParticlesCtlr> {};
	class NiPSForceActiveCtlr : public BasicNode, public Niflib::NiPSForceActiveCtlr {};
	class NiPSForceActiveCtlr_Storage : public ObjectStorage <NiPSForceActiveCtlr> {};
	class NiPSSimulator : public BasicNode, public Niflib::NiPSSimulator {};
	class NiPSSimulator_Storage : public ObjectStorage <NiPSSimulator> {};
	class NiPSSimulatorStep : public BasicNode, public Niflib::NiPSSimulatorStep {};
	class NiPSSimulatorStep_Storage : public ObjectStorage <NiPSSimulatorStep> {};
	class NiPSSimulatorGeneralStep : public BasicNode, public Niflib::NiPSSimulatorGeneralStep {};
	class NiPSSimulatorGeneralStep_Storage : public ObjectStorage <NiPSSimulatorGeneralStep> {};
	class NiPSSimulatorForcesStep : public BasicNode, public Niflib::NiPSSimulatorForcesStep {};
	class NiPSSimulatorForcesStep_Storage : public ObjectStorage <NiPSSimulatorForcesStep> {};
	class NiPSSimulatorCollidersStep : public BasicNode, public Niflib::NiPSSimulatorCollidersStep {};
	class NiPSSimulatorCollidersStep_Storage : public ObjectStorage <NiPSSimulatorCollidersStep> {};
	class NiPSSimulatorMeshAlignStep : public BasicNode, public Niflib::NiPSSimulatorMeshAlignStep {};
	class NiPSSimulatorMeshAlignStep_Storage : public ObjectStorage <NiPSSimulatorMeshAlignStep> {};
	class NiPSSimulatorFinalStep : public BasicNode, public Niflib::NiPSSimulatorFinalStep {};
	class NiPSSimulatorFinalStep_Storage : public ObjectStorage <NiPSSimulatorFinalStep> {};
	class NiPSFacingQuadGenerator : public BasicNode, public Niflib::NiPSFacingQuadGenerator {};
	class NiPSFacingQuadGenerator_Storage : public ObjectStorage <NiPSFacingQuadGenerator> {};
	class NiShadowGenerator : public BasicNode, public Niflib::NiShadowGenerator {};
	class NiShadowGenerator_Storage : public ObjectStorage <NiShadowGenerator> {};
	class NiPSBoundUpdater : public BasicNode, public Niflib::NiPSBoundUpdater {};
	class NiPSBoundUpdater_Storage : public ObjectStorage <NiPSBoundUpdater> {};
	class NiPSDragForce : public BasicNode, public Niflib::NiPSDragForce {};
	class NiPSDragForce_Storage : public ObjectStorage <NiPSDragForce> {};
	class NiPSGravityForce : public BasicNode, public Niflib::NiPSGravityForce {};
	class NiPSGravityForce_Storage : public ObjectStorage <NiPSGravityForce> {};
	class NiPSBoxEmitter : public BasicNode, public Niflib::NiPSBoxEmitter {};
	class NiPSBoxEmitter_Storage : public ObjectStorage <NiPSBoxEmitter> {};
	class NiPSMeshEmitter : public BasicNode, public Niflib::NiPSMeshEmitter {};
	class NiPSMeshEmitter_Storage : public ObjectStorage <NiPSMeshEmitter> {};
	class NiPSGravityStrengthCtlr : public BasicNode, public Niflib::NiPSGravityStrengthCtlr {};
	class NiPSGravityStrengthCtlr_Storage : public ObjectStorage <NiPSGravityStrengthCtlr> {};
	class NiPSPlanarCollider : public BasicNode, public Niflib::NiPSPlanarCollider {};
	class NiPSPlanarCollider_Storage : public ObjectStorage <NiPSPlanarCollider> {};
	class NiPSEmitterSpeedCtlr : public BasicNode, public Niflib::NiPSEmitterSpeedCtlr {};
	class NiPSEmitterSpeedCtlr_Storage : public ObjectStorage <NiPSEmitterSpeedCtlr> {};
	class NiPSEmitterRadiusCtlr : public BasicNode, public Niflib::NiPSEmitterRadiusCtlr {};
	class NiPSEmitterRadiusCtlr_Storage : public ObjectStorage <NiPSEmitterRadiusCtlr> {};
	class NiPSResetOnLoopCtlr : public BasicNode, public Niflib::NiPSResetOnLoopCtlr {};
	class NiPSResetOnLoopCtlr_Storage : public ObjectStorage <NiPSResetOnLoopCtlr> {};
	class NiPSSphereEmitter : public BasicNode, public Niflib::NiPSSphereEmitter {};
	class NiPSSphereEmitter_Storage : public ObjectStorage <NiPSSphereEmitter> {};
	class NiPSCylinderEmitter : public BasicNode, public Niflib::NiPSCylinderEmitter {};
	class NiPSCylinderEmitter_Storage : public ObjectStorage <NiPSCylinderEmitter> {};
	class NiPSEmitterDeclinationCtlr : public BasicNode, public Niflib::NiPSEmitterDeclinationCtlr {};
	class NiPSEmitterDeclinationCtlr_Storage : public ObjectStorage <NiPSEmitterDeclinationCtlr> {};
	class NiPSEmitterDeclinationVarCtlr : public BasicNode, public Niflib::NiPSEmitterDeclinationVarCtlr {};
	class NiPSEmitterDeclinationVarCtlr_Storage : public ObjectStorage <NiPSEmitterDeclinationVarCtlr> {};
	class NiPSEmitterPlanarAngleCtlr : public BasicNode, public Niflib::NiPSEmitterPlanarAngleCtlr {};
	class NiPSEmitterPlanarAngleCtlr_Storage : public ObjectStorage <NiPSEmitterPlanarAngleCtlr> {};
	class NiPSEmitterPlanarAngleVarCtlr : public BasicNode, public Niflib::NiPSEmitterPlanarAngleVarCtlr {};
	class NiPSEmitterPlanarAngleVarCtlr_Storage : public ObjectStorage <NiPSEmitterPlanarAngleVarCtlr> {};
	class NiPSEmitterRotAngleCtlr : public BasicNode, public Niflib::NiPSEmitterRotAngleCtlr {};
	class NiPSEmitterRotAngleCtlr_Storage : public ObjectStorage <NiPSEmitterRotAngleCtlr> {};
	class NiPSEmitterRotAngleVarCtlr : public BasicNode, public Niflib::NiPSEmitterRotAngleVarCtlr {};
	class NiPSEmitterRotAngleVarCtlr_Storage : public ObjectStorage <NiPSEmitterRotAngleVarCtlr> {};
	class NiPSEmitterRotSpeedCtlr : public BasicNode, public Niflib::NiPSEmitterRotSpeedCtlr {};
	class NiPSEmitterRotSpeedCtlr_Storage : public ObjectStorage <NiPSEmitterRotSpeedCtlr> {};
	class NiPSEmitterRotSpeedVarCtlr : public BasicNode, public Niflib::NiPSEmitterRotSpeedVarCtlr {};
	class NiPSEmitterRotSpeedVarCtlr_Storage : public ObjectStorage <NiPSEmitterRotSpeedVarCtlr> {};
	class NiPSEmitterLifeSpanCtlr : public BasicNode, public Niflib::NiPSEmitterLifeSpanCtlr {};
	class NiPSEmitterLifeSpanCtlr_Storage : public ObjectStorage <NiPSEmitterLifeSpanCtlr> {};
	class NiPSBombForce : public BasicNode, public Niflib::NiPSBombForce {};
	class NiPSBombForce_Storage : public ObjectStorage <NiPSBombForce> {};
	class NiPSSphericalCollider : public BasicNode, public Niflib::NiPSSphericalCollider {};
	class NiPSSphericalCollider_Storage : public ObjectStorage <NiPSSphericalCollider> {};
	class NiPSSpawner : public BasicNode, public Niflib::NiPSSpawner {};
	class NiPSSpawner_Storage : public ObjectStorage <NiPSSpawner> {};
	class NiSequenceData : public BasicNode, public Niflib::NiSequenceData {};
	class NiSequenceData_Storage : public ObjectStorage <NiSequenceData> {};
	class NiTransformEvaluator : public BasicNode, public Niflib::NiTransformEvaluator {};
	class NiTransformEvaluator_Storage : public ObjectStorage <NiTransformEvaluator> {};
	class NiBSplineCompTransformEvaluator : public BasicNode, public Niflib::NiBSplineCompTransformEvaluator {};
	class NiBSplineCompTransformEvaluator_Storage : public ObjectStorage <NiBSplineCompTransformEvaluator> {};
	class NiMeshHWInstance : public BasicNode, public Niflib::NiMeshHWInstance {};
	class NiMeshHWInstance_Storage : public ObjectStorage <NiMeshHWInstance> {};
	class NiFurSpringController : public BasicNode, public Niflib::NiFurSpringController {};
	class NiFurSpringController_Storage : public ObjectStorage <NiFurSpringController> {};
	class CStreamableAssetData : public BasicNode, public Niflib::CStreamableAssetData {};
	class CStreamableAssetData_Storage : public ObjectStorage <CStreamableAssetData> {};
	class bhkCompressedMeshShape : public BasicNode, public Niflib::bhkCompressedMeshShape {};
	class bhkCompressedMeshShape_Storage : public ObjectStorage <bhkCompressedMeshShape> {};
	class bhkCompressedMeshShapeData : public BasicNode, public Niflib::bhkCompressedMeshShapeData {};
	class bhkCompressedMeshShapeData_Storage : public ObjectStorage <bhkCompressedMeshShapeData> {};
	class BSInvMarker : public BasicNode, public Niflib::BSInvMarker {};
	class BSInvMarker_Storage : public ObjectStorage <BSInvMarker> {};
	class BSBoneLODExtraData : public BasicNode, public Niflib::BSBoneLODExtraData {};
	class BSBoneLODExtraData_Storage : public ObjectStorage <BSBoneLODExtraData> {};
	class BSBehaviorGraphExtraData : public BasicNode, public Niflib::BSBehaviorGraphExtraData {};
	class BSBehaviorGraphExtraData_Storage : public ObjectStorage <BSBehaviorGraphExtraData> {};
	class BSLagBoneController : public BasicNode, public Niflib::BSLagBoneController {};
	class BSLagBoneController_Storage : public ObjectStorage <BSLagBoneController> {};
	class BSLODTriShape : public BasicNode, public Niflib::BSLODTriShape {};
	class BSLODTriShape_Storage : public ObjectStorage <BSLODTriShape> {};
	class BSFurnitureMarkerNode : public BasicNode, public Niflib::BSFurnitureMarkerNode {};
	class BSFurnitureMarkerNode_Storage : public ObjectStorage <BSFurnitureMarkerNode> {};
	class BSLeafAnimNode : public BasicNode, public Niflib::BSLeafAnimNode {};
	class BSLeafAnimNode_Storage : public ObjectStorage <BSLeafAnimNode> {};
	class BSTreeNode : public BasicNode, public Niflib::BSTreeNode {};
	class BSTreeNode_Storage : public ObjectStorage <BSTreeNode> {};
	class NiLightRadiusController : public BasicNode, public Niflib::NiLightRadiusController {};
	class NiLightRadiusController_Storage : public ObjectStorage <NiLightRadiusController> {};
	class BSShape : public BasicNode, public Niflib::BSShape {};
	class BSShape_Storage : public ObjectStorage <BSShape> {};
	class BSTriShape : public BasicNode, public Niflib::BSTriShape {};
	class BSTriShape_Storage : public ObjectStorage <BSTriShape> {};
	class BSSubIndexTriShape : public BasicNode, public Niflib::BSSubIndexTriShape {};
	class BSSubIndexTriShape_Storage : public ObjectStorage <BSSubIndexTriShape> {};
	class BSMeshLODTriShape : public BasicNode, public Niflib::BSMeshLODTriShape {};
	class BSMeshLODTriShape_Storage : public ObjectStorage <BSMeshLODTriShape> {};
	class bhkNPCollisionObject : public BasicNode, public Niflib::bhkNPCollisionObject {};
	class bhkNPCollisionObject_Storage : public ObjectStorage <bhkNPCollisionObject> {};
	class BSExtraData : public BasicNode, public Niflib::BSExtraData {};
	class BSExtraData_Storage : public ObjectStorage <BSExtraData> {};
	class bhkPhysicsSystem : public BasicNode, public Niflib::bhkPhysicsSystem {};
	class bhkPhysicsSystem_Storage : public ObjectStorage <bhkPhysicsSystem> {};
	class bhkRagdollSystem : public BasicNode, public Niflib::bhkRagdollSystem {};
	class bhkRagdollSystem_Storage : public ObjectStorage <bhkRagdollSystem> {};
	class BSClothExtraData : public BasicNode, public Niflib::BSClothExtraData {};
	class BSClothExtraData_Storage : public ObjectStorage <BSClothExtraData> {};
	class BSSkin__Instance : public BasicNode, public Niflib::BSSkin__Instance {};
	class BSSkin__Instance_Storage : public ObjectStorage <BSSkin__Instance> {};
	class BSSkin__BoneData : public BasicNode, public Niflib::BSSkin__BoneData {};
	class BSSkin__BoneData_Storage : public ObjectStorage <BSSkin__BoneData> {};
	class BSPositionData : public BasicNode, public Niflib::BSPositionData {};
	class BSPositionData_Storage : public ObjectStorage <BSPositionData> {};
	class BSConnectPoint__Parents : public BasicNode, public Niflib::BSConnectPoint__Parents {};
	class BSConnectPoint__Parents_Storage : public ObjectStorage <BSConnectPoint__Parents> {};
	class BSConnectPoint__Children : public BasicNode, public Niflib::BSConnectPoint__Children {};
	class BSConnectPoint__Children_Storage : public ObjectStorage <BSConnectPoint__Children> {};
	//Object Registration of NifNodeTree

};
#endif