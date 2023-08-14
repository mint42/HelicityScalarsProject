#ifndef TREE_VARIABLES_H
# define TREE_VARIABLES_H

# define NUM_VARS 22
# define NUM_PARAMS 2

# define SCAL_VARS(i) (vars[i][0])
# define HELI_VARS(i) (vars[i][1])

const char	*vars[NUM_VARS][NUM_PARAMS] =
{
//	"H.BCM1.scaler",          "H.BCM1_Hel.scaler",
	"H.BCM1.scalerRate",      "H.BCM1_Hel.scalerRate",
//	"H.Empty.scaler",         "H.Empty.scaler",
//	"H.Empty.scalerRate",     "H.Empty.scalerRate",
//	"H.BCM2.scaler",          "H.BCM2_Hel.scaler",
	"H.BCM2.scalerRate",      "H.BCM2_Hel.scalerRate",
//	"H.Empty_2.scaler",       "H.Empty_2.scaler",
//	"H.Empty_2.scalerRate",   "H.Empty_2.scalerRate",
//	"H.BCM4B.scaler",         "H.BCM4B_Hel.scaler",
	"H.BCM4B.scalerRate",     "H.BCM4B_Hel.scalerRate",
//	"H.Unser.scaler",         "H.Unser_Hel.scaler",
	"H.Unser.scalerRate",     "H.Unser_Hel.scalerRate",
//	"H.1MHz.scaler",          "H.1MHz_Hel.scaler",
	"H.1MHz.scalerRate",      "H.1MHz_Hel.scalerRate",
//	"H.BCM4A.scaler",         "H.BCM4A_Hel.scaler",
	"H.BCM4A.scalerRate",     "H.BCM4A_Hel.scalerRate",
//	"H.BCM4C.scaler",         "H.BCM4C_Hel.scaler",
	"H.BCM4C.scalerRate",     "H.BCM4C_Hel.scalerRate",
//	"H.hL1ACCP.scaler",       "H.hL1ACCP_Hel.scaler",
	"H.hL1ACCP.scalerRate",   "H.hL1ACCP_Hel.scalerRate",
//	"H.pTRIG1.scaler",        "H.pTRIG1_Hel.scaler",
	"H.pTRIG1.scalerRate",    "H.pTRIG1_Hel.scalerRate",
//	"H.pTRIG2.scaler",        "H.pTRIG2_Hel.scaler",
	"H.pTRIG2.scalerRate",    "H.pTRIG2_Hel.scalerRate",
//	"H.pTRIG3.scaler",        "H.pTRIG3_Hel.scaler",
	"H.pTRIG3.scalerRate",    "H.pTRIG3_Hel.scalerRate",
//	"H.pTRIG4.scaler",        "H.pTRIG4_Hel.scaler",
	"H.pTRIG4.scalerRate",    "H.pTRIG4_Hel.scalerRate",
//	"H.pTRIG5.scaler",        "H.pTRIG5_Hel.scaler",
	"H.pTRIG5.scalerRate",    "H.pTRIG5_Hel.scalerRate",
//	"H.pTRIG6.scaler",        "H.pTRIG6_Hel.scaler",
	"H.pTRIG6.scalerRate",    "H.pTRIG6_Hel.scalerRate",
//	"H.hTRIG1.scaler",        "H.hTRIG1_Hel.scaler",
	"H.hTRIG1.scalerRate",    "H.hTRIG1_Hel.scalerRate",
//	"H.hTRIG2.scaler",        "H.hTRIG2_Hel.scaler",
	"H.hTRIG2.scalerRate",    "H.hTRIG2_Hel.scalerRate",
//	"H.hTRIG3.scaler",        "H.hTRIG3_Hel.scaler",
	"H.hTRIG3.scalerRate",    "H.hTRIG3_Hel.scalerRate",
//	"H.hTRIG4.scaler",        "H.hTRIG4_Hel.scaler",
	"H.hTRIG4.scalerRate",    "H.hTRIG4_Hel.scalerRate",
//	"H.hTRIG5.scaler",        "H.hTRIG5_Hel.scaler",
	"H.hTRIG5.scalerRate",    "H.hTRIG5_Hel.scalerRate",
//	"H.hTRIG6.scaler",        "H.hTRIG6_Hel.scaler",
	"H.hTRIG6.scalerRate",    "H.hTRIG6_Hel.scalerRate",
	"evcount",                "evcount",
	"evNumber",               "evNumber"
};

#endif
