// Copyright Benoit Blanchon 2014-2015
// MIT License
//
// Arduino JSON library
// https://github.com/bblanchon/ArduinoJson

#include <gtest/gtest.h>
#include <ArduinoJson.h>

#define NIGHSCOUT_JSON_SIZE

TEST(Nightscout, ExtractSgv) {
  char json[] =
      "{"
      "  status: [{"
      "      now: 1426017007130"
      "  }],"
      "  bgs: [{"
      "      sgv: \"102\","
      "      bgdelta: 2,"
      "      trend: 4,"
      "      direction: \"Flat\","
      "      datetime: 1426016912000,"
      "      filtered: 115232,"
      "      unfiltered: 118368,"
      "      noise: 1,"
      "      rssi: 191,"
      "      battery: \"59\""
      "  }]"
      "}";

  DynamicJsonBuffer jsonBuffer;

  JsonObject& root = jsonBuffer.parseObject(json);
  ASSERT_TRUE(root.success());

  int sgv = root["bgs"][0]["sgv"];
  ASSERT_EQ(102, sgv);
}
