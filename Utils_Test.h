//
// Created by lucac on 16.06.2021.
//

#ifndef MULTITHREADING_UTILS_TEST_H
#define MULTITHREADING_UTILS_TEST_H

#include "Tester.h"
#include "Utils.h"

class Utils_Test
{
public:
   static void Test();
};

void Utils_Test::Test()
{
   CHECK(Utils::IsSequenceNewer(1, 0));
   CHECK(!Utils::IsSequenceNewer(0, 1));
   CHECK(!Utils::IsSequenceNewer(0, 0));
   CHECK(Utils::IsSequenceNewer(0, std::numeric_limits<uint16_t>::max()));

   CHECK(Utils::SequenceDiff(0, 0) == 0);
   CHECK(Utils::SequenceDiff(1, 0) == 1);
   CHECK(Utils::SequenceDiff(0, std::numeric_limits<uint16_t>::max()) == 1);

   uint64_t bitfield = 0;
   CHECK(bitfield == 0);
   Utils::SetBit(bitfield, 0);
   CHECK(Utils::HasBit(bitfield, 0));
   CHECK(bitfield == Utils::Bit<uint64_t>::Right);
   Utils::UnsetBit(bitfield, 0);
   CHECK(bitfield == 0);
   Utils::SetBit(bitfield, 5);
   CHECK(Utils::HasBit(bitfield, 5));
   CHECK(bitfield == (Utils::Bit<uint64_t>::Right << 5));
   Utils::UnsetBit(bitfield, 0);
   CHECK(bitfield == (Utils::Bit<uint64_t>::Right << 5));
   Utils::UnsetBit(bitfield, 5);
   CHECK(bitfield == 0);
}
#endif //MULTITHREADING_UTILS_TEST_H
