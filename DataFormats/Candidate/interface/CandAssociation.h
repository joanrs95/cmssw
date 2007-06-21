#ifndef Candidate_CandAssociation_h
#define Candidate_CandAssociation_h
//
// \author Luca Lista, INFN
//
#include "DataFormats/Common/interface/AssociationVector.h"
#include "DataFormats/Candidate/interface/Candidate.h"
#include <vector>

namespace edm {
  namespace helper {
    struct CandMasterKeyReference {
      template<typename CandRef>
      static const CandRef & get( const CandRef & t, edm::ProductID id ) { 
	if ( id == t.id() ) return t;
	else return t->masterClone().template castTo<CandRef>(); 
      }
    };

    template<>
    struct AssociationKeyReferenceTrait<reco::CandidateCollection> {
      typedef CandMasterKeyReference type;
    };

  }
}

namespace reco {
  typedef edm::AssociationVector<CandidateRefProd, std::vector<float> > CandFloatAssociations;
  typedef edm::AssociationVector<CandidateRefProd, std::vector<double> > CandDoubleAssociations;
  typedef edm::AssociationVector<CandidateRefProd, std::vector<int> > CandIntAssociations;
  typedef edm::AssociationVector<CandidateRefProd, std::vector<unsigned int> > CandUIntAssociations;
}

#endif
