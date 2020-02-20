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



void rhbDictRank()

{

  std::ofstream analysisOut;
  std::ofstream bothOut;
  
  analysisOut.open("analysisRHB.txt");
   bothOut.open("bothRHB.txt");
   //  std::ifstream inputFiles("TestOneSpreadsheet.txt");
  std::ifstream inputFiles("annotated_v5_ALL.txt");
  
  std::vector<std::string> letterFileList;
  std::string letterLine;


  while(std::getline(inputFiles,letterLine))
    {
      letterFileList.push_back(letterLine);
      //     std::cout << "checking " << letterLine << std::endl;
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
    achiev,power,reward,risk,focuspast,focuspresent,focusfuture ,
    relativ,motion,space,time,work,leisure,home,money,relig,death,informal,swear,netspeak,assent,nonflu,filler,AllPunc,Period,Comma,Colon,SemiC,QMark,Exclam,Dash,Quote,
    Apostro,Parent,OtherP;

  Int_t canGender, writerGender,both,candId,writerId,discipline;
  string candidateName;
  Int_t wcCut;

  
  Int_t Ref_is_advisor, Ref_nonresearch,both_gender_non_advisor_refs;

  Float_t standout, ability, grindstone , teaching , research , agentic, communal, comparisonMale , comparisonFemale, signalPhysics, signalSociology , ranking, negative;
  
  Int_t nlines = 0;
  TFile* f = new TFile("lexicalAnalysisRHBGt1000.root", "RECREATE");
  TH1F* wordCountPhysicscMrM = new TH1F("wordCountWilsoncMrM", " number of words in Wilson letter, cMrM ",100,0.,5000.);
  TH1F* wordCountPhysicscFrM = new TH1F("wordCountWilsoncFrM", " number of words in Wilson letter, cFrM ",100,0.,5000.);
  TH1F* wordCountPhysicscFrF = new TH1F("wordCountWilsoncFrF", " number of words in Wilson letter, cFrF ",100,0.,5000.);
  TH1F* wordCountPhysicscMrF = new TH1F("wordCountWilsoncMrF", " number of words in Wilson letter, cMrF ",100,0.,5000.);

  TH1F* wordCountSocScicMrM = new TH1F("wordCountSocScicMrM", " number of words in Cornell letter, cMrM ",100,0.,5000.);
  TH1F* wordCountSocScicFrM = new TH1F("wordCountSocScicFrM", " number of words in Cornell letter, cFrM ",100,0.,5000.);
  TH1F* wordCountSocScicFrF = new TH1F("wordCountSocScicFrF", " number of words in Cornell letter, cFrF ",100,0.,5000.);
  TH1F* wordCountSocScicMrF = new TH1F("wordCountSocScicMrF", " number of words in Cornell letter, cMrF ",100,0.,5000.);


  TH1F* agenticPhysicscMrM = new TH1F("agenticWilsoncMrM", " rate of agentic words in Wilson letter, cMrM ",50,0.,5.);
  TH1F* agenticPhysicscFrM = new TH1F("agenticWilsoncFrM", " rate of agentic words in Wilson letter, cFrM ",50,0.,5.);
  TH1F* agenticPhysicscFrF = new TH1F("agenticWilsoncFrF", " rate of agentic words in Wilson letter, cFrF ",50,0.,5.);
  TH1F* agenticPhysicscMrF = new TH1F("agenticWilsoncMrF", " rate of agentic words in Wilson letter, cMrF ",50,0.,5.);

  TH1F* agenticSocScicMrM = new TH1F("agenticSocScicMrM", " rate of agentic words in Cornell letter, cMrM ",50,0.,5.);
  TH1F* agenticSocScicFrM = new TH1F("agenticSocScicFrM", " rate of agentic words in Cornell letter, cFrM ",50,0.,5.);
  TH1F* agenticSocScicFrF = new TH1F("agenticSocScicFrF", " rate of agentic words in Cornell letter, cFrF ",50,0.,5.);
  TH1F* agenticSocScicMrF = new TH1F("agenticSocScicMrF", " rate of agentic words in Cornell letter, cMrF ",50,0.,5.);

  TH1F* communalPhysicscMrM = new TH1F("communalWilsoncMrM", " rate of communal words in Wilson letter, cMrM ",50,0.,5.);
  TH1F* communalPhysicscFrM = new TH1F("communalWilsoncFrM", " rate of communal words in Wilson letter, cFrM ",50,0.,5.);
  TH1F* communalPhysicscFrF = new TH1F("communalWilsoncFrF", " rate of communal words in Wilson letter, cFrF ",50,0.,5.);
  TH1F* communalPhysicscMrF = new TH1F("communalWilsoncMrF", " rate of communal words in Wilson letter, cMrF ",50,0.,5.);

  TH1F* communalSocScicMrM = new TH1F("communalSocScicMrM", " rate of communal words in Cornell letter, cMrM ",50,0.,5.);
  TH1F* communalSocScicFrM = new TH1F("communalSocScicFrM", " rate of communal words in Cornell letter, cFrM ",50,0.,5.);
  TH1F* communalSocScicFrF = new TH1F("communalSocScicFrF", " rate of communal words in Cornell letter, cFrF ",50,0.,5.);
  TH1F* communalSocScicMrF= new TH1F("communalSocScicMrF", " rate of communal words in Cornell letter, cMrF ",50,0.,5.);

  TH1F* standoutPhysicscMrM = new TH1F("standoutWilsoncMrM", " rate of standout words in Wilson letter, cMrM ",50,0.,5.);
  TH1F* standoutPhysicscFrM = new TH1F("standoutWilsoncFrM", " rate of standout words in Wilson letter, cFrM ",50,0.,5.);
  TH1F* standoutPhysicscFrF = new TH1F("standoutWilsoncFrF", " rate of standout words in Wilson letter, cFrF ",50,0.,5.);
  TH1F* standoutPhysicscMrF = new TH1F("standoutWilsoncMrF", " rate of standout words in Wilson letter, cMrF ",50,0.,5.);

  TH1F* standoutSocScicMrM = new TH1F("standoutSocScicMrM", " rate of standout words in Cornell letter, cMrM ",50,0.,5.);
  TH1F* standoutSocScicFrM = new TH1F("standoutSocScicFrM", " rate of standout words in Cornell letter, cFrM ",50,0.,5.);
  TH1F* standoutSocScicFrF = new TH1F("standoutSocScicFrF", " rate of standout words in Cornell letter, cFrF ",50,0.,5.);
  TH1F* standoutSocScicMrF = new TH1F("standoutSocScicMrF", " rate of standout words in Cornell letter, cMrF ",50,0.,5.);

  TH1F* abilityPhysicscMrM = new TH1F("abilityWilsoncMrM", " rate of ability words in Wilson letter, cMrM ",50,0.,5.);
  TH1F* abilityPhysicscFrM = new TH1F("abilityWilsoncFrM", " rate of ability words in Wilson letter, cFrM ",50,0.,5.);
  TH1F* abilityPhysicscFrF = new TH1F("abilityWilsoncFrF", " rate of ability words in Wilson letter, cFrF ",50,0.,5.);
  TH1F* abilityPhysicscMrF = new TH1F("abilityWilsoncMrF", " rate of ability words in Wilson letter, cMrF ",50,0.,5.);

  TH1F* comparisonFemalePhysicscMrM = new TH1F("comparisonFemaleWilsoncMrM", " rate of comparisonFemale words in Wilson letter, cMrM ",50,0.,5.);
  TH1F* comparisonFemalePhysicscFrM = new TH1F("comparisonFemaleWilsoncFrM", " rate of comparisonFemale words in Wilson letter, cFrM ",50,0.,5.);
  TH1F* comparisonFemalePhysicscFrF = new TH1F("comparisonFemaleWilsoncFrF", " rate of comparisonFemale words in Wilson letter, cFrF ",50,0.,5.);
  TH1F* comparisonFemalePhysicscMrF = new TH1F("comparisonFemaleWilsoncMrF", " rate of comparisonFemale words in Wilson letter, cMrF ",50,0.,5.);

  TH1F* comparisonMalePhysicscMrM = new TH1F("comparisonMaleWilsoncMrM", " rate of comparisonMale words in Wilson letter, cMrM ",50,0.,5.);
  TH1F* comparisonMalePhysicscFrM = new TH1F("comparisonMaleWilsoncFrM", " rate of comparisonMale words in Wilson letter, cFrM ",50,0.,5.);
  TH1F* comparisonMalePhysicscFrF = new TH1F("comparisonMaleWilsoncFrF", " rate of comparisonMale words in Wilson letter, cFrF ",50,0.,5.);
  TH1F* comparisonMalePhysicscMrF = new TH1F("comparisonMaleWilsoncMrF", " rate of comparisonMale words in Wilson letter, cMrF ",50,0.,5.);

  TH1F* abilitySocScicMrM = new TH1F("abilitySocScicMrM", " rate of ability words in Cornell letter, cMrM ",50,0.,5.);
  TH1F* abilitySocScicFrM = new TH1F("abilitySocScicFrM", " rate of ability words in Cornell letter, cFrM ",50,0.,5.);
  TH1F* abilitySocScicFrF = new TH1F("abilitySocScicFrF", " rate of ability words in Cornell letter, cFrF ",50,0.,5.);
  TH1F* abilitySocScicMrF = new TH1F("abilitySocScicMrF", " rate of ability words in Cornell letter, cMrF ",50,0.,5.);

  TH1F* grindstonePhysicscMrM = new TH1F("grindstoneWilsoncMrM", " rate of grindstone words in Wilson letter, cMrM ",50,0.,5.);
  TH1F* grindstonePhysicscFrM = new TH1F("grindstoneWilsoncFrM", " rate of grindstone words in Wilson letter, cFrM ",50,0.,5.);
  TH1F* grindstonePhysicscFrF = new TH1F("grindstoneWilsoncFrF", " rate of grindstone words in Wilson letter, cFrF ",50,0.,5.);
  TH1F* grindstonePhysicscMrF = new TH1F("grindstoneWilsoncMrF", " rate of grindstone words in Wilson letter, cMrF ",50,0.,5.);

  TH1F* grindstoneSocScicMrM = new TH1F("grindstoneSocScicMrM", " rate of grindstone words in Cornell letter, cMrM ",50,0.,5.);
  TH1F* grindstoneSocScicFrM = new TH1F("grindstoneSocScicFrM", " rate of grindstone words in Cornell letter, cFrM ",50,0.,5.);
  TH1F* grindstoneSocScicFrF = new TH1F("grindstoneSocScicFrF", " rate of grindstone words in Cornell letter, cFrF ",50,0.,5.);
  TH1F* grindstoneSocScicMrF = new TH1F("grindstoneSocScicMrF", " rate of grindstone words in Cornell letter, cMrF ",50,0.,5.);

  TH1F* signalPhysicscMrM = new TH1F("signalWilsoncMrM", " rate of signal words in Wilson letter, cMrM ",50,0.,5.);
  TH1F* signalPhysicscFrM = new TH1F("signalWilsoncFrM", " rate of signal words in Wilson letter, cFrM ",50,0.,5.);
  TH1F* signalPhysicscFrF = new TH1F("signalWilsoncFrF", " rate of signal words in Wilson letter, cFrF ",50,0.,5.);
  TH1F* signalPhysicscMrF = new TH1F("signalWilsoncMrF", " rate of signal words in Wilson letter, cMrF ",50,0.,5.);

  TH1F* signalSocScicMrM = new TH1F("signalSocScicMrM", " rate of signal words in Cornell letter, cMrM ",50,0.,5.);
  TH1F* signalSocScicFrM = new TH1F("signalSocScicFrM", " rate of signal words in Cornell letter, cFrM ",50,0.,5.);
  TH1F* signalSocScicFrF = new TH1F("signalSocScicFrF", " rate of signal words in Cornell letter, cFrF ",50,0.,5.);
  TH1F* signalSocScicMrF = new TH1F("signalSocScicMrF", " rate of signal words in Cornell letter, cMrF ",50,0.,5.);

  //
  // some correlation plots
  TH2F* agenticVsCommunalPhysics = new TH2F("agenticVsCommunalPhysics", " agentic vs communal rates, Physics", 25, 0., 2.5, 25, 0., 2.5);
  TH2F* standoutVsGrindstonePhysics = new TH2F("standoutVsGrindstonePhysics",
					       " standout vs grindstone rates, Physics", 25, 0., 2.5, 25, 0., 2.5);
  TH2F* agenticVsCommunalSocSci = new TH2F("agenticVsCommunalSocSci", " agentic vs communal rates, SocSci", 25, 0., 2.5, 25, 0., 2.5);
  TH2F* standoutVsGrindstoneSocSci = new TH2F("standoutVsGrindstoneSocSci",
					      " standout vs grindstone rates, SocSci", 25, 0., 2.5, 25, 0., 2.5);

  
  TH2F* agenticVsCommunalPhysicsMaleCand = new TH2F("agenticVsCommunalPhysicsMaleCand", " agentic vs communal rates, PhysicsMaleCand", 10, 0., 2.5, 10, 0., 2.5);
  TH2F* standoutVsGrindstonePhysicsMaleCand = new TH2F("standoutVsGrindstonePhysicsMaleCand",
						       " standout vs grindstone rates, PhysicsMaleCand", 10, 0., 2.5, 10, 0., 2.5);
  TH2F* agenticVsCommunalSocSciMaleCand = new TH2F("agenticVsCommunalSocSciMaleCand", " agentic vs communal rates, SocSciMaleCand", 10, 0., 2.5, 10, 0., 2.5);
  TH2F* standoutVsGrindstoneSocSciMaleCand = new TH2F("standoutVsGrindstoneSocSciMaleCand",
						      " standout vs grindstone rates, SocSciMaleCand", 10, 0., 2.5, 10, 0., 2.5);
  TH2F* agenticVsCommunalPhysicsFemaleCand = new TH2F("agenticVsCommunalPhysicsFemaleCand", " agentic vs communal rates, PhysicsFemaleCand", 10, 0., 2.5, 10, 0., 2.5);
  TH2F* standoutVsGrindstonePhysicsFemaleCand = new TH2F("standoutVsGrindstonePhysicsFemaleCand",
							 " standout vs grindstone rates, PhysicsFemaleCand", 10, 0., 2.5, 10, 0., 2.5);
  TH2F* agenticVsCommunalSocSciFemaleCand = new TH2F("agenticVsCommunalSocSciFemaleCand", " agentic vs communal rates, SocSciFemaleCand", 10, 0., 2.5, 10, 0., 2.5);
  TH2F* standoutVsGrindstoneSocSciFemaleCand = new TH2F("standoutVsGrindstoneSocSciFemaleCand",
							" standout vs grindstone rates, SocSciFemaleCand", 10, 0., 2.5, 10, 0., 2.5);

  TH2F* agenticVsCommunalPhysicsMaleWriter = new TH2F("agenticVsCommunalPhysicsMaleWriter", " agentic vs communal rates, PhysicsMaleWriter", 10, 0., 2.5, 10, 0., 2.5);
  TH2F* standoutVsGrindstonePhysicsMaleWriter = new TH2F("standoutVsGrindstonePhysicsMaleWriter",
							 " standout vs grindstone rates, PhysicsMaleWriter", 10, 0., 2.5, 10, 0., 2.5);
  TH2F* agenticVsCommunalSocSciMaleWriter = new TH2F("agenticVsCommunalSocSciMaleWriter", " agentic vs communal rates, SocSciMaleWriter", 10, 0., 2.5, 10, 0., 2.5);
  TH2F* standoutVsGrindstoneSocSciMaleWriter = new TH2F("standoutVsGrindstoneSocSciMaleWriter",
							" standout vs grindstone rates, SocSciMaleWriter", 10, 0., 2.5, 10, 0., 2.5);
  TH2F* agenticVsCommunalPhysicsFemaleWriter = new TH2F("agenticVsCommunalPhysicsFemaleWriter", " agentic vs communal rates, PhysicsFemaleWriter", 10, 0., 2.5, 10, 0., 2.5);
  TH2F* standoutVsGrindstonePhysicsFemaleWriter = new TH2F("standoutVsGrindstonePhysicsFemaleWriter",
							   " standout vs grindstone rates, PhysicsFemaleWriter", 10, 0., 2.5, 10, 0., 2.5);
  TH2F* agenticVsCommunalSocSciFemaleWriter = new TH2F("agenticVsCommunalSocSciFemaleWriter", " agentic vs communal rates, SocSciFemaleWriter", 10, 0., 2.5, 10, 0., 2.5);
  TH2F* standoutVsGrindstoneSocSciFemaleWriter = new TH2F("standoutVsGrindstoneSocSciFemaleWriter",
							  " standout vs grindstone rates, SocSciFemaleWriter", 10, 0., 2.5, 10, 0., 2.5);

  
  // make some summed histos

  TH1F* sumOverMenAppPhysicsWordCount = new TH1F("sumOverMenAppPhysicsWordCount"," for all male applicants, physics, wordCount", 100,0.,5000.);
  TH1F* sumOverMenAppPhysicsAgentic = new TH1F("sumOverMenAppPhysicsAgentic"," for all male applicants, physics, agentic", 50,0.,5.);
  TH1F* sumOverMenAppPhysicsCommunal = new TH1F("sumOverMenAppPhysicsCommunal"," for all male applicants, physics, communal", 50,0.,5.);
  TH1F* sumOverMenAppPhysicsAbility = new TH1F("sumOverMenAppPhysicsAbility"," for all male applicants, physics, ability", 50,0.,5.);
  TH1F* sumOverMenAppPhysicsGrindstone = new TH1F("sumOverMenAppPhysicsGrindstone"," for all male applicants, physics, grindstone", 50,0.,5.);
  TH1F* sumOverMenAppPhysicsStandout = new TH1F("sumOverMenAppPhysicsStandout"," for all male applicants, physics, standout", 50,0.,5.);
 
  TH1F* sumOverWomenAppPhysicsWordCount = new TH1F("sumOverWomenAppPhysicsWordCount"," for all female applicants, physics, wordCount", 100,0.,5000.);
  TH1F* sumOverWomenAppPhysicsAgentic = new TH1F("sumOverWomenAppPhysicsAgentic"," for all female applicants, physics, agentic", 50,0.,5.);
  TH1F* sumOverWomenAppPhysicsCommunal = new TH1F("sumOverWomenAppPhysicsCommunal"," for all female applicants, physics, communal", 50,0.,5.);
  TH1F* sumOverWomenAppPhysicsAbility = new TH1F("sumOverWomenAppPhysicsAbilty"," for all female applicants, physics, ability", 50,0.,5.);
  TH1F* sumOverWomenAppPhysicsGrindstone = new TH1F("sumOverWomenAppPhysicsGrindstone"," for all female applicants, physics, grindstone", 50,0.,5.);
  TH1F* sumOverWomenAppPhysicsStandout = new TH1F("sumOverWomenAppPhysicsStandout"," for all female applicants, physics, standout", 50,0.,5.);


  TH1F* sumOverMenWritersPhysicsWordCount = new TH1F("sumOverMenWritersPhysicsWordCount"," for all male writers, physics, wordCount", 100,0.,5000.);
  TH1F* sumOverMenWritersPhysicsAgentic = new TH1F("sumOverMenWritersPhysicsAgentic"," for all male writers, physics, agentic", 50,0.,5.);
  TH1F* sumOverMenWritersPhysicsCommunal = new TH1F("sumOverMenWritersPhysicsCommunal"," for all male writers, physics, communal", 50,0.,5.);
  TH1F* sumOverMenWritersPhysicsAbility = new TH1F("sumOverMenWritersPhysicsAbility"," for all male writers, physics, ability", 50,0.,5.);
  TH1F* sumOverMenWritersPhysicsGrindstone = new TH1F("sumOverMenWritersPhysicsGrindstone"," for all male writers, physics, grindstone", 50,0.,5.);
  TH1F* sumOverMenWritersPhysicsStandout = new TH1F("sumOverMenWritersPhysicsStandout"," for all male writers, physics, standout", 50,0.,5.);
 
  TH1F* sumOverWomenWritersPhysicsWordCount = new TH1F("sumOverWomenWritersPhysicsWordCount"," for all female writers, physics, wordCount", 100,0.,5000.);
  TH1F* sumOverWomenWritersPhysicsAgentic = new TH1F("sumOverWomenWritersPhysicsAgentic"," for all female writers, physics, agentic", 50,0.,5.);
  TH1F* sumOverWomenWritersPhysicsCommunal = new TH1F("sumOverWomenWritersPhysicsCommunal"," for all female writers, physics, communal", 50,0.,5.);
  TH1F* sumOverWomenWritersPhysicsAbility = new TH1F("sumOverWomenWritersPhysicsAbilty"," for all female writers, physics, ability", 50,0.,5.);
  TH1F* sumOverWomenWritersPhysicsGrindstone = new TH1F("sumOverWomenWritersPhysicsGrindstone"," for all female writers, physics, grindstone", 50,0.,5.);
  TH1F* sumOverWomenWritersPhysicsStandout = new TH1F("sumOverWomenWritersPhysicsStandout"," for all female writers, physics, standout", 50,0.,5.);


  /**********socsci*********/
  TH1F* sumOverMenAppSocSciWordCount = new TH1F("sumOverMenAppSocSciWordCount"," for all male applicants, social science, wordCount", 100,0.,5000.);
  TH1F* sumOverMenAppSocSciAgentic = new TH1F("sumOverMenAppSocSciAgentic"," for all male applicants, social science, agentic", 50,0.,5.);
  TH1F* sumOverMenAppSocSciCommunal = new TH1F("sumOverMenAppSocSciWordCommunal"," for all male applicants, social science, communal", 50,0.,5.);
  TH1F* sumOverMenAppSocSciAbility = new TH1F("sumOverMenAppSocSciAbility"," for all male applicants, social science, ability", 50,0.,5.);
  TH1F* sumOverMenAppSocSciGrindstone = new TH1F("sumOverMenAppSocSciGrindstone"," for all male applicants, social science, grindstone", 50,0.,5.);
  TH1F* sumOverMenAppSocSciStandout = new TH1F("sumOverMenAppSocSciStandout"," for all male applicants, social science, standout", 50,0.,5.);
 
  TH1F* sumOverWomenAppSocSciWordCount = new TH1F("sumOverWomenAppSocSciWordCount"," for all female applicants, social science, wordCount", 100,0.,5000.);
  TH1F* sumOverWomenAppSocSciAgentic = new TH1F("sumOverWomenAppSocSciAgentic"," for all female applicants, social science, agentic", 50,0.,5.);
  TH1F* sumOverWomenAppSocSciCommunal = new TH1F("sumOverWomenAppSocSciCommunal"," for all female applicants, social science, communal", 50,0.,5.);
  TH1F* sumOverWomenAppSocSciAbility = new TH1F("sumOverWomenAppSocSciAbilty"," for all female applicants, social science, ability", 50,0.,5.);
  TH1F* sumOverWomenAppSocSciGrindstone = new TH1F("sumOverWomenAppSocSciGrindstone"," for all female applicants, social science, grindstone", 50,0.,5.);
  TH1F* sumOverWomenAppSocSciStandout = new TH1F("sumOverWomenAppSocSciStandout"," for all female applicants, social science, standout", 50,0.,5.);


  TH1F* sumOverMenWritersSocSciWordCount = new TH1F("sumOverMenWritersSocSciWordCount"," for all male writers, social science, wordCount", 100,0.,5000.);
  TH1F* sumOverMenWritersSocSciAgentic = new TH1F("sumOverMenWritersSocSciAgentic"," for all male writers, social science, agentic", 50,0.,5.);
  TH1F* sumOverMenWritersSocSciCommunal = new TH1F("sumOverMenWritersSocSciCommunal"," for all male writers, social science, communal", 50,0.,5.);
  TH1F* sumOverMenWritersSocSciAbility = new TH1F("sumOverMenWritersSocSciAbility"," for all male writers, social science, ability", 50,0.,5.);
  TH1F* sumOverMenWritersSocSciGrindstone = new TH1F("sumOverMenWritersSocSciGrindstone"," for all male writers, social science, grindstone", 50,0.,5.);
  TH1F* sumOverMenWritersSocSciWStandout = new TH1F("sumOverMenWritersSocSciStandout"," for all male writers, social science, standout", 50,0.,5.);
 
  TH1F* sumOverWomenWritersSocSciWordCount = new TH1F("sumOverWomenWritersSocSciWordCount"," for all female writers, social science, wordCount", 100,0.,5000.);
  TH1F* sumOverWomenWritersSocSciAgentic = new TH1F("sumOverWomenWritersSocSciAgentic"," for all female writers, social science, agentic", 50,0.,5.);
  TH1F* sumOverWomenWritersSocSciCommunal = new TH1F("sumOverWomenWritersSocSciCommunal"," for all female writers, social science, communal", 50,0.,5.);
  TH1F* sumOverWomenWritersSocSciAbility = new TH1F("sumOverWomenWritersSocSciAbilty"," for all female writers, social science, ability", 50,0.,5.);
  TH1F* sumOverWomenWritersSocSciGrindstone = new TH1F("sumOverWomenWritersSocSciGrindstone"," for all female writers, social science, grindstone", 50,0.,5.);
  TH1F* sumOverWomenWritersSocSciStandout = new TH1F("sumOverWomenWritersSocSciStandout"," for all female writers, social science, standout", 50,0.,5.);
 

  Float_t nt[17];
  TNtuple* physics = new TNtuple("physics","Physics Ntuple",
				 "cat:wc:WPS:Dic:standout:ability:grindstone:teaching:research:agentic:communal:comparisonMale:comparisonFemale:signalPhysics:signalSociology:ranking:negative");

  TNtuple* socsci = new TNtuple("socsci","SocSci Ntuple",
				"cat:wc:WPS:Dic:standout:ability:grindstone:teaching:research:agentic:communal:comparisonMale:comparisonFemale:signalPhysics:signalSociology:ranking:negative");


  const char* labels[4] = {"cMwM", "cMwF", "cFwF","cFwM"};
  analysisOut << "made ntuples" << std::endl;
  inputFiles.clear();
  inputFiles.seekg(0);
 

  Int_t comparisonMin = 0.0;
  wcCut = 0;
  //    physicsLength = 10;
  string headerInfo;
  Int_t oldCandId = -1;
  Int_t bothNum;
  Bool_t femaleWriter;
  Bool_t maleWriter;
  femaleWriter = false;
  maleWriter = false;
  std::getline(inputFiles,headerInfo);
  Int_t nWriters;
  nWriters = 0;
  std::cout << "letter Length = " << letterLength << std::endl;
  for (Int_t ithLetter = 0 ; ithLetter< letterLength; ++ithLetter)
    {
      std::cout << "rowNo = " << rowNo << std::endl;
           inputFiles >> rowNo >> rowHash >> bobHash >> candId >> writerId >> canGender >> writerGender >> both >> discipline
	       >> Ref_is_advisor >> Ref_nonresearch >> both_gender_non_advisor_refs >>  wc >> Analytic >> Clout >> Authentic >> Tone >>  WPS>> Dic>> function>> pronoun>> ppron>> i>> we>> you >> shehe>> they>> ipron>> article>> prep>> auxverb>> adverb>> conj>> negate>> verb>> adj>> compare>> interrog>> number>> quant>>
      affect>> posemo>> negemo>> anx>> anger>> sad >>      social >> family>> friends>> female>> male>> cogproc>> insight>> cause>> discrep>> tentat>> certain>> differ>> percept>> see>> hear>> feel>> bio>> body>> health>> sexual>> ingest>> drives>> affiliation>>
      achiev>>power>>reward>>risk>>focuspast>>focuspresent>>focusfuture >>
      relativ>>motion>>space>>time>>work>>leisure>>home>>money>>relig>>death>>informal>>swear>>netspeak>>assent>>nonflu>>filler>>AllPunc>>Period>>Comma>>Colon>>SemiC>>QMark>>Exclam>>Dash>>Quote>>
      Apostro>>Parent>>OtherP >> standout >> ability >> grindstone >> teaching >> research >> agentic >> communal >> comparisonMale >> comparisonFemale >> signalPhysics >> signalSociology >> ranking >> negative;
      if (ithLetter == 0){oldCandId = candId; nWriters = 0;}
      //      bothOut << "candidate ID " << candId << std::endl;
      // this doesn't do last person, just check externally.

	if (ithLetter > 10000){
	  analysisOut   << candidateName << " "  <<   wc <<  " "  <<  WPS <<  " "  <<  Dic <<  " "  <<  function <<  " "  <<  pronoun <<  " "  <<  ppron <<  " "  <<  i <<  " "  <<  we <<  " "  <<  you  <<  " "  <<  shehe <<  " "  <<  they <<  " "  <<  ipron  <<  " "  <<  article <<  " "
			<<  prep  <<  " "  <<  auxverb <<  " "  <<  adverb <<  " "  <<  conj <<  " "  <<  negate <<  " "  <<  verb <<  " "  <<  adj <<  " "  <<  compare <<  " "  <<  interrog <<  " "  <<  number <<  " "  <<  quant <<  "\n "
			<<  affect <<  " "  <<  posemo <<  " "  <<  negemo <<  " "  <<  anx <<  " "  <<  anger <<  " "  <<  sad  <<  " "
			<<  social  <<  " "  <<  family <<  " "  <<  friends <<  " "  <<  female <<  " "  <<  male <<  "\n "  <<  cogproc <<  " "  <<  insight <<  " "  <<  cause <<  " "  <<  discrep <<  " "  <<  tentat <<  " "  <<  certain <<  " "  <<  differ <<  " "
			<<  percept <<  " "  <<  see <<  " "  <<  hear  <<  " "  <<  feel  <<  " "  <<  bio  <<  " "  <<  body  <<  " "  <<  health <<  " "  <<  sexual <<  " "  <<  ingest  <<  " "  <<  drives  <<  " "  <<  affiliation  <<  " " 
			<<  achiev <<  " "  << power <<  " "  << reward <<  " "  << risk <<  " "  <<  focuspast <<  " "  <<  focuspresent <<  " "  <<  focusfuture  <<  "\n "  << 
	    relativ <<  " "  << motion <<  " "  << space <<  " "  << time <<  " "  << work <<  " "  << leisure <<  " "  << home <<  " "  << money <<  " "  << relig <<  " "
			<< death <<  "\n "  << informal <<  " "  << swear <<  " "  << netspeak <<  " "  << assent <<  " "  << nonflu <<  " "  << filler <<  " "  << AllPunc <<  " "  << Period <<  " "  << Comma <<  " "
			<< Colon <<  " "  << SemiC <<  " "  << QMark <<  " "  << Exclam <<  " "  << Dash <<  " "  << Quote <<  " "  << 
	    Apostro <<  " "  << Parent <<  " "  << OtherP  <<  "\n \n " <<  std::endl;
	}

      if (candId != oldCandId ){
	bothNum = 0;
	if (femaleWriter && maleWriter) bothNum = 1;
	for (Int_t iWrite = 0; iWrite< nWriters;++iWrite){
	bothOut << oldCandId << " " << bothNum << std::endl;
	}
	oldCandId = candId;
	femaleWriter = false;
	maleWriter = false;
	nWriters = 0;
      }
      if (writerGender > 0.5){
	femaleWriter= true;
	//bothOut << "female writer" << std::endl;
      }
      if (writerGender < 0.5){
	maleWriter=true;
	//	bothOut << "maleWriter" << std::endl;
      }
      ++nWriters;
 
            if (useBoth && both < 0.5) continue;
      if (discipline > 0.5) {
	//	analysisOut << "finished" << std::endl;
	//analysisOut << " candidate and writer " << canGender << " " << writerGender << " " << candId << std::endl;
	//if (writerGender < 0.5){analysisOut << "male writer " << std::endl;}
	if (wc < wcCut ) continue;
    
	if (canGender < 0.5 && writerGender < 0.5){
	  cat = 1;
	  wordCountPhysicscMrM->Fill(wc);
	  agenticPhysicscMrM->Fill(agentic);
	  communalPhysicscMrM->Fill(communal);
	  standoutPhysicscMrM->Fill(standout);
	  abilityPhysicscMrM->Fill(ability);
	  grindstonePhysicscMrM->Fill(grindstone);
	  if ( (comparisonMale+comparisonFemale) > comparisonMin){
	    comparisonMalePhysicscMrM->Fill(comparisonMale);
	    comparisonFemalePhysicscMrM->Fill(comparisonFemale);
	  }
	  sumOverMenAppPhysicsWordCount->Fill(wc);
	  sumOverMenWritersPhysicsWordCount->Fill(wc);

	  agenticVsCommunalPhysics->Fill(communal,agentic);
	  agenticVsCommunalPhysicsMaleCand->Fill(communal,agentic);
	  agenticVsCommunalPhysicsMaleWriter->Fill(communal,agentic);


	  standoutVsGrindstonePhysics->Fill(grindstone,standout);
	  standoutVsGrindstonePhysicsMaleCand->Fill(grindstone,standout);
	  standoutVsGrindstonePhysicsMaleWriter->Fill(grindstone,standout);
	  cat = 1;
	  //analysisOut << "in cat 1" << std::endl;
	  nt[0] = cat;
	  nt[1] = wc;
	  nt[2] = WPS;
	  nt[3] = Dic;
	  nt[4] = standout;
	  nt[5] = ability;
	  nt[6] = grindstone;
	  nt[7] = teaching;
	  nt[8] = research;
	  nt[9] = agentic;
	  nt[10] = communal;
	  nt[11] = comparisonMale;
	  nt[12] = comparisonFemale;
	  nt[13] = signalPhysics;
	  nt[14] = signalSociology;
	  nt[15] = ranking;
	  nt[16] = negative;
	  physics->Fill(nt);
   
	  ++nlines;
	}

    
	if ( canGender > 0.5 && writerGender < 0.5){
	  cat = 2;
	  //  analysisOut << "in cat 2" << std::endl;
	  wordCountPhysicscFrM->Fill(wc);
	  agenticPhysicscFrM->Fill(agentic);
	  communalPhysicscFrM->Fill(communal);
	  standoutPhysicscFrM->Fill(standout);
	  abilityPhysicscFrM->Fill(ability);
	  grindstonePhysicscFrM->Fill(grindstone);
	  if ( (comparisonMale+comparisonFemale) > comparisonMin){
	    comparisonMalePhysicscFrM->Fill(comparisonMale);
	    comparisonFemalePhysicscFrM->Fill(comparisonFemale);
	  }
	  sumOverWomenAppPhysicsWordCount->Fill(wc);
	  sumOverMenWritersPhysicsWordCount->Fill(wc);

	  agenticVsCommunalPhysics->Fill(communal,agentic);
	  agenticVsCommunalPhysicsFemaleCand->Fill(communal,agentic);
	  agenticVsCommunalPhysicsMaleWriter->Fill(communal,agentic);

	  standoutVsGrindstonePhysics->Fill(grindstone,standout);
	  standoutVsGrindstonePhysicsFemaleCand->Fill(grindstone,standout);
	  standoutVsGrindstonePhysicsMaleWriter->Fill(grindstone,standout);


	  nt[0] = cat;
	  nt[1] = wc;
	  nt[2] = WPS;
	  nt[3] = Dic;
	  nt[4] = standout;
	  nt[5] = ability;
	  nt[6] = grindstone;
	  nt[7] = teaching;
	  nt[8] = research;
	  nt[9] = agentic;
	  nt[10] = communal;
	  nt[11] = comparisonMale;
	  nt[12] = comparisonFemale;
	  nt[13] = signalPhysics;
	  nt[14] = signalSociology;
	  nt[15] = ranking;
	  nt[16] = negative;
	  physics->Fill(nt);
	  ++nlines;
	}

	if (canGender > 0.5 && (writerGender > 0.5)){
	  cat = 3;
	  // analysisOut << "in cat 3" << std::endl;
	  wordCountPhysicscFrF->Fill(wc);
	  agenticPhysicscFrF->Fill(agentic);
	  communalPhysicscFrF->Fill(communal);
	  standoutPhysicscFrF->Fill(standout);
	  abilityPhysicscFrF->Fill(ability);
	  grindstonePhysicscFrF->Fill(grindstone);
	  sumOverWomenAppPhysicsWordCount->Fill(wc);
	  sumOverWomenWritersPhysicsWordCount->Fill(wc);
	  if ( (comparisonMale+comparisonFemale) > comparisonMin){
	    comparisonMalePhysicscFrF->Fill(comparisonMale);
	    comparisonFemalePhysicscFrF->Fill(comparisonFemale);
	  }

	  agenticVsCommunalPhysics->Fill(communal,agentic);
	  agenticVsCommunalPhysicsFemaleCand->Fill(communal,agentic);
	  agenticVsCommunalPhysicsFemaleWriter->Fill(communal,agentic);

	  standoutVsGrindstonePhysics->Fill(grindstone,standout);
	  standoutVsGrindstonePhysicsFemaleCand->Fill(grindstone,standout);
	  standoutVsGrindstonePhysicsFemaleWriter->Fill(grindstone,standout);

	  nt[0] = cat;
	  nt[1] = wc;
	  nt[2] = WPS;
	  nt[3] = Dic;
	  nt[4] = standout;
	  nt[5] = ability;
	  nt[6] = grindstone;
	  nt[7] = teaching;
	  nt[8] = research;
	  nt[9] = agentic;
	  nt[10] = communal;
	  nt[11] = comparisonMale; 
	  nt[12] = comparisonFemale;
	  nt[13] = signalPhysics;
	  nt[14] = signalSociology;
	  nt[15] = ranking;
	  nt[16] = negative;
	  physics->Fill(nt);
	  ++nlines;
	}

	if (canGender < 0.5 && writerGender > 0.5){
	  cat = 4;
	  //	  analysisOut << "in cat 4" << std::endl;
	  wordCountPhysicscMrF->Fill(wc);
	  agenticPhysicscMrF->Fill(agentic);
	  communalPhysicscMrF->Fill(communal);
	  standoutPhysicscMrF->Fill(standout);
	  abilityPhysicscMrF->Fill(ability);
	  grindstonePhysicscMrF->Fill(grindstone);
	  sumOverMenAppPhysicsWordCount->Fill(wc);
	  sumOverWomenWritersPhysicsWordCount->Fill(wc);
	  if ( (comparisonMale + comparisonFemale) > comparisonMin){
	    comparisonMalePhysicscMrF->Fill(comparisonMale);
	    comparisonFemalePhysicscMrF->Fill(comparisonFemale);
	  }

	  agenticVsCommunalPhysics->Fill(communal,agentic);
	  agenticVsCommunalPhysicsMaleCand->Fill(communal,agentic);
	  agenticVsCommunalPhysicsFemaleWriter->Fill(communal,agentic);

	  standoutVsGrindstonePhysics->Fill(grindstone,standout);
	  standoutVsGrindstonePhysicsMaleCand->Fill(grindstone,standout);
	  standoutVsGrindstonePhysicsFemaleWriter->Fill(grindstone,standout);

	  nt[0] = cat;
	  nt[1] = wc;
	  nt[2] = WPS;
	  nt[3] = Dic;
	  nt[4] = standout;
	  nt[5] = ability;
	  nt[6] = grindstone;
	  nt[7] = teaching;
	  nt[8] = research;
	  nt[9] = agentic;
	  nt[10] = communal;
	  nt[11] = comparisonMale;
	  nt[12] = comparisonFemale;
	  nt[13] = signalPhysics;
	  nt[14] = signalSociology;
	  nt[15] = ranking;
	  nt[16] = negative;
	  physics->Fill(nt);
	  ++nlines;
	}

      
      }
      //     analysisOut << "discipline and genders = " << discipline << " " << canGender << " " << writerGender << std::endl;
      if (discipline < 0.5){
	
	if (canGender < 0.5 && writerGender < 0.5){
	  cat = 5;
	  wordCountSocScicMrM->Fill(wc);
	  agenticSocScicMrM->Fill(agentic);
	  communalSocScicMrM->Fill(communal);
	  standoutSocScicMrM->Fill(standout);
	  abilitySocScicMrM->Fill(ability);
	  grindstoneSocScicMrM->Fill(grindstone);
	  sumOverMenAppSocSciWordCount->Fill(wc);
	  sumOverMenWritersSocSciWordCount->Fill(wc);

	  agenticVsCommunalSocSci->Fill(communal,agentic);
	  agenticVsCommunalSocSciMaleCand->Fill(communal,agentic);
	  agenticVsCommunalSocSciMaleWriter->Fill(communal,agentic);

	  standoutVsGrindstoneSocSci->Fill(grindstone,standout);
	  standoutVsGrindstoneSocSciMaleCand->Fill(grindstone,standout);
	  standoutVsGrindstoneSocSciMaleWriter->Fill(grindstone,standout);

	  nt[0] = cat;
	  nt[1] = wc;
	  nt[2] = WPS;
	  nt[3] = Dic;
	  nt[4] = standout;
	  nt[5] = ability;
	  nt[6] = grindstone;
	  nt[7] = teaching;
	  nt[8] = research;
	  nt[9] = agentic;
	  nt[10] = communal;
	  nt[11] = comparisonMale;
	  nt[12] = comparisonFemale;
	  nt[13] = signalPhysics;
	  nt[14] = signalSociology;
	  nt[15] = ranking;
	  nt[16] = negative;
	  socsci->Fill(nt);
	  ++nlines;
	}
	
	if ( canGender > 0.5 && writerGender < 0.5){
	  cat = 6;
	  wordCountSocScicFrM->Fill(wc);
	  agenticSocScicFrM->Fill(agentic);
	  communalSocScicFrM->Fill(communal);
	  standoutSocScicFrM->Fill(standout);
	  abilitySocScicFrM->Fill(ability);
	  grindstoneSocScicFrM->Fill(grindstone);
	  sumOverWomenAppSocSciWordCount->Fill(wc);
	  sumOverMenWritersSocSciWordCount->Fill(wc);

	  agenticVsCommunalSocSci->Fill(communal,agentic);
	  agenticVsCommunalSocSciFemaleCand->Fill(communal,agentic);
	  agenticVsCommunalSocSciMaleWriter->Fill(communal,agentic);

	  standoutVsGrindstoneSocSci->Fill(grindstone,standout);
	  standoutVsGrindstoneSocSciFemaleCand->Fill(grindstone,standout);
	  standoutVsGrindstoneSocSciMaleWriter->Fill(grindstone,standout);

	  nt[0] = cat;
	  nt[1] = wc;
	  nt[2] = WPS;
	  nt[3] = Dic;
	  nt[4] = standout;
	  nt[5] = ability;
	  nt[6] = grindstone;
	  nt[7] = teaching;
	  nt[8] = research;
	  nt[9] = agentic;
	  nt[10] = communal;
	  nt[11] = comparisonMale;
	  nt[12] = comparisonFemale;
	  nt[13] = signalPhysics;
	  nt[14] = signalSociology;
	  nt[15] = ranking;
	  nt[16] = negative;
	  socsci->Fill(nt);
	  ++nlines;
	}


	if (canGender > 0.5 && (writerGender > 0.5)){
	  cat = 7;
	  wordCountSocScicFrF->Fill(wc);
	  agenticSocScicFrF->Fill(agentic);
	  communalSocScicFrF->Fill(communal);
	  standoutSocScicFrF->Fill(standout);
	  abilitySocScicFrF->Fill(ability);
	  grindstoneSocScicFrF->Fill(grindstone);
	  sumOverWomenAppSocSciWordCount->Fill(wc);
	  sumOverWomenWritersSocSciWordCount->Fill(wc);

	  agenticVsCommunalSocSci->Fill(communal,agentic);
	  agenticVsCommunalSocSciFemaleCand->Fill(communal,agentic);
	  agenticVsCommunalSocSciFemaleWriter->Fill(communal,agentic);

	  standoutVsGrindstoneSocSci->Fill(grindstone,standout);
	  standoutVsGrindstoneSocSciFemaleCand->Fill(grindstone,standout);
	  standoutVsGrindstoneSocSciFemaleWriter->Fill(grindstone,standout);

	  nt[0] = cat;
	  nt[1] = wc;
	  nt[2] = WPS;
	  nt[3] = Dic;
	  nt[4] = standout;
	  nt[5] = ability;
	  nt[6] = grindstone;
	  nt[7] = teaching;
	  nt[8] = research;
	  nt[9] = agentic;
	  nt[10] = communal;
	  nt[11] = comparisonMale;
	  nt[12] = comparisonFemale;
	  nt[13] = signalPhysics;
	  nt[14] = signalSociology;
	  nt[15] = ranking;
	  nt[16] = negative;
	  socsci->Fill(nt);
	  ++nlines;
	}


	if (canGender < 0.5 && writerGender > 0.5){
	  cat = 8;
	  wordCountSocScicMrF->Fill(wc);
	  agenticSocScicMrF->Fill(agentic);
	  communalSocScicMrF->Fill(communal);
	  standoutSocScicMrF->Fill(standout);
	  abilitySocScicMrF->Fill(ability);
	  grindstoneSocScicMrF->Fill(grindstone);
	  sumOverMenAppSocSciWordCount->Fill(wc);
	  sumOverWomenWritersSocSciWordCount->Fill(wc);

	  agenticVsCommunalSocSci->Fill(communal,agentic);
	  agenticVsCommunalSocSciMaleCand->Fill(communal,agentic);
	  agenticVsCommunalSocSciFemaleWriter->Fill(communal,agentic);

	  standoutVsGrindstoneSocSci->Fill(grindstone,standout);
	  standoutVsGrindstoneSocSciMaleCand->Fill(grindstone,standout);
	  standoutVsGrindstoneSocSciFemaleWriter->Fill(grindstone,standout);

	  nt[0] = cat;
	  nt[1] = wc;
	  nt[2] = WPS;
	  nt[3] = Dic;
	  nt[4] = standout;
	  nt[5] = ability;
	  nt[6] = grindstone;
	  nt[7] = teaching;
	  nt[8] = research;
	  nt[9] = agentic;
	  nt[10] = communal;
	  nt[11] = comparisonMale;
	  nt[12] = comparisonFemale;
	  nt[13] = signalPhysics;
	  nt[14] = signalSociology;
	  nt[15] = ranking;
	  nt[16] = negative;
	  socsci->Fill(nt);
	  ++nlines;
	}


      }
    }
  std::cout << "about to write physics ntuple" << std::endl;
  
  physics->Write();

  wordCountPhysicscMrM->Write();
  wordCountPhysicscFrM->Write();
  wordCountPhysicscFrF->Write();
  wordCountPhysicscFrM->Write();


  agenticPhysicscMrM->Write();
  agenticPhysicscFrM->Write();
  agenticPhysicscFrF->Write();
  agenticPhysicscFrM->Write();
 
  communalPhysicscMrM->Write();
  communalPhysicscFrM->Write();
  communalPhysicscFrF->Write();
  communalPhysicscFrM->Write();

  abilityPhysicscMrM->Write();
  abilityPhysicscFrM->Write();
  abilityPhysicscFrF->Write();
  abilityPhysicscFrM->Write();

  grindstonePhysicscMrM->Write();
  grindstonePhysicscFrM->Write();
  grindstonePhysicscFrF->Write();
  grindstonePhysicscFrM->Write();

  standoutPhysicscMrM->Write();
  standoutPhysicscFrM->Write();
  standoutPhysicscFrF->Write();
  standoutPhysicscFrM->Write();
  //  analysisOut << "everything in physics written" << std::endl;
 
  
  sumOverMenWritersPhysicsWordCount->Write();
  sumOverMenAppPhysicsWordCount->Write();
  sumOverWomenWritersPhysicsWordCount->Write();
  sumOverWomenAppPhysicsWordCount->Write();
  sumOverMenWritersSocSciWordCount->Write();
  sumOverMenAppSocSciWordCount->Write();
  sumOverWomenWritersSocSciWordCount->Write();
  sumOverWomenAppSocSciWordCount->Write();


  socsci->Write();
 
  agenticSocScicMrM->Write();
  agenticSocScicFrM->Write();
  agenticSocScicFrF->Write();
  agenticSocScicMrF->Write();
 
  communalSocScicMrM->Write();
  communalSocScicFrM->Write();
  communalSocScicFrF->Write();
  communalSocScicMrF->Write();

  abilitySocScicMrM->Write();
  abilitySocScicFrM->Write();
  abilitySocScicFrF->Write();
  abilitySocScicMrF->Write();

  grindstoneSocScicMrM->Write();
  grindstoneSocScicFrM->Write();
  grindstoneSocScicFrF->Write();
  grindstoneSocScicMrF->Write();

  standoutSocScicMrM->Write();
  standoutSocScicFrM->Write();
  standoutSocScicFrF->Write();
  standoutSocScicMrF->Write();
  


  
  wordCountSocScicMrM->Write();
  wordCountSocScicFrM->Write();
  wordCountSocScicFrF->Write();
  wordCountSocScicMrF->Write();

  agenticSocScicMrM->Write();
  agenticSocScicFrM->Write();
  agenticSocScicFrF->Write();
  agenticSocScicMrF->Write();
 
  communalSocScicMrM->Write();
  communalSocScicFrM->Write();
  communalSocScicFrF->Write();
  communalSocScicMrF->Write();
 
 
  //  analysisOut << "finished socsci" << std::endl;
      



  gStyle->SetOptFit(1);
  //
  // get means and errors.  Look at ratio M/F and make a big TGraphErrors

 
 Double_t par0;
  Double_t err0;
  TF1* fitRaw = new TF1("fits","[0]",0.,10.);
  fitRaw->SetParNames("average");
 
  
  TCanvas* c1 = new TCanvas();
  c1->Divide(2,1);
  c1->cd(2);

  
  Float_t x2[4] = {1.,2.,3.,4.};
  Float_t y2[4] = {
    static_cast<Float_t>(wordCountPhysicscMrM->GetMean()),
    static_cast<Float_t>(wordCountPhysicscFrM->GetMean()),
    static_cast<Float_t>(wordCountPhysicscMrF->GetMean()),
    static_cast<Float_t>(wordCountPhysicscFrF->GetMean())
  };
  Float_t ex2[4] = {0.1,0.1,0.1,0.1};
  Float_t ey2[4] = {
    static_cast<Float_t>(wordCountPhysicscMrM->GetMeanError()),
    static_cast<Float_t>(wordCountPhysicscFrM->GetMeanError()),
    static_cast<Float_t>(wordCountPhysicscMrF->GetMeanError()),
    static_cast<Float_t>(wordCountPhysicscFrF->GetMeanError())
  };

  TGraphErrors* wordCountsPhysics = new TGraphErrors(4,x2,y2,ex2,ey2);
  wordCountsPhysics->SetTitle("             EPP Word Count          ");

  TFitResultPtr fitWordCountsPhysics = wordCountsPhysics->Fit("fits","S");
  Double_t parWordCountsPhysics = fitWordCountsPhysics->Value(0);
  Double_t errWordCountsPhysics = fitWordCountsPhysics->ParError(0);

  TAxis* yAxisWordCountsPhysics = wordCountsPhysics->GetYaxis();
   yAxisWordCountsPhysics->SetTitle("Number of Words");
   yAxisWordCountsPhysics->SetTickLength(0.);
  TAxis* xaxisWordCountsPhysics= wordCountsPhysics->GetXaxis();
  xaxisWordCountsPhysics->SetTickLength(0.);
  xaxisWordCountsPhysics->ChangeLabel(1,-1.,-1.,-1,-1,-1,"#splitline{cand. M}{writer M}");
  xaxisWordCountsPhysics->ChangeLabel(3,-1.,-1.,-1,-1,-1,"#splitline{cand. F}{writer M}");
  xaxisWordCountsPhysics->ChangeLabel(5,-1.,-1.,-1,-1,-1,"#splitline{cand. M}{writer F}");
  xaxisWordCountsPhysics->ChangeLabel(7,-1.,-1.,-1,-1,-1,"#splitline{cand. F}{writer F}");
  xaxisWordCountsPhysics->ChangeLabel(2,-1.,0.);
  xaxisWordCountsPhysics->ChangeLabel(4,-1.,0.);
  xaxisWordCountsPhysics->ChangeLabel(6,-1.,0.);
  xaxisWordCountsPhysics->ChangeLabel(1,-1.,-1.,-1,-1,-1," ");
  xaxisWordCountsPhysics->ChangeLabel(3,-1.,-1.,-1,-1,-1," ");
  xaxisWordCountsPhysics->ChangeLabel(5,-1.,-1.,-1,-1,-1," ");
  xaxisWordCountsPhysics->ChangeLabel(7,-1.,-1.,-1,-1,-1," ");
  xaxisWordCountsPhysics->ChangeLabel(2,-1.,0.);
  xaxisWordCountsPhysics->ChangeLabel(4,-1.,0.);
  xaxisWordCountsPhysics->ChangeLabel(6,-1.,0.);
 
  wordCountsPhysics->SetFillColor(38);
  wordCountsPhysics->Draw("AB");
  TBox* boxWordCountsPhysics = new TBox(0.6,parWordCountsPhysics-errWordCountsPhysics,4.4,parWordCountsPhysics+errWordCountsPhysics);
  boxWordCountsPhysics->SetFillColor(kBlue);
  boxWordCountsPhysics->SetFillStyle(3004);
  wordCountsPhysics->SetMaximum(parWordCountsPhysics+5.*wordCountPhysicscFrF->GetMeanError());
  wordCountsPhysics->SetMinimum(TMath::Max(parWordCountsPhysics-5.*wordCountPhysicscFrF->GetMeanError(),0.));
  boxWordCountsPhysics->Draw();


  wordCountsPhysics->Write();


  if (useBoth){
  c1->SaveAs("pdfPlotsBoth/physicsWC.pdf");
  }else { c1->SaveAs("pdfPlots/physicsWC.pdf");}

  c1->cd(1);
  Float_t x1[4] = {1.,2.,3.,4.};
  Float_t y1[4] = {
    static_cast<Float_t>(wordCountSocScicMrM->GetMean()),
    static_cast<Float_t>(wordCountSocScicFrM->GetMean()),
    static_cast<Float_t>(wordCountSocScicMrF->GetMean()),
    static_cast<Float_t>(wordCountSocScicFrF->GetMean())
  };
  Float_t ex1[4] = {0.1,0.1,0.1,0.1};
  Float_t ey1[4] = {
    static_cast<Float_t>(wordCountSocScicMrM->GetMeanError()),
    static_cast<Float_t>(wordCountSocScicFrM->GetMeanError()),
    static_cast<Float_t>(wordCountSocScicMrF->GetMeanError()),
    static_cast<Float_t>(wordCountSocScicFrF->GetMeanError())
  };

  
  TGraphErrors* wordCountsSocSci = new TGraphErrors(4,x1,y1,ex1,ey1);
  wordCountsSocSci->SetMaximum(1250.);
  wordCountsSocSci->SetMinimum(750.);
  wordCountsSocSci->SetTitle("         Social Science Word Count        ");
  TFitResultPtr fit = wordCountsSocSci->Fit("fits","S");
  par0 = fit->Value(0);
  err0 = fit->ParError(0);
  TAxis* yAxisWordCountsSocSci = wordCountsSocSci->GetYaxis();
  yAxisWordCountsSocSci->SetTitle("Number of Words");
  yAxisWordCountsSocSci->SetTickLength(0.);
  TAxis* xaxisWordCountsSocSci = wordCountsSocSci->GetXaxis();
  xaxisWordCountsSocSci->SetTickLength(0.);
   xaxisWordCountsSocSci->ChangeLabel(1,-1.,-1.,-1,-1,-1,"#splitline{cand. M}{writer M}");
  xaxisWordCountsSocSci->ChangeLabel(3,-1.,-1.,-1,-1,-1,"#splitline{cand. F}{writer M}");
  xaxisWordCountsSocSci->ChangeLabel(5,-1.,-1.,-1,-1,-1,"#splitline{cand. M}{writer F}");
  xaxisWordCountsSocSci->ChangeLabel(7,-1.,-1.,-1,-1,-1,"#splitline{cand. F}{writer F}");
  xaxisWordCountsSocSci->ChangeLabel(2,-1.,0.);
  xaxisWordCountsSocSci->ChangeLabel(4,-1.,0.);
  xaxisWordCountsSocSci->ChangeLabel(6,-1.,0.);
  xaxisWordCountsSocSci->ChangeLabel(1,-1.,-1.,-1,-1,-1," ");
  xaxisWordCountsSocSci->ChangeLabel(3,-1.,-1.,-1,-1,-1," ");
  xaxisWordCountsSocSci->ChangeLabel(5,-1.,-1.,-1,-1,-1," ");
  xaxisWordCountsSocSci->ChangeLabel(7,-1.,-1.,-1,-1,-1," ");
  xaxisWordCountsSocSci->ChangeLabel(2,-1.,0.);
  xaxisWordCountsSocSci->ChangeLabel(4,-1.,0.);
  xaxisWordCountsSocSci->ChangeLabel(6,-1.,0.);
  wordCountsSocSci->SetFillColor(38);
  wordCountsSocSci->SetMaximum(par0 + 5.*wordCountSocScicFrF->GetMeanError());
  wordCountsSocSci->SetMinimum(TMath::Max(par0 - 5.*wordCountSocScicFrF->GetMeanError(),0.));
   wordCountsSocSci->Draw("AB");
  //wordCountsSocSci->SetMinimum(0.);

  TBox* boxWordCountsSocSci = new TBox(0.6,par0-err0,4.4,par0+err0);
  boxWordCountsSocSci->SetFillColor(kBlue);
  boxWordCountsSocSci->SetFillStyle(3004);
  boxWordCountsSocSci->Draw();

  if (useBoth){
    c1->SaveAs("pdfPlotsBoth/SocSciWC.pdf");
  }else
    {
      c1->SaveAs("pdfPlots/SocSciWC.pdf");
    }

 

  analysisOut  << "summary word count " << std::endl;
					    
  analysisOut <<  static_cast<Float_t>(wordCountPhysicscMrM->GetMean()) << " " << 
    static_cast<Float_t>(wordCountPhysicscFrM->GetMean()) << " " << 
    static_cast<Float_t>(wordCountPhysicscMrF->GetMean()) << " " <<
    static_cast<Float_t>(wordCountPhysicscFrF->GetMean()) << " " << std::endl;
    
  analysisOut <<    static_cast<Float_t>(wordCountPhysicscMrM->GetMeanError()) << " " << 
    static_cast<Float_t>(wordCountPhysicscFrM->GetMeanError()) << " " << 
    static_cast<Float_t>(wordCountPhysicscFrM->GetMeanError()) << " " <<
    static_cast<Float_t>(wordCountPhysicscFrF->GetMeanError()) << " " << std::endl;


  analysisOut <<    static_cast<Float_t>(wordCountSocScicMrM->GetMean()) << " " << 
    static_cast<Float_t>(wordCountSocScicFrM->GetMean()) << " " << 
    static_cast<Float_t>(wordCountSocScicMrF->GetMean()) << " " <<
    static_cast<Float_t>(wordCountSocScicFrF->GetMean()) << " " << std::endl;
    
  analysisOut <<    static_cast<Float_t>(wordCountSocScicMrM->GetMeanError()) << " " << 
    static_cast<Float_t>(wordCountSocScicFrM->GetMeanError()) << " " << 
    static_cast<Float_t>(wordCountSocScicMrF->GetMeanError()) << " " <<
    static_cast<Float_t>(wordCountSocScicFrF->GetMeanError()) << " " << std::endl;

   analysisOut << "summary standout" << std::endl;

  analysisOut <<  static_cast<Float_t>(standoutPhysicscMrM->GetMean()) << " " << 
    static_cast<Float_t>(standoutPhysicscFrM->GetMean()) << " " << 
    static_cast<Float_t>(standoutPhysicscMrF->GetMean()) << " " <<
    static_cast<Float_t>(standoutPhysicscFrF->GetMean()) << " " << std::endl;

    
    analysisOut <<    static_cast<Float_t>(standoutPhysicscMrM->GetMeanError()) << " " << 
    static_cast<Float_t>(standoutPhysicscFrM->GetMeanError()) << " " << 
    static_cast<Float_t>(standoutPhysicscMrF->GetMeanError()) << " " <<
    static_cast<Float_t>(standoutPhysicscFrF->GetMeanError()) << " " << std::endl;

  analysisOut <<    static_cast<Float_t>(standoutSocScicMrM->GetMean()) << " " << 
    static_cast<Float_t>(standoutSocScicFrM->GetMean()) << " " << 
    static_cast<Float_t>(standoutSocScicFrF->GetMean()) << " " <<
    static_cast<Float_t>(standoutSocScicMrF->GetMean()) << " " << std::endl;

   
  analysisOut <<    static_cast<Float_t>(standoutSocScicMrM->GetMeanError()) << " " << 
    static_cast<Float_t>(standoutSocScicFrM->GetMeanError()) << " " << 
    static_cast<Float_t>(standoutSocScicMrF->GetMeanError()) << " " <<
    static_cast<Float_t>(standoutSocScicFrF->GetMeanError()) << " " << std::endl;
  
  analysisOut << " summary grindstone" << std::endl;
  analysisOut <<    static_cast<Float_t>(grindstonePhysicscMrM->GetMean()) << " " << 
    static_cast<Float_t>(grindstonePhysicscFrM->GetMean()) << " " << 
    static_cast<Float_t>(grindstonePhysicscMrF->GetMean()) << " " <<
    static_cast<Float_t>(grindstonePhysicscFrF->GetMean()) << " " << std::endl;

    
  analysisOut <<    static_cast<Float_t>(grindstonePhysicscMrM->GetMeanError()) << " " << 
    static_cast<Float_t>(grindstonePhysicscFrM->GetMeanError()) << " " << 
    static_cast<Float_t>(grindstonePhysicscMrF->GetMeanError()) << " " <<
    static_cast<Float_t>(grindstonePhysicscFrF->GetMeanError()) << " " << std::endl;



  analysisOut <<    static_cast<Float_t>(grindstoneSocScicMrM->GetMean()) << " " << 
    static_cast<Float_t>(grindstoneSocScicFrM->GetMean()) << " " << 
    static_cast<Float_t>(grindstoneSocScicMrF->GetMean()) << " " <<
    static_cast<Float_t>(grindstoneSocScicFrF->GetMean()) << " " << std::endl;

   
  analysisOut <<    static_cast<Float_t>(grindstoneSocScicMrM->GetMeanError()) << " " << 
    static_cast<Float_t>(grindstoneSocScicFrM->GetMeanError()) << " " << 
    static_cast<Float_t>(grindstoneSocScicMrF->GetMeanError()) << " " <<
    static_cast<Float_t>(grindstoneSocScicFrF->GetMeanError()) << " " << std::endl;


  /* agentic and communal*/
  analysisOut << "summary agentic" << std::endl;
  analysisOut <<    static_cast<Float_t>(agenticPhysicscMrM->GetMean()) << " " << 
    static_cast<Float_t>(agenticPhysicscFrM->GetMean()) << " " << 
    static_cast<Float_t>(agenticPhysicscMrF->GetMean()) << " " <<
    static_cast<Float_t>(agenticPhysicscFrF->GetMean()) << " " << std::endl;


				      
  analysisOut <<    static_cast<Float_t>(agenticPhysicscMrM->GetMeanError()) << " " << 
    static_cast<Float_t>(agenticPhysicscFrM->GetMeanError()) << " " << 
    static_cast<Float_t>(agenticPhysicscMrF->GetMeanError()) << " " <<
    static_cast<Float_t>(agenticPhysicscFrF->GetMeanError()) << " " << std::endl;



  analysisOut <<    static_cast<Float_t>(agenticSocScicMrM->GetMean()) << " " << 
    static_cast<Float_t>(agenticSocScicFrM->GetMean()) << " " << 
    static_cast<Float_t>(agenticSocScicMrF->GetMean()) << " " <<
    static_cast<Float_t>(agenticSocScicFrF->GetMean()) << " " << std::endl;

   
  analysisOut <<    static_cast<Float_t>(agenticSocScicMrM->GetMeanError()) << " " << 
    static_cast<Float_t>(agenticSocScicFrM->GetMeanError()) << " " << 
    static_cast<Float_t>(agenticSocScicMrF->GetMeanError()) << " " <<
    static_cast<Float_t>(agenticSocScicFrF->GetMeanError()) << " " << std::endl;

  analysisOut << "summary communal" << std::endl;
  analysisOut <<    static_cast<Float_t>(communalPhysicscMrM->GetMean()) << " " << 
    static_cast<Float_t>(communalPhysicscFrM->GetMean()) << " " << 
    static_cast<Float_t>(communalPhysicscMrF->GetMean()) << " " <<
    static_cast<Float_t>(communalPhysicscFrF->GetMean()) << " " << std::endl;


				      
  analysisOut <<    static_cast<Float_t>(communalPhysicscMrM->GetMeanError()) << " " << 
    static_cast<Float_t>(communalPhysicscFrM->GetMeanError()) << " " << 
    static_cast<Float_t>(communalPhysicscMrF->GetMeanError()) << " " <<
    static_cast<Float_t>(communalPhysicscFrF->GetMeanError()) << " " << std::endl;



  analysisOut <<    static_cast<Float_t>(communalSocScicMrM->GetMean()) << " " << 
    static_cast<Float_t>(communalSocScicFrM->GetMean()) << " " << 
    static_cast<Float_t>(communalSocScicMrF->GetMean()) << " " <<
    static_cast<Float_t>(communalSocScicFrF->GetMean()) << " " << std::endl;

   
  analysisOut <<    static_cast<Float_t>(communalSocScicMrM->GetMeanError()) << " " << 
    static_cast<Float_t>(communalSocScicFrM->GetMeanError()) << " " << 
    static_cast<Float_t>(communalSocScicMrF->GetMeanError()) << " " <<
    static_cast<Float_t>(communalSocScicFrF->GetMeanError()) << " " << std::endl;

								       analysisOut << "all done" << std::endl;
 TCanvas* c2 = new TCanvas();
 c2->Divide(2);
 c2->cd(2);
  Float_t xStandoutPhysics[4] = {1.,2.,3.,4.};
  Float_t yStandoutPhysics[4] = {
    static_cast<Float_t>(standoutPhysicscMrM->GetMean()),
    static_cast<Float_t>(standoutPhysicscFrM->GetMean()),
    static_cast<Float_t>(standoutPhysicscMrF->GetMean()),
    static_cast<Float_t>(standoutPhysicscFrF->GetMean())
  };
  Float_t exStandoutPhysics[4] = {0.1,0.1,0.1,0.1};
  Float_t eyStandoutPhysics[4] = {
    static_cast<Float_t>(standoutPhysicscMrM->GetMeanError()),
    static_cast<Float_t>(standoutPhysicscFrM->GetMeanError()),
    static_cast<Float_t>(standoutPhysicscMrF->GetMeanError()),
    static_cast<Float_t>(standoutPhysicscFrF->GetMeanError())
  };

  TGraphErrors* standoutPhysics = new TGraphErrors(4,xStandoutPhysics,yStandoutPhysics,exStandoutPhysics,eyStandoutPhysics);
  standoutPhysics->SetMaximum(1.7);
  standoutPhysics->SetMinimum(0.7);
  standoutPhysics->SetTitle("EPP Standout");
  TFitResultPtr fitStandoutPhysics = standoutPhysics->Fit("fits","S");
  par0 = fitStandoutPhysics->Value(0);
  err0 = fitStandoutPhysics->ParError(0);
  TAxis* yAxisStandoutPhysics = standoutPhysics->GetYaxis();
  yAxisStandoutPhysics->SetTitle("% of Words");
  yAxisStandoutPhysics->SetTickLength(0.);
 
  TAxis* xaxisStandoutPhysics = standoutPhysics->GetXaxis();
   xaxisStandoutPhysics->SetTickLength(0.);
   xaxisStandoutPhysics->ChangeLabel(1,-1.,-1.,-1,-1,-1,"#splitline{cand. M}{writer M}");
  xaxisStandoutPhysics->ChangeLabel(3,-1.,-1.,-1,-1,-1,"#splitline{cand. F}{writer M}");
  xaxisStandoutPhysics->ChangeLabel(5,-1.,-1.,-1,-1,-1,"#splitline{cand. M}{writer F}");
  xaxisStandoutPhysics->ChangeLabel(7,-1.,-1.,-1,-1,-1,"#splitline{cand. F}{writer F}");
  xaxisStandoutPhysics->ChangeLabel(2,-1.,0.);
  xaxisStandoutPhysics->ChangeLabel(4,-1.,0.);
  xaxisStandoutPhysics->ChangeLabel(6,-1.,0.);
  xaxisStandoutPhysics->ChangeLabel(1,-1.,-1.,-1,-1,-1," ");
  xaxisStandoutPhysics->ChangeLabel(3,-1.,-1.,-1,-1,-1," ");
  xaxisStandoutPhysics->ChangeLabel(5,-1.,-1.,-1,-1,-1," ");
  xaxisStandoutPhysics->ChangeLabel(7,-1.,-1.,-1,-1,-1," ");
  xaxisStandoutPhysics->ChangeLabel(2,-1.,0.);
  xaxisStandoutPhysics->ChangeLabel(4,-1.,0.);
  xaxisStandoutPhysics->ChangeLabel(6,-1.,0.);
  standoutPhysics->SetFillColor(38);
  standoutPhysics->SetMaximum(par0 + 5.*standoutPhysicscFrF->GetMeanError());
  standoutPhysics->SetMinimum(TMath::Max(par0 - 5.*standoutPhysicscFrF->GetMeanError(),0.));

  standoutPhysics->Draw("AB");
  TBox* boxStandoutPhysics = new TBox(0.6,par0-err0,4.4,par0+err0);
  boxStandoutPhysics->SetFillColor(kBlue);
  boxStandoutPhysics->SetFillStyle(3004);
  boxStandoutPhysics->Draw();

  standoutPhysics->Write();
  if (useBoth)
    {c2->SaveAs("pdfPlotsBoth/physicsStandout.pdf");}
  else{c2->SaveAs("pdfPlots/physicsStandout.pdf");}

  c2->cd(1);
  //  TCanvas* c4 = new TCanvas();

  analysisOut <<    static_cast<Float_t>(standoutSocScicMrM->GetMean()) << " " << 
    static_cast<Float_t>(standoutSocScicFrM->GetMean()) << " " << 
    static_cast<Float_t>(standoutSocScicFrF->GetMean()) << " " <<
    static_cast<Float_t>(standoutSocScicMrF->GetMean()) << " " << std::endl;
 
  Float_t xStandoutSocSci[4] = {1.,2.,3.,4.};
  Float_t yStandoutSocSci[4] = {
    static_cast<Float_t>(standoutSocScicMrM->GetMean()),
    static_cast<Float_t>(standoutSocScicFrM->GetMean()),
    static_cast<Float_t>(standoutSocScicMrF->GetMean()),
    static_cast<Float_t>(standoutSocScicFrF->GetMean())
  };
  Float_t exStandoutSocSci[4] = {0.1,0.1,0.1,0.1};
  Float_t eyStandoutSocSci[4] = {
    static_cast<Float_t>(standoutSocScicMrM->GetMeanError()),
    static_cast<Float_t>(standoutSocScicFrM->GetMeanError()),
    static_cast<Float_t>(standoutSocScicMrF->GetMeanError()),
    static_cast<Float_t>(standoutSocScicFrF->GetMeanError())
  };

  TGraphErrors* standoutSocSci = new TGraphErrors(4,xStandoutSocSci,yStandoutSocSci,exStandoutSocSci,eyStandoutSocSci);
  standoutSocSci->SetTitle("Social Science Standout");
  TFitResultPtr fit4 = standoutSocSci->Fit("fits","S");
  par0 = fit4->Value(0);
  err0 = fit4->ParError(0);
   TAxis* yAxisStandoutSocSci = standoutSocSci->GetYaxis();
   yAxisStandoutSocSci->SetTitle("% of Words");
  yAxisStandoutSocSci->SetTickLength(0.);

  TAxis* xaxisStandoutSocSci = standoutSocSci->GetXaxis();
   xaxisStandoutSocSci->SetTickLength(0.);
   xaxisStandoutSocSci->ChangeLabel(1,-1.,-1.,-1,-1,-1,"#splitline{cand. M}{writer M}");
  xaxisStandoutSocSci->ChangeLabel(3,-1.,-1.,-1,-1,-1,"#splitline{cand. F}{writer M}");
  xaxisStandoutSocSci->ChangeLabel(5,-1.,-1.,-1,-1,-1,"#splitline{cand. M}{writer F}");
  xaxisStandoutSocSci->ChangeLabel(7,-1.,-1.,-1,-1,-1,"#splitline{cand. F}{writer F}");
  xaxisStandoutSocSci->ChangeLabel(2,-1.,0.);
  xaxisStandoutSocSci->ChangeLabel(4,-1.,0.);
  xaxisStandoutSocSci->ChangeLabel(6,-1.,0.);
  xaxisStandoutSocSci->ChangeLabel(1,-1.,-1.,-1,-1,-1," ");
  xaxisStandoutSocSci->ChangeLabel(3,-1.,-1.,-1,-1,-1," ");
  xaxisStandoutSocSci->ChangeLabel(5,-1.,-1.,-1,-1,-1," ");
  xaxisStandoutSocSci->ChangeLabel(7,-1.,-1.,-1,-1,-1," ");
  xaxisStandoutSocSci->ChangeLabel(2,-1.,0.);
  xaxisStandoutSocSci->ChangeLabel(4,-1.,0.);
  xaxisStandoutSocSci->ChangeLabel(6,-1.,0.);
  standoutSocSci->SetFillColor(38);


  standoutSocSci->SetMaximum(par0 + 5.*standoutSocScicFrF->GetMeanError());
  standoutSocSci->SetMinimum(TMath::Max(par0 - 5.*standoutSocScicFrF->GetMeanError(),0.));

  standoutSocSci->Draw("AB");
  TBox* boxStandoutSocSci = new TBox(0.6,par0-err0,4.4,par0+err0);
  boxStandoutSocSci->SetFillColor(kBlue);
  boxStandoutSocSci->SetFillStyle(3004);
  boxStandoutSocSci->Draw();

  standoutSocSci->Write();
  if (useBoth){
    c2->SaveAs("pdfPlotsBoth/SocSciStandout.pdf");
  }else {c2->SaveAs("pdfPlots/SocSciStandout.pdf");}


    TCanvas* c3 = new TCanvas();
   c3->Divide(2);
  c3->cd(2);

    Float_t xGrindstonePhysics[4] = {1.,2.,3.,4.};
  Float_t yGrindstonePhysics[4] = {
    static_cast<Float_t>(grindstonePhysicscMrM->GetMean()),
    static_cast<Float_t>(grindstonePhysicscFrM->GetMean()),
    static_cast<Float_t>(grindstonePhysicscMrF->GetMean()),
    static_cast<Float_t>(grindstonePhysicscFrF->GetMean())
  };
  Float_t exGrindstonePhysics[4] = {0.1,0.1,0.1,0.1};
  Float_t eyGrindstonePhysics[4] = {
    static_cast<Float_t>(grindstonePhysicscMrM->GetMeanError()),
    static_cast<Float_t>(grindstonePhysicscFrM->GetMeanError()),
    static_cast<Float_t>(grindstonePhysicscMrF->GetMeanError()),
    static_cast<Float_t>(grindstonePhysicscFrF->GetMeanError())
  };

  TGraphErrors* grindstonePhysics = new TGraphErrors(4,xGrindstonePhysics,yGrindstonePhysics,exGrindstonePhysics,eyGrindstonePhysics);
  grindstonePhysics->SetTitle("EPP Grindstone");
  TFitResultPtr fitGrindstonePhysics = grindstonePhysics->Fit("fits","S");
  par0 = fitGrindstonePhysics->Value(0);
  err0 = fitGrindstonePhysics->ParError(0);
    TAxis* yAxisGrindstonePhysics = grindstonePhysics->GetYaxis();
  yAxisGrindstonePhysics->SetTitle("% of Words");
  yAxisGrindstonePhysics->SetTickLength(0.);

  TAxis* xaxisGrindstonePhysics = grindstonePhysics->GetXaxis();
  xaxisGrindstonePhysics->SetTickLength(0.);
   xaxisGrindstonePhysics->ChangeLabel(1,-1.,-1.,-1,-1,-1,"#splitline{cand. M}{writer M}");
  xaxisGrindstonePhysics->ChangeLabel(3,-1.,-1.,-1,-1,-1,"#splitline{cand. F}{writer M}");
  xaxisGrindstonePhysics->ChangeLabel(5,-1.,-1.,-1,-1,-1,"#splitline{cand. M}{writer F}");
  xaxisGrindstonePhysics->ChangeLabel(7,-1.,-1.,-1,-1,-1,"#splitline{cand. F}{writer F}");
  xaxisGrindstonePhysics->ChangeLabel(2,-1.,0.);
  xaxisGrindstonePhysics->ChangeLabel(4,-1.,0.);
  xaxisGrindstonePhysics->ChangeLabel(6,-1.,0.);
  xaxisGrindstonePhysics->ChangeLabel(1,-1.,-1.,-1,-1,-1," ");
  xaxisGrindstonePhysics->ChangeLabel(3,-1.,-1.,-1,-1,-1," ");
  xaxisGrindstonePhysics->ChangeLabel(5,-1.,-1.,-1,-1,-1," ");
  xaxisGrindstonePhysics->ChangeLabel(7,-1.,-1.,-1,-1,-1," ");
  xaxisGrindstonePhysics->ChangeLabel(2,-1.,0.);
  xaxisGrindstonePhysics->ChangeLabel(4,-1.,0.);
  xaxisGrindstonePhysics->ChangeLabel(6,-1.,0.);
  grindstonePhysics->SetFillColor(38);

  grindstonePhysics->SetMaximum(par0 + 5.*grindstonePhysicscFrF->GetMeanError());
  grindstonePhysics->SetMinimum(TMath::Max(par0 - 5.*grindstonePhysicscFrF->GetMeanError(),0.));

  grindstonePhysics->Draw("AB");
  TBox* boxGrindstonePhysics = new TBox(0.6,par0-err0,4.4,par0+err0);
  boxGrindstonePhysics->SetFillColor(kBlue);
  boxGrindstonePhysics->SetFillStyle(3004);
  boxGrindstonePhysics->Draw();

  grindstonePhysics->Write();
  if (useBoth)
    {c2->SaveAs("pdfPlotsBoth/physicsGrindstone.pdf");}
  else{c2->SaveAs("pdfPlots/physicsGrindstone.pdf");}
  
     // TCanvas* c4 = new TCanvas();
  c3->cd(1);

  analysisOut <<    static_cast<Float_t>(grindstoneSocScicMrM->GetMean()) << " " << 
    static_cast<Float_t>(grindstoneSocScicFrM->GetMean()) << " " << 
    static_cast<Float_t>(grindstoneSocScicFrF->GetMean()) << " " <<
    static_cast<Float_t>(grindstoneSocScicMrF->GetMean()) << " " << std::endl;
 
  Float_t x4[4] = {1.,2.,3.,4.};
  Float_t y4[4] = {
    static_cast<Float_t>(grindstoneSocScicMrM->GetMean()),
    static_cast<Float_t>(grindstoneSocScicFrM->GetMean()),
    static_cast<Float_t>(grindstoneSocScicMrF->GetMean()),
    static_cast<Float_t>(grindstoneSocScicFrF->GetMean())
  };
  Float_t ex4[4] = {0.1,0.1,0.1,0.1};
  Float_t ey4[4] = {
    static_cast<Float_t>(grindstoneSocScicMrM->GetMeanError()),
    static_cast<Float_t>(grindstoneSocScicFrM->GetMeanError()),
    static_cast<Float_t>(grindstoneSocScicMrF->GetMeanError()),
    static_cast<Float_t>(grindstoneSocScicFrF->GetMeanError())
  };

  TGraphErrors* grindstoneSocSci = new TGraphErrors(4,x4,y4,ex4,ey4);
  grindstoneSocSci->SetMaximum(2.0);
  grindstoneSocSci->SetMinimum(1.0);
  grindstoneSocSci->SetTitle("Social Science Grindstone");
  TFitResultPtr fitGrindstoneSocSci = grindstoneSocSci->Fit("fits","S");
  par0 = fitGrindstoneSocSci->Value(0);
  err0 = fitGrindstoneSocSci->ParError(0);
    TAxis* yAxisGrindstoneSocSci = grindstoneSocSci->GetYaxis();
  yAxisGrindstoneSocSci->SetTitle("% of Words");
  yAxisGrindstoneSocSci->SetTickLength(0.);
  TAxis* xaxisGrindstoneSocSci = grindstoneSocSci->GetXaxis();
  xaxisGrindstoneSocSci->SetTickLength(0.);
  xaxisGrindstoneSocSci->ChangeLabel(1,-1.,-1.,-1,-1,-1,"#splitline{cand. M}{writer M}");
  xaxisGrindstoneSocSci->ChangeLabel(3,-1.,-1.,-1,-1,-1,"#splitline{cand. F}{writer M}");
  xaxisGrindstoneSocSci->ChangeLabel(5,-1.,-1.,-1,-1,-1,"#splitline{cand. M}{writer F}");
  xaxisGrindstoneSocSci->ChangeLabel(7,-1.,-1.,-1,-1,-1,"#splitline{cand. F}{writer F}");
  xaxisGrindstoneSocSci->ChangeLabel(2,-1.,0.);
  xaxisGrindstoneSocSci->ChangeLabel(4,-1.,0.);
  xaxisGrindstoneSocSci->ChangeLabel(6,-1.,0.);
  xaxisGrindstoneSocSci->ChangeLabel(1,-1.,-1.,-1,-1,-1," ");
  xaxisGrindstoneSocSci->ChangeLabel(3,-1.,-1.,-1,-1,-1," ");
  xaxisGrindstoneSocSci->ChangeLabel(5,-1.,-1.,-1,-1,-1," ");
  xaxisGrindstoneSocSci->ChangeLabel(7,-1.,-1.,-1,-1,-1," ");
  xaxisGrindstoneSocSci->ChangeLabel(2,-1.,0.);
  xaxisGrindstoneSocSci->ChangeLabel(4,-1.,0.);
  xaxisGrindstoneSocSci->ChangeLabel(6,-1.,0.);
  grindstoneSocSci->SetFillColor(38);

  grindstoneSocSci->SetMaximum(par0 + 5.*grindstoneSocScicFrF->GetMeanError());
  grindstoneSocSci->SetMinimum(TMath::Max(par0 - 5.*grindstoneSocScicFrF->GetMeanError(),0.));

  grindstoneSocSci->Draw("AB");
  TBox* boxGrindstoneSocSci = new TBox(0.6,par0-err0,4.4,par0+err0);
  boxGrindstoneSocSci->SetFillColor(kBlue);
  boxGrindstoneSocSci->SetFillStyle(3004);
  boxGrindstoneSocSci->Draw();

  grindstoneSocSci->Write();
  if (useBoth){
    c2->SaveAs("pdfPlotsBoth/SocSciGrindstone.pdf");
  }else {c2->SaveAs("pdfPlots/SocSciGrindstone.pdf");}

  TCanvas* c5 = new TCanvas();
  c5->Divide(2);
  c5->cd(2);
  analysisOut <<    static_cast<Float_t>(agenticPhysicscMrM->GetMean()) << " " << 
    static_cast<Float_t>(agenticPhysicscFrM->GetMean()) << " " << 
    static_cast<Float_t>(agenticPhysicscFrF->GetMean()) << " " <<
    static_cast<Float_t>(agenticPhysicscMrF->GetMean()) << " " << std::endl;
 
  Float_t x5[4] = {1.,2.,3.,4.};
  Float_t y5[4] = {
    static_cast<Float_t>(agenticPhysicscMrM->GetMean()),
    static_cast<Float_t>(agenticPhysicscFrM->GetMean()),
    static_cast<Float_t>(agenticPhysicscMrF->GetMean()),
    static_cast<Float_t>(agenticPhysicscFrF->GetMean())
  };
  Float_t ex5[4] = {0.1,0.1,0.1,0.1};
  Float_t ey5[4] = {
    static_cast<Float_t>(agenticPhysicscMrM->GetMeanError()),
    static_cast<Float_t>(agenticPhysicscFrM->GetMeanError()),
    static_cast<Float_t>(agenticPhysicscMrF->GetMeanError()),
    static_cast<Float_t>(agenticPhysicscFrF->GetMeanError())
  };

  TGraphErrors* agenticPhysics = new TGraphErrors(4,x5,y5,ex5,ey5);
  agenticPhysics->SetMaximum(1.5);
  agenticPhysics->SetMinimum(0.5);
  agenticPhysics->SetTitle("EPP Agentic");
  TFitResultPtr fit5 = agenticPhysics->Fit("fits","S");
  par0 = fit5->Value(0);
  err0 = fit5->ParError(0);
    TAxis* yAxisAgenticPhysics = agenticPhysics->GetYaxis();
  yAxisAgenticPhysics->SetTitle("% of Words");
  yAxisAgenticPhysics->SetTickLength(0.);
 

  TAxis* xaxisAgenticPhysics= agenticPhysics->GetXaxis();
  xaxisAgenticPhysics->SetTickLength(0.);
   xaxisAgenticPhysics->SetTickLength(0.);
   xaxisAgenticPhysics->ChangeLabel(1,-1.,-1.,-1,-1,-1,"#splitline{cand. M}{writer M}");
  xaxisAgenticPhysics->ChangeLabel(3,-1.,-1.,-1,-1,-1,"#splitline{cand. F}{writer M}");
  xaxisAgenticPhysics->ChangeLabel(5,-1.,-1.,-1,-1,-1,"#splitline{cand. M}{writer F}");
  xaxisAgenticPhysics->ChangeLabel(7,-1.,-1.,-1,-1,-1,"#splitline{cand. F}{writer F}");
  xaxisAgenticPhysics->ChangeLabel(2,-1.,0.);
  xaxisAgenticPhysics->ChangeLabel(4,-1.,0.);
  xaxisAgenticPhysics->ChangeLabel(6,-1.,0.);
  xaxisAgenticPhysics->ChangeLabel(1,-1.,-1.,-1,-1,-1," ");
  xaxisAgenticPhysics->ChangeLabel(3,-1.,-1.,-1,-1,-1," ");
  xaxisAgenticPhysics->ChangeLabel(5,-1.,-1.,-1,-1,-1," ");
  xaxisAgenticPhysics->ChangeLabel(7,-1.,-1.,-1,-1,-1," ");
  xaxisAgenticPhysics->ChangeLabel(2,-1.,0.);
  xaxisAgenticPhysics->ChangeLabel(4,-1.,0.);
  xaxisAgenticPhysics->ChangeLabel(6,-1.,0.);
  agenticPhysics->SetFillColor(38);
  agenticPhysics->SetMaximum(par0 + 5.*agenticPhysicscFrF->GetMeanError());
  agenticPhysics->SetMinimum(TMath::Max(par0 - 5.*agenticPhysicscFrF->GetMeanError(),0.));
   agenticPhysics->Draw("AB");

  TBox* box5 = new TBox(0.6,par0-err0,4.4,par0+err0);
  box5->SetFillColor(kBlue);
  box5->SetFillStyle(3004);
  box5->Draw();

  agenticPhysics->Write();
  if (useBoth){
    c5->SaveAs("pdfPlotsBoth/physicsAgentic.pdf");}
  else{ c5->SaveAs("pdfPlots/physicsAgentic.pdf");}
  
  //    TCanvas* c6 = new TCanvas();
  c5->cd(1);
  analysisOut <<    static_cast<Float_t>(agenticSocScicMrM->GetMean()) << " " << 
    static_cast<Float_t>(agenticSocScicFrM->GetMean()) << " " << 
    static_cast<Float_t>(agenticSocScicFrF->GetMean()) << " " <<
    static_cast<Float_t>(agenticSocScicMrF->GetMean()) << " " << std::endl;
 
  Float_t x6[4] = {1.,2.,3.,4.};
  Float_t y6[4] = {
    static_cast<Float_t>(agenticSocScicMrM->GetMean()),
    static_cast<Float_t>(agenticSocScicFrM->GetMean()),
    static_cast<Float_t>(agenticSocScicMrF->GetMean()),
    static_cast<Float_t>(agenticSocScicFrF->GetMean())
  };
  Float_t ex6[4] = {0.1,0.1,0.1,0.1};
  Float_t ey6[4] = {
    static_cast<Float_t>(agenticSocScicMrM->GetMeanError()),
    static_cast<Float_t>(agenticSocScicFrM->GetMeanError()),
    static_cast<Float_t>(agenticSocScicMrF->GetMeanError()),
    static_cast<Float_t>(agenticSocScicFrF->GetMeanError())
  };

  TGraphErrors* agenticSocSci = new TGraphErrors(4,x6,y6,ex6,ey6);
  agenticSocSci->SetMaximum(1.5);
  agenticSocSci->SetMinimum(0.5);
  agenticSocSci->SetTitle("Social Science Agentic");
  TFitResultPtr fit6 = agenticSocSci->Fit("fits","S");
  par0 = fit6->Value(0);
  err0 = fit6->ParError(0);
   TAxis* yAxisAgenticSocSci = agenticSocSci->GetYaxis();
  yAxisAgenticSocSci->SetTitle("% of Words");
  yAxisAgenticSocSci->SetTickLength(0.);
 
  TAxis* xaxisAgenticSocSci = agenticSocSci->GetXaxis();
   xaxisAgenticSocSci->SetTickLength(0.);
   xaxisAgenticSocSci->ChangeLabel(1,-1.,-1.,-1,-1,-1,"#splitline{cand. M}{writer M}");
  xaxisAgenticSocSci->ChangeLabel(3,-1.,-1.,-1,-1,-1,"#splitline{cand. F}{writer M}");
  xaxisAgenticSocSci->ChangeLabel(5,-1.,-1.,-1,-1,-1,"#splitline{cand. M}{writer F}");
  xaxisAgenticSocSci->ChangeLabel(7,-1.,-1.,-1,-1,-1,"#splitline{cand. F}{writer F}");
  xaxisAgenticSocSci->ChangeLabel(2,-1.,0.);
  xaxisAgenticSocSci->ChangeLabel(4,-1.,0.);
  xaxisAgenticSocSci->ChangeLabel(6,-1.,0.);
  xaxisAgenticSocSci->ChangeLabel(1,-1.,-1.,-1,-1,-1," ");
  xaxisAgenticSocSci->ChangeLabel(3,-1.,-1.,-1,-1,-1," ");
  xaxisAgenticSocSci->ChangeLabel(5,-1.,-1.,-1,-1,-1," ");
  xaxisAgenticSocSci->ChangeLabel(7,-1.,-1.,-1,-1,-1," ");
  xaxisAgenticSocSci->ChangeLabel(2,-1.,0.);
  xaxisAgenticSocSci->ChangeLabel(4,-1.,0.);
  xaxisAgenticSocSci->ChangeLabel(6,-1.,0.);
  agenticSocSci->SetFillColor(38);
  agenticSocSci->SetMaximum(par0 + 5.*agenticSocScicFrF->GetMeanError());
  agenticSocSci->SetMinimum(TMath::Max(par0 - 5.*agenticSocScicFrF->GetMeanError(),0.));
   agenticSocSci->Draw("AB");

 
  TBox* box6 = new TBox(0.6,par0-err0,4.4,par0+err0);
  box6->SetFillColor(kBlue);
  box6->SetFillStyle(3004);
  box6->Draw();

  agenticSocSci->Write();

  if (useBoth){
    c5->SaveAs("pdfPlotsBoth/SocSciAgentic.pdf");
  } else {c5->SaveAs("pdfPlots/SocSciAgentic.pdf");}

  TCanvas* c7 = new TCanvas();
  c7->Divide(2);
  c7->cd(2);
  analysisOut <<    static_cast<Float_t>(communalPhysicscMrM->GetMean()) << " " << 
    static_cast<Float_t>(communalPhysicscFrM->GetMean()) << " " << 
    static_cast<Float_t>(communalPhysicscFrF->GetMean()) << " " <<
    static_cast<Float_t>(communalPhysicscMrF->GetMean()) << " " << std::endl;
 
  Float_t x7[4] = {1.,2.,3.,4.};
  Float_t y7[4] = {
    static_cast<Float_t>(communalPhysicscMrM->GetMean()),
    static_cast<Float_t>(communalPhysicscFrM->GetMean()),
    static_cast<Float_t>(communalPhysicscMrF->GetMean()),
    static_cast<Float_t>(communalPhysicscFrF->GetMean())
  };
  Float_t ex7[4] = {0.1,0.1,0.1,0.1};
  Float_t ey7[4] = {
    static_cast<Float_t>(communalPhysicscMrM->GetMeanError()),
    static_cast<Float_t>(communalPhysicscFrM->GetMeanError()),
    static_cast<Float_t>(communalPhysicscMrF->GetMeanError()),
    static_cast<Float_t>(communalPhysicscFrF->GetMeanError())
  };

  TGraphErrors* communalPhysics = new TGraphErrors(4,x7,y7,ex7,ey7);
  communalPhysics->SetMaximum(1.6);
  communalPhysics->SetMinimum(0.5);
  communalPhysics->SetTitle("EPP Communal");
  TFitResultPtr fit7 = communalPhysics->Fit("fits","S");
  par0 = fit7->Value(0);
  err0 = fit7->ParError(0);
     TAxis* yAxisCommunalPhysics = communalPhysics->GetYaxis();
  yAxisCommunalPhysics->SetTitle("% of Words");
  yAxisCommunalPhysics->SetTickLength(0.);
 

  TAxis* xaxisCommunalPhysics= communalPhysics->GetXaxis();
  xaxisCommunalPhysics->SetTickLength(0.);
   xaxisCommunalPhysics->SetTickLength(0.);
   xaxisCommunalPhysics->ChangeLabel(1,-1.,-1.,-1,-1,-1,"#splitline{cand. M}{writer M}");
  xaxisCommunalPhysics->ChangeLabel(3,-1.,-1.,-1,-1,-1,"#splitline{cand. F}{writer M}");
  xaxisCommunalPhysics->ChangeLabel(5,-1.,-1.,-1,-1,-1,"#splitline{cand. M}{writer F}");
  xaxisCommunalPhysics->ChangeLabel(7,-1.,-1.,-1,-1,-1,"#splitline{cand. F}{writer F}");
  xaxisCommunalPhysics->ChangeLabel(2,-1.,0.);
  xaxisCommunalPhysics->ChangeLabel(4,-1.,0.);
  xaxisCommunalPhysics->ChangeLabel(6,-1.,0.);
  communalPhysics->SetFillColor(38);
  communalPhysics->SetMaximum(par0 + 5.*communalPhysicscFrF->GetMeanError());
  communalPhysics->SetMinimum(TMath::Max(par0 - 5.*communalPhysicscFrF->GetMeanError(),0.));
   communalPhysics->Draw("AB");

  TBox* boxCommunalPhysics = new TBox(0.6,par0-err0,4.4,par0+err0);
  boxCommunalPhysics->SetFillColor(kBlue);
  boxCommunalPhysics->SetFillStyle(3004);
  boxCommunalPhysics->Draw();

  communalPhysics->Write();
  if (useBoth){
    c5->SaveAs("pdfPlotsBoth/physicsCommunal.pdf");}
  else{ c5->SaveAs("pdfPlots/physicsCommunal.pdf");}
 
  if (useBoth)
    {
      c7->SaveAs("pdfPlotsBoth/physicsCommunal.pdf");
    }else{c7->SaveAs("pdfPlots/physicsCommunal.pdf");}

  //
  c7->cd(1); //TCanvas* c8 = new TCanvas();

  analysisOut <<    static_cast<Float_t>(communalSocScicMrM->GetMean()) << " " << 
    static_cast<Float_t>(communalSocScicFrM->GetMean()) << " " << 
    static_cast<Float_t>(communalSocScicFrF->GetMean()) << " " <<
    static_cast<Float_t>(communalSocScicMrF->GetMean()) << " " << std::endl;
 
  Float_t x8[4] = {1.,2.,3.,4.};
  Float_t y8[4] = {
    static_cast<Float_t>(communalSocScicMrM->GetMean()),
    static_cast<Float_t>(communalSocScicFrM->GetMean()),
    static_cast<Float_t>(communalSocScicMrF->GetMean()),
    static_cast<Float_t>(communalSocScicFrF->GetMean())
  };
  Float_t ex8[4] = {0.1,0.1,0.1,0.1};
  Float_t ey8[4] = {
    static_cast<Float_t>(communalSocScicMrM->GetMeanError()),
    static_cast<Float_t>(communalSocScicFrM->GetMeanError()),
    static_cast<Float_t>(communalSocScicMrF->GetMeanError()),
    static_cast<Float_t>(communalSocScicFrF->GetMeanError())
    //static_cast<Float_t>(100000.),
    //static_cast<Float_t>(100000.),
    //    static_cast<Float_t>(100000.),
    //static_cast<Float_t>(100000.)
  };

  TGraphErrors* communalSocSci = new TGraphErrors(4,x8,y8,ex8,ey8);
  communalSocSci->SetTitle("Social Science Communal");
  TFitResultPtr fit8 = communalSocSci->Fit("fits","S");
  par0 = fit8->Value(0);
  err0 = fit8->ParError(0);
     TAxis* yAxisCommunalSocSci = communalSocSci->GetYaxis();
  yAxisCommunalSocSci->SetTitle("% of Words");
  yAxisCommunalSocSci->SetTickLength(0.);
 

  TAxis* xaxisCommunalSocSci= communalSocSci->GetXaxis();
  xaxisCommunalSocSci->SetTickLength(0.);
   xaxisCommunalSocSci->SetTickLength(0.);
   xaxisCommunalSocSci->ChangeLabel(1,-1.,-1.,-1,-1,-1,"#splitline{cand. M}{writer M}");
  xaxisCommunalSocSci->ChangeLabel(3,-1.,-1.,-1,-1,-1,"#splitline{cand. F}{writer M}");
  xaxisCommunalSocSci->ChangeLabel(5,-1.,-1.,-1,-1,-1,"#splitline{cand. M}{writer F}");
  xaxisCommunalSocSci->ChangeLabel(7,-1.,-1.,-1,-1,-1,"#splitline{cand. F}{writer F}");
  xaxisCommunalSocSci->ChangeLabel(2,-1.,0.);
  xaxisCommunalSocSci->ChangeLabel(4,-1.,0.);
  xaxisCommunalSocSci->ChangeLabel(6,-1.,0.);
  communalSocSci->SetFillColor(38);
  communalSocSci->SetMaximum(par0 + 5.*communalSocScicFrF->GetMeanError());
  communalSocSci->SetMinimum(TMath::Max(par0 - 5.*communalSocScicFrF->GetMeanError(),0.));
   communalSocSci->Draw("AB");

  TBox* boxCommunalSocSci = new TBox(0.6,par0-err0,4.4,par0+err0);
  boxCommunalSocSci->SetFillColor(kBlue);
  boxCommunalSocSci->SetFillStyle(3004);
  boxCommunalSocSci->Draw();
 
 
  communalSocSci->Write();
  if (useBoth)
    {
      c7->SaveAs("pdfPlotsBoth/SocSciCommunal.pdf");
    }else{ c7->SaveAs("pdfPlots/SocSciCommunal.pdf");}


  
  TCanvas* c9 = new TCanvas();

  analysisOut <<    static_cast<Float_t>(comparisonMalePhysicscMrM->GetMean()) << " " << 
    static_cast<Float_t>(comparisonMalePhysicscFrM->GetMean()) << " " << 
    static_cast<Float_t>(comparisonMalePhysicscFrF->GetMean()) << " " <<
    static_cast<Float_t>(comparisonMalePhysicscMrF->GetMean()) << " " << std::endl;
 
  Float_t x9[4] = {1.,2.,3.,4.};
  Float_t y9[4] = {
    static_cast<Float_t>(comparisonMalePhysicscMrM->GetMean()),
    static_cast<Float_t>(comparisonMalePhysicscFrM->GetMean()),
    static_cast<Float_t>(comparisonMalePhysicscMrF->GetMean()),
    static_cast<Float_t>(comparisonMalePhysicscFrF->GetMean())
  };
  Float_t ex9[4] = {0.1,0.1,0.1,0.1};
  Float_t ey9[4] = {
    static_cast<Float_t>(comparisonMalePhysicscMrM->GetMeanError()),
    static_cast<Float_t>(comparisonMalePhysicscFrM->GetMeanError()),
    static_cast<Float_t>(comparisonMalePhysicscMrF->GetMeanError()),
    static_cast<Float_t>(comparisonMalePhysicscFrF->GetMeanError())
  };

  TGraphErrors* comparisonMalePhysics = new TGraphErrors(4,x9,y9,ex9,ey9);
  comparisonMalePhysics->SetMaximum(0.3);
  comparisonMalePhysics->SetMinimum(0.0);

  comparisonMalePhysics->SetTitle("Physics Comparison to a Male");
  TFitResultPtr fit9 = comparisonMalePhysics->Fit("fits","S");
  par0 = fit9->Value(0);
  err0 = fit9->ParError(0);
  TAxis* xaxis9= comparisonMalePhysics->GetXaxis();
  xaxis9->SetTickLength(0.);
  xaxis9->ChangeLabel(1,-1.,-1.,-1,-1,-1,"cMrM");
  xaxis9->ChangeLabel(3,-1.,-1.,-1,-1,-1,"cFrM");
  xaxis9->ChangeLabel(5,-1.,-1.,-1,-1,-1,"cMrF");
  xaxis9->ChangeLabel(7,-1.,-1.,-1,-1,-1,"cFrF");
  xaxis9->ChangeLabel(2,-1.,0.);
  xaxis9->ChangeLabel(4,-1.,0.);
  xaxis9->ChangeLabel(6,-1.,0.);
    comparisonMalePhysics->SetMaximum(par0 + 5.*comparisonMalePhysicscFrF->GetMeanError());
  comparisonMalePhysics->SetMinimum(TMath::Max(par0 - 5.*comparisonMalePhysicscFrF->GetMeanError(),0.));

  comparisonMalePhysics->Draw("A*");
  TBox* box9 = new TBox(0.6,par0-err0,4.4,par0+err0);
  box9->SetFillColor(kBlue);
  box9->SetFillStyle(3004);
  box9->Draw();

  comparisonMalePhysics->Write();
  if (useBoth){
    c9->SaveAs("pdfPlotsBoth/physicsComparisonMale.pdf");
  }else {c9->SaveAs("pdfPlots/physicsComparisonMale.pdf");}

  TCanvas* c10 = new TCanvas();
  analysisOut <<    static_cast<Float_t>(comparisonFemalePhysicscMrM->GetMean()) << " " << 
    static_cast<Float_t>(comparisonFemalePhysicscFrM->GetMean()) << " " << 
    static_cast<Float_t>(comparisonFemalePhysicscFrF->GetMean()) << " " <<
    static_cast<Float_t>(comparisonFemalePhysicscMrF->GetMean()) << " " << std::endl;
 
  Float_t x10[4] = {1.,2.,3.,4.};
  Float_t y10[4] = {
    static_cast<Float_t>(comparisonFemalePhysicscMrM->GetMean()),
    static_cast<Float_t>(comparisonFemalePhysicscFrM->GetMean()),
    static_cast<Float_t>(comparisonFemalePhysicscMrF->GetMean()),
    static_cast<Float_t>(comparisonFemalePhysicscFrF->GetMean())
  };
  Float_t ex10[4] = {0.1,0.1,0.1,0.1};
  Float_t ey10[4] = {
    static_cast<Float_t>(comparisonFemalePhysicscMrM->GetMeanError()),
    static_cast<Float_t>(comparisonFemalePhysicscFrM->GetMeanError()),
    static_cast<Float_t>(comparisonFemalePhysicscFrF->GetMeanError()),
    static_cast<Float_t>(comparisonFemalePhysicscMrF->GetMeanError())
  };

  TGraphErrors* comparisonFemalePhysics = new TGraphErrors(4,x10,y10,ex10,ey10);
  comparisonFemalePhysics->SetMaximum(0.3);
  comparisonFemalePhysics->SetMinimum(0.0);

  comparisonFemalePhysics->SetTitle("Physics Comparison to a Female");
 
  TFitResultPtr fit10 = comparisonFemalePhysics->Fit("fits","S");
  par0 = fit10->Value(0);
  err0 = fit10->ParError(0);
  TAxis* xaxis10= comparisonFemalePhysics->GetXaxis();
  xaxis10->SetTickLength(0.);
  xaxis10->ChangeLabel(1,-1.,-1.,-1,-1,-1,"cMrM");
  xaxis10->ChangeLabel(3,-1.,-1.,-1,-1,-1,"cFrM");
  xaxis10->ChangeLabel(5,-1.,-1.,-1,-1,-1,"cFrF");
  xaxis10->ChangeLabel(7,-1.,-1.,-1,-1,-1,"cMrF");
  xaxis10->ChangeLabel(2,-1.,0.);
  xaxis10->ChangeLabel(4,-1.,0.);
  xaxis10->ChangeLabel(6,-1.,0.);
  comparisonFemalePhysics->SetMaximum(par0 + 5.*comparisonFemalePhysicscFrF->GetMeanError());
  comparisonFemalePhysics->SetMinimum(TMath::Max(par0 - 5.*comparisonFemalePhysicscFrF->GetMeanError(),0.));

  comparisonFemalePhysics->Draw("A*");
  TBox* box10 = new TBox(0.6,par0-err0,4.4,par0+err0);
  box10->SetFillColor(kBlue);
  box10->SetFillStyle(3004);
  box10->Draw();
  if (useBoth)
    {
      c10->SaveAs("pdfPlotsBoth/physicsComparisonFemale.pdf");
    }else{ c10->SaveAs("pdfPlots/physicsComparisonFemale.pdf");}


  TCanvas* c11 = new TCanvas();
  c11->Divide(2);
  c11->cd(2);
    analysisOut <<    static_cast<Float_t>(abilityPhysicscMrM->GetMean()) << " " << 
    static_cast<Float_t>(abilityPhysicscFrM->GetMean()) << " " << 
    static_cast<Float_t>(abilityPhysicscFrF->GetMean()) << " " <<
    static_cast<Float_t>(abilityPhysicscMrF->GetMean()) << " " << std::endl;
 
  Float_t x11[4] = {1.,2.,3.,4.};
  Float_t y11[4] = {
    static_cast<Float_t>(abilityPhysicscMrM->GetMean()),
    static_cast<Float_t>(abilityPhysicscFrM->GetMean()),
    static_cast<Float_t>(abilityPhysicscMrF->GetMean()),
    static_cast<Float_t>(abilityPhysicscFrF->GetMean())
  };
  Float_t ex11[4] = {0.1,0.1,0.1,0.1};
  Float_t ey11[4] = {
    static_cast<Float_t>(abilityPhysicscMrM->GetMeanError()),
    static_cast<Float_t>(abilityPhysicscFrM->GetMeanError()),
    static_cast<Float_t>(abilityPhysicscMrF->GetMeanError()),
    static_cast<Float_t>(abilityPhysicscFrF->GetMeanError())
  };

  TGraphErrors* abilityPhysics = new TGraphErrors(4,x11,y11,ex11,ey11);
  abilityPhysics->SetMaximum(0.3);
  abilityPhysics->SetMinimum(0.0);

  abilityPhysics->SetTitle("EPP Ability");
 
  TFitResultPtr fit11 = abilityPhysics->Fit("fits","S");
  par0 = fit11->Value(0);
  err0 = fit11->ParError(0);
  TAxis* xaxis11= abilityPhysics->GetXaxis();
  xaxis11->SetTickLength(0.);
  xaxis11->ChangeLabel(1,-1.,-1.,-1,-1,-1,"#splitline{cand. M}{writer M}");
  xaxis11->ChangeLabel(3,-1.,-1.,-1,-1,-1,"#splitline{cand. F}{writer M}");
  xaxis11->ChangeLabel(5,-1.,-1.,-1,-1,-1,"#splitline{cand. M}{writer F}");
  xaxis11->ChangeLabel(7,-1.,-1.,-1,-1,-1,"#splitline{cand. F}{writer F}");
  xaxis11->ChangeLabel(2,-1.,0.);
  xaxis11->ChangeLabel(4,-1.,0.);
  xaxis11->ChangeLabel(6,-1.,0.);
  abilityPhysics->SetMaximum(par0 + 5.*abilityPhysicscFrF->GetMeanError());
  abilityPhysics->SetMinimum(TMath::Max(par0 - 5.*abilityPhysicscFrF->GetMeanError(),0.));
  abilityPhysics->SetFillColor(38);
  abilityPhysics->Draw("AB");
  TBox* box11 = new TBox(0.6,par0-err0,4.4,par0+err0);
  box11->SetFillColor(kBlue);
  box11->SetFillStyle(3004);
  box11->Draw();

  c11->cd(1);
  
   analysisOut <<    static_cast<Float_t>(abilitySocScicMrM->GetMean()) << " " << 
    static_cast<Float_t>(abilitySocScicFrM->GetMean()) << " " << 
    static_cast<Float_t>(abilitySocScicFrF->GetMean()) << " " <<
    static_cast<Float_t>(abilitySocScicMrF->GetMean()) << " " << std::endl;
 
  Float_t x12[4] = {1.,2.,3.,4.};
  Float_t y12[4] = {
    static_cast<Float_t>(abilitySocScicMrM->GetMean()),
    static_cast<Float_t>(abilitySocScicFrM->GetMean()),
    static_cast<Float_t>(abilitySocScicMrF->GetMean()),
    static_cast<Float_t>(abilitySocScicFrF->GetMean())
  };
  Float_t ex12[4] = {0.1,0.1,0.1,0.1};
  Float_t ey12[4] = {
    static_cast<Float_t>(abilitySocScicMrM->GetMeanError()),
    static_cast<Float_t>(abilitySocScicFrM->GetMeanError()),
    static_cast<Float_t>(abilitySocScicMrF->GetMeanError()),
    static_cast<Float_t>(abilitySocScicFrF->GetMeanError())
  };

  TGraphErrors* abilitySocSci = new TGraphErrors(4,x12,y12,ex12,ey12);
  abilitySocSci->SetMaximum(0.3);
  abilitySocSci->SetMinimum(0.0);

  abilitySocSci->SetTitle("Social Science Ability");
 
  TFitResultPtr fit12 = abilitySocSci->Fit("fits","S");
  par0 = fit12->Value(0);
  err0 = fit12->ParError(0);
  TAxis* xaxis12= abilitySocSci->GetXaxis();
  xaxis12->SetTickLength(0.);
  xaxis12->ChangeLabel(1,-1.,-1.,-1,-1,-1,"#splitline{cand. M}{writer M}");
  xaxis12->ChangeLabel(3,-1.,-1.,-1,-1,-1,"#splitline{cand. F}{writer M}");
  xaxis12->ChangeLabel(5,-1.,-1.,-1,-1,-1,"#splitline{cand. M}{writer F}");
  xaxis12->ChangeLabel(7,-1.,-1.,-1,-1,-1,"#splitline{cand. F}{writer F}");
  xaxis12->ChangeLabel(2,-1.,0.);
  xaxis12->ChangeLabel(4,-1.,0.);
  xaxis12->ChangeLabel(6,-1.,0.);
  abilitySocSci->SetMaximum(par0 + 5.*abilitySocScicFrF->GetMeanError());
  abilitySocSci->SetMinimum(TMath::Max(par0 - 5.*abilitySocScicFrF->GetMeanError(),0.));
  abilitySocSci->SetFillColor(38);
  abilitySocSci->Draw("AB");
  TBox* box12 = new TBox(0.6,par0-err0,4.4,par0+err0);
  box12->SetFillColor(kBlue);
  box12->SetFillStyle(3004);
  box12->Draw();


      TCanvas* c20 = new TCanvas();

 
    Float_t x20[8] = {1.,2.,3.,4.,5.,6.,7.,8.};
  Float_t y20[8] = {
    static_cast<Float_t>(0.139),
    static_cast<Float_t>(0.096),
    static_cast<Float_t>(0.173),
    static_cast<Float_t>(0.240),
    static_cast<Float_t>(0.459),
    static_cast<Float_t>(0.455),
    static_cast<Float_t>(0.230),
    static_cast<Float_t>(0.210)
  };
  Float_t ex20[8] = {0.1,0.1,0.1,0.1,0.1,0.1,0.1,0.1};
  Float_t ey20[8] = {0.018*1.96,0.013*1.96,0.020*1.96,0.020*1.96,0.032*1.96,0.027*1.96,0.023*1.96,0.019*1.96};

  TGraphErrors* rankSocSci = new TGraphErrors(8,x20,y20,ex20,ey20);
  TAxis* rankSocSciAxis = rankSocSci->GetXaxis();
    rankSocSciAxis->ChangeLabel(1,-1.,-1.,-1,-1,-1,"#splitline{rank 0-2}{writer M}");
  rankSocSciAxis->ChangeLabel(2,-1.,-1.,-1,-1,-1,"#splitline{rank 0-2}{writer F}");
  rankSocSciAxis->ChangeLabel(3,-1.,-1.,-1,-1,-1,"#splitline{rank 3}{writer M}");
  rankSocSciAxis->ChangeLabel(4,-1.,-1.,-1,-1,-1,"#splitline{rank 3}{writer F}");
    rankSocSciAxis->ChangeLabel(5,-1.,-1.,-1,-1,-1,"#splitline{rank 4}{writer M}");
  rankSocSciAxis->ChangeLabel(6,-1.,-1.,-1,-1,-1,"#splitline{rank 4}{writer F}");
  rankSocSciAxis->ChangeLabel(7,-1.,-1.,-1,-1,-1,"#splitline{rank 5}{writer M}");
  rankSocSciAxis->ChangeLabel(8,-1.,-1.,-1,-1,-1,"#splitline{rank 5}{writer F}");
  TAxis* rankSocSciY = rankSocSci->GetYaxis();
   rankSocSciY->SetTitle("Fraction of Letters (M/F)");
   //   rankSocSciY->SetTickLength(0.);

   rankSocSci->SetMaximum(1.0);
  rankSocSci->SetMinimum(0.0);

  rankSocSci->SetFillColor(38);
  rankSocSci->SetTitle("SocSci Rank");
  rankSocSci->Draw("AB");
  //
  //physics
       TCanvas* c21 = new TCanvas();

 
    Float_t x21[8] = {1.,2.,3.,4.,5.,6.,7.,8.};
  Float_t y21[8] = {
    static_cast<Float_t>(0.039),
    static_cast<Float_t>(0.020),
    static_cast<Float_t>(0.104),
    static_cast<Float_t>(0.086),
    static_cast<Float_t>(0.669),
    static_cast<Float_t>(0.712),
    static_cast<Float_t>(0.188),
    static_cast<Float_t>(0.182)
  };
  Float_t ex21[8] = {0.1,0.1,0.1,0.1,0.1,0.1,0.1,0.1};
  Float_t ey21[8] = {0.006*1.96,.010*1.96,.010*1.96,.021*1.96,.026*1.96,.060*1.96,.014*1.96,.030*1.96};

  TGraphErrors* rankPhysics = new TGraphErrors(8,x21,y21,ex21,ey21);
  TAxis* rankPhysicsAxis = rankPhysics->GetXaxis();
    rankPhysicsAxis->ChangeLabel(1,-1.,-1.,-1,-1,-1,"#splitline{rank 0-2}{writer M}");
  rankPhysicsAxis->ChangeLabel(2,-1.,-1.,-1,-1,-1,"#splitline{rank 0-2}{writer F}");
  rankPhysicsAxis->ChangeLabel(3,-1.,-1.,-1,-1,-1,"#splitline{rank 3}{writer M}");
  rankPhysicsAxis->ChangeLabel(4,-1.,-1.,-1,-1,-1,"#splitline{rank 3}{writer F}");
    rankPhysicsAxis->ChangeLabel(5,-1.,-1.,-1,-1,-1,"#splitline{rank 4}{writer M}");
  rankPhysicsAxis->ChangeLabel(6,-1.,-1.,-1,-1,-1,"#splitline{rank 4}{writer F}");
  rankPhysicsAxis->ChangeLabel(7,-1.,-1.,-1,-1,-1,"#splitline{rank 5}{writer M}");
  rankPhysicsAxis->ChangeLabel(8,-1.,-1.,-1,-1,-1,"#splitline{rank 5}{writer F}");
  TAxis* rankPhysicsY = rankPhysics->GetYaxis();
   rankPhysicsY->SetTitle("Fraction of Letters (M/F)");
   //   rankPhysicsY->SetTickLength(0.);

  rankPhysics->SetMaximum(1.0);
  rankPhysics->SetMinimum(0.0);

  rankPhysics->SetFillColor(38);
  rankPhysics->SetTitle("F/");
  rankPhysics->Draw("AB");

  /*********************/
        TCanvas* c30 = new TCanvas();

 
    Float_t x30[4] = {1.,2.,3.,4.};
  Float_t y30[4] = {
    static_cast<Float_t>(0.46),
    static_cast<Float_t>(1.03),
     static_cast<Float_t>(0.14),
    static_cast<Float_t>(0.13)
 };
  Float_t ex30[4] = {0.1,0.1,0.1,0.1};
  Float_t ey30[4] ={.047,.084,.014,.028};

  TGraphErrors* fOverMSocSci = new TGraphErrors(4,x30,y30,ex30,ey30);
  TAxis* fOverMSocSciAxis = fOverMSocSci->GetXaxis();
    fOverMSocSciAxis->ChangeLabel(5,-1.,-1.,-1,-1,-1,"#splitline{     EPP}{male candidate}");
  fOverMSocSciAxis->ChangeLabel(7,-1.,-1.,-1,-1,-1,"#splitline{       EPP}{female candidate}");
  fOverMSocSciAxis->ChangeLabel(1,-1.,-1.,-1,-1,-1,"#splitline{social science}{male candidate}");
  fOverMSocSciAxis->ChangeLabel(3,-1.,-1.,-1,-1,-1,"#splitline{social science}{female candidate}");
  TAxis* fOverMSocSciY = fOverMSocSci->GetYaxis();
   fOverMSocSciY->SetTitle("Fraction of Letters (F/M)");
   //   fOverMSocSciY->SetTickLength(0.);


 
   fOverMSocSci->SetMaximum(1.5);
  fOverMSocSci->SetMinimum(0.0);

  fOverMSocSci->SetFillColor(38);
  fOverMSocSci->SetTitle("F/M Ratio of Writers");
  fOverMSocSci->Draw("AB");

 TBox* boxFOverMP = new TBox(2.65,.13,4.4,.19);
  boxFOverMP->SetFillColor(kBlue);
  boxFOverMP->SetFillStyle(3004);
  boxFOverMP->Draw();

   TBox* boxFOverMS = new TBox(0.6,.63,2.35,.71);
  boxFOverMS->SetFillColor(kBlue);
  boxFOverMS->SetFillStyle(3004);
  boxFOverMS->Draw();
  /******95%CL*****/
         TCanvas* c31 = new TCanvas();

 
    Float_t x31[4] = {1.,2.,3.,4.};
  Float_t y31[4] = {
    static_cast<Float_t>(0.46),
    static_cast<Float_t>(1.03),
    static_cast<Float_t>(0.14),
    static_cast<Float_t>(0.13),
  };
  Float_t ex31[4] = {0.1,0.1,0.1,0.1};
  Float_t ey31[4] = {.047*1.96,.084*1.96,.014*1.96,.028*1.96};

  TGraphErrors* fOverMSocSci95 = new TGraphErrors(4,x31,y31,ex31,ey31);
  TAxis* fOverMSocSciAxis95 = fOverMSocSci95->GetXaxis();
    fOverMSocSciAxis95->ChangeLabel(5,-1.,-1.,-1,-1,-1,"#splitline{     EPP}{male candidate}");
  fOverMSocSciAxis95->ChangeLabel(7,-1.,-1.,-1,-1,-1,"#splitline{       EPP}{female candidate}");
  fOverMSocSciAxis95->ChangeLabel(1,-1.,-1.,-1,-1,-1,"#splitline{social science}{male candidate}");
  fOverMSocSciAxis95->ChangeLabel(3,-1.,-1.,-1,-1,-1,"#splitline{social science}{female candidate}");
  TAxis* fOverMSocSciY95 = fOverMSocSci->GetYaxis();
   fOverMSocSciY95->SetTitle("Fraction of Letters (F/M)");
   //   fOverMSocSciY->SetTickLength(0.);


 
   fOverMSocSci95->SetMaximum(1.5);
  fOverMSocSci95->SetMinimum(0.0);

  fOverMSocSci95->SetFillColor(38);
  fOverMSocSci95->SetTitle("F/M Ratio of Writers");
  fOverMSocSci95->Draw("AB");

 TBox* boxFOverMP95 = new TBox(2.65,0.16-1.96*.03,4.4,.16+1.96*.03);
  boxFOverMP95->SetFillColor(kBlue);
  boxFOverMP95->SetFillStyle(3004);
  boxFOverMP95->Draw();

   TBox* boxFOverMS95 = new TBox(0.6,.67-.04*1.96,2.35,.67+.04*1.96);
  boxFOverMS95->SetFillColor(kBlue);
  boxFOverMS95->SetFillStyle(3004);
  boxFOverMS95->Draw();
  /****/
  abilityPhysics->Write();
  abilitySocSci->Write();

  agenticVsCommunalPhysics->Write();
  agenticVsCommunalPhysicsMaleCand->Write();
  agenticVsCommunalPhysicsMaleWriter->Write();

  standoutVsGrindstonePhysics->Write();
  standoutVsGrindstonePhysicsMaleCand->Write();
  standoutVsGrindstonePhysicsMaleWriter->Write();
  standoutVsGrindstonePhysicsFemaleCand->Write();
  standoutVsGrindstonePhysicsFemaleWriter->Write();

  agenticVsCommunalSocSci->Write();
  agenticVsCommunalSocSciMaleCand->Write();
  agenticVsCommunalSocSciMaleWriter->Write();

  standoutVsGrindstoneSocSci->Write();
  standoutVsGrindstoneSocSciMaleCand->Write();
  standoutVsGrindstoneSocSciMaleWriter->Write();
  standoutVsGrindstoneSocSciFemaleCand->Write();
  standoutVsGrindstoneSocSciFemaleWriter->Write();

  f->Close();
  
}


