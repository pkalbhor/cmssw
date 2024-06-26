#ifndef DataFormats_L1Trigger_ETSum_h
#define DataFormats_L1Trigger_ETSum_h

#include "DataFormats/L1Trigger/interface/L1Candidate.h"
#include "DataFormats/L1Trigger/interface/BXVector.h"
#include "DataFormats/L1Trigger/interface/L1TObjComparison.h"

namespace l1t {

  class EtSum;
  typedef BXVector<EtSum> EtSumBxCollection;
  typedef edm::Ref<EtSumBxCollection> EtSumRef;
  typedef edm::RefVector<EtSumBxCollection> EtSumRefVector;
  typedef std::vector<EtSumRef> EtSumVectorRef;
  // Phase-2
  typedef std::vector<EtSum> EtSumP2Collection;
  typedef edm::Ref<EtSumP2Collection> EtSumP2Ref;
  typedef edm::RefVector<EtSumP2Collection> EtSumP2RefVector;
  typedef std::vector<EtSumP2Ref> EtSumVectorP2Ref;

  typedef ObjectRefBxCollection<EtSum> EtSumRefBxCollection;
  typedef ObjectRefPair<EtSum> EtSumRefPair;
  typedef ObjectRefPairBxCollection<EtSum> EtSumRefPairBxCollection;

  class EtSum : public L1Candidate {
  public:
    enum EtSumType {
      kTotalEt,
      kTotalHt,
      kMissingEt,
      kMissingHt,
      kTotalEtx,
      kTotalEty,
      kTotalHtx,
      kTotalHty,
      kMissingEtHF,
      kTotalEtxHF,
      kTotalEtyHF,
      kMinBiasHFP0,
      kMinBiasHFM0,
      kMinBiasHFP1,
      kMinBiasHFM1,
      kTotalEtHF,
      kTotalEtEm,
      kTotalHtHF,
      kTotalHtxHF,
      kTotalHtyHF,
      kMissingHtHF,
      kTowerCount,
      kCentrality,
      kAsymEt,
      kAsymHt,
      kAsymEtHF,
      kAsymHtHF,
      kZDCP,
      kZDCM,
      kUninitialized
    };

    EtSum() : type_{kUninitialized} {}
    explicit EtSum(EtSumType type) : type_{type} {}

    EtSum(const LorentzVector& p4, EtSumType type, int pt = 0, int eta = 0, int phi = 0, int qual = 0);

    EtSum(const PolarLorentzVector& p4, EtSumType type, int pt = 0, int eta = 0, int phi = 0, int qual = 0);

    ~EtSum() override;

    void setType(EtSumType type);

    EtSumType getType() const;

    bool operator==(const l1t::EtSum& rhs) const;
    inline bool operator!=(const l1t::EtSum& rhs) const { return !(operator==(rhs)); };

  private:
    using L1Candidate::operator==;
    using L1Candidate::operator!=;
    // type of EtSum
    EtSumType type_;

    // additional hardware quantities common to L1 global EtSum
    // there are currently none
  };

}  // namespace l1t

#endif
