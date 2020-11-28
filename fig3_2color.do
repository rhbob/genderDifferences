use epp_masterfile_stemmed2,clear
sort dif_doc_b
keep if pxct_doc_b<.05 | pxct_doc_f<.05 | pxct_doc_m<.05 
drop if stemvar=="merit"
drop if stemvar=="stateoftheart"
replace dif_doc_b=dif_doc_b*100
replace dif_doc_b_hi=dif_doc_b_hi*100
replace dif_doc_b_lo=dif_doc_b_lo*100
ren dif_doc_b dif_doc
ren  dif_doc_b_lo dif_doc_lo
ren  dif_doc_b_hi dif_doc_hi
cap drop tmp
gen tmp=_n

label define tmp 1 `"physicist*"', modify
label define tmp 2 `"discover*"', modify
label define tmp 3 `"idea*"', modify
label define tmp 4 `"intellectu*"', modify
label define tmp 5 `"technical*"', modify
label define tmp 6 `"innovat*"', modify
label define tmp 7 `"creativ*"', modify
label define tmp 8 `"dedicat*"', modify
label define tmp 9 `"talent*"', modify
label define tmp 10 `"notabl*"', modify
label define tmp 11 `"brilliant*"', modify

label value tmp tmp

cap drop dif_doc1 
cap drop dif_doc2
gen dif_doc1=dif_doc if tmp==5 | tmp==8
gen dif_doc2=dif_doc if tmp~=5 & tmp~=8 
//gen dif_doc3=dif_doc if tmp==

twoway rcap dif_doc_hi dif_doc_lo tmp  || scatter dif_doc1 tmp, mcolor(blue) || scatter dif_doc2 tmp, mcolor(red) xline(1 2 3 4 5 6 7 8 9 10 11,lpattern(dash) lcolor(bluishgray%100))  yscale(alt) l1title(EPP) l2title(" Favors Men                                      Favors Women", size(small) ring(0)) ytitle(Percent)yline(0,lcolor(black)) xtitle("")ylabel(-20(10)20) xlabel(1(1)11, labels angle(vertical) labsize(small) valuelabel) legend(off)

graph save fig3_epp.gph,replace


use soc_masterfile_stemmed2,clear
sort dif_doc_b
keep if pxct_doc_b<.05 | pxct_doc_f<.05 | pxct_doc_m<.05
drop if stemvar=="superb" 
replace dif_doc_b=dif_doc_b*100
replace dif_doc_b_hi=dif_doc_b_hi*100
replace dif_doc_b_lo=dif_doc_b_lo*100
ren dif_doc_b dif_doc
ren  dif_doc_b_lo dif_doc_lo
ren  dif_doc_b_hi dif_doc_hi
drop if stemvar=="superb"
cap drop tmp
cap label drop tmp
gen tmp=_n

label define tmp 1 `"scienc*"', modify
label define tmp 2 `"technical*"', modify
label define tmp 3 `"discover*"', modify
label define tmp 4 `"deft*"', modify
label define tmp 5 `"milestone*"', modify
label define tmp 6 `"well-regarded"', modify
label define tmp 7 `"disciplined"', modify
label define tmp 8 `"first-author*"', modify
label define tmp 9 `"volunteer*"', modify
label define tmp 10 `"initiativ*"', modify
label define tmp 11 `"ambitio*"', modify
label define tmp 12 `"delight*"', modify
label define tmp 13 `"excel*"', modify
label define tmp 14 `"accomplish*"', modify
label define tmp 15 `"success*"', modify
label define tmp 16 `"commit*"', modify

label value tmp tmp

cap drop dif_doc1 
cap drop dif_doc2
gen dif_doc1=dif_doc if tmp==2 | tmp==3  | tmp==4  | tmp==9 
gen dif_doc2=dif_doc if tmp==1 | tmp==6  | tmp==7  | tmp==8  | tmp==12 | tmp==15 | tmp==16     
gen dif_doc3=dif_doc if tmp==5 | tmp==10 | tmp==11 | tmp==13 | tmp==14  

label var dif_doc1 "Mainly Female Writers"
label var dif_doc2 "Mainly Male Writers"
label var dif_doc3 "Equal"

twoway rcap dif_doc_hi dif_doc_lo tmp  || scatter dif_doc1 tmp, mcolor(blue) || scatter dif_doc3 tmp, mcolor(black) || scatter dif_doc2 tmp, mcolor(red) xline(1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16,lpattern(dash) lcolor(bluishgray%100))  yscale(alt) l1title(Social Science) l2title(" Favors Men                                Favors Women", size(small) ring(0)) ytitle(Percent)yline(0,lcolor(black)) xtitle("")ylabel(-20(10)20) xlabel(1(1)16, labels angle(vertical) labsize(small) valuelabel) legend(rows(1) pos(12) order(2 4 3) size(small))

graph save fig3_soc.gph,replace

graph combine fig3_soc.gph fig3_epp.gph, cols(1) xsize(8) ysize(11) r2title("Gender difference in percent of letters containing term", size(small)) 

graph save fig3_2color,replace
graph export fig3_2color.jpg, as(jpg) name("Graph") quality(100) replace

