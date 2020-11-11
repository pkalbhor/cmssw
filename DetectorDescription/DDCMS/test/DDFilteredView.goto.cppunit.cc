#include <cppunit/extensions/HelperMacros.h>

#include "DetectorDescription/DDCMS/interface/DDFilteredView.h"
#include "DetectorDescription/DDCMS/interface/DDDetector.h"
#include "FWCore/ParameterSet/interface/FileInPath.h"
#include "DD4hep/Detector.h"

#include <string>
#include <memory>
#include <vector>

#include "cppunit/TestAssert.h"
#include "cppunit/TestFixture.h"

using namespace cms;

class testDDFilteredViewGoTo : public CppUnit::TestFixture {
  CPPUNIT_TEST_SUITE(testDDFilteredViewGoTo);
  CPPUNIT_TEST(checkFilteredView);
  CPPUNIT_TEST_SUITE_END();

public:
  void setUp() override;
  void tearDown() override {}
  void checkFilteredView();

private:
  void printMe(const cms::DDFilteredView&);
  double refRadLength_ = 0.03142;
  double refXi_ = 6.24526e-05;
  std::string fileName_;
  std::vector<int> refPos_{0, 0, 6, 2, 2};
};

CPPUNIT_TEST_SUITE_REGISTRATION(testDDFilteredViewGoTo);

void testDDFilteredViewGoTo::setUp() {
  fileName_ = edm::FileInPath("Geometry/CMSCommonData/data/dd4hep/cmsExtendedGeometry2021.xml").fullPath();
}

void testDDFilteredViewGoTo::checkFilteredView() {
  std::unique_ptr<DDDetector> det = std::make_unique<DDDetector>("DUMMY", fileName_);
  DDFilteredView fview(det.get(), det->description()->worldVolume());

  int count = 1;
  auto testPos = fview.navPos();
  while (fview.next(0)) {
    std::cout << "#" << count << ": ";
    printMe(fview);

    if (count == 45) {
      testPos = fview.navPos();
    }
    if (count == 50) {
      break;
    }
    count++;
  }

  // world_volume/OCMS_1/CMSE_1/Tracker_1/PixelBarrel_1/pixbarlayer0:PixelBarrelLayer0_1/PixelBarrelLadderFull0_6/PixelBarrelModuleBoxFull_1/PixelBarrelModuleFullPlus_4/PixelBarrelSensorFull_1/PixelBarrelActiveFull0_1
  //
  std::vector<int> activeVol{0, 0, 6, 2, 93, 12, 1, 7, 1, 0};
  fview.goTo(activeVol);
  printMe(fview);

  double radLength = fview.get<double>("TrackerRadLength");
  double xi = fview.getNextValue("TrackerXi");
  CPPUNIT_ASSERT(radLength == refRadLength_);
  CPPUNIT_ASSERT(xi == refXi_);

  std::cout << "TrackerRadLength = " << radLength << "\nTrackerXi = " << xi << "\n";

  std::cout << "\n==== Let's go to #45\n";
  fview.goTo(testPos);
  printMe(fview);

  int i = 0;
  for (auto it : fview.navPos()) {
    CPPUNIT_ASSERT(it == testPos[i++]);
  }
  i = 0;
  for (auto it : testPos) {
    CPPUNIT_ASSERT(it == refPos_[i++]);
  }

  // Start with Tracker
  std::cout << "\n==== Let's go to Tracker\n";
  fview.goTo({0, 0, 6});
  CPPUNIT_ASSERT(fview.fullName() == "tracker:Tracker");
  printMe(fview);

  // Go to the first daughter
  fview.next(0);
  printMe(fview);

  // Use it as an escape level
  int startLevel = fview.level();

  count = 1;

  do {
    std::cout << "#" << count++ << ": ";
    std::cout << "started at level " << startLevel << "\n";
    printMe(fview);

  } while (fview.next(0) && fview.level() < startLevel);

  std::cout << "\n==== Continue iteration\n";

  count = 1;
  fview.next(0);
  startLevel = fview.level();
  printMe(fview);

  do {
    std::cout << "#" << count++;
    std::cout << " started at level " << startLevel << ":\n";
    printMe(fview);
  } while (fview.next(0) && fview.level() < startLevel);

  fview.next(0);
  printMe(fview);

  std::cout << "\n==== Let's do it again, go to Tracker\n";
  fview.goTo({0, 0, 6});
  CPPUNIT_ASSERT(fview.name() == "Tracker");
  printMe(fview);

  // Go to the first daughter
  fview.next(0);
  printMe(fview);

  // Use it as an escape level
  startLevel = fview.level();

  count = 1;

  do {
    std::cout << "#" << count++ << ": ";
    std::cout << "started at level " << startLevel << "\n";
    printMe(fview);

  } while (fview.next(0) && fview.level() < startLevel);
}

void testDDFilteredViewGoTo::printMe(const cms::DDFilteredView& fview) {
  std::cout << ">>> " << fview.level() << " level: " << fview.name() << " is a "
            << cms::dd::name(cms::DDSolidShapeMap, fview.shape()) << "\n";
  std::cout << "Full path to it is " << fview.path() << "\n";

  auto copies = fview.copyNos();
  std::cout << "    copy Nos: ";
  std::for_each(copies.rbegin(), copies.rend(), [](const auto& it) { std::cout << it << ", "; });
  std::cout << "\n    levels  : ";
  for (auto it : fview.navPos()) {
    std::cout << it << ", ";
  }
  std::cout << "\n";
}