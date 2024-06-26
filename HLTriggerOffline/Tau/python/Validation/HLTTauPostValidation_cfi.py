import FWCore.ParameterSet.Config as cms

from HLTriggerOffline.Tau.Validation.HLTTauValidation_cfi import *
import DQMOffline.Trigger.HLTTauPostProcessor_cfi as postProcessor

(HLTTauValPostAnalysisMC, HLTTauValPostAnalysisMC2) = postProcessor.makePFTauAnalyzer(hltTauValIdealMonitorMC)
(HLTTauValPostAnalysisPF, HLTTauValPostAnalysisPF2) = postProcessor.makePFTauAnalyzer(hltTauValIdealMonitorPF)
(HLTTauValPostAnalysisPN, HLTTauValPostAnalysisPN2) = postProcessor.makePFTauAnalyzer(hltTauValIdealMonitorPNet)
(HLTTauValPostAnalysisTP, HLTTauValPostAnalysisTP2) = postProcessor.makePFTauAnalyzer(hltTauValTagAndProbe)
HLTTauPostVal = cms.Sequence(
    HLTTauValPostAnalysisMC+HLTTauValPostAnalysisMC2+
    HLTTauValPostAnalysisPF+HLTTauValPostAnalysisPF2+
    HLTTauValPostAnalysisPN+HLTTauValPostAnalysisPN2+
    HLTTauValPostAnalysisTP+HLTTauValPostAnalysisTP2
)
