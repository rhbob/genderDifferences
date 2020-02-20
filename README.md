# genderDifferences
supplemental materials for Science Bernstein et al.
This archive contains the information necessary to reconstruct our analysis (past identifying information).

Data: 
   1) scienceMasterSpreadsheet.xlsx are the results. You will see some internal variable columns we may use for future
   analyses. 
   2) annotated_v6_drives.xlsx is the same but I have added a column for achievement+power-familyRelated that is the 
   drives variable we use in the analysis.
   3) extraCategoriesDict.xlsx is a LIWC dictionary made from standout, grindstone, agentic, and communal from the
   literature.
   4) physicsDepartments.xlsx and 
   5) sociologyDepartments.xlsx are the data for determining the F/M ratio for the writer pool.
   6) rank.xlsx is the writer rank data
   
Code:
   1) annotated_v5_LIWCanalysisForPaper.cxx is a ROOT macro for the LIWC dictionaries.
   2) rhbDictRank.cxx is the same for the extraCategory words, rank, and F/M writer ratios.
   
   Both of these make plots that were cleaned up in Illustrator.  You should put whatever you name Data 1) or 2) here.
   
   3) annotated_v5_LIWCanalysisMedianForPaper.cxx is a ROOT macro for the LIWC dictionaries but plots our medians.
   4) rhbDictRankMedian.cxx is the same for the extraCategory words, rank, and F/M writer ratios but plots our medians.
   
   Not all variables were changed to medians, just ones we used.  The extension is straightforward.
   
   5) ttestsWithDrives.do is a typical STATA file for Data 2).
   
   We supplied all the LIWC variable outputs.  We do not think you should plot variables we did not publish without much 
   thought.Many of these LIWC categories have words associated with subject matter or are otherwise problematic. 
   The ones we did use were checked by RHB and the drives formula was chosen after looking at all letters, 
   but then the results were blind -- we got what we got without further change.  The LIWC summary variables have 
   particularly tricky problems, and Jamie Pennebaker explained the private algorithms and we decided not to use them.  
   The raw letter data are not available for reasons of confidentiality, especially in EPP. 
   
   If you have questions contact rhbob@fnal.gov.
   

   
