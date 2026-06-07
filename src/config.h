#ifndef CONFIG_H_
#define CONFIG_H_

#include <avr/pgmspace.h>

#define NODEID      55          // This module's ID (transmitter)
#define NETWORKID   42          // Must match the receiver/gateway
#define GATEWAYID   1           // ID of the gateway/receiver we send to
#define FREQUENCY   RF69_433MHZ
const char ENCRYPTKEY[17] = { "MQTTGateway_42MY" }; // Encryption key (NULL = no encryption)

constexpr uint16_t minutes(uint32_t m) {
    return m * 60;
}

constexpr uint16_t hours(uint32_t h) {
    return h * 60 * 60;
}

const uint16_t IDENT_PERIOD = hours(12);
const uint16_t UPDATE_PERIOD = minutes(5);
const uint16_t START_DELAY_PERIOD = minutes(1);
const uint16_t REFERENCE_VOLTAGE = 1100;

#define PLACEHOLDER "\xff\xff\xff\xff\xff\xff"
const char PLACEHOLDER_CHAR = 255;

char state_topic[] = "home/sensor_" PLACEHOLDER;

const char id_topic[] PROGMEM = "homeassistant/device/" PLACEHOLDER "/config";
const char id_payload[] PROGMEM =
    R"({"dev":{"ids":")" PLACEHOLDER
    R"(","name":"RFMSensor","mf":"Tsukihime","mdl":"RFM69/BMP280 Sensor"},"o":{"name":"RFMSensor)" PLACEHOLDER
    R"("},"cmps":{"t":{"p":"sensor","uniq_id":")" PLACEHOLDER
    R"(t","name":"Temperature","dev_cla":"temperature","unit_of_meas":"°C","val_tpl":"{{value_json.t}}"},"p":{"p":"sensor","uniq_id":")" PLACEHOLDER
    R"(p","name":"Pressure","dev_cla":"pressure","unit_of_meas":"hPa","val_tpl":"{{value_json.p}}"},"b":{"p":"sensor","uniq_id":")" PLACEHOLDER
    R"(b","name":"Battery","dev_cla":"battery","unit_of_meas":"%","val_tpl":"{{value_json.b}}"},"v":{"p":"sensor","uniq_id":")" PLACEHOLDER
    R"(v","name":"Battery voltage","dev_cla":"voltage","unit_of_meas":"mV","val_tpl":"{{value_json.v}}"},"u":{"p":"sensor","uniq_id":")" PLACEHOLDER
    R"(u","name":"Uplink RSSI","dev_cla":"signal_strength","unit_of_meas":"dBm","val_tpl":"{{value_json.u}}"},"d":{"p":"sensor","uniq_id":")" PLACEHOLDER
    R"(d","name":"Downlink RSSI","dev_cla":"signal_strength","unit_of_meas":"dBm","val_tpl":"{{value_json.d}}"}},"stat_t":"home/sensor_)" PLACEHOLDER
    R"("})";

#endif /* CONFIG_H_ */
