#pragma once
#ifndef NifTreeObjectRegistryClasses_IncludeGuard
#define NifTreeObjectRegistryClasses_IncludeGuard

#include "..\..\SharedCode\SharedCode_NodeTrees\LooseNodeTreeTemplate.h"
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
#include "..\..\SharedCode\SharedCode_VariableLists\VariableList.h"
#include "DLLAPI.h"
#include <iostream>
#include "..\niflib\include\RefObject.h"
#include <typeinfo>

namespace ObjectRegistryClasses
{
	template <typename NifLibBaseObject>
	struct BasicNode
	{
		//Actual Node Data
		NifLibBaseObject Data;
		//Keep the name of the actual Node connected to(For use with functions like auto-connect nodes)
		std::string InternalName;
		//************************************
		// Returns StringFormat Version of Pointer of parent (Return "" if no parent exists)
		// Method:    GetParentPointerString
		// FullName:  ObjectRegistryClasses::BasicNode<NifLibBaseObject>::GetParentPointerString
		// Access:    public 
		// Returns:   std::string
		// Qualifier:
		//************************************
		std::string GetParentPointerString()
		{
			std::string ExtractedData = "";
			//std::string ParentTypeName;
			//Create code to check for if function exists later
			if(Data.GetParent() != null)
			{
				//ParentTypeName = Data.GetParent()->GetType().GetTypeName();
				ExtractedData = StringFunctions::ConvertPointerToStringAddressV2(Data.GetParent());
			}
			else
			{
				ExtractedData = "";
			}
			return ExtractedData;
		}
		NifLibBaseObject* GetParent()
		{
			try
			{
				if(Data.GetParent() == null)
				{
					return nullptr;
				}
				else
				{
					return Data.GetParent();
				}
			}
			catch(std::exception& e)
			{
				try
				{
					std::string NodeType = typeid(NifLibBaseObject).name();
					cout << "GetParentFunction doesn't exist for "<< NodeType <<".\n";
				}
				catch(bad_typeid)
				{
					cout << "GetParentFunction doesn't exist(Failed to retrieve NodeType string)\n";
				}
				return nullptr;
			}
		}
		std::string GetDataType()
		{
			std::string NodeType = "";
			try
			{
				NodeType = typeid(NifLibBaseObject).name();
			}
			catch(bad_typeid)
			{
				cout << "Failed to retrieve NodeType string.\n";
			}
			return NodeType;
		}
	};
	template <typename NodeElementType>
	class DLL_API ObjectStorage : public VariableList<NodeType>
	{
		friend NifLibBaseObject;
	public:
		//Output to String all asString Functions within Storage
		std::string asString()
		{
			std::string StringOutput = "";
			//Create code for this later
			return StringOutput;
		}
		//NifLibBaseObject = things such as Niflib::NiObject
		//Converting from NiObjectRef -> NifLibBaseObject
		NifLibBaseObject ConvertToNifLibBaseObject(Niflib::NiObjectRef TargetNodeData)
		{
			//Brute force conversion to NiflibBaseObject for now(requires removing protected status from _object)
			friend NifLibBaseObject;
			NifLibBaseObject ConversionObject = (NifLibBaseObject) *TargetNodeData._object;
			return ConversionObject;
		}
		//************************************
		// Method:    AddDataV2
		// FullName:  ObjectRegistryClasses::ObjectStorage::AddDataV2
		// Access:    public
		// Returns:   size_t
		// Qualifier:
		// Parameter: NodeTreeType * TargetNodeTree
		// Parameter: std::string InternalNameTemp
		//************************************
		template <typename NodeTreeType>
		size_t AddDataV2(NodeTreeType* TargetNodeTree, std::string InternalNameTemp)
		{
			size_t Index = Size();
			AddData();
			NifLibBaseObject* CurrentNode = GetElementPointerV2(Index);
			TargetNodeTree->CurrentNodeInternalName = TargetNodeTree->GenerateUnusedInternalName(InternalNameTemp);
			CurrentNode->InternalName = TargetNodeTree->CurrentNodeInternalName;
			return Index;
		}
		//************************************
		// Method:    AddData
		// FullName:  ObjectRegistryClasses::ObjectStorage<NifLibBaseObject>::AddData
		// Access:    public
		// Returns:   size_t
		// Qualifier:
		// Parameter: std::string InternalNameTemp
		//************************************
		size_t AddData(std::string InternalNameTemp)
		{
			size_t Index = Size();
			AddData();
			NodeType* CurrentNode = GetElementPointerV2(Index);
			CurrentNode->InternalName = InternalNameTemp;
			return Index;
		}
		//************************************
		// Performs Read function on last Node added to the VariableList
		// Method:    Read
		// FullName:  ObjectRegistryClasses::ObjectStorage<NifLibBaseObject>::Read
		// Access:    public
		// Returns:   void
		// Qualifier:
		// Parameter: std::string ObjectType
		// Parameter: istream & in
		// Parameter: list<unsigned int> & link_stack
		// Parameter: const Niflib::NifInfo & info
		//************************************
		void Read(istream& in, list<unsigned int> & link_stack, const Niflib::NifInfo & info)
		{
			size_t Index = Size() - 1;
			NodeType* CurrentNode = GetElementPointerV2(Index);
			CurrentNode->Data.Read(ObjectType, in, info);
		}
		//************************************
		// Used mainly by CopyNodeToTree
		// Method:    AddData
		// FullName:  ObjectRegistryClasses::ObjectStorage<NifLibBaseObject>::AddData
		// Access:    public
		// Returns:   size_t
		// Qualifier:
		// Parameter: std::string InternalNameTemp
		// Parameter: Niflib::NiObjectRef TargetNodeData
		//************************************
		size_t AddData(std::string InternalNameTemp, Niflib::NiObjectRef TargetNodeData)
		{
			size_t Index = Size();
			NodeType NodeData = ConvertToNifLibBaseObject(TargetNodeData);
			Add(NodeData);
			NodeType* CurrentNode = GetElementPointerV2(Index);
			CurrentNode->InternalName = InternalNameTemp;
			return Index;
		}
		std::string GetElementSummary(size_t Index)
		{
			std::string ElementInfoString = "";
			NodeType* CurrentNode = GetElementPointerV2(Index);
			ElementInfoString = CurrentNode->Data.asString(true);
			return ElementInfoString;
		}
	};
	//Stores the Actual Node data Specifics (ObjectRegistry Node class-section)
	using NiObject = Niflib::NiObject;
	class DLL_API NiObjectNode : public BasicNode <NiObject> {};
	class DLL_API NiObject_Storage : public ObjectStorage <NiObjectNode> {};
	using Ni3dsAlphaAnimator = Niflib::Ni3dsAlphaAnimator;
	class DLL_API Ni3dsAlphaAnimatorNode : public BasicNode <Ni3dsAlphaAnimator> {};
	class DLL_API Ni3dsAlphaAnimator_Storage : public ObjectStorage <Ni3dsAlphaAnimatorNode> {};
	using Ni3dsAnimationNode = Niflib::Ni3dsAnimationNode;
	class DLL_API Ni3dsAnimationNodeNode : public BasicNode <Ni3dsAnimationNode> {};
	class DLL_API Ni3dsAnimationNode_Storage : public ObjectStorage <Ni3dsAnimationNodeNode> {};
	using Ni3dsColorAnimator = Niflib::Ni3dsColorAnimator;
	class DLL_API Ni3dsColorAnimatorNode : public BasicNode <Ni3dsColorAnimator> {};
	class DLL_API Ni3dsColorAnimator_Storage : public ObjectStorage <Ni3dsColorAnimatorNode> {};
	using Ni3dsMorphShape = Niflib::Ni3dsMorphShape;
	class DLL_API Ni3dsMorphShapeNode : public BasicNode <Ni3dsMorphShape> {};
	class DLL_API Ni3dsMorphShape_Storage : public ObjectStorage <Ni3dsMorphShapeNode> {};
	using Ni3dsParticleSystem = Niflib::Ni3dsParticleSystem;
	class DLL_API Ni3dsParticleSystemNode : public BasicNode <Ni3dsParticleSystem> {};
	class DLL_API Ni3dsParticleSystem_Storage : public ObjectStorage <Ni3dsParticleSystemNode> {};
	using Ni3dsPathController = Niflib::Ni3dsPathController;
	class DLL_API Ni3dsPathControllerNode : public BasicNode <Ni3dsPathController> {};
	class DLL_API Ni3dsPathController_Storage : public ObjectStorage <Ni3dsPathControllerNode> {};
	using NiParticleModifier = Niflib::NiParticleModifier;
	class DLL_API NiParticleModifierNode : public BasicNode <NiParticleModifier> {};
	class DLL_API NiParticleModifier_Storage : public ObjectStorage <NiParticleModifierNode> {};
	using NiPSysCollider = Niflib::NiPSysCollider;
	class DLL_API NiPSysColliderNode : public BasicNode <NiPSysCollider> {};
	class DLL_API NiPSysCollider_Storage : public ObjectStorage <NiPSysColliderNode> {};
	using bhkRefObject = Niflib::bhkRefObject;
	class DLL_API bhkRefObjectNode : public BasicNode <bhkRefObject> {};
	class DLL_API bhkRefObject_Storage : public ObjectStorage <bhkRefObjectNode> {};
	using bhkSerializable = Niflib::bhkSerializable;
	class DLL_API bhkSerializableNode : public BasicNode <bhkSerializable> {};
	class DLL_API bhkSerializable_Storage : public ObjectStorage <bhkSerializableNode> {};
	using bhkWorldObject = Niflib::bhkWorldObject;
	class DLL_API bhkWorldObjectNode : public BasicNode <bhkWorldObject> {};
	class DLL_API bhkWorldObject_Storage : public ObjectStorage <bhkWorldObjectNode> {};
	using bhkPhantom = Niflib::bhkPhantom;
	class DLL_API bhkPhantomNode : public BasicNode <bhkPhantom> {};
	class DLL_API bhkPhantom_Storage : public ObjectStorage <bhkPhantomNode> {};
	using bhkShapePhantom = Niflib::bhkShapePhantom;
	class DLL_API bhkShapePhantomNode : public BasicNode <bhkShapePhantom> {};
	class DLL_API bhkShapePhantom_Storage : public ObjectStorage <bhkShapePhantomNode> {};
	using bhkSimpleShapePhantom = Niflib::bhkSimpleShapePhantom;
	class DLL_API bhkSimpleShapePhantomNode : public BasicNode <bhkSimpleShapePhantom> {};
	class DLL_API bhkSimpleShapePhantom_Storage : public ObjectStorage <bhkSimpleShapePhantomNode> {};
	using bhkEntity = Niflib::bhkEntity;
	class DLL_API bhkEntityNode : public BasicNode <bhkEntity> {};
	class DLL_API bhkEntity_Storage : public ObjectStorage <bhkEntityNode> {};
	using bhkRigidBody = Niflib::bhkRigidBody;
	class DLL_API bhkRigidBodyNode : public BasicNode <bhkRigidBody> {};
	class DLL_API bhkRigidBody_Storage : public ObjectStorage <bhkRigidBodyNode> {};
	using bhkRigidBodyT = Niflib::bhkRigidBodyT;
	class DLL_API bhkRigidBodyTNode : public BasicNode <bhkRigidBodyT> {};
	class DLL_API bhkRigidBodyT_Storage : public ObjectStorage <bhkRigidBodyTNode> {};
	using bhkConstraint = Niflib::bhkConstraint;
	class DLL_API bhkConstraintNode : public BasicNode <bhkConstraint> {};
	class DLL_API bhkConstraint_Storage : public ObjectStorage <bhkConstraintNode> {};
	using bhkLimitedHingeConstraint = Niflib::bhkLimitedHingeConstraint;
	class DLL_API bhkLimitedHingeConstraintNode : public BasicNode <bhkLimitedHingeConstraint> {};
	class DLL_API bhkLimitedHingeConstraint_Storage : public ObjectStorage <bhkLimitedHingeConstraintNode> {};
	using bhkMalleableConstraint = Niflib::bhkMalleableConstraint;
	class DLL_API bhkMalleableConstraintNode : public BasicNode <bhkMalleableConstraint> {};
	class DLL_API bhkMalleableConstraint_Storage : public ObjectStorage <bhkMalleableConstraintNode> {};
	using bhkStiffSpringConstraint = Niflib::bhkStiffSpringConstraint;
	class DLL_API bhkStiffSpringConstraintNode : public BasicNode <bhkStiffSpringConstraint> {};
	class DLL_API bhkStiffSpringConstraint_Storage : public ObjectStorage <bhkStiffSpringConstraintNode> {};
	using bhkRagdollConstraint = Niflib::bhkRagdollConstraint;
	class DLL_API bhkRagdollConstraintNode : public BasicNode <bhkRagdollConstraint> {};
	class DLL_API bhkRagdollConstraint_Storage : public ObjectStorage <bhkRagdollConstraintNode> {};
	using bhkPrismaticConstraint = Niflib::bhkPrismaticConstraint;
	class DLL_API bhkPrismaticConstraintNode : public BasicNode <bhkPrismaticConstraint> {};
	class DLL_API bhkPrismaticConstraint_Storage : public ObjectStorage <bhkPrismaticConstraintNode> {};
	using bhkHingeConstraint = Niflib::bhkHingeConstraint;
	class DLL_API bhkHingeConstraintNode : public BasicNode <bhkHingeConstraint> {};
	class DLL_API bhkHingeConstraint_Storage : public ObjectStorage <bhkHingeConstraintNode> {};
	using bhkBallAndSocketConstraint = Niflib::bhkBallAndSocketConstraint;
	class DLL_API bhkBallAndSocketConstraintNode : public BasicNode <bhkBallAndSocketConstraint> {};
	class DLL_API bhkBallAndSocketConstraint_Storage : public ObjectStorage <bhkBallAndSocketConstraintNode> {};
	using bhkBallSocketConstraintChain = Niflib::bhkBallSocketConstraintChain;
	class DLL_API bhkBallSocketConstraintChainNode : public BasicNode <bhkBallSocketConstraintChain> {};
	class DLL_API bhkBallSocketConstraintChain_Storage : public ObjectStorage <bhkBallSocketConstraintChainNode> {};
	using bhkShape = Niflib::bhkShape;
	class DLL_API bhkShapeNode : public BasicNode <bhkShape> {};
	class DLL_API bhkShape_Storage : public ObjectStorage <bhkShapeNode> {};
	using bhkTransformShape = Niflib::bhkTransformShape;
	class DLL_API bhkTransformShapeNode : public BasicNode <bhkTransformShape> {};
	class DLL_API bhkTransformShape_Storage : public ObjectStorage <bhkTransformShapeNode> {};
	using bhkSphereRepShape = Niflib::bhkSphereRepShape;
	class DLL_API bhkSphereRepShapeNode : public BasicNode <bhkSphereRepShape> {};
	class DLL_API bhkSphereRepShape_Storage : public ObjectStorage <bhkSphereRepShapeNode> {};
	using bhkConvexShape = Niflib::bhkConvexShape;
	class DLL_API bhkConvexShapeNode : public BasicNode <bhkConvexShape> {};
	class DLL_API bhkConvexShape_Storage : public ObjectStorage <bhkConvexShapeNode> {};
	using bhkSphereShape = Niflib::bhkSphereShape;
	class DLL_API bhkSphereShapeNode : public BasicNode <bhkSphereShape> {};
	class DLL_API bhkSphereShape_Storage : public ObjectStorage <bhkSphereShapeNode> {};
	using bhkCapsuleShape = Niflib::bhkCapsuleShape;
	class DLL_API bhkCapsuleShapeNode : public BasicNode <bhkCapsuleShape> {};
	class DLL_API bhkCapsuleShape_Storage : public ObjectStorage <bhkCapsuleShapeNode> {};
	using bhkBoxShape = Niflib::bhkBoxShape;
	class DLL_API bhkBoxShapeNode : public BasicNode <bhkBoxShape> {};
	class DLL_API bhkBoxShape_Storage : public ObjectStorage <bhkBoxShapeNode> {};
	using bhkConvexVerticesShape = Niflib::bhkConvexVerticesShape;
	class DLL_API bhkConvexVerticesShapeNode : public BasicNode <bhkConvexVerticesShape> {};
	class DLL_API bhkConvexVerticesShape_Storage : public ObjectStorage <bhkConvexVerticesShapeNode> {};
	using bhkConvexTransformShape = Niflib::bhkConvexTransformShape;
	class DLL_API bhkConvexTransformShapeNode : public BasicNode <bhkConvexTransformShape> {};
	class DLL_API bhkConvexTransformShape_Storage : public ObjectStorage <bhkConvexTransformShapeNode> {};
	using bhkMultiSphereShape = Niflib::bhkMultiSphereShape;
	class DLL_API bhkMultiSphereShapeNode : public BasicNode <bhkMultiSphereShape> {};
	class DLL_API bhkMultiSphereShape_Storage : public ObjectStorage <bhkMultiSphereShapeNode> {};
	using bhkBvTreeShape = Niflib::bhkBvTreeShape;
	class DLL_API bhkBvTreeShapeNode : public BasicNode <bhkBvTreeShape> {};
	class DLL_API bhkBvTreeShape_Storage : public ObjectStorage <bhkBvTreeShapeNode> {};
	using bhkMoppBvTreeShape = Niflib::bhkMoppBvTreeShape;
	class DLL_API bhkMoppBvTreeShapeNode : public BasicNode <bhkMoppBvTreeShape> {};
	class DLL_API bhkMoppBvTreeShape_Storage : public ObjectStorage <bhkMoppBvTreeShapeNode> {};
	using bhkShapeCollection = Niflib::bhkShapeCollection;
	class DLL_API bhkShapeCollectionNode : public BasicNode <bhkShapeCollection> {};
	class DLL_API bhkShapeCollection_Storage : public ObjectStorage <bhkShapeCollectionNode> {};
	using bhkListShape = Niflib::bhkListShape;
	class DLL_API bhkListShapeNode : public BasicNode <bhkListShape> {};
	class DLL_API bhkListShape_Storage : public ObjectStorage <bhkListShapeNode> {};
	using bhkMeshShape = Niflib::bhkMeshShape;
	class DLL_API bhkMeshShapeNode : public BasicNode <bhkMeshShape> {};
	class DLL_API bhkMeshShape_Storage : public ObjectStorage <bhkMeshShapeNode> {};
	using bhkPackedNiTriStripsShape = Niflib::bhkPackedNiTriStripsShape;
	class DLL_API bhkPackedNiTriStripsShapeNode : public BasicNode <bhkPackedNiTriStripsShape> {};
	class DLL_API bhkPackedNiTriStripsShape_Storage : public ObjectStorage <bhkPackedNiTriStripsShapeNode> {};
	using bhkNiTriStripsShape = Niflib::bhkNiTriStripsShape;
	class DLL_API bhkNiTriStripsShapeNode : public BasicNode <bhkNiTriStripsShape> {};
	class DLL_API bhkNiTriStripsShape_Storage : public ObjectStorage <bhkNiTriStripsShapeNode> {};
	using NiExtraData = Niflib::NiExtraData;
	class DLL_API NiExtraDataNode : public BasicNode <NiExtraData> {};
	class DLL_API NiExtraData_Storage : public ObjectStorage <NiExtraDataNode> {};
	using NiInterpolator = Niflib::NiInterpolator;
	class DLL_API NiInterpolatorNode : public BasicNode <NiInterpolator> {};
	class DLL_API NiInterpolator_Storage : public ObjectStorage <NiInterpolatorNode> {};
	using NiKeyBasedInterpolator = Niflib::NiKeyBasedInterpolator;
	class DLL_API NiKeyBasedInterpolatorNode : public BasicNode <NiKeyBasedInterpolator> {};
	class DLL_API NiKeyBasedInterpolator_Storage : public ObjectStorage <NiKeyBasedInterpolatorNode> {};
	using NiFloatInterpolator = Niflib::NiFloatInterpolator;
	class DLL_API NiFloatInterpolatorNode : public BasicNode <NiFloatInterpolator> {};
	class DLL_API NiFloatInterpolator_Storage : public ObjectStorage <NiFloatInterpolatorNode> {};
	using NiTransformInterpolator = Niflib::NiTransformInterpolator;
	class DLL_API NiTransformInterpolatorNode : public BasicNode <NiTransformInterpolator> {};
	class DLL_API NiTransformInterpolator_Storage : public ObjectStorage <NiTransformInterpolatorNode> {};
	using NiPoint3Interpolator = Niflib::NiPoint3Interpolator;
	class DLL_API NiPoint3InterpolatorNode : public BasicNode <NiPoint3Interpolator> {};
	class DLL_API NiPoint3Interpolator_Storage : public ObjectStorage <NiPoint3InterpolatorNode> {};
	using NiPathInterpolator = Niflib::NiPathInterpolator;
	class DLL_API NiPathInterpolatorNode : public BasicNode <NiPathInterpolator> {};
	class DLL_API NiPathInterpolator_Storage : public ObjectStorage <NiPathInterpolatorNode> {};
	using NiBoolInterpolator = Niflib::NiBoolInterpolator;
	class DLL_API NiBoolInterpolatorNode : public BasicNode <NiBoolInterpolator> {};
	class DLL_API NiBoolInterpolator_Storage : public ObjectStorage <NiBoolInterpolatorNode> {};
	using NiBoolTimelineInterpolator = Niflib::NiBoolTimelineInterpolator;
	class DLL_API NiBoolTimelineInterpolatorNode : public BasicNode <NiBoolTimelineInterpolator> {};
	class DLL_API NiBoolTimelineInterpolator_Storage : public ObjectStorage <NiBoolTimelineInterpolatorNode> {};
	using NiBlendInterpolator = Niflib::NiBlendInterpolator;
	class DLL_API NiBlendInterpolatorNode : public BasicNode <NiBlendInterpolator> {};
	class DLL_API NiBlendInterpolator_Storage : public ObjectStorage <NiBlendInterpolatorNode> {};
	using NiBSplineInterpolator = Niflib::NiBSplineInterpolator;
	class DLL_API NiBSplineInterpolatorNode : public BasicNode <NiBSplineInterpolator> {};
	class DLL_API NiBSplineInterpolator_Storage : public ObjectStorage <NiBSplineInterpolatorNode> {};
	using NiObjectNET = Niflib::NiObjectNET;
	class DLL_API NiObjectNETNode : public BasicNode <NiObjectNET> {};
	class DLL_API NiObjectNET_Storage : public ObjectStorage <NiObjectNETNode> {};
	using NiCollisionObject = Niflib::NiCollisionObject;
	class DLL_API NiCollisionObjectNode : public BasicNode <NiCollisionObject> {};
	class DLL_API NiCollisionObject_Storage : public ObjectStorage <NiCollisionObjectNode> {};
	using NiCollisionData = Niflib::NiCollisionData;
	class DLL_API NiCollisionDataNode : public BasicNode <NiCollisionData> {};
	class DLL_API NiCollisionData_Storage : public ObjectStorage <NiCollisionDataNode> {};
	using bhkNiCollisionObject = Niflib::bhkNiCollisionObject;
	class DLL_API bhkNiCollisionObjectNode : public BasicNode <bhkNiCollisionObject> {};
	class DLL_API bhkNiCollisionObject_Storage : public ObjectStorage <bhkNiCollisionObjectNode> {};
	using bhkCollisionObject = Niflib::bhkCollisionObject;
	class DLL_API bhkCollisionObjectNode : public BasicNode <bhkCollisionObject> {};
	class DLL_API bhkCollisionObject_Storage : public ObjectStorage <bhkCollisionObjectNode> {};
	using bhkBlendCollisionObject = Niflib::bhkBlendCollisionObject;
	class DLL_API bhkBlendCollisionObjectNode : public BasicNode <bhkBlendCollisionObject> {};
	class DLL_API bhkBlendCollisionObject_Storage : public ObjectStorage <bhkBlendCollisionObjectNode> {};
	using bhkPCollisionObject = Niflib::bhkPCollisionObject;
	class DLL_API bhkPCollisionObjectNode : public BasicNode <bhkPCollisionObject> {};
	class DLL_API bhkPCollisionObject_Storage : public ObjectStorage <bhkPCollisionObjectNode> {};
	using bhkSPCollisionObject = Niflib::bhkSPCollisionObject;
	class DLL_API bhkSPCollisionObjectNode : public BasicNode <bhkSPCollisionObject> {};
	class DLL_API bhkSPCollisionObject_Storage : public ObjectStorage <bhkSPCollisionObjectNode> {};
	using NiAVObject = Niflib::NiAVObject;
	class DLL_API NiAVObjectNode : public BasicNode <NiAVObject> {};
	class DLL_API NiAVObject_Storage : public ObjectStorage <NiAVObjectNode> {};
	using NiDynamicEffect = Niflib::NiDynamicEffect;
	class DLL_API NiDynamicEffectNode : public BasicNode <NiDynamicEffect> {};
	class DLL_API NiDynamicEffect_Storage : public ObjectStorage <NiDynamicEffectNode> {};
	using NiLight = Niflib::NiLight;
	class DLL_API NiLightNode : public BasicNode <NiLight> {};
	class DLL_API NiLight_Storage : public ObjectStorage <NiLightNode> {};
	using NiProperty = Niflib::NiProperty;
	class DLL_API NiPropertyNode : public BasicNode <NiProperty> {};
	class DLL_API NiProperty_Storage : public ObjectStorage <NiPropertyNode> {};
	using NiTransparentProperty = Niflib::NiTransparentProperty;
	class DLL_API NiTransparentPropertyNode : public BasicNode <NiTransparentProperty> {};
	class DLL_API NiTransparentProperty_Storage : public ObjectStorage <NiTransparentPropertyNode> {};
	using NiPSysModifier = Niflib::NiPSysModifier;
	class DLL_API NiPSysModifierNode : public BasicNode <NiPSysModifier> {};
	class DLL_API NiPSysModifier_Storage : public ObjectStorage <NiPSysModifierNode> {};
	using NiPSysEmitter = Niflib::NiPSysEmitter;
	class DLL_API NiPSysEmitterNode : public BasicNode <NiPSysEmitter> {};
	class DLL_API NiPSysEmitter_Storage : public ObjectStorage <NiPSysEmitterNode> {};
	using NiPSysVolumeEmitter = Niflib::NiPSysVolumeEmitter;
	class DLL_API NiPSysVolumeEmitterNode : public BasicNode <NiPSysVolumeEmitter> {};
	class DLL_API NiPSysVolumeEmitter_Storage : public ObjectStorage <NiPSysVolumeEmitterNode> {};
	using NiTimeController = Niflib::NiTimeController;
	class DLL_API NiTimeControllerNode : public BasicNode <NiTimeController> {};
	class DLL_API NiTimeController_Storage : public ObjectStorage <NiTimeControllerNode> {};
	using NiInterpController = Niflib::NiInterpController;
	class DLL_API NiInterpControllerNode : public BasicNode <NiInterpController> {};
	class DLL_API NiInterpController_Storage : public ObjectStorage <NiInterpControllerNode> {};
	using NiMultiTargetTransformController = Niflib::NiMultiTargetTransformController;
	class DLL_API NiMultiTargetTransformControllerNode : public BasicNode <NiMultiTargetTransformController> {};
	class DLL_API NiMultiTargetTransformController_Storage : public ObjectStorage <NiMultiTargetTransformControllerNode> {};
	using NiGeomMorpherController = Niflib::NiGeomMorpherController;
	class DLL_API NiGeomMorpherControllerNode : public BasicNode <NiGeomMorpherController> {};
	class DLL_API NiGeomMorpherController_Storage : public ObjectStorage <NiGeomMorpherControllerNode> {};
	using NiMorphController = Niflib::NiMorphController;
	class DLL_API NiMorphControllerNode : public BasicNode <NiMorphController> {};
	class DLL_API NiMorphController_Storage : public ObjectStorage <NiMorphControllerNode> {};
	using NiMorpherController = Niflib::NiMorpherController;
	class DLL_API NiMorpherControllerNode : public BasicNode <NiMorpherController> {};
	class DLL_API NiMorpherController_Storage : public ObjectStorage <NiMorpherControllerNode> {};
	using NiSingleInterpController = Niflib::NiSingleInterpController;
	class DLL_API NiSingleInterpControllerNode : public BasicNode <NiSingleInterpController> {};
	class DLL_API NiSingleInterpController_Storage : public ObjectStorage <NiSingleInterpControllerNode> {};
	using NiKeyframeController = Niflib::NiKeyframeController;
	class DLL_API NiKeyframeControllerNode : public BasicNode <NiKeyframeController> {};
	class DLL_API NiKeyframeController_Storage : public ObjectStorage <NiKeyframeControllerNode> {};
	using NiTransformController = Niflib::NiTransformController;
	class DLL_API NiTransformControllerNode : public BasicNode <NiTransformController> {};
	class DLL_API NiTransformController_Storage : public ObjectStorage <NiTransformControllerNode> {};
	using NiPSysModifierCtlr = Niflib::NiPSysModifierCtlr;
	class DLL_API NiPSysModifierCtlrNode : public BasicNode <NiPSysModifierCtlr> {};
	class DLL_API NiPSysModifierCtlr_Storage : public ObjectStorage <NiPSysModifierCtlrNode> {};
	using NiPSysEmitterCtlr = Niflib::NiPSysEmitterCtlr;
	class DLL_API NiPSysEmitterCtlrNode : public BasicNode <NiPSysEmitterCtlr> {};
	class DLL_API NiPSysEmitterCtlr_Storage : public ObjectStorage <NiPSysEmitterCtlrNode> {};
	using NiPSysModifierBoolCtlr = Niflib::NiPSysModifierBoolCtlr;
	class DLL_API NiPSysModifierBoolCtlrNode : public BasicNode <NiPSysModifierBoolCtlr> {};
	class DLL_API NiPSysModifierBoolCtlr_Storage : public ObjectStorage <NiPSysModifierBoolCtlrNode> {};
	using NiPSysModifierActiveCtlr = Niflib::NiPSysModifierActiveCtlr;
	class DLL_API NiPSysModifierActiveCtlrNode : public BasicNode <NiPSysModifierActiveCtlr> {};
	class DLL_API NiPSysModifierActiveCtlr_Storage : public ObjectStorage <NiPSysModifierActiveCtlrNode> {};
	using NiPSysModifierFloatCtlr = Niflib::NiPSysModifierFloatCtlr;
	class DLL_API NiPSysModifierFloatCtlrNode : public BasicNode <NiPSysModifierFloatCtlr> {};
	class DLL_API NiPSysModifierFloatCtlr_Storage : public ObjectStorage <NiPSysModifierFloatCtlrNode> {};
	using NiPSysEmitterDeclinationCtlr = Niflib::NiPSysEmitterDeclinationCtlr;
	class DLL_API NiPSysEmitterDeclinationCtlrNode : public BasicNode <NiPSysEmitterDeclinationCtlr> {};
	class DLL_API NiPSysEmitterDeclinationCtlr_Storage : public ObjectStorage <NiPSysEmitterDeclinationCtlrNode> {};
	using NiPSysEmitterDeclinationVarCtlr = Niflib::NiPSysEmitterDeclinationVarCtlr;
	class DLL_API NiPSysEmitterDeclinationVarCtlrNode : public BasicNode <NiPSysEmitterDeclinationVarCtlr> {};
	class DLL_API NiPSysEmitterDeclinationVarCtlr_Storage : public ObjectStorage <NiPSysEmitterDeclinationVarCtlrNode> {};
	using NiPSysEmitterInitialRadiusCtlr = Niflib::NiPSysEmitterInitialRadiusCtlr;
	class DLL_API NiPSysEmitterInitialRadiusCtlrNode : public BasicNode <NiPSysEmitterInitialRadiusCtlr> {};
	class DLL_API NiPSysEmitterInitialRadiusCtlr_Storage : public ObjectStorage <NiPSysEmitterInitialRadiusCtlrNode> {};
	using NiPSysEmitterLifeSpanCtlr = Niflib::NiPSysEmitterLifeSpanCtlr;
	class DLL_API NiPSysEmitterLifeSpanCtlrNode : public BasicNode <NiPSysEmitterLifeSpanCtlr> {};
	class DLL_API NiPSysEmitterLifeSpanCtlr_Storage : public ObjectStorage <NiPSysEmitterLifeSpanCtlrNode> {};
	using NiPSysEmitterSpeedCtlr = Niflib::NiPSysEmitterSpeedCtlr;
	class DLL_API NiPSysEmitterSpeedCtlrNode : public BasicNode <NiPSysEmitterSpeedCtlr> {};
	class DLL_API NiPSysEmitterSpeedCtlr_Storage : public ObjectStorage <NiPSysEmitterSpeedCtlrNode> {};
	using NiPSysGravityStrengthCtlr = Niflib::NiPSysGravityStrengthCtlr;
	class DLL_API NiPSysGravityStrengthCtlrNode : public BasicNode <NiPSysGravityStrengthCtlr> {};
	class DLL_API NiPSysGravityStrengthCtlr_Storage : public ObjectStorage <NiPSysGravityStrengthCtlrNode> {};
	using NiFloatInterpController = Niflib::NiFloatInterpController;
	class DLL_API NiFloatInterpControllerNode : public BasicNode <NiFloatInterpController> {};
	class DLL_API NiFloatInterpController_Storage : public ObjectStorage <NiFloatInterpControllerNode> {};
	using NiFlipController = Niflib::NiFlipController;
	class DLL_API NiFlipControllerNode : public BasicNode <NiFlipController> {};
	class DLL_API NiFlipController_Storage : public ObjectStorage <NiFlipControllerNode> {};
	using NiAlphaController = Niflib::NiAlphaController;
	class DLL_API NiAlphaControllerNode : public BasicNode <NiAlphaController> {};
	class DLL_API NiAlphaController_Storage : public ObjectStorage <NiAlphaControllerNode> {};
	using NiTextureTransformController = Niflib::NiTextureTransformController;
	class DLL_API NiTextureTransformControllerNode : public BasicNode <NiTextureTransformController> {};
	class DLL_API NiTextureTransformController_Storage : public ObjectStorage <NiTextureTransformControllerNode> {};
	using NiLightDimmerController = Niflib::NiLightDimmerController;
	class DLL_API NiLightDimmerControllerNode : public BasicNode <NiLightDimmerController> {};
	class DLL_API NiLightDimmerController_Storage : public ObjectStorage <NiLightDimmerControllerNode> {};
	using NiBoolInterpController = Niflib::NiBoolInterpController;
	class DLL_API NiBoolInterpControllerNode : public BasicNode <NiBoolInterpController> {};
	class DLL_API NiBoolInterpController_Storage : public ObjectStorage <NiBoolInterpControllerNode> {};
	using NiVisController = Niflib::NiVisController;
	class DLL_API NiVisControllerNode : public BasicNode <NiVisController> {};
	class DLL_API NiVisController_Storage : public ObjectStorage <NiVisControllerNode> {};
	using NiPoint3InterpController = Niflib::NiPoint3InterpController;
	class DLL_API NiPoint3InterpControllerNode : public BasicNode <NiPoint3InterpController> {};
	class DLL_API NiPoint3InterpController_Storage : public ObjectStorage <NiPoint3InterpControllerNode> {};
	using NiMaterialColorController = Niflib::NiMaterialColorController;
	class DLL_API NiMaterialColorControllerNode : public BasicNode <NiMaterialColorController> {};
	class DLL_API NiMaterialColorController_Storage : public ObjectStorage <NiMaterialColorControllerNode> {};
	using NiLightColorController = Niflib::NiLightColorController;
	class DLL_API NiLightColorControllerNode : public BasicNode <NiLightColorController> {};
	class DLL_API NiLightColorController_Storage : public ObjectStorage <NiLightColorControllerNode> {};
	using NiExtraDataController = Niflib::NiExtraDataController;
	class DLL_API NiExtraDataControllerNode : public BasicNode <NiExtraDataController> {};
	class DLL_API NiExtraDataController_Storage : public ObjectStorage <NiExtraDataControllerNode> {};
	using NiFloatExtraDataController = Niflib::NiFloatExtraDataController;
	class DLL_API NiFloatExtraDataControllerNode : public BasicNode <NiFloatExtraDataController> {};
	class DLL_API NiFloatExtraDataController_Storage : public ObjectStorage <NiFloatExtraDataControllerNode> {};
	using NiBoneLODController = Niflib::NiBoneLODController;
	class DLL_API NiBoneLODControllerNode : public BasicNode <NiBoneLODController> {};
	class DLL_API NiBoneLODController_Storage : public ObjectStorage <NiBoneLODControllerNode> {};
	using NiBSBoneLODController = Niflib::NiBSBoneLODController;
	class DLL_API NiBSBoneLODControllerNode : public BasicNode <NiBSBoneLODController> {};
	class DLL_API NiBSBoneLODController_Storage : public ObjectStorage <NiBSBoneLODControllerNode> {};
	using NiGeometry = Niflib::NiGeometry;
	class DLL_API NiGeometryNode : public BasicNode <NiGeometry> {};
	class DLL_API NiGeometry_Storage : public ObjectStorage <NiGeometryNode> {};
	using NiTriBasedGeom = Niflib::NiTriBasedGeom;
	class DLL_API NiTriBasedGeomNode : public BasicNode <NiTriBasedGeom> {};
	class DLL_API NiTriBasedGeom_Storage : public ObjectStorage <NiTriBasedGeomNode> {};
	using NiGeometryData = Niflib::NiGeometryData;
	class DLL_API NiGeometryDataNode : public BasicNode <NiGeometryData> {};
	class DLL_API NiGeometryData_Storage : public ObjectStorage <NiGeometryDataNode> {};
	using AbstractAdditionalGeometryData = Niflib::AbstractAdditionalGeometryData;
	class DLL_API AbstractAdditionalGeometryDataNode : public BasicNode <AbstractAdditionalGeometryData> {};
	class DLL_API AbstractAdditionalGeometryData_Storage : public ObjectStorage <AbstractAdditionalGeometryDataNode> {};
	using NiTriBasedGeomData = Niflib::NiTriBasedGeomData;
	class DLL_API NiTriBasedGeomDataNode : public BasicNode <NiTriBasedGeomData> {};
	class DLL_API NiTriBasedGeomData_Storage : public ObjectStorage <NiTriBasedGeomDataNode> {};
	using bhkBlendController = Niflib::bhkBlendController;
	class DLL_API bhkBlendControllerNode : public BasicNode <bhkBlendController> {};
	class DLL_API bhkBlendController_Storage : public ObjectStorage <bhkBlendControllerNode> {};
	using BSBound = Niflib::BSBound;
	class DLL_API BSBoundNode : public BasicNode <BSBound> {};
	class DLL_API BSBound_Storage : public ObjectStorage <BSBoundNode> {};
	using BSFurnitureMarker = Niflib::BSFurnitureMarker;
	class DLL_API BSFurnitureMarkerNode : public BasicNode <BSFurnitureMarker> {};
	class DLL_API BSFurnitureMarker_Storage : public ObjectStorage <BSFurnitureMarkerNode> {};
	using BSParentVelocityModifier = Niflib::BSParentVelocityModifier;
	class DLL_API BSParentVelocityModifierNode : public BasicNode <BSParentVelocityModifier> {};
	class DLL_API BSParentVelocityModifier_Storage : public ObjectStorage <BSParentVelocityModifierNode> {};
	using BSPSysArrayEmitter = Niflib::BSPSysArrayEmitter;
	class DLL_API BSPSysArrayEmitterNode : public BasicNode <BSPSysArrayEmitter> {};
	class DLL_API BSPSysArrayEmitter_Storage : public ObjectStorage <BSPSysArrayEmitterNode> {};
	using BSWindModifier = Niflib::BSWindModifier;
	class DLL_API BSWindModifierNode : public BasicNode <BSWindModifier> {};
	class DLL_API BSWindModifier_Storage : public ObjectStorage <BSWindModifierNode> {};
	using hkPackedNiTriStripsData = Niflib::hkPackedNiTriStripsData;
	class DLL_API hkPackedNiTriStripsDataNode : public BasicNode <hkPackedNiTriStripsData> {};
	class DLL_API hkPackedNiTriStripsData_Storage : public ObjectStorage <hkPackedNiTriStripsDataNode> {};
	using NiAlphaProperty = Niflib::NiAlphaProperty;
	class DLL_API NiAlphaPropertyNode : public BasicNode <NiAlphaProperty> {};
	class DLL_API NiAlphaProperty_Storage : public ObjectStorage <NiAlphaPropertyNode> {};
	using NiAmbientLight = Niflib::NiAmbientLight;
	class DLL_API NiAmbientLightNode : public BasicNode <NiAmbientLight> {};
	class DLL_API NiAmbientLight_Storage : public ObjectStorage <NiAmbientLightNode> {};
	using NiParticlesData = Niflib::NiParticlesData;
	class DLL_API NiParticlesDataNode : public BasicNode <NiParticlesData> {};
	class DLL_API NiParticlesData_Storage : public ObjectStorage <NiParticlesDataNode> {};
	using NiRotatingParticlesData = Niflib::NiRotatingParticlesData;
	class DLL_API NiRotatingParticlesDataNode : public BasicNode <NiRotatingParticlesData> {};
	class DLL_API NiRotatingParticlesData_Storage : public ObjectStorage <NiRotatingParticlesDataNode> {};
	using NiAutoNormalParticlesData = Niflib::NiAutoNormalParticlesData;
	class DLL_API NiAutoNormalParticlesDataNode : public BasicNode <NiAutoNormalParticlesData> {};
	class DLL_API NiAutoNormalParticlesData_Storage : public ObjectStorage <NiAutoNormalParticlesDataNode> {};
	using NiPSysData = Niflib::NiPSysData;
	class DLL_API NiPSysDataNode : public BasicNode <NiPSysData> {};
	class DLL_API NiPSysData_Storage : public ObjectStorage <NiPSysDataNode> {};
	using NiMeshPSysData = Niflib::NiMeshPSysData;
	class DLL_API NiMeshPSysDataNode : public BasicNode <NiMeshPSysData> {};
	class DLL_API NiMeshPSysData_Storage : public ObjectStorage <NiMeshPSysDataNode> {};
	using NiBinaryExtraData = Niflib::NiBinaryExtraData;
	class DLL_API NiBinaryExtraDataNode : public BasicNode <NiBinaryExtraData> {};
	class DLL_API NiBinaryExtraData_Storage : public ObjectStorage <NiBinaryExtraDataNode> {};
	using NiBinaryVoxelExtraData = Niflib::NiBinaryVoxelExtraData;
	class DLL_API NiBinaryVoxelExtraDataNode : public BasicNode <NiBinaryVoxelExtraData> {};
	class DLL_API NiBinaryVoxelExtraData_Storage : public ObjectStorage <NiBinaryVoxelExtraDataNode> {};
	using NiBinaryVoxelData = Niflib::NiBinaryVoxelData;
	class DLL_API NiBinaryVoxelDataNode : public BasicNode <NiBinaryVoxelData> {};
	class DLL_API NiBinaryVoxelData_Storage : public ObjectStorage <NiBinaryVoxelDataNode> {};
	using NiBlendBoolInterpolator = Niflib::NiBlendBoolInterpolator;
	class DLL_API NiBlendBoolInterpolatorNode : public BasicNode <NiBlendBoolInterpolator> {};
	class DLL_API NiBlendBoolInterpolator_Storage : public ObjectStorage <NiBlendBoolInterpolatorNode> {};
	using NiBlendFloatInterpolator = Niflib::NiBlendFloatInterpolator;
	class DLL_API NiBlendFloatInterpolatorNode : public BasicNode <NiBlendFloatInterpolator> {};
	class DLL_API NiBlendFloatInterpolator_Storage : public ObjectStorage <NiBlendFloatInterpolatorNode> {};
	using NiBlendPoint3Interpolator = Niflib::NiBlendPoint3Interpolator;
	class DLL_API NiBlendPoint3InterpolatorNode : public BasicNode <NiBlendPoint3Interpolator> {};
	class DLL_API NiBlendPoint3Interpolator_Storage : public ObjectStorage <NiBlendPoint3InterpolatorNode> {};
	using NiBlendTransformInterpolator = Niflib::NiBlendTransformInterpolator;
	class DLL_API NiBlendTransformInterpolatorNode : public BasicNode <NiBlendTransformInterpolator> {};
	class DLL_API NiBlendTransformInterpolator_Storage : public ObjectStorage <NiBlendTransformInterpolatorNode> {};
	using NiBoolData = Niflib::NiBoolData;
	class DLL_API NiBoolDataNode : public BasicNode <NiBoolData> {};
	class DLL_API NiBoolData_Storage : public ObjectStorage <NiBoolDataNode> {};
	using NiBooleanExtraData = Niflib::NiBooleanExtraData;
	class DLL_API NiBooleanExtraDataNode : public BasicNode <NiBooleanExtraData> {};
	class DLL_API NiBooleanExtraData_Storage : public ObjectStorage <NiBooleanExtraDataNode> {};
	using NiBSplineBasisData = Niflib::NiBSplineBasisData;
	class DLL_API NiBSplineBasisDataNode : public BasicNode <NiBSplineBasisData> {};
	class DLL_API NiBSplineBasisData_Storage : public ObjectStorage <NiBSplineBasisDataNode> {};
	using NiBSplineFloatInterpolator = Niflib::NiBSplineFloatInterpolator;
	class DLL_API NiBSplineFloatInterpolatorNode : public BasicNode <NiBSplineFloatInterpolator> {};
	class DLL_API NiBSplineFloatInterpolator_Storage : public ObjectStorage <NiBSplineFloatInterpolatorNode> {};
	using NiBSplineCompFloatInterpolator = Niflib::NiBSplineCompFloatInterpolator;
	class DLL_API NiBSplineCompFloatInterpolatorNode : public BasicNode <NiBSplineCompFloatInterpolator> {};
	class DLL_API NiBSplineCompFloatInterpolator_Storage : public ObjectStorage <NiBSplineCompFloatInterpolatorNode> {};
	using NiBSplinePoint3Interpolator = Niflib::NiBSplinePoint3Interpolator;
	class DLL_API NiBSplinePoint3InterpolatorNode : public BasicNode <NiBSplinePoint3Interpolator> {};
	class DLL_API NiBSplinePoint3Interpolator_Storage : public ObjectStorage <NiBSplinePoint3InterpolatorNode> {};
	using NiBSplineCompPoint3Interpolator = Niflib::NiBSplineCompPoint3Interpolator;
	class DLL_API NiBSplineCompPoint3InterpolatorNode : public BasicNode <NiBSplineCompPoint3Interpolator> {};
	class DLL_API NiBSplineCompPoint3Interpolator_Storage : public ObjectStorage <NiBSplineCompPoint3InterpolatorNode> {};
	using NiBSplineTransformInterpolator = Niflib::NiBSplineTransformInterpolator;
	class DLL_API NiBSplineTransformInterpolatorNode : public BasicNode <NiBSplineTransformInterpolator> {};
	class DLL_API NiBSplineTransformInterpolator_Storage : public ObjectStorage <NiBSplineTransformInterpolatorNode> {};
	using NiBSplineCompTransformInterpolator = Niflib::NiBSplineCompTransformInterpolator;
	class DLL_API NiBSplineCompTransformInterpolatorNode : public BasicNode <NiBSplineCompTransformInterpolator> {};
	class DLL_API NiBSplineCompTransformInterpolator_Storage : public ObjectStorage <NiBSplineCompTransformInterpolatorNode> {};
	using BSRotAccumTransfInterpolator = Niflib::BSRotAccumTransfInterpolator;
	class DLL_API BSRotAccumTransfInterpolatorNode : public BasicNode <BSRotAccumTransfInterpolator> {};
	class DLL_API BSRotAccumTransfInterpolator_Storage : public ObjectStorage <BSRotAccumTransfInterpolatorNode> {};
	using NiBSplineData = Niflib::NiBSplineData;
	class DLL_API NiBSplineDataNode : public BasicNode <NiBSplineData> {};
	class DLL_API NiBSplineData_Storage : public ObjectStorage <NiBSplineDataNode> {};
	using NiCamera = Niflib::NiCamera;
	class DLL_API NiCameraNode : public BasicNode <NiCamera> {};
	class DLL_API NiCamera_Storage : public ObjectStorage <NiCameraNode> {};
	using NiColorData = Niflib::NiColorData;
	class DLL_API NiColorDataNode : public BasicNode <NiColorData> {};
	class DLL_API NiColorData_Storage : public ObjectStorage <NiColorDataNode> {};
	using NiColorExtraData = Niflib::NiColorExtraData;
	class DLL_API NiColorExtraDataNode : public BasicNode <NiColorExtraData> {};
	class DLL_API NiColorExtraData_Storage : public ObjectStorage <NiColorExtraDataNode> {};
	using NiControllerManager = Niflib::NiControllerManager;
	class DLL_API NiControllerManagerNode : public BasicNode <NiControllerManager> {};
	class DLL_API NiControllerManager_Storage : public ObjectStorage <NiControllerManagerNode> {};
	using NiSequence = Niflib::NiSequence;
	class DLL_API NiSequenceNode : public BasicNode <NiSequence> {};
	class DLL_API NiSequence_Storage : public ObjectStorage <NiSequenceNode> {};
	using NiControllerSequence = Niflib::NiControllerSequence;
	class DLL_API NiControllerSequenceNode : public BasicNode <NiControllerSequence> {};
	class DLL_API NiControllerSequence_Storage : public ObjectStorage <NiControllerSequenceNode> {};
	using NiAVObjectPalette = Niflib::NiAVObjectPalette;
	class DLL_API NiAVObjectPaletteNode : public BasicNode <NiAVObjectPalette> {};
	class DLL_API NiAVObjectPalette_Storage : public ObjectStorage <NiAVObjectPaletteNode> {};
	using NiDefaultAVObjectPalette = Niflib::NiDefaultAVObjectPalette;
	class DLL_API NiDefaultAVObjectPaletteNode : public BasicNode <NiDefaultAVObjectPalette> {};
	class DLL_API NiDefaultAVObjectPalette_Storage : public ObjectStorage <NiDefaultAVObjectPaletteNode> {};
	using NiDirectionalLight = Niflib::NiDirectionalLight;
	class DLL_API NiDirectionalLightNode : public BasicNode <NiDirectionalLight> {};
	class DLL_API NiDirectionalLight_Storage : public ObjectStorage <NiDirectionalLightNode> {};
	using NiDitherProperty = Niflib::NiDitherProperty;
	class DLL_API NiDitherPropertyNode : public BasicNode <NiDitherProperty> {};
	class DLL_API NiDitherProperty_Storage : public ObjectStorage <NiDitherPropertyNode> {};
	using NiRollController = Niflib::NiRollController;
	class DLL_API NiRollControllerNode : public BasicNode <NiRollController> {};
	class DLL_API NiRollController_Storage : public ObjectStorage <NiRollControllerNode> {};
	using NiFloatData = Niflib::NiFloatData;
	class DLL_API NiFloatDataNode : public BasicNode <NiFloatData> {};
	class DLL_API NiFloatData_Storage : public ObjectStorage <NiFloatDataNode> {};
	using NiFloatExtraData = Niflib::NiFloatExtraData;
	class DLL_API NiFloatExtraDataNode : public BasicNode <NiFloatExtraData> {};
	class DLL_API NiFloatExtraData_Storage : public ObjectStorage <NiFloatExtraDataNode> {};
	using NiFloatsExtraData = Niflib::NiFloatsExtraData;
	class DLL_API NiFloatsExtraDataNode : public BasicNode <NiFloatsExtraData> {};
	class DLL_API NiFloatsExtraData_Storage : public ObjectStorage <NiFloatsExtraDataNode> {};
	using NiFogProperty = Niflib::NiFogProperty;
	class DLL_API NiFogPropertyNode : public BasicNode <NiFogProperty> {};
	class DLL_API NiFogProperty_Storage : public ObjectStorage <NiFogPropertyNode> {};
	using NiGravity = Niflib::NiGravity;
	class DLL_API NiGravityNode : public BasicNode <NiGravity> {};
	class DLL_API NiGravity_Storage : public ObjectStorage <NiGravityNode> {};
	using NiIntegerExtraData = Niflib::NiIntegerExtraData;
	class DLL_API NiIntegerExtraDataNode : public BasicNode <NiIntegerExtraData> {};
	class DLL_API NiIntegerExtraData_Storage : public ObjectStorage <NiIntegerExtraDataNode> {};
	using BSXFlags = Niflib::BSXFlags;
	class DLL_API BSXFlagsNode : public BasicNode <BSXFlags> {};
	class DLL_API BSXFlags_Storage : public ObjectStorage <BSXFlagsNode> {};
	using NiIntegersExtraData = Niflib::NiIntegersExtraData;
	class DLL_API NiIntegersExtraDataNode : public BasicNode <NiIntegersExtraData> {};
	class DLL_API NiIntegersExtraData_Storage : public ObjectStorage <NiIntegersExtraDataNode> {};
	using BSKeyframeController = Niflib::BSKeyframeController;
	class DLL_API BSKeyframeControllerNode : public BasicNode <BSKeyframeController> {};
	class DLL_API BSKeyframeController_Storage : public ObjectStorage <BSKeyframeControllerNode> {};
	using NiKeyframeData = Niflib::NiKeyframeData;
	class DLL_API NiKeyframeDataNode : public BasicNode <NiKeyframeData> {};
	class DLL_API NiKeyframeData_Storage : public ObjectStorage <NiKeyframeDataNode> {};
	using NiLookAtController = Niflib::NiLookAtController;
	class DLL_API NiLookAtControllerNode : public BasicNode <NiLookAtController> {};
	class DLL_API NiLookAtController_Storage : public ObjectStorage <NiLookAtControllerNode> {};
	using NiLookAtInterpolator = Niflib::NiLookAtInterpolator;
	class DLL_API NiLookAtInterpolatorNode : public BasicNode <NiLookAtInterpolator> {};
	class DLL_API NiLookAtInterpolator_Storage : public ObjectStorage <NiLookAtInterpolatorNode> {};
	using NiMaterialProperty = Niflib::NiMaterialProperty;
	class DLL_API NiMaterialPropertyNode : public BasicNode <NiMaterialProperty> {};
	class DLL_API NiMaterialProperty_Storage : public ObjectStorage <NiMaterialPropertyNode> {};
	using NiMorphData = Niflib::NiMorphData;
	class DLL_API NiMorphDataNode : public BasicNode <NiMorphData> {};
	class DLL_API NiMorphData_Storage : public ObjectStorage <NiMorphDataNode> {};
	using NiNode = Niflib::NiNode;
	class DLL_API NiNodeNode : public BasicNode <NiNode> {};
	class DLL_API NiNode_Storage : public ObjectStorage <NiNodeNode> {};
	using NiBone = Niflib::NiBone;
	class DLL_API NiBoneNode : public BasicNode <NiBone> {};
	class DLL_API NiBone_Storage : public ObjectStorage <NiBoneNode> {};
	using AvoidNode = Niflib::AvoidNode;
	class DLL_API AvoidNodeNode : public BasicNode <AvoidNode> {};
	class DLL_API AvoidNode_Storage : public ObjectStorage <AvoidNodeNode> {};
	using FxWidget = Niflib::FxWidget;
	class DLL_API FxWidgetNode : public BasicNode <FxWidget> {};
	class DLL_API FxWidget_Storage : public ObjectStorage <FxWidgetNode> {};
	using FxButton = Niflib::FxButton;
	class DLL_API FxButtonNode : public BasicNode <FxButton> {};
	class DLL_API FxButton_Storage : public ObjectStorage <FxButtonNode> {};
	using FxRadioButton = Niflib::FxRadioButton;
	class DLL_API FxRadioButtonNode : public BasicNode <FxRadioButton> {};
	class DLL_API FxRadioButton_Storage : public ObjectStorage <FxRadioButtonNode> {};
	using NiBillboardNode = Niflib::NiBillboardNode;
	class DLL_API NiBillboardNodeNode : public BasicNode <NiBillboardNode> {};
	class DLL_API NiBillboardNode_Storage : public ObjectStorage <NiBillboardNodeNode> {};
	using NiBSAnimationNode = Niflib::NiBSAnimationNode;
	class DLL_API NiBSAnimationNodeNode : public BasicNode <NiBSAnimationNode> {};
	class DLL_API NiBSAnimationNode_Storage : public ObjectStorage <NiBSAnimationNodeNode> {};
	using NiBSParticleNode = Niflib::NiBSParticleNode;
	class DLL_API NiBSParticleNodeNode : public BasicNode <NiBSParticleNode> {};
	class DLL_API NiBSParticleNode_Storage : public ObjectStorage <NiBSParticleNodeNode> {};
	using NiSwitchNode = Niflib::NiSwitchNode;
	class DLL_API NiSwitchNodeNode : public BasicNode <NiSwitchNode> {};
	class DLL_API NiSwitchNode_Storage : public ObjectStorage <NiSwitchNodeNode> {};
	using NiLODNode = Niflib::NiLODNode;
	class DLL_API NiLODNodeNode : public BasicNode <NiLODNode> {};
	class DLL_API NiLODNode_Storage : public ObjectStorage <NiLODNodeNode> {};
	using NiPalette = Niflib::NiPalette;
	class DLL_API NiPaletteNode : public BasicNode <NiPalette> {};
	class DLL_API NiPalette_Storage : public ObjectStorage <NiPaletteNode> {};
	using NiParticleBomb = Niflib::NiParticleBomb;
	class DLL_API NiParticleBombNode : public BasicNode <NiParticleBomb> {};
	class DLL_API NiParticleBomb_Storage : public ObjectStorage <NiParticleBombNode> {};
	using NiParticleColorModifier = Niflib::NiParticleColorModifier;
	class DLL_API NiParticleColorModifierNode : public BasicNode <NiParticleColorModifier> {};
	class DLL_API NiParticleColorModifier_Storage : public ObjectStorage <NiParticleColorModifierNode> {};
	using NiParticleGrowFade = Niflib::NiParticleGrowFade;
	class DLL_API NiParticleGrowFadeNode : public BasicNode <NiParticleGrowFade> {};
	class DLL_API NiParticleGrowFade_Storage : public ObjectStorage <NiParticleGrowFadeNode> {};
	using NiParticleMeshModifier = Niflib::NiParticleMeshModifier;
	class DLL_API NiParticleMeshModifierNode : public BasicNode <NiParticleMeshModifier> {};
	class DLL_API NiParticleMeshModifier_Storage : public ObjectStorage <NiParticleMeshModifierNode> {};
	using NiParticleRotation = Niflib::NiParticleRotation;
	class DLL_API NiParticleRotationNode : public BasicNode <NiParticleRotation> {};
	class DLL_API NiParticleRotation_Storage : public ObjectStorage <NiParticleRotationNode> {};
	using NiParticles = Niflib::NiParticles;
	class DLL_API NiParticlesNode : public BasicNode <NiParticles> {};
	class DLL_API NiParticles_Storage : public ObjectStorage <NiParticlesNode> {};
	using NiAutoNormalParticles = Niflib::NiAutoNormalParticles;
	class DLL_API NiAutoNormalParticlesNode : public BasicNode <NiAutoNormalParticles> {};
	class DLL_API NiAutoNormalParticles_Storage : public ObjectStorage <NiAutoNormalParticlesNode> {};
	using NiParticleMeshes = Niflib::NiParticleMeshes;
	class DLL_API NiParticleMeshesNode : public BasicNode <NiParticleMeshes> {};
	class DLL_API NiParticleMeshes_Storage : public ObjectStorage <NiParticleMeshesNode> {};
	using NiParticleMeshesData = Niflib::NiParticleMeshesData;
	class DLL_API NiParticleMeshesDataNode : public BasicNode <NiParticleMeshesData> {};
	class DLL_API NiParticleMeshesData_Storage : public ObjectStorage <NiParticleMeshesDataNode> {};
	using NiParticleSystem = Niflib::NiParticleSystem;
	class DLL_API NiParticleSystemNode : public BasicNode <NiParticleSystem> {};
	class DLL_API NiParticleSystem_Storage : public ObjectStorage <NiParticleSystemNode> {};
	using NiMeshParticleSystem = Niflib::NiMeshParticleSystem;
	class DLL_API NiMeshParticleSystemNode : public BasicNode <NiMeshParticleSystem> {};
	class DLL_API NiMeshParticleSystem_Storage : public ObjectStorage <NiMeshParticleSystemNode> {};
	using NiParticleSystemController = Niflib::NiParticleSystemController;
	class DLL_API NiParticleSystemControllerNode : public BasicNode <NiParticleSystemController> {};
	class DLL_API NiParticleSystemController_Storage : public ObjectStorage <NiParticleSystemControllerNode> {};
	using NiBSPArrayController = Niflib::NiBSPArrayController;
	class DLL_API NiBSPArrayControllerNode : public BasicNode <NiBSPArrayController> {};
	class DLL_API NiBSPArrayController_Storage : public ObjectStorage <NiBSPArrayControllerNode> {};
	using NiPathController = Niflib::NiPathController;
	class DLL_API NiPathControllerNode : public BasicNode <NiPathController> {};
	class DLL_API NiPathController_Storage : public ObjectStorage <NiPathControllerNode> {};
	using ATextureRenderData = Niflib::ATextureRenderData;
	class DLL_API ATextureRenderDataNode : public BasicNode <ATextureRenderData> {};
	class DLL_API ATextureRenderData_Storage : public ObjectStorage <ATextureRenderDataNode> {};
	using NiPersistentSrcTextureRendererData = Niflib::NiPersistentSrcTextureRendererData;
	class DLL_API NiPersistentSrcTextureRendererDataNode : public BasicNode <NiPersistentSrcTextureRendererData> {};
	class DLL_API NiPersistentSrcTextureRendererData_Storage : public ObjectStorage <NiPersistentSrcTextureRendererDataNode> {};
	using NiPixelData = Niflib::NiPixelData;
	class DLL_API NiPixelDataNode : public BasicNode <NiPixelData> {};
	class DLL_API NiPixelData_Storage : public ObjectStorage <NiPixelDataNode> {};
	using NiPlanarCollider = Niflib::NiPlanarCollider;
	class DLL_API NiPlanarColliderNode : public BasicNode <NiPlanarCollider> {};
	class DLL_API NiPlanarCollider_Storage : public ObjectStorage <NiPlanarColliderNode> {};
	using NiPointLight = Niflib::NiPointLight;
	class DLL_API NiPointLightNode : public BasicNode <NiPointLight> {};
	class DLL_API NiPointLight_Storage : public ObjectStorage <NiPointLightNode> {};
	using NiPosData = Niflib::NiPosData;
	class DLL_API NiPosDataNode : public BasicNode <NiPosData> {};
	class DLL_API NiPosData_Storage : public ObjectStorage <NiPosDataNode> {};
	using NiPSysAgeDeathModifier = Niflib::NiPSysAgeDeathModifier;
	class DLL_API NiPSysAgeDeathModifierNode : public BasicNode <NiPSysAgeDeathModifier> {};
	class DLL_API NiPSysAgeDeathModifier_Storage : public ObjectStorage <NiPSysAgeDeathModifierNode> {};
	using NiPSysBombModifier = Niflib::NiPSysBombModifier;
	class DLL_API NiPSysBombModifierNode : public BasicNode <NiPSysBombModifier> {};
	class DLL_API NiPSysBombModifier_Storage : public ObjectStorage <NiPSysBombModifierNode> {};
	using NiPSysBoundUpdateModifier = Niflib::NiPSysBoundUpdateModifier;
	class DLL_API NiPSysBoundUpdateModifierNode : public BasicNode <NiPSysBoundUpdateModifier> {};
	class DLL_API NiPSysBoundUpdateModifier_Storage : public ObjectStorage <NiPSysBoundUpdateModifierNode> {};
	using NiPSysBoxEmitter = Niflib::NiPSysBoxEmitter;
	class DLL_API NiPSysBoxEmitterNode : public BasicNode <NiPSysBoxEmitter> {};
	class DLL_API NiPSysBoxEmitter_Storage : public ObjectStorage <NiPSysBoxEmitterNode> {};
	using NiPSysColliderManager = Niflib::NiPSysColliderManager;
	class DLL_API NiPSysColliderManagerNode : public BasicNode <NiPSysColliderManager> {};
	class DLL_API NiPSysColliderManager_Storage : public ObjectStorage <NiPSysColliderManagerNode> {};
	using NiPSysColorModifier = Niflib::NiPSysColorModifier;
	class DLL_API NiPSysColorModifierNode : public BasicNode <NiPSysColorModifier> {};
	class DLL_API NiPSysColorModifier_Storage : public ObjectStorage <NiPSysColorModifierNode> {};
	using NiPSysCylinderEmitter = Niflib::NiPSysCylinderEmitter;
	class DLL_API NiPSysCylinderEmitterNode : public BasicNode <NiPSysCylinderEmitter> {};
	class DLL_API NiPSysCylinderEmitter_Storage : public ObjectStorage <NiPSysCylinderEmitterNode> {};
	using NiPSysDragModifier = Niflib::NiPSysDragModifier;
	class DLL_API NiPSysDragModifierNode : public BasicNode <NiPSysDragModifier> {};
	class DLL_API NiPSysDragModifier_Storage : public ObjectStorage <NiPSysDragModifierNode> {};
	using NiPSysEmitterCtlrData = Niflib::NiPSysEmitterCtlrData;
	class DLL_API NiPSysEmitterCtlrDataNode : public BasicNode <NiPSysEmitterCtlrData> {};
	class DLL_API NiPSysEmitterCtlrData_Storage : public ObjectStorage <NiPSysEmitterCtlrDataNode> {};
	using NiPSysGravityModifier = Niflib::NiPSysGravityModifier;
	class DLL_API NiPSysGravityModifierNode : public BasicNode <NiPSysGravityModifier> {};
	class DLL_API NiPSysGravityModifier_Storage : public ObjectStorage <NiPSysGravityModifierNode> {};
	using NiPSysGrowFadeModifier = Niflib::NiPSysGrowFadeModifier;
	class DLL_API NiPSysGrowFadeModifierNode : public BasicNode <NiPSysGrowFadeModifier> {};
	class DLL_API NiPSysGrowFadeModifier_Storage : public ObjectStorage <NiPSysGrowFadeModifierNode> {};
	using NiPSysMeshEmitter = Niflib::NiPSysMeshEmitter;
	class DLL_API NiPSysMeshEmitterNode : public BasicNode <NiPSysMeshEmitter> {};
	class DLL_API NiPSysMeshEmitter_Storage : public ObjectStorage <NiPSysMeshEmitterNode> {};
	using NiPSysMeshUpdateModifier = Niflib::NiPSysMeshUpdateModifier;
	class DLL_API NiPSysMeshUpdateModifierNode : public BasicNode <NiPSysMeshUpdateModifier> {};
	class DLL_API NiPSysMeshUpdateModifier_Storage : public ObjectStorage <NiPSysMeshUpdateModifierNode> {};
	using BSPSysInheritVelocityModifier = Niflib::BSPSysInheritVelocityModifier;
	class DLL_API BSPSysInheritVelocityModifierNode : public BasicNode <BSPSysInheritVelocityModifier> {};
	class DLL_API BSPSysInheritVelocityModifier_Storage : public ObjectStorage <BSPSysInheritVelocityModifierNode> {};
	using BSPSysHavokUpdateModifier = Niflib::BSPSysHavokUpdateModifier;
	class DLL_API BSPSysHavokUpdateModifierNode : public BasicNode <BSPSysHavokUpdateModifier> {};
	class DLL_API BSPSysHavokUpdateModifier_Storage : public ObjectStorage <BSPSysHavokUpdateModifierNode> {};
	using BSPSysRecycleBoundModifier = Niflib::BSPSysRecycleBoundModifier;
	class DLL_API BSPSysRecycleBoundModifierNode : public BasicNode <BSPSysRecycleBoundModifier> {};
	class DLL_API BSPSysRecycleBoundModifier_Storage : public ObjectStorage <BSPSysRecycleBoundModifierNode> {};
	using BSPSysSubTexModifier = Niflib::BSPSysSubTexModifier;
	class DLL_API BSPSysSubTexModifierNode : public BasicNode <BSPSysSubTexModifier> {};
	class DLL_API BSPSysSubTexModifier_Storage : public ObjectStorage <BSPSysSubTexModifierNode> {};
	using NiPSysPlanarCollider = Niflib::NiPSysPlanarCollider;
	class DLL_API NiPSysPlanarColliderNode : public BasicNode <NiPSysPlanarCollider> {};
	class DLL_API NiPSysPlanarCollider_Storage : public ObjectStorage <NiPSysPlanarColliderNode> {};
	using NiPSysSphericalCollider = Niflib::NiPSysSphericalCollider;
	class DLL_API NiPSysSphericalColliderNode : public BasicNode <NiPSysSphericalCollider> {};
	class DLL_API NiPSysSphericalCollider_Storage : public ObjectStorage <NiPSysSphericalColliderNode> {};
	using NiPSysPositionModifier = Niflib::NiPSysPositionModifier;
	class DLL_API NiPSysPositionModifierNode : public BasicNode <NiPSysPositionModifier> {};
	class DLL_API NiPSysPositionModifier_Storage : public ObjectStorage <NiPSysPositionModifierNode> {};
	using NiPSysResetOnLoopCtlr = Niflib::NiPSysResetOnLoopCtlr;
	class DLL_API NiPSysResetOnLoopCtlrNode : public BasicNode <NiPSysResetOnLoopCtlr> {};
	class DLL_API NiPSysResetOnLoopCtlr_Storage : public ObjectStorage <NiPSysResetOnLoopCtlrNode> {};
	using NiPSysRotationModifier = Niflib::NiPSysRotationModifier;
	class DLL_API NiPSysRotationModifierNode : public BasicNode <NiPSysRotationModifier> {};
	class DLL_API NiPSysRotationModifier_Storage : public ObjectStorage <NiPSysRotationModifierNode> {};
	using NiPSysSpawnModifier = Niflib::NiPSysSpawnModifier;
	class DLL_API NiPSysSpawnModifierNode : public BasicNode <NiPSysSpawnModifier> {};
	class DLL_API NiPSysSpawnModifier_Storage : public ObjectStorage <NiPSysSpawnModifierNode> {};
	using NiPSysSphereEmitter = Niflib::NiPSysSphereEmitter;
	class DLL_API NiPSysSphereEmitterNode : public BasicNode <NiPSysSphereEmitter> {};
	class DLL_API NiPSysSphereEmitter_Storage : public ObjectStorage <NiPSysSphereEmitterNode> {};
	using NiPSysUpdateCtlr = Niflib::NiPSysUpdateCtlr;
	class DLL_API NiPSysUpdateCtlrNode : public BasicNode <NiPSysUpdateCtlr> {};
	class DLL_API NiPSysUpdateCtlr_Storage : public ObjectStorage <NiPSysUpdateCtlrNode> {};
	using NiPSysFieldModifier = Niflib::NiPSysFieldModifier;
	class DLL_API NiPSysFieldModifierNode : public BasicNode <NiPSysFieldModifier> {};
	class DLL_API NiPSysFieldModifier_Storage : public ObjectStorage <NiPSysFieldModifierNode> {};
	using NiPSysVortexFieldModifier = Niflib::NiPSysVortexFieldModifier;
	class DLL_API NiPSysVortexFieldModifierNode : public BasicNode <NiPSysVortexFieldModifier> {};
	class DLL_API NiPSysVortexFieldModifier_Storage : public ObjectStorage <NiPSysVortexFieldModifierNode> {};
	using NiPSysGravityFieldModifier = Niflib::NiPSysGravityFieldModifier;
	class DLL_API NiPSysGravityFieldModifierNode : public BasicNode <NiPSysGravityFieldModifier> {};
	class DLL_API NiPSysGravityFieldModifier_Storage : public ObjectStorage <NiPSysGravityFieldModifierNode> {};
	using NiPSysDragFieldModifier = Niflib::NiPSysDragFieldModifier;
	class DLL_API NiPSysDragFieldModifierNode : public BasicNode <NiPSysDragFieldModifier> {};
	class DLL_API NiPSysDragFieldModifier_Storage : public ObjectStorage <NiPSysDragFieldModifierNode> {};
	using NiPSysTurbulenceFieldModifier = Niflib::NiPSysTurbulenceFieldModifier;
	class DLL_API NiPSysTurbulenceFieldModifierNode : public BasicNode <NiPSysTurbulenceFieldModifier> {};
	class DLL_API NiPSysTurbulenceFieldModifier_Storage : public ObjectStorage <NiPSysTurbulenceFieldModifierNode> {};
	using BSPSysLODModifier = Niflib::BSPSysLODModifier;
	class DLL_API BSPSysLODModifierNode : public BasicNode <BSPSysLODModifier> {};
	class DLL_API BSPSysLODModifier_Storage : public ObjectStorage <BSPSysLODModifierNode> {};
	using BSPSysScaleModifier = Niflib::BSPSysScaleModifier;
	class DLL_API BSPSysScaleModifierNode : public BasicNode <BSPSysScaleModifier> {};
	class DLL_API BSPSysScaleModifier_Storage : public ObjectStorage <BSPSysScaleModifierNode> {};
	using NiPSysFieldMagnitudeCtlr = Niflib::NiPSysFieldMagnitudeCtlr;
	class DLL_API NiPSysFieldMagnitudeCtlrNode : public BasicNode <NiPSysFieldMagnitudeCtlr> {};
	class DLL_API NiPSysFieldMagnitudeCtlr_Storage : public ObjectStorage <NiPSysFieldMagnitudeCtlrNode> {};
	using NiPSysFieldAttenuationCtlr = Niflib::NiPSysFieldAttenuationCtlr;
	class DLL_API NiPSysFieldAttenuationCtlrNode : public BasicNode <NiPSysFieldAttenuationCtlr> {};
	class DLL_API NiPSysFieldAttenuationCtlr_Storage : public ObjectStorage <NiPSysFieldAttenuationCtlrNode> {};
	using NiPSysFieldMaxDistanceCtlr = Niflib::NiPSysFieldMaxDistanceCtlr;
	class DLL_API NiPSysFieldMaxDistanceCtlrNode : public BasicNode <NiPSysFieldMaxDistanceCtlr> {};
	class DLL_API NiPSysFieldMaxDistanceCtlr_Storage : public ObjectStorage <NiPSysFieldMaxDistanceCtlrNode> {};
	using NiPSysAirFieldAirFrictionCtlr = Niflib::NiPSysAirFieldAirFrictionCtlr;
	class DLL_API NiPSysAirFieldAirFrictionCtlrNode : public BasicNode <NiPSysAirFieldAirFrictionCtlr> {};
	class DLL_API NiPSysAirFieldAirFrictionCtlr_Storage : public ObjectStorage <NiPSysAirFieldAirFrictionCtlrNode> {};
	using NiPSysAirFieldInheritVelocityCtlr = Niflib::NiPSysAirFieldInheritVelocityCtlr;
	class DLL_API NiPSysAirFieldInheritVelocityCtlrNode : public BasicNode <NiPSysAirFieldInheritVelocityCtlr> {};
	class DLL_API NiPSysAirFieldInheritVelocityCtlr_Storage : public ObjectStorage <NiPSysAirFieldInheritVelocityCtlrNode> {};
	using NiPSysAirFieldSpreadCtlr = Niflib::NiPSysAirFieldSpreadCtlr;
	class DLL_API NiPSysAirFieldSpreadCtlrNode : public BasicNode <NiPSysAirFieldSpreadCtlr> {};
	class DLL_API NiPSysAirFieldSpreadCtlr_Storage : public ObjectStorage <NiPSysAirFieldSpreadCtlrNode> {};
	using NiPSysInitialRotSpeedCtlr = Niflib::NiPSysInitialRotSpeedCtlr;
	class DLL_API NiPSysInitialRotSpeedCtlrNode : public BasicNode <NiPSysInitialRotSpeedCtlr> {};
	class DLL_API NiPSysInitialRotSpeedCtlr_Storage : public ObjectStorage <NiPSysInitialRotSpeedCtlrNode> {};
	using NiPSysInitialRotSpeedVarCtlr = Niflib::NiPSysInitialRotSpeedVarCtlr;
	class DLL_API NiPSysInitialRotSpeedVarCtlrNode : public BasicNode <NiPSysInitialRotSpeedVarCtlr> {};
	class DLL_API NiPSysInitialRotSpeedVarCtlr_Storage : public ObjectStorage <NiPSysInitialRotSpeedVarCtlrNode> {};
	using NiPSysInitialRotAngleCtlr = Niflib::NiPSysInitialRotAngleCtlr;
	class DLL_API NiPSysInitialRotAngleCtlrNode : public BasicNode <NiPSysInitialRotAngleCtlr> {};
	class DLL_API NiPSysInitialRotAngleCtlr_Storage : public ObjectStorage <NiPSysInitialRotAngleCtlrNode> {};
	using NiPSysInitialRotAngleVarCtlr = Niflib::NiPSysInitialRotAngleVarCtlr;
	class DLL_API NiPSysInitialRotAngleVarCtlrNode : public BasicNode <NiPSysInitialRotAngleVarCtlr> {};
	class DLL_API NiPSysInitialRotAngleVarCtlr_Storage : public ObjectStorage <NiPSysInitialRotAngleVarCtlrNode> {};
	using NiPSysEmitterPlanarAngleCtlr = Niflib::NiPSysEmitterPlanarAngleCtlr;
	class DLL_API NiPSysEmitterPlanarAngleCtlrNode : public BasicNode <NiPSysEmitterPlanarAngleCtlr> {};
	class DLL_API NiPSysEmitterPlanarAngleCtlr_Storage : public ObjectStorage <NiPSysEmitterPlanarAngleCtlrNode> {};
	using NiPSysEmitterPlanarAngleVarCtlr = Niflib::NiPSysEmitterPlanarAngleVarCtlr;
	class DLL_API NiPSysEmitterPlanarAngleVarCtlrNode : public BasicNode <NiPSysEmitterPlanarAngleVarCtlr> {};
	class DLL_API NiPSysEmitterPlanarAngleVarCtlr_Storage : public ObjectStorage <NiPSysEmitterPlanarAngleVarCtlrNode> {};
	using NiPSysAirFieldModifier = Niflib::NiPSysAirFieldModifier;
	class DLL_API NiPSysAirFieldModifierNode : public BasicNode <NiPSysAirFieldModifier> {};
	class DLL_API NiPSysAirFieldModifier_Storage : public ObjectStorage <NiPSysAirFieldModifierNode> {};
	using NiPSysTrailEmitter = Niflib::NiPSysTrailEmitter;
	class DLL_API NiPSysTrailEmitterNode : public BasicNode <NiPSysTrailEmitter> {};
	class DLL_API NiPSysTrailEmitter_Storage : public ObjectStorage <NiPSysTrailEmitterNode> {};
	using NiLightIntensityController = Niflib::NiLightIntensityController;
	class DLL_API NiLightIntensityControllerNode : public BasicNode <NiLightIntensityController> {};
	class DLL_API NiLightIntensityController_Storage : public ObjectStorage <NiLightIntensityControllerNode> {};
	using NiPSysRadialFieldModifier = Niflib::NiPSysRadialFieldModifier;
	class DLL_API NiPSysRadialFieldModifierNode : public BasicNode <NiPSysRadialFieldModifier> {};
	class DLL_API NiPSysRadialFieldModifier_Storage : public ObjectStorage <NiPSysRadialFieldModifierNode> {};
	using NiLODData = Niflib::NiLODData;
	class DLL_API NiLODDataNode : public BasicNode <NiLODData> {};
	class DLL_API NiLODData_Storage : public ObjectStorage <NiLODDataNode> {};
	using NiRangeLODData = Niflib::NiRangeLODData;
	class DLL_API NiRangeLODDataNode : public BasicNode <NiRangeLODData> {};
	class DLL_API NiRangeLODData_Storage : public ObjectStorage <NiRangeLODDataNode> {};
	using NiScreenLODData = Niflib::NiScreenLODData;
	class DLL_API NiScreenLODDataNode : public BasicNode <NiScreenLODData> {};
	class DLL_API NiScreenLODData_Storage : public ObjectStorage <NiScreenLODDataNode> {};
	using NiRotatingParticles = Niflib::NiRotatingParticles;
	class DLL_API NiRotatingParticlesNode : public BasicNode <NiRotatingParticles> {};
	class DLL_API NiRotatingParticles_Storage : public ObjectStorage <NiRotatingParticlesNode> {};
	using NiSequenceStreamHelper = Niflib::NiSequenceStreamHelper;
	class DLL_API NiSequenceStreamHelperNode : public BasicNode <NiSequenceStreamHelper> {};
	class DLL_API NiSequenceStreamHelper_Storage : public ObjectStorage <NiSequenceStreamHelperNode> {};
	using NiShadeProperty = Niflib::NiShadeProperty;
	class DLL_API NiShadePropertyNode : public BasicNode <NiShadeProperty> {};
	class DLL_API NiShadeProperty_Storage : public ObjectStorage <NiShadePropertyNode> {};
	using NiSkinData = Niflib::NiSkinData;
	class DLL_API NiSkinDataNode : public BasicNode <NiSkinData> {};
	class DLL_API NiSkinData_Storage : public ObjectStorage <NiSkinDataNode> {};
	using NiSkinInstance = Niflib::NiSkinInstance;
	class DLL_API NiSkinInstanceNode : public BasicNode <NiSkinInstance> {};
	class DLL_API NiSkinInstance_Storage : public ObjectStorage <NiSkinInstanceNode> {};
	using NiTriShapeSkinController = Niflib::NiTriShapeSkinController;
	class DLL_API NiTriShapeSkinControllerNode : public BasicNode <NiTriShapeSkinController> {};
	class DLL_API NiTriShapeSkinController_Storage : public ObjectStorage <NiTriShapeSkinControllerNode> {};
	using NiClodSkinInstance = Niflib::NiClodSkinInstance;
	class DLL_API NiClodSkinInstanceNode : public BasicNode <NiClodSkinInstance> {};
	class DLL_API NiClodSkinInstance_Storage : public ObjectStorage <NiClodSkinInstanceNode> {};
	using NiSkinPartition = Niflib::NiSkinPartition;
	class DLL_API NiSkinPartitionNode : public BasicNode <NiSkinPartition> {};
	class DLL_API NiSkinPartition_Storage : public ObjectStorage <NiSkinPartitionNode> {};
	using NiTexture = Niflib::NiTexture;
	class DLL_API NiTextureNode : public BasicNode <NiTexture> {};
	class DLL_API NiTexture_Storage : public ObjectStorage <NiTextureNode> {};
	using NiSourceTexture = Niflib::NiSourceTexture;
	class DLL_API NiSourceTextureNode : public BasicNode <NiSourceTexture> {};
	class DLL_API NiSourceTexture_Storage : public ObjectStorage <NiSourceTextureNode> {};
	using NiSpecularProperty = Niflib::NiSpecularProperty;
	class DLL_API NiSpecularPropertyNode : public BasicNode <NiSpecularProperty> {};
	class DLL_API NiSpecularProperty_Storage : public ObjectStorage <NiSpecularPropertyNode> {};
	using NiSphericalCollider = Niflib::NiSphericalCollider;
	class DLL_API NiSphericalColliderNode : public BasicNode <NiSphericalCollider> {};
	class DLL_API NiSphericalCollider_Storage : public ObjectStorage <NiSphericalColliderNode> {};
	using NiSpotLight = Niflib::NiSpotLight;
	class DLL_API NiSpotLightNode : public BasicNode <NiSpotLight> {};
	class DLL_API NiSpotLight_Storage : public ObjectStorage <NiSpotLightNode> {};
	using NiStencilProperty = Niflib::NiStencilProperty;
	class DLL_API NiStencilPropertyNode : public BasicNode <NiStencilProperty> {};
	class DLL_API NiStencilProperty_Storage : public ObjectStorage <NiStencilPropertyNode> {};
	using NiStringExtraData = Niflib::NiStringExtraData;
	class DLL_API NiStringExtraDataNode : public BasicNode <NiStringExtraData> {};
	class DLL_API NiStringExtraData_Storage : public ObjectStorage <NiStringExtraDataNode> {};
	using NiStringPalette = Niflib::NiStringPalette;
	class DLL_API NiStringPaletteNode : public BasicNode <NiStringPalette> {};
	class DLL_API NiStringPalette_Storage : public ObjectStorage <NiStringPaletteNode> {};
	using NiStringsExtraData = Niflib::NiStringsExtraData;
	class DLL_API NiStringsExtraDataNode : public BasicNode <NiStringsExtraData> {};
	class DLL_API NiStringsExtraData_Storage : public ObjectStorage <NiStringsExtraDataNode> {};
	using NiTextKeyExtraData = Niflib::NiTextKeyExtraData;
	class DLL_API NiTextKeyExtraDataNode : public BasicNode <NiTextKeyExtraData> {};
	class DLL_API NiTextKeyExtraData_Storage : public ObjectStorage <NiTextKeyExtraDataNode> {};
	using NiTextureEffect = Niflib::NiTextureEffect;
	class DLL_API NiTextureEffectNode : public BasicNode <NiTextureEffect> {};
	class DLL_API NiTextureEffect_Storage : public ObjectStorage <NiTextureEffectNode> {};
	using NiTextureModeProperty = Niflib::NiTextureModeProperty;
	class DLL_API NiTextureModePropertyNode : public BasicNode <NiTextureModeProperty> {};
	class DLL_API NiTextureModeProperty_Storage : public ObjectStorage <NiTextureModePropertyNode> {};
	using NiImage = Niflib::NiImage;
	class DLL_API NiImageNode : public BasicNode <NiImage> {};
	class DLL_API NiImage_Storage : public ObjectStorage <NiImageNode> {};
	using NiTextureProperty = Niflib::NiTextureProperty;
	class DLL_API NiTexturePropertyNode : public BasicNode <NiTextureProperty> {};
	class DLL_API NiTextureProperty_Storage : public ObjectStorage <NiTexturePropertyNode> {};
	using NiMultiTextureProperty = Niflib::NiMultiTextureProperty;
	class DLL_API NiMultiTexturePropertyNode : public BasicNode <NiMultiTextureProperty> {};
	class DLL_API NiMultiTextureProperty_Storage : public ObjectStorage <NiMultiTexturePropertyNode> {};
	using NiTexturingProperty = Niflib::NiTexturingProperty;
	class DLL_API NiTexturingPropertyNode : public BasicNode <NiTexturingProperty> {};
	class DLL_API NiTexturingProperty_Storage : public ObjectStorage <NiTexturingPropertyNode> {};
	using NiTransformData = Niflib::NiTransformData;
	class DLL_API NiTransformDataNode : public BasicNode <NiTransformData> {};
	class DLL_API NiTransformData_Storage : public ObjectStorage <NiTransformDataNode> {};
	using NiTriShape = Niflib::NiTriShape;
	class DLL_API NiTriShapeNode : public BasicNode <NiTriShape> {};
	class DLL_API NiTriShape_Storage : public ObjectStorage <NiTriShapeNode> {};
	using NiTriShapeData = Niflib::NiTriShapeData;
	class DLL_API NiTriShapeDataNode : public BasicNode <NiTriShapeData> {};
	class DLL_API NiTriShapeData_Storage : public ObjectStorage <NiTriShapeDataNode> {};
	using NiTriStrips = Niflib::NiTriStrips;
	class DLL_API NiTriStripsNode : public BasicNode <NiTriStrips> {};
	class DLL_API NiTriStrips_Storage : public ObjectStorage <NiTriStripsNode> {};
	using NiTriStripsData = Niflib::NiTriStripsData;
	class DLL_API NiTriStripsDataNode : public BasicNode <NiTriStripsData> {};
	class DLL_API NiTriStripsData_Storage : public ObjectStorage <NiTriStripsDataNode> {};
	using NiEnvMappedTriShape = Niflib::NiEnvMappedTriShape;
	class DLL_API NiEnvMappedTriShapeNode : public BasicNode <NiEnvMappedTriShape> {};
	class DLL_API NiEnvMappedTriShape_Storage : public ObjectStorage <NiEnvMappedTriShapeNode> {};
	using NiEnvMappedTriShapeData = Niflib::NiEnvMappedTriShapeData;
	class DLL_API NiEnvMappedTriShapeDataNode : public BasicNode <NiEnvMappedTriShapeData> {};
	class DLL_API NiEnvMappedTriShapeData_Storage : public ObjectStorage <NiEnvMappedTriShapeDataNode> {};
	using NiBezierTriangle4 = Niflib::NiBezierTriangle4;
	class DLL_API NiBezierTriangle4Node : public BasicNode <NiBezierTriangle4> {};
	class DLL_API NiBezierTriangle4_Storage : public ObjectStorage <NiBezierTriangle4Node> {};
	using NiBezierMesh = Niflib::NiBezierMesh;
	class DLL_API NiBezierMeshNode : public BasicNode <NiBezierMesh> {};
	class DLL_API NiBezierMesh_Storage : public ObjectStorage <NiBezierMeshNode> {};
	using NiClod = Niflib::NiClod;
	class DLL_API NiClodNode : public BasicNode <NiClod> {};
	class DLL_API NiClod_Storage : public ObjectStorage <NiClodNode> {};
	using NiClodData = Niflib::NiClodData;
	class DLL_API NiClodDataNode : public BasicNode <NiClodData> {};
	class DLL_API NiClodData_Storage : public ObjectStorage <NiClodDataNode> {};
	using NiUVController = Niflib::NiUVController;
	class DLL_API NiUVControllerNode : public BasicNode <NiUVController> {};
	class DLL_API NiUVController_Storage : public ObjectStorage <NiUVControllerNode> {};
	using NiUVData = Niflib::NiUVData;
	class DLL_API NiUVDataNode : public BasicNode <NiUVData> {};
	class DLL_API NiUVData_Storage : public ObjectStorage <NiUVDataNode> {};
	using NiVectorExtraData = Niflib::NiVectorExtraData;
	class DLL_API NiVectorExtraDataNode : public BasicNode <NiVectorExtraData> {};
	class DLL_API NiVectorExtraData_Storage : public ObjectStorage <NiVectorExtraDataNode> {};
	using NiVertexColorProperty = Niflib::NiVertexColorProperty;
	class DLL_API NiVertexColorPropertyNode : public BasicNode <NiVertexColorProperty> {};
	class DLL_API NiVertexColorProperty_Storage : public ObjectStorage <NiVertexColorPropertyNode> {};
	using NiVertWeightsExtraData = Niflib::NiVertWeightsExtraData;
	class DLL_API NiVertWeightsExtraDataNode : public BasicNode <NiVertWeightsExtraData> {};
	class DLL_API NiVertWeightsExtraData_Storage : public ObjectStorage <NiVertWeightsExtraDataNode> {};
	using NiVisData = Niflib::NiVisData;
	class DLL_API NiVisDataNode : public BasicNode <NiVisData> {};
	class DLL_API NiVisData_Storage : public ObjectStorage <NiVisDataNode> {};
	using NiWireframeProperty = Niflib::NiWireframeProperty;
	class DLL_API NiWireframePropertyNode : public BasicNode <NiWireframeProperty> {};
	class DLL_API NiWireframeProperty_Storage : public ObjectStorage <NiWireframePropertyNode> {};
	using NiZBufferProperty = Niflib::NiZBufferProperty;
	class DLL_API NiZBufferPropertyNode : public BasicNode <NiZBufferProperty> {};
	class DLL_API NiZBufferProperty_Storage : public ObjectStorage <NiZBufferPropertyNode> {};
	using RootCollisionNode = Niflib::RootCollisionNode;
	class DLL_API RootCollisionNodeNode : public BasicNode <RootCollisionNode> {};
	class DLL_API RootCollisionNode_Storage : public ObjectStorage <RootCollisionNodeNode> {};
	using NiRawImageData = Niflib::NiRawImageData;
	class DLL_API NiRawImageDataNode : public BasicNode <NiRawImageData> {};
	class DLL_API NiRawImageData_Storage : public ObjectStorage <NiRawImageDataNode> {};
	using NiSortAdjustNode = Niflib::NiSortAdjustNode;
	class DLL_API NiSortAdjustNodeNode : public BasicNode <NiSortAdjustNode> {};
	class DLL_API NiSortAdjustNode_Storage : public ObjectStorage <NiSortAdjustNodeNode> {};
	using NiSourceCubeMap = Niflib::NiSourceCubeMap;
	class DLL_API NiSourceCubeMapNode : public BasicNode <NiSourceCubeMap> {};
	class DLL_API NiSourceCubeMap_Storage : public ObjectStorage <NiSourceCubeMapNode> {};
	using NiPhysXProp = Niflib::NiPhysXProp;
	class DLL_API NiPhysXPropNode : public BasicNode <NiPhysXProp> {};
	class DLL_API NiPhysXProp_Storage : public ObjectStorage <NiPhysXPropNode> {};
	using NiPhysXPropDesc = Niflib::NiPhysXPropDesc;
	class DLL_API NiPhysXPropDescNode : public BasicNode <NiPhysXPropDesc> {};
	class DLL_API NiPhysXPropDesc_Storage : public ObjectStorage <NiPhysXPropDescNode> {};
	using NiPhysXActorDesc = Niflib::NiPhysXActorDesc;
	class DLL_API NiPhysXActorDescNode : public BasicNode <NiPhysXActorDesc> {};
	class DLL_API NiPhysXActorDesc_Storage : public ObjectStorage <NiPhysXActorDescNode> {};
	using NiPhysXBodyDesc = Niflib::NiPhysXBodyDesc;
	class DLL_API NiPhysXBodyDescNode : public BasicNode <NiPhysXBodyDesc> {};
	class DLL_API NiPhysXBodyDesc_Storage : public ObjectStorage <NiPhysXBodyDescNode> {};
	using NiPhysXD6JointDesc = Niflib::NiPhysXD6JointDesc;
	class DLL_API NiPhysXD6JointDescNode : public BasicNode <NiPhysXD6JointDesc> {};
	class DLL_API NiPhysXD6JointDesc_Storage : public ObjectStorage <NiPhysXD6JointDescNode> {};
	using NiPhysXShapeDesc = Niflib::NiPhysXShapeDesc;
	class DLL_API NiPhysXShapeDescNode : public BasicNode <NiPhysXShapeDesc> {};
	class DLL_API NiPhysXShapeDesc_Storage : public ObjectStorage <NiPhysXShapeDescNode> {};
	using NiPhysXMeshDesc = Niflib::NiPhysXMeshDesc;
	class DLL_API NiPhysXMeshDescNode : public BasicNode <NiPhysXMeshDesc> {};
	class DLL_API NiPhysXMeshDesc_Storage : public ObjectStorage <NiPhysXMeshDescNode> {};
	using NiPhysXMaterialDesc = Niflib::NiPhysXMaterialDesc;
	class DLL_API NiPhysXMaterialDescNode : public BasicNode <NiPhysXMaterialDesc> {};
	class DLL_API NiPhysXMaterialDesc_Storage : public ObjectStorage <NiPhysXMaterialDescNode> {};
	using NiPhysXKinematicSrc = Niflib::NiPhysXKinematicSrc;
	class DLL_API NiPhysXKinematicSrcNode : public BasicNode <NiPhysXKinematicSrc> {};
	class DLL_API NiPhysXKinematicSrc_Storage : public ObjectStorage <NiPhysXKinematicSrcNode> {};
	using NiPhysXTransformDest = Niflib::NiPhysXTransformDest;
	class DLL_API NiPhysXTransformDestNode : public BasicNode <NiPhysXTransformDest> {};
	class DLL_API NiPhysXTransformDest_Storage : public ObjectStorage <NiPhysXTransformDestNode> {};
	using NiArkAnimationExtraData = Niflib::NiArkAnimationExtraData;
	class DLL_API NiArkAnimationExtraDataNode : public BasicNode <NiArkAnimationExtraData> {};
	class DLL_API NiArkAnimationExtraData_Storage : public ObjectStorage <NiArkAnimationExtraDataNode> {};
	using NiArkImporterExtraData = Niflib::NiArkImporterExtraData;
	class DLL_API NiArkImporterExtraDataNode : public BasicNode <NiArkImporterExtraData> {};
	class DLL_API NiArkImporterExtraData_Storage : public ObjectStorage <NiArkImporterExtraDataNode> {};
	using NiArkTextureExtraData = Niflib::NiArkTextureExtraData;
	class DLL_API NiArkTextureExtraDataNode : public BasicNode <NiArkTextureExtraData> {};
	class DLL_API NiArkTextureExtraData_Storage : public ObjectStorage <NiArkTextureExtraDataNode> {};
	using NiArkViewportInfoExtraData = Niflib::NiArkViewportInfoExtraData;
	class DLL_API NiArkViewportInfoExtraDataNode : public BasicNode <NiArkViewportInfoExtraData> {};
	class DLL_API NiArkViewportInfoExtraData_Storage : public ObjectStorage <NiArkViewportInfoExtraDataNode> {};
	using NiArkShaderExtraData = Niflib::NiArkShaderExtraData;
	class DLL_API NiArkShaderExtraDataNode : public BasicNode <NiArkShaderExtraData> {};
	class DLL_API NiArkShaderExtraData_Storage : public ObjectStorage <NiArkShaderExtraDataNode> {};
	using NiLines = Niflib::NiLines;
	class DLL_API NiLinesNode : public BasicNode <NiLines> {};
	class DLL_API NiLines_Storage : public ObjectStorage <NiLinesNode> {};
	using NiLinesData = Niflib::NiLinesData;
	class DLL_API NiLinesDataNode : public BasicNode <NiLinesData> {};
	class DLL_API NiLinesData_Storage : public ObjectStorage <NiLinesDataNode> {};
	using NiScreenElementsData = Niflib::NiScreenElementsData;
	class DLL_API NiScreenElementsDataNode : public BasicNode <NiScreenElementsData> {};
	class DLL_API NiScreenElementsData_Storage : public ObjectStorage <NiScreenElementsDataNode> {};
	using NiScreenElements = Niflib::NiScreenElements;
	class DLL_API NiScreenElementsNode : public BasicNode <NiScreenElements> {};
	class DLL_API NiScreenElements_Storage : public ObjectStorage <NiScreenElementsNode> {};
	using NiRoomGroup = Niflib::NiRoomGroup;
	class DLL_API NiRoomGroupNode : public BasicNode <NiRoomGroup> {};
	class DLL_API NiRoomGroup_Storage : public ObjectStorage <NiRoomGroupNode> {};
	using NiRoom = Niflib::NiRoom;
	class DLL_API NiRoomNode : public BasicNode <NiRoom> {};
	class DLL_API NiRoom_Storage : public ObjectStorage <NiRoomNode> {};
	using NiPortal = Niflib::NiPortal;
	class DLL_API NiPortalNode : public BasicNode <NiPortal> {};
	class DLL_API NiPortal_Storage : public ObjectStorage <NiPortalNode> {};
	using BSFadeNode = Niflib::BSFadeNode;
	class DLL_API BSFadeNodeNode : public BasicNode <BSFadeNode> {};
	class DLL_API BSFadeNode_Storage : public ObjectStorage <BSFadeNodeNode> {};
	using BSShaderProperty = Niflib::BSShaderProperty;
	class DLL_API BSShaderPropertyNode : public BasicNode <BSShaderProperty> {};
	class DLL_API BSShaderProperty_Storage : public ObjectStorage <BSShaderPropertyNode> {};
	using BSShaderLightingProperty = Niflib::BSShaderLightingProperty;
	class DLL_API BSShaderLightingPropertyNode : public BasicNode <BSShaderLightingProperty> {};
	class DLL_API BSShaderLightingProperty_Storage : public ObjectStorage <BSShaderLightingPropertyNode> {};
	using BSShaderNoLightingProperty = Niflib::BSShaderNoLightingProperty;
	class DLL_API BSShaderNoLightingPropertyNode : public BasicNode <BSShaderNoLightingProperty> {};
	class DLL_API BSShaderNoLightingProperty_Storage : public ObjectStorage <BSShaderNoLightingPropertyNode> {};
	using BSShaderPPLightingProperty = Niflib::BSShaderPPLightingProperty;
	class DLL_API BSShaderPPLightingPropertyNode : public BasicNode <BSShaderPPLightingProperty> {};
	class DLL_API BSShaderPPLightingProperty_Storage : public ObjectStorage <BSShaderPPLightingPropertyNode> {};
	using BSEffectShaderPropertyFloatController = Niflib::BSEffectShaderPropertyFloatController;
	class DLL_API BSEffectShaderPropertyFloatControllerNode : public BasicNode <BSEffectShaderPropertyFloatController> {};
	class DLL_API BSEffectShaderPropertyFloatController_Storage : public ObjectStorage <BSEffectShaderPropertyFloatControllerNode> {};
	using BSEffectShaderPropertyColorController = Niflib::BSEffectShaderPropertyColorController;
	class DLL_API BSEffectShaderPropertyColorControllerNode : public BasicNode <BSEffectShaderPropertyColorController> {};
	class DLL_API BSEffectShaderPropertyColorController_Storage : public ObjectStorage <BSEffectShaderPropertyColorControllerNode> {};
	using BSLightingShaderPropertyFloatController = Niflib::BSLightingShaderPropertyFloatController;
	class DLL_API BSLightingShaderPropertyFloatControllerNode : public BasicNode <BSLightingShaderPropertyFloatController> {};
	class DLL_API BSLightingShaderPropertyFloatController_Storage : public ObjectStorage <BSLightingShaderPropertyFloatControllerNode> {};
	using BSLightingShaderPropertyColorController = Niflib::BSLightingShaderPropertyColorController;
	class DLL_API BSLightingShaderPropertyColorControllerNode : public BasicNode <BSLightingShaderPropertyColorController> {};
	class DLL_API BSLightingShaderPropertyColorController_Storage : public ObjectStorage <BSLightingShaderPropertyColorControllerNode> {};
	using BSNiAlphaPropertyTestRefController = Niflib::BSNiAlphaPropertyTestRefController;
	class DLL_API BSNiAlphaPropertyTestRefControllerNode : public BasicNode <BSNiAlphaPropertyTestRefController> {};
	class DLL_API BSNiAlphaPropertyTestRefController_Storage : public ObjectStorage <BSNiAlphaPropertyTestRefControllerNode> {};
	using BSProceduralLightningController = Niflib::BSProceduralLightningController;
	class DLL_API BSProceduralLightningControllerNode : public BasicNode <BSProceduralLightningController> {};
	class DLL_API BSProceduralLightningController_Storage : public ObjectStorage <BSProceduralLightningControllerNode> {};
	using BSShaderTextureSet = Niflib::BSShaderTextureSet;
	class DLL_API BSShaderTextureSetNode : public BasicNode <BSShaderTextureSet> {};
	class DLL_API BSShaderTextureSet_Storage : public ObjectStorage <BSShaderTextureSetNode> {};
	using WaterShaderProperty = Niflib::WaterShaderProperty;
	class DLL_API WaterShaderPropertyNode : public BasicNode <WaterShaderProperty> {};
	class DLL_API WaterShaderProperty_Storage : public ObjectStorage <WaterShaderPropertyNode> {};
	using SkyShaderProperty = Niflib::SkyShaderProperty;
	class DLL_API SkyShaderPropertyNode : public BasicNode <SkyShaderProperty> {};
	class DLL_API SkyShaderProperty_Storage : public ObjectStorage <SkyShaderPropertyNode> {};
	using TileShaderProperty = Niflib::TileShaderProperty;
	class DLL_API TileShaderPropertyNode : public BasicNode <TileShaderProperty> {};
	class DLL_API TileShaderProperty_Storage : public ObjectStorage <TileShaderPropertyNode> {};
	using DistantLODShaderProperty = Niflib::DistantLODShaderProperty;
	class DLL_API DistantLODShaderPropertyNode : public BasicNode <DistantLODShaderProperty> {};
	class DLL_API DistantLODShaderProperty_Storage : public ObjectStorage <DistantLODShaderPropertyNode> {};
	using BSDistantTreeShaderProperty = Niflib::BSDistantTreeShaderProperty;
	class DLL_API BSDistantTreeShaderPropertyNode : public BasicNode <BSDistantTreeShaderProperty> {};
	class DLL_API BSDistantTreeShaderProperty_Storage : public ObjectStorage <BSDistantTreeShaderPropertyNode> {};
	using TallGrassShaderProperty = Niflib::TallGrassShaderProperty;
	class DLL_API TallGrassShaderPropertyNode : public BasicNode <TallGrassShaderProperty> {};
	class DLL_API TallGrassShaderProperty_Storage : public ObjectStorage <TallGrassShaderPropertyNode> {};
	using VolumetricFogShaderProperty = Niflib::VolumetricFogShaderProperty;
	class DLL_API VolumetricFogShaderPropertyNode : public BasicNode <VolumetricFogShaderProperty> {};
	class DLL_API VolumetricFogShaderProperty_Storage : public ObjectStorage <VolumetricFogShaderPropertyNode> {};
	using HairShaderProperty = Niflib::HairShaderProperty;
	class DLL_API HairShaderPropertyNode : public BasicNode <HairShaderProperty> {};
	class DLL_API HairShaderProperty_Storage : public ObjectStorage <HairShaderPropertyNode> {};
	using Lighting30ShaderProperty = Niflib::Lighting30ShaderProperty;
	class DLL_API Lighting30ShaderPropertyNode : public BasicNode <Lighting30ShaderProperty> {};
	class DLL_API Lighting30ShaderProperty_Storage : public ObjectStorage <Lighting30ShaderPropertyNode> {};
	using BSLightingShaderProperty = Niflib::BSLightingShaderProperty;
	class DLL_API BSLightingShaderPropertyNode : public BasicNode <BSLightingShaderProperty> {};
	class DLL_API BSLightingShaderProperty_Storage : public ObjectStorage <BSLightingShaderPropertyNode> {};
	using BSEffectShaderProperty = Niflib::BSEffectShaderProperty;
	class DLL_API BSEffectShaderPropertyNode : public BasicNode <BSEffectShaderProperty> {};
	class DLL_API BSEffectShaderProperty_Storage : public ObjectStorage <BSEffectShaderPropertyNode> {};
	using BSWaterShaderProperty = Niflib::BSWaterShaderProperty;
	class DLL_API BSWaterShaderPropertyNode : public BasicNode <BSWaterShaderProperty> {};
	class DLL_API BSWaterShaderProperty_Storage : public ObjectStorage <BSWaterShaderPropertyNode> {};
	using BSSkyShaderProperty = Niflib::BSSkyShaderProperty;
	class DLL_API BSSkyShaderPropertyNode : public BasicNode <BSSkyShaderProperty> {};
	class DLL_API BSSkyShaderProperty_Storage : public ObjectStorage <BSSkyShaderPropertyNode> {};
	using BSDismemberSkinInstance = Niflib::BSDismemberSkinInstance;
	class DLL_API BSDismemberSkinInstanceNode : public BasicNode <BSDismemberSkinInstance> {};
	class DLL_API BSDismemberSkinInstance_Storage : public ObjectStorage <BSDismemberSkinInstanceNode> {};
	using BSDecalPlacementVectorExtraData = Niflib::BSDecalPlacementVectorExtraData;
	class DLL_API BSDecalPlacementVectorExtraDataNode : public BasicNode <BSDecalPlacementVectorExtraData> {};
	class DLL_API BSDecalPlacementVectorExtraData_Storage : public ObjectStorage <BSDecalPlacementVectorExtraDataNode> {};
	using BSPSysSimpleColorModifier = Niflib::BSPSysSimpleColorModifier;
	class DLL_API BSPSysSimpleColorModifierNode : public BasicNode <BSPSysSimpleColorModifier> {};
	class DLL_API BSPSysSimpleColorModifier_Storage : public ObjectStorage <BSPSysSimpleColorModifierNode> {};
	using BSValueNode = Niflib::BSValueNode;
	class DLL_API BSValueNodeNode : public BasicNode <BSValueNode> {};
	class DLL_API BSValueNode_Storage : public ObjectStorage <BSValueNodeNode> {};
	using BSStripParticleSystem = Niflib::BSStripParticleSystem;
	class DLL_API BSStripParticleSystemNode : public BasicNode <BSStripParticleSystem> {};
	class DLL_API BSStripParticleSystem_Storage : public ObjectStorage <BSStripParticleSystemNode> {};
	using BSStripPSysData = Niflib::BSStripPSysData;
	class DLL_API BSStripPSysDataNode : public BasicNode <BSStripPSysData> {};
	class DLL_API BSStripPSysData_Storage : public ObjectStorage <BSStripPSysDataNode> {};
	using BSPSysStripUpdateModifier = Niflib::BSPSysStripUpdateModifier;
	class DLL_API BSPSysStripUpdateModifierNode : public BasicNode <BSPSysStripUpdateModifier> {};
	class DLL_API BSPSysStripUpdateModifier_Storage : public ObjectStorage <BSPSysStripUpdateModifierNode> {};
	using BSMaterialEmittanceMultController = Niflib::BSMaterialEmittanceMultController;
	class DLL_API BSMaterialEmittanceMultControllerNode : public BasicNode <BSMaterialEmittanceMultController> {};
	class DLL_API BSMaterialEmittanceMultController_Storage : public ObjectStorage <BSMaterialEmittanceMultControllerNode> {};
	using BSMasterParticleSystem = Niflib::BSMasterParticleSystem;
	class DLL_API BSMasterParticleSystemNode : public BasicNode <BSMasterParticleSystem> {};
	class DLL_API BSMasterParticleSystem_Storage : public ObjectStorage <BSMasterParticleSystemNode> {};
	using BSPSysMultiTargetEmitterCtlr = Niflib::BSPSysMultiTargetEmitterCtlr;
	class DLL_API BSPSysMultiTargetEmitterCtlrNode : public BasicNode <BSPSysMultiTargetEmitterCtlr> {};
	class DLL_API BSPSysMultiTargetEmitterCtlr_Storage : public ObjectStorage <BSPSysMultiTargetEmitterCtlrNode> {};
	using BSRefractionStrengthController = Niflib::BSRefractionStrengthController;
	class DLL_API BSRefractionStrengthControllerNode : public BasicNode <BSRefractionStrengthController> {};
	class DLL_API BSRefractionStrengthController_Storage : public ObjectStorage <BSRefractionStrengthControllerNode> {};
	using BSOrderedNode = Niflib::BSOrderedNode;
	class DLL_API BSOrderedNodeNode : public BasicNode <BSOrderedNode> {};
	class DLL_API BSOrderedNode_Storage : public ObjectStorage <BSOrderedNodeNode> {};
	using BSBlastNode = Niflib::BSBlastNode;
	class DLL_API BSBlastNodeNode : public BasicNode <BSBlastNode> {};
	class DLL_API BSBlastNode_Storage : public ObjectStorage <BSBlastNodeNode> {};
	using BSDamageStage = Niflib::BSDamageStage;
	class DLL_API BSDamageStageNode : public BasicNode <BSDamageStage> {};
	class DLL_API BSDamageStage_Storage : public ObjectStorage <BSDamageStageNode> {};
	using BSRefractionFirePeriodController = Niflib::BSRefractionFirePeriodController;
	class DLL_API BSRefractionFirePeriodControllerNode : public BasicNode <BSRefractionFirePeriodController> {};
	class DLL_API BSRefractionFirePeriodController_Storage : public ObjectStorage <BSRefractionFirePeriodControllerNode> {};
	using bhkConvexListShape = Niflib::bhkConvexListShape;
	class DLL_API bhkConvexListShapeNode : public BasicNode <bhkConvexListShape> {};
	class DLL_API bhkConvexListShape_Storage : public ObjectStorage <bhkConvexListShapeNode> {};
	using BSTreadTransfInterpolator = Niflib::BSTreadTransfInterpolator;
	class DLL_API BSTreadTransfInterpolatorNode : public BasicNode <BSTreadTransfInterpolator> {};
	class DLL_API BSTreadTransfInterpolator_Storage : public ObjectStorage <BSTreadTransfInterpolatorNode> {};
	using BSAnimNotes = Niflib::BSAnimNotes;
	class DLL_API BSAnimNotesNode : public BasicNode <BSAnimNotes> {};
	class DLL_API BSAnimNotes_Storage : public ObjectStorage <BSAnimNotesNode> {};
	using bhkLiquidAction = Niflib::bhkLiquidAction;
	class DLL_API bhkLiquidActionNode : public BasicNode <bhkLiquidAction> {};
	class DLL_API bhkLiquidAction_Storage : public ObjectStorage <bhkLiquidActionNode> {};
	using BSMultiBoundNode = Niflib::BSMultiBoundNode;
	class DLL_API BSMultiBoundNodeNode : public BasicNode <BSMultiBoundNode> {};
	class DLL_API BSMultiBoundNode_Storage : public ObjectStorage <BSMultiBoundNodeNode> {};
	using BSMultiBound = Niflib::BSMultiBound;
	class DLL_API BSMultiBoundNode : public BasicNode <BSMultiBound> {};
	class DLL_API BSMultiBound_Storage : public ObjectStorage <BSMultiBoundNode> {};
	using BSMultiBoundData = Niflib::BSMultiBoundData;
	class DLL_API BSMultiBoundDataNode : public BasicNode <BSMultiBoundData> {};
	class DLL_API BSMultiBoundData_Storage : public ObjectStorage <BSMultiBoundDataNode> {};
	using BSMultiBoundOBB = Niflib::BSMultiBoundOBB;
	class DLL_API BSMultiBoundOBBNode : public BasicNode <BSMultiBoundOBB> {};
	class DLL_API BSMultiBoundOBB_Storage : public ObjectStorage <BSMultiBoundOBBNode> {};
	using BSMultiBoundSphere = Niflib::BSMultiBoundSphere;
	class DLL_API BSMultiBoundSphereNode : public BasicNode <BSMultiBoundSphere> {};
	class DLL_API BSMultiBoundSphere_Storage : public ObjectStorage <BSMultiBoundSphereNode> {};
	using BSSegmentedTriShape = Niflib::BSSegmentedTriShape;
	class DLL_API BSSegmentedTriShapeNode : public BasicNode <BSSegmentedTriShape> {};
	class DLL_API BSSegmentedTriShape_Storage : public ObjectStorage <BSSegmentedTriShapeNode> {};
	using BSMultiBoundAABB = Niflib::BSMultiBoundAABB;
	class DLL_API BSMultiBoundAABBNode : public BasicNode <BSMultiBoundAABB> {};
	class DLL_API BSMultiBoundAABB_Storage : public ObjectStorage <BSMultiBoundAABBNode> {};
	using NiAdditionalGeometryData = Niflib::NiAdditionalGeometryData;
	class DLL_API NiAdditionalGeometryDataNode : public BasicNode <NiAdditionalGeometryData> {};
	class DLL_API NiAdditionalGeometryData_Storage : public ObjectStorage <NiAdditionalGeometryDataNode> {};
	using BSPackedAdditionalGeometryData = Niflib::BSPackedAdditionalGeometryData;
	class DLL_API BSPackedAdditionalGeometryDataNode : public BasicNode <BSPackedAdditionalGeometryData> {};
	class DLL_API BSPackedAdditionalGeometryData_Storage : public ObjectStorage <BSPackedAdditionalGeometryDataNode> {};
	using BSWArray = Niflib::BSWArray;
	class DLL_API BSWArrayNode : public BasicNode <BSWArray> {};
	class DLL_API BSWArray_Storage : public ObjectStorage <BSWArrayNode> {};
	using bhkAabbPhantom = Niflib::bhkAabbPhantom;
	class DLL_API bhkAabbPhantomNode : public BasicNode <bhkAabbPhantom> {};
	class DLL_API bhkAabbPhantom_Storage : public ObjectStorage <bhkAabbPhantomNode> {};
	using BSFrustumFOVController = Niflib::BSFrustumFOVController;
	class DLL_API BSFrustumFOVControllerNode : public BasicNode <BSFrustumFOVController> {};
	class DLL_API BSFrustumFOVController_Storage : public ObjectStorage <BSFrustumFOVControllerNode> {};
	using BSDebrisNode = Niflib::BSDebrisNode;
	class DLL_API BSDebrisNodeNode : public BasicNode <BSDebrisNode> {};
	class DLL_API BSDebrisNode_Storage : public ObjectStorage <BSDebrisNodeNode> {};
	using bhkBreakableConstraint = Niflib::bhkBreakableConstraint;
	class DLL_API bhkBreakableConstraintNode : public BasicNode <bhkBreakableConstraint> {};
	class DLL_API bhkBreakableConstraint_Storage : public ObjectStorage <bhkBreakableConstraintNode> {};
	using bhkOrientHingedBodyAction = Niflib::bhkOrientHingedBodyAction;
	class DLL_API bhkOrientHingedBodyActionNode : public BasicNode <bhkOrientHingedBodyAction> {};
	class DLL_API bhkOrientHingedBodyAction_Storage : public ObjectStorage <bhkOrientHingedBodyActionNode> {};
	using NiDataStream = Niflib::NiDataStream;
	class DLL_API NiDataStreamNode : public BasicNode <NiDataStream> {};
	class DLL_API NiDataStream_Storage : public ObjectStorage <NiDataStreamNode> {};
	using NiRenderObject = Niflib::NiRenderObject;
	class DLL_API NiRenderObjectNode : public BasicNode <NiRenderObject> {};
	class DLL_API NiRenderObject_Storage : public ObjectStorage <NiRenderObjectNode> {};
	using NiMeshModifier = Niflib::NiMeshModifier;
	class DLL_API NiMeshModifierNode : public BasicNode <NiMeshModifier> {};
	class DLL_API NiMeshModifier_Storage : public ObjectStorage <NiMeshModifierNode> {};
	using NiMesh = Niflib::NiMesh;
	class DLL_API NiMeshNode : public BasicNode <NiMesh> {};
	class DLL_API NiMesh_Storage : public ObjectStorage <NiMeshNode> {};
	using NiMorphWeightsController = Niflib::NiMorphWeightsController;
	class DLL_API NiMorphWeightsControllerNode : public BasicNode <NiMorphWeightsController> {};
	class DLL_API NiMorphWeightsController_Storage : public ObjectStorage <NiMorphWeightsControllerNode> {};
	using NiMorphMeshModifier = Niflib::NiMorphMeshModifier;
	class DLL_API NiMorphMeshModifierNode : public BasicNode <NiMorphMeshModifier> {};
	class DLL_API NiMorphMeshModifier_Storage : public ObjectStorage <NiMorphMeshModifierNode> {};
	using NiSkinningMeshModifier = Niflib::NiSkinningMeshModifier;
	class DLL_API NiSkinningMeshModifierNode : public BasicNode <NiSkinningMeshModifier> {};
	class DLL_API NiSkinningMeshModifier_Storage : public ObjectStorage <NiSkinningMeshModifierNode> {};
	using NiInstancingMeshModifier = Niflib::NiInstancingMeshModifier;
	class DLL_API NiInstancingMeshModifierNode : public BasicNode <NiInstancingMeshModifier> {};
	class DLL_API NiInstancingMeshModifier_Storage : public ObjectStorage <NiInstancingMeshModifierNode> {};
	using NiSkinningLODController = Niflib::NiSkinningLODController;
	class DLL_API NiSkinningLODControllerNode : public BasicNode <NiSkinningLODController> {};
	class DLL_API NiSkinningLODController_Storage : public ObjectStorage <NiSkinningLODControllerNode> {};
	using NiPSParticleSystem = Niflib::NiPSParticleSystem;
	class DLL_API NiPSParticleSystemNode : public BasicNode <NiPSParticleSystem> {};
	class DLL_API NiPSParticleSystem_Storage : public ObjectStorage <NiPSParticleSystemNode> {};
	using NiPSMeshParticleSystem = Niflib::NiPSMeshParticleSystem;
	class DLL_API NiPSMeshParticleSystemNode : public BasicNode <NiPSMeshParticleSystem> {};
	class DLL_API NiPSMeshParticleSystem_Storage : public ObjectStorage <NiPSMeshParticleSystemNode> {};
	using NiPSEmitParticlesCtlr = Niflib::NiPSEmitParticlesCtlr;
	class DLL_API NiPSEmitParticlesCtlrNode : public BasicNode <NiPSEmitParticlesCtlr> {};
	class DLL_API NiPSEmitParticlesCtlr_Storage : public ObjectStorage <NiPSEmitParticlesCtlrNode> {};
	using NiPSForceActiveCtlr = Niflib::NiPSForceActiveCtlr;
	class DLL_API NiPSForceActiveCtlrNode : public BasicNode <NiPSForceActiveCtlr> {};
	class DLL_API NiPSForceActiveCtlr_Storage : public ObjectStorage <NiPSForceActiveCtlrNode> {};
	using NiPSSimulator = Niflib::NiPSSimulator;
	class DLL_API NiPSSimulatorNode : public BasicNode <NiPSSimulator> {};
	class DLL_API NiPSSimulator_Storage : public ObjectStorage <NiPSSimulatorNode> {};
	using NiPSSimulatorStep = Niflib::NiPSSimulatorStep;
	class DLL_API NiPSSimulatorStepNode : public BasicNode <NiPSSimulatorStep> {};
	class DLL_API NiPSSimulatorStep_Storage : public ObjectStorage <NiPSSimulatorStepNode> {};
	using NiPSSimulatorGeneralStep = Niflib::NiPSSimulatorGeneralStep;
	class DLL_API NiPSSimulatorGeneralStepNode : public BasicNode <NiPSSimulatorGeneralStep> {};
	class DLL_API NiPSSimulatorGeneralStep_Storage : public ObjectStorage <NiPSSimulatorGeneralStepNode> {};
	using NiPSSimulatorForcesStep = Niflib::NiPSSimulatorForcesStep;
	class DLL_API NiPSSimulatorForcesStepNode : public BasicNode <NiPSSimulatorForcesStep> {};
	class DLL_API NiPSSimulatorForcesStep_Storage : public ObjectStorage <NiPSSimulatorForcesStepNode> {};
	using NiPSSimulatorCollidersStep = Niflib::NiPSSimulatorCollidersStep;
	class DLL_API NiPSSimulatorCollidersStepNode : public BasicNode <NiPSSimulatorCollidersStep> {};
	class DLL_API NiPSSimulatorCollidersStep_Storage : public ObjectStorage <NiPSSimulatorCollidersStepNode> {};
	using NiPSSimulatorMeshAlignStep = Niflib::NiPSSimulatorMeshAlignStep;
	class DLL_API NiPSSimulatorMeshAlignStepNode : public BasicNode <NiPSSimulatorMeshAlignStep> {};
	class DLL_API NiPSSimulatorMeshAlignStep_Storage : public ObjectStorage <NiPSSimulatorMeshAlignStepNode> {};
	using NiPSSimulatorFinalStep = Niflib::NiPSSimulatorFinalStep;
	class DLL_API NiPSSimulatorFinalStepNode : public BasicNode <NiPSSimulatorFinalStep> {};
	class DLL_API NiPSSimulatorFinalStep_Storage : public ObjectStorage <NiPSSimulatorFinalStepNode> {};
	using NiPSFacingQuadGenerator = Niflib::NiPSFacingQuadGenerator;
	class DLL_API NiPSFacingQuadGeneratorNode : public BasicNode <NiPSFacingQuadGenerator> {};
	class DLL_API NiPSFacingQuadGenerator_Storage : public ObjectStorage <NiPSFacingQuadGeneratorNode> {};
	using NiShadowGenerator = Niflib::NiShadowGenerator;
	class DLL_API NiShadowGeneratorNode : public BasicNode <NiShadowGenerator> {};
	class DLL_API NiShadowGenerator_Storage : public ObjectStorage <NiShadowGeneratorNode> {};
	using NiPSBoundUpdater = Niflib::NiPSBoundUpdater;
	class DLL_API NiPSBoundUpdaterNode : public BasicNode <NiPSBoundUpdater> {};
	class DLL_API NiPSBoundUpdater_Storage : public ObjectStorage <NiPSBoundUpdaterNode> {};
	using NiPSDragForce = Niflib::NiPSDragForce;
	class DLL_API NiPSDragForceNode : public BasicNode <NiPSDragForce> {};
	class DLL_API NiPSDragForce_Storage : public ObjectStorage <NiPSDragForceNode> {};
	using NiPSGravityForce = Niflib::NiPSGravityForce;
	class DLL_API NiPSGravityForceNode : public BasicNode <NiPSGravityForce> {};
	class DLL_API NiPSGravityForce_Storage : public ObjectStorage <NiPSGravityForceNode> {};
	using NiPSBoxEmitter = Niflib::NiPSBoxEmitter;
	class DLL_API NiPSBoxEmitterNode : public BasicNode <NiPSBoxEmitter> {};
	class DLL_API NiPSBoxEmitter_Storage : public ObjectStorage <NiPSBoxEmitterNode> {};
	using NiPSMeshEmitter = Niflib::NiPSMeshEmitter;
	class DLL_API NiPSMeshEmitterNode : public BasicNode <NiPSMeshEmitter> {};
	class DLL_API NiPSMeshEmitter_Storage : public ObjectStorage <NiPSMeshEmitterNode> {};
	using NiPSGravityStrengthCtlr = Niflib::NiPSGravityStrengthCtlr;
	class DLL_API NiPSGravityStrengthCtlrNode : public BasicNode <NiPSGravityStrengthCtlr> {};
	class DLL_API NiPSGravityStrengthCtlr_Storage : public ObjectStorage <NiPSGravityStrengthCtlrNode> {};
	using NiPSPlanarCollider = Niflib::NiPSPlanarCollider;
	class DLL_API NiPSPlanarColliderNode : public BasicNode <NiPSPlanarCollider> {};
	class DLL_API NiPSPlanarCollider_Storage : public ObjectStorage <NiPSPlanarColliderNode> {};
	using NiPSEmitterSpeedCtlr = Niflib::NiPSEmitterSpeedCtlr;
	class DLL_API NiPSEmitterSpeedCtlrNode : public BasicNode <NiPSEmitterSpeedCtlr> {};
	class DLL_API NiPSEmitterSpeedCtlr_Storage : public ObjectStorage <NiPSEmitterSpeedCtlrNode> {};
	using NiPSEmitterRadiusCtlr = Niflib::NiPSEmitterRadiusCtlr;
	class DLL_API NiPSEmitterRadiusCtlrNode : public BasicNode <NiPSEmitterRadiusCtlr> {};
	class DLL_API NiPSEmitterRadiusCtlr_Storage : public ObjectStorage <NiPSEmitterRadiusCtlrNode> {};
	using NiPSResetOnLoopCtlr = Niflib::NiPSResetOnLoopCtlr;
	class DLL_API NiPSResetOnLoopCtlrNode : public BasicNode <NiPSResetOnLoopCtlr> {};
	class DLL_API NiPSResetOnLoopCtlr_Storage : public ObjectStorage <NiPSResetOnLoopCtlrNode> {};
	using NiPSSphereEmitter = Niflib::NiPSSphereEmitter;
	class DLL_API NiPSSphereEmitterNode : public BasicNode <NiPSSphereEmitter> {};
	class DLL_API NiPSSphereEmitter_Storage : public ObjectStorage <NiPSSphereEmitterNode> {};
	using NiPSCylinderEmitter = Niflib::NiPSCylinderEmitter;
	class DLL_API NiPSCylinderEmitterNode : public BasicNode <NiPSCylinderEmitter> {};
	class DLL_API NiPSCylinderEmitter_Storage : public ObjectStorage <NiPSCylinderEmitterNode> {};
	using NiPSEmitterDeclinationCtlr = Niflib::NiPSEmitterDeclinationCtlr;
	class DLL_API NiPSEmitterDeclinationCtlrNode : public BasicNode <NiPSEmitterDeclinationCtlr> {};
	class DLL_API NiPSEmitterDeclinationCtlr_Storage : public ObjectStorage <NiPSEmitterDeclinationCtlrNode> {};
	using NiPSEmitterDeclinationVarCtlr = Niflib::NiPSEmitterDeclinationVarCtlr;
	class DLL_API NiPSEmitterDeclinationVarCtlrNode : public BasicNode <NiPSEmitterDeclinationVarCtlr> {};
	class DLL_API NiPSEmitterDeclinationVarCtlr_Storage : public ObjectStorage <NiPSEmitterDeclinationVarCtlrNode> {};
	using NiPSEmitterPlanarAngleCtlr = Niflib::NiPSEmitterPlanarAngleCtlr;
	class DLL_API NiPSEmitterPlanarAngleCtlrNode : public BasicNode <NiPSEmitterPlanarAngleCtlr> {};
	class DLL_API NiPSEmitterPlanarAngleCtlr_Storage : public ObjectStorage <NiPSEmitterPlanarAngleCtlrNode> {};
	using NiPSEmitterPlanarAngleVarCtlr = Niflib::NiPSEmitterPlanarAngleVarCtlr;
	class DLL_API NiPSEmitterPlanarAngleVarCtlrNode : public BasicNode <NiPSEmitterPlanarAngleVarCtlr> {};
	class DLL_API NiPSEmitterPlanarAngleVarCtlr_Storage : public ObjectStorage <NiPSEmitterPlanarAngleVarCtlrNode> {};
	using NiPSEmitterRotAngleCtlr = Niflib::NiPSEmitterRotAngleCtlr;
	class DLL_API NiPSEmitterRotAngleCtlrNode : public BasicNode <NiPSEmitterRotAngleCtlr> {};
	class DLL_API NiPSEmitterRotAngleCtlr_Storage : public ObjectStorage <NiPSEmitterRotAngleCtlrNode> {};
	using NiPSEmitterRotAngleVarCtlr = Niflib::NiPSEmitterRotAngleVarCtlr;
	class DLL_API NiPSEmitterRotAngleVarCtlrNode : public BasicNode <NiPSEmitterRotAngleVarCtlr> {};
	class DLL_API NiPSEmitterRotAngleVarCtlr_Storage : public ObjectStorage <NiPSEmitterRotAngleVarCtlrNode> {};
	using NiPSEmitterRotSpeedCtlr = Niflib::NiPSEmitterRotSpeedCtlr;
	class DLL_API NiPSEmitterRotSpeedCtlrNode : public BasicNode <NiPSEmitterRotSpeedCtlr> {};
	class DLL_API NiPSEmitterRotSpeedCtlr_Storage : public ObjectStorage <NiPSEmitterRotSpeedCtlrNode> {};
	using NiPSEmitterRotSpeedVarCtlr = Niflib::NiPSEmitterRotSpeedVarCtlr;
	class DLL_API NiPSEmitterRotSpeedVarCtlrNode : public BasicNode <NiPSEmitterRotSpeedVarCtlr> {};
	class DLL_API NiPSEmitterRotSpeedVarCtlr_Storage : public ObjectStorage <NiPSEmitterRotSpeedVarCtlrNode> {};
	using NiPSEmitterLifeSpanCtlr = Niflib::NiPSEmitterLifeSpanCtlr;
	class DLL_API NiPSEmitterLifeSpanCtlrNode : public BasicNode <NiPSEmitterLifeSpanCtlr> {};
	class DLL_API NiPSEmitterLifeSpanCtlr_Storage : public ObjectStorage <NiPSEmitterLifeSpanCtlrNode> {};
	using NiPSBombForce = Niflib::NiPSBombForce;
	class DLL_API NiPSBombForceNode : public BasicNode <NiPSBombForce> {};
	class DLL_API NiPSBombForce_Storage : public ObjectStorage <NiPSBombForceNode> {};
	using NiPSSphericalCollider = Niflib::NiPSSphericalCollider;
	class DLL_API NiPSSphericalColliderNode : public BasicNode <NiPSSphericalCollider> {};
	class DLL_API NiPSSphericalCollider_Storage : public ObjectStorage <NiPSSphericalColliderNode> {};
	using NiPSSpawner = Niflib::NiPSSpawner;
	class DLL_API NiPSSpawnerNode : public BasicNode <NiPSSpawner> {};
	class DLL_API NiPSSpawner_Storage : public ObjectStorage <NiPSSpawnerNode> {};
	using NiSequenceData = Niflib::NiSequenceData;
	class DLL_API NiSequenceDataNode : public BasicNode <NiSequenceData> {};
	class DLL_API NiSequenceData_Storage : public ObjectStorage <NiSequenceDataNode> {};
	using NiTransformEvaluator = Niflib::NiTransformEvaluator;
	class DLL_API NiTransformEvaluatorNode : public BasicNode <NiTransformEvaluator> {};
	class DLL_API NiTransformEvaluator_Storage : public ObjectStorage <NiTransformEvaluatorNode> {};
	using NiBSplineCompTransformEvaluator = Niflib::NiBSplineCompTransformEvaluator;
	class DLL_API NiBSplineCompTransformEvaluatorNode : public BasicNode <NiBSplineCompTransformEvaluator> {};
	class DLL_API NiBSplineCompTransformEvaluator_Storage : public ObjectStorage <NiBSplineCompTransformEvaluatorNode> {};
	using NiMeshHWInstance = Niflib::NiMeshHWInstance;
	class DLL_API NiMeshHWInstanceNode : public BasicNode <NiMeshHWInstance> {};
	class DLL_API NiMeshHWInstance_Storage : public ObjectStorage <NiMeshHWInstanceNode> {};
	using NiFurSpringController = Niflib::NiFurSpringController;
	class DLL_API NiFurSpringControllerNode : public BasicNode <NiFurSpringController> {};
	class DLL_API NiFurSpringController_Storage : public ObjectStorage <NiFurSpringControllerNode> {};
	using CStreamableAssetData = Niflib::CStreamableAssetData;
	class DLL_API CStreamableAssetDataNode : public BasicNode <CStreamableAssetData> {};
	class DLL_API CStreamableAssetData_Storage : public ObjectStorage <CStreamableAssetDataNode> {};
	using bhkCompressedMeshShape = Niflib::bhkCompressedMeshShape;
	class DLL_API bhkCompressedMeshShapeNode : public BasicNode <bhkCompressedMeshShape> {};
	class DLL_API bhkCompressedMeshShape_Storage : public ObjectStorage <bhkCompressedMeshShapeNode> {};
	using bhkCompressedMeshShapeData = Niflib::bhkCompressedMeshShapeData;
	class DLL_API bhkCompressedMeshShapeDataNode : public BasicNode <bhkCompressedMeshShapeData> {};
	class DLL_API bhkCompressedMeshShapeData_Storage : public ObjectStorage <bhkCompressedMeshShapeDataNode> {};
	using BSInvMarker = Niflib::BSInvMarker;
	class DLL_API BSInvMarkerNode : public BasicNode <BSInvMarker> {};
	class DLL_API BSInvMarker_Storage : public ObjectStorage <BSInvMarkerNode> {};
	using BSBoneLODExtraData = Niflib::BSBoneLODExtraData;
	class DLL_API BSBoneLODExtraDataNode : public BasicNode <BSBoneLODExtraData> {};
	class DLL_API BSBoneLODExtraData_Storage : public ObjectStorage <BSBoneLODExtraDataNode> {};
	using BSBehaviorGraphExtraData = Niflib::BSBehaviorGraphExtraData;
	class DLL_API BSBehaviorGraphExtraDataNode : public BasicNode <BSBehaviorGraphExtraData> {};
	class DLL_API BSBehaviorGraphExtraData_Storage : public ObjectStorage <BSBehaviorGraphExtraDataNode> {};
	using BSLagBoneController = Niflib::BSLagBoneController;
	class DLL_API BSLagBoneControllerNode : public BasicNode <BSLagBoneController> {};
	class DLL_API BSLagBoneController_Storage : public ObjectStorage <BSLagBoneControllerNode> {};
	using BSLODTriShape = Niflib::BSLODTriShape;
	class DLL_API BSLODTriShapeNode : public BasicNode <BSLODTriShape> {};
	class DLL_API BSLODTriShape_Storage : public ObjectStorage <BSLODTriShapeNode> {};
	using BSFurnitureMarkerNode = Niflib::BSFurnitureMarkerNode;
	class DLL_API BSFurnitureMarkerNodeNode : public BasicNode <BSFurnitureMarkerNode> {};
	class DLL_API BSFurnitureMarkerNode_Storage : public ObjectStorage <BSFurnitureMarkerNodeNode> {};
	using BSLeafAnimNode = Niflib::BSLeafAnimNode;
	class DLL_API BSLeafAnimNodeNode : public BasicNode <BSLeafAnimNode> {};
	class DLL_API BSLeafAnimNode_Storage : public ObjectStorage <BSLeafAnimNodeNode> {};
	using BSTreeNode = Niflib::BSTreeNode;
	class DLL_API BSTreeNodeNode : public BasicNode <BSTreeNode> {};
	class DLL_API BSTreeNode_Storage : public ObjectStorage <BSTreeNodeNode> {};
	using NiLightRadiusController = Niflib::NiLightRadiusController;
	class DLL_API NiLightRadiusControllerNode : public BasicNode <NiLightRadiusController> {};
	class DLL_API NiLightRadiusController_Storage : public ObjectStorage <NiLightRadiusControllerNode> {};
	using BSShape = Niflib::BSShape;
	class DLL_API BSShapeNode : public BasicNode <BSShape> {};
	class DLL_API BSShape_Storage : public ObjectStorage <BSShapeNode> {};
	using BSTriShape = Niflib::BSTriShape;
	class DLL_API BSTriShapeNode : public BasicNode <BSTriShape> {};
	class DLL_API BSTriShape_Storage : public ObjectStorage <BSTriShapeNode> {};
	using BSSubIndexTriShape = Niflib::BSSubIndexTriShape;
	class DLL_API BSSubIndexTriShapeNode : public BasicNode <BSSubIndexTriShape> {};
	class DLL_API BSSubIndexTriShape_Storage : public ObjectStorage <BSSubIndexTriShapeNode> {};
	using BSMeshLODTriShape = Niflib::BSMeshLODTriShape;
	class DLL_API BSMeshLODTriShapeNode : public BasicNode <BSMeshLODTriShape> {};
	class DLL_API BSMeshLODTriShape_Storage : public ObjectStorage <BSMeshLODTriShapeNode> {};
	using bhkNPCollisionObject = Niflib::bhkNPCollisionObject;
	class DLL_API bhkNPCollisionObjectNode : public BasicNode <bhkNPCollisionObject> {};
	class DLL_API bhkNPCollisionObject_Storage : public ObjectStorage <bhkNPCollisionObjectNode> {};
	using BSExtraData = Niflib::BSExtraData;
	class DLL_API BSExtraDataNode : public BasicNode <BSExtraData> {};
	class DLL_API BSExtraData_Storage : public ObjectStorage <BSExtraDataNode> {};
	using bhkPhysicsSystem = Niflib::bhkPhysicsSystem;
	class DLL_API bhkPhysicsSystemNode : public BasicNode <bhkPhysicsSystem> {};
	class DLL_API bhkPhysicsSystem_Storage : public ObjectStorage <bhkPhysicsSystemNode> {};
	using bhkRagdollSystem = Niflib::bhkRagdollSystem;
	class DLL_API bhkRagdollSystemNode : public BasicNode <bhkRagdollSystem> {};
	class DLL_API bhkRagdollSystem_Storage : public ObjectStorage <bhkRagdollSystemNode> {};
	using BSClothExtraData = Niflib::BSClothExtraData;
	class DLL_API BSClothExtraDataNode : public BasicNode <BSClothExtraData> {};
	class DLL_API BSClothExtraData_Storage : public ObjectStorage <BSClothExtraDataNode> {};
	using BSSkin__Instance = Niflib::BSSkin__Instance;
	class DLL_API BSSkin__InstanceNode : public BasicNode <BSSkin__Instance> {};
	class DLL_API BSSkin__Instance_Storage : public ObjectStorage <BSSkin__InstanceNode> {};
	using BSSkin__BoneData = Niflib::BSSkin__BoneData;
	class DLL_API BSSkin__BoneDataNode : public BasicNode <BSSkin__BoneData> {};
	class DLL_API BSSkin__BoneData_Storage : public ObjectStorage <BSSkin__BoneDataNode> {};
	using BSPositionData = Niflib::BSPositionData;
	class DLL_API BSPositionDataNode : public BasicNode <BSPositionData> {};
	class DLL_API BSPositionData_Storage : public ObjectStorage <BSPositionDataNode> {};
	using BSConnectPoint__Parents = Niflib::BSConnectPoint__Parents;
	class DLL_API BSConnectPoint__ParentsNode : public BasicNode <BSConnectPoint__Parents> {};
	class DLL_API BSConnectPoint__Parents_Storage : public ObjectStorage <BSConnectPoint__ParentsNode> {};
	using BSConnectPoint__Children = Niflib::BSConnectPoint__Children;
	class DLL_API BSConnectPoint__ChildrenNode : public BasicNode <BSConnectPoint__Children> {};
	class DLL_API BSConnectPoint__Children_Storage : public ObjectStorage <BSConnectPoint__ChildrenNode> {};
	//End of ObjectRegistry Node class-section
};
#endif