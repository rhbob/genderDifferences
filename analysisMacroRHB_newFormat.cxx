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



void analysisMacroRHB_newFormat()

{

  /***********physics******************/

  //
  // M files

  // std::ifstream inputFilesPhysics ("26FebDic_physics_both.txt");
  std::ifstream inputFilesPhysics("PhysicsMasterBothDicsBothGenders.txt");
  
  std::vector<std::string> physicsFileList;
  std::string physicsLine;


  while(std::getline(inputFilesPhysics,physicsLine))
    {
      physicsFileList.push_back(physicsLine);
      //     std::cout << physicscMrMLine << std::endl;
    }

  std::cout << " past initial while loop" << std::endl;
  Int_t physicsLength = physicsFileList.size();
  std::cout << "length of physics list = " << physicsLength << std::endl;
 
  /**************socsci*****************/
  /*
  //
  // cMrM files

  std::ifstream inputFilesSocScicMrM ("SocScicMrM_RHBDic.txt");

  std::vector<std::string> socscicMrcFrMileList;
  std::string socscicMrMLine;


  while(std::getline(inputFilesSocScicMrM,socscicMrMLine))
  {
  socscicMrcFrMileList.push_back(socscicMrMLine);
  //     std::cout << socscicMrMLine << std::endl;
  }

  std::cout << " past initial while loop" << std::endl;
  Int_t socsciLengthcMrM = socscicMrcFrMileList.size();
  std::cout << "length of cMrM socsci list = " << socsciLengthcMrM << std::endl;


  //
  // cFrM Files
  std::ifstream inputFilesSocScicFrM ("SocScicFrM_RHBDic.txt");

  std::vector<std::string> socsciMcFrFileList;
  std::string socscicFrMLine;


  while(std::getline(inputFilesSocScicFrM,socscicFrMLine))
  {
  socsciMcFrFileList.push_back(socscicFrMLine);
  //    std::cout << socscicFrMLine << std::endl;
  }

  Int_t socsciLengthcFrM = socsciMcFrFileList.size();
  std::cout << "length of cFrM socsci list = " << socsciLengthcFrM << std::endl;


  //
  //cFrF files

  //   std::ifstream inputFilesSocScicFrF ("socScicFrF.txt");
  std::ifstream inputFilesSocScicFrF ("SocScicFrF_RHBDic.txt");

  std::vector<std::string> socscicFrFFileList;
  std::string socscicFrFLine;


  while(std::getline(inputFilesSocScicFrF,socscicFrFLine))
  {
  socscicFrFFileList.push_back(socscicFrFLine);
  //     std::cout << socscicFrFLine << std::endl;
  }

  Int_t socsciLengthcFrF = socscicFrFFileList.size();
  std::cout << "length of cFrF socsci list = " << socsciLengthcFrF << std::endl;


  //
  // cFrM files
  //   std::ifstream inputFilesSocScicFrM ("socScicFrM.txt");
  std::ifstream inputFilesSocScicFrM ("SocScicFrM_RHBDic.txt");

  std::vector<std::string> socscicFrcFrMileList;
  std::string socscicFrMLine;


  while(std::getline(inputFilesSocScicFrM,socscicFrMLine))
  {
  socscicFrcFrMileList.push_back(socscicFrMLine);
  //     std::cout << socscicFrMLine << std::endl
  }

  Int_t socsciLengthcFrM = socscicFrcFrMileList.size();
  std::cout << "length of cFrM socsci list = " << socsciLengthcFrM << std::endl;

  */
  /*********analyze**************/
 Int_t cat;

  Int_t wc; Int_t disp;

 Float_t Analytic,Clout,Authentic,Tone,WPS, Dic, function, pronoun, ppron, i, we, you , shehe, they, ipron, article, prep, auxverb, adverb, conj, negate, verb, adj, compare, interrog, number, quant,
    affect, posemo, negemo, anx, anger, sad ,
    social , family, friends, female, male, cogproc, insight, cause, discrep, tentat, certain, differ, percept, see, hear, feel, bio, body, health, sexual, ingest, drives, affiliation,
    achiev,power,reward,risk,focuspast,focuspresent,focusfuture ,
    relativ,motion,space,time,work,leisure,home,money,relig,death,informal,swear,netspeak,assent,nonflu,filler,AllPunc,Period,Comma,Colon,SemiC,QMark,Exclam,Dash,Quote,
    Apostro,Parent,OtherP;

  Int_t canGender, writerGender,both,candId,writerId,discipline;
  string candidateName;
  Int_t wcCut;

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
  TH1F* standoutPhysicscMrF = new TH1F("standoutWilsoncFrM", " rate of standout words in Wilson letter, cMrF ",50,0.,5.);

  TH1F* standoutSocScicMrM = new TH1F("standoutSocScicMrM", " rate of standout words in Cornell letter, cMrM ",50,0.,5.);
  TH1F* standoutSocScicFrM = new TH1F("standoutSocScicFrM", " rate of standout words in Cornell letter, cFrM ",50,0.,5.);
  TH1F* standoutSocScicFrF = new TH1F("standoutSocScicFrF", " rate of standout words in Cornell letter, cFrF ",50,0.,5.);
  TH1F* standoutSocScicMrF = new TH1F("standoutSocScicFrM", " rate of standout words in Cornell letter, cMrF ",50,0.,5.);

  TH1F* abilityPhysicscMrM = new TH1F("abilityWilsoncMrM", " rate of ability words in Wilson letter, cMrM ",50,0.,5.);
  TH1F* abilityPhysicscFrM = new TH1F("abilityWilsoncFrM", " rate of ability words in Wilson letter, cFrM ",50,0.,5.);
  TH1F* abilityPhysicscFrF = new TH1F("abilityWilsoncFrF", " rate of ability words in Wilson letter, cFrF ",50,0.,5.);
  TH1F* abilityPhysicscMrF = new TH1F("abilityWilsoncFrM", " rate of ability words in Wilson letter, cMrF ",50,0.,5.);

  TH1F* comparisonFemalePhysicscMrM = new TH1F("comparisonFemaleWilsoncMrM", " rate of comparisonFemale words in Wilson letter, cMrM ",50,0.,5.);
  TH1F* comparisonFemalePhysicscFrM = new TH1F("comparisonFemaleWilsoncFrM", " rate of comparisonFemale words in Wilson letter, cFrM ",50,0.,5.);
  TH1F* comparisonFemalePhysicscFrF = new TH1F("comparisonFemaleWilsoncFrF", " rate of comparisonFemale words in Wilson letter, cFrF ",50,0.,5.);
  TH1F* comparisonFemalePhysicscMrF = new TH1F("comparisonFemaleWilsoncFrM", " rate of comparisonFemale words in Wilson letter, cMrF ",50,0.,5.);

  TH1F* comparisonMalePhysicscMrM = new TH1F("comparisonMaleWilsoncMrM", " rate of comparisonMale words in Wilson letter, cMrM ",50,0.,5.);
  TH1F* comparisonMalePhysicscFrM = new TH1F("comparisonMaleWilsoncFrM", " rate of comparisonMale words in Wilson letter, cFrM ",50,0.,5.);
  TH1F* comparisonMalePhysicscFrF = new TH1F("comparisonMaleWilsoncFrF", " rate of comparisonMale words in Wilson letter, cFrF ",50,0.,5.);
  TH1F* comparisonMalePhysicscMrF = new TH1F("comparisonMaleWilsoncFrM", " rate of comparisonMale words in Wilson letter, cMrF ",50,0.,5.);

  TH1F* abilitySocScicMrM = new TH1F("abilitySocScicMrM", " rate of ability words in Cornell letter, cMrM ",50,0.,5.);
  TH1F* abilitySocScicFrM = new TH1F("abilitySocScicFrM", " rate of ability words in Cornell letter, cFrM ",50,0.,5.);
  TH1F* abilitySocScicFrF = new TH1F("abilitySocScicFrF", " rate of ability words in Cornell letter, cFrF ",50,0.,5.);
  TH1F* abilitySocScicMrF = new TH1F("abilitySocScicFrM", " rate of ability words in Cornell letter, cMrF ",50,0.,5.);

  TH1F* grindstonePhysicscMrM = new TH1F("grindstoneWilsoncMrM", " rate of grindstone words in Wilson letter, cMrM ",50,0.,5.);
  TH1F* grindstonePhysicscFrM = new TH1F("grindstoneWilsoncFrM", " rate of grindstone words in Wilson letter, cFrM ",50,0.,5.);
  TH1F* grindstonePhysicscFrF = new TH1F("grindstoneWilsoncFrF", " rate of grindstone words in Wilson letter, cFrF ",50,0.,5.);
  TH1F* grindstonePhysicscMrF = new TH1F("grindstoneWilsoncFrM", " rate of grindstone words in Wilson letter, cMrF ",50,0.,5.);

  TH1F* grindstoneSocScicMrM = new TH1F("grindstoneSocScicMrM", " rate of grindstone words in Cornell letter, cMrM ",50,0.,5.);
  TH1F* grindstoneSocScicFrM = new TH1F("grindstoneSocScicFrM", " rate of grindstone words in Cornell letter, cFrM ",50,0.,5.);
  TH1F* grindstoneSocScicFrF = new TH1F("grindstoneSocScicFrF", " rate of grindstone words in Cornell letter, cFrF ",50,0.,5.);
  TH1F* grindstoneSocScicMrF = new TH1F("grindstoneSocScicFrM", " rate of grindstone words in Cornell letter, cMrF ",50,0.,5.);

  TH1F* signalPhysicscMrM = new TH1F("signalWilsoncMrM", " rate of signal words in Wilson letter, cMrM ",50,0.,5.);
  TH1F* signalPhysicscFrM = new TH1F("signalWilsoncFrM", " rate of signal words in Wilson letter, cFrM ",50,0.,5.);
  TH1F* signalPhysicscFrF = new TH1F("signalWilsoncFrF", " rate of signal words in Wilson letter, cFrF ",50,0.,5.);
  TH1F* signalPhysicscMrF = new TH1F("signalWilsoncFrM", " rate of signal words in Wilson letter, cMrF ",50,0.,5.);

  TH1F* signalSocScicMrM = new TH1F("signalSocScicMrM", " rate of signal words in Cornell letter, cMrM ",50,0.,5.);
  TH1F* signalSocScicFrM = new TH1F("signalSocScicFrM", " rate of signal words in Cornell letter, cFrM ",50,0.,5.);
  TH1F* signalSocScicFrF = new TH1F("signalSocScicFrF", " rate of signal words in Cornell letter, cFrF ",50,0.,5.);
  TH1F* signalSocScicMrF = new TH1F("signalSocScicFrM", " rate of signal words in Cornell letter, cMrF ",50,0.,5.);

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


  const char* labels[4] = {"cMrM", "cMrF", "cFrF","cFrM"};
  std::cout << "made ntuples" << std::endl;
  inputFilesPhysics.clear();
  inputFilesPhysics.seekg(0);
 

  Float_t comparisonMin = 0.0;
  // 11/2021
    comparisonMin = -0.5;
  wcCut = 0;
  //    physicsLength = 10;
  string headerInfo;
  std::getline(inputFilesPhysics,headerInfo);
  for (Int_t ithLetter = 0 ; ithLetter< physicsLength; ++ithLetter)
    {
    inputFilesPhysics >> candidateName  >> candId >> writerId >> canGender >> writerGender >> both >> discipline  >>  wc >> Analytic >> Clout >> Authentic >> Tone >>  WPS>> Dic>> function>> pronoun>> ppron>> i>> we>> you >> shehe>> they>> ipron>> article>> prep>> auxverb>> adverb>> conj>> negate>> verb>> adj>> compare>> interrog>> number>> quant>>
      affect>> posemo>> negemo>> anx>> anger>> sad >>
      social >> family>> friends>> female>> male>> cogproc>> insight>> cause>> discrep>> tentat>> certain>> differ>> percept>> see>> hear>> feel>> bio>> body>> health>> sexual>> ingest>> drives>> affiliation>>
      achiev>>power>>reward>>risk>>focuspast>>focuspresent>>focusfuture >>
      relativ>>motion>>space>>time>>work>>leisure>>home>>money>>relig>>death>>informal>>swear>>netspeak>>assent>>nonflu>>filler>>AllPunc>>Period>>Comma>>Colon>>SemiC>>QMark>>Exclam>>Dash>>Quote>>
      Apostro>>Parent>>OtherP >> standout >> ability >> grindstone >> teaching >> research >> agentic >> communal >> comparisonMale >> comparisonFemale >> signalPhysics >> signalSociology >> ranking >> negative;
       if (ithLetter > -10000){
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
       }
       std::cout << "finished" << std::endl;
       // if (both < 0.5) continue;
      std::cout << " candidate and writer " << canGender << " " << writerGender << " " << candId << std::endl;
      if (writerGender < 0.5){std::cout << "male writer " << std::endl;}
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
	std::cout << "in cat 1" << std::endl;
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

    
      if ( canGender < 0.5 && writerGender > 0.5){
	cat = 2;
	std::cout << "in cat 2" << std::endl;
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

      //     if (canGender > 0.5 && writerGender < 0.5){
      if (canGender > 0.5 && (writerGender > 0.5)){
 	cat = 3;
	std::cout << "in cat 3" << std::endl;
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
	std::cout << "in cat 4" << std::endl;
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

  comparisonMalePhysicscMrM->Write();
  comparisonMalePhysicscFrM->Write();
  comparisonMalePhysicscFrF->Write();
  comparisonMalePhysicscMrF->Write();

  /************socsci***************/ /*
				      // cMrM analysis
				      cat = 5;
				      for (Int_t ithLetter = 0 ; ithLetter< socsciLengthcMrM; ++ithLetter){
				      inputFilesSocScicMrM >> wc >>  WPS >> Dic >> standout >> ability >> grindstone >> teaching >> research >> agentic >> communal >> comparisonMale >> comparisonFemale >> signalPhysics >> signalSociology >> ranking >> negative;
				      wordCountSocScicMrM->Fill(wc);
				      if (wc < wcCut) continue;
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
				      // cFrM analysis
				      cat = 6;
				      for (Int_t ithLetter = 0 ; ithLetter< socsciLengthcFrM; ++ithLetter){
				      inputFilesSocScicFrM >> wc >>  WPS >> Dic >> standout >> ability >> grindstone >> teaching >> research >> agentic >> communal >> comparisonMale >> comparisonFemale >> signalPhysics >> signalSociology >> ranking >> negative;
				      wordCountSocScicFrM->Fill(wc);
				      if (wc < wcCut) continue;
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

				      // cFrM analysis
				      cat = 7;
				      for (Int_t ithLetter = 0 ; ithLetter< socsciLengthcFrM; ++ithLetter){
				      inputFilesSocScicFrM >> wc >>  WPS >> Dic >> standout >> ability >> grindstone >> teaching >> research >> agentic >> communal >> comparisonMale >> comparisonFemale >> signalPhysics >> signalSociology >> ranking >> negative;
				      wordCountSocScicFrM->Fill(wc);
				      if (wc < wcCut) continue;
				      agenticSocScicFrM->Fill(agentic);
				      communalSocScicFrM->Fill(communal);
				      standoutSocScicFrM->Fill(standout);
				      abilitySocScicFrM->Fill(ability);
				      grindstoneSocScicFrM->Fill(grindstone);
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


				      // cFrF analysis
				      cat = 8;
				      for (Int_t ithLetter = 0 ; ithLetter< socsciLengthcFrF; ++ithLetter){
				      inputFilesSocScicFrF >> wc >>  WPS >> Dic >> standout >> ability >> grindstone >> teaching >> research >> agentic >> communal >> comparisonMale >> comparisonFemale >> signalPhysics >> signalSociology >> ranking >> negative;
				      wordCountSocScicFrF->Fill(wc);
				      if (wc < wcCut) continue;
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

 

				      sumOverMenWritersPhysicsWordCount->Write();
				      sumOverMenAppPhysicsWordCount->Write();
				      sumOverWomenWritersPhysicsWordCount->Write();
				      sumOverWomenAppPhysicsWordCount->Write();
				      sumOverMenWritersSocSciWordCount->Write();
				      sumOverMenAppSocSciWordCount->Write();
				      sumOverWomenWritersSocSciWordCount->Write();
				      sumOverWomenAppSocSciWordCount->Write();


				      socsci->Write();
				      */
 
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

  gStyle->SetOptFit(1);
  //
  // get means and errors.  Look at ratio M/F and make a big TGraphErrors

  std::cout <<    static_cast<Float_t>(wordCountSocScicMrM->GetMean()) << " " << 
    static_cast<Float_t>(wordCountSocScicFrM->GetMean()) << " " << 
    static_cast<Float_t>(wordCountSocScicFrF->GetMean()) << " " <<
    static_cast<Float_t>(wordCountSocScicFrM->GetMean()) << " " << std::endl;
 
  Float_t x1[4] = {1.,2.,3.,4.};
  Float_t y1[4] = {
    static_cast<Float_t>(wordCountSocScicMrM->GetMean()),
    static_cast<Float_t>(wordCountSocScicFrM->GetMean()),
    static_cast<Float_t>(wordCountSocScicFrF->GetMean()),
    static_cast<Float_t>(wordCountSocScicMrF->GetMean())
  };
  Float_t ex1[4] = {0.1,0.1,0.1,0.1};
  Float_t ey1[4] = {
    static_cast<Float_t>(wordCountSocScicMrM->GetMeanError()),
    static_cast<Float_t>(wordCountSocScicFrM->GetMeanError()),
    static_cast<Float_t>(wordCountSocScicFrF->GetMeanError()),
    static_cast<Float_t>(wordCountSocScicMrF->GetMeanError())
  };

  Double_t par0;
  Double_t err0;
  TF1* fitRaw = new TF1("fits","[0]",0.,10.);
  fitRaw->SetParNames("average");
  
  TGraphErrors* wordCountsSocSci = new TGraphErrors(4,x1,y1,ex1,ey1);
  wordCountsSocSci->SetMaximum(1250.);
  wordCountsSocSci->SetMinimum(750.);
  wordCountsSocSci->SetTitle("Social Science Word Count: cMrM, cFrM, cFrF, cFrM");
  TCanvas* c1 = new TCanvas();
  TFitResultPtr fit = wordCountsSocSci->Fit("fits","S");
  par0 = fit->Value(0);
  err0 = fit->ParError(0);
  TAxis* xaxis = wordCountsSocSci->GetXaxis();
  xaxis->SetTickLength(0.);
  xaxis->ChangeLabel(1,-1.,-1.,-1,-1,-1,"cMrM");
  xaxis->ChangeLabel(3,-1.,-1.,-1,-1,-1,"cFrM");
  xaxis->ChangeLabel(5,-1.,-1.,-1,-1,-1,"cFrF");
  xaxis->ChangeLabel(7,-1.,-1.,-1,-1,-1,"cMrF");
  xaxis->ChangeLabel(2,-1.,0.);
  xaxis->ChangeLabel(4,-1.,0.);
  xaxis->ChangeLabel(6,-1.,0.);
  wordCountsSocSci->Draw("A*");
  TBox* box = new TBox(0.6,par0-err0,4.4,par0+err0);
  box->SetFillColor(kBlue);
  box->SetFillStyle(3004);
  box->Draw();

  TCanvas* c2 = new TCanvas();

  std::cout <<    static_cast<Float_t>(wordCountPhysicscMrM->GetMean()) << " " << 
    static_cast<Float_t>(wordCountPhysicscFrM->GetMean()) << " " << 
    static_cast<Float_t>(wordCountPhysicscFrF->GetMean()) << " " <<
    static_cast<Float_t>(wordCountPhysicscFrM->GetMean()) << " " << std::endl;
 
  Float_t x2[4] = {1.,2.,3.,4.};
  Float_t y2[4] = {
    static_cast<Float_t>(wordCountPhysicscMrM->GetMean()),
    static_cast<Float_t>(wordCountPhysicscFrM->GetMean()),
    static_cast<Float_t>(wordCountPhysicscFrF->GetMean()),
    static_cast<Float_t>(wordCountPhysicscMrF->GetMean())
  };
  Float_t ex2[4] = {0.1,0.1,0.1,0.1};
  Float_t ey2[4] = {
    static_cast<Float_t>(wordCountPhysicscMrM->GetMeanError()),
    static_cast<Float_t>(wordCountPhysicscFrM->GetMeanError()),
    static_cast<Float_t>(wordCountPhysicscFrF->GetMeanError()),
    static_cast<Float_t>(wordCountPhysicscMrF->GetMeanError())
  };

  TGraphErrors* wordCountsPhysics = new TGraphErrors(4,x2,y2,ex2,ey2);
  wordCountsPhysics->SetMaximum(1250.);
  wordCountsPhysics->SetMinimum(750.);
  wordCountsPhysics->SetTitle("Physics Word Count: cMrM, cFrM, cFrF, cFrM");
  TFitResultPtr fit2 = wordCountsPhysics->Fit("fits","S");
  par0 = fit2->Value(0);
  err0 = fit2->ParError(0);
  TAxis* xaxis2 = wordCountsPhysics->GetXaxis();
  xaxis2->SetTickLength(0.);
  xaxis2->ChangeLabel(1,-1.,-1.,-1,-1,-1,"cMrM");
  xaxis2->ChangeLabel(3,-1.,-1.,-1,-1,-1,"cFrM");
  xaxis2->ChangeLabel(5,-1.,-1.,-1,-1,-1,"cFrF");
  xaxis2->ChangeLabel(7,-1.,-1.,-1,-1,-1,"cMrF");
  xaxis2->ChangeLabel(2,-1.,0.);
  xaxis2->ChangeLabel(4,-1.,0.);
  xaxis2->ChangeLabel(6,-1.,0.);
  wordCountsPhysics->Draw("A*");
  TBox* box2 = new TBox(0.6,par0-err0,4.4,par0+err0);
  box2->SetFillColor(kBlue);
  box2->SetFillStyle(3004);
  box2->Draw();

  wordCountsPhysics->Write();


  //
  TCanvas* c3 = new TCanvas();

  std::cout <<    static_cast<Float_t>(standoutPhysicscMrM->GetMean()) << " " << 
    static_cast<Float_t>(standoutPhysicscFrM->GetMean()) << " " << 
    static_cast<Float_t>(standoutPhysicscFrF->GetMean()) << " " <<
    static_cast<Float_t>(standoutPhysicscFrM->GetMean()) << " " << std::endl;
 
  Float_t x3[4] = {1.,2.,3.,4.};
  Float_t y3[4] = {
    static_cast<Float_t>(standoutPhysicscMrM->GetMean()),
    static_cast<Float_t>(standoutPhysicscFrM->GetMean()),
    static_cast<Float_t>(standoutPhysicscFrF->GetMean()),
    static_cast<Float_t>(standoutPhysicscMrF->GetMean())
  };
  Float_t ex3[4] = {0.1,0.1,0.1,0.1};
  Float_t ey3[4] = {
    static_cast<Float_t>(standoutPhysicscMrM->GetMeanError()),
    static_cast<Float_t>(standoutPhysicscFrM->GetMeanError()),
    static_cast<Float_t>(standoutPhysicscFrF->GetMeanError()),
    static_cast<Float_t>(standoutPhysicscMrF->GetMeanError())
  };

  TGraphErrors* standoutPhysics = new TGraphErrors(4,x3,y3,ex3,ey3);
  standoutPhysics->SetMaximum(1.7);
  standoutPhysics->SetMinimum(0.7);
  standoutPhysics->SetTitle("Physics Standout");
  TFitResultPtr fit3 = standoutPhysics->Fit("fits","S");
  par0 = fit3->Value(0);
  err0 = fit3->ParError(0);
  TAxis* xaxis3 = standoutPhysics->GetXaxis();
  xaxis3->SetTickLength(0.);
  xaxis3->ChangeLabel(1,-1.,-1.,-1,-1,-1,"cMrM");
  xaxis3->ChangeLabel(3,-1.,-1.,-1,-1,-1,"cFrM");
  xaxis3->ChangeLabel(5,-1.,-1.,-1,-1,-1,"cFrF");
  xaxis3->ChangeLabel(7,-1.,-1.,-1,-1,-1,"cMrF");
  xaxis3->ChangeLabel(2,-1.,0.);
  xaxis3->ChangeLabel(4,-1.,0.);
  xaxis3->ChangeLabel(6,-1.,0.);
  standoutPhysics->Draw("A*");
  TBox* box3 = new TBox(0.6,par0-err0,4.4,par0+err0);
  box3->SetFillColor(kBlue);
  box3->SetFillStyle(3004);
  box3->Draw();

  standoutPhysics->Write();

  
  TCanvas* c4 = new TCanvas();

  std::cout <<    static_cast<Float_t>(standoutSocScicMrM->GetMean()) << " " << 
    static_cast<Float_t>(standoutSocScicFrM->GetMean()) << " " << 
    static_cast<Float_t>(standoutSocScicFrF->GetMean()) << " " <<
    static_cast<Float_t>(standoutSocScicMrF->GetMean()) << " " << std::endl;
 
  Float_t x4[4] = {1.,2.,3.,4.};
  Float_t y4[4] = {
    static_cast<Float_t>(standoutSocScicMrM->GetMean()),
    static_cast<Float_t>(standoutSocScicFrM->GetMean()),
    static_cast<Float_t>(standoutSocScicFrF->GetMean()),
    static_cast<Float_t>(standoutSocScicMrF->GetMean())
  };
  Float_t ex4[4] = {0.1,0.1,0.1,0.1};
  Float_t ey4[4] = {
    static_cast<Float_t>(standoutSocScicMrM->GetMeanError()),
    static_cast<Float_t>(standoutSocScicFrM->GetMeanError()),
    static_cast<Float_t>(standoutSocScicFrF->GetMeanError()),
    static_cast<Float_t>(standoutSocScicMrF->GetMeanError())
  };

  TGraphErrors* standoutSocSci = new TGraphErrors(4,x4,y4,ex4,ey4);
  standoutSocSci->SetMaximum(1.5);
  standoutSocSci->SetMinimum(0.5);
  standoutSocSci->SetTitle("SocSci Standout");
  TFitResultPtr fit4 = standoutSocSci->Fit("fits","S");
  par0 = fit4->Value(0);
  err0 = fit4->ParError(0);
  TAxis* xaxis4 = standoutSocSci->GetXaxis();
  xaxis4->SetTickLength(0.);
  xaxis4->ChangeLabel(1,-1.,-1.,-1,-1,-1,"cMrM");
  xaxis4->ChangeLabel(3,-1.,-1.,-1,-1,-1,"cFrM");
  xaxis4->ChangeLabel(5,-1.,-1.,-1,-1,-1,"cFrF");
  xaxis4->ChangeLabel(7,-1.,-1.,-1,-1,-1,"cMrF");
  xaxis4->ChangeLabel(2,-1.,0.);
  xaxis4->ChangeLabel(4,-1.,0.);
  xaxis4->ChangeLabel(6,-1.,0.);
  standoutSocSci->Draw("A*");
  TBox* box4 = new TBox(0.6,par0-err0,4.4,par0+err0);
  box4->SetFillColor(kBlue);
  box4->SetFillStyle(3004);
  box4->Draw();

  standoutSocSci->Write();


  TCanvas* c5 = new TCanvas();

  std::cout <<    static_cast<Float_t>(agenticPhysicscMrM->GetMean()) << " " << 
    static_cast<Float_t>(agenticPhysicscFrM->GetMean()) << " " << 
    static_cast<Float_t>(agenticPhysicscFrF->GetMean()) << " " <<
    static_cast<Float_t>(agenticPhysicscMrF->GetMean()) << " " << std::endl;
 
  Float_t x5[4] = {1.,2.,3.,4.};
  Float_t y5[4] = {
    static_cast<Float_t>(agenticPhysicscMrM->GetMean()),
    static_cast<Float_t>(agenticPhysicscFrM->GetMean()),
    static_cast<Float_t>(agenticPhysicscFrF->GetMean()),
    static_cast<Float_t>(agenticPhysicscMrF->GetMean())
  };
  Float_t ex5[4] = {0.1,0.1,0.1,0.1};
  Float_t ey5[4] = {
    static_cast<Float_t>(agenticPhysicscMrM->GetMeanError()),
    static_cast<Float_t>(agenticPhysicscFrM->GetMeanError()),
    static_cast<Float_t>(agenticPhysicscFrF->GetMeanError()),
    static_cast<Float_t>(agenticPhysicscMrF->GetMeanError())
  };

  TGraphErrors* agenticPhysics = new TGraphErrors(4,x5,y5,ex5,ey5);
  agenticPhysics->SetMaximum(1.5);
  agenticPhysics->SetMinimum(0.5);
  agenticPhysics->SetTitle("Physics Agentic");
  TFitResultPtr fit5 = agenticPhysics->Fit("fits","S");
  par0 = fit5->Value(0);
  err0 = fit5->ParError(0);
  TAxis* xaxis5= agenticPhysics->GetXaxis();
  xaxis5->SetTickLength(0.);
  xaxis5->ChangeLabel(1,-1.,-1.,-1,-1,-1,"cMrM");
  xaxis5->ChangeLabel(3,-1.,-1.,-1,-1,-1,"cFrM");
  xaxis5->ChangeLabel(5,-1.,-1.,-1,-1,-1,"cFrF");
  xaxis5->ChangeLabel(7,-1.,-1.,-1,-1,-1,"cMrF");
  xaxis5->ChangeLabel(2,-1.,0.);
  xaxis5->ChangeLabel(4,-1.,0.);
  xaxis5->ChangeLabel(6,-1.,0.);
  agenticPhysics->Draw("A*");
  TBox* box5 = new TBox(0.6,par0-err0,4.4,par0+err0);
  box5->SetFillColor(kBlue);
  box5->SetFillStyle(3004);
  box5->Draw();

  agenticPhysics->Write();

  
  TCanvas* c6 = new TCanvas();

  std::cout <<    static_cast<Float_t>(agenticSocScicMrM->GetMean()) << " " << 
    static_cast<Float_t>(agenticSocScicFrM->GetMean()) << " " << 
    static_cast<Float_t>(agenticSocScicFrF->GetMean()) << " " <<
    static_cast<Float_t>(agenticSocScicMrF->GetMean()) << " " << std::endl;
 
  Float_t x6[4] = {1.,2.,3.,4.};
  Float_t y6[4] = {
    static_cast<Float_t>(agenticSocScicMrM->GetMean()),
    static_cast<Float_t>(agenticSocScicFrM->GetMean()),
    static_cast<Float_t>(agenticSocScicFrF->GetMean()),
    static_cast<Float_t>(agenticSocScicMrF->GetMean())
  };
  Float_t ex6[4] = {0.1,0.1,0.1,0.1};
  Float_t ey6[4] = {
    static_cast<Float_t>(agenticSocScicMrM->GetMeanError()),
    static_cast<Float_t>(agenticSocScicFrM->GetMeanError()),
    static_cast<Float_t>(agenticSocScicFrF->GetMeanError()),
    static_cast<Float_t>(agenticSocScicMrF->GetMeanError())
  };

  TGraphErrors* agenticSocSci = new TGraphErrors(4,x6,y6,ex6,ey6);
  agenticSocSci->SetMaximum(1.5);
  agenticSocSci->SetMinimum(0.5);
  agenticSocSci->SetTitle("SocSci Agentic");
  TFitResultPtr fit6 = agenticSocSci->Fit("fits","S");
  par0 = fit6->Value(0);
  err0 = fit6->ParError(0);
  TAxis* xaxis6 = agenticSocSci->GetXaxis();
  xaxis6->SetTickLength(0.);
  xaxis6->ChangeLabel(1,-1.,-1.,-1,-1,-1,"cMrM");
  xaxis6->ChangeLabel(3,-1.,-1.,-1,-1,-1,"cFrM");
  xaxis6->ChangeLabel(5,-1.,-1.,-1,-1,-1,"cFrF");
  xaxis6->ChangeLabel(7,-1.,-1.,-1,-1,-1,"cMrF");
  xaxis6->ChangeLabel(2,-1.,0.);
  xaxis6->ChangeLabel(4,-1.,0.);
  xaxis6->ChangeLabel(6,-1.,0.);
  agenticSocSci->Draw("A*");
  TBox* box6 = new TBox(0.6,par0-err0,4.4,par0+err0);
  box6->SetFillColor(kBlue);
  box6->SetFillStyle(3004);
  box6->Draw();

  agenticSocSci->Write();



  TCanvas* c7 = new TCanvas();

  std::cout <<    static_cast<Float_t>(communalPhysicscMrM->GetMean()) << " " << 
    static_cast<Float_t>(communalPhysicscFrM->GetMean()) << " " << 
    static_cast<Float_t>(communalPhysicscFrF->GetMean()) << " " <<
    static_cast<Float_t>(communalPhysicscMrF->GetMean()) << " " << std::endl;
 
  Float_t x7[4] = {1.,2.,3.,4.};
  Float_t y7[4] = {
    static_cast<Float_t>(communalPhysicscMrM->GetMean()),
    static_cast<Float_t>(communalPhysicscFrM->GetMean()),
    static_cast<Float_t>(communalPhysicscFrF->GetMean()),
    static_cast<Float_t>(communalPhysicscMrF->GetMean())
  };
  Float_t ex7[4] = {0.1,0.1,0.1,0.1};
  Float_t ey7[4] = {
    static_cast<Float_t>(communalPhysicscMrM->GetMeanError()),
    static_cast<Float_t>(communalPhysicscFrM->GetMeanError()),
    static_cast<Float_t>(communalPhysicscFrF->GetMeanError()),
    static_cast<Float_t>(communalPhysicscMrF->GetMeanError())
  };

  TGraphErrors* communalPhysics = new TGraphErrors(4,x7,y7,ex7,ey7);
  communalPhysics->SetMaximum(1.6);
  communalPhysics->SetMinimum(0.5);
  communalPhysics->SetTitle("Physics Communal");
  TFitResultPtr fit7 = communalPhysics->Fit("fits","S");
  par0 = fit7->Value(0);
  err0 = fit7->ParError(0);
  TAxis* xaxis7= communalPhysics->GetXaxis();
  xaxis7->SetTickLength(0.);
  xaxis7->ChangeLabel(1,-1.,-1.,-1,-1,-1,"cMrM");
  xaxis7->ChangeLabel(3,-1.,-1.,-1,-1,-1,"cFrM");
  xaxis7->ChangeLabel(5,-1.,-1.,-1,-1,-1,"cFrF");
  xaxis7->ChangeLabel(7,-1.,-1.,-1,-1,-1,"cMrF");
  xaxis7->ChangeLabel(2,-1.,0.);
  xaxis7->ChangeLabel(4,-1.,0.);
  xaxis7->ChangeLabel(6,-1.,0.);
  communalPhysics->Draw("A*");
  TBox* box7 = new TBox(0.6,par0-err0,4.4,par0+err0);
  box7->SetFillColor(kBlue);
  box7->SetFillStyle(3004);
  box7->Draw();

  communalPhysics->Write();

 

  TCanvas* c8 = new TCanvas();

  std::cout <<    static_cast<Float_t>(communalSocScicMrM->GetMean()) << " " << 
    static_cast<Float_t>(communalSocScicFrM->GetMean()) << " " << 
    static_cast<Float_t>(communalSocScicFrF->GetMean()) << " " <<
    static_cast<Float_t>(communalSocScicMrF->GetMean()) << " " << std::endl;
 
  Float_t x8[4] = {1.,2.,3.,4.};
  Float_t y8[4] = {
    static_cast<Float_t>(communalSocScicMrM->GetMean()),
    static_cast<Float_t>(communalSocScicFrM->GetMean()),
    static_cast<Float_t>(communalSocScicFrF->GetMean()),
    static_cast<Float_t>(communalSocScicMrF->GetMean())
  };
  Float_t ex8[4] = {0.1,0.1,0.1,0.1};
  Float_t ey8[4] = {
    static_cast<Float_t>(communalSocScicMrM->GetMeanError()),
    static_cast<Float_t>(communalSocScicFrM->GetMeanError()),
    static_cast<Float_t>(communalSocScicFrF->GetMeanError()),
    static_cast<Float_t>(communalSocScicMrF->GetMeanError())
    //static_cast<Float_t>(100000.),
    //static_cast<Float_t>(100000.),
    //    static_cast<Float_t>(100000.),
    //static_cast<Float_t>(100000.)
  };

  TGraphErrors* communalSocSci = new TGraphErrors(4,x8,y8,ex8,ey8);
  communalSocSci->SetMaximum(1.5);
  communalSocSci->SetMinimum(0.5);
  communalSocSci->SetTitle("SocSci Communal");
  TFitResultPtr fit8 = communalSocSci->Fit("fits","S");
  par0 = fit8->Value(0);
  err0 = fit8->ParError(0);
  TAxis* xaxis8 = communalSocSci->GetXaxis();
  xaxis8->SetTickLength(0.);
  xaxis8->ChangeLabel(1,-1.,-1.,-1,-1,-1,"cMrM");
  xaxis8->ChangeLabel(3,-1.,-1.,-1,-1,-1,"cFrM");
  xaxis8->ChangeLabel(5,-1.,-1.,-1,-1,-1,"cFrF");
  xaxis8->ChangeLabel(7,-1.,-1.,-1,-1,-1,"cMrF");
  xaxis8->ChangeLabel(2,-1.,0.);
  xaxis8->ChangeLabel(4,-1.,0.);
  xaxis8->ChangeLabel(6,-1.,0.);
  communalSocSci->Draw("A*");
  TBox* box8 = new TBox(0.6,par0-err0,4.4,par0+err0);
  box8->SetFillColor(kBlue);
  box8->SetFillStyle(3004);
  box8->Draw();

  communalSocSci->Write();


  
  TCanvas* c9 = new TCanvas();

  std::cout <<    static_cast<Float_t>(comparisonMalePhysicscMrM->GetMean()) << " " << 
    static_cast<Float_t>(comparisonMalePhysicscFrM->GetMean()) << " " << 
    static_cast<Float_t>(comparisonMalePhysicscFrF->GetMean()) << " " <<
    static_cast<Float_t>(comparisonMalePhysicscMrF->GetMean()) << " " << std::endl;
 
  Float_t x9[4] = {1.,2.,3.,4.};
  Float_t y9[4] = {
    static_cast<Float_t>(comparisonMalePhysicscMrM->GetMean()),
    static_cast<Float_t>(comparisonMalePhysicscFrM->GetMean()),
    static_cast<Float_t>(comparisonMalePhysicscFrF->GetMean()),
    static_cast<Float_t>(comparisonMalePhysicscMrF->GetMean())
  };
  Float_t ex9[4] = {0.1,0.1,0.1,0.1};
  Float_t ey9[4] = {
    static_cast<Float_t>(comparisonMalePhysicscMrM->GetMeanError()),
    static_cast<Float_t>(comparisonMalePhysicscFrM->GetMeanError()),
    static_cast<Float_t>(comparisonMalePhysicscFrF->GetMeanError()),
    static_cast<Float_t>(comparisonMalePhysicscMrF->GetMeanError())
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
  xaxis9->ChangeLabel(5,-1.,-1.,-1,-1,-1,"cFrF");
  xaxis9->ChangeLabel(7,-1.,-1.,-1,-1,-1,"cMrF");
  xaxis9->ChangeLabel(2,-1.,0.);
  xaxis9->ChangeLabel(4,-1.,0.);
  xaxis9->ChangeLabel(6,-1.,0.);
  comparisonMalePhysics->Draw("A*");
  TBox* box9 = new TBox(0.6,par0-err0,4.4,par0+err0);
  box9->SetFillColor(kBlue);
  box9->SetFillStyle(3004);
  box9->Draw();

  comparisonMalePhysics->Write();


  TCanvas* c10 = new TCanvas();
  std::cout <<    static_cast<Float_t>(comparisonFemalePhysicscMrM->GetMean()) << " " << 
    static_cast<Float_t>(comparisonFemalePhysicscFrM->GetMean()) << " " << 
    static_cast<Float_t>(comparisonFemalePhysicscFrF->GetMean()) << " " <<
    static_cast<Float_t>(comparisonFemalePhysicscMrF->GetMean()) << " " << std::endl;
 
  Float_t x10[4] = {1.,2.,3.,4.};
  Float_t y10[4] = {
    static_cast<Float_t>(comparisonFemalePhysicscMrM->GetMean()),
    static_cast<Float_t>(comparisonFemalePhysicscFrM->GetMean()),
    static_cast<Float_t>(comparisonFemalePhysicscFrF->GetMean()),
    static_cast<Float_t>(comparisonFemalePhysicscMrF->GetMean())
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
  comparisonFemalePhysics->Draw("A*");
  TBox* box10 = new TBox(0.6,par0-err0,4.4,par0+err0);
  box10->SetFillColor(kBlue);
  box10->SetFillStyle(3004);
  box10->Draw();

  comparisonFemalePhysics->Write();

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


