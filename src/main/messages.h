
const char *state_topic = "homeassistant/sensor/testProbe/state";

const char *config_topic = "homeassistant/sensor/testProbe/test123/config";

const char *data_json =
    "{\n"
    "  \"temperature\": 69.420\n"
    "}";

const char *config_json =
    "{\n"
    "  \"device_class\": \"temperature\",\n"
    "  \"state_topic\": \"homeassistant/sensor/sensorTestProbe/state\",\n"
    "  \"unit_of_measurement\": \"°F\",\n"
    "  \"value_template\": \"{{ value_json.temperature }}\",\n"
    "  \"unique_id\": \"test123\",\n"
    "  \"device\": {\n"
    "    \"identifiers\": \"test123\",\n"
    "    \"name\": \"testProbe\"\n"
    "  }\n"
    "}";