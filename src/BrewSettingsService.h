#ifndef BrewSettingsService_h
#define BrewSettingsService_h

#include <SettingsService.h>
#include <IPAddress.h>

#define BREW_SETTINGS_FILE "/config/brewSettings.json"
#define BREW_SETTINGS_SERVICE_PATH "/rest/brewSettings"

class BrewSettingsService : public SettingsService {

  public:

    BrewSettingsService(AsyncWebServer* server, FS* fs);
    ~BrewSettingsService();

    void begin();

  protected:

    void readFromJsonObject(JsonObject& root);
    void writeToJsonObject(JsonObject& root);
    void onConfigUpdated();

  private:
    // connection settings
    double _boilPercent;
    int _boilTime;
    int _sampleTime;
    double _kP;
    double _kI;
    double _kD;
};

#endif // end BrewSettingsService_h