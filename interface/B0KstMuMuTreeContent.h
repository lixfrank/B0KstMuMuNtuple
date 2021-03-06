#ifndef B0KSTMUMUTREECONTENT_H
#define B0KSTMUMUTREECONTENT_H

#include <vector>
#include <string>
#include "TTree.h"


class B0KstMuMuTreeContent
{
 public:
  
  B0KstMuMuTreeContent ();
  ~B0KstMuMuTreeContent ();

  void Init ();
  void ClearNTuple ();
  void ClearMonteCarlo ();
  void MakeTreeBranches (TTree* theTree);
  void SetBranchAddresses (TTree* theTree);
  void CopyCandidate (B0KstMuMuTreeContent* NTupleIn, int index);
  void CopyAllCandidates (B0KstMuMuTreeContent* NTupleIn);
  void FillWithNull (unsigned int upTo);


  // ########################################################
  // # Run Number, event number, #reco vtx and event weight #
  // ########################################################
  unsigned int              runN;
  unsigned int              eventN;
  unsigned int              recoVtxN;
  double                    evWeight;
  double                    evWeightE2;
  unsigned int              numEventsTried;
  unsigned int              numEventsPassed;


  // ###########
  // # Trigger #
  // ###########
  std::vector<std::string>  *TrigTable;
  std::vector<int>          *TrigPrescales;
  
  // ###########################
  // # Number of B0 candidates #
  // ###########################
  unsigned int              nB;
  
  // ############################
  // # Pileup information in MC #
  // ############################
  std::vector<double>       *bunchXingMC, *numInteractionsMC, *trueNumInteractionsMC;
  // Comment:
  // - PileupSummaryInfo::getTrueNumInteractions() gives the distribution of the mean number of interactions per crossing.
  // Since this is the mean value of the poisson distribution from which the number of interactions in- and out-of-time are
  // generated, no additional information should be required for reweighting if these values are matched in data and Monte Carlo.
  // - PileupSummaryInfo::getPU_NumInteractions() gives the expected mean number of interactions per crossing for each LumiSection.
  // Therefore the pileup histogram will contain the distribution of the number of interactions one would actually observe given
  // a poisson of that mean. So, this distribution is what one would see if one counted the number of events seen in a given beam
  // crossing (by looking at the number of vertices in data, for example. This would be appropriate for pileup reweighting based
  // on in-time-only distributions.

  // ################################
  // # Primary Vertex and Beam Spot #
  // ################################
  double                    priVtxCL, priVtxX, priVtxY, priVtxZ;
  double                    bsX, bsY;

  // ###########
  // # B0 Mass #
  // ###########
  std::vector<double>       *bMass, *bMassE, *bBarMass, *bBarMassE, *bPx, *bPy, *bPz;

  // ##########
  // # B0 Vtx #
  // ##########
  std::vector<double>       *bVtxCL, *bVtxX, *bVtxY, *bVtxZ;
  std::vector<double>       *bCosAlphaVtx, *bCosAlphaVtxE, *bCosAlphaBS, *bCosAlphaBSE;
  std::vector<double>       *bLVtx, *bLVtxE, *bLBS, *bLBSE;
  std::vector<double>       *bDCAVtx, *bDCAVtxE, *bDCABS, *bDCABSE;

  // ###########
  // # B0 ctau #
  // ###########
  std::vector<double>       *bctauPVBS, *bctauPVBSE;

  // ############
  // # K*0 Mass #
  // ############
  std::vector<double>       *kstMass, *kstMassE, *kstBarMass, *kstBarMassE, *kstPx, *kstPy, *kstPz;
  std::vector<double>       *kstPxxE, *kstPyyE, *kstPzzE, *kstPxyE, *kstPxzE, *kstPyzE;

  // ###########
  // # K*0 Vtx #
  // ###########
  std::vector<double>       *kstVtxCL, *kstVtxX, *kstVtxY, *kstVtxZ;

  // ################
  // # mu+ mu- Mass #
  // ################
  std::vector<double>       *mumuMass, *mumuMassE, *mumuPx, *mumuPy, *mumuPz;

  // ###############
  // # mu+ mu- Vtx #
  // ###############
  std::vector<double>       *mumuVtxCL, *mumuVtxX, *mumuVtxY, *mumuVtxZ;
  std::vector<double>       *mumuCosAlphaBS, *mumuCosAlphaBSE;
  std::vector<double>       *mumuLBS, *mumuLBSE;
  std::vector<double>       *mumuDCA;

  // #######
  // # mu- #
  // #######
//   std::vector<int>         *mumHighPurity;
  std::vector<bool>         *mumHighPurity;
  std::vector<double>       *mumCL, *mumNormChi2, *mumPx, *mumPy, *mumPz;
  std::vector<double>       *mumDCAVtx, *mumDCAVtxE, *mumDCABS, *mumDCABSE, *mumKinkChi2, *mumFracHits;
  std::vector<double>       *mumdxyVtx, *mumdzVtx, *mumMinIP2D, *mumMinIP2DE, *mumMinIP, *mumMinIPE;
  std::vector<double>       *mumDeltaRwithMC;
  std::vector<std::string>  *mumCat;
  std::vector<int>          *mumNPixHits, *mumNPixLayers, *mumNTrkHits, *mumNTrkLayers, *mumNMuonHits, *mumNMatchStation;
  std::vector<std::string>  *mumTrig;
  std::vector<std::vector<float>> *mumIso, *mumIsoPt, *mumIsoMom, *mumIsodR;

  // #######
  // # mu+ #
  // #######
//   std::vector<int>         *mupHighPurity;
  std::vector<bool>         *mupHighPurity;
  std::vector<double>       *mupCL, *mupNormChi2, *mupPx, *mupPy, *mupPz;
  std::vector<double>       *mupDCAVtx, *mupDCAVtxE, *mupDCABS, *mupDCABSE, *mupKinkChi2, *mupFracHits;
  std::vector<double>       *mupdxyVtx, *mupdzVtx, *mupMinIP2D, *mupMinIP2DE, *mupMinIP, *mupMinIPE;
  std::vector<double>       *mupDeltaRwithMC;
  std::vector<std::string>  *mupCat;
  std::vector<int>          *mupNPixHits, *mupNPixLayers, *mupNTrkHits, *mupNTrkLayers, *mupNMuonHits, *mupNMatchStation;
  std::vector<std::string>  *mupTrig;
  std::vector<std::vector<float>> *mupIso, *mupIsoPt, *mupIsoMom, *mupIsodR;

  // ##############
  // # K*0 track- #
  // ##############
//   std::vector<int>         *kstTrkmHighPurity;
  std::vector<bool>         *kstTrkmHighPurity;
  std::vector<double>       *kstTrkmCL, *kstTrkmNormChi2, *kstTrkmPx, *kstTrkmPy, *kstTrkmPz;
  std::vector<double>       *kstTrkmPxxE, *kstTrkmPyyE, *kstTrkmPzzE, *kstTrkmPxyE, *kstTrkmPxzE, *kstTrkmPyzE;
  std::vector<double>       *kstTrkmDCAVtx, *kstTrkmDCAVtxE, *kstTrkmDCABS, *kstTrkmDCABSE, *kstTrkmFracHits;
  std::vector<double>       *kstTrkmdxyVtx, *kstTrkmdzVtx, *kstTrkmMinIP2D, *kstTrkmMinIP2DE, *kstTrkmMinIP, *kstTrkmMinIPE;
  std::vector<double>       *kstTrkmDeltaRwithMC;
  std::vector<int>          *kstTrkmNPixHits, *kstTrkmNPixLayers, *kstTrkmNTrkHits, *kstTrkmNTrkLayers;
  std::vector<std::string>  *kstTrkmMuMatch;
  std::vector<std::string>  *kstTrkmTrig;
  std::vector<std::vector<float>> *kstTrkmIso, *kstTrkmIsoPt, *kstTrkmIsoMom, *kstTrkmIsodR;

  // ##############
  // # K*0 track+ #
  // ##############
//   std::vector<int>         *kstTrkpHighPurity;
  std::vector<bool>         *kstTrkpHighPurity;
  std::vector<double>       *kstTrkpCL, *kstTrkpNormChi2, *kstTrkpPx, *kstTrkpPy, *kstTrkpPz;
  std::vector<double>       *kstTrkpPxxE, *kstTrkpPyyE, *kstTrkpPzzE, *kstTrkpPxyE, *kstTrkpPxzE, *kstTrkpPyzE;
  std::vector<double>       *kstTrkpDCAVtx, *kstTrkpDCAVtxE, *kstTrkpDCABS, *kstTrkpDCABSE, *kstTrkpFracHits;
  std::vector<double>       *kstTrkpdxyVtx, *kstTrkpdzVtx, *kstTrkpMinIP2D, *kstTrkpMinIP2DE, *kstTrkpMinIP, *kstTrkpMinIPE;
  std::vector<double>       *kstTrkpDeltaRwithMC;
  std::vector<int>          *kstTrkpNPixHits, *kstTrkpNPixLayers, *kstTrkpNTrkHits, *kstTrkpNTrkLayers;
  std::vector<std::string>  *kstTrkpMuMatch;
  std::vector<std::string>  *kstTrkpTrig;
  std::vector<std::vector<float>> *kstTrkpIso, *kstTrkpIsoPt, *kstTrkpIsoMom, *kstTrkpIsodR;

  // #########################
  // # Generated Observables #
  // #########################
  int                       genSignal; // ###############################################
                                       // # 1 = B0 --> K*0(K+pi-) mu+mu-                #
                                       // # 2 = B0bar --> K*0bar(K-pi+) mu+mu-          #
                                       // # 3 = B0 --> K*0(K+pi-) J/psi(mu+mu-)         #
                                       // # 4 = B0bar --> K*0bar(K-pi+) J/psi(mu+mu-)   #
                                       // # 5 = B0 --> K*0(K-pi+) psi(2S)(mu+mu-)       #
                                       // # 6 = B0bar --> K*0bar(K-pi+) psi(2S)(mu+mu-) #
                                       // ###############################################
  int                       genMuMuBG, genMuMuBGnTrksm, genMuMuBGnTrksp;
  bool                      genPsiPrompt;
  bool                      genSignHasFSR, genSignKstHasFSR, genSignPsiHasFSR;

  // ############################
  // # Generated Primary Vertex #
  // ############################
  double                    genPriVtxX, genPriVtxY, genPriVtxZ;

  // #####################
  // # Generated B0 Mass #
  // #####################
  double                    genB0Mass, genB0Px, genB0Py, genB0Pz;

  // ####################
  // # Generated B0 Vtx #
  // ####################
  double                    genB0VtxX, genB0VtxY, genB0VtxZ;

  // ######################
  // # Generated K*0 Mass #
  // ######################
  double                    genKstMass, genKstPx, genKstPy, genKstPz;

  // #####################
  // # Generated K*0 Vtx #
  // #####################
  double                    genKstVtxX, genKstVtxY, genKstVtxZ;

  // ###########################################
  // # Generated J/psi or psi(2S) Mass and Vtx #
  // ###########################################
  double                    genPsiMass, genPsiVtxX, genPsiVtxY, genPsiVtxZ;

  // #################
  // # Generated mu- #
  // #################
  int                       genMumMother;
  double                    genMumPx, genMumPy, genMumPz;

  // #################
  // # Generated mu+ #
  // #################
  int                       genMupMother;
  double                    genMupPx, genMupPy, genMupPz;

  // ########################
  // # Generated K*0 track- #
  // ########################
  int                       genKstTrkmMother, genKstTrkmID;
  double                    genKstTrkmPx, genKstTrkmPy, genKstTrkmPz;

  // ########################
  // # Generated K*0 track+ #
  // ########################
  int                       genKstTrkpMother, genKstTrkpID;
  double                    genKstTrkpPx, genKstTrkpPy, genKstTrkpPz;

  // ################################################
  // # Matching Between Reconstructed and Generated #
  // ################################################
//   std::vector<int>         *truthMatchSignal, *truthMatchMum, *truthMatchMup, *truthMatchTrkm, *truthMatchTrkp;
  std::vector<bool>         *truthMatchSignal, *truthMatchMum, *truthMatchMup, *truthMatchTrkm, *truthMatchTrkp;

  
 private:

  void ClearScalars ();
  void ClearScalarsMonteCarlo ();
  void ClearVectors ();
  void ClearVectorsMonteCarlo ();
  void CopyScalars (B0KstMuMuTreeContent* NTupleIn);
  void CopyVectors (B0KstMuMuTreeContent* NTupleIn, int index);
};

#endif
