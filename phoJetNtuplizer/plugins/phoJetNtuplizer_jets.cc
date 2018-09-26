#include "FWCore/MessageLogger/interface/MessageLogger.h"
#include "phoJetAnalysis/phoJetNtuplizer/interface/phoJetNtuplizer.h"
#include "JetMETCorrections/Objects/interface/JetCorrector.h"
#include "CondFormats/JetMETObjects/interface/JetCorrectorParameters.h"
#include "CondFormats/JetMETObjects/interface/JetCorrectionUncertainty.h"
#include "JetMETCorrections/Objects/interface/JetCorrectionsRecord.h"
#include "FWCore/Framework/interface/ESHandle.h"
#include "FWCore/Framework/interface/EventSetup.h"
#include "DataFormats/Math/interface/LorentzVector.h"
#include "CondFormats/JetMETObjects/interface/FactorizedJetCorrector.h"
#include "FWCore/Utilities/interface/RandomNumberGenerator.h"
#include "CLHEP/Random/RandomEngine.h"
#include "CLHEP/Random/RandGauss.h"
#include <iostream>
#include <vector>
#include "phoJetAnalysis/JetWidthCalculator/interface/JetWidthCalculator.hh"

Int_t             nJet_;

vector<double>    jetPt_;
vector<double>    jetPx_;
vector<double>    jetPy_;
vector<double>    jetPz_;
vector<double>    jetEn_;
vector<double>    jetEta_;
vector<double>    jetPhi_;
vector<double>    jetRawPt_;
vector<double>    jetRawEn_;
vector<double>    jetMt_;
vector<double>    jetArea_;
vector<double>    jetMass_;
vector<double>    jetMaxDistance_;
vector<double>    jetPhiPhiMoment_;
vector<double>    jetConstituentEtaPhiSpread_;
vector<double>    jetConstituentPtDistribution_;
vector<double>    jetPileup_;
vector<UShort_t>  jetID_; 
vector<double>    jetPUID_;
vector<Int_t>     jetPUFullID_;
vector<Int_t>     jetPartonID_;
vector<Int_t>     jetHadFlvr_;
vector<double>    jetJECUnc_;

vector<double>    jetCEF_;
vector<double>    jetNEF_;
vector<double>    jetCHF_;
vector<double>    jetNHF_;
vector<Int_t>     jetPhotonEnF_;
vector<Int_t>     jetElectronEnF_;
vector<double>    jetMuonEnF_;
vector<double>    jetChargedMuonEnF_;
vector<double>    jetHFHAE_;
vector<double>    jetHFEME_;
vector<Int_t>     jetNConst_;
vector<Int_t>     jetNConstituents_;
vector<Int_t>     jetNCharged_; 
vector<Int_t>     jetNNeutral_;
vector<Int_t>     jetNChargedHad_;
vector<Int_t>     jetNNeutralHad_;
vector<Int_t>     jetNPhoton_;
vector<Int_t>     jetNElectron_;
vector<Int_t>     jetNMuon_;

vector<double>    jetCSV2BJetTags_;
vector<double>    jetDeepCSVTags_b_;
vector<double>    jetDeepCSVTags_bb_;
vector<double>    jetDeepCSVTags_c_;
vector<double>    jetDeepCSVTags_udsg_;

vector<double>    jetLeadTrackPt_;
vector<double>    jetLeadTrackEta_;
vector<double>    jetLeadTrackPhi_;
vector<Int_t>     jetLepTrackPID_;
vector<double>    jetLepTrackPt_;
vector<double>    jetLepTrackEta_;
vector<double>    jetLepTrackPhi_;

vector<double>    jetetaWidth_;
vector<double>    jetphiWidth_;
vector<double>    jetnPhotons_;
vector<double>    jetnCHPions_;
vector<double>    jetnMisc_;
vector<vector<Int_t>>  jetMiscPdgId_;
vector<vector<double>> jetConstPt_;
vector<vector<double>> jetConstEt_;
vector<vector<double>> jetConstEta_;
vector<vector<double>> jetConstPhi_;
vector<vector<Int_t>>  jetConstPdgId_;

vector<double>    jetGenJetEn_;
vector<double>    jetGenJetPt_;
vector<double>    jetGenJetEta_;
vector<double>    jetGenJetPhi_;
vector<Int_t>     jetGenPartonID_;
vector<double>    jetGenEn_;
vector<double>    jetGenPt_;
vector<double>    jetGenEta_;
vector<double>    jetGenPhi_;
vector<Int_t>     jetGenPartonMomID_;

void phoJetNtuplizer::branchJets(TTree* tree){

  tree->Branch("nJet",                         &nJet_);

  tree->Branch("jetPt",                        &jetPt_);
  tree->Branch("jetPx",                        &jetPx_);
  tree->Branch("jetPy",                        &jetPy_);
  tree->Branch("jetPz",                        &jetPz_);
  tree->Branch("jetEn",                        &jetEn_);
  tree->Branch("jetEta",                       &jetEta_);
  tree->Branch("jetPhi",                       &jetPhi_);
  tree->Branch("jetRawPt",                     &jetRawPt_);
  tree->Branch("jetRawEn",                     &jetRawEn_);
  tree->Branch("jetMt",                        &jetMt_);
  tree->Branch("jetArea",                      &jetArea_);
  tree->Branch("jetMass",                      &jetMass_);
  tree->Branch("jetMaxDistance",               &jetMaxDistance_);
  tree->Branch("jetPhiPhiMoment",              &jetPhiPhiMoment_);
  tree->Branch("jetConstituentEtaPhiSpread",   &jetConstituentEtaPhiSpread_);
  tree->Branch("jetConstituentPtDistribution", &jetConstituentPtDistribution_);
  tree->Branch("jetPileup",                    &jetPileup_);
  tree->Branch("jetID",                        &jetID_); 
  tree->Branch("jetPUID",                      &jetPUID_);
  tree->Branch("jetPUFullID",                  &jetPUFullID_);
  tree->Branch("jetPartonID",                  &jetPartonID_);
  tree->Branch("jetHadFlvr",                   &jetHadFlvr_);
  tree->Branch("jetJECUnc",                    &jetJECUnc_);

  tree->Branch("jetCEF",                       &jetCEF_);
  tree->Branch("jetNEF",                       &jetNEF_);
  tree->Branch("jetCHF",                       &jetCHF_);
  tree->Branch("jetNHF",                       &jetNHF_);
  tree->Branch("jetPhotonEnF",                 &jetPhotonEnF_);
  tree->Branch("jetElectronEnF",               &jetElectronEnF_);
  tree->Branch("jetMuonEnF",                   &jetMuonEnF_);
  tree->Branch("jetChargedMuonEnF",            &jetChargedMuonEnF_);
  tree->Branch("jetHFHAE",                     &jetHFHAE_);
  tree->Branch("jetHFEME",                     &jetHFEME_);
  tree->Branch("jetNConst",                    &jetNConst_);
  tree->Branch("jetNConstituents",             &jetNConstituents_);
  tree->Branch("jetNCharged",                  &jetNCharged_); 
  tree->Branch("jetNNeutral",                  &jetNNeutral_);
  tree->Branch("jetNChargedHad",               &jetNChargedHad_);
  tree->Branch("jetNNeutralHad",               &jetNNeutralHad_);
  tree->Branch("jetNPhoton",                   &jetNPhoton_);
  tree->Branch("jetNElectron",                 &jetNElectron_);
  tree->Branch("jetNMuon",                     &jetNMuon_);

  tree->Branch("jetCSV2BJetTags",              &jetCSV2BJetTags_);
  tree->Branch("jetDeepCSVTags_b",             &jetDeepCSVTags_b_);
  tree->Branch("jetDeepCSVTags_bb",            &jetDeepCSVTags_bb_);
  tree->Branch("jetDeepCSVTags_c",             &jetDeepCSVTags_c_);
  tree->Branch("jetDeepCSVTags_udsg",          &jetDeepCSVTags_udsg_);

  tree->Branch("jetLeadTrackPt",               &jetLeadTrackPt_);
  tree->Branch("jetLeadTrackEta",              &jetLeadTrackEta_);
  tree->Branch("jetLeadTrackPhi",              &jetLeadTrackPhi_);
  tree->Branch("jetLepTrackPID",               &jetLepTrackPID_);
  tree->Branch("jetLepTrackPt",                &jetLepTrackPt_);
  tree->Branch("jetLepTrackEta",               &jetLepTrackEta_);
  tree->Branch("jetLepTrackPhi",               &jetLepTrackPhi_);

  if(runJetWidthCalculator_){
    tree->Branch("jetetaWidth",                  &jetetaWidth_);
    tree->Branch("jetphiWidth",                  &jetphiWidth_);
    tree->Branch("jetnPhotons",                  &jetnPhotons_);
    tree->Branch("jetnCHPions",                  &jetnCHPions_);
    tree->Branch("jetnMisc",                     &jetnMisc_);
    tree->Branch("jetMiscPdgId",                 &jetMiscPdgId_);
    tree->Branch("jetConstPt",                   &jetConstPt_);
    tree->Branch("jetConstEt",                   &jetConstEt_);
    tree->Branch("jetConstEta",                  &jetConstEta_);
    tree->Branch("jetConstPhi",                  &jetConstPhi_);
    tree->Branch("jetConstPdgId",                &jetConstPdgId_);
  }

  if(runGenInfo_){
    tree->Branch("jetGenJetEn",                  &jetGenJetEn_);
    tree->Branch("jetGenJetPt",                  &jetGenJetPt_);
    tree->Branch("jetGenJetEta",                 &jetGenJetEta_);
    tree->Branch("jetGenJetPhi",                 &jetGenJetPhi_);
    tree->Branch("jetGenPartonID",               &jetGenPartonID_);
    tree->Branch("jetGenEn",                     &jetGenEn_);
    tree->Branch("jetGenPt",                     &jetGenPt_);
    tree->Branch("jetGenEta",                    &jetGenEta_);
    tree->Branch("jetGenPhi",                    &jetGenPhi_);
    tree->Branch("jetGenPartonMomID",            &jetGenPartonMomID_);
  }

}
void phoJetNtuplizer::fillJets(const edm::Event& iEvent, const edm::EventSetup& iSetup){

  initJets();

  edm::Handle<edm::View<pat::Jet> > jetHandle;
  iEvent.getByToken(jetsAK4Token_, jetHandle);

  if (!jetHandle.isValid()) {
    edm::LogWarning("phoJetNtuplizer") << "no pat::Jets (AK4) in event";
    return;
  }

  edm::Handle<vector<reco::GenParticle> > genParticlesHandle;
  if(runGenInfo_)iEvent.getByToken(genParticlesToken_, genParticlesHandle);

  edm::Handle<reco::VertexCollection> vtxHandle;
  iEvent.getByToken(vtxToken_, vtxHandle);
  if (!vtxHandle.isValid()) 
    edm::LogWarning("phoJetNtuplizer") << "Primary vertices info not unavailable";

  // Accessing the JEC uncertainties AK4 
  edm::ESHandle<JetCorrectorParametersCollection> JetCorParColl;
  iSetup.get<JetCorrectionsRecord>().get("AK4PFchs",JetCorParColl); 
  JetCorrectorParameters const & JetCorPar = (*JetCorParColl)["Uncertainty"];
  JetCorrectionUncertainty *jecUnc=0;
  jecUnc = new JetCorrectionUncertainty(JetCorPar);

  for (edm::View<pat::Jet>::const_iterator iJet = jetHandle->begin(); iJet != jetHandle->end(); ++iJet) {

    jetPt_                        .push_back(iJet->pt());
    jetPx_                        .push_back(iJet->px());
    jetPy_                        .push_back(iJet->py());
    jetPz_                        .push_back(iJet->pz());
    jetEn_                        .push_back(iJet->energy());
    jetEta_                       .push_back(iJet->eta());
    jetPhi_                       .push_back(iJet->phi());
    jetRawPt_                     .push_back((*iJet).correctedJet("Uncorrected").pt());
    jetRawEn_                     .push_back((*iJet).correctedJet("Uncorrected").energy());
    jetMt_                        .push_back(iJet->mt());
    jetArea_                      .push_back(iJet->jetArea());
    jetMass_                      .push_back(iJet->mass());
    jetMaxDistance_               .push_back(iJet->maxDistance());
    jetPhiPhiMoment_              .push_back(iJet->phiphiMoment());
    jetConstituentEtaPhiSpread_   .push_back(iJet->constituentEtaPhiSpread());
    jetConstituentPtDistribution_ .push_back(iJet->constituentPtDistribution());
    jetPileup_                    .push_back(iJet->pileup());


    //PF JetID
    double NHF      = iJet->neutralHadronEnergyFraction();
    double NEMF     = iJet->neutralEmEnergyFraction();
    double NumConst = iJet->chargedMultiplicity()+iJet->neutralMultiplicity();
    double CHF      = iJet->chargedHadronEnergyFraction();
    double CHM      = iJet->chargedMultiplicity();
    double CEMF     = iJet->chargedEmEnergyFraction();
    double NNP      = iJet->neutralMultiplicity();
    double MUF      = iJet->muonEnergyFraction();

    bool tightJetID        = false;
    bool tightLepVetoJetID = false;
    if (fabs(iJet->eta()) <= 2.7) {
      tightJetID = (NHF<0.90 && NEMF<0.90 && NumConst>1) && ((fabs(iJet->eta())<=2.4 && CHF>0 && CHM>0) || fabs(iJet->eta())>2.4);
      tightLepVetoJetID = (NHF<0.90 && NEMF<0.90 && NumConst>1 && MUF<0.8) && ((fabs(iJet->eta())<=2.4 && CHF>0 && CHM>0 && CEMF<0.8) || fabs(iJet->eta())>2.4);
    } else if (fabs(iJet->eta()) <= 3.0) {
      tightJetID = (NEMF>0.02 && NEMF<0.99 && NNP>2);
    } else {
      tightJetID = (NEMF<0.90 && NHF>0.02 && NNP>10);
    }

    UShort_t tmpjetIDbit = 0;
    if (tightJetID)        setbit(tmpjetIDbit, 0);
    if (tightLepVetoJetID) setbit(tmpjetIDbit, 1);

    jetID_                        .push_back(tmpjetIDbit);    
    // PUJet ID from slimmedJets
    jetPUID_                      .push_back(iJet->userFloat("pileupJetId:fullDiscriminant"));
    jetPUFullID_                  .push_back(iJet->userInt("pileupJetId:fullId"));
    //parton id
    jetPartonID_                  .push_back(iJet->partonFlavour());
    jetHadFlvr_                   .push_back(iJet->hadronFlavour());

    if (fabs(iJet->eta()) < 5.2) {
      jecUnc->setJetEta(iJet->eta());
      jecUnc->setJetPt(iJet->pt()); // here you must use the CORRECTED jet pt
      jetJECUnc_.push_back(jecUnc->getUncertainty(true));
    } else {
      jetJECUnc_.push_back(-1.);
    }   

    jetCEF_                       .push_back(iJet->chargedEmEnergyFraction());
    jetNEF_                       .push_back(iJet->neutralEmEnergyFraction());
    jetCHF_                       .push_back(iJet->chargedHadronEnergyFraction());
    jetNHF_                       .push_back(iJet->neutralHadronEnergyFraction());
    jetPhotonEnF_                 .push_back(iJet->photonEnergyFraction());
    jetElectronEnF_               .push_back(iJet->electronEnergyFraction());
    jetMuonEnF_                   .push_back(iJet->muonEnergyFraction());
    jetChargedMuonEnF_            .push_back(iJet->chargedMuEnergyFraction());
    jetHFHAE_                     .push_back( iJet->HFHadronEnergy());
    jetHFEME_                     .push_back( iJet->HFEMEnergy());
    jetNConst_                    .push_back(iJet->nConstituents());
    jetNConstituents_             .push_back(iJet->numberOfDaughters());
    //jetNConst60_                  .push_back(iJet->nCarrying(0.60)); //return # of consitutents carrying 60% of energy
    jetNCharged_                  .push_back(iJet->chargedMultiplicity());
    jetNNeutral_                  .push_back(iJet->neutralMultiplicity());
    jetNChargedHad_               .push_back(iJet->chargedHadronMultiplicity());
    jetNNeutralHad_               .push_back(iJet->neutralHadronMultiplicity());
    jetNPhoton_                   .push_back(iJet->photonMultiplicity());
    jetNElectron_                 .push_back(iJet->electronMultiplicity());
    jetNMuon_                     .push_back(iJet->muonMultiplicity());

    //b/c-tagging
    jetCSV2BJetTags_             .push_back(iJet->bDiscriminator("pfCombinedInclusiveSecondaryVertexV2BJetTags"));
    jetDeepCSVTags_b_            .push_back(iJet->bDiscriminator("pfDeepCSVJetTags:probb"));
    jetDeepCSVTags_bb_           .push_back(iJet->bDiscriminator("pfDeepCSVJetTags:probbb"));
    jetDeepCSVTags_c_            .push_back(iJet->bDiscriminator("pfDeepCSVJetTags:probc"));
    jetDeepCSVTags_udsg_         .push_back(iJet->bDiscriminator("pfDeepCSVJetTags:probudsg"));

    //Searching for leading track and lepton
    double leadTrkPt  = -99;
    double leadTrkEta = -99;
    double leadTrkPhi = -99;
    Int_t   lepTrkPID  = -99;
    double lepTrkPt   = -99;
    double lepTrkEta  = -99;
    double lepTrkPhi  = -99;

    for (unsigned id = 0; id < iJet->getJetConstituents().size(); id++) {

      const edm::Ptr<reco::Candidate> daughter = iJet->getJetConstituents().at(id);

      if (daughter.isNonnull() && daughter.isAvailable()) {
	if (daughter->charge() != 0 && daughter->pt() > leadTrkPt) {
	  leadTrkPt  = daughter->pt();
	  leadTrkEta = daughter->eta();
	  leadTrkPhi = daughter->phi();
	}

	if (fabs(daughter->pdgId()) == 11 || fabs(daughter->pdgId()) == 13) {
	  if (daughter->pt() > lepTrkPt) {
	    lepTrkPID = daughter->pdgId();
	    lepTrkPt  = daughter->pt();
	    lepTrkEta = daughter->eta();
	    lepTrkPhi = daughter->phi();
	  }
	}
      }
    }

    jetLeadTrackPt_ .push_back(leadTrkPt);
    jetLeadTrackEta_.push_back(leadTrkEta);
    jetLeadTrackPhi_.push_back(leadTrkPhi);
    jetLepTrackPID_ .push_back(lepTrkPID);
    jetLepTrackPt_  .push_back(lepTrkPt);
    jetLepTrackEta_ .push_back(lepTrkEta);
    jetLepTrackPhi_ .push_back(lepTrkPhi);    
    //jetVtxPt_       .push_back(sqrt(pow(iJet->userFloat("vtxPx"),2)+pow(iJet->userFloat("vtxPy"),2)));
    //jetVtxMass_     .push_back(iJet->userFloat("vtxMass"));
    //jetVtxNtrks_    .push_back(iJet->userFloat("vtxNtracks"));
    //jetVtx3DVal_    .push_back(iJet->userFloat("vtx3DVal"));
    //jetVtx3DSig_    .push_back(iJet->userFloat("vtx3DSig"));

    //JetWidthCalculator
    if(runJetWidthCalculator_){
      const pat::Jet &jet = (*jetHandle)[nJet_];
      JetWidthCalculator jwc(jet);
      jetetaWidth_       .push_back(jwc.getEtaWidth());
      jetphiWidth_       .push_back(jwc.getPhiWidth());
      jetnPhotons_       .push_back(jwc.getnPhotons());
      jetnCHPions_       .push_back(jwc.getnCHPions());
      jetnMisc_          .push_back(jwc.getnMiscParticles());

      jetConstPt_        .push_back(jwc.getConstPt());
      jetConstEt_        .push_back(jwc.getConstEt());
      jetConstEta_       .push_back(jwc.getConstEta());
      jetConstPhi_       .push_back(jwc.getConstPhi());
      jetConstPdgId_     .push_back(jwc.getConstPdgId());
    }


    // gen jet and parton
    if (runGenInfo_ && genParticlesHandle.isValid()) {
      Int_t  jetGenPartonID    = -99;
      Int_t  jetGenPartonMomID = -99;
      double jetGenEn          = -999.;
      double jetGenPt          = -999.;
      double jetGenEta         = -999.;
      double jetGenPhi         = -999.;      
      if ((*iJet).genParton()) {
	jetGenPartonID = (*iJet).genParton()->pdgId();
	jetGenEn       = (*iJet).genParton()->energy();
	jetGenPt       = (*iJet).genParton()->pt();
	jetGenEta      = (*iJet).genParton()->eta();
	jetGenPhi      = (*iJet).genParton()->phi();
	if ((*iJet).genParton()->mother()) {
	  jetGenPartonMomID = (*iJet).genParton()->mother()->pdgId();
	}
      }

      jetGenPartonID_     .push_back(jetGenPartonID);
      jetGenPartonMomID_  .push_back(jetGenPartonMomID);
      jetGenEn_           .push_back(jetGenEn);
      jetGenPt_           .push_back(jetGenPt);
      jetGenEta_          .push_back(jetGenEta);
      jetGenPhi_          .push_back(jetGenPhi);

      double jetGenJetEn       = -999.;
      double jetGenJetPt       = -999.;
      double jetGenJetEta      = -999.;
      double jetGenJetPhi      = -999.;
      if ((*iJet).genJet()) {
	jetGenJetEn    = (*iJet).genJet()->energy();
	jetGenJetPt    = (*iJet).genJet()->pt();
	jetGenJetEta   = (*iJet).genJet()->eta();
	jetGenJetPhi   = (*iJet).genJet()->phi();
      }
      jetGenJetEn_        .push_back(jetGenJetEn);
      jetGenJetPt_        .push_back(jetGenJetPt);
      jetGenJetEta_       .push_back(jetGenJetEta);
      jetGenJetPhi_       .push_back(jetGenJetPhi);

    }// runGenInfo

    nJet_++;
  }
}

void phoJetNtuplizer::initJets(){

  nJet_                          = 0;

  jetPt_                        .clear();
  jetPx_                        .clear();
  jetPy_                        .clear();
  jetPz_                        .clear();
  jetEn_                        .clear();
  jetEta_                       .clear();
  jetPhi_                       .clear();
  jetRawPt_                     .clear();
  jetRawEn_                     .clear();
  jetMt_                        .clear();
  jetArea_                      .clear();
  jetMass_                      .clear();
  jetMaxDistance_               .clear();
  jetPhiPhiMoment_              .clear();
  jetConstituentEtaPhiSpread_   .clear();
  jetConstituentPtDistribution_ .clear();
  jetPileup_                    .clear();
  jetID_                        .clear(); 
  jetPUID_                      .clear();
  jetPUFullID_                  .clear();
  jetPartonID_                  .clear();
  jetHadFlvr_                   .clear();
  jetJECUnc_                    .clear();

  jetCEF_                       .clear();
  jetNEF_                       .clear();
  jetCHF_                       .clear();
  jetNHF_                       .clear();
  jetPhotonEnF_                 .clear();
  jetElectronEnF_               .clear();
  jetMuonEnF_                   .clear();
  jetChargedMuonEnF_            .clear();
  jetHFHAE_                     .clear();
  jetHFEME_                     .clear();
  jetNConst_                    .clear();
  jetNConstituents_             .clear();
  jetNCharged_                  .clear(); 
  jetNNeutral_                  .clear();
  jetNChargedHad_               .clear();
  jetNNeutralHad_               .clear();
  jetNPhoton_                   .clear();
  jetNElectron_                 .clear();
  jetNMuon_                     .clear();

  jetCSV2BJetTags_              .clear();
  jetDeepCSVTags_b_             .clear();
  jetDeepCSVTags_bb_            .clear();
  jetDeepCSVTags_c_             .clear();
  jetDeepCSVTags_udsg_          .clear();

  jetLeadTrackPt_               .clear();
  jetLeadTrackEta_              .clear();
  jetLeadTrackPhi_              .clear();
  jetLepTrackPID_               .clear();
  jetLepTrackPt_                .clear();
  jetLepTrackEta_               .clear();
  jetLepTrackPhi_               .clear();

  jetetaWidth_                  .clear();
  jetphiWidth_                  .clear();
  jetnPhotons_                  .clear();
  jetnCHPions_                  .clear();
  jetnMisc_                     .clear();
  jetMiscPdgId_                 .clear();
  jetConstPt_                   .clear();
  jetConstEt_                   .clear();
  jetConstEta_                  .clear();
  jetConstPhi_                  .clear();
  jetConstPdgId_                .clear();

  jetGenJetEn_                  .clear();
  jetGenJetPt_                  .clear();
  jetGenJetEta_                 .clear();
  jetGenJetPhi_                 .clear();
  jetGenPartonID_               .clear();
  jetGenEn_                     .clear();
  jetGenPt_                     .clear();
  jetGenEta_                    .clear();
  jetGenPhi_                    .clear();
  jetGenPartonMomID_            .clear();

}