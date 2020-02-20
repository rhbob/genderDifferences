#include "TTree.h"
#include "TStyle.h"
#include "TMath.h"
#include "TFile.h"
#include "TH1F.h"
#include "TH2F.h"
#include "TF1.h"
#include "TCut.h"
#include "TLegend.h"
#include "TCanvas.h"
#include "TProfile.h"
#include "TMath.h"
#include "TPaveText.h"
#include "TLeaf.h"
#include "TLine.h"
#include "TArrow.h"
#include "TRandom2.h"
#include "TRandom3.h"
#include "TRolke.h"
#include <iostream>
#include <vector>
#include <math.h>
#include <cmath>
#include <algorithm>
#include "TRandom3.h"
#include "TFrame.h"
//#include <boost/lexical_cast.hpp>
//#include <boost/timer.hpp>
//#include <boost/functional/hash.hpp>
#include <TChain.h>
#include <string>
#include <fstream>

#include <TLimit.h>
#include <TConfidenceLevel.h>
#include <TLimitDataSource.h>
#include "Riostream.h"
#include "TMath.h"
#include "TNtuple.h"
#include "TObject.h"
#include "TString.h"
#include "TGraph.h"

#include "TFile.h"
#include <cstdio>
#include "TAxis.h"


#include <iostream>
#include <iomanip>
#include "TSystem.h"
#include "TFile.h"
#include "TH1.h"
#include "TH2.h"
#include "TTree.h"
#include "TF1.h"
#include "TMath.h"
#include "TFitResult.h"
#include "TChain.h"
#include "TLegend.h"
#include "TCanvas.h"
#include "TLine.h"
#include "TLatex.h"
#include "TVector.h"
#include "TLorentzVector.h"

#include "TGraphErrors.h"
#include "TFitResultPtr.h"
#include "TBox.h"
#include "TAxis.h"
using namespace std;

Double_t getMedian(TH1F* histo,Double_t x, Double_t q){
  histo->ComputeIntegral();
  histo->GetQuantiles(1,&x,&q);
  return x;
}


void annotated_v5_LIWC_analysisMedianForPaper()

{

  std::ofstream analysisOut;
  analysisOut.open("analysisLIWC.txt");
  //  std::ifstream inputFiles("TestOneSpreadsheet.txt");
  std::ifstream inputFiles("annotated_v5_ALL_drivesFixed.txt");
  std::ofstream hashOut("hashOut.txt");
  std::vector<std::string> letterFileList;
  std::string letterLine;

  std::ofstream candIdMalePhysicsOut("candIdMalePhysics.txt");
  std::ofstream candIdFemalePhysicsOut("candIdFemalePhysics.txt");


  std::ofstream candIdMaleSocSciOut("candIdMaleSocSci.txt");
  std::ofstream candIdFemaleSocSciOut("candIdFemaleSocSci.txt");

  while(std::getline(inputFiles,letterLine))
    {
      letterFileList.push_back(letterLine);
      //     std::cout << physicscMrMLine << std::endl;
    }

  analysisOut << " past initial while loop" << std::endl;
  Int_t letterLength = letterFileList.size();
  analysisOut << "length of letter list = " << letterLength << std::endl;
 
  
  /*********analyze**************/
  Int_t cat;
  Bool_t useBoth;
  useBoth = false;
  
  Int_t wc; Int_t disp;

  string rowHash;
  string rowNo,bobHash;
  Float_t Analytic,Clout,Authentic,Tone,WPS, Dic, function, pronoun, ppron, i, we, you , shehe, they, ipron, article, prep, auxverb, adverb, conj, negate, verb, adj, compare, interrog, number, quant,
    affect, posemo, negemo, anx, anger, sad ,
    social , family, friends, female, male, cogproc, insight, cause, discrep, tentat, certain, differ, percept, see, hear, feel, bio, body, health, sexual, ingest, drives, affiliation,
    achiev,power,familyRelated,reward,risk,focuspast,focuspresent,focusfuture ,
    relativ,motion,space,time,work,leisure,home,money,relig,death,informal,swear,netspeak,assent,nonflu,filler,AllPunc,Period,Comma,Colon,SemiC,QMark,Exclam,Dash,Quote,
    Apostro,Parent,OtherP;

  Int_t canGender, writerGender,both,candId,writerId,discipline;
  string candidateName;
  Int_t wcCut;

  Int_t Ref_is_advisor, Ref_nonresearch,both_gender_non_advisor_refs;

  Float_t standout, ability, grindstone , teaching , research , agentic, communal, internal1 , internal2, internal3, internal4 , internal5, internal6;
  Int_t nlines = 0;
    
  TFile* f = new TFile("lexicalAnalysisLIWC.root", "RECREATE");

  Float_t nt[93];
  TNtuple* physics = new TNtuple("physics","Physics Ntuple",
				 "cat:WC:Analytic:Clout:Authentic:Tone:WPS:Dic:function:pronoun:ppron:i:we:you:shehe:they:ipron:article:prep:auxverb:adverb:conj:negate:verb:adj:compare:interrog:number:quant:affect:posemo:negemo:anx:anger:sad:social:family:friends:female:male:cogproc:insight:cause:discrep:tentat:certain:differ:percept:see:hear:feel:bio:body:health:sexual:ingest:drives:affiliation:achiev:power:familyRelated:reward:risk:focuspast:focuspresent:focusfuture:relativ:motion:space:time:work:leisure:home:money:relig:death:informal:swear:netspeak:assent:nonflu:filler:AllPunc:Period:Comma:Colon:SemiC:QMark:Exclam:Dash:Quote:Apostro:Parent:OtherP");

  TNtuple*socsci = new TNtuple("socsci","SocSci Ntuple",
			       "cat:WC:Analytic:Clout:Authentic:Tone:WPS:Dic:function:pronoun:ppron:i:we:you:shehe:they:ipron:article:prep:auxverb:adverb:conj:negate:verb:adj:compare:interrog:number:quant:affect:posemo:negemo:anx:anger:sad:social:family:friends:female:male:cogproc:insight:cause:discrep:tentat:certain:differ:percept:see:hear:feel:bio:body:health:sexual:ingest:drives:affiliation:achiev:power:familyRelated:reward:risk:focuspast:focuspresent:focusfuture:relativ:motion:space:time:work:leisure:home:money:relig:death:informal:swear:netspeak:assent:nonflu:filler:AllPunc:Period:Comma:Colon:SemiC:QMark:Exclam:Dash:Quote:Apostro:Parent:OtherP");


  TH1F* wordsPhysicscMrM = new TH1F("wordsPhysicscMrM", " number of words in Physics letter, male candidate/male writer",100,0.,5000.);
  TH1F* wordsPhysicscFrM = new TH1F("wordsPhysicscFrM", " number of words in Physics letter, female candidate/male writer",100,0.,5000.);
  TH1F* wordsPhysicscFrF = new TH1F("wordsPhysicscFrF", " number of words in Physics letter, female candidate/female writer",100,0.,5000.);
  TH1F* wordsPhysicscMrF = new TH1F("wordsPhysicscMrF", " number of words in Physics letter, male candidate/female writer",100,0.,5000.);

  TH1F* wordsSocScicMrM = new TH1F("wordsSocScicMrM", " number of words in SocSci letter, male candidate/male writer",100,0.,5000.);
  TH1F* wordsSocScicFrM = new TH1F("wordsSocScicFrM", " number of words in SocSci letter, female candidate/male writer",100,0.,5000.);
  TH1F* wordsSocScicFrF = new TH1F("wordsSocScicFrF", " number of words in SocSci letter, female candidate/female writer",100,0.,5000.);
  TH1F* wordsSocScicMrF = new TH1F("wordsSocScicMrF", " number of words in SocSci letter, male candidate/female writer",100,0.,5000.);

 
  TH1F* drivescMrMphysics = new TH1F("drivesphysicscMrM","LIWC Drive words in Wilson Letters, cMrM (cat 80)", 20,0.,50.);
  TH1F* drivescMrFphysics = new TH1F("drivesphysicscMrF","LIWC Drive words in Wilson Letters, cMrM (cat 80)", 20,0.,50.);
  TH1F* drivescFrFphysics = new TH1F("drivesphysicscFrF","LIWC Drive words in Wilson Letters, cFrF (cat 80)", 20,0.,50.);
  TH1F* drivescFrMphysics = new TH1F("drivesphysicscFrM","LIWC Drive words in Wilson Letters, cFrM (cat 80)", 20,0.,50.);

  TH1F* drivescMrMsocsci = new TH1F("drivessocscicMrM","LIWC Drive words in Cornell Letters, cMrM (cat 80)", 20,0.,50.);
  TH1F* drivescMrFsocsci = new TH1F("drivessocscicMrF","LIWC Drive words in Cornell Letters, cMrF (cat 80)", 20,0.,50.);
  TH1F* drivescFrFsocsci = new TH1F("drivessocscicFrF","LIWC Drive words in Cornell Letters, cFrF (cat 80)", 20,0.,50.);
  TH1F* drivescFrMsocsci = new TH1F("drivessocscicFrM","LIWC Drive words in Cornell Letters, cFrM (cat 80)", 20,0.,50.);


  TH1F* workcMrMphysics = new TH1F("workphysicscMrM","LIWC Work words in Wilson Letters, cMrM", 20,0.,50.);
  TH1F* workcMrFphysics = new TH1F("workphysicscMrF","LIWC Work words in Wilson Letters, cMrM", 20,0.,50.);
  TH1F* workcFrFphysics = new TH1F("workphysicscFrF","LIWC Work words in Wilson Letters, cFrF", 20,0.,50.);
  TH1F* workcFrMphysics = new TH1F("workphysicscFrM","LIWC Work words in Wilson Letters, cFrM", 20,0.,50.);

  TH1F* workcMrMsocsci = new TH1F("worksocscicMrM","LIWC Work words in Cornell Letters, cMrM", 20,0.,50.);
  TH1F* workcMrFsocsci = new TH1F("worksocscicMrF","LIWC Work words in Cornell Letters, cMrF", 20,0.,50.);
  TH1F* workcFrFsocsci = new TH1F("worksocscicFrF","LIWC Work words in Cornell Letters, cFrF", 20,0.,50.);
  TH1F* workcFrMsocsci = new TH1F("worksocscicFrM","LIWC Work words in Cornell Letters, cFrM", 20,0.,50.);


  TH1F* affectcMrMphysics = new TH1F("affectphysicscMrM","LIWC Affect words in Wilson Letters, (cat 30)", 20,0.,20.);
  TH1F* affectcMrFphysics = new TH1F("affectphysicscMrF","LIWC Affect words in Wilson Letters, (cat 30)", 20,0.,20.);
  TH1F* affectcFrFphysics = new TH1F("affectphysicscFrF","LIWC Affect words in Wilson Letters, (cat 30)", 20,0.,20.);
  TH1F* affectcFrMphysics = new TH1F("affectphysicscFrM","LIWC Affect words in Wilson Letters, (cat 30)", 20,0.,20.);

  TH1F* affectcMrMsocsci = new TH1F("affectsocscicMrM","LIWC Affect words in Cornell Letters, (cat 30)", 20,0.,20.);
  TH1F* affectcMrFsocsci = new TH1F("affectsocscicMrF","LIWC Affect words in Cornell Letters, (cat 30)", 20,0.,20.);
  TH1F* affectcFrFsocsci = new TH1F("affectsocscicFrF","LIWC Affect words in Cornell Letters, (cat 30)", 20,0.,20.);
  TH1F* affectcFrMsocsci = new TH1F("affectsocscicFrM","LIWC Affect words in Cornell Letters, (cat 30)", 20,0.,20.);

  TH1F* socialcMrMphysics = new TH1F("socialphysicscMrM","LIWC Social words in Wilson Letters, (cat 40)", 20,0.,20.);
  TH1F* socialcMrFphysics = new TH1F("socialphysicscMrF","LIWC Social words in Wilson Letters, (cat 40)", 20,0.,20.);
  TH1F* socialcFrFphysics = new TH1F("socialphysicscFrF","LIWC Social words in Wilson Letters, (cat 40)", 20,0.,20.);
  TH1F* socialcFrMphysics = new TH1F("socialphysicscFrM","LIWC Social words in Wilson Letters, (cat 40)", 20,0.,20.);

  TH1F* socialcMrMsocsci = new TH1F("socialsocscicMrM","LIWC Social words in Cornell Letters, (cat 40)", 20,0.,20.);
  TH1F* socialcMrFsocsci = new TH1F("socialsocscicMrF","LIWC Social words in Cornell Letters, (cat 40)", 20,0.,20.);
  TH1F* socialcFrFsocsci = new TH1F("socialsocscicFrF","LIWC Social words in Cornell Letters, (cat 40)", 20,0.,20.);
  TH1F* socialcFrMsocsci = new TH1F("socialsocscicFrM","LIWC Social words in Cornell Letters, (cat 40)", 20,0.,20.);

  TH1F* cogProccMrMphysics = new TH1F("cogProcphysicscMrM","LIWC CogProc words in Wilson Letters, (cat 50)", 20,0.,20.);
  TH1F* cogProccMrFphysics = new TH1F("cogProcphysicscMrF","LIWC CogProc words in Wilson Letters, (cat 50)", 20,0.,20.);
  TH1F* cogProccFrFphysics = new TH1F("cogProcphysicscFrF","LIWC CogProc words in Wilson Letters, (cat 50)", 20,0.,20.);
  TH1F* cogProccFrMphysics = new TH1F("cogProcphysicscFrM","LIWC CogProc words in Wilson Letters, (cat 50)", 20,0.,20.);

  TH1F* cogProccMrMsocsci = new TH1F("cogProcsocscicMrM","LIWC CogProc words in Cornell Letters, (cat 50)", 20,0.,20.);
  TH1F* cogProccMrFsocsci = new TH1F("cogProcsocscicMrF","LIWC CogProc words in Cornell Letters, (cat 50)", 20,0.,20.);
  TH1F* cogProccFrFsocsci = new TH1F("cogProcsocscicFrF","LIWC CogProc words in Cornell Letters, (cat 50)", 20,0.,20.);
  TH1F* cogProccFrMsocsci = new TH1F("cogProcsocscicFrM","LIWC CogProc words in Cornell Letters, (cat 50)", 20,0.,20.);

  
  TH1F* timeOrientPastcMrMphysics = new TH1F("timeOrientPastphysicscMrM","LIWC TimeOrientPast+Present words in Wilson Letters", 20,0.,20.);
  TH1F* timeOrientPastcMrFphysics = new TH1F("timeOrientPastphysicscMrF","LIWC TimeOrientPast+Present words in Wilson Letters", 20,0.,20.);
  TH1F* timeOrientPastcFrFphysics = new TH1F("timeOrientPastphysicscFrF","LIWC TimeOrientPast+Present words in Wilson Letters", 20,0.,20.);
  TH1F* timeOrientPastcFrMphysics = new TH1F("timeOrientPastphysicscFrM","LIWC TimeOrientPast+Present words in Wilson Letters", 20,0.,20.);

  TH1F* timeOrientPastcMrMsocsci = new TH1F("timeOrientPastsocscicMrM","LIWC TimeOrientPast+Present words in Cornell Letters", 20,0.,20.);
  TH1F* timeOrientPastcMrFsocsci = new TH1F("timeOrientPastsocscicMrF","LIWC TimeOrientPast+Present words in Cornell Letters", 20,0.,20.);
  TH1F* timeOrientPastcFrFsocsci = new TH1F("timeOrientPastsocscicFrF","LIWC TimeOrientPast+Present words in Cornell Letters", 20,0.,20.);
  TH1F* timeOrientPastcFrMsocsci = new TH1F("timeOrientPastsocscicFrM","LIWC TimeOrientPast+Present words in Cornell Letters", 20,0.,20.);

  TH1F* timeOrientFuturecMrMphysics = new TH1F("timeOrientFuturephysicscMrM","LIWC TimeOrientFuture words in Wilson Letters", 20,0.,5.);
  TH1F* timeOrientFuturecMrFphysics = new TH1F("timeOrientFuturephysicscMrF","LIWC TimeOrientFuture words in Wilson Letters", 20,0.,5.);
  TH1F* timeOrientFuturecFrFphysics = new TH1F("timeOrientFuturephysicscFrF","LIWC TimeOrientFuture words in Wilson Letters", 20,0.,5.);
  TH1F* timeOrientFuturecFrMphysics = new TH1F("timeOrientFuturephysicscFrM","LIWC TimeOrientFuture words in Wilson Letters", 20,0.,5.);

  TH1F* timeOrientFuturecMrMsocsci = new TH1F("timeOrientFuturesocscicMrM","LIWC TimeOrientFuture words in Wilson Letters", 20,0.,5.);
  TH1F* timeOrientFuturecMrFsocsci = new TH1F("timeOrientFuturesocscicMrF","LIWC TimeOrientFuture words in Wilson Letters", 20,0.,5.);
  TH1F* timeOrientFuturecFrFsocsci = new TH1F("timeOrientFuturesocscicFrF","LIWC TimeOrientFuture words in Wilson Letters", 20,0.,5.);
  TH1F* timeOrientFuturecFrMsocsci = new TH1F("timeOrientFuturesocscicFrM","LIWC TimeOrientFuture words in Wilson Letters", 20,0.,5.);


  TH1F* PersConccMrMphysics = new TH1F("PersConcphysicscMrM","LIWC PersConc words in Wilson Letters", 40,0.,40.);
  TH1F* PersConccMrFphysics = new TH1F("PersConcphysicscMrF","LIWC PersConc words in Wilson Letters", 40,0.,40.);
  TH1F* PersConccFrFphysics = new TH1F("PersConcphysicscFrF","LIWC PersConc words in Wilson Letters", 40,0.,40.);
  TH1F* PersConccFrMphysics = new TH1F("PersConcphysicscFrM","LIWC PersConc words in Wilson Letters", 40,0.,40.);

  TH1F* PersConccMrMsocsci = new TH1F("PersConcsocscicMrM","LIWC PersConc words in Cornell Letters", 40,0.,40.);
  TH1F* PersConccMrFsocsci = new TH1F("PersConcsocscicMrF","LIWC PersConc words in Cornell Letters", 40,0.,40.);
  TH1F* PersConccFrFsocsci = new TH1F("PersConcsocscicFrF","LIWC PersConc words in Cornell Letters", 40,0.,40.);
  TH1F* PersConccFrMsocsci = new TH1F("PersConcsocscicFrM","LIWC PersConc words in Cornell Letters", 40,0.,40.);

  TH1F* PosemocMrMphysics = new TH1F("PosemophysicscMrM","LIWC Posemo words in Wilson Letters", 40,0.,40.);
  TH1F* PosemocMrFphysics = new TH1F("PosemophysicscMrF","LIWC Posemo words in Wilson Letters", 40,0.,40.);
  TH1F* PosemocFrFphysics = new TH1F("PosemophysicscFrF","LIWC Posemo words in Wilson Letters", 40,0.,40.);
  TH1F* PosemocFrMphysics = new TH1F("PosemophysicscFrM","LIWC Posemo words in Wilson Letters", 40,0.,40.);

    TH1F* NegemocMrMphysics = new TH1F("NegemophysicscMrM","LIWC Negemo words in Wilson Letters", 40,0.,40.);
  TH1F* NegemocMrFphysics = new TH1F("NegemophysicscMrF","LIWC Negemo words in Wilson Letters", 40,0.,40.);
  TH1F* NegemocFrFphysics = new TH1F("NegemophysicscFrF","LIWC Negemo words in Wilson Letters", 40,0.,40.);
  TH1F* NegemocFrMphysics = new TH1F("NegemophysicscFrM","LIWC Negemo words in Wilson Letters", 40,0.,40.);

  TH1F* analyticcMrMsocsci = new TH1F("analyticsocscicMrM","LIWC analytic words in Cornell Letters", 50,0.,100.);
  TH1F* analyticcMrFsocsci = new TH1F("analyticsocscicMrF","LIWC analytic words in Cornell Letters", 50,0.,100.);
  TH1F* analyticcFrFsocsci = new TH1F("analyticsocscicFrF","LIWC analytic words in Cornell Letters", 50,0.,100.);
  TH1F* analyticcFrMsocsci = new TH1F("analyticsocscicFrM","LIWC analytic words in Cornell Letters", 50,0.,100.);

  TH1F* analyticcMrMphysics = new TH1F("analyticphysicscMrM","LIWC analytic words in Wilson Letters", 50,0.,100.);
  TH1F* analyticcMrFphysics = new TH1F("analyticphysicscMrF","LIWC analytic words in Wilson Letters", 50,0.,100.);
  TH1F* analyticcFrFphysics = new TH1F("analyticphysicscFrF","LIWC analytic words in Wilson Letters", 50,0.,100.);
  TH1F* analyticcFrMphysics = new TH1F("analyticphysicscFrM","LIWC analytic words in Wilson Letters", 50,0.,100.);

  TH1F* analyticPhysicsHist = new TH1F("analyticPhysicsHist","LIWC analytic distribution in Physics", 100,0.,100.);
  TH1F* analyticSocSciHist = new TH1F("analyticSocSciHist","LIWC analytic distribution in SocSci", 100,0.,100.);

  TH1F* homecMrMsocsci = new TH1F("homesocscicMrM","LIWC home words in Cornell Letters", 50,0.,100.);
  TH1F* homecMrFsocsci = new TH1F("homesocscicMrF","LIWC home words in Cornell Letters", 50,0.,100.);
  TH1F* homecFrFsocsci = new TH1F("homesocscicFrF","LIWC home words in Cornell Letters", 50,0.,100.);
  TH1F* homecFrMsocsci = new TH1F("homesocscicFrM","LIWC home words in Cornell Letters", 50,0.,100.);

  TH1F* homecMrMphysics = new TH1F("homephysicscMrM","LIWC home words in Wilson Letters", 50,0.,100.);
  TH1F* homecMrFphysics = new TH1F("homephysicscMrF","LIWC home words in Wilson Letters", 50,0.,100.);
  TH1F* homecFrFphysics = new TH1F("homephysicscFrF","LIWC home words in Wilson Letters", 50,0.,100.);
  TH1F* homecFrMphysics = new TH1F("homephysicscFrM","LIWC home words in Wilson Letters", 50,0.,100.);


  TH1F* cloutcMrMsocsci = new TH1F("cloutsocscicMrM","LIWC clout words in Cornell Letters", 50,0.,100.);
  TH1F* cloutcMrFsocsci = new TH1F("cloutsocscicMrF","LIWC clout words in Cornell Letters", 50,0.,100.);
  TH1F* cloutcFrFsocsci = new TH1F("cloutsocscicFrF","LIWC clout words in Cornell Letters", 50,0.,100.);
  TH1F* cloutcFrMsocsci = new TH1F("cloutsocscicFrM","LIWC clout words in Cornell Letters", 50,0.,100.);

  TH1F* cloutcMrMphysics = new TH1F("cloutphysicscMrM","LIWC clout words in Wilson Letters", 50,0.,100.);
  TH1F* cloutcMrFphysics = new TH1F("cloutphysicscMrF","LIWC clout words in Wilson Letters", 50,0.,100.);
  TH1F* cloutcFrFphysics = new TH1F("cloutphysicscFrF","LIWC clout words in Wilson Letters", 50,0.,100.);
  TH1F* cloutcFrMphysics = new TH1F("cloutphysicscFrM","LIWC clout words in Wilson Letters", 50,0.,100.);

  TH1F* authenticcMrMsocsci = new TH1F("authenticsocscicMrM","LIWC authentic words in Cornell Letters", 50,0.,100.);
  TH1F* authenticcMrFsocsci = new TH1F("authenticsocscicMrF","LIWC authentic words in Cornell Letters", 50,0.,100.);
  TH1F* authenticcFrFsocsci = new TH1F("authenticsocscicFrF","LIWC authentic words in Cornell Letters", 50,0.,100.);
  TH1F* authenticcFrMsocsci = new TH1F("authenticsocscicFrM","LIWC authentic words in Cornell Letters", 50,0.,100.);

  TH1F* authenticcMrMphysics = new TH1F("authenticphysicscMrM","LIWC authentic words in Wilson Letters", 50,0.,100.);
  TH1F* authenticcMrFphysics = new TH1F("authenticphysicscMrF","LIWC authentic words in Wilson Letters", 50,0.,100.);
  TH1F* authenticcFrFphysics = new TH1F("authenticphysicscFrF","LIWC authentic words in Wilson Letters", 50,0.,100.);
  TH1F* authenticcFrMphysics = new TH1F("authenticphysicscFrM","LIWC authentic words in Wilson Letters", 50,0.,100.);


  TH1F* tonecMrMsocsci = new TH1F("tonesocscicMrM","LIWC tone words in Cornell Letters", 50,0.,100.);
  TH1F* tonecMrFsocsci = new TH1F("tonesocscicMrF","LIWC tone words in Cornell Letters", 50,0.,100.);
  TH1F* tonecFrFsocsci = new TH1F("tonesocscicFrF","LIWC tone words in Cornell Letters", 50,0.,100.);
  TH1F* tonecFrMsocsci = new TH1F("tonesocscicFrM","LIWC tone words in Cornell Letters", 50,0.,100.);

  TH1F* tonecMrMphysics = new TH1F("tonephysicscMrM","LIWC tone words in Wilson Letters", 50,0.,100.);
  TH1F* tonecMrFphysics = new TH1F("tonephysicscMrF","LIWC tone words in Wilson Letters", 50,0.,100.);
  TH1F* tonecFrFphysics = new TH1F("tonephysicscFrF","LIWC tone words in Wilson Letters", 50,0.,100.);
  TH1F* tonecFrMphysics = new TH1F("tonephysicscFrM","LIWC tone words in Wilson Letters", 50,0.,100.);


  
  TH1F* PosemocMrMsocsci = new TH1F("PosemosocscicMrM","LIWC Posemo words in Cornell Letters", 40,0.,40.);
  TH1F* PosemocMrFsocsci = new TH1F("PosemosocscicMrF","LIWC Posemo words in Cornell Letters", 40,0.,40.);
  TH1F* PosemocFrFsocsci = new TH1F("PosemosocscicFrF","LIWC Posemo words in Cornell Letters", 40,0.,40.);
  TH1F* PosemocFrMsocsci = new TH1F("PosemosocscicFrM","LIWC Posemo words in Cornell Letters", 40,0.,40.);

  TH1F* NegemocMrMsocsci = new TH1F("NegemosocscicMrM","LIWC Negemo words in Cornell Letters", 40,0.,40.);
  TH1F* NegemocMrFsocsci = new TH1F("NegemosocscicMrF","LIWC Negemo words in Cornell Letters", 40,0.,40.);
  TH1F* NegemocFrFsocsci = new TH1F("NegemosocscicFrF","LIWC Negemo words in Cornell Letters", 40,0.,40.);
  TH1F* NegemocFrMsocsci = new TH1F("NegemosocscicFrM","LIWC Negemo words in Cornell Letters", 40,0.,40.);


  TH2F* workVsSocialcFrMsocsci = new TH2F("workVsSocialcFrM","Work Vs Social socsci cFrM",40,0.,40,40,0.,40.);
  TH2F* workVsSocialcFrFsocsci = new TH2F("workVsSocialcFrF","Work Vs Social socsci cFrF",40,0.,40,40,0.,40.);
  TH2F* workVsSocialcMrMsocsci = new TH2F("workVsSocialcMrM","Work Vs Social socsci cMrM",40,0.,40,40,0.,40.);
  TH2F* workVsSocialcMrFsocsci = new TH2F("workVsSocialcMrF","Work Vs Social socsci cMrF",40,0.,40,40,0.,40.);

  TH2F* workVsSocialcFrMphysics = new TH2F("workVsSocialcFrM","Work Vs Social physics cFrM",40,0.,40,40,0.,40.);
  TH2F* workVsSocialcFrFphysics = new TH2F("workVsSocialcFrF","Work Vs Social physics cFrF",40,0.,40,40,0.,40.);
  TH2F* workVsSocialcMrMphysics = new TH2F("workVsSocialcMrM","Work Vs Social physics cMrM",40,0.,40,40,0.,40.);
  TH2F* workVsSocialcMrFphysics = new TH2F("workVsSocialcMrF","Work Vs Social physics cMrF",40,0.,40,40,0.,40.);

  const char* labels[4] = {"cMwM", "cMwF", "cFwF","cFwM"};
  std::cout << "made ntuples" << std::endl;
  inputFiles.clear();
  inputFiles.seekg(0);
 
  string headerInfo;
  std::getline(inputFiles,headerInfo);


  // this code assumes list sorted by candidate ID
  Int_t uniqueMaleCandidatesPhysics, uniqueFemaleCandidatesPhysics, uniqueMaleCandidatesSocSci, uniqueFemaleCandidatesSocSci;
  uniqueMaleCandidatesPhysics = uniqueFemaleCandidatesPhysics = uniqueMaleCandidatesSocSci = uniqueFemaleCandidatesSocSci = 0;
  Int_t currentMaleCandidatePhysics, currentFemaleCandidatePhysics, currentMaleCandidateSocSci, currentFemaleCandidateSocSci;
  currentMaleCandidatePhysics = currentFemaleCandidatePhysics = currentMaleCandidateSocSci = currentFemaleCandidateSocSci = 0;
  Int_t currentCandidateIdMalePhysics = 0;
  Int_t currentCandidateIdFeMalePhysics = 0;
  Int_t currentCandidateIdMaleSocSci= 0;
  Int_t currentCandidateIdFeMaleSocSci = 0;
  Int_t currentCandidateId = 0;
  // cMrM analysis
  // letterLength = 10;
  
  for (Int_t ithLetter = 0 ; ithLetter< letterLength; ++ithLetter){
    inputFiles >> rowNo >> rowHash >> bobHash >> candId >> writerId >> canGender >> writerGender >> both >> discipline
	       >> Ref_is_advisor >> Ref_nonresearch >> both_gender_non_advisor_refs >>  wc >> Analytic >> Clout >> Authentic >> Tone >>  WPS>> Dic>> function>> pronoun>> ppron>> i>> we>> you >> shehe>> they>> ipron>> article>> prep>> auxverb>> adverb>> conj>> negate>> verb>> adj>> compare>> interrog>> number>> quant>>
      affect>> posemo>> negemo>> anx>> anger>> sad >>      social >> family>> friends>> female>> male>> cogproc>> insight>> cause>> discrep>> tentat>> certain>> differ>> percept>> see>> hear>> feel>> bio>> body>> health>> sexual>> ingest>> drives>> affiliation>>
      achiev>>power>>familyRelated>>reward>>risk>>focuspast>>focuspresent>>focusfuture >>
      relativ>>motion>>space>>time>>work>>leisure>>home>>money>>relig>>death>>informal>>swear>>netspeak>>assent>>nonflu>>filler>>AllPunc>>Period>>Comma>>Colon>>SemiC>>QMark>>Exclam>>Dash>>Quote>>
      Apostro>>Parent>>OtherP >> standout >> ability >> grindstone >> teaching >> research >> agentic >> communal >> internal1 >> internal2 >> internal3 >> internal4 >> internal5 >> internal6;
    std::cout << "wc = " << wc << std::endl;
    std::cout << "read a row" << std::endl;
    wcCut = 0.;
    if (ithLetter > -10000){
      analysisOut   << rowNo << " " << rowHash << " " << bobHash << " " << candId << " " << writerId << " " << canGender << " " << writerGender << " " << " "
		    << both << " " << discipline << " " << Ref_is_advisor << " " << Ref_nonresearch << " " << both_gender_non_advisor_refs << " " <<   wc <<  " "  <<  WPS <<  " "  <<  Dic <<  " "  <<  function <<  " "  <<  pronoun <<  " "  <<  ppron <<  " "  <<  i <<  " "  <<  we <<  " "  <<  you  <<  " "  <<  shehe <<  " "  <<  they <<  " "  <<  ipron  <<  " "  <<  article <<  " "
		    <<  prep  <<  " "  <<  auxverb <<  " "  <<  adverb <<  " "  <<  conj <<  " "  <<  negate <<  " "  <<  verb <<  " "  <<  adj <<  " "  <<  compare <<  " "  <<  interrog <<  " "  <<  number <<  " "  <<  quant <<  "\n "
		    <<  affect <<  " "  <<  posemo <<  " "  <<  negemo <<  " "  <<  anx <<  " "  <<  anger <<  " "  <<  sad  <<  " "
		    <<  social  <<  " "  <<  family <<  " "  <<  friends <<  " "  <<  female <<  " "  <<  male <<  "\n "  <<  cogproc <<  " "  <<  insight <<  " "  <<  cause <<  " "  <<  discrep <<  " "  <<  tentat <<  " "  <<  certain <<  " "  <<  differ <<  " "
		    <<  percept <<  " "  <<  see <<  " "  <<  hear  <<  " "  <<  feel  <<  " "  <<  bio  <<  " "  <<  body  <<  " "  <<  health <<  " "  <<  sexual <<  " "  <<  ingest  <<  " "  <<  drives  <<  " "  <<  affiliation  <<  " " 
		    <<  achiev <<  " "  << power <<  " "  << reward <<  " "  << risk <<  " "  <<  focuspast <<  " "  <<  focuspresent <<  " "  <<  focusfuture  <<  "\n "  << 
	relativ <<  " "  << motion <<  " "  << space <<  " "  << time <<  " "  << work <<  " "  << leisure <<  " "  << home <<  " "  << money <<  " "  << relig <<  " "
		    << death <<  "\n "  << informal <<  " "  << swear <<  " "  << netspeak <<  " "  << assent <<  " "  << nonflu <<  " "  << filler <<  " "  << AllPunc <<  " "  << Period <<  " "  << Comma <<  " "
		    << Colon <<  " "  << SemiC <<  " "  << QMark <<  " "  << Exclam <<  " "  << Dash <<  " "  << Quote <<  " "  << 
	Apostro <<  " "  << Parent <<  " "  << OtherP  << " " << internal5 << " " << internal6 << "\n \n " <<  std::endl;
    }

    if (candId != currentCandidateId) {
      if (discipline == 1){
	if (canGender == 1){
	  ++uniqueFemaleCandidatesPhysics;
	  candIdFemalePhysicsOut << candidateName << " " << candId << std::endl;
	}
	if (canGender == 0){
	  ++uniqueMaleCandidatesPhysics;
	  candIdMalePhysicsOut << candidateName << " " << candId << std::endl;
	}
      }
      if (discipline == 0){
	if (canGender == 1){
	  candIdFemaleSocSciOut << candidateName << " " << candId << std::endl;
	  ++uniqueFemaleCandidatesSocSci;
	}
	if (canGender == 0){
	  candIdMaleSocSciOut << candidateName << " " << candId << std::endl;
	  ++uniqueMaleCandidatesSocSci;
	}
      }
      currentCandidateId = candId;
    }
    useBoth = false;
    std::cout << "finished" << std::endl;
    if  (useBoth && both < 0.5) continue;
    std::cout << " candidate and writer " << canGender << " " << writerGender << " " << candId << std::endl;
    if (writerGender < 0.5){std::cout << "male writer " << std::endl;}
    if (wc < wcCut ) continue;

    if (discipline > 0.5){
      if (canGender < 0.5 && writerGender < 0.5){
	cat = 1;
	std::cout << "in cat 1" << std::endl;
	nt[0] = cat;
	nt[1] = wc;
	nt[2] = Analytic;
	nt[3] = Clout;
	nt[4] = Authentic;
	nt[5] = Tone;
	nt[6] = WPS;
	nt[7] = Dic;
	nt[8] = function;
	nt[9] = pronoun;
	nt[10] = ppron;
	nt[11] = i;
	nt[12] = we;
	nt[13] = you ;
	nt[14] = shehe;
	nt[15] = they;
	nt[16] = ipron;
	nt[17] = article;
	nt[18] = prep;
	nt[19] = auxverb;
	nt[20] = adverb;
	nt[21] = conj;
	nt[22] = negate;
	nt[23] = verb;
	nt[24] = adj;
	nt[25] = compare;
	nt[26] = interrog;
	nt[27] = number;
	nt[28] = quant;
	nt[29] = affect;
	nt[30] = posemo;
	nt[31] = negemo;
	nt[32] = anx;
	nt[33] = anger;
	nt[34] = sad ;
	nt[35] = social ;
	nt[36] = family;
	nt[37] = friends;
	nt[38] = female;
	nt[39] = male;
	nt[40] = cogproc;
	nt[41] = insight;
	nt[42] = cause;
	nt[43] = discrep;
	nt[44] = tentat;
	nt[45] = certain;
	nt[46] = differ;
	nt[47] = percept;
	nt[48] = see;
	nt[49] = hear;
	nt[50] = feel;
	nt[51] = bio;
	nt[52] = body;
	nt[53] = health;
	nt[54] = sexual;
	nt[55] = ingest;
	nt[56] = drives;
	nt[57] = affiliation;
	nt[58] = achiev;
	nt[59] = power;
	nt[60] = reward;
	nt[61] = risk;
	nt[62] = focuspast;
	nt[63] = focuspresent;
	nt[64] = focusfuture ;
	nt[65] = relativ;
	nt[66] = motion;
	nt[67] = space;
	nt[68] = time;
	nt[69] = work;
	nt[70] = leisure;
	nt[71] = home;
	nt[72] = money;
	nt[73] = relig;
	nt[74] = death;
	nt[75] = informal;
	nt[76] = swear;
	nt[77] = netspeak;
	nt[78] = assent;
	nt[79] = nonflu;
	nt[80] = filler;
	nt[81] = AllPunc;
	nt[82] = Period;
	nt[83] = Comma;
	nt[84] = Colon;
	nt[85] = SemiC;
	nt[86] = QMark;
	nt[87] = Exclam;
	nt[88] = Dash;
	nt[89] = Quote;
	nt[90] = Apostro;
	nt[91] = Parent;
	nt[92] = OtherP;

	wordsPhysicscMrM->Fill(wc);
	PosemocMrMphysics->Fill(posemo);
	NegemocMrMphysics->Fill(negemo);
	Float_t  drivesT = achiev + power - familyRelated;
	//drivesT = achiev;
	drivescMrMphysics->Fill(drivesT);
	affectcMrMphysics->Fill(affect);
	socialcMrMphysics->Fill(social);
	cogProccMrMphysics->Fill(cogproc);
	timeOrientPastcMrMphysics->Fill(focuspast+focuspresent);
	timeOrientFuturecMrMphysics->Fill(focusfuture);
	PersConccMrMphysics->Fill(work+leisure+home+money+relig+death);
	workcMrMphysics->Fill(work);
	homecMrMphysics->Fill(home);
	analyticcMrMphysics->Fill(Analytic);
	cloutcMrMphysics->Fill(Clout);
	authenticcMrMphysics->Fill(Authentic);
	tonecMrMphysics->Fill(Tone);
	analyticPhysicsHist->Fill(Analytic);
	physics->Fill(nt);
	++nlines;
      }
      // cFrM analysis
    
      if (canGender > 0.5 && writerGender < 0.5){
	cat = 2;
	nt[0] = cat;
	nt[1] = wc;
	nt[2] = Analytic;
	nt[3] = Clout;
	nt[4] = Authentic;
	nt[5] = Tone;
	nt[6] = WPS;
	nt[7] = Dic;
	nt[8] = function;
	nt[9] = pronoun;
	nt[10] = ppron;
	nt[11] = i;
	nt[12] = we;
	nt[13] = you ;
	nt[14] = shehe;
	nt[15] = they;
	nt[16] = ipron;
	nt[17] = article;
	nt[18] = prep;
	nt[19] = auxverb;
	nt[20] = adverb;
	nt[21] = conj;
	nt[22] = negate;
	nt[23] = verb;
	nt[24] = adj;
	nt[25] = compare;
	nt[26] = interrog;
	nt[27] = number;
	nt[28] = quant;
	nt[29] = affect;
	nt[30] = posemo;
	nt[31] = negemo;
	nt[32] = anx;
	nt[33] = anger;
	nt[34] = sad ;
	nt[35] = social ;
	nt[36] = family;
	nt[37] = friends;
	nt[38] = female;
	nt[39] = male;
	nt[40] = cogproc;
	nt[41] = insight;
	nt[42] = cause;
	nt[43] = discrep;
	nt[44] = tentat;
	nt[45] = certain;
	nt[46] = differ;
	nt[47] = percept;
	nt[48] = see;
	nt[49] = hear;
	nt[50] = feel;
	nt[51] = bio;
	nt[52] = body;
	nt[53] = health;
	nt[54] = sexual;
	nt[55] = ingest;
	nt[56] = drives;
	nt[57] = affiliation;
	nt[58] = achiev;
	nt[59] = power;
	nt[60] = reward;
	nt[61] = risk;
	nt[62] = focuspast;
	nt[63] = focuspresent;
	nt[64] = focusfuture ;
	nt[65] = relativ;
	nt[66] = motion;
	nt[67] = space;
	nt[68] = time;
	nt[69] = work;
	nt[70] = leisure;
	nt[71] = home;
	nt[72] = money;
	nt[73] = relig;
	nt[74] = death;
	nt[75] = informal;
	nt[76] = swear;
	nt[77] = netspeak;
	nt[78] = assent;
	nt[79] = nonflu;
	nt[80] = filler;
	nt[81] = AllPunc;
	nt[82] = Period;
	nt[83] = Comma;
	nt[84] = Colon;
	nt[85] = SemiC;
	nt[86] = QMark;
	nt[87] = Exclam;
	nt[88] = Dash;
	nt[89] = Quote;
	nt[90] = Apostro;
	nt[91] = Parent;
	nt[92] = OtherP;
	timeOrientPastcFrMphysics->Fill(focuspast+focuspresent);
	timeOrientFuturecFrMphysics->Fill(focusfuture);
	PosemocFrMphysics->Fill(posemo);
	NegemocFrMphysics->Fill(negemo);
	wordsPhysicscFrM->Fill(wc);
	Float_t  drivesT = achiev + power - familyRelated;
	//	drivesT = achiev;
	drivescFrMphysics->Fill(drivesT);
	affectcFrMphysics->Fill(affect);
	socialcFrMphysics->Fill(social);
	cogProccFrMphysics->Fill(cogproc);
	timeOrientPastcFrMphysics->Fill(focuspast+focuspresent);
	timeOrientFuturecFrMphysics->Fill(focusfuture);
	PersConccFrMphysics->Fill(work+leisure+home+money+relig+death);
	workcFrMphysics->Fill(work);
	analyticcFrMphysics->Fill(Analytic);
	cloutcFrMphysics->Fill(Clout);
	authenticcFrMphysics->Fill(Authentic);
	tonecFrMphysics->Fill(Tone);
	homecFrMphysics->Fill(home);
	analyticPhysicsHist->Fill(Analytic);

	physics->Fill(nt);
	++nlines;
      }

      // cFrF analysis
      if (canGender > 0.5 && (writerGender > 0.5)){
	cat = 3;
	std::cout << "in cat 3" << std::endl;
	std::cout   << candidateName << " "  <<   wc <<  " "  <<  WPS <<  " "  <<  Dic <<  " "  <<  function <<  " "  <<  pronoun <<  " "  <<  ppron <<  " "  <<  i <<  " "  <<  we <<  " "  <<  you  <<  " "  <<  shehe <<  " "  <<  they <<  " "  <<  ipron  <<  " "  <<  article <<  " "
		    <<  prep  <<  " "  <<  auxverb <<  " "  <<  adverb <<  " "  <<  conj <<  " "  <<  negate <<  " "  <<  verb <<  " "  <<  adj <<  " "  <<  compare <<  " "  <<  interrog <<  " "  <<  number <<  " "  <<  quant <<  "\n "
		    <<  affect <<  " "  <<  posemo <<  " "  <<  negemo <<  " "  <<  anx <<  " "  <<  anger <<  " "  <<  sad  <<  " "
		    <<  social  <<  " "  <<  family <<  " "  <<  friends <<  " "  <<  female <<  " "  <<  male <<  "\n "  <<  cogproc <<  " "  <<  insight <<  " "  <<  cause <<  " "  <<  discrep <<  " "  <<  tentat <<  " "  <<  certain <<  " "  <<  differ <<  " "
		    <<  percept <<  " "  <<  see <<  " "  <<  hear  <<  " "  <<  feel  <<  " "  <<  bio  <<  " "  <<  body  <<  " "  <<  health <<  " "  <<  sexual <<  " "  <<  ingest  <<  " "  <<  drives  <<  " "  <<  affiliation  <<  " " 
		    <<  achiev <<  " "  << power <<  " "  << reward <<  " "  << risk <<  " "  <<  focuspast <<  " "  <<  focuspresent <<  " "  <<  focusfuture  <<  "\n "  << 
	  relativ <<  " "  << motion <<  " "  << space <<  " "  << time <<  " "  << work <<  " "  << leisure <<  " "  << home <<  " "  << money <<  " "  << relig <<  " "
		    << death <<  "\n "  << informal <<  " "  << swear <<  " "  << netspeak <<  " "  << assent <<  " "  << nonflu <<  " "  << filler <<  " "  << AllPunc <<  " "  << Period <<  " "  << Comma <<  " "
		    << Colon <<  " "  << SemiC <<  " "  << QMark <<  " "  << Exclam <<  " "  << Dash <<  " "  << Quote <<  " "  << 
	  Apostro <<  " "  << Parent <<  " "  << OtherP  <<  "\n \n " <<  std::endl;

	nt[0] = cat;
	nt[1] = wc;
	nt[2] = Analytic;
	nt[3] = Clout;
	nt[4] = Authentic;
	nt[5] = Tone;
	nt[6] = WPS;
	nt[7] = Dic;
	nt[8] = function;
	nt[9] = pronoun;
	nt[10] = ppron;
	nt[11] = i;
	nt[12] = we;
	nt[13] = you ;
	nt[14] = shehe;
	nt[15] = they;
	nt[16] = ipron;
	nt[17] = article;
	nt[18] = prep;
	nt[19] = auxverb;
	nt[20] = adverb;
	nt[21] = conj;
	nt[22] = negate;
	nt[23] = verb;
	nt[24] = adj;
	nt[25] = compare;
	nt[26] = interrog;
	nt[27] = number;
	nt[28] = quant;
	nt[29] = affect;
	nt[30] = posemo;
	nt[31] = negemo;
	nt[32] = anx;
	nt[33] = anger;
	nt[34] = sad ;
	nt[35] = social ;
	nt[36] = family;
	nt[37] = friends;
	nt[38] = female;
	nt[39] = male;
	nt[40] = cogproc;
	nt[41] = insight;
	nt[42] = cause;
	nt[43] = discrep;
	nt[44] = tentat;
	nt[45] = certain;
	nt[46] = differ;
	nt[47] = percept;
	nt[48] = see;
	nt[49] = hear;
	nt[50] = feel;
	nt[51] = bio;
	nt[52] = body;
	nt[53] = health;
	nt[54] = sexual;
	nt[55] = ingest;
	nt[56] = drives;
	nt[57] = affiliation;
	nt[58] = achiev;
	nt[59] = power;
	nt[60] = reward;
	nt[61] = risk;
	nt[62] = focuspast;
	nt[63] = focuspresent;
	nt[64] = focusfuture ;
	nt[65] = relativ;
	nt[66] = motion;
	nt[67] = space;
	nt[68] = time;
	nt[69] = work;
	nt[70] = leisure;
	nt[71] = home;
	nt[72] = money;
	nt[73] = relig;
	nt[74] = death;
	nt[75] = informal;
	nt[76] = swear;
	nt[77] = netspeak;
	nt[78] = assent;
	nt[79] = nonflu;
	nt[80] = filler;
	nt[81] = AllPunc;
	nt[82] = Period;
	nt[83] = Comma;
	nt[84] = Colon;
	nt[85] = SemiC;
	nt[86] = QMark;
	nt[87] = Exclam;
	nt[88] = Dash;
	nt[89] = Quote;
	nt[90] = Apostro;
	nt[91] = Parent;
	nt[92] = OtherP;
	PosemocFrFphysics->Fill(posemo);
	NegemocFrFphysics->Fill(negemo);
	wordsPhysicscFrF->Fill(wc);
	Float_t  drivesT = achiev + power - familyRelated;
	//drivesT	drivesT = achiev;
	drivescFrFphysics->Fill(drivesT);
	affectcFrFphysics->Fill(affect);
	socialcFrFphysics->Fill(social);
	cogProccFrFphysics->Fill(cogproc);
	timeOrientPastcFrFphysics->Fill(focuspast+focuspresent);
	timeOrientFuturecFrFphysics->Fill(focusfuture);
	PersConccFrFphysics->Fill(work+leisure+home+money+relig+death);
	workcFrFphysics->Fill(work);

	analyticcFrFphysics->Fill(Analytic);
	cloutcFrFphysics->Fill(Clout);
	authenticcFrFphysics->Fill(Authentic);
	tonecFrFphysics->Fill(Tone);
	homecFrFphysics->Fill(home);
 	analyticPhysicsHist->Fill(Analytic);

	physics->Fill(nt);
	++nlines;
      }


      // cMrF analysis
      if (canGender < 0.5 && writerGender > 0.5){
	cat = 4;
	std::cout << "in cat 4" << std::endl;

	nt[0] = cat;
	nt[1] = wc;
	nt[2] = Analytic;
	nt[3] = Clout;
	nt[4] = Authentic;
	nt[5] = Tone;
	nt[6] = WPS;
	nt[7] = Dic;
	nt[8] = function;
	nt[9] = pronoun;
	nt[10] = ppron;
	nt[11] = i;
	nt[12] = we;
	nt[13] = you ;
	nt[14] = shehe;
	nt[15] = they;
	nt[16] = ipron;
	nt[17] = article;
	nt[18] = prep;
	nt[19] = auxverb;
	nt[20] = adverb;
	nt[21] = conj;
	nt[22] = negate;
	nt[23] = verb;
	nt[24] = adj;
	nt[25] = compare;
	nt[26] = interrog;
	nt[27] = number;
	nt[28] = quant;
	nt[29] = affect;
	nt[30] = posemo;
	nt[31] = negemo;
	nt[32] = anx;
	nt[33] = anger;
	nt[34] = sad ;
	nt[35] = social ;
	nt[36] = family;
	nt[37] = friends;
	nt[38] = female;
	nt[39] = male;
	nt[40] = cogproc;
	nt[41] = insight;
	nt[42] = cause;
	nt[43] = discrep;
	nt[44] = tentat;
	nt[45] = certain;
	nt[46] = differ;
	nt[47] = percept;
	nt[48] = see;
	nt[49] = hear;
	nt[50] = feel;
	nt[51] = bio;
	nt[52] = body;
	nt[53] = health;
	nt[54] = sexual;
	nt[55] = ingest;
	nt[56] = drives;
	nt[57] = affiliation;
	nt[58] = achiev;
	nt[59] = power;
	nt[60] = reward;
	nt[61] = risk;
	nt[62] = focuspast;
	nt[63] = focuspresent;
	nt[64] = focusfuture ;
	nt[65] = relativ;
	nt[66] = motion;
	nt[67] = space;
	nt[68] = time;
	nt[69] = work;
	nt[70] = leisure;
	nt[71] = home;
	nt[72] = money;
	nt[73] = relig;
	nt[74] = death;
	nt[75] = informal;
	nt[76] = swear;
	nt[77] = netspeak;
	nt[78] = assent;
	nt[79] = nonflu;
	nt[80] = filler;
	nt[81] = AllPunc;
	nt[82] = Period;
	nt[83] = Comma;
	nt[84] = Colon;
	nt[85] = SemiC;
	nt[86] = QMark;
	nt[87] = Exclam;
	nt[88] = Dash;
	nt[89] = Quote;
	nt[90] = Apostro;
	nt[91] = Parent;
	nt[92] = OtherP;
	PosemocMrFphysics->Fill(posemo);
	NegemocMrFphysics->Fill(negemo);
	Float_t  drivesT = achiev + power - familyRelated;
	//	drivesT= achiev;
        wordsPhysicscMrF->Fill(wc);
	drivescMrFphysics->Fill(drivesT);
	affectcMrFphysics->Fill(affect);
	socialcMrFphysics->Fill(social);
	cogProccMrFphysics->Fill(cogproc);
	timeOrientPastcMrFphysics->Fill(focuspast+focuspresent);
	timeOrientFuturecMrFphysics->Fill(focusfuture);
	PersConccMrFphysics->Fill(work+leisure+home+money+relig+death);
	workcMrFphysics->Fill(work);
	homecMrFphysics->Fill(home);
 	analyticPhysicsHist->Fill(Analytic);

	analyticcMrFphysics->Fill(Analytic);
	cloutcMrFphysics->Fill(Clout);
	authenticcMrFphysics->Fill(Authentic);
	tonecMrFphysics->Fill(Tone);

    
	physics->Fill(nt);
	++nlines;
      }
    }



    if (discipline < 0.5){
      std::cout << "in soscsi clause" << std::endl;	
      if (canGender < 0.5 && writerGender < 0.5){

	cat = 5; 
	nt[0] = cat;
	nt[1] = wc;
	nt[2] = Analytic;
	nt[3] = Clout;
	nt[4] = Authentic;
	nt[5] = Tone;
	nt[6] = WPS;
	nt[7] = Dic;
	nt[8] = function;
	nt[9] = pronoun;
	nt[10] = ppron;
	nt[11] = i;
	nt[12] = we;
	nt[13] = you ;
	nt[14] = shehe;
	nt[15] = they;
	nt[16] = ipron;
	nt[17] = article;
	nt[18] = prep;
	nt[19] = auxverb;
	nt[20] = adverb;
	nt[21] = conj;
	nt[22] = negate;
	nt[23] = verb;
	nt[24] = adj;
	nt[25] = compare;
	nt[26] = interrog;
	nt[27] = number;
	nt[28] = quant;
	nt[29] = affect;
	nt[30] = posemo;
	nt[31] = negemo;
	nt[32] = anx;
	nt[33] = anger;
	nt[34] = sad ;
	nt[35] = social ;
	nt[36] = family;
	nt[37] = friends;
	nt[38] = female;
	nt[39] = male;
	nt[40] = cogproc;
	nt[41] = insight;
	nt[42] = cause;
	nt[43] = discrep;
	nt[44] = tentat;
	nt[45] = certain;
	nt[46] = differ;
	nt[47] = percept;
	nt[48] = see;
	nt[49] = hear;
	nt[50] = feel;
	nt[51] = bio;
	nt[52] = body;
	nt[53] = health;
	nt[54] = sexual;
	nt[55] = ingest;
	nt[56] = drives;
	nt[57] = affiliation;
	nt[58] = achiev;
	nt[59] = power;
	nt[60] = reward;
	nt[61] = risk;
	nt[62] = focuspast;
	nt[63] = focuspresent;
	nt[64] = focusfuture ;
	nt[65] = relativ;
	nt[66] = motion;
	nt[67] = space;
	nt[68] = time;
	nt[69] = work;
	nt[70] = leisure;
	nt[71] = home;
	nt[72] = money;
	nt[73] = relig;
	nt[74] = death;
	nt[75] = informal;
	nt[76] = swear;
	nt[77] = netspeak;
	nt[78] = assent;
	nt[79] = nonflu;
	nt[80] = filler;
	nt[81] = AllPunc;
	nt[82] = Period;
	nt[83] = Comma;
	nt[84] = Colon;
	nt[85] = SemiC;
	nt[86] = QMark;
	nt[87] = Exclam;
	nt[88] = Dash;
	nt[89] = Quote;
	nt[90] = Apostro;
	nt[91] = Parent;
	nt[92] = OtherP;
	PosemocMrMsocsci->Fill(posemo);
	NegemocMrMsocsci->Fill(negemo);
	Float_t  drivesT = achiev + power - familyRelated;
	//	drivesT = achiev;
	wordsSocScicMrM->Fill(wc);
	drivescMrMsocsci->Fill(drivesT);
	affectcMrMsocsci->Fill(affect);
	socialcMrMsocsci->Fill(social);
	cogProccMrMsocsci->Fill(cogproc);
	timeOrientPastcMrMsocsci->Fill(focuspast+focuspresent);
	timeOrientFuturecMrMsocsci->Fill(focusfuture);
	PersConccMrMsocsci->Fill(work+leisure+home+money+relig+death);
	workVsSocialcMrMsocsci->Fill(work,social);
	workcMrMsocsci->Fill(work);
	analyticcMrMsocsci->Fill(Analytic);
	cloutcMrMsocsci->Fill(Clout);
	authenticcMrMsocsci->Fill(Authentic);
	tonecMrMsocsci->Fill(Tone);
	homecMrMsocsci->Fill(home);
 	analyticSocSciHist->Fill(Analytic);

	socsci->Fill(nt);
	++nlines;
      }
      // cFrm analysis
      if ( canGender > 0.5 && writerGender < 0.5){

	cat = 6;
 
	nt[0] = cat;
	nt[1] = wc;
	nt[2] = Analytic;
	nt[3] = Clout;
	nt[4] = Authentic;
	nt[5] = Tone;
	nt[6] = WPS;
	nt[7] = Dic;
	nt[8] = function;
	nt[9] = pronoun;
	nt[10] = ppron;
	nt[11] = i;
	nt[12] = we;
	nt[13] = you ;
	nt[14] = shehe;
	nt[15] = they;
	nt[16] = ipron;
	nt[17] = article;
	nt[18] = prep;
	nt[19] = auxverb;
	nt[20] = adverb;
	nt[21] = conj;
	nt[22] = negate;
	nt[23] = verb;
	nt[24] = adj;
	nt[25] = compare;
	nt[26] = interrog;
	nt[27] = number;
	nt[28] = quant;
	nt[29] = affect;
	nt[30] = posemo;
	nt[31] = negemo;
	nt[32] = anx;
	nt[33] = anger;
	nt[34] = sad ;
	nt[35] = social ;
	nt[36] = family;
	nt[37] = friends;
	nt[38] = female;
	nt[39] = male;
	nt[40] = cogproc;
	nt[41] = insight;
	nt[42] = cause;
	nt[43] = discrep;
	nt[44] = tentat;
	nt[45] = certain;
	nt[46] = differ;
	nt[47] = percept;
	nt[48] = see;
	nt[49] = hear;
	nt[50] = feel;
	nt[51] = bio;
	nt[52] = body;
	nt[53] = health;
	nt[54] = sexual;
	nt[55] = ingest;
	nt[56] = drives;
	nt[57] = affiliation;
	nt[58] = achiev;
	nt[59] = power;
	nt[60] = reward;
	nt[61] = risk;
	nt[62] = focuspast;
	nt[63] = focuspresent;
	nt[64] = focusfuture ;
	nt[65] = relativ;
	nt[66] = motion;
	nt[67] = space;
	nt[68] = time;
	nt[69] = work;
	nt[70] = leisure;
	nt[71] = home;
	nt[72] = money;
	nt[73] = relig;
	nt[74] = death;
	nt[75] = informal;
	nt[76] = swear;
	nt[77] = netspeak;
	nt[78] = assent;
	nt[79] = nonflu;
	nt[80] = filler;
	nt[81] = AllPunc;
	nt[82] = Period;
	nt[83] = Comma;
	nt[84] = Colon;
	nt[85] = SemiC;
	nt[86] = QMark;
	nt[87] = Exclam;
	nt[88] = Dash;
	nt[89] = Quote;
	nt[90] = Apostro;
	nt[91] = Parent;
	nt[92] = OtherP;

	PosemocFrMsocsci->Fill(posemo);
	NegemocFrMsocsci->Fill(negemo);
	Float_t  drivesT = achiev + power - familyRelated;
	//	drivesT = achiev;
	wordsSocScicFrM->Fill(wc);
	drivescFrMsocsci->Fill(drivesT);
	affectcFrMsocsci->Fill(affect);
	socialcFrMsocsci->Fill(social);
	cogProccFrMsocsci->Fill(cogproc);
	timeOrientPastcFrMsocsci->Fill(focuspast+focuspresent);
	timeOrientFuturecFrMsocsci->Fill(focusfuture);
	PersConccFrMsocsci->Fill(work+leisure+home+money+relig+death);
	workVsSocialcFrMsocsci->Fill(work,social);
	workcFrMsocsci->Fill(work);
	homecFrMsocsci->Fill(home);
 
	analyticcFrMsocsci->Fill(Analytic);
	cloutcFrMsocsci->Fill(Clout);
	authenticcFrMsocsci->Fill(Authentic);
	tonecFrMsocsci->Fill(Tone);
	analyticSocSciHist->Fill(Analytic);

	socsci->Fill(nt);
	++nlines;
      }

      // cFrF analysis

      if (canGender > 0.5 && (writerGender > 0.5)){
	cat = 7;
 


	nt[0] = cat;
	nt[1] = wc;
	nt[2] = Analytic;
	nt[3] = Clout;
	nt[4] = Authentic;
	nt[5] = Tone;
	nt[6] = WPS;
	nt[7] = Dic;
	nt[8] = function;
	nt[9] = pronoun;
	nt[10] = ppron;
	nt[11] = i;
	nt[12] = we;
	nt[13] = you ;
	nt[14] = shehe;
	nt[15] = they;
	nt[16] = ipron;
	nt[17] = article;
	nt[18] = prep;
	nt[19] = auxverb;
	nt[20] = adverb;
	nt[21] = conj;
	nt[22] = negate;
	nt[23] = verb;
	nt[24] = adj;
	nt[25] = compare;
	nt[26] = interrog;
	nt[27] = number;
	nt[28] = quant;
	nt[29] = affect;
	nt[30] = posemo;
	nt[31] = negemo;
	nt[32] = anx;
	nt[33] = anger;
	nt[34] = sad ;
	nt[35] = social ;
	nt[36] = family;
	nt[37] = friends;
	nt[38] = female;
	nt[39] = male;
	nt[40] = cogproc;
	nt[41] = insight;
	nt[42] = cause;
	nt[43] = discrep;
	nt[44] = tentat;
	nt[45] = certain;
	nt[46] = differ;
	nt[47] = percept;
	nt[48] = see;
	nt[49] = hear;
	nt[50] = feel;
	nt[51] = bio;
	nt[52] = body;
	nt[53] = health;
	nt[54] = sexual;
	nt[55] = ingest;
	nt[56] = drives;
	nt[57] = affiliation;
	nt[58] = achiev;
	nt[59] = power;
	nt[60] = reward;
	nt[61] = risk;
	nt[62] = focuspast;
	nt[63] = focuspresent;
	nt[64] = focusfuture ;
	nt[65] = relativ;
	nt[66] = motion;
	nt[67] = space;
	nt[68] = time;
	nt[69] = work;
	nt[70] = leisure;
	nt[71] = home;
	nt[72] = money;
	nt[73] = relig;
	nt[74] = death;
	nt[75] = informal;
	nt[76] = swear;
	nt[77] = netspeak;
	nt[78] = assent;
	nt[79] = nonflu;
	nt[80] = filler;
	nt[81] = AllPunc;
	nt[82] = Period;
	nt[83] = Comma;
	nt[84] = Colon;
	nt[85] = SemiC;
	nt[86] = QMark;
	nt[87] = Exclam;
	nt[88] = Dash;
	nt[89] = Quote;
	nt[90] = Apostro;
	nt[91] = Parent;
	nt[92] = OtherP;
	PosemocFrFsocsci->Fill(posemo);
	NegemocFrFsocsci->Fill(negemo);
	Float_t  drivesT = achiev + power - familyRelated;
	//	drivesT = achiev;
	wordsSocScicFrF->Fill(wc);
	drivescFrFsocsci->Fill(drivesT);
	affectcFrFsocsci->Fill(affect);
	socialcFrFsocsci->Fill(social);
	cogProccFrFsocsci->Fill(cogproc);
	timeOrientPastcFrFsocsci->Fill(focuspast+focuspresent);
	timeOrientFuturecFrFsocsci->Fill(focusfuture);
	PersConccFrFsocsci->Fill(work+leisure+home+money+relig+death);
	workVsSocialcFrFsocsci->Fill(work,social);
	workcFrFsocsci->Fill(work);

	analyticcFrFsocsci->Fill(Analytic);
	cloutcFrFsocsci->Fill(Clout);
	authenticcFrFsocsci->Fill(Authentic);
	tonecFrFsocsci->Fill(Tone);
	homecFrFsocsci->Fill(home);
 	analyticSocSciHist->Fill(Analytic);

	socsci->Fill(nt);
	++nlines;
      }


      // cMrF analysis
      if (canGender < 0.5 && writerGender > 0.5){
	cat = 8;
	nt[0] = cat;
	nt[1] = wc;
	nt[2] = Analytic;
	nt[3] = Clout;
	nt[4] = Authentic;
	nt[5] = Tone;
	nt[6] = WPS;
	nt[7] = Dic;
	nt[8] = function;
	nt[9] = pronoun;
	nt[10] = ppron;
	nt[11] = i;
	nt[12] = we;
	nt[13] = you ;
	nt[14] = shehe;
	nt[15] = they;
	nt[16] = ipron;
	nt[17] = article;
	nt[18] = prep;
	nt[19] = auxverb;
	nt[20] = adverb;
	nt[21] = conj;
	nt[22] = negate;
	nt[23] = verb;
	nt[24] = adj;
	nt[25] = compare;
	nt[26] = interrog;
	nt[27] = number;
	nt[28] = quant;
	nt[29] = affect;
	nt[30] = posemo;
	nt[31] = negemo;
	nt[32] = anx;
	nt[33] = anger;
	nt[34] = sad ;
	nt[35] = social ;
	nt[36] = family;
	nt[37] = friends;
	nt[38] = female;
	nt[39] = male;
	nt[40] = cogproc;
	nt[41] = insight;
	nt[42] = cause;
	nt[43] = discrep;
	nt[44] = tentat;
	nt[45] = certain;
	nt[46] = differ;
	nt[47] = percept;
	nt[48] = see;
	nt[49] = hear;
	nt[50] = feel;
	nt[51] = bio;
	nt[52] = body;
	nt[53] = health;
	nt[54] = sexual;
	nt[55] = ingest;
	nt[56] = drives;
	nt[57] = affiliation;
	nt[58] = achiev;
	nt[59] = power;
	nt[60] = reward;
	nt[61] = risk;
	nt[62] = focuspast;
	nt[63] = focuspresent;
	nt[64] = focusfuture ;
	nt[65] = relativ;
	nt[66] = motion;
	nt[67] = space;
	nt[68] = time;
	nt[69] = work;
	nt[70] = leisure;
	nt[71] = home;
	nt[72] = money;
	nt[73] = relig;
	nt[74] = death;
	nt[75] = informal;
	nt[76] = swear;
	nt[77] = netspeak;
	nt[78] = assent;
	nt[79] = nonflu;
	nt[80] = filler;
	nt[81] = AllPunc;
	nt[82] = Period;
	nt[83] = Comma;
	nt[84] = Colon;
	nt[85] = SemiC;
	nt[86] = QMark;
	nt[87] = Exclam;
	nt[88] = Dash;
	nt[89] = Quote;
	nt[90] = Apostro;
	nt[91] = Parent;
	nt[92] = OtherP;
	PosemocMrFsocsci->Fill(posemo);
	NegemocMrFsocsci->Fill(negemo);
	Float_t  drivesT = achiev + power - familyRelated;
	//	drivesT = achiev;
	wordsSocScicMrF->Fill(wc);
	drivescMrFsocsci->Fill(drivesT);
	affectcMrFsocsci->Fill(affect);
	socialcMrFsocsci->Fill(social);
	cogProccMrFsocsci->Fill(cogproc);
	timeOrientPastcMrFsocsci->Fill(focuspast+focuspresent);
	timeOrientFuturecMrFsocsci->Fill(focusfuture);
	PersConccMrFsocsci->Fill(work+leisure+home+money+relig+death);
	workVsSocialcMrFsocsci->Fill(work,social);
	workcMrFsocsci->Fill(work);
	homecMrFsocsci->Fill(home);
 	analyticSocSciHist->Fill(Analytic);

	analyticcMrFsocsci->Fill(Analytic);
	cloutcMrFsocsci->Fill(Clout);
	authenticcMrFsocsci->Fill(Authentic);
	tonecMrFsocsci->Fill(Tone);

	socsci->Fill(nt);
	++nlines;
      }
    }
  }

  analysisOut << "unique Male Candidates Physics = " << uniqueMaleCandidatesPhysics << std::endl;
  analysisOut << "unique Female Candidates Physics = " << uniqueFemaleCandidatesPhysics << std::endl;
  analysisOut << "unique Male Candidates SocSci = " << uniqueMaleCandidatesSocSci << std::endl;
  analysisOut << "unique Female Candidates SocSci = " << uniqueFemaleCandidatesSocSci << std::endl;

  physics->Write();
  socsci->Write();


  wordsPhysicscMrM->Write(); 
  wordsPhysicscFrM->Write(); 
  wordsPhysicscFrF->Write(); 
  wordsPhysicscMrF->Write(); 


  wordsSocScicMrM->Write(); 
  wordsSocScicMrF->Write(); 
  wordsSocScicFrF->Write(); 
  wordsSocScicFrM->Write(); 

  workcMrMphysics->Write(); 
  workcFrMphysics->Write(); 
  workcFrMphysics->Write(); 
  workcMrFphysics->Write(); 

  workcMrMsocsci->Write(); 
  workcFrMsocsci->Write(); 
  workcFrMsocsci->Write(); 
  workcMrFsocsci->Write(); 

 
  workVsSocialcMrFsocsci->Write();
  workVsSocialcMrMsocsci->Write();
  workVsSocialcFrFsocsci->Write();
  workVsSocialcFrFsocsci->Write();
   
  drivescMrMphysics->Write(); 
  drivescMrFphysics->Write(); 
  drivescFrFphysics->Write(); 
  drivescFrMphysics->Write(); 

  drivescMrMsocsci->Write(); 
  drivescMrFsocsci->Write(); 
  drivescFrFsocsci->Write(); 
  drivescFrMsocsci->Write();


  affectcMrMphysics->Write(); 
  affectcMrFphysics->Write(); 
  affectcFrFphysics->Write(); 
  affectcFrMphysics->Write(); 

  affectcMrMsocsci->Write(); 
  affectcMrFsocsci->Write(); 
  affectcFrFsocsci->Write();
  affectcFrMsocsci->Write(); 

  socialcMrMphysics->Write(); 
  socialcMrFphysics->Write(); 
  socialcFrFphysics->Write(); 
  socialcFrMphysics->Write();
   
  socialcMrMsocsci->Write();
  socialcMrFsocsci->Write(); 
  socialcFrFsocsci->Write(); 
  socialcFrMsocsci->Write(); 

  cogProccMrMphysics->Write(); 
  cogProccMrFphysics->Write(); 
  cogProccFrFphysics->Write(); 
  cogProccFrMphysics->Write(); 

  cogProccMrMsocsci->Write(); 
  cogProccMrFsocsci->Write(); 
  cogProccFrFsocsci->Write(); 
  cogProccFrMsocsci->Write(); 

  
  timeOrientPastcMrMphysics->Write();
  timeOrientPastcMrFphysics->Write();
  timeOrientPastcFrFphysics->Write(); 
  timeOrientPastcFrMphysics->Write(); 

  timeOrientPastcMrMsocsci->Write(); 
  timeOrientPastcMrFsocsci->Write(); 
  timeOrientPastcFrFsocsci->Write(); 
  timeOrientPastcFrMsocsci->Write(); 

  timeOrientFuturecMrMphysics->Write(); 
  timeOrientFuturecMrFphysics->Write(); 
  timeOrientFuturecFrFphysics->Write(); 
  timeOrientFuturecMrFphysics->Write(); 

  timeOrientFuturecMrMsocsci->Write(); 
  timeOrientFuturecMrFsocsci->Write(); 
  timeOrientFuturecFrFsocsci->Write(); 
  timeOrientFuturecFrMsocsci->Write(); 

  analyticPhysicsHist->Write();
  analyticSocSciHist->Write();

  PersConccMrMphysics->Write(); 
  PersConccMrFphysics->Write(); 
  PersConccFrFphysics->Write(); 
  PersConccFrMphysics->Write(); 

  PersConccMrMsocsci->Write(); 
  PersConccMrFsocsci->Write(); 
  PersConccFrFsocsci->Write(); 
  PersConccFrMsocsci->Write(); 

  workcMrMphysics->Write();
  workcMrFphysics->Write();
  workcFrFphysics->Write();
  workcFrMphysics->Write();

  workcMrMsocsci->Write();
  workcMrFsocsci->Write();
  workcFrFsocsci->Write();
  workcFrMsocsci->Write();


  homecMrMphysics->Write();
  homecMrFphysics->Write();
  homecFrFphysics->Write();
  homecFrMphysics->Write();

  homecMrMsocsci->Write();
  homecMrFsocsci->Write();
  homecFrFsocsci->Write();
  homecFrMsocsci->Write();


  PosemocMrMphysics->Write();
  PosemocMrFphysics->Write();
  PosemocFrFphysics->Write();
  PosemocFrMphysics->Write();

  PosemocMrMsocsci->Write();
  PosemocMrFsocsci->Write();
  PosemocFrFsocsci->Write();
  PosemocFrMsocsci->Write();

  
  analyticcMrMsocsci->Write();
  cloutcMrMsocsci->Write();
  authenticcMrMsocsci->Write();
  tonecMrMsocsci->Write();

  analyticcMrFsocsci->Write();
  cloutcMrFsocsci->Write();
  authenticcMrFsocsci->Write();
  tonecMrFsocsci->Write();

  analyticcFrFsocsci->Write();
  cloutcFrFsocsci->Write();
  authenticcFrFsocsci->Write();
  tonecFrFsocsci->Write();

  analyticcFrMsocsci->Write();
  cloutcFrMsocsci->Write();
  authenticcFrMsocsci->Write();
  tonecFrMsocsci->Write();


  analyticcMrMphysics->Write();
  cloutcMrMphysics->Write();
  authenticcMrMphysics->Write();
  tonecMrMphysics->Write();

  analyticcMrFphysics->Write();
  cloutcMrFphysics->Write();
  authenticcMrFphysics->Write();
  tonecMrFphysics->Write();

  analyticcFrFphysics->Write();
  cloutcFrFphysics->Write();
  authenticcFrFphysics->Write();
  tonecFrFphysics->Write();

  analyticcFrMphysics->Write();
  cloutcFrMphysics->Write();
  authenticcFrMphysics->Write();
  tonecFrMphysics->Write();

  gStyle->SetOptFit(1);

  /* printouts*/



  
  analysisOut << "Posemo" << std::endl;
 analysisOut <<    static_cast<Float_t>(PosemocMrMphysics->GetMean()) << " " << 
    static_cast<Float_t>(PosemocFrMphysics->GetMean()) << " " << 
    static_cast<Float_t>(PosemocFrFphysics->GetMean()) << " " <<
    static_cast<Float_t>(PosemocMrFphysics->GetMean()) << " " << std::endl;


				      
  analysisOut <<    static_cast<Float_t>(PosemocMrMphysics->GetMeanError()) << " " << 
    static_cast<Float_t>(PosemocFrMphysics->GetMeanError()) << " " << 
    static_cast<Float_t>(PosemocFrFphysics->GetMeanError()) << " " <<
    static_cast<Float_t>(PosemocMrFphysics->GetMeanError()) << " " << std::endl;



  analysisOut <<    static_cast<Float_t>(PosemocMrMsocsci->GetMean()) << " " << 
    static_cast<Float_t>(PosemocFrMsocsci->GetMean()) << " " << 
    static_cast<Float_t>(PosemocFrFsocsci->GetMean()) << " " <<
    static_cast<Float_t>(PosemocMrFsocsci->GetMean()) << " " << std::endl;

   
  analysisOut <<    static_cast<Float_t>(PosemocMrMsocsci->GetMeanError()) << " " << 
    static_cast<Float_t>(PosemocFrMsocsci->GetMeanError()) << " " << 
    static_cast<Float_t>(PosemocFrFsocsci->GetMeanError()) << " " <<
    static_cast<Float_t>(PosemocMrFsocsci->GetMeanError()) << " " << std::endl;


  

  
  analysisOut << "Negemo" << std::endl;
 analysisOut <<    static_cast<Float_t>(NegemocMrMphysics->GetMean()) << " " << 
    static_cast<Float_t>(NegemocFrMphysics->GetMean()) << " " << 
    static_cast<Float_t>(NegemocFrFphysics->GetMean()) << " " <<
    static_cast<Float_t>(NegemocMrFphysics->GetMean()) << " " << std::endl;


				      
  analysisOut <<    static_cast<Float_t>(NegemocMrMphysics->GetMeanError()) << " " << 
    static_cast<Float_t>(NegemocFrMphysics->GetMeanError()) << " " << 
    static_cast<Float_t>(NegemocFrFphysics->GetMeanError()) << " " <<
    static_cast<Float_t>(NegemocMrFphysics->GetMeanError()) << " " << std::endl;



  analysisOut <<    static_cast<Float_t>(NegemocMrMsocsci->GetMean()) << " " << 
    static_cast<Float_t>(NegemocFrMsocsci->GetMean()) << " " << 
    static_cast<Float_t>(NegemocFrFsocsci->GetMean()) << " " <<
    static_cast<Float_t>(NegemocMrFsocsci->GetMean()) << " " << std::endl;

   
  analysisOut <<    static_cast<Float_t>(NegemocMrMsocsci->GetMeanError()) << " " << 
    static_cast<Float_t>(NegemocFrMsocsci->GetMeanError()) << " " << 
    static_cast<Float_t>(NegemocFrFsocsci->GetMeanError()) << " " <<
    static_cast<Float_t>(NegemocMrFsocsci->GetMeanError()) << " " << std::endl;


 analysisOut << "Drives" << std::endl;
 analysisOut <<    static_cast<Float_t>(drivescMrMphysics->GetMean()) << " " << 
    static_cast<Float_t>(drivescFrMphysics->GetMean()) << " " << 
    static_cast<Float_t>(drivescFrFphysics->GetMean()) << " " <<
    static_cast<Float_t>(drivescMrFphysics->GetMean()) << " " << std::endl;


				      
  analysisOut <<    static_cast<Float_t>(drivescMrMphysics->GetMeanError()) << " " << 
    static_cast<Float_t>(drivescFrMphysics->GetMeanError()) << " " << 
    static_cast<Float_t>(drivescFrFphysics->GetMeanError()) << " " <<
    static_cast<Float_t>(drivescMrFphysics->GetMeanError()) << " " << std::endl;



  analysisOut <<    static_cast<Float_t>(drivescMrMsocsci->GetMean()) << " " << 
    static_cast<Float_t>(drivescFrMsocsci->GetMean()) << " " << 
    static_cast<Float_t>(drivescFrFsocsci->GetMean()) << " " <<
    static_cast<Float_t>(drivescMrFsocsci->GetMean()) << " " << std::endl;

   
  analysisOut <<    static_cast<Float_t>(drivescMrMsocsci->GetMeanError()) << " " << 
    static_cast<Float_t>(drivescFrMsocsci->GetMeanError()) << " " << 
    static_cast<Float_t>(drivescFrFsocsci->GetMeanError()) << " " <<
    static_cast<Float_t>(drivescMrFsocsci->GetMeanError()) << " " << std::endl;

  Double_t quantileVal;
  Double_t quantile = 0.5;

 
  /*endprintouts*/
  TCanvas* c1 = new TCanvas();
  c1->Divide(2,1);
  c1->cd(2);
  TF1* fitDrives = new TF1("fits","[0]",0.,10.);
  fitDrives->SetParNames("average");

  Float_t x1[4] = {1.,2.,3.,4.};
  Float_t y1[4] = {
    static_cast<Float_t>(getMedian(drivescMrMphysics,quantileVal,quantile)),
    static_cast<Float_t>(getMedian(drivescFrMphysics,quantileVal,quantile)),
    static_cast<Float_t>(getMedian(drivescMrFphysics,quantileVal,quantile)),
    static_cast<Float_t>(getMedian(drivescFrFphysics,quantileVal,quantile))
  };
  Float_t ex1[4] = {0.1,0.1,0.1,0.1};
  Float_t ey1[4] = {
    static_cast<Float_t>(drivescMrMphysics->GetMeanError()),
    static_cast<Float_t>(drivescFrMphysics->GetMeanError()),
    static_cast<Float_t>(drivescMrFphysics->GetMeanError()),
    static_cast<Float_t>(drivescFrFphysics->GetMeanError())
  };
 
  TGraphErrors* drivesPhysics = new TGraphErrors(4,x1,y1,ex1,ey1);


  drivesPhysics->SetMaximum(10.0);
  drivesPhysics->SetMinimum(5.0);

  drivesPhysics->SetTitle("    EPP Drives: Median achievement + power    ");
  TFitResultPtr fitDrivesPhysics = drivesPhysics->Fit("fits","S");
  Double_t   parDrivesPhysics = fitDrivesPhysics->Value(0);
  Double_t  errDrivesPhysics = fitDrivesPhysics->ParError(0);
  TAxis* yAxisDrivesPhysics = drivesPhysics->GetYaxis();
  yAxisDrivesPhysics->SetTitle("% of Words");
  TAxis* xaxisDrivesPhysics= drivesPhysics->GetXaxis();
  xaxisDrivesPhysics->SetTickLength(0.);
  //  xaxisDrivesPhysics->CenterTitle(kTRUE);
  //xaxisDrivesPhysics->SetTitle("#splitline{male writers                          female writers}{male candidate female candidate      }");
  xaxisDrivesPhysics->ChangeLabel(1,-1.,-1.,-1,-1,-1,"#splitline{cand. M}{writer M}");
  xaxisDrivesPhysics->ChangeLabel(3,-1.,-1.,-1,-1,-1,"#splitline{cand. F}{writer M}");
  xaxisDrivesPhysics->ChangeLabel(5,-1.,-1.,-1,-1,-1,"#splitline{cand. M}{writer F}");
  xaxisDrivesPhysics->ChangeLabel(7,-1.,-1.,-1,-1,-1,"#splitline{cand. F}{writer F}");
  xaxisDrivesPhysics->ChangeLabel(2,-1.,0.);
  xaxisDrivesPhysics->ChangeLabel(4,-1.,0.);
  xaxisDrivesPhysics->ChangeLabel(6,-1.,0.);
  xaxisDrivesPhysics->ChangeLabel(1,-1.,-1.,-1,-1,-1," ");
  xaxisDrivesPhysics->ChangeLabel(3,-1.,-1.,-1,-1,-1," ");
  xaxisDrivesPhysics->ChangeLabel(5,-1.,-1.,-1,-1,-1," ");
  xaxisDrivesPhysics->ChangeLabel(7,-1.,-1.,-1,-1,-1," ");
  xaxisDrivesPhysics->ChangeLabel(2,-1.,0.);
  xaxisDrivesPhysics->ChangeLabel(4,-1.,0.);
  xaxisDrivesPhysics->ChangeLabel(6,-1.,0.);
 
  drivesPhysics->SetFillColor(38);
  drivesPhysics->Draw("AB");
  TBox* boxDrivesPhysics = new TBox(0.6,parDrivesPhysics-errDrivesPhysics,4.4,parDrivesPhysics+errDrivesPhysics);
  boxDrivesPhysics->SetFillColor(kBlue);
  boxDrivesPhysics->SetFillStyle(3004);
  drivesPhysics->SetMaximum(parDrivesPhysics+5.*drivescFrFphysics->GetMeanError());
  drivesPhysics->SetMinimum(TMath::Max(parDrivesPhysics-5.*drivescFrFphysics->GetMeanError(),0.));
  boxDrivesPhysics->Draw();

  drivesPhysics->Write();

  //
  // TCanvas* c2 = new TCanvas();
  c1->cd(1);
  TF1* fitDrivesSocSci = new TF1("fits","[0]",0.,10.);
  fitDrivesSocSci->SetParNames("average");

  Float_t x2[4] = {1.,2.,3.,4.};
  // make measured adjustment for family words.
  Float_t y2[4] = {
    static_cast<Float_t>(getMedian(drivescMrMsocsci,quantileVal,quantile)),
    static_cast<Float_t>(getMedian(drivescFrMsocsci,quantileVal,quantile)),
    static_cast<Float_t>(getMedian(drivescMrFsocsci,quantileVal,quantile)),
    static_cast<Float_t>(getMedian(drivescFrFsocsci,quantileVal,quantile))
  };
 
  Float_t ex2[4] = {0.1,0.1,0.1,0.1};
  Float_t ey2[4] = {
    static_cast<Float_t>(drivescMrMsocsci->GetMeanError()),
    static_cast<Float_t>(drivescFrMsocsci->GetMeanError()),
    static_cast<Float_t>(drivescMrFsocsci->GetMeanError()),
    static_cast<Float_t>(drivescFrFsocsci->GetMeanError())
  };
 
  TGraphErrors* drivesSocsci = new TGraphErrors(4,x2,y2,ex2,ey2);


  drivesSocsci->SetMaximum(10.0);
  drivesSocsci->SetMinimum(5.0);

  drivesSocsci->SetTitle("Social Science Drives: Median achievement + power");
  TFitResultPtr fitDrivesSocsci = drivesSocsci->Fit("fits","S");
  Double_t   parDrivesSocsci = fitDrivesSocsci->Value(0);
  Double_t  errDrivesSocsci = fitDrivesSocsci->ParError(0);
  TAxis* xaxisDrivesSocsci= drivesSocsci->GetXaxis();
  TAxis* yaxisDrivesSocsci = drivesSocsci->GetYaxis();
  yaxisDrivesSocsci->SetTitle("% of Words");
  xaxisDrivesSocsci->SetTickLength(0.);
  xaxisDrivesSocsci->ChangeLabel(1,-1.,-1.,-1,-1,-1,"#splitline{cand. M}{writer M}");
  xaxisDrivesSocsci->ChangeLabel(3,-1.,-1.,-1,-1,-1,"#splitline{cand. F}{writer M}");
  xaxisDrivesSocsci->ChangeLabel(5,-1.,-1.,-1,-1,-1,"#splitline{cand. M}{writer F}");
  xaxisDrivesSocsci->ChangeLabel(7,-1.,-1.,-1,-1,-1,"#splitline{cand. F}{writer F}");
  /* made uniform with STATA up to here 2/15/2020 8:52 AM*/ 
  xaxisDrivesSocsci->ChangeLabel(2,-1.,0.);
  xaxisDrivesSocsci->ChangeLabel(4,-1.,0.);
  xaxisDrivesSocsci->ChangeLabel(6,-1.,0.);
  drivesSocsci->SetFillColor(38);

  drivesSocsci->Draw("AB");
  TBox* boxDrivesSocsci = new TBox(0.6,parDrivesSocsci-errDrivesSocsci,4.4,parDrivesSocsci+errDrivesSocsci);
  boxDrivesSocsci->SetFillColor(kBlue);
  boxDrivesSocsci->SetFillStyle(3004);
  drivesSocsci->SetMaximum(parDrivesSocsci+8.*drivescFrFsocsci->GetMeanError());
  drivesSocsci->SetMinimum(TMath::Max(parDrivesSocsci-8.*drivescFrFsocsci->GetMeanError(),0.));
 
  boxDrivesSocsci->Draw();

  drivesSocsci->Write();

 
  if (useBoth){
    c1->SaveAs("pdfPlotsLIWCBoth/socsciDrives.pdf");
  }else{c1->SaveAs("pdfPlotsLIWC/socsciDrives.pdf");}



  // 2nd plot family; affect or posemo 

  
  TCanvas* c3 = new TCanvas();
  TF1* fitAffect = new TF1("fits","[0]",0.,10.);
  fitAffect->SetParNames("average");

  Float_t x3[4] = {1.,2.,3.,4.};
  Float_t y3[4] = {
    static_cast<Float_t>(getMedian(affectcMrMphysics,quantileVal,quantile)),
    static_cast<Float_t>(getMedian(affectcFrMphysics,quantileVal,quantile)),
    static_cast<Float_t>(getMedian(affectcMrFphysics,quantileVal,quantile)),
    static_cast<Float_t>(getMedian(affectcFrFphysics,quantileVal,quantile))
  };
  Float_t ex3[4] = {0.1,0.1,0.1,0.1};
  Float_t ey3[4] = {
    static_cast<Float_t>(affectcMrMphysics->GetMeanError()),
    static_cast<Float_t>(affectcFrMphysics->GetMeanError()),
    static_cast<Float_t>(affectcMrFphysics->GetMeanError()),
    static_cast<Float_t>(affectcFrFphysics->GetMeanError())
  };
 
  TGraphErrors* affectPhysics = new TGraphErrors(4,x3,y3,ex3,ey3);



  affectPhysics->SetTitle("Physics LIWC Affect");
  TFitResultPtr fitAffectPhysics = affectPhysics->Fit("fits","S");
  Double_t   parAffectPhysics = fitAffectPhysics->Value(0);
  Double_t  errAffectPhysics = fitAffectPhysics->ParError(0);
  TAxis* xaxisAffectPhysics= affectPhysics->GetXaxis();
  xaxisAffectPhysics->SetTickLength(0.);
  xaxisAffectPhysics->ChangeLabel(1,-1.,-1.,-1,-1,-1,"cMrM");
  xaxisAffectPhysics->ChangeLabel(3,-1.,-1.,-1,-1,-1,"cFrM");
  xaxisAffectPhysics->ChangeLabel(5,-1.,-1.,-1,-1,-1,"cMrF");
  xaxisAffectPhysics->ChangeLabel(7,-1.,-1.,-1,-1,-1,"cFrF");
  xaxisAffectPhysics->ChangeLabel(2,-1.,0.);
  xaxisAffectPhysics->ChangeLabel(4,-1.,0.);
  xaxisAffectPhysics->ChangeLabel(6,-1.,0.);
  affectPhysics->Draw("A*");
  TBox* boxAffectPhysics = new TBox(0.6,parAffectPhysics-errAffectPhysics,4.4,parAffectPhysics+errAffectPhysics);
  affectPhysics->SetMaximum(parAffectPhysics + 5.*affectcFrFphysics->GetMeanError());
  affectPhysics->SetMinimum(TMath::Max(parAffectPhysics - 5.*affectcFrFphysics->GetMeanError(),0.));

  boxAffectPhysics->SetFillColor(kBlue);
  boxAffectPhysics->SetFillStyle(3004);
  boxAffectPhysics->Draw();

  affectPhysics->Write();
  c3->SaveAs("pdfPlotsLIWC/physicsAffect.pdf");
  //
  TCanvas* c4 = new TCanvas();
  TF1* fitAffectSocSci = new TF1("fits","[0]",0.,10.);
  fitAffectSocSci->SetParNames("average");

  Float_t x4[4] = {1.,2.,3.,4.};
  Float_t y4[4] = {
    static_cast<Float_t>(getMedian(affectcMrMsocsci,quantileVal,quantile)),
    static_cast<Float_t>(getMedian(affectcFrMsocsci,quantileVal,quantile)),
    static_cast<Float_t>(getMedian(affectcMrFsocsci,quantileVal,quantile)),
    static_cast<Float_t>(getMedian(affectcFrFsocsci,quantileVal,quantile))
  };
  Float_t ex4[4] = {0.1,0.1,0.1,0.1};
  Float_t ey4[4] = {
    static_cast<Float_t>(affectcMrMsocsci->GetMeanError()),
    static_cast<Float_t>(affectcFrMsocsci->GetMeanError()),
    static_cast<Float_t>(affectcMrFsocsci->GetMeanError()),
    static_cast<Float_t>(affectcFrFsocsci->GetMeanError())
  };
 
  TGraphErrors* affectSocsci = new TGraphErrors(4,x4,y4,ex4,ey4);


  affectSocsci->SetMaximum(6.0);
  affectSocsci->SetMinimum(3.0);

  affectSocsci->SetTitle("SocSci LIWC Affect");
  TFitResultPtr fitAffectSocsci = affectSocsci->Fit("fits","S");
  Double_t   parAffectSocsci = fitAffectSocsci->Value(0);
  Double_t  errAffectSocsci = fitAffectSocsci->ParError(0);
  TAxis* xaxisAffectSocsci= affectSocsci->GetXaxis();
  xaxisAffectSocsci->SetTickLength(0.);
  xaxisAffectSocsci->ChangeLabel(1,-1.,-1.,-1,-1,-1,"cMrM");
  xaxisAffectSocsci->ChangeLabel(3,-1.,-1.,-1,-1,-1,"cFrM");
  xaxisAffectSocsci->ChangeLabel(5,-1.,-1.,-1,-1,-1,"cMrF");
  xaxisAffectSocsci->ChangeLabel(7,-1.,-1.,-1,-1,-1,"cFrF");
  xaxisAffectSocsci->ChangeLabel(2,-1.,0.);
  xaxisAffectSocsci->ChangeLabel(4,-1.,0.);
  xaxisAffectSocsci->ChangeLabel(6,-1.,0.);
  affectSocsci->Draw("A*");
  TBox* boxAffectSocsci = new TBox(0.6,parAffectSocsci-errAffectSocsci,4.4,parAffectSocsci+errAffectSocsci);
  boxAffectSocsci->SetFillColor(kBlue);
  boxAffectSocsci->SetFillStyle(3004);
  affectSocsci->SetMaximum(parAffectSocsci + 5.*affectcFrFsocsci->GetMeanError());
  affectSocsci->SetMinimum(TMath::Max(parAffectSocsci - 5.*affectcFrFsocsci->GetMeanError(),0.));

  boxAffectSocsci->Draw();

  affectSocsci->Write();
  if (useBoth){
    c4->SaveAs("pdfPlotsLIWCBoth/socsciAffect.pdf");
  }else
    { c4->SaveAs("pdfPlotsLIWCBoth/socsciAffect.pdf");}

  //3rd plot family: social
  
  TCanvas* c5 = new TCanvas();
  TF1* fitSocial = new TF1("fits","[0]",0.,10.);
  fitSocial->SetParNames("average");

  Float_t x5[4] = {1.,2.,3.,4.};
  Float_t y5[4] = {
    static_cast<Float_t>(getMedian(socialcMrMphysics,quantileVal,quantile)),
    static_cast<Float_t>(getMedian(socialcFrMphysics,quantileVal,quantile)),
    static_cast<Float_t>(getMedian(socialcMrFphysics,quantileVal,quantile)),
    static_cast<Float_t>(getMedian(socialcFrFphysics,quantileVal,quantile))
  };
  Float_t ex5[4] = {0.1,0.1,0.1,0.1};
  Float_t ey5[4] = {
    static_cast<Float_t>(socialcMrMphysics->GetMeanError()),
    static_cast<Float_t>(socialcFrMphysics->GetMeanError()),
    static_cast<Float_t>(socialcMrFphysics->GetMeanError()),
    static_cast<Float_t>(socialcFrFphysics->GetMeanError())
  };
 
  TGraphErrors* socialPhysics = new TGraphErrors(4,x5,y5,ex5,ey5);


  socialPhysics->SetMaximum(9.);
  socialPhysics->SetMinimum(5.);

  socialPhysics->SetTitle("Physics LIWC Social");
  TFitResultPtr fitSocialPhysics = socialPhysics->Fit("fits","S");
  Double_t   parSocialPhysics = fitSocialPhysics->Value(0);
  Double_t  errSocialPhysics = fitSocialPhysics->ParError(0);
  TAxis* xaxisSocialPhysics= socialPhysics->GetXaxis();
  xaxisSocialPhysics->SetTickLength(0.);
  xaxisSocialPhysics->ChangeLabel(1,-1.,-1.,-1,-1,-1,"cMrM");
  xaxisSocialPhysics->ChangeLabel(3,-1.,-1.,-1,-1,-1,"cFrM");
  xaxisSocialPhysics->ChangeLabel(5,-1.,-1.,-1,-1,-1,"cMrF");
  xaxisSocialPhysics->ChangeLabel(6,-1.,-1.,-1,-1,-1,"cFrF");
  xaxisSocialPhysics->ChangeLabel(2,-1.,0.);
  xaxisSocialPhysics->ChangeLabel(4,-1.,0.);
  xaxisSocialPhysics->ChangeLabel(6,-1.,0.);
  socialPhysics->Draw("A*");
  TBox* boxSocialPhysics = new TBox(0.6,parSocialPhysics-errSocialPhysics,4.4,parSocialPhysics+errSocialPhysics);
  boxSocialPhysics->SetFillColor(kBlue);
  boxSocialPhysics->SetFillStyle(3004);
  socialPhysics->SetMaximum(parSocialPhysics + 5.*socialcFrFphysics->GetMeanError());
  socialPhysics->SetMinimum(TMath::Max(parSocialPhysics - 5.*socialcFrFphysics->GetMeanError(),0.));

  boxSocialPhysics->Draw();

  socialPhysics->Write();
  if (useBoth){
    c5->SaveAs("pdfPlotsLIWCBoth/physicsSocial.pdf");
  }else {c5->SaveAs("pdfPlotsLIWCBoth/physicsSocial.pdf");}
  //
  TCanvas* c6 = new TCanvas();
  TF1* fitSocialSocSci = new TF1("fits","[0]",0.,10.);
  fitSocialSocSci->SetParNames("average");

  Float_t x6[4] = {1.,2.,3.,4.};
  Float_t y6[4] = {
    static_cast<Float_t>(getMedian(socialcMrMsocsci,quantileVal,quantile)),
    static_cast<Float_t>(getMedian(socialcFrMsocsci,quantileVal,quantile)),
    static_cast<Float_t>(getMedian(socialcMrFsocsci,quantileVal,quantile)),
    static_cast<Float_t>(getMedian(socialcFrFsocsci,quantileVal,quantile))
  };
  Float_t ex6[4] = {0.1,0.1,0.1,0.1};
  Float_t ey6[4] = {
    static_cast<Float_t>(socialcMrMsocsci->GetMeanError()),
    static_cast<Float_t>(socialcFrMsocsci->GetMeanError()),
    static_cast<Float_t>(socialcMrFsocsci->GetMeanError()),
    static_cast<Float_t>(socialcFrFsocsci->GetMeanError())
  };
 
  TGraphErrors* socialSocsci = new TGraphErrors(4,x6,y6,ex6,ey6);


  socialSocsci->SetMaximum(13.);
  socialSocsci->SetMinimum(7.);

  socialSocsci->SetTitle("SocSci LIWC Social");
  TFitResultPtr fitSocialSocsci = socialSocsci->Fit("fits","S");
  Double_t   parSocialSocsci = fitSocialSocsci->Value(0);
  Double_t  errSocialSocsci = fitSocialSocsci->ParError(0);
  TAxis* xaxisSocialSocsci= socialSocsci->GetXaxis();
  xaxisSocialSocsci->SetTickLength(0.);
  xaxisSocialSocsci->ChangeLabel(1,-1.,-1.,-1,-1,-1,"cMrM");
  xaxisSocialSocsci->ChangeLabel(3,-1.,-1.,-1,-1,-1,"cFrM");
  xaxisSocialSocsci->ChangeLabel(5,-1.,-1.,-1,-1,-1,"cMrF");
  xaxisSocialSocsci->ChangeLabel(7,-1.,-1.,-1,-1,-1,"cFrF");
  xaxisSocialSocsci->ChangeLabel(2,-1.,0.);
  xaxisSocialSocsci->ChangeLabel(4,-1.,0.);
  xaxisSocialSocsci->ChangeLabel(6,-1.,0.);
  socialSocsci->Draw("A*");
  TBox* boxSocialSocsci = new TBox(0.6,parSocialSocsci-errSocialSocsci,4.4,parSocialSocsci+errSocialSocsci);
  boxSocialSocsci->SetFillColor(kBlue);
  boxSocialSocsci->SetFillStyle(3004);
  socialSocsci->SetMaximum(parSocialSocsci + 20.*socialcFrFsocsci->GetMeanError());
  socialSocsci->SetMinimum(TMath::Max(parSocialSocsci - 20.*socialcFrFsocsci->GetMeanError(),0.));

  boxSocialSocsci->Draw();

  socialSocsci->Write();
  if (useBoth){
    c6->SaveAs("pdfPlotsLIWCBoth/socsciSocial.pdf");
  }else {c6->SaveAs("pdfPlotsLIWC/socsciSocial.pdf");}

  //4th plot family: future time

    
  TCanvas* c7 = new TCanvas();
  TF1* fittimeOrientFuture = new TF1("fits","[0]",0.,10.);
  fittimeOrientFuture->SetParNames("average");

  Float_t x7[4] = {1.,2.,3.,4.};
  Float_t y7[4] = {
    static_cast<Float_t>(getMedian(timeOrientFuturecMrMphysics,quantileVal,quantile)),
    static_cast<Float_t>(getMedian(timeOrientFuturecFrMphysics,quantileVal,quantile)),
    static_cast<Float_t>(getMedian(timeOrientFuturecMrFphysics,quantileVal,quantile)),
    static_cast<Float_t>(getMedian(timeOrientFuturecFrFphysics,quantileVal,quantile))
  };
  Float_t ex7[4] = {0.1,0.1,0.1,0.1};
  Float_t ey7[4] = {
    static_cast<Float_t>(timeOrientFuturecMrMphysics->GetMeanError()),
    static_cast<Float_t>(timeOrientFuturecFrMphysics->GetMeanError()),
    static_cast<Float_t>(timeOrientFuturecMrFphysics->GetMeanError()),
    static_cast<Float_t>(timeOrientFuturecFrFphysics->GetMeanError())
  };
 
  TGraphErrors* timeOrientFuturePhysics = new TGraphErrors(4,x7,y7,ex7,ey7);


  timeOrientFuturePhysics->SetMaximum(1.5);
  timeOrientFuturePhysics->SetMinimum(0.5);

  timeOrientFuturePhysics->SetTitle("Physics LIWC timeOrientFuture");
  TFitResultPtr fittimeOrientFuturePhysics = timeOrientFuturePhysics->Fit("fits","S");
  Double_t   partimeOrientFuturePhysics = fittimeOrientFuturePhysics->Value(0);
  Double_t  errtimeOrientFuturePhysics = fittimeOrientFuturePhysics->ParError(0);
  TAxis* xaxistimeOrientFuturePhysics= timeOrientFuturePhysics->GetXaxis();
  xaxistimeOrientFuturePhysics->SetTickLength(0.);
  xaxistimeOrientFuturePhysics->ChangeLabel(1,-1.,-1.,-1,-1,-1,"cMrM");
  xaxistimeOrientFuturePhysics->ChangeLabel(3,-1.,-1.,-1,-1,-1,"cFrM");
  xaxistimeOrientFuturePhysics->ChangeLabel(5,-1.,-1.,-1,-1,-1,"cMrF");
  xaxistimeOrientFuturePhysics->ChangeLabel(7,-1.,-1.,-1,-1,-1,"cFrF");
  xaxistimeOrientFuturePhysics->ChangeLabel(2,-1.,0.);
  xaxistimeOrientFuturePhysics->ChangeLabel(4,-1.,0.);
  xaxistimeOrientFuturePhysics->ChangeLabel(6,-1.,0.);
  timeOrientFuturePhysics->SetMaximum(partimeOrientFuturePhysics + 5.*timeOrientFuturecFrFphysics->GetMeanError());
  timeOrientFuturePhysics->SetMinimum(TMath::Max(partimeOrientFuturePhysics - 5.*timeOrientFuturecFrFphysics->GetMeanError(),0.));

  timeOrientFuturePhysics->Draw("A*");
  TBox* boxtimeOrientFuturePhysics = new TBox(0.6,partimeOrientFuturePhysics-errtimeOrientFuturePhysics,4.4,partimeOrientFuturePhysics+errtimeOrientFuturePhysics);
  boxtimeOrientFuturePhysics->SetFillColor(kBlue);
  boxtimeOrientFuturePhysics->SetFillStyle(3004);

  boxtimeOrientFuturePhysics->Draw();

  timeOrientFuturePhysics->Write();
  if (useBoth){
    c7->SaveAs("pdfPlotsLIWCBoth/physicsFuture.pdf");
  } else {c7->SaveAs("pdfPlotsLIWC/physicsFuture.pdf");}
  //
  TCanvas* c8 = new TCanvas();
  TF1* fittimeOrientFutureSocSci = new TF1("fits","[0]",0.,10.);
  fittimeOrientFutureSocSci->SetParNames("average");

  Float_t x8[4] = {1.,2.,3.,4.};
  Float_t y8[4] = {
    static_cast<Float_t>(getMedian(timeOrientFuturecMrMsocsci,quantileVal,quantile)),
    static_cast<Float_t>(getMedian(timeOrientFuturecFrMsocsci,quantileVal,quantile)),
    static_cast<Float_t>(getMedian(timeOrientFuturecMrFsocsci,quantileVal,quantile)),
    static_cast<Float_t>(getMedian(timeOrientFuturecFrFsocsci,quantileVal,quantile))
  };
  Float_t ex8[4] = {0.1,0.1,0.1,0.1};
  Float_t ey8[4] = {
    static_cast<Float_t>(timeOrientFuturecMrMsocsci->GetMeanError()),
    static_cast<Float_t>(timeOrientFuturecFrMsocsci->GetMeanError()),
    static_cast<Float_t>(timeOrientFuturecMrFsocsci->GetMeanError()),
    static_cast<Float_t>(timeOrientFuturecFrFsocsci->GetMeanError())
  };
 
  TGraphErrors* timeOrientFutureSocsci = new TGraphErrors(4,x8,y8,ex8,ey8);


  timeOrientFutureSocsci->SetMaximum(1.5);
  timeOrientFutureSocsci->SetMinimum(0.5);

  timeOrientFutureSocsci->SetTitle("SocSci LIWC timeOrientFuture");
  TFitResultPtr fittimeOrientFutureSocsci = timeOrientFutureSocsci->Fit("fits","S");
  Double_t   partimeOrientFutureSocsci = fittimeOrientFutureSocsci->Value(0);
  Double_t  errtimeOrientFutureSocsci = fittimeOrientFutureSocsci->ParError(0);
  TAxis* xaxistimeOrientFutureSocsci= timeOrientFutureSocsci->GetXaxis();
  xaxistimeOrientFutureSocsci->SetTickLength(0.);
  xaxistimeOrientFutureSocsci->ChangeLabel(1,-1.,-1.,-1,-1,-1,"cMrM");
  xaxistimeOrientFutureSocsci->ChangeLabel(3,-1.,-1.,-1,-1,-1,"cFrM");
  xaxistimeOrientFutureSocsci->ChangeLabel(5,-1.,-1.,-1,-1,-1,"cMrF");
  xaxistimeOrientFutureSocsci->ChangeLabel(7,-1.,-1.,-1,-1,-1,"cFrF");
  xaxistimeOrientFutureSocsci->ChangeLabel(2,-1.,0.);
  xaxistimeOrientFutureSocsci->ChangeLabel(4,-1.,0.);
  xaxistimeOrientFutureSocsci->ChangeLabel(6,-1.,0.);
  timeOrientFutureSocsci->SetMaximum(partimeOrientFutureSocsci + 5.*timeOrientFuturecFrFsocsci->GetMeanError());
  timeOrientFutureSocsci->SetMinimum(TMath::Max(partimeOrientFutureSocsci - 5.*timeOrientFuturecFrFsocsci->GetMeanError(),0.));

  timeOrientFutureSocsci->Draw("A*");
  TBox* boxtimeOrientFutureSocsci = new TBox(0.6,partimeOrientFutureSocsci-errtimeOrientFutureSocsci,4.4,partimeOrientFutureSocsci+errtimeOrientFutureSocsci);
  boxtimeOrientFutureSocsci->SetFillColor(kBlue);
  boxtimeOrientFutureSocsci->SetFillStyle(3004);
  boxtimeOrientFutureSocsci->Draw();

  timeOrientFutureSocsci->Write();
  if (useBoth){
    c8->SaveAs("pdfPlotsLIWCBoth/socsciFuture.pdf");
  }else{ c8->SaveAs("pdfPlotsLIWCBoth/socsciFuture.pdf");}
  

  // 5th category work



    
  TCanvas* c9 = new TCanvas();
  TF1* fitwork = new TF1("fits","[0]",0.,10.);
  fitwork->SetParNames("average");

  Float_t x9[4] = {1.,2.,3.,4.};
  Float_t y9[4] = {
    static_cast<Float_t>(getMedian(workcMrMphysics,quantileVal,quantile)),
    static_cast<Float_t>(getMedian(workcFrMphysics,quantileVal,quantile)),
    static_cast<Float_t>(getMedian(workcMrFphysics,quantileVal,quantile)),
    static_cast<Float_t>(getMedian(workcFrFphysics,quantileVal,quantile))
  };
  Float_t ex9[4] = {0.1,0.1,0.1,0.1};
  Float_t ey9[4] = {
    static_cast<Float_t>(workcMrMphysics->GetMeanError()),
    static_cast<Float_t>(workcFrMphysics->GetMeanError()),
    static_cast<Float_t>(workcMrFphysics->GetMeanError()),
    static_cast<Float_t>(workcFrFphysics->GetMeanError())
  };
 
  TGraphErrors* workPhysics = new TGraphErrors(4,x9,y9,ex9,ey9);


  workPhysics->SetMaximum(15.);
  workPhysics->SetMinimum(5.);

  workPhysics->SetTitle("Physics LIWC work");
  TFitResultPtr fitworkPhysics = workPhysics->Fit("fits","S");
  Double_t   parworkPhysics = fitworkPhysics->Value(0);
  Double_t  errworkPhysics = fitworkPhysics->ParError(0);
  TAxis* xaxisworkPhysics= workPhysics->GetXaxis();
  xaxisworkPhysics->SetTickLength(0.);
  xaxisworkPhysics->ChangeLabel(1,-1.,-1.,-1,-1,-1,"cMrM");
  xaxisworkPhysics->ChangeLabel(3,-1.,-1.,-1,-1,-1,"cFrM");
  xaxisworkPhysics->ChangeLabel(5,-1.,-1.,-1,-1,-1,"cMrF");
  xaxisworkPhysics->ChangeLabel(7,-1.,-1.,-1,-1,-1,"cFrF");
  xaxisworkPhysics->ChangeLabel(2,-1.,0.);
  xaxisworkPhysics->ChangeLabel(4,-1.,0.);
  xaxisworkPhysics->ChangeLabel(6,-1.,0.);
  workPhysics->SetMaximum(parworkPhysics + 5.*workcFrFphysics->GetMeanError());
  workPhysics->SetMinimum(TMath::Max(parworkPhysics - 5.*workcFrFphysics->GetMeanError(),0.));

  workPhysics->Draw("A*");
  TBox* boxworkPhysics = new TBox(0.6,parworkPhysics-errworkPhysics,4.4,parworkPhysics+errworkPhysics);
  boxworkPhysics->SetFillColor(kBlue);
  boxworkPhysics->SetFillStyle(3004);
  boxworkPhysics->Draw();

  workPhysics->Write();
  if (useBoth){
    c9->SaveAs("pdfPlotsLIWCBoth/physicsWork.pdf");
  }else { c9->SaveAs("pdfPlotsLIWC/physicsWork.pdf");}
  //
  TCanvas* c10 = new TCanvas();
  TF1* fitworkSocSci = new TF1("fits","[0]",0.,10.);
  fitworkSocSci->SetParNames("average");

  Float_t x10[4] = {1.,2.,3.,4.};
  Float_t y10[4] = {
    static_cast<Float_t>(getMedian(workcMrMsocsci,quantileVal,quantile)),
    static_cast<Float_t>(getMedian(workcFrMsocsci,quantileVal,quantile)),
    static_cast<Float_t>(getMedian(workcMrFsocsci,quantileVal,quantile)),
    static_cast<Float_t>(getMedian(workcFrFsocsci,quantileVal,quantile))
  };
  Float_t ex10[4] = {0.1,0.1,0.1,0.1};
  Float_t ey10[4] = {
    static_cast<Float_t>(workcMrMsocsci->GetMeanError()),
    static_cast<Float_t>(workcFrMsocsci->GetMeanError()),
    static_cast<Float_t>(workcMrFsocsci->GetMeanError()),
    static_cast<Float_t>(workcFrFsocsci->GetMeanError())
  };
 
  TGraphErrors* workSocsci = new TGraphErrors(4,x10,y10,ex10,ey10);


  workSocsci->SetMaximum(15.);
  workSocsci->SetMinimum(5.);

  workSocsci->SetTitle("SocSci LIWC work");
  TFitResultPtr fitworkSocsci = workSocsci->Fit("fits","S");
  Double_t   parworkSocsci = fitworkSocsci->Value(0);
  Double_t  errworkSocsci = fitworkSocsci->ParError(0);
  TAxis* xaxisworkSocsci= workSocsci->GetXaxis();
  xaxisworkSocsci->SetTickLength(0.);
  xaxisworkSocsci->ChangeLabel(1,-1.,-1.,-1,-1,-1,"cMrM");
  xaxisworkSocsci->ChangeLabel(3,-1.,-1.,-1,-1,-1,"cFrM");
  xaxisworkSocsci->ChangeLabel(5,-1.,-1.,-1,-1,-1,"cMrF");
  xaxisworkSocsci->ChangeLabel(7,-1.,-1.,-1,-1,-1,"cFrF");
  xaxisworkSocsci->ChangeLabel(2,-1.,0.);
  xaxisworkSocsci->ChangeLabel(4,-1.,0.);
  xaxisworkSocsci->ChangeLabel(6,-1.,0.);
  workSocsci->SetMaximum(parworkSocsci + 5.*workcFrFsocsci->GetMeanError());
  workSocsci->SetMinimum(TMath::Max(parworkSocsci - 5.*workcFrFsocsci->GetMeanError(),0.));

  workSocsci->Draw("A*");
  TBox* boxworkSocsci = new TBox(0.6,parworkSocsci-errworkSocsci,4.4,parworkSocsci+errworkSocsci);
  boxworkSocsci->SetFillColor(kBlue);
  boxworkSocsci->SetFillStyle(3004);
  boxworkSocsci->Draw();

  if (useBoth){
    c10->SaveAs("pdfPlotsLIWCBoth/socsciWork.pdf");
  } else { c10->SaveAs("pdfPlotsLIWC/socsciWork.pdf");}
    
  //6th category analytic




    
  TCanvas* c11 = new TCanvas();
  TF1* fitanalytic = new TF1("fits","[0]",0.,10.);
  fitanalytic->SetParNames("average");

  Float_t x11[4] = {1.,2.,3.,4.};
  Float_t y11[4] = {
    static_cast<Float_t>(getMedian(analyticcMrMphysics,quantileVal,quantile)),
    static_cast<Float_t>(getMedian(analyticcFrMphysics,quantileVal,quantile)),
    static_cast<Float_t>(getMedian(analyticcMrFphysics,quantileVal,quantile)),
    static_cast<Float_t>(getMedian(analyticcFrFphysics,quantileVal,quantile))
  };
  Float_t ex11[4] = {0.1,0.1,0.1,0.1};
  Float_t ey11[4] = {
    static_cast<Float_t>(analyticcMrMphysics->GetMeanError()),
    static_cast<Float_t>(analyticcFrMphysics->GetMeanError()),
    static_cast<Float_t>(analyticcMrFphysics->GetMeanError()),
    static_cast<Float_t>(analyticcFrFphysics->GetMeanError())
  };
 
  TGraphErrors* analyticPhysics = new TGraphErrors(4,x11,y11,ex11,ey11);


  analyticPhysics->SetMaximum(100.);
  analyticPhysics->SetMinimum(70.);

  analyticPhysics->SetTitle("Physics LIWC analytic");
  TFitResultPtr fitanalyticPhysics = analyticPhysics->Fit("fits","S");
  Double_t   paranalyticPhysics = fitanalyticPhysics->Value(0);
  Double_t  erranalyticPhysics = fitanalyticPhysics->ParError(0);
  TAxis* xaxisanalyticPhysics= analyticPhysics->GetXaxis();
  xaxisanalyticPhysics->SetTickLength(0.);
  xaxisanalyticPhysics->ChangeLabel(1,-1.,-1.,-1,-1,-1,"cMrM");
  xaxisanalyticPhysics->ChangeLabel(3,-1.,-1.,-1,-1,-1,"cFrM");
  xaxisanalyticPhysics->ChangeLabel(5,-1.,-1.,-1,-1,-1,"cMrF");
  xaxisanalyticPhysics->ChangeLabel(7,-1.,-1.,-1,-1,-1,"cFrF");
  xaxisanalyticPhysics->ChangeLabel(2,-1.,0.);
  xaxisanalyticPhysics->ChangeLabel(4,-1.,0.);
  xaxisanalyticPhysics->ChangeLabel(6,-1.,0.);
  analyticPhysics->Draw("A*");
  analyticPhysics->SetMaximum(paranalyticPhysics + 5.*analyticcFrFphysics->GetMeanError());
  analyticPhysics->SetMinimum(TMath::Max(paranalyticPhysics - 5.*analyticcFrFphysics->GetMeanError(),0.));

  TBox* boxanalyticPhysics = new TBox(0.6,paranalyticPhysics-erranalyticPhysics,4.4,paranalyticPhysics+erranalyticPhysics);
  boxanalyticPhysics->SetFillColor(kBlue);
  boxanalyticPhysics->SetFillStyle(3004);
  boxanalyticPhysics->Draw();
  if (useBoth){
    c11->SaveAs("pdfPlotsLIWCBoth/analyticPhysics.pdf");
  } else { c11->SaveAs("pdfPlotsLIWC/analyticPhysics.pdf");}

  analyticPhysics->Write();

  //
  TCanvas* c12 = new TCanvas();
  TF1* fitanalyticSocSci = new TF1("fits","[0]",0.,12.);
  fitanalyticSocSci->SetParNames("average");

  Float_t x12[4] = {1.,2.,3.,4.};
  Float_t y12[4] = {
    static_cast<Float_t>(getMedian(analyticcMrMsocsci,quantileVal,quantile)),
    static_cast<Float_t>(getMedian(analyticcFrMsocsci,quantileVal,quantile)),
    static_cast<Float_t>(getMedian(analyticcMrFsocsci,quantileVal,quantile)),
    static_cast<Float_t>(getMedian(analyticcFrFsocsci,quantileVal,quantile))
  };
  Float_t ex12[4] = {0.1,0.1,0.1,0.1};
  Float_t ey12[4] = {
    static_cast<Float_t>(analyticcMrMsocsci->GetMeanError()),
    static_cast<Float_t>(analyticcFrMsocsci->GetMeanError()),
    static_cast<Float_t>(analyticcMrFsocsci->GetMeanError()),
    static_cast<Float_t>(analyticcFrFsocsci->GetMeanError())
  };
 
  TGraphErrors* analyticSocsci = new TGraphErrors(4,x12,y12,ex12,ey12);


  analyticSocsci->SetMaximum(100.);
  analyticSocsci->SetMinimum(70.);

  analyticSocsci->SetTitle("SocSci LIWC analytic");
  TFitResultPtr fitanalyticSocsci = analyticSocsci->Fit("fits","S");
  Double_t   paranalyticSocsci = fitanalyticSocsci->Value(0);
  Double_t  erranalyticSocsci = fitanalyticSocsci->ParError(0);
  TAxis* xaxisanalyticSocsci= analyticSocsci->GetXaxis();
  xaxisanalyticSocsci->SetTickLength(0.);
  xaxisanalyticSocsci->ChangeLabel(1,-1.,-1.,-1,-1,-1,"cMrM");
  xaxisanalyticSocsci->ChangeLabel(3,-1.,-1.,-1,-1,-1,"cFrM");
  xaxisanalyticSocsci->ChangeLabel(5,-1.,-1.,-1,-1,-1,"cMrF");
  xaxisanalyticSocsci->ChangeLabel(7,-1.,-1.,-1,-1,-1,"cFrF");
  xaxisanalyticSocsci->ChangeLabel(2,-1.,0.);
  xaxisanalyticSocsci->ChangeLabel(4,-1.,0.);
  xaxisanalyticSocsci->ChangeLabel(6,-1.,0.);
  analyticSocsci->SetMaximum(paranalyticSocsci + 5.*analyticcFrFsocsci->GetMeanError());
  analyticSocsci->SetMinimum(TMath::Max(paranalyticSocsci - 5.*analyticcFrFsocsci->GetMeanError(),0.));

  analyticSocsci->Draw("A*");
  TBox* boxanalyticSocsci = new TBox(0.6,paranalyticSocsci-erranalyticSocsci,4.4,paranalyticSocsci+erranalyticSocsci);
  boxanalyticSocsci->SetFillColor(kBlue);
  boxanalyticSocsci->SetFillStyle(3004);
  boxanalyticSocsci->Draw();
  if (useBoth){
    c12->SaveAs("pdfPlotsLIWCBoth/analyticSocsci.pdf");
  } else { c12->SaveAs("pdfPlotsLIWC/analyticSocsci.pdf");}

  analyticSocsci->Write();

  //  7th category clout

 




    
  TCanvas* c13 = new TCanvas();
  TF1* fitclout = new TF1("fits","[0]",0.,10.);
  fitclout->SetParNames("average");

  Float_t x13[4] = {1.,2.,3.,4.};
  Float_t y13[4] = {
    static_cast<Float_t>(getMedian(cloutcMrMphysics,quantileVal,quantile)),
    static_cast<Float_t>(getMedian(cloutcFrMphysics,quantileVal,quantile)),
    static_cast<Float_t>(getMedian(cloutcMrFphysics,quantileVal,quantile)),
    static_cast<Float_t>(getMedian(cloutcFrFphysics,quantileVal,quantile))
  };
  Float_t ex13[4] = {0.1,0.1,0.1,0.1};
  Float_t ey13[4] = {
    static_cast<Float_t>(cloutcMrMphysics->GetMeanError()),
    static_cast<Float_t>(cloutcFrMphysics->GetMeanError()),
    static_cast<Float_t>(cloutcMrFphysics->GetMeanError()),
    static_cast<Float_t>(cloutcFrFphysics->GetMeanError())
  };
 
  TGraphErrors* cloutPhysics = new TGraphErrors(4,x13,y13,ex13,ey13);


  cloutPhysics->SetMaximum(80.);
  cloutPhysics->SetMinimum(50.);

  cloutPhysics->SetTitle("Physics LIWC clout");
  TFitResultPtr fitcloutPhysics = cloutPhysics->Fit("fits","S");
  Double_t   parcloutPhysics = fitcloutPhysics->Value(0);
  Double_t  errcloutPhysics = fitcloutPhysics->ParError(0);
  TAxis* xaxiscloutPhysics= cloutPhysics->GetXaxis();
  xaxiscloutPhysics->SetTickLength(0.);
  xaxiscloutPhysics->ChangeLabel(1,-1.,-1.,-1,-1,-1,"cMrM");
  xaxiscloutPhysics->ChangeLabel(3,-1.,-1.,-1,-1,-1,"cFrM");
  xaxiscloutPhysics->ChangeLabel(5,-1.,-1.,-1,-1,-1,"cMrF");
  xaxiscloutPhysics->ChangeLabel(7,-1.,-1.,-1,-1,-1,"cFrF");
  xaxiscloutPhysics->ChangeLabel(2,-1.,0.);
  xaxiscloutPhysics->ChangeLabel(4,-1.,0.);
  xaxiscloutPhysics->ChangeLabel(6,-1.,0.);
  cloutPhysics->SetMaximum(parcloutPhysics + 5.*cloutcFrFphysics->GetMeanError());
  cloutPhysics->SetMinimum(TMath::Max(parcloutPhysics - 5.*cloutcFrFphysics->GetMeanError(),0.));

  cloutPhysics->Draw("A*");
  TBox* boxcloutPhysics = new TBox(0.6,parcloutPhysics-errcloutPhysics,4.4,parcloutPhysics+errcloutPhysics);
  boxcloutPhysics->SetFillColor(kBlue);
  boxcloutPhysics->SetFillStyle(3004);
  boxcloutPhysics->Draw();
  if (useBoth){
    c13->SaveAs("pdfPlotsLIWCBoth/cloutPhysics.pdf");
  } else { c13->SaveAs("pdfPlotsLIWC/cloutPhysics.pdf");}

  cloutPhysics->Write();

  //
  TCanvas* c14 = new TCanvas();
  TF1* fitcloutSocSci = new TF1("fits","[0]",0.,14.);
  fitcloutSocSci->SetParNames("average");

  Float_t x14[4] = {1.,2.,3.,4.};
  Float_t y14[4] = {
    static_cast<Float_t>(getMedian(cloutcMrMsocsci,quantileVal,quantile)),
    static_cast<Float_t>(getMedian(cloutcFrMsocsci,quantileVal,quantile)),
    static_cast<Float_t>(getMedian(cloutcMrFsocsci,quantileVal,quantile)),
    static_cast<Float_t>(getMedian(cloutcFrFsocsci,quantileVal,quantile))
  };
  Float_t ex14[4] = {0.1,0.1,0.1,0.1};
  Float_t ey14[4] = {
    static_cast<Float_t>(cloutcMrMsocsci->GetMeanError()),
    static_cast<Float_t>(cloutcFrMsocsci->GetMeanError()),
    static_cast<Float_t>(cloutcMrFsocsci->GetMeanError()),
    static_cast<Float_t>(cloutcFrFsocsci->GetMeanError())
  };
 
  TGraphErrors* cloutSocsci = new TGraphErrors(4,x14,y14,ex14,ey14);


  cloutSocsci->SetMaximum(80.);
  cloutSocsci->SetMinimum(50.);

  cloutSocsci->SetTitle("SocSci LIWC clout");
  TFitResultPtr fitcloutSocsci = cloutSocsci->Fit("fits","S");
  Double_t   parcloutSocsci = fitcloutSocsci->Value(0);
  Double_t  errcloutSocsci = fitcloutSocsci->ParError(0);
  TAxis* xaxiscloutSocsci= cloutSocsci->GetXaxis();
  xaxiscloutSocsci->SetTickLength(0.);
  xaxiscloutSocsci->ChangeLabel(1,-1.,-1.,-1,-1,-1,"cMrM");
  xaxiscloutSocsci->ChangeLabel(3,-1.,-1.,-1,-1,-1,"cFrM");
  xaxiscloutSocsci->ChangeLabel(5,-1.,-1.,-1,-1,-1,"cMrF");
  xaxiscloutSocsci->ChangeLabel(7,-1.,-1.,-1,-1,-1,"cFrF");
  xaxiscloutSocsci->ChangeLabel(2,-1.,0.);
  xaxiscloutSocsci->ChangeLabel(4,-1.,0.);
  xaxiscloutSocsci->ChangeLabel(6,-1.,0.);
  cloutSocsci->SetMaximum(parcloutSocsci + 20.*cloutcFrFsocsci->GetMeanError());
  cloutSocsci->SetMinimum(TMath::Max(parcloutSocsci - 20.*cloutcFrFsocsci->GetMeanError(),0.));

  cloutSocsci->Draw("A*");
  TBox* boxcloutSocsci = new TBox(0.6,parcloutSocsci-errcloutSocsci,4.4,parcloutSocsci+errcloutSocsci);
  boxcloutSocsci->SetFillColor(kBlue);
  boxcloutSocsci->SetFillStyle(3004);
  boxcloutSocsci->Draw();
  if (useBoth){
    c14->SaveAs("pdfPlotsLIWCBoth/cloutSocsci.pdf");
  } else { c14->SaveAs("pdfPlotsLIWC/cloutSocsci.pdf");}

  cloutSocsci->Write();


  //home category
  
 


    
  TCanvas* c15 = new TCanvas();
  TF1* fithome = new TF1("fits","[0]",0.,10.);
  fithome->SetParNames("average");

  Float_t x15[4] = {1.,2.,3.,4.};
  Float_t y15[4] = {
    static_cast<Float_t>(getMedian(homecMrMphysics,quantileVal,quantile)),
    static_cast<Float_t>(getMedian(homecFrMphysics,quantileVal,quantile)),
    static_cast<Float_t>(getMedian(homecMrFphysics,quantileVal,quantile)),
    static_cast<Float_t>(getMedian(homecFrFphysics,quantileVal,quantile))
  };
  Float_t ex15[4] = {0.1,0.1,0.1,0.1};
  Float_t ey15[4] = {
    static_cast<Float_t>(homecMrMphysics->GetMeanError()),
    static_cast<Float_t>(homecFrMphysics->GetMeanError()),
    static_cast<Float_t>(homecMrFphysics->GetMeanError()),
    static_cast<Float_t>(homecFrFphysics->GetMeanError())
  };
 
  TGraphErrors* homePhysics = new TGraphErrors(4,x15,y15,ex15,ey15);


  homePhysics->SetMaximum(0.5);
  homePhysics->SetMinimum(0.);

  homePhysics->SetTitle("Physics LIWC home");
  TFitResultPtr fithomePhysics = homePhysics->Fit("fits","S");
  Double_t   parhomePhysics = fithomePhysics->Value(0);
  Double_t  errhomePhysics = fithomePhysics->ParError(0);
  TAxis* xaxishomePhysics= homePhysics->GetXaxis();
  xaxishomePhysics->SetTickLength(0.);
  xaxishomePhysics->ChangeLabel(1,-1.,-1.,-1,-1,-1,"cMrM");
  xaxishomePhysics->ChangeLabel(3,-1.,-1.,-1,-1,-1,"cFrM");
  xaxishomePhysics->ChangeLabel(5,-1.,-1.,-1,-1,-1,"cMrF");
  xaxishomePhysics->ChangeLabel(7,-1.,-1.,-1,-1,-1,"cFrF");
  xaxishomePhysics->ChangeLabel(2,-1.,0.);
  xaxishomePhysics->ChangeLabel(4,-1.,0.);
  xaxishomePhysics->ChangeLabel(6,-1.,0.);
  homePhysics->SetMaximum(parhomePhysics + 5.*homecFrFphysics->GetMeanError());
  homePhysics->SetMinimum(TMath::Max(parhomePhysics - 5.*homecFrFphysics->GetMeanError(),0.));

  homePhysics->Draw("A*");
  TBox* boxhomePhysics = new TBox(0.6,parhomePhysics-errhomePhysics,4.4,parhomePhysics+errhomePhysics);
  boxhomePhysics->SetFillColor(kBlue);
  boxhomePhysics->SetFillStyle(3004);
  boxhomePhysics->Draw();
  if (useBoth){
    c15->SaveAs("pdfPlotsLIWCBoth/homePhysics.pdf");
  } else { c15->SaveAs("pdfPlotsLIWC/homePhysics.pdf");}

  homePhysics->Write();

  //
  TCanvas* c16 = new TCanvas();
  TF1* fithomeSocSci = new TF1("fits","[0]",0.,10.);
  fithomeSocSci->SetParNames("average");

  Float_t x16[4] = {1.,2.,3.,4.};
  Float_t y16[4] = {
    static_cast<Float_t>(getMedian(homecMrMsocsci,quantileVal,quantile)),
    static_cast<Float_t>(getMedian(homecFrMsocsci,quantileVal,quantile)),
    static_cast<Float_t>(getMedian(homecMrFsocsci,quantileVal,quantile)),
    static_cast<Float_t>(getMedian(homecFrFsocsci,quantileVal,quantile))
  };
  Float_t ex16[4] = {0.1,0.1,0.1,0.1};
  Float_t ey16[4] = {
    static_cast<Float_t>(homecMrMsocsci->GetMeanError()),
    static_cast<Float_t>(homecFrMsocsci->GetMeanError()),
    static_cast<Float_t>(homecMrFsocsci->GetMeanError()),
    static_cast<Float_t>(homecFrFsocsci->GetMeanError())
  };
 
  TGraphErrors* homeSocsci = new TGraphErrors(4,x16,y16,ex16,ey16);


  homeSocsci->SetMaximum(0.5);
  homeSocsci->SetMinimum(0.);

  homeSocsci->SetTitle("SocSci LIWC home");
  TFitResultPtr fithomeSocsci = homeSocsci->Fit("fits","S");
  Double_t   parhomeSocsci = fithomeSocsci->Value(0);
  Double_t  errhomeSocsci = fithomeSocsci->ParError(0);
  TAxis* xaxishomeSocsci= homeSocsci->GetXaxis();
  xaxishomeSocsci->SetTickLength(0.);
  xaxishomeSocsci->ChangeLabel(1,-1.,-1.,-1,-1,-1,"cMrM");
  xaxishomeSocsci->ChangeLabel(3,-1.,-1.,-1,-1,-1,"cFrM");
  xaxishomeSocsci->ChangeLabel(5,-1.,-1.,-1,-1,-1,"cMrF");
  xaxishomeSocsci->ChangeLabel(7,-1.,-1.,-1,-1,-1,"cFrF");
  xaxishomeSocsci->ChangeLabel(2,-1.,0.);
  xaxishomeSocsci->ChangeLabel(4,-1.,0.);
  xaxishomeSocsci->ChangeLabel(6,-1.,0.);
  homeSocsci->SetMaximum(parhomeSocsci + 5.*homecFrFsocsci->GetMeanError());
  homeSocsci->SetMinimum(TMath::Max(parhomeSocsci - 5.*homecFrFsocsci->GetMeanError(),0.));

  homeSocsci->Draw("A*");
  TBox* boxhomeSocsci = new TBox(0.6,parhomeSocsci-errhomeSocsci,4.4,parhomeSocsci+errhomeSocsci);
  boxhomeSocsci->SetFillColor(kBlue);
  boxhomeSocsci->SetFillStyle(3004);
  boxhomeSocsci->Draw();
  if (useBoth){
    c16->SaveAs("pdfPlotsLIWCBoth/homeSocsci.pdf");
  } else { c16->SaveAs("pdfPlotsLIWC/homeSocsci.pdf");}



  
  TCanvas* c19 = new TCanvas();
  c19->Divide(2);
  c19->cd(2);

    Float_t xPosemoPhysics[4] = {1.,2.,3.,4.};
  Float_t yPosemoPhysics[4] = {
    static_cast<Float_t>(getMedian(PosemocMrMphysics,quantileVal,quantile)),
    static_cast<Float_t>(getMedian(PosemocFrMphysics,quantileVal,quantile)),
    static_cast<Float_t>(getMedian(PosemocMrFphysics,quantileVal,quantile)),
    static_cast<Float_t>(getMedian(PosemocFrFphysics,quantileVal,quantile))
  };
  Float_t exPosemoPhysics[4] = {0.1,0.1,0.1,0.1};
  Float_t eyPosemoPhysics[4] = {
    static_cast<Float_t>(PosemocMrMphysics->GetMeanError()),
    static_cast<Float_t>(PosemocFrMphysics->GetMeanError()),
    static_cast<Float_t>(PosemocMrFphysics->GetMeanError()),
    static_cast<Float_t>(PosemocFrFphysics->GetMeanError())
  };

  TGraphErrors* posemoPhysics = new TGraphErrors(4,xPosemoPhysics,yPosemoPhysics,exPosemoPhysics,eyPosemoPhysics);
  posemoPhysics->SetMaximum(1.7);
  posemoPhysics->SetMinimum(0.7);
  posemoPhysics->SetTitle("EPP Median Positive Affect");
  TFitResultPtr fitPosemoPhysics = posemoPhysics->Fit("fits","S");
  double par0 = fitPosemoPhysics->Value(0);
  double err0 = fitPosemoPhysics->ParError(0);
  TAxis* yAxisPosemoPhysics = posemoPhysics->GetYaxis();
  yAxisPosemoPhysics->SetTitle("% of Words");
  yAxisPosemoPhysics->SetTickLength(0.);
 
  TAxis* xaxisPosemoPhysics = posemoPhysics->GetXaxis();
   xaxisPosemoPhysics->SetTickLength(0.);
   xaxisPosemoPhysics->ChangeLabel(1,-1.,-1.,-1,-1,-1,"#splitline{cand. M}{writer M}");
  xaxisPosemoPhysics->ChangeLabel(3,-1.,-1.,-1,-1,-1,"#splitline{cand. F}{writer M}");
  xaxisPosemoPhysics->ChangeLabel(5,-1.,-1.,-1,-1,-1,"#splitline{cand. M}{writer F}");
  xaxisPosemoPhysics->ChangeLabel(7,-1.,-1.,-1,-1,-1,"#splitline{cand. F}{writer F}");
  xaxisPosemoPhysics->ChangeLabel(2,-1.,0.);
  xaxisPosemoPhysics->ChangeLabel(4,-1.,0.);
  xaxisPosemoPhysics->ChangeLabel(6,-1.,0.);
  xaxisPosemoPhysics->ChangeLabel(1,-1.,-1.,-1,-1,-1," ");
  xaxisPosemoPhysics->ChangeLabel(3,-1.,-1.,-1,-1,-1," ");
  xaxisPosemoPhysics->ChangeLabel(5,-1.,-1.,-1,-1,-1," ");
  xaxisPosemoPhysics->ChangeLabel(7,-1.,-1.,-1,-1,-1," ");
  xaxisPosemoPhysics->ChangeLabel(2,-1.,0.);
  xaxisPosemoPhysics->ChangeLabel(4,-1.,0.);
  xaxisPosemoPhysics->ChangeLabel(6,-1.,0.);
  posemoPhysics->SetFillColor(38);
  posemoPhysics->SetMaximum(par0 + 5.*PosemocFrFphysics->GetMeanError());
  posemoPhysics->SetMinimum(TMath::Max(par0 - 5.*PosemocFrFphysics->GetMeanError(),0.));

  posemoPhysics->Draw("AB");
  TBox* boxPosemoPhysics = new TBox(0.6,par0-err0,4.4,par0+err0);
  boxPosemoPhysics->SetFillColor(kBlue);
  boxPosemoPhysics->SetFillStyle(3004);
  boxPosemoPhysics->Draw();

  posemoPhysics->Write();
  if (useBoth)
    {c19->SaveAs("pdfPlotsBoth/physicsPosemo.pdf");}
  else{c19->SaveAs("pdfPlots/physicsPosemo.pdf");}

  c19->cd(1);

  //  analysisOut <<    static_cast<Float_t>(getMedian(posemoSocScicMrM,quantileVal,quantile)) << " " << 
  //static_cast<Float_t>(getMedian(posemoSocScicFrM,quantileVal,quantile)) << " " << 
  //static_cast<Float_t>(getMedian(posemoSocScicFrF,quantileVal,quantile)) << " " <<
  //static_cast<Float_t>(getMedian(posemoSocScicMrF,quantileVal,quantile)) << " " << std::endl;
									  
 
  Float_t xPosemoSocSci[4] = {1.,2.,3.,4.};
  Float_t yPosemoSocSci[4] = {
    static_cast<Float_t>(getMedian(PosemocMrMsocsci,quantileVal,quantile)),
    static_cast<Float_t>(getMedian(PosemocFrMsocsci,quantileVal,quantile)),
    static_cast<Float_t>(getMedian(PosemocMrFsocsci,quantileVal,quantile)),
    static_cast<Float_t>(getMedian(PosemocFrFsocsci,quantileVal,quantile))
  };
  Float_t exPosemoSocSci[4] = {0.1,0.1,0.1,0.1};
  Float_t eyPosemoSocSci[4] = {
    static_cast<Float_t>(PosemocMrMsocsci->GetMeanError()),
    static_cast<Float_t>(PosemocFrMsocsci->GetMeanError()),
    static_cast<Float_t>(PosemocMrFsocsci->GetMeanError()),
    static_cast<Float_t>(PosemocFrFsocsci->GetMeanError())
  };

  TGraphErrors* posemoSocSci = new TGraphErrors(4,xPosemoSocSci,yPosemoSocSci,exPosemoSocSci,eyPosemoSocSci);
  posemoSocSci->SetTitle("Social Science Median Positive Affect");
  TFitResultPtr fit4 = posemoSocSci->Fit("fits","S");
  par0 = fit4->Value(0);
  err0 = fit4->ParError(0);
   TAxis* yAxisPosemoSocSci = posemoSocSci->GetYaxis();
   yAxisPosemoSocSci->SetTitle("% of Words");
  yAxisPosemoSocSci->SetTickLength(0.);

  TAxis* xaxisPosemoSocSci = posemoSocSci->GetXaxis();
   xaxisPosemoSocSci->SetTickLength(0.);
   xaxisPosemoSocSci->ChangeLabel(1,-1.,-1.,-1,-1,-1,"#splitline{cand. M}{writer M}");
  xaxisPosemoSocSci->ChangeLabel(3,-1.,-1.,-1,-1,-1,"#splitline{cand. F}{writer M}");
  xaxisPosemoSocSci->ChangeLabel(5,-1.,-1.,-1,-1,-1,"#splitline{cand. M}{writer F}");
  xaxisPosemoSocSci->ChangeLabel(7,-1.,-1.,-1,-1,-1,"#splitline{cand. F}{writer F}");
  xaxisPosemoSocSci->ChangeLabel(2,-1.,0.);
  xaxisPosemoSocSci->ChangeLabel(4,-1.,0.);
  xaxisPosemoSocSci->ChangeLabel(6,-1.,0.);
  xaxisPosemoSocSci->ChangeLabel(1,-1.,-1.,-1,-1,-1," ");
  xaxisPosemoSocSci->ChangeLabel(3,-1.,-1.,-1,-1,-1," ");
  xaxisPosemoSocSci->ChangeLabel(5,-1.,-1.,-1,-1,-1," ");
  xaxisPosemoSocSci->ChangeLabel(7,-1.,-1.,-1,-1,-1," ");
  xaxisPosemoSocSci->ChangeLabel(2,-1.,0.);
  xaxisPosemoSocSci->ChangeLabel(4,-1.,0.);
  xaxisPosemoSocSci->ChangeLabel(6,-1.,0.);
  posemoSocSci->SetFillColor(38);


  posemoSocSci->SetMaximum(par0 + 5.*PosemocFrFsocsci->GetMeanError());
  posemoSocSci->SetMinimum(TMath::Max(par0 - 5.*PosemocFrFsocsci->GetMeanError(),0.));

  posemoSocSci->Draw("AB");
  TBox* boxPosemoSocSci = new TBox(0.6,par0-err0,4.4,par0+err0);
  boxPosemoSocSci->SetFillColor(kBlue);
  boxPosemoSocSci->SetFillStyle(3004);
  boxPosemoSocSci->Draw();

  posemoSocSci->Write();
  if (useBoth){
    c19->SaveAs("pdfPlotsBoth/SocSciPosemo.pdf");
  }else {c19->SaveAs("pdfPlots/SocSciPosemo.pdf");}


    TCanvas* c20 = new TCanvas();
   c20->Divide(2);
  c20->cd(2);

    Float_t xNegemoPhysics[4] = {1.,2.,3.,4.};
  Float_t yNegemoPhysics[4] = {
    static_cast<Float_t>(getMedian(NegemocMrMphysics,quantileVal,quantile)),
    static_cast<Float_t>(getMedian(NegemocFrMphysics,quantileVal,quantile)),
    static_cast<Float_t>(getMedian(NegemocMrFphysics,quantileVal,quantile)),
    static_cast<Float_t>(getMedian(NegemocFrFphysics,quantileVal,quantile))
  };
  Float_t exNegemoPhysics[4] = {0.1,0.1,0.1,0.1};
  Float_t eyNegemoPhysics[4] = {
    static_cast<Float_t>(NegemocMrMphysics->GetMeanError()),
    static_cast<Float_t>(NegemocFrMphysics->GetMeanError()),
    static_cast<Float_t>(NegemocMrFphysics->GetMeanError()),
    static_cast<Float_t>(NegemocFrFphysics->GetMeanError())
  };

  TGraphErrors* negemoPhysics = new TGraphErrors(4,xNegemoPhysics,yNegemoPhysics,exNegemoPhysics,eyNegemoPhysics);
  negemoPhysics->SetTitle("EPP Median Negative Affect");
  TFitResultPtr fitNegemoPhysics = negemoPhysics->Fit("fits","S");
  par0 = fitNegemoPhysics->Value(0);
  err0 = fitNegemoPhysics->ParError(0);
    TAxis* yAxisNegemoPhysics = negemoPhysics->GetYaxis();
  yAxisNegemoPhysics->SetTitle("% of Words");
  yAxisNegemoPhysics->SetTickLength(0.);

  TAxis* xaxisNegemoPhysics = negemoPhysics->GetXaxis();
  xaxisNegemoPhysics->SetTickLength(0.);
   xaxisNegemoPhysics->ChangeLabel(1,-1.,-1.,-1,-1,-1,"#splitline{cand. M}{writer M}");
  xaxisNegemoPhysics->ChangeLabel(3,-1.,-1.,-1,-1,-1,"#splitline{cand. F}{writer M}");
  xaxisNegemoPhysics->ChangeLabel(5,-1.,-1.,-1,-1,-1,"#splitline{cand. M}{writer F}");
  xaxisNegemoPhysics->ChangeLabel(7,-1.,-1.,-1,-1,-1,"#splitline{cand. F}{writer F}");
  xaxisNegemoPhysics->ChangeLabel(2,-1.,0.);
  xaxisNegemoPhysics->ChangeLabel(4,-1.,0.);
  xaxisNegemoPhysics->ChangeLabel(6,-1.,0.);
  xaxisNegemoPhysics->ChangeLabel(1,-1.,-1.,-1,-1,-1," ");
  xaxisNegemoPhysics->ChangeLabel(3,-1.,-1.,-1,-1,-1," ");
  xaxisNegemoPhysics->ChangeLabel(5,-1.,-1.,-1,-1,-1," ");
  xaxisNegemoPhysics->ChangeLabel(7,-1.,-1.,-1,-1,-1," ");
  xaxisNegemoPhysics->ChangeLabel(2,-1.,0.);
  xaxisNegemoPhysics->ChangeLabel(4,-1.,0.);
  xaxisNegemoPhysics->ChangeLabel(6,-1.,0.);
  negemoPhysics->SetFillColor(38);

  negemoPhysics->SetMaximum(par0 + 5.*NegemocFrFphysics->GetMeanError());
  negemoPhysics->SetMinimum(TMath::Max(par0 - 5.*NegemocFrFphysics->GetMeanError(),0.));

  negemoPhysics->Draw("AB");
  TBox* boxNegemoPhysics = new TBox(0.6,par0-err0,4.4,par0+err0);
  boxNegemoPhysics->SetFillColor(kBlue);
  boxNegemoPhysics->SetFillStyle(3004);
  boxNegemoPhysics->Draw();

  negemoPhysics->Write();
  if (useBoth)
    {c19->SaveAs("pdfPlotsBoth/physicsNegemo.pdf");}
  else{c19->SaveAs("pdfPlots/physicsNegemo.pdf");}
  
     // TCanvas* c4 = new TCanvas();
  c20->cd(1);

  //  analysisOut <<    static_cast<Float_t>(getMedian(negemoSocScicMrM,quantileVal,quantile)) << " " << 
  // static_cast<Float_t>(getMedian(negemoSocScicFrM,quantileVal,quantile)) << " " << 
  // static_cast<Float_t>(getMedian(negemoSocScicFrF,quantileVal,quantile)) << " " <<
  // static_cast<Float_t>(getMedian(negemoSocScicMrF,quantileVal,quantile)) << " " << std::endl;
 
  Float_t xNegemoSocsci[4] = {1.,2.,3.,4.};
  Float_t yNegemoSocsci[4] = {
    static_cast<Float_t>(getMedian(NegemocMrMsocsci,quantileVal,quantile)),
    static_cast<Float_t>(getMedian(NegemocFrMsocsci,quantileVal,quantile)),
    static_cast<Float_t>(getMedian(NegemocMrFsocsci,quantileVal,quantile)),
    static_cast<Float_t>(getMedian(NegemocFrFsocsci,quantileVal,quantile))
  };
  Float_t exNegemoSocsci[4] = {0.1,0.1,0.1,0.1};
  Float_t eyNegemoSocsci[4] = {
    static_cast<Float_t>(NegemocMrMsocsci->GetMeanError()),
    static_cast<Float_t>(NegemocFrMsocsci->GetMeanError()),
    static_cast<Float_t>(NegemocMrFsocsci->GetMeanError()),
    static_cast<Float_t>(NegemocFrFsocsci->GetMeanError())
  };

  TGraphErrors* negemoSocSci = new TGraphErrors(4,xNegemoSocsci,yNegemoSocsci,exNegemoSocsci,eyNegemoSocsci);
  negemoSocSci->SetMaximum(2.0);
  negemoSocSci->SetMinimum(1.0);
  negemoSocSci->SetTitle("Social Science Median Negative Affect");
  TFitResultPtr fitNegemoSocSci = negemoSocSci->Fit("fits","S");
  par0 = fitNegemoSocSci->Value(0);
  err0 = fitNegemoSocSci->ParError(0);
    TAxis* yAxisNegemoSocSci = negemoSocSci->GetYaxis();
  yAxisNegemoSocSci->SetTitle("% of Words");
  yAxisNegemoSocSci->SetTickLength(0.);
  TAxis* xaxisNegemoSocSci = negemoSocSci->GetXaxis();
  xaxisNegemoSocSci->SetTickLength(0.);
  xaxisNegemoSocSci->ChangeLabel(1,-1.,-1.,-1,-1,-1,"#splitline{cand. M}{writer M}");
  xaxisNegemoSocSci->ChangeLabel(3,-1.,-1.,-1,-1,-1,"#splitline{cand. F}{writer M}");
  xaxisNegemoSocSci->ChangeLabel(5,-1.,-1.,-1,-1,-1,"#splitline{cand. M}{writer F}");
  xaxisNegemoSocSci->ChangeLabel(7,-1.,-1.,-1,-1,-1,"#splitline{cand. F}{writer F}");
  xaxisNegemoSocSci->ChangeLabel(2,-1.,0.);
  xaxisNegemoSocSci->ChangeLabel(4,-1.,0.);
  xaxisNegemoSocSci->ChangeLabel(6,-1.,0.);
  xaxisNegemoSocSci->ChangeLabel(1,-1.,-1.,-1,-1,-1," ");
  xaxisNegemoSocSci->ChangeLabel(3,-1.,-1.,-1,-1,-1," ");
  xaxisNegemoSocSci->ChangeLabel(5,-1.,-1.,-1,-1,-1," ");
  xaxisNegemoSocSci->ChangeLabel(7,-1.,-1.,-1,-1,-1," ");
  xaxisNegemoSocSci->ChangeLabel(2,-1.,0.);
  xaxisNegemoSocSci->ChangeLabel(4,-1.,0.);
  xaxisNegemoSocSci->ChangeLabel(6,-1.,0.);
  negemoSocSci->SetFillColor(38);

  negemoSocSci->SetMaximum(par0 + 5.*NegemocFrFsocsci->GetMeanError());
  negemoSocSci->SetMinimum(TMath::Max(par0 - 5.*NegemocFrFsocsci->GetMeanError(),0.));

  negemoSocSci->Draw("AB");
  TBox* boxNegemoSocSci = new TBox(0.6,par0-err0,4.4,par0+err0);
  boxNegemoSocSci->SetFillColor(kBlue);
  boxNegemoSocSci->SetFillStyle(3004);
  boxNegemoSocSci->Draw();

  negemoSocSci->Write();
  if (useBoth){
    c20->SaveAs("pdfPlotsBoth/SocSciNegemo.pdf");
  }else {c20->SaveAs("pdfPlots/SocSciNegemo.pdf");}

 
  f->Close();
}


