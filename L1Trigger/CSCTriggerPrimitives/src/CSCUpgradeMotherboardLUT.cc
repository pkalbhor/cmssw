#include "L1Trigger/CSCTriggerPrimitives/interface/CSCUpgradeMotherboardLUT.h"
#include "DataFormats/CSCDigi/interface/CSCConstants.h"

CSCGEMMotherboardLUT::CSCGEMMotherboardLUT()
    : lut_wg_eta_odd(0),
      lut_wg_eta_even(0),
      lut_pt_vs_dphi_gemcsc(0)

      ,
      gem_roll_eta_limits_odd_l1(0),
      gem_roll_eta_limits_odd_l2(0),
      gem_roll_eta_limits_even_l1(0),
      gem_roll_eta_limits_even_l2(0)

      ,
      csc_wg_to_gem_roll_odd_l1(0),
      csc_wg_to_gem_roll_odd_l2(0),
      csc_wg_to_gem_roll_even_l1(0),
      csc_wg_to_gem_roll_even_l2(0) {}

std::vector<std::pair<int, int> > CSCGEMMotherboardLUT::get_csc_wg_to_gem_roll(Parity par, int layer) const {
  if (par == Parity::Even) {
    return layer == 1 ? csc_wg_to_gem_roll_even_l1 : csc_wg_to_gem_roll_even_l2;
  } else {
    return layer == 1 ? csc_wg_to_gem_roll_odd_l1 : csc_wg_to_gem_roll_odd_l2;
  }
}

std::vector<int> CSCGEMMotherboardLUT::get_gem_roll_to_csc_wg(Parity par) const {
  if (par == Parity::Even) {
    return gem_roll_to_csc_wg_even;
  } else {
    return gem_roll_to_csc_wg_odd;
  }
}

std::vector<int> CSCGEMMotherboardLUTME11::get_gem_pad_to_csc_hs(Parity par, enum CSCPart p) const {
  if (p == CSCPart::ME1A) {
    return par == Parity::Even ? gem_pad_to_csc_hs_me1a_even : gem_pad_to_csc_hs_me1a_odd;
  } else {
    return par == Parity::Even ? gem_pad_to_csc_hs_me1b_even : gem_pad_to_csc_hs_me1b_odd;
  }
}

std::vector<int> CSCGEMMotherboardLUTME21::get_gem_pad_to_csc_hs(Parity par, enum CSCPart p) const {
  return par == Parity::Even ? gem_pad_to_csc_hs_even : gem_pad_to_csc_hs_odd;
}

std::vector<std::pair<int, int> > CSCGEMMotherboardLUTME21::get_csc_hs_to_gem_pad(Parity par, enum CSCPart p) const {
  return par == Parity::Even ? csc_hs_to_gem_pad_even : csc_hs_to_gem_pad_odd;
}

std::vector<std::pair<int, int> > CSCGEMMotherboardLUTME11::get_csc_hs_to_gem_pad(Parity par, enum CSCPart p) const {
  if (p == CSCPart::ME1A) {
    return par == Parity::Even ? csc_hs_to_gem_pad_me1a_even : csc_hs_to_gem_pad_me1a_odd;
  } else {
    return par == Parity::Even ? csc_hs_to_gem_pad_me1b_even : csc_hs_to_gem_pad_me1b_odd;
  }
}

CSCGEMMotherboardLUT::~CSCGEMMotherboardLUT() {}

CSCGEMMotherboardLUTME11::CSCGEMMotherboardLUTME11() : CSCGEMMotherboardLUT() {
  lut_wg_eta_odd = {{2.4466, 2.45344},  {2.33403, 2.43746}, {2.28122, 2.38447}, {2.23122, 2.33427}, {2.18376, 2.2866},
                    {2.1386, 2.24124},  {2.09556, 2.19796}, {2.05444, 2.15662}, {2.01511, 2.11704}, {1.97741, 2.07909},
                    {1.94124, 2.04266}, {1.90649, 2.00764}, {1.87305, 1.97392}, {1.84084, 1.94143}, {1.80978, 1.91008},
                    {1.77981, 1.87981}, {1.75086, 1.85055}, {1.72286, 1.82225}, {1.69577, 1.79484}, {1.66954, 1.76828},
                    {1.64412, 1.74253}, {1.61946, 1.71754}, {1.60584, 1.69328}, {1.60814, 1.6697}};

  lut_wg_eta_even = {{2.3981, 2.40492},  {2.28578, 2.38883}, {2.23311, 2.33595}, {2.18324, 2.28587}, {2.13592, 2.23831},
                     {2.09091, 2.19306}, {2.048, 2.14991},   {2.00704, 2.10868}, {1.96785, 2.06923}, {1.93031, 2.03141},
                     {1.8943, 1.9951},   {1.8597, 1.96021},  {1.82642, 1.92663}, {1.79438, 1.89427}, {1.76349, 1.86306},
                     {1.73369, 1.83293}, {1.70491, 1.80382}, {1.67709, 1.77566}, {1.65018, 1.7484},  {1.62413, 1.72199},
                     {1.59889, 1.69639}, {1.57443, 1.67155}, {1.56088, 1.64745}, {1.5631, 1.62403}};

  /*
    98% acceptance cuts of the GEM-CSC bending angle in ME1b
    for various pT thresholds and for even/odd chambers
   */
  lut_pt_vs_dphi_gemcsc = {{3, 0.03971647, 0.01710244},
                           {5, 0.02123785, 0.00928431},
                           {7, 0.01475524, 0.00650928},
                           {10, 0.01023299, 0.00458796},
                           {15, 0.00689220, 0.00331313},
                           {20, 0.00535176, 0.00276152},
                           {30, 0.00389050, 0.00224959},
                           {40, 0.00329539, 0.00204670}};

  gem_roll_eta_limits_odd_l1 = {{1.61082, 1.67865},
                                {1.67887, 1.7528},
                                {1.75303, 1.82091},
                                {1.82116, 1.89486},
                                {1.89513, 1.96311},
                                {1.9634, 2.037},
                                {2.03732, 2.10527},
                                {2.10562, 2.17903}};

  gem_roll_eta_limits_odd_l2 = {{1.61705, 1.68494},
                                {1.68515, 1.75914},
                                {1.75938, 1.8273},
                                {1.82756, 1.9013},
                                {1.90158, 1.96959},
                                {1.96988, 2.04352},
                                {2.04384, 2.11181},
                                {2.11216, 2.1856}};

  gem_roll_eta_limits_even_l1 = {{1.55079, 1.62477},
                                 {1.62497, 1.70641},
                                 {1.70663, 1.78089},
                                 {1.78113, 1.86249},
                                 {1.86275, 1.9371},
                                 {1.93739, 2.01855},
                                 {2.01887, 2.09324},
                                 {2.09358, 2.17456}};

  gem_roll_eta_limits_even_l2 = {{1.55698, 1.63103},
                                 {1.63123, 1.71275},
                                 {1.71297, 1.78728},
                                 {1.78752, 1.86894},
                                 {1.86921, 1.94359},
                                 {1.94388, 2.02509},
                                 {2.02541, 2.09981},
                                 {2.10015, 2.18115}};

  csc_wg_to_gem_roll_odd_l1 = {{-99, -99}, {-99, -99}, {-99, -99}, {-99, -99}, {-99, -99}, {-99, -99}, {-99, -99},
                               {-99, -99}, {-99, -99}, {8, -99},   {8, -99},   {8, -99},   {7, -99},   {7, 8},
                               {7, 8},     {6, 8},     {6, 8},     {6, 7},     {6, 7},     {5, 7},     {5, 7},
                               {5, 6},     {5, 6},     {4, 6},     {4, 6},     {4, 5},     {4, 5},     {4, 5},
                               {3, 5},     {3, -99},   {3, 4},     {3, 4},     {2, 4},     {2, 4},     {2, 4},
                               {2, 3},     {2, 3},     {2, 3},     {1, 3},     {1, 3},     {1, 2},     {1, 2},
                               {1, 2},     {-99, 2},   {-99, 2},   {-99, 2},   {-99, 1},   {-99, 1}};

  csc_wg_to_gem_roll_odd_l2 = {{-99, -99}, {-99, -99}, {-99, -99}, {-99, -99}, {-99, -99}, {-99, -99}, {-99, -99},
                               {-99, -99}, {8, -99},   {8, -99},   {8, -99},   {8, -99},   {7, -99},   {7, 8},
                               {7, 8},     {6, 8},     {6, 8},     {6, 7},     {6, 7},     {5, 7},     {5, 6},
                               {5, 6},     {5, 6},     {4, 6},     {4, 6},     {4, 5},     {4, 5},     {3, 5},
                               {3, 5},     {3, 4},     {3, 4},     {3, 4},     {2, 4},     {2, 4},     {2, 3},
                               {2, 3},     {2, 3},     {1, 3},     {1, 3},     {1, 2},     {1, 2},     {1, 2},
                               {1, 2},     {-99, 2},   {-99, 2},   {-99, 1},   {-99, 1},   {-99, 1}};

  csc_wg_to_gem_roll_even_l1 = {
      {-99, -99}, {-99, -99}, {-99, -99}, {-99, -99}, {-99, -99}, {-99, -99}, {-99, -99}, {8, -99}, {8, -99}, {8, -99},
      {7, -99},   {7, 8},     {7, 8},     {7, 8},     {6, 8},     {6, 7},     {6, 7},     {6, 7},   {5, 7},   {5, 6},
      {5, 6},     {5, 6},     {4, 6},     {4, 6},     {4, 5},     {4, 5},     {4, 5},     {3, 5},   {3, 5},   {3, 4},
      {3, 4},     {3, 4},     {2, 4},     {2, 4},     {2, 3},     {2, 3},     {2, 3},     {2, 3},   {1, 3},   {1, 3},
      {1, 2},     {1, 2},     {1, 2},     {1, 2},     {1, 2},     {1, 2},     {1, 1},     {1, 1}};

  csc_wg_to_gem_roll_even_l2 = {
      {-99, -99}, {-99, -99}, {-99, -99}, {-99, -99}, {-99, -99}, {-99, -99}, {-99, -99}, {8, -99}, {8, -99}, {8, -99},
      {7, -99},   {7, 8},     {7, 8},     {7, 8},     {6, 8},     {6, 7},     {6, 7},     {6, 7},   {5, 7},   {5, 6},
      {5, 6},     {5, 6},     {4, 6},     {4, 6},     {4, 5},     {4, 5},     {4, 5},     {3, 5},   {3, 4},   {3, 4},
      {3, 4},     {3, 4},     {2, 4},     {2, 4},     {2, 3},     {2, 3},     {2, 3},     {2, 3},   {1, 3},   {1, 2},
      {1, 2},     {1, 2},     {1, 2},     {1, 2},     {1, 2},     {1, 2},     {1, 1},     {1, 1}};

  gem_roll_to_csc_wg_odd = {38, 33, 28, 24, 20, 16, 12, 9};
  gem_roll_to_csc_wg_even = {43, 36, 31, 26, 21, 17, 13, 9};

  gem_pad_to_csc_hs_me1a_odd = {
      93, 92, 92, 92, 91, 91, 90, 90, 89, 89, 88, 88, 87, 87, 86, 86, 85, 85, 84, 84, 83, 83, 83, 82, 82, 81, 81, 80,
      80, 79, 79, 78, 78, 77, 77, 76, 76, 75, 75, 74, 74, 73, 73, 73, 72, 72, 71, 71, 70, 70, 69, 69, 68, 68, 67, 67,
      66, 66, 65, 65, 64, 64, 63, 63, 63, 62, 62, 61, 61, 60, 60, 59, 59, 58, 58, 57, 57, 56, 56, 55, 55, 54, 54, 53,
      53, 53, 52, 52, 51, 51, 50, 50, 49, 49, 48, 48, 47, 47, 46, 46, 45, 45, 44, 44, 43, 43, 43, 42, 42, 41, 41, 40,
      40, 39, 39, 38, 38, 37, 37, 36, 36, 35, 35, 34, 34, 33, 33, 33, 32, 32, 31, 31, 30, 30, 29, 29, 28, 28, 27, 27,
      26, 26, 25, 25, 24, 24, 23, 23, 23, 22, 22, 21, 21, 20, 20, 19, 19, 18, 18, 17, 17, 16, 16, 15, 15, 14, 14, 13,
      13, 13, 12, 12, 11, 11, 10, 10, 9,  9,  8,  8,  7,  7,  6,  6,  5,  5,  4,  4,  4,  3,  3,  2};

  gem_pad_to_csc_hs_me1b_odd = {
      123, 123, 122, 121, 121, 120, 119, 119, 118, 118, 117, 116, 116, 115, 114, 114, 113, 113, 112, 111, 111, 110,
      110, 109, 108, 108, 107, 106, 106, 105, 105, 104, 103, 103, 102, 101, 101, 100, 100, 99,  98,  98,  97,  96,
      96,  95,  95,  94,  93,  93,  92,  91,  91,  90,  90,  89,  88,  88,  87,  86,  86,  85,  85,  84,  83,  83,
      82,  81,  81,  80,  80,  79,  78,  78,  77,  76,  76,  75,  75,  74,  73,  73,  72,  71,  71,  70,  70,  69,
      68,  68,  67,  66,  66,  65,  65,  64,  63,  63,  62,  61,  61,  60,  60,  59,  58,  58,  57,  56,  56,  55,
      55,  54,  53,  53,  52,  51,  51,  50,  50,  49,  48,  48,  47,  46,  46,  45,  45,  44,  43,  43,  42,  41,
      41,  40,  40,  39,  38,  38,  37,  36,  36,  35,  35,  34,  33,  33,  32,  31,  31,  30,  30,  29,  28,  28,
      27,  26,  26,  25,  25,  24,  23,  23,  22,  21,  21,  20,  20,  19,  18,  18,  17,  16,  16,  15,  15,  14,
      13,  13,  12,  11,  11,  10,  10,  9,   8,   8,   7,   7,   6,   5,   5,   4};

  gem_pad_to_csc_hs_me1a_even = {
      3,  3,  4,  4,  5,  5,  5,  6,  6,  7,  7,  8,  8,  9,  9,  10, 10, 11, 11, 12, 12, 13, 13, 14, 14, 14, 15, 15,
      16, 16, 17, 17, 18, 18, 19, 19, 20, 20, 21, 21, 22, 22, 23, 23, 24, 24, 24, 25, 25, 26, 26, 27, 27, 28, 28, 29,
      29, 30, 30, 31, 31, 32, 32, 33, 33, 34, 34, 34, 35, 35, 36, 36, 37, 37, 38, 38, 39, 39, 40, 40, 41, 41, 42, 42,
      43, 43, 44, 44, 44, 45, 45, 46, 46, 47, 47, 48, 48, 49, 49, 50, 50, 51, 51, 52, 52, 53, 53, 54, 54, 54, 55, 55,
      56, 56, 57, 57, 58, 58, 59, 59, 60, 60, 61, 61, 62, 62, 63, 63, 64, 64, 65, 65, 65, 66, 66, 67, 67, 68, 68, 69,
      69, 70, 70, 71, 71, 72, 72, 73, 73, 74, 74, 74, 75, 75, 76, 76, 77, 77, 78, 78, 79, 79, 80, 80, 81, 81, 82, 82,
      83, 83, 84, 84, 84, 85, 85, 86, 86, 87, 87, 88, 88, 89, 89, 90, 90, 91, 91, 92, 92, 93, 93, 93};

  gem_pad_to_csc_hs_me1b_even = {
      4,   5,   6,   6,   7,   8,   8,   9,   9,   10,  11,  11,  12,  12,  13,  14,  14,  15,  16,  16,  17,  17,
      18,  19,  19,  20,  21,  21,  22,  22,  23,  24,  24,  25,  26,  26,  27,  27,  28,  29,  29,  30,  31,  31,
      32,  32,  33,  34,  34,  35,  36,  36,  37,  37,  38,  39,  39,  40,  41,  41,  42,  42,  43,  44,  44,  45,
      46,  46,  47,  47,  48,  49,  49,  50,  51,  51,  52,  52,  53,  54,  54,  55,  56,  56,  57,  57,  58,  59,
      59,  60,  61,  61,  62,  62,  63,  64,  64,  65,  66,  66,  67,  67,  68,  69,  69,  70,  71,  71,  72,  72,
      73,  74,  74,  75,  76,  76,  77,  77,  78,  79,  79,  80,  81,  81,  82,  82,  83,  84,  84,  85,  86,  86,
      87,  87,  88,  89,  89,  90,  91,  91,  92,  92,  93,  94,  94,  95,  95,  96,  97,  97,  98,  99,  99,  100,
      100, 101, 102, 102, 103, 104, 104, 105, 105, 106, 107, 107, 108, 109, 109, 110, 110, 111, 112, 112, 113, 114,
      114, 115, 115, 116, 117, 117, 118, 119, 119, 120, 120, 121, 122, 122, 123, 123};

  csc_hs_to_gem_pad_me1a_odd = {
      {192, 192}, {192, 192}, {192, 192}, {190, 191}, {188, 189}, {186, 187}, {184, 185}, {181, 182}, {179, 180},
      {177, 178}, {175, 176}, {173, 174}, {171, 172}, {169, 170}, {167, 168}, {165, 166}, {162, 163}, {160, 161},
      {158, 159}, {156, 157}, {154, 155}, {152, 153}, {150, 151}, {148, 149}, {146, 147}, {144, 145}, {141, 142},
      {139, 140}, {137, 138}, {135, 136}, {133, 134}, {131, 132}, {129, 130}, {127, 128}, {125, 126}, {123, 124},
      {120, 121}, {118, 119}, {116, 117}, {114, 115}, {112, 113}, {110, 111}, {108, 109}, {106, 107}, {104, 105},
      {102, 103}, {99, 100},  {97, 98},   {95, 96},   {93, 94},   {91, 92},   {89, 90},   {87, 88},   {85, 86},
      {83, 84},   {81, 82},   {79, 80},   {76, 77},   {74, 75},   {72, 73},   {70, 71},   {68, 69},   {66, 67},
      {64, 65},   {62, 63},   {60, 61},   {58, 59},   {55, 56},   {53, 54},   {51, 52},   {49, 50},   {47, 48},
      {45, 46},   {43, 44},   {41, 42},   {39, 40},   {37, 38},   {34, 35},   {32, 33},   {30, 31},   {28, 29},
      {26, 27},   {24, 25},   {22, 23},   {20, 21},   {18, 19},   {15, 16},   {13, 14},   {11, 12},   {9, 10},
      {7, 8},     {5, 6},     {3, 4},     {1, 2},     {0, 0},     {0, 0}};

  csc_hs_to_gem_pad_me1a_even = {
      {0, 0},     {0, 0},     {0, 0},     {1, 2},     {3, 4},     {5, 6},     {7, 8},     {9, 10},    {11, 12},
      {14, 15},   {16, 17},   {18, 19},   {20, 21},   {22, 23},   {24, 25},   {26, 27},   {28, 29},   {30, 31},
      {33, 34},   {35, 36},   {37, 38},   {39, 40},   {41, 42},   {43, 44},   {45, 46},   {47, 48},   {49, 50},
      {51, 52},   {54, 55},   {56, 57},   {58, 59},   {60, 61},   {62, 63},   {64, 65},   {66, 67},   {68, 69},
      {70, 71},   {72, 73},   {75, 76},   {77, 78},   {79, 80},   {81, 82},   {83, 84},   {85, 86},   {87, 88},
      {89, 90},   {91, 92},   {93, 94},   {95, 96},   {98, 99},   {100, 101}, {102, 103}, {104, 105}, {106, 107},
      {108, 109}, {110, 111}, {112, 113}, {114, 115}, {116, 117}, {119, 120}, {121, 122}, {123, 124}, {125, 126},
      {127, 128}, {129, 130}, {131, 132}, {133, 134}, {135, 136}, {137, 138}, {140, 141}, {142, 143}, {144, 145},
      {146, 147}, {148, 149}, {150, 151}, {152, 153}, {154, 155}, {156, 157}, {158, 159}, {161, 162}, {163, 164},
      {165, 166}, {167, 168}, {169, 170}, {171, 172}, {173, 174}, {175, 176}, {177, 178}, {180, 181}, {182, 183},
      {184, 185}, {186, 187}, {188, 189}, {190, 191}, {192, 192}, {192, 192}};

  csc_hs_to_gem_pad_me1b_odd = {
      {192, 192}, {192, 192}, {192, 192}, {192, 192}, {192, 192}, {190, 191}, {188, 189}, {187, 188}, {185, 186},
      {184, 185}, {182, 183}, {180, 181}, {179, 180}, {177, 178}, {176, 177}, {174, 175}, {172, 173}, {171, 172},
      {169, 170}, {168, 169}, {166, 167}, {164, 165}, {163, 164}, {161, 162}, {160, 161}, {158, 159}, {156, 157},
      {155, 156}, {153, 154}, {152, 153}, {150, 151}, {148, 149}, {147, 148}, {145, 146}, {143, 144}, {142, 143},
      {140, 141}, {139, 140}, {137, 138}, {135, 136}, {134, 135}, {132, 133}, {131, 132}, {129, 130}, {127, 128},
      {126, 127}, {124, 125}, {123, 124}, {121, 122}, {119, 120}, {118, 119}, {116, 117}, {115, 116}, {113, 114},
      {111, 112}, {110, 111}, {108, 109}, {107, 108}, {105, 106}, {104, 105}, {102, 103}, {100, 101}, {99, 100},
      {97, 98},   {96, 97},   {94, 95},   {92, 93},   {91, 92},   {89, 90},   {88, 89},   {86, 87},   {84, 85},
      {83, 84},   {81, 82},   {80, 81},   {78, 79},   {76, 77},   {75, 76},   {73, 74},   {72, 73},   {70, 71},
      {68, 69},   {67, 68},   {65, 66},   {64, 65},   {62, 63},   {60, 61},   {59, 60},   {57, 58},   {56, 57},
      {54, 55},   {52, 53},   {51, 52},   {49, 50},   {48, 49},   {46, 47},   {44, 45},   {43, 44},   {41, 42},
      {40, 41},   {38, 39},   {36, 37},   {35, 36},   {33, 34},   {31, 32},   {30, 31},   {28, 29},   {27, 28},
      {25, 26},   {23, 24},   {22, 23},   {20, 21},   {19, 20},   {17, 18},   {15, 16},   {14, 15},   {12, 13},
      {11, 12},   {9, 10},    {7, 8},     {6, 7},     {4, 5},     {3, 4},     {1, 2},     {0, 0},     {0, 0},
      {0, 0},     {0, 0}};

  csc_hs_to_gem_pad_me1b_even = {
      {0, 0},     {0, 0},     {0, 0},     {0, 0},     {0, 0},     {1, 2},     {3, 4},     {4, 5},     {6, 7},
      {8, 9},     {9, 10},    {11, 12},   {12, 13},   {14, 15},   {16, 17},   {17, 18},   {19, 20},   {20, 21},
      {22, 23},   {24, 25},   {25, 26},   {27, 28},   {28, 29},   {30, 31},   {32, 33},   {33, 34},   {35, 36},
      {36, 37},   {38, 39},   {40, 41},   {41, 42},   {43, 44},   {44, 45},   {46, 47},   {48, 49},   {49, 50},
      {51, 52},   {52, 53},   {54, 55},   {56, 57},   {57, 58},   {59, 60},   {60, 61},   {62, 63},   {64, 65},
      {65, 66},   {67, 68},   {68, 69},   {70, 71},   {72, 73},   {73, 74},   {75, 76},   {76, 77},   {78, 79},
      {80, 81},   {81, 82},   {83, 84},   {84, 85},   {86, 87},   {88, 89},   {89, 90},   {91, 92},   {92, 93},
      {94, 95},   {96, 97},   {97, 98},   {99, 100},  {100, 101}, {102, 103}, {104, 105}, {105, 106}, {107, 108},
      {108, 109}, {110, 111}, {112, 113}, {113, 114}, {115, 116}, {116, 117}, {118, 119}, {120, 121}, {121, 122},
      {123, 124}, {124, 125}, {126, 127}, {128, 129}, {129, 130}, {131, 132}, {132, 133}, {134, 135}, {136, 137},
      {137, 138}, {139, 140}, {140, 141}, {142, 143}, {144, 145}, {145, 146}, {147, 148}, {148, 149}, {150, 151},
      {152, 153}, {153, 154}, {155, 156}, {156, 157}, {158, 159}, {160, 161}, {161, 162}, {163, 164}, {164, 165},
      {166, 167}, {168, 169}, {169, 170}, {171, 172}, {172, 173}, {174, 175}, {176, 177}, {177, 178}, {179, 180},
      {181, 182}, {182, 183}, {184, 185}, {185, 186}, {187, 188}, {189, 190}, {190, 191}, {192, 192}, {192, 192},
      {192, 192}, {192, 192}};
}

CSCGEMMotherboardLUTME11::~CSCGEMMotherboardLUTME11() {}

CSCGEMMotherboardLUTME21::CSCGEMMotherboardLUTME21() : CSCGEMMotherboardLUT() {
  lut_wg_eta_odd = {{2.4305, 2.43067},  {2.42422, 2.4244},  {2.41385, 2.41403}, {2.40359, 2.40377}, {2.39345, 2.39363},
                    {2.3834, 2.38359},  {2.37347, 2.37365}, {2.36363, 2.36382}, {2.3539, 2.35409},  {2.34427, 2.34446},
                    {2.33473, 2.33492}, {2.32529, 2.32548}, {2.31594, 2.31614}, {2.30668, 2.30688}, {2.29752, 2.29771},
                    {2.28844, 2.28864}, {2.27945, 2.27965}, {2.27054, 2.27074}, {2.26172, 2.26192}, {2.25297, 2.25318},
                    {2.24431, 2.24452}, {2.23573, 2.23594}, {2.22723, 2.22744}, {2.2188, 2.21901},  {2.21045, 2.21067},
                    {2.20217, 2.20239}, {2.19397, 2.19419}, {2.18584, 2.18606}, {2.17778, 2.178},   {2.16978, 2.17},
                    {2.16186, 2.16208}, {2.154, 2.15423},   {2.14621, 2.14644}, {2.13848, 2.13871}, {2.13082, 2.13105},
                    {2.12322, 2.12346}, {2.11569, 2.11592}, {2.10821, 2.10845}, {2.1008, 2.10103},  {2.09344, 2.09368},
                    {2.08615, 2.08638}, {2.07891, 2.07915}, {2.07172, 2.07197}, {2.0646, 2.06484},  {2.05964, 2.05989},
                    {2.04842, 2.04866}, {2.04355, 2.0438},  {2.03664, 2.03689}, {2.02978, 2.03003}, {2.02297, 2.02323},
                    {2.01622, 2.01647}, {2.00951, 2.00977}, {2.00286, 2.00312}, {1.99625, 1.99651}, {1.98969, 1.98995},
                    {1.98318, 1.98344}, {1.97672, 1.97698}, {1.9703, 1.97057},  {1.96393, 1.96419}, {1.9576, 1.95787},
                    {1.95132, 1.95159}, {1.94508, 1.94535}, {1.93888, 1.93916}, {1.93273, 1.93301}, {1.92662, 1.9269},
                    {1.91995, 1.92023}, {1.91272, 1.913},   {1.90556, 1.90584}, {1.89845, 1.89874}, {1.8914, 1.89169},
                    {1.88441, 1.8847},  {1.87747, 1.87776}, {1.87059, 1.87088}, {1.86376, 1.86405}, {1.85698, 1.85728},
                    {1.85026, 1.85055}, {1.84358, 1.84388}, {1.83696, 1.83726}, {1.83039, 1.83069}, {1.82387, 1.82417},
                    {1.81901, 1.81931}, {1.80937, 1.80968}, {1.80459, 1.8049},  {1.79826, 1.79857}, {1.79197, 1.79229},
                    {1.78573, 1.78605}, {1.77954, 1.77986}, {1.77339, 1.77371}, {1.76729, 1.76761}, {1.76122, 1.76155},
                    {1.75521, 1.75553}, {1.74923, 1.74956}, {1.7433, 1.74362},  {1.7374, 1.73773},  {1.73155, 1.73188},
                    {1.72574, 1.72607}, {1.71997, 1.7203},  {1.71424, 1.71457}, {1.70855, 1.70888}, {1.70289, 1.70323},
                    {1.69728, 1.69762}, {1.6917, 1.69204},  {1.68616, 1.6865},  {1.68065, 1.681},   {1.67518, 1.67553},
                    {1.66975, 1.6701},  {1.66436, 1.66471}, {1.65899, 1.65935}, {1.65367, 1.65402}, {1.64838, 1.64873},
                    {1.64312, 1.64348}, {1.6379, 1.63826}};

  lut_wg_eta_even = {{2.40148, 2.4015},  {2.39521, 2.39522}, {2.38485, 2.38486}, {2.37459, 2.37461}, {2.36445, 2.36447},
                     {2.35442, 2.35443}, {2.34449, 2.34451}, {2.33466, 2.33468}, {2.32493, 2.32495}, {2.31531, 2.31533},
                     {2.30578, 2.3058},  {2.29634, 2.29636}, {2.287, 2.28702},   {2.27775, 2.27777}, {2.26859, 2.26862},
                     {2.25952, 2.25954}, {2.25053, 2.25056}, {2.24164, 2.24166}, {2.23282, 2.23285}, {2.22409, 2.22412},
                     {2.21544, 2.21546}, {2.20686, 2.20689}, {2.19837, 2.1984},  {2.18995, 2.18998}, {2.18161, 2.18164},
                     {2.17334, 2.17337}, {2.16515, 2.16518}, {2.15702, 2.15706}, {2.14897, 2.149},   {2.14099, 2.14102},
                     {2.13307, 2.13311}, {2.12523, 2.12526}, {2.11745, 2.11748}, {2.10973, 2.10977}, {2.10208, 2.10212},
                     {2.09449, 2.09453}, {2.08697, 2.087},   {2.0795, 2.07954},  {2.0721, 2.07214},  {2.06475, 2.06479},
                     {2.05747, 2.05751}, {2.05024, 2.05028}, {2.04307, 2.04311}, {2.03596, 2.036},   {2.03101, 2.03105},
                     {2.0198, 2.01985},  {2.01494, 2.01499}, {2.00804, 2.00809}, {2.0012, 2.00124},  {1.9944, 1.99445},
                     {1.98766, 1.98771}, {1.98097, 1.98102}, {1.97433, 1.97437}, {1.96773, 1.96778}, {1.96119, 1.96124},
                     {1.95469, 1.95474}, {1.94824, 1.94829}, {1.94183, 1.94188}, {1.93547, 1.93552}, {1.92916, 1.92921},
                     {1.92289, 1.92294}, {1.91667, 1.91672}, {1.91048, 1.91054}, {1.90435, 1.9044},  {1.89825, 1.8983},
                     {1.89159, 1.89165}, {1.88439, 1.88444}, {1.87724, 1.8773},  {1.87015, 1.87021}, {1.86312, 1.86318},
                     {1.85614, 1.8562},  {1.84922, 1.84928}, {1.84236, 1.84241}, {1.83554, 1.8356},  {1.82878, 1.82884},
                     {1.82208, 1.82214}, {1.81542, 1.81548}, {1.80882, 1.80888}, {1.80227, 1.80233}, {1.79576, 1.79583},
                     {1.79092, 1.79098}, {1.78131, 1.78137}, {1.77654, 1.77661}, {1.77023, 1.7703},  {1.76396, 1.76403},
                     {1.75775, 1.75781}, {1.75157, 1.75164}, {1.74544, 1.74551}, {1.73936, 1.73943}, {1.73332, 1.73338},
                     {1.72732, 1.72739}, {1.72136, 1.72143}, {1.71545, 1.71552}, {1.70958, 1.70965}, {1.70374, 1.70382},
                     {1.69795, 1.69803}, {1.6922, 1.69228},  {1.68649, 1.68657}, {1.68082, 1.68089}, {1.67519, 1.67526},
                     {1.66959, 1.66967}, {1.66403, 1.66411}, {1.65851, 1.65859}, {1.65303, 1.65311}, {1.64759, 1.64766},
                     {1.64218, 1.64225}, {1.6368, 1.63688},  {1.63146, 1.63154}, {1.62616, 1.62624}, {1.62089, 1.62097},
                     {1.61565, 1.61573}, {1.61045, 1.61053}};

  /*
    98% acceptance cuts of the GEM-CSC bending angle in ME21
    for various pT thresholds and for even/odd chambers
   */
  lut_pt_vs_dphi_gemcsc = {{3, 0.01832829, 0.01003643},
                           {5, 0.01095490, 0.00631625},
                           {7, 0.00786026, 0.00501017},
                           {10, 0.00596349, 0.00414560},
                           {15, 0.00462411, 0.00365550},
                           {20, 0.00435298, 0.00361550},
                           {30, 0.00465160, 0.00335700},
                           {40, 0.00372145, 0.00366262}};

  // roll 1 through 8
  gem_roll_eta_limits_odd_l1 = {{1.64351, 1.70857},
                                {1.70864, 1.77922},
                                {1.79143, 1.86953},
                                {1.8696, 1.95538},
                                {1.97034, 2.06691},
                                {2.06701, 2.17505},
                                {2.19413, 2.31912},
                                {2.31924, 2.46333}};

  gem_roll_eta_limits_odd_l2 = {{1.64764, 1.71913},
                                {1.71919, 1.79737},
                                {1.80979, 1.89713},
                                {1.8972, 1.99417},
                                {2.00973, 2.10042},
                                {2.10052, 2.20119},
                                {2.22072, 2.33613},
                                {2.33625, 2.46772}};

  gem_roll_eta_limits_even_l1 = {{1.6407, 1.70574},
                                 {1.70581, 1.77636},
                                 {1.78857, 1.86665},
                                 {1.86672, 1.95247},
                                 {1.96743, 2.06399},
                                 {2.06408, 2.1721},
                                 {2.19118, 2.31615},
                                 {2.31627, 2.46036}};

  gem_roll_eta_limits_even_l2 = {{1.64485, 1.71631},
                                 {1.71637, 1.79453},
                                 {1.80694, 1.89425},
                                 {1.89433, 1.99127},
                                 {2.00683, 2.0975},
                                 {2.0976, 2.19825},
                                 {2.21778, 2.33317},
                                 {2.3333, 2.46475}};

  csc_wg_to_gem_roll_odd_l1 = {
      {8, 8}, {8, 8}, {8, 8}, {8, 8}, {8, 8}, {8, 8}, {8, 8}, {8, 8}, {8, 8}, {8, 8}, {8, 8}, {7, 7}, {7, 7}, {7, 7},
      {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7},
      {6, 6}, {6, 6}, {6, 6}, {6, 6}, {6, 6}, {6, 6}, {6, 6}, {6, 6}, {6, 6}, {6, 6}, {6, 6}, {6, 6}, {6, 6}, {6, 6},
      {5, 5}, {5, 5}, {5, 5}, {5, 5}, {5, 5}, {5, 5}, {5, 5}, {5, 5}, {5, 5}, {5, 5}, {5, 5}, {5, 5}, {5, 5}, {5, 5},
      {5, 5}, {5, 5}, {4, 4}, {4, 4}, {4, 4}, {4, 4}, {4, 4}, {4, 4}, {4, 4}, {4, 4}, {4, 4}, {4, 4}, {4, 4}, {4, 4},
      {4, 4}, {3, 3}, {3, 3}, {3, 3}, {3, 3}, {3, 3}, {3, 3}, {3, 3}, {3, 3}, {3, 3}, {3, 3}, {3, 3}, {3, 3}, {3, 3},
      {3, 3}, {2, 2}, {2, 2}, {2, 2}, {2, 2}, {2, 2}, {2, 2}, {2, 2}, {2, 2}, {2, 2}, {2, 2}, {2, 2}, {2, 2}, {1, 1},
      {1, 1}, {1, 1}, {1, 1}, {1, 1}, {1, 1}, {1, 1}, {1, 1}, {1, 1}, {1, 1}, {1, 1}, {1, 1}, {1, 1}, {1, 1}, {1, 1}};

  csc_wg_to_gem_roll_odd_l2 = {
      {8, 8}, {8, 8}, {8, 8}, {8, 8}, {8, 8}, {8, 8}, {8, 8}, {8, 8}, {8, 8}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7},
      {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {6, 6}, {6, 6}, {6, 6}, {6, 6},
      {6, 6}, {6, 6}, {6, 6}, {6, 6}, {6, 6}, {6, 6}, {6, 6}, {6, 6}, {6, 6}, {5, 5}, {5, 5}, {5, 5}, {5, 5}, {5, 5},
      {5, 5}, {5, 5}, {5, 5}, {5, 5}, {5, 5}, {5, 5}, {5, 5}, {5, 5}, {5, 5}, {5, 5}, {4, 4}, {4, 4}, {4, 4}, {4, 4},
      {4, 4}, {4, 4}, {4, 4}, {4, 4}, {4, 4}, {4, 4}, {4, 4}, {4, 4}, {4, 4}, {4, 4}, {4, 4}, {3, 3}, {3, 3}, {3, 3},
      {3, 3}, {3, 3}, {3, 3}, {3, 3}, {3, 3}, {3, 3}, {3, 3}, {3, 3}, {3, 3}, {3, 3}, {3, 3}, {3, 3}, {2, 2}, {2, 2},
      {2, 2}, {2, 2}, {2, 2}, {2, 2}, {2, 2}, {2, 2}, {2, 2}, {2, 2}, {2, 2}, {2, 2}, {2, 2}, {1, 1}, {1, 1}, {1, 1},
      {1, 1}, {1, 1}, {1, 1}, {1, 1}, {1, 1}, {1, 1}, {1, 1}, {1, 1}, {1, 1}, {1, 1}, {1, 1}, {1, 1}, {1, 1}, {1, 1}};

  csc_wg_to_gem_roll_even_l1 = {
      {8, 8}, {8, 8}, {8, 8}, {8, 8}, {8, 8}, {8, 8}, {8, 8}, {8, 8}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7},
      {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {6, 6}, {6, 6}, {6, 6}, {6, 6},
      {6, 6}, {6, 6}, {6, 6}, {6, 6}, {6, 6}, {6, 6}, {6, 6}, {6, 6}, {6, 6}, {6, 6}, {5, 5}, {5, 5}, {5, 5}, {5, 5},
      {5, 5}, {5, 5}, {5, 5}, {5, 5}, {5, 5}, {5, 5}, {5, 5}, {5, 5}, {5, 5}, {5, 5}, {5, 5}, {5, 5}, {4, 4}, {4, 4},
      {4, 4}, {4, 4}, {4, 4}, {4, 4}, {4, 4}, {4, 4}, {4, 4}, {4, 4}, {4, 4}, {4, 4}, {4, 4}, {4, 4}, {3, 3}, {3, 3},
      {3, 3}, {3, 3}, {3, 3}, {3, 3}, {3, 3}, {3, 3}, {3, 3}, {3, 3}, {3, 3}, {3, 3}, {3, 3}, {2, 2}, {2, 2}, {2, 2},
      {2, 2}, {2, 2}, {2, 2}, {2, 2}, {2, 2}, {2, 2}, {2, 2}, {2, 2}, {1, 1}, {1, 1}, {1, 1}, {1, 1}, {1, 1}, {1, 1},
      {1, 1}, {1, 1}, {1, 1}, {1, 1}, {1, 1}, {1, 1}, {1, 1}, {1, 1}, {1, 1}, {1, 1}, {1, 1}, {1, 1}, {1, 1}, {1, 1}};

  csc_wg_to_gem_roll_even_l2 = {
      {8, 8}, {8, 8}, {8, 8}, {8, 8}, {8, 8}, {8, 8}, {8, 8}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7},
      {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {7, 7}, {6, 6}, {6, 6}, {6, 6}, {6, 6}, {6, 6}, {6, 6}, {6, 6},
      {6, 6}, {6, 6}, {6, 6}, {6, 6}, {6, 6}, {6, 6}, {5, 5}, {5, 5}, {5, 5}, {5, 5}, {5, 5}, {5, 5}, {5, 5}, {5, 5},
      {5, 5}, {5, 5}, {5, 5}, {5, 5}, {5, 5}, {5, 5}, {4, 4}, {4, 4}, {4, 4}, {4, 4}, {4, 4}, {4, 4}, {4, 4}, {4, 4},
      {4, 4}, {4, 4}, {4, 4}, {4, 4}, {4, 4}, {4, 4}, {4, 4}, {3, 3}, {3, 3}, {3, 3}, {3, 3}, {3, 3}, {3, 3}, {3, 3},
      {3, 3}, {3, 3}, {3, 3}, {3, 3}, {3, 3}, {3, 3}, {3, 3}, {3, 3}, {2, 2}, {2, 2}, {2, 2}, {2, 2}, {2, 2}, {2, 2},
      {2, 2}, {2, 2}, {2, 2}, {2, 2}, {2, 2}, {2, 2}, {2, 2}, {1, 1}, {1, 1}, {1, 1}, {1, 1}, {1, 1}, {1, 1}, {1, 1},
      {1, 1}, {1, 1}, {1, 1}, {1, 1}, {1, 1}, {1, 1}, {1, 1}, {1, 1}, {1, 1}, {1, 1}, {1, 1}, {1, 1}, {1, 1}, {1, 1}};

  gem_pad_to_csc_hs_odd = {
      157, 157, 156, 156, 156, 155, 155, 154, 154, 154, 153, 153, 152, 152, 152, 151, 151, 150, 150, 150, 149, 149, 148,
      148, 148, 147, 147, 146, 146, 146, 145, 145, 144, 144, 144, 143, 143, 142, 142, 142, 141, 141, 140, 140, 140, 139,
      139, 138, 138, 138, 137, 137, 136, 136, 135, 135, 135, 134, 134, 133, 133, 133, 132, 132, 131, 131, 131, 130, 130,
      129, 129, 129, 128, 128, 127, 127, 127, 126, 126, 125, 125, 125, 124, 124, 123, 123, 122, 122, 122, 121, 121, 120,
      120, 120, 119, 119, 118, 118, 118, 117, 117, 116, 116, 116, 115, 115, 114, 114, 113, 113, 113, 112, 112, 111, 111,
      111, 110, 110, 109, 109, 109, 108, 108, 107, 107, 107, 106, 106, 105, 105, 104, 104, 104, 103, 103, 102, 102, 102,
      101, 101, 100, 100, 100, 99,  99,  98,  98,  97,  97,  97,  96,  96,  95,  95,  95,  94,  94,  93,  93,  93,  92,
      92,  91,  91,  90,  90,  90,  89,  89,  88,  88,  88,  87,  87,  86,  86,  86,  85,  85,  84,  84,  83,  83,  83,
      82,  82,  81,  81,  81,  80,  80,  79,  79,  79,  78,  78,  77,  77,  76,  76,  76,  75,  75,  74,  74,  74,  73,
      73,  72,  72,  72,  71,  71,  70,  70,  69,  69,  69,  68,  68,  67,  67,  67,  66,  66,  65,  65,  65,  64,  64,
      63,  63,  62,  62,  62,  61,  61,  60,  60,  60,  59,  59,  58,  58,  58,  57,  57,  56,  56,  55,  55,  55,  54,
      54,  53,  53,  53,  52,  52,  51,  51,  51,  50,  50,  49,  49,  48,  48,  48,  47,  47,  46,  46,  46,  45,  45,
      44,  44,  44,  43,  43,  42,  42,  42,  41,  41,  40,  40,  39,  39,  39,  38,  38,  37,  37,  37,  36,  36,  35,
      35,  35,  34,  34,  33,  33,  33,  32,  32,  31,  31,  31,  30,  30,  29,  29,  28,  28,  28,  27,  27,  26,  26,
      26,  25,  25,  24,  24,  24,  23,  23,  22,  22,  22,  21,  21,  20,  20,  20,  19,  19,  18,  18,  18,  17,  17,
      16,  16,  16,  15,  15,  14,  14,  14,  13,  13,  12,  12,  11,  11,  11,  10,  10,  9,   9,   9,   8,   8,   7,
      7,   7,   6,   6,   5,   5,   5,   4,   4,   3,   3,   3,   2,   2,   1,   1};

  gem_pad_to_csc_hs_even = {
      1,   1,   2,   2,   2,   3,   3,   4,   4,   4,   5,   5,   6,   6,   6,   7,   7,   8,   8,   8,   9,   9,   10,
      10,  10,  11,  11,  12,  12,  12,  13,  13,  14,  14,  14,  15,  15,  16,  16,  17,  17,  17,  18,  18,  19,  19,
      19,  20,  20,  21,  21,  21,  22,  22,  23,  23,  23,  24,  24,  25,  25,  25,  26,  26,  27,  27,  27,  28,  28,
      29,  29,  29,  30,  30,  31,  31,  32,  32,  32,  33,  33,  34,  34,  34,  35,  35,  36,  36,  36,  37,  37,  38,
      38,  38,  39,  39,  40,  40,  40,  41,  41,  42,  42,  43,  43,  43,  44,  44,  45,  45,  45,  46,  46,  47,  47,
      47,  48,  48,  49,  49,  50,  50,  50,  51,  51,  52,  52,  52,  53,  53,  54,  54,  54,  55,  55,  56,  56,  56,
      57,  57,  58,  58,  59,  59,  59,  60,  60,  61,  61,  61,  62,  62,  63,  63,  63,  64,  64,  65,  65,  66,  66,
      66,  67,  67,  68,  68,  68,  69,  69,  70,  70,  70,  71,  71,  72,  72,  73,  73,  73,  74,  74,  75,  75,  75,
      76,  76,  77,  77,  77,  78,  78,  79,  79,  80,  80,  80,  81,  81,  82,  82,  82,  83,  83,  84,  84,  84,  85,
      85,  86,  86,  87,  87,  87,  88,  88,  89,  89,  89,  90,  90,  91,  91,  92,  92,  92,  93,  93,  94,  94,  94,
      95,  95,  96,  96,  96,  97,  97,  98,  98,  98,  99,  99,  100, 100, 101, 101, 101, 102, 102, 103, 103, 103, 104,
      104, 105, 105, 105, 106, 106, 107, 107, 108, 108, 108, 109, 109, 110, 110, 110, 111, 111, 112, 112, 112, 113, 113,
      114, 114, 115, 115, 115, 116, 116, 117, 117, 117, 118, 118, 119, 119, 119, 120, 120, 121, 121, 121, 122, 122, 123,
      123, 124, 124, 124, 125, 125, 126, 126, 126, 127, 127, 128, 128, 128, 129, 129, 130, 130, 130, 131, 131, 132, 132,
      132, 133, 133, 134, 134, 134, 135, 135, 136, 136, 137, 137, 137, 138, 138, 139, 139, 139, 140, 140, 141, 141, 141,
      142, 142, 143, 143, 143, 144, 144, 145, 145, 145, 146, 146, 147, 147, 147, 148, 148, 149, 149, 149, 150, 150, 151,
      151, 151, 152, 152, 153, 153, 153, 154, 154, 155, 155, 155, 156, 156, 157, 157};

  csc_hs_to_gem_pad_odd = {
      {384, 384}, {384, 384}, {382, 383}, {380, 381}, {377, 378}, {375, 376}, {372, 373}, {369, 370}, {367, 368},
      {364, 365}, {362, 363}, {359, 360}, {357, 358}, {355, 356}, {352, 353}, {350, 351}, {347, 348}, {345, 346},
      {342, 343}, {340, 341}, {337, 338}, {335, 336}, {332, 333}, {330, 331}, {327, 328}, {325, 326}, {322, 323},
      {320, 321}, {317, 318}, {315, 316}, {312, 313}, {310, 311}, {307, 308}, {305, 306}, {303, 304}, {300, 301},
      {298, 299}, {295, 296}, {293, 294}, {290, 291}, {288, 289}, {285, 286}, {283, 284}, {280, 281}, {278, 279},
      {276, 277}, {273, 274}, {271, 272}, {268, 269}, {266, 267}, {263, 264}, {261, 262}, {258, 259}, {256, 257},
      {254, 255}, {251, 252}, {249, 250}, {246, 247}, {244, 245}, {241, 242}, {239, 240}, {236, 237}, {234, 235},
      {232, 233}, {229, 230}, {227, 228}, {224, 225}, {222, 223}, {219, 220}, {217, 218}, {215, 216}, {212, 213},
      {210, 211}, {207, 208}, {205, 206}, {202, 203}, {200, 201}, {198, 199}, {195, 196}, {193, 194}, {190, 191},
      {188, 189}, {185, 186}, {183, 184}, {180, 181}, {178, 179}, {176, 177}, {173, 174}, {171, 172}, {168, 169},
      {166, 167}, {163, 164}, {161, 162}, {159, 160}, {156, 157}, {154, 155}, {151, 152}, {149, 150}, {146, 147},
      {144, 145}, {142, 143}, {139, 140}, {137, 138}, {134, 135}, {132, 133}, {129, 130}, {127, 128}, {124, 125},
      {122, 123}, {120, 121}, {117, 118}, {115, 116}, {112, 113}, {110, 111}, {107, 108}, {105, 106}, {102, 103},
      {100, 101}, {98, 99},   {95, 96},   {93, 94},   {90, 91},   {88, 89},   {85, 86},   {83, 84},   {80, 81},
      {78, 79},   {75, 76},   {73, 74},   {70, 71},   {68, 69},   {66, 67},   {63, 64},   {61, 62},   {58, 59},
      {56, 57},   {53, 54},   {51, 52},   {48, 49},   {46, 47},   {43, 44},   {41, 42},   {38, 39},   {36, 37},
      {33, 34},   {31, 32},   {28, 29},   {26, 27},   {23, 24},   {21, 22},   {18, 19},   {16, 17},   {13, 14},
      {11, 12},   {8, 9},     {6, 7},     {3, 4},     {1, 2},     {0, 0},     {0, 0}};

  csc_hs_to_gem_pad_even = {
      {0, 0},     {0, 0},     {1, 2},     {3, 4},     {6, 7},     {8, 9},     {11, 12},   {13, 14},   {16, 17},
      {18, 19},   {21, 22},   {23, 24},   {26, 27},   {28, 29},   {31, 32},   {33, 34},   {36, 37},   {38, 39},
      {41, 42},   {43, 44},   {46, 47},   {48, 49},   {51, 52},   {53, 54},   {56, 57},   {58, 59},   {61, 62},
      {63, 64},   {66, 67},   {68, 69},   {71, 72},   {73, 74},   {76, 77},   {78, 79},   {80, 81},   {83, 84},
      {85, 86},   {88, 89},   {90, 91},   {93, 94},   {95, 96},   {98, 99},   {100, 101}, {103, 104}, {105, 106},
      {107, 108}, {110, 111}, {112, 113}, {115, 116}, {117, 118}, {120, 121}, {122, 123}, {125, 126}, {127, 128},
      {129, 130}, {132, 133}, {134, 135}, {137, 138}, {139, 140}, {142, 143}, {144, 145}, {147, 148}, {149, 150},
      {151, 152}, {154, 155}, {156, 157}, {159, 160}, {161, 162}, {164, 165}, {166, 167}, {168, 169}, {171, 172},
      {173, 174}, {176, 177}, {178, 179}, {181, 182}, {183, 184}, {185, 186}, {188, 189}, {190, 191}, {193, 194},
      {195, 196}, {198, 199}, {200, 201}, {203, 204}, {205, 206}, {207, 208}, {210, 211}, {212, 213}, {215, 216},
      {217, 218}, {220, 221}, {222, 223}, {224, 225}, {227, 228}, {229, 230}, {232, 233}, {234, 235}, {237, 238},
      {239, 240}, {242, 243}, {244, 245}, {246, 247}, {249, 250}, {251, 252}, {254, 255}, {256, 257}, {259, 260},
      {261, 262}, {263, 264}, {266, 267}, {268, 269}, {271, 272}, {273, 274}, {276, 277}, {278, 279}, {281, 282},
      {283, 284}, {286, 287}, {288, 289}, {290, 291}, {293, 294}, {295, 296}, {298, 299}, {300, 301}, {303, 304},
      {305, 306}, {308, 309}, {310, 311}, {313, 314}, {315, 316}, {318, 319}, {320, 321}, {322, 323}, {325, 326},
      {327, 328}, {330, 331}, {332, 333}, {335, 336}, {337, 338}, {340, 341}, {342, 343}, {345, 346}, {347, 348},
      {350, 351}, {352, 353}, {355, 356}, {357, 358}, {360, 361}, {362, 363}, {365, 366}, {367, 368}, {370, 371},
      {372, 373}, {375, 376}, {377, 378}, {380, 381}, {382, 383}, {384, 384}, {384, 384}};

  gem_roll_to_csc_wg_odd = {98, 86, 73, 61, 46, 31, 15, 1};
  gem_roll_to_csc_wg_even = {98, 86, 73, 61, 46, 31, 15, 1};
}

CSCGEMMotherboardLUTME21::~CSCGEMMotherboardLUTME21() {}
