
#include<sqlite3.h>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cmath>
using namespace std;


int main(int nNumberofArgs, char* pszArgs[])
   {   cout << "Per. #\t" <<" Fact\t" <<"  BS-Trend\t" << " Residue-One\t" <<"   Sharp\t  " << " Flat\t"
   << "    Model\t   "<<"ResTwo" <<endl;
    cout << "\n";

    const int size =62;
    int arrPeriods[size];
    for(int i=0; i<size; i++){

        arrPeriods[i] = i+1;

    }

   double arrFactAssets [size];
arrFactAssets[0]  =   1.000000;
arrFactAssets[1]  =   1.157483;
arrFactAssets[2]  =   1.219787;
arrFactAssets[3]  =   1.251081;
arrFactAssets[4]  =   1.299898;
arrFactAssets[5]  =   1.413524;
arrFactAssets[6]  =   1.468954;
arrFactAssets[7]  =   1.708543;
arrFactAssets[8]  =   1.838737;
arrFactAssets[9]  =   1.950833;
arrFactAssets[10]  =  2.104963;
arrFactAssets[11]  =  2.398589;
arrFactAssets[12]  =  2.585100;
arrFactAssets[13]  =  2.719387;
arrFactAssets[14]  =  2.86842;
arrFactAssets[15]  =  3.033058;
arrFactAssets[16]  =  3.200906;
arrFactAssets[17]  =  3.573864;
arrFactAssets[18]  =  3.857833;
arrFactAssets[19]  =  4.259713;
arrFactAssets[20]  =  4.805432;
arrFactAssets[21]  =  5.11538;
arrFactAssets[22]  =  5.705583;
arrFactAssets[23]  =  6.113655;
arrFactAssets[24]  =  6.79834;
arrFactAssets[25]  = 7.690231;
arrFactAssets[26]  = 7.647407;
arrFactAssets[27]  = 8.604734;
arrFactAssets[28]  = 9.38766;
arrFactAssets[29]  = 10.45369;
arrFactAssets[30]  = 12.17445;
arrFactAssets[31]  = 12.94906;
arrFactAssets[32]  = 14.49008;
arrFactAssets[33]  = 16.36286;
arrFactAssets[34]  = 19.36383;
arrFactAssets[35]  = 21.54175;
arrFactAssets[36]  = 25.04988;
arrFactAssets[37]  = 28.95277;
arrFactAssets[38]  = 34.11908;
arrFactAssets[39]  = 36.7509;
arrFactAssets[40]  = 39.77085;
arrFactAssets[41]  = 43.01082;
arrFactAssets[42]  = 52.71509;
arrFactAssets[43]  = 49.55857;
arrFactAssets[44]  = 49.22054;
arrFactAssets[45]  = 50.6586;
arrFactAssets[46]  = 49.71887;
arrFactAssets[47]  = 49.80512;
arrFactAssets[48]  = 50.3909;
arrFactAssets[49]  = 52.22618;
arrFactAssets[50]  = 53.62571;
arrFactAssets[51]  = 56.6397;
arrFactAssets[52]  = 58.05012;
arrFactAssets[53]  = 58.58243;
arrFactAssets[54]  = 60.01174;
arrFactAssets[55]  = 61.61700;
arrFactAssets[56]  = 62.86486;
arrFactAssets[57]  = 63.60773;
arrFactAssets[58]  = 64.16179;
arrFactAssets[59]  = 65.18392;
arrFactAssets[60]  = 67.97739;
arrFactAssets[61]  = 70.12867;




    double arrBS_Trend[size];
    const double PRIMACONST = 1.000000;
    const double dalpha = 1.260474671;
    const double dbeta = 22.96552188;
    double dMinPower;
    double dFraction;
    double dWeib;
    double darrResOne[size];

    for (int i=0; i < size; i++){
        dFraction = (i)/dbeta;
        dMinPower = pow(dFraction, dalpha);
        dWeib = PRIMACONST*exp(dMinPower);
        arrBS_Trend[i]=dWeib;
        darrResOne[i] = arrFactAssets[i] - arrBS_Trend[i];


    double arrTrendSH[size];
    const double PRIMACONST_SH = 36.030000;
    const double ASH =43.0;
    const double dalphaSH = 0.999;
    const double dbetaSH = 8.0;
    double dMinPowerSH;
    double dFractionSH;
    double dWeibSH;
    double argUmSH = abs(i+1-ASH);


        dFractionSH = argUmSH/dbetaSH;
        dMinPowerSH = -pow(dFractionSH, dalphaSH);
        dWeibSH = PRIMACONST_SH*exp(dMinPowerSH);
        arrTrendSH[i]=dWeibSH;




    double arrTrendFL[size];
    const double PRIMACONST_FL = 35.87263;
    const double AFL =62.0;
    const double dalphaFL = 2.8344;
    const double dbetaFL = 16.45;
    double dMinPowerFL;
    double dFractionFL;
    double dWeibFL;
    double argUmFL = abs(i+1-AFL);

        dFractionFL = argUmFL/dbetaFL;
        dMinPowerFL = -pow(dFractionFL, dalphaFL);
        dWeibFL = PRIMACONST_FL*exp(dMinPowerFL);
        arrTrendFL[i]=dWeibFL;

   double arrModelWeib[size];

          arrModelWeib[i]= arrBS_Trend[i] + arrTrendSH[i] + arrTrendFL[i];

   double arrResTWo[size];
         arrResTWo[i] = arrFactAssets[i] - arrModelWeib[i];


   cout << arrPeriods[i]<< "\t " <<  arrFactAssets[i]  << "      \t"<< arrBS_Trend[i]
   << "\t       "  << darrResOne[i]<<"\t   " <<arrTrendSH[i]<<"\t" << arrTrendFL[i] << "\t"<< arrModelWeib[i]
   <<"\t"<<arrResTWo[i]<<endl;

        }


    cout << "Press Enter to continue..." << endl;


    return 0;