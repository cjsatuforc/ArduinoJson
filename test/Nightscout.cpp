// Copyright Benoit Blanchon 2014-2015
// MIT License
//
// Arduino JSON library
// https://github.com/bblanchon/ArduinoJson

#include <gtest/gtest.h>
#include <ArduinoJson.h>

TEST(Nightscout, ExtractSgv) {
  char json[] =
      "{\"status\":[{\"now\":1426277351973}],\"bgs\":[{\"sgv\":\"245\","
      "\"bgdelta\":2,\"trend\":4,\"direction\":\"Flat\",\"datetime\":"
      "1426254513000,\"battery\":\"24\"}]}";

  DynamicJsonBuffer jsonBuffer;

  JsonObject& root = jsonBuffer.parseObject(json);
  ASSERT_TRUE(root.success());

  const char* sgv = root["bgs"][0]["sgv"];
  ASSERT_STREQ("245", sgv);
}
