#include <cstdint>
#include "CondFormats/EcalObjects/interface/EcalCondObjectContainer.h"
#include "CondFormats/EcalObjects/interface/EcalCondTowerObjectContainer.h"
#include "CondFormats/EcalObjects/interface/EcalPedestals.h"
#include "CondFormats/EcalObjects/interface/EcalWeightXtalGroups.h"
#include "CondFormats/EcalObjects/interface/EcalXtalGroupId.h"
#include "CondFormats/EcalObjects/interface/EcalTBWeights.h"
#include "CondFormats/EcalObjects/interface/EcalWeightSet.h"
#include "CondFormats/EcalObjects/interface/EcalSampleMask.h"
#include "CondFormats/EcalObjects/interface/EcalADCToGeVConstant.h"
#include "CondFormats/EcalObjects/interface/EcalGainRatios.h"
#include "CondFormats/EcalObjects/interface/EcalMGPAGainRatio.h"
#include "CondFormats/EcalObjects/interface/EcalIntercalibConstants.h"
#include "CondFormats/EcalObjects/interface/EcalIntercalibConstantsMC.h"
#include "CondFormats/EcalObjects/interface/EcalIntercalibErrors.h"
#include "CondFormats/EcalObjects/interface/EcalTimeBiasCorrections.h"
#include "CondFormats/EcalObjects/interface/EcalSamplesCorrelation.h"
#include "CondFormats/EcalObjects/interface/EcalPulseShapes.h"
#include "CondFormats/EcalObjects/interface/EcalPulseCovariances.h"
#include "CondFormats/EcalObjects/interface/EcalPulseSymmCovariances.h"
#include "CondFormats/EcalObjects/interface/EcalTimeCalibConstants.h"
#include "CondFormats/EcalObjects/interface/EcalTimeCalibErrors.h"
#include "CondFormats/EcalObjects/interface/EcalTimeOffsetConstant.h"
#include "CondFormats/EcalObjects/interface/EcalDCUTemperatures.h"
#include "CondFormats/EcalObjects/interface/EcalPTMTemperatures.h"
#include "CondFormats/EcalObjects/interface/EcalChannelStatus.h"
#include "CondFormats/EcalObjects/interface/EcalDQMTowerStatus.h"
#include "CondFormats/EcalObjects/interface/EcalDQMChannelStatus.h"
#include "CondFormats/EcalObjects/interface/EcalDCSTowerStatus.h"
#include "CondFormats/EcalObjects/interface/EcalDAQTowerStatus.h"
#include "CondFormats/EcalObjects/interface/EcalChannelStatusCode.h"
#include "CondFormats/EcalObjects/interface/EcalDAQStatusCode.h"
#include "CondFormats/EcalObjects/interface/EcalLaserAlphas.h"
#include "CondFormats/EcalObjects/interface/EcalTimeDependentCorrections.h"
#include "CondFormats/EcalObjects/interface/EcalLaserAPDPNRatios.h"
#include "CondFormats/EcalObjects/interface/EcalLinearCorrections.h"
#include "CondFormats/EcalObjects/interface/EcalLaserAPDPNRatiosRef.h"
#include "CondFormats/EcalObjects/interface/EcalTPGFineGrainEBIdMap.h"
#include "CondFormats/EcalObjects/interface/EcalTPGFineGrainStripEE.h"
#include "CondFormats/EcalObjects/interface/EcalTPGFineGrainTowerEE.h"
#include "CondFormats/EcalObjects/interface/EcalTPGFineGrainConstEB.h"
#include "CondFormats/EcalObjects/interface/EcalTPGTowerStatus.h"
#include "CondFormats/EcalObjects/interface/EcalTPGGroups.h"
#include "CondFormats/EcalObjects/interface/EcalTPGLinearizationConst.h"
#include "CondFormats/EcalObjects/interface/EcalTPGLutIdMap.h"
#include "CondFormats/EcalObjects/interface/EcalTPGPedestals.h"
#include "CondFormats/EcalObjects/interface/EcalTPGWeightIdMap.h"
#include "CondFormats/EcalObjects/interface/EcalTPGOddWeightIdMap.h"
#include "CondFormats/EcalObjects/interface/EcalTPGSlidingWindow.h"
#include "CondFormats/EcalObjects/interface/EcalMappingElectronics.h"
#include "CondFormats/EcalObjects/interface/EcalFunctionParameters.h"
#include "CondFormats/EcalObjects/interface/EcalClusterLocalContCorrParameters.h"
#include "CondFormats/EcalObjects/interface/EcalPFRecHitThresholds.h"
#include "CondFormats/EcalObjects/interface/EcalClusterCrackCorrParameters.h"
#include "CondFormats/EcalObjects/interface/EcalClusterEnergyCorrectionParameters.h"
#include "CondFormats/EcalObjects/interface/EcalClusterEnergyUncertaintyParameters.h"
#include "CondFormats/EcalObjects/interface/EcalClusterEnergyCorrectionObjectSpecificParameters.h"
#include "CondFormats/EcalObjects/interface/EcalTPGFineGrainEBGroup.h"
#include "CondFormats/EcalObjects/interface/EcalTPGLutGroup.h"
#include "CondFormats/EcalObjects/interface/EcalTPGWeightGroup.h"
#include "CondFormats/EcalObjects/interface/EcalTPGOddWeightGroup.h"
#include "CondFormats/EcalObjects/interface/EcalTPGTPMode.h"
#include "CondFormats/EcalObjects/interface/EcalTPGPhysicsConst.h"
#include "CondFormats/EcalObjects/interface/EcalTPGCrystalStatus.h"
#include "CondFormats/EcalObjects/interface/EcalTPGCrystalStatusCode.h"
#include "CondFormats/EcalObjects/interface/EcalTPGStripStatus.h"
#include "CondFormats/EcalObjects/interface/EcalTPGSpike.h"
#include "CondFormats/EcalObjects/interface/EcalSRSettings.h"
#include "CondFormats/EcalObjects/interface/EcalSimPulseShape.h"
#include "CondFormats/EcalObjects/interface/EcalSimComponentShape.h"
#include "CondFormats/EcalObjects/interface/EcalMustacheSCParameters.h"
#include "CondFormats/EcalObjects/interface/EcalSCDynamicDPhiParameters.h"
//ECAL PH2:
#include "CondFormats/EcalObjects/interface/EcalLiteDTUPedestals.h"
#include "CondFormats/EcalObjects/interface/EcalCATIAGainRatios.h"
#include "CondFormats/EcalObjects/interface/EcalEBPhase2TPGAmplWeightIdMap.h"
#include "CondFormats/EcalObjects/interface/EcalEBPhase2TPGTimeWeightIdMap.h"
#include "CondFormats/EcalObjects/interface/EcalEBPhase2TPGLinearizationConst.h"
#include "CondFormats/EcalObjects/interface/EcalEBPhase2TPGPedestals.h"
