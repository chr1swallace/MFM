#include <Rcpp.h>

using namespace Rcpp;

// [[Rcpp::export]]
double finnerK(NumericVector lvec, double n) {
 int K=lvec.size();
 double t1=0;
 double t2=0;
 double t3=0;
 double tmp=0;
 // double out=0;
 double lsum=0;
 // int x1=0;
 // int x2=0;
 
 for(int k=1; k< K; ++k) {
   lsum += lvec[k-1];
   t1 += Rf_lchoose(n-lsum,lvec[k]);   
   t3 += Rf_lchoose(n,lvec[k]);
  }
  
  
  //  tmp=v/n;
  // for(int i=0; i< K; ++i) {
  //  t2 += Rf_dbinom(lvec[i],n,tmp,1);
  // }
  // return(t1+t2-t3);

  return(t1 - t3);
}    

// [[Rcpp::export]]
double pp(double l, double n, double v) {
  Rf_dbinom(l,n,v/n,1);
}

// [[Rcpp::export]]
double kappa2(double pk, double n, double maxn, NumericVector LP) {
 double out=0;
 double tmp=0;
 double fsum=0;
 NumericVector lvec(2);
 double ok = pk/(1-pk);
 
 for(int i=0; i<=n; i++) {
   lvec[0]=i;
  for(int j=0; j<=n; j++) {
   lvec[1]=j;
   tmp=finnerK(lvec,n) + LP[i] + LP[j];
   fsum += exp(tmp);
  }
  }
       
 out = ok*fsum/(1-fsum); 
  
  return out;
}


// [[Rcpp::export]]
double kappa3(double pk, double n, double maxn, NumericVector LP) {
 double out=0;
 double tmp=0;
 double fsum=0;
 NumericVector lvec(3);
 double ok = pk/(1-pk);
 
 for(int i=0; i< maxn; ++i) {
   lvec[0]=i;
   for(int j=0; j<maxn; ++j) {
     lvec[1]=j;
     for(int k=0; k<maxn; ++k) {
       lvec[2]=k;
       tmp=finnerK(lvec,n) + LP[i] + LP[j] + LP[k];
       fsum += exp(tmp);
     }}}
       
 out = ok*fsum/(1-fsum); 
  
  return out;
}


// [[Rcpp::export]]
double kappa4(double pk, double n, double maxn, NumericVector LP) {
 double out=0;
 double tmp=0;
 double fsum=0;
 NumericVector lvec(4);
 double ok = pk/(1-pk);
 
 
 for(int i=0; i<=maxn; ++i) {
   lvec[0]=i;
  for(int j=0; j<=maxn; ++j) {
   lvec[1]=j;
   for(int k=0; k<=maxn; ++k) {
   lvec[2]=k;
    for(int l=0; l<=maxn; ++l) {
   lvec[3]=l;
   tmp=finnerK(lvec,n) + LP[i] + LP[j] + LP[k] + LP[l];
   fsum += exp(tmp);
  }}}}
       
 out = ok*fsum/(1-fsum); 
  
  return out;
}



