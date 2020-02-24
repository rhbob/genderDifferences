cap drop _all
import excel "/Users/rhbob/Desktop/stata/annotated_v6_drives.xlsx", sheet("annotated_v6_drives") firstrow clear
keep CandID-WC Ability posemo negemo achieve Standout Grindstone Agentic Communal

cap label drop can_gender
label define can_gender 1 "Female" 0 "Male"
label values can can_gender

cap label drop writer_gender
label define writer_gender 1 "Female Writer" 0 "Male Writer"
label values writer writer_gender

cap label drop discipline
label define discipline 1 "EPP" 0 "Social Science"
label values discipline discipline

label var WC "Word Count"
label var posemo "Positive Affect"
label var negemo "Negative Affect"
label var achieve "Achievement Words"
label var Standout "Standout Words"
label var Grindstone "Grindstone Words"
label var Agentic "Agentic Words"
label var Communal "Communal Words"

gen sorter=_n
save LOR_fromChris,replace

mac drop _all
foreach x in WC posemo negemo achieve Standout Grindstone Agentic Communal Ability{
	ttest `x' if discipline==0 & writer==0,by(can)
	global `x'_0_0_n=r(N_1)+r(N_2)
	global `x'_0_0_d=r(mu_1)-r(mu_2)
	global `x'_0_0_t=r(t)
	global `x'_0_0_p=r(p)
	
	ttest `x' if discipline==0 & writer==1,by(can)
	global `x'_0_1_n=r(N_1)+r(N_2)
	global `x'_0_1_d=r(mu_1)-r(mu_2)
	global `x'_0_1_t=r(t)
	global `x'_0_1_p=r(p)

	ttest `x' if discipline==1 & writer==0,by(can)
	global `x'_1_0_n=r(N_1)+r(N_2)
	global `x'_1_0_d=r(mu_1)-r(mu_2)
	global `x'_1_0_t=r(t)
	global `x'_1_0_p=r(p)
	
	ttest `x' if discipline==1 & writer==1,by(can)
	global `x'_1_1_n=r(N_1)+r(N_2)
	global `x'_1_1_d=r(mu_1)-r(mu_2)
	global `x'_1_1_t=r(t)
	global `x'_1_1_p=r(p)
}

foreach x in WC posemo negemo achieve Standout Grindstone Agentic Communal Ability {

noi di "`x'"  " | " "Physics" " | " "Male Writer  " " | " $`x'_1_0_d " | " $`x'_1_0_t " | " $`x'_1_0_p " | " $`x'_1_0_n

noi di "`x'"  " | " "Physics" " | " "Female Writer" " | " $`x'_1_1_d " | " $`x'_1_1_t " | " $`x'_1_1_p " | " $`x'_1_1_n 

noi di "`x'"  " | " "Social " " | " "Male Writer  " " | " $`x'_0_0_d " | " $`x'_0_0_t " | " $`x'_0_0_p " | " $`x'_0_0_n 

noi di "`x'"  " | " "Social " " | " "Female Writer" " | " $`x'_0_1_d " | " $`x'_0_1_t " | " $`x'_0_1_p " | " $`x'_0_1_n

}

cibar WC, over1(can) over2(writer) over3(disc) barcol(ltblue erose ) blsize(tiny) graphopts(ytitle("Word Count")legend(off))
graph export fig1_WC.eps,replace

cibar posemo, over1(can) over2(writer) over3(disc) barcol(ltblue erose ) blsize(tiny) graphopts(ytitle("Positive Affect")legend(off))
graph export fig1_posemo.eps,replace
 
cibar negemo, over1(can) over2(writer) over3(disc) barcol(ltblue erose ) blsize(tiny) graphopts(ytitle("Negative Affect")legend(off)) 
graph export fig1_negemo.eps,replace

cibar achieve, over1(can) over2(writer) over3(disc) barcol(ltblue erose ) blsize(tiny) graphopts(ytitle("Achievement Words")legend(off))
graph export fig1_achieve.eps,replace 

cibar Standout, over1(can) over2(writer) over3(disc) barcol(ltblue erose ) blsize(tiny) graphopts(ytitle("Standout Words")legend(off))
graph export fig1_standout.eps,replace
 
cibar Grindstone, over1(can) over2(writer) over3(disc) barcol(ltblue erose ) blsize(tiny) graphopts(ytitle("Grindstone Words")legend(off))
graph export fig1_grindstone.eps,replace
 
cibar Agentic, over1(can) over2(writer) over3(disc) barcol(ltblue erose ) blsize(tiny) graphopts(ytitle("Agentic Words"))
graph export fig1_agentic.eps,replace

cibar Communal, over1(can) over2(writer) over3(disc) barcol(ltblue erose ) blsize(tiny) graphopts(ytitle("Communal Words"))
graph export fig1_communal.eps,replace 

cibar Ability, over1(can) over2(writer) over3(disc) barcol(ltblue erose ) blsize(tiny) graphopts(ytitle("Ability Words"))
graph export fig1_communal.eps,replace 


// ***** graph combine fig1_WC.gph fig1_agentic.gph fig1_communal.gph,fig1_achievement.gph fig1_grindstone.gph  fig1_standout.gph fig1_posemo.gph fig1_negemo.gph, rows(4) cols(2) 
 
// ***** graph save fig1,replace



// ***** Ignores gender of writer:

mac drop _all
foreach x in WC posemo negemo achieve Standout Grindstone Agentic Communal {
	ttest `x' if discipline==0,by(can)
	global `x'_0_n=r(N_1)+r(N_2)
	global `x'_0_d=r(mu_1)-r(mu_2)
	global `x'_0_t=r(t)
	global `x'_0_p=r(p)
	
	ttest `x' if discipline==1,by(can)
	global `x'_1_n=r(N_1)+r(N_2)
	global `x'_1_d=r(mu_1)-r(mu_2)
	global `x'_1_t=r(t)
	global `x'_1_p=r(p)
}

foreach x in WC posemo negemo achieve Standout Grindstone Agentic Communal {

noi di "`x'"  " | " "Physics" " | " $`x'_0_d " | " $`x'_0_t " | " $`x'_0_p " | " $`x'_0_n

noi di "`x'"  " | " "Social " " | " $`x'_1_d " | " $`x'_1_t " | " $`x'_1_p " | " $`x'_1_n
}


// *** Compares M and F non-advisors for the candidates with letters from both genders


foreach x in WC posemo negemo achieve Standout Grindstone Agentic Communal {
	ttest `x' if discipline==0 & both_g==1,by(writer)
	global `x'_0_n=r(N_1)+r(N_2)
	global `x'_0_d=r(mu_1)-r(mu_2)
	global `x'_0_t=r(t)
	global `x'_0_p=r(p)

	ttest `x' if discipline==1 & both_g==1,by(writer)
	global `x'_1_n=r(N_1)+r(N_2)
	global `x'_1_d=r(mu_1)-r(mu_2)
	global `x'_1_t=r(t)
	global `x'_1_p=r(p)
}

noi di "These are results for letters by non-advisors who wrote candidates with letters from both genders"

foreach x in WC posemo negemo achieve Standout Grindstone Agentic Communal {
	noi di "`x'"  " | " "Social"   " | " $`x'_0_d " | " $`x'_0_t " | " $`x'_0_p " | " $`x'_0_n
	noi di "`x'"  " | " "Physics " " | " $`x'_1_d " | " $`x'_1_t " | " $`x'_1_p " | " $`x'_1_n
}


// * Two tests for gender differences in the status of authors of letters for M and F candidates.
// * One test is for academic rank of the author, the other test is for gender of the author.

ttest writer if discipline==0,by(can)
	global female_0_n=r(N_1)+r(N_2)
	global female_0_d=r(mu_1)-r(mu_2)
	global female_0_t=r(t)
	global female_0_p=r(p)	
	
ttest writer if discipline==1,by(can)
	global female_1_n=r(N_1)+r(N_2)
	global female_1_d=r(mu_1)-r(mu_2)
	global female_1_t=r(t)
	global female_1_p=r(p)

noi di "female writer"  " | " "Social " " | " $female_0_d " | " $female_0_t " | " $female_0_p " | " $female_0_n

noi di "female writer"  " | " "EPP    " " | " $female_1_d " | " $female_1_t " | " $female_1_p " | " $female_1_n


foreach x in RefRank {
	spearman `x' can if discipline==0 & writer==0
	global `x'_0_0_n=r(N)
	global `x'_0_0_r=r(rho)
	global `x'_0_0_p=r(p)

	spearman `x' can if discipline==0 & writer==1
	global `x'_0_1_n=r(N)
	global `x'_0_1_r=r(rho)
	global `x'_0_1_p=r(p)

	spearman `x' can if discipline==1 & writer==0
	global `x'_1_0_n=r(N)
	global `x'_1_0_r=r(rho)
	global `x'_1_0_p=r(p)
	
	spearman `x' can if discipline==1 & writer==1
	global `x'_1_1_n=r(N)
	global `x'_1_1_r=r(rho)
	global `x'_1_1_p=r(p)
}

foreach x in RefRank {

noi di "`x'"  " | " "Physics" " | " "Male Writer  " " | " $`x'_1_0_r " | " $`x'_1_0_p " | " $`x'_1_0_n

noi di "`x'"  " | " "Physics" " | " "Female Writer" " | " $`x'_1_1_d " | " $`x'_1_1_p " | " $`x'_1_1_n 

noi di "`x'"  " | " "Social " " | " "Male Writer  " " | " $`x'_0_0_d " | " $`x'_0_0_p " | " $`x'_0_0_n 

noi di "`x'"  " | " "Social " " | " "Female Writer" " | " $`x'_0_1_d " | " $`x'_0_1_p " | " $`x'_0_1_n

}


// Test for Ability

mac drop _all
foreach x in Ability {
	ttest `x' if discipline==0 & writer==0,by(can)
	global `x'_0_0_n=r(N_1)+r(N_2)
	global `x'_0_0_d=r(mu_1)-r(mu_2)
	global `x'_0_0_t=r(t)
	global `x'_0_0_p=r(p)
	
	ttest `x' if discipline==0 & writer==1,by(can)
	global `x'_0_1_n=r(N_1)+r(N_2)
	global `x'_0_1_d=r(mu_1)-r(mu_2)
	global `x'_0_1_t=r(t)
	global `x'_0_1_p=r(p)

	ttest `x' if discipline==1 & writer==0,by(can)
	global `x'_1_0_n=r(N_1)+r(N_2)
	global `x'_1_0_d=r(mu_1)-r(mu_2)
	global `x'_1_0_t=r(t)
	global `x'_1_0_p=r(p)
	
	ttest `x' if discipline==1 & writer==1,by(can)
	global `x'_1_1_n=r(N_1)+r(N_2)
	global `x'_1_1_d=r(mu_1)-r(mu_2)
	global `x'_1_1_t=r(t)
	global `x'_1_1_p=r(p)
}

foreach x in Ability {

noi di "`x'"  " | " "Physics" " | " "Male Writer  " " | " $`x'_1_0_d " | " $`x'_1_0_t " | " $`x'_1_0_p " | " $`x'_1_0_n

noi di "`x'"  " | " "Physics" " | " "Female Writer" " | " $`x'_1_1_d " | " $`x'_1_1_t " | " $`x'_1_1_p " | " $`x'_1_1_n 

noi di "`x'"  " | " "Social " " | " "Male Writer  " " | " $`x'_0_0_d " | " $`x'_0_0_t " | " $`x'_0_0_p " | " $`x'_0_0_n 

noi di "`x'"  " | " "Social " " | " "Female Writer" " | " $`x'_0_1_d " | " $`x'_0_1_t " | " $`x'_0_1_p " | " $`x'_0_1_n

}
